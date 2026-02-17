#include "game.h"

extern int DAT_06014136;
extern int DAT_06014212;
extern int DAT_06014306;
extern int DAT_0601440e;
extern int DAT_06014410;
extern int DAT_06014594;
extern int DAT_06014682;
extern int DAT_06014818;
extern int DAT_06014a4e;
extern int DAT_06014ae2;
extern int DAT_06014bce;
extern int DAT_06014bd0;
extern int DAT_06014bd2;
extern int DAT_06014bd4;
extern int DAT_06014bd6;
extern int DAT_06014cf2;
extern int DAT_06014de4;
extern int DAT_0601541a;
extern int FUN_06013e12();
extern unsigned int FUN_060146d2();
extern unsigned int FUN_0601476c();
extern int FUN_06014f34();
extern int PTR_DAT_06014308;
extern int PTR_DAT_06014684;
extern int PTR_DAT_06014cf4;

/* hud_position_marker_render -- Render position marker sprite for current car.
 * Guards on car count < 4. Looks up sprite offset from 0x0605AD4C table,
 * pushes matrix, sets position/scale, renders via FUN_06013e12,
 * then draws texture with palette from 0x06062338/0x060622C0 tables. */
void FUN_060140c4()
{
  int sprite_offset;

  if (*(unsigned int *)0x06084B18 < 4) {
    sprite_offset = *(int *)(0x0605AD4C + *(int *)(0x06084B18 << 2));
    (*(int(*)())0x06026DBC)(); /* matrix_push */
    (*(int(*)())0x06026E2E)(sprite_offset, -13107, 0x00010000); /* set position */
    (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* set scale 1.0 */
    FUN_06013e12(); /* render digit/marker */
    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + *(int *)(0x06084B08 << 2)), 4); /* texture select */
    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + *(int *)(0x06084B08 << 2)),
               (int)*(short *)0x06089E4A, 1); /* palette draw */
    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30; /* advance VDP1 cmd slot */
  }
}

/* hud_position_digits_render -- Render up to 3 position digit sprites.
 * Resets matrix, then for each digit slot (up to car count):
 * looks up position from 0x0605AD4C, maps character to sprite index
 * ('.' → 0x1A, else char + 0xBF), renders texture from lookup tables. */
void FUN_0601416c()
{
  unsigned char sprite_idx;
  unsigned int i;

  (*(int(*)())0x06026E0C)(); /* matrix_reset */

  i = 0;
  do {
    if (i < *(unsigned int *)0x06084B18) {
      (*(int(*)())0x06026DBC)(); /* matrix_push */
      (*(int(*)())0x06026E2E)(*(int *)(0x0605AD4C + (i << 2)), -13107, 0x00010000); /* position */
      (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* scale 1.0 */

      if (((int *)0x06084B14)[i] == '.') {
        sprite_idx = 0x1a; /* period character */
      } else {
        sprite_idx = ((int *)0x06084B14)[i] + 0xbf; /* ASCII to sprite index */
      }

      (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + (unsigned int)(sprite_idx << 2)), 4);
      (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + (unsigned int)(sprite_idx << 2)),
                 (int)*(short *)0x06089E4A, 1);
      *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30; /* advance VDP1 cmd slot */
    }
    i = i + 1;
  } while (i < 3);
}

/* hud_indicator_render -- Render HUD indicator with smoothed rotation.
 * Smooths target angle (exponential half-step toward target from table 0x0605AD5C),
 * applies fixed-point multiply for position offset,
 * rotates by frame counter bits (animation), renders at scale 1.0. */
