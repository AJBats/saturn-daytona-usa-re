/* subsystem_counter.c -- Subsystem memory counter update
 *
 * Functions:
 *   FUN_0600F822 (0x0600F822) -- Subsystem init: sound cmd + timer setup
 *   FUN_0600F898 (0x0600F898) -- Subsystem reset: clear counters, increment state
 *   FUN_0600F8BE (0x0600F8BE) -- Timer tick: decrement counter, dispatch
 *   FUN_0600F914 (0x0600F914) -- VDP subsystem init: reset counters, render setup
 *   FUN_0600F98C (0x0600F98C) -- Prologue: set r6=0, call FUN_0600F990
 *   FUN_0600F990 (0x0600F990) -- Advance memory pointer, increment counter, flag check
 *
 * FUN_0600F990 advances a 32-bit memory pointer global by 0x100000 (1MB),
 * passes the new address to FUN_06014884 as a rendering parameter,
 * increments a 16-bit frame counter at 0x0607886E by 2,
 * calls FUN_0601155e for display refresh, then checks if the global
 * has wrapped to zero (flags subsystem state = 8 if so).
 *
 * FUN_0600F98C is a 2-instruction prologue that sets r6=0 (third param
 * for FUN_06014884) and falls through to FUN_0600F990.
 *
 * Globals:
 *   0x0607885C: 32-bit memory pointer (advanced by 0x100000 per call)
 *   0x0607886E: 16-bit frame counter (incremented by 2 per call)
 *   0x0607887F: 8-bit subsystem state flag (set to 8 when pointer wraps)
 *
 * Original addresses: 0x0600F98C, 0x0600F990
 */

/* Rendering parameter setter (r4=type, r5=value, r6=flags) */
extern void FUN_06014884(int type, int value, int flags);

/* Display refresh function (takes counter value) */
extern void FUN_0601155e(unsigned short counter);

/* Sound command dispatch (defined in asm_game_core.c) */
extern void FUN_0601D5F4(int cmd, int param);

/* Subsystem init helpers */
extern unsigned int FUN_060114ac(int param);
extern void FUN_06011094(void);

/* VDP command reset (returns pointer) */
extern int *FUN_06028560(void);

/* Subsystem processing continuation */
extern void FUN_060115F0(void);

/* Config helper (param=mode selector) */
extern void FUN_0602853E(int param);

/* VDP2 scroll setup */
extern void FUN_06011678(void);

/* VDP1 render setup (3 attributes) */
extern void FUN_06012080(void);

/* Tile DMA transfer */
extern void FUN_06011450(void);

/* Memory pointer global */
#define MEM_PTR_GLOBAL     (*(volatile int *)0x0607885C)

/* Frame counter (16-bit) */
#define FRAME_COUNTER      (*(volatile short *)0x0607886E)

/* Subsystem state flag (8-bit) */
#define SUBSYS_STATE_FLAG  (*(volatile char *)0x0607887F)

/* Timer counter (16-bit at 0x0607887C) */
#define TIMER_COUNTER      (*(volatile short *)0x0607887C)

/* Rendering parameter cache (32-bit at 0x0607EBCC) */
#define RENDER_PARAM_CACHE (*(volatile int *)0x0607EBCC)

/* Display config register (16-bit at 0x0605AAA2) */
#define DISPLAY_CONFIG_REG (*(volatile short *)0x0605AAA2)


/* ================================================================
 * FUN_0600F822 -- Subsystem Init: Sound + Timer Setup (0x0600F822)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F822-0x0600F846)
 * Pool verified:
 *   0x0600F858 = 0xAB1101FF (sound command parameter)
 *   0x0600F85C = 0x0601D5F4 (sound_cmd_dispatch)
 *   0x0600F860 = 0x060114AC (subsystem init A)
 *   0x0600F864 = 0x06011094 (subsystem init B)
 *   0x0600F868 = 0x0607887C (timer counter)
 *   0x0600F86C = 0x0607887F (state flag)
 *
 * Sends a sound command, calls two init helpers, sets timer=120,
 * state flag=3.
 *
 * 20 instructions. Saves PR.
 * ================================================================ */
