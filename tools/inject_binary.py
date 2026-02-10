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

APROG.BIN starts at sector 21, user data offset (raw byte 49408 = 21*2352+16).
We write the binary into consecutive sectors' user data areas only.

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
APROG_MAX_SIZE = 394896

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

def inject_binary(bin_path, disc_path, output_path):
    with open(bin_path, 'rb') as f:
        bin_data = f.read()

    bin_size = len(bin_data)
    if bin_size > APROG_MAX_SIZE:
        print("WARNING: Binary (%d bytes) exceeds APROG.BIN size (%d)" % (bin_size, APROG_MAX_SIZE))

    sectors_needed = (bin_size + USER_DATA_SIZE - 1) // USER_DATA_SIZE
    print("Binary: %d bytes (%d sectors)" % (bin_size, sectors_needed))

    shutil.copy2(disc_path, output_path)

    with open(output_path, 'r+b') as f:
        for i in range(sectors_needed):
            sector_num = APROG_START_SECTOR + i
            sector_offset = sector_num * SECTOR_SIZE

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

    print("Injected into %d sectors starting at sector %d" % (sectors_needed, APROG_START_SECTOR))
    print("Output: %s" % output_path)

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

    cue_path = os.path.join(out_dir, "daytona_rebuilt.cue")
    with open(cue_path, 'w') as f:
        f.write('FILE "Track 01.bin" BINARY\n')
        f.write('  TRACK 01 MODE1/2352\n')
        f.write('    INDEX 01 00:00:00\n')

    print("CUE: %s" % cue_path)

if __name__ == "__main__":
    main()
