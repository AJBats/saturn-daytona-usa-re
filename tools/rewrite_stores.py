#!/usr/bin/env python3
"""Try store reordering experiments for FUN_06026E0C and similar functions"""
import subprocess
import os
import re

CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
TMPDIR = "/tmp/store_exp"

os.makedirs(TMPDIR, exist_ok=True)

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

    with open(outfile) as f:
        lines = f.read().replace('\r', '').split('\n')
    ops = []
    full = []
    for line in lines:
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            full.append(line.strip())
            ops.append(line.strip().split()[0])

    diffs = sum(1 for i in range(min(len(ops), len(expected))) if ops[i] != expected[i])
    diffs += abs(len(ops) - len(expected))
    delta = len(ops) - len(expected)
    return ops, full, expected, diffs, delta

# ============================================================
# FUN_06026E0C: Store reordering
# Expected: mov.l(const), mov(zero), mov.l(ptr), mov.l(deref), ...
# Ours:     mov.l(const), mov.l(ptr), mov.l(deref), mov(zero), ...
# ============================================================
print("=" * 70)
print("FUN_06026E0C - Store materialization order experiments")
print("=" * 70)

variants = {
    "v0_original": """\
void FUN_06026e0c()
{
  char *puVar1;
  int *puVar2;

  puVar1 = 0x00010000;
  puVar2 = *(int **)0x06089EDC;
  puVar2[1] = 0;
  *puVar2 = puVar1;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = puVar1;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = puVar1;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  return;
}
""",
    "v1_zero_first": """\
void FUN_06026e0c()
{
  int zero;
  int val;
  int *puVar2;

  val = 0x00010000;
  zero = 0;
  puVar2 = *(int **)0x06089EDC;
  puVar2[1] = zero;
  *puVar2 = val;
  puVar2[2] = zero;
  puVar2[3] = zero;
  puVar2[4] = val;
  puVar2[5] = zero;
  puVar2[6] = zero;
  puVar2[7] = zero;
  puVar2[8] = val;
  puVar2[9] = zero;
  puVar2[10] = zero;
  puVar2[0xb] = zero;
  return;
}
""",
    "v2_reorder_ptr_last": """\
void FUN_06026e0c()
{
  int *puVar2;

  puVar2 = *(int **)0x06089EDC;
  puVar2[1] = 0;
  *puVar2 = 0x00010000;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0x00010000;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0x00010000;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  return;
}
""",
    "v3_array_init": """\
void FUN_06026e0c()
{
  int val;
  int *p;

  val = 0x00010000;
  p = *(int **)0x06089EDC;
  *p = val; p[1] = 0; p[2] = 0; p[3] = 0;
  p[4] = val; p[5] = 0; p[6] = 0; p[7] = 0;
  p[8] = val; p[9] = 0; p[10] = 0; p[11] = 0;
  return;
}
""",
    "v4_field_first": """\
void FUN_06026e0c()
{
  int *puVar2;

  puVar2 = *(int **)0x06089EDC;
  *puVar2 = 0x00010000;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0x00010000;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0x00010000;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  return;
}
""",
}