void FUN_0601424c()
{
  int delta;
  int pos_offset;
  int *anim_table;

  (*(int(*)())0x06026E0C)(); /* matrix_reset */
  (*(int(*)())0x06026DBC)(); /* matrix_push */
  (*(int(*)())0x06026E2E)(0, (int)DAT_06014306, 0x000108F5); /* set base position */

  anim_table = (int *)(0x0605AD5C + *(int *)(0x06084B08 << 5));

  /* smooth angle: move halfway toward target each frame */
  delta = (int)*(short *)(anim_table + 6) - (int)*(short *)0x06084AF8;
  *(short *)0x06084AF8 =
       *(short *)0x06084AF8 + (short)((int)(delta + (unsigned int)(delta < 0)) >> 1);

  (*(int(*)())0x06026F2A)((int)*(short *)0x06084AF8); /* set rotation */

  /* smooth position offset with fixed-point multiply */
  pos_offset = (*(int(*)())0x06027552)((*anim_table - *(int *)0x06084AFC) + (int)PTR_DAT_06014308,
                     0x00008000);
  pos_offset = *(int *)0x06084AFC + pos_offset;
  *(int *)0x06084AFC = pos_offset;

  (*(int(*)())0x06026E2E)(0, pos_offset); /* apply position */
  (*(int(*)())0x06026F2A)(-(int)*(short *)0x06084AF8); /* undo rotation */
  (*(int(*)())0x06026EDE)((FRAME_COUNTER & 0x1f) << 0xb); /* frame-based animation */
  (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* scale 1.0 */

  (*(int(*)())0x06031D8C)(*(int *)0x060623AC, 4); /* texture select */
  (*(int(*)())0x06031A28)(*(int *)0x06062334, (int)*(short *)0x06089E4A, 1); /* draw */
  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30; /* advance VDP1 cmd slot */
}

/* sprite_table_3d_render -- Render 29 course/car selection sprites with 3D transforms.
 * Iterates 0x1D (29) entries from descriptor table at 0x0605AD5C (stride 0x20).
 * For each: pushes matrix, translates Y by DAT_0601440e, rotates by heading,
 * translates by position, un-rotates. Highlights current selection (0x06084B08)
 * via FUN_06013e12. Scales by 0x4CCC, submits mesh + texture.
 * Decrements VDP1 command slot counter at 0x06089EDC by 0x30 per entry. */
void FUN_06014360()
{
  int *desc;
  unsigned int idx = 0;
  int y_offset = (int)DAT_0601440e;
  int scale = 0x4ccc;
  (*(int(*)())0x06026E0C)();               /* matrix_identity */
  do {
    desc = (int *)(0x0605AD5C + (idx << 5));
    (*(int(*)())0x06026DBC)();             /* matrix_push */
    (*(int(*)())0x06026E2E)(0, y_offset, 0x00010000);  /* matrix_translate */
    (*(int(*)())0x06026F2A)((int)*(short *)(desc + 6));  /* matrix_rotate */
    (*(int(*)())0x06026E2E)(0, *desc);     /* matrix_translate(pos) */
    (*(int(*)())0x06026F2A)(-(int)*(short *)(desc + 6));  /* matrix_unrotate */
    if (*(unsigned int *)0x06084B08 == idx) {
      FUN_06013e12();                      /* highlight selection */
    }
    (*(int(*)())0x06026E60)(scale, scale, scale);  /* matrix_scale */
    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + (idx << 2)), 4);  /* mesh_submit */
    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + (idx << 2)),
               (int)*(short *)0x06089E4A, 1);  /* texture_submit */
    idx = idx + 1;
    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;  /* advance VDP1 cmd slot */
  } while (idx < 0x1d);
  return;
}

/* analog_to_view_index -- Map analog steering input to camera view index.
 * Reads analog stick value from controller (+4), inverts and shifts to 0..0x1C range.
 * Saves previous index for change detection. Clamps to 0x1B..0x1C when
 * car count > 2. Plays sound 0xAB111DFF on index change.
 * Writes render flag from lookup table 0x0605AD2C to 0x06084B20. */
