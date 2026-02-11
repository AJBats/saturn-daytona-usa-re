/* state_init_handlers.c -- Early game state machine handlers
 *
 * Functions:
 *   FUN_06008938 (0x06008938) -- State handler: game session init (full)
 *   FUN_0600893C (0x0600893C) -- State handler: game session init (body)
 *   FUN_060088CC (0x060088CC) -- State init: CD play, render setup, callbacks
 *   FUN_06008B34 (0x06008B34) -- State handler: subsystem dispatch + clear
 *   FUN_06008B78 (0x06008B78) -- State handler: pre-race subsystem init
 *   FUN_06008B9C (0x06008B9C) -- State handler: subsystem sequence + clear
 *   FUN_06008BD8 (0x06008BD8) -- State handler: link subsystem init, mode=11
 *   FUN_06008BFC (0x06008BFC) -- State handler: conditional mode advance
 *   FUN_06008B04 (0x06008B04) -- State handler: CD play + mode=7 setup
 *   FUN_06008C14 (0x06008C14) -- State handler: mode transition dispatch
 *   FUN_06008C76 (0x06008C76) -- State handler: conditional mode dispatch
 *   FUN_06008D74 (0x06008D74) -- State handler: countdown + button check
 *   FUN_06008A18 (0x06008A18) -- State handler: attract mode / title timeout
 *   FUN_06008CCC (0x06008CCC) -- State handler: pre-attract init (prologue)
 *   FUN_06008CD0 (0x06008CD0) -- State handler: pre-attract init (body)
 *   FUN_06009C48 (0x06009C48) -- State handler: post-race gameplay
 *   FUN_06009E60 (0x06009E60) -- State handler: post-race transition
 *   FUN_06009F10 (0x06009F10) -- State handler: counter transition
 *   FUN_06008E00 (0x06008E00) -- State handler: race setup, mode=13
 *   FUN_06008E48 (0x06008E48) -- State handler: race monitor / abort
 *   FUN_06009DD0 (0x06009DD0) -- State handler: race end setup, mode=27
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
 *   0x06008B04, 0x06008BD8, 0x06008BFC, 0x06008C76,
 *   0x06008E00, 0x06008E48, 0x06009DD0
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

/* Pre-race subsystem setup */
extern void FUN_060193F4(void);

/* Post-race subsystem setup */
extern void FUN_060190B8(void);

/* Mode transition check (returns nonzero when transition complete) */
extern int FUN_0601F8C0(void);

/* VDP2 flag check (returns nonzero if complete) */
extern int FUN_0601F900(void);

/* Sound/display subsystem */
extern void FUN_0601D3C0(void);

/* Session/sound init */
extern void FUN_06018A3C(void);

/* Race/engine init */
extern void FUN_0600EB14(void);

/* Graphics palette init */
extern void FUN_06033AAC(void);

/* VDP1 command clear */
extern void FUN_0600A140(void);

/* Splash/overlay display */
extern void FUN_0600330A(void);

/* Session communication init */
extern void FUN_0601AE80(void);

/* Per-frame subsystem update */
extern void FUN_0600A1F6(void);

/* Graphics state reset (alternate) */
extern void FUN_06033BC8(void);

/* VDP2 display update */
extern void FUN_0601FD74(void);

/* Rendering pipeline update */
extern void FUN_0600DE40(void);

/* Scene/object update dispatch */
extern void FUN_0600A914(void);

/* Car physics per-frame update */
extern void FUN_060055BC(void);

/* Timed display/render sequence (param, mode) */
extern void FUN_0600338C(int param, int mode);

/* Post-frame render finalize */
extern void FUN_0600BFFC(void);

/* Session result display */
extern void FUN_0601AEB6(void);

/* Per-frame tail call (VDP sync + return) */
extern void FUN_060078DC(void);

/* Display subsystem shutdown */
extern void FUN_0601D2DC(void);

/* Sound engine reset */
extern void FUN_0601B074(void);

/* CD audio stop/fade */
extern void FUN_06018FF8(void);

/* VDP1 sprite setup (pre-display) */
extern void FUN_06014A42(void);

/* Results screen update */
extern void FUN_0601DF88(void);

/* Results screen animation */
extern void FUN_0601DBB8(void);

/* AI/object position update */
extern void FUN_0600DF66(void);

