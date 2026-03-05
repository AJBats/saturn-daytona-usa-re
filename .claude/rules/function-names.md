# Function Names Are Guesses

All ~1,000 named functions in reimpl/src/ are LLM-generated guesses from annotation
passes. They are hypotheses, not facts.

## Rules

1. **Never use a function name as evidence of what it does.** Reason from instructions,
   data flow, and empirical observation — not from names.
2. **VERIFIED means human-approved.** A function only reaches VERIFIED when the user
   has reviewed the emulator evidence and approved graduation. Some existing VERIFIED
   functions in `reimpl/src/*.s` predate the current tier system — they stand but new
   graduations require the full process (see `ground-truth.md`).
3. **`asm/*.s` is entirely LLM-generated.** Everything in there — names, comments,
   VERIFIED tags — is inference. None of it counts as ground truth.
4. **When analyzing code, say "this function is named X" not "this function does X"**
   unless you have empirical evidence.
