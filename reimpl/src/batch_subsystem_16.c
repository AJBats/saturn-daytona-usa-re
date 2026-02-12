#include "game.h"

extern int DAT_06016eda;
extern int DAT_06016ffa;
extern int DAT_0601729e;
extern int DAT_0601748a;
extern int DAT_0601748c;
extern int DAT_0601748e;
extern int DAT_06017490;
extern int DAT_06017492;
extern int DAT_060175b4;
extern int DAT_060175b6;
extern int DAT_060175b8;
extern int DAT_060175ba;
extern int DAT_06017692;
extern int DAT_06017694;
extern int DAT_06017696;
extern int DAT_06017698;
extern int DAT_0601769a;
extern int DAT_0601769c;
extern int DAT_06017728;
extern int DAT_0601772a;
extern int DAT_0601772c;
extern int DAT_060178aa;
extern int DAT_060178ac;
extern int DAT_060179b6;
extern int DAT_06017bd4;
extern int DAT_06017bd6;
extern int DAT_06017bd8;
extern int DAT_06017c52;
extern int DAT_06017d92;
extern int DAT_06017d94;
extern int DAT_06017d96;
extern int DAT_06017d98;
extern int DAT_06017d9a;
extern int DAT_06017ea6;
extern int DAT_06017ea8;
extern int DAT_06017eaa;
extern int DAT_06017fdc;
extern int DAT_06017fde;
extern int DAT_06017fe0;
extern int DAT_06017fe2;
extern int DAT_06017fe4;
extern int DAT_06017fe6;
extern int DAT_060180fc;
extern int DAT_060180fe;
extern int DAT_06018100;
extern int DAT_06018102;
extern int DAT_06018104;
extern void hud_sprite_vertex_project();
extern void FUN_060172e4();
extern int FUN_06017330(unsigned short param_1);
extern int FUN_06017784();
extern void FUN_06017bf4();
extern void FUN_06017c78();
extern unsigned int FUN_06017c9c();
extern int track_calculation();
extern int PTR_DAT_060172a0;
extern int PTR_DAT_060179b8;
extern int PTR_DAT_06017d9c;

/* race_slot_init -- Initialize a race slot with position data from course table.
 * Clears slot state, loads 5 position values from 0x0605BB74 (indexed by
 * param_2 * 5, offset +0x28 for mirror mode). Stores as 16.16 fixed-point
 * into slot fields at +4/+8/+C/+10/+34. Then calls hud_sprite_vertex_project for
 * further init, and sets up display entry at 0x06085490 (stride 0x18). */
void FUN_06016cdc(param_1, param_2)
    unsigned char param_1;
    unsigned char param_2;
{
    char *slot_base = (char *)0x06084FC8;       /* race slot array base */
    char *pos_table = (char *)0x0605BB74;       /* course position table */
    int slot_off = (short)((unsigned short)param_1 * 0x44);
    int tbl_idx;

    ((int *)0x06084FC8)[slot_off + 1] = 0;     /* clear slot state */
    tbl_idx = 0;

    /* Mirror mode: offset position table by 0x28 entries */
    if (((unsigned int)(*(int *)0x06085F89 == '\0') & *(unsigned int *)0x0607EBF4) != 0) {
        tbl_idx = 0x28;
        *(char **)(slot_base + slot_off + 0x2c) = 0x00008000;
    }

    tbl_idx = (unsigned int)param_2 * 5 + tbl_idx;

    /* Load 5 position values as 16.16 fixed-point */
    *(int *)(slot_base + slot_off + 4) =
         (int)*(short *)(0x0605BB74 + (tbl_idx << 1)) << 0x10;
    *(int *)(slot_base + slot_off + 8) =
         (int)*(short *)(pos_table + ((tbl_idx + 1) << 1)) << 0x10;
    *(int *)(slot_base + slot_off + 0xc) =
         (int)*(short *)(pos_table + ((tbl_idx + 2) << 1)) << 0x10;
    *(int *)(slot_base + slot_off + 0x10) =
         (int)*(short *)(pos_table + ((tbl_idx + 3) << 1)) << 0x10;
    *(int *)(slot_base + slot_off + 0x34) =
         (int)*(short *)(pos_table + ((tbl_idx + 4) << 1)) << 0x10;

    hud_sprite_vertex_project(param_1);

    /* Set up display entry for this slot */
    char *disp_base = (char *)0x06085490;
    int disp_off = (short)((unsigned short)param_1 * 0x18);
    *(unsigned short *)(0x06085490 + disp_off + 6) = param_2 + 0x17;
    disp_base[disp_off + 4] = 1;
    disp_base[disp_off + 5] = 0x3a;
}

/* hud_sprite_vertex_project -- Project 4 corners of a HUD sprite element.
 * Takes slot index into object table at 0x06084FC8 (0x44 bytes/entry).
 * Reads rotation angles at +0x2C and +0x30 within the slot.
 * Decomposes angle via matrix function (0x06027358) into sin/cos,
 * then transforms 4 corner offsets (half-width/half-height) through
 * rotation matrix using fixed-point multiply (0x06027552).
 * Corner sizes: normal=0x10/0xC, results mode (0x15)=0x20/0x18.
 * Second pass applies depth correction with divide (0x0602755C).
 * Third pass writes final screen X/Y to sprite table at 0x06085490
 * (0x18 bytes/entry, corners at +8). NOTE: Heavy Ghidra stack artifacts
 * (stack0x...) — Ghidra failed to resolve the stack frame layout. */
