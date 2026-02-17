#include "game.h"

extern int DAT_0601a6dc;
extern int DAT_0601a6de;
extern int DAT_0601a6e0;
extern int DAT_0601a6e2;
extern int DAT_0601a756;
extern int DAT_0601a758;
extern int DAT_0601a75a;
extern int DAT_0601a872;
extern int DAT_0601a926;
extern int DAT_0601a928;
extern int DAT_0601a92a;
extern int DAT_0601a9a4;
extern int DAT_0601aa3a;
extern int DAT_0601aac2;
extern int DAT_0601ae3e;
extern int DAT_0601b0c6;
extern int DAT_0601b246;
extern int DAT_0601b248;
extern int DAT_0601b24a;
extern int DAT_0601b24c;
extern int DAT_0601b24e;
extern int DAT_0601b250;
extern int DAT_0601b252;
extern int DAT_0601b254;
extern int DAT_0601b256;
extern int DAT_0601b258;
extern int DAT_0601b25a;
extern int DAT_0601b25c;
extern int DAT_0601b25e;
extern int DAT_0601b260;
extern int DAT_0601b262;
extern int DAT_0601b38a;
extern int DAT_0601b38c;
extern int DAT_0601b38e;
extern int DAT_0601b390;
extern int DAT_0601b392;
extern int DAT_0601b45a;
extern int DAT_0601b76c;
extern int DAT_0601b76e;
extern int DAT_0601b87e;
extern int DAT_0601b946;
extern int DAT_0601bb3a;
extern int DAT_0601bb3c;
extern int DAT_0601bb3e;
extern int DAT_0601bb40;
extern int DAT_0601bb42;
extern int DAT_0601bb44;
extern int DAT_0601bb46;
extern int DAT_0601bb48;
extern int DAT_0601bb4a;
extern int DAT_0601bbc0;
extern int DAT_0601bbc2;
extern int DAT_0601bcba;
extern char * FUN_0601adb0();
extern unsigned int FUN_0601ae2c();
extern int FUN_0601bbcc();
extern int PTR_DAT_0601a4a8;
extern int PTR_DAT_0601a608;
extern int PTR_DAT_0601a75c;
extern int PTR_DAT_0601ace4;
extern int PTR_DAT_0601b0c8;
extern int PTR_DAT_0601b264;
extern int PTR_DAT_0601b394;

/* course_vdp_tile_load -- Load course-specific VDP tile sprites.
 * Dispatches on param_2 (bank 0xA8 vs 0xA9):
 *   0xA8: uses tile table 0x06049C28, count table 0x06049CCC,
 *          index table 0x06049CD4. Slots 1/4 get priority 2, others 3.
 *   0xA9: uses tile table 0x06049B36, count table 0x06049C14,
 *          index table 0x06049C1E. Slots 5/8 get priority 2, others 3.
 * Renders tile count sprites via VDP1 draw (0x060283E0),
 * then renders final overlay sprite via 0x060284AE at priority 0x60. */
void FUN_0601a3f4(param_1, param_2)
    unsigned short param_1;
    unsigned int param_2;
{
  unsigned char base_idx;
  unsigned char *count_ptr;
  unsigned char tile_idx;
  int priority;
  char *sprite_data = (char *)0x06049E54;
  if ((param_2 & 0xffff) == 0xa8) {
    /* bank A (0xA8) */
    base_idx = ((int *)0x06049CD4)[param_1];
    priority = ((param_1 == 1) || (param_1 == 4)) ? 2 : 3;
    count_ptr = (unsigned char *)0x06049CCC + param_1;
    for (tile_idx = 0; tile_idx < *count_ptr; tile_idx = tile_idx + 1) {
      (*(int(*)())0x060283E0)(priority << 2,
          ((unsigned int)(unsigned char)((char *)(0x06049C28 + ((unsigned int)base_idx + (unsigned int)tile_idx) << 1))[1] * 0x40
          + (unsigned int)(unsigned char)((int *)0x06049C28)[((unsigned int)base_idx + (unsigned int)tile_idx) << 1]) << 1,
          0, sprite_data);
    }
    count_ptr = (unsigned char *)0x06059084 + (unsigned int)(param_1 << 1);
    sprite_data = (char *)0x06049E58;
  } else {
    /* bank B (0xA9) */
    base_idx = ((int *)0x06049C1E)[param_1];
    priority = ((param_1 == 5) || (param_1 == 8)) ? 2 : 3;
    count_ptr = (unsigned char *)0x06049C14 + param_1;
    for (tile_idx = 0; tile_idx < *count_ptr; tile_idx = tile_idx + 1) {
      (*(int(*)())0x060283E0)(priority << 2,
          ((unsigned int)(unsigned char)((char *)0x06049B36 + (((unsigned int)base_idx + (unsigned int)tile_idx) << 1))[1] * 0x40 +
          (unsigned int)(unsigned char)((char *)0x06049B36)[((unsigned int)base_idx + (unsigned int)tile_idx) << 1]) << 1,
          0, sprite_data);
    }
    count_ptr = (unsigned char *)0x06059060 + (unsigned int)(param_1 << 1);
    sprite_data = (char *)0x06049E58;
  }
  /* render final overlay sprite */
  (*(int(*)())0x060284AE)(priority << 2,
      ((unsigned int)count_ptr[1] * 0x40 + (unsigned int)*count_ptr) << 1,
      0x60, sprite_data);
  return;
}


/* menu_cursor_animate -- Render animated cursor sprite on menu screen.
 * Selection at 0x06085FF0 == 3: uses priority 3, alternate sprite (6 or 7)
 * based on animation counter 0x0605D242 (resets at 0x10).
 * Otherwise: uses priority 5/6 pair.
 * Mode flag 0x0605D241: selects between two sprite position sets.
 * Renders two sprites via VDP1 draw (0x06028400) at priority 0xC. */
void FUN_0601a65e()
{
  int priority_a, priority_b;
  int *sprite_pair;
  char *sprite_base = (char *)0x06063750;
  if (*(int *)0x06085FF0 == '\x03') {
    priority_a = 3;
    if ((unsigned char)*(int *)0x0605D242 < 8) {
      priority_b = 6;
    } else {
      priority_b = 7;
      if (0x10 < (unsigned char)*(int *)0x0605D242) {
        *(int *)0x0605D242 = 0;  /* reset animation counter */
      }
    }
  } else {
    priority_b = 6;
    priority_a = 5;
  }
  if (*(int *)0x0605D241 == '\0') {
    /* normal mode: position set A */
    (*(int(*)())0x06028400)(0xc, *(int *)(0x06063750 + DAT_0601a6de), (int)DAT_0601a6e0,
               (priority_b << 12) + *(int *)((int)(0x06063750 + DAT_0601a6de) + 4));
    sprite_pair = (int *)(sprite_base + DAT_0601a6e2);
    priority_a = (priority_a << 12) + sprite_pair[1];
  } else {
    /* alternate mode: position set B */
    (*(int(*)())0x06028400)(0xc, *(int *)(0x06063750 + DAT_0601a756), (int)DAT_0601a758,
               (priority_a << 12) + *(int *)((int)(0x06063750 + DAT_0601a756) + 4));
    sprite_pair = (int *)(sprite_base + DAT_0601a75a);
    priority_a = (priority_b << 12) + sprite_pair[1];
  }
  (*(int(*)())0x06028400)(0xc, *sprite_pair, (int)PTR_DAT_0601a75c, priority_a);
  return;
}

/* menu_cursor_sound -- Play menu cursor movement sound effect.
 * Checks flag at 0x0605D241; plays sound 0x06 if clear, 0x07 if set.
 * Channel 0xF is the menu/UI sound channel. */
extern void sound_cmd_dispatch(int channel, int command);

/* sound_mode_select -- selects BGM track based on game mode flag.
 *   Flag at 0x0605D241: 0 = normal mode (track 0x06), non-zero = alt mode (track 0x07).
 *   Dispatches via sound_cmd_dispatch channel 0xF (direct SCSP command). */
