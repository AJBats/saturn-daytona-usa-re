#include "game.h"

extern int DAT_0600a10c;
extern int DAT_0600a110;
extern int DAT_0600a112;
extern int DAT_0600a224;
extern int DAT_0600a226;
extern int DAT_0600a2d8;
extern int DAT_0600a2da;
extern int DAT_0600a2dc;
extern int DAT_0600a2de;
extern int DAT_0600a854;
extern int DAT_0600a856;
extern int DAT_0600a99a;
extern int DAT_0600aa7e;
extern int DAT_0600b100;
extern int DAT_0600b102;
extern int DAT_0600b104;
extern int DAT_0600b106;
extern int DAT_0600b47a;
extern int DAT_0600b47c;
extern int DAT_0600b47e;
extern int DAT_0600b630;
extern int DAT_0600b632;
extern int DAT_0600b634;
extern int DAT_0600b636;
extern int DAT_0600b838;
extern int DAT_0600b83a;
extern int DAT_0600b83c;
extern int DAT_0600b83e;
extern int DAT_0600b840;
extern int DAT_0600b842;
extern int DAT_0600b90e;
extern int DAT_0600bab0;
extern int DAT_0600bab2;
extern int DAT_0600bab4;
extern int DAT_0600bab6;
extern int DAT_0600bab8;
extern int DAT_0600baba;
extern int DAT_0600bc2c;
extern int DAT_0600bc2e;
extern int DAT_0600bcee;
extern int DAT_0600bdac;
extern int DAT_0600bdae;
extern int DAT_0600bf3c;
extern int DAT_0600bfe2;
extern int DAT_0600bfe4;
extern int DAT_0600bfe6;
extern int DAT_0600c090;
extern void FUN_0600a76c();
extern void FUN_0600aa98();
extern void FUN_0600ac44();
extern unsigned int FUN_0600b6a0();
extern void FUN_0600bf70();
extern int FUN_0600c3a8();
extern int FUN_06031A28();
extern int FUN_06031D8C();
extern int PTR_DAT_0600a900;
extern int PTR_DAT_0600a99c;
extern int PTR_DAT_0600aa80;
extern int PTR_DAT_0600b480;
extern int PTR_DAT_0600b638;
extern int PTR_DAT_0600b844;
extern int PTR_DAT_0600babc;
extern int PTR_DAT_0600bb8c;
extern int PTR_DAT_0600bc30;
extern int PTR_DAT_0600be4c;
extern short DAT_0600a36c;
extern short DAT_0600a36e;
extern short DAT_0600a370;
extern short DAT_0600a372;

/* vdp_render_reset -- Reset VDP rendering state and SCU interrupt masks.
 * First clears 4 VDP render slots (0, 4, 8, 0xC) via 0x0602853E,
 * then finalizes with 0x06028560.
 * Then resets 4 SCU interrupt masks (4, 8, 0x10, 0x20) to 0 via 0x06014884. */
void FUN_0600a026(void)
{
    register void (*vdp_clear)(int) = (void (*)(int))0x0602853E;
    register void (*scu_mask)(int, int) = (void (*)(int, int))0x06014884;

    vdp_clear(0);
    vdp_clear(4);
    vdp_clear(8);
    vdp_clear(0xc);
    (*(int(*)())0x06028560)();  /* vdp render finalize */

    scu_mask(4, 0);
    scu_mask(8, 0);
    scu_mask(0x10, 0);
    scu_mask(0x20, 0);
}

/* camera_shake_update -- Apply screen shake based on impact intensity.
 * If intensity < 2, no shake. Otherwise alternates direction each frame
 * (positive on even frames, negative on odd). Intensity scaled by 0x8000. */
void FUN_0600a084(void)
{
    register int shake_func asm("r3") = 0x06014884;
    int intensity = *(int *)(CAR_PTR_TARGET + (int)DAT_0600a10c);
    int offset;

    if (intensity < 2) {
        (*(void(*)())shake_func)(0x10, 0, 0);
        return;
    }
    offset = intensity << 15;
    if ((FRAME_COUNTER & 1) != 0) {
        offset = intensity * -0x8000;  /* negate on odd frames */
    }
    (*(void(*)())shake_func)(0x10, offset, 0);
}

/* vdp_state_init -- Initialize VDP1/VDP2 rendering state for new frame.
 * Configures display mode (0x100), resets VBlank counter, sets up
 * scroll regions, clears command buffer, marks draw-end (0x8000). */
void FUN_0600a0c0(void)
{
    register int render_flush asm("r3") = 0x06026CE0;
    register int scroll_ptr asm("r2") = 0x06063F5C;

    (*(int(*)())0x06038BD4)(0x100, 0);         /* VDP2 display mode */
    (*(int(*)())render_flush)();                /* flush render pipeline */
    VBLANK_OUT_COUNTER = 0;
    (*(int(*)())0x06039250)(scroll_ptr);        /* configure scroll plane */
    (*(int(*)())0x060393FC)(0, 0, 0, (int)DAT_0600a112, (int)DAT_0600a110);
    VDP1_CMD_BASE_PTR = 0;
    **(short **)scroll_ptr = (short)0x8000;     /* draw-end command */
    (*(int(*)())render_flush)();                /* flush again */
    VBLANK_OUT_COUNTER = 0;
}

/* vdp1_vram_clear -- Clear VDP1 VRAM framebuffer (0x25C80000) twice.
 * Sets draw-end command at 0x25C00000, then zeros 64KB of VRAM.
 * Each pass: clear VRAM, enable VBlank, flush render, reset counter.
 * Double-clear ensures both front/back buffers are wiped. */
void FUN_0600a140(void)
{
    int *dst;
    int i;

    *(int *)0x25C00000 = 0x80000000;  /* VDP1 draw-end command */

    /* First pass: clear front buffer */
    dst = (int *)0x25C80000;
    for (i = 0x10000; i > 0; i -= 2) {
        dst[0] = 0;
        dst[1] = 0;
        dst += 2;
    }
    VBL_DISABLE_FLAG = 0;
    (*(int(*)())0x06026CE0)();  /* render flush */
    VBLANK_OUT_COUNTER = 0;

    /* Second pass: clear back buffer */
    dst = (int *)0x25C80000;
    for (i = 0x10000; i > 0; i -= 2) {
        dst[0] = 0;
        dst[1] = 0;
        dst += 2;
    }
    VBL_DISABLE_FLAG = 0;
    (*(int(*)())0x06026CE0)();  /* render flush */
    VBLANK_OUT_COUNTER = 0;
}