void hud_sprite_vertex_project(slot_index)
    char slot_index;
{
  int stack0xfffffff0;
  int stack0x0000002c;
  int stack0xfffffff4;
  int stack0xfffffff8;
  int stack0x00000008;
  int stack0xfffffffe;
  int stack0xfffffffc;
  int stack0xffffffe8;
  int stack0x0000000c;
  int stack0xffffffec;
  int stack0xffffffe4;
  int stack0x0000003c;
  int stack0x0000001c;
  int stack0x00000004;
  int stack0x0000000a;
  int stack0x00000006;
  int stack0x0000005c;
  int stack0x0000004c;
  int stack0x00000002;
  int stack0x00000000;
  char *multiply_fn;
  char *slot_table;
  int frame_offset;
  int mul_result;
  int cross_result;
  short half_width;
  int *corner_ptr;
  short sprite_half_w;
  short *y_offset_ptr;
  short sprite_half_h;
  int corner_idx;
  unsigned char vertex_i;
  unsigned char slot_id;
  int *depth_ptr;
  int temp_buf[2];
  int cos_component;
  multiply_fn = (char *)0x06027552;                          /* fixed-point multiply */
  frame_offset = -140;
  sprite_half_w = 0x10;
  (&stack0xffffffec)[frame_offset] = slot_index;
  sprite_half_h = 0xc;
  if (GAME_STATE == 0x15) {                                  /* results screen: larger sprites */
    sprite_half_w = 0x20;
    sprite_half_h = 0x18;
  }
  /* set up 4 corner X offsets: -W, +W, +W, -W */
  *(short *)(&stack0x00000004 + frame_offset) = -sprite_half_w;
  *(short *)(&stack0x00000006 + frame_offset) = sprite_half_w;
  *(short *)(&stack0x00000008 + frame_offset) = sprite_half_w;
  *(short *)(&stack0x0000000a + frame_offset) = -sprite_half_w;
  /* set up 4 corner Y offsets: -H, -H, +H, +H */
  *(short *)(&stack0xfffffffc + frame_offset) = -sprite_half_h;
  *(short *)(&stack0xfffffffe + frame_offset) = -sprite_half_h;
  *(short *)(&stack0x00000000 + frame_offset) = sprite_half_h;
  *(short *)(&stack0x00000002 + frame_offset) = sprite_half_h;
  /* decompose angle at slot+0x30 into sin/cos components */
  (*(int(*)())0x06027358)(*(int *)                           /* matrix_decompose */
              (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x30),
             (int)&cos_component + frame_offset,&stack0xffffffe4 + frame_offset);
  /* pass 1: rotate 4 corners by angle (X*cos + Y*sin, Y*cos - X*sin) */
  slot_id = 0;
  do {
    corner_idx = (unsigned int)(slot_id << 2);
    *(char **)((int)temp_buf + frame_offset + 4) = &stack0x0000005c + corner_idx + frame_offset;
    *(unsigned int *)(&stack0xffffffe8 + frame_offset) = (unsigned int)(slot_id << 1);
    *(char **)(&stack0xfffffff0 + frame_offset) = &stack0x00000004 + (unsigned int)(slot_id << 1) + frame_offset;
    mul_result = (*(int(*)())multiply_fn)((int)*(short *)(&stack0x00000004 + (unsigned int)(slot_id << 1) + frame_offset) << 0x10,
                              *(int *)(&stack0xffffffe4 + frame_offset));
    *(int *)((int)temp_buf + frame_offset) = mul_result;
    y_offset_ptr = (short *)(*(int *)(&stack0xffffffe8 + frame_offset) + (int)(&stack0xfffffffc + frame_offset));
    *(short **)(&stack0xfffffff4 + frame_offset) = y_offset_ptr;
    cross_result = (*(int(*)())multiply_fn)((int)*y_offset_ptr << 0x10,*(int *)((int)&cos_component + frame_offset));
    **(int **)((int)temp_buf + frame_offset + 4) = cross_result + *(int *)((int)temp_buf + frame_offset);
    *(char **)((int)temp_buf + frame_offset + 4) = &stack0x0000004c + corner_idx + frame_offset;
    mul_result = (*(int(*)())multiply_fn)((int)**(short **)(&stack0xfffffff4 + frame_offset) << 0x10,
                              *(int *)(&stack0xffffffe4 + frame_offset));
    *(int *)((int)temp_buf + frame_offset) = mul_result;
    cross_result = (*(int(*)())multiply_fn)((int)**(short **)(&stack0xfffffff0 + frame_offset) << 0x10,
                              *(int *)((int)&cos_component + frame_offset));
    slot_id = slot_id + 1;
    **(int **)((int)temp_buf + frame_offset + 4) = *(int *)((int)temp_buf + frame_offset) - cross_result;
    *(int *)(&stack0x0000003c + corner_idx + frame_offset) = 0;
  } while (slot_id < 4);
  /* save original angle at slot+0x2C, apply highlight offset if needed */
  *(int *)(&stack0xfffffff8 + frame_offset) =
       *(int *)
        (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x2c);
  if (*(int *)0x06078663 != '\0') {                          /* highlight active flag */
    *(char **)
     (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x2c) =
         0x00008000 +
         *(int *)(0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x2c)
    ;
  }
  /* decompose angle at slot+0x2C (heading) into sin/cos */
  (*(int(*)())0x06027358)(*(int *)                           /* matrix_decompose */
              (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x2c),
             (int)&cos_component + frame_offset,&stack0xffffffe4 + frame_offset);
  /* pass 2: apply heading rotation with depth correction */
  slot_id = 0;
  do {
    corner_idx = (unsigned int)(slot_id << 2);
    *(char **)(&stack0xffffffe8 + frame_offset) = &stack0x0000000c + corner_idx + frame_offset;
    *(char **)((int)temp_buf + frame_offset + 4) = &stack0x0000000c + corner_idx + frame_offset;
    corner_ptr = (int *)((int)temp_buf + corner_idx + DAT_06016ffa + frame_offset + 4);
    *(int **)(&stack0xfffffff4 + frame_offset) = corner_ptr;
    mul_result = (*(int(*)())multiply_fn)(*corner_ptr,*(int *)((int)&cos_component + frame_offset));
    *(int *)((int)temp_buf + frame_offset) = mul_result;
    *(char **)(&stack0xfffffff0 + frame_offset) = &stack0x0000003c + corner_idx + frame_offset;
    cross_result = (*(int(*)())multiply_fn)(*(int *)(&stack0x0000003c + corner_idx + frame_offset),
                              *(int *)(&stack0xffffffe4 + frame_offset));
    **(int **)((int)temp_buf + frame_offset + 4) = cross_result + *(int *)((int)temp_buf + frame_offset);
    *(char **)((int)temp_buf + frame_offset + 4) = &stack0x0000002c + corner_idx + frame_offset;
    mul_result = (*(int(*)())multiply_fn)(**(int **)(&stack0xfffffff4 + frame_offset),
                              *(int *)(&stack0xffffffe4 + frame_offset));
    *(int *)((int)temp_buf + frame_offset) = mul_result;
    cross_result = (*(int(*)())multiply_fn)(**(int **)(&stack0xfffffff0 + frame_offset),
                              *(int *)((int)&cos_component + frame_offset));
    **(int **)((int)temp_buf + frame_offset + 4) = *(int *)((int)temp_buf + frame_offset) - cross_result;
    *(int *)(&stack0x0000001c + corner_idx + frame_offset) =
         *(int *)(&stack0x0000004c + corner_idx + frame_offset);
    /* depth correction: divide to adjust for perspective */
    if (**(int **)(&stack0xffffffe8 + frame_offset) != 0) {
      corner_idx = (unsigned int)(slot_id << 2);
      corner_ptr = (int *)(&stack0x0000002c + corner_idx + frame_offset);
      *(int **)(&stack0xfffffff4 + frame_offset) = corner_ptr;
      *(int **)((int)temp_buf + frame_offset + 4) = corner_ptr;
      *(int *)(&stack0xffffffe8 + frame_offset) = *corner_ptr;
      *(char **)(&stack0xfffffff0 + frame_offset) = &stack0x0000000c + corner_idx + frame_offset;
      cross_result = (*(int(*)())0x0602755C)(*(int *)(&stack0xffffffe8 + frame_offset),  /* fixed_divide */
                         *(int *)(&stack0x0000000c + corner_idx + frame_offset));
      **(int **)((int)temp_buf + frame_offset + 4) = cross_result + *(int *)(&stack0xffffffe8 + frame_offset);
      depth_ptr = (int *)(&stack0x0000001c + corner_idx + frame_offset);
      *(int **)(&stack0xfffffff4 + frame_offset) = depth_ptr;
      cross_result = *depth_ptr;
      *(int *)(&stack0xffffffe8 + frame_offset) = cross_result;
      (*(int(*)())0x0602755C)(cross_result,**(int **)(&stack0xfffffff0 + frame_offset));  /* fixed_divide */
      cross_result = (*(int(*)())0x06034FE0)();              /* get_divide_result */
      *depth_ptr = *(int *)(&stack0xffffffe8 + frame_offset) - cross_result;
    }
    slot_id = slot_id + 1;
  } while (slot_id < 4);
  /* restore original angle at slot+0x2C */
  *(int *)(0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x44) + 0x2c)
       = *(int *)(&stack0xfffffff8 + frame_offset);
  /* pass 3: convert rotated corners to screen coordinates */
  slot_table = (char *)0x06084FC8;                           /* HUD object slot table */
  *(char **)(&stack0xfffffff0 + frame_offset) =
       0x06085490 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[frame_offset] * 0x18) + 8;  /* sprite output table */
  vertex_i = 0;
  slot_id = (&stack0xffffffec)[frame_offset];
  do {
    cross_result = (unsigned int)(vertex_i << 2) + *(int *)(&stack0xfffffff0 + frame_offset);
    *(int *)(&stack0xffffffec + frame_offset) = cross_result;
    *(int *)((int)temp_buf + frame_offset + 4) = cross_result;
    mul_result = *(int *)(slot_table + (short)((unsigned short)slot_id * 0x44) + 0xc);  /* slot depth */
    *(unsigned int *)(&stack0xffffffe8 + frame_offset) = (unsigned int)(vertex_i << 2);
    cross_result = (*(int(*)())multiply_fn)(*(int *)(&stack0x0000002c + (unsigned int)(vertex_i << 2) + frame_offset),mul_result);
    half_width = (*(int(*)())0x0602754C)(*(int *)(slot_table + (short)((unsigned short)slot_id * 0x44) + 4) + cross_result);  /* truncate_to_short: screen X */
    **(short **)((int)temp_buf + frame_offset + 4) = half_width;
    *(int *)((int)temp_buf + frame_offset + 4) = *(int *)(&stack0xffffffec + frame_offset) + 2;
    cross_result = (*(int(*)())multiply_fn)(*(int *)
                               (&stack0x0000001c + *(int *)(&stack0xffffffe8 + frame_offset) + frame_offset),
                              *(int *)(slot_table + (short)((unsigned short)slot_id * 0x44) + 0xc));
    half_width = (*(int(*)())0x0602754C)(*(int *)(slot_table + (short)((unsigned short)slot_id * 0x44) + 8) + cross_result);  /* truncate_to_short: screen Y */
    vertex_i = vertex_i + 1;
    **(short **)((int)temp_buf + frame_offset + 4) = half_width;
  } while (vertex_i < 4);
  return;
}