unsigned int FUN_06014466()
{
  unsigned int prev_result;
  unsigned int analog_raw = (int)(((unsigned int)*(unsigned short *)(0x06063D98 + 4) ^ (unsigned int)0x0000FFFF) & 0xff) >> 3;
  unsigned int view_idx = analog_raw;
  if (0x1c < analog_raw) {
    view_idx = 0x1c;            /* clamp max */
  }
  *(int *)0x06084B0C = *(int *)0x06084B08;  /* save previous */
  *(unsigned int *)0x06084B08 = view_idx;
  if (2 < *(unsigned int *)0x06084B18) {
    /* restrict range when 3+ cars */
    if (view_idx < 0xf) {
      *(int *)0x06084B08 = 0x1b;
    } else {
      *(int *)0x06084B08 = 0x1c;
    }
  }
  prev_result = analog_raw;
  if (*(int *)0x06084B08 != *(int *)0x06084B0C) {
    prev_result = (*(int(*)())0x0601D5F4)(0, 0xAB111DFF);  /* view change sound */
  }
  *(unsigned int *)0x06084B20 =
       (unsigned int)(unsigned char)((int *)0x0605AD2C)[*(int *)0x06084B08];
  return prev_result;
}

/* hud_camera_angle_update -- Update HUD camera view angle index.
 * Reads controller input every 4th frame: D-pad up (DAT_06014594)
 * decrements, bit 15 (analog up) increments (range 0..0x1C).
 * Clamps to 0x1B..0x1C when car count > 2.
 * Looks up render flag from table 0x0605AD2C, plays sound on change. */
void FUN_0601450c()
{
  int prev_angle = *(int *)0x06084B08;

  if ((FRAME_COUNTER & 3) == 0) {
    if ((*(unsigned short *)0x06063D98 & DAT_06014594) == 0) {
      if ((((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) != 0) &&
         (*(unsigned int *)0x06084B08 < 0x1c)) {
        *(int *)0x06084B08 = *(int *)0x06084B08 + 1; /* increment angle */
      }
    } else if (*(int *)0x06084B08 != 0) {
      *(int *)0x06084B08 = *(int *)0x06084B08 + -1; /* decrement angle */
    }
  }

  /* clamp range when 3+ cars */
  if (2 < *(unsigned int *)0x06084B18) {
    if (*(unsigned int *)0x06084B08 < 0x1b) {
      *(int *)0x06084B08 = 0x1b;
    } else if (0x1c < *(unsigned int *)0x06084B08) {
      *(int *)0x06084B08 = 0x1c;
    }
  }

  *(unsigned int *)0x06084B20 =
       (unsigned int)(unsigned char)((int *)0x0605AD2C)[*(int *)0x06084B08];

  if (prev_angle != *(int *)0x06084B08) {
    (*(int(*)())0x0601D5F4)(0, 0xAB111DFF); /* play angle change sound */
  }
}

/* name_entry_keyboard -- Handle keyboard input for name entry screen.
 * Button press (DAT_06014682): dispatches based on selected character:
 *   0x7B ('{' = confirm): calls FUN_060146d2 to validate/save
 *   0x7D ('}' = backspace): does nothing (blocked)
 *   other: appends character to name buffer at 0x06084B14,
 *          plays letter sound from table 0x0605B0FC (A-Z mapped)
 * Backspace (PTR_DAT_06014684): decrements count, clears last char.
 * When count reaches 3: forces view to 0x1C, plays confirm sound.
 * Empty name + backspace: clears all 4 chars. */
void FUN_060145bc()
{
  int pos;
  int snd_code;
  char *name_buf = (char *)0x06084B14;   /* 4-byte name buffer */
  int *name_len = (int *)0x06084B18;     /* current name length */
  int *sel_char = (int *)0x06084B20;     /* currently selected character */
  void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;
  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06014682) != 0) {
    if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06014684) == 0 &&
        *sel_char != 0x7d) {
      if (*sel_char == 0x7b) {
        FUN_060146d2();           /* confirm entry */
        return;
      }
      /* append selected character */
      pos = *name_len;
      *name_len = pos + 1;
      name_buf[pos] = (char)*sel_char;
      snd_code = 0xAB1102FF;     /* default keypress sound */
      if (-1 < *sel_char + -0x41) {
        snd_code = *(int *)(0x0605B0FC + (*sel_char + -0x41) << 2);  /* letter sound */
      }
      snd_cmd(0, snd_code);
      if (*name_len == 3) {
        *(int *)0x06084B08 = 0x1c;  /* auto-advance view to confirm */
        snd_cmd(0, 0xAB111EFF);     /* name complete sound */
      }
    } else if (*name_len == 0) {
      /* empty name + backspace: clear buffer */
      *(int *)0x06084B14 = 0;
      name_buf[1] = 0;
      name_buf[2] = 0;
      name_buf[3] = 0;
    } else {
      /* backspace: remove last character */
      snd_cmd(0, 0xAB1101FF);
      pos = *name_len;
      *name_len = pos + -1;
      name_buf[pos + -1] = 0;
    }
  }
  return;
}