void sound_mode_select(void)
{
    if (*(int *)0x0605D241 == '\0') {
        sound_cmd_dispatch(0xF, 0xAE0006FF);   /* SCSP: BGM track 0x06 (normal) */
    } else {
        sound_cmd_dispatch(0xF, 0xAE0007FF);   /* SCSP: BGM track 0x07 (alt) */
    }
}

/* course_select_display_update -- Update course selection display scroll.
 *
 * Pool verified (0x0601A874-0x0601A93C):
 *   0x0601A874 = 0x06063D98 (INPUT_BASE — controller input words)
 *   0x0601A878 = 0x0605D248 (CSEL_SCROLL_INDEX)
 *   0x0601A87C = 0x00008000 (DPAD_UP)
 *   0x0601A880 = 0x0605D243 (CSEL_REPEAT_TIMER)
 *   0x0601A926 = 0x0600 (CSEL_CONFIRM_MASK)
 *   0x0601A928 = 0x079C (scroll plane A ID)
 *   0x0601A92A = 0x081C (scroll plane B ID)
 *   0x0601A92C = 0x06018DDC (FUN_06018DDC — confirm handler)
 *   0x0601A930 = 0x060283E0 (vdp2_scroll_set — VDP2 scroll register writer)
 *   0x0601A934 = 0x06049CDC (scroll param table)
 *   0x0601A938 = 0x0605D2B4 (scroll offset table)
 *   0x0601A93C = 0x0000E000 (VDP2 scroll page offset)
 *
 * Handles D-pad up/down to change course selection index (0..0x14).
 * Auto-repeat at threshold 0x14 frames. Renders two VDP2 scroll
 * planes (A and B) with course-dependent offsets from lookup table. */
#define CSEL_INPUT_BASE       ((volatile unsigned short *)0x06063D98)
#define CSEL_SCROLL_INDEX     (*(volatile int *)0x0605D248)
#define CSEL_REPEAT_TIMER     (*(volatile char *)0x0605D243)
#define DPAD_UP               0x8000
#define CSEL_REPEAT_THRESHOLD 0x14
#define CSEL_CONFIRM_MASK     0x0600
#define CSEL_SCROLL_TABLE     0x0605D2B4
#define vdp2_scroll_set       ((void (*)(int, int, int, int))0x060283E0)
#define SCROLL_PARAM_TABLE    0x06049CDC
#define VDP2_SCROLL_PAGE      0x0000E000
#define SCROLL_PLANE_A_ID     0x079C
#define SCROLL_PLANE_B_ID     0x081C
void course_select_display_update()
{
    int index_val;

    /* D-pad input: up/down changes scroll index */
    if ((CSEL_INPUT_BASE[1] & DPAD_UP) != 0) {
        /* Edge-triggered UP pressed */
        CSEL_SCROLL_INDEX = CSEL_SCROLL_INDEX + 1;
        CSEL_REPEAT_TIMER = 0;
    } else if ((CSEL_INPUT_BASE[1] & DAT_0601a872) != 0) {
        /* Edge-triggered DOWN pressed */
        CSEL_SCROLL_INDEX = CSEL_SCROLL_INDEX + -1;
        CSEL_REPEAT_TIMER = 0;
    } else if ((CSEL_INPUT_BASE[0] & DPAD_UP) != 0) {
        /* Held UP with repeat */
        if (CSEL_REPEAT_TIMER == CSEL_REPEAT_THRESHOLD) {
            CSEL_SCROLL_INDEX = CSEL_SCROLL_INDEX + 1;
            CSEL_REPEAT_TIMER = 0;
        }
    } else if ((CSEL_INPUT_BASE[0] & DAT_0601a872) != 0) {
        /* Held DOWN with repeat */
        if (CSEL_REPEAT_TIMER == CSEL_REPEAT_THRESHOLD) {
            CSEL_SCROLL_INDEX = CSEL_SCROLL_INDEX + -1;
            CSEL_REPEAT_TIMER = 0;
        }
    }

    /* Clamp and wrap scroll index */
    if ((CSEL_INPUT_BASE[1] & 0xf8) != 0) {
        CSEL_SCROLL_INDEX = 0;
    }
    if (CSEL_SCROLL_INDEX > CSEL_REPEAT_THRESHOLD) {
        CSEL_SCROLL_INDEX = 0;
    }
    if (CSEL_SCROLL_INDEX < 0) {
        CSEL_SCROLL_INDEX = (char *)CSEL_REPEAT_THRESHOLD;
    }

    /* Handle confirm button */
    if ((CSEL_INPUT_BASE[1] & CSEL_CONFIRM_MASK) != 0) {
        index_val = CSEL_SCROLL_INDEX + 2;
        (*(int(*)())0x06018DDC)(index_val, index_val, 0, 0, index_val);
    }

    /* Render VDP2 scroll planes: clear then set with course-specific offsets */
    vdp2_scroll_set(0xc, SCROLL_PLANE_A_ID, 0, SCROLL_PARAM_TABLE);
    vdp2_scroll_set(0xc, SCROLL_PLANE_B_ID, 0, SCROLL_PARAM_TABLE);

    vdp2_scroll_set(0xc, SCROLL_PLANE_A_ID, VDP2_SCROLL_PAGE,
                    *(int *)(CSEL_SCROLL_TABLE + (CSEL_SCROLL_INDEX << 3)));

    vdp2_scroll_set(0xc, SCROLL_PLANE_B_ID, VDP2_SCROLL_PAGE,
                    *(int *)(CSEL_SCROLL_TABLE + ((CSEL_SCROLL_INDEX << 1) + 1) << 2));
}
#undef CSEL_INPUT_BASE
#undef CSEL_SCROLL_INDEX
#undef CSEL_REPEAT_TIMER
#undef DPAD_UP
#undef CSEL_REPEAT_THRESHOLD
#undef CSEL_CONFIRM_MASK
#undef CSEL_SCROLL_TABLE
#undef vdp2_scroll_set
#undef SCROLL_PARAM_TABLE
#undef VDP2_SCROLL_PAGE
#undef SCROLL_PLANE_A_ID
#undef SCROLL_PLANE_B_ID

/* course_select_input -- Handle D-pad input for course/music selection menu.
 * Reads input from 0x06063D98 (raw + edge-triggered). Up/Down changes
 * selection index at 0x0605D24C (range 0..0x31). Input repeat timer
 * at 0x0605D243 (threshold 0x14). On confirm (DAT_0601aa3a), resets
 * attract mode flags, switches sound bank if crossing threshold 0x24,
 * plays selection sound via SCSP (0x0601D5F4). Renders 4 sprite
 * layers for the selection highlight via VDP1 (0x060283E0). */
