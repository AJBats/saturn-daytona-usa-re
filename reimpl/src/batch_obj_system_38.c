#include "game.h"

extern int DAT_06038106;
extern int DAT_06038108;
extern int DAT_0603881a;
extern int DAT_06038932;
extern int DAT_060389f2;
extern int DAT_06038a9a;
extern int DAT_06038a9e;
extern int DAT_06038cc8;
extern int DAT_06038cca;
extern int DAT_06038cce;
extern int DAT_06038cd0;
extern int DAT_06038cd2;
extern int DAT_06038cd4;
extern int DAT_06038cd6;
extern int DAT_06038e1a;
extern int DAT_06038efa;
extern int DAT_06038efc;
extern int DAT_0603918c;
extern int DAT_0603918e;
extern int DAT_060392e6;
extern int DAT_060395b6;
extern int DAT_060397f4;
extern int DAT_060397f6;
extern int DAT_060397f8;
extern void FUN_060388c0();
extern void FUN_06038a48();
extern void FUN_06038ac8();
extern unsigned short FUN_0603931c(unsigned short, unsigned short, short);
extern void FUN_060393fc(short, unsigned short, unsigned short, short, unsigned short);
extern void FUN_060394f0();
extern int FUN_0603a6c0();
extern int FUN_0603a72c();
extern int FUN_0603a766();
extern int PTR_DAT_060388b4;
extern int PTR_DAT_06038934;
extern int PTR_DAT_06038e20;
extern int PTR_DAT_06039190;
extern int PTR_DAT_0603923c;
extern int PTR_DAT_060392e8;

/* cd_toc_table_init -- Initialize CD table-of-contents data structure.
 * param_1 = TOC buffer pointer. Clears first 16 bytes (flags/counters),
 * initializes 64 FAD entries at +DAT_06038108. For each of 0x200 entries,
 * converts position data via softfloat (FUN_06035BC8 = uint-to-double),
 * processes through double multiply and divide chain. */
void FUN_0603806c(param_1)
    char *param_1;
{
  char *puVar1;
  int uVar2;
  char *puVar3;
  int extraout_r3 = 0;
  int uVar4;
  unsigned int uVar5;
  int iVar6;
  int iVar7;
  char *puVar8;
  int *piVar9;
  int local_30 [8];
  char local_10 [4];

  puVar1 = (char *)0x00010000;
  puVar8 = local_10;
  iVar7 = 0x200;
  uVar4 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[3] = 0;
  *(int *)(param_1 + 8) = 0;
  *(int *)(param_1 + 0xc) = 0;
  param_1[4] = 0;
  uVar5 = 0;
  do {
    if ((uVar5 & 0xffff) < 0x40) {
      *(int *)(param_1 + ((uVar5 & 0xffff) << 2) + (int)DAT_06038108) = uVar4;
    }
    iVar6 = (int)(short)((short)uVar5 * 0xc);
    *(int *)(param_1 + iVar6 + 0x10) = uVar4;
    *(char **)(puVar8 + -0x14) = puVar8 + -0x14;
    (*(int(*)())0x06035BC8)();
    *(int *)(puVar8 + -0x18) = 0;
    *(int *)(puVar8 + -0x1c) = 0x40F00000;
    puVar3 = puVar8 + -0xc;
    piVar9 = (int *)(puVar8 + -0x20);
    puVar8 = puVar8 + -0x20;
    *piVar9 = (int)puVar3;
    (*(int(*)())0x060359E4)();
    uVar2 = (*(int(*)())0x060357B8)();
    uVar5 = uVar5 + 1;
    *(int *)(extraout_r3 + 4) = uVar2;
    *(char **)(param_1 + iVar6 + 0x18) = puVar1;
  } while ((int)(uVar5 & 0xffff) < iVar7);
  return;
}

/* vdp2_state_init -- Initialize all VDP2 shadow register tables.
 * Resets framebuffer state, clears display list flags, DMA flags,
 * then zeroes all VDP2 register shadow arrays (scroll params, color calc,
 * rotation params, window coords). Sets VDP2 base to 0x25F80000.
 * Triggers VDP1_BATCH_FLAG for first frame. */
/* vdp2_subsystem_init -- Initialize all VDP2 shadow register tables.
 * Calls hardware reset (0x06038F34), zeroes scroll/rotation/line-scroll
 * state, then initializes: VDP2 VRAM base (0x25F80000 at 0x060A3D84),
 * scroll regs (0x060A3D88), rotation table (0x060A3DB0), coordinate
 * table (0x060A3DF8 — scale defaults 0x10000 = 1.0 in 16.16),
 * color calc regs (0x060A3E38), and window table (0x060A3E48).
 * Triggers VDP1_BATCH_FLAG for next frame commit. */