/* name_entry_confirm -- Validate and store entered name.
 * Resets countdown, checks cheat code table via FUN_0601476c:
 *   cheat detected (return != 0): sets state to 6 (easter egg)
 *   normal: sets state to 4 (standard entry)
 * If mode flag (0x06084B10) bit 0 is clear, copies 4-byte name
 * to two destination slots (0x06085FFC and 0x06086000) for
 * high score table insertion. Returns mode flag. */
unsigned int FUN_060146d2()
{
  char cheat_found;
  unsigned int mode;
  char *name_buf = (char *)0x06084B14;
  char *dest;
  *(int *)0x0607EBCC = 0;               /* reset countdown timer */
  cheat_found = FUN_0601476c(0x06084FB4);  /* check cheat code table */
  if (cheat_found == '\0') {
    *(int *)0x06084AF2 = 4;              /* normal entry state */
  } else {
    *(int *)0x06084AF2 = 6;              /* cheat code detected state */
  }
  mode = *(unsigned int *)0x06084B10;
  if ((mode & 1) == 0) {
    /* copy name to high score slot A */
    dest = *(char **)0x06085FFC;
    if (dest != (char *)0x0) {
      dest[0] = name_buf[0];
      dest[1] = name_buf[1];
      dest[2] = name_buf[2];
      dest[3] = name_buf[3];
    }
    /* copy name to high score slot B */
    dest = *(char **)0x06086000;
    if (dest != (char *)0x0) {
      dest[0] = name_buf[0];
      dest[1] = name_buf[1];
      dest[2] = name_buf[2];
      dest[3] = name_buf[3];
    }
  }
  return mode;
}

/* cheat_code_check -- Check 3-byte input against cheat code table.
 * Compares input at 0x06084B14 against entries in table at 0x0605B3C4 (3 bytes each).
 * On partial match (index < 2): scrambles input with frame-seeded pattern.
 * On full match (index >= 2): sets found flag at 0x06084FB8.
 * Stores match value from 0x0605B164 lookup, returns 0 when match found. */
unsigned int FUN_0601476c(param_1)
    unsigned int *param_1;
{
  char *input_buf;
  unsigned char *code_next;
  unsigned char *code_ptr;
  char *scramble_src;
  unsigned int code_idx;
  unsigned int sentinel;
  unsigned int active;
  char match_count;
  code_ptr = 0x0605B3C4;                    /* cheat code table */
  input_buf = (char *)0x06084B14;            /* 3-byte input buffer */
  sentinel = (unsigned int)DAT_06014818;
  active = 1;
  code_idx = 0;
  *(short *)0x06084FB8 = 0;                  /* clear found flag */
  *(unsigned int *)0x0607EBCC = sentinel - 0x4b;
  do {
    /* Compare 3 input bytes against current code entry */
    match_count = *input_buf == *code_ptr;
    code_next = code_ptr + 2;
    if (input_buf[1] == code_ptr[1]) {
      match_count = match_count + '\x01';
    }
    code_ptr = code_ptr + 3;
    if (input_buf[2] == *code_next) {
      match_count = match_count + '\x01';
    }
    if (match_count == '\x03') {
      /* All 3 bytes match — store associated value */
      *(int *)0x0607EBCC = *(int *)(0x0605B164 + (code_idx << 2));
      if (code_idx < 2) {
        /* Partial cheat: scramble input with frame-seeded pattern */
        if (0x2a < code_idx) {
          code_idx = 0x2b;
        }
        scramble_src = 0x0605B4A8 +
                 (short)(((short)(code_idx << 2) + ((unsigned short)FRAME_COUNTER & 3)) * 3);
        *input_buf = *scramble_src;
        input_buf[1] = scramble_src[1];
        code_ptr = scramble_src + 3;
        input_buf[2] = scramble_src[2];
        active = sentinel & 0xff;
      }
      else {
        /* Full cheat code match */
        active = 0;
        *(short *)0x06084FB8 = 1;
      }
    }
    code_idx = code_idx + 1;
    if (*code_ptr == sentinel) {
      active = 0;                            /* end of table */
    }
  } while (active == 1);
  *param_1 = code_idx;
  return active;
}

