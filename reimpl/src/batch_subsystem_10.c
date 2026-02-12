#include "game.h"

extern int DAT_060100f6;
extern int DAT_060100f8;
extern int DAT_060101b2;
extern int DAT_0601038c;
extern int DAT_0601038e;
extern int DAT_0601043e;
extern int DAT_0601064a;
extern int DAT_06010736;
extern int DAT_0601096e;
extern int DAT_06010a2a;
extern int DAT_06010c4c;
extern int DAT_06010c4e;
extern int DAT_0601112c;
extern int DAT_0601112e;
extern int DAT_06011206;
extern int DAT_06011208;
extern int DAT_0601120a;
extern int DAT_060112e2;
extern int DAT_060112e4;
extern int DAT_060112e6;
extern int DAT_060113b2;
extern int DAT_060113b4;
extern int DAT_060113b6;
extern int DAT_06011462;
extern int DAT_06011464;
extern int DAT_06011466;
extern int DAT_060115c6;
extern int DAT_06011fd4;
extern int DAT_06011fd6;
extern int DAT_06011fd8;
extern int DAT_06011fda;
extern void FUN_06010d94();
extern void FUN_060111e2();
extern void FUN_06011310();
extern void FUN_060116a8(int,int,short,int,short);
extern int FUN_06011978();
extern void FUN_06011e7c();
extern int PTR_DAT_06010274;
extern int PTR_DAT_06010278;
extern int PTR_DAT_0601030c;
extern int PTR_DAT_06010440;
extern int PTR_DAT_06010508;
extern int PTR_DAT_06010870;
extern int PTR_DAT_06010970;
extern int PTR_DAT_06010ac8;
extern int PTR_DAT_06010c50;
extern int PTR_DAT_06011130;
extern int PTR_DAT_0601120c;
extern int PTR_DAT_06011f04;
extern short DAT_06011efe;
extern short DAT_06011f00;
extern short DAT_06011f02;

/* player_sprite_render -- Render player car sprite with animation/scaling.
 * Loads sprite data from table at 0x060447C8 indexed by player slot.
 * DMA-copies palette (0x20 bytes) to VRAM. If game mode > 4, advances
 * animation frame counter at 0x06078870 (max 0x1E for active, 0x1D for
 * inactive players). Active player uses stride from DAT_060101b2,
 * others use 0x72B. Calls 3D sprite renderer (FUN_06011AF4) with
 * computed position, scale, and texture from course lookup table. */
int FUN_060100a4(param_1)
    unsigned char param_1;
{
  short y_offset;
  unsigned short anim_frame;
  char *palette_src;
  int tex_x;
  char *tex_y;
  int scale_y;
  char *scale_x;
  int anim_stride;

  scale_x = (char *)0x00010000;
  y_offset = (unsigned short)param_1 + DAT_060100f6;
  scale_y = (int)DAT_060100f8;
  tex_x = *(int *)(0x060447C8 + (unsigned int)(param_1 << 4));         /* sprite table X */
  tex_y = *(char **)((int)(0x060447C8 + (unsigned int)(param_1 << 4)) + 4); /* sprite table Y */
  if ((unsigned int)param_1 == CAR_COUNT) {
    palette_src = 0x0605D0BC + (unsigned int)(param_1 << 5);            /* active player palette */
  } else {
    palette_src = 0x0605D0BC + (param_1 + 3) << 5;                     /* inactive player palette */
  }
  (*(int(*)())0x0602766C)(*(int *)(0x06078888 + (unsigned int)(param_1 << 2)), palette_src, 0x20);
  if (4 < (unsigned char)*(int *)0x0607887F) {          /* game mode > 4: animate */
    if ((unsigned int)param_1 == CAR_COUNT) {            /* active player */
      if (*(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) < 0x1e) {
        anim_frame = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;
        *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = anim_frame;
      } else {
        *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) = 0x20;
        anim_frame = 0x20;
      }
      tex_x = tex_x + *(int *)(0x060447F8 + (char)(param_1 * '\f')) * (unsigned int)anim_frame;
      tex_y = tex_y + *(int *)((int)(0x060447F8 + (char)(param_1 * '\f')) + 4) * (unsigned int)anim_frame;
      anim_stride = (unsigned int)anim_frame * (int)DAT_060101b2;
    } else {                                             /* inactive player */
      if (0x1d < *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1))) {
        return (unsigned int)(param_1 << 1);             /* animation complete */
      }
      anim_frame = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;
      *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = anim_frame;
      anim_stride = (unsigned int)anim_frame * 0x72b;
    }
    scale_y = scale_y + (unsigned int)anim_frame * -0x800;
    scale_x = scale_x + -anim_stride;
  }
  if (0xb < (unsigned char)*(int *)0x0607887F) {        /* mode > 11: override Y */
    tex_y = (short *)0x00960000;
  }
  tex_x = (*(int(*)())0x06011AF4)(tex_x, tex_y,        /* 3D sprite render */
                     (*(unsigned int *)(0x06044844 + *(int *)(0x0605AA98 << 2)) >> 1) << 0x10,
                     0x00200000, scale_y, scale_x, (int)y_offset);
  return tex_x;
}

/* player_count_detect -- Detect player count from cabinet analog input.
 * Reads inverted analog input, checks two thresholds:
 *   >0x72B = one additional player, >0xC0 = one additional player
 * Result: 0=single, 1=2P, 2=4P. Mirrors to CAR_COUNT and game state. */
void player_count_detect(void)
{
    unsigned short raw = *(unsigned short *)0x06063D9C;
    int *player_count = (int *)0x0607EADC;
    unsigned int input_val = ((unsigned int)raw ^ 0xFFFF) & 0xFF;

    *player_count = 0;
    if ((int)input_val > 0x72B)
        *player_count += 1;
    if ((int)input_val > 0xC0)
        *player_count += 1;

    *(int *)0x0607887E = (char)*player_count;
    CAR_COUNT = *player_count;
}
void FUN_06010238(void) __attribute__((alias("player_count_detect")));

/* coin_start_handler -- Handle coin insert / start button during attract.
 * Decrements start timer at 0x0607EBCC. If start bits (PTR_DAT_0601030c)
 * are set in param_1: transitions to GAME_STATE=6 (service mode).
 * Otherwise: if timer expired or confirm button pressed, loads sound bank
 * for current player count, sets game mode to 2, mirrors CAR_COUNT.
 * On course 0 with START pressed, enables route select (0x0605AB18). */
void FUN_060102ea(unsigned short param_1)
{
  int *start_timer = (int *)0x0607EBCC;
  *start_timer = *start_timer - 1;

  if ((param_1 & PTR_DAT_0601030c) == 0) {
    if ((*start_timer < 1) || ((param_1 & DAT_0601038c) != 0)) {
      (*(int(*)())0x0601D5F4)(0, *(int *)(0x0604481C + *(int *)(0x0607EADC << 2)));
      *start_timer = 0;
      *(int *)0x0607887F = 2;              /* set game mode */
      *(int *)0x06078648 = (char)CAR_COUNT;
      *(int *)0x0605AB18 = 0;
      if ((*(int *)0x06085FF4 == '\0') &&
          (COURSE_SELECT == 0 && ((*(unsigned short *)0x06063D98 & DAT_0601038e) != 0))) {
        *(char *)0x0605AB18 = 1;           /* enable route select */
      }
    }
  } else {
    GAME_STATE = 6;                         /* service mode transition */
  }
}

