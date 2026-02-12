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
extern unsigned short camera_view_select();
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

/* FUN_0600a084: L2 version in render_setup.c */
extern void FUN_0600A084(void);
void FUN_0600a084(void) { FUN_0600A084(); }

/* FUN_0600a0c0: L2 version in vdp_state_init.c */
extern void FUN_0600A0C0(void);
void FUN_0600a0c0(void) { FUN_0600A0C0(); }

/* FUN_0600a140: L2 version in vdp1_clear.c */
extern void FUN_0600A140(void);
void FUN_0600a140(void) { FUN_0600A140(); }

/* FUN_0600a1b8: L2 version in game_state_utils.c */
extern void FUN_0600A1B8(void);
void FUN_0600a1b8(void) { FUN_0600A1B8(); }

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

/* FUN_0600a33c: L2 version in game_state_utils.c */
extern void FUN_0600A33C(void);
void FUN_0600a33c(void) { FUN_0600A33C(); }

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

/* FUN_0600a8bc: L2 version in speed_counter.c */
extern void FUN_0600A8BC(void);
void FUN_0600a8bc(void) { FUN_0600A8BC(); }

/* FUN_0600a914: L2 version in collision.c */
extern void FUN_0600A914(void);
void FUN_0600a914(void) { FUN_0600A914(); }

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

/* car_model_render_setup -- Set up car model rendering with matrix transforms.
 * Uses CAR_PTR_TARGET for car data. Pushes matrix stack (0x06027080),
 * translates by car position (+0x10/14/18), applies X/Y/Z rotations
 * via 0x060271A2/0x060271EE/0x06027158. If scene rendering enabled
 * (0x06059F30 != 0), transforms normals via FUN_06032158 and projects
 * polygons via FUN_06031DF4. Selects vertex/normal tables based on
 * CAR_COUNT (0/1/2 → different 0x06063434-0x06063488 addresses). */
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

/* car_model_render_all -- Render all active AI car 3D models.
 * Iterates car slots 1..N, builds per-car rotation matrix from position/angles,
 * applies body roll/pitch if car is moving (+0xB8 or collision state).
 * Selects model LOD based on car state flags:
 *   - 0x400000 set or scene state 8: damaged model (LOD_C at 0x0606212C)
 *   - 0x200000 set: spinning/airborne model (LOD_B at 0x060621D8)
 *   - Normal with flag bit 7: standard model (LOD_D at 0x060620D8)
 * Each LOD config has fields at +0x18 (model), +0x28 (matrix A),
 * +0x2c (matrix B), +0x30 (texture). Car palette from 0x06089E44. */