/* hud_init_and_render -- Initialize HUD: DMA palette to VDP1, render digits.
 * Copies 32 words from 0x06044B64 to VDP1 CRAM at calculated offset
 * (0x25C00260 + frame-selected bank). Calls hud_digits_render_all.
 * Sets HUD active flag (bit 0 of 0x0607EBF4), initializes display slots. */
void FUN_06014a04(void)
{
    int in_r7 = 0;

    (*(int(*)())0x0602761E)(0x25C00000 + 0x260 + *(int *)(0x06059FFC << 3),
                            0x06044B64, 0x20, in_r7, 0x25C00000);

    (*(int(*)())0x060172BC)();  /* hud_digits_render_all */

    *(unsigned int *)0x0607EBF4 = *(unsigned int *)0x0607EBF4 | 1;
    *(short *)0x06085F90 = 0;
    *(short *)0x06085F94 = 1;
}

/* game_display_full_init -- Full game display initialization.
 * Configures VDP2 scroll/priority registers, uploads palettes to VDP1/VDP2 color RAM,
 * loads 4 scroll plane patterns, initializes 44 HUD text slots (stride 0x36),
 * renders digits/sprites, optionally sets up race-specific car state. */
void FUN_06014a74()
{
  char *hud_slots;
  char *config_fn;
  char *vdp1_base;
  unsigned int idx;
  short *slot_ptr;
  unsigned char char_idx;
  unsigned char slot_idx;
  config_fn = (char *)0x06038BD4;
  hud_slots = (char *)0x06085640;
  /* VDP2 scroll/priority register config */
  (*(int(*)())0x06038BD4)(0x100,0);
  (*(int(*)())config_fn)(4,1);
  (*(int(*)())config_fn)(8,1);
  (*(int(*)())config_fn)(0x10,2);
  (*(int(*)())config_fn)(0x20,7);
  (*(int(*)())config_fn)(1,0);
  /* Scene-specific initialization */
  if (*(int *)0x06085F8A == '\0') {
    (*(int(*)())0x0602853E)(4);           /* VDP1 command init */
    (*(int(*)())0x06014884)(8,0);         /* SCU interrupt clear */
    (*(int(*)())config_fn)(0x10,6);
    (*(int(*)())0x06028560)();            /* VDP1 flush */
    (*(int(*)())0x060032D4)();            /* scene setup */
  }
  else {
    (*(int(*)())0x06020CF4)();
    (*(int(*)())0x060078DC)();
  }
  (*(int(*)())config_fn)(0x100,4);
  (*(int(*)())0x0602853E)(0xc);
  (*(int(*)())0x06014884)(0x10,0);
  (*(int(*)())0x06014884)(0x20,0);
  /* Upload 4 palettes to VDP2 color RAM (0x25F00660-0x25F006C0) */
  config_fn = (char *)0x0602761E;
  (*(int(*)())0x0602761E)(0x25F00660,0x06044A64,0x20);
  (*(int(*)())config_fn)(0x25F00680,0x06044A84,0x20);
  (*(int(*)())config_fn)(0x25F006A0,0x06044AA4,0x20);
  (*(int(*)())config_fn)(0x25F006C0,0x06044AC4,0x20);
  /* Upload 4 palettes to VDP1 color RAM (frame-bank selected) */
  vdp1_base = (char *)0x25C00000;
  (*(int(*)())config_fn)(0x25C00000 + 0x260 + *(int *)(0x06059FFC << 3),
                    0x06044AE4,0x20);
  (*(int(*)())config_fn)(vdp1_base + 0x280 + *(int *)(0x06059FFC << 3),0x06044B24,0x20)
  ;
  (*(int(*)())config_fn)(vdp1_base + 0x220 + *(int *)(0x06059FFC << 3),0x06044B04,0x20)
  ;
  (*(int(*)())config_fn)(vdp1_base + 0x240 + *(int *)(0x06059FFC << 3),0x06044B44,0x20)
  ;
  /* Load 4 VDP2 scroll plane patterns */
  config_fn = (char *)0x0600511E;
  (*(int(*)())0x0600511E)(0x25E73B98,0x00017700,0,8);
  (*(int(*)())config_fn)(0x25E74158,0x000189E0,0,8);
  (*(int(*)())config_fn)(0x25E74AFC,0x0001AFA0,0,8);
  (*(int(*)())config_fn)(0x25E75730,0x0001C980,0,8);
  /* Initialize 44 HUD text slots (stride 0x36 bytes each) */
  for (slot_idx = 0; slot_idx < 0x2c; slot_idx = slot_idx + 1) {
    slot_ptr = (short *)(hud_slots + (short)((unsigned short)slot_idx * 0x36));
    *slot_ptr = 1;                         /* active flag */
    slot_ptr[1] = 0x19;                   /* max chars = 25 */
    char_idx = 0;
    do {
      idx = (unsigned int)char_idx;
      char_idx = char_idx + 1;
      *(short *)(hud_slots + (idx << 1) + (int)(short)((unsigned short)slot_idx * 0x36) + 4) = 0x20;  /* space */
    } while (char_idx < 0x19);
  }
  /* Render HUD digits and sprites */
  (*(int(*)())0x060172BC)();               /* digit render */
  (*(int(*)())0x060173AC)();               /* sprite render */
  *(int *)0x06085F89 = 0;
  *(short *)0x06085F90 = 0;
  *(short *)0x06085F94 = 1;
  (*(int(*)())0x060149CC)();
  /* Race-specific initialization */
  if (((unsigned int)(*(short *)0x0607ED8C == 2) & *(unsigned int *)0x0607EBF4) != 0) {
    *(short *)0x06085F90 = 0x27;
    hud_slots = (char *)0x0607E944;
    *(int *)(CAR_PTR_TARGET + (int)DAT_06014cf2) = (int)(char)*(int *)0x06078637;
    *(int *)(*(int *)hud_slots + 0x240) = *(int *)0x06078638;
    *(int *)0x060786A4 = *(int *)0x0607863C;
  }
  return;
}

