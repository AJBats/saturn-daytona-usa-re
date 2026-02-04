#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

compare() {
  local label="$1"
  $CC1 -quiet -O2 -m2 -mbsr /tmp/t_loop.c -o /tmp/t_loop.s 2>/dev/null
  if [ $? -ne 0 ]; then echo "  [$label] COMPILE ERROR"; return; fi
  local OUR=$(tr -d '\r' < /tmp/t_loop.s | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//')
  local EXP=$(tr -d '\r' < "$TDIR/FUN_0602760C.expected" | sed '/^$/d')
  if [ "$OUR" = "$EXP" ]; then
    echo "  [$label] >>> MATCH!"
  else
    local oc=$(echo "$OUR" | wc -l); local ec=$(echo "$EXP" | wc -l)
    echo "  [$label] delta=$((oc - ec)) ($oc vs $ec)"
  fi
  echo "  asm:"
  tr -d '\r' < /tmp/t_loop.s | grep -P '^\t[a-z]'
  echo ""
}

echo "=== Expected ==="
tr -d '\r' < "$TDIR/FUN_0602760C.expected" | sed '/^$/d'
echo ""

echo "=== Current ==="
cat > /tmp/t_loop.c << 'EOF'
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3--;
  do {
    *(char *)(param_1 + iVar2) = *(char *)(param_2 + iVar2);
    iVar2++;
  } while (param_3 > iVar2);
  return;
}
EOF
compare "current"

echo "=== Variant: test-before-inc ==="
cat > /tmp/t_loop.c << 'EOF'
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int i = 0;
  param_3--;
  for (;;) {
    char byte = *(char *)(param_2 + i);
    int more = (param_3 > i);
    *(char *)(param_1 + i) = byte;
    if (!more) break;
    i++;
  }
}
EOF
compare "test-before-inc"

echo "=== Variant: while top-tested ==="
cat > /tmp/t_loop.c << 'EOF'
void FUN_0602760c(p1, p2, n)
    char *p1;
    char *p2;
    int n;
{
  int i = 0;
  n--;
  while (n > i) {
    char b = *(p2 + i);
    *(p1 + i) = b;
    i++;
  }
}
EOF
compare "while-top"

echo "=== Variant: for loop n-1 ==="
cat > /tmp/t_loop.c << 'EOF'
void FUN_0602760c(p1, p2, n)
    char *p1;
    char *p2;
    int n;
{
  int i;
  for (i = 0; i < n - 1; i++) {
    *(p1 + i) = *(p2 + i);
  }
}
EOF
compare "for-loop"

echo "=== Variant: comma expr ==="
cat > /tmp/t_loop.c << 'EOF'
void FUN_0602760c(p1, p2, n)
    char *p1;
    char *p2;
    int n;
{
  int i = 0;
  n--;
  do {
    *(p1 + i) = *(p2 + i);
  } while (i++, n > i);
}
EOF
compare "comma"
