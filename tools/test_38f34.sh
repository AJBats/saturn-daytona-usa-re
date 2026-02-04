#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/test_38f34_$$
mkdir -p "$TMPDIR"

test_variant() {
  local label="$1"
  local cfile="$2"

  "$CC1" -quiet -O2 -m2 -mbsr "$cfile" -o "$TMPDIR/out.s" 2>/dev/null
  [ ! -f "$TMPDIR/out.s" ] && { echo "$label: COMPILE ERROR"; return; }

  grep -P '^\t[a-z]' "$TMPDIR/out.s" > "$TMPDIR/out.full"
  sed 's/\t/ /g' < "$TMPDIR/out.full" | awk '{print $1}' > "$TMPDIR/out.opcodes"
  tr -d '\r' < "$TESTDIR/FUN_06038F34.expected" > "$TMPDIR/out.exp"

  ours=$(wc -l < "$TMPDIR/out.opcodes")
  orig=$(wc -l < "$TMPDIR/out.exp")
  delta=$((ours - orig))

  if diff -q "$TMPDIR/out.opcodes" "$TMPDIR/out.exp" >/dev/null 2>&1; then
    echo "$label: *** PASS *** (ours=$ours)"
  else
    ndiffs=$(diff "$TMPDIR/out.opcodes" "$TMPDIR/out.exp" | grep -c '^[<>]')
    echo "$label: FAIL delta=$delta diffs=$ndiffs"
  fi
  echo "--- full asm ---"
  cat -n "$TMPDIR/out.full"
  echo ""
}

# Variant 1: original (current)
cat > "$TMPDIR/v1.c" << 'EOF'
void FUN_06038f34()
{
  *(short *)0x060635B4 = 0;
  *(int *)0x060635B8 = 1;
  *(int *)0x060635BC = 0;
  *(int *)0x060635C0 = 0;
  *(int *)0x060635C4 = 0;
  *(int *)0x060635C8 = 0;
}
EOF
test_variant "v1 (current)" "$TMPDIR/v1.c"

# Variant 2: use variables for constants
cat > "$TMPDIR/v2.c" << 'EOF'
void FUN_06038f34()
{
  int zero = 0;
  int one = 1;
  *(short *)0x060635B4 = zero;
  *(int *)0x060635B8 = one;
  *(int *)0x060635BC = zero;
  *(int *)0x060635C0 = zero;
  *(int *)0x060635C4 = zero;
  *(int *)0x060635C8 = zero;
}
EOF
test_variant "v2 (variables)" "$TMPDIR/v2.c"

# Variant 3: group stores by value
cat > "$TMPDIR/v3.c" << 'EOF'
void FUN_06038f34()
{
  *(short *)0x060635B4 = 0;
  *(int *)0x060635BC = 0;
  *(int *)0x060635C0 = 0;
  *(int *)0x060635C4 = 0;
  *(int *)0x060635C8 = 0;
  *(int *)0x060635B8 = 1;
}
EOF
test_variant "v3 (grouped)" "$TMPDIR/v3.c"

# Variant 4: use base pointer with offsets
cat > "$TMPDIR/v4.c" << 'EOF'
void FUN_06038f34()
{
  int *base = (int *)0x060635B4;
  *(short *)base = 0;
  base[1] = 1;
  base[2] = 0;
  base[3] = 0;
  base[4] = 0;
  base[5] = 0;
}
EOF
test_variant "v4 (base pointer)" "$TMPDIR/v4.c"

rm -rf "$TMPDIR"
