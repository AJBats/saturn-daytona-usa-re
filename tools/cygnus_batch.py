#!/usr/bin/env python3
"""Batch Cygnus AS assembly via DOSBox-X.

Preprocesses source files (converts ELF directives to COFF-compatible),
then assembles them with Cygnus AS running in DOSBox-X. Splits work into
chunks to avoid DOS memory exhaustion.

The preprocessing is done on copies in the build directory, so the
original source files remain unchanged (they must stay compatible
with sh-elf-as for the ELF validation pipeline).

Usage:
    python cygnus_batch.py [--chunk-size N] [--dry-run]

Assembles all src/*.s files. Skips files that already have a .O in build/.
"""

import argparse
import glob
import os
import subprocess
import sys
import time

CYGNUS_PATH = r'D:\Projects\SaturnReverseTest\tools\cygnus-2.7-96Q3'
REIMPL_PATH = r'D:\Projects\SaturnReverseTest\reimpl'
SRC_DIR = os.path.join(REIMPL_PATH, 'src')
BUILD_DIR = os.path.join(REIMPL_PATH, 'build', 'coff')
DOSBOX_EXE = r'C:\DOSBox-X\dosbox-x.exe'

DEFAULT_CHUNK_SIZE = 100


def preprocess_for_cygnus(src_path, dst_path):
    """Convert a source file to be Cygnus AS compatible.

    Changes:
    - .2byte -> .short
    - .4byte -> .long
    - bf/s -> bf.s (Cygnus uses dot notation, not slash)
    - bt/s -> bt.s
    - muls.w -> muls (Cygnus doesn't support .w suffix on muls/mulu)
    - mulu.w -> mulu
    """
    with open(src_path, 'r') as f:
        content = f.read()

    content = content.replace('.2byte', '.short')
    content = content.replace('.4byte', '.long')
    content = content.replace('bf/s', 'bf.s')
    content = content.replace('bt/s', 'bt.s')
    content = content.replace('muls.w', 'muls')
    content = content.replace('mulu.w', 'mulu')
    # COFF 8-char section name limit — normalize .text.startup to .text
    content = content.replace('.section .text.startup', '\t.text')

    with open(dst_path, 'w') as f:
        f.write(content)


def generate_chunk_conf(stems, chunk_idx, build_dir):
    """Generate .conf and .BAT for one chunk of files."""
    bat_name = f'ASM_{chunk_idx:03d}.BAT'
    conf_name = f'asm_{chunk_idx:03d}.conf'
    done_name = f'DONE_{chunk_idx:03d}.TXT'

    bat_path = os.path.join(build_dir, bat_name)
    conf_path = os.path.join(build_dir, conf_name)

    # Generate .BAT
    bat_lines = ['@ECHO OFF']
    for stem in stems:
        bat_lines.append(f'AS -o {stem}.O {stem}.S')
    bat_lines.append(f'ECHO DONE > {done_name}')
    bat_lines.append('')

    with open(bat_path, 'w') as f:
        f.write('\r\n'.join(bat_lines))

    # Generate .conf
    lines = [
        '[dosbox]',
        'memsize=16',
        '',
        '[cpu]',
        'cycles=max',
        '',
        '[autoexec]',
        f'MOUNT S "{CYGNUS_PATH}"',
        f'MOUNT W "{REIMPL_PATH}"',
        'SET PATH=S:\\BIN',
        'SET GCC_EXEC_PREFIX=S:\\LIB\\',
        'SET TMPDIR=W:\\BUILD\\COFF',
        'SET GO32=EMU S:\\BIN\\EMU387',
        'W:',
        'CD BUILD\\COFF',
        f'CALL {bat_name}',
        'EXIT',
        '',
    ]

    with open(conf_path, 'w') as f:
        f.write('\n'.join(lines))

    return conf_path, os.path.join(build_dir, done_name)


def run_chunk(conf_path, done_path, chunk_idx, stems, total_done, total_count):
    """Run DOSBox for one chunk. Returns (success, error_stem_or_None)."""
    # Remove done marker if it exists
    if os.path.exists(done_path):
        os.remove(done_path)

    label = f'Chunk {chunk_idx} ({total_done+1}-{total_done+len(stems)}/{total_count})'
    print(f'  {label}: assembling {len(stems)} files...', end='', flush=True)

    result = subprocess.run(
        [DOSBOX_EXE, '-silent', '-fastlaunch', '-conf', conf_path],
        capture_output=True, timeout=120
    )

    if os.path.exists(done_path):
        print(' OK')
        return True, None

    # Find which file failed — last stem without a .O
    for stem in stems:
        o_path = os.path.join(BUILD_DIR, stem + '.O')
        if not os.path.exists(o_path):
            print(f' FAILED at {stem}.S')
            return False, stem

    print(' FAILED (done marker missing but all .O exist?)')
    return False, None


