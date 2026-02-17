#include "game.h"

extern int DAT_0602014a;
extern int DAT_0602014c;
extern int DAT_060203be;
extern int DAT_060204a8;
extern int DAT_06020db2;
extern int DAT_06020f2e;
extern int DAT_06020f30;
extern int DAT_06020fc6;
extern int DAT_06020fc8;
extern int DAT_06020fca;
extern int DAT_06021098;
extern int DAT_0602109a;
extern int DAT_0602109c;
extern int DAT_0602109e;
extern int DAT_060212d4;
extern int DAT_060212d6;
extern int DAT_060212d8;
extern int DAT_060212da;
extern int DAT_06021414;
extern int DAT_06021416;
extern int DAT_06021418;
extern int DAT_0602141a;
extern int DAT_06021520;
extern int DAT_06021522;
extern int DAT_06021524;
extern int DAT_06021526;
extern int DAT_060218de;
extern int DAT_060218e0;
extern int DAT_060218e2;
extern int DAT_06021c2e;
extern int DAT_06021c32;
extern int DAT_06021e98;
extern int DAT_06021e9a;
extern int DAT_06021fe0;
extern int DAT_06022114;
extern int DAT_06022116;
extern int DAT_06022118;
extern int object_destruction(char, unsigned int, unsigned int, int);
extern int FUN_06020946();
extern int FUN_06020dd0();
extern int PTR_DAT_060211d8;
extern int PTR_DAT_060212dc;
extern int PTR_DAT_06021528;
extern short PTR_DAT_06020b48;
extern void FUN_06020b20();

/* vdp2_render_init -- Initialize VDP2 rendering: load color tables, set up DMA,
 * configure scroll plane, clear SCU interrupt masks, init text rendering state.
 * Copies VDP2 color RAM (0x25F006C0, 0x25F00060), loads 4 tile pattern sets
 * via DMA (0x0600511E), configures sprite layer, clears render counters. */
#if 0 /* FUN_060200A4 -- replaced by ASM import */
void FUN_060200a4(void)
{
    (*(int(*)())0x0602761E)(0x25F006C0, 0x0604896C, 0x20);  /* color RAM bank 1 */
    (*(int(*)())0x0602761E)(0x25F00060, 0x0604BC14, 0x20);  /* color RAM bank 2 */

    (*(int(*)())0x0600511E)(0x25E33AD8, 0x00017700, 0, 8);  /* tile pattern 1 */
    (*(int(*)())0x0600511E)(0x25E33764, 0x00018B40, 0, 8);  /* tile pattern 2 */
    (*(int(*)())0x0600511E)(0x0605E164, 0x0001D2A0, 0, 8);  /* tile pattern 3 */
    (*(int(*)())0x0600511E)(0x25E3398C, 0x00018F20, 0, 8);  /* tile pattern 4 */

    (*(int(*)())0x06028400)(0xc, *(int *)0x06063CA0, (int)DAT_0602014c,
               *(int *)(0x06063CA0 + 4) + (int)DAT_0602014a, 0x06063CA0);

    (*(int(*)())0x06014884)(0x20, 0);   /* clear SCU interrupt mask 0x20 */
    (*(int(*)())0x06014884)(8, 0);      /* clear SCU interrupt mask 0x08 */

    FUN_06020dd0();   /* extended render init */

    /* Clear text rendering state */
    *(short *)0x0608780A = 0;
    *(short *)0x06087808 = 0;
    *(int *)0x06087814 = 0;
    *(short *)0x06087806 = 0;

    (*(int(*)())0x0601D5F4)(0, 0xAB1128FF);   /* palette init */

    *(int *)0x06087826 = 0;
    *(int *)0x06087824 = 0;
    *(int *)0x06087825 = 0xf;   /* default text attribute */
}
#endif

