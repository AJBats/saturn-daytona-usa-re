#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

test_compile() {
    local name=$1
    local src=$2
    $CC1 -quiet -O2 -m2 -mbsr "$src" -o "/tmp/${name}.s" 2>&1
    echo "=== $name ==="
    echo -n "insns: "
    grep -cP '^\t[a-z]' "/tmp/${name}.s"
    echo "--- opcodes ---"
    grep -oP '^\t\K[a-z][a-z0-9./]*' "/tmp/${name}.s" | tr '\n' ','
    echo ""
    echo "--- full asm ---"
    cat "/tmp/${name}.s"
    echo ""
    echo "================"
}

# Test FUN_0600D336 fix
cat > /tmp/test_0600D336.c << 'CEOF'
void FUN_0600d336()
{
  int baseA;
  int baseB;

  baseA = 0x06078900;
  baseB = baseA + 0x0268;

  if ((*(unsigned int *)0x0607EBC4 & 0x00200000) == 0) {
    if (*(int *)(baseA + 0x01F4) < *(int *)(baseB + 0x01F4)) {
      *(int *)(baseA + 0x0224) = 1;
      *(int *)(baseB + 0x0224) = 0;
    } else {
      *(int *)(baseA + 0x0224) = 0;
      *(int *)(baseB + 0x0224) = 1;
    }
  }
}
CEOF
test_compile "FUN_0600D336" "/tmp/test_0600D336.c"

# Test FUN_060283B8 fix
cat > /tmp/test_060283B8.c << 'CEOF'
int FUN_060283b8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    unsigned int param_4;
{
  int base;
  int offset;

  base = **(int **)(0x06028614 + param_1) + param_2;
  offset = 14;
  do {
    *(unsigned short *)(base + offset) = (param_4 & 0xf) + param_3;
    param_4 >>= 4;
    offset -= 2;
  } while (offset >= 0);
  return 0;
}
CEOF
test_compile "FUN_060283B8" "/tmp/test_060283B8.c"

# Test FUN_0601DB84 fix
cat > /tmp/test_0601DB84.c << 'CEOF'
void FUN_0601db84()
{
  int counter;
  int flag;

  flag = 1;
  counter = 0x000186A0;
  do {
    counter = counter - 1;
    if (counter == 0) {
      *(int *)0x06086050 = flag;
      return;
    }
  } while (*(int *)0x25A02C20 != 0);
}
CEOF
test_compile "FUN_0601DB84" "/tmp/test_0601DB84.c"

# Test FUN_0603B878 fix
cat > /tmp/test_0603B878.c << 'CEOF'
int FUN_0603b878(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;
  int *pp;

  pp = (int *)0x060A4D14;
  iVar2 = 0;
  iVar1 = *(int *)pp + 0x0C3C;
  goto check;
loop:
  if (iVar1 == param_1) goto done;
  iVar1 = iVar1 + 0x00F0;
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < **(int **)pp) goto loop;
done:
  if (iVar2 == **(int **)pp) {
    iVar1 = 0;
  }
  return iVar1;
}
CEOF
test_compile "FUN_0603B878" "/tmp/test_0603B878.c"