void FUN_0601a940()
{
  char *repeat_timer = (char *)0x0605D243;
  char *select_idx = (char *)0x0605D24C;
  char *input_base = (char *)0x06063D98;

  /* --- D-pad input processing (edge + held with repeat) --- */
  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {
    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a9a4) == 0) {
      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {
        if (((*(unsigned short *)0x06063D98 & DAT_0601a9a4) != 0) &&
            (*(int *)0x0605D243 == '\x14')) {            /* repeat threshold met */
          *(int *)0x0605D24C = *(int *)0x0605D24C + -1;  /* decrement selection */
          *repeat_timer = 0;
        }
      } else if (*(int *)0x0605D243 == '\x14') {
        *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01'; /* increment selection */
        *repeat_timer = 0;
      }
    } else {
      *(int *)0x0605D24C = *(int *)0x0605D24C + -1;     /* edge-triggered down */
      *repeat_timer = 0;
    }
  } else {
    *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01';   /* edge-triggered up */
    *repeat_timer = 0;
  }
  /* --- clamp selection to 0..0x31 with wrap --- */
  if ('1' < (char)*select_idx) {
    *select_idx = 0;
  }
  if ((char)*select_idx < '\0') {
    *select_idx = (char *)0x31;                          /* wrap to max */
  }
  if ((*(unsigned short *)(input_base + 2) & 0xf8) != 0) { /* any button: reset to 0 */
    *select_idx = 0;
  }
  /* --- confirm button handling --- */
  if ((*(unsigned short *)(input_base + 2) & DAT_0601aa3a) != 0) {
    if (*(int *)0x06085FF6 != '\0') {                    /* reset attract state */
      (*(int(*)())0x06012EC4)();
      (*(int(*)())0x06012F00)();
      *(int *)0x06085FF6 = 0;
    }
    if ((char)*select_idx < '$') {                       /* below sound bank threshold */
      if (*(int *)0x06085FF7 != '\0') {
        (*(int(*)())0x060191E0)();                       /* switch to bank A */
        *(int *)0x06085FF7 = 0;
      }
    } else if (*(int *)0x06085FF7 != '\x01') {
      (*(int(*)())0x06019248)();                         /* switch to bank B */
      *(int *)0x06085FF7 = 1;
    }
    (*(int(*)())0x0601D5F4)(0, 0xAE0001FF);             /* confirm sound */
    (*(int(*)())0x0601D5F4)(0, *(int *)(0x06049CFC + (char)(*select_idx << 2))); /* selection sound */
  }
  /* --- sprite rendering: 4 layers for selection highlight --- */
  (*(int(*)())0x060283E0)(0xc, (int)DAT_0601aac2, 0, 0x06049CDC);           /* background A */
  (*(int(*)())0x060283E0)(0xc, (int)0x091CFFFF, 0, 0x06049CDC);             /* background B */
  (*(int(*)())0x060283E0)(0xc, (int)0x091CFFFF, 0x0000E000,                 /* highlight A */
                    *(int *)(0x0605D35C + (char)(*select_idx << 3)));
  (*(int(*)())0x060283E0)(0xc, (int)DAT_0601aac2, 0x0000E000,               /* highlight B */
                    *(int *)(0x0605D35C + (char)(*select_idx << 3) + 4));
}



/* high_score_insert -- Insert new race time into high score table.
 * Looks up course-specific score table from 0x0605DD6C indexed by
 * CAR_COUNT*6 + course. Scans 0x13 entries (stride 0xC) to find
 * insertion point for race time at 0x060786A4. Shifts entries down
 * via memcpy (0x06035168), writes new entry: time at +4, character
 * index at +8 (via FUN_0601ae2c), difficulty at +9, demo flag at +10.
 * Also checks lap record: updates best lap at table+4 if beaten.
 * Stores result pointer at 0x06085FFC, rank at 0x06086012. */
unsigned int FUN_0601ac7c()
{
  unsigned int result;
  char char_idx;
  int score_table;
  int lap_table;
  char *entry;
  unsigned char rank;

  score_table = *(int *)(0x0605DD6C +
                  (CAR_COUNT * 6 + *(int *)(0x0605AD00 << 1)) << 2);  /* course score table */
  lap_table = *(int *)(0x0605DE24 + *(int *)(0x0607EAD8 << 3));       /* lap record table */
  result = (unsigned int)PTR_DAT_0601ace4;
  rank = 0x13;                                           /* start from bottom (19th place) */
  if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(score_table + result)) &&
     (result = 0, *(int *)0x0607EBF4 != 0)) {           /* race completed & beats worst */
    do {
      if (*(unsigned int *)((rank - 1) * 0xc + score_table + 4) <= *(unsigned int *)0x060786A4) break;
      (*(int(*)())0x06035168)();                         /* shift entry down (memcpy) */
      rank = rank - 1;
    } while (rank != 0);
    entry = (char *)((unsigned int)rank * 0xc + score_table);
    *(int *)(entry + 4) = *(int *)0x060786A4;            /* write race time */
    char_idx = FUN_0601ae2c();                           /* get character index */
    entry[8] = char_idx;
    entry[9] = *(int *)0x0605DE3C;                       /* difficulty level */
    result = DEMO_MODE_FLAG & 0xff;
    entry[10] = (char)DEMO_MODE_FLAG;                    /* demo flag */
    *entry = 0;                                          /* mark entry valid */
    *(char **)0x06085FFC = entry;                        /* store result pointer */
    *(int *)0x06086012 = rank;                           /* store final rank */
  } else {
    *(int *)0x06085FFC = 0;                              /* no new record */
  }
  /* --- lap record check --- */
  if ((*(int *)0x06078638 < *(int *)(lap_table + 4)) && (0 < *(int *)0x06078638)) {
    *(int *)(lap_table + 4) = *(int *)0x06078638;        /* update best lap */
    *(int *)0x06086000 = lap_table;
  } else {
    *(int *)0x06086000 = 0;
  }
  return result;
}

/* best_record_update -- Update best lap/race records if current times are better.
 * Only operates in non-demo mode (DEMO_MODE_FLAG != 0).
 * Checks lap time at 0x06078638 against stored best, updates if beaten.
 * Checks race time at 0x060786A4 against stored best, updates if beaten.
 * Returns pointer to updated record entry, or NULL if no update. */