/* FUN_060200A4 -- original binary (276 bytes) */
__asm__(
    ".section .text.FUN_060200A4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060200A4\n"
    ".global _FUN_060200a4\n"
    ".type _FUN_060200A4, @function\n"
    "_FUN_060200A4:\n"
    "_FUN_060200a4:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x7F, 0xFC, 0xD5, 0x29, 0xD4, 0x29, 0xD3, 0x2A, 0x43, 0x0B, 0xE6, 0x20\n"  /* 0x060200A4 */
    ".byte 0xD5, 0x29, 0xD4, 0x2A, 0xD3, 0x27, 0x43, 0x0B, 0xE6, 0x20, 0xE7, 0x08, 0xD5, 0x29, 0xDE, 0x28\n"  /* 0x060200B4 */
    ".byte 0xD4, 0x29, 0x4E, 0x0B, 0xE6, 0x00, 0xE7, 0x08, 0xD5, 0x28, 0xD4, 0x29, 0x4E, 0x0B, 0xE6, 0x00\n"  /* 0x060200C4 */
    ".byte 0xE7, 0x08, 0xD5, 0x28, 0xD4, 0x28, 0x4E, 0x0B, 0xE6, 0x00, 0xE7, 0x08, 0xD5, 0x27, 0xD4, 0x28\n"  /* 0x060200D4 */
    ".byte 0x4E, 0x0B, 0xE6, 0x00, 0xD2, 0x27, 0x2F, 0x22, 0x67, 0x23, 0x65, 0x23, 0x93, 0x2B, 0x96, 0x2B\n"  /* 0x060200E4 */
    ".byte 0x57, 0x71, 0x65, 0x52, 0x37, 0x3C, 0xD3, 0x24, 0x43, 0x0B, 0xE4, 0x0C, 0xE6, 0x00, 0xD3, 0x23\n"  /* 0x060200F4 */
    ".byte 0x65, 0x63, 0x43, 0x0B, 0xE4, 0x20, 0xE6, 0x00, 0xD3, 0x20, 0x65, 0x63, 0x43, 0x0B, 0xE4, 0x08\n"  /* 0x06020104 */
    ".byte 0xB6, 0x5C, 0x00, 0x09, 0xE2, 0x00, 0xD3, 0x1E, 0x23, 0x21, 0xD3, 0x1E, 0x23, 0x21, 0xD3, 0x1E\n"  /* 0x06020114 */
    ".byte 0x23, 0x22, 0xD3, 0x1E, 0x23, 0x21, 0xD5, 0x1E, 0xD3, 0x1E, 0x43, 0x0B, 0x64, 0x23, 0xE2, 0x00\n"  /* 0x06020124 */
    ".byte 0xD3, 0x1D, 0x23, 0x20, 0xD3, 0x1D, 0x23, 0x20, 0xE2, 0x0F, 0xD3, 0x1D, 0x23, 0x20, 0x7F, 0x04\n"  /* 0x06020134 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x60, 0x00, 0x0A, 0x02, 0xFF, 0xFF, 0x06, 0x04, 0x89, 0x6C\n"  /* 0x06020144 */
    ".byte 0x25, 0xF0, 0x06, 0xC0, 0x06, 0x02, 0x76, 0x1E, 0x06, 0x04, 0xBC, 0x14, 0x25, 0xF0, 0x00, 0x60\n"  /* 0x06020154 */
    ".byte 0x06, 0x00, 0x51, 0x1E, 0x00, 0x01, 0x77, 0x00, 0x25, 0xE3, 0x3A, 0xD8, 0x00, 0x01, 0x8B, 0x40\n"  /* 0x06020164 */
    ".byte 0x25, 0xE3, 0x37, 0x64, 0x00, 0x01, 0xD2, 0xA0, 0x06, 0x05, 0xE1, 0x64, 0x00, 0x01, 0x8F, 0x20\n"  /* 0x06020174 */
    ".byte 0x25, 0xE3, 0x39, 0x8C, 0x06, 0x06, 0x3C, 0xA0, 0x06, 0x02, 0x84, 0x00, 0x06, 0x01, 0x48, 0x84\n"  /* 0x06020184 */
    ".byte 0x06, 0x08, 0x78, 0x0A, 0x06, 0x08, 0x78, 0x08, 0x06, 0x08, 0x78, 0x14, 0x06, 0x08, 0x78, 0x06\n"  /* 0x06020194 */
    ".byte 0xAB, 0x11, 0x28, 0xFF, 0x06, 0x01, 0xD5, 0xF4, 0x06, 0x08, 0x78, 0x26, 0x06, 0x08, 0x78, 0x24\n"  /* 0x060201A4 */
    ".byte 0x06, 0x08, 0x78, 0x25\n"  /* 0x060201B4 */
);


/* object_creation -- Create a multi-part text/sprite object from template table.
 * param_1 = object index (low byte). Looks up template chain at 0x0605F458.
 * Each template entry has: [char_count, row, font_bank]. First part uses
 * font pointer from 0x0605F478, subsequent parts use font table at 0x0604BD72.
 * Chain terminates when sentinel value DAT_060203be is encountered. */
#if 0 /* object_creation -- redirected to ASM import via linker PROVIDE */
int object_creation(unsigned int param_1)
{
    unsigned short sentinel = DAT_060203be;
    unsigned char *tmpl = *(unsigned char **)(0x0605F458 + (param_1 & 0xff) << 2);

    int result = object_destruction(
        **(short **)(0x0605F478 + (unsigned int)tmpl[2] * 4),
        *tmpl, tmpl[1],
        *(short **)(0x0605F478 + (unsigned int)tmpl[2] * 4) + 2);

    unsigned char *next;
    while (next = tmpl + 3, *next != sentinel) {
        result = object_destruction(
            *(short *)(0x0604BD72 + (unsigned int)tmpl[5] * 0x2a),
            *next, tmpl[4],
            (short *)((int)(0x0604BD72 + (unsigned int)tmpl[5] * 0x2a) + 4));
        tmpl = next;
    }

    return result;
}
#endif /* object_creation */
/* REMOVED: conflicting alias */ // void FUN_06020366(void) __attribute__((alias("object_creation")));

/* object_destruction -- Render a text string to VDP2 scroll plane.
 * param_1 = character count, param_2 = X column, param_3 = Y row,
 * param_4 = character data pointer (16-bit per char).
 * For each character: space (0x20) maps to tile 0/0, others map to
 * (ascii - 0x40) * 2 tile pair. Writes via VDP2 command (0x06028400)
 * at cell position computed from (X + Y*64) * 2. */
#if 0 /* object_destruction -- redirected to ASM import via linker PROVIDE */
int object_destruction(char param_1, unsigned int param_2, unsigned int param_3, int param_4)
{
    char *cmd_buf = (char *)0x0605F44E;
    short *tile_a = (short *)(0x0605F44E + 4);
    short *tile_b = (short *)(0x0605F44E + 6);
    unsigned int idx = 0;

    if ('\0' < param_1) {
        do {
            unsigned short ch = *(unsigned short *)(param_4 + (idx & 0xff) << 1);
            if ((char)ch == ' ') {
                *tile_a = 0;
                *tile_b = 0;
            } else {
                short tile = ((ch & 0xff) - 0x40) << 1;
                *tile_a = tile;
                *tile_b = tile + 1;
            }
            (*(int(*)())0x06028400)(8, cmd_buf,
                ((param_2 & 0xffff) + (param_3 & 0xffff) << 6) << 1, 0x3c79);
            idx++;
            param_2++;
        } while ((int)(idx & 0xff) < (int)param_1);
    }
    return 0;
}
#endif /* object_destruction */
/* REMOVED: conflicting alias */ // void FUN_06020414(void) __attribute__((alias("object_destruction")));


/* vdp1_display_mode_dispatch -- Select VDP1 display mode based on 0x0608780C.
 * Calls CD sector read (0x06035228) twice, then dispatches:
 * Mode 1: 0xC060 display, batch DMA, render via 0x06038044
 * Mode 2: 0xC044 display, batch DMA, render via 0x06038044
 * Mode 3: extended render (FUN_06020946)
 * Mode 4: VDP render clear slot 4 (0x0602853E)
 * Clears mode register after dispatch. */
