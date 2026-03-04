// Export Decompiled C for All Functions — Daytona USA '95
//
// Iterates every function in the current program and writes decompiled C
// output to ghidra_reference/FUN_XXXXXXXX.c (one file per function).
//
// Runs entirely inside Ghidra's JVM — much faster than MCP round-trips.
//
// Usage:
//   1. Open daytona_data.iso in CodeBrowser
//   2. Script Manager -> Run this script
//   3. Files written to D:/Projects/SaturnReverseTest/ghidra_reference/
//
// @category Daytona95
// @author Claude

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.util.task.TaskMonitor;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ExportDecompiledAll extends GhidraScript {

    private static final String OUT_DIR = "D:/Projects/SaturnReverseTest/ghidra_reference";

    @Override
    public void run() throws Exception {

        File outDir = new File(OUT_DIR);
        outDir.mkdirs();

        println("Exporting decompiled C for all functions");
        println("Output directory: " + outDir.getAbsolutePath());

        // Set up decompiler
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        FunctionManager fm = currentProgram.getFunctionManager();
        int total = fm.getFunctionCount();
        int done = 0;
        int success = 0;
        int failed = 0;
        int skipped = 0;

        FunctionIterator iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function func = iter.next();
            done++;

            if (monitor.isCancelled()) {
                println("Cancelled by user at " + done + "/" + total);
                break;
            }

            // Normalize name to FUN_XXXXXXXX format
            String addr = String.format("%08X", func.getEntryPoint().getOffset());
            String normName = "FUN_" + addr.toUpperCase();
            File outFile = new File(outDir, normName + ".c");

            // Skip if already exists
            if (outFile.exists() && outFile.length() > 0) {
                skipped++;
                continue;
            }

            // Decompile
            DecompileResults result = decomp.decompileFunction(func, 30, monitor);

            if (result != null && result.getDecompiledFunction() != null) {
                String cCode = result.getDecompiledFunction().getC();
                if (cCode != null && !cCode.isEmpty()) {
                    try (PrintWriter pw = new PrintWriter(new FileWriter(outFile))) {
                        pw.println("/* " + normName + "  0x" + addr.toUpperCase() + " */");
                        pw.println();
                        pw.print(cCode);
                    }
                    success++;
                    if (success <= 20 || success % 100 == 0) {
                        println("  [" + done + "/" + total + "] " + normName + " OK");
                    }
                } else {
                    println("  [" + done + "/" + total + "] " + normName + " EMPTY");
                    failed++;
                }
            } else {
                String errMsg = (result != null) ? result.getErrorMessage() : "null result";
                println("  [" + done + "/" + total + "] " + normName + " FAIL: " + errMsg);
                failed++;
            }
        }

        decomp.dispose();

        println("");
        println("=== Export Summary ===");
        println("  Total functions: " + total);
        println("  Exported:        " + success);
        println("  Skipped (exist): " + skipped);
        println("  Failed:          " + failed);
    }
}
