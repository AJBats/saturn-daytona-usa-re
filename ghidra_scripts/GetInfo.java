// Ghidra Java script: GetInfo.java
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.Reference;
import java.util.Set;

public class GetInfo extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: GetInfo.java <address_hex>");
            println("Example: GetInfo.java 0x06028560");
            return;
        }

        String addrStr = args[0];
        if (addrStr.startsWith("0x")) {
            addrStr = addrStr.substring(2);
        }
        Address addr = toAddr(Long.parseLong(addrStr, 16));

        println("=== Address: 0x" + addr + " ===");

        Function func = getFunctionAt(addr);
        if (func != null) {
            println("");
            println("FUNCTION: " + func.getName());
            println("Entry: 0x" + func.getEntryPoint());
            println("Signature: " + func.getSignature());
            println("Size: " + func.getBody().getNumAddresses() + " bytes");

            println("");
            println("CALLERS (references TO this function):");
            Reference[] refsTo = getReferencesTo(addr);
            for (Reference ref : refsTo) {
                Function callerFunc = getFunctionContaining(ref.getFromAddress());
                String callerName = (callerFunc != null) ? callerFunc.getName() : "???";
                println("  0x" + ref.getFromAddress() + " in " + callerName);
            }

            println("");
            println("CALLEES (functions THIS calls):");
            Set<Function> called = func.getCalledFunctions(monitor);
            for (Function callee : called) {
                println("  " + callee.getName() + " at 0x" + callee.getEntryPoint());
            }
        } else {
            println("No function at this address");
            Data data = getDataAt(addr);
            if (data != null) {
                println("DATA: " + data + " (type: " + data.getDataType() + ")");
            } else {
                println("No data defined at this address");
            }
        }

        Symbol sym = getSymbolAt(addr);
        if (sym != null) {
            println("");
            println("SYMBOL: " + sym.getName() + " (type: " + sym.getSymbolType() + ")");
        }
    }
}
