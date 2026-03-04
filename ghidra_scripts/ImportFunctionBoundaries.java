// Import Function Boundaries from reimpl/retail/ — Daytona USA '95
//
// Scans reimpl/retail/*.s for .section .text.FUN_XXXXXXXX directives
// and creates functions in Ghidra at any addresses not already detected.
//
// Usage:
//   1. Open daytona_data.iso in CodeBrowser
//   2. Script Manager -> Run this script
//   3. It seeds Ghidra with addresses from the retail assembly source
//
// @category Daytona95
// @author Claude

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.Memory;

import java.io.*;
import java.util.*;
import java.util.regex.*;

public class ImportFunctionBoundaries extends GhidraScript {

    private static final String RETAIL_DIR = "D:/Projects/SaturnReverseTest/reimpl/retail";

    @Override
    public void run() throws Exception {

        println("Scanning " + RETAIL_DIR + " for .section .text.FUN_ directives...");

        // Collect unique function addresses from all .s files
        Set<Long> addresses = new TreeSet<>();
        Pattern pattern = Pattern.compile("\\.section\\s+\\.text\\.FUN_([0-9A-Fa-f]{8})");

        File retailDir = new File(RETAIL_DIR);
        if (!retailDir.isDirectory()) {
            popup("retail/ directory not found: " + retailDir.getAbsolutePath());
            return;
        }

        for (File f : retailDir.listFiles()) {
            if (!f.getName().endsWith(".s")) continue;
            try (BufferedReader br = new BufferedReader(new FileReader(f))) {
                String line;
                while ((line = br.readLine()) != null) {
                    Matcher m = pattern.matcher(line);
                    if (m.find()) {
                        long addr = Long.parseLong(m.group(1), 16);
                        addresses.add(addr);
                    }
                }
            }
        }

        println("Found " + addresses.size() + " unique function addresses in retail/*.s");

        // Get existing functions in Ghidra
        FunctionManager fm = currentProgram.getFunctionManager();
        Set<Long> existing = new HashSet<>();
        FunctionIterator iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function func = iter.next();
            existing.add(func.getEntryPoint().getOffset());
        }
        println("Ghidra currently has " + existing.size() + " functions");

        // Create missing functions
        int created = 0;
        int failed = 0;
        int skipped = 0;
        Memory mem = currentProgram.getMemory();

        for (long addrVal : addresses) {
            String name = String.format("FUN_%08X", addrVal);

            if (existing.contains(addrVal)) {
                skipped++;
                continue;
            }

            Address addr = currentProgram.getAddressFactory()
                .getDefaultAddressSpace().getAddress(addrVal);

            if (!mem.contains(addr)) {
                println("  SKIP " + name + " @ " + addr + " - not in memory");
                failed++;
                continue;
            }

            try {
                disassemble(addr);
            } catch (Exception e) {
                // May already be disassembled
            }

            try {
                Function func = createFunction(addr, name);
                if (func != null) {
                    created++;
                    if (created <= 20 || created % 50 == 0) {
                        println("  Created " + name + " @ " + addr);
                    }
                } else {
                    println("  FAIL  " + name + " @ " + addr + " - createFunction returned null");
                    failed++;
                }
            } catch (Exception e) {
                println("  ERROR " + name + " @ " + addr + " - " + e.getMessage());
                failed++;
            }

            if (monitor.isCancelled()) {
                println("Cancelled by user.");
                break;
            }
        }

        println("");
        println("=== Summary ===");
        println("  Known from retail/:  " + addresses.size());
        println("  Already in Ghidra:   " + skipped);
        println("  Newly created:       " + created);
        println("  Failed:              " + failed);
        println("  Ghidra total now:    " + (existing.size() + created));
    }
}
