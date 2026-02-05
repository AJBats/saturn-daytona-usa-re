# Dashboard Skill

## Purpose

Dashboards provide stable, canonical views of project metrics. They live in `dashboard/` and are the source of truth for project status.

## Core Principles

### 1. Stable Tables, Not Session Logs

**Wrong approach** (chaotic):
```markdown
## Session Updates
- 2026-02-05: Fixed FUN_06005174, now PASS
- 2026-02-05: FUN_06018EC8 improved to delta=-1
- 2026-02-04: Added 5 new functions...
```

**Right approach** (stable):
```markdown
| Function | Status | Delta | Notes |
|----------|--------|-------|-------|
| FUN_06005174 | PASS | 0 | Fixed displacement store |
| FUN_06018EC8 | FAIL | -1 | Delay slot filled |
```

### 2. Full Catalogue, Update In-Place

Every dashboard table should be a **complete enumeration** of its domain:
- Function status dashboard: ALL functions, one row each
- Boot testing dashboard: ALL tested functions
- Compilation dashboard: Summary counts covering all files

When something changes, **update the existing row** - don't append a new entry.

### 3. Counts Derive From Tables

Summary counts at the top should be calculable from the detailed table below:
```markdown
## Summary
- **PASS**: 53 / 867 (6.1%)   <-- derived from table below

## Function Status
| Function | Status | ... |
```

If you update a row in the table, update the summary count too.

## Dashboard Files

| File | Domain | Key Columns |
|------|--------|-------------|
| `asm_matching.md` | Test harness results | Status, Delta, Category |
| `boot_testing.md` | Boot test results | Boot status, Notes |
| `compilation.md` | C source compilation | Compile success counts |

## Creating a New Dashboard

1. Define the domain (what's being tracked)
2. Create a complete table with one row per item
3. Add summary counts at top derived from table
4. Add `*Last updated: YYYY-MM-DD*` footer

## Updating a Dashboard

1. Find the existing row for the item being updated
2. Modify that row's columns in place
3. Recalculate summary counts if needed
4. Update the `*Last updated*` date

## Example: Function Status Dashboard

```markdown
# Function Status Dashboard

## Summary
- **PASS**: 53 / 867 (6.1%)
- **FAIL delta=0**: 46 (scheduling)
- **FAIL delta<0**: 373 (better optimization)
- **FAIL delta>0**: 386 (register allocation)

## All Functions

| Function | Status | Delta | Category | Notes |
|----------|--------|-------|----------|-------|
| FUN_06003000 | FAIL | +3 | reg_alloc | Main entry |
| FUN_06005174 | PASS | 0 | - | Fixed 2026-02-05 |
| FUN_06018EC8 | FAIL | -1 | better_opt | Delay slot |
| ... | ... | ... | ... | ... |

---
*Last updated: 2026-02-05*
```

## Anti-Patterns

- Session-based update sections ("Today's changes...")
- Appending new rows instead of updating existing ones
- Orphan counts that don't match table data
- Multiple entries for the same item
- Changelog-style formatting
