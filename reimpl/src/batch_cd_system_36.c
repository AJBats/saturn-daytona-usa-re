#include "game.h"

extern int DAT_06036832;
extern int DAT_06036a0e;
extern int DAT_06036fba;
extern int DAT_06036fbc;
extern int DAT_06036fbe;
extern int DAT_06036fc0;
extern int DAT_06036fc2;
extern int DAT_06037078;
extern int DAT_0603707a;
extern int DAT_0603707c;
extern int DAT_0603707e;
extern int DAT_06037154;
extern int DAT_06037156;
extern int DAT_0603728e;
extern int DAT_06037362;
extern int DAT_0603743a;
extern int DAT_06037532;
extern int DAT_06037534;
extern int DAT_06037536;
extern int DAT_060376a4;
extern int DAT_060376a6;
extern int DAT_060376a8;
extern int DAT_060378f8;
extern int DAT_060378fa;
extern int DAT_060378fc;
extern int DAT_060378fe;
extern int DAT_06037b10;
extern int DAT_06037c8e;
extern int DAT_06037c90;
extern int DAT_06037c92;
extern int DAT_06037c94;
extern int DAT_06037c96;
extern int FUN_06036650();
extern int PTR_DAT_060368d0;
extern int PTR_DAT_06036a8c;
extern int PTR_DAT_06036fc4;
extern int PTR_DAT_06037158;
extern int PTR_DAT_06037364;
extern int PTR_DAT_0603743c;
extern int PTR_DAT_06037900;
extern int PTR_DAT_06037c98;
extern void FUN_06036d94();
extern void FUN_06036d14();
extern void FUN_06036cb0();
extern void FUN_06036be4();

/* shift_right_large_dispatch -- Arithmetic right shift for counts > 8.
 * Dispatches through offset table at 0x0603603C indexed by in_r1.
 * Target stubs at 0x06036086 handle specific shift amounts. */
void FUN_06036068()
{
  int in_r1 = 0;

  (*(int(*)())(0x06036086 + *(char *)(0x0603603C + in_r1)))();
  return;
}

/* memmove_impl -- Overlap-safe byte-level memory copy (memmove).
 * If dest < src: copies forward (ascending addresses).
 * If dest > src: copies backward (descending addresses) to handle overlap.
 * Returns param_1 (dest pointer). */
char * FUN_060360fc(char *param_1, char *param_2, unsigned int param_3)
{
  char uVar1;
  unsigned int uVar2;
  char *puVar3;

  if (param_1 != param_2) {
    if (param_1 < param_2) {
      uVar2 = 0;
      puVar3 = param_1;
      if (param_3 != 0) {
        do {
          uVar1 = *param_2;
          param_2 = param_2 + 1;
          uVar2 = uVar2 + 1;
          *puVar3 = uVar1;
          puVar3 = puVar3 + 1;
        } while (uVar2 < param_3);
      }
    } else {
      puVar3 = param_1 + param_3;
      param_2 = param_2 + param_3;
      uVar2 = 0;
      if (param_3 != 0) {
        do {
          param_2 = param_2 + -1;
          uVar2 = uVar2 + 1;
          puVar3 = puVar3 + -1;
          *puVar3 = *param_2;
        } while (uVar2 < param_3);
      }
    }
  }
  return param_1;
}

/* cd_cmd_set_filter -- CD-Block command 0x30: Set CD connection filter.
 * param_1: filter number. Sends via cd_status_full_read with flag=0x40. */
void FUN_06036144(char param_1)
{
    char buf[8];
    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x30;
    buf[4] = param_1;
    (*(int(*)())0x06035EC8)(0x40, buf);
}

/* cd_cmd_set_filter_range -- CD-Block command 0x40: Set filter range.
 * Packs cmd=0x40 with param_2 (start FAD) and param_1+param_3 (end FAD). */
void FUN_060361fc(char param_1, int param_2, int param_3)
{
    int buf[2];
    (*(int(*)())0x06035E90)(buf);
    buf[0] = (0x40 << 24) | (param_2 & 0xFFFFFF);
    buf[1] = (param_1 << 24) | (param_3 & 0xFFFFFF);
    (*(int(*)())0x06035EC8)(0x40, buf);
}

/* cd_cmd_set_filter_mode -- CD-Block command 0x42: Set filter mode.
 * Packs 6 filter parameter bytes from param_2 into command buffer
 * (reordered: [1][2][4] → bytes 1-3, [0][3][5] → bytes 5-7),
 * sets filter number to param_1 (byte 4), sends with flag 0x40. */
void FUN_060362a8(char param_1, char *param_2)
{
  char local_14;
  char uStack_13, uStack_12, uStack_11;
  char uStack_10, uStack_f, uStack_e, uStack_d;

  (*(int(*)())0x06035E90)(&local_14);
  local_14 = 0x42;              /* command: set filter mode */
  uStack_13 = param_2[1];
  uStack_12 = param_2[2];
  uStack_11 = param_2[4];
  uStack_f = *param_2;
  uStack_e = param_2[3];
  uStack_d = param_2[5];
  uStack_10 = param_1;         /* filter number */
  (*(int(*)())0x06035EC8)(0x40, &local_14);
}

/* cd_cmd_set_cddev_conn -- CD-Block command 0x44: Set CD device connection.
 * param_1: device, param_2: connection filter. */
/* FUN_06036380 -- original binary (8 bytes) */
__asm__(
    ".section .text.FUN_06036380, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06036380\n"
    ".type _FUN_06036380, @function\n"
    "_FUN_06036380:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x53, 0x2F, 0xD6, 0x6D, 0x43\n"  /* 0x06036380 */
);


/* cd_cmd_get_filter_conn -- CD-Block command 0x45: Get filter connection.
 * Queries connection info for filter param_1.
 * Returns connection value (byte) in *param_2. */
int FUN_060363bc(char param_1, unsigned int *param_2)
{
  int uVar1;
  char uStack_1c;
  unsigned char bStack_1b;
  char local_14[4];
  char uStack_10;

  (*(int(*)())0x06035E90)(local_14);
  local_14[0] = 0x45;           /* get filter connection */
  uStack_10 = param_1;          /* filter number */
  uVar1 = (*(int(*)())0x06035EA2)(0, local_14, &uStack_1c);
  *param_2 = (unsigned int)bStack_1b;
  return uVar1;
}

/* cd_cmd_set_sector_size -- CD-Block command 0x46: Set sector read size.
 * param_1: partition, param_2: get size, param_3: put size, param_4: copy size.
 * Sends with flag 0x40. */
/* FUN_06036414 -- original binary (16 bytes) */
__asm__(
    ".section .text.FUN_06036414, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06036414\n"
    ".type _FUN_06036414, @function\n"
    "_FUN_06036414:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x53, 0x2F, 0xD6, 0x6D, 0x73, 0x2F, 0xC6, 0x6C, 0x43, 0x2F, 0xB6, 0x6B, 0x63\n"  /* 0x06036414 */
);


/* cd_cmd_set_filter_subhdr -- CD-Block command 0x48: Set filter subheader.
 * param_1: subheader mode, param_2: filter number. */
void FUN_060364d4(char param_1, char param_2)
{
    char buf[8];
    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x48;
    buf[1] = param_1;
    buf[4] = param_2;
    (*(int(*)())0x06035EC8)(0x40, buf);
}

/* cd_cmd_get_buffer_size -- CD-Block command 0x50: Get CD buffer size info.
 * Returns 3 values: *param_3 = total sectors, *param_2 = free sectors,
 * *param_1 = max selectable partition. */
int FUN_06036518(unsigned int *param_1, unsigned int *param_2, unsigned int *param_3)
{
  int uVar1;
  char auStack_20[2];
  unsigned short uStack_1e;
  unsigned char bStack_1c;
  unsigned short uStack_1a;
  char local_18[12];

  (*(int(*)())0x06035E90)(local_18);
  local_18[0] = 0x50;           /* get buffer size */
  uVar1 = (*(int(*)())0x06035EA2)(0, local_18, auStack_20);
  *param_3 = (unsigned int)uStack_1e;    /* total sectors */
  *param_2 = (unsigned int)bStack_1c;    /* free sectors */
  *param_1 = (unsigned int)uStack_1a;    /* max partition */
  return uVar1;
}

/* cd_cmd_get_partition_size -- CD-Block command 0x51: Get partition sector count.
 * param_1: partition number. Returns sector count in *param_2. */
/* FUN_06036572 -- original binary (6 bytes) */
__asm__(
    ".section .text.FUN_06036572, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06036572\n"
    ".type _FUN_06036572, @function\n"
    "_FUN_06036572:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x6E, 0x43\n"  /* 0x06036572 */
);


/* cd_cmd_calc_actual_size -- CD-Block command 0x52: Calculate actual data size.
 * param_1: partition, param_2: sector offset, param_3: sector count.
 * Sends with flag 0x40. */
