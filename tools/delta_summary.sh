#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/delta_$$
mkdir -p "$TMPDIR"

pass=0; d0=0; dp1=0; dm1=0; dmp=0; dpp=0; skip=0; err=0

for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && { skip=$((skip+1)); continue; }

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  if [ ! -f "$TMPDIR/$base.s" ]; then
    err=$((err+1))
    continue
  fi

  # Extract opcodes
  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" > /dev/null 2>&1; then
    pass=$((pass+1))
  elif [ "$delta" -eq 0 ]; then
    d0=$((d0+1))
  elif [ "$delta" -eq 1 ]; then
    dp1=$((dp1+1))
  elif [ "$delta" -eq -1 ]; then
    dm1=$((dm1+1))
  elif [ "$delta" -lt -1 ]; then
    dmp=$((dmp+1))
  else
    dpp=$((dpp+1))
  fi
done

echo "=== DELTA DISTRIBUTION ==="
echo "PASS:       $pass"
echo "delta=0:    $d0"
echo "delta=+1:   $dp1"
echo "delta=-1:   $dm1"
echo "delta<=-2:  $dmp"
echo "delta>=+2:  $dpp"
echo "compile err: $err"
echo "skip:       $skip"
echo "total:      $((pass+d0+dp1+dm1+dmp+dpp+err+skip))"

rm -rf "$TMPDIR"
