#include "saturn.h"
#include "game.h"

/*
 * system_init -- FUN_060030FC
 *
 * Called once at boot. Initializes all Saturn hardware and game subsystems.
 *
 * Sequence from production ASM (0x060030FC-0x060031E0):
 *   1. BIOS call with param 1 (via indirect ptr at 0x06000320)
 *   2. SMPC CKCHG320 -- clock change to 320-pixel mode
 *   3. Memory clear -- zero work RAM regions
 *   4. FUN_0603BF7C(0) -- hardware subsystem init
 *   5. FUN_06034E58()  -- graphics/rendering init
 *   6. BIOS call via 0x06000344 with params (-1, 0x0083)
 *   7. FUN_06012CF4()  -- object/physics setup
 *   8. FUN_06003274()  -- VDP init dispatcher
 *   9. FUN_06004A98()  -- engine init
 *  10. FUN_06012E6A()  -- state machine setup
 *  11. FUN_06003218()  -- sound/timer init
 *  12. FUN_06018EE4()  -- camera/viewport init
 *  13. BIOS call via 0x06000344 with params (0xFF7C, 0)
 *  14. FUN_06005174()  -- animation/sprite init
 *  15. FUN_0601F936()  -- sound system init
 *  16. FUN_0601492C()  -- game state init
 *  17. FUN_060149E0()  -- physics parameters init
 *  18. Set GAME_STATE = 2
 */
void system_init(void)
{
    int *ptr;

    /* Phase 1: BIOS init call (param 1) */
    BIOS_FUNC_0320(1);

    /* Phase 2: SMPC CKCHG320 (clock change to 320-pixel mode) */
    while (SMPC_SF & 0x01)
        ;
    SMPC_SF = 0x01;
    SMPC_COMREG = 25;
    while (SMPC_SF & 0x01)
        ;

    /* Phase 3: Clear work RAM regions */
    for (ptr = MEM_REGION1_START; ptr < MEM_REGION1_END; ptr++)
        *ptr = 0;
    for (ptr = MEM_REGION2_START; ptr < MEM_REGION2_END; ptr++)
        *ptr = 0;

    /* Phase 4-5: Hardware and graphics init */
    FUN_0603BF7C(0);
    FUN_06034E58();

    /* Phase 6: BIOS call (params -1, 0x0083) */
    BIOS_FUNC_0344(-1, 0x0083);

    /* Phase 7: Object/physics setup */
    FUN_06012CF4();

    /* Phase 8: VDP initialization */
    vdp_init_dispatcher();

    /* Phase 9: Engine init */
    FUN_06004A98();

    /* Phase 10: State machine setup */
    FUN_06012E6A();

    /* Phase 11: Sound/timer init */
    sound_timer_init();

    /* Phase 12: Camera/viewport init */
    FUN_06018EE4();

    /* Phase 13: BIOS call (params 0xFF7C, 0) */
    BIOS_FUNC_0344(0xFF7C, 0);

    /* Phase 14-17: Animation, sound, game state, physics */
    FUN_06005174();
    FUN_0601F936();
    FUN_0601492C();
    FUN_060149E0();

    /* Phase 18: Mark system ready */
    GAME_STATE = 2;
}
