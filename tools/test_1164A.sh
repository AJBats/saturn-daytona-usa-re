#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/test_1164A_$$
mkdir -p "$TMPDIR"

test_variant() {
  local label="$1"
  local cfile="$2"
  "$CC1" -quiet -O2 -m2 -mbsr "$cfile" -o "$TMPDIR/out.s" 2>/dev/null
  grep -P '^\t[a-z]' "$TMPDIR/out.s" > "$TMPDIR/out.full"
  sed 's/\t/ /g' < "$TMPDIR/out.full" | awk '{print $1}' > "$TMPDIR/out.opc"
  tr -d '\r' < "$TESTDIR/FUN_0601164A.expected" > "$TMPDIR/exp"
  if diff -q "$TMPDIR/out.opc" "$TMPDIR/exp" >/dev/null 2>&1; then
    echo "$label: *** PASS ***"
  else
    echo "$label: FAIL"
  fi
  cat -n "$TMPDIR/out.full"
  echo ""
}

# v1: current
cat > "$TMPDIR/v1.c" << 'EOF'
void FUN_0601164a()
{
  char *puVar1;
  puVar1 = 0x25F800A4;
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)(puVar1 + -10) = 0x0200;
}
EOF
test_variant "v1 (current)" "$TMPDIR/v1.c"

# v2: pre-load value before address computation
cat > "$TMPDIR/v2.c" << 'EOF'
void FUN_0601164a()
{
  short val = 0x0200;
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)(0x25F800A4 + -10) = val;
}
EOF
test_variant "v2 (pre-load value)" "$TMPDIR/v2.c"

# v3: two separate addresses
cat > "$TMPDIR/v3.c" << 'EOF'
void FUN_0601164a()
{
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)0x25F8009A = 0x0200;
}
EOF
test_variant "v3 (separate addrs)" "$TMPDIR/v3.c"

# v4: swapped order
cat > "$TMPDIR/v4.c" << 'EOF'
void FUN_0601164a()
{
  char *puVar1 = 0x25F800A4;
  *(short *)(puVar1 + -10) = 0x0200;
  *(int *)puVar1 = 0x12F2FC00;
}
EOF
test_variant "v4 (swapped order)" "$TMPDIR/v4.c"

rm -rf "$TMPDIR"
