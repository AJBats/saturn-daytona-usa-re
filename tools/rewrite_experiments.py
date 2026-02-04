#!/usr/bin/env python3
"""Try multiple C source variations for delta=0 functions and test which ones improve/pass"""
import subprocess
import os
import re
import tempfile

CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
TMPDIR = "/tmp/rewrite_exp"

os.makedirs(TMPDIR, exist_ok=True)

def extract_opcodes(asmfile):
    with open(asmfile) as f:
        lines = f.read().replace('\r', '').split('\n')
    ops = []
    for line in lines:
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            op = line.strip().split()[0]
            ops.append(op)
    return ops

def extract_full_asm(asmfile):
    with open(asmfile) as f:
        lines = f.read().replace('\r', '').split('\n')
    result = []
    for line in lines:
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            result.append(line.strip())
    return result

def count_diffs(a, b):
    diffs = 0
    for i in range(min(len(a), len(b))):
        if a[i] != b[i]:
            diffs += 1
    diffs += abs(len(a) - len(b))
    return diffs

def test_variant(base, c_source, flags=None):
    if flags is None:
        flags = "-O2 -m2 -mbsr"
        flagsfile = os.path.join(TDIR, base + '.flags')
        if os.path.exists(flagsfile):
            with open(flagsfile) as f:
                flags = f.read().strip().replace('\r', '')

    expfile = os.path.join(TDIR, base + '.expected')
    with open(expfile) as f:
        expected = [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

    cleanc = os.path.join(TMPDIR, base + '_var.c')
    with open(cleanc, 'w') as f:
        f.write(c_source)

    outfile = os.path.join(TMPDIR, base + '_var.s')
    cmd = f"{CC1} -quiet {flags} {cleanc} -o {outfile}"
    subprocess.run(cmd, shell=True, capture_output=True, text=True)

    ops = extract_opcodes(outfile)
    full = extract_full_asm(outfile)
    diffs = count_diffs(ops, expected)
    delta = len(ops) - len(expected)
    return ops, full, expected, diffs, delta

# ============================================================
# FUN_06018EC8: Byte extraction (4 diffs)
# Expected has extu.b + mov.b in rts delay slot
# ============================================================
print("=" * 70)
print("FUN_06018EC8 - Byte extraction experiments")
print("=" * 70)

variants_18ec8 = {
    "v0_original": """\
void FUN_06018ec8()
{
  short val = 0x00E0;
  *(volatile char *)0x25B00217 = (unsigned char)val;
  *(volatile char *)0x25B00237 = (char)val;
}
""",
    "v1_no_volatile": """\
void FUN_06018ec8()
{
  short val = 0x00E0;
  *(char *)0x25B00217 = (unsigned char)val;
  *(char *)0x25B00237 = (char)val;
}
""",
    "v2_uchar_var": """\
void FUN_06018ec8()
{
  unsigned char val;
  val = 0xE0;
  *(char *)0x25B00217 = val;
  *(char *)0x25B00237 = val;
}
""",
    "v3_int_val": """\
void FUN_06018ec8()
{
  int val = 0xE0;
  *(char *)0x25B00217 = val;
  *(char *)0x25B00237 = val;
}
""",
    "v4_short_cast": """\
void FUN_06018ec8()
{
  short raw = 0x00E0;
  unsigned char val = (unsigned char)raw;
  *(char *)0x25B00217 = val;
  *(char *)0x25B00237 = val;
}
""",
    "v5_extu_force": """\
void FUN_06018ec8()
{
  unsigned char val = (unsigned char)(short)0x00E0;
  *(char *)0x25B00217 = val;
  *(char *)0x25B00237 = val;
}
""",
    "v6_volatile_read": """\
void FUN_06018ec8()
{
  short val = 0x00E0;
  unsigned char bval = val;
  *(volatile char *)0x25B00217 = bval;
  *(volatile char *)0x25B00237 = bval;
}
""",
    "v7_param_style": """\
void FUN_06018ec8()
{
  *(char *)0x25B00217 = (unsigned char)0xE0;
  *(char *)0x25B00237 = (unsigned char)0xE0;
}
""",
}

for name, src in sorted(variants_18ec8.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_06018EC8", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if diffs > 0 and diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_0600C970: Range check (11 diffs)
# Expected has cmp/ge+bf, cmp/gt+bt (two separate comparisons)
# ============================================================
print("=" * 70)
print("FUN_0600C970 - Range check experiments")
print("=" * 70)

variants_c970 = {
    "v0_original": """\
int FUN_0600c970(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;

  iVar1 = 0x01EC;
  iVar2 = *(int *)(param_1 + iVar1);

  if ((0x44 < iVar2) && (iVar2 < 99)) {
    *(int *)(param_1 + 0xc) =
         *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 + -0x45) << 1));
  }

  return iVar1;
}
""",
    "v1_nested_ifs": """\
int FUN_0600c970(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;

  iVar1 = 0x01EC;
  iVar2 = *(int *)(param_1 + iVar1);

  if (0x44 < iVar2) {
    if (iVar2 < 99) {
      *(int *)(param_1 + 0xc) =
           *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 + -0x45) << 1));
    }
  }

  return iVar1;
}
""",
    "v2_nested_ge_lt": """\
int FUN_0600c970(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;

  iVar1 = 0x01EC;
  iVar2 = *(int *)(param_1 + iVar1);

  if (iVar2 >= 0x45) {
    if (iVar2 < 99) {
      *(int *)(param_1 + 0xc) =
           *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 - 0x45) << 1));
    }
  }

  return iVar1;
}
""",
    "v3_nested_ge_le": """\
int FUN_0600c970(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;

  iVar1 = 0x01EC;
  iVar2 = *(int *)(param_1 + iVar1);

  if (iVar2 >= 0x45) {
    if (iVar2 <= 98) {
      *(int *)(param_1 + 0xc) =
           *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 - 0x45) << 1));
    }
  }

  return iVar1;
}
""",
    "v4_shift_instead_of_add": """\
int FUN_0600c970(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;

  iVar1 = 0x01EC;
  iVar2 = *(int *)(param_1 + iVar1);

  if (iVar2 >= 0x45) {
    if (iVar2 < 99) {
      *(int *)(param_1 + 0xc) =
           *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 - 0x45) * 2));
    }
  }

  return iVar1;
}
""",
}

for name, src in sorted(variants_c970.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_0600C970", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if diffs > 0 and diffs <= 12:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_060122F4: add vs sub, cmp/gt vs cmp/ge (8 diffs)
# ============================================================
print("=" * 70)
print("FUN_060122F4 - Sign convention experiments")
print("=" * 70)

variants_122f4 = {
    "v0_original": """\
void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1] - 0x2999;
  base[1] = val4;

  val8 = base[2] - 0x4000;
  base[2] = val8;

  if (val4 < 0x00020000) {
    base[1] = 0x00020000;
  }

  if (val8 < 0x0004CCCC) {
    base[2] = 0x0004CCCC;
  }

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
""",
    "v1_explicit_sub_le": """\
void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1];
  val4 = val4 - 0x2999;
  base[1] = val4;

  val8 = base[2];
  val8 = val8 - 0x4000;
  base[2] = val8;

  if (val4 < 0x00020000) {
    base[1] = 0x00020000;
  }

  if (val8 < 0x0004CCCC) {
    base[2] = 0x0004CCCC;
  }

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
""",
    "v2_ge_comparison": """\
void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1] - 0x2999;
  base[1] = val4;

  val8 = base[2] - 0x4000;
  base[2] = val8;

  if (!(val4 >= 0x00020000)) {
    base[1] = 0x00020000;
  }

  if (!(val8 >= 0x0004CCCC)) {
    base[2] = 0x0004CCCC;
  }

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
""",
    "v3_ge_skip": """\
void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1] - 0x2999;
  base[1] = val4;

  val8 = base[2] - 0x4000;
  base[2] = val8;

  if (val4 >= 0x00020000)
    goto skip1;
  base[1] = 0x00020000;
skip1:

  if (val8 >= 0x0004CCCC)
    goto skip2;
  base[2] = 0x0004CCCC;
skip2:

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
""",
}

for name, src in sorted(variants_122f4.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_060122F4", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if diffs > 0 and diffs <= 10:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_0602760C/1E/30: Delay slot fill (bt.s vs bt)
# ============================================================
print("=" * 70)
print("FUN_0602760C - Delay slot experiments")
print("=" * 70)

variants_760c = {
    "v0_original": """\
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
""",
    "v1_while_loop": """\
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int i;
  param_3 = param_3 - 1;
  i = 0;
  while (i < param_3) {
    param_1[i] = param_2[i];
    i = i + 1;
  }
}
""",
    "v2_for_loop": """\
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int i;
  for (i = 0; i < param_3 - 1; i++) {
    param_1[i] = param_2[i];
  }
}
""",
    "v3_ptr_style": """\
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int n = param_3 - 1;
  int i = 0;
  do {
    param_1[i] = param_2[i];
    i++;
  } while (i < n);
}
""",
}

for name, src in sorted(variants_760c.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_0602760C", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if diffs > 0 and diffs <= 8:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()
