# Memory Scanner — Test Results

Feature: H1 (Memory scanner)
Tool: `tools/mem_scan.py`

## Implementation

Cheat Engine-style memory scanner with 4 modes:
- **exact**: Search for specific value (8/16/32-bit, big/little endian)
- **delta**: Compare two dumps (increased/decreased/changed/unchanged)
- **range**: Search for values in [lo, hi]
- **text**: Search for ASCII strings

Supports candidate narrowing (re-scan only previous hits via --candidates).
Default endianness is big (Saturn SH-2 native).

## Testing

### Text Search: PASS
```
python tools/mem_scan.py text wram_high.bin --string "DAYTONA"
Found 13 matches (game title, disc labels, error messages, save data headers)
```

### Exact Value Search: PASS
```
python tools/mem_scan.py exact wram_high.bin --value 0x2000 --width 16
Found 106 matches for 0x2000 (DOWN button bitmask)
```

### Candidate Narrowing: PASS
Re-scanning with --candidates preserves all 106 hits (same dump = same results).

### Delta Scan: PASS (synthetic test)
Created two 256-byte dumps with known changes:
- offset 0x10: 100 → 120 (increased) — detected by `--delta-mode increased`
- offset 0x20: 3 → 3 (unchanged) — NOT detected by increased/decreased
- offset 0x30: 50 → 40 (decreased) — detected by `--delta-mode decreased`

### Range Search: PASS
```
python tools/mem_scan.py range wram_high.bin --lo 0x0100 --hi 0x0200 --width 16
Found 12,349 matches in range [256, 512]
```

## Intended Workflow

```bash
# 1. Dump WRAM while gear is 3rd
bot.send_and_wait("dump_region wram_high /tmp/gear3.bin", "ok dump_region")

# 2. Shift to 4th gear, dump again
bot.send_and_wait("dump_region wram_high /tmp/gear4.bin", "ok dump_region")

# 3. Find addresses where value increased by 1
python tools/mem_scan.py delta gear3.bin gear4.bin -m increased -w 8 -o candidates.json

# 4. Shift to 2nd gear, dump, narrow
python tools/mem_scan.py exact gear2.bin -v 2 -w 8 -c candidates.json -o narrowed.json

# 5. Found: gear address in WRAM. Set watchpoint to find writing function.
```

## Verdict: PASS
