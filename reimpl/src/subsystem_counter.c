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

/* VDP display list fill / pattern table clear */
extern int *vdp_display_list_fill(int channel);
extern int *vdp2_pattern_table_clear(void);

/* Subsystem processing continuation */
extern void FUN_060115F0(void);

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
/* FUN_0600F898 -- original binary (38 bytes) */
__asm__(
    ".section .text.FUN_0600F898, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600F898\n"
    ".type _FUN_0600F898, @function\n"
    "_FUN_0600F898:\n"
    ".byte 0x4F, 0x22, 0xD3, 0x13, 0x43, 0x0B, 0x00, 0x09, 0x92, 0x18, 0xD3, 0x12, 0x23, 0x22, 0xE2, 0x14\n"  /* 0x0600F898 */
    ".byte 0xD3, 0x0D, 0x23, 0x21, 0xE2, 0x00, 0xD3, 0x10, 0x23, 0x21, 0xD4, 0x0C, 0x4F, 0x26, 0x62, 0x40\n"  /* 0x0600F8A8 */
    ".byte 0x72, 0x01, 0x00, 0x0B, 0x24, 0x20\n"  /* 0x0600F8B8 */
);



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
 * vdp_display_list_fill(4) and advances the state flag.
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
    vdp_display_list_fill(4);
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
/* FUN_0600F990 -- original binary (54 bytes) */
__asm__(
    ".section .text.FUN_0600F990, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600F990\n"
    ".type _FUN_0600F990, @function\n"
    "_FUN_0600F990:\n"
    ".byte 0x4F, 0x22, 0xDE, 0x1D, 0xD3, 0x1D, 0x62, 0xE2, 0x32, 0x3C, 0x65, 0x23, 0x2E, 0x22, 0xD3, 0x1C\n"  /* 0x0600F990 */
    ".byte 0x43, 0x0B, 0xE4, 0x10, 0xD4, 0x1B, 0xD3, 0x1B, 0x64, 0x41, 0x74, 0x02, 0x23, 0x41, 0xD3, 0x1A\n"  /* 0x0600F9A0 */
    ".byte 0x43, 0x0B, 0x00, 0x09, 0x60, 0xE2, 0x20, 0x08, 0x8B, 0x02, 0xE3, 0x08, 0xD2, 0x17, 0x22, 0x30\n"  /* 0x0600F9B0 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600F9C0 */
);



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
extern void podium_object_render_static(void);

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
    podium_object_render_static();
    FUN_0601416c();  /* tail-call in original */
}


/* Input processing — mode counter adjust */
extern void FUN_060102A8(unsigned int param);

/* Secondary input processor */
extern void FUN_060102ea(int param);

/* Mode-specific setup (no params) */
extern void FUN_06010238(void);

/* ================================================================
 * FUN_0600F794 -- Subsystem Init with Mode Dispatch (0x0600F794)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600F794-0x0600F820)
 * Pool verified:
 *   [0x0600F7E4] = 0x06063D98 (input state base)
 *   [0x0600F7E8] = 0x060114AC (subsystem init A)
 *   [0x0600F7EC] = 0x06011094 (subsystem init B)
 *   word [0x0600F848] = 0x0800 (bit 11 mask)
 *   [0x0600F84C] = 0x06085FF4 (flag byte)
 *   [0x0600F850] = 0x06063D98 (input state base, reloaded)
 *   [0x0600F854] = 0x06078663 (control byte destination)
 *
 * Reads input word from 0x06063D9A, calls init helpers, then
 * dispatches based on mode byte at 0x06063D9E:
 *   mode == 16: call FUN_06010238 (setup)
 *   mode != 16: call FUN_060102A8(input_word) (adjust)
 * Always calls FUN_060102EA(input_word).
 * If flag byte at 0x06085FF4 is non-zero, writes bit 11 test
 * result (0 or 1) to control byte at 0x06078663.
 *
 * 40 instructions. Saves r14 + PR.
 * ================================================================ */
void FUN_0600F794(void)
{
    /* Read input word (sign-extended from 16-bit) */
    short input_word = *(volatile short *)0x06063D9A;

    /* Initialize subsystems */
    FUN_060114ac(0);
    FUN_06011094();

    /* Dispatch based on mode byte */
    unsigned short mode = *(volatile unsigned short *)0x06063D9E;

    if (mode == 16) {
        FUN_06010238();
    } else {
        FUN_060102A8((unsigned int)(unsigned short)input_word);
    }

    /* Common input processing */
    FUN_060102ea((int)(unsigned short)input_word);

    /* If flag byte is set, test input bit 11 and store result */
    if (*(volatile char *)0x06085FF4 != 0) {
        unsigned short input0 = *(volatile unsigned short *)0x06063D98;
        char bit_val = (input0 & 0x0800) ? 1 : 0;
        *(volatile char *)0x06078663 = bit_val;
    }
}