char * FUN_0601adb0(void)
{
    char *course_ptr = (char *)0x0607EAD8;
    char *result = (char *)0x0;
    if (DEMO_MODE_FLAG != 0) {
        if ((*(int *)0x06078638 <
             *(int *)(*(int *)(0x0605DE24 +
                              (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4)) &&
            (0 < *(int *)0x06078638)) {
            *(int *)(*(int *)(0x0605DE24 +
                     (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4) =
                *(int *)(CAR_ARRAY_BASE + DAT_0601ae3e);
        }
        result = 0x0605DE40 + (char)((char)*(int *)course_ptr * '\f');
        if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(result + *(int *)(0x0605AD00 << 2))) &&
            (result = (char *)0x0, *(int *)0x0607EBF4 != 0)) {
            result = 0x0605DE40 + (char)((char)*(int *)course_ptr * '\f');
            *(int *)(result + *(int *)(0x0605AD00 << 2)) = *(int *)0x060786A4;
        }
    }
    return result;
}


/* display_mode_init -- Initialize display subsystem state and load VDP2 scroll data.
 * Resets mode counters, then DMA-copies 3 scroll plane data blocks to VRAM:
 *   VDP2 color RAM (0x25F006C0), scroll plane A (0x25F00180), pattern (0x25F00000). */
void FUN_0601ae80(void)
{
    register int dma_func asm("r3") = 0x0602761E;

    *(int *)0x06086010 = 0;
    *(int *)0x0608600F = 0x28;
    *(int *)0x06086011 = 0;

    (*(int(*)())dma_func)(0x25F006C0, 0x0604866C, 0x60);      /* color RAM */
    (*(int(*)())dma_func)(0x25F00180, 0x060485CC, 0x20);       /* scroll plane A */
    (*(void(*)())0x0602766C)(0x25F00000, 0x0604996C, 0x180);   /* pattern data */
}

/* FUN_0601aeb6: L2 version in mode_dispatch.c */
extern void FUN_0601AEB6(void);
void FUN_0601aeb6(void) { FUN_0601AEB6(); }

/* FUN_0601b074: L2 version in display_region_init.c */
extern void FUN_0601B074(void);
extern void FUN_0601abc6();
extern void FUN_0601ab8c();
extern void FUN_0601a5f8();
void FUN_0601b074(void) { FUN_0601B074(); }

/* menu_text_render -- Render menu text from lookup table.
 * Computes index: param_1*6 + param_2*2 + language_byte at 0x0605D4F7.
 * Looks up text pointer from table at 0x0605DD6C, renders with FUN_0601bbcc.
 * param_3 = character count (fixed 6). */
void FUN_0601b09a(char param_1, char param_2, char param_3)
{
    int idx = param_1 * 6 + (param_2 << 1) + (unsigned int)(unsigned char)*(int *)0x0605D4F7;
    int text_ptr = *(int *)(0x0605DD6C + (idx << 2));
    FUN_0601bbcc(text_ptr, (int)param_3, 6);
}

/* tile_row_render_loop -- Render 5 tile rows of text/graphics.
 * Each iteration draws a header tile (0x0604A490), a body tile (0x0604A4B8),
 * and a separator tile using the DMA sprite renderer at 0x060284AE.
 * Row stride is 3 (rows 6-20 in steps of 3). */
void FUN_0601b0d8(void)
{
    int row_base;
    unsigned short count = 0;
    unsigned int row = 0;
    do {
        row_base = ((row & 0xffff) + 6) << 6;
        (*(int(*)())0x060284AE)(8, (row_base + 2) << 1, 0x60, 0x0604A490);
        (*(int(*)())0x060284AE)(8, (((row & 0xffff) + 7) << 6 + 0x21) << 1, 0x60, 0x0604A4B8);
        (*(int(*)())0x060284AE)(0xc, (row_base + 0x25) << 1, 0x60, 0x0604A4B8);
        count = count + 1;
        row = row + 3;
    } while (count < 5);
}

/* menu_scene_init -- Initialize menu/selection screen.
 * Registers 3 sprite characters, configures sprite table entries,
 * DMA copies sprite data and palettes, sets up VDP2 scroll planes,
 * disables input during transition, clears menu state variables. */
void FUN_0601b160()
{
  char *sprite_src;
  char *render_flush;
  char *render_flags;
  int sprite_id_a;
  int sprite_data_offset_b;
  int sprite_data_offset_c;
  int sprite_id_c;
  int sprite_id_a_val;
  int sprite_id_b;
  int char_height;
  char *vdp_char_register;   /* 0x06007658 */
  char *sprite_table_entry;  /* 0x06007540 */
  char *vdp2_reg_config;     /* 0x06038BD4 */
  *(int *)0x0606A4F4 = 0;
  *(int *)0x0606A4EC = (int)DAT_0601b246;
  /* Initialize render subsystem */
  (*(int(*)())0x06039250)(0x06063F5C);
  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_0601b24a,(int)DAT_0601b248);
  VDP1_CMD_BASE_PTR = 0;
  **(short **)0x06063F5C = (short)0x00008000;
  (*(int(*)())0x06012E00)();
  /* DMA copy sprite data from CD buffer (0x002A0000) to VRAM */
  sprite_src = (char *)0x002A0000;
  (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C,0x002A0000,
             0x640);
  /* Register 3 sprite characters with vdp1_char_register */
  vdp_char_register = (char *)0x06007658;
  sprite_id_a_val = 0x101;
  char_height = 0xb40;
  sprite_data_offset_b = 0x4b46;
  (*(int(*)())0x06007658)(sprite_id_a_val,char_height,0x78);
  sprite_id_b = (int)DAT_0601b254;
  sprite_data_offset_c = (int)DAT_0601b256;
  (*(int(*)())vdp_char_register)(sprite_id_b,char_height,0x7c);
  sprite_id_c = 0x103;
  sprite_id_a = (int)DAT_0601b25a;
  (*(int(*)())vdp_char_register)(sprite_id_c,char_height,0x80);
  /* Configure sprite table entries (pass 1) */
  sprite_table_entry = (char *)0x06007540;
  (*(int(*)())0x06007540)((int)DAT_0601b260,sprite_id_a_val,(int)DAT_0601b25e);
  (*(int(*)())sprite_table_entry)(DAT_0601b262 + 0x7d,sprite_id_b);
  (*(int(*)())sprite_table_entry)(PTR_DAT_0601b264 + 0x7a,sprite_id_c);
  /* Upload sprite character data (pass 1) */
  (*(int(*)())vdp_char_register)(sprite_id_a_val,char_height,0x78,sprite_src + sprite_data_offset_b);
  (*(int(*)())vdp_char_register)(sprite_id_b,char_height,0x7c,sprite_src + sprite_data_offset_c);
  (*(int(*)())vdp_char_register)(sprite_id_c,char_height,0x80,sprite_src + sprite_id_a);
  /* Configure sprite table entries (pass 2) */
  (*(int(*)())sprite_table_entry)((int)DAT_0601b260,sprite_id_a_val,(int)DAT_0601b25e);
  (*(int(*)())sprite_table_entry)(DAT_0601b262 + 0x7d,sprite_id_b);
  (*(int(*)())sprite_table_entry)(DAT_0601b38a + 0x7a,sprite_id_c);
  /* Upload sprite character data (pass 2) */
  (*(int(*)())vdp_char_register)(sprite_id_a_val,char_height,0x78,sprite_src + sprite_data_offset_b);
  (*(int(*)())vdp_char_register)(sprite_id_b,char_height,0x7c,sprite_src + sprite_data_offset_c);
  (*(int(*)())vdp_char_register)(sprite_id_c,char_height,(int)DAT_0601b38c,sprite_src + sprite_id_a);
  /* Configure sprite table entries (pass 3) */
  (*(int(*)())sprite_table_entry)((int)DAT_0601b390,sprite_id_a_val,(int)DAT_0601b38e);
  (*(int(*)())sprite_table_entry)(DAT_0601b392 + 0x7d,sprite_id_b);
  (*(int(*)())sprite_table_entry)(DAT_0601b38a + 0x7a,sprite_id_c);
  *(short *)0x0605AAA0 = 0;
  render_flush = (char *)0x06026CE0;
  render_flags = (char *)0x0605B6D8;
  /* Disable input during scene transition */
  INPUT_STATE = INPUT_STATE | 0x80000000;
  /* Flush render pipeline twice */
  (*(int(*)())render_flush)();
  (*(int(*)())0x06026CE0)();
  /* DMA copy palettes to VDP2 color RAM */
  (*(int(*)())0x0602766C)(0x25F00540,0x0604842C,0x40);  /* palette A → CRAM 0x540 */
  (*(int(*)())0x0602766C)(0x25F001A0,0x060487EC,0x20);  /* palette B → CRAM 0x1A0 */
  /* Load VDP2 scroll plane data */
  (*(int(*)())0x0600511E)(0x25E6F9C4,0x00017700,0,9);
  render_flush = (char *)0x06094FA8;
  (*(int(*)())0x06028654)(0x25E75DDC);                   /* VDP2 pattern name table */
  (*(int(*)())0x06028400)(4,render_flush,0,0x0000B000);  /* VDP1 command table flush */
  /* Flush scroll plane display (layers 0x10 and 0x20) */
  (*(int(*)())0x06014884)(0x10,0,0);
  (*(int(*)())0x06014884)(0x20,0,0);
  /* Configure VDP2 registers: scroll priorities and display enables */
  vdp2_reg_config = (char *)0x06038BD4;
  (*(int(*)())0x06038BD4)((int)PTR_DAT_0601b394,7);
  (*(int(*)())vdp2_reg_config)(4,0);     /* NBG0 priority */
  (*(int(*)())vdp2_reg_config)(8,1);     /* NBG1 priority */
  (*(int(*)())vdp2_reg_config)(0x10,6);  /* NBG2 priority */
  (*(int(*)())vdp2_reg_config)(0x20,5);  /* NBG3 priority */
  (*(int(*)())vdp2_reg_config)(1,0);     /* RBG0 priority */
  (*(int(*)())0x0602853E)(0xc);          /* VDP1 command count */
  (*(int(*)())0x06028560)();             /* VDP1 command flush */
  /* Set render flags and clear menu state */
  *(unsigned int *)render_flags = *(unsigned int *)render_flags | 0x40000000;
  *(int *)0x0608600D = 0;   /* menu mode index */
  *(int *)0x0608600C = 0;   /* menu state */
  *(int *)0x0608600E = 0;   /* menu sub-state */
  /* Send CD command (mode 4, params 4, 0xF) */
  (*(int(*)())0x06018DDC)(4,4,0xf);
  return;
}

/* menu_frame_update -- Per-frame menu/select screen update.
 * Dispatches through menu mode vtable (indexed by 0x0608600D),
 * updates background scroll with fixed-point parameters,
 * commits frame display, increments menu animation counter.
 * Returns current menu state byte. */
int FUN_0601b418(void)
{
    (*(int(*)())(*(int *)(0x0605DEB4 + (unsigned int)(unsigned char)*(int *)(0x0608600D << 2))))();
    (*(int(*)())0x06011AF4)(0x01000000, 0x01000000, 0x00200000, 0x00200000,
                            0x00008000, 0x00010000, 0x101);
    (*(int(*)())0x060078DC)();  /* frame_end_display_commit */
    *(short *)0x0605D4F8 = *(short *)0x0605D4F8 + 1;
    return (int)(char)*(int *)0x0608600C;
}

/* menu_item_highlight -- cycles through 3 menu items with input and renders highlight.
 *   Reads joypad input (0x06063D98+2) for up/down navigation.
 *   Cycles selection index at 0x0608600E through 0-2 range.
 *   Renders 3 sprites via VDP1 draw (0x06028400) with blink effect
 *   on selected item (priority 1 vs 2 based on frame counter bit 2). */
void menu_item_highlight()
{
  char prev_sel;
  char *sel_index = (char *)0x0608600E;    /* current selection (0-2) */
  int priority;
  unsigned char idx;
  unsigned char local_28[4];
  unsigned char local_24[8];
  (*(int(*)())0x06035228)();               /* read joypad state */
  (*(int(*)())0x06035228)();               /* read joypad state (2nd port) */
  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76c) == 0) {
    /* No up press — check down */
    if (((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76e) != 0) &&
       (prev_sel = *sel_index, *sel_index = prev_sel + '\x01', '\x02' < (char)(prev_sel + '\x01'))) {
      *sel_index = 0;                      /* wrap to first item */
    }
  } else {
    /* Up pressed — decrement selection */
    prev_sel = *sel_index;
    *sel_index = prev_sel + -1;
    if ((char)(prev_sel + -1) < '\0') {
      *sel_index = 2;                      /* wrap to last item */
    }
  }
  idx = 0;
  do {
    if ((int)(char)*sel_index == (unsigned int)idx) {
      /* Selected item: blink priority based on frame counter */
      if ((*(unsigned short *)0x0605D4F8 & 4) == 0) {
        priority = 2;
      } else {
        priority = 1;                      /* bright frame */
      }
    } else {
      priority = 2;                        /* unselected items: normal */
    }
    (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + (idx + 0x36) << 3),
               ((unsigned int)local_28[idx] * 0x40 + (unsigned int)local_24[idx]) << 1,
               (priority << 12) + *(int *)((int)(0x06063750 + (idx + 0x36) << 3) + 4));
    idx = idx + 1;
  } while (idx < 3);
  return;
}