/* player_select_dpad -- Handle D-pad input for player/character selection.
 * Up (bit 0x8000): increment selection (max 1).
 * Down (DAT_0601043e): decrement selection (min 0).
 * Mirrors selection to 0x0607EAB8 and 0x06078868, then DMA-copies
 * the appropriate character sprite data (0xC0 bytes) for both slots. */
void FUN_060103b8(unsigned int param_1)
{
  int *select_idx = (int *)0x0607EADC;  /* player selection index */

  if (((param_1 & 0xffff & 0x00008000) != 0) && (*select_idx < 1)) {
    *select_idx = *select_idx + 1;
  }
  if (((param_1 & 0xffff & (int)DAT_0601043e) != 0) && (0 < *select_idx)) {
    *select_idx = *select_idx + -1;
  }

  *(int *)0x0607EAB8 = *select_idx;     /* mirror to character select */
  *(int *)0x06078868 = *select_idx;      /* mirror to car select */

  if (*(int *)0x0607EAB8 == 0) {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D05C, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D088, 0xc0);
  } else {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D084, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D060, 0xc0);
  }
}

/* player_select_analog -- Analog input version of player/character selection.
 * Reads raw analog value from 0x06063D9C, inverts (XOR 0xFFFF), masks to low byte.
 * Resets selection to 0, then if analog value > 0xC0 increments to 1.
 * Mirrors to 0x0607EAB8 and 0x06078868, DMA-copies sprite data (0xC0 bytes). */
void FUN_06010470(void)
{
  int *select_idx = (int *)0x0607EADC;
  unsigned int analog_val = (unsigned int)*(unsigned short *)0x06063D9C ^ 0x0000FFFF;

  *select_idx = 0;
  if (0xc0 < (int)(analog_val & 0xff)) {
    *select_idx = *select_idx + 1;
  }

  *(int *)0x0607EAB8 = *select_idx;     /* mirror to character select */
  *(int *)0x06078868 = *select_idx;      /* mirror to car select */

  if (*(int *)0x0607EAB8 == 0) {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D05C, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D088, 0xc0);
  } else {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D084, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D060, 0xc0);
  }
}

/* track_select_button_input -- handle digital button input for track/music selection */
unsigned int FUN_060104e0(param_1)
    unsigned int param_1;
{
  char game_mode;
  char *double_buf_toggle;
  char *current_index;
  char *odd_even_flag;
  char *selection_counter;
  unsigned int result;
  int prev_index;
  unsigned int new_index;
  int max_entries;
  int *dma_target;
  int scroll_offset;

  double_buf_toggle = (short *)0x060788A8; /* double-buffer page toggle */
  current_index = (char *)0x06078868;      /* displayed track index */
  odd_even_flag = (int *)0x0607EAB8;       /* odd/even page flag */
  selection_counter = (char *)0x0607EADC;  /* selection index counter */

  /* Determine max selection entries based on game mode */
  game_mode = *(int *)0x0605AB16;
  if ((game_mode == '\x01') || (game_mode == '\x02')) {
LAB_06010504:
    max_entries = 5;
  }
  else {
    if (game_mode != '\x03') {
      if (game_mode == '\x04') goto LAB_06010504;
      if ((game_mode != '\x05') && (game_mode != '\x06')) {
        if (game_mode == '\a') {
          max_entries = 9;
        }
        else {
          max_entries = 3;
        }
        goto LAB_06010570;
      }
    }
    max_entries = 7;
  }

LAB_06010570:
  if (*(int *)0x0605AB17 == '\a') {
    max_entries = 0xb;
  }
  result = (unsigned int)(char)*(int *)0x0605AB17;
  if (result == 0xf) {
    max_entries = 0xd;
  }

  /* Check button input: bit 0x8000 = scroll up, DAT_0601064a = scroll down */
  if ((param_1 & 0xffff & (unsigned int)0x00008000) == 0) {
    /* No up button — check down button */
    if ((param_1 & 0xffff & (int)DAT_0601064a) != 0) {
      /* Scroll down: decrement selection */
      *(char **)0x0607889C = 0x00010000; /* scroll_direction = positive */
      prev_index = *(int *)selection_counter;
      *(int *)selection_counter = prev_index + -1;
      if (prev_index + -1 < 0) {
        *(int *)selection_counter = max_entries; /* wrap to end */
      }
      scroll_offset = 0xFFF40000;
      result = (unsigned int)(unsigned char)*double_buf_toggle;
      if (result == 0) {
        *double_buf_toggle = 1;
        *(int *)0x06078898 = scroll_offset;
        *(int *)0x060788A4 = *(int *)selection_counter;
      }
      else {
        *double_buf_toggle = 0;
        *(int *)0x06078894 = scroll_offset;
        *(int *)0x060788A0 = *(int *)selection_counter;
      }
    }
  }
  else {
    /* Scroll up: increment selection with CD preview load */
    *(int *)0x0607889C = 0xFFFF0000; /* scroll_direction = negative */
    prev_index = *(int *)selection_counter;
    *(int *)selection_counter = prev_index + 1;
    if (max_entries < prev_index + 1) {
      *(int *)selection_counter = 0; /* wrap around */
    }
    if (*double_buf_toggle == '\0') {
      *double_buf_toggle = 1;
      (*(int(*)())0x060359E4)();     /* cd_seek_preview */
      result = (*(int(*)())0x060357B8)(); /* cd_read_preview */
      *(unsigned int *)0x06078898 = result; /* page_a_offset = cd data */
      *(int *)0x060788A4 = *(int *)selection_counter;
    }
    else {
      *double_buf_toggle = 0;
      (*(int(*)())0x060359E4)();
      result = (*(int(*)())0x060357B8)();
      *(unsigned int *)0x06078894 = result;
      *(int *)0x060788A0 = *(int *)selection_counter;
    }
  }

  /* Update current display index */
  new_index = *(unsigned int *)selection_counter;
  *(unsigned int *)current_index = new_index;
  *(unsigned int *)odd_even_flag = new_index & 1;

  /* DMA transfer track preview sprite if index < 10 */
  if (*(unsigned int *)current_index < 10) {
    if (*double_buf_toggle == '\0') {
      scroll_offset = *(int *)(0x0605D05C + *(int *)((int)(int)current_index << 2));
      dma_target = (int *)0x06078884; /* vdp1_target_a */
    }
    else {
      scroll_offset = *(int *)(0x0605D05C + *(int *)((int)(int)current_index << 2));
      dma_target = (int *)0x06078880; /* vdp1_target_b */
    }
    result = (*(int(*)())0x0602766C)(*dma_target,scroll_offset,0xc0); /* dma_copy_vdp1_alt */
  }

  /* DMA transfer selection highlight when button was pressed */
  if ((param_1 & 0xffff & (unsigned int)0x0000C000) != 0) {
    if (*(unsigned int *)current_index < 0xc) {
      max_entries = *(int *)current_index;
    }
    else {
      max_entries = *(int *)current_index + -2;
    }
    result = (*(int(*)())0x0602761E)(0x25F00000 + (*(int *)((int)(int)odd_even_flag << 1) + 0x23) << 5,
                       0x0605CA9C + (max_entries << 6),0x40);
    return result;
  }

  return result;
}