/* save_course_params -- Save current course parameters to state buffer.
 * Only writes if in special mode (0x06078635 != 0) or on course 0.
 * Stores: steering mode (byte 0), gear type (byte 1), car flags (byte 2).
 * Returns last-read value (car flags or course index). */
unsigned int FUN_0600a1b8(void)
{
    register char *base asm("r2") = (char *)0x0607ED90;
    unsigned int result;

    if (*(char *)0x06078635 != 0 ||
       ((result = *(unsigned short *)0x0607ED8C) == 0 &&
        (result = COURSE_SELECT) == 0)) {
        base[0] = (char)*(short *)0x06063F44;
        base[1] = (char)*(int *)0x06078868;
        result = *(unsigned int *)0x0607EAB8 & 0xff;
        base[2] = (char)result;
    }
    return result;
}

/* phase_transition_check -- Check state countdown and set PHASE_FLAG.
 * Uses per-course thresholds (car_count=0/1/2+) to decide when to
 * transition to phase 3 (pre-race) or 4 (race start).
 * Returns CAR_COUNT value. */
int FUN_0600a1f6(void)
{
    int count = CAR_COUNT;

    if (count == 0) {
        if (STATE_COUNTDOWN == (int)DAT_0600a224)
            PHASE_FLAG = 3;
        else if (STATE_COUNTDOWN == 0xa8)
            PHASE_FLAG = 4;
    } else if (count == 1) {
        if (STATE_COUNTDOWN == (int)DAT_0600a2d8)
            PHASE_FLAG = 3;
        else if (STATE_COUNTDOWN == 0x271)
            PHASE_FLAG = 4;
    } else {
        if (STATE_COUNTDOWN == (int)DAT_0600a2dc)
            PHASE_FLAG = 3;
        else if (STATE_COUNTDOWN == 0x190)
            PHASE_FLAG = 4;
    }

    return count;
}

/* phase_transition_extended -- Extended phase transition for 1-2 player modes.
 * For 1-player: check STATE_COUNTDOWN against 0x371 (phase 3) / 0x352 (phase 4).
 * For 2-player: check 3 pairs of thresholds for phase 3/4 transitions.
 * Returns CAR_COUNT. */
int FUN_0600a294(void)
{
    int count = CAR_COUNT;
    int countdown = STATE_COUNTDOWN;

    if (count == 1) {
        if (countdown == 0x371)       PHASE_FLAG = 3;
        else if (countdown == 0x352)  PHASE_FLAG = 4;
    } else if (count == 2) {
        if (countdown == 0x3ab)                PHASE_FLAG = 3;
        else if (countdown == 0x398)           PHASE_FLAG = 4;
        else if (countdown == (int)DAT_0600a36c) PHASE_FLAG = 3;
        else if (countdown == (int)DAT_0600a36e) PHASE_FLAG = 4;
        else if (countdown == (int)DAT_0600a370) PHASE_FLAG = 3;
        else if (countdown == (int)DAT_0600a372) PHASE_FLAG = 4;
    }
    return count;
}

/* phase_select -- Map game sub-phase (0x06063E1C) to PHASE_FLAG value.
 * Sub-phase 0->5, 1->6, 2->7, 3->8. Used during race state transitions. */
int FUN_0600a33c(void)
{
    register int sub_phase asm("r0");
    sub_phase = *(int *)0x06063E1C;

    if (sub_phase == 0)      PHASE_FLAG = 5;
    else if (sub_phase == 1) PHASE_FLAG = 6;
    else if (sub_phase == 2) PHASE_FLAG = 7;
    else if (sub_phase == 3) PHASE_FLAG = 8;

    return sub_phase;
}

/* sound_position_update -- Update positional sound for a given source index.
 * param_1 = sound source index (0-based).
 * Looks up parameters from 4 parallel arrays at 0x06062820-0x0606291C.
 * Calls sound tempo setter (0x06031D8C) and sound position updater (0x06031A28). */
void FUN_0600a474(int param_1, int param_2, int param_3, int param_4)
{
    int off = param_1 << 2;

    (*(int(*)())0x06031D8C)(*(int *)(0x06062874 + off), *(int *)(0x060628C8 + off),
               param_3, param_4, param_1);

    (*(int(*)())0x06031A28)(*(int *)(0x06062820 + off), (int)*(short *)0x06089E9E,
               *(int *)(0x0606291C + off));
}

/* scene_sound_update -- Update scene audio: set BGM tempo and play positional sound.
 * Reads tempo from game state, position from render globals. */
void FUN_0600a4aa(void)
{
    FUN_06031D8C(*(int *)0x06062130, *(int *)0x060621DC);
    FUN_06031A28(*(int *)0x060620DC, *(short *)0x06089E44, *(int *)0x06062184);
}

/* course_sound_dispatch -- Dispatch course-specific BGM and positional audio.
 * Selects from 3 parallel table sets based on CAR_COUNT (course 0/1/2).
 * Sets BGM tempo via FUN_06031D8C, then positional sound via FUN_06031A28.
 * param_1 = sound source index. */
int FUN_0600a4ca(int param_1)
{
    int off = param_1 << 2;
    int count = CAR_COUNT;
    int vol;
    int pan;
    char *pos_table;

    if (count == 0) {
        (*(int(*)())0x06031D8C)(*(int *)(0x06063488 + off), *(int *)(0x060634F8 + off));
        vol = *(int *)(0x060634DC + off);
        pan = (int)*(short *)(0x06089E44 + 0x54);
        pos_table = (char *)0x06063434;
    } else if (count == 1) {
        (*(int(*)())0x06031D8C)(*(int *)(0x060634A4 + off), *(int *)(0x060634F8 + off));
        vol = *(int *)(0x060634DC + off);
        pan = (int)*(short *)(0x06089E44 + 0x54);
        pos_table = (char *)0x06063450;
    } else if (count == 2) {
        (*(int(*)())0x06031D8C)(*(int *)(0x060634C0 + off), *(int *)(0x060634F8 + off));
        vol = *(int *)(0x060634DC + off);
        pan = (int)*(short *)(0x06089E44 + 0x54);
        pos_table = (char *)0x0606346C;
    } else {
        return count;
    }

    return (*(int(*)())0x06031A28)(*(int *)(pos_table + off), pan, vol);
}

