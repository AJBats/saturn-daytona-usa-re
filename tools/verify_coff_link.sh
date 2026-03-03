#!/bin/bash
# Verify COFF hybrid pipeline: build/coff/*.O → sh-elf-ld → binary matches original
set -e

SHTOOLS=/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin
COFF_DIR=/mnt/d/Projects/SaturnReverseTest/reimpl/build/coff
REIMPL=/mnt/d/Projects/SaturnReverseTest/reimpl
ORIGINAL=/mnt/d/Projects/SaturnReverseTest/build/disc/files/APROG.BIN

COFF_OBJS="$COFF_DIR/_start.O"
for f in $(ls $COFF_DIR/0*.O 2>/dev/null | sort); do
    COFF_OBJS="$COFF_OBJS $f"
done
echo "Linking $(echo $COFF_OBJS | wc -w) COFF .O files..."

cat > /tmp/free_coff.ld << 'LDEOF'
OUTPUT_FORMAT("elf32-sh")
OUTPUT_ARCH(sh)
ENTRY(_start)
SECTIONS {
    . = 0x06003000;
    .text : SUBALIGN(2) { *(.text) }
    /DISCARD/ : { *(.comment) *(.note.*) *(.eh_frame) }
}
ASSERT(. <= 0x06063690, "Code overflow!")
LDEOF
grep '^PROVIDE' $REIMPL/free.ld >> /tmp/free_coff.ld

$SHTOOLS/sh-elf-ld -T /tmp/free_coff.ld -b coff-sh -nostdlib -o /tmp/coff_daytona.elf $COFF_OBJS
$SHTOOLS/sh-elf-objcopy -O binary /tmp/coff_daytona.elf /tmp/coff_APROG.BIN

if cmp -s /tmp/coff_APROG.BIN $ORIGINAL; then
    echo "PASS: COFF binary byte-identical to original ($(wc -c < /tmp/coff_APROG.BIN) bytes)"
else
    echo "FAIL: COFF binary differs from original"
    cmp -l /tmp/coff_APROG.BIN $ORIGINAL | head -10
    exit 1
fi
