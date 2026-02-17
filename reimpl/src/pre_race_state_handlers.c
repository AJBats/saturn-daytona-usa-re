#include "saturn.h"
#include "game.h"

/* Memory-mapped game state addresses used by pre-race handlers */
#define RACE_PHASE_FLAG       (*(volatile unsigned char *)0x06078635)
#define RACE_CAR_COUNT_BYTE   (*(volatile unsigned char *)0x06078634)
#define RACE_INIT_FLAG_W      (*(volatile unsigned short *)0x0607ED8C)
#define RACE_DISPLAY_BYTE     (*(volatile unsigned char *)0x0607864B)
#define RACE_COUNTDOWN        (*(volatile int *)0x0607EBCC)
#define RACE_EXT_EVENT        (*(volatile int *)0x0607EAE0)
#define RACE_PLAYER_MODE      (*(volatile int *)0x0607EAD8)
#define RACE_DISPLAY_FLAGS    (*(volatile int *)0x0605B6D8)
#define RACE_VBL_OUT_FLAG     (*(volatile int *)0x06059F44)
#define RACE_PHASE_WORD       (*(volatile short *)0x0605A016)
#define RACE_TRANSITION_WORD  (*(volatile unsigned short *)0x06087804)
#define RACE_NEW_BUTTONS      (*(volatile unsigned short *)0x06063D9A)
#define RACE_KEY_STATE        (*(volatile unsigned short *)0x06063DA0)
#define RACE_BOUNDARY_FLAG    (*(volatile int *)0x06078644)
#define RACE_SOUND_STATE      (*(volatile int *)0x06086024)
#define RACE_RESOURCE_FLAG    (*(volatile unsigned char *)0x0605E0A2)

/* Extern functions used by pre-race states */
extern void FUN_06018E70(void);
extern void FUN_0601C978(void);
extern void FUN_06014884(int r4, int r5, int r6);
extern void FUN_06018DDC(int arg);
extern void FUN_060210F6(void);
extern void FUN_06026CE0(void);
extern void FUN_0601CAEE(void);
extern void FUN_06018A3C(void);
extern void FUN_0600EB14(void);
extern void FUN_06033AAC(void);
extern void FUN_0600A140(void);
extern void FUN_0600330A(void);
extern void FUN_0601AE80(void);
extern void FUN_0600A1F6(void);
extern void FUN_06033BC8(void);
extern void FUN_0601FD74(void);
extern void FUN_0600DE40(void);
extern void FUN_0600A914(void);
extern void FUN_060055BC(void);
extern void FUN_0600338C(int r4, int r5);
extern void FUN_0600BFFC(void);
extern void FUN_0601AEB6(void);
extern void FUN_060078DC(void);
extern void FUN_060149E0(void);
extern void FUN_0601D2DC(void);
extern void FUN_0601B074(void);
extern void FUN_06018FF8(void);
extern void FUN_0601D3C0(void);
extern void FUN_060193F4(void);
extern void FUN_060196A4(void);
extern void FUN_0601950C(void);
extern void FUN_060198E0(void);
extern void FUN_06019A48(void);
extern void FUN_06019928(void);
extern void FUN_0601B160(void);
extern int  FUN_0601B418(void);
extern void FUN_0600A0C0(void);
extern void FUN_06018FA4(void);
extern void FUN_0600EC78(void);
extern void FUN_0600F424(void);


/* =================================================================
 * State 0 — Game/Course Initialization (FUN_060088CC)
 *
 * First-frame setup after power-on or full reset.
 * Calls init chain, sets GAME_STATE = 1.
 * ================================================================= */
#if 0 /* state_0_handler -- redirected to ASM import via linker PROVIDE */
void state_0_handler(void)
{
    FUN_06018E70();
    FUN_0601C978();
    FUN_06014884(4, (int)0xFFFF0000, 0);
    FUN_06018DDC(2);   /* original: r4=2, r5=2, r6=0 */
    FUN_060210F6();
    GAME_STATE = 1;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}
#endif /* state_0_handler */


/* =================================================================
 * State 1 — Long Init Chain (0x0600890A)
 *
 * Mid-function jump target within FUN_060088CC code space.
 * Just jumps to FUN_0601CAEE (no return from there).
 * ================================================================= */
void state_1_handler(void)
{
    FUN_0601CAEE();
}


/* =================================================================
 * State 2 — Attract Mode / First-Run Setup (FUN_06008938 → FUN_0600893C)
 *
 * Sets up initial game state: car count, phase flags, countdown (920
 * frames, minus 60 if 2-player mode). Transitions to state 3.
 * ================================================================= */