/* course_sound_update -- Update course-specific positional audio.
 * Indexes into 4 parallel arrays by course_idx<<2 to get audio params.
 * Sets BGM tempo (FUN_06031D8C) and positional sound (FUN_06031A28). */
void FUN_0600a5b2(int course_idx, int param_2, int param_3, int param_4)
{
    int off = course_idx << 2;

    (*(int(*)())0x06031D8C)(*(int *)(0x06063520 + off), *(int *)(0x06063538 + off),
        param_3, param_4, course_idx);
    (*(int(*)())0x06031A28)(*(int *)(0x06063514 + off), (int)*(short *)0x06089E98,
        *(int *)(0x0606352C + off));
    return;

}

/* scene_object_sound -- Position and play 3D sound for up to 2 scene objects.
 * Reads scene object state from 0x0607EB8C. For each active object (slots 1, 4):
 * resets matrix (0x06027080), sets world position with Y offset (-13107),
 * sets scale to 0x8000 uniform, then updates sound tempo (0x06032158)
 * and positional audio (0x06031DF4) using object index + 14 as table offset.
 * Decrements OBJ_STATE_SECONDARY by 0x30 per active object. */
void FUN_0600a76c(void)
{
    int scale = 0x00008000;
    char *pcVar4 = *(char **)0x0607EB8C;

    if (pcVar4[1] != '\0') {
        (*(int(*)())0x06027080)();       /* matrix reset */
        (*(int(*)())0x060270F2)(*(int *)0x06044640 + (int)DAT_0600a856,
                   *(int *)(0x06044640 + 4) + -13107,
                   *(int *)(0x06044640 + 8) + 0xFFFF0F5D);
        (*(int(*)())0x06027124)(scale, scale, scale);

        int off = (*pcVar4 + 0xe) << 2;
        (*(int(*)())0x06032158)(*(int *)(0x0606212C + off), *(int *)(0x060621D8 + off));

        off = (*pcVar4 + 0xe) << 2;
        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + off), *(short *)0x06089E9C,
                   *(int *)(0x06062180 + off));

        OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;
    }

    if (pcVar4[4] != '\0') {
        (*(int(*)())0x06027080)();       /* matrix reset */
        (*(int(*)())0x060270F2)(*(int *)0x06044670, *(int *)(0x06044670 + 4) + -13107,
                   0xFFFDB334 - *(int *)(0x06044670 + 8));
        (*(int(*)())0x06027124)(scale, scale, scale);

        int off = (pcVar4[3] + 0xe) << 2;
        (*(int(*)())0x06032158)(*(int *)(0x0606212C + off), *(int *)(0x060621D8 + off));

        off = (pcVar4[3] + 0xe) << 2;
        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + off), *(short *)0x06089E9C,
                   *(int *)(0x06062180 + off));

        OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;
    }
}

/* speed_frame_counter -- Increment frame counter based on car speed.
 * If CAR_ACCEL (+0x0C) is 0, resets counter.
 * Otherwise increments by 1/2/4 depending on CAR_SPEED (+0x08) thresholds
 * (100, 200). Counter wraps at 16 (mask 0x0F). */
unsigned short FUN_0600a8bc(void)
{
    int car = CAR_PTR_CURRENT;
    unsigned short result;

    if (*(int *)(car + CAR_ACCEL) == 0) {
        *(short *)0x06063F46 = 0;
        result = 0;
    } else {
        if (*(int *)(car + CAR_SPEED) < 100)
            *(short *)0x06063F46 += 1;
        else if (*(int *)(car + CAR_SPEED) < 0xc8)
            *(short *)0x06063F46 += 2;
        else
            *(short *)0x06063F46 += 4;

        result = *(unsigned short *)0x06063F46 & 0xf;
        *(unsigned short *)0x06063F46 = result;
    }
    return result;
}

/* car_collision_proximity_check -- Detect car-to-car collisions by proximity.
 * Pass 1: For each AI car pair, checks checkpoint gap (<±0x15), then computes
 * weighted Manhattan distance (shorter axis /4). If close (<0x4B333) and speed
 * low enough, calls AI-AI collision handler (0x060316C4).
 * Pass 2: Checks all AI cars vs player car similarly, calls player collision
 * handler (0x06030FC0). Car struct stride 0x268, X at +0x10, Z at +0x18. */
int FUN_0600a914()
{
  char *car_base;
  char *car_count_ptr;
  int result;
  int checkpoint_delta;
  int dx;
  int dz;
  unsigned int i;
  unsigned int j;
  int player_car;
  int car_stride;
  unsigned int *car_ptr;
  car_base = (char *)0x06078900;        /* car array base */
  car_count_ptr = (int *)0x0607EA98;    /* active car count */
  car_stride = 0x268;
  result = DEMO_MODE_FLAG;
  if (result == 0) {
    /* Pass 1: AI-to-AI collision pairs */
    for (i = 1; i < *(int *)car_count_ptr - 1U; i = i + 1) {
      car_ptr = (unsigned int *)(car_base + i * car_stride);
      *(unsigned int **)0x0607E940 = car_ptr;
      j = i;
      if ((*car_ptr & (unsigned int)0x00E00000) != 0) {
        while (j = j + 1, j < *(unsigned int *)car_count_ptr) {
          checkpoint_delta = j * car_stride;
          result = (int)PTR_DAT_0600a99c;
          /* Check checkpoint proximity (within ±0x15) */
          dx = *(int *)((int)car_ptr + result) - *(int *)(car_base + result + checkpoint_delta);
          if ((dx < 0x15) && (-0x15 < dx)) {
            /* Compute weighted Manhattan distance */
            dx = *(int *)(car_base + checkpoint_delta + 0x10) - car_ptr[4];  /* delta X */
            dz = *(int *)(car_base + checkpoint_delta + 0x18) - car_ptr[6];  /* delta Z */
            if (dx < 0) {
              dx = -dx;
            }
            if (dz < 0) {
              dz = -dz;
            }
            /* Reduce shorter axis by 75% */
            if (dz < dx) {
              dz = dz >> 2;
            }
            else {
              dx = dx >> 2;
            }
            /* If close enough and speed condition met, handle collision */
            if ((dx + dz < (int)0x0004B333) &&
               (result = (int)DAT_0600aa7e, *(int *)(car_base + result + checkpoint_delta) < (int)0x00010000)
               ) {
              result = (*(int(*)())0x060316C4)(car_ptr);
            }
          }
        }
      }
    }
    /* Pass 2: AI-to-Player collision check */
    *(char **)0x0607E940 = car_base;
    player_car = *(int *)0x0607E940;
    for (i = 1; i < *(unsigned int *)car_count_ptr; i = i + 1) {
      car_ptr = (unsigned int *)(car_base + i * car_stride);
      if ((*car_ptr & (unsigned int)0x00E00000) != 0) {
        result = (int)PTR_DAT_0600aa80;
        checkpoint_delta = *(int *)(player_car + result) - *(int *)((int)car_ptr + result);
        if ((checkpoint_delta < 0x15) && (-0x15 < checkpoint_delta)) {
          dx = car_ptr[4] - *(int *)(player_car + 0x10);
          dz = car_ptr[6] - *(int *)(player_car + 0x18);
          if (dx < 0) {
            dx = -dx;
          }
          if (dz < 0) {
            dz = -dz;
          }
          if (dz < dx) {
            dz = dz >> 2;
          }
          else {
            dx = dx >> 2;
          }
          if ((dx + dz < (int)0x0004B333) &&
             (result = (int)DAT_0600aa7e, *(int *)((int)car_ptr + result) < (int)0x00010000)) {
            result = (*(int(*)())0x06030FC0)(player_car,car_ptr);
          }
        }
      }
    }
  }
  return result;
}

