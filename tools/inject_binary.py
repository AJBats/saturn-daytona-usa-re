#!/usr/bin/env python3
"""
Inject a binary into a Saturn disc image (Mode 1/2352), respecting sector boundaries.

Saturn disc sectors are 2352 bytes:
  - 12 bytes: sync pattern
  - 4 bytes: header (MSF + mode)
  - 2048 bytes: user data  <-- we only write here
  - 4 bytes: EDC
  - 8 bytes: reserved
  - 276 bytes: ECC

APROG.BIN starts at sector 21 (LBA 21).
If the binary is larger than the original, all subsequent files are shifted forward
and the ISO 9660 directory entries are patched with new LBAs.

Usage:
    python3 inject_binary.py <binary> [disc_image]
"""

import sys
import os
import struct
import shutil

SECTOR_SIZE = 2352
USER_DATA_OFFSET = 16
USER_DATA_SIZE = 2048
EDC_SIZE = 4
RESERVED_SIZE = 8
ECC_SIZE = 276

APROG_START_SECTOR = 21
APROG_ORIG_SECTORS = 193   # ceil(394896 / 2048)
APROG_ORIG_SIZE = 394896

SYNC_PATTERN = bytes([0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00])

def compute_edc(data):
    """Compute EDC (Error Detection Code) for Mode 1 sector."""
    edc_table = [0] * 256
    for i in range(256):
        edc = i
        for _ in range(8):
            if edc & 1:
                edc = (edc >> 1) ^ 0xD8018001
            else:
                edc >>= 1
        edc_table[i] = edc

    edc = 0
    for b in data:
        edc = edc_table[(edc ^ b) & 0xFF] ^ (edc >> 8)
    return edc & 0xFFFFFFFF


