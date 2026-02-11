/* state_init_handlers.c -- Early game state machine handlers
 *
 * Functions:
 *   FUN_060088CC (0x060088CC) -- State init: CD play, render setup, callbacks
 *   FUN_06008B34 (0x06008B34) -- State handler: subsystem dispatch + clear
 *   FUN_06008B78 (0x06008B78) -- State handler: pre-race subsystem init
 *   FUN_06008B9C (0x06008B9C) -- State handler: subsystem sequence + clear
 *   FUN_06008BD8 (0x06008BD8) -- State handler: link subsystem init, mode=11
 *   FUN_06008BFC (0x06008BFC) -- State handler: conditional mode advance
 *   FUN_06008E00 (0x06008E00) -- State handler: race setup, mode=13
 *   FUN_06008E48 (0x06008E48) -- State handler: race monitor / abort
 *
 * These are game state machine handlers called from the main loop
 * jump table. Each follows a pattern of calling subsystem functions,
 * setting global mode/state values, and clearing the state flag at
 * 0x06059F44.
 *
 * Shared globals:
 *   0x0605AD10: Mode selector (int)
 *   0x06059F44: State completion flag (int, cleared to 0 on exit)
 *   0x0605A016: Sub-state counter (short)
 *
 * Original addresses: 0x060088CC, 0x06008B34, 0x06008B78, 0x06008B9C,
 *   0x06008BD8, 0x06008BFC, 0x06008E00, 0x06008E48
 */

/* CD command: play/resume */
extern void FUN_06018E70(void);

/* Subsystem initializers */
extern void FUN_0601C978(void);
extern void FUN_060198E0(void);
extern void FUN_06019A48(void);
extern void FUN_06019928(void);
extern void FUN_060196A4(void);
extern void FUN_0601950C(void);

/* Rendering parameter setter (type, value, flags) */
extern void FUN_06014884(int type, int value, int flags);

/* Display/render mode config */
extern void FUN_06018DDC(int arg);

/* VDP1 batch render */
extern void FUN_060210F6(void);

/* Scene callback dispatcher */
extern void FUN_06026CE0(void);

/* VDP rendering state init */
extern void FUN_0600A0C0(void);

/* Subsystem setup (pre-race) */
extern void FUN_06018FA4(void);

/* Engine/physics init */
extern void FUN_0600EC78(void);

/* Loading/init continuation */
extern void FUN_0600F424(void);

/* Link subsystem init */
extern void FUN_0601B160(void);

/* Link subsystem poll (returns nonzero when complete) */
extern int FUN_0601B418(void);

/* Mode selector global */
#define MODE_SELECTOR      (*(volatile int *)0x0605AD10)

/* State completion flag */
#define STATE_DONE_FLAG    (*(volatile int *)0x06059F44)

/* Sub-state counter */
#define SUB_STATE_COUNTER  (*(volatile short *)0x0605A016)

/* Engine state flags (32-bit, OR'd with flag bits) */
#define ENGINE_STATE_FLAGS (*(volatile unsigned int *)0x0605B6D8)

/* Render parameter cache (checked for negative = abort) */
#define RENDER_PARAM_CACHE (*(volatile int *)0x0607EBCC)


/* ================================================================
 * FUN_060088CC -- State Init: CD Play + Render Setup (0x060088CC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060088CC-0x06008908)
 * Pool verified:
 *   0x06008910 = 0x06018E70 (CD play command)
 *   0x06008914 = 0x0601C978 (subsystem init)
 *   0x06008918 = 0xFFFF0000 (render param value)
 *   0x0600891C = 0x06014884 (render param setter)
 *   0x06008920 = 0x06018DDC (display mode config)
 *   0x06008924 = 0x060210F6 (VDP1 batch render)
 *   0x06008928 = 0x0605AD10 (mode selector)
 *   0x0600892C = 0x06026CE0 (scene callback)
 *   0x06008930 = 0x06059F44 (state flag)
 *
 * Initializes a game state: starts CD playback, configures
 * rendering pipeline, triggers VDP1 batch draw, sets mode=1,
 * dispatches scene callbacks, clears state flag.
 *
 * 30 instructions. Saves PR.
 * ================================================================ */