/* hud_sprite_layer_render -- Render HUD sprite layers for race/results.
 * Active in game states 0x19 (race) and 0x15 (results) when race slot
 * at 0x06084FC8 is valid. Sprite table at 0x06085490, each entry 0x18 bytes.
 * State 0x19 renders 4 extra layers (8 total), state 0x15 renders 4.
 * Each VDP1 command submitted via FUN_060280F8, write pointer at
 * 0x060785FC advances by 0x20, sprite counter at 0x0605A008 increments. */
void FUN_060171ac()
{
    int *vdp_ptr = (int *)0x060785FC;
    int *sprite_count = (int *)0x0605A008;
    char *vdp_submit = (char *)0x060280F8;         /* VDP1 command submit */
    char *sprite_base = (char *)0x06085490;
    int pos;

    if ((GAME_STATE == 0x19 || GAME_STATE == 0x15) &&
       (((int *)0x06084FC8)[1] == '\0' && *(int *)0x06084FC8 != '\0')) {

        if (GAME_STATE == 0x19) {
            /* Full HUD: 4 extra layers */
            (*(int(*)())0x060280F8)(sprite_base + DAT_0601729e, *vdp_ptr);
            *sprite_count = *sprite_count + 1;
            pos = *vdp_ptr;
            *vdp_ptr = pos + 0x20;
            (*(int(*)())vdp_submit)(sprite_base + PTR_DAT_060172a0, pos + 0x20);
            *sprite_count = *sprite_count + 1;
            pos = *vdp_ptr;
            *vdp_ptr = pos + 0x20;
            (*(int(*)())vdp_submit)(sprite_base + 0x78, pos + 0x20);
            *sprite_count = *sprite_count + 1;
            pos = *vdp_ptr;
            *vdp_ptr = pos + 0x20;
            (*(int(*)())vdp_submit)(sprite_base + 0x60, pos + 0x20);
            *sprite_count = *sprite_count + 1;
            *vdp_ptr = *vdp_ptr + 0x20;
        }

        /* Common: 4 bottom sprite layers */
        (*(int(*)())vdp_submit)(sprite_base + 0x48, *vdp_ptr);
        *sprite_count = *sprite_count + 1;
        pos = *vdp_ptr;
        *vdp_ptr = pos + 0x20;
        (*(int(*)())vdp_submit)(sprite_base + 0x30, pos + 0x20);
        *sprite_count = *sprite_count + 1;
        pos = *vdp_ptr;
        *vdp_ptr = pos + 0x20;
        (*(int(*)())vdp_submit)(sprite_base + 0x18, pos + 0x20);
        *sprite_count = *sprite_count + 1;
        pos = *vdp_ptr;
        *vdp_ptr = pos + 0x20;
        (*(int(*)())vdp_submit)(sprite_base, pos + 0x20);
        *sprite_count = *sprite_count + 1;
        *vdp_ptr = *vdp_ptr + 0x20;
    }
}