def lba_to_msf(lba):
    """Convert LBA to MSF (minute/second/frame) for CD sector headers.
    LBA 0 = 00:02:00 (2-second pregap)."""
    lba += 150  # 2-second pregap
    f = lba % 75
    s = (lba // 75) % 60
    m = lba // (75 * 60)
    return m, s, f


def to_bcd(val):
    """Convert integer to BCD."""
    return ((val // 10) << 4) | (val % 10)


def make_sector_header(lba, mode=1):
    """Build the 16-byte Mode 1 sector header (sync + MSF + mode)."""
    m, s, f = lba_to_msf(lba)
    return SYNC_PATTERN + bytes([to_bcd(m), to_bcd(s), to_bcd(f), mode])


def write_sector(f, lba, user_data):
    """Write a complete Mode 1 sector at the given LBA."""
    assert len(user_data) == USER_DATA_SIZE
    offset = lba * SECTOR_SIZE

    header = make_sector_header(lba)
    sector_for_edc = header + user_data
    edc = compute_edc(sector_for_edc)

    f.seek(offset)
    f.write(header)
    f.write(user_data)
    f.write(struct.pack('<I', edc))
    # Write zeroed reserved + ECC (we don't compute full ECC — Saturn doesn't check it)
    f.write(b'\x00' * (RESERVED_SIZE + ECC_SIZE))


def read_user_data(f, lba):
    """Read the 2048-byte user data from a sector."""
    f.seek(lba * SECTOR_SIZE + USER_DATA_OFFSET)
    return f.read(USER_DATA_SIZE)


def parse_directory(dir_data, dir_size):
    """Parse ISO 9660 directory entries, return list of (offset, name, lba, data_len, flags)."""
    entries = []
    offset = 0
    while offset < dir_size and offset < len(dir_data):
        rec_len = dir_data[offset]
        if rec_len == 0:
            break

        lba = struct.unpack_from('<I', dir_data, offset + 2)[0]
        data_len = struct.unpack_from('<I', dir_data, offset + 10)[0]
        flags = dir_data[offset + 25]
        name_len = dir_data[offset + 32]
        name = dir_data[offset + 33:offset + 33 + name_len].decode('ascii', errors='replace')

        entries.append((offset, name, lba, data_len, flags))
        offset += rec_len

    return entries


def patch_dir_lba(dir_data, entry_offset, new_lba):
    """Patch both LE and BE LBA fields in a directory entry."""
    struct.pack_into('<I', dir_data, entry_offset + 2, new_lba)
    struct.pack_into('>I', dir_data, entry_offset + 6, new_lba)


def patch_dir_size(dir_data, entry_offset, new_size):
    """Patch both LE and BE data length fields in a directory entry."""
    struct.pack_into('<I', dir_data, entry_offset + 10, new_size)
    struct.pack_into('>I', dir_data, entry_offset + 14, new_size)


def inject_binary(bin_path, disc_path, output_path):
    with open(bin_path, 'rb') as f:
        bin_data = f.read()

    bin_size = len(bin_data)
    new_sectors = (bin_size + USER_DATA_SIZE - 1) // USER_DATA_SIZE
    shift = new_sectors - APROG_ORIG_SECTORS

    print("Binary: %d bytes (%d sectors, original %d sectors)" % (bin_size, new_sectors, APROG_ORIG_SECTORS))

    if shift > 0:
        print("Shift: +%d sectors needed — rebuilding disc with relocated files" % shift)
    elif shift == 0:
        print("Binary fits in original space exactly")
    else:
        print("Binary is smaller than original (%d sectors free)" % (-shift))

    with open(disc_path, 'rb') as f:
        disc_data = bytearray(f.read())

    orig_total_sectors = len(disc_data) // SECTOR_SIZE

    # Read PVD from sector 16
    pvd = bytearray(read_user_data_from_bytes(disc_data, 16))
    orig_vol_size = struct.unpack_from('<I', pvd, 80)[0]

    # Read root directory from sector 20
    root_dir = bytearray(read_user_data_from_bytes(disc_data, 20))
    root_dir_size = struct.unpack_from('<I', pvd, 166)[0]
    entries = parse_directory(root_dir, root_dir_size)

    print("\nOriginal disc layout:")
    for off, name, lba, size, flags in entries:
        sectors = (size + USER_DATA_SIZE - 1) // USER_DATA_SIZE
        kind = "DIR " if (flags & 2) else "FILE"
        print("  %s %-20s LBA=%d size=%d (%d sectors)" % (kind, name, lba, size, sectors))

    if shift > 0:
        # Build new disc image
        new_total_sectors = orig_total_sectors + shift
        new_disc = bytearray(new_total_sectors * SECTOR_SIZE)

        # Copy sectors 0-20 (system area + PVD + dir) — we'll patch PVD and dir later
        for lba in range(APROG_START_SECTOR):
            src_off = lba * SECTOR_SIZE
            new_disc[src_off:src_off + SECTOR_SIZE] = disc_data[src_off:src_off + SECTOR_SIZE]

        # Patch directory entries: shift all files after APROG
        for off, name, lba, size, flags in entries:
            if name.startswith('APROG'):
                # Update APROG size to new size
                patch_dir_size(root_dir, off, bin_size)
                # LBA stays at 21
            elif lba > APROG_START_SECTOR:
                new_lba = lba + shift
                patch_dir_lba(root_dir, off, new_lba)

        # Update PVD volume size
        new_vol_size = orig_vol_size + shift
        struct.pack_into('<I', pvd, 80, new_vol_size)
        struct.pack_into('>I', pvd, 84, new_vol_size)

        # Write patched PVD to sector 16
        write_sector_to_bytes(new_disc, 16, bytes(pvd))

        # Write patched root directory to sector 20
        write_sector_to_bytes(new_disc, 20, bytes(root_dir))

        # Write new APROG.BIN
        for i in range(new_sectors):
            lba = APROG_START_SECTOR + i
            chunk_start = i * USER_DATA_SIZE
            chunk_end = min(chunk_start + USER_DATA_SIZE, bin_size)
            chunk = bin_data[chunk_start:chunk_end]
            if len(chunk) < USER_DATA_SIZE:
                chunk = chunk + b'\x00' * (USER_DATA_SIZE - len(chunk))
            write_sector_to_bytes(new_disc, lba, chunk)

        # Copy all sectors after APROG, shifted forward
        after_aprog_start = APROG_START_SECTOR + APROG_ORIG_SECTORS  # sector 214
        for orig_lba in range(after_aprog_start, orig_total_sectors):
            new_lba = orig_lba + shift
            src_off = orig_lba * SECTOR_SIZE
            dst_off = new_lba * SECTOR_SIZE
            # Copy the raw sector data
            sector_raw = disc_data[src_off:src_off + SECTOR_SIZE]
            if len(sector_raw) < SECTOR_SIZE:
                break
            new_disc[dst_off:dst_off + SECTOR_SIZE] = sector_raw
            # Fix the sector header MSF
            header = make_sector_header(new_lba)
            new_disc[dst_off:dst_off + USER_DATA_OFFSET] = header
            # Recompute EDC with new header
            user_data = new_disc[dst_off + USER_DATA_OFFSET:dst_off + USER_DATA_OFFSET + USER_DATA_SIZE]
            edc = compute_edc(bytes(header) + bytes(user_data))
            struct.pack_into('<I', new_disc, dst_off + USER_DATA_OFFSET + USER_DATA_SIZE, edc)

        with open(output_path, 'wb') as f:
            f.write(new_disc)

        print("\nRebuilt disc: %d sectors (was %d, +%d)" % (new_total_sectors, orig_total_sectors, shift))

    else:
        # Binary fits — simple injection (original behavior)
        shutil.copy2(disc_path, output_path)

        # Update APROG size in ISO directory if it changed
        if bin_size != APROG_ORIG_SIZE:
            for off, name, lba, size, flags in entries:
                if name.startswith('APROG'):
                    patch_dir_size(root_dir, off, bin_size)
            # Write patched root directory to sector 20 in the output
            with open(output_path, 'r+b') as f:
                dir_offset = 20 * SECTOR_SIZE + USER_DATA_OFFSET
                f.seek(dir_offset)
                f.write(bytes(root_dir))
                # Recompute EDC for dir sector
                f.seek(20 * SECTOR_SIZE)
                sector_header = f.read(USER_DATA_OFFSET)
                sector_for_edc = sector_header + bytes(root_dir)
                edc = compute_edc(sector_for_edc)
                edc_pos = 20 * SECTOR_SIZE + USER_DATA_OFFSET + USER_DATA_SIZE
                f.seek(edc_pos)
                f.write(struct.pack('<I', edc))

        with open(output_path, 'r+b') as f:
            for i in range(new_sectors):
                lba = APROG_START_SECTOR + i
                sector_offset = lba * SECTOR_SIZE

                chunk_start = i * USER_DATA_SIZE
                chunk_end = min(chunk_start + USER_DATA_SIZE, bin_size)
                chunk = bin_data[chunk_start:chunk_end]
                if len(chunk) < USER_DATA_SIZE:
                    chunk = chunk + b'\x00' * (USER_DATA_SIZE - len(chunk))

                user_data_pos = sector_offset + USER_DATA_OFFSET
                f.seek(user_data_pos)
                f.write(chunk)

                f.seek(sector_offset)
                sector_header = f.read(USER_DATA_OFFSET)
                sector_for_edc = sector_header + chunk
                edc = compute_edc(sector_for_edc)

                edc_pos = sector_offset + USER_DATA_OFFSET + USER_DATA_SIZE
                f.seek(edc_pos)
                f.write(struct.pack('<I', edc))

            # If binary is smaller, zero-pad remaining original sectors
            if bin_size < APROG_ORIG_SIZE:
                for i in range(new_sectors, APROG_ORIG_SECTORS):
                    lba = APROG_START_SECTOR + i
                    sector_offset = lba * SECTOR_SIZE
                    user_data_pos = sector_offset + USER_DATA_OFFSET
                    f.seek(user_data_pos)
                    f.write(b'\x00' * USER_DATA_SIZE)

    # Verify new layout
    print("\nNew disc layout:")
    new_entries = parse_directory(root_dir, root_dir_size)
    for off, name, lba, size, flags in new_entries:
        sectors = (size + USER_DATA_SIZE - 1) // USER_DATA_SIZE
        kind = "DIR " if (flags & 2) else "FILE"
        print("  %s %-20s LBA=%d size=%d (%d sectors)" % (kind, name, lba, size, sectors))

    print("\nOutput: %s" % output_path)


def read_user_data_from_bytes(data, lba):
    """Read user data from an in-memory disc image."""
    off = lba * SECTOR_SIZE + USER_DATA_OFFSET
    return data[off:off + USER_DATA_SIZE]


def write_sector_to_bytes(data, lba, user_data):
    """Write a sector to an in-memory disc image."""
    assert len(user_data) == USER_DATA_SIZE
    offset = lba * SECTOR_SIZE

    header = make_sector_header(lba)
    sector_for_edc = header + user_data
    edc = compute_edc(sector_for_edc)

    data[offset:offset + USER_DATA_OFFSET] = header
    data[offset + USER_DATA_OFFSET:offset + USER_DATA_OFFSET + USER_DATA_SIZE] = user_data
    edc_off = offset + USER_DATA_OFFSET + USER_DATA_SIZE
    struct.pack_into('<I', data, edc_off, edc)
    # Zero reserved + ECC
    zero_off = edc_off + EDC_SIZE
    data[zero_off:zero_off + RESERVED_SIZE + ECC_SIZE] = b'\x00' * (RESERVED_SIZE + ECC_SIZE)


def generate_cue(orig_cue, out_dir, cue_path):
    """Parse original CUE, copy audio track BINs, write full CUE sheet."""
    with open(orig_cue, 'r') as f:
        cue_lines = f.readlines()

    orig_dir = os.path.dirname(orig_cue)
    new_lines = []
    track_num = 0

    for line in cue_lines:
        stripped = line.strip()
        if stripped.startswith('FILE'):
            parts = stripped.split('"')
            if len(parts) >= 2:
                orig_filename = parts[1]
                if track_num == 0:
                    # Data track — already injected as Track 01.bin
                    new_lines.append('FILE "Track 01.bin" BINARY\n')
                else:
                    # Audio track — copy from original disc
                    src = os.path.join(orig_dir, orig_filename)
                    dst_name = os.path.basename(orig_filename)
                    dst = os.path.join(out_dir, dst_name)
                    if os.path.exists(src):
                        if not os.path.exists(dst):
                            print("  Copying audio track: %s" % dst_name)
                            shutil.copy2(src, dst)
                    else:
                        print("  WARNING: Audio track not found: %s" % src)
                    new_lines.append('FILE "%s" BINARY\n' % dst_name)
                track_num += 1
            else:
                new_lines.append(line)
        else:
            new_lines.append(line)

    with open(cue_path, 'w') as f:
        f.writelines(new_lines)

    print("\nCUE: %d tracks (%d audio)" % (track_num, track_num - 1))


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <binary> [disc_image]" % sys.argv[0])
        sys.exit(1)

    bin_path = sys.argv[1]

    project_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if len(sys.argv) >= 3:
        disc_path = sys.argv[2]
    else:
        disc_path = os.path.join(
            project_dir, "external_resources",
            "Daytona USA (USA)",
            "Daytona USA (USA) (Track 01).bin"
        )

    if not os.path.exists(bin_path):
        print("ERROR: Binary not found: %s" % bin_path)
        sys.exit(1)
    if not os.path.exists(disc_path):
        print("ERROR: Disc image not found: %s" % disc_path)
        sys.exit(1)

    out_dir = os.path.join(project_dir, "build", "disc", "rebuilt_disc")
    os.makedirs(out_dir, exist_ok=True)
    output_track = os.path.join(out_dir, "Track 01.bin")

    inject_binary(bin_path, disc_path, output_track)

    # Generate full CUE sheet with audio tracks from original disc
    orig_cue = os.path.join(
        project_dir, "external_resources",
        "Daytona USA (USA)",
        "Daytona USA (USA).cue"
    )
    cue_path = os.path.join(out_dir, "daytona_rebuilt.cue")
    generate_cue(orig_cue, out_dir, cue_path)

    print("CUE: %s" % cue_path)

if __name__ == "__main__":
    main()