/* track_select_analog_scroll -- handle analog stick input for track/music selection menu */
unsigned int FUN_06010760()
{
  char game_mode;
  char *dma_copy_fn;
  char *double_buf_toggle;
  char *current_index;
  char *selection_counter;
  char *scroll_target;
  unsigned int stick_pos;
  unsigned int result;
  unsigned int new_index;
  int prev_index;
  int max_entries;
  int scroll_offset;

  selection_counter = (short *)0x0607EADC; /* selection index counter */
  current_index = (char *)0x06078868;      /* displayed track index */
  double_buf_toggle = (int *)0x060788A8;   /* double-buffer page toggle */
  dma_copy_fn = (char *)0x0602761E;        /* dma_copy_vdp1 function */

  /* Determine max selection entries based on game mode */
  game_mode = *(int *)0x0605AB16;
  if ((game_mode == '\x01') || (game_mode == '\x02')) {
LAB_06010782:
    max_entries = 5;
  }
  else {
    if (game_mode != '\x03') {
      if (game_mode == '\x04') goto LAB_06010782;
      if ((game_mode != '\x05') && (game_mode != '\x06')) {
        if (game_mode == '\a') {
          max_entries = 9;
        }
        else {
          max_entries = 3; /* default: 4 entries (0-3) */
        }
        goto LAB_060107c8;
      }
    }
    max_entries = 7;
  }

LAB_060107c8:
  /* Special mode overrides */
  if (*(int *)0x0605AB17 == '\a') {
    max_entries = 0xb;
  }
  if (*(int *)0x0605AB17 == '\x0f') {
    max_entries = 0xd;
  }

  /* Read analog stick X position (inverted, 8-bit) */
  stick_pos = ((unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF) & 0xff;
  result = stick_pos;

  /* Stick right (> 0x90): scroll forward */
  if (0x90 < (int)stick_pos) {
    *(int *)0x0607889C = 0xFFFF0000; /* scroll_direction = negative */
    *(int *)0x0605AA9C = 0x1e;       /* scroll_repeat_delay = 30 frames */
    prev_index = *(int *)selection_counter;
    *(int *)selection_counter = prev_index + 1;
    if (max_entries < prev_index + 1) {
      *(int *)selection_counter = 0; /* wrap around */
    }
    scroll_target = (char *)0x000C0000;
    result = (unsigned int)(unsigned char)*double_buf_toggle;
    if (result == 0) {
      *double_buf_toggle = 1;
      *(char **)0x06078898 = scroll_target; /* page_a_offset */
      *(int *)0x060788A4 = *(int *)selection_counter; /* page_a_index */
    }
    else {
      *double_buf_toggle = 0;
      *(char **)0x06078894 = scroll_target; /* page_b_offset */
      *(int *)0x060788A0 = *(int *)selection_counter; /* page_b_index */
    }
  }

  /* Stick left (< 0x70): scroll backward */
  if (stick_pos < 0x70) {
    *(char **)0x0607889C = 0x00010000; /* scroll_direction = positive */
    *(int *)0x0605AA9C = 0x1e;         /* scroll_repeat_delay */
    prev_index = *(int *)selection_counter;
    *(int *)selection_counter = prev_index + -1;
    if (prev_index + -1 < 0) {
      *(int *)selection_counter = max_entries; /* wrap to end */
    }
    scroll_offset = 0xFFF40000;
    result = (unsigned int)(unsigned char)*double_buf_toggle;
    if (result == 0) {
      *double_buf_toggle = 1;
      *(int *)0x06078898 = scroll_offset;
      *(int *)0x060788A4 = *(int *)selection_counter;
    }
    else {
      *double_buf_toggle = 0;
      *(int *)0x06078894 = scroll_offset;
      *(int *)0x060788A0 = *(int *)selection_counter;
    }
  }

  /* Update current display index */
  new_index = *(unsigned int *)selection_counter;
  *(unsigned int *)current_index = new_index;
  *(unsigned int *)0x0607EAB8 = new_index & 1; /* odd/even page flag */

  /* DMA transfer track preview sprite if index < 10 */
  if (*(unsigned int *)current_index < 10) {
    if (*double_buf_toggle == '\0') {
      scroll_offset = *(int *)(0x0605D05C + *(int *)((int)(int)current_index << 2));
      max_entries = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x40;
    }
    else {
      scroll_offset = *(int *)(0x0605D05C + *(int *)((int)(int)current_index << 2));
      max_entries = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + DAT_0601096e + 0x40;
    }
    result = (*(int(*)())dma_copy_fn)(max_entries,scroll_offset,0xc0);
  }

  /* DMA transfer selection highlight arrow when stick moved */
  if ((stick_pos < 0x70) || (0x90 < (int)stick_pos)) {
    if (*(unsigned int *)current_index < 0xc) {
      max_entries = *(int *)current_index;
    }
    else {
      max_entries = *(int *)current_index + -2;
    }
    result = (*(int(*)())dma_copy_fn)(0x25F00000 + (*(int *)(0x0607EAB8 << 1) + 0x23) << 5,
                              0x0605CA9C + (max_entries << 6),0x40);
  }

  return result;
}

/* character_sprite_dma -- DMA-copy character sprite data for current selection.
 * Normal mode (0x06083255 == 0): copies 0xC0 bytes from sprite table indexed
 *   by car selection (0x06078868), dest from scroll offset + VDP base + 0x40.
 * Demo mode: copies 0x20 bytes from demo sprite table indexed by 0x0607EAB8,
 *   dest includes player count offset and additional scroll offset.
 * Always copies a second sprite block for the overlay at 0x0607ED91. */
void FUN_06010994(void)
{
  int scroll_base = *(int *)0x06063F5C;   /* VDP scroll base address */
  int scroll_page = *(int *)0x06059FFC;   /* current scroll page index */
  int dest, src, size;

  if (*(int *)0x06083255 == '\0') {
    size = 0xc0;
    src = *(int *)(0x0605D05C + *(int *)(0x06078868 << 2));
    dest = *(int *)(scroll_page << 3) + scroll_base + 0x40;
  } else {
    size = 0x20;
    src = *(int *)(0x0605D0AC + *(int *)(0x0607EAB8 << 2));
    dest = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +
            (unsigned int)*(unsigned short *)0x0607886C) << 5 +
            *(int *)(scroll_page << 3) + scroll_base;
  }

  (*(int(*)())0x0602761E)(dest, src, size);
  (*(int(*)())0x0602761E)(*(int *)(scroll_page << 3) + scroll_base + DAT_06010a2a + 0x40,
                    *(int *)(0x0605D05C + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2)));
}

/* subsystem_slot_dma -- DMA a sprite data block for subsystem HUD slot.
 * Destination: scroll page base + HUD offset + 0x40.
 * Source: character sprite table indexed by slot_idx. */
void subsystem_slot_dma(int slot_idx)
{
    int dest = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + PTR_DAT_06010ac8 + 0x40;
    int src = *(int *)(0x0605D05C + (slot_idx << 2));
    (*(int(*)())0x0602761E)(dest, src);
}
void FUN_06010a5c(int slot_idx) __attribute__((alias("subsystem_slot_dma")));