/* hud_digits_render_all -- Render all 18 HUD digit slots (0x00-0x11).
 * For each slot: compute digit value (FUN_060172e4), then render sprite (FUN_06017330). */
void FUN_060172bc(void)
{
    unsigned char slot;
    for (slot = 0; slot < 0x12; slot++) {
        FUN_060172e4(slot);
        FUN_06017330(slot);
    }
}

/* race_slot_clear -- Zero all fields in a HUD race slot descriptor.
 * Slot array at 0x06084FC8, stride 0x44 bytes per slot.
 * param_1 (low byte): slot index. Clears bytes 0-2,
 * ints at +0x04..+0x38 (14 words), and bytes at +0x40/+0x41. */
void FUN_060172e4(param_1)
    unsigned short param_1;
{
  char *slot = (char *)0x06084FC8 + (short)((param_1 & 0xff) * 0x44);
  slot[2] = 0;
  slot[1] = 0;
  *slot = 0;
  *(int *)(slot + 0x0c) = 0;
  *(int *)(slot + 0x08) = 0;
  *(int *)(slot + 0x04) = 0;
  *(int *)(slot + 0x18) = 0;
  *(int *)(slot + 0x14) = 0;
  *(int *)(slot + 0x10) = 0;
  *(int *)(slot + 0x24) = 0;
  *(int *)(slot + 0x20) = 0;
  *(int *)(slot + 0x1c) = 0;
  *(int *)(slot + 0x30) = 0;
  *(int *)(slot + 0x2c) = 0;
  *(int *)(slot + 0x28) = 0;
  *(int *)(slot + 0x38) = 0;
  *(int *)(slot + 0x34) = 0;
  slot[0x41] = 0;
  slot[0x40] = 0;
  return;
}

/* hud_slot_clear -- Clear a HUD digit display slot.
 * Slot array at 0x06085490, stride 0x18 bytes per slot.
 * param_1 (low byte): slot index.
 * Zeros: counter (+16), display value (+6), active flag (+5),
 * and all 8 digit values (+8 to +22). */
int FUN_06017330(unsigned short param_1)
{
    register char *base asm("r2") = (char *)0x06085490;
    int offset;
    unsigned char i;

    param_1 = param_1 & 0xff;
    offset = (short)(param_1 * 0x18);

    *(int *)(base + offset + 16) = 0;
    *(short *)(base + offset + 6) = 0;
    *(base + offset + 5) = 0;

    i = 0;
    do {
        *(short *)(base + (i << 1) + offset + 8) = 0;
        i++;
    } while (i < 8);

    return 0;
}

/* race_slot_find_by_id -- Find a race slot index matching a car ID.
 * Scans 18 (0x12) slots of stride 0x44 bytes at 0x06084FC8, comparing
 * byte 0 (car ID) to param_1. Returns slot index, or 0x12 if not found. */
unsigned char FUN_06017372(param_1)
    char param_1;
{
    unsigned char slot = 0;
    do {
        if (param_1 == *(char *)((short)((unsigned short)slot * 0x44) + 0x06084FC8)) {
            return slot;
        }
        slot = slot + 1;
    } while (slot < 0x12);
    return slot;
}

/* hud_race_panel_render -- Render the full in-race HUD panel.
 * Draws lap counter, speed display, position display, gear indicator,
 * and timer digits. Uses two layout tables: normal (0x06044B84) and
 * demo mode (0x06044BB4). Converts player speed and AI speed to
 * digit arrays via FUN_06005DD4, clamps speed to 0x927BF max.
 * Gear display dispatches on remainder (1-4) with special case for
 * laps 11-13. Demo mode uses simplified single-line layout. */