void FUN_060088CC(void)
{
    /* Start CD playback */
    FUN_06018E70();

    /* Initialize subsystem */
    FUN_0601C978();

    /* Set rendering parameter: type=4, value=0xFFFF0000, flags=0 */
    FUN_06014884(4, (int)0xFFFF0000, 0);

    /* Configure display mode */
    FUN_06018DDC(2);

    /* Trigger VDP1 batch render */
    FUN_060210F6();

    /* Set mode selector to 1 */
    MODE_SELECTOR = 1;

    /* Dispatch scene callbacks */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;
}


/* ================================================================
 * FUN_06008B34 -- State Handler: Subsystem Dispatch (0x06008B34)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008B34-0x06008B50)
 * Pool verified:
 *   0x06008B70 = 0x060196A4 (subsystem dispatch A)
 *   0x06008B74 = 0x0601950C (subsystem dispatch B)
 *   0x06008B64 = 0x06026CE0 (scene callback)
 *   0x06008B68 = 0x06059F44 (state flag)
 *
 * Calls two subsystem dispatchers, scene callback, clears flag.
 *
 * 15 instructions. Saves PR.
 * ================================================================ */
void FUN_06008B34(void)
{
    FUN_060196A4();
    FUN_0601950C();
    FUN_06026CE0();
    STATE_DONE_FLAG = 0;
}


/* ================================================================
 * FUN_06008B78 -- State Handler: Pre-Race Subsystem Init (0x06008B78)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008B78-0x06008B9A)
 * Pool verified:
 *   0x06008BBC = 0x0605AD10 (mode selector)
 *   0x06008BC0 = 0x060198E0 (subsystem init)
 *   0x06008BC4 = 0x06026CE0 (scene callback)
 *   0x06008BC8 = 0x06059F44 (state flag)
 *   0x06008BCC = 0x0605A016 (sub-state counter)
 *
 * Sets mode=9, initializes pre-race subsystem, dispatches scene
 * callbacks, clears state flag, sets sub-state to 3.
 *
 * 16 instructions. Saves PR.
 * ================================================================ */
void FUN_06008B78(void)
{
    MODE_SELECTOR = 9;
    FUN_060198E0();
    FUN_06026CE0();
    STATE_DONE_FLAG = 0;
    SUB_STATE_COUNTER = 3;
}


/* ================================================================
 * FUN_06008B9C -- State Handler: Subsystem Sequence (0x06008B9C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008B9C-0x06008BB8)
 * Pool verified:
 *   0x06008BD0 = 0x06019A48 (subsystem sequence A)
 *   0x06008BD4 = 0x06019928 (subsystem sequence B)
 *   0x06008BC4 = 0x06026CE0 (scene callback)
 *   0x06008BC8 = 0x06059F44 (state flag)
 *
 * Runs two subsystem sequences, dispatches scene callback,
 * clears state flag.
 *
 * 14 instructions. Saves PR.
 * ================================================================ */
void FUN_06008B9C(void)
{
    FUN_06019A48();
    FUN_06019928();
    FUN_06026CE0();
    STATE_DONE_FLAG = 0;
}


/* ================================================================
 * FUN_06008BD8 -- State Handler: Link Subsystem Init (0x06008BD8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008BD8-0x06008BFA)
 * Pool verified:
 *   0x06008C38 = 0x0605AD10 (mode selector)
 *   0x06008C3C = 0x0601B160 (link subsystem init)
 *   0x06008C40 = 0x06026CE0 (scene callback)
 *   0x06008C44 = 0x06059F44 (state flag)
 *   0x06008C48 = 0x0605A016 (sub-state counter)
 *
 * Sets mode=11 (link/VS mode), initializes link subsystem,
 * dispatches scene callbacks, clears state flag, sets sub-state=3.
 *
 * 18 instructions. Saves PR.
 * ================================================================ */
void FUN_06008BD8(void)
{
    MODE_SELECTOR = 11;
    FUN_0601B160();
    FUN_06026CE0();
    STATE_DONE_FLAG = 0;
    SUB_STATE_COUNTER = 3;
}