/* sound_bank_load -- Load the sound bank for the current course/mode.
 * Normal mode: look up bank ID from course sound table, indexed by course.
 * Demo mode: use fixed SCSP bank IDs (different bank for player 2).
 * The SCSP command function at 0x0601D5F4 sends the bank load command. */
int sound_bank_load(void)
{
    int scsp_cmd = 0x0601D5F4;
    int result;

    if (DEMO_MODE_FLAG == 0) {
        int course = CHAR_SELECT_IDX;
        int bank_id = *(int *)(0x0604483C + (course << 2));
        result = (*(int(*)())scsp_cmd)(0, bank_id);
    } else {
        int bank = 0xAB110BFF;
        if (*(int *)0x06078644 == 1)
            bank = 0xAB110AFF;
        result = (*(int(*)())scsp_cmd)(0, bank);
    }
    return result;
}
int FUN_06010b54(void) __attribute__((alias("sound_bank_load")));

/* character_select_anim_update -- Character selection 3D model animation.
 * First-run path: set initial position, trigger DMA, poll for completion.
 * Ongoing path: apply velocity/damping, clamp at zero, trigger DMA.
 * DMA status register at 0xFFFFFE11 (SH-2 DMAC), object render at 0x0603C000. */
int FUN_06010bc4()
{
  unsigned short dma_complete_mask;
  short angle_step;
  char *pos_y;          /* 0x06078894 */
  char *pos_z;          /* 0x06078898 */
  char *anim_counter;   /* 0x0608A52C */
  char *rotation;       /* 0x06078878 */
  int result;
  unsigned char *dma_status;  /* 0xFFFFFE11 — SH-2 DMA operation register */
  rotation = (char *)0x06078878;
  anim_counter = (short *)0x0608A52C;
  pos_z = (char *)0x06078898;
  pos_y = (int *)0x06078894;
  angle_step = PTR_DAT_06010c50;
  dma_complete_mask = DAT_06010c4e;
  dma_status = (unsigned char *)-495;          /* 0xFFFFFE11 */
  if (*(int *)0x06085FF4 == '\0') {
    /* First-run: initial position setup */
    *(int *)0x060788A0 = 1;                    /* model slot active */
    *(short *)rotation = *(short *)rotation + angle_step;
    FUN_06011310();
    pos_y = (int *)0x060270D0;                 /* matrix push function */
    *(int *)anim_counter = *(int *)anim_counter + 0x30;
    (*(int(*)())pos_y)();
    /* Set initial 3D position (fixed-point) */
    *(int *)0x0607884C = 1;                    /* model visible */
    *(char **)0x06078850 = 0x00038000;         /* initial X */
    *(int *)0x06078854 = 0xFFFF0000;           /* initial Y (-1.0) */
    *(char **)0x06078858 = 0x0006B333;         /* initial Z (+6.7) */
    *(char **)0x06063574 = 0x06010F04;         /* render callback */
    *(short *)0x21000000 = (short)0x0000FFFF;  /* VDP1 system clip */
    FUN_06010d94(0,0xFFFC8000,0xFFFF0000,0x0006B333);
    pos_y = (int *)0x0603C000;                 /* object render */
    /* Poll DMA completion */
    do {
    } while ((*dma_status & dma_complete_mask) != dma_complete_mask);
    *dma_status = *dma_status & 0xf;           /* clear DMA status */
    result = (*(int(*)())pos_y)();
  }
  else {
    /* Ongoing: apply velocity with clamping */
    *(short *)0x06078878 = *(short *)0x06078878 + PTR_DAT_06010c50;
    rotation = (char *)0x0607889C;             /* velocity */
    *(int *)pos_y = *(int *)pos_y + *(int *)0x0607889C;
    *(int *)pos_z = *(int *)pos_z + *(int *)rotation;
    /* Clamp position at zero based on velocity direction and axis */
    if (*(int *)rotation < 0) {
      if (*(int *)0x060788A8 == '\0') {
        if (*(int *)pos_y < 1) {
          *(int *)pos_y = 0;
          *(int *)rotation = 0;
        }
      }
      else if ((*(int *)0x060788A8 == '\x01') && (*(int *)pos_z < 1)) {
        *(int *)pos_z = 0;
        *(int *)rotation = 0;
      }
    }
    else if (*(int *)0x060788A8 == '\0') {
      if (-1 < *(int *)pos_y) {
        *(int *)pos_y = 0;
        *(int *)rotation = 0;
      }
    }
    else if ((*(int *)0x060788A8 == '\x01') && (-1 < *(int *)pos_z)) {
      *(int *)pos_z = 0;
      *(int *)rotation = 0;
    }
    FUN_060111e2();
    rotation = (char *)0x060270D0;             /* matrix push */
    *(int *)anim_counter = *(int *)anim_counter + 0x30;
    (*(int(*)())rotation)();
    /* Set current position for rendering */
    *(int *)0x0607884C = 1;
    *(int *)0x06078850 = *(int *)pos_z;
    *(int *)0x06078854 = 0xFFFF3334;           /* Y offset (-0.8) */
    *(char **)0x06078858 = 0x00063333;         /* Z offset (+6.2) */
    *(char **)0x06063574 = 0x06010F04;         /* render callback */
    *(short *)0x21000000 = (short)0x0000FFFF;  /* VDP1 system clip */
    FUN_06010d94(0,*(int *)pos_y,0xFFFF3334,0x00063333);
    pos_y = (int *)0x0603C000;                 /* object render */
    /* Poll DMA completion */
    do {
    } while ((*dma_status & dma_complete_mask) != dma_complete_mask);
    *dma_status = *dma_status & 0xf;
    result = (*(int(*)())pos_y)();
  }
  *(int *)anim_counter = *(int *)anim_counter + -0x30;
  return result;
}

/* character_model_3d_render -- Render 3D character model with matrix pipeline.
 * Only renders if slot index at 0x060788A0 < 10 (max visible models).
 * Pushes matrix stack (0x06026E0C), translates by param position,
 * rotates by heading angle from 0x06078878. Then renders 3 body
 * segments (torso/arms/legs) each with: multiply (0x06031D8C),
 * scale (0x06031A28), matrix pop (0x06026DBC), translate, repeat.
 * Transform data at 0x06044640-0x06044678, rotation index from
 * table at 0x06089E44. State pointer at 0x06089EDC tracks stack. */