void FUN_0600F822(void)
{
    /* Sound command: stop all (cmd=0, param=0xAB1101FF) */
    FUN_0601D5F4(0, (int)0xAB1101FF);

    /* Initialize subsystems */
    FUN_060114ac(0);
    FUN_06011094();

    /* Set timer to 120 frames (2 seconds at 60fps) */
    TIMER_COUNTER = 120;

    /* Set subsystem state to 3 */
    SUBSYS_STATE_FLAG = 3;
}


/* ================================================================
 * FUN_0600F898 -- Subsystem Reset: Clear Counters (0x0600F898)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F898-0x0600F8BC)
 * Pool verified:
 *   0x0600F8E8 = 0x06028560 (VDP command reset)
 *   word pool at 0x0600F8D4 = 0x0708 (1800 = 30sec timer)
 *   0x0600F8EC = 0x0607EBCC (render param cache)
 *   0x0600F8E0 = 0x0607887C (timer counter)
 *   0x0600F8F0 = 0x0607886E (frame counter)
 *   0x0600F8E4 = 0x0607887F (state flag)
 *
 * Calls VDP reset, stores 1800 to render cache, sets timer=20,
 * clears frame counter, increments state flag.
 *
 * 20 instructions. Saves PR.
 * ================================================================ */
void FUN_0600F898(void)
{
    /* Reset VDP command state */
    FUN_06028560();

    /* Set render parameter cache to 1800 (30 seconds at 60fps) */
    RENDER_PARAM_CACHE = 0x0708;

    /* Set timer to 20 frames */
    TIMER_COUNTER = 20;

    /* Clear frame counter */
    FRAME_COUNTER = 0;

    /* Increment subsystem state flag */
    SUBSYS_STATE_FLAG = SUBSYS_STATE_FLAG + 1;
}


/* ================================================================
 * FUN_0600F8BE -- Timer Tick / Subsystem Dispatch (0x0600F8BE)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F8BE-0x0600F912)
 * Pool verified:
 *   0x0600F8E0 = 0x0607887C (timer counter)
 *   0x0600F8F4 = 0x060115F0 (subsystem continuation)
 *   0x0600F960 = 0x0602853E (config helper)
 *   0x0600F964 = 0x0607887F (state flag)
 *
 * Decrements timer counter. If still positive, tail-calls
 * FUN_060115F0 (subsystem processing). If expired, calls
 * FUN_0602853E(4) and advances the state flag.
 *
 * 22 instructions. Saves PR.
 * ================================================================ */
void FUN_0600F8BE(void)
{
    short counter = TIMER_COUNTER;
    counter--;
    TIMER_COUNTER = counter;

    if (counter > 0) {
        /* Timer still running -- continue subsystem processing */
        FUN_060115F0();  /* tail-call in original asm */
        return;
    }

    /* Timer expired -- advance to next state */
    FUN_0602853E(4);
    SUBSYS_STATE_FLAG = SUBSYS_STATE_FLAG + 1;
}


/* ================================================================
 * FUN_0600F914 -- VDP Subsystem Init (0x0600F914)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F914-0x0600F95C)
 * Pool verified:
 *   0x0600F968 = 0x06011678 (VDP2 scroll setup)
 *   0x0600F96C = 0x06012080 (VDP1 render setup)
 *   0x0600F970 = 0x0607886E (frame counter)
 *   0x0600F974 = 0x0605AAA2 (display config register)
 *   0x0600F978 = 0xFEA00000 (initial memory pointer)
 *   0x0600F97C = 0x0607885C (memory pointer global)
 *   0x0600F980 = 0x06014884 (rendering parameter setter)
 *   0x0600F984 = 0x06011450 (tile DMA transfer)
 *   0x0600F964 = 0x0607887F (state flag)
 *   0x0600F988 = 0x0601155E (display refresh — tail call)
 *
 * Initializes VDP subsystem: calls scroll + render setup, resets
 * frame counter, sets memory pointer to 0xFEA00000, configures
 * rendering params, sets state=7, tail-calls display refresh.
 *
 * 34 instructions. Saves PR + r14.
 * ================================================================ */