/* hud_page_scroll_handler -- Handle HUD page scroll transitions and configure car entry Y-offsets.
 * Button press cycles through display pages. Behavior depends on HUD active flag (0x0607EBF4 bit 0).
 * Clears display lines 8-15 when transitioning through certain page ranges.
 * Sets Y offsets for 8 car entries based on validity (0x44/0x4C normal, 0x48/0x50 invalid). */
void FUN_06014d2c()
{
  char *entry_table;
  char *scroll_pos;
  short target_state;
  int base_offset;
  char *dirty_flag;
  unsigned char idx;
  scroll_pos = (char *)0x06085F90;
  entry_table = (char *)0x06063F64;
  dirty_flag = (char *)0x06085F94;
  /* Handle page scroll button press */
  if ((*(int *)0x06085F89 == '\0') && ((*(unsigned short *)0x06063D9A & DAT_06014de4) != 0)) {
    if ((*(unsigned int *)0x0607EBF4 & 1) == 0) {
      /* HUD inactive mode */
      if (*(unsigned short *)0x06085F90 < 0xc || 0x15 < *(unsigned short *)0x06085F90) {
        if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x16) {
          *(int *)0x06085F89 = 1;
          *(short *)dirty_flag = 1;
          *(short *)scroll_pos = *(short *)scroll_pos + 0x12;
        }
      }
      else {
        /* Clear display lines 8-15 */
        *(int *)0x06085F89 = 1;
        idx = 8;
        do {
          (*(int(*)())0x060172E4)(idx);
          idx = idx + 1;
        } while (idx < 0x10);
        *(short *)dirty_flag = 1;
        target_state = 0x20;
        if (0x14 < *(unsigned short *)scroll_pos) {
          target_state = 0x22;
        }
        *(short *)scroll_pos = target_state;
      }
    }
    else if (*(unsigned short *)0x06085F90 < 0xc || 0x16 < *(unsigned short *)0x06085F90) {
      /* HUD active mode — simple offset */
      if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x17) {
        *(int *)0x06085F89 = 1;
        *(short *)dirty_flag = 1;
        *(short *)scroll_pos = *(short *)scroll_pos + 0x13;
      }
    }
    else {
      /* HUD active mode — clear and transition */
      *(int *)0x06085F89 = 1;
      idx = 8;
      do {
        (*(int(*)())0x060172E4)(idx);
        idx = idx + 1;
      } while (idx < 0x10);
      *(short *)dirty_flag = 1;
      target_state = 0x23;
      if (0x14 < *(unsigned short *)scroll_pos) {
        target_state = 0x26;
      }
      *(short *)scroll_pos = target_state;
    }
  }
  if (*(int *)0x06085F8A != '\0') {
    (*(int(*)())0x06020CF4)();
  }
  FUN_06014f34();
  (*(int(*)())0x0601712C)();
  /* Configure Y offsets for 8 car entries */
  idx = 0;
  base_offset = *(int *)0x06085F98;
  do {
    dirty_flag = *(char **)(0x06084FC8 + (short)((unsigned short)idx * 0x44) + 0x2c);
    if ((dirty_flag == (char *)0x0 || dirty_flag == 0x00008000) || dirty_flag == 0x00010000) {
      *(short *)(entry_table + (((unsigned int)idx + base_offset) << 3) + 6) = 0x4c;  /* invalid car */
      target_state = 0x50;
    }
    else {
      *(short *)(entry_table + (((unsigned int)idx + base_offset) << 3) + 6) = 0x44;  /* valid car */
      target_state = 0x48;
    }
    idx = idx + 1;
    *(short *)(entry_table + ((base_offset + 6) << 3) + 6) = target_state;
  } while (idx < 8);
  return;
}

