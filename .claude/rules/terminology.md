# Terminology: Primary / Secondary SH-2

The Saturn has two SH-2 CPUs. Sega documentation calls them "master" and "slave."
We don't use those terms in our code, comments, docs, or conversation.

## Our terms

| Saturn docs | We say |
|---|---|
| Master SH-2 | **Primary SH-2** |
| Slave SH-2 | **Secondary SH-2** |

## Where the old terms survive (intentionally)

- **Sega vendor SDK headers** (`tools/cygnus-2.7-96Q3/`) — original files, not ours to edit.
- **Quoted Mednafen trace output** — field names like `master_PC` and `slave_PC` that come
  from the emulator's log format. The surrounding description text uses our terms.
- **Saturn hardware register names** — SMPC commands like `SSHON`/`SSHOFF` stay as-is
  (they're register mnemonics, not prose).

## When interfacing with Sega docs

If you need to reference a Sega API like `slSlaveOn()` or `SPR_InitSlaveSH()`, use
the original function name (it's a symbol) but describe it in our terms:

> `slSlaveOn()` — activates the secondary SH-2.
