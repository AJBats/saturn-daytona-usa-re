#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/reorder_$$
mkdir -p "$TMPDIR"

# FUN_0601164A: try preloading the constant
echo "=== FUN_0601164A variants ==="
echo "Expected:"
tr -d '\r' < "$TDIR/FUN_0601164A.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'
echo ""

# Variant A: preload constant into variable
cat > "$TMPDIR/v_a.c" << 'EOF'
void FUN_0601164a()
{
  short val = 0x0200;
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)(0x25F800A4 + -10) = val;
  return;
}
EOF

echo "Variant A (preload constant):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_a.c" -o "$TMPDIR/v_a.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_a.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

# Variant B: use absolute addresses directly
cat > "$TMPDIR/v_b.c" << 'EOF'
void FUN_0601164a()
{
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)0x25F8009A = 0x0200;
  return;
}
EOF

echo "Variant B (absolute addresses):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_b.c" -o "$TMPDIR/v_b.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_b.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

# Variant C: use volatile short
cat > "$TMPDIR/v_c.c" << 'EOF'
void FUN_0601164a()
{
  short val;
  val = 0x0200;
  *(int *)0x25F800A4 = 0x12F2FC00;
  *(volatile short *)(0x25F800A4 - 10) = val;
  return;
}
EOF

echo "Variant C (volatile short, precomputed val):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_c.c" -o "$TMPDIR/v_c.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_c.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

# Variant D: cast to int* + displacement, different pointer arithmetic
cat > "$TMPDIR/v_d.c" << 'EOF'
void FUN_0601164a()
{
  char *puVar1;
  short val;
  puVar1 = (char *)0x25F800A4;
  val = 0x0200;
  *(int *)puVar1 = 0x12F2FC00;
  puVar1 = puVar1 + -10;
  *(short *)puVar1 = val;
  return;
}
EOF

echo "Variant D (separate pointer adjust + preload):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_d.c" -o "$TMPDIR/v_d.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_d.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

echo "=== FUN_06026E0C: try swapping init order ==="
echo "Expected:"
tr -d '\r' < "$TDIR/FUN_06026E0C.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'
echo ""

# Original has puVar1 = 0x10000 first, then puVar2 = load
# Try: load first, then set constant
cat > "$TMPDIR/v_e.c" << 'EOF'
void FUN_06026e0c()
{
  int *puVar2;
  int val;
  puVar2 = *(int **)0x06089EDC;
  val = 0x00010000;
  puVar2[1] = 0;
  *puVar2 = val;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = val;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = val;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  return;
}
EOF

echo "Variant E (load before constant):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_e.c" -o "$TMPDIR/v_e.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_e.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

# Variant F: set puVar1 after load
cat > "$TMPDIR/v_f.c" << 'EOF'
void FUN_06026e0c()
{
  int val;
  int *puVar2;
  puVar2 = *(int **)0x06089EDC;
  val = 0x00010000;
  *puVar2 = val;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = val;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = val;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  return;
}
EOF

echo "Variant F (original store order with int val):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_f.c" -o "$TMPDIR/v_f.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_f.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

echo "=== FUN_060285E0: try different arg expression order ==="
echo "Expected:"
tr -d '\r' < "$TDIR/FUN_060285E0.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'
echo ""

# Try computing the shift early
cat > "$TMPDIR/v_g.c" << 'EOF'
extern void FUN_060283b8();
void FUN_060285e0(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  int shifted;
  shifted = (unsigned int)(param_2 << 8) >> 2;
  FUN_060283b8(8,(shifted + param_1) << 1,0xFFFFF000,param_3);
  return;
}
EOF

echo "Variant G (precompute shift):"
$CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/v_g.c" -o "$TMPDIR/v_g.s" 2>/dev/null
tr -d '\r' < "$TMPDIR/v_g.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""

rm -rf "$TMPDIR"
