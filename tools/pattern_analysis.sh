#!/bin/bash
# Comprehensive analysis of opcode diff patterns across all failing functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/pattern_$$
mkdir -p "$TMPDIR"

# Collect diff patterns
> "$TMPDIR/all_patterns.txt"
> "$TMPDIR/all_adds.txt"  # opcodes we add (not in original)
> "$TMPDIR/all_removes.txt"  # opcodes we remove (in original but not ours)

total=0
for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && continue

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  # Skip PASS
  diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1 && continue

  total=$((total + 1))

  # Collect added opcodes (in ours, not in original) - lines starting with <
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep '^< ' | sed 's/^< //' >> "$TMPDIR/all_adds.txt"
  # Collect removed opcodes (in original, not in ours) - lines starting with >
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep '^> ' | sed 's/^> //' >> "$TMPDIR/all_removes.txt"

done

echo "Total failing functions analyzed: $total"
echo ""

echo "=== OPCODES WE ADD (not in original) ==="
sort "$TMPDIR/all_adds.txt" | uniq -c | sort -rn | head -30

echo ""
echo "=== OPCODES WE MISS (in original, not ours) ==="
sort "$TMPDIR/all_removes.txt" | uniq -c | sort -rn | head -30

echo ""
echo "=== NET OPCODE BALANCE (add - remove) ==="
# Count each opcode's net contribution
> "$TMPDIR/net.txt"
for opc in $(cat "$TMPDIR/all_adds.txt" "$TMPDIR/all_removes.txt" | sort -u); do
  adds=$(grep -c "^${opc}$" "$TMPDIR/all_adds.txt" || true)
  removes=$(grep -c "^${opc}$" "$TMPDIR/all_removes.txt" || true)
  net=$((adds - removes))
  echo "$net $opc (add=$adds remove=$removes)" >> "$TMPDIR/net.txt"
done
sort -rn "$TMPDIR/net.txt" | head -20
echo "..."
sort -rn "$TMPDIR/net.txt" | tail -20

rm -rf "$TMPDIR"