void FUN_06010d94(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{
  short *rot_entry;

  if (*(unsigned int *)0x060788A0 < 10) {               /* max visible models */
    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + 0x30;        /* advance state */
    (*(int(*)())0x06026E0C)();                           /* matrix_push */
    (*(int(*)())0x06026E2E)(param_2, param_3, param_4);  /* matrix_translate */
    (*(int(*)())0x06026EDE)((int)*(short *)0x06078878);  /* matrix_rotate_y (heading) */
    rot_entry = (short *)(0x06089E44 + (param_1 << 1));  /* rotation index table */
    /* --- segment 0: torso --- */
    (*(int(*)())0x06031D8C)(*(int *)0x0606212C, *(int *)0x060621D8);  /* matrix_multiply */
    (*(int(*)())0x06031A28)(*(int *)0x060620D8, (int)*rot_entry, *(int *)0x06062180); /* matrix_scale */
    (*(int(*)())0x06026DBC)();                           /* matrix_pop */
    (*(int(*)())0x06026E2E)(*(int *)0x06044640, *(int *)0x06044644,   /* translate seg 1 */
                      -*(int *)0x06044648);
    /* --- segment 1: arms --- */
    (*(int(*)())0x06031D8C)(*(int *)(0x0606212C + 4), *(int *)0x060621DC);
    (*(int(*)())0x06031A28)(*(int *)(0x060620D8 + 4), (int)*rot_entry, *(int *)(0x06062180 + 4));
    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;     /* stack adjust */
    (*(int(*)())0x06026DBC)();                           /* matrix_pop */
    (*(int(*)())0x06026E2E)(*(int *)0x0604464C, *(int *)0x06044650,   /* translate seg 2 */
                      -*(int *)0x06044654);
    /* --- segment 2: legs --- */
    (*(int(*)())0x06031D8C)(*(int *)(0x0606212C + 8), *(int *)0x060621E0);
    (*(int(*)())0x06031A28)(*(int *)(0x060620D8 + 8), (int)*rot_entry, *(int *)(0x06062180 + 8));
    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;     /* stack adjust */
    (*(int(*)())0x06026DBC)();                           /* matrix_pop */
    (*(int(*)())0x06026E2E)(*(int *)0x06044670, *(int *)0x06044674,   /* translate seg 3 */
                      -*(int *)0x06044678);
    /* --- segment 3: extra --- */
    (*(int(*)())0x06031D8C)(*(int *)(0x0606212C + 0xc), *(int *)0x060621E4);
    (*(int(*)())0x06031A28)(*(int *)(0x060620D8 + 0xc), (int)*rot_entry, *(int *)(0x06062180 + 0xc));
    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x60;     /* stack adjust (2 levels) */
  }
}

/* course_banner_render -- Render 3-layer course selection banner sprites.
 * Draws course name/icon in 3 priority layers via VDP1 (0x06028400).
 * Layer priority flickers based on FRAME_COUNTER (mode 3: every frame,
 * otherwise every 2 frames) for the active player's selection.
 * Non-selected players forced to priority 3.
 * Sprite data from 0x0605AC70 (car table) and 0x0605AB98 (course table).
 * Banner position from 0x06063750 + DAT_0601112c. */
void FUN_06011094()
{
  int priority_base;
  int pos_x, pos_y;

  /* flicker priority based on game mode and frame counter */
  if (*(int *)0x0607887F == '\x03') {
    priority_base = ((FRAME_COUNTER & 1) == 0) ? 4 : 3;
  } else if ((FRAME_COUNTER & 3) < 2) {
    priority_base = 3;
  } else {
    priority_base = 4;
  }
  pos_x = *(int *)(0x06063750 + DAT_0601112c);          /* banner X position */
  pos_y = *(int *)(0x06063750 + DAT_0601112c + 0x10);   /* banner Y position */
  /* --- layer 0: player 0 selection --- */
  {
    int pri_0 = priority_base;
    if (*(int *)0x0607EADC != 0) pri_0 = 3;             /* non-active: force priority 3 */
    (*(int(*)())0x06028400)(4, *(int *)(0x0605AC70 + *(int *)(0x06078644 << 2)),
               0x282, (pri_0 << 12) + pos_x);           /* car banner */
    (*(int(*)())0x06028400)(8, *(int *)(0x0605AB98 + *(int *)(0x0605AD00 << 2)),
               (int)PTR_DAT_06011130, (pri_0 << 12) + pos_y); /* course banner */
  }
  /* --- layer 1: player 1 selection --- */
  {
    int pri_1 = priority_base;
    if (*(int *)0x0607EADC != 1) pri_1 = 3;
    int offset_1 = (pri_1 + 2) << 12;
    (*(int(*)())0x06028400)(4, *(int *)(0x0605AC70 + *(int *)(0x06078644 << 2) + 0xc),
               (int)DAT_06011206, offset_1 + pos_x);
    (*(int(*)())0x06028400)(8, *(int *)(0x0605AB98 + *(int *)(0x0605AD00 << 2) + 0xc),
               0x4a8, offset_1 + pos_y);
  }
  /* --- layer 2: player 2 selection --- */
  {
    int pri_2 = priority_base;
    if (*(int *)0x0607EADC != 2) pri_2 = 3;
    int offset_2 = (pri_2 + 4) << 12;
    (*(int(*)())0x06028400)(4, *(int *)(0x0605AC70 + *(int *)(0x06078644 << 2) + 0x18),
               0x2ba, offset_2 + pos_x);
    (*(int(*)())0x06028400)(8, *(int *)(0x0605AB98 + *(int *)(0x0605AD00 << 2) + 0x18),
               (int)PTR_DAT_0601120c, offset_2 + pos_y);
  }
}

/* char_select_sprite -- Render character selection sprite overlay.
 * Draws 3 VDP1 sprites for character select: background banner,
 * character icon (from 0x0605ABBC indexed by car selection), and
 * transmission indicator (manual=0x0605A9B0, auto=0x0605A9B8).
 * Player A (0x0607EAB8==0): base priority, player B: priority+2.
 * Mode 0xB: flicker priority 3↔4 on alternating frames.
 * Position from scroll offset table at 0x06063828+4. */
void FUN_060111e2()
{
  int priority;
  int *sprite_pos = (int *)0x06063828;
  int vdp1_draw = 0x06028400;
  int *trans_sprite;
  int cmd_offset;
  int pos;

  priority = 3;
  if ((*(int *)0x0607887F == '\v') && ((FRAME_COUNTER & 1) == 0)) {
    priority = 4;                                        /* flicker on mode 0xB */
  }
  if (*(int *)0x0607EAB8 == 0) {                         /* player A selected */
    pos = *(int *)(sprite_pos + 4) + (priority << 12);
    (*(int(*)())vdp1_draw)(4, 0x0605A7FC, 0x2a0, pos);  /* background banner A */
    (*(int(*)())vdp1_draw)(4, *(int *)
                         (0x0605ABBC +
                         (unsigned int)(*(int *)0x06078644 != 0) << 2 + *(int *)(0x06078868 << 3)),
                      0x530, pos);                       /* character icon */
    cmd_offset = (int)DAT_060112e6;
    trans_sprite = (int *)0x0605A9B8;                    /* auto transmission sprite */
    if (*(int *)0x06078644 != 0) {
      trans_sprite = (int *)0x0605A9B0;                  /* manual transmission sprite */
    }
  } else {                                               /* player B selected */
    pos = *(int *)(sprite_pos + 4) + ((priority + 2) << 12);
    (*(int(*)())vdp1_draw)(4, 0x0605A8B6, 0x2a0, pos);  /* background banner B */
    (*(int(*)())vdp1_draw)(4, *(int *)
                         (0x0605ABBC +
                         (unsigned int)(*(int *)0x06078644 != 0) << 2 + *(int *)(0x06078868 << 3)),
                      0x530, pos);                       /* character icon */
    cmd_offset = (int)DAT_060112e6;
    trans_sprite = (int *)0x0605A9B8;
    if (*(int *)0x06078644 != 0) {
      trans_sprite = (int *)0x0605A9B0;
    }
  }
  (*(int(*)())vdp1_draw)(4, trans_sprite, cmd_offset, pos); /* transmission indicator */
}

/* dual_char_select_sprite -- Render character selection for 2-player mode.
 * Draws 2 sets of 3 sprites each (banner, transmission, car variant)
 * via VDP1 (0x06028400). Player 0: uses priority flicker, forced to
 * priority 3 if not selected (0x0607EADC != 0). Player 1: priority+2.
 * Transmission sprites: auto=0x0605A9B8/0x0605A978, manual=0x0605A9B0/0x0605A998.
 * Position from scroll offset 0x06063828+4. */
void FUN_06011310()
{
  int priority_base;
  int pos;

  /* determine flicker priority */
  if (*(int *)0x0607887F == '\v') {
    priority_base = ((FRAME_COUNTER & 1) == 0) ? 4 : 3;
  } else if ((FRAME_COUNTER & 3) < 2) {
    priority_base = 3;
  } else {
    priority_base = 4;
  }
  /* --- player 0 sprites --- */
  {
    int pri_0 = priority_base;
    if (*(int *)0x0607EADC != 0) pri_0 = 3;             /* non-active: force 3 */
    pos = *(int *)(0x06063828 + 4) + (pri_0 << 12);
    (*(int(*)())0x06028400)(4, 0x0605A7FC, 0x288, pos); /* banner A */
    char *trans_0 = (char *)0x0605A9B8;                  /* auto transmission */
    if (*(int *)0x06078644 != 0) trans_0 = (char *)0x0605A9B0; /* manual */
    (*(int(*)())0x06028400)(4, trans_0, (int)DAT_060113b4, pos);
    char *car_0 = (char *)0x0605A978;                    /* auto car variant */
    if (*(int *)0x06078644 != 0) car_0 = (char *)0x0605A998; /* manual */
    (*(int(*)())0x06028400)(4, car_0, 0x518, pos);
  }
  /* --- player 1 sprites --- */
  {
    int pri_1 = priority_base;
    if (*(int *)0x0607EADC != 1) pri_1 = 3;
    int offset_1 = (pri_1 + 2) << 12;
    pos = *(int *)(0x06063828 + 4) + offset_1;
    (*(int(*)())0x06028400)(4, 0x0605A8B6, (int)DAT_06011462, pos); /* banner B */
    char *trans_1 = (char *)0x0605A9B8;
    if (*(int *)0x06078644 != 0) trans_1 = (char *)0x0605A9B0;
    (*(int(*)())0x06028400)(4, trans_1, 0x54a, pos);
    char *car_1 = (char *)0x0605A980;
    if (*(int *)0x06078644 != 0) car_1 = (char *)0x0605A9A0;
    (*(int(*)())0x06028400)(4, car_1, (int)DAT_06011466, pos);
  }
}

/* gauge_needle_update -- Interpolate gauge needle position toward target.
 * Reads target position from lookup table at 0x060447A8, indexed by
 * player selection and param_1. Smooths toward target by halving the
 * difference each frame (exponential approach).
 * In game modes 3/0xB, skips rendering on odd frames.
 * Calls FUN_060116a8 (needle sprite render) and FUN_06011978 (gauge marks). */
unsigned int FUN_060114ac(unsigned int param_1)
{
  int *needle_pos = (int *)0x06078860;  /* current needle position */
  int target = *(int *)(0x060447A8 + *(int *)(0x0607EADC << 2) + (param_1 & 0xffff) << 4);
  int delta = target - *needle_pos;

  *needle_pos = *needle_pos + ((int)(delta + (unsigned int)(delta < 0)) >> 1);

  if (((*(int *)0x0607887F == '\x03') || (*(int *)0x0607887F == '\v')) &&
     ((FRAME_COUNTER & 1) != 0)) {
    return FRAME_COUNTER;
  }

  {
    short *sprite_idx = (short *)(0x060447A4 + (param_1 & 0xffff) << 1);
    int *needle_data = (int *)(0x060447A8 + (param_1 & 0xffff) << 4 + 0xc);
    unsigned int uVar2;

    FUN_060116a8(*needle_pos, *needle_data, (int)DAT_060115c6, 0x00010000, (int)*sprite_idx);
    FUN_06011978(0x06044764, *needle_pos, *needle_data, (int)*sprite_idx);
    uVar2 = FUN_06011978(0x06044784, *needle_pos, *needle_data, (int)*sprite_idx);
    return uVar2;
  }
}

/* sprite_row_data_load -- Load 0x1C sprite row entries from course data table.
 * Iterates 0x1C entries at stride 0x58 in the course data block (0x06063788),
 * copying 2-word pairs into the sprite buffer at 0x0605AAA6.
 * Then triggers DMA via 0x06028400 with the row offset into VRAM. */
void FUN_0601155e(unsigned short param_1)
{
  char *sprite_buf = (char *)0x0605AAA6;
  int course_data = *(int *)0x06063788;
  unsigned short i = 0;

  do {
    unsigned int idx = (unsigned int)i;
    short *src = (short *)(idx * 0x58 + (unsigned int)(param_1 << 1) + course_data + 4);
    *(short *)(sprite_buf + (idx << 2)) = *src;
    *(short *)((int)(sprite_buf + (idx << 2)) + 2) = src[1];
    i = i + 1;
  } while (i < 0x1c);

  (*(int(*)())0x06028400)(8, 0x0605AAA2, (param_1 & 0x3f) << 1,
             0x0000F000 + *(int *)(0x06063788 + 4));
}

/* rotated_quad_vertex_compute -- Compute 4 rotated vertices for VDP1 polygon.
 * Takes center position (x,y), rotation angle, scale, and color.
 * Writes 8 vertex coordinates (4 corners x X,Y) to polygon command table
 * at 0x060786CC with 0x18-byte stride. Uses sin/cos decomposition
 * with asymmetric offsets to form a trapezoidal gauge shape. */
void FUN_060116a8(int center_x,int center_y,short angle,int scale,short color)
{
  char *poly_table;
  char *poly_count_ptr;
  char *fixed_to_short;  /* 0x0602754C */
  char *fixed_mul;       /* 0x06027552 */
  int sin_val;
  int cos_val;
  int rotated;
  short screen_coord;
  short center_screen;
  short slot_idx;
  short *vertex_ptr;
  int sin_component;
  int cos_component;
  short angle_copy;
  angle_copy = angle;

  /* Decompose angle into sin/cos */
  (*(int(*)())0x06027358)((int)angle,&sin_component,&cos_component);
  fixed_mul = (char *)0x06027552;
  fixed_to_short = (char *)0x0602754C;
  poly_count_ptr = (char *)0x0605AAA0;
  poly_table = (char *)0x060786CC;
  vertex_ptr = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);
  /* Vertex 0 X (top-left): offset (-56, +30) rotated */
  sin_val = (*(int(*)())0x06027552)(0xFFC80000,cos_component);
  cos_val = (*(int(*)())fixed_mul)(0x001E0000,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_x);
  *vertex_ptr = center_screen + screen_coord;
  /* Vertex 0 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0xFFC80000,sin_component);
  cos_val = (*(int(*)())fixed_mul)(0x001E0000,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 10) = center_screen + screen_coord;
  /* Vertex 1 X (top-right): offset (+56, +30) rotated */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0x00380000,cos_component);
  cos_val = (*(int(*)())fixed_mul)(0x001E0000,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0xc) = center_screen + screen_coord;
  /* Vertex 1 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0x00380000,sin_component);
  cos_val = (*(int(*)())fixed_mul)(0x001E0000,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0xe) = center_screen + screen_coord;
  /* Vertex 2 X (bottom-right): offset (+56, -30) rotated */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0x00380000,cos_component);
  cos_val = (*(int(*)())fixed_mul)(0xFFE20000,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x10) = center_screen + screen_coord;
  /* Vertex 2 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0x00380000,sin_component);
  cos_val = (*(int(*)())fixed_mul)(0xFFE20000,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x12) = center_screen + screen_coord;
  /* Vertex 3 X (bottom-left): offset (-56, -30) rotated */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0xFFC80000,cos_component);
  cos_val = (*(int(*)())fixed_mul)(0xFFE20000,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x14) = center_screen + screen_coord;
  /* Vertex 3 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(0xFFC80000,sin_component);
  cos_val = (*(int(*)())fixed_mul)(0xFFE20000,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(center_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x16) = center_screen + screen_coord;
  /* Set polygon color and flags, advance polygon count */
  *(short *)(poly_table + (short)(*(short *)poly_count_ptr * 0x18) + 6) = color;
  poly_table[(short)(*(short *)poly_count_ptr * 0x18) + 4] = 0;    /* draw mode */
  poly_table[(short)(*(short *)poly_count_ptr * 0x18) + 5] = 1;    /* visible */
  *(short *)poly_count_ptr = *(short *)poly_count_ptr + 1;
  return;
}