/* Score/results display */
extern void FUN_0600BB94(void);

/* Triple display overlay (3 display addr params) */
extern void FUN_060053AC(int addr_c, int addr_b, int addr_a);

/* Course-specific display effect */
extern void FUN_060033E6(void);

/* End-of-race cleanup */
extern void FUN_0600A084(void);

/* Post-race subsystem transition */
extern void FUN_06019058(void);

/* VDP command channel clear (takes channel ID) */
extern void FUN_0602853E(int channel);

/* Splash screen / overlay init */
extern void FUN_060032D4(void);

/* Per-frame scene update (alternate) */
extern void FUN_0600A294(void);

/* 2-player mode display setup */
extern void FUN_06033EA8(void);

/* VDP1 attribute setup (post-mode-transition) */
extern void FUN_060149E0(void);

/* VDP command reset */
extern void FUN_06028560(void);

/* Rendering subsystem init */
extern void FUN_06012F80(void);

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

/* Mode override flag (byte, cleared after use) */
#define MODE_OVERRIDE_FLAG (*(volatile unsigned char *)0x0605E0A2)

/* Course identification register (16-bit) */
#define COURSE_ID_REG      (*(volatile unsigned short *)0x06063DA0)

/* Button input state (16-bit, bit 8 = start) */
#define BUTTON_INPUT_STATE (*(volatile unsigned short *)0x06063D9A)


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


/* ================================================================
 * FUN_06008B04 -- State Handler: CD Play + Mode 7 Setup (0x06008B04)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008B04-0x06008B32)
 * Pool verified:
 *   0x06008B54 = 0x06018E70 (CD play command)
 *   0x06008B58 = 0x0605AD10 (mode selector)
 *   0x06008B5C = 0x060193F4 (pre-race subsystem setup)
 *   0x06008B60 = 0x060210F6 (VDP1 batch render)
 *   0x06008B64 = 0x06026CE0 (scene callback)
 *   0x06008B68 = 0x06059F44 (state flag)
 *   0x06008B6C = 0x0605A016 (sub-state counter)
 *
 * Starts CD playback, sets mode=7, initializes pre-race subsystem,
 * triggers VDP1 render, dispatches callbacks, clears flag, sub-state=3.
 *
 * 24 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
void FUN_06008B04(void)
{
    FUN_06018E70();
    MODE_SELECTOR = 7;
    FUN_060193F4();
    FUN_060210F6();
    FUN_06026CE0();
    STATE_DONE_FLAG = 0;
    SUB_STATE_COUNTER = 3;
}


/* ================================================================
 * FUN_06008C76 -- State Handler: Conditional Mode Dispatch (0x06008C76)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008C76-0x06008CB0)
 * Pool verified:
 *   0x06008CBC = 0x0601F900 (VDP2 flag check)
 *   0x06008CC0 = 0x0605AD10 (mode selector)
 *   0x06008CB4 = 0x0605E0A2 (mode override flag)
 *   0x06008CC4 = 0x060149E0 (VDP1 attribute setup)
 *   0x06008CC8 = 0x06026CE0 (scene callback)
 *
 * Checks VDP2 completion. If not done, returns immediately.
 * If done, checks byte flag at 0x0605E0A2:
 *   - flag==0: mode=4, setup VDP1 attrs, dispatch callbacks
 *   - flag!=0: mode=6
 * Either way, clears the flag byte.
 *
 * 30 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
void FUN_06008C76(void)
{
    int result = FUN_0601F900();
    if (result == 0)
        return;

    if (MODE_OVERRIDE_FLAG == 0) {
        MODE_SELECTOR = 4;
        FUN_060149E0();
        FUN_06026CE0();
    } else {
        MODE_SELECTOR = 6;
    }
    MODE_OVERRIDE_FLAG = 0;
}


/* ================================================================
 * FUN_06009DD0 -- State Handler: Race End Setup (0x06009DD0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06009DD0-0x06009E00)
 * Pool verified:
 *   0x06009E38 = 0x060190B8 (post-race subsystem setup)
 *   0x06009E3C = 0x0605AD10 (mode selector)
 *   word pool at 0x06009E34 = 0x0258 (600 = 10sec timer)
 *   0x06009E40 = 0x0607EBCC (render param cache)
 *   0x06009E44 = 0x06028560 (VDP command reset)
 *   0x06009E48 = 0x06012F80 (rendering subsystem init)
 *   0x06009E4C = 0x0605A016 (sub-state counter)
 *   0x06009E50 = 0x06018DDC (display mode config -- tail call)
 *
 * Sets mode=27 (race end), stores 600 (10 second timer) to render
 * cache, resets VDP commands, inits rendering subsystem, sets
 * sub-state=3, tail-calls display config(19,19,0).
 *
 * 25 instructions (incl. delay slots). Saves PR.
 * ================================================================ */
