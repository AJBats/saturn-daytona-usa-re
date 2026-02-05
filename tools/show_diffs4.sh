#!/bin/bash
# Show side-by-side for delta=0, diffs=4 functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/show_diffs4_$$
mkdir -p "$TMPDIR"

show_func() {
  local base="$1"
  local cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && return

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && return

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' > "$TMPDIR/$base.full"
  awk '{print $1}' "$TMPDIR/$base.full" > "$TMPDIR/$base.opc"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  echo "=== $base ==="
  echo "  OURS (opcode):                      EXPECTED:"
  paste "$TMPDIR/$base.opc" "$TMPDIR/$base.exp" | awk '{printf "  %2d: %-30s %s\n", NR, $1, $2}'
  echo "  Full asm (ours):"
  cat -n "$TMPDIR/$base.full" | sed 's/^/    /'
  echo ""
}

for func in FUN_06005174 FUN_06018EC8 FUN_06033330 FUN_0603C0A0 FUN_0603F8B8; do
  show_func "$func"
done

rm -rf "$TMPDIR"