unsigned int FUN_06020c3c(void)
{
    register int func asm("r3") = 0x06035228;
    char auStack_24[16];
    char auStack_14[20];

    (*(int(*)())func)();   /* CD sector read 1 */
    (*(int(*)())func)();   /* CD sector read 2 */

    unsigned int mode = *(unsigned short *)0x0608780C;

    if (mode == 1) {
        *(short *)0x060A3DBA = (short)0xC060;
        *(short *)0x060A3DA8 = 0xf;
        VDP1_BATCH_FLAG = 1;
        mode = (*(int(*)())0x06038044)(auStack_14);
    } else if (mode == 2) {
        *(short *)0x060A3DBA = (short)0xC044;
        *(short *)0x060A3DA8 = 0xf;
        VDP1_BATCH_FLAG = 1;
        mode = (*(int(*)())0x06038044)(auStack_24);
    } else if (mode == 3) {
        mode = FUN_06020946();
    } else if (mode == 4) {
        mode = (*(int(*)())0x0602853E)(4);
    }

    *(short *)0x0608780C = 0;
    return mode;
}

/* vdp1_cmd_emit_clear_poly -- Emit a VDP1 clear polygon command.
 * Fills 8 vertex coordinates (shorts at +8..+0x16) with DAT_06020db2
 * (typically screen bounds for a full-screen clear polygon).
 * Sets command link=0x17, draw mode=0x003A (transparent clear).
 * Submits via 0x060280F8, advances VDP1 command pointer by 0x20. */
#if 0 /* FUN_06020CF4 -- replaced by ASM import */
void FUN_06020cf4(void)
{
  char *cmd = (char *)0x06087C6C;       /* VDP1 command scratch buffer */
  short clear_val = DAT_06020db2;

  *(short *)(cmd + 8) = clear_val;       /* vertex coords */
  *(short *)(cmd + 10) = clear_val;
  *(short *)(cmd + 0xc) = clear_val;
  *(short *)(cmd + 0xe) = clear_val;
  *(short *)(cmd + 0x10) = clear_val;
  *(short *)(cmd + 0x12) = clear_val;
  *(short *)(cmd + 0x14) = clear_val;
  *(short *)(cmd + 0x16) = clear_val;
  *(short *)(cmd + 6) = 0x17;           /* link pointer */
  cmd[4] = 0;                            /* draw mode high */
  cmd[5] = 0x3a;                         /* draw mode low */

  (*(int(*)())0x060280F8)(cmd, *(int *)0x060785FC);
  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + 1;
  *(int *)0x060785FC = *(int *)0x060785FC + 0x20;
}
#endif

/* render_slot_dispatch -- Iterate 16 render slots and dispatch active ones.
 * Calls CD sync (0x06035168), then loops slots 0-15 in the render table
 * at 0x0608782C (stride 0x44). If slot type byte is non-zero, dispatches
 * to the handler at auStack_38[type-1] passing the slot index. */
#if 0 /* FUN_06020D46 -- replaced by ASM import */
void FUN_06020d46(void)
{
  char *slot_table = (char *)0x0608782C;
  unsigned int i;
  int auStack_38[10];

  (*(int(*)())0x06035168)();              /* CD sync */
  i = 0;
  do {
    if (slot_table[(short)(((unsigned short)i & 0xff) * 0x44)] != '\0') {
      (*(int(*)())auStack_38[(unsigned char)slot_table[(short)(((unsigned short)i & 0xff) * 0x44)] - 1])(i);
    }
    i = i + 1;
  } while ((i & 0xff) < 0x10);
}
#endif

/* road_surface_scroll_update -- Update road surface sprite and scroll offsets.
 * Part 1: On surface state change, swaps road sprite based on surface flags
 * (0x00=normal, 0x44=left variant, 0x88=right variant, special).
 * Part 2: Computes road scroll offsets from car speed (+0x60 >> 14),
 * fills 22 entries in forward/reverse scroll arrays, applies to VDP2. */