for name, src in sorted(variants.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_06026E0C", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if 0 < diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_06035C80: Call then store
# ============================================================
print("=" * 70)
print("FUN_06035C80 - Call+store ordering experiments")
print("=" * 70)

variants_c80 = {
    "v0_original": """\
extern void FUN_06035c6e();

void FUN_06035c80()
{
  FUN_06035c6e(0x0BE1);
  *(short *)0x06063590 = 0;
  return;
}
""",
    "v1_precompute": """\
extern void FUN_06035c6e();

void FUN_06035c80()
{
  short zero;
  zero = 0;
  FUN_06035c6e(0x0BE1);
  *(short *)0x06063590 = zero;
  return;
}
""",
    "v2_volatile_store": """\
extern void FUN_06035c6e();

void FUN_06035c80()
{
  FUN_06035c6e(0x0BE1);
  *(volatile short *)0x06063590 = 0;
  return;
}
""",
    "v3_int_store": """\
extern void FUN_06035c6e();

void FUN_06035c80()
{
  FUN_06035c6e(0x0BE1);
  {
    short *p = (short *)0x06063590;
    short v = 0;
    *p = v;
  }
  return;
}
""",
}

for name, src in sorted(variants_c80.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_06035C80", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if 0 < diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_0603F8B8: Struct write with return value timing
# ============================================================
print("=" * 70)
print("FUN_0603F8B8 - Return value timing experiments")
print("=" * 70)

variants_f8b8 = {
    "v0_original": """\
int * FUN_0603f8b8(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
    int *param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    int param_6;
    int param_7;
{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[4] = param_6;
  param_1[5] = param_7;
  return param_1;
}
""",
    "v1_return_first": """\
int * FUN_0603f8b8(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
    int *param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    int param_6;
    int param_7;
{
  int *ret = param_1;
  ret[0] = param_2;
  ret[1] = param_3;
  ret[2] = param_4;
  ret[3] = param_5;
  ret[4] = param_6;
  ret[5] = param_7;
  return ret;
}
""",
    "v2_void_cast": """\
int * FUN_0603f8b8(p, a, b, c, d, e, f)
    int *p;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
{
  p[0] = a;
  p[1] = b;
  p[2] = c;
  p[3] = d;
  p[4] = e;
  p[5] = f;
  return p;
}
""",
}

for name, src in sorted(variants_f8b8.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_0603F8B8", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if 0 < diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_06040954: shll2 vs lds.l ordering after call
# ============================================================
print("=" * 70)
print("FUN_06040954 - Post-call instruction ordering experiments")
print("=" * 70)

variants_0954 = {
    "v0_original": """\
extern int FUN_06040964();

int
FUN_06040954()
{
    return FUN_06040964() << 11;
}
""",
    "v1_explicit_steps": """\
extern int FUN_06040964();

int
FUN_06040954()
{
    int val;
    val = FUN_06040964();
    val = val << 11;
    return val;
}
""",
    "v2_unsigned": """\
extern unsigned int FUN_06040964();

unsigned int
FUN_06040954()
{
    return FUN_06040964() << 11;
}
""",
}

for name, src in sorted(variants_0954.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_06040954", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if 0 < diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()

# ============================================================
# FUN_0603F4CC: add vs mov ordering before call
# ============================================================
print("=" * 70)
print("FUN_0603F4CC - Pre-call arg ordering experiments")
print("=" * 70)

variants_f4cc = {
    "v0_original": """\
extern void FUN_0603F3F6();

int
FUN_0603F4CC(a, b)
int a;
int b;
{
    short buf[2];
    FUN_0603F3F6(buf, b, 2);
    return buf[0];
}
""",
    "v1_param_first": """\
extern void FUN_0603F3F6();

int
FUN_0603F4CC(a, b)
int a;
int b;
{
    short buf[2];
    int n = 2;
    FUN_0603F3F6(buf, b, n);
    return buf[0];
}
""",
    "v2_explicit_alloc": """\
extern void FUN_0603F3F6();

int
FUN_0603F4CC(a, b)
int a;
int b;
{
    short buf[2];
    short *p = buf;
    FUN_0603F3F6(p, b, 2);
    return *p;
}
""",
}

for name, src in sorted(variants_f4cc.items()):
    ops, full, expected, diffs, delta = test_variant("FUN_0603F4CC", src)
    status = "PASS!" if diffs == 0 else f"{diffs} diffs (d={delta})"
    print(f"  {name}: {status}")
    if 0 < diffs <= 6:
        for i in range(max(len(full), len(expected))):
            o = full[i] if i < len(full) else "---"
            e = expected[i] if i < len(expected) else "---"
            op = ops[i] if i < len(ops) else "---"
            marker = " <--" if op != e else ""
            print(f"    {i+1}: {o:<35s} | {e:<10s}{marker}")
    print()