#if 0 /* state_2_handler -- redirected to ASM import via linker PROVIDE */
void state_2_handler(void)
{
    RACE_CAR_COUNT_BYTE = 1;
    RACE_PHASE_FLAG = 0;
    RACE_INIT_FLAG_W = 0;
    RACE_DISPLAY_BYTE = 0;
    FUN_06018A3C();
    FUN_0600EB14();
    FUN_06033AAC();
    FUN_0600A140();

    if (RACE_KEY_STATE == 0)
        FUN_0600330A();

    RACE_TRANSITION_WORD = 0;
    RACE_COUNTDOWN = 920;   /* 0x0398 */
    RACE_EXT_EVENT = 0;

    if (RACE_PLAYER_MODE == 2)
        RACE_COUNTDOWN -= 60;

    FUN_0601AE80();
    RACE_DISPLAY_FLAGS |= 0x40000000;
    GAME_STATE = 3;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 4;
}
#endif /* state_2_handler */


/* =================================================================
 * State 3 — Attract Mode Countdown (FUN_06008A18)
 *
 * Manages countdown timer with start-button override.
 * While countdown active: runs full attract-mode frame (physics,
 * collision, rendering). On timer expiry or start press, transitions
 * to state 4.
 * ================================================================= */
#if 0 /* state_3_handler -- redirected to ASM import via linker PROVIDE */
void state_3_handler(void)
{
    int countdown;

    RACE_COUNTDOWN--;
    FUN_0600A1F6();

    countdown = RACE_COUNTDOWN;

    if (countdown >= 0) {
        /* Timer still active — check for start button */
        unsigned short buttons = RACE_NEW_BUTTONS;
        if (!(buttons & 0x0800)) {
            /* No start pressed — run attract mode frame */
            if (RACE_PLAYER_MODE == 2)
                FUN_06033BC8();
            FUN_0601FD74();
            FUN_0600DE40();
            FUN_0600A914();
            FUN_060055BC();
            FUN_0600338C(RACE_COUNTDOWN, 21);
            FUN_0600BFFC();
            if (RACE_COUNTDOWN <= 580)
                FUN_0601AEB6();
            FUN_060078DC();   /* tail call: frame commit */
            return;
        }
        /* Start pressed — fall through to transition */
    }

    /* Timer expired or start pressed */
    countdown = RACE_COUNTDOWN;
    if (countdown >= 0) {
        /* Start pressed while timer still active */
        FUN_06018E70();
    } else {
        /* Timer naturally expired — cycle player mode */
        int mode = RACE_PLAYER_MODE;
        mode++;
        if ((unsigned int)mode >= 3)
            mode = 0;
        RACE_PLAYER_MODE = mode;
    }

    GAME_STATE = 4;
    RACE_TRANSITION_WORD = 3;
}
#endif /* state_3_handler */


/* =================================================================
 * State 4 — Boundary Handler (FUN_06008CCC → FUN_06008CD0)
 *
 * Sets r14=0, chains to shared handler that initializes subsystems,
 * sets countdown to 600, transitions to state 5.
 * ================================================================= */
#if 0 /* state_4_handler -- redirected to ASM import via linker PROVIDE */
void state_4_handler(void)
{
    RACE_BOUNDARY_FLAG = 0;
    FUN_060149E0();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    FUN_0601D2DC();
    FUN_0601B074();
    RACE_COUNTDOWN = 600;    /* 0x0258 */
    RACE_SOUND_STATE = 0;
    GAME_STATE = 5;
    RACE_DISPLAY_FLAGS |= 0x40000000;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;

    if (RACE_DISPLAY_BYTE == 1) {
        FUN_06018FF8();
        RACE_DISPLAY_BYTE = 0;
    }
}
#endif /* state_4_handler */


/* =================================================================
 * State 5 — Input Detection Router (FUN_06008D74)
 *
 * Checks for key code 0x70 (special input), decrements countdown.
 * On timer expiry or button press (0x0100 mask), transitions to
 * state 0 (full re-init). Always calls FUN_0601D3C0 and display
 * update.
 * ================================================================= */