/* object_render_primary -- Render 3-part object using primary matrix pipeline.
 * Reads 4-byte descriptor from 0x0605A1D5 + (param_2 * 4) for sub-object
 * indices. Each part: resets primary matrix (0x06026DBC), applies camera
 * translation (0x06044640/4C/70), Y rotation (param_1+0x40 doubled),
 * X rotation (param_1+0x48 negated), then renders mesh (0x06031D8C)
 * and applies texture/color (0x06031A28) with palette from 0x06089E44.
 * Decrements OBJ_STATE_PRIMARY by 0x30 per sub-object. Third part uses
 * separate rotation (param_1+0x50) without Y-rotate. */
void FUN_0600aa98(param_1, param_2)
    int param_1;
    int param_2;
{
    unsigned char *desc = (unsigned char *)(0x0605A1D5 + (param_2 << 2));
    unsigned char palette_idx = desc[3];
    int rot_x = *(int *)(param_1 + 0x48);
    int rot_y = *(int *)(param_1 + 0x40) << 1;
    unsigned char part0 = *desc;
    char *mesh_table = (char *)0x0606212C;
    char *tex_table = (char *)0x060620D8;
    char *mtx_alt = (char *)0x06089EDC;
    short *palette = (short *)(0x06089E44 + (unsigned int)(palette_idx << 1));

    /* Part 0: main body */
    (*(int(*)())0x06026DBC)();                     /* matrix_reset */
    (*(int(*)())0x06026E2E)(*(int *)0x06044640, *(int *)(0x06044640 + 4),
               -*(int *)(0x06044640 + 8));         /* translate (camera 0) */
    (*(int(*)())0x06026EDE)(rot_y);                /* rotate Y */
    (*(int(*)())0x06026E94)(-rot_x);              /* rotate X */
    int idx = (unsigned int)(part0 << 2);
    (*(int(*)())0x06031D8C)(*(int *)(0x0606212C + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031A28)(*(int *)(0x060620D8 + idx), (int)*palette,
               *(int *)(0x06062180 + idx));
    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;

    /* Part 1: secondary body */
    unsigned char part1 = desc[1];
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)0x0604464C, *(int *)(0x0604464C + 4),
               -*(int *)(0x0604464C + 8));         /* translate (camera 1) */
    (*(int(*)())0x06026EDE)(rot_y);
    (*(int(*)())0x06026E94)(-rot_x);
    idx = (unsigned int)(part1 << 2);
    (*(int(*)())0x06031D8C)(*(int *)(mesh_table + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031A28)(*(int *)(tex_table + idx), (int)*palette, *(int *)(0x06062180 + idx));
    *(int *)mtx_alt = *(int *)mtx_alt + -0x30;

    /* Part 2: tertiary (separate X rotation) */
    int rot_x2 = *(int *)(param_1 + 0x50);
    unsigned char part2 = desc[2];
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)0x06044670, *(int *)(0x06044670 + 4),
               -*(int *)(0x06044670 + 8));         /* translate (camera 2) */
    (*(int(*)())0x06026E94)(-rot_x2);
    idx = (unsigned int)(part2 << 2);
    (*(int(*)())0x06031D8C)(*(int *)(mesh_table + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031A28)(*(int *)(tex_table + idx), (int)*palette, *(int *)(0x06062180 + idx));
    *(int *)mtx_alt = *(int *)mtx_alt + -0x30;
}

/* object_render_secondary -- Render 3-part object using secondary matrix stack.
 * Same structure as object_render_primary but uses secondary matrix
 * pipeline: stack push (0x06027080), translate (0x060270F2), rotate Y
 * (0x060271A2), rotate X (0x06027158). Renders via 0x06032158 and
 * textures via 0x06031DF4. Decrements OBJ_STATE_SECONDARY and matrix
 * stack pointer at 0x0608A52C by 0x30 per sub-object. */
