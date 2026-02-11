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