void FUN_06009DD0(void)
{
    FUN_060190B8();
    MODE_SELECTOR = 27;
    RENDER_PARAM_CACHE = 0x0258;  /* 600 = 10 seconds at 60fps */
    FUN_06028560();
    FUN_06012F80();
    SUB_STATE_COUNTER = 3;
    FUN_06018DDC(19);  /* original: r4=19, r5=19, r6=0 (tail call) */
}


/* ================================================================
 * FUN_06008C14 -- State Handler: Mode Transition Dispatch (0x06008C14)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008C14-0x06008C74)
 * Pool verified:
 *   0x06008C38 = 0x0605AD10 (mode selector)
 *   0x06008C50 = 0x0601F8C0 (mode transition check)
 *   0x06008C54 = 0x0605E0A2 (mode override flag)
 *   0x06008CB4 = 0x0605E0A2 (mode override flag -- store)
 *   0x06008CB8 = 0x0605A016 (sub-state counter)
 *
 * Checks if mode transition is complete. If complete, dispatches
 * based on override flag: flag==0 -> mode=4, flag!=0 -> mode=7.
 * Clears the override flag. If not complete, sets mode=31.
 * Always sets sub-state=3.
 *
 * 50 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06008C14(void)
{
    int result = FUN_0601F8C0();

    if (result != 0) {
        /* Transition complete: check override flag */
        if (MODE_OVERRIDE_FLAG == 0) {
            MODE_SELECTOR = 4;
        } else {
            MODE_SELECTOR = 7;
        }
        MODE_OVERRIDE_FLAG = 0;
    } else {
        /* Not complete: set mode to 31 (waiting) */
        MODE_SELECTOR = 31;
    }

    SUB_STATE_COUNTER = 3;
}


/* ================================================================
 * FUN_06008D74 -- State Handler: Countdown + Button Check (0x06008D74)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008D74-0x06008DD4)
 * Pool verified:
 *   0x06008DD8 = 0x06063DA0 (course ID register)
 *   0x06008DDC = 0x06078644 (config register)
 *   0x06008DE0 = 0x0607EBCC (render param cache)
 *   0x06008DE4 = 0x0605AD10 (mode selector)
 *   0x06008DE8 = 0x060149E0 (VDP1 attribute setup)
 *   0x06008DEC = 0x06063D9A (button input state)
 *   word pool at 0x06008DD6 = 0x0100 (start button mask)
 *   0x06008DF0 = 0x0601D3C0 (sound/display subsystem)
 *   0x06008DF4 = 0x0605B6D8 (engine state flags)
 *   0x06008DF8 = 0x06026CE0 (scene callback)
 *   0x06008DFC = 0x06059F44 (state flag)
 *
 * Checks course ID: if 112 (0x70), sets config to 2.
 * Decrements render cache. If expired, clears mode and sets up
 * VDP attrs. Also checks start button (bit 8): if pressed,
 * forces mode=0 and VDP setup. Then calls display subsystem,
 * sets engine flag bit 2, dispatches callbacks, clears state flag.
 *
 * 50 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06008D74(void)
{
    /* Check course ID for special config */
    if (COURSE_ID_REG == 112) {
        *(volatile int *)0x06078644 = 2;
    }

    /* Decrement render parameter cache */
    int counter = RENDER_PARAM_CACHE;
    counter--;
    RENDER_PARAM_CACHE = counter;

    if (counter < 0) {
        /* Timer expired: clear mode, setup VDP attributes */
        MODE_SELECTOR = 0;
        FUN_060149E0();
    }

    /* Check start button (bit 8 = 0x0100) */
    if (BUTTON_INPUT_STATE & 0x0100) {
        /* Start pressed: force mode=0, setup VDP attributes */
        MODE_SELECTOR = 0;
        FUN_060149E0();
    }

    /* Call sound/display subsystem */
    FUN_0601D3C0();

    /* Set engine state flag bit 2 */
    ENGINE_STATE_FLAGS = ENGINE_STATE_FLAGS | 0x04;

    /* Dispatch scene callbacks */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;
}