unsigned int FUN_0600b6a0()
{
  char *matrix_stack;    /* 0x06089EDC */
  char *palette_table;   /* 0x06089E44 */
  char *model_setup;     /* 0x06031D8C — model data setup function */
  char *model_render;    /* 0x06031A28 — model render function */
  unsigned int result;
  int *lod_c_mat_a;      /* LOD C (0x0606212C) fields */
  int *lod_b_mat_a;      /* LOD B (0x060621D8) fields */
  int *lod_a_mat_a;      /* LOD A (0x06062180) fields */
  int *lod_d_mat_a;      /* LOD D (0x060620D8) fields */
  short *palette_idx;
  int *lod_b_mat_b;
  int *lod_c_mat_b;
  int *lod_a_mat_b;
  int *lod_d_mat_b;
  int *lod_b_tex;
  int *lod_c_tex;
  int *lod_a_tex;
  int *lod_d_tex;
  int *lod_b_model;
  int *lod_c_model;
  int *lod_a_model;
  int *lod_d_model;
  unsigned int car_palette_idx;
  unsigned int slot;
  unsigned int *car_ptr;
  model_render = (char *)0x06031A28;
  model_setup = (char *)0x06031D8C;
  palette_table = (int *)0x06089E44;
  matrix_stack = (char *)0x06089EDC;
  result = DEMO_MODE_FLAG;
  if (result == 0) {
    /* Pre-load LOD config pointers for all 4 detail levels */
    lod_b_mat_a = (int *)(0x060621D8 + 0x28);
    lod_c_mat_a = (int *)(0x0606212C + 0x28);
    lod_a_mat_a = (int *)(0x06062180 + 0x28);
    palette_idx = (short *)(0x06089E44 + 4);
    lod_d_mat_a = (int *)(0x060620D8 + 0x28);
    lod_b_mat_b = (int *)(0x060621D8 + 0x2c);
    lod_c_mat_b = (int *)(0x0606212C + 0x2c);
    lod_a_mat_b = (int *)(0x06062180 + 0x2c);
    lod_d_mat_b = (int *)(0x060620D8 + 0x2c);
    lod_b_tex = (int *)(0x060621D8 + 0x30);
    lod_c_tex = (int *)(0x0606212C + 0x30);
    lod_a_tex = (int *)(0x06062180 + 0x30);
    lod_d_tex = (int *)(0x060620D8 + 0x30);
    result = 0x40;
    lod_b_model = (int *)(0x060621D8 + 0x18);
    lod_c_model = (int *)(0x0606212C + 0x18);
    lod_a_model = (int *)(0x06062180 + 0x18);
    lod_d_model = (int *)(0x060620D8 + 0x18);
    for (slot = 1; slot < (unsigned int)(int)*(short *)0x06078664; slot = slot + 1) {
      car_ptr = (unsigned int *)(0x06078900 + slot * 0x268);
      if ((*car_ptr & (unsigned int)0x00E00000) != 0) {
        /* Build rotation matrix: translate → rotate Y → pitch → roll */
        (*(int(*)())0x06026DBC)();                   /* reset matrix */
        (*(int(*)())0x06026E2E)(car_ptr[4],car_ptr[5] + *(int *)((int)car_ptr + CAR_FORCE_SUB),car_ptr[6]);
        (*(int(*)())0x06026EDE)(0x00008000 + car_ptr[8]);   /* heading */
        (*(int(*)())0x06026F2A)(-car_ptr[9]);                /* pitch */
        (*(int(*)())0x06026E94)(-car_ptr[7]);                /* roll */
        /* Apply body deformation if car is moving or in collision */
        if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) + *(int *)((int)car_ptr + CAR_STEER_TIMER)
            != 0) {
          (*(int(*)())0x06026EDE)(-*(int *)((int)car_ptr + CAR_FORCE_Z) -
                     *(int *)((int)car_ptr + CAR_STEER_DEFLECT));
          (*(int(*)())0x06026F2A)(-*(int *)((int)car_ptr + CAR_FORCE_ANG));
          (*(int(*)())0x06026E94)(-*(int *)((int)car_ptr + CAR_FORCE_X));
        }
        car_palette_idx = (unsigned int)(unsigned char)((int *)0x06047FC4)[slot];
        /* Select model LOD based on car state flags */
        if (((*car_ptr & 0x400000) == 0) &&
           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {
          if ((*car_ptr & 0x200000) == 0) {
            /* Normal rendering — check visibility flag (bit 7) */
            result = (unsigned int)*(char *)((int)car_ptr + 1);
            if ((result & 0x80) != 0) {
              if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) < 1) {
                /* Wheel shadow model */
                (*(int(*)())model_setup)(*lod_c_mat_a,*lod_b_mat_a);
                (*(int(*)())model_render)(*lod_d_mat_a,(int)*palette_idx,*lod_a_mat_a);
              }
              /* Update car state and render standard model */
              FUN_0600aa98(car_ptr,1);
              (*(int(*)())model_setup)(*lod_c_model,*lod_b_model);
              result = (*(int(*)())model_render)(*lod_d_model,(int)*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_model);
            }
          }
          else {
            /* Spinning/airborne model (LOD B+D) */
            (*(int(*)())model_setup)(*lod_c_tex,*lod_b_tex);
            result = (*(int(*)())model_render)(*lod_d_tex,(int)*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_tex);
          }
        }
        else {
          /* Damaged/crashed model (LOD C) */
          if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) < 1) {
            (*(int(*)())model_setup)(*lod_c_mat_a,*lod_b_mat_a);
            (*(int(*)())model_render)(*lod_d_mat_a,(int)*palette_idx,*lod_a_mat_a);
          }
          (*(int(*)())model_setup)(*lod_c_mat_b,*lod_b_mat_b);
          result = (*(int(*)())model_render)(*lod_d_mat_b,(int)*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_mat_b);
        }
        *(int *)matrix_stack = *(int *)matrix_stack + -0x30;  /* pop matrix */
      }
    }
  }
  return result;
}