/* dual_column_selector -- two-column menu with per-item value cycling and sprite rendering.
 *   Column 0 at 0x0605D4F4, column 1 at 0x0605D4F5. Active column at 0x0608600E.
 *   D-pad left/right (0x8000 / DAT_0601b87e) cycles value within column bounds.
 *   Renders 3 items per column via VDP1 draw (0x06028400) with blink on selected.
 *   Background scroll rendered via 0x06011AF4 per item. */
void dual_column_selector()
{
  char *sprite_table = (char *)0x06063750;
  char *col_select = (char *)0x0608600E;       /* active column (0 or 1) */
  char *col0_val = (char *)0x0605D4F4;         /* column 0 selected value */
  char *col1_val = (char *)0x0605D4F5;         /* column 1 selected value */
  char prev_val;
  int *sprite_entry;
  char *max_vals;
  int priority;
  unsigned char idx;
  char auStack_38[4];                          /* max value per column */
  unsigned char local_34[4];
  int local_30[3];
  unsigned char local_24;
  unsigned char local_23;
  (*(int(*)())0x06035228)();                   /* read joypad port 1 */
  (*(int(*)())0x06035168)();                   /* process input */
  (*(int(*)())0x06035228)();                   /* read joypad port 2 */
  max_vals = auStack_38;
  (*(int(*)())0x06035228)();                   /* read joypad (additional) */
  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b87e) == 0) {
    /* No left press — check right (0x8000) */
    if ((((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) != 0) &&
       (prev_val = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + '\x01',
       ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = prev_val, (char)max_vals[(char)*col_select] <= prev_val)) {
      ((int *)0x0605D4F4)[(char)*col_select] = 0; /* wrap to first value */
    }
  } else {
    /* Left pressed — decrement value */
    prev_val = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + -1;
    ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = prev_val;
    if (prev_val < '\0') {
      ((int *)0x0605D4F4)[(char)*col_select] = max_vals[(char)*col_select] + -1;
    }
  }
  /* Render column 0 (3 items at sprite offsets 0x30-0x32) */
  col_select = (char *)0x0605D4F4;
  idx = 0;
  do {
    if ((int)(char)*col_select == (unsigned int)idx) {
      priority = 1;                            /* selected: high priority */
    } else {
      priority = 4;                            /* unselected: low priority */
    }
    (*(int(*)())0x06011AF4)(local_30[idx], 0xFFD40000, 0x002F0000, 0x001C0000, 0x00008000,
               0x00010000, (unsigned int)idx + priority + 0x100);
    if ((int)(char)*col_select == (unsigned int)idx) {
      /* Blink selected item based on frame counter */
      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\0')) {
        priority = 4;                          /* dim frame (column 0 active) */
      } else {
        priority = 3;                          /* bright frame */
      }
    } else {
      priority = 4;
    }
    sprite_entry = (int *)(sprite_table + ((idx + 0x30) << 3));
    (*(int(*)())0x06028400)(8, *sprite_entry, ((unsigned int)local_34[idx] + (unsigned int)(local_24 << 6)) << 1,
               (priority << 12) + sprite_entry[1]);
    col1_val = (char *)0x0605D4F5;
    idx = idx + 1;
  } while (idx < 3);
  /* Render column 1 (3 items at sprite offsets 0x33-0x35) */
  idx = 0;
  do {
    if ((int)(char)*col1_val == (unsigned int)idx) {
      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\x01')) {
        priority = 4;                          /* dim frame (column 1 active) */
      } else {
        priority = 3;                          /* bright frame */
      }
    } else {
      priority = 4;
    }
    sprite_entry = (int *)(sprite_table + ((idx + 0x33) << 3));
    (*(int(*)())0x06028400)(8, *sprite_entry, ((unsigned int)local_34[idx] + (unsigned int)(local_23 << 6)) << 1,
               (priority << 12) + sprite_entry[1]);
    idx = idx + 1;
  } while (idx < 3);
  return;
}

/* select_confirm_display -- renders confirmation screen for car/transmission selection.
 *   param_1 = car index (selects sprite at offset 0x30+), param_2 = transmission index
 *   (offset 0x33+), param_3 = display mode. Reads joypad, draws background overlay
 *   sprites at priority 0xA, selected car/trans sprites at priority 0x9.
 *   Looks up combination data from table at 0x0605DD6C, renders name initials
 *   via FUN_0601bbcc, draws record time via 0x06005DD4. */
void select_confirm_display(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{
  char *game_mode = (char *)0x0605D4F7;       /* current game mode byte */
  char *vdp1_draw_offset = (char *)0x060284AE; /* VDP1 draw with offset */
  char *sprite_table = (char *)0x06063750;
  char *vdp1_draw = (char *)0x06028400;        /* VDP1 sprite draw */
  int time_display;
  char *record_ptr;
  char auStack_1c[8];
  (*(int(*)())0x06035228)();                   /* read joypad */
  /* Draw background overlay sprites */
  (*(int(*)())0x06028400)(0xc, *(int *)(0x06063750 + DAT_0601bb3a), 0x290,
             0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601bb3a) + 4));
  (*(int(*)())vdp1_draw)(0xc, *(int *)(sprite_table + DAT_0601bb3e), (int)DAT_0601bb40,
                    0x0000A000 + *(int *)((int)(sprite_table + DAT_0601bb3e) + 4));
  /* Draw selected car sprite */
  (*(int(*)())vdp1_draw)(0xc, *(int *)(sprite_table + ((param_1 + 0x30) << 3)), 0x390,
                    0x00009000 + *(int *)((int)(sprite_table + ((param_1 + 0x30) << 3)) + 4));
  /* Draw selected transmission sprite */
  (*(int(*)())vdp1_draw)(0xc, *(int *)(sprite_table + ((param_2 + 0x33) << 3)), (int)DAT_0601bb44,
                    0x00009000 + *(int *)((int)(sprite_table + ((param_2 + 0x33) << 3)) + 4));
  /* Render name initials from combination table */
  FUN_0601bbcc(*(int *)
                (0x0605DD6C + (param_1 * 6 + (param_2 << 1) + (unsigned int)(unsigned char)*game_mode) << 2),
               (int)param_3, 10);
  /* Draw record label sprite */
  (*(int(*)())vdp1_draw)(0xc, *(int *)(sprite_table + DAT_0601bb46), (int)DAT_0601bb4a,
                    *(int *)((int)(sprite_table + DAT_0601bb46) + 4) + (int)DAT_0601bb48);
  /* Draw record time initials */
  record_ptr = *(char **)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*game_mode) << 2);
  (*(int(*)())vdp1_draw_offset)(8, (int)DAT_0601bbc0, 0x60, auStack_1c);
  if (*record_ptr != '\0') {
    (*(int(*)())vdp1_draw_offset)(8, (int)DAT_0601bbc0, 0x60, record_ptr);
  }
  /* Format and draw record time */
  time_display = (*(int(*)())0x06005DD4)(*(int *)
                      (*(int *)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*game_mode) << 2) + 4));
  (*(int(*)())vdp1_draw_offset)(8, 0xcb2, 0x78, time_display);
  return;
}