void FUN_060365c4(char param_1, short param_2, short param_3)
{
  char local_18[2];
  short uStack_16;
  char uStack_14;
  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);
  local_18[0] = 0x52;           /* calc actual size */
  uStack_16 = param_2;          /* sector offset */
  uStack_14 = param_1;          /* partition */
  uStack_12 = param_3;          /* sector count */
  (*(int(*)())0x06035EC8)(0x40, local_18);
}

/* cd_cmd_get_toc_entry -- CD-Block command 0x53: Get TOC entry.
 * Reads a single TOC entry, masks to 24-bit FAD. */
int FUN_0603660e(unsigned int *param_1)
{
    int result;
    unsigned int response[2];
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x53;
    result = FUN_06036650(buf, response);
    *param_1 = response[0] & 0x00FFFFFF;
    return result;
}

/* cd_cmd_send_with_check -- Send CD command only if HIRQ bit 6 is set.
 * Returns -1 if not ready, otherwise sends via cd_status_read. */
/* FUN_06036650 -- original binary (46 bytes) */
__asm__(
    ".section .text.FUN_06036650, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06036650\n"
    ".type _FUN_06036650, @function\n"
    "_FUN_06036650:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43, 0x2F, 0xD6, 0x4F, 0x22, 0xD3, 0x26, 0x43, 0x0B, 0x6D, 0x53, 0x64, 0x03\n"  /* 0x06036650 */
    ".byte 0x60, 0x4D, 0xC8, 0x40, 0x8B, 0x01, 0xA0, 0x06, 0xE0, 0xFF, 0x66, 0xD3, 0x65, 0xE3, 0xD3, 0x22\n"  /* 0x06036660 */
    ".byte 0x43, 0x0B, 0xE4, 0x00, 0x64, 0x03, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06036670 */
);


/* cd_cmd_put_sector -- CD-Block command 0x61: Put sector data to buffer.
 * param_1: partition, param_2: sector offset, param_3: sector count.
 * Sends with flag 0x80 (data transfer mode). */
void FUN_060367e8(char param_1, short param_2, short param_3)
{
  char local_18[2];
  short uStack_16;
  char uStack_14;
  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);
  local_18[0] = 0x61;           /* put sector */
  uStack_16 = param_2;          /* sector offset */
  uStack_14 = param_1;          /* partition */
  uStack_12 = param_3;          /* sector count */
  (*(int(*)())0x06035EC8)(0x80, local_18);
}

/* cd_cmd_copy_sector -- CD-Block command 0x62: Copy sector within buffer.
 * param_1: partition, param_2: source offset, param_3: dest offset.
 * Sends with flag 0x80 (data transfer mode). */
void FUN_0603683c(char param_1, short param_2, short param_3)
{
  char local_18[2];
  short uStack_16;
  char uStack_14;
  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);
  local_18[0] = 0x62;           /* copy sector */
  uStack_16 = param_2;          /* source offset */
  uStack_14 = param_1;          /* partition */
  uStack_12 = param_3;          /* dest offset */
  (*(int(*)())0x06035EC8)(0x80, local_18);
}

/* cd_cmd_move_sector -- CD-Block command 0x66: Move sector between partitions.
 * param_1: source partition, param_2: source offset, param_3: sector count,
 * param_4: dest partition. Sends with flag 0x100. */
void FUN_0603697c(char param_1, short param_2, short param_3, char param_4)
{
  char local_1c;
  char uStack_1b;
  short uStack_1a;
  char uStack_18;
  short uStack_16;

  (*(int(*)())0x06035E90)(&local_1c);
  local_1c = 0x66;              /* move sector */
  uStack_1b = param_4;          /* dest partition */
  uStack_1a = param_2;          /* source offset */
  uStack_18 = param_1;          /* source partition */
  uStack_16 = param_3;          /* sector count */
  (*(int(*)())0x06035EC8)(0x100, &local_1c);

  return;

}

/* cd_cmd_set_sector_length -- CD-Block command 0x70: Set sector data length.
 * param_1: get/put selector, param_2: sector size (masked to 24-bit).
 * Sends with flag=0x200 (data transfer command class). */
void FUN_06036a1c(char param_1, int param_2)
{
    char buf[8];
    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x70;
    *(int *)(buf + 4) = (param_1 << 24) | (param_2 & 0xFFFFFF);
    (*(int(*)())0x06035EC8)(0x200, buf);
}

/* cd_cmd_get_calc_result -- CD-Block command 0x72: Get calculation result.
 * Returns 3 values: *param_2 = word count, *param_3 = status byte (high),
 * *param_1 = sector count (24-bit). */
int FUN_06036a98(unsigned int *param_1, unsigned int *param_2, unsigned int *param_3)
{
  int uVar1;
  char auStack_20[2];
  unsigned short uStack_1e;
  unsigned int uStack_1c;
  char local_18[12];

  (*(int(*)())0x06035E90)(local_18);
  local_18[0] = 0x72;           /* get calc result */
  uVar1 = (*(int(*)())0x06035EA2)(0, local_18, auStack_20);
  *param_2 = (unsigned int)uStack_1e;       /* word count */
  *param_3 = uStack_1c >> 0x18;             /* status byte */
  *param_1 = uStack_1c & 0x00FFFFFF;        /* sector count */
  return uVar1;
}

/* cd_cmd_get_file_info -- CD-Block command 0x73: Get file system info.
 * param_1: file index. Sends query, then reads response data (24-bit
 * word count) via cd_sector_read_words into param_2 buffer. */
int FUN_06036af2(unsigned int param_1, int param_2)
{
  int iVar1;
  unsigned int local_1c[2];
  char local_14[4];
  unsigned int uStack_10;

  (*(int(*)())0x06035E90)(local_14);
  local_14[0] = 0x73;           /* get file info */
  uStack_10 = (unsigned int)param_1;
  iVar1 = (*(int(*)())0x06035EA2)(0, local_14, local_1c);
  if (iVar1 == 0) {
    iVar1 = (*(int(*)())0x06035CBC)(local_1c[0] & 0x00FFFFFF, param_2);
  }
  return iVar1;
}





/* strncpy_impl -- Copy string with length limit and null padding.
 * Copies up to param_3 bytes from param_2 to param_1 (stops at null).
 * Remaining bytes are zero-filled. Returns param_1.
 * Equivalent to standard strncpy. */
