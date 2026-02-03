#!/bin/bash
set -e

PROJ="/mnt/d/Projects/SaturnReverseTest"
BUILD_DIR="$HOME/gcc26-rebuild"

echo "=== Clean rebuild ==="
rm -rf "$BUILD_DIR"
cp -r "$PROJ/tools/gcc-2.6.3" "$BUILD_DIR"
cd "$BUILD_DIR"

sed -i -- 's/include <varargs.h>/include <stdarg.h>/g' *.c
./configure --target=sh-hms --prefix="$BUILD_DIR/install" \
    --with-gnu-as --host=i386-pc-linux --build=i386-pc-linux \
    --quiet 2>&1 | tail -2

# Touch ALL pre-generated files
touch c-gperf.h c-parse.c c-parse.h c-parse.y \
      cp/parse.h cp/parse.c cp/parse.y 2>/dev/null || true

echo ""
echo "=== Build cc1 ==="
make -j"$(nproc)" cc1 CFLAGS="-std=gnu89 -m32 -static -fcommon -DHAVE_STRERROR" 2>&1 | tail -3

if [ ! -x cc1 ]; then
    echo "FAIL"
    exit 1
fi
echo "cc1 built successfully"

echo ""
echo "=== Test output ==="
cat > /tmp/test_regs.c << 'EOF'
extern void call(int);
extern int read_val(void);
int foo(a, b)
    int a, b;
{
    int x;
    x = read_val();
    call(a + b + x);
    return x;
}
int bar(a, b, c, d)
    int a, b, c, d;
{
    int x, y, z, w, v;
    x = read_val();
    y = read_val();
    z = read_val();
    w = read_val();
    v = read_val();
    call(a + b + c + d + x + y + z + w + v);
    return x + y + z + w + v;
}
EOF
./cc1 -quiet -O2 /tmp/test_regs.c -o /tmp/test_regs.s

echo "--- Full output ---"
cat /tmp/test_regs.s

echo ""
echo "--- Daytona binary reference (FUN_060030FC) ---"
echo "Prologue: mov.l r14,@-r15 / r13 / r12 / r11 / r10 / sts.l pr,@-r15"
echo "Epilogue: lds.l @r15+,pr / mov.l @r15+,r10 / r11 / r12 / r13 / rts + mov.l @r15+,r14"

echo ""
echo "=== Copy to project ==="
mkdir -p "$PROJ/tools/gcc26-build"
cp cc1 "$PROJ/tools/gcc26-build/cc1"
echo "Done"