/* car_model_render_secondary -- Render secondary/remote car models.
 * Like car_model_render_all but uses secondary matrix pipeline (0x06027080 etc)
 * and iterates car slots from *(short *)0x06078664 to *(int *)0x0607EA98
 * (remote/networked cars in VS mode). Same LOD selection logic. */
unsigned int FUN_0600b914()
{
  char *matrix_stack;
  char *palette_table;
  char *model_setup;
  char *model_render;
  unsigned int result;
  int *lod_c_mat_a;
  int *lod_b_mat_a;
  int *lod_d_mat_a;
  int *lod_c_mat_b;
  short *palette_idx;
  int *lod_b_mat_b;
  int *lod_d_mat_b;
  int *lod_a_mat_a;
  int *lod_a_mat_b;
  int *lod_b_tex;
  int *lod_c_tex;
  int *lod_a_tex;
  int *lod_d_tex;
  int *lod_b_model;
  int *lod_c_model;
  int *lod_a_model;
  int *lod_d_model;
  unsigned int car_palette_idx;
  unsigned int slot;
  unsigned int *car_ptr;
  model_render = (char *)0x06031DF4;
  model_setup = (char *)0x06032158;
  palette_table = (int *)0x06089E44;
  matrix_stack = (char *)0x0608A52C;

  result = DEMO_MODE_FLAG;
  if (result == 0) {
    /* Pre-load LOD config pointers */
    lod_b_mat_a = (int *)(0x060621D8 + 0x28);
    lod_c_mat_a = (int *)(0x0606212C + 0x28);
    lod_a_mat_a = (int *)(0x06062180 + 0x28);
    palette_idx = (short *)(0x06089E44 + 4);
    lod_d_mat_a = (int *)(0x060620D8 + 0x28);
    lod_b_mat_b = (int *)(0x060621D8 + 0x2c);
    lod_c_mat_b = (int *)(0x0606212C + 0x2c);
    lod_a_mat_b = (int *)(0x06062180 + 0x2c);
    lod_d_mat_b = (int *)(0x060620D8 + 0x2c);
    lod_b_tex = (int *)(0x060621D8 + 0x30);
    lod_c_tex = (int *)(0x0606212C + 0x30);
    lod_a_tex = (int *)(0x06062180 + 0x30);
    lod_d_tex = (int *)(0x060620D8 + 0x30);
    result = 0x40;
    lod_b_model = (int *)(0x060621D8 + 0x18);
    lod_c_model = (int *)(0x0606212C + 0x18);
    lod_a_model = (int *)(0x06062180 + 0x18);
    lod_d_model = (int *)(0x060620D8 + 0x18);
    /* Iterate secondary car slots (remote/VS cars) */
    for (slot = (unsigned int)*(short *)0x06078664; slot < *(unsigned int *)0x0607EA98;
        slot = slot + 1) {
      car_ptr = (unsigned int *)(0x06078900 + slot * 0x268);
      if ((*car_ptr & (unsigned int)0x00E00000) != 0) {
        /* Build rotation matrix using secondary pipeline */
        (*(int(*)())0x06027080)();
        (*(int(*)())0x060270F2)(car_ptr[4],car_ptr[5] + *(int *)((int)car_ptr + CAR_FORCE_SUB),car_ptr[6]);
        (*(int(*)())0x060271A2)(0x00008000 + car_ptr[8]);
        (*(int(*)())0x060271EE)(-car_ptr[9]);
        (*(int(*)())0x06027158)(-car_ptr[7]);
        if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) + *(int *)((int)car_ptr + CAR_STEER_TIMER)
            != 0) {
          (*(int(*)())0x060271A2)(-*(int *)((int)car_ptr + CAR_FORCE_Z) -
                     *(int *)((int)car_ptr + CAR_STEER_DEFLECT));
          (*(int(*)())0x060271EE)(-*(int *)((int)car_ptr + CAR_FORCE_ANG));
          (*(int(*)())0x06027158)(-*(int *)((int)car_ptr + CAR_FORCE_X));
        }
        car_palette_idx = (unsigned int)(unsigned char)((int *)0x06047FC4)[slot];
        /* Select model LOD based on state flags */
        if (((*car_ptr & 0x400000) == 0) &&
           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {
          if ((*car_ptr & 0x200000) == 0) {
            result = (unsigned int)*(char *)((int)car_ptr + 1);
            if ((result & 0x80) != 0) {
              if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) < 1) {
                (*(int(*)())model_setup)(*lod_c_mat_a,*lod_b_mat_a);
                (*(int(*)())model_render)(*lod_d_mat_a,*palette_idx,*lod_a_mat_a);
              }
              FUN_0600ac44(car_ptr,1);
              (*(int(*)())model_setup)(*lod_c_model,*lod_b_model);
              result = (*(int(*)())model_render)(*lod_d_model,*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_model);
            }
          }
          else {
            (*(int(*)())model_setup)(*lod_c_tex,*lod_b_tex);
            result = (*(int(*)())model_render)(*lod_d_tex,*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_tex);
          }
        }
        else {
          if (*(int *)((int)car_ptr + CAR_FORCE_COUNT) < 1) {
            (*(int(*)())model_setup)(*lod_c_mat_a,*lod_b_mat_a);
            (*(int(*)())model_render)(*lod_d_mat_a,*palette_idx,*lod_a_mat_a);
          }
          (*(int(*)())model_setup)(*lod_c_mat_b,*lod_b_mat_b);
          result = (*(int(*)())model_render)(*lod_d_mat_b,*(short *)(palette_table + (car_palette_idx << 1)),*lod_a_mat_b);
        }
        *(int *)matrix_stack = *(int *)matrix_stack + -0x30;
      }
    }
  }
  return result;
}

