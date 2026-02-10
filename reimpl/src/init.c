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
 *   4. course_system_init(0) -- hardware subsystem init
 *   5. menu_system_init()  -- graphics/rendering init
 *   6. BIOS call via 0x06000344 with params (-1, 0x0083)
 *   7. game_subsystem_init()  -- object/physics setup
 *   8. vdp_init_dispatcher()  -- VDP init dispatcher
 *   9. global_engine_init()  -- engine init
 *  10. game_subsystem_init2()  -- state machine setup
 *  11. sound_timer_init()  -- sound/timer init
 *  12. cd_system_init()  -- camera/viewport init
 *  13. BIOS call via 0x06000344 with params (0xFF7C, 0)
 *  14. object_system_init()  -- animation/sprite init
 *  15. render_system_init()  -- sound system init
 *  16. vdp_system_init_a()  -- game state init
 *  17. vdp_system_init_b()  -- physics parameters init
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
    course_system_init(0);
    menu_system_init();

    /* Phase 6: BIOS call (params -1, 0x0083) */
    BIOS_FUNC_0344(-1, 0x0083);

    /* Phase 7: Object/physics setup */
    game_subsystem_init();

    /* Phase 8: VDP initialization */
    vdp_init_dispatcher();

    /* Phase 9: Engine init */
    global_engine_init();

    /* Phase 10: State machine setup */
    game_subsystem_init2();

    /* Phase 11: Sound/timer init */
    sound_timer_init();

    /* Phase 12: Camera/viewport init */
    cd_system_init();

    /* Phase 13: BIOS call (params 0xFF7C, 0) */
    BIOS_FUNC_0344(0xFF7C, 0);

    /* Phase 14-17: Animation, sound, game state, physics */
    object_system_init();
    render_system_init();
    vdp_system_init_a();
    vdp_system_init_b();

    /* Phase 18: Mark system ready */
    GAME_STATE = 2;
}

void FUN_060030FC(void) __attribute__((alias("system_init")));
