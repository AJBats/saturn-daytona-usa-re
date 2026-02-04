#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TMPDIR=/tmp/mulsr_$$
mkdir -p "$TMPDIR"

cat > "$TMPDIR/test_mul.c" << 'EOF'
int test_mul4(x)
    int x;
{
    return x * 4;
}

int test_mul8(x)
    int x;
{
    return x * 8;
}

int test_shl2(x)
    int x;
{
    return x << 2;
}

int test_mul7(x)
    int x;
{
    return x * 7;
}

int test_mul12(x)
    int x;
{
    return x * 12;
}

int test_mul256(x)
    int x;
{
    return x * 256;
}
EOF

echo "=== With -O2 ==="
"$CC1" -quiet -O2 -m2 -mbsr "$TMPDIR/test_mul.c" -o "$TMPDIR/test_mul.s" 2>/dev/null
grep -P '^\t[a-z]|^_' "$TMPDIR/test_mul.s"

rm -rf "$TMPDIR"