/* ================================================================
 * FUN_06008938 -- State Handler: Game Session Init (0x06008938)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008938-0x060089C0)
 * Pool verified:
 *   0x060089C4 = 0x06078634 (session flag A)
 *   0x060089C8 = 0x06078635 (session flag B)
 *   0x060089CC = 0x0607ED8C (display counter)
 *   0x060089D0 = 0x0607864B (session byte)
 *   0x060089D4 = 0x06018A3C (session/sound init)
 *   0x060089D8 = 0x0600EB14 (race/engine init)
 *   0x060089DC = 0x06033AAC (graphics palette init)
 *   0x060089E0 = 0x0600A140 (VDP1 command clear)
 *   0x060089E4 = 0x06063DA0 (course ID)
 *   0x060089E8 = 0x0600330A (splash/overlay display)
 *   0x060089EC = 0x06087804 (mode timer)
 *   0x060089F0 = 0x0607EBCC (render param cache)
 *   word pool at 0x060089C2 = 0x0398 (920 = ~15sec timer)
 *   0x060089F4 = 0x0607EAE0 (subsystem flag)
 *   0x060089F8 = 0x0607EAD8 (player count)
 *   0x060089FC = 0x0601AE80 (session communication init)
 *   0x06008A04 = 0x40000000 (engine flag bit)
 *   0x06008A00 = 0x0605B6D8 (engine state flags)
 *   0x06008A08 = 0x0605AD10 (mode selector)
 *   0x06008A0C = 0x06026CE0 (scene callback)
 *   0x06008A10 = 0x06059F44 (state flag)
 *   0x06008A14 = 0x0605A016 (sub-state counter)
 *
 * Entry point FUN_06008938 saves r14 and sets r3=1 before falling
 * through to FUN_0600893C. Initializes a new game session: sets
 * session flags, inits sound/engine/graphics, conditionally displays
 * splash screen, sets timer to 920 (reduced by 60 for 2P mode),
 * inits communication, sets engine flag bit 30, mode=3, sub-state=4.
 *
 * 68 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06008938(void)
{
    /* Set session flag A to 1 (from prologue: r3=1) */
    *(volatile char *)0x06078634 = 1;

    /* Clear session flag B */
    *(volatile char *)0x06078635 = 0;

    /* Clear display counter */
    *(volatile short *)0x0607ED8C = 0;

    /* Clear session byte */
    *(volatile char *)0x0607864B = 0;

    /* Initialize session/sound */
    FUN_06018A3C();

    /* Initialize race/engine */
    FUN_0600EB14();

    /* Initialize graphics palette */
    FUN_06033AAC();

    /* Clear VDP1 commands */
    FUN_0600A140();

    /* If course ID is set, display splash screen */
    if (COURSE_ID_REG != 0) {
        FUN_0600330A();
    }

    /* Clear mode timer */
    *(volatile short *)0x06087804 = 0;

    /* Set render parameter cache to 920 (~15 seconds) */
    RENDER_PARAM_CACHE = 0x0398;

    /* Clear subsystem flag */
    *(volatile int *)0x0607EAE0 = 0;

    /* For 2-player mode, reduce timer by 60 (1 second) */
    if (*(volatile int *)0x0607EAD8 == 2) {
        RENDER_PARAM_CACHE = RENDER_PARAM_CACHE - 60;
    }

    /* Initialize session communication */
    FUN_0601AE80();

    /* Set engine state flag bit 30 (0x40000000) */
    ENGINE_STATE_FLAGS = ENGINE_STATE_FLAGS | 0x40000000;

    /* Set mode to 3 */
    MODE_SELECTOR = 3;

    /* Dispatch scene callbacks */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;

    /* Set sub-state counter to 4 */
    SUB_STATE_COUNTER = 4;
}


/* ================================================================
 * FUN_0600893C -- Game Session Init Body (0x0600893C)
 *
 * This is the body of FUN_06008938. In the original binary,
 * FUN_06008938 saves r14 and sets r3=1, then falls through here.
 * In C, both entry points produce the same behavior.
 * ================================================================ */