int FUN_060173ac()
{
    char *sprite_table = (char *)0x06063750;    /* VDP sprite table base */
    int y_offset = (int)DAT_0601748a;
    short auStack_7c[14];
    short auStack_60[14];
    char auStack_44[4];
    short auStack_40[6];
    short auStack_34[12];

    (*(int(*)())0x06035228)();
    (*(int(*)())0x06035228)();

    /* Select layout table: normal or demo mode */
    short *layout = (short *)0x06044B84;
    if (DEMO_MODE_FLAG != 0) {
        layout = (short *)0x06044BB4;
    }

    /* Render lap counter digits */
    int *lap_data = (int *)(sprite_table + DAT_0601748c);
    FUN_06017784(*lap_data, lap_data[1] + y_offset, *layout, layout[1]);
    FUN_06017784(*(int *)(sprite_table + DAT_0601748e), lap_data[1] + y_offset,
                 layout[3], layout[4]);
    FUN_06017784(*(int *)(sprite_table + DAT_06017490), lap_data[1] + y_offset,
                 layout[9], layout[10]);

    /* Get player speed, clamped to max */
    char *car_base = (char *)0x06078900;
    int ai_speed = *(int *)(0x06078900 + DAT_06017492);
    char *player_speed = *(char **)0x060786A4;
    if ((int)0x000927BF <= (int)*(char **)0x060786A4) {
        player_speed = (char *)0x000927BF;
    }
    if ((*(unsigned int *)0x0607EBF4 & 1) == 0) {
        player_speed = (char *)(GAME_STATE_VAR * 5);
    }

    /* Convert player speed to digit array */
    int digits = (*(int(*)())0x06005DD4)(player_speed);
    unsigned char idx = 0;
    do {
        unsigned int i = (unsigned int)idx;
        auStack_40[idx] = auStack_7c[*(unsigned char *)(i + digits)];
        unsigned int j = (unsigned int)idx;
        idx = idx + 1;
        auStack_34[j + 2] = auStack_60[*(unsigned char *)(i + digits)];
    } while (idx < 8);
    FUN_06017784(auStack_44, *(int *)(sprite_table + DAT_060175b4) + y_offset,
                 layout[6], layout[7]);

    /* Convert AI speed to digit array */
    digits = (*(int(*)())0x06005DD4)(ai_speed);
    idx = 0;
    do {
        unsigned int i = (unsigned int)idx;
        unsigned int k = (unsigned int)idx;
        unsigned int m = (unsigned int)idx;
        idx = idx + 1;
        auStack_40[i] = auStack_7c[*(unsigned char *)(k + digits)];
        auStack_34[m + 2] = auStack_60[*(unsigned char *)(k + digits)];
    } while (idx < 8);
    FUN_06017784(auStack_44, *(int *)(sprite_table + DAT_060175b4) + y_offset,
                 layout[0xc], layout[0xd]);

    /* Gear and position indicators */
    int tens_digit = (*(int(*)())0x06034FE0)(*(int *)(car_base + DAT_060175b6) + 1, 10);
    int ones_digit = (*(int(*)())0x06035C2C)();

    if (DEMO_MODE_FLAG == 0) {
        int gear_y = (int)DAT_06017692;
        int gear_off = 0x348;
        int lap_num = *(int *)(car_base + DAT_06017696) + 1;

        if (lap_num < 0xb || 0xd < lap_num) {
            /* Normal lap range: dispatch on gear digit */
            if (ones_digit == 1) {
                FUN_06017784(*(int *)(sprite_table + gear_off),
                             *(int *)((int)(sprite_table + gear_off) + 4) + gear_y,
                             layout[0x15], layout[0x16]);
            } else if (ones_digit == 2) {
                FUN_06017784(*(int *)(sprite_table + DAT_06017698),
                             *(int *)(sprite_table + gear_off + 4) + gear_y,
                             layout[0x15], layout[0x16]);
            } else if (ones_digit == 3) {
                FUN_06017784(*(int *)(sprite_table + DAT_0601769a),
                             *(int *)(sprite_table + gear_off + 4) + gear_y,
                             layout[0x15], layout[0x16]);
            } else {
                FUN_06017784(*(int *)(sprite_table + DAT_0601769c),
                             *(int *)(sprite_table + gear_off + 4) + gear_y,
                             layout[0x15], layout[0x16]);
            }
        } else {
            /* Special lap range (11-13): alternate gear sprite */
            FUN_06017784(*(int *)(sprite_table + DAT_06017728),
                         *(int *)(sprite_table + gear_off + 4) + gear_y,
                         layout[0x15], layout[0x16]);
        }

        /* Tens digit display (if non-zero) */
        if (tens_digit != 0) {
            FUN_06017784(*(int *)(sprite_table + ((tens_digit + 0x5f) << 3)),
                         *(int *)(sprite_table + DAT_0601772a) + (int)DAT_0601772c,
                         layout[0xf], layout[0x10]);
        }

        /* Ones digit display */
        ai_speed = FUN_06017784(*(int *)(sprite_table + ((ones_digit + 0x5f) << 3)),
                                *(int *)(sprite_table + DAT_0601772a) + (int)DAT_0601772c,
                                layout[0x12], layout[0x13]);
    } else {
        /* Demo mode: simplified display */
        ai_speed = FUN_06017784(*(int *)(sprite_table + DAT_060175b8),
                                *(int *)((int)(sprite_table + DAT_060175b8) + 4) + (int)DAT_060175ba,
                                layout[0xf], layout[0x10]);
    }
    return ai_speed;
}

/* tilemap_row_fill -- Fill remaining tilemap rows with VDP2 tile data.
 * Starting from param_1, writes (0x2C - param_1) rows to VDP2 via
 * tilemap writer at 0x06028400. Each row is 0x36 bytes in the source
 * table at 0x06085640. Tile offset starts at (param_1 + 0x40) * 2. */
void FUN_0601772e(param_1)
    int param_1;
{
    char *tile_src  = (char *)0x06085640;       /* tilemap source data */
    char *tile_write = (char *)0x06028400;      /* vdp2_tilemap_write */
    unsigned int remaining = 0x2cU - param_1 & 0xff;
    unsigned char idx = 0;

    if (remaining != 0) {
        do {
            (*(int(*)())tile_write)(0xc, tile_src + (short)((unsigned short)idx * 0x36),
                                    (param_1 + 0x40) << 1, 0);
            idx = idx + 1;
            param_1 = param_1 + 1;
        } while (idx < remaining);
    }
}

