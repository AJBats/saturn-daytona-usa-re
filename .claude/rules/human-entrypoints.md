# Human Entrypoints

1. **No ad-hoc testing without a make target or script** — If you edit a file to test something, that edit either gets reverted cleanly or becomes a permanent fixture with a human-friendly command (`make X`, `./script.sh Y`).

2. **Clean house always** — After any investigation, the working tree should be clean. No stray edits, no temporary patches baked into source files. If it's not committed, it doesn't exist.

3. **Entrypoints must be current** — When you touch the build system, validate that existing entrypoints (`make`, `make validate`, `make disc`, `setup.sh`) still work. Stale scripts are worse than no scripts.

4. **Document the command, not the reasoning** — A human should be able to run `make validate` without knowing why the ICF NOP was there. The Makefile is the interface, not the conversation history.

5. **After any commit that touches build infrastructure, run the full entrypoint chain and confirm it passes before moving on.**