#if 0 /* state_5_handler -- redirected to ASM import via linker PROVIDE */
void state_5_handler(void)
{
    int countdown;

    if (RACE_KEY_STATE == 112)  /* 0x70 */
        RACE_BOUNDARY_FLAG = 2;

    countdown = RACE_COUNTDOWN - 1;
    RACE_COUNTDOWN = countdown;

    if (countdown < 0) {
        GAME_STATE = 0;
        FUN_060149E0();
    }

    if (RACE_NEW_BUTTONS & 0x0100) {
        GAME_STATE = 0;
        FUN_060149E0();
    }

    FUN_0601D3C0();
    RACE_DISPLAY_FLAGS |= 0x04;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}
#endif /* state_5_handler */


/* =================================================================
 * State 6 — Course Select Init (FUN_06008B04)
 *
 * One-frame setup: initializes course select, transitions to state 7.
 * ================================================================= */
#if 0 /* state_6_handler -- redirected to ASM import via linker PROVIDE */
void state_6_handler(void)
{
    FUN_06018E70();
    GAME_STATE = 7;
    FUN_060193F4();
    FUN_060210F6();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;
}
#endif /* state_6_handler */


/* =================================================================
 * State 7 — Course Select Active (FUN_06008B34)
 *
 * Per-frame course selection: process input, update display.
 * ================================================================= */
#if 0 /* state_7_handler -- redirected to ASM import via linker PROVIDE */
void state_7_handler(void)
{
    FUN_060196A4();
    FUN_0601950C();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}
#endif /* state_7_handler */


/* =================================================================
 * State 8 — Car Select Init (FUN_06008B78)
 *
 * One-frame setup: initializes car/transmission select, state 9.
 * ================================================================= */
#if 0 /* state_8_handler -- redirected to ASM import via linker PROVIDE */
void state_8_handler(void)
{
    GAME_STATE = 9;
    FUN_060198E0();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;
}
#endif /* state_8_handler */


/* =================================================================
 * State 9 — Car Select Active (FUN_06008B9C)
 *
 * Per-frame car selection: process input, update display.
 * ================================================================= */
#if 0 /* state_9_handler -- redirected to ASM import via linker PROVIDE */
void state_9_handler(void)
{
    FUN_06019A48();
    FUN_06019928();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}
#endif /* state_9_handler */


/* =================================================================
 * State 10 — Loading Init (FUN_06008BD8)
 *
 * One-frame setup: starts disc loading, transitions to state 11.
 * ================================================================= */
#if 0 /* state_10_handler -- redirected to ASM import via linker PROVIDE */
void state_10_handler(void)
{
    GAME_STATE = 11;
    FUN_0601B160();
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;
}
#endif /* state_10_handler */


/* =================================================================
 * State 11 — Loading Check (FUN_06008BFC)
 *
 * Polls loading status. Non-zero return = failure/re-select (state 6).
 * Zero return = loading still in progress (stay in state 11).
 * ================================================================= */
#if 0 /* state_11_handler -- redirected to ASM import via linker PROVIDE */
void state_11_handler(void)
{
    int result = FUN_0601B418();
    if (result != 0)
        GAME_STATE = 6;
}
#endif /* state_11_handler */


/* =================================================================
 * State 12 — Race Preparation (FUN_06008E00)
 *
 * Final pre-race setup: resource validation, physics init, render.
 * Sets "race ready" flag, dispatches to handler 5 with target 15
 * (main race loop).
 * ================================================================= */
#if 0 /* state_12_handler -- redirected to ASM import via linker PROVIDE */
void state_12_handler(void)
{
    FUN_0600A0C0();
    FUN_06018FA4();
    GAME_STATE = 13;
    FUN_0600EC78();
    FUN_060210F6();
    RACE_DISPLAY_FLAGS |= 0x40000000;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;
    FUN_06018DDC(5);   /* original: r4=5, r5=5, r6=15 (tail call) */
}
#endif /* state_12_handler */


/* =================================================================
 * State 13 — Race Readiness Check (FUN_06008E48)
 *
 * Checks countdown: if expired, transitions to state 14 (race begin).
 * If still counting, calls FUN_0600F424 (loading/init continuation).
 * If state changed by a callee, tail-calls FUN_06018E70.
 * ================================================================= */
#if 0 /* state_13_handler -- redirected to ASM import via linker PROVIDE */
void state_13_handler(void)
{
    int countdown = RACE_COUNTDOWN;

    if (countdown < 0) {
        /* Timer expired — start race */
        GAME_STATE = 14;
        FUN_06026CE0();
        RACE_VBL_OUT_FLAG = 0;
    } else {
        /* Timer still active — continue init */
        FUN_0600F424();
    }

    /* If a callee changed the state away from 13, call reset */
    if (GAME_STATE != 13)
        FUN_06018E70();
}
#endif /* state_13_handler */