/* leaderboard_table_render -- Render 5-entry leaderboard table.
 * Each 12-byte entry: name(bytes 0-?), time(+4), hour(+8), star(+9), flag(+10).
 * Displays position number, name, formatted time, AM/PM clock indicator,
 * speed unit flag (mph/kmh), and star marker for special entries. */
int FUN_0601bbcc(param_1, param_2, param_3)
    int param_1;
    char param_2;
    unsigned int param_3;
{
  char star_flag;
  int is_pm;
  char *vdp_render_num;
  char *vdp_render_sprite;
  char *mph_data;
  char *kmh_data;
  char *star_sprite;
  int temp;
  int time_display;
  int *unit_ptr;
  int y_offset;
  char *entry_ptr;
  unsigned char hour;
  unsigned int row_idx;
  unsigned int row_offset;
  char temp_buf [8];
  vdp_render_sprite = (char *)0x060284AE;
  vdp_render_num = (char *)0x06028400;
  y_offset = (int)DAT_0601bcba;
  temp = (*(int(*)())0x06035228)();
  star_sprite = (char *)0x06063920;
  kmh_data = (char *)0x06063D08;
  mph_data = (int *)0x06063918;
  for (row_idx = (unsigned int)param_2; (int)(row_idx & 0xffff) < param_2 + 5; row_idx = row_idx + 1) {
    row_offset = (param_3 & 0xffff) << 6;
    /* Position number */
    (*(int(*)())vdp_render_sprite)(8,(row_offset + 2) << 1,0x60,
                      *(int *)(0x0605DE64 + (row_idx & 0xffff) << 2));
    entry_ptr = (char *)((row_idx & 0xffff) * 0xc + param_1);
    /* Name string (clear then draw) */
    (*(int(*)())vdp_render_sprite)(8,(row_offset + 9) << 1,0x60,temp_buf);
    if (*entry_ptr != '\0') {
      (*(int(*)())vdp_render_sprite)(8,((param_3 & 0xffff) << 6 + 9) << 1,0x60,entry_ptr);
    }
    /* Race time */
    temp = (row_idx & 0xffff) * 0xc + param_1;
    time_display = (*(int(*)())0x06005DD4)(*(int *)(temp + 4));
    (*(int(*)())vdp_render_sprite)(8,((param_3 & 0xffff) << 6 + 0x10) << 1,0x78,time_display);
    /* AM/PM clock indicator */
    hour = *(unsigned char *)(temp + 8);
    is_pm = 0xb < hour;
    if (is_pm) {
      hour = hour - 0xc;              /* convert to 12-hour */
    }
    if (9 < hour) {
      row_offset = 0x2000000;         /* two-digit hour flag */
    }
    temp = (param_3 & 0xffff) << 6;
    (*(int(*)())vdp_render_num)(8,*(int *)
                         (0x06063750 + ((row_offset >> 0x18) + (unsigned int)is_pm + 0x3c) << 3),
                      (temp + 0x21) << 1,
                      (unsigned int)(hour << 12) +
                      *(int *)((int)(0x06063750 +
                                    ((row_offset >> 0x18) + (unsigned int)is_pm + 0x3c) << 3) + 4));
    /* Decorative separator */
    (*(int(*)())vdp_render_sprite)(0xc,(temp + 0x25) << 1,0x60,0x0604A4B8);
    /* Speed unit flag (mph/kmh) */
    if (*(char *)((row_idx & 0xffff) * 0xc + param_1 + 10) != '\0') {
      if (*(int *)0x06078644 == 1) {
        temp = *(int *)(mph_data + 4);
        unit_ptr = (int *)mph_data;
      }
      else {
        temp = *(int *)(kmh_data + 4);
        unit_ptr = (int *)kmh_data;
      }
      (*(int(*)())vdp_render_num)(0xc,*unit_ptr,((param_3 & 0xffff) << 6 + 0x25) << 1,temp + y_offset);
    }
    /* Star marker for special entries */
    star_flag = *(char *)((row_idx & 0xffff) * 0xc + param_1 + 9);
    temp = (int)star_flag;
    if (star_flag != '\0') {
      temp = (*(int(*)())vdp_render_num)(0xc,*(int *)star_sprite,((param_3 & 0xffff) << 6 + 0x28) << 1,
                                0x00008000 + *(int *)(star_sprite + 4));
    }
    param_3 = param_3 + 3;
  }
  return temp;
}

/* car_heading_track_update -- Update heading tracking counters for target car.
 * Increments frame counter (0x06059F3C) by CD time delta + 1 (wraps at 0x50).
 * Compares previous heading (0x06086018) with current car heading (car+0x20):
 * if turning right, increments direction accumulator (0x06059F38) by 2;
 * if turning left, decrements by 2 (wraps to 0 above 0xA0).
 * Saves current heading for next frame. */
void FUN_0601bdec(void)
{
    register int base asm("r2") = CAR_PTR_TARGET;
    unsigned int *dir_accum   = (unsigned int *)0x06059F38;  /* direction accumulator */
    unsigned int *frame_count = (unsigned int *)0x06059F3C;  /* frame counter */
    int *prev_heading = (int *)0x06086018;                   /* previous heading */
    int cd_delta, heading_diff;

    cd_delta = (*(int(*)())0x06034FE0)();  /* cd_time_delta */
    *frame_count = *frame_count + cd_delta + 1;

    heading_diff = *prev_heading - *(int *)(base + 0x20);
    if (heading_diff >= 1) {
        *dir_accum = *dir_accum + 2;       /* turning right */
    } else if (heading_diff < 0) {
        *dir_accum = *dir_accum - 2;       /* turning left */
    }

    if (*frame_count > 0x50) {
        *frame_count = *frame_count - 0x50; /* wrap frame counter */
    }

    if (*dir_accum > 0xa0) {
        *dir_accum = 0;                    /* wrap direction */
    }

    *prev_heading = *(int *)(base + 0x20); /* save current heading */
}

/* --- FUN_0601A80C (L1 import from src/FUN_0601A80C.c) --- */

