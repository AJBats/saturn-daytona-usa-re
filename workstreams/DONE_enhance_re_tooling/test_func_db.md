# Persistent Function Database — Test Results

Tool: `tools/func_db.py`
Database: `build/function_db.json`

## Pipeline

```
python tools/func_db.py init --map reimpl/build/daytona.map
python tools/func_db.py merge-sdk build/sdk_matches_filtered.json
python tools/func_db.py merge-hw build/hw_tags.json
python tools/func_db.py merge-strings build/string_scan_for_merge.txt
python tools/func_db.py stats
```

## Results

```
Total entries:          4610
Human-named:            1272 (27.6%)
With SDK matches:       20
With HW tags:           7
With string data:       249
With any tag:           276
```

### Validated Features

- **init**: Populates from daytona.map (5883 raw symbols, filtered to 4369 in code range)
- **merge-sdk**: Imports 24 SDK matches from sdk_match.py JSON output
- **merge-hw**: Imports HW register tags from hw_tag.py JSON output
- **merge-strings**: Imports 249 string references from string_scan.py output
- **query**: Lookup by address, shows all metadata (name, tags, SDK matches, HW, strings)
- **stats**: Summary of database contents with tag distribution
- **export**: Full text dump for review

### Query Example

```
$ python tools/func_db.py query 0x060433D0
Address: 0x060433D0
Name:    None
Tags:    sdk
SDK Matches:
  MTH_Sin [SEGA_SAT.A] exact
```

### Known Limitations

- HW tag merge only matches 7/130 tagged functions. The TU file names (e.g., `vdp1_init`)
  must match either a symbol name in the map or a FUN_XXXXXXXX address. Many TU names are
  human-readable and don't appear as top-level symbols. Future: reverse-lookup via .s file
  → first .global symbol → address.
- String merge creates new entries for string addresses that aren't function boundaries.
  These are data locations, not functions, but still useful for cross-referencing.
- Database lives in build/ (gitignored). Rebuild with the pipeline above after any tool update.

## Verdict: PASS

Core functionality works. Aggregates outputs from all three RE tools into
one queryable database. The HW merge coverage will improve with better
TU-to-address mapping.