void FUN_0600ac44(param_1, param_2)
    int param_1;
    int param_2;
{
    unsigned char *desc = (unsigned char *)(0x0605A1D5 + (param_2 << 2));
    unsigned char palette_idx = desc[3];
    int rot_x = *(int *)(param_1 + 0x48);
    int rot_y = *(int *)(param_1 + 0x40) << 1;
    unsigned char part0 = *desc;
    char *mesh_table = (char *)0x0606212C;
    char *tex_table = (char *)0x060620D8;
    char *mtx_stack = (char *)0x0608A52C;
    short *palette = (short *)(0x06089E44 + (unsigned int)(palette_idx << 1));

    /* Part 0: main body */
    (*(int(*)())0x06027080)();                     /* matrix_stack_push */
    (*(int(*)())0x060270F2)(*(int *)0x06044640, *(int *)(0x06044640 + 4),
               -*(int *)(0x06044640 + 8));         /* translate (camera 0) */
    (*(int(*)())0x060271A2)(rot_y);                /* rotate Y */
    (*(int(*)())0x06027158)(-rot_x);              /* rotate X */
    int idx = (unsigned int)(part0 << 2);
    (*(int(*)())0x06032158)(*(int *)(0x0606212C + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + idx), *palette,
               *(int *)(0x06062180 + idx));
    OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

    /* Part 1: secondary body */
    unsigned char part1 = desc[1];
    (*(int(*)())0x06027080)();
    (*(int(*)())0x060270F2)(*(int *)0x0604464C, *(int *)(0x0604464C + 4),
               -*(int *)(0x0604464C + 8));         /* translate (camera 1) */
    (*(int(*)())0x060271A2)(rot_y);
    (*(int(*)())0x06027158)(-rot_x);
    idx = (unsigned int)(part1 << 2);
    (*(int(*)())0x06032158)(*(int *)(mesh_table + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031DF4)(*(int *)(tex_table + idx), *palette, *(int *)(0x06062180 + idx));
    *(int *)mtx_stack = *(int *)mtx_stack + -0x30;

    /* Part 2: tertiary (separate X rotation) */
    int rot_x2 = *(int *)(param_1 + 0x50);
    unsigned char part2 = desc[2];
    (*(int(*)())0x06027080)();
    (*(int(*)())0x060270F2)(*(int *)0x06044670, *(int *)(0x06044670 + 4),
               -*(int *)(0x06044670 + 8));         /* translate (camera 2) */
    (*(int(*)())0x06027158)(-rot_x2);
    idx = (unsigned int)(part2 << 2);
    (*(int(*)())0x06032158)(*(int *)(mesh_table + idx), *(int *)(0x060621D8 + idx));
    (*(int(*)())0x06031DF4)(*(int *)(tex_table + idx), *palette, *(int *)(0x06062180 + idx));
    *(int *)mtx_stack = *(int *)mtx_stack + -0x30;
}

/* car_render_with_transform -- Render player car using secondary matrix stack.
 * Sets current car from target, pushes matrix, applies translate (XYZ from
 * car+0x10..+0x18), rotate Y (car+0x20 + 0x8000), rotate Z (-car+0x24).
 * Camera pitch computed from 0x06078668 vs car heading, with game state
 * affecting sign. Renders main body mesh + texture, then sub-objects via
 * object_render_secondary. Steering wheel mesh selected by car flags.
 * Calls reflection handler (0x0601C3E4) for replay/VS modes. */
void FUN_0600afb2()
{
    char *rotate_x = (char *)0x06027158;           /* matrix_rotate_X */
    char *cam_table = (char *)0x06063F46;
    int car = CAR_PTR_TARGET;
    CAR_PTR_CURRENT = car;

    (*(int(*)())0x06027080)();                     /* matrix_stack_push */
    (*(int(*)())0x060270F2)(*(int *)(car + 0x10), *(int *)(car + 0x14),
               *(int *)(car + 0x18));              /* translate XYZ */
    (*(int(*)())0x060271A2)(0x00008000 + *(int *)(car + 0x20)); /* rotate Y (+ 180 deg) */
    (*(int(*)())0x060271EE)(-*(int *)(car + 0x24));             /* rotate Z */

    /* Compute camera pitch from heading delta */
    int pitch;
    if ((GAME_STATE_BIT & (unsigned int)0x00800008) == 0) {
        pitch = (*(int *)0x06078668 - *(int *)(car + 0x1c)) +
                *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)((int)(int)cam_table << 2));
    } else {
        pitch = *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)((int)(int)cam_table << 2)) -
                *(int *)(car + 0x1c);
    }
    (*(int(*)())rotate_x)(pitch);                  /* rotate X (pitch) */
    (*(int(*)())0x060271A2)(*(int *)(car + DAT_0600b100) +
               *(int *)(car + DAT_0600b100 + -0xc)); /* additional Y rotation */

    if (*(int *)0x06059F30 != 0) {
        /* Render main body */
        (*(int(*)())0x06032158)(*(int *)0x0606213C, *(int *)0x060621E8);
        (*(int(*)())0x06031DF4)(*(int *)0x060620E8, *(short *)0x06089E44,
                   *(int *)0x06062190);

        /* Sub-object transforms */
        (*(int(*)())0x060270F2)(0, *(int *)(car + DAT_0600b102));
        (*(int(*)())0x060271EE)(*(int *)(car + DAT_0600b104));
        (*(int(*)())rotate_x)(*(int *)(car + DAT_0600b106));

        if ((*(int *)0x06082A25 & 2) == 0) {
            FUN_0600ac44(car, 0);                  /* render sub-objects */
        }

        /* Steering wheel / driver mesh */
        int mesh_idx = 0;
        int wheel_rot;
        if ((*(unsigned char *)(car + 1) & 1) == 0) {
            wheel_rot = *(int *)0x06083258;
        } else {
            mesh_idx = 0xd;
            wheel_rot = (int)(char)((int *)0x06044740)[*(unsigned short *)cam_table] +
                        *(int *)0x06083258;
        }
        (*(int(*)())rotate_x)(wheel_rot);
        mesh_idx = (mesh_idx << 2);
        (*(int(*)())0x06032158)(*(int *)(0x0606212C + mesh_idx), *(int *)(0x060621D8 + mesh_idx));
        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + mesh_idx), *(short *)0x06089E44,
                   *(int *)(0x06062180 + mesh_idx));
    }

    if ((GAME_STATE_BIT & (unsigned int)0x20020000) != 0) {
        (*(int(*)())0x0601C3E4)();                 /* reflection/shadow handler */
    }

    OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;
}

