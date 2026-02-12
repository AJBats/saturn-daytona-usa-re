#!/usr/bin/env python3
"""Find files that ICE with -Os on sh-elf-gcc 13."""
import subprocess, os, glob

GCC = "/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin/sh-elf-gcc"
INCDIR = "/mnt/d/Projects/SaturnReverseTest/reimpl/include"
SRCDIR = "/mnt/d/Projects/SaturnReverseTest/reimpl/src"

files = sorted(os.listdir(r"d:\Projects\SaturnReverseTest\reimpl\src"))
c_files = [f for f in files if f.endswith(".c")]

ice_files = []
ok = 0

for fname in c_files:
    src = f"{SRCDIR}/{fname}"
    cmd = f"{GCC} -m2 -mb -Os -Wall -nostdlib -ffreestanding -fno-builtin -I{INCDIR} -c {src} -o /tmp/test.o 2>&1"
    r = subprocess.run(["wsl", "-d", "Ubuntu", "--", "bash", "-c", cmd],
                       capture_output=True, text=True, timeout=60)
    out = r.stdout + r.stderr
    if "confused" in out or "internal compiler error" in out:
        ice_files.append(fname)
        print(f"ICE: {fname}")
    else:
        ok += 1

print(f"\nOK: {ok}, ICE: {len(ice_files)}")
if ice_files:
    print("Files needing -O2 fallback:", ", ".join(ice_files))
