#include "game.h"

/*
 * stubs.c -- Placeholder implementations for untranslated functions
 *
 * Each stub is a no-op. As functions get translated into their own .c files,
 * delete the corresponding stub here. The linker will error on duplicates,
 * which tells you what to remove.
 *
 * To find what a stub should do, check:
 *   1. asm/<subsystem>.s  -- annotated ASM with human-readable descriptions
 *   2. build/aprog.s      -- raw disassembly at the function address
 *   3. src/FUN_XXXXXXXX.c -- existing decomp C (if it exists, for the 886 functions)
 *   4. ghidra_project/decomp_all.txt -- Ghidra decompilation output
 */

/* -- Init subsystem stubs (called by system_init / FUN_060030FC) -- */

/* 0x0603BF7C: Hardware/cache subsystem init
 *
 * Hand-translated from binary at 0x0603BF7C (66 instructions).
 *
 * Initializes cache address array at 0x60000000 (SH-2 on-chip cache SRAM).
 * For each of 4 channels (selected via TIER register bits 7:6), clears 64
 * longword entries at 16-byte stride. Then configures TIER post-flags:
 * clears bits 1,2,3, ORs in param, sets bit 0.
 *
 * TIER = SH-2 Timer Interrupt Enable Register at 0xFFFFFE92.
 * On Saturn, 0x60000000 = cache address/data array (bits 31:29 = 0b011).
 *
 * Called from system_init (FUN_060030FC) with param=0.
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0603BF7C-0x0603BFF6)
 * Pool verified:
 *   0x0603BFFC = 0x60000000 (cache array base)
 * Word pool:
 *   0x0603BFF8 = 0x0100 (256, outer loop limit)
 *   0x0603BFFA = 0xFE92 (sign-ext → 0xFFFFFE92, TIER register)
 *
 * 66 instructions. Saves r9-r13. No PR save (no sub-calls).
 */
void course_system_init(int param)
{
    volatile unsigned char *tier = (volatile unsigned char *)0xFFFFFE92;
    volatile int *cache_base = (volatile int *)0x60000000;
    unsigned char val;
    int channel;   /* 0, 64, 128, 192 = bits 7:6 channel selector */

    /* Step 1: Clear TIER bit 0 (disable timer) */
    val = *tier;
    val &= 0xFE;
    *tier = val;

    /* Step 2: For each of 4 channels, set selector and clear cache entries */
    for (channel = 0; channel < 256; channel += 64) {
        /* Set TIER bits 7:6 to channel selector, keep lower 6 bits */
        val = *tier;
        val &= 0x3F;
        val |= (unsigned char)channel;
        *tier = val;

        /* Clear 64 longword entries at stride 16 bytes (unrolled by 2) */
        {
            volatile int *ptr = cache_base;
            int count = 64;
            while (count > 0) {
                *ptr = 0;
                ptr += 4;    /* +16 bytes */
                *ptr = 0;
                ptr += 4;    /* +16 bytes */
                count -= 2;
            }
        }
    }

    /* Step 3: Post-loop TIER configuration */

    /* Clear bit 3, OR in param */
    val = *tier;
    val &= 0xF7;
    val |= (unsigned char)param;
    *tier = val;

    /* Clear bit 1 */
    val = *tier;
    val &= 0xFD;
    *tier = val;

    /* Clear bit 2 */
    val = *tier;
    val &= 0xFB;
    *tier = val;

    /* Set bit 0 (re-enable timer) */
    val = *tier;
    val = (val & 0xFE) | 0x01;
    *tier = val;
}

/* 0x06034E58: Graphics/rendering setup */
void menu_system_init(void) { }

/* 0x06012CF4: CD subsystem initialization with retry loop
 *
 * Hand-translated from binary at 0x06012CF4 (74 instructions).
 *
 * Initializes the CD subsystem:
 *   1. Clears CD busy flag at 0x06084AEC
 *   2. Sets up config struct at 0x06084360:
 *        [0] = 1, [4] = 80, [8] = 0x0608436C (buffer pointer)
 *   3. Loops calling FUN_0603AC1C(5, 0x06083274, 0x06084360) until result > 2
 *   4. Every 5+ iterations, calls yield callback via *(0x0600026C)
 *
 * The retry-with-yield pattern matches cd_io_retry.c exactly.
 * FUN_0603AC1C is likely a CDC (CD-ROM Controller) library function.
 *
 * Called from system_init (FUN_060030FC).
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012CF4-0x06012D54)
 * Pool verified:
 *   0x06012D5C = 0x0603AC1C (CDC library function)
 *   0x06012D60 = 0x0600026C (yield callback pointer)
 *   0x06012D64 = 0x06084AEC (CD busy flag)
 *   0x06012D68 = 0x06084360 (config struct)
 *   0x06012D6C = 0x0608436C (buffer address)
 *   0x06012D70 = 0x06083274 (data source address)
 *
 * 74 instructions. Saves r9-r14, PR. 4-byte stack frame.
 */