void FUN_0600b340()
{

  char *puVar1;

  int iVar2;

  char *unaff_r11;

  int iVar3;

  char *puVar4;

  char *unaff_r12;

  char *puVar5;

  char *puVar6;

  char *unaff_r13;

  char *puVar7;

  int iVar8;

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar8;

  iVar2 = CAR_COUNT;

  puVar5 = (char *)0x06063434;

  puVar7 = (int *)0x06063488;

  if (((iVar2 != 0) && (puVar5 = 0x06063450, puVar7 = 0x060634A4, iVar2 != 1)) &&

     (puVar5 = unaff_r12, puVar7 = unaff_r13, iVar2 == 2)) {

    puVar5 = (char *)0x0606346C;

    puVar7 = (int *)0x060634C0;

  }

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)(iVar8 + 0x10),*(int *)(iVar8 + 0x14),

             *(int *)(iVar8 + 0x18));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(int(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(int(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b47a) + *(int *)(iVar8 + DAT_0600b47a + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(int(*)())0x06032158)(*(int *)(puVar7 + 0x18),*(int *)0x06063510);

    puVar4 = (char *)0x06089E98;

    (*(int(*)())0x06031DF4)(*(int *)(puVar5 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(int(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b47c));

    (*(int(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b47e));

    (*(int(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b480) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06032158)(*(int *)(puVar7 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(puVar5 + iVar2),*(short *)puVar4,

               *(int *)(0x060634DC + iVar2));

    FUN_0600a76c();

  }

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  if (*(int *)0x0607867C == '\0') {

    return;

  }

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar8;

  puVar7 = (int *)0x06078670;

  puVar5 = (char *)0x00008000;

  iVar2 = CAR_COUNT;

  puVar4 = (char *)0x06063434;

  puVar6 = (int *)0x06063488;

  if (((iVar2 != 0) && (puVar4 = 0x06063450, puVar6 = 0x060634A4, iVar2 != 1)) &&

     (puVar4 = unaff_r11, puVar6 = unaff_r12, iVar2 == 2)) {

    puVar4 = (char *)0x0606346C;

    puVar6 = (int *)0x060634C0;

  }

  *(int *)0x06078670 =

       *(int *)0x06078670 +

       ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670) +

             ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670)) < 0)) >>

       1);

  iVar2 = *(int *)(iVar8 + 0x14) - *(int *)(puVar7 + 4);

  *(int *)(puVar7 + 4) = *(int *)(puVar7 + 4) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  puVar1 = (char *)0x06027080;

  iVar2 = (*(int *)(iVar8 + 0x18) - *(int *)(puVar7 + 8)) + (int)DAT_0600b630;

  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  (*(int(*)())puVar1)();

  (*(int(*)())0x060270F2)(*(int *)puVar7,*(int *)(puVar7 + 4),*(int *)(puVar7 + 8));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(int(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(int(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b632) + *(int *)(iVar8 + DAT_0600b632 + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(int(*)())0x06027124)(puVar5,puVar5,puVar5);

    (*(int(*)())0x06032158)(*(int *)(puVar6 + 0x18),*(int *)0x06063510);

    puVar5 = (char *)0x06089E98;

    (*(int(*)())0x06031DF4)(*(int *)(puVar4 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(int(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b634));

    (*(int(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b636));

    (*(int(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b638) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06032158)(*(int *)(puVar6 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(puVar4 + iVar2),*(short *)puVar5,

               *(int *)(0x060634DC + iVar2));

  }

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  return;

}

unsigned int FUN_0600b6a0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int *puVar6;

  int *puVar7;

  int *puVar8;

  int *puVar9;

  short *psVar10;

  int *puVar11;

  int *puVar12;

  int *puVar13;

  int *puVar14;

  int *puVar15;

  int *puVar16;

  int *puVar17;

  int *puVar18;

  int *puVar19;

  int *puVar20;

  int *puVar21;

  int *puVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int *puVar25;

  puVar4 = (char *)0x06031A28;

  puVar3 = (char *)0x06031D8C;

  puVar2 = (int *)0x06089E44;

  puVar1 = (char *)0x06089EDC;

  uVar5 = DEMO_MODE_FLAG;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    psVar10 = (short *)(0x06089E44 + 4);

    puVar16 = (int *)(0x060620D8 + 0x28);

    puVar11 = (int *)(0x060621D8 + 0x2c);

    puVar6 = (int *)(0x0606212C + 0x2c);

    puVar17 = (int *)(0x06062180 + 0x2c);

    puVar12 = (int *)(0x060620D8 + 0x2c);

    puVar7 = (int *)(0x060621D8 + 0x30);

    puVar18 = (int *)(0x0606212C + 0x30);

    puVar13 = (int *)(0x06062180 + 0x30);

    puVar8 = (int *)(0x060620D8 + 0x30);

    uVar5 = 0x40;

    puVar20 = (int *)(0x060621D8 + 0x18);

    puVar21 = (int *)(0x0606212C + 0x18);

    puVar19 = (int *)(0x06062180 + 0x18);

    puVar22 = (int *)(0x060620D8 + 0x18);

    for (uVar24 = 1; uVar24 < (unsigned int)(int)*(short *)0x06078664; uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * 0x268);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*(int(*)())0x06026DBC)();

        (*(int(*)())0x06026E2E)(puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600b83a),puVar25[6]);

        (*(int(*)())0x06026EDE)(0x00008000 + puVar25[8]);

        (*(int(*)())0x06026F2A)(-puVar25[9]);

        (*(int(*)())0x06026E94)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600b83c) + *(int *)((int)puVar25 + 0xb8)

            != 0) {

          (*(int(*)())0x06026EDE)(-*(int *)((int)puVar25 + DAT_0600b840 + -0xc) -

                     *(int *)((int)puVar25 + 0x1d8));

          (*(int(*)())0x06026F2A)(-*(int *)((int)puVar25 + 0x1d0));

          (*(int(*)())0x06026E94)(-*(int *)((int)puVar25 + 0x1c8));

        }

        uVar23 = (unsigned int)(unsigned char)((int *)0x06047FC4)[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)DAT_0600b90e) < 1) {

                (*(int(*)())puVar3)(*puVar9,*puVar14);

                (*(int(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

              }

              FUN_0600aa98(puVar25,1);

              (*(int(*)())puVar3)(*puVar21,*puVar20);

              uVar5 = (*(int(*)())puVar4)(*puVar22,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar19);

            }

          }

          else {

            (*(int(*)())puVar3)(*puVar18,*puVar7);

            uVar5 = (*(int(*)())puVar4)(*puVar8,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600b83c) < 1) {

            (*(int(*)())puVar3)(*puVar9,*puVar14);

            (*(int(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

          }

          (*(int(*)())puVar3)(*puVar6,*puVar11);

          uVar5 = (*(int(*)())puVar4)(*puVar12,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}

unsigned int FUN_0600b914()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int *puVar6;

  int *puVar7;

  int *puVar8;

  int *puVar9;

  short *puVar10;

  int *puVar11;

  int *puVar12;

  int *puVar13;

  int *puVar14;

  int *puVar15;

  int *puVar16;

  int *puVar17;

  int *puVar18;

  int *puVar19;

  int *puVar20;

  int *puVar21;

  int *puVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int *puVar25;

  puVar4 = (char *)0x06031DF4;

  puVar3 = (char *)0x06032158;

  puVar2 = (int *)0x06089E44;

  puVar1 = (char *)0x0608A52C;

  uVar5 = DEMO_MODE_FLAG;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    puVar10 = (short *)(0x06089E44 + 4);

    puVar16 = (int *)(0x060620D8 + 0x28);

    puVar11 = (int *)(0x060621D8 + 0x2c);

    puVar6 = (int *)(0x0606212C + 0x2c);

    puVar17 = (int *)(0x06062180 + 0x2c);

    puVar12 = (int *)(0x060620D8 + 0x2c);

    puVar7 = (int *)(0x060621D8 + 0x30);

    puVar18 = (int *)(0x0606212C + 0x30);

    puVar13 = (int *)(0x06062180 + 0x30);

    puVar8 = (int *)(0x060620D8 + 0x30);

    uVar5 = 0x40;

    puVar20 = (int *)(0x060621D8 + 0x18);

    puVar21 = (int *)(0x0606212C + 0x18);

    puVar19 = (int *)(0x06062180 + 0x18);

    puVar22 = (int *)(0x060620D8 + 0x18);

    for (uVar24 = (unsigned int)*(short *)0x06078664; uVar24 < *(unsigned int *)0x0607EA98;

        uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * 0x268);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*(int(*)())0x06027080)();

        (*(int(*)())0x060270F2)(puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600bab2),puVar25[6]);

        (*(int(*)())0x060271A2)(0x00008000 + puVar25[8]);

        (*(int(*)())0x060271EE)(-puVar25[9]);

        (*(int(*)())0x06027158)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600bab4) + *(int *)((int)puVar25 + 0xb8)

            != 0) {

          (*(int(*)())0x060271A2)(-*(int *)((int)puVar25 + DAT_0600bab8 + -0xc) -

                     *(int *)((int)puVar25 + 0x1d8));

          (*(int(*)())0x060271EE)(-*(int *)((int)puVar25 + 0x1d0));

          (*(int(*)())0x06027158)(-*(int *)((int)puVar25 + 0x1c8));

        }

        uVar23 = (unsigned int)(unsigned char)((int *)0x06047FC4)[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)PTR_DAT_0600bb8c) < 1) {

                (*(int(*)())puVar3)(*puVar9,*puVar14);

                (*(int(*)())puVar4)(*puVar16,*puVar10,*puVar15);

              }

              FUN_0600ac44(puVar25,1);

              (*(int(*)())puVar3)(*puVar21,*puVar20);

              uVar5 = (*(int(*)())puVar4)(*puVar22,*(short *)(puVar2 + (uVar23 << 1)),*puVar19);

            }

          }

          else {

            (*(int(*)())puVar3)(*puVar18,*puVar7);

            uVar5 = (*(int(*)())puVar4)(*puVar8,*(short *)(puVar2 + (uVar23 << 1)),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600bab4) < 1) {

            (*(int(*)())puVar3)(*puVar9,*puVar14);

            (*(int(*)())puVar4)(*puVar16,*puVar10,*puVar15);

          }

          (*(int(*)())puVar3)(*puVar6,*puVar11);

          uVar5 = (*(int(*)())puVar4)(*puVar12,*(short *)(puVar2 + (uVar23 << 1)),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}