char * FUN_06036ddc(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{
    unsigned int i = 0;
    char *dst = param_1;

    /* Copy source string up to limit */
    for (; (i < param_3 && (*param_2 != '\0')); param_2 = param_2 + 1) {
        *dst = *param_2;
        i = i + 1;
        dst = dst + 1;
    }
    /* Zero-pad remainder */
    for (; i < param_3; i = i + 1) {
        *dst = '\0';
        dst = dst + 1;
    }
    return param_1;
}

long long FUN_06036e1c()
{
  int *in_r0;
  int *piVar1;
  int *in_r1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;

  iVar4 = *in_r0;
  iVar5 = *in_r1;
  while( 1 ) {
    piVar2 = in_r1 + 1;
    piVar1 = in_r0 + 1;
    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||
        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;
    piVar3 = piVar2;
    if (iVar5 != iVar4) goto LAB_06036e82;
    iVar5 = *piVar2;
    piVar2 = in_r1 + 2;
    iVar4 = *piVar1;
    piVar1 = in_r0 + 2;
    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||
        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;
    piVar3 = piVar2;
    if (iVar5 != iVar4) goto LAB_06036e82;
    iVar5 = *piVar2;
    piVar2 = in_r1 + 3;
    iVar4 = *piVar1;
    piVar1 = in_r0 + 3;
    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||
        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;
    piVar3 = piVar2;
    if (iVar5 != iVar4) goto LAB_06036e82;
    iVar5 = *piVar2;
    piVar2 = in_r1 + 4;
    iVar4 = *piVar1;
    piVar1 = in_r0 + 4;
    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||
        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;
    piVar3 = piVar2;
    if (iVar5 != iVar4) goto LAB_06036e82;
    iVar4 = *piVar1;
    iVar5 = *piVar2;
    in_r0 = piVar1;
    in_r1 = piVar2;
  }
  iVar4 = (int)*(char *)(piVar1 + -1);
  iVar5 = (int)*(char *)(piVar2 + -1);
  piVar3 = (int *)((int)piVar2 + -3);
  if ((iVar5 != 0) && (iVar5 == iVar4)) {
    iVar4 = (int)*(char *)((int)piVar1 + -3);
    iVar5 = (int)*(char *)piVar3;
    piVar3 = (int *)((int)piVar2 + -2);
    if ((iVar5 != 0) && (iVar5 == iVar4)) {
      iVar4 = (int)*(char *)((int)piVar1 + -2);
      iVar5 = (int)*(char *)piVar3;
      piVar3 = (int *)((int)piVar2 + -1);
      if ((iVar5 != 0) && (iVar5 == iVar4)) {
        iVar4 = (int)*(char *)((int)piVar1 + -1);
        iVar5 = (int)*(char *)piVar3;
        piVar3 = piVar2;
      }
    }
  }
LAB_06036e82:
  return CONCAT44(piVar3,iVar4 - iVar5);
}

/* vdp2_bitmap_load -- Load bitmap data to VDP2 VRAM and configure display.
 * Masks address to 19-bit VDP2 VRAM offset, stores in coordinate table
 * (+0x3C at 0x060A3DF8). Calls DMA copy (0x06038A48) to VDP2 VRAM
 * (0x25E00000 | offset) with doubled plane index. Shifts stored address
 * right by 1 for character pattern alignment; sets bit 31 for plane != 1.
 * Only processes if param_2 matches plane 1 or current active plane
 * (0x060635B0). Triggers VDP1_BATCH_FLAG for next frame commit. */
void vdp2_bitmap_load(param_1, param_2, param_3)
    unsigned int param_1;
    unsigned short param_2;
    int param_3;
{
  char *coord_tbl = (char *)0x060A3DF8;                /* coordinate table */
  if ((param_2 == 1) || (param_2 == *(unsigned short *)0x060635B0)) {
    param_1 = param_1 & (unsigned int)0x0007FFFF;      /* 19-bit VRAM offset */
    *(unsigned int *)(coord_tbl + 0x3c) = param_1;
    (*(int(*)())0x06038A48)(param_1 | (unsigned int)0x25E00000, param_3,
                            (unsigned int)param_2 << 1); /* DMA to VDP2 VRAM */
    *(unsigned int *)(coord_tbl + 0x3c) = *(unsigned int *)(coord_tbl + 0x3c) >> 1;
    if (param_2 != 1) {
      *(unsigned int *)(coord_tbl + 0x3c) = *(unsigned int *)(coord_tbl + 0x3c) | 0x80000000;
    }
    if (VDP1_BATCH_FLAG == 0) {
      VDP1_BATCH_FLAG = 1;
    }
  }
  return;
}

/* vdp2_tv_mode_config -- Configure VDP2 TV mode, interlace, and resolution.
 * param_1: color depth (0=default, 2=hi-color 0x80, 3=true-color 0xC0,
 *   mode 3 also doubles active plane count).
 * param_2: horizontal resolution (0=320px, 1=352px bit 0x10, 2=640px bit 0x20).
 *   Sets active plane count at 0x060635B0.
 * param_3: interlace/scan mode (0-7), configures BIOS display mode via
 *   BIOS_FUNC_0320 (0=non-interlace, 1=interlace), sets line count at
 *   0x060635AE, and encodes mode bits 0-3 of CHCTLA (0x060A3D88).
 *   Modes 4-7 additionally set plane override (DAT_06036fba).
 * Triggers VDP1_BATCH_FLAG for next frame commit. */
void vdp2_tv_mode_config(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{
  short plane_override;
  unsigned short chctla_bits;
  char *chctla_reg = (char *)0x060A3D88;               /* CHCTLA shadow */
  char *active_planes = (char *)0x060635B0;             /* active plane count */
  int *line_count = (int *)0x060635AE;                  /* line count setting */
  int bios_mode = *(int *)0x06000324;                   /* current BIOS display mode */
  plane_override = DAT_06036fba;

  /* --- Horizontal resolution (bits 4-5 of CHCTLA) --- */
  *(unsigned short *)chctla_reg = *(unsigned short *)chctla_reg & (unsigned short)0x0000FFCF;
  if (param_2 == '\0') {                                /* 320px normal */
    *(short *)active_planes = DAT_06036fbc;
  } else {
    if (param_2 == '\x01') {                            /* 352px */
      *(short *)active_planes = DAT_06036fbe;
      chctla_bits = *(unsigned short *)chctla_reg | 0x10;
    } else {
      if (param_2 != '\x02') goto LAB_06036f58;        /* 640px hi-res */
      *(short *)active_planes = DAT_06036fc0;
      chctla_bits = *(unsigned short *)chctla_reg | 0x20;
    }
    *(unsigned short *)chctla_reg = chctla_bits;
  }
LAB_06036f58:
  /* --- Color depth (bits 6-7 of CHCTLA) --- */
  *(unsigned short *)chctla_reg = *(unsigned short *)chctla_reg & (unsigned short)0x0000FF3F;
  if (param_1 != '\0') {
    if (param_1 == '\x02') {                            /* hi-color mode */
      chctla_bits = *(unsigned short *)chctla_reg | 0x80;
    } else {
      if (param_1 != '\x03') goto LAB_06036f86;        /* true-color mode */
      *(short *)active_planes = *(short *)active_planes + *(short *)active_planes; /* 2x planes */
      chctla_bits = *(unsigned short *)chctla_reg | 0xc0;
    }
    *(unsigned short *)chctla_reg = chctla_bits;
  }
LAB_06036f86:
  /* --- Interlace/scan mode (bits 0-3 of CHCTLA) --- */
  *(unsigned short *)chctla_reg = *(unsigned short *)chctla_reg & (unsigned short)0x0000FFF0;
  if (param_3 == '\0') {                                /* mode 0: non-interlace, standard */
    if (bios_mode != 0) {
      (*(int(*)())(BIOS_FUNC_0320))(0);
    }
    *(short *)line_count = DAT_06036fc2;
  } else {
    if (param_3 == '\x01') {                            /* mode 1: interlace */
      if (bios_mode != 1) {
        (*(int(*)())(BIOS_FUNC_0320))(1);
      }
      *(short *)line_count = PTR_DAT_06036fc4;
      chctla_bits = *(unsigned short *)chctla_reg | 1;
    }
    else if (param_3 == '\x02') {                       /* mode 2: non-interlace, alt lines */
      if (bios_mode != 0) {
        (*(int(*)())(BIOS_FUNC_0320))(0);
      }
      *(short *)line_count = DAT_06037078;
      chctla_bits = *(unsigned short *)chctla_reg | 2;
    }
    else if (param_3 == '\x03') {                       /* mode 3: interlace, alt lines */
      if (bios_mode != 1) {
        (*(int(*)())(BIOS_FUNC_0320))(1);
      }
      *(short *)line_count = DAT_0603707a;
      chctla_bits = *(unsigned short *)chctla_reg | 3;
    }
    else if (param_3 == '\x04') {                       /* mode 4: non-interlace + override */
      if (bios_mode != 0) {
        (*(int(*)())(BIOS_FUNC_0320))(0);
      }
      *(short *)line_count = DAT_0603707c;
      *(short *)active_planes = plane_override;
      chctla_bits = *(unsigned short *)chctla_reg | 4;
    }
    else if (param_3 == '\x05') {                       /* mode 5: interlace + override */
      if (bios_mode != 1) {
        (*(int(*)())(BIOS_FUNC_0320))(1);
      }
      *(short *)line_count = DAT_0603707e;
      *(short *)active_planes = plane_override;
      chctla_bits = *(unsigned short *)chctla_reg | 5;
    }
    else if (param_3 == '\x06') {                       /* mode 6: non-interlace + override */
      if (bios_mode != 0) {
        (*(int(*)())(BIOS_FUNC_0320))(0);
      }
      *(short *)line_count = DAT_06037078;
      *(short *)active_planes = plane_override;
      chctla_bits = *(unsigned short *)chctla_reg | 6;
    }
    else {
      if (param_3 != '\a') goto LAB_060370a0;          /* mode 7: interlace + override */
      if (bios_mode != 1) {
        (*(int(*)())(BIOS_FUNC_0320))(1);
      }
      *(short *)line_count = DAT_0603707a;
      *(short *)active_planes = plane_override;
      chctla_bits = *(unsigned short *)chctla_reg | 7;
    }
    *(unsigned short *)chctla_reg = chctla_bits;
  }
LAB_060370a0:
  if (VDP1_BATCH_FLAG == 0) {
    VDP1_BATCH_FLAG = 1;
  }
  return;
}

/* vdp1_texture_config -- Configure VDP1 texture/CLUT banks.
 * Sets up texture mapping, color lookup tables, and UV coordinates
 * from a configuration struct pointed to by param_1.
 *
 * State registers:
 *   0x060A3D88 = VDP1 mode shadow registers
 *   0x060A3E38 = texture bank state
 *   0x060A4C44 = CLUT output pair (2 ints, cleared on entry)
 *   0x060A4C4C = config cache (8 bytes from param_1)
 *
 * Part of VDP1 texture management subsystem (#15). */
unsigned int vdp1_texture_config(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned short uVar7;

  int iVar8;

  int *piVar9;

  unsigned char bVar10;

  puVar5 = (char *)0x060A4C4C;

  puVar4 = (char *)0x060A3E38;

  puVar3 = (char *)0x060A3D88;

  puVar2 = (int *)0x060A4C44;

  puVar1 = (char *)0x0000FF00;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar2 + 4) = 0;

  *(int *)puVar5 = *param_1;

  *(int *)(puVar5 + 4) = param_1[1];

  *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & DAT_06037154;

  if (*(char *)(param_1 + 2) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | DAT_06037156;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FEFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  if (*(char *)((int)param_1 + 9) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | PTR_DAT_06037158;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FDFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  iVar8 = 0;

  bVar10 = 0;

  uVar7 = (unsigned short)puVar1;

  if (*(unsigned char *)((int)param_1 + 10) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC | (unsigned short)*(unsigned char *)((int)param_1 + 10)

    ;

    if (*(char *)((int)param_1 + 10) == '\x01') {

      bVar10 = *(int *)puVar5 == 0;

      if (!(int)bVar10) {

        *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC;

      }

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

      *(char **)puVar2 = 0x25E00000 + *(int *)puVar5;

      iVar8 = 1;

    }

  }

  else if (*(char *)((int)param_1 + 10) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(char **)(puVar2 + 4) = 0x25E00000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xb) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3 |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xb) << 2;

    if (*(char *)((int)param_1 + 0xb) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 2;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 1;

        *(char **)puVar2 = 0x25E20000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603728e;

        *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

        iVar8 = iVar8 + 1;

      }

    }

  }

  else if (*(char *)((int)param_1 + 0xb) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037362;

    *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)(param_1 + 3) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF | (unsigned short)*(unsigned char *)(param_1 + 3) << 4;

    if (*(char *)(param_1 + 3) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 3;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 2;

        *(char **)puVar2 = 0x25E40000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_06037364;

        iVar8 = iVar8 + 1;

        *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)(param_1 + 3) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603743a;

    *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xd) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xd) << 6;

    if (*(char *)((int)param_1 + 0xd) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 4;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 3;

        *(char **)puVar2 = 0x25E60000 + *(int *)puVar5;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_0603743c;

        *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)((int)param_1 + 0xd) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037532;

    *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

  }

  uVar6 = *(unsigned int *)(puVar2 + 4);

  if (uVar6 == 0) {

    if (((*(char *)((int)param_1 + 0xe) == '\x01') && (*(int *)0x060A4C44 == 0)) &&

       (iVar8 = (*(int(*)())0x0603C156)(), iVar8 == 1)) {

      uVar6 = (int)*(short *)(puVar3 + 0xe) | (unsigned int)0x00008000;

      *(short *)(puVar3 + 0xe) = (short)uVar6;

      *(char **)puVar2 = (int *)0x25F00800;

    }

    else if ((*(int *)puVar2 == 0) || (*(int *)0x060A4C59 == '\0')) {

      uVar6 = *(unsigned int *)puVar2;

      if (uVar6 == 0) {

        if ((*(int *)puVar5 != 0) && (*(int *)0x060A4C58 != '\0')) {

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

          piVar9 = (int *)puVar5;

          uVar7 = (*(int(*)())0x06034FFC)();

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | uVar7;

          *(char **)puVar2 = 0x25E00000 + *piVar9;

        }

        uVar6 = *(unsigned int *)(puVar5 + 4);

        if ((uVar6 != 0) && (*(int *)0x060A4C59 != '\0')) {

          piVar9 = (int *)(puVar5 + 4);

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

          uVar6 = (*(int(*)())0x06034FFC)();

          uVar6 = (int)*(short *)(puVar4 + 6) | (uVar6 & 0xffff) << 8;

          *(short *)(puVar4 + 6) = (short)uVar6;

          *(char **)(puVar2 + 4) = 0x25E00000 + *piVar9;

        }

      }

    }

    else {

      if (*(int *)(puVar5 + 4) == 0) {

        *(int *)(puVar5 + 4) = *(int *)puVar5 + 0x400;

      }

      if (*(int *)puVar5 == 0) {

        *(int *)puVar5 = (char *)0xffffffff;

      }

      *(int *)(puVar2 + 4) = *(int *)(puVar5 + 4) + *(int *)puVar2;

      *(unsigned short *)(puVar4 + 6) =

           DAT_06037536 & *(unsigned short *)(puVar4 + 6) | *(unsigned short *)(puVar4 + 6) << 8;

      uVar6 = (unsigned int)bVar10;

      if (uVar6 == 1) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFFC;

      }

      else if (uVar6 == 2) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFF3;

      }

      else if (uVar6 == 3) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFCF;

      }

      else {

        if (uVar6 != 4) {

          return uVar6;

        }

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FF3F;

      }

      *(short *)(puVar3 + 0xe) = (short)uVar6;

    }

  }

  return uVar6;

}