def main():
    parser = argparse.ArgumentParser(description='Batch Cygnus AS assembly via DOSBox-X')
    parser.add_argument('--chunk-size', type=int, default=DEFAULT_CHUNK_SIZE,
                        help=f'Files per DOSBox session (default {DEFAULT_CHUNK_SIZE})')
    parser.add_argument('--dry-run', action='store_true',
                        help='Preprocess and generate configs but don\'t run DOSBox')
    parser.add_argument('--clean', action='store_true',
                        help='Remove all .O and .S files from build dir first')
    args = parser.parse_args()

    os.makedirs(BUILD_DIR, exist_ok=True)

    # Clean if requested
    if args.clean:
        for ext in ('*.O', '*.S'):
            for f in glob.glob(os.path.join(BUILD_DIR, ext)):
                os.remove(f)
        print('Cleaned build directory')

    # Find all source files: src/ overrides retail/ by stem name
    retail_dir = os.path.join(REIMPL_PATH, 'retail')
    src_files = sorted(glob.glob(os.path.join(SRC_DIR, '*.s')))
    retail_files = sorted(glob.glob(os.path.join(retail_dir, '*.s')))

    # Build stem→path mapping: retail first, then src overwrites
    stem_map = {}
    for r in retail_files:
        stem = os.path.splitext(os.path.basename(r))[0]
        stem_map[stem] = r
    for s in src_files:
        stem = os.path.splitext(os.path.basename(s))[0]
        stem_map[stem] = s  # src/ overrides retail/

    if not stem_map:
        print('No source files found')
        return 1

    # Determine which files need assembly (skip existing .O)
    all_stems = []
    skip_count = 0
    for stem in sorted(stem_map.keys()):
        o_path = os.path.join(BUILD_DIR, stem + '.O')
        if os.path.exists(o_path):
            skip_count += 1
            continue
        all_stems.append((stem, stem_map[stem]))

    total_count = len(all_stems)
    print(f'Found {len(stem_map)} source files ({len(src_files)} src + {len(retail_files) - len(src_files)} retail-only), {skip_count} already assembled, {total_count} to do')

    if total_count == 0:
        print('Nothing to assemble!')
        return 0

    # Preprocess all files
    print('Preprocessing...', end='', flush=True)
    for stem, src_path in all_stems:
        dst_path = os.path.join(BUILD_DIR, stem + '.S')
        preprocess_for_cygnus(src_path, dst_path)
    print(f' {total_count} files')

    # Split into chunks
    chunk_size = args.chunk_size
    chunks = []
    for i in range(0, total_count, chunk_size):
        chunk_stems = [s[0] for s in all_stems[i:i+chunk_size]]
        chunks.append(chunk_stems)

    print(f'Split into {len(chunks)} chunks of up to {chunk_size} files')

    if args.dry_run:
        for i, chunk in enumerate(chunks):
            conf_path, done_path = generate_chunk_conf(chunk, i, BUILD_DIR)
            print(f'  Generated {conf_path} ({len(chunk)} files)')
        print('Dry run complete')
        return 0

    # Run each chunk
    total_done = 0
    t0 = time.time()
    for i, chunk in enumerate(chunks):
        conf_path, done_path = generate_chunk_conf(chunk, i, BUILD_DIR)
        success, failed_stem = run_chunk(conf_path, done_path, i, chunk, total_done, len(src_files))
        if not success:
            print(f'\nFAILED: {failed_stem}.S could not be assembled')
            print(f'Check the preprocessed file: {os.path.join(BUILD_DIR, failed_stem + ".S")}')
            return 1
        total_done += len(chunk)

    elapsed = time.time() - t0
    total_o = len(glob.glob(os.path.join(BUILD_DIR, '*.O')))
    print(f'\nDone: {total_o} COFF .O files in {elapsed:.1f}s')
    return 0


if __name__ == '__main__':
    sys.exit(main())