#if 0 /* FUN_06020E74 -- replaced by ASM import */
int FUN_06020e74()
{
  char *transition_trigger; /* 0x06089595 */
  char *scroll_data;        /* 0x06087C84 */
  char *mirror_flag;        /* 0x06078663 */
  char *cooldown_timer;     /* 0x06089594 */
  unsigned int surface_bits;
  unsigned char scroll_idx;
  int sprite_slot_a;
  int sprite_slot_b;
  int scroll_speed;
  int scroll_base;
  int scroll_fwd;
  int scroll_rev;
  transition_trigger = (char *)0x06089595;
  scroll_data = (char *)0x06087C84;
  mirror_flag = (char *)0x06078663;
  cooldown_timer = (char *)0x06089594;
  /* Handle transition trigger: reset cooldown to 10 frames */
  if (*(int *)0x06089595 != '\0') {
    *(int *)0x06089594 = 10;
    *transition_trigger = 0;
  }
  if (*cooldown_timer != '\0') {
    *cooldown_timer = *cooldown_timer + -1;
  }
  /* Part 1: Swap road surface sprite on state change */
  if ((*(int *)(CAR_PTR_TARGET + (int)DAT_06020f2e) != *(int *)0x06089598) &&
     (*(int *)0x06083255 == '\0')) {
    scroll_speed = 0x900;
    surface_bits = *(unsigned int *)((int)DAT_06020f2e + CAR_PTR_TARGET) & 0xcc;
    if (surface_bits == 0) {
      /* Normal road surface */
      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x48),scroll_speed,
                 *(int *)(0x06063750 + 0x4c));
    }
    else if (surface_bits == 0x44) {
      /* Left-side surface variant */
      if (*mirror_flag == '\0') { sprite_slot_a = 10; } else { sprite_slot_a = 0xb; }
      if (*mirror_flag == '\0') { sprite_slot_b = 10; } else { sprite_slot_b = 0xb; }
      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (sprite_slot_b << 3)),scroll_speed,
                 *(int *)(0x06063750 + (sprite_slot_a << 3) + 4));
    }
    else if (surface_bits == 0x88) {
      /* Right-side surface variant (mirror of left) */
      if (*mirror_flag == '\0') { sprite_slot_a = 0xb; } else { sprite_slot_a = 10; }
      if (*mirror_flag == '\0') { sprite_slot_b = 0xb; } else { sprite_slot_b = 10; }
      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (sprite_slot_b << 3)),scroll_speed,
                 *(int *)(0x06063750 + (sprite_slot_a << 3) + 4));
    }
    else if (surface_bits == (int)DAT_06020fc8) {
      /* Special surface (off-road/pit) */
      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x60),scroll_speed,
                 *(int *)(0x06063750 + 100));
    }
  }
  *(int *)0x06089598 = *(int *)(CAR_PTR_TARGET + (int)DAT_06020fca);
  /* Part 2: Road scroll based on car speed */
  if (*(int *)0x06063E20 != 1) {
    return *(int *)0x06063E20;
  }
  scroll_fwd = 0;
  scroll_rev = 0;
  scroll_speed = *(int *)(CAR_PTR_TARGET + 0x60) >> 0xe;  /* car speed >> 14 */
  scroll_base = *(int *)(0x0604D3E0 + (unsigned int)(unsigned char)(*cooldown_timer << 2));
  /* Mirror scroll direction if needed */
  if (*mirror_flag != '\0') {
    scroll_speed = -scroll_speed;
  }
  /* Dead zone: zero out small scroll speeds */
  if ((scroll_speed < DAT_06021098) && (DAT_0602109a < scroll_speed)) {
    scroll_speed = 0;
  }
  *(int *)(scroll_data + DAT_0602109c) = 0;
  /* Fill 22 scroll offset entries (forward and reverse) */
  scroll_idx = 0;
  do {
    scroll_fwd = scroll_fwd + scroll_speed;
    scroll_rev = scroll_rev - scroll_speed;
    surface_bits = (unsigned int)scroll_idx;
    *(int *)(scroll_data + (((0x15 - (unsigned int)scroll_idx) << 2) + (int)DAT_0602109e)) = scroll_fwd + scroll_base;
    scroll_idx = scroll_idx + 1;
    *(int *)(scroll_data + (surface_bits << 2) + (int)DAT_0602109e + 0x58) = scroll_rev + scroll_base;
  } while (scroll_idx < 0x16);
  /* Apply scroll data to VDP2 */
  (*(int(*)())0x0603850C)(8);
  (*(int(*)())0x06038120)(0x06087C84);
  scroll_speed = (*(int(*)())0x06038520)();
  return scroll_speed;
}
#endif

/* track_zone_sprite_swap -- Swap sprite/palette data when car enters track zones.
 * Monitors car X/Z position against two hardcoded zones (pit lane regions).
 * Zone A: X in (0x760000, 0x14B0000), Z in (-0xD00000, 0xD00000), checkpoint 0x57-0x7A.
 * Zone B: Three sub-zones at negative X/Z (back section of track).
 * On zone enter/exit: DMA copies alternate sprite and palette data to VRAM.
 * Two sprite sets: zone=0 uses 0x0604D408/0x060039C8, zone=1 uses 0x0604D608/0x060039F2. */
unsigned int FUN_06021178()
{
  char *zone_flags;
  char *dma_copy;       /* 0x0602766C */
  char *vram_page;      /* 0x06059FFC */
  char *vram_base;      /* 0x06063F5C */
  unsigned int result;
  int car_x;
  int vram_dst;
  int vram_offset;
  int sprite_src;
  zone_flags = (char *)0x0608959C;
  car_x = *(int *)(CAR_PTR_CURRENT + 0x10);     /* car X position */
  vram_offset = *(int *)(CAR_PTR_CURRENT + 0x18);  /* car Z position */
  /* Zone A: pit lane / tunnel area */
  if (((((int)0x00760000 < car_x) && (car_x < (int)0x014B0000)) &&
      (vram_offset < (int)0x00D00000)) && (0xFF3B0000 < vram_offset)) {
    if (((0x57 < *(int *)(CAR_PTR_CURRENT + (int)PTR_DAT_060211d8)) &&
        (*(int *)(CAR_PTR_CURRENT + (int)PTR_DAT_060211d8) < 0x7a)) &&
       ((*(unsigned short *)0x0608959C & 1) == 0)) {
      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;   /* enter zone */
      *(unsigned short *)zone_flags = *(unsigned short *)zone_flags | 2;   /* mark dirty */
    }
  }
  /* Zone B: back section (3 sub-zones with decreasing thresholds) */
  else if ((((car_x < 0xFE9A0000) && (vram_offset < 0xFDCD0000)) ||
           ((car_x < 0xFE950000 && (vram_offset < 0xFDD30000)))) ||
          ((car_x < 0xFE8F0000 && (vram_offset < 0xFDD80000)))) {
    if ((*(unsigned short *)0x0608959C & 1) == 0) {
      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;
      *(unsigned short *)zone_flags = *(unsigned short *)zone_flags | 2;
    }
  }
  /* Outside all zones: clear zone flag */
  else if ((*(unsigned short *)0x0608959C & 1) != 0) {
    *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C & 0xfffe;
    *(unsigned short *)zone_flags = *(unsigned short *)zone_flags | 2;
  }
  dma_copy = (char *)0x0602766C;
  vram_page = (char *)0x06059FFC;
  vram_base = (char *)0x06063F5C;
  result = (unsigned int)(*(unsigned short *)zone_flags >> 1);
  /* If dirty flag set, DMA copy new sprite/palette data */
  if ((*(unsigned short *)zone_flags >> 1 & 1) != 0) {
    car_x = 0xc0;
    if ((*(unsigned short *)zone_flags & 1) == 0) {
      /* Zone inactive: load default sprites */
      (*(int(*)())0x060039C8)();
      (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base,0x0604D408,0x200);
      (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base + 0x3c0,0x0604D808,
                        (int)DAT_06021416);
      if (*(int *)0x06083255 == '\0') {
        (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base + 0x40,
                          *(int *)(0x0605D05C + *(int *)(0x06078868 << 2)),car_x);
        sprite_src = *(int *)(0x0605D05C + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2));
        vram_offset = 0x100;
        vram_dst = *(int *)((int)(int)vram_page << 3) + *(int *)vram_base;
      }
      else {
        car_x = 0x20;
        sprite_src = *(int *)(0x0605D0AC + *(int *)(0x0607EAB8 << 2));
        vram_dst = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +
                (unsigned int)*(unsigned short *)0x0607886C) << 5 + *(int *)((int)(int)vram_page << 3);
        vram_offset = *(int *)vram_base;
      }
      result = (*(int(*)())dma_copy)(vram_dst + vram_offset,sprite_src,car_x);
    }
    else {
      /* Zone active: load alternate sprites */
      (*(int(*)())0x060039F2)();
      (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base,0x0604D608,0x200);
      (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base + 0x3c0,0x0604EFC8,
                        (int)DAT_060212d8);
      if (*(int *)0x06083255 == '\0') {
        (*(int(*)())dma_copy)(*(int *)((int)(int)vram_page << 3) + *(int *)vram_base + 0x40,
                          *(int *)(0x0605D084 + *(int *)(0x06078868 << 2)),car_x);
        sprite_src = *(int *)(0x0605D084 + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2));
        vram_offset = 0x100;
        vram_dst = *(int *)((int)(int)vram_page << 3) + *(int *)vram_base;
      }
      else {
        car_x = 0x20;
        sprite_src = *(int *)(0x0605D0B4 + *(int *)(0x0607EAB8 << 2));
        vram_dst = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +
                (unsigned int)*(unsigned short *)0x0607886C) << 5 + *(int *)((int)(int)vram_page << 3);
        vram_offset = *(int *)vram_base;
      }
      result = (*(int(*)())dma_copy)(vram_dst + vram_offset,sprite_src,car_x);
    }
    *(unsigned short *)zone_flags = *(unsigned short *)zone_flags & 0xfffd;  /* clear dirty */
  }
  return result;
}