/* cd_descriptor_clear -- Zero-initialize a CD transfer descriptor (0x4C bytes). */
int FUN_06037618(desc)
    char *desc;
{
  unsigned int idx;
  unsigned char i;
  desc[0] = 0;
  desc[1] = 0;
  desc[2] = 0;
  desc[3] = 0;
  desc[4] = 0;
  desc[5] = 0;
  i = 0;
  desc[6] = 0;
  desc[8] = 0;
  desc[7] = 0;
  *(short *)(desc + 10) = 0;
  do {
    idx = (unsigned int)i;
    i = i + 1;
    *(int *)(desc + (idx << 2) + 0xc) = 0;  /* clear 16 int slots */
  } while (i < 0x10);
  return 0;
}

void vdp1_command_builder(param_1, param_2)
    unsigned short *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  unsigned short *extraout_r3;

  unsigned short uVar8;

  unsigned short uVar11;

  char *puVar9;

  unsigned short *puVar10;

  char *puVar12;

  unsigned short local_38;

  char *puStack_2c;

  puVar12 = (char *)0x060A3D88;

  puVar4 = (char *)0x060A3DB0;

  uVar3 = DAT_060376a6;

  uVar2 = DAT_060376a4;

  puStack_2c = (char *)0x0;

  local_38 = (unsigned short)param_2[8];

  uVar11 = local_38 << 0xe & DAT_060376a8;

  puVar9 = (char *)(unsigned int)uVar11;

  uVar5 = (unsigned int)param_1 & 0xffff;

  uVar6 = (unsigned short)0x00008000;

  uVar7 = (unsigned short)0x0000BFFF;

  if (uVar5 == 1) {

    bVar1 = *param_2;

    *(unsigned short *)(0x060A3D88 + 0x20) =

         *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFEF;

    *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 4;

    uVar8 = (unsigned short)param_2[1] << 8 & DAT_06037c8e;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FEFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar8;

    *(short *)(puVar4 + 0x10) = *(short *)(param_2 + 10);

    bVar1 = param_2[2];

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar2;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | (unsigned short)bVar1 << 0xf & uVar6;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar7;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | uVar11;

    uVar6 = (unsigned short)param_2[3] << 8 & DAT_06037c90;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FCFF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[7] << 10 & DAT_06037c92;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000F3FF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[4] << 10 & DAT_06037c94;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FBFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[5] << 0xc & DAT_06037c96;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x00008FFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037c98;

    param_1 = (unsigned short *)(unsigned int)uVar6;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FDFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    puVar12 = (void *)0x00000008;

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x01')) {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

      puStack_2c = puVar4 + 0x38;

    }

    else if (*(int *)0x060A4C58 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

    }

    else if (*(int *)0x060A4C59 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

    }

  }

  else if (uVar5 == 2) {

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x02')) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFDF;

      if (*param_2 != 0) {

        *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | 0x20;

      }

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

      puVar12 = (void *)0x00000008;

    }

  }

  else {

    if (uVar5 == 4) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | bVar1 & 1;

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[4];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF3;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 3) << 2;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      bVar1 = param_2[6];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FFF0;

      puVar9 = puVar4 + 0x18;

    }

    else if (uVar5 == 8) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FDFD;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | DAT_060378f8;

      uVar8 = (unsigned short)param_2[1] << 8 & DAT_060378fa;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FEFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar8;

      *(short *)(puVar4 + 10) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar2;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar7;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFF3;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 2;

      uVar6 = (unsigned short)param_2[4] << 10 & DAT_060378fc;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000F3FF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[5] << 0xc & DAT_060378fe;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000CFFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037900;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FDFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FF0F;

      puVar9 = puVar4 + 0x1c;

    }

    else if (uVar5 == 0x10) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFB;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 2;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | bVar1 & 1;

      *(short *)(puVar4 + 0xc) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar2;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar7;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFCF;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 4;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000F0FF;

      puVar9 = puVar4 + 0x20;

    }

    else {

      if (uVar5 != 0x20) goto LAB_06037e88;

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFF7;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 3;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFEF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 4;

      *(short *)(puVar4 + 0xe) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar2;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar7;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FF3F;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 6;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFDF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 5;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & DAT_06037b10;

      puVar9 = puVar4 + 0x24;

    }

    param_1 = (unsigned short *)(puVar4 + 0x14);

    puVar12 = (void *)0x00000002;

  }