void FUN_0600bb94()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  char *puVar8;

  int iVar9;

  int local_28;

  int aiStack_24 [2];

  puVar8 = (char *)0x06063E24;

  puVar6 = (int *)0x06063EEC;

  puVar5 = (char *)0x06063EF8;

  puVar4 = (char *)0x06063E30;

  puVar3 = (char *)0x06063E28;

  puVar2 = (int *)0x06038520;

  iVar9 = CAR_PTR_TARGET;

  iVar7 = (int)DAT_0600bc2c;

  cVar1 = *(int *)0x06078654;

  if (cVar1 != '\0') {

    if (cVar1 == '\x01') {

      if (*(int *)0x0605A1C4 == 0) {

        if (*(unsigned int *)0x06063E20 < 2) {

          *(int *)(0x06063EEC + 4) = *(int *)(iVar9 + 0x20) + *(int *)(iVar9 + DAT_0600bc2e);

        }

        FUN_0600c3a8((int)*(short *)0x06063D9A);

      }

    }

    else if (cVar1 == '\x04') {

      if (*(int *)(iVar9 + DAT_0600bcee) == 0) {

        *(int *)0x06063E20 = 2;

      }

      else if (*(int *)(iVar9 + DAT_0600bcee) < 0x31) {

        if (*(int *)(iVar9 + DAT_0600bcee) < 0x29) {

          if (*(int *)(iVar9 + DAT_0600bcee) < 0x11) {

            if (*(int *)(iVar9 + DAT_0600bcee) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bdac) == 8) || (*(int *)(iVar9 + DAT_0600bdac) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(int(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = (char *)0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = (char *)0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      iVar7 = (int)DAT_0600bdae;

      *(int *)(puVar6 + 4) = *(int *)(iVar9 + 0x20) - *(int *)(iVar9 + iVar7);

      *(int *)(iVar9 + iVar7) =

           *(int *)(iVar9 + iVar7) + ((int)0x00008000 - *(int *)(iVar9 + iVar7) >> 4);

    }

    else if (cVar1 == '\x06') {

      *(int *)0x06063E20 = 3;

    }

    else if (cVar1 == '\a') {

      if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x31) {

        if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x29) {

          if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x11) {

            if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bcee) == 8) || (*(int *)(iVar9 + DAT_0600bcee) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(int(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = (char *)0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = (char *)0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      FUN_0600c3a8((int)*(short *)0x06063D9A);

    }

  }

  if (*(int *)0x06078663 == '\0') {

    puVar8 = (char *)(*(int *)(puVar6 + 4) * -0x400 + 0xFFA00000);

  }

  else {

    puVar8 = 0x01A00000 + *(int *)(puVar6 + 4) << 10;

  }

  if (*(int *)0x06082A30 == 0) {

    if (*(int *)(iVar9 + PTR_DAT_0600be4c) == 0) {

      (*(int(*)())0x060064F2)();

    }

    else {

      iVar7 = (int)DAT_0600bf3c;

      *(int *)0x06063F04 = iVar7;

      *(int *)0x06063F08 = iVar7;

    }

    (*(int(*)())0x0603850C)(4);

    (*(int(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(int(*)())puVar2)();

    iVar7 = *(int *)(iVar9 + 0x1c) << 8;

    if (iVar7 < 0) {

      iVar7 = *(int *)(iVar9 + 0x1c) << 9;

    }

    (*(int(*)())0x0603850C)(8);

    (*(int(*)())0x0603853C)(0,*(int *)(0x0605BDCC + (*(unsigned short *)0x06063F46 & 0xc) << 2) << 9 +

                 *(int *)0x06063E2C + iVar7);

    (*(int(*)())puVar2)();

    (*(int(*)())0x06020E74)();

    (*(int(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = *(int *)(iVar9 + 0x10) - local_28;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0];

    FUN_0600bf70();

    iVar7 = (*(int(*)())0x06027344)(*(int *)(puVar6 + 4) - *(int *)(iVar9 + 0x20));

    *(int *)0x06078668 = -(iVar7 >> 7);

    iVar7 = (*(int(*)())0x06027552)(*(int *)(iVar9 + 0x24),iVar7);

    *(int *)(puVar6 + 8) = iVar7 + *(int *)(puVar6 + 8) >> 1;

  }

  else {

    (*(int(*)())0x0603850C)(4);

    (*(int(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(int(*)())puVar2)();

    (*(int(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = (*(int *)(iVar9 + 0x10) - local_28) + *(int *)0x06082A70;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0] + *(int *)0x06082A78;

  }

  return;

}

/* camera_heading_filter -- Compute filtered camera heading from car rotation.
 * Blends car's X-rotation (ROT_X at +0x1C) scaled by DAT_0600bfe2 with
 * the camera base heading (0x06063E34).
 * If camera phase matches target (0x06063E1C == 0x06063E20), applies IIR
 * filter (old*0x320 + new*0xE0) >> 10. Otherwise snaps directly. */
void FUN_0600bf70(void)
{
    short blended = (short)((int)(short)*(int *)(CAR_PTR_TARGET + CAR_ROT_X) * (int)DAT_0600bfe2
                   >> 10) + (short)*(int *)0x06063E34;

    if (*(int *)0x06063E1C == *(int *)0x06063E20) {
        *(int *)0x06063EEC =
            (int)(short)*(int *)0x06063EEC * 0x320 +
            (int)blended * 0xe0 >> 10;
    } else {
        *(int *)0x06063EEC = (int)blended;
    }
}

/* frame_render_dispatch -- Main per-frame rendering dispatch.
 * Calls scene visibility (0x06034708) if active, then dispatches AI
 * (0x0600D31C/0x0600D336) based on game mode. Copies primary matrix
 * state to secondary stack. Sets LOD level at 0x06078664 from either
 * half-max-objects or current descriptor count. Triggers VDP1 draw
 * start (0x21000000=0xFFFF), calls scene render (0x06006868) and
 * car render (FUN_0600b6a0). Busy-waits on VDP1 status (0xFFFFFE11)
 * for frame sync, adjusts LOD up/down based on VDP1 completion. */
void FUN_0600bffc()
{
    char *lod_ptr = (char *)0x0605A1DD;
    int *mtx_stack = (int *)0x0608A52C;
    int *game_flags = (int *)0x0607EBC4;
    unsigned char *vdp1_status = (unsigned char *)-495; /* 0xFFFFFE11 */
    int overloaded = 0;

    if (*(int *)0x06083255 != '\0') {
        (*(int(*)())0x06034708)(*(int *)0x0607EB8C);
    }

    /* Dispatch AI / physics update */
    if ((*(unsigned int *)game_flags & (unsigned int)0x02000000) == 0) {
        if (*(int *)0x06078635 == '\0') {
            (*(int(*)())0x0600D31C)();             /* single-player AI */
        } else {
            (*(int(*)())0x0600D336)();             /* VS mode AI */
        }
    }

    if ((*(char **)game_flags == 0x00020000) && (DEMO_MODE_FLAG == 0)) {
        (*(int(*)())0x0602E610)();                 /* replay handler */
    }

    /* Copy primary matrix to secondary stack */
    int prev_stack = *mtx_stack;
    *mtx_stack = prev_stack + 0x30;
    (*(int(*)())0x06027630)(prev_stack + 0x30, OBJ_STATE_PRIMARY, 0x30);

    /* Set LOD level */
    if (*(int *)0x06059F30 == 0) {
        *(short *)0x06078664 = (short)(*(int *)0x0607EA98 >> 1);
    } else {
        *(unsigned short *)0x06078664 = (unsigned short)(unsigned char)*lod_ptr;
    }

    *(char **)0x06063574 = (char *)0x0600C170;    /* render callback ptr */
    *(short *)0x21000000 = (short)0x0000FFFF;     /* VDP1: start draw */

    if ((*(unsigned int *)game_flags & (unsigned int)0x02800008) == 0) {
        (*(int(*)())0x060058FA)();                 /* pre-render setup */
    }

    (*(int(*)())0x06006868)();                     /* scene render */
    FUN_0600b6a0();                                /* car render */

    if (*(char **)game_flags != (char *)0x02000000) {
        (*(int(*)())0x0601BDEC)();                 /* post-render effects */
    }

    /* VDP1 busy wait for frame sync */
    while ((*vdp1_status & 0x80) != 0x80) {
        overloaded = 1;
    }
    *vdp1_status = *vdp1_status & 0xf;

    /* Adjust LOD based on VDP1 completion timing */
    if (overloaded) {
        if ((int)(unsigned int)(unsigned char)*lod_ptr < *(int *)0x0607EA98) {
            *lod_ptr = *lod_ptr + '\x01';          /* reduce detail */
        }
    } else if (1 < (unsigned char)*lod_ptr) {
        *lod_ptr = *lod_ptr + -1;                  /* increase detail */
    }

    (*(int(*)())0x0603C000)();                     /* frame finalize */
    *mtx_stack = *mtx_stack + -0x30;               /* pop matrix stack */
}