void FUN_0600893C(void)
{
    FUN_06008938();
}


/* ================================================================
 * FUN_06008A18 -- State Handler: Attract Mode / Title Timeout (0x06008A18)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008A18-0x06008AB8)
 * Pool verified:
 *   0x06008AC4 = 0x0607EBCC (render param cache)
 *   0x06008AC8 = 0x0600A1F6 (per-frame subsystem update)
 *   0x06008ACC = 0x0607EAD8 (frame counter)
 *   0x06008AD0 = 0x06063D9A (button input state)
 *   word pool at 0x06008AC0 = 0x0800 (start button mask)
 *   0x06008AD4 = 0x06018E70 (CD play command)
 *   0x06008AD8 = 0x0605AD10 (mode selector)
 *   0x06008ADC = 0x06087804 (display timer)
 *   0x06008AE0 = 0x06033BC8 (graphics state reset)
 *   0x06008AE4 = 0x0601FD74 (VDP2 display update)
 *   0x06008AE8 = 0x0600DE40 (rendering pipeline)
 *   0x06008AEC = 0x0600A914 (scene/object update)
 *   0x06008AF0 = 0x060055BC (car physics update)
 *   0x06008AF4 = 0x0600338C (timed display sequence)
 *   0x06008AF8 = 0x0600BFFC (post-frame render)
 *   word pool at 0x06008AC0+2 = 0x0244 (580 timer threshold)
 *   0x06008AFC = 0x0601AEB6 (session result display)
 *   0x06008B00 = 0x060078DC (per-frame tail call)
 *
 * Decrements render param cache (title screen timer). Two paths:
 *
 * Path A (timer >= 0, no start button): Run full display pipeline
 *   (graphics reset if counter==2, VDP2 update, rendering, scene,
 *   physics, timed display, post-frame, optional result display
 *   if timer <= 580), tail-call FUN_060078DC.
 *
 * Path B (timer < 0 or start pressed): If start pressed + timer >= 0,
 *   calls CD play. If timer < 0, increments frame counter mod 3.
 *   Sets MODE_SELECTOR=4 and display timer=3.
 *
 * 80 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06008A18(void)
{
    volatile int *frame_counter = (volatile int *)0x0607EAD8;

    /* Decrement title screen timer */
    RENDER_PARAM_CACHE = RENDER_PARAM_CACHE - 1;

    /* Per-frame subsystem update */
    FUN_0600A1F6();

    if (RENDER_PARAM_CACHE >= 0) {
        /* Timer still running: check for start button (0x0800) */
        if (((unsigned short)BUTTON_INPUT_STATE & 0x0800) == 0) {
            /* No start button: run full display pipeline */
            if (*frame_counter == 2) {
                FUN_06033BC8();
            }
            FUN_0601FD74();
            FUN_0600DE40();
            FUN_0600A914();
            FUN_060055BC();
            FUN_0600338C(RENDER_PARAM_CACHE, 21);
            FUN_0600BFFC();
            if (RENDER_PARAM_CACHE <= 580) {  /* 0x0244 */
                FUN_0601AEB6();
            }
            FUN_060078DC();
            return;
        }
        /* Start button pressed: play CD and set mode */
        FUN_06018E70();
    } else {
        /* Timer expired: increment frame counter mod 3 */
        int val = *frame_counter + 1;
        *frame_counter = val;
        if ((unsigned int)val >= 3) {
            *frame_counter = 0;
        }
    }

    /* Set mode=4 (state boundary normalizer) and display timer=3 */
    MODE_SELECTOR = 4;
    *(volatile short *)0x06087804 = 3;
}