LAB_06037e88:

  if (param_2[6] == 1) {

    uVar6 = (*(int(*)())0x06035280)();

  }

  else {

    (*(int(*)())0x06035F44)();

    uVar6 = (*(int(*)())0x06035280)();

  }

  *param_1 = *param_1 | uVar6;

  uVar6 = 0;

  if (((unsigned int)puVar12 & 0xffff) != 0) {

    do {

      uVar7 = (*(int(*)())0x06035F44)();

      *extraout_r3 = uVar7 & 0x3f;

      uVar7 = (*(int(*)())0x06035F44)();

      *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) =

           *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) | (uVar7 & 0x3f) << 8 & uVar3;

      uVar6 = uVar6 + 1;

    } while ((unsigned int)uVar6 < ((unsigned int)puVar12 & 0xffff));

  }

  if (puStack_2c != (char *)0x0) {

    *param_1 = *param_1 & 0xf;

    *param_1 = *param_1 | *param_1 << 4;

    uVar5 = 0;

    if (((unsigned int)puVar12 & 0xffff) != 0) {

      do {

        puVar10 = (unsigned short *)(puStack_2c + ((uVar5 & 0xffff) << 1));

        uVar6 = (*(int(*)())0x06035F44)();

        *puVar10 = uVar6 & 0x3f;

        uVar6 = (*(int(*)())0x06035F44)();

        uVar5 = uVar5 + 1;

        *puVar10 = *puVar10 | (uVar6 & 0x3f) << 8 & uVar3;

      } while ((uVar5 & 0xffff) < ((unsigned int)puVar12 & 0xffff));

    }

  }

  if (VDP1_BATCH_FLAG == 0) {

    VDP1_BATCH_FLAG = 1;

  }

  return;

}

/* --- FUN_06036E90 (L1 import from src/FUN_06036E90.c) --- */

void FUN_06036e90(param_1, param_2, param_3)
    unsigned int param_1;
    unsigned short param_2;
    int param_3;
{

  char *puVar1;

  puVar1 = (char *)0x060A3DF8;

  if ((param_2 == 1) || (param_2 == *(unsigned short *)0x060635B0)) {

    param_1 = param_1 & (unsigned int)0x0007FFFF;

    *(unsigned int *)(0x060A3DF8 + 0x3c) = param_1;

    (*(int(*)())0x06038A48)(param_1 | (unsigned int)0x25E00000,param_3,(unsigned int)param_2 << 1);

    *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) >> 1;

    if (param_2 != 1) {

      *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) | 0x80000000;

    }

    if (*(short *)0x060635AC == 0) {

      *(short *)0x060635AC = 1;

    }

  }

  return;

}

/* --- FUN_06036F0C (L1 import from src/FUN_06036F0C.c) --- */

void FUN_06036f0c(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  int iVar6;

  puVar4 = (char *)0x060A3D88;

  puVar3 = (char *)0x060635B0;

  puVar2 = (char *)0x060635AE;

  uVar1 = DAT_06036fba;

  iVar6 = *(int *)0x06000324;

  *(unsigned short *)0x060A3D88 = *(unsigned short *)0x060A3D88 & (unsigned short)0x0000FFCF;

  if (param_2 == '\0') {

    *(short *)puVar3 = DAT_06036fbc;

  }

  else {

    if (param_2 == '\x01') {

      *(short *)puVar3 = DAT_06036fbe;

      uVar5 = *(unsigned short *)puVar4 | 0x10;

    }

    else {

      if (param_2 != '\x02') goto LAB_06036f58;

      *(short *)puVar3 = DAT_06036fc0;

      uVar5 = *(unsigned short *)puVar4 | 0x20;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f58:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF3F;

  if (param_1 != '\0') {

    if (param_1 == '\x02') {

      uVar5 = *(unsigned short *)puVar4 | 0x80;

    }

    else {

      if (param_1 != '\x03') goto LAB_06036f86;

      *(short *)puVar3 = *(short *)puVar3 + *(short *)puVar3;

      uVar5 = *(unsigned short *)puVar4 | 0xc0;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f86:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF0;

  if (param_3 == '\0') {

    if (iVar6 != 0) {

      (*(int(*)())(*(int *)0x06000320))(0);

    }

    *(short *)puVar2 = DAT_06036fc2;

  }

  else {

    if (param_3 == '\x01') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = PTR_DAT_06036fc4;

      uVar5 = *(unsigned short *)puVar4 | 1;

    }

    else if (param_3 == '\x02') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      uVar5 = *(unsigned short *)puVar4 | 2;

    }

    else if (param_3 == '\x03') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      uVar5 = *(unsigned short *)puVar4 | 3;

    }

    else if (param_3 == '\x04') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_0603707c;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 4;

    }

    else if (param_3 == '\x05') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707e;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 5;

    }

    else if (param_3 == '\x06') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 6;

    }

    else {

      if (param_3 != '\a') goto LAB_060370a0;

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 7;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_060370a0:

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}

/* --- FUN_060370E4 (L1 import from src/FUN_060370E4.c) --- */

#if 0 /* FUN_060370E4 -- replaced by ASM import of original bytes */
unsigned int FUN_060370e4(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned short uVar7;

  int iVar8;

  int *piVar9;

  unsigned char bVar10;

  puVar5 = (char *)0x060A4C4C;

  puVar4 = (char *)0x060A3E38;

  puVar3 = (char *)0x060A3D88;

  puVar2 = (char *)0x060A4C44;

  puVar1 = (char *)0x0000FF00;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar2 + 4) = 0;

  *(int *)puVar5 = *param_1;

  *(int *)(puVar5 + 4) = param_1[1];

  *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & DAT_06037154;

  if (*(char *)(param_1 + 2) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | DAT_06037156;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FEFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  if (*(char *)((int)param_1 + 9) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | PTR_DAT_06037158;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FDFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  iVar8 = 0;

  bVar10 = 0;

  uVar7 = (unsigned short)puVar1;

  if (*(unsigned char *)((int)param_1 + 10) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC | (unsigned short)*(unsigned char *)((int)param_1 + 10)

    ;

    if (*(char *)((int)param_1 + 10) == '\x01') {

      bVar10 = *(int *)puVar5 == 0;

      if (!(int)bVar10) {

        *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC;

      }

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

      *(char **)puVar2 = 0x25E00000 + *(int *)puVar5;

      iVar8 = 1;

    }

  }

  else if (*(char *)((int)param_1 + 10) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(char **)(puVar2 + 4) = 0x25E00000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xb) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3 |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xb) << 2;

    if (*(char *)((int)param_1 + 0xb) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 2;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 1;

        *(char **)puVar2 = 0x25E20000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603728e;

        *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

        iVar8 = iVar8 + 1;

      }

    }

  }

  else if (*(char *)((int)param_1 + 0xb) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037362;

    *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)(param_1 + 3) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF | (unsigned short)*(unsigned char *)(param_1 + 3) << 4;

    if (*(char *)(param_1 + 3) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 3;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 2;

        *(char **)puVar2 = 0x25E40000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_06037364;

        iVar8 = iVar8 + 1;

        *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)(param_1 + 3) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603743a;

    *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xd) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xd) << 6;

    if (*(char *)((int)param_1 + 0xd) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 4;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 3;

        *(char **)puVar2 = 0x25E60000 + *(int *)puVar5;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_0603743c;

        *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)((int)param_1 + 0xd) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037532;

    *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

  }

  uVar6 = *(unsigned int *)(puVar2 + 4);

  if (uVar6 == 0) {

    if (((*(char *)((int)param_1 + 0xe) == '\x01') && (*(int *)0x060A4C44 == 0)) &&

       (iVar8 = (*(int(*)())0x0603C156)(), iVar8 == 1)) {

      uVar6 = (int)*(short *)(puVar3 + 0xe) | (unsigned int)0x00008000;

      *(short *)(puVar3 + 0xe) = (short)uVar6;

      *(char **)puVar2 = (char *)0x25F00800;

    }

    else if ((*(int *)puVar2 == 0) || (*(int *)0x060A4C59 == '\0')) {

      uVar6 = *(unsigned int *)puVar2;

      if (uVar6 == 0) {

        if ((*(int *)puVar5 != 0) && (*(int *)0x060A4C58 != '\0')) {

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

          piVar9 = (int *)puVar5;

          uVar7 = (*(int(*)())0x06034FFC)();

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | uVar7;

          *(char **)puVar2 = 0x25E00000 + *piVar9;

        }

        uVar6 = *(unsigned int *)(puVar5 + 4);

        if ((uVar6 != 0) && (*(int *)0x060A4C59 != '\0')) {

          piVar9 = (int *)(puVar5 + 4);

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

          uVar6 = (*(int(*)())0x06034FFC)();

          uVar6 = (int)*(short *)(puVar4 + 6) | (uVar6 & 0xffff) << 8;

          *(short *)(puVar4 + 6) = (short)uVar6;

          *(char **)(puVar2 + 4) = 0x25E00000 + *piVar9;

        }

      }

    }

    else {

      if (*(int *)(puVar5 + 4) == 0) {

        *(int *)(puVar5 + 4) = *(int *)puVar5 + 0x400;

      }

      if (*(int *)puVar5 == 0) {

        *(int *)puVar5 = (char *)0xffffffff;

      }

      *(int *)(puVar2 + 4) = *(int *)(puVar5 + 4) + *(int *)puVar2;

      *(unsigned short *)(puVar4 + 6) =

           DAT_06037536 & *(unsigned short *)(puVar4 + 6) | *(unsigned short *)(puVar4 + 6) << 8;

      uVar6 = (unsigned int)bVar10;

      if (uVar6 == 1) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFFC;

      }

      else if (uVar6 == 2) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFF3;

      }

      else if (uVar6 == 3) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFCF;

      }

      else {

        if (uVar6 != 4) {

          return uVar6;

        }

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FF3F;

      }

      *(short *)(puVar3 + 0xe) = (short)uVar6;

    }

  }

  return uVar6;

}
#endif