extern int FUN_0603AC1C(int mode, int src, int config);

#if 0 /* game_subsystem_init -- redirected to ASM import via linker PROVIDE */
void game_subsystem_init(void)
{
    volatile unsigned char *cd_flag = (volatile unsigned char *)0x06084AEC;
    volatile int *config = (volatile int *)0x06084360;
    int result;
    int count = 0;

    /* Clear CD busy flag */
    *cd_flag = 0;

    /* Set up config struct */
    config[0] = 1;                       /* mode = 1 */
    config[2] = (int)0x0608436C;         /* buffer pointer (offset +8) */
    config[1] = 80;                      /* sector count? (offset +4) */

    /* Retry loop: call CDC function until result > 2 */
    do {
        result = FUN_0603AC1C(5, (int)0x06083274, (int)0x06084360);
        count++;

        /* Yield every iteration once count reaches 5 */
        if (count >= 5) {
            ((void (*)(void))(*(volatile int *)0x0600026C))();
        }
    } while (result <= 2);
}
#endif /* game_subsystem_init */
/* REMOVED: conflicting alias */ // void FUN_06012CF4(void) __attribute__((alias("game_subsystem_init")));

/* 0x06004A98: Global engine initialization — real code in asm_restored_stubs.c as FUN_06004A98 */
extern void FUN_06004A98(void);
void global_engine_init(void) { FUN_06004A98(); }

/* 0x06012E6A: now in resource_loader.c */

/* 0x06018EE4: Sound system initialization (SCSP + SMPC sound on/off)
 *
 * Hand-translated from binary at 0x06018EE4 (72 instructions).
 *
 * Full sound system bring-up sequence:
 *   1. SMPC: wait for SF idle, issue SNDOFF (command 7)
 *   2. SMPC: wait for command completion
 *   3. Clear 512KB of SCSP sound RAM at 0x25A00000
 *   4. Write 0x0200 to SCSP register at 0x25B00400
 *   5. Load sound driver via FUN_06012E84 (CD→0x25A00000)
 *   6. Load sound data via FUN_06012EBC (CD→0x25A03000)
 *   7. SMPC: wait for SF idle, issue SNDON (command 6)
 *   8. SMPC: wait for command completion
 *   9. Wait for SCSP handshake: poll 0x25A02DBC until == 0x4F4B ("OK")
 *  10. Send two sound configuration commands via FUN_0601D5F4
 *  11. Clear sound state at 0x06086038
 *  12. Tail-call FUN_06018EC8 (write SCSP slot config)
 *
 * SMPC registers:
 *   0x20100063 = SF (Status Flag) — bit 0 = busy
 *   0x2010001F = COMREG (Command Register) — 6=SNDON, 7=SNDOFF
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018EE4-0x06018F72)
 * Pool verified:
 *   0x06018F78 = 0x25A02DBC (SCSP handshake word)
 *   0x06018F7C = 0x20100063 (SMPC SF register)
 *   0x06018F80 = 0x2010001F (SMPC COMREG)
 *   0x06018F84 = 0x25B00400 (SCSP control register)
 *   0x06018F88 = 0x06012E84 (sound driver load)
 *   0x06018F8C = 0x06012EBC (sound data load)
 *   0x06018F90 = 0xAE0600FF (sound config param 1)
 *   0x06018F94 = 0x0601D5F4 (sound command dispatch)
 *   0x06018F98 = 0xAE0007FF (sound config param 2)
 *   0x06018F9C = 0x06086038 (sound state variable)
 *   0x06018FA0 = 0x06018EC8 (SCSP slot config — tail call)
 * Word pool:
 *   0x06018F74 = 0x4F4B ("OK" handshake signature)
 *   0x06018F76 = 0x0200 (SCSP control value)
 *
 * 72 instructions. Saves r11-r14, PR. Tail-calls FUN_06018EC8.
 */

