// Ghidra Java script: GetData.java
// Get data type and value at an address
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.Reference;

public class GetData extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: GetData.java <address_hex>");
            return;
        }

        String addrStr = args[0];
        if (addrStr.startsWith("0x")) {
            addrStr = addrStr.substring(2);
        }
        Address addr = toAddr(Long.parseLong(addrStr, 16));

        println("=== Data at 0x" + addr + " ===");

        Data data = getDataAt(addr);
        if (data != null) {
            println("Type: " + data.getDataType());
            println("Value: " + data.getValue());
            println("Length: " + data.getLength() + " bytes");
        } else {
            println("No data defined at this address");

            // Try to read raw bytes
            byte[] bytes = getBytes(addr, 4);
            if (bytes != null) {
                StringBuilder sb = new StringBuilder();
                for (byte b : bytes) {
                    sb.append(String.format("%02X ", b & 0xFF));
                }
                println("Raw bytes: " + sb.toString());
            }
        }

        Symbol sym = getSymbolAt(addr);
        if (sym != null) {
            println("Symbol: " + sym.getName());
        }

        println("");
        println("References TO this address:");
        Reference[] refsTo = getReferencesTo(addr);
        int count = 0;
        for (Reference ref : refsTo) {
            if (count++ >= 20) {
                println("  ... and " + (refsTo.length - 20) + " more");
                break;
            }
            println("  0x" + ref.getFromAddress() + " (" + ref.getReferenceType() + ")");
        }
    }
}
