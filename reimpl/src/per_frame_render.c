/* per_frame_render.c -- Per-frame rendering dispatch
 *
 * Functions:
 *   FUN_0600C286 (0x0600C286) -- Per-frame render dispatch: obj update + conditional draw
 *
 * This function is called via function pointer table at 0x06063574
 * (stored in batch_game_logic_b.c). It runs the object system update,
 * game logic update, then dispatches to one of two rendering paths
 * based on a mode flag at 0x06082A26. Finally writes 0xFFFF to
 * the cartridge hardware register at 0x21800000.
 *
 * Original addresses: 0x0600C286
 */

/* Object system update (defined in batch_obj_system_3c.c) */
extern void FUN_0603c000(void);

/* Game logic per-frame update (defined in batch_game_logic_a.c) */
extern void FUN_0600afb2(void);

/* Rendering path A -- mode 0 (defined in batch_game_core.c) */
extern int FUN_06006cdc(void);

/* Rendering path B -- mode 1 (defined in batch_game_core.c) */
extern int FUN_06006a9c(void);


/* ================================================================
 * FUN_0600C286 -- Per-Frame Render Dispatch (0x0600C286)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600C286-0x0600C300)
 * Pool verified:
 *   0x0600C2DC = 0x0603C000 (obj system update)
 *   0x0600C2E0 = 0x0600AFB2 (game logic update)
 *   0x0600C2E4 = 0x06082A26 (render mode flag)
 *   0x0600C2E8 = 0x06006CDC (render path A)
 *   0x0600C378 = 0x06006A9C (render path B)
 *   0x0600C37C = 0x0000FFFF (cart reset value)
 *   0x0600C380 = 0x21800000 (cart hardware register)
 *
 * Calls obj system + game logic updates, checks render mode flag:
 *   0 -> render path A (FUN_06006CDC)
 *   1 -> render path B (FUN_06006A9C)
 * Writes 0xFFFF to cart register on exit.
 *
 * 22 instructions (incl. delay slots + pool). Saves PR.
 * ================================================================ */
void FUN_0600C286(void)
{
    FUN_0603c000();
    FUN_0600afb2();

    unsigned char flag = *(volatile unsigned char *)0x06082A26;
    if (flag == 0) {
        FUN_06006cdc();
    } else if (flag == 1) {
        FUN_06006a9c();
    }

    *(volatile short *)0x21800000 = (short)0xFFFF;
}