/* gauge_mark_render -- Render gauge tick mark as VDP1 polygon.
 * Writes 4-vertex polygon (8 coords) to VDP1 command table at
 * 0x060786CC, stride 0x18 per entry. Each vertex pair computed
 * as fixed-point truncation (0x0602754C) of template offsets
 * (param_1[0..7]) + needle position (param_2=X, param_3=Y).
 * Sets sprite index (param_4), flags (visible=1), and advances
 * the command table counter at 0x0605AAA0. */
int FUN_06011978(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    short param_4;
{
  short *cmd_counter = (short *)0x0605AAA0;
  char *cmd_table = (int *)0x060786CC;
  int fp_trunc = 0x0602754C;                             /* fixed-point truncate */
  short idx;
  short *vertex_base;

  idx = *cmd_counter;
  vertex_base = (short *)(0x060786CC + (short)(idx * 0x18) + 8);
  /* vertex 0: X */
  *vertex_base = (*(int(*)())fp_trunc)(*param_1 + param_2);
  /* vertex 0: Y */
  *(short *)(cmd_table + (short)(idx * 0x18) + 10) = (*(int(*)())fp_trunc)(param_1[1] + param_3);
  /* vertex 1: X */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0xc) = (*(int(*)())fp_trunc)(param_1[2] + param_2);
  /* vertex 1: Y */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0xe) = (*(int(*)())fp_trunc)(param_1[3] + param_3);
  /* vertex 2: X */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0x10) = (*(int(*)())fp_trunc)(param_1[4] + param_2);
  /* vertex 2: Y */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0x12) = (*(int(*)())fp_trunc)(param_1[5] + param_3);
  /* vertex 3: X */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0x14) = (*(int(*)())fp_trunc)(param_1[6] + param_2);
  /* vertex 3: Y */
  *(short *)(cmd_table + (short)(idx * 0x18) + 0x16) = (*(int(*)())fp_trunc)(param_1[7] + param_3);
  /* command metadata */
  *(short *)(cmd_table + (short)(idx * 0x18) + 6) = param_4;  /* sprite index */
  cmd_table[(short)(idx * 0x18) + 4] = 0;               /* flags low */
  cmd_table[(short)(idx * 0x18) + 5] = 1;               /* visible flag */
  *cmd_counter = *cmd_counter + 1;                       /* advance counter */
  return 0;
}