/* tilemap_block_fill -- Fill a rectangular region in the VDP2 tilemap.
 * Reads width/height from param_1[0]/param_1[1], tile data from param_1[2+].
 * Writes to tilemap buffer at 0x06085640, each row stride 0x36 tiles.
 * param_2 = tile ID offset, param_3 = start column, param_4 = start row.
 * Nested loop copies width*height tiles with row/column indexing. */
int FUN_06017784(param_1, param_2, param_3, param_4)
    unsigned short *param_1;
    short param_2;
    unsigned short param_3;
    int param_4;
{
    char *tilemap = (char *)0x06085640;
    unsigned short width = *param_1;
    unsigned short height = param_1[1];
    unsigned int row = param_4 + 2;
    unsigned short y;

    for (y = 0; y < height; y = y + 1) {
        unsigned short x = 0;
        if (width != 0) {
            do {
                unsigned int col = (unsigned int)x;
                x = x + 1;
                *(unsigned short *)(tilemap + (((row & 0xff) << 1) +
                    (int)(short)((param_3 & 0xff) * 0x36))) =
                    param_1[(unsigned int)y * (unsigned int)width + col + 2] + param_2;
                param_3 = param_3 + 1;
            } while (x < width);
        }
        param_3 = param_3 - width;                 /* reset column for next row */
        row = row + 1;
    }

    return 0;
}

void track_geometry_processor()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int in_r7 = 0;

  char *puVar8;

  char *puVar9;

  puVar7 = (int *)0x0605BE20;

  puVar6 = (char *)0x0605BE22;

  puVar5 = (char *)0x0605BE26;

  puVar4 = (char *)0x0605BE1A;

  puVar3 = (char *)0x0605BE24;

  puVar2 = (char *)0x0605BE18;

  (*(int(*)())0x06026DBC)();

  *(int *)0x06085FAC = *(int *)0x06085FAC - 0x333;

  (*(int(*)())0x06026E2E)(*(int *)0x06048128,*(int *)0x0604812C,

             -*(int *)0x06048130);

  (*(int(*)())0x06026EDE)(*(int *)0x06085FAC);

  puVar8 = (char *)0x00200000;

  (*(int(*)())0x06031D8C)(0x00200000 + (int)0x00037D88,8);

  (*(int(*)())0x06031A28)(puVar8 + (int)0x00037DE8,(int)*(short *)0x06089E98,6,in_r7,

             puVar8 + (int)0x00037DE8);

  (*(int(*)())0x06026DF8)();

  (*(int(*)())0x06026DBC)();

  if (*(short *)puVar2 == 10) {

    *(short *)puVar2 = 0;

    *(int *)0x06085FBC = *(int *)0x06085FBC - (int)DAT_060178ac;

  }

  else {

    *(int *)0x06085FBC = *(int *)0x06085FBC + 0x333;

  }

  (*(int(*)())0x06026E2E)(*(int *)0x06048134,*(int *)0x06048138,

             -*(int *)0x0604813C);

  (*(int(*)())0x06026F2A)(*(int *)0x06085FBC);

  puVar9 = (char *)0x00200000;

  (*(int(*)())0x06031D8C)(0x00200000 + (int)0x00037E78,4);

  (*(int(*)())0x06031A28)(puVar9 + (int)0x00037EA8,(int)*(short *)0x06089E98,1);

  (*(int(*)())0x06026DF8)();

  puVar8 = (char *)0x06026DBC;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  (*(int(*)())puVar8)();

  (*(int(*)())0x06031D8C)(puVar9 + (int)0x00037EC0,4);

  (*(int(*)())0x06031A28)(puVar9 + (int)0x00037EF0,

             (int)*(short *)(0x06089E44 + (((int)(*(unsigned short *)puVar2 & 4) >> 2) + 0x2a) << 1),1)

  ;

  (*(int(*)())0x06026DF8)();

  if (*(unsigned int *)(CAR_PTR_CURRENT + (int)PTR_DAT_060179b8) <

      *(int *)0x06063F28 - 1U) {

    if (*(int *)0x06078636 == '\0') {

      *(short *)puVar4 = 1;

    }

    else {

      *(short *)puVar4 = 0;

    }

  }

  else {

    *(short *)puVar4 = 2;

  }

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06031D8C)(*(int *)(0x06062290 + (unsigned int)*(unsigned short *)((int)(int)puVar4 << 2)),

             *(int *)(0x060622B4 + (unsigned int)*(unsigned short *)((int)(int)puVar4 << 2)));

  (*(int(*)())0x06031A28)(*(int *)(0x0606229C + (unsigned int)*(unsigned short *)((int)(int)puVar4 << 2)),

             (int)*(short *)0x06089E98,

             *(int *)(0x060622A8 + (unsigned int)*(unsigned short *)((int)(int)puVar4 << 2)));

  (*(int(*)())0x06026DF8)();

  puVar2 = (char *)0x0605BE2A;

  if ((*(int *)0x0607EAD0 == 0) && ((GAME_STATE_BIT & (unsigned int)0x000A0000) != 0)

     ) {

    if ((*(unsigned short *)0x06063D98 & 0x40) == 0) {

      *(short *)0x0605BE2A = 0;

    }

    else if (*(short *)0x0605BE2A == 0) {

      *(short *)0x0605BE2A = 1;

      *(short *)puVar5 = *(short *)puVar5 + 1;

      *(unsigned short *)puVar5 = *(unsigned short *)puVar5 & 3;

    }

  }

  else {

    *(short *)0x0605BE28 = 0;

    *(short *)puVar5 = 0;

    *(short *)puVar2 = 0;

  }

  sVar1 = *(short *)puVar5;

  if (sVar1 == 0) {

    *(short *)puVar3 = *(short *)puVar3 + -1;

    *(short *)puVar6 = *(short *)puVar6 + -2;

  }

  else {

    if (sVar1 == 1) {

      FUN_06017c9c(0x0605BE24);

      *(short *)puVar6 = *(short *)puVar6 + -2;

      *(short *)puVar7 = *(short *)puVar7 + -3;

      goto LAB_06017b4e;

    }

    if (sVar1 != 2) {

      if ((sVar1 == 3) && (FUN_06017c9c(0x0605BE20), *(short *)0x0605BE28 == 0)) {

        FUN_06017bf4();

      }

      goto LAB_06017b4e;

    }

    FUN_06017c9c(0x0605BE22);

    if (*(int *)0x06085FCC == '\0') {

      FUN_06017c78();

    }

  }

  *(short *)puVar7 = *(short *)puVar7 + -3;