void FUN_0601a80c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int in_r7;

  puVar3 = (char *)0x0605D243;

  puVar2 = (char *)0x0605D248;

  puVar1 = (char *)0x06063D98;

  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a872) == 0) {

      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {

        if (((*(unsigned short *)0x06063D98 & DAT_0601a872) != 0) && (*(int *)0x0605D243 == '\x14')) {

          *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

          *puVar3 = 0;

        }

      }

      else if (*(int *)0x0605D243 == '\x14') {

        *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

        *puVar3 = 0;

      }

    }

    else {

      *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

      *puVar3 = 0;

    }

  }

  else {

    *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

    *puVar3 = 0;

  }

  if ((*(unsigned short *)(puVar1 + 2) & 0xf8) != 0) {

    *(int *)puVar2 = 0;

  }

  if (0x14 < *(int *)puVar2) {

    *(int *)puVar2 = 0;

  }

  if (*(int *)puVar2 < 0) {

    *(int *)puVar2 = (char *)0x14;

  }

  if ((*(unsigned short *)(puVar1 + 2) & DAT_0601a926) != 0) {

    iVar4 = *(int *)puVar2 + 2;

    (*(int(*)())0x06018DDC)(iVar4,iVar4,0,in_r7,iVar4);

  }

  puVar1 = (char *)0x060283E0;

  (*(int(*)())0x060283E0)(0xc,(int)DAT_0601a928,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a928,0x0000E000,

                    *(int *)(0x0605D2B4 + *(int *)((int)(int)puVar2 << 3)));

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0x0000E000,

                    *(int *)(0x0605D2B4 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2));

  return;

}

/* --- FUN_0601B6DC (L1 import from src/FUN_0601B6DC.c) --- */

#if 0 /* FUN_0601B6DC -- replaced by ASM import of original bytes */
void FUN_0601b6dc()
{

  char cVar1;

  char *puVar2;

  int iVar3;

  unsigned char bVar4;

  unsigned char local_28 [4];

  unsigned char local_24 [8];

  puVar2 = (char *)0x0608600E;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035228)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76c) == 0) {

    if (((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76e) != 0) &&

       (cVar1 = *puVar2, *puVar2 = cVar1 + '\x01', '\x02' < (char)(cVar1 + '\x01'))) {

      *puVar2 = 0;

    }

  }

  else {

    cVar1 = *puVar2;

    *puVar2 = cVar1 + -1;

    if ((char)(cVar1 + -1) < '\0') {

      *puVar2 = 2;

    }

  }

  bVar4 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar4) {

      if ((*(unsigned short *)0x0605D4F8 & 4) == 0) {

        iVar3 = 2;

      }

      else {

        iVar3 = 1;

      }

    }

    else {

      iVar3 = 2;

    }

    (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (bVar4 + 0x36) << 3),

               ((unsigned int)local_28[bVar4] * 0x40 + (unsigned int)local_24[bVar4]) << 1,

               (iVar3 << 12) + *(int *)((int)(0x06063750 + (bVar4 + 0x36) << 3) + 4));

    bVar4 = bVar4 + 1;

  } while (bVar4 < 3);

  return;

}
#endif

/* --- FUN_0601B7F4 (L1 import from src/FUN_0601B7F4.c) --- */

#if 0 /* FUN_0601B7F4 -- replaced by ASM import of original bytes */
void FUN_0601b7f4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char cVar4;

  int *puVar5;

  char *puVar6;

  int iVar7;

  unsigned char bVar8;

  char auStack_38 [4];

  unsigned char local_34 [4];

  int local_30 [3];

  unsigned char local_24;

  unsigned char local_23;

  puVar1 = (char *)0x06063750;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035228)();

  puVar6 = auStack_38;

  (*(int(*)())0x06035228)();

  puVar2 = (char *)0x0608600E;

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b87e) == 0) {

    if ((((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) != 0) &&

       (cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + '\x01',

       ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4, (char)puVar6[(char)*puVar2] <= cVar4)) {

      ((int *)0x0605D4F4)[(char)*puVar2] = 0;

    }

  }

  else {

    cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + -1;

    ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4;

    if (cVar4 < '\0') {

      ((int *)0x0605D4F4)[(char)*puVar2] = puVar6[(char)*puVar2] + -1;

    }

  }

  puVar2 = (char *)0x0605D4F4;

  bVar8 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      iVar7 = 1;

    }

    else {

      iVar7 = 4;

    }

    (*(int(*)())0x06011AF4)(local_30[bVar8],0xFFD40000,0x002F0000,0x001C0000,0x00008000,

               0x00010000,(unsigned int)bVar8 + iVar7 + 0x100);

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\0')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + ((bVar8 + 0x30) << 3));

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_24 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    puVar3 = (char *)0x0605D4F5;

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  bVar8 = 0;

  do {

    if ((int)(char)*puVar3 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\x01')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + ((bVar8 + 0x33) << 3));

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_23 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  return;

}
#endif

/* --- FUN_0601BA50 (L1 import from src/FUN_0601BA50.c) --- */

void FUN_0601ba50(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  char *pcVar6;

  char auStack_1c [8];

  puVar2 = (char *)0x0605D4F7;

  puVar1 = (char *)0x060284AE;

  (*(int(*)())0x06035228)();

  puVar4 = (char *)0x06063750;

  puVar3 = (char *)0x06028400;

  (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601bb3a),0x290,

             0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601bb3a) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb3e),(int)DAT_0601bb40,

                    0x0000A000 + *(int *)((int)(puVar4 + DAT_0601bb3e) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + ((param_1 + 0x30) << 3)),0x390,

                    0x00009000 + *(int *)((int)(puVar4 + ((param_1 + 0x30) << 3)) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + ((param_2 + 0x33) << 3)),(int)DAT_0601bb44,

                    0x00009000 + *(int *)((int)(puVar4 + ((param_2 + 0x33) << 3)) + 4));

  FUN_0601bbcc(*(int *)

                (0x0605DD6C + (param_1 * 6 + (param_2 << 1) + (unsigned int)(unsigned char)*puVar2) << 2),

               (int)param_3,10);

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb46),(int)DAT_0601bb4a,

                    *(int *)((int)(puVar4 + DAT_0601bb46) + 4) + (int)DAT_0601bb48);

  pcVar6 = *(char **)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*puVar2) << 2);

  (*(int(*)())puVar1)(8,(int)DAT_0601bbc0,0x60,auStack_1c);

  if (*pcVar6 != '\0') {

    (*(int(*)())puVar1)(8,(int)DAT_0601bbc0,0x60,pcVar6);

  }

  uVar5 = (*(int(*)())0x06005DD4)(*(int *)

                      (*(int *)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*puVar2) << 2) + 4));

  (*(int(*)())puVar1)(8,0xcb2,0x78,uVar5);

  return;

}

