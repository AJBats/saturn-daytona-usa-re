#!/usr/bin/env python3
"""test_disc_with_prod_binary.py — Test rebuilt disc with production binary.

Makes a copy of the rebuilt disc, injects the ORIGINAL production binary,
and tests if it boots. This isolates: is the issue the binary or the disc?
"""

import os, sys, shutil, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

PROD_BIN = os.path.join(PROJDIR, "build", "aprog.bin")
FREE_CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
FREE_BIN_TRACK = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "Track 01.bin")

# Output
TEST_DIR = os.path.join(PROJDIR, "build", "disc", "test_prod_on_rebuilt")
TEST_BIN_TRACK = os.path.join(TEST_DIR, "Track 01.bin")
TEST_CUE = os.path.join(TEST_DIR, "test.cue")

SECTOR_SIZE = 2352
USER_DATA_OFFSET = 16
USER_DATA_SIZE = 2048


def inject_binary_at_lba(track_bin, binary_data, lba, orig_size):
    """Write binary data into sectors starting at LBA, then patch directory."""
    with open(track_bin, 'r+b') as f:
        remaining = len(binary_data)
        offset = 0
        sector = lba
        while remaining > 0:
            chunk = binary_data[offset:offset + USER_DATA_SIZE]
            if len(chunk) < USER_DATA_SIZE:
                # Read existing sector to preserve padding
                f.seek(sector * SECTOR_SIZE + USER_DATA_OFFSET)
                existing = bytearray(f.read(USER_DATA_SIZE))
                existing[:len(chunk)] = chunk
                chunk = bytes(existing)
            f.seek(sector * SECTOR_SIZE + USER_DATA_OFFSET)
            f.write(chunk)
            remaining -= USER_DATA_SIZE
            offset += USER_DATA_SIZE
            sector += 1

    # Patch ISO directory entry size
    patch_directory_size(track_bin, len(binary_data))


def patch_directory_size(track_bin, new_size):
    """Patch the ISO 9660 directory entry for APROG.BIN with new file size."""
    with open(track_bin, 'r+b') as f:
        # Read PVD (sector 16)
        f.seek(16 * SECTOR_SIZE + USER_DATA_OFFSET)
        pvd = f.read(USER_DATA_SIZE)

        # Root directory record
        root_lba = struct.unpack('<I', pvd[156+2:156+6])[0]
        root_size = struct.unpack('<I', pvd[156+10:156+14])[0]

        # Read root directory
        f.seek(root_lba * SECTOR_SIZE + USER_DATA_OFFSET)
        dir_data = bytearray(f.read(root_size))

        # Find APROG.BIN entry
        offset = 0
        while offset < len(dir_data):
            rec_len = dir_data[offset]
            if rec_len == 0:
                offset = ((offset // 2048) + 1) * 2048
                if offset >= len(dir_data):
                    break
                continue

            name_len = dir_data[offset + 32]
            name = dir_data[offset + 33:offset + 33 + name_len].decode('ascii', errors='replace')
            if name.split(';')[0].upper() in ('APROG.BIN', '0APROG.BIN'):
                # Patch size (both little-endian at +10 and big-endian at +14)
                struct.pack_into('<I', dir_data, offset + 10, new_size)
                struct.pack_into('>I', dir_data, offset + 14, new_size)
                print(f"  Patched APROG.BIN size to {new_size}")

                # Write back directory
                f.seek(root_lba * SECTOR_SIZE + USER_DATA_OFFSET)
                f.write(bytes(dir_data))
                return True

            offset += rec_len

    print("  ERROR: Could not find APROG.BIN in directory")
    return False


def main():
    # Make test directory
    os.makedirs(TEST_DIR, exist_ok=True)

    # Copy rebuilt disc track 01
    print("Copying rebuilt disc Track 01...")
    shutil.copy2(FREE_BIN_TRACK, TEST_BIN_TRACK)

    # Read production binary
    with open(PROD_BIN, 'rb') as f:
        prod_data = f.read()
    print(f"Production binary: {len(prod_data)} bytes")

    # Inject production binary into the copy
    print("Injecting production binary into rebuilt disc copy...")
    inject_binary_at_lba(TEST_BIN_TRACK, prod_data, 21, 394896)

    # Create CUE sheet
    # Copy audio tracks from rebuilt disc directory
    cue_lines = [
        'CATALOG 0000000000000',
        f'FILE "Track 01.bin" BINARY',
        '  TRACK 01 MODE1/2352',
        '    INDEX 01 00:00:00',
    ]

    # Read the original CUE to get audio track references
    with open(FREE_CUE, 'r') as f:
        in_track1 = True
        for line in f:
            line = line.rstrip()
            if 'TRACK 02' in line:
                in_track1 = False
            if not in_track1:
                cue_lines.append(line)

    with open(TEST_CUE, 'w') as f:
        f.write('\n'.join(cue_lines) + '\n')

    print(f"\nTest disc ready: {TEST_CUE}")
    print("Now run boot test with this disc to verify...")

    # Verify by reading back
    with open(TEST_BIN_TRACK, 'rb') as f:
        f.seek(21 * SECTOR_SIZE + USER_DATA_OFFSET)
        check = f.read(16)
    print(f"First 16 bytes on test disc: {check.hex()}")
    print(f"Expected (prod):             {prod_data[:16].hex()}")
    print(f"Match: {check == prod_data[:16]}")

    # Now test boot
    print("\n--- Running boot test ---")
    from parallel_compare import MednafenInstance, read_regs_bin
    import time, re

    TMPDIR = os.path.join(PROJDIR, ".tmp")
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, "test_prod_disc")
    inst = MednafenInstance("test", TEST_CUE, ipc)

    print("Starting Mednafen with production binary on rebuilt disc...")
    inst.start()

    # Set breakpoint at post-system_init
    inst.breakpoint(0x0600300A)
    try:
        ack = inst.continue_exec()
        m = re.search(r'frame=(\d+)', ack)
        frame = int(m.group(1)) if m else -1
        print(f"  system_init returned at frame {frame}")

        inst.breakpoint_clear()
        inst.breakpoint(0x06003010)
        ack = inst.continue_exec()
        m = re.search(r'frame=(\d+)', ack)
        frame = int(m.group(1)) if m else -1
        print(f"  Main loop entered at frame {frame}")
        print(f"  PRODUCTION BINARY ON REBUILT DISC: BOOTS OK")

    except TimeoutError:
        print(f"  TIMEOUT: system_init never returned!")
        regs_path = os.path.join(ipc, "regs.bin")
        inst.dump_regs_bin(regs_path)
        time.sleep(0.3)
        regs = read_regs_bin(regs_path)
        if regs:
            print(f"  Stuck at PC=0x{regs['PC']:08X}")
        print(f"  PRODUCTION BINARY ON REBUILT DISC: FAILS")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