/* camera_position_update -- update camera position/orientation based on car state and camera mode */
void FUN_0600bb94()
{
  char camera_mode;
  char *matrix_apply;
  char *cam_z_offset;
  char *cam_y_offset;
  char *cam_world_pos;
  char *cam_track_arr;
  int zoom_step;
  char *cam_lateral;
  int car_ptr;
  int sin_result;
  int cos_result[2];

  cam_lateral = (char *)0x06063E24;  /* camera X lateral offset */
  cam_track_arr = (int *)0x06063EEC; /* +4=heading, +8=pitch */
  cam_world_pos = (char *)0x06063EF8; /* camera world X/Y/Z */
  cam_y_offset = (char *)0x06063E30; /* camera Y offset */
  cam_z_offset = (char *)0x06063E28; /* camera Z offset */
  matrix_apply = (int *)0x06038520;  /* matrix_apply function */
  car_ptr = CAR_PTR_TARGET;
  zoom_step = (int)DAT_0600bc2c;    /* camera zoom increment */

  camera_mode = *(int *)0x06078654;
  if (camera_mode != '\0') {

    if (camera_mode == '\x01') {
      /* Mode 1: Normal following camera */
      if (*(int *)0x0605A1C4 == 0) {
        if (*(unsigned int *)0x06063E20 < 2) {
          /* Track car heading + steering offset */
          *(int *)(0x06063EEC + 4) = *(int *)(car_ptr + 0x20) + *(int *)(car_ptr + DAT_0600bc2e);
        }
        camera_view_select((int)*(short *)0x06063D9A); /* camera_steering_input */
      }
    }

    else if (camera_mode == '\x04') {
      /* Mode 4: Crash/recovery — time-based zoom with heading interpolation */
      if (*(int *)(car_ptr + DAT_0600bcee) == 0) {
        *(int *)0x06063E20 = 2; /* set camera state = zoomed */
      }
      else if (*(int *)(car_ptr + DAT_0600bcee) < 0x31) {
        if (*(int *)(car_ptr + DAT_0600bcee) < 0x29) {
          if (*(int *)(car_ptr + DAT_0600bcee) < 0x11) {
            if (*(int *)(car_ptr + DAT_0600bcee) < 9) {
              /* Early crash frames: snap to overhead if collision type 7 or 8 */
              if ((*(int *)(car_ptr + DAT_0600bdac) == 8) || (*(int *)(car_ptr + DAT_0600bdac) == 7)) {
                *(int *)0x06063E1C = 2;
                *(int *)0x06059F30 = 1;
                (*(int(*)())0x06038BD4)(8,0); /* matrix_reset */
                *(char **)cam_lateral = (char *)0x00058000;
                *(char **)0x06063E34 = 0x0000F300; /* cam_base_heading */
                *(char **)cam_z_offset = (char *)0x006E0000;
                *(char **)0x06063E2C = 0x00100000; /* cam_pitch_offset */
                *(int *)cam_y_offset = 0;
              }
            }
            else {
              /* Frames 9-16: zoom in */
              *(int *)0x06063E24 = *(int *)0x06063E24 + zoom_step;
            }
          }
        }
        else {
          /* Frames 41-48: zoom out */
          *(int *)0x06063E24 = *(int *)0x06063E24 - zoom_step;
        }
      }

      /* Interpolate heading toward 0x8000 (forward) */
      zoom_step = (int)DAT_0600bdae;
      *(int *)(cam_track_arr + 4) = *(int *)(car_ptr + 0x20) - *(int *)(car_ptr + zoom_step);
      *(int *)(car_ptr + zoom_step) =
           *(int *)(car_ptr + zoom_step) + ((int)0x00008000 - *(int *)(car_ptr + zoom_step) >> 4);
    }

    else if (camera_mode == '\x06') {
      /* Mode 6: Set camera state to 3 (transition) */
      *(int *)0x06063E20 = 3;
    }

    else if (camera_mode == '\a') {
      /* Mode 7: Same crash zoom as mode 4, plus steering input */
      if (*(int *)(car_ptr + PTR_DAT_0600bc30) < 0x31) {
        if (*(int *)(car_ptr + PTR_DAT_0600bc30) < 0x29) {
          if (*(int *)(car_ptr + PTR_DAT_0600bc30) < 0x11) {
            if (*(int *)(car_ptr + PTR_DAT_0600bc30) < 9) {
              if ((*(int *)(car_ptr + DAT_0600bcee) == 8) || (*(int *)(car_ptr + DAT_0600bcee) == 7)) {
                *(int *)0x06063E1C = 2;
                *(int *)0x06059F30 = 1;
                (*(int(*)())0x06038BD4)(8,0);
                *(char **)cam_lateral = (char *)0x00058000;
                *(char **)0x06063E34 = 0x0000F300;
                *(char **)cam_z_offset = (char *)0x006E0000;
                *(char **)0x06063E2C = 0x00100000;
                *(int *)cam_y_offset = 0;
              }
            }
            else {
              *(int *)0x06063E24 = *(int *)0x06063E24 + zoom_step;
            }
          }
        }
        else {
          *(int *)0x06063E24 = *(int *)0x06063E24 - zoom_step;
        }
      }
      camera_view_select((int)*(short *)0x06063D9A);
    }
  }

  /* Compute camera lateral offset from heading direction */
  if (*(int *)0x06078663 == '\0') {
    cam_lateral = (char *)(*(int *)(cam_track_arr + 4) * -0x400 + 0xFFA00000);
  }
  else {
    cam_lateral = 0x01A00000 + *(int *)(cam_track_arr + 4) << 10;
  }

  if (*(int *)0x06082A30 == 0) {
    /* Normal racing — full camera pipeline */
    if (*(int *)(car_ptr + PTR_DAT_0600be4c) == 0) {
      (*(int(*)())0x060064F2)(); /* camera_auto_adjust */
    }
    else {
      zoom_step = (int)DAT_0600bf3c;
      *(int *)0x06063F04 = zoom_step; /* cam_near_clip */
      *(int *)0x06063F08 = zoom_step; /* cam_far_clip */
    }

    /* Build camera lateral rotation matrix */
    (*(int(*)())0x0603850C)(4); /* matrix_mode(4) = lateral */
    (*(int(*)())0x0603853C)(cam_lateral,*(int *)cam_z_offset,0);
    (*(int(*)())matrix_apply)();

    /* Build camera pitch rotation matrix */
    zoom_step = *(int *)(car_ptr + 0x1c) << 8; /* car roll * 256 */
    if (zoom_step < 0) {
      zoom_step = *(int *)(car_ptr + 0x1c) << 9; /* double scale for negative */
    }
    (*(int(*)())0x0603850C)(8); /* matrix_mode(8) = pitch */
    (*(int(*)())0x0603853C)(0,*(int *)(0x0605BDCC + (*(unsigned short *)0x06063F46 & 0xc) << 2) << 9 +
                 *(int *)0x06063E2C + zoom_step);
    (*(int(*)())matrix_apply)();

    (*(int(*)())0x06020E74)(); /* road_surface_scroll_update */

    /* Decompose camera heading into sin/cos for world position */
    (*(int(*)())0x06027358)(*(int *)(cam_track_arr + 4),&sin_result,cos_result);
    *(int *)cam_world_pos = *(int *)(car_ptr + 0x10) - sin_result;       /* cam_X = car_X - sin */
    *(int *)(cam_world_pos + 4) = *(int *)(car_ptr + 0x14) + *(int *)cam_y_offset; /* cam_Y */
    *(int *)(cam_world_pos + 8) = *(int *)(car_ptr + 0x18) + cos_result[0]; /* cam_Z = car_Z + cos */

    FUN_0600bf70(); /* camera_clamp_bounds */

    /* Compute filtered yaw from heading delta */
    zoom_step = (*(int(*)())0x06027344)(*(int *)(cam_track_arr + 4) - *(int *)(car_ptr + 0x20));
    *(int *)0x06078668 = -(zoom_step >> 7); /* yaw_rate = -delta/128 */
    zoom_step = (*(int(*)())0x06027552)(*(int *)(car_ptr + 0x24),zoom_step); /* fixed_multiply */
    *(int *)(cam_track_arr + 8) = zoom_step + *(int *)(cam_track_arr + 8) >> 1; /* IIR filter pitch */
  }
  else {
    /* Non-racing state — simplified camera with replay offset */
    (*(int(*)())0x0603850C)(4);
    (*(int(*)())0x0603853C)(cam_lateral,*(int *)cam_z_offset,0);
    (*(int(*)())matrix_apply)();

    (*(int(*)())0x06027358)(*(int *)(cam_track_arr + 4),&sin_result,cos_result);
    *(int *)cam_world_pos = (*(int *)(car_ptr + 0x10) - sin_result) + *(int *)0x06082A70; /* + replay_offset_X */
    *(int *)(cam_world_pos + 4) = *(int *)(car_ptr + 0x14) + *(int *)cam_y_offset;
    *(int *)(cam_world_pos + 8) = *(int *)(car_ptr + 0x18) + cos_result[0] + *(int *)0x06082A78; /* + replay_offset_Z */
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