/* --- FUN_06037660 (L1 import from src/FUN_06037660.c) --- */

void FUN_06037660(param_1, param_2)
    unsigned short *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  unsigned short *extraout_r3;

  unsigned short uVar8;

  unsigned short uVar11;

  char *puVar9;

  unsigned short *puVar10;

  char *puVar12;

  unsigned short local_38;

  char *puStack_2c;

  puVar12 = (char *)0x060A3D88;

  puVar4 = (char *)0x060A3DB0;

  uVar3 = DAT_060376a6;

  uVar2 = DAT_060376a4;

  puStack_2c = (char *)0x0;

  local_38 = (unsigned short)param_2[8];

  uVar11 = local_38 << 0xe & DAT_060376a8;

  puVar9 = (char *)(unsigned int)uVar11;

  uVar5 = (unsigned int)param_1 & 0xffff;

  uVar6 = (unsigned short)0x00008000;

  uVar7 = (unsigned short)0x0000BFFF;

  if (uVar5 == 1) {

    bVar1 = *param_2;

    *(unsigned short *)(0x060A3D88 + 0x20) =

         *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFEF;

    *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 4;

    uVar8 = (unsigned short)param_2[1] << 8 & DAT_06037c8e;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FEFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar8;

    *(short *)(puVar4 + 0x10) = *(short *)(param_2 + 10);

    bVar1 = param_2[2];

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar2;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | (unsigned short)bVar1 << 0xf & uVar6;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar7;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | uVar11;

    uVar6 = (unsigned short)param_2[3] << 8 & DAT_06037c90;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FCFF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[7] << 10 & DAT_06037c92;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000F3FF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[4] << 10 & DAT_06037c94;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FBFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[5] << 0xc & DAT_06037c96;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x00008FFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037c98;

    param_1 = (unsigned short *)(unsigned int)uVar6;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FDFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    puVar12 = (void *)0x00000008;

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x01')) {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

      puStack_2c = puVar4 + 0x38;

    }

    else if (*(int *)0x060A4C58 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

    }

    else if (*(int *)0x060A4C59 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

    }

  }

  else if (uVar5 == 2) {

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x02')) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFDF;

      if (*param_2 != 0) {

        *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | 0x20;

      }

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

      puVar12 = (void *)0x00000008;

    }

  }

  else {

    if (uVar5 == 4) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | bVar1 & 1;

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[4];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF3;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 3) << 2;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      bVar1 = param_2[6];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FFF0;

      puVar9 = puVar4 + 0x18;

    }

    else if (uVar5 == 8) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FDFD;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | DAT_060378f8;

      uVar8 = (unsigned short)param_2[1] << 8 & DAT_060378fa;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FEFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar8;

      *(short *)(puVar4 + 10) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar2;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar7;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFF3;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 2;

      uVar6 = (unsigned short)param_2[4] << 10 & DAT_060378fc;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000F3FF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[5] << 0xc & DAT_060378fe;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000CFFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037900;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FDFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FF0F;

      puVar9 = puVar4 + 0x1c;

    }

    else if (uVar5 == 0x10) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFB;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 2;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | bVar1 & 1;

      *(short *)(puVar4 + 0xc) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar2;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar7;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFCF;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 4;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000F0FF;

      puVar9 = puVar4 + 0x20;

    }

    else {

      if (uVar5 != 0x20) goto LAB_06037e88;

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFF7;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 3;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFEF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 4;

      *(short *)(puVar4 + 0xe) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar2;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar7;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FF3F;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 6;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFDF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 5;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & DAT_06037b10;

      puVar9 = puVar4 + 0x24;

    }

    param_1 = (unsigned short *)(puVar4 + 0x14);

    puVar12 = (void *)0x00000002;

  }

LAB_06037e88:

  if (param_2[6] == 1) {

    uVar6 = (*(int(*)())0x06035280)();

  }

  else {

    (*(int(*)())0x06035F44)();

    uVar6 = (*(int(*)())0x06035280)();

  }

  *param_1 = *param_1 | uVar6;

  uVar6 = 0;

  if (((unsigned int)puVar12 & 0xffff) != 0) {

    do {

      uVar7 = (*(int(*)())0x06035F44)();

      *extraout_r3 = uVar7 & 0x3f;

      uVar7 = (*(int(*)())0x06035F44)();

      *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) =

           *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) | (uVar7 & 0x3f) << 8 & uVar3;

      uVar6 = uVar6 + 1;

    } while ((unsigned int)uVar6 < ((unsigned int)puVar12 & 0xffff));

  }

  if (puStack_2c != (char *)0x0) {

    *param_1 = *param_1 & 0xf;

    *param_1 = *param_1 | *param_1 << 4;

    uVar5 = 0;

    if (((unsigned int)puVar12 & 0xffff) != 0) {

      do {

        puVar10 = (unsigned short *)(puStack_2c + ((uVar5 & 0xffff) << 1));

        uVar6 = (*(int(*)())0x06035F44)();

        *puVar10 = uVar6 & 0x3f;

        uVar6 = (*(int(*)())0x06035F44)();

        uVar5 = uVar5 + 1;

        *puVar10 = *puVar10 | (uVar6 & 0x3f) << 8 & uVar3;

      } while ((uVar5 & 0xffff) < ((unsigned int)puVar12 & 0xffff));

    }

  }

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}