LAB_06017b4e:

  if (*(short *)puVar3 < 1) {

    *(short *)puVar3 = (char *)0x30;

  }

  if (*(short *)puVar7 < 1) {

    *(short *)puVar7 = (int *)0x30;

  }

  if (*(short *)puVar6 < 1) {

    *(short *)puVar6 = (char *)0x30;

  }

  puVar5 = (char *)0x06063F64;

  puVar4 = (char *)0x060684EC;

  puVar2 = (char *)0x0606A4F0;

  *(int *)(0x06063F64 + (unsigned int)*(unsigned short *)(0x060684EC + DAT_06017bd4) << 3) =

       *(short *)puVar3 * 3 + *(int *)0x0606A4F0;

  *(int *)(puVar5 + ((unsigned int)*(unsigned short *)(puVar4 + DAT_06017bd6) << 3)) =

       *(short *)puVar6 * 3 + *(int *)puVar2;

  *(int *)(puVar5 + ((unsigned int)*(unsigned short *)(puVar4 + DAT_06017bd8) << 3)) =

       *(short *)puVar7 * 3 + *(int *)puVar2;

  return;

}

/* race_bonus_check -- Check if all 3 lap positions match for bonus award.
 * Only active in 2-player VS mode (0x0607EBC4 == 0x20000). If all 3
 * position trackers at 0x0605BE20/22/24 agree: awards bonus points to
 * score at 0x0607EAAC. Position 0x2A awards DAT_06017c52 bonus,
 * position 0x12 awards 100 points. Sets completion flag and plays sound. */
void FUN_06017bf4()
{
    if (*(char **)0x0607EBC4 != 0x00020000) {
        return;
    }
    if ((*(short *)0x0605BE24 == *(short *)0x0605BE22) &&
        (*(short *)0x0605BE24 == *(short *)0x0605BE20)) {
        if (*(short *)0x0605BE24 == 0x2a) {
            *(int *)0x0607EAAC = *(int *)0x0607EAAC + (int)DAT_06017c52;
            *(short *)0x0605BE28 = 1;
            (*(int(*)())0x0601D5F4)(0, 0xAE1117FF);
            return;
        }
        if (*(short *)0x0605BE24 == 0x12) {
            *(int *)0x0607EAAC = *(int *)0x0607EAAC + 100;
            *(short *)0x0605BE28 = 1;
            (*(int(*)())0x0601D5F4)(0, 0xAE1117FF);
            return;
        }
    }
}

/* check_race_complete_sound -- If both race positions match and equal 42 (0x2A),
 * set completion flag and play race-complete sound effect. */
extern void sound_cmd_dispatch(int channel, int command);

/* time_limit_warning -- Trigger time limit warning sound.
 * When both timer values at 0x0605BE24 and 0x0605BE22 equal 0x2A (42),
 * sets warning flag at 0x06085FCC and plays sound 0xAE1118FF. */
void FUN_06017c78(void)
{
    if (*(short *)0x0605BE24 == *(short *)0x0605BE22 &&
        *(short *)0x0605BE24 == 0x2A) {
        *(char *)0x06085FCC = 1;                   /* warning active flag */
        sound_cmd_dispatch(0, 0xAE1118FF);         /* time warning sound */
    }
}

/* division_adjust -- Adjust a value by hardware division result.
 * Calls division unit read (0x06035C2C), subtracts low 16 bits from *param_1.
 * If result >= 4, adds wrap correction of +6 (for base-10 digit carry). */
unsigned int FUN_06017c9c(short *param_1)
{
    unsigned int div_result = (*(int(*)())0x06035C2C)();

    if ((div_result & 0xffff) < 4) {
        *param_1 = *param_1 - (short)div_result;
    } else {
        *param_1 = (*param_1 - (short)div_result) + 6;
    }
    return div_result;
}

