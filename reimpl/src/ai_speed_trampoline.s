/* VERIFIED: called every physics frame during racing (part of player_physics_main pipeline)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   117 calls during LEFT (baseline 39, +78) — same delta as player_physics_main
 * Date: 2026-02-28
 */

    .section .text.FUN_0600C8CC


    .global ai_speed_trampoline
    .type ai_speed_trampoline, @function
ai_speed_trampoline:
    mov.l r14, @-r15
    mov r4, r14
