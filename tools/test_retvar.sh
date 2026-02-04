#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/test_retvar_$$
mkdir -p "$TMPDIR"

# Test FUN_06002510 - current vs return-optimized
cat > "$TMPDIR/v1.c" << 'CEOF'
extern int DAT_06002554;
extern int DAT_06002556;
extern int FUN_060023e6();
extern int FUN_060024d8();
int FUN_06002510(param_1)
    short param_1;
{
  int uVar1;
  short local_8;
  for (local_8 = DAT_06002554; (int)(unsigned int)local_8 < (int)DAT_06002556; local_8 = local_8 + param_1)
  {
    FUN_060024d8((int)(short)local_8);
    FUN_060023e6();
  }
  FUN_060024d8((int)DAT_06002556);
  uVar1 = FUN_060023e6();
  return uVar1;
}
CEOF

cat > "$TMPDIR/v2.c" << 'CEOF'
extern int DAT_06002554;
extern int DAT_06002556;
extern int FUN_060023e6();
extern int FUN_060024d8();
int FUN_06002510(param_1)
    short param_1;
{
  short local_8;
  for (local_8 = DAT_06002554; (int)(unsigned int)local_8 < (int)DAT_06002556; local_8 = local_8 + param_1)
  {
    FUN_060024d8((int)(short)local_8);
    FUN_060023e6();
  }
  FUN_060024d8((int)DAT_06002556);
  return FUN_060023e6();
}
CEOF

for v in v1 v2; do
  "$CC1" -quiet -O2 -m2 -mbsr "$TMPDIR/$v.c" -o "$TMPDIR/$v.s" 2>/dev/null
  grep -P '^\t[a-z]' "$TMPDIR/$v.s" > "$TMPDIR/$v.full"
  echo "=== $v ==="
  wc -l < "$TMPDIR/$v.full"
  cat -n "$TMPDIR/$v.full"
  echo ""
done

echo "=== diff ==="
diff "$TMPDIR/v1.full" "$TMPDIR/v2.full"

rm -rf "$TMPDIR"