void vdp2_subsystem_init(void)
{
    char *scroll_regs;
    char *rotation_tbl;
    char *coord_tbl;
    unsigned int i;
    unsigned short j;

    (*(int(*)())0x06038F34)();                          /* hardware reset */
    *(int *)0x060A4C60 = 0;  *(int *)0x060A4C64 = 0;   /* scroll offset A/B */
    *(int *)0x060A4C68 = 0;  *(int *)0x060A4C6C = 0;   /* scroll offset C/D */
    *(int *)0x060A4C78 = 0;  *(int *)0x060A4C7C = 0;   /* line scroll A/B */
    *(short *)0x060A4C40 = 0;  *(short *)0x060A4C42 = 0; /* rotation flags */
    *(short *)0x060A4C54 = 0;  *(short *)0x060A4C56 = 0; /* rotation flags 2 */
    *(int *)0x060A4C44 = 0;  *(int *)0x060A4C48 = 0;   /* line scroll enable A/B */
    *(int *)0x060A4C4C = 0;  *(int *)0x060A4C50 = 0;   /* line scroll mode A/B */
    (*(int(*)())0x0603C104)();                          /* additional reset */

    scroll_regs = (char *)0x060A3D88;                   /* VDP2 scroll shadow */
    rotation_tbl = (char *)0x060A3DB0;                  /* VDP2 rotation shadow */
    *(char **)0x060A3D84 = 0x25F80000;                  /* VDP2 VRAM base */
    *(short *)scroll_regs = (short)0x00008000;          /* CHCTLA: 8bpp mode */
    *(short *)(scroll_regs + 2) = 0;                    /* BMPNA */
    *(short *)(scroll_regs + 6) = 0;                    /* PNCN0 */
    *(short *)(scroll_regs + 0xc) = 0;                  /* PLSZ */
    *(short *)(scroll_regs + 0xe) = (short)(0x8000 >> 2); /* MPOFR */
    for (i = 0; i < 8; i++) {
        *(short *)(scroll_regs + (i << 1) + 0x10) = (short)0xFFFF; /* MPA-MPH: all banks */
    }
    *(short *)(scroll_regs + 0x20) = 0;                /* SCXIN0 */
    *(short *)(scroll_regs + 0x22) = 0;                /* SCXDN0 */
    *(short *)(scroll_regs + 0x24) = 0;                /* SCYIN0 */
    *(short *)(scroll_regs + 0x26) = 0;                /* SCYDN0 */

    /* Clear rotation table A (0x060A3DB0, 24 shorts + loops) */
    *(short *)(rotation_tbl + 0) = 0;   *(short *)(rotation_tbl + 2) = 0;
    *(short *)(rotation_tbl + 4) = 0;   *(short *)(rotation_tbl + 6) = 0;
    *(short *)(rotation_tbl + 8) = 0;   *(short *)(rotation_tbl + 10) = 0;
    *(short *)(rotation_tbl + 0xc) = 0; *(short *)(rotation_tbl + 0xe) = 0;
    *(short *)(rotation_tbl + 0x10) = 0; *(short *)(rotation_tbl + 0x12) = 0;
    *(short *)(rotation_tbl + 0x14) = 0; *(short *)(rotation_tbl + 0x16) = 0;
    for (i = 0; i < 8; i++) {
        *(short *)(rotation_tbl + (i << 1) + 0x18) = 0; /* rot matrix entries */
    }
    for (j = 0; j < 0x10; j++) {
        *(short *)(rotation_tbl + ((unsigned int)j << 1) + 0x28) = 0; /* rot coeff tbl */
    }

    /* Coordinate table (0x060A3DF8): pos=0, scale=1.0 (0x10000 in 16.16) */
    coord_tbl = (char *)0x060A3DF8;
    *(int *)(coord_tbl + 0) = 0;                        /* NBG0 scroll X */
    *(int *)(coord_tbl + 4) = 0;                        /* NBG0 scroll Y */
    *(char **)(coord_tbl + 8) = 0x00010000;             /* NBG0 scale X (1.0) */
    *(char **)(coord_tbl + 0xc) = 0x00010000;           /* NBG0 scale Y (1.0) */
    *(int *)(coord_tbl + 0x10) = 0;                     /* NBG1 scroll X */
    *(int *)(coord_tbl + 0x14) = 0;                     /* NBG1 scroll Y */
    *(char **)(coord_tbl + 0x18) = 0x00010000;          /* NBG1 scale X (1.0) */
    *(char **)(coord_tbl + 0x1c) = 0x00010000;          /* NBG1 scale Y (1.0) */
    *(short *)(coord_tbl + 0x20) = 0;  *(short *)(coord_tbl + 0x22) = 0; /* NBG2 X/Y */
    *(short *)(coord_tbl + 0x24) = 0;  *(short *)(coord_tbl + 0x26) = 0; /* NBG3 X/Y */
    *(short *)(coord_tbl + 0x28) = 0;  *(short *)(coord_tbl + 0x2a) = 0; /* reserved */
    *(int *)(coord_tbl + 0x2c) = 0;    *(int *)(coord_tbl + 0x30) = 0;
    *(int *)(coord_tbl + 0x34) = 0;    *(int *)(coord_tbl + 0x38) = 0;
    *(int *)(coord_tbl + 0x3c) = 0;

    /* Color calculation shadow regs (0x060A3E38) */
    *(short *)0x060A3E38 = 0;  *(short *)0x060A3E3A = 0; /* CCRSA/CCRSB */
    *(short *)0x060A3E3C = 0;  *(short *)0x060A3E3E = 0; /* CLOFEN/CLOFSL */
    *(short *)0x060A3E40 = 0;  *(short *)0x060A3E42 = 0; /* COAR/COAG */
    *(int *)0x060A3E44 = 0;                              /* COAB + padding */

    /* Window coordinate table (0x060A3E48) */
    *(short *)0x060A3E48 = 0;  *(short *)0x060A3E4A = 0; /* W0 left X/Y */
    *(short *)0x060A3E4C = 0;  *(short *)0x060A3E4E = 0; /* W0 right X/Y */
    *(short *)0x060A3E50 = 0;  *(short *)0x060A3E52 = 0; /* W1 left X/Y */
    *(short *)0x060A3E54 = 0;  *(short *)0x060A3E56 = 0; /* W1 right X/Y */
    *(short *)0x060A3E58 = 0;  *(short *)0x060A3E5A = 0; /* window flags */
    *(short *)0x060A3E5C = 0;  *(short *)0x060A3E5E = 0; /* window flags 2 */
    *(int *)0x060A3E60 = 0;    *(int *)0x060A3E64 = 0;   /* window CC params */

    if (VDP1_BATCH_FLAG == 0) {
        VDP1_BATCH_FLAG = 1;
    }
}

/* vdp1_batch_complete -- Mark VDP1 batch as complete and set render target.
 * Clears batch flag if it was pending (1), stores new render target address. */
void FUN_0603850c(int render_target)
{
    if (VDP1_BATCH_FLAG == 1) {
        VDP1_BATCH_FLAG = 0;
    }
    *(int *)0x060635A8 = render_target;
}

/* vdp1_batch_request -- Request VDP1 batch processing if not already queued */
void FUN_06038520(void)
{
    if (VDP1_BATCH_FLAG == 0) {
        VDP1_BATCH_FLAG = 1;
    }
}

/* vdp2_scroll_set -- Set VDP2 scroll position for the active render target.
 * Dispatches by render target selector (0x060635A8):
 *   1: scroll plane A — set position + optional line scroll trigger
 *   2: scroll plane B — set position + optional line scroll trigger
 *   4: rotation A X/Y
 *   8: rotation B X/Y
 *   0x10/0x20: coordinate table X/Y (16-bit, upper half of params) */
