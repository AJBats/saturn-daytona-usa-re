# Ghidra Script: Export decompiler output for all functions
# Run from Ghidra's Script Manager (Window > Script Manager, then load this file)
#
# Output: writes to <project_dir>/decomp_all.txt
#   Each function gets a header with address, name, size, and instruction count,
#   followed by the decompiled C code.

import os
from ghidra.app.decompiler import DecompInterface

decomp = DecompInterface()
decomp.openProgram(currentProgram)

listing = currentProgram.getListing()
fm = currentProgram.getFunctionManager()

outpath = os.path.join(os.path.dirname(str(currentProgram.getDomainFile().getProjectLocator().getProjectDir())), "decomp_all.txt")

# Also try a simpler path if that fails
try:
    outfile = open(outpath, "w")
except:
    outpath = os.path.join(os.path.expanduser("~"), "decomp_all.txt")
    outfile = open(outpath, "w")

print("Writing to: " + outpath)

funcs = fm.getFunctions(True)  # True = forward iteration
count = 0

for func in funcs:
    entry = func.getEntryPoint()
    name = func.getName()
    body = func.getBody()
    size = body.getNumAddresses()

    # Count instructions
    insn_count = 0
    has_jsr = False
    has_pr_save = False
    insns = listing.getInstructions(body, True)
    while insns.hasNext():
        insn = insns.next()
        mnemonic = insn.getMnemonicString()
        insn_count += 1
        if mnemonic in ["jsr", "bsr"]:
            has_jsr = True
        if "sts" in mnemonic.lower() and "pr" in str(insn).lower():
            has_pr_save = True

    # Decompile
    results = decomp.decompileFunction(func, 30, monitor)
    if results.decompileCompleted():
        code = results.getDecompiledFunction().getC()
    else:
        code = "// DECOMPILE FAILED\n"

    # Write entry
    leaf = "LEAF" if (not has_jsr and not has_pr_save) else "CALL"
    outfile.write("=" * 60 + "\n")
    outfile.write("FUNC %s  addr=0x%s  size=%d  insns=%d  type=%s\n" % (name, entry, size, insn_count, leaf))
    outfile.write("=" * 60 + "\n")
    outfile.write(code)
    outfile.write("\n\n")

    count += 1
    if count % 50 == 0:
        print("Processed %d functions..." % count)

outfile.close()
decomp.dispose()
print("Done! Exported %d functions to %s" % (count, outpath))