/* track_scenery_sprite_animate -- animate roadside scenery sprites and render track-side 3D objects */
void FUN_06017cec()
{
  unsigned short sprite_id;
  char *model_base;
  char *sprite_table;
  char *scenery_state;
  char *vdp1_base;
  char *tree_reset_pos;
  short priority_val;
  int base_pos;
  int tree_table_offset;
  int car_checkpoint;
  int scenery_table_offset;
  int *rotation_entry;
  unsigned int obj_index;
  unsigned int obj_next;

  vdp1_base = (char *)0x06063F64;       /* VDP1 sprite command table */
  sprite_table = (char *)0x060684EC;     /* scenery sprite index table */
  scenery_state = (char *)0x0605BE10;    /* scenery animation state (X/Z rotation) */
  model_base = (char *)0x00088734;       /* model data base offset */
  car_checkpoint = CAR_PTR_TARGET;
  base_pos = *(int *)0x06089E28;         /* road marker base position */

  /* Increment animation frame counters */
  *(short *)0x0605BE2C = *(short *)0x0605BE2C + 1; /* marker_frame */
  *(short *)0x0605BE2E = *(short *)0x0605BE2E + 1; /* tree_frame */

  /* Set road marker priority based on car position vs track segment count */
  if (*(unsigned int *)(car_checkpoint + DAT_06017d92) < *(int *)0x06063F28 - 1U) {
    sprite_id = *(unsigned short *)(sprite_table + DAT_06017d94);
    priority_val = DAT_06017d98; /* normal priority */
  }
  else {
    base_pos = *(int *)0x06089E2C; /* alternate base for last segment */
    sprite_id = *(unsigned short *)(sprite_table + DAT_06017d94);
    priority_val = DAT_06017d96;  /* end-of-track priority */
  }
  *(short *)(vdp1_base + (unsigned int)(sprite_id << 3) + 6) = priority_val;

  /* Road marker animation: advance by 0x90 per frame, reset every 6 frames */
  scenery_table_offset = (int)DAT_06017d9a;
  if (*(short *)0x0605BE2C < 6) {
    car_checkpoint = 0x90;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + DAT_06017d94) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + DAT_06017d94) << 3)) + car_checkpoint;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) + car_checkpoint;
  }
  else {
    /* Reset marker positions from base values */
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + DAT_06017ea6) << 3)) = base_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) =
         *(int *)0x06089E30;
    *(short *)0x0605BE2C = 0;
  }

  /* Tree/scenery sprite animation: reset positions every 4 frames, scroll by 0x40 otherwise */
  tree_reset_pos = (char *)0x06089E34;
  scenery_table_offset = (int)DAT_06017ea8;
  if ((*(unsigned short *)0x0605BE2E & 3) == 0) {
    /* Every 4 frames: snap tree sprites to base positions */
    car_checkpoint = (int)DAT_06017eaa;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint) << 3)) =
         *(int *)0x06089E34;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x18) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x2a) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x3a) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x4a) << 3)) = *(int *)tree_reset_pos;
    tree_reset_pos = (char *)0x06089E38;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset + -8) << 3)) =
         *(int *)0x06089E38;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x20) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x32) << 3)) = *(int *)tree_reset_pos;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x42) << 3)) = *(int *)tree_reset_pos;
  }
  else {
    /* Intermediate frames: scroll all scenery sprites by 0x40 */
    car_checkpoint = (int)DAT_06017fdc;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset + -8) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset + -8) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + scenery_table_offset) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x18) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x18) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x20) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x20) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x2a) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x2a) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x32) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x32) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x3a) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x3a) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x42) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x42) << 3)) + 0x40;
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x4a) << 3)) =
         *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + car_checkpoint + 0x4a) << 3)) + 0x40;
  }

  /* Checkpoint blinking indicator: toggles every 16 frames */
  if ((*(unsigned short *)0x0605BE2E & 0x10) == 0) {
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + DAT_06017fde) << 3)) =
         *(int *)0x06089E40;
  }
  else {
    *(int *)(vdp1_base + ((unsigned int)*(unsigned short *)(sprite_table + DAT_06017fde) << 3)) =
         *(int *)0x06089E40 + 0x100; /* blink offset */
  }

  /* Track zone flags based on car checkpoint position */
  car_checkpoint = *(int *)(CAR_PTR_TARGET + DAT_06017fe2);
  if ((car_checkpoint < DAT_06017fe4) || (DAT_06017fe6 < car_checkpoint)) {
    *(short *)0x0605BE36 = 0; /* not in zone A */
  }
  else {
    *(short *)0x0605BE36 = 1; /* in zone A */
  }
  if ((car_checkpoint < 0x4b) || (0x57 < car_checkpoint)) {
    *(short *)0x0605BE38 = 0; /* not in zone B */
  }
  else {
    *(short *)0x0605BE38 = 4; /* in zone B */
  }

  /* Render 3D roadside objects (trees/signs) if in special track zone */
  if ((DAT_060180fc <= car_checkpoint) && (car_checkpoint <= DAT_060180fe)) {
    /* Advance rotation angles */
    *(int *)scenery_state = *(int *)scenery_state + 0x333;        /* X rotation step */
    *(int *)(scenery_state + 4) = *(int *)(scenery_state + 4) + (int)DAT_06018102; /* Z rotation step */

    sprite_table = (char *)0x06089E98; /* tree sprite ID table */
    obj_index = 0;
    do {
      /* Render object A (even index) */
      (*(int(*)())0x06026DBC)();  /* matrix_identity */
      rotation_entry = (int *)(0x06048078 + ((obj_index & 0xff) * 0xc & 0xff));
      (*(int(*)())0x06026E2E)(*rotation_entry,rotation_entry[1],-rotation_entry[2]); /* matrix_set_rotation */
      (*(int(*)())0x06026EDE)(0x0000C000); /* matrix_set_scale */
      (*(int(*)())0x06026F2A)(*(int *)scenery_state + (obj_index & 3) * (int)DAT_06018104); /* matrix_set_position */
      vdp1_base = (char *)0x00200000;
      (*(int(*)())0x06031D8C)(0x00200000 + (int)model_base,0xc); /* render_model */
      (*(int(*)())0x06031A28)(vdp1_base + (int)0x000887C4,(int)*(short *)sprite_table,3); /* render_texture */
      (*(int(*)())0x06026DF8)(); /* matrix_flush */

      /* Render object B (odd index) */
      obj_next = obj_index + 1;
      (*(int(*)())0x06026DBC)();
      rotation_entry = (int *)(0x06048078 + ((obj_next & 0xff) * 0xc & 0xff));
      (*(int(*)())0x06026E2E)(*rotation_entry,rotation_entry[1],-rotation_entry[2]);
      (*(int(*)())0x06026EDE)(0x0000C000);
      (*(int(*)())0x06026F2A)(*(int *)(scenery_state + ((obj_next & 1) << 2)) + (obj_next & 3) * (int)DAT_06018104);
      (*(int(*)())0x06031D8C)(vdp1_base + (int)model_base,0xc);
      (*(int(*)())0x06031A28)(vdp1_base + (int)0x000887C4,(int)*(short *)sprite_table,3);
      (*(int(*)())0x06026DF8)();

      obj_index = obj_index + 2;
    } while ((int)obj_index < 0xe); /* 7 pairs = 14 objects */
  }

  (*(int(*)())0x06021178)(); /* track_zone_sprite_swap */
  track_calculation();

  return;
}