/* ================================================================
 * FUN_06008CCC -- State Handler: Pre-Attract Init, Prologue (0x06008CCC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06008CCC-0x06008D36)
 * Pool verified:
 *   0x06008D3C = 0x06078644 (config register)
 *   0x06008D40 = 0x060149E0 (VDP1 attribute setup)
 *   0x06008D44 = 0x06026CE0 (scene callback)
 *   0x06008D48 = 0x06059F44 (state done flag)
 *   0x06008D4C = 0x0601D2DC (display subsystem shutdown)
 *   0x06008D50 = 0x0601B074 (sound engine reset)
 *   0x06008D54 = 0x0607EBCC (render param cache)
 *   word pool at 0x06008D38 = 0x0258 (600 = 10sec timer)
 *   0x06008D58 = 0x06086024 (subsystem state)
 *   0x06008D5C = 0x0605AD10 (mode selector)
 *   0x06008D60 = 0x0605B6D8 (engine state flags)
 *   0x06008D64 = 0x40000000 (engine flag bit 30)
 *   0x06008D68 = 0x0605A016 (sub-state counter)
 *   0x06008D6C = 0x0607864B (session byte)
 *   0x06008D70 = 0x06018FF8 (CD audio stop/fade)
 *
 * Prologue saves r14, sets r14=0. Body: stores 0 to config register,
 * sets up VDP1 attrs, dispatches callbacks, clears state flag,
 * shuts down display+sound, sets 10-second timer, clears subsystem
 * state, sets mode=5, engine flag bit 30, dispatches callbacks again,
 * clears state flag, sets sub-state=3. If session byte == 1, stops
 * CD audio and clears the byte.
 *
 * 52 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06008CCC(void)
{
    /* Config register = 0 (from prologue: r14 = 0) */
    *(volatile int *)0x06078644 = 0;

    /* VDP1 attribute setup */
    FUN_060149E0();

    /* Dispatch scene callbacks */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;

    /* Shut down display subsystem */
    FUN_0601D2DC();

    /* Reset sound engine */
    FUN_0601B074();

    /* Set render parameter cache to 600 (10 seconds) */
    RENDER_PARAM_CACHE = 600;  /* 0x0258 */

    /* Clear subsystem state */
    *(volatile int *)0x06086024 = 0;

    /* Set mode to 5 (timed/conditional branch) */
    MODE_SELECTOR = 5;

    /* Set engine state flag bit 30 */
    ENGINE_STATE_FLAGS = ENGINE_STATE_FLAGS | 0x40000000;

    /* Dispatch scene callbacks (second time) */
    FUN_06026CE0();

    /* Clear state completion flag */
    STATE_DONE_FLAG = 0;

    /* Set sub-state counter to 3 */
    SUB_STATE_COUNTER = 3;

    /* If session byte is 1, stop CD audio and clear it */
    if (*(volatile unsigned char *)0x0607864B == 1) {
        FUN_06018FF8();
        *(volatile unsigned char *)0x0607864B = 0;
    }
}


/* ================================================================
 * FUN_06008CD0 -- State Handler: Pre-Attract Init, Body (0x06008CD0)
 *
 * This is the body entry point of FUN_06008CCC. In the original binary,
 * FUN_06008CCC saves r14 and sets r14=0, then falls through here.
 * In C, both entry points produce the same behavior.
 * ================================================================ */
void FUN_06008CD0(void)
{
    FUN_06008CCC();
}


/* ================================================================
 * FUN_06009C48 -- State Handler: Post-Race Gameplay (0x06009C48)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06009C48-0x06009CB4)
 * Pool verified:
 *   0x06009CB8 = 0x06014A42 (VDP1 sprite setup)
 *   0x06009CBC = 0x0607EAE0 (subsystem flag)
 *   0x06009CC0 = 0x0601DF88 (results screen update)
 *   0x06009CC4 = 0x0607EAD8 (frame counter)
 *   0x06009CC8 = 0x0601DBB8 (results screen animation)
 *   0x06009CCC = 0x0600DF66 (AI/object position update)
 *   0x06009CD0 = 0x0600A914 (scene/object update)
 *   0x06009CD4 = 0x0600BB94 (score/results display)
 *   0x06009CD8 = 0x06063E24 (display addr C ptr)
 *   0x06009CDC = 0x06063EEC (display addr B)
 *   0x06009CE0 = 0x06063EF8 (display addr A)
 *   0x06009CE4 = 0x060053AC (triple display overlay)
 *   0x06009CE8 = 0x0600BFFC (post-frame render)
 *   0x06009CEC = 0x0607ED8C (display counter)
 *   0x06009CF0 = 0x060033E6 (course-specific display)
 *   0x06009CF4 = 0x0607E944 (object table pointer)
 *   word pool at 0x06009CB6 = 0x00BC (188 = struct offset)
 *   0x06009CF8 = 0x060078DC (per-frame tail call)
 *
 * Post-race gameplay state: sets up VDP1 sprites, conditionally
 * updates results screen (if subsystem flag != 0) and animation
 * (if frame counter != 0). Then runs scene/object update pipeline,
 * score display, overlay rendering, post-frame render. Checks
 * display counter and object table entry for additional effects.
 * Tail-calls FUN_060078DC.
 *
 * 55 instructions (incl. delay slots + pool). Saves PR.
 * ================================================================ */