/* SMPC commands */
#define SMPC_CMD_SNDON   6
#define SMPC_CMD_SNDOFF  7

/* SCSP handshake and control (not in saturn.h) */
#define SCSP_HANDSHAKE   (*(volatile unsigned short *)0x25A02DBC)
#define SCSP_CTRL_REG    (*(volatile unsigned short *)0x25B00400)
#define SCSP_OK_SIGNATURE  0x4F4B  /* "OK" */

/* Sub-functions */
extern void FUN_06012E84(void);     /* load sound driver to SCSP RAM */
extern void FUN_06012EBC(void);     /* load sound data to SCSP RAM */
extern void FUN_0601D5F4(int channel, int param);  /* sound command dispatch */
extern void FUN_06018EC8(void);     /* SCSP slot configuration */

#if 0 /* cd_system_init -- redirected to ASM import via linker PROVIDE */
void cd_system_init(void)
{
    /* === Phase 1: SMPC — turn sound OFF === */

    /* Wait for SMPC status flag idle (bit 0 = 0) */
    while ((SMPC_SF & 1) == 1)
        ;

    /* Set SF = 1 (mark command in progress), issue SNDOFF */
    SMPC_SF = 1;
    SMPC_COMREG = SMPC_CMD_SNDOFF;

    /* Wait for command completion (SF bit 0 clears) */
    while ((SMPC_SF & 1) != 0)
        ;

    /* === Phase 2: Clear and load sound RAM === */

    /* Clear 512KB of SCSP sound RAM (inlined from 0x060192B4) */
    {
        volatile unsigned char *p = (volatile unsigned char *)SCSP_RAM_BASE;
        int i = 0x80000;   /* 512KB — original binary value */
        while (i > 0) {
            *p = 0;
            p++;
            i--;
        }
    }

    /* Set SCSP control register */
    SCSP_CTRL_REG = 0x0200;

    /* Load sound driver and data from CD */
    FUN_06012E84();
    FUN_06012EBC();

    /* === Phase 3: SMPC — turn sound ON === */

    /* Wait for SMPC status flag idle */
    while ((SMPC_SF & 1) == 1)
        ;

    /* Set SF = 1, issue SNDON */
    SMPC_SF = 1;
    SMPC_COMREG = SMPC_CMD_SNDON;

    /* Wait for command completion */
    while ((SMPC_SF & 1) != 0)
        ;

    /* === Phase 4: Wait for SCSP handshake === */
    while (SCSP_HANDSHAKE != SCSP_OK_SIGNATURE)
        ;

    /* === Phase 5: Send sound configuration commands === */
    FUN_0601D5F4(15, (int)0xAE0600FF);
    FUN_0601D5F4(15, (int)0xAE0007FF);

    /* Clear sound state variable */
    *(volatile int *)0x06086038 = 0;

    /* === Phase 6: Configure SCSP slots (tail call) === */
    FUN_06018EC8();
}
#endif /* cd_system_init */

/* 0x06005174: Animation/sprite frame init
 * Clears 8 shorts (16 bytes) at 0x06063D98 — animation state buffer.
 * Binary verified at 0x06005174-0x06005196, pool: 0x06005220 = 0x06063D98 */
void object_system_init(void)
{
    volatile short *buf = (volatile short *)0x06063D98;
    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
}

/* 0x0601F936: Sound/audio system init */
void render_system_init(void) { }

/* 0x0601492C: now in vdp1_cmd.c */

/* 0x060149E0: now in game_state_utils.c */

/* -- Main loop stubs -- */

/* per_frame_setup: moved to per_frame_setup.c */

/* -- State handler stubs (32-state machine, we have 18 slots) -- */
/* Original addresses from jump table at 0x0600307C */

/* state_0_handler through state_13_handler: moved to pre_race_state_handlers.c */
/* state_14_handler through state_17_handler: moved to race_state_handlers.c */

/* state_18_handler through state_20_handler: moved to race_state_handlers.c */
/* state_21_handler through state_25_handler: moved to race_state_handlers.c */
/* state_26_handler through state_31_handler: moved to race_state_handlers.c */
