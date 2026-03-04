#!/bin/bash
# Single-file Cygnus AS assembly via DOSBox-X (headless)
#
# Usage: cygnus_as.sh <input.s> <output.O>
#
# Copies source to build dir, generates a DOSBox-X conf, assembles,
# and verifies output. Designed to plug into Make pattern rules.

set -e

INPUT="$1"
OUTPUT="$2"

if [ -z "$INPUT" ] || [ -z "$OUTPUT" ]; then
    echo "Usage: cygnus_as.sh <input.s> <output.O>" >&2
    exit 1
fi

STEM=$(basename "$OUTPUT" .O)
COFFDIR=$(dirname "$OUTPUT")
DOSBOX="/mnt/c/DOSBox-X/dosbox-x.exe"

# Paths for DOSBox conf (Windows-style)
CYGNUS_WIN='D:\Projects\SaturnReverseTest\tools\cygnus-2.7-96Q3'
REIMPL_WIN='D:\Projects\SaturnReverseTest\reimpl'

# Copy source to build dir (uppercase .S for DOS)
cp "$INPUT" "$COFFDIR/$STEM.S"

# Generate per-file conf (use stem in filename to avoid -j conflicts)
CONF="$COFFDIR/_asm_$STEM.conf"
cat > "$CONF" << EOF
[dosbox]
memsize=16

[cpu]
cycles=max

[autoexec]
MOUNT S "$CYGNUS_WIN"
MOUNT W "$REIMPL_WIN"
SET PATH=S:\BIN
SET GCC_EXEC_PREFIX=S:\LIB\\
SET TMPDIR=W:\BUILD\COFF
SET GO32=EMU S:\BIN\EMU387
W:
CD BUILD\COFF
AS -relax -o $STEM.O $STEM.S
EXIT
EOF

# Run DOSBox-X headlessly
"$DOSBOX" -silent -fastlaunch -conf "$CONF" > /dev/null 2>&1

# Clean up conf and source copy
rm -f "$CONF" "$COFFDIR/$STEM.S"

# Verify output
if [ ! -f "$OUTPUT" ]; then
    echo "FAIL: $STEM.S assembly failed" >&2
    exit 1
fi