void FUN_06009C48(void)
{
    /* VDP1 sprite setup */
    FUN_06014A42();

    /* Conditional results screen update */
    if (*(volatile int *)0x0607EAE0 != 0) {
        FUN_0601DF88();
        if (*(volatile int *)0x0607EAD8 != 0) {
            FUN_0601DBB8();
        }
    }

    /* AI/object position update */
    FUN_0600DF66();

    /* Scene/object update dispatch */
    FUN_0600A914();

    /* Score/results display */
    FUN_0600BB94();

    /* Triple display overlay (r6 loaded from pointer in delay slot) */
    FUN_060053AC((int)0x06063EF8, (int)0x06063EEC, *(volatile int *)0x06063E24);

    /* Post-frame render finalize */
    FUN_0600BFFC();

    /* Course-specific display effect if display counter != 0 */
    if (*(volatile unsigned short *)0x0607ED8C != 0) {
        FUN_060033E6();
    }

    /* Check object table entry at offset 0xBC for cleanup */
    volatile int *table = *(volatile int * volatile *)0x0607E944;
    if (*(int *)((char *)table + 0xBC) > 0) {
        FUN_0600A084();
    }

    /* Per-frame tail call */
    FUN_060078DC();
}


/* ================================================================
 * FUN_06009E60 -- State Handler: Post-Race Transition (0x06009E60)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06009E60-0x06009ED8)
 * Pool verified:
 *   0x06009EDC = 0x06019058 (post-race subsystem transition)
 *   0x06009EE0 = 0x0602853E (VDP command channel clear)
 *   0x06009EE4 = 0x06028560 (VDP command reset)
 *   0x06009EE8 = 0x06014884 (render parameter setter)
 *   0x06009EEC = 0x060032D4 (splash screen init)
 *   word pool at 0x06009EDA = 0x03E8 (1000 = ~16.7sec timer)
 *   0x06009EF0 = 0x0607EBCC (render param cache)
 *   0x06009EF4 = 0x0605AD10 (mode selector)
 *   0x06009EF8 = 0x06087804 (display timer)
 *   0x06009EFC = 0x0600EB14 (race/engine init)
 *   0x06009F00 = 0x06033AAC (graphics palette init)
 *   0x06009F04 = 0x0605A016 (sub-state counter)
 *   0x06009F08 = 0x06078648 (session mode byte)
 *   0x06009F0C = 0x06018DDC (display mode config -- tail call)
 *
 * Runs post-race subsystem transition, clears 3 VDP command channels
 * (4, 8, 12), resets VDP commands, clears 3 render params (8, 16, 32),
 * inits splash screen, sets 1000-frame timer (~16.7sec), mode=23,
 * clears display timer, re-inits engine+palette, sets sub-state=4,
 * tail-calls display config with mode byte + 14.
 *
 * 60 instructions (incl. delay slots + pool). Saves PR + r14.
 * ================================================================ */
void FUN_06009E60(void)
{
    /* Post-race subsystem transition */
    FUN_06019058();

    /* Clear VDP command channels 4, 8, 12 */
    FUN_0602853E(4);
    FUN_0602853E(8);
    FUN_0602853E(12);

    /* Reset VDP commands */
    FUN_06028560();

    /* Clear render parameters: priority, color calc, mesh */
    FUN_06014884(8, 0, 0);
    FUN_06014884(16, 0, 0);
    FUN_06014884(32, 0, 0);

    /* Initialize splash screen */
    FUN_060032D4();

    /* Set render parameter cache to 1000 (~16.7 seconds at 60fps) */
    RENDER_PARAM_CACHE = 1000;  /* 0x03E8 */

    /* Set mode to 23 (counter transition) */
    MODE_SELECTOR = 23;

    /* Clear display timer */
    *(volatile short *)0x06087804 = 0;

    /* Re-initialize engine and palette */
    FUN_0600EB14();
    FUN_06033AAC();

    /* Set sub-state counter to 4 */
    SUB_STATE_COUNTER = 4;

    /* Tail-call display config with session mode byte + 14 */
    int mode = (int)(*(volatile unsigned char *)0x06078648) + 14;
    FUN_06018DDC(mode);  /* original: r4=r5=mode, r6=0 (tail call) */
}