void FUN_0600F914(void)
{
    /* Set up VDP2 scroll and VDP1 render attributes */
    FUN_06011678();
    FUN_06012080();

    /* Clear frame counter */
    FRAME_COUNTER = 0;

    /* Set display config to 2 */
    DISPLAY_CONFIG_REG = 2;

    /* Initialize memory pointer to 0xFEA00000 */
    MEM_PTR_GLOBAL = (int)0xFEA00000;

    /* Set rendering parameter: type=16, value=ptr, flags=0 */
    FUN_06014884(16, MEM_PTR_GLOBAL, 0);

    /* Transfer tile data */
    FUN_06011450();

    /* Set subsystem state to 7 */
    SUBSYS_STATE_FLAG = 7;

    /* Clear frame counter again (after function calls) */
    FRAME_COUNTER = 0;

    /* Tail-call display refresh with counter=0 */
    FUN_0601155e(0);
}


/* ================================================================
 * FUN_0600F990 -- Subsystem Counter Update (0x0600F990)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F990-0x0600F9C4)
 * Pool verified:
 *   0x0600FA08 = 0x0607885C (memory pointer global)
 *   0x0600FA0C = 0x00100000 (1MB increment)
 *   0x0600FA10 = 0x06014884 (rendering parameter setter)
 *   0x0600FA14 = 0x0607886E (frame counter)
 *   0x0600FA18 = 0x0601155E (display refresh)
 *   0x0600FA1C = 0x0607887F (subsystem state flag)
 *
 * 27 instructions. Saves PR, uses r14 for global pointer.
 * ================================================================ */
void FUN_0600F990(void)
{
    int val;
    short cnt;

    /* Advance memory pointer by 1MB */
    val = MEM_PTR_GLOBAL;
    val += 0x100000;
    MEM_PTR_GLOBAL = val;

    /* Set rendering parameter: type=16, value=new pointer, flags=0 */
    FUN_06014884(16, val, 0);

    /* Increment frame counter by 2 */
    cnt = FRAME_COUNTER;
    cnt += 2;
    FRAME_COUNTER = cnt;

    /* Call display refresh with current counter */
    FUN_0601155e((unsigned short)cnt);

    /* If memory pointer wrapped to zero, flag subsystem state */
    if (MEM_PTR_GLOBAL == 0) {
        SUBSYS_STATE_FLAG = 8;
    }
}


/* ================================================================
 * FUN_0600F98C -- Subsystem Counter Prologue (0x0600F98C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F98C-0x0600F98E)
 *
 * 2-instruction prologue: pushes r14, sets r6=0 (flags param for
 * FUN_06014884), falls through to FUN_0600F990.
 * In C, just calls FUN_0600F990 (r6=0 is hardcoded in body).
 * ================================================================ */
void FUN_0600F98C(void)
{
    FUN_0600F990();
}


/* VDP data decompressor (r4=source, r5=dest) */
extern void FUN_06028654(int src, int dest);

/* VDP data transfer (r4=cmd, r5=src, r6=offset, r7=dest) */
extern int FUN_06028400(int cmd, int src, int offset, int dest);

/* Rendering attribute writer (r4=mode, r5=width, r6=height, r7=table) */
extern void FUN_060284AE(int mode, int width, int height, int table);

/* VDP2 register writer (r4=register address) */
extern void FUN_06011f1c(unsigned short *reg_addr);

/* Rendering control word */
#define RENDER_CTRL_WORD  (*(volatile int *)0x06078864)