/* ================================================================
 * FUN_06008BFC -- State Handler: Conditional Mode Advance (0x06008BFC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008BFC-0x06008C12)
 * Pool verified:
 *   0x06008C4C = 0x0601B418 (link subsystem poll)
 *   0x06008C38 = 0x0605AD10 (mode selector)
 *
 * Polls link subsystem. If result is nonzero, advances mode to 6.
 * Otherwise does nothing (stays in current state for next frame).
 *
 * 10 instructions. Saves PR.
 * ================================================================ */
void FUN_06008BFC(void)
{
    int result = FUN_0601B418();
    if (result != 0) {
        MODE_SELECTOR = 6;
    }
}


/* ================================================================
 * FUN_06008E00 -- State Handler: Race Setup (0x06008E00)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008E00-0x06008E46)
 * Pool verified:
 *   0x06008E84 = 0x0600A0C0 (VDP rendering state init)
 *   0x06008E88 = 0x06018FA4 (subsystem setup)
 *   0x06008E8C = 0x0605AD10 (mode selector)
 *   0x06008E90 = 0x0600EC78 (engine/physics init)
 *   0x06008E94 = 0x060210F6 (VDP1 batch render)
 *   0x06008E98 = 0x0605B6D8 (engine state flags)
 *   0x06008E9C = 0x40000000 (flag bit to OR)
 *   0x06008EA0 = 0x06026CE0 (scene callback)
 *   0x06008EA4 = 0x06059F44 (state flag)
 *   0x06008EA8 = 0x0605A016 (sub-state counter)
 *   0x06008EAC = 0x06018DDC (display mode config -- tail call)
 *
 * Initializes the race state: resets VDP rendering, sets up
 * subsystems, configures engine/physics, triggers batch render,
 * sets engine flag bit 30, dispatches scene callbacks, sets
 * mode=13 / sub-state=3, tail-calls display config(5,5,15).
 *
 * 36 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
void FUN_06008E00(void)
{
    /* Reset VDP rendering state */
    FUN_0600A0C0();

    /* Set up subsystems */
    FUN_06018FA4();

    /* Set mode to 13 (race) */
    MODE_SELECTOR = 13;

    /* Initialize engine/physics */
    FUN_0600EC78();

    /* Trigger VDP1 batch render */
    FUN_060210F6();

    /* Set engine flag bit 30 (0x40000000) */
    ENGINE_STATE_FLAGS = ENGINE_STATE_FLAGS | 0x40000000;

    /* Dispatch scene callbacks */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;

    /* Set sub-state counter to 3 */
    SUB_STATE_COUNTER = 3;

    /* Configure display mode: r4=5, r5=5, r6=15 (tail call) */
    FUN_06018DDC(5);
}


/* ================================================================
 * FUN_06008E48 -- State Handler: Race Monitor / Abort (0x06008E48)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008E48-0x06008E80)
 * Pool verified:
 *   0x06008EB0 = 0x0607EBCC (render parameter cache)
 *   0x06008E8C = 0x0605AD10 (mode selector)
 *   0x06008EA0 = 0x06026CE0 (scene callback)
 *   0x06008EA4 = 0x06059F44 (state flag)
 *   0x06008EB4 = 0x0600F424 (loading/init continuation)
 *   0x06008EB8 = 0x06018E70 (CD play command)
 *
 * Monitors race state: if render param cache is negative, aborts
 * to mode=14 (dispatches callbacks, clears flag). If positive,
 * continues loading via FUN_0600F424. After either path, if
 * mode selector is no longer 13, tail-calls CD play (FUN_06018E70).
 *
 * 28 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
void FUN_06008E48(void)
{
    int val = RENDER_PARAM_CACHE;

    if (val < 0) {
        /* Negative: abort race, set mode=14 */
        MODE_SELECTOR = 14;
        FUN_06026CE0();
        STATE_DONE_FLAG = 0;
    } else {
        /* Positive: continue loading/init */
        FUN_0600F424();
    }

    /* If mode changed from 13, restart CD playback */
    if (MODE_SELECTOR != 13) {
        FUN_06018E70();
    }
}