/* ================================================================
 * FUN_06009F10 -- State Handler: Counter Transition (0x06009F10)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06009F10-0x06009FA4)
 * Pool verified:
 *   0x06009FB0 = 0x0607EBCC (render param cache)
 *   0x06009FB4 = 0x0607E944 (object table pointer)
 *   0x06009FB8 = 0x06078637 (session config byte)
 *   word pool at 0x06009FAC = 0x0224 (548 = struct offset)
 *   0x06009FBC = 0x06078638 (session config word)
 *   0x06009FC0 = 0x0607863C (config value source)
 *   0x06009FC4 = 0x060786A4 (config value dest)
 *   0x06009FC8 = 0x0605AD10 (mode selector)
 *   0x06009FCC = 0x06087804 (display timer)
 *   0x06009FD0 = 0x0607EAD8 (player count)
 *   0x06009FD4 = 0x06033EA8 (2-player display setup)
 *   0x06009FD8 = 0x0601FD74 (VDP2 display update)
 *   0x06009FDC = 0x06078900 (car struct base)
 *   0x06009FE0 = 0x0600DE40 (rendering pipeline)
 *   0x06009FE4 = 0x0600A914 (scene/object update)
 *   0x06009FE8 = 0x060055BC (car physics update)
 *   0x06009FEC = 0x0600BFFC (post-frame render)
 *   0x06009FF0 = 0x060078DC (per-frame tail call)
 *   0x06009FF4 = 0x0605A00C (subsystem sync flag)
 *   0x06009FF8 = 0x06026CE0 (scene callback)
 *
 * Decrements timer. If expired: copies session data to object table
 * at offsets 0x224/0x240, copies config value, sets mode=24, display=3.
 * If running: checks 2P mode, updates VDP2, then either runs full
 * display pipeline (physics/render) or short exit (clear sync, callback).
 * Short exit taken when display timer == 3.
 *
 * 70 instructions (incl. delay slots + pool). Saves PR.
 * ================================================================ */
void FUN_06009F10(void)
{
    /* Per-frame scene update */
    FUN_0600A294();

    /* Decrement timer */
    RENDER_PARAM_CACHE = RENDER_PARAM_CACHE - 1;

    if (RENDER_PARAM_CACHE < 0) {
        /* Timer expired: copy session data to object table */
        volatile int *table = *(volatile int * volatile *)0x0607E944;

        /* Copy session config byte to table at offset 0x224 (sign-extended) */
        *(volatile int *)((char *)table + 0x0224) = (int)*(volatile signed char *)0x06078637;

        /* Copy session config word to table at offset 0x240 */
        *(volatile int *)((char *)table + 0x0240) = *(volatile int *)0x06078638;

        /* Copy config value */
        *(volatile int *)0x060786A4 = *(volatile int *)0x0607863C;

        /* Set mode=24 (post-race display init), display timer=3 */
        MODE_SELECTOR = 24;
        *(volatile short *)0x06087804 = 3;
        return;
    }

    /* Timer still running */
    if (*(volatile int *)0x0607EAD8 == 2) {
        FUN_06033EA8();
    }

    /* VDP2 display update */
    FUN_0601FD74();

    /* Check display timer */
    if ((unsigned short)*(volatile short *)0x06087804 == 3) {
        /* Display timer == 3: short exit */
        *(volatile int *)0x0605A00C = 0;
        FUN_06026CE0();
        return;
    }

    /* Full display pipeline */
    /* Set bit 7 of car struct flag byte at offset +1 */
    volatile unsigned char *car_flag = (volatile unsigned char *)0x06078901;
    *car_flag = (*car_flag & 0x7F) | 0x80;

    /* Run display pipeline */
    FUN_0600DE40();
    FUN_0600A914();
    FUN_060055BC();
    FUN_0600BFFC();
    FUN_060078DC();
}