/* replay_init_sequence -- Initialize replay mode state and rendering.
 * Stops sound (0x06018E70), configures CD transfer (0x06038BD4),
 * sets GAME_STATE to 0x1E (replay). If demo flags set, may redirect
 * to state 0x1A. Sets up VDP rendering, clears screen twice,
 * configures scroll planes, enables input, then dispatches to
 * course-specific handler via jump table at 0x0605B724. */
void FUN_06015338()
{
  int (*cd_config)(int, int) = (int (*)(int, int))0x06038BD4;

  (*(int(*)())0x06018E70)(); /* stop sound */
  cd_config(0x100, 0); /* configure CD transfer */

  *(int *)0x06085F8A = 0; /* clear render flag */
  GAME_STATE = 0x1e; /* set replay state */
  (*(int(*)())0x0601ABC6)(); /* replay setup */

  if (*(int *)0x06085FF8 != '\0' || *(int *)0x06085FF9 != '\0') {
    if (*(short *)0x06085F92 == 0) {
      (*(int(*)())0x0601AC7C)(); /* demo mode setup */
    }
    GAME_STATE = 0x1a; /* redirect to attract mode */
  }

  (*(int(*)())0x060172BC)(); /* init replay subsystem */
  cd_config(0x100, 0);
  cd_config(4, 1);
  cd_config(0x10, 6);

  (*(int(*)())0x060149E0)(); /* HUD setup */
  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)(); /* VDP sync */
  PHASE_FLAG = 3;

  (*(int(*)())0x06020CF4)(); /* vdp1_clear */
  (*(int(*)())0x060078DC)(); /* wait vblank */
  (*(int(*)())0x06020CF4)(); /* vdp1_clear (double buffer) */
  (*(int(*)())0x060078DC)(); /* wait vblank */

  (*(int(*)())0x0602853E)(4); /* scroll plane setup A */
  (*(int(*)())0x0602853E)(0xc); /* scroll plane setup B */
  (*(int(*)())0x06028560)(); /* finalize scroll config */
  (*(int(*)())0x060032D4)(); /* system sync */

  INPUT_STATE = INPUT_STATE | 4; /* enable input */
  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)(); /* VDP sync */
  cd_config(0x100, 4);
  cd_config(4, 0);

  (*(int(*)())(*(int *)(0x0605B724 + *(int *)(0x0607EAD8 << 2))))(); /* course handler dispatch */
}