/* FUN_060370E4 -- original binary (1404 bytes) */
__asm__(
    ".section .text.FUN_060370E4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060370E4\n"
    ".type _FUN_060370E4, @function\n"
    "_FUN_060370E4:\n"
    ".byte 0x2F, 0xE6, 0xE3, 0x00, 0x2F, 0xD6, 0x62, 0x33, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x6B, 0x43\n"  /* 0x060370E4 */
    ".byte 0x2F, 0x96, 0x2F, 0x86, 0x4F, 0x22, 0xD9, 0x18, 0xDA, 0x18, 0xDC, 0x19, 0xDD, 0x19, 0xDE, 0x1A\n"  /* 0x060370F4 */
    ".byte 0x2A, 0x32, 0x1A, 0x31, 0x63, 0xB2, 0x2E, 0x32, 0x52, 0xB1, 0x1E, 0x21, 0x93, 0x20, 0x85, 0xC7\n"  /* 0x06037104 */
    ".byte 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0x81, 0xC7, 0x84, 0xB8, 0x60, 0x0C, 0x88, 0x01, 0x8B, 0x06\n"  /* 0x06037114 */
    ".byte 0x92, 0x17, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x2B, 0x60, 0x33, 0xA0, 0x05, 0x00, 0x09, 0xD2, 0x0F\n"  /* 0x06037124 */
    ".byte 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0x81, 0xC7, 0x84, 0xB9, 0x60, 0x0C, 0x88, 0x01\n"  /* 0x06037134 */
    ".byte 0x8B, 0x16, 0x92, 0x07, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x2B, 0x60, 0x33, 0xA0, 0x15, 0x00, 0x09\n"  /* 0x06037144 */
    ".byte 0x7F, 0xFF, 0x01, 0x00, 0x02, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x06, 0x0A, 0x4C, 0x44\n"  /* 0x06037154 */
    ".byte 0x06, 0x0A, 0x3D, 0x88, 0x06, 0x0A, 0x3E, 0x38, 0x06, 0x0A, 0x4C, 0x4C, 0x00, 0x00, 0xFE, 0xFF\n"  /* 0x06037164 */
    ".byte 0xD2, 0x46, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0xE5, 0x00, 0xE2, 0x04, 0x81, 0xC7\n"  /* 0x06037174 */
    ".byte 0x64, 0x5C, 0x84, 0xBA, 0x63, 0x03, 0x63, 0x3C, 0x33, 0x23, 0x8D, 0x26, 0x68, 0x5C, 0x85, 0xC7\n"  /* 0x06037184 */
    ".byte 0xD3, 0x3F, 0x62, 0x03, 0x62, 0x2D, 0x84, 0xBA, 0x22, 0x39, 0x61, 0x03, 0x61, 0x1C, 0x22, 0x1B\n"  /* 0x06037194 */
    ".byte 0x62, 0x2D, 0x60, 0x23, 0x81, 0xC7, 0x84, 0xBA, 0x60, 0x0C, 0x88, 0x01, 0x8B, 0x20, 0x60, 0xE2\n"  /* 0x060371A4 */
    ".byte 0x20, 0x08, 0x89, 0x06, 0xD3, 0x36, 0x85, 0xC7, 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0xA0, 0x01\n"  /* 0x060371B4 */
    ".byte 0x81, 0xC7, 0xE8, 0x01, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x99, 0x60, 0x23, 0x81, 0xD3, 0x63, 0xE2\n"  /* 0x060371C4 */
    ".byte 0xD2, 0x30, 0x33, 0x2C, 0x2A, 0x32, 0xA0, 0x0B, 0xE4, 0x01, 0x84, 0xBA, 0x60, 0x0C, 0x88, 0x04\n"  /* 0x060371D4 */
    ".byte 0x8B, 0x06, 0x85, 0xD3, 0xC9, 0xFF, 0x81, 0xD3, 0x53, 0xE1, 0xD2, 0x2A, 0x33, 0x2C, 0x1A, 0x31\n"  /* 0x060371E4 */
    ".byte 0x84, 0xBB, 0xE2, 0x04, 0x63, 0x03, 0x63, 0x3C, 0x33, 0x23, 0x89, 0x51, 0x85, 0xC7, 0xD3, 0x26\n"  /* 0x060371F4 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x84, 0xBB, 0x22, 0x39, 0x61, 0x03, 0x61, 0x1C, 0x41, 0x08, 0x61, 0x1D\n"  /* 0x06037204 */
    ".byte 0x22, 0x1B, 0x62, 0x2D, 0x60, 0x23, 0x81, 0xC7, 0x84, 0xBB, 0x60, 0x0C, 0x88, 0x01, 0x8B, 0x50\n"  /* 0x06037214 */
    ".byte 0x62, 0x4C, 0x22, 0x28, 0x8B, 0x18, 0x60, 0xE2, 0x20, 0x08, 0x89, 0x06, 0xD3, 0x1A, 0x85, 0xC7\n"  /* 0x06037224 */
    ".byte 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0xA0, 0x01, 0x81, 0xC7, 0xE8, 0x02, 0x85, 0xD3, 0x62, 0x03\n"  /* 0x06037234 */
    ".byte 0x22, 0x99, 0x60, 0x23, 0x81, 0xD3, 0x85, 0xD3, 0xCB, 0x01, 0x81, 0xD3, 0x63, 0xE2, 0xD2, 0x13\n"  /* 0x06037244 */
    ".byte 0x33, 0x2C, 0x2A, 0x32, 0xA0, 0x17, 0xE4, 0x01, 0x50, 0xE1, 0x20, 0x08, 0x89, 0x05, 0xD3, 0x0E\n"  /* 0x06037254 */
    ".byte 0x85, 0xC7, 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0x81, 0xC7, 0x85, 0xD3, 0xC9, 0xFF, 0x81, 0xD3\n"  /* 0x06037264 */
    ".byte 0x93, 0x0B, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23, 0x81, 0xD3, 0x53, 0xE1, 0xD2, 0x07\n"  /* 0x06037274 */
    ".byte 0x33, 0x2C, 0x1A, 0x31, 0x74, 0x01, 0xA0, 0x1C, 0x00, 0x09, 0x01, 0x00, 0x00, 0x00, 0xFD, 0xFF\n"  /* 0x06037284 */
    ".byte 0x00, 0x00, 0xFF, 0xFC, 0x25, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF3, 0x25, 0xE2, 0x00, 0x00\n"  /* 0x06037294 */
    ".byte 0x84, 0xBB, 0x60, 0x0C, 0x88, 0x04, 0x8B, 0x0C, 0x85, 0xD3, 0xC9, 0xFF, 0x81, 0xD3, 0x93, 0x56\n"  /* 0x060372A4 */
    ".byte 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23, 0x81, 0xD3, 0x53, 0xE1, 0xD2, 0x29, 0x33, 0x2C\n"  /* 0x060372B4 */
    ".byte 0x1A, 0x31, 0xE2, 0x04, 0x84, 0xBC, 0x63, 0x03, 0x63, 0x3C, 0x33, 0x23, 0x89, 0x50, 0x85, 0xC7\n"  /* 0x060372C4 */
    ".byte 0xD3, 0x25, 0x62, 0x03, 0x62, 0x2D, 0x84, 0xBC, 0x22, 0x39, 0x61, 0x03, 0x61, 0x1C, 0x41, 0x08\n"  /* 0x060372D4 */
    ".byte 0x41, 0x08, 0x61, 0x1D, 0x22, 0x1B, 0x62, 0x2D, 0x60, 0x23, 0x81, 0xC7, 0x84, 0xBC, 0x60, 0x0C\n"  /* 0x060372E4 */
    ".byte 0x88, 0x01, 0x8B, 0x52, 0x62, 0x4C, 0x22, 0x28, 0x8B, 0x18, 0x60, 0xE2, 0x20, 0x08, 0x89, 0x06\n"  /* 0x060372F4 */
    ".byte 0xD3, 0x19, 0x85, 0xC7, 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0xA0, 0x01, 0x81, 0xC7, 0xE8, 0x03\n"  /* 0x06037304 */
    ".byte 0x85, 0xD3, 0x62, 0x03, 0x22, 0x99, 0x60, 0x23, 0x81, 0xD3, 0x85, 0xD3, 0xCB, 0x02, 0x81, 0xD3\n"  /* 0x06037314 */
    ".byte 0x63, 0xE2, 0xD2, 0x12, 0x33, 0x2C, 0x2A, 0x32, 0xA0, 0x17, 0xE4, 0x01, 0x50, 0xE1, 0x20, 0x08\n"  /* 0x06037324 */
    ".byte 0x89, 0x05, 0xD3, 0x0D, 0x85, 0xC7, 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0x81, 0xC7, 0x85, 0xD3\n"  /* 0x06037334 */
    ".byte 0xC9, 0xFF, 0x81, 0xD3, 0x93, 0x0C, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23, 0x81, 0xD3\n"  /* 0x06037344 */
    ".byte 0x74, 0x01, 0x53, 0xE1, 0xD2, 0x05, 0x33, 0x2C, 0x1A, 0x31, 0xA0, 0x1E, 0x00, 0x09, 0x01, 0x00\n"  /* 0x06037354 */
    ".byte 0x02, 0x00, 0xFF, 0xFF, 0x25, 0xE2, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xCF, 0x25, 0xE4, 0x00, 0x00\n"  /* 0x06037364 */
    ".byte 0x84, 0xBC, 0x60, 0x0C, 0x88, 0x04, 0x8B, 0x10, 0xD2, 0x30, 0x60, 0x22, 0x20, 0x08, 0x89, 0x0C\n"  /* 0x06037374 */
    ".byte 0x85, 0xD3, 0xC9, 0xFF, 0x81, 0xD3, 0x93, 0x56, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23\n"  /* 0x06037384 */
    ".byte 0x81, 0xD3, 0x53, 0xE1, 0xD2, 0x2A, 0x33, 0x2C, 0x1A, 0x31, 0xE2, 0x04, 0x84, 0xBD, 0x63, 0x03\n"  /* 0x06037394 */
    ".byte 0x63, 0x3C, 0x33, 0x23, 0x89, 0x52, 0x85, 0xC7, 0xD3, 0x26, 0x62, 0x03, 0x62, 0x2D, 0x84, 0xBD\n"  /* 0x060373A4 */
    ".byte 0x22, 0x39, 0x61, 0x03, 0x61, 0x1C, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x61, 0x1D, 0x22, 0x1B\n"  /* 0x060373B4 */
    ".byte 0x62, 0x2D, 0x60, 0x23, 0x81, 0xC7, 0x84, 0xBD, 0x60, 0x0C, 0x88, 0x01, 0x8B, 0x53, 0x64, 0x4C\n"  /* 0x060373C4 */
    ".byte 0x24, 0x48, 0x8B, 0x18, 0x60, 0xE2, 0x20, 0x08, 0x89, 0x06, 0xD3, 0x1A, 0x85, 0xC7, 0x62, 0x03\n"  /* 0x060373D4 */
    ".byte 0x22, 0x39, 0x60, 0x23, 0xA0, 0x01, 0x81, 0xC7, 0xE8, 0x04, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x99\n"  /* 0x060373E4 */
    ".byte 0x60, 0x23, 0x81, 0xD3, 0x85, 0xD3, 0xCB, 0x03, 0x81, 0xD3, 0x63, 0xE2, 0xD2, 0x12, 0x33, 0x2C\n"  /* 0x060373F4 */
    ".byte 0x2A, 0x32, 0xA0, 0x16, 0x00, 0x09, 0x50, 0xE1, 0x20, 0x08, 0x89, 0x05, 0xD3, 0x0D, 0x85, 0xC7\n"  /* 0x06037404 */
    ".byte 0x62, 0x03, 0x22, 0x39, 0x60, 0x23, 0x81, 0xC7, 0x85, 0xD3, 0xC9, 0xFF, 0x81, 0xD3, 0x93, 0x0B\n"  /* 0x06037414 */
    ".byte 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23, 0x81, 0xD3, 0x53, 0xE1, 0xD2, 0x06, 0x33, 0x2C\n"  /* 0x06037424 */
    ".byte 0x1A, 0x31, 0xA0, 0x20, 0x00, 0x09, 0x02, 0x00, 0x03, 0x00, 0xFF, 0xFF, 0x06, 0x0A, 0x4C, 0x50\n"  /* 0x06037434 */
    ".byte 0x25, 0xE4, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0x25, 0xE6, 0x00, 0x00, 0x84, 0xBD, 0x60, 0x0C\n"  /* 0x06037444 */
    ".byte 0x88, 0x04, 0x8B, 0x10, 0xD2, 0x37, 0x60, 0x22, 0x20, 0x08, 0x89, 0x0C, 0x85, 0xD3, 0xC9, 0xFF\n"  /* 0x06037454 */
    ".byte 0x81, 0xD3, 0x93, 0x64, 0x85, 0xD3, 0x62, 0x03, 0x22, 0x3B, 0x60, 0x23, 0x81, 0xD3, 0x53, 0xE1\n"  /* 0x06037464 */
    ".byte 0xD2, 0x31, 0x33, 0x2C, 0x1A, 0x31, 0x50, 0xA1, 0x20, 0x08, 0x89, 0x01, 0xA0, 0xB7, 0x00, 0x09\n"  /* 0x06037474 */
    ".byte 0x84, 0xBE, 0x60, 0x0C, 0x88, 0x01, 0x8B, 0x12, 0xD2, 0x2C, 0x60, 0x22, 0x20, 0x08, 0x8B, 0x0E\n"  /* 0x06037484 */
    ".byte 0xD3, 0x2B, 0x43, 0x0B, 0x00, 0x09, 0x88, 0x01, 0x8B, 0x09, 0xD3, 0x2A, 0x85, 0xC7, 0x62, 0x03\n"  /* 0x06037494 */
    ".byte 0x22, 0x3B, 0x60, 0x23, 0x81, 0xC7, 0xD3, 0x28, 0x2A, 0x32, 0xA0, 0xA0, 0x00, 0x09, 0x60, 0xA2\n"  /* 0x060374A4 */
    ".byte 0x20, 0x08, 0x89, 0x5F, 0xD3, 0x25, 0x63, 0x30, 0x63, 0x3C, 0x23, 0x38, 0x89, 0x5A, 0x50, 0xE1\n"  /* 0x060374B4 */
    ".byte 0x20, 0x08, 0x8B, 0x03, 0x63, 0xE2, 0x92, 0x33, 0x33, 0x2C, 0x1E, 0x31, 0x60, 0xE2, 0x20, 0x08\n"  /* 0x060374C4 */
    ".byte 0x8B, 0x01, 0xE3, 0xFF, 0x2E, 0x32, 0x52, 0xE1, 0x63, 0xA2, 0x32, 0x3C, 0x1A, 0x21, 0x85, 0xD3\n"  /* 0x060374D4 */
    ".byte 0x64, 0x03, 0x64, 0x4D, 0x93, 0x25, 0x23, 0x49, 0x62, 0x43, 0x42, 0x18, 0x23, 0x2B, 0x60, 0x3D\n"  /* 0x060374E4 */
    ".byte 0x81, 0xD3, 0xA0, 0x35, 0x60, 0x8C, 0xD2, 0x16, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33\n"  /* 0x060374F4 */
    ".byte 0xA0, 0x13, 0x00, 0x09, 0xD2, 0x13, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0xA0, 0x0C\n"  /* 0x06037504 */
    ".byte 0x00, 0x09, 0xD2, 0x11, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0xA0, 0x05, 0x00, 0x09\n"  /* 0x06037514 */
    ".byte 0xD2, 0x0E, 0x85, 0xC7, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0xA0, 0x60, 0x81, 0xC7, 0x03, 0x00\n"  /* 0x06037524 */
    ".byte 0x04, 0x00, 0x00, 0xFF, 0x06, 0x0A, 0x4C, 0x50, 0x25, 0xE6, 0x00, 0x00, 0x06, 0x0A, 0x4C, 0x44\n"  /* 0x06037534 */
    ".byte 0x06, 0x03, 0xC1, 0x56, 0x00, 0x00, 0x80, 0x00, 0x25, 0xF0, 0x08, 0x00, 0x06, 0x0A, 0x4C, 0x59\n"  /* 0x06037544 */
    ".byte 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0xFF, 0xF3, 0x00, 0x00, 0xFF, 0xCF, 0x00, 0x00, 0xFF, 0x3F\n"  /* 0x06037554 */
    ".byte 0x88, 0x01, 0x89, 0xC8, 0x88, 0x02, 0x89, 0xCD, 0x88, 0x03, 0x89, 0xD2, 0x88, 0x04, 0x89, 0xD7\n"  /* 0x06037564 */
    ".byte 0xA0, 0x3D, 0x00, 0x09, 0x60, 0xA2, 0x20, 0x08, 0x8B, 0x39, 0x60, 0xE2, 0x20, 0x08, 0x89, 0x19\n"  /* 0x06037574 */
    ".byte 0xD3, 0x1F, 0x63, 0x30, 0x63, 0x3C, 0x23, 0x38, 0x89, 0x14, 0x85, 0xD3, 0x64, 0xE3, 0x63, 0x03\n"  /* 0x06037584 */
    ".byte 0x23, 0x99, 0x60, 0x33, 0x81, 0xD3, 0xD0, 0x1B, 0xD3, 0x1B, 0x43, 0x0B, 0x61, 0x42, 0x60, 0x0D\n"  /* 0x06037594 */
    ".byte 0xE2, 0x06, 0x32, 0xDC, 0x62, 0x21, 0x22, 0x0B, 0x60, 0x23, 0x81, 0xD3, 0x63, 0x42, 0xD2, 0x17\n"  /* 0x060375A4 */
    ".byte 0x33, 0x2C, 0x2A, 0x32, 0x50, 0xE1, 0x20, 0x08, 0x89, 0x19, 0xD3, 0x15, 0x63, 0x30, 0x63, 0x3C\n"  /* 0x060375B4 */
    ".byte 0x23, 0x38, 0x89, 0x14, 0x85, 0xD3, 0x64, 0xE3, 0xC9, 0xFF, 0x74, 0x04, 0x81, 0xD3, 0xD0, 0x0D\n"  /* 0x060375C4 */
    ".byte 0xD3, 0x0D, 0x43, 0x0B, 0x61, 0x42, 0x60, 0x0D, 0x40, 0x18, 0xE2, 0x06, 0x32, 0xDC, 0x62, 0x21\n"  /* 0x060375D4 */
    ".byte 0x22, 0x0B, 0x60, 0x23, 0x81, 0xD3, 0x63, 0x42, 0xD2, 0x08, 0x33, 0x2C, 0x1A, 0x31, 0x4F, 0x26\n"  /* 0x060375E4 */
    ".byte 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x060375F4 */
    ".byte 0x06, 0x0A, 0x4C, 0x58, 0x00, 0x02, 0x00, 0x00, 0x06, 0x03, 0x4F, 0xFC, 0x25, 0xE0, 0x00, 0x00\n"  /* 0x06037604 */
    ".byte 0x06, 0x0A, 0x4C, 0x59, 0xE7, 0x10, 0xE5, 0x00, 0x24, 0x50, 0x62, 0x5C, 0x60, 0x23, 0x80, 0x41\n"  /* 0x06037614 */
    ".byte 0x60, 0x5C, 0x80, 0x42, 0x60, 0x5C, 0x80, 0x43, 0x60, 0x5C, 0x80, 0x44, 0x60, 0x5C, 0x80, 0x45\n"  /* 0x06037624 */
    ".byte 0x60, 0x5C, 0x80, 0x46, 0x60, 0x5C, 0x80, 0x48, 0x60, 0x5C, 0x80, 0x47, 0x63, 0x5D, 0x60, 0x33\n"  /* 0x06037634 */
    ".byte 0x81, 0x45, 0x66, 0x5C, 0x63, 0x6C, 0x62, 0x43, 0x43, 0x08, 0x76, 0x01, 0x72, 0x0C, 0x33, 0x2C\n"  /* 0x06037644 */
    ".byte 0x23, 0x52, 0x63, 0x6C, 0x33, 0x73, 0x8B, 0xF5, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06037654 */
);