/* rotated_rect_vertex_compute -- Compute 4 rotated vertices for VDP1 polygon.
 * Like rotated_quad_vertex_compute but with explicit width/height parameters
 * instead of fixed offsets. Takes center (x,y), half-width, half-height,
 * rotation angle, scale, and color. Writes 8 coords to polygon table
 * at 0x060786CC (0x18-byte stride). */
void FUN_06011af4(int center_x,int center_y,int half_width,int half_height,short angle,short scale,short color)
{
  char *poly_table;
  char *poly_count_ptr;
  char *fixed_to_short;  /* 0x0602754C */
  char *fixed_mul;       /* 0x06027552 */
  int sin_val;
  int cos_val;
  int rotated;
  short screen_coord;
  short center_screen;
  short slot_idx;
  short *vertex_ptr;
  int sin_component;
  int cos_component;
  int saved_y;
  int saved_x;
  int neg_width;
  int neg_height;
  saved_y = center_y;
  saved_x = center_x;
  /* Decompose angle into sin/cos */
  (*(int(*)())0x06027358)((int)angle,&sin_component,&cos_component);
  fixed_mul = (char *)0x06027552;
  fixed_to_short = (int *)0x0602754C;
  poly_count_ptr = (char *)0x0605AAA0;
  poly_table = (char *)0x060786CC;
  neg_width = -half_width;
  vertex_ptr = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);
  /* Vertex 0 X (top-left): (-width * cos - height * sin) * scale */
  sin_val = (*(int(*)())0x06027552)(neg_width,cos_component);
  cos_val = (*(int(*)())fixed_mul)(half_height,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_x);
  *vertex_ptr = center_screen - screen_coord;
  /* Vertex 0 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(neg_width,sin_component);
  cos_val = (*(int(*)())fixed_mul)(half_height,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 10) = center_screen + screen_coord;
  /* Vertex 1 X (top-right): (width * cos - height * sin) * scale */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(half_width,cos_component);
  cos_val = (*(int(*)())fixed_mul)(half_height,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0xc) = center_screen - screen_coord;
  /* Vertex 1 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(half_width,sin_component);
  cos_val = (*(int(*)())fixed_mul)(half_height,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0xe) = center_screen + screen_coord;
  /* Vertex 2 X (bottom-right): (width * cos + height * sin) * scale */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(half_width,cos_component);
  neg_height = -half_height;
  cos_val = (*(int(*)())fixed_mul)(neg_height,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x10) = center_screen - screen_coord;
  /* Vertex 2 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(half_width,sin_component);
  cos_val = (*(int(*)())fixed_mul)(neg_height,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x12) = center_screen + screen_coord;
  /* Vertex 3 X (bottom-left): (-width * cos + height * sin) * scale */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(neg_width,cos_component);
  cos_val = (*(int(*)())fixed_mul)(neg_height,sin_component);
  rotated = (*(int(*)())fixed_mul)(sin_val - cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_x);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x14) = center_screen - screen_coord;
  /* Vertex 3 Y */
  slot_idx = *(short *)poly_count_ptr;
  sin_val = (*(int(*)())fixed_mul)(neg_width,sin_component);
  cos_val = (*(int(*)())fixed_mul)(neg_height,cos_component);
  rotated = (*(int(*)())fixed_mul)(sin_val + cos_val,scale);
  screen_coord = (*(int(*)())fixed_to_short)(rotated);
  center_screen = (*(int(*)())fixed_to_short)(saved_y);
  *(short *)(poly_table + (short)(slot_idx * 0x18) + 0x16) = center_screen + screen_coord;
  /* Set polygon color and flags, advance polygon count */
  *(short *)(poly_table + (short)(*(short *)poly_count_ptr * 0x18) + 6) = color;
  poly_table[(short)(*(short *)poly_count_ptr * 0x18) + 4] = 0;
  poly_table[(short)(*(short *)poly_count_ptr * 0x18) + 5] = 0;
  *(short *)poly_count_ptr = *(short *)poly_count_ptr + 1;
  return;
}