void FUN_0603853c(int param_1, int param_2, int param_3)
{
    char *rot_tbl_b = (char *)0x060A3EE8;   /* rotation table B */
    char *rot_tbl_a = (char *)0x060A3E68;   /* rotation table A */
    char *coord_tbl = (char *)0x060A3DF8;   /* coordinate table */
    char *line_scroll = (char *)0x060A4C78;  /* line scroll flags */
    int target = *(int *)0x060635A8;

    if (target == 1) {
        *(int *)(rot_tbl_a + 0x44) = param_1;
        *(int *)(rot_tbl_a + 0x48) = param_2;
        if ((*(int *)0x060A4C44 == 0) ||
            ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {
            *(int *)line_scroll = 0;
        } else {
            *(int *)line_scroll = param_3;
        }
        if (*(int *)line_scroll != 0) {
            (*(int(*)())0x0603DDFC)(0, 0);
            return;
        }
    } else if (target == 2) {
        *(int *)(rot_tbl_b + 0x44) = param_1;
        *(int *)(rot_tbl_b + 0x48) = param_2;
        if ((*(int *)0x060A4C48 == 0) ||
            ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {
            *(int *)(line_scroll + 4) = 0;
        } else {
            *(int *)(line_scroll + 4) = param_3;
        }
        if (*(int *)(line_scroll + 4) != 0) {
            (*(int(*)())0x0603DDFC)(0, 0);
            return;
        }
    } else if (target == 4) {
        *(int *)coord_tbl = param_1;
        *(int *)(coord_tbl + 4) = param_2;
    } else if (target == 8) {
        *(int *)(coord_tbl + 0x10) = param_1;
        *(int *)(coord_tbl + 0x14) = param_2;
    } else {
        short val_x = (short)((unsigned int)param_1 >> 0x10);
        if (target == 0x10) {
            *(short *)(coord_tbl + 0x20) = val_x;
            target = 0x22;
        } else {
            if (target != 0x20) return;
            *(short *)(coord_tbl + 0x24) = val_x;
            target = 0x26;
        }
        *(short *)(coord_tbl + target) = (short)((unsigned int)param_2 >> 0x10);
    }
}

/* vdp2_scroll_accumulate -- Accumulate (add) VDP2 scroll offset for active render target.
 * Same dispatch structure as vdp2_scroll_set but adds to existing values.
 * Returns 0 on success, or result of line scroll handler if triggered. */
/* vdp2_scroll_offset -- Add scroll offset to active VDP2 render target.
 * Dispatches by render target (0x060635A8): rotation planes (1/2) update
 * rotation table A/B scroll at +0x44/+0x48 and optionally trigger line
 * scroll via 0x0603DDFC; bitmap planes (4/8) update coordinate table
 * at 0x060A3DF8; tile planes (0x10/0x20) update NBG2/NBG3 as 16.16→int. */
int vdp2_scroll_offset(int dx, int dy, int line_delta)
{
    char *rot_tbl_b = (char *)0x060A3EE8;              /* rotation table B shadow */
    char *rot_tbl_a = (char *)0x060A3E68;              /* rotation table A shadow */
    char *coord_tbl = (char *)0x060A3DF8;              /* coordinate table shadow */
    char *line_scroll = (char *)0x060A4C78;            /* line scroll accumulator */
    int target = *(int *)0x060635A8;                   /* active render target */

    if (target == 1) {                                 /* rotation plane A */
        *(int *)(rot_tbl_a + 0x44) += dx;              /* rot A scroll X */
        *(int *)(rot_tbl_a + 0x48) += dy;              /* rot A scroll Y */
        if ((*(int *)0x060A4C44 == 0) ||
            ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {
            *(int *)line_scroll = 0;                   /* line scroll disabled */
        } else {
            *(int *)line_scroll += line_delta;          /* accumulate line scroll */
        }
        target = 0;
        if (*(int *)line_scroll != 0) {
            target = (*(int(*)())0x0603DDFC)(0, 0);    /* apply line scroll */
            return target;
        }
    } else if (target == 2) {                          /* rotation plane B */
        *(int *)(rot_tbl_b + 0x44) += dx;              /* rot B scroll X */
        *(int *)(rot_tbl_b + 0x48) += dy;              /* rot B scroll Y */
        if ((*(int *)0x060A4C48 == 0) ||
            ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {
            *(int *)(line_scroll + 4) = 0;
        } else {
            *(int *)(line_scroll + 4) += line_delta;
        }
        target = 0;
        if (*(int *)(line_scroll + 4) != 0) {
            target = (*(int(*)())0x0603DDFC)(0, 0);    /* apply line scroll */
            return target;
        }
    } else if (target == 4) {                          /* NBG0 bitmap */
        *(int *)coord_tbl += dx;                       /* NBG0 scroll X */
        *(int *)(coord_tbl + 4) += dy;                 /* NBG0 scroll Y */
    } else if (target == 8) {                          /* NBG1 bitmap */
        *(int *)(coord_tbl + 0x10) += dx;              /* NBG1 scroll X */
        *(int *)(coord_tbl + 0x14) += dy;              /* NBG1 scroll Y */
    } else {
        short sdx = (short)((unsigned int)dx >> 0x10); /* 16.16 → integer */
        short sdy = (short)((unsigned int)dy >> 0x10);
        if (target == 0x10) {                          /* NBG2 tile */
            *(short *)(coord_tbl + 0x20) += sdx;
            *(short *)(coord_tbl + 0x22) += sdy;
            target = 0x22;
        } else if (target == 0x20) {                   /* NBG3 tile */
            *(short *)(coord_tbl + 0x24) += sdx;
            *(short *)(coord_tbl + 0x26) += sdy;
            target = 0x26;
        }
    }
    return target;
}

/* vdp2_scale_set -- Set VDP2 zoom/scale for active render target.
 * For rotation targets (4/8), clamps scale to [DAT_0603881a..0x00FF0000],
 * defaulting to 0x10000 (1.0 in 16.16) if zero.
 * Divides 0x10000 by clamped values via 0x0603C0A0 (fixed-point divide).
 * Dispatches by render target (1/2/4/8) to appropriate VDP2 shadow regs.
 * Targets 1/2 may trigger line scroll handler if scale flag is set. */
void FUN_06038794(char *param_1, char *param_2)
{
    char *scale_x = param_1;
    char *scale_y = param_2;
    char *min_scale = (char *)(int)DAT_0603881a;
    int target = *(int *)0x060635A8;

    if ((target != 1) && (target != 2)) {
        if ((target != 4) && (target != 8)) goto LAB_06038802;
        /* Clamp scale_x to [min_scale..0x00FF0000], default 0x10000 if zero */
        scale_x = (char *)0x00FF0000;
        if ((((int)param_1 <= (int)0x00FF0000) &&
             (scale_x = min_scale, (int)min_scale <= (int)param_1)) &&
            (scale_x = param_1, param_1 == (char *)0x0)) {
            scale_x = (char *)0x00010000;
        }
        scale_y = (char *)0x00FF0000;
        if ((((int)param_2 <= (int)0x00FF0000) &&
             (scale_y = min_scale, (int)min_scale <= (int)param_2)) &&
            (scale_y = param_2, param_2 == (char *)0x0)) {
            scale_y = (char *)0x00010000;
        }
    }
    param_1 = (char *)(*(int(*)())0x0603C0A0)(0x00010000, scale_x);  /* reciprocal X */
    param_2 = (char *)(*(int(*)())0x0603C0A0)(0x00010000, scale_y);  /* reciprocal Y */

LAB_06038802:
    ;
    short plane_b_off = PTR_DAT_060388b4;
    char *coord_tbl = (char *)0x060A3DF8;
    char *rot_tbl_a = (char *)0x060A3E68;
    char *color_calc = (char *)0x060A3E38;
    target = *(int *)0x060635A8;

    if (target == 1) {
        *(char **)(rot_tbl_a + 0x4c) = param_1;
        *(char **)(rot_tbl_a + 0x50) = param_2;
        if ((*(unsigned short *)(color_calc + 4) & 0xff) != 0) {
            (*(int(*)())0x0603DDFC)(0, 0);
            return;
        }
    } else if (target == 2) {
        *(char **)(rot_tbl_a + plane_b_off + 0x4c) = param_1;
        *(char **)(rot_tbl_a + plane_b_off + 0x50) = param_2;
        if (((unsigned int)*(unsigned short *)(color_calc + 4) & (unsigned int)0x0000FF00) != 0) {
            (*(int(*)())0x0603DDFC)(0, 0);
            return;
        }
    } else if (target == 4) {
        *(char **)(coord_tbl + 8) = param_1;
        *(char **)(coord_tbl + 0xc) = param_2;
    } else if (target == 8) {
        *(char **)(coord_tbl + 0x18) = param_1;
        *(char **)(coord_tbl + 0x1c) = param_2;
    }
}

/* dma_transfer_batch -- Execute batch of word copies to VDP2 hardware.
 * Conditionally copies display-list segments if flags are set,
 * then copies render state, scroll, coordinate, color, and attribute
 * tables from work RAM (0x060A3xxx) to VDP2 base at *(0x060A3D84). */
void FUN_060388c0(void)
{
    if ((*(short *)0x060A4C40 != 0) && (*(int *)0x060A4C44 != 0)) {
        FUN_06038a48(*(int *)0x060A4C44, 0x060A3F68, *(int *)0x060A4C38 << 1);
        *(short *)0x060A4C40 = 0;
    }
    if ((*(short *)0x060A4C42 != 0) && (*(int *)0x060A4C48 != 0)) {
        FUN_06038a48(*(int *)0x060A4C48, 0x060A45D0, *(int *)0x060A4C3C << 1);
        *(short *)0x060A4C42 = 0;
    }
    if (*(int *)0x060635B2 == 1) {
        FUN_06038a48(*(int *)0x060A4C5C, 0x060A3E68, 0x80);
    } else if (*(int *)0x060635B2 == 2) {
        FUN_06038a48(*(int *)0x060A4C5C, 0x060A3E68, 0x100);
    }
    FUN_06038a48(*(int *)0x060A3D84, 0x060A3D88, 0x28);
    FUN_06038a48(*(int *)0x060A3D84 + 0x28, 0x060A3DB0, 0x48);
    FUN_06038a48(*(int *)0x060A3D84 + 0x70, 0x060A3DF8, 0x40);
    FUN_06038a48(*(int *)0x060A3D84 + (int)0x00B000C0, 0x060A3E38, 0x10);
    FUN_06038a48(*(int *)0x060A3D84 + 0xc0, 0x060A3E48, 0x20);
}

/* vdp1_batch_dispatch -- Dispatch VDP1 batch transfer based on batch flag.
 * flag=1: run DMA transfers directly.
 * flag=2: copy object/sprite tables first, then run DMA.
 * Clears dispatch flag 0x060635AC after transfer, then runs peripheral DMA. */
void FUN_060389a6(void)
{
    if (VDP1_BATCH_FLAG == 1) {
        FUN_060388c0();
    } else {
        if (VDP1_BATCH_FLAG != 2) goto LAB_06038a42;
        FUN_06038a48(*(int *)0x060A3D70, *(int *)0x060A3D74,
                     (unsigned int)*(unsigned short *)0x060635A0 * 0xc);
        FUN_06038a48(*(int *)0x060A3D78, *(int *)0x060A3D7C,
                     (unsigned int)*(unsigned short *)0x060635A2 << 2);
        FUN_060388c0();
    }
    *(short *)0x060635AC = 0;
LAB_06038a42:
    FUN_06038ac8();
}

/* word_copy -- Copy byte_count/2 words from src to dst.
 * 16-bit (short) granularity memcpy used for DMA-style block transfers. */
void FUN_06038a48(short *dst, short *src, unsigned int byte_count)
{
    unsigned int i = 0;
    if (byte_count >> 1 != 0) {
        do {
            i = i + 1;
            *dst = *src;
            dst = dst + 1;
            src = src + 1;
        } while (i < byte_count >> 1);
    }
}

/* fbcr_mode_set -- Set FBCR display mode from selector.
 * mode 0: keep existing bits masked by DAT_06038a9a.
 * mode 1: set interlace bits 0x10002000.
 * mode 2: set alternative mode bits (DAT_06038a9e).
 * Triggers VDP1_BATCH_FLAG for next frame update. */
unsigned int FUN_06038a64(unsigned int mode)
{
    unsigned short uVar1;
    if (mode == 0) {
        uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a;
    } else if (mode == 1) {
        uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | 0x10002000;
    } else {
        if (mode != 2) goto LAB_06038ab0;
        uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | DAT_06038a9e;
    }
    mode = (unsigned int)uVar1;
    *(unsigned short *)(0x060A3D88 + 0xe) = uVar1;
LAB_06038ab0:
    if (VDP1_BATCH_FLAG == 0) {
        VDP1_BATCH_FLAG = 1;
    }
    return mode;
}

/* peripheral_dma_dispatch -- Transfer peripheral data blocks based on flag bits.
 * Reads control byte at 0x060A4D58 and dispatches up to 6 DMA copies
 * for SCSP/peripheral registers. Each bit (0x80..0x04) triggers a
 * word_copy from work RAM to hardware, followed by a sync call. */
void FUN_06038ac8(void)
{
    char *flags = (char *)0x060A4D58;
    (*(int(*)())0x0603C728)();
    if (((int)(char)*flags & 0x80U) != 0) {
        FUN_06038a48(*(int *)0x0606360C, 0x060A4D18, 0x10);
        (*(int(*)())0x06034F78)();
    }
    if ((*flags & 0x40) != 0) {
        FUN_06038a48(*(int *)0x06063610, 0x060A4D28, 8);
        (*(int(*)())0x06034F78)();
    }
    if ((*flags & 0x20) != 0) {
        FUN_06038a48(*(int *)0x06063614, 0x060A4D30, 6);
        (*(int(*)())0x06034F78)();
    }
    if ((*flags & 0x10) != 0) {
        FUN_06038a48(*(int *)0x06063618, 0x060A4D36, 8);
        (*(int(*)())0x06034F78)();
    }
    if ((*flags & 8) != 0) {
        FUN_06038a48(*(int *)0x0606361C, 0x060A4D3E, 8);
        (*(int(*)())0x06034F78)();
    }
    if ((*flags & 4) != 0) {
        FUN_06038a48(*(int *)0x06063620, 0x060A4D46, 0x10);
        (*(int(*)())0x06034F78)();
    }
}

/* vdp2_priority_set -- Set VDP2 layer priority and color calculation registers.
 * param_1 is a bitmask selecting which register fields to update.
 * param_2 (low byte) is the value to write. Each bit dispatches to a
 * different VDP2 shadow register nibble at 0x060A4D28 (PRISA-PRISD)
 * or 0x060A4D30 (CCRSA/CCRSB/CCRSC):
 *   Bits 8-15: priority registers A-D (low/high nibble per pair)
 *   Bits 1-5,7,0x80: color calculation registers
 *   Bit 0: direct write to CCRS offset +4
 * Calls sync (0x06034F78) before each register update. */
void vdp2_priority_set(param_1, param_2)
    unsigned int param_1;
    unsigned int param_2;
{
    unsigned short lo_mask = (unsigned short)0x0000FFF0;
    unsigned short hi_mask = (unsigned short)0x0000F0FF;
    unsigned short cc_lo_mask = (unsigned short)0x0000FF00;
    unsigned short cc_hi_mask = DAT_06038cc8;
    unsigned short *pris_base = (unsigned short *)0x060A4D28;  /* VDP2 PRISA shadow */
    char *ccrs_base = (char *)0x060A4D30;                     /* VDP2 CCRSA shadow */
    short val;

    param_2 = param_2 & 0xff;

    /* Priority register A low nibble (NBG0) */
    if ((0x100 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        *pris_base = *pris_base & lo_mask | (unsigned short)param_2;
    }
    /* Priority register A high nibble (NBG1) */
    if ((0x200 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        *pris_base = *pris_base & hi_mask | (unsigned short)((param_2 & 0xffff) << 8);
    }
    /* Priority register B low (NBG2) */
    if ((0x400 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[1] = pris_base[1] & lo_mask | (unsigned short)param_2;
    }
    /* Priority register B high (NBG3) */
    if ((0x800 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[1] = pris_base[1] & hi_mask | (unsigned short)((param_2 & 0xff) << 8);
    }
    /* Priority register C low (RBG0) */
    if (((int)DAT_06038cd4 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[2] = pris_base[2] & lo_mask | (unsigned short)param_2;
    }
    /* Priority register C high */
    if (((int)DAT_06038cd6 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[2] = pris_base[2] & hi_mask | (unsigned short)((param_2 & 0xff) << 8);
    }
    /* Priority register D low */
    if (((int)DAT_06038e1a & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[3] = pris_base[3] & lo_mask | (unsigned short)param_2;
    }
    /* Priority register D high */
    if (((unsigned int)0x00008000 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        pris_base[3] = pris_base[3] & hi_mask | (unsigned short)((param_2 & 0xff) << 8);
    }
    /* Color calculation A low (bit 2: NBG0, bit 4: NBG2) */
    if ((param_1 & 4) != 0) {
        (*(int(*)())0x06034F78)();
        *(unsigned short *)ccrs_base = *(unsigned short *)ccrs_base & cc_lo_mask | (unsigned short)param_2;
    }
    /* Color calculation A low (bit 1: sprite) */
    if ((param_1 & 2) != 0) {
        (*(int(*)())0x06034F78)();
        *(unsigned short *)ccrs_base = *(unsigned short *)ccrs_base & cc_lo_mask | (unsigned short)param_2;
    }
    /* Color calculation A high (bit 3: NBG1) */
    if ((param_1 & 8) != 0) {
        (*(int(*)())0x06034F78)();
        *(unsigned short *)ccrs_base = *(unsigned short *)ccrs_base & cc_hi_mask | (unsigned short)((param_2 & 0xffff) << 8);
    }
    /* Color calculation A high (bit 7: RBG0) */
    if ((0x80 & param_1) != 0) {
        (*(int(*)())0x06034F78)();
        *(unsigned short *)ccrs_base = *(unsigned short *)ccrs_base & cc_hi_mask | (unsigned short)((param_2 & 0xffff) << 8);
    }
    /* Color calculation B low (bit 4: NBG3) */
    if ((param_1 & 0x10) != 0) {
        (*(int(*)())0x06034F78)();
        *(unsigned short *)(ccrs_base + 2) = *(unsigned short *)(ccrs_base + 2) & cc_lo_mask | (unsigned short)param_2;
    }
    /* Color calculation B high (bit 5) */
    val = (short)param_2;
    if ((param_1 & 0x20) != 0) {
        (*(int(*)())0x06034F78)();
        val = (short)param_2;
        *(unsigned short *)(ccrs_base + 2) = *(unsigned short *)(ccrs_base + 2) & cc_hi_mask | (unsigned short)((param_2 & 0xff) << 8);
    }
    /* Direct color calc write (bit 0) */
    if ((param_1 & 1) != 0) {
        (*(int(*)())0x06034F78)();
        *(short *)(ccrs_base + 4) = val;
    }
}

/* fb_state_control -- Set framebuffer state and VDP1 FBCR from mode param.
 * 0xFFFF: freeze mode (FB_STATE=2), force manual erase.
 * 0xFFFE: alt freeze mode (FB_STATE=3), force manual erase.
 * Other: extract swap/interlace bits from param to set VDP1 display mode.
 * Writes VDP1 FBCR register at 0x25D00002. */
void FUN_06038e54(unsigned short param_1)
{
    unsigned int uVar6;
    if ((unsigned int)param_1 == 0xFFFF) {
        FB_STATE = 2;
        *(int *)0x060635B8 = 0;
        *(unsigned short *)0x25D00002 = *(unsigned short *)0x060A4C92 | 3;
        *(unsigned int *)0x060635BC = (unsigned int)param_1;
    } else if ((unsigned int)param_1 == 0xFFFE) {
        FB_STATE = 3;
        *(int *)0x060635B8 = 0;
        *(unsigned short *)0x25D00002 = *(unsigned short *)0x060A4C92 | 3;
        *(unsigned int *)0x060635BC = (unsigned int)param_1;
    } else {
        if ((param_1 & DAT_06038efa) == 0) {
            *(int *)0x060635B8 = 1;
        } else {
            *(int *)0x060635B8 = 0;
        }
        uVar6 = (unsigned int)(param_1 & DAT_06038efc);
        if (uVar6 == 0) {
            *(short *)0x060635B4 = 0;
        } else {
            *(unsigned short *)0x060635B4 = (unsigned short)(uVar6 != 1);
        }
        *(unsigned int *)0x060635BC = uVar6;
        if (*(short *)0x060635B4 == 0) {
            *(short *)0x25D00002 = *(short *)0x060A4C92;
        } else {
            *(unsigned short *)0x25D00002 = *(unsigned short *)0x060A4C92 | 3;
        }
    }
}

/* framebuffer_state_reset -- Reset all framebuffer/frame timing state.
 * Clears FB_STATE, enables FBCR swap mode, resets all frame counters. */
void FUN_06038f34(void)
{
    FB_STATE = 0;
    FBCR_SWAP_MODE = 1;
    FBCR_SWAP_THRESHOLD = 0;
    FRAME_SEC_COUNTER = 0;
    FRAME_READY_FLAG = 0;
    *(int *)0x060635C8 = 0;
}

/* vdp2_window_config -- Configure VDP2 display window coordinates and color calc.
 * param_1: window index (0 = window A, 1 = window B; others return early).
 * Sets window left/right/top/bottom coords, doubling X if resolution <= 352.
 * Applies color calculation parameters via function at 0x0603EDC4.
 * Sets color calc mode (shadow=3 if bit 16 of param_3 set).
 * Triggers VDP1_BATCH_FLAG for next frame update. */
unsigned int FUN_06039100(unsigned int param_1, int param_2, unsigned int param_3,
                          int param_4, short param_5, short param_6, short param_7, short param_8)
{
    unsigned int result;
    short *win_right;
    short *win_left;
    int base_idx;
    int step;
    int next_idx;
    char *win_tbl = (char *)0x060A3E48;  /* window coordinate table */
    char cc_mode;

    param_1 = param_1 & 0xff;
    if (param_1 == 0) {
        *(int *)(win_tbl + 0x18) = 0;
        win_right = (short *)(win_tbl + 4);
        cc_mode = 2;
        base_idx = (int)DAT_0603918c;
        step = 1;
        next_idx = base_idx + 1;
        win_left = (short *)win_tbl;
    } else {
        if (param_1 != 1) return param_1;
        *(int *)(win_tbl + 0x1c) = 0;
        win_right = (short *)(win_tbl + 0xc);
        cc_mode = 8;
        base_idx = (int)DAT_0603918e;
        step = 4;
        next_idx = base_idx + 4;
        win_left = (short *)(win_tbl + 8);
    }

    win_tbl = win_tbl + 0x10;  /* advance to color calc sub-table */

    if (0x160 < (int)(unsigned int)*(unsigned short *)0x060635AE) {
        *win_left = param_5;      /* high-res: use coords directly */
        *win_right = param_7;
    } else {
        *win_left = param_5 << 1; /* low-res: double X coords */
        *win_right = param_7 << 1;
    }
    win_left[1] = param_6;       /* top Y */
    win_right[1] = param_8;      /* bottom Y */

    if (param_2 != 0 || param_3 != 0) {
        (*(int(*)())0x0603EDC4)(param_2, param_3, win_tbl, 0x80, 0x7f);
    }
    if (param_4 != 0 || param_3 != 0) {
        (*(int(*)())0x0603EDC4)(param_4, param_3, win_tbl, step, next_idx);
    }
    result = (*(int(*)())0x0603EDC4)(param_3, 0xffffffff, win_tbl, cc_mode, base_idx);

    if ((param_3 & (unsigned int)0x00010000) == 0) {
        *(short *)0x060A3E38 = *(short *)0x060A4C80;
    } else {
        *(short *)0x060A3E38 = 3;  /* shadow color calc mode */
    }
    if (VDP1_BATCH_FLAG == 0) {
        VDP1_BATCH_FLAG = 1;
    }
    return result;
}

/* vdp1_init -- Initialize VDP1 command table and display registers.
 * Sets FBCR to single-buffer, TV mode 0, default erase window,
 * then writes initial command at VDP1 VRAM base (0x25C00000).
 * param_1 receives the VDP1 VRAM base pointer. */
unsigned int FUN_06039250(int *param_1)
{
    unsigned int in_sr = 0;
    unsigned int uVar3 = in_sr & -241 & 0xfff0fff | 0xf0;
    FUN_060394f0(0);
    FUN_0603931c(0, 0, 0);
    VDP1_FBCR = FBCR_SHADOW;
    VDP1_PTMR = 2;
    VDP1_EWDR = (short)0x00008000;
    VDP1_EWLR = 0;
    VDP1_EWRR = (short)0x0000FFFF;
    FUN_060393fc(0x00008000, 0, 0, *(int *)0x060A4C88 - 1U & 0xffff,
                 *(int *)0x060A4C8C - 1U & 0xffff);
    *param_1 = (int)0x25C00000;
    *(char *)0x25C00000 = (char)PTR_DAT_060392e8;
    *(char *)(*param_1 + 1) = 0;
    *(int *)0x060635CC = 1;
    return (in_sr >> 4 & 0xf) << 4 | uVar3 & (unsigned int)DAT_060392e6;
}

/* tv_mode_select -- Configure VDP1 TV mode, resolution, and palette bank.
 * Sets TVMR register (bits 0-2), looks up resolution from mode table,
 * selects 16-color (bank=1) or 256-color (bank=0) palette mode.
 * param_3=1 doubles vertical resolution (interlace). */
unsigned short FUN_0603931c(unsigned short param_1, unsigned short param_2, short param_3)
{
    short *psVar2;
    TVMR_SHADOW = param_1 & 7;
    VDP1_TVMR = param_1 & 7;
    if (7 < param_2) {
        param_2 = 0;
    }
    psVar2 = (short *)(0x060635E0 + (unsigned int)(param_2 << 2));
    *(int *)0x060A4C88 = (int)*psVar2;
    *(int *)0x060A4C8C = (int)psVar2[1];
    if (param_3 == 1) {
        *(int *)0x060A4C8C = *(int *)0x060A4C8C << 1;
    }
    if ((param_1 == 1) || (param_1 == 3)) {
        PALETTE_BANK_SEL = 1;
    } else {
        PALETTE_BANK_SEL = 0;
    }
    if (param_3 == 0) {
        *(short *)0x060A4C94 = 0;
    } else {
        *(short *)0x060A4C94 = 8;
    }
    *(short *)0x060A4C96 = 0;
    return param_1;
}

/* erase_window_config -- Set VDP1 erase window (EWDR/EWLR/EWRR).
 * Stores shadow copies of all params, then computes EWLR/EWRR
 * from X coords (shifted by palette bank: >>3 or >>4) and Y coords
 * (halved if interlace mode is active at 0x060A4C94). */
void FUN_060393fc(short erase_data, unsigned short x_left, unsigned short y_top,
                  short x_right, unsigned short y_bottom)
{
    unsigned short uVar1;
    *(short *)0x060635D4 = erase_data;
    *(unsigned short *)0x060635D6 = x_left;
    *(unsigned short *)0x060635D8 = y_top;
    *(short *)0x060635DA = x_right;
    *(unsigned short *)0x060635DC = y_bottom;
    VDP1_EWDR = erase_data;
    if (PALETTE_BANK_SEL == 0) {
        x_left = x_left >> 3;
    } else {
        x_left = x_left >> 4;
    }
    if (*(short *)0x060A4C94 != 0) {
        y_top = y_top >> 1;
    }
    *(unsigned short *)0x060635D0 = (x_left << 9) + y_top;
    VDP1_EWLR = *(short *)0x060635D0;
    if (PALETTE_BANK_SEL == 0) {
        uVar1 = (unsigned short)(x_right + 1U) >> 3;
    } else {
        uVar1 = (unsigned short)(x_right + 1U) >> 4;
    }
    if (*(short *)0x060A4C94 != 0) {
        y_bottom = y_bottom >> 1;
    }
    *(unsigned short *)0x060635D2 = (uVar1 << 9) + y_bottom;
    VDP1_EWRR = *(short *)0x060635D2;
}

/* fbcr_mode_select -- Set VDP1 frame buffer control shadow.
 * param_1=0: single buffer mode (FBCR=0).
 * param_1!=0: manual erase mode (FBCR=0x10). */
void FUN_060394f0(int param_1)
{
    FBCR_SHADOW = (param_1 == 0) ? 0 : 0x10;
}

/* display_mode_init -- Initialize VDP display mode and timing configuration.
 * Clears VDP status registers (0x20100079..7F), installs VBlank handler
 * (0x0603990E via BIOS 0x47), sets interrupt mask. Configures display mode
 * at 0x060A4CAA (0=off, 1=non-interlace, 2=interlace), frame timing params,
 * and computes stride offsets for the 5-slot display config ring buffer
 * based on resolution mode (0x060A4CAF). Performs initial field swap. */
void display_mode_init(char mode, short line_count, char res_mode, char scan_lines,
                       int base_addr, int frame_threshold)
{
  char mode_val;
  unsigned short res;
  int stride;
  char *display_flags = (char *)0x06063602;             /* display mode flags */
  char *scan_cfg = (char *)0x060A4CAE;                  /* scan line config */

  /* Clear VDP status registers */
  *(int *)0x20100079 = 0;
  *(int *)0x2010007B = 0;                               /* +2 */
  *(int *)0x2010007F = 0;                               /* +6 */
  *(int *)0x2010007D = 0;                               /* +4 */

  /* Install VBlank interrupt handler */
  (*(int(*)())(BIOS_FUNC_0300))(0x47, 0x0603990E);
  (*(int(*)())(BIOS_FUNC_0344))(-129, 0);              /* set interrupt mask */

  *(int *)0x060A4CAA = mode;                            /* display mode */
  mode_val = *(char *)0x060A4CAA;

  if (mode_val == '\0') {                               /* mode 0: display off */
    *display_flags = 1;
    display_flags[1] = 0;
    *(int *)0x060A4CA8 = 0;
    (*(int(*)())0x0603A72C)();                          /* query display state */
    return;
  }

  if (mode_val == '\x01') {                             /* mode 1: non-interlace */
    *display_flags = 0;
    display_flags[1] = 8;
  }
  else if (mode_val == '\x02') {                        /* mode 2: interlace */
    *display_flags = 1;
    display_flags[1] = 8;
    *(int *)0x060A4CD8 = 0;                             /* interlace field counter */
  }

  /* Store timing parameters */
  *scan_cfg = scan_lines;
  *(short *)0x060A4CAC = line_count;                    /* lines per frame */
  *(int *)0x060A4CAB = frame_threshold;                 /* frame count threshold */
  *(int *)0x060A4CAF = res_mode;                        /* resolution mode */
  *(int *)0x060A4CB0 = base_addr;                       /* display buffer base */
  *(int *)0x060A4CB8 = 0;                               /* frame counter: reset */

  if (0xf < (unsigned char)*scan_cfg) {
    display_flags[1] = display_flags[1] | 0x50;        /* hi-res scan flag */
  }

  /* Initialize display config ring buffer pointers */
  *(char **)0x060A4CE8 = 0x060A4CD9;                   /* slot[4] = config base */
  *(char **)0x060A4C98 = (char *)0x060A4CD9 + 7;       /* slot[0] = base + 7 */
  *(int *)0x060A4CBC = *(int *)0x060A4CB0;              /* slot[2] = base_addr */

  /* Compute stride offsets based on resolution mode */
  res = (unsigned short)(unsigned char)*(int *)0x060A4CAF;
  if (res == 0) {                                       /* 320×224 */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 6 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 0xc + *(int *)0x060A4CB0;
  }
  else if (res == 0x10) {                               /* 352×224 */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 0x12 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 0x24 + *(int *)0x060A4CB0;
  }
  else if (res == 0x20) {                               /* 640×224 */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 0x12 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 0x24 + *(int *)0x060A4CB0;
  }
  else if (res == 0x30) {                               /* 704×224 */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 10 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 0x14 + *(int *)0x060A4CB0;
  }
  else if (res == DAT_060397f4) {                       /* custom mode A */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 3 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 6 + *(int *)0x060A4CB0;
  }
  else if (res == DAT_060397f6) {                       /* custom mode B */
    *(unsigned int *)0x060A4CC0 = (unsigned int)*(unsigned short *)0x060A4CAC * 6 + *(int *)0x060A4CB0;
    *(unsigned int *)0x060A4CC8 = (unsigned int)*(unsigned short *)0x060A4CAC * 0xc + *(int *)0x060A4CB0;
  }
  else if (res == DAT_060397f8) {                       /* custom mode C */
    stride = ((unsigned char)*scan_cfg + 1) * (unsigned int)*(unsigned short *)0x060A4CAC;
    *(int *)0x060A4CC0 = *(int *)0x060A4CB0 + stride;
    *(int *)0x060A4CC8 = (stride << 1) + *(int *)0x060A4CB0;
  }

  /* Perform initial field swap and display commit */
  *(int *)0x060A4CB4 = 0;
  (*(int(*)())0x0603A766)();                            /* field swap */
  *(int *)0x060A4CC4 = *(int *)0x060A4CC0;              /* rotate ring: slot[1] = slot[3] */
  *(int *)0x060A4CC0 = *(int *)0x060A4CBC;              /* slot[3] = slot[2] */
  *(int *)0x060A4CBC = *(int *)0x060A4CC4;              /* slot[2] = slot[1] */
  *(int *)0x060A4CB4 = 0;
  (*(int(*)())0x0603A766)();                            /* field swap again */
  FUN_0603a6c0();                                       /* commit display config */
  FUN_0603a72c();                                       /* query display mode */
  return;
}

/* framebuffer_vsync_poll -- Poll VDP vsync and advance frame timing.
 * Monitors interlace mode (0x060A4CAA) and VDP status register bit 4
 * (0x20100061) to count vsync events. When frame counter (0x060A4CB8)
 * reaches threshold (0x060A4CAB), rotates the 5-slot display config
 * ring buffer (0x060A4CBC..CE8) and commits the new display params.
 * Returns: 0 = still counting, 1 = inactive mode, or display query result. */
int framebuffer_vsync_poll(param_1)
    int *param_1;
{
  int vsync_count;
  int result;
  int display_mode = *(int *)0x060A4CAA;               /* interlace mode */
  if (display_mode == 1 || display_mode == 2) {
    if ((*(int *)0x20100061 & 0x10) == 0x10) {         /* VDP status: vsync active */
      vsync_count = *(int *)0x06063608;                 /* vsync frame counter */
      *(int *)0x06063608 = vsync_count + 1;
      if (2 < vsync_count + 1) {
        *(int *)0x06063601 = 1;                         /* vsync flag: ready */
        *(int *)0x06063608 = *(int *)0x06063608 + -1;
      }
    }
    else {
      *(int *)0x06063601 = 0;                           /* vsync flag: reset */
      *(int *)0x06063608 = 0;                           /* vsync counter: reset */
    }
    if ((int)(unsigned int)(unsigned char)*(int *)0x060A4CAB <= *(int *)0x060A4CB8) {
      *(int *)0x060A4CB8 = 0;                           /* frame counter: reset */
      if (*(int *)0x060A4CB4 < (int)(unsigned int)*(unsigned short *)0x060A4CAC) {
        *(int *)0x06063600 = *(int *)0x06063600 + 1;    /* interlace field counter */
        if (2 < (unsigned char)*(int *)0x06063600) {
          FUN_0603a766();                               /* interlace field swap */
          *(int *)0x06063600 = *(int *)0x06063600 + -1;
        }
      }
      else {
        *(int *)0x06063600 = 0;                         /* field counter: reset */
      }
      /* rotate 5-slot display config ring buffer */
      *(int *)0x060A4CC4 = *(int *)0x060A4CE8;         /* slot[1] = slot[4] */
      *(int *)0x060A4CE8 = *(int *)0x060A4C98;         /* slot[4] = slot[0] (base) */
      *(int *)0x060A4C98 = *(int *)0x060A4CC4;         /* slot[0] = slot[1] */
      *(int *)0x060A4CC4 = *(int *)0x060A4CC0;         /* slot[1] = slot[3] */
      *(int *)0x060A4CC0 = *(int *)0x060A4CBC;         /* slot[3] = slot[2] */
      result = *(int *)0x060A4CC4;
      *(int *)0x060A4CBC = result;                      /* slot[2] = slot[1] */
      *param_1 = result;
      FUN_0603a6c0();                                   /* commit display config */
      result = FUN_0603a72c();                          /* query display mode */
      return result;
    }
    *(int *)0x060A4CB8 = *(int *)0x060A4CB8 + 1;       /* frame counter++ */
    result = 0;
  }
  else {
    *param_1 = 0;
    result = 1;
  }
  return result;
}

/* smpc_check_version -- Check SMPC firmware version register.
 * If SMPC area pointer (0x060A4CEC) is >= 0x20100061 AND
 * the firmware byte at 0x20100061 has bit 5 set, mark version=2. */
void FUN_06039fe8(void)
{
    if ((0x20100061 <= *(char **)0x060A4CEC) &&
        ((*(int *)0x20100061 & 0x20) == 0x20)) {
        *(int *)0x060A4CF4 = 2;
    }
}