/* ================================================================
 * FUN_0600FE38 -- Subsystem Countdown / Rendering Transition (0x0600FE38)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600FE38-0x0600FE90)
 * Pool verified:
 *   [0x0600FE98] = 0x0607EBCC (countdown counter / RENDER_PARAM_CACHE)
 *   word [0x0600FE92] = 0x00AB (threshold = 171)
 *   [0x0600FE9C] = 0x06094FA8 (rendering data buffer)
 *   [0x0600FEA0] = 0x060EFB24 (VDP source data)
 *   [0x0600FEA4] = 0x06028654 (VDP decompressor)
 *   [0x0600FEA8] = 0x06063838 (VRAM pointer table)
 *   [0x0600FEAC] = 0x00009000 (VRAM offset)
 *   [0x0600FEB0] = 0x06028400 (VDP data transfer)
 *   [0x0600FEB4] = 0x06078864 (rendering control word)
 *   [0x0600FEB8] = 0x0607887F (subsystem state flag)
 *   [0x0600FEBC] = 0x0605ACE4 (attribute table base)
 *   word [0x0600FE94] = 0x0090 (144 = height param)
 *   word [0x0600FE96] = 0x07A2 (1954 = width param)
 *   [0x0600FEC0] = 0x060284AE (rendering attribute writer)
 *   [0x0600FEC4] = 0x25F001E0 (VDP2 register A)
 *   [0x0600FEC8] = 0x06011F1C (VDP2 register writer)
 *   [0x0600FECC] = 0x25F00520 (VDP2 register B)
 *
 * Decrements countdown counter. At threshold 171: decompresses
 * VDP data, transfers to VRAM, clears render control, sets state=16.
 * Always: configures rendering attributes, writes two VDP2 registers.
 *
 * 43 instructions. Saves PR. Tail-calls FUN_06011f1c.
 * ================================================================ */
void FUN_0600FE38(void)
{
    /* Decrement render parameter countdown */
    int count = RENDER_PARAM_CACHE;
    count--;
    RENDER_PARAM_CACHE = count;

    /* At threshold 171: trigger rendering data transfer */
    if (count == 171) {
        /* Decompress VDP data from source to buffer */
        FUN_06028654((int)0x060EFB24, (int)0x06094FA8);

        /* Compute VRAM destination: indirect pointer + 0x9000 offset */
        int vram_dest = *(volatile int *)0x0606383C + 0x9000;

        /* Transfer rendering data to VRAM */
        FUN_06028400(4, (int)0x06094FA8, 0, vram_dest);

        /* Clear rendering control word */
        RENDER_CTRL_WORD = 0;

        /* Set subsystem state to 16 (rendering transition) */
        SUBSYS_STATE_FLAG = 16;
    }

    /* Always: configure rendering attributes */
    FUN_060284AE(12, 1954, 144, (int)0x0605ACE4);

    /* Write VDP2 register pair */
    FUN_06011f1c((unsigned short *)0x25F001E0);
    FUN_06011f1c((unsigned short *)0x25F00520);  /* tail-call in original */
}


/* Subsystem processing step (in batch_subsystem_12.c) */
extern void FUN_06013fc4(void);

/* Subsystem advance handler (in batch_subsystem_14.c) */
extern void FUN_0601416c(void);

/* ================================================================
 * FUN_06013C20 -- Subsystem Counter Increment + Advance (0x06013C20)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06013C20-0x06013C40)
 * Pool verified:
 *   [0x06013C54] = 0x06084AF6 (16-bit counter)
 *
 * Reads 16-bit counter at 0x06084AF6, increments by 1, clamps to
 * max 20, writes back. Then calls subsystem processing step and
 * tail-calls advance handler.
 *
 * 17 instructions. Saves PR.
 * ================================================================ */
void FUN_06013C20(void)
{
    volatile unsigned short *counter = (volatile unsigned short *)0x06084AF6;

    unsigned short val = *counter;
    val++;

    /* Clamp to max 20 */
    if ((short)val > 20) {
        val = 20;
    }
    *counter = val;

    /* Process and advance subsystem */
    FUN_06013fc4();
    FUN_0601416c();  /* tail-call in original */
}
