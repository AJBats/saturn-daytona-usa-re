/* asm_misc.c -- Miscellaneous ASM-only functions
 *
 * FUN_06046E48 was previously here as a 116KB ASM blob, but it's actually
 * the data region at the tail of the original binary (parameter tables,
 * lookup tables, strings), not executable code. The disassembler mislabeled
 * it as a function.
 *
 * The correct data is restored by tools/patch_data_holes.py post-build,
 * which fills unclaimed binary regions with original APROG.BIN bytes.
 *
 * We provide a minimal symbol so the linker doesn't complain about
 * undefined references (though nothing actually calls this "function").
 */
__asm__(



    ".section .text.FUN_06046E48, \"ax\"\n"

    ".global _FUN_06046E48\n"



    ".section .text.FUN_06046e48, \"ax\"\n"

    ".global _FUN_06046e48\n"
    ".type _FUN_06046E48, @function\n"
    "_FUN_06046E48:\n"
    "_FUN_06046e48:\n"
    "rts\n"
    "nop\n"
);