/* vdp1_overlay_dispatch -- Emit VDP1 commands for overlay sprite queue.
 * Iterates overlay entries at 0x060786CC (24 bytes each), count at 0x0605AAA0.
 * Entry byte +5 selects command type: 0=normal sprite (0x060280F8),
 * non-zero=polygon (0x060280C4, clears flag after). Advances VDP1 write
 * pointer by 0x20 per entry, increments frame counter. Resets queue count. */
void FUN_06011dc0(void)
{
  int *vdp1_write = (int *)0x060785FC;     /* VDP1 command write pointer */
  char *overlay_buf = (char *)0x060786CC;  /* overlay command buffer (24B entries) */
  int *frame_cnt = (int *)0x0605A008;      /* frame counter */
  unsigned short *queue_cnt = (unsigned short *)0x0605AAA0;
  unsigned short i;

  for (i = 0; i < *queue_cnt; i++) {
    int off = (short)(i * 0x18);
    if (overlay_buf[off + 5] == '\0') {
      (*(int(*)())0x060280F8)(overlay_buf + off, *vdp1_write);
    } else {
      (*(int(*)())0x060280C4)(overlay_buf + off, *vdp1_write);
      overlay_buf[off + 5] = 0;            /* clear polygon flag */
    }
    *frame_cnt = *frame_cnt + 1;
    *vdp1_write = *vdp1_write + 0x20;
  }
  *queue_cnt = 0;
}

/* subsystem_sprite_pair_update -- Update 2 paired VDP1 sprites.
 * Builds VDP1 commands for two sprite entries at 0x060638B0/A0
 * using shared vertical offset from DAT_06011efe. */
void FUN_06011e7c(void)
{
    register int vdp_cmd_build asm("r3") = 0x06028400;
    register int y_offset asm("r2") = (int)DAT_06011efe;

    (*(int(*)())vdp_cmd_build)(0xC, *(int *)0x060638B0, (int)DAT_06011f00,
        *(int *)0x060638B4 + y_offset);
    (*(int(*)())vdp_cmd_build)(0xC, *(int *)0x060638A0, (int)DAT_06011f02,
        *(int *)0x060638A4 + y_offset);
}

/* sprite_pair_or_single_update -- Update VDP1 sprite(s) for HUD overlay.
 * In alternate mode (0x06085FF4 != 0): updates both sprites via FUN_06011e7c.
 * Otherwise: updates single sprite from buffer 0x060638B0 (if 0x0607EADC set)
 * or 0x060638A0 (default). Uses fixed character ID 0x420 with Y offset. */
void FUN_06011eb4(void)
{
  if (*(int *)0x06085FF4 != '\0') {
    FUN_06011e7c();                         /* update both sprites */
    return;
  }

  if (*(int *)0x0607EADC != 0) {
    (*(int(*)())0x06028400)(0xc, *(int *)0x060638B0, 0x420,
               *(int *)(0x060638B0 + 4) + (int)DAT_06011efe);
  } else {
    (*(int(*)())0x06028400)(0xc, *(int *)0x060638A0, 0x420,
               *(int *)(0x060638A0 + 4) + (int)DAT_06011efe);
  }
}

/* palette_darken -- Attenuate 16 RGB555 palette entries toward black.
 * For each entry: decomposes into R (bits 0-4), G (masked by DAT_06011fd4),
 * B (masked by DAT_06011fd6). Subtracts 2 from R, 0x40 from G, 0x800 from B
 * (clamping each to 0). Recomposes into RGB555 and writes back.
 * Used for fade-to-black transitions. */
void FUN_06011f1c(param_1)
    unsigned short *param_1;
{
  unsigned short rgb;
  unsigned short green_mask, blue_mask;
  short i;
  int red, green, blue;

  blue_mask = DAT_06011fd6;
  green_mask = DAT_06011fd4;
  i = 0;
  do {
    rgb = *param_1;
    *param_1 = 0;
    red = ((int)(short)rgb & 0x1fU) - 2;                /* attenuate R by 2 */
    if (red < 1) red = 0;
    green = (short)(rgb & green_mask) + -0x40;           /* attenuate G by 0x40 */
    *param_1 = *param_1 | (unsigned short)red;
    if (green < 1) green = 0;
    *param_1 = *param_1 | (unsigned short)green;
    blue = (short)(rgb & blue_mask) + -2048;             /* attenuate B by 0x800 */
    if (blue < 1) blue = 0;
    i = i + 1;
    *param_1 = *param_1 | (unsigned short)blue;
    param_1 = param_1 + 1;
  } while (i < 0x10);
}

/* palette_blend_toward -- Blend 16 RGB555 entries toward target palette.
 * For each entry: increments R by 1 (capped at target R), increments
 * G by 0x20 (capped at target G), increments B by 0x400 (capped at
 * target B). param_1 = current palette, param_2 = target palette.
 * Used for fade-in or palette transition effects. */
void FUN_06011f92(param_1, param_2)
    unsigned short *param_1;
    unsigned short *param_2;
{
  unsigned short cur_rgb;
  unsigned short tgt_rgb;
  int channel;
  unsigned short result;
  unsigned short blue_mask;
  unsigned int green_mask;
  short i;

  blue_mask = DAT_06011fd6;
  green_mask = 0x400 - 0x20;                             /* green channel mask (0x3E0) */
  i = 0;
  do {
    cur_rgb = *param_1;
    tgt_rgb = *param_2;
    *param_1 = 0;
    /* red channel: increment by 1, cap at target */
    channel = ((int)(short)cur_rgb & 0x1fU) + 1;
    if (channel < (short)tgt_rgb) {
      result = (unsigned short)channel;
    } else {
      result = tgt_rgb & 0x1f;                           /* cap at target R */
    }
    *param_1 = *param_1 | result;
    /* green channel: increment by 0x20, cap at target */
    channel = ((int)(short)cur_rgb & green_mask) + 0x20;
    if ((((short)tgt_rgb <= channel ^ 1) & green_mask) == 0) {
      result = tgt_rgb & (unsigned short)green_mask;     /* cap at target G */
    } else {
      result = (unsigned short)channel;
    }
    channel = (short)(cur_rgb & blue_mask) + 0x400;
    *param_1 = *param_1 | result;
    /* blue channel: increment by 0x400, cap at target */
    if ((((short)tgt_rgb <= channel ^ 1) & blue_mask) == 0) {
      tgt_rgb = tgt_rgb & blue_mask;                     /* cap at target B */
    } else {
      tgt_rgb = (unsigned short)channel;
    }
    i = i + 1;
    *param_1 = *param_1 | tgt_rgb;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (i < 0x10);
}