void track_object_placement()
{

  short uVar1;

  short uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  int **ppuVar11;

  unsigned int uVar12;

  short uVar14;

  int uVar13;

  int *puVar15;

  int *piVar16;

  int extraout_r3 = 0;

  int extraout_r3_00;

  int extraout_r3_01;

  int *puVar17;

  int extraout_r3_02;

  int extraout_r3_03;

  int extraout_r3_04;

  int extraout_r3_05;

  int *extraout_r3_06;

  int *extraout_r3_07;

  int *extraout_r3_08;

  int *extraout_r3_09;

  int *extraout_r3_10;

  int *extraout_r3_11;

  int *extraout_r3_12;

  unsigned int uVar18;

  short uVar19;

  unsigned int uVar20;

  int iVar21;

  unsigned int *puVar22;

  char *puVar23;

  int iVar24;

  int *piVar25;

  int *piVar26;

  int *piVar27;

  int *piVar28;

  int *piVar33;

  int *local_34;

  unsigned int *puStack_30;

  unsigned int uStack_2c;

  int *puStack_28;

  int *puStack_24;

  int *piVar29;

  int *piVar30;

  int *piVar31;

  int *piVar32;

  int *piVar34;

  int *piVar35;

  puVar10 = (char *)0x00200000;

  puVar9 = (char *)0x00200000;

  puVar8 = (char *)0x00200000;

  puVar7 = (char *)0x06089D98;

  puVar23 = (char *)0x060896B8;

  puVar6 = (char *)0x060895A0;

  puVar5 = (char *)0x06089744;

  puVar4 = (char *)0x0608962C;

  puVar3 = (char *)0x060897D0;

  uVar2 = DAT_06021522;

  uVar1 = DAT_06021520;

  iVar24 = 0x140;

  uVar18 = 0;

  if (CAR_COUNT == 0) {

    *(char **)0x06089D98 = 0x00200000 + (int)0x00037F08;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar8 + (int)0x00037F98;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(int *)(puVar7 + DAT_06021526) = 10;

    uStack_2c = 0;

    puStack_28 = (int *)0x060507A4;

    local_34 = (int *)puVar3;

    puStack_24 = (int *)(puVar3 + PTR_DAT_06021528);

    do {

      puStack_30 = puStack_28;

      *local_34 = *puStack_28;

      local_34[1] = puStack_28[1];

      local_34[2] = -puStack_28[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      puVar15 = local_34;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)((int)puVar15 + 0x16) = uVar14;

      *(unsigned int *)(puVar23 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar4 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar5 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar6 + uStack_2c) = uVar18;

      uStack_2c = uStack_2c + 4;

      puStack_28 = puStack_28 + 4;

      local_34 = local_34 + 6;

    } while (local_34 < puStack_24);

  }

  else if (CAR_COUNT == 1) {

    *(char **)(0x06089D98 + 4) = 0x00200000 + (int)0x00089364;

    *(int *)(puVar7 + 0x20) = 0x12;

    *(char **)(puVar7 + 0x3c) = puVar9 + (int)0x0008943C;

    *(int *)(puVar7 + 0x58) = 0xb;

    *(char **)(puVar7 + 0x74) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar9 + (int)0x00089124;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar9 + (int)0x00089274;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0xc) = puVar9 + (int)0x00089544;

    *(int *)(puVar7 + 0x28) = 0x34;

    *(char **)(puVar7 + 0x44) = puVar9 + (int)0x000897B4;

    *(int *)(puVar7 + 0x60) = 0x1c;

    *(char **)(puVar7 + 0x7c) = 0x0000F333;

    *(int *)(puVar7 + 0x8c) = 0xf;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050844 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 1;

    } while (uVar20 < 4);

    uStack_2c = 0;

    for (; uVar20 < 0xc; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050874 + ((uStack_2c & 0xff) * 0x14 & 0xff));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3 + 0x14) = uVar14;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_00 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0xf; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050914 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_01 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 3;

      uStack_2c = uStack_2c + 1;

    }

  }

  else {

    *(char **)0x06089D98 = 0x00200000 + (int)0x000BE1F8;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar10 + (int)0x000BE288;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar10 + (int)0x000BE360;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar10 + (int)0x000BE4B0;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0x10) = puVar10 + (int)0x000BDBF8;

    *(int *)(puVar7 + 0x2c) = 0x20;

    *(char **)(puVar7 + 0x48) = puVar10 + (int)0x000BDD78;

    *(int *)(puVar7 + 100) = 0xe;

    *(char **)(puVar7 + DAT_060218de) = 0x0000F333;

    *(char **)(puVar7 + 0x14) = puVar10 + (int)0x000BDEC8;

    *(int *)(puVar7 + 0x30) = 0xe;

    *(char **)(puVar7 + 0x4c) = puVar10 + (int)0x000BDF70;

    *(int *)(puVar7 + 0x68) = 10;

    *(char **)(puVar7 + DAT_060218e0) = 0x0000CCCC;

    *(char **)(puVar7 + 0x18) = puVar10 + (int)0x000BE060;

    *(int *)(puVar7 + 0x34) = 0xe;

    *(char **)(puVar7 + 0x50) = puVar10 + (int)0x000BE108;

    *(int *)(puVar7 + 0x6c) = 10;

    iVar21 = 0x88;

    *(char **)(puVar7 + iVar21) = 0x0000CCCC;

    *(int *)(puVar7 + iVar21 + 4) = 0x23;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050AE4 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 0;

    } while (uVar20 < 9);

    uStack_2c = 0;

    for (; uVar12 = uVar18, uVar20 < 0x15; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050974 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_02 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar12 = uVar18, uVar20 < 0x18; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050944 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_03 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 4;

      uVar12 = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar20 < 0x1d; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A34 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_04 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 5;

      uVar12 = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0x23; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A84 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_05 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 6;

      uStack_2c = uStack_2c + 1;

    }

  }

  puVar23 = (char *)0x06089B18;

  *(unsigned int *)0x06089B18 = uVar18;

  *(short *)(puVar23 + 4) = DAT_06021c2e;

  *(short *)(puVar23 + 6) = 0x40008000;

  *(unsigned int *)(puVar23 + 8) = uVar18;

  uVar19 = (short)uVar18;

  *(short *)(puVar23 + 0xc) = uVar19;

  uVar14 = DAT_06021c32;

  *(short *)(puVar23 + 0xe) = DAT_06021c32;

  *(unsigned int *)(puVar23 + 0x10) = uVar18;

  *(short *)(puVar23 + 0x14) = uVar19;

  *(short *)(puVar23 + 0x16) = uVar14;

  puStack_30 = (unsigned int *)(puVar23 + 0x18);

  *(unsigned int *)(puVar23 + 0x18) = uVar18;

  *(short *)(puVar23 + 0x1c) = uVar19;

  *(short *)(puVar23 + 0x1e) = uVar14;

  uVar20 = 4;

  local_34 = (int *)0x06089B18;

  ppuVar11 = &local_34;

  do {

    piVar25 = (int *)ppuVar11;

    piVar25[1] = (uVar20 << 3) + *piVar25;

    piVar25[-9] = (int)(piVar25 + -9);

    (*(int(*)())0x06035BC8)();

    piVar25[-10] = 0x33333333;

    piVar25[-0xb] = 0x4054D333;

    piVar25[-0xc] = (int)(piVar25 + -7);

    (*(int(*)())0x060359E4)();

    piVar25[-0x13] = (int)(piVar25 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x16] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x17] = (int)(piVar25 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar25[-0x18] = 0x9999999A;

    piVar25[-0x19] = 0x40139999;

    piVar25[-0x1a] = (int)(piVar25 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar25[-0x1b] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035460)();

    piVar25[-0x1c] = 0;

    piVar25[-0x1d] = 0x40680000;

    piVar25[-0x1e] = (int)(piVar25 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = uVar20 + 1;

    *extraout_r3_06 = uVar13;

    *(short *)(piVar25[-0x1d] + 4) = uVar1;

    *(short *)(piVar25[-0x1d] + 6) = uVar2;

    piVar25[-0x1d] = (iVar21 << 3) + piVar25[-0x1e];

    piVar25[-0x27] = (int)(piVar25 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x28] = 0x33333333;

    piVar25[-0x29] = 0x4054D333;

    piVar25[-0x2a] = (int)(piVar25 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar25[-0x31] = (int)(piVar25 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x34] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x35] = (int)(piVar25 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar25[-0x36] = 0x9999999A;

    piVar25[-0x37] = 0x40139999;

    piVar25[-0x38] = (int)(piVar25 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar25[-0x39] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035460)();

    piVar25[-0x3a] = 0;

    piVar25[-0x3b] = 0x40680000;

    piVar25[-0x3c] = (int)(piVar25 + -0x37);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = iVar21 + 1;

    *extraout_r3_07 = uVar13;

    *(short *)(piVar25[-0x3b] + 4) = uVar1;

    *(short *)(piVar25[-0x3b] + 6) = uVar2;

    piVar25[-0x3b] = (iVar21 << 3) + piVar25[-0x3c];

    piVar25[-0x45] = (int)(piVar25 + -0x45);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x46] = 0x33333333;

    piVar25[-0x47] = 0x4054D333;

    piVar25[-0x48] = (int)(piVar25 + -0x43);

    (*(int(*)())0x060359E4)();

    piVar25[-0x4f] = (int)(piVar25 + -0x4f);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x52] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x53] = (int)(piVar25 + -0x4e);

    (*(int(*)())0x060359E4)();

    piVar25[-0x54] = 0x9999999A;

    piVar25[-0x55] = 0x40139999;

    piVar25[-0x56] = (int)(piVar25 + -0x51);

    (*(int(*)())0x060359E4)();

    piVar25[-0x57] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035460)();

    piVar25[-0x58] = 0;

    piVar25[-0x59] = 0x40680000;

    piVar26 = piVar25 + -0x5a;

    piVar25[-0x5a] = (int)(piVar25 + -0x55);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_08 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(piVar25[-0x59] + 4) = uVar1;

    *(short *)(piVar25[-0x59] + 6) = uVar2;

    ppuVar11 = (int **)(piVar25 + -0x5a);

  } while (uVar20 < 0x16);

  piVar25[-0x5a] = iVar21 + -0x15;

  piVar25[-0x58] = iVar21 + -0x15;

  piVar25[-0x59] = piVar25[-0x5a];

  piVar25[-0x56] = (int)0x06089B18;

  piVar31 = piVar25 + -0x5a;

  for (; uVar20 < 0x28; uVar20 = uVar20 + 1) {

    *(unsigned int *)((int)piVar31 + 0xc) = (uVar20 << 3) + *(int *)((int)piVar31 + 0x10);

    *(char **)((int)piVar31 + -0x24) = (char *)((int)piVar31 + -0x24);

    (*(int(*)())0x06035BC8)();

    *(int *)((int)piVar31 + -0x28) = 0x33333333;

    *(int *)((int)piVar31 + -0x2c) = 0x4054D333;

    *(char **)((int)piVar31 + -0x30) = (char *)((int)piVar31 + -0x1c);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x4c) = (char *)((int)piVar31 + -0x4c);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x58) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x5c) = (char *)((int)piVar31 + -0x48);

    (*(int(*)())0x060359E4)();

    *(int *)((int)piVar31 + -0x60) = 0x9999999A;

    *(int *)((int)piVar31 + -100) = 0x40139999;

    *(char **)((int)piVar31 + -0x68) = (char *)((int)piVar31 + -0x54);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x6c) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035460)();

    *(int *)((int)piVar31 + -0x70) = 0;

    *(int *)((int)piVar31 + -0x74) = 0x40580000;

    piVar26 = (int *)((int)piVar31 + -0x78);

    *(char **)((int)piVar31 + -0x78) = (char *)((int)piVar31 + -100);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_09 = uVar13;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 4) = DAT_06021e98;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 6) = DAT_06021e9a;

    *(int *)((int)piVar31 + -0x70) = *(int *)((int)piVar31 + -0x70) + 1;

    *(int *)((int)piVar31 + -0x74) = *(int *)((int)piVar31 + -0x74) + 1;

    *(int *)((int)piVar31 + -0x78) = *(int *)((int)piVar31 + -0x78) + 1;

    piVar31 = (int *)((int)piVar31 + -0x78);

  }

  *(char **)((int)piVar26 + 4) = 0x06089B18;

  uVar20 = uVar18;

  do {

    *piVar26 = (uVar20 << 3) + piVar26[1] + iVar24;

    piVar26[-9] = (int)(piVar26 + -9);

    (*(int(*)())0x06035BC8)();

    piVar26[-10] = 0x9999999A;

    piVar26[-0xb] = 0x404FD999;

    piVar26[-0xc] = (int)(piVar26 + -7);

    (*(int(*)())0x060359E4)();

    piVar26[-0x13] = (int)(piVar26 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x16] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x17] = (int)(piVar26 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar26[-0x18] = 0x9999999A;

    piVar26[-0x19] = 0x40139999;

    piVar26[-0x1a] = (int)(piVar26 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar26[-0x1b] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035460)();

    piVar26[-0x1c] = 0;

    piVar26[-0x1d] = 0x40700000;

    piVar26[-0x1e] = (int)(piVar26 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_10 = uVar13;

    iVar21 = uVar20 + 1;

    *(short *)(piVar26[-0x1e] + 4) = DAT_06021fe0;

    *(short *)(piVar26[-0x1e] + 6) = (short)uVar18;

    piVar26[-0x1e] = (iVar21 << 3) + piVar26[-0x1d] + iVar24;

    piVar26[-0x27] = (int)(piVar26 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x28] = 0x9999999A;

    piVar26[-0x29] = 0x404FD999;

    piVar26[-0x2a] = (int)(piVar26 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar26[-0x31] = (int)(piVar26 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x34] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x35] = (int)(piVar26 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar26[-0x36] = 0x9999999A;

    piVar26[-0x37] = 0x40139999;

    piVar26[-0x38] = (int)(piVar26 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar26[-0x39] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035460)();

    piVar26[-0x3a] = 0;

    piVar27 = piVar26 + -0x3b;

    piVar26[-0x3b] = 0x40700000;

    piVar16 = piVar26 + -0x37;

    piVar28 = piVar26 + -0x3c;

    piVar29 = piVar26 + -0x3c;

    piVar30 = piVar26 + -0x3c;

    piVar31 = piVar26 + -0x3c;

    piVar32 = piVar26 + -0x3c;

    piVar26 = piVar26 + -0x3c;

    *piVar28 = (int)piVar16;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_11 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(*piVar29 + 4) = DAT_06022114;

    *(short *)(*piVar30 + 6) = (short)uVar18;

  } while (uVar20 < 0xe);

  *piVar27 = (int)0x06089B18;

  for (; uVar20 < 0x1c; uVar20 = uVar20 + 1) {

    *piVar31 = (uVar20 << 3) + piVar31[1] + iVar24;

    piVar31[-9] = (int)(piVar31 + -9);

    (*(int(*)())0x06035BC8)();

    piVar31[-10] = 0x9999999A;

    piVar31[-0xb] = 0x404FD999;

    piVar31[-0xc] = (int)(piVar31 + -7);

    (*(int(*)())0x060359E4)();

    piVar31[-0x13] = (int)(piVar31 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x16] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x17] = (int)(piVar31 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar31[-0x18] = 0x9999999A;

    piVar31[-0x19] = 0x40139999;

    piVar31[-0x1a] = (int)(piVar31 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar31[-0x1b] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035460)();

    piVar31[-0x1c] = 0;

    piVar31[-0x1d] = 0x40600000;

    piVar26 = piVar31 + -0x19;

    piVar33 = piVar31 + -0x1e;

    piVar34 = piVar31 + -0x1e;

    piVar35 = piVar31 + -0x1e;

    piVar32 = piVar31 + -0x1e;

    piVar31 = piVar31 + -0x1e;

    *piVar33 = (int)piVar26;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_12 = uVar13;

    *(short *)(*piVar34 + 4) = (short)uVar18;

    *(short *)(*piVar35 + 6) = (short)uVar18;

  }

  *piVar32 = (int)0x06089B18;

  puVar22 = (unsigned int *)(0x06089B18 + iVar24 + (uVar20 << 3));

  piVar32[1] = (int)(0x06089B18 + DAT_06022116);

  if (puVar22 < 0x06089B18 + DAT_06022116) {

    do {

      *piVar32 = (int)puVar22;

      *puVar22 = uVar18;

      puVar22 = puVar22 + 2;

      *(short *)(*piVar32 + 4) = DAT_06022118;

      *(short *)(*piVar32 + 6) = (short)uVar18;

    } while (puVar22 < (unsigned int *)piVar32[1]);

  }

  return;

}

/* --- FUN_06020414 (L1 import from src/FUN_06020414.c) --- */

#if 0 /* FUN_06020414 -- replaced by ASM import */
void FUN_06020414(param_1, param_2, param_3, param_4)
    char param_1;
    unsigned int param_2;
    unsigned int param_3;
    int param_4;
{

  unsigned short uVar1;

  char *puVar2;

  short sVar3;

  short *psVar4;

  int iVar5;

  short *psVar6;

  unsigned int uVar7;

  puVar2 = (char *)0x0605F44E;

  uVar7 = 0;

  iVar5 = 0x3c79;

  psVar6 = (short *)(0x0605F44E + 4);

  psVar4 = (short *)(0x0605F44E + 6);

  if ('\0' < param_1) {

    do {

      uVar1 = *(unsigned short *)(param_4 + (uVar7 & 0xff) << 1);

      if ((char)uVar1 == ' ') {

        *psVar6 = 0;

        *psVar4 = 0;

      }

      else {

        sVar3 = ((uVar1 & 0xff) - 0x40) << 1;

        *psVar6 = sVar3;

        *psVar4 = sVar3 + 1;

      }

      (*(int(*)())0x06028400)(8,puVar2,((param_2 & 0xffff) + (param_3 & 0xffff) << 6) << 1,iVar5);

      uVar7 = uVar7 + 1;

      param_2 = param_2 + 1;

    } while ((int)(uVar7 & 0xff) < (int)param_1);

  }

  return;

}
#endif

/* FUN_06020E74 -- original binary (16 bytes) */
__asm__(
    ".section .text.FUN_06020E74, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06020E74\n"
    ".global _FUN_06020e74\n"
    ".type _FUN_06020E74, @function\n"
    "_FUN_06020E74:\n"
    "_FUN_06020e74:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0xE8, 0x15\n"  /* 0x06020E74 */
);

/* FUN_06020414 -- original binary (28 bytes) */
__asm__(
    ".section .text.FUN_06020414, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06020414\n"
    ".type _FUN_06020414, @function\n"
    "_FUN_06020414:\n"
    ".byte 0x2F, 0xE6, 0x66, 0x6D, 0x2F, 0xD6, 0xEE, 0x00, 0x46, 0x08, 0x2F, 0xC6, 0x6D, 0xEC, 0x46, 0x08\n"  /* 0x06020414 */
    ".byte 0x2F, 0xB6, 0x46, 0x08, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0x68, 0x53\n"  /* 0x06020424 */
);

/* FUN_06020D46 -- original binary (10 bytes) */
__asm__(
    ".section .text.FUN_06020D46, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06020D46\n"
    ".global _FUN_06020d46\n"
    ".type _FUN_06020D46, @function\n"
    "_FUN_06020D46:\n"
    "_FUN_06020d46:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0xEB, 0x10\n"  /* 0x06020D46 */
);

/* FUN_06020CF4 -- original binary (82 bytes) */
__asm__(
    ".section .text.FUN_06020CF4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06020CF4\n"
    ".global _FUN_06020cf4\n"
    ".type _FUN_06020CF4, @function\n"
    "_FUN_06020CF4:\n"
    "_FUN_06020cf4:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x95, 0x5B, 0xD4, 0x2E, 0x60, 0x5F, 0x81, 0x44, 0x60, 0x5F, 0x81, 0x45\n"  /* 0x06020CF4 */
    ".byte 0x60, 0x5F, 0x81, 0x46, 0x60, 0x5F, 0x81, 0x47, 0x60, 0x5F, 0x81, 0x48, 0x60, 0x5F, 0x81, 0x49\n"  /* 0x06020D04 */
    ".byte 0x60, 0x5F, 0x81, 0x4A, 0x60, 0x5F, 0x81, 0x4B, 0xE0, 0x17, 0x81, 0x43, 0xE0, 0x00, 0x80, 0x44\n"  /* 0x06020D14 */
    ".byte 0xE0, 0x3A, 0x80, 0x45, 0xDE, 0x23, 0xD3, 0x24, 0x65, 0xE2, 0x43, 0x0B, 0x00, 0x09, 0xD4, 0x23\n"  /* 0x06020D24 */
    ".byte 0x62, 0x42, 0x72, 0x01, 0x24, 0x22, 0x63, 0xE2, 0x73, 0x20, 0x2E, 0x32, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x06020D34 */
    ".byte 0x6E, 0xF6\n"  /* 0x06020D44 */
);