/* FUN_0601B7F4 -- original binary (604 bytes) */
__asm__(
    ".section .text.FUN_0601B7F4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601B7F4\n"
    ".type _FUN_0601B7F4, @function\n"
    "_FUN_0601B7F4:\n"
    ".byte 0x2F, 0xE6, 0xEE, 0x04, 0x2F, 0xD6, 0xED, 0x03, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0xEB, 0x08\n"  /* 0x0601B7F4 */
    ".byte 0x2F, 0x96, 0x2F, 0x86, 0x4F, 0x22, 0x7F, 0xDC, 0xD8, 0x1C, 0x6A, 0xF3, 0x61, 0xF3, 0xD2, 0x1C\n"  /* 0x0601B804 */
    ".byte 0xD3, 0x1C, 0x7A, 0x10, 0x71, 0x20, 0x43, 0x0B, 0xE0, 0x02, 0x61, 0xF3, 0xD2, 0x1A, 0xD3, 0x1B\n"  /* 0x0601B814 */
    ".byte 0x71, 0x14, 0x43, 0x0B, 0xE0, 0x0C, 0x61, 0xF3, 0xD2, 0x19, 0xD3, 0x16, 0x71, 0x10, 0x43, 0x0B\n"  /* 0x0601B824 */
    ".byte 0x60, 0xD3, 0x65, 0xF3, 0x61, 0xF3, 0xD2, 0x17, 0xD3, 0x12, 0x75, 0x0C, 0x71, 0x0C, 0x43, 0x0B\n"  /* 0x0601B834 */
    ".byte 0x60, 0xD3, 0xD6, 0x15, 0xD4, 0x15, 0x93, 0x18, 0x85, 0x61, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39\n"  /* 0x0601B844 */
    ".byte 0x22, 0x28, 0x89, 0x27, 0x63, 0x40, 0xD2, 0x12, 0x33, 0x2C, 0x61, 0x30, 0x71, 0xFF, 0x23, 0x10\n"  /* 0x0601B854 */
    ".byte 0x61, 0x1E, 0x41, 0x11, 0x89, 0x35, 0x66, 0x40, 0xD2, 0x0D, 0x32, 0x6C, 0x35, 0x6C, 0x63, 0x50\n"  /* 0x0601B864 */
    ".byte 0x73, 0xFF, 0x63, 0x3E, 0x22, 0x30, 0xA0, 0x2C, 0x00, 0x09, 0x40, 0x00, 0x06, 0x06, 0x37, 0x50\n"  /* 0x0601B874 */
    ".byte 0x06, 0x05, 0xDF, 0x26, 0x06, 0x03, 0x52, 0x28, 0x06, 0x05, 0xDF, 0x28, 0x06, 0x03, 0x51, 0x68\n"  /* 0x0601B884 */
    ".byte 0x06, 0x05, 0xDF, 0x34, 0x06, 0x05, 0xDF, 0x37, 0x06, 0x06, 0x3D, 0x98, 0x06, 0x08, 0x60, 0x0E\n"  /* 0x0601B894 */
    ".byte 0x06, 0x05, 0xD4, 0xF4, 0x85, 0x61, 0xD3, 0x27, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x22, 0x28\n"  /* 0x0601B8A4 */
    ".byte 0x89, 0x0F, 0x63, 0x40, 0xD2, 0x24, 0x33, 0x2C, 0x61, 0x30, 0x71, 0x01, 0x23, 0x10, 0x61, 0x1E\n"  /* 0x0601B8B4 */
    ".byte 0x60, 0x40, 0x03, 0x5C, 0x31, 0x33, 0x8B, 0x04, 0x63, 0x40, 0xD2, 0x1F, 0x33, 0x2C, 0xE1, 0x00\n"  /* 0x0601B8C4 */
    ".byte 0x23, 0x10, 0xEC, 0x00, 0xD3, 0x1C, 0x2F, 0x32, 0x63, 0xF3, 0x73, 0x20, 0x1F, 0x32, 0x62, 0xCC\n"  /* 0x0601B8D4 */
    ".byte 0x63, 0xF2, 0x63, 0x30, 0x33, 0x20, 0x8B, 0x01, 0xA0, 0x01, 0xE9, 0x01, 0x69, 0xEC, 0x62, 0xCC\n"  /* 0x0601B8E4 */
    ".byte 0x69, 0x9C, 0x64, 0xCC, 0x1F, 0x21, 0x44, 0x08, 0x32, 0x9C, 0x93, 0x22, 0x32, 0x3C, 0x2F, 0x26\n"  /* 0x0601B8F4 */
    ".byte 0xD2, 0x12, 0x2F, 0x26, 0xD3, 0x0F, 0x2F, 0x36, 0xD7, 0x11, 0x63, 0xF3, 0xD2, 0x13, 0xD6, 0x11\n"  /* 0x0601B904 */
    ".byte 0xD5, 0x11, 0x73, 0x20, 0x34, 0x3C, 0x42, 0x0B, 0x64, 0x42, 0x7F, 0x0C, 0x63, 0xF2, 0x52, 0xF1\n"  /* 0x0601B914 */
    ".byte 0x63, 0x30, 0x33, 0x20, 0x8B, 0x20, 0xD2, 0x0E, 0x62, 0x21, 0x62, 0x2D, 0x22, 0xB9, 0x22, 0x28\n"  /* 0x0601B924 */
    ".byte 0x8B, 0x03, 0xD3, 0x0C, 0x63, 0x30, 0x23, 0x38, 0x89, 0x01, 0xA0, 0x16, 0x69, 0xDC, 0xA0, 0x14\n"  /* 0x0601B934 */
    ".byte 0x69, 0xEC, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x06, 0x05, 0xD4, 0xF4, 0x00, 0x01, 0x00, 0x00\n"  /* 0x0601B944 */
    ".byte 0x00, 0x1C, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0xFF, 0xD4, 0x00, 0x00, 0x06, 0x01, 0x1A, 0xF4\n"  /* 0x0601B954 */
    ".byte 0x06, 0x05, 0xD4, 0xF8, 0x06, 0x08, 0x60, 0x0E, 0x69, 0xEC, 0x67, 0x9C, 0x62, 0xCC, 0x60, 0xCC\n"  /* 0x0601B964 */
    ".byte 0x47, 0x18, 0x72, 0x30, 0x47, 0x08, 0x63, 0x23, 0x47, 0x08, 0x43, 0x08, 0x43, 0x00, 0x62, 0x33\n"  /* 0x0601B974 */
    ".byte 0x32, 0x8C, 0x1F, 0x21, 0x53, 0x21, 0x06, 0xAC, 0x55, 0xF1, 0x37, 0x3C, 0x66, 0x6C, 0x65, 0x52\n"  /* 0x0601B984 */
    ".byte 0x53, 0xF2, 0x63, 0x30, 0x62, 0x3C, 0x42, 0x08, 0xD3, 0x28, 0x42, 0x08, 0x42, 0x08, 0x36, 0x2C\n"  /* 0x0601B994 */
    ".byte 0x46, 0x00, 0x43, 0x0B, 0xE4, 0x08, 0x7C, 0x01, 0x62, 0xCC, 0x32, 0xD3, 0x8B, 0x97, 0xEC, 0x00\n"  /* 0x0601B9A4 */
    ".byte 0xD2, 0x23, 0x1F, 0x22, 0x63, 0xF3, 0x73, 0x21, 0x2F, 0x32, 0x62, 0xCC, 0x53, 0xF2, 0x63, 0x30\n"  /* 0x0601B9B4 */
    ".byte 0x33, 0x20, 0x8B, 0x0D, 0xD2, 0x1F, 0x62, 0x21, 0x62, 0x2D, 0x22, 0xB9, 0x22, 0x28, 0x8B, 0x03\n"  /* 0x0601B9C4 */
    ".byte 0xD0, 0x1D, 0x60, 0x00, 0x88, 0x01, 0x89, 0x01, 0xA0, 0x03, 0x69, 0xDC, 0xA0, 0x01, 0x69, 0xEC\n"  /* 0x0601B9D4 */
    ".byte 0x69, 0xEC, 0x67, 0x9C, 0x62, 0xCC, 0x60, 0xCC, 0x47, 0x18, 0x72, 0x33, 0x47, 0x08, 0x63, 0x23\n"  /* 0x0601B9E4 */
    ".byte 0x47, 0x08, 0x43, 0x08, 0x43, 0x00, 0x62, 0x33, 0x32, 0x8C, 0x1F, 0x21, 0x53, 0x21, 0x06, 0xAC\n"  /* 0x0601B9F4 */
    ".byte 0x55, 0xF1, 0x37, 0x3C, 0x66, 0x6C, 0x65, 0x52, 0x63, 0xF2, 0x63, 0x30, 0x62, 0x3C, 0x42, 0x08\n"  /* 0x0601BA04 */
    ".byte 0xD3, 0x0A, 0x42, 0x08, 0x42, 0x08, 0x36, 0x2C, 0x46, 0x00, 0x43, 0x0B, 0xE4, 0x08, 0x7C, 0x01\n"  /* 0x0601BA14 */
    ".byte 0x62, 0xCC, 0x32, 0xD3, 0x8B, 0xC9, 0x7F, 0x24, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6\n"  /* 0x0601BA24 */
    ".byte 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0xFF, 0xFF, 0x06, 0x02, 0x84, 0x00\n"  /* 0x0601BA34 */
    ".byte 0x06, 0x05, 0xD4, 0xF5, 0x06, 0x05, 0xD4, 0xF8, 0x06, 0x08, 0x60, 0x0E\n"  /* 0x0601BA44 */
);

/* FUN_0601B6DC -- original binary (20 bytes) */
__asm__(
    ".section .text.FUN_0601B6DC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601B6DC\n"
    ".type _FUN_0601B6DC, @function\n"
    "_FUN_0601B6DC:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0xED, 0x02, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0xEA, 0x03\n"  /* 0x0601B6DC */
    ".byte 0x2F, 0x86, 0xE8, 0x01\n"  /* 0x0601B6EC */
);