/* Subsystem handler: full reset sequence */
extern void FUN_06014360(void);

/* Subsystem handler: mode processing */
extern void FUN_0601424c(void);

/* Subsystem handler: timer calibration */
extern void FUN_060140c4(void);

/* Controller input handler */
extern void FUN_0601444C(void);

/* Mode-16 specific handler */
extern void FUN_06014466(void);

/* Alternate mode handler */
extern void FUN_0601450c(void);

/* Post-dispatch update */
extern void FUN_060145bc(void);

/* End-of-round trigger handler */
extern unsigned int FUN_060146d2(void);

/* ================================================================
 * FUN_06013A74 -- Subsystem Dispatch Chain (0x06013A74)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06013A74-0x06013AD8)
 * Pool verified:
 *   [0x06013AEC] = 0x06063D9E (mode flag, 16-bit)
 *   [0x06013AF0] = 0x06063D9A (input word, 16-bit)
 *   word [0x06013AEA] = 0x0800 (bit 11 mask)
 *   [0x06013AF4] = 0x06084B18 (countdown limit, 32-bit)
 *   [0x06013AF8] = 0x06084AF0 (counter, 16-bit)
 *
 * Calls sequence of 5 subsystem handlers, then mode-dispatches
 * between FUN_06014466 (mode==16) and FUN_0601450c (other).
 * After dispatch, calls FUN_060145bc, tests input bit 11, and
 * conditionally calls FUN_060146d2. Then checks countdown limit
 * (>=4 triggers end) and decrements counter (<=0 triggers end).
 *
 * 50 instructions. Saves PR.
 * ================================================================ */
/* FUN_06013A74 -- original binary (144 bytes) */
__asm__(
    ".section .text.FUN_06013A74, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06013A74\n"
    ".type _FUN_06013A74, @function\n"
    "_FUN_06013A74:\n"
    ".byte 0x4F, 0x22, 0xB4, 0x73, 0x00, 0x09, 0xB3, 0x77, 0x00, 0x09, 0xB3, 0xE5, 0x00, 0x09, 0xB3, 0x1F\n"  /* 0x06013A74 */
    ".byte 0x00, 0x09, 0xB4, 0xE1, 0x00, 0x09, 0xD0, 0x18, 0x60, 0x01, 0x60, 0x0D, 0x88, 0x10, 0x8B, 0x03\n"  /* 0x06013A84 */
    ".byte 0xB4, 0xE7, 0x00, 0x09, 0xA0, 0x02, 0x00, 0x09, 0xB5, 0x36, 0x00, 0x09, 0xB5, 0x8C, 0x00, 0x09\n"  /* 0x06013A94 */
    ".byte 0xD2, 0x12, 0x63, 0x21, 0x92, 0x1F, 0x63, 0x3D, 0x23, 0x29, 0x23, 0x38, 0x89, 0x01, 0xB6, 0x0E\n"  /* 0x06013AA4 */
    ".byte 0x00, 0x09, 0xE3, 0x04, 0xD2, 0x0E, 0x62, 0x22, 0x32, 0x32, 0x89, 0x07, 0xD3, 0x0D, 0xD2, 0x0D\n"  /* 0x06013AB4 */
    ".byte 0x63, 0x31, 0x73, 0xFF, 0x22, 0x31, 0x63, 0x3F, 0x43, 0x15, 0x89, 0x01, 0xA5, 0xFF, 0x4F, 0x26\n"  /* 0x06013AC4 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09, 0xE3, 0x05, 0xD2, 0x07, 0x22, 0x30, 0xE3, 0x00, 0xD2, 0x07\n"  /* 0x06013AD4 */
    ".byte 0x22, 0x31, 0xA0, 0x0D, 0x00, 0x09, 0x08, 0x00, 0x06, 0x06, 0x3D, 0x9E, 0x06, 0x06, 0x3D, 0x9A\n"  /* 0x06013AE4 */
    ".byte 0x06, 0x08, 0x4B, 0x18, 0x06, 0x08, 0x4A, 0xF0, 0x06, 0x08, 0x4A, 0xF2, 0x06, 0x08, 0x4A, 0xF6\n"  /* 0x06013AF4 */
);