/* sound_channel_configure -- Configure a sound channel from lookup tables.
 * param_1 low byte = channel index. Computes table offset from channel's
 * state byte at 0x06084FC8, loads PCM address/pitch/flags from 0x0605B8B8.
 * Checks if pitch == 0x100000 (special marker) to set loop flag.
 * If stereo mode (0x06085F89), also loads alternate PCM parameters.
 * Increments channel's sequence counter. */
void FUN_06015eb8(param_1)
    unsigned int param_1;
{
  unsigned short chan_idx;
  unsigned int table_off;
  int *table_entry;
  int pitch_check;
  char *chan_base = (char *)0x06084FC8;
  char *pcm_table = (char *)0x0605B8B8;

  chan_idx = (unsigned short)param_1 & 0xff;
  table_off = (unsigned int)(unsigned char)((int *)0x06084FC8)[(short)(chan_idx * 0x44) + 0x41] * 4 +
              (param_1 & 0xff) << 4 & 0xff;

  table_entry = (int *)(0x0605B8B8 + (table_off << 2));

  *(int *)(0x06084FC8 + (short)(chan_idx * 0x44) + 0x34) = *table_entry; /* PCM address */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x10) = table_entry[1]; /* pitch */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x1c) = 0; /* clear loop flag */

  pitch_check = (*(int(*)())0x06035438)(*(int *)(chan_base + (short)(chan_idx * 0x44) + 0x10));
  if (pitch_check == 0x00100000) {
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x1c) = 1; /* set loop flag */
  }

  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x38) =
       *(int *)(pcm_table + (table_off << 2) + 8); /* volume */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x18) =
       *(int *)(pcm_table + (table_off << 2) + 0xc); /* pan */

  if (*(int *)0x06085F89 != '\0') {
    /* stereo mode: load alternate parameters */
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x30) =
         *(int *)((int)(pcm_table + ((((param_1 & 0xff) << 4) + 8) << 2)) + 8);
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 4) =
         *(int *)(pcm_table + ((((param_1 & 0xff) << 4) + 8) << 2));
  }

  chan_base[(short)(chan_idx * 0x44) + 2] = chan_base[(short)(chan_idx * 0x44) + 2] + '\x01'; /* increment sequence */
}

/* --- FUN_06014868 (L1 import from src/FUN_06014868.c) --- */

void FUN_06014868(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  register int p2 asm("r2") = param_2;
  register int p3 asm("r3") = param_3;

  (*(int(*)())0x0603850C)();
  (*(int(*)())0x06038794)(p2, p3);
  (*(void(*)())0x06038520)();
}

/* --- FUN_0601492C (L1 import from src/FUN_0601492C.c) --- */

void FUN_0601492c()
{

  char *puVar1;

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,4);

  (*(int(*)())puVar1)(4,1);

  (*(int(*)())puVar1)(8,5);

  (*(int(*)())puVar1)(0x10,6);

  (*(int(*)())puVar1)(0x20,7);

  (*(int(*)())puVar1)(1,0);

  return;

}
