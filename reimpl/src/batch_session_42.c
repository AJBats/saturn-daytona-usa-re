#include "game.h"

extern int DAT_0604211e;
extern int DAT_06042120;
extern int DAT_06042122;
extern int DAT_0604222c;
extern int DAT_0604222e;
extern int DAT_0604230a;
extern int DAT_0604230c;
extern int DAT_0604230e;
extern int DAT_06042398;
extern int DAT_0604239a;
extern int DAT_060424c8;
extern int DAT_060424ca;
extern int DAT_06042b9c;
extern int DAT_06042b9e;
extern int DAT_06042ba0;
extern int DAT_06042ba2;
extern int DAT_06042ba4;
extern int DAT_06042ba6;
extern int DAT_06042c78;
extern int DAT_06042c7a;
extern int DAT_06042cb2;
extern int Onchip_DMA0R;
extern int PTR_DAT_06042230;
extern int PTR_DAT_060423f6;
extern int PTR_DAT_06042cb4;
extern void FUN_060424a2();
extern void FUN_0604249c();

/* cd_session_read_step -- Advance one step of CD sector read state machine.
 * State 0: idle. State 1: issue async read via cd_read_sector (0x06036A1C),
 * store header byte at +0x40, advance to state 2. State 2: poll cd_get_status
 * until completion bits set, then return to state 0.
 * Returns current state (0=complete, 1=busy, 2=finishing). */
int cd_session_read_step(param_1)
    int *param_1;
{
    unsigned short status_mask;
    unsigned short status;
    int result;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;    /* CD session base pointer */

    /* State 1: initiate async CD read */
    if (*(int *)(0x360 + CD_SESSION_BASE) == 1) {
        result = (*(int(*)())0x06036A1C)(      /* cd_read_sector_async */
            *(int *)(CD_SESSION_BASE + DAT_06042120 + 4),
            *(int *)(CD_SESSION_BASE + (int)DAT_06042120));
        if (result != 0) {
            return 1;                          /* read still in progress */
        }
        (*(int(*)())0x060349B6)(cd_result);    /* cd_get_result */
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];  /* store sector header */
        *param_1 = *param_1 + 1;              /* increment sectors read */
        *(int *)(*(int *)session_ptr + 0x360) = 2;  /* advance to completion state */
    }

    /* State 2: wait for CD status completion bits */
    status_mask = DAT_06042122;
    if ((*(int *)(0x360 + *(int *)session_ptr) == 2) &&
       (status = (*(int(*)())0x06035C4E)(), (status & status_mask) != 0)) {
        *(int *)(*(int *)session_ptr + 0x360) = 0;  /* back to idle */
    }

    return *(int *)(0x360 + *(int *)session_ptr);
}

/* cd_session_file_batch -- Process pending CD file seeks in batch.
 * Iterates through file table entries (12 bytes each at DAT_0604222e offset).
 * For each: builds LBA range flags from start/end (-2 = use default),
 * calls cd_seek_file (0x06036414). On success, reads result header.
 * If interrupted mid-batch, compacts remaining entries into pending table.
 * Clears transfer state (+0x1E0) when all files done and CD status bit 0x40 set.
 * Returns pending file count. */
int cd_session_file_batch(param_1)
    int *param_1;
{
    unsigned short cd_status;
    int seek_result;
    unsigned char range_flags;
    int start_lba, end_lba;
    int default_lba = (int)DAT_0604222c;
    int file_idx;
    int compact_idx;
    short entry_off;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;    /* CD session base pointer */
    int file_count = *(int *)(*(int *)session_ptr + (int)PTR_DAT_06042230);

    /* Process each file entry in the table */
    for (file_idx = 0; file_idx < file_count; file_idx++) {
        entry_off = (short)((short)file_idx * 0xc);

        /* Check start LBA: -2 means use default */
        range_flags = *(int *)(*(int *)session_ptr + (int)DAT_0604222e + (int)entry_off + 4) != -2;
        start_lba = default_lba;
        if ((int)range_flags) {
            start_lba = *(int *)(*(int *)session_ptr + (int)DAT_0604222e + (int)entry_off + 4);
        }

        /* Check end LBA: -2 means use default */
        end_lba = default_lba;
        if (*(int *)(*(int *)session_ptr + (int)DAT_0604222e + (int)entry_off + 8) != -2) {
            range_flags = range_flags | 2;
            end_lba = *(int *)(*(int *)session_ptr + (int)DAT_0604222e + (int)entry_off + 8);
        }

        /* Issue CD seek for this file entry */
        seek_result = (*(int(*)())0x06036414)(   /* cd_seek_file */
            *(int *)(*(int *)session_ptr + (int)DAT_0604222e + (int)entry_off),
            range_flags, start_lba, end_lba);
        if (seek_result != 0) break;             /* seek failed, stop batch */

        (*(int(*)())0x060349B6)(cd_result);      /* cd_get_result */
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];  /* store header byte */
        *param_1 = *param_1 + 1;                /* increment files processed */
    }

    /* If stopped early: compact remaining entries into pending table */
    if (file_idx < *(int *)(*(int *)session_ptr + (int)PTR_DAT_06042230)) {
        compact_idx = 0;
        for (; file_idx < *(int *)(*(int *)session_ptr + (int)DAT_0604230c); file_idx++) {
            int dst_off = (int)(short)((short)compact_idx * 0xc);
            int src_off = (int)(short)((short)file_idx * 0xc);

            /* Copy 12-byte entry (sector, start_lba, end_lba) */
            *(int *)(*(int *)session_ptr + (int)DAT_0604230a + dst_off) =
                 *(int *)(*(int *)session_ptr + (int)DAT_0604230a + src_off);
            *(int *)(*(int *)session_ptr + (int)DAT_0604230a + dst_off + 4) =
                 *(int *)(*(int *)session_ptr + (int)DAT_0604230a + src_off + 4);
            *(int *)(dst_off + *(int *)session_ptr + (int)DAT_0604230a + 8) =
                 *(int *)(src_off + *(int *)session_ptr + (int)DAT_0604230a + 8);
            compact_idx++;
        }
        *(int *)(*(int *)session_ptr + (int)DAT_0604230c) = compact_idx;
    } else {
        /* All files processed — clear file count */
        *(int *)(*(int *)session_ptr + (int)PTR_DAT_06042230) = 0;
    }

    /* If CD ready (bit 0x40) and no pending files, clear transfer state */
    cd_status = (*(int(*)())0x06035C4E)();       /* cd_get_status */
    if (((cd_status & 0x40) != 0) && (*(int *)(*(int *)session_ptr + (int)DAT_0604230c) == 0)) {
        *(int *)(*(int *)session_ptr + 0x1e0) = 0;
    }

    return *(int *)((int)DAT_0604230c + *(int *)session_ptr);
}

/* cd_session_state_reset -- Clear CD session state to initial values.
 * Zeros filename buffers at +0x00 and +0x18 (23 bytes each),
 * clears read/write pointers, sets +0x38 to 0xFFFFFFFF (no sector),
 * and zeros the file table and track list at DAT offsets. */
void cd_session_state_reset()
{
    char *session_ptr = (char *)0x060A5400;    /* CD session base pointer */
    int tbl_offset;
    int i;

    /* Zero filename buffer A (+0x00) and B (+0x18), 23 bytes each */
    for (i = 0; i < 0x17; i++) {
        *(char *)(i + *(int *)session_ptr) = 0;
        *(char *)(*(int *)session_ptr + 0x18 + i) = 0;
    }

    /* Clear session control fields */
    *(int *)(*(int *)session_ptr + 0x30) = 0;          /* read offset */
    *(int *)(*(int *)session_ptr + 0x34) = 0;          /* write offset */
    *(int *)(*(int *)session_ptr + 0x38) = 0xffffffff; /* current sector (none) */
    *(int *)(*(int *)session_ptr + 0x3c) = 0;          /* error code */
    *(int *)(*(int *)session_ptr + 0x4c) = 0;          /* transfer count */
    *(int *)(*(int *)session_ptr + 0x50) = 0;          /* bytes remaining */
    *(int *)(*(int *)session_ptr + 0x54) = 0;          /* DMA channel */
    *(int *)(*(int *)session_ptr + 0x58) = 0;          /* callback pointer */

    /* Clear file table entries */
    tbl_offset = (int)DAT_06042398;
    *(int *)(*(int *)session_ptr + tbl_offset) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 8) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 0x24) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 0x34) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 0x44) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 0x5c) = 0;

    /* Clear track list */
    tbl_offset = (int)DAT_0604239a;
    *(int *)(*(int *)session_ptr + tbl_offset) = 0;
    *(int *)(*(int *)session_ptr + tbl_offset + 4) = 0;
}

/* cd_poll_status_ready -- Busy-wait for CD drive status bit, then read.
 * Spins on cd_get_status (0x06035C4E) until required bits
 * (PTR_DAT_060423f6) are set, then reads sector via cd_read (0x06035C54)
 * with mask 0xFBFF. Returns read result. */
int cd_poll_status_ready()
{
    unsigned short status_mask = PTR_DAT_060423f6;
    unsigned short status;

    /* Busy-wait until CD status bits are ready */
    do {
        status = (*(int(*)())0x06035C4E)();    /* cd_get_status */
    } while ((status & status_mask) == 0);

    return (*(int(*)())0x06035C54)(0xFBFF);    /* cd_read_sector */
}



/* vdp2_vram_write -- Write data to VDP2 VRAM with mode-dependent addressing.
 * Checks color mode via 0x0603C156: mode 2 = 32-bit (word), else 16-bit (short).
 * For 32-bit: address = 0x25F00000 + (offset<<2) + (bank<<10).
 * For 16-bit: address = 0x25F00000 + (offset<<1) + (bank<<9).
 * Single-word writes use direct store; multi-word uses DMA copy (0x06038A48). */
void vdp2_vram_write(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int *param_4;
{
    int bank;
    int color_mode = (*(int(*)())0x0603C156)();  /* get_vdp2_color_mode */

    if (color_mode == 2) {
        /* 32-bit color mode: word-addressed */
        bank = (*(int(*)())0x06042BFC)(param_1);  /* get_vram_bank */
        if (param_3 != 1) {
            (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 2) + (bank << 10),
                                   param_4, param_3 << 2);  /* dma_copy */
            return;
        }
        *(int *)(0x25F00000 + (param_2 << 2) + (bank << 10)) = *param_4;
    } else {
        /* 16-bit color mode: short-addressed */
        bank = (*(int(*)())0x06042BFC)(param_1);  /* get_vram_bank */
        if (param_3 != 1) {
            (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 1) + (bank << 9),
                                   param_4, param_3 << 1);  /* dma_copy */
            return;
        }
        *(short *)(0x25F00000 + (param_2 << 1) + (bank << 9)) = *(short *)param_4;
    }
}

/* dma_register_config -- Configure on-chip DMA0 register from parameter block.
 * param_1[0] = value OR'd into DMA0R (bit 3 cleared first).
 * param_1[1] = additional OR value for bit 0 (if flags & 4).
 * param_1[2] = flags: bit 2 = set enable, bit 0 = clear bit 2, bit 1 = clear bit 1.
 * Applied sequentially to Onchip_DMA0R. */
void FUN_06042a8c(param_1)
    unsigned int *param_1;
{
  register int *reg asm("r2") = &Onchip_DMA0R;
  int flags;
  int val;

  val = *reg;
  val = (val & 0xfffffff7) | *param_1;  /* clear bit 3, OR config */
  *reg = val;

  flags = param_1[2];

  if ((flags & 4) == 4) {  /* set enable bit */
    val = (val & 0xfffffffe) | param_1[1];
    *reg = val;
  }

  if ((flags & 1) == 1) {  /* clear transfer bit */
    val = val & 0xfffffffb;
    *reg = val;
  }

  if ((flags & 2) == 2) {  /* clear direction bit */
    val = val & 0xfffffffd;
    *reg = val;
  }
}

/* timer_channel_config -- Configure SH-2 on-chip timer channel from 10-element config struct.
 * param_1[0..8] = register values, param_1[9] = bitmask of which fields to write.
 * Writes to on-chip registers at (param_2 << 4) - 0x80 address range.
 * Fields: base addr, compare A, compare B, then bit-field updates for control register. */
unsigned int FUN_06042aca(param_1, param_2)
    int *param_1;
    int param_2;
{
  unsigned int flags;
  unsigned int reg_val;
  unsigned int updated;
  unsigned int *ctrl_reg;
  /* Write base timer value */
  *(int *)((param_2 << 4) + -0x80) = *param_1;
  /* Compare register A */
  if ((param_1[9] & 1) == 1) {
    *(int *)((param_2 << 4) + -0x7c) = param_1[1];
  }
  /* Compare register B */
  if ((param_1[9] & 2) == 2) {
    *(int *)((param_2 << 4) + -0x78) = param_1[2];
  }
  /* Control register — selective bit-field updates */
  ctrl_reg = (unsigned int *)((param_2 << 4) + -0x74);
  reg_val = *ctrl_reg;
  if ((param_1[9] & 4) == 4) {         /* bits 14-15 */
    reg_val = reg_val & 0xFFFF3FFF | param_1[3] << 0xe;
  }
  if ((param_1[9] & 8) == 8) {         /* bits 12-13 */
    reg_val = reg_val & -12289 | param_1[4] << 0xc;
  }
  if ((param_1[9] & 0x10) == 0x10) {   /* bits 10-11 */
    reg_val = reg_val & -3073 | param_1[5];
  }
  if ((param_1[9] & 0x20) == 0x20) {   /* bit 9 */
    reg_val = reg_val & -513 | param_1[6];
  }
  flags = param_1[9];
  updated = reg_val & 0xffffffe7;
  if ((flags & 0x40) == 0x40) {         /* bits 3-4 */
    updated = reg_val & 0xffffffe3 | param_1[7];
  }
  if ((param_1[9] & 0x100) == 0x100) { /* bit 1: clear enable */
    updated = updated & 0xfffffffd;
  }
  *ctrl_reg = updated;
  /* Optional byte write */
  if ((param_1[9] & 0x80) == 0x80) {
    *(char *)(param_2 + DAT_06042ba6) = (char)param_1[8];
  }
  return flags & 0x40;
}

/* vdp2_get_vram_bank -- Return VDP2 VRAM bank number for a given layer.
 * Reads VDP2 RAMCTL/CYCA/CYCB registers cached at 0x060A4D18.
 * param_1 selects the layer: 1=NBG0, 2/4=NBG1, 8/0x80=NBG2,
 * 0x10=NBG3, 0x20=RBG0, 0x100=sprite, 0x40000=raw pointer.
 * Returns bank index (0-7) extracted from the appropriate register bits. */
char * vdp2_get_vram_bank(param_1)
    char *param_1;
{
    if (param_1 == (void *)0x00000001) {       /* NBG0: CYCB bits 0-2 */
        return (char *)(*(unsigned short *)(0x060A4D18 + 6) & 7);
    }
    if ((param_1 == (void *)0x00000002) || (param_1 == (void *)0x00000004)) {
        return (char *)(*(unsigned short *)(0x060A4D18 + 4) & 7);  /* NBG1: CYCA bits 0-2 */
    }
    if (param_1 != (void *)0x00000008) {
        if (param_1 == (void *)0x00000010) {   /* NBG3: CYCA bits 8-10 */
            return (char *)((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & 0x700) >> 8);
        }
        if (param_1 == (void *)0x00000020) {   /* RBG0: CYCA bits 12-14 */
            return (char *)
                   ((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & (int)DAT_06042c7a) >> 0xc);
        }
        if (param_1 != (char *)0x80) {
            if (param_1 == (char *)0x100) {    /* Sprite: CYCB bits 4-6 */
                return (char *)((int)(*(unsigned short *)(0x060A4D18 + 6) & 0x70) >> 4);
            }
            if (param_1 != 0x00040000) {
                return param_1;                /* unknown — pass through */
            }
            return *(char **)0x060A4D5C;       /* raw pointer mode */
        }
    }
    return (char *)((int)(*(unsigned short *)(0x060A4D18 + 4) & 0x70) >> 4);  /* NBG2: CYCA bits 4-6 */
}

/* --- FUN_06042088 (L1 import from src/FUN_06042088.c) --- */

int FUN_06042088(param_1)
    int *param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char local_14 [16];

  puVar2 = (char *)0x060A5400;

  if (*(int *)(0x360 + *(int *)0x060A5400) == 1) {

    iVar3 = (*(int(*)())0x06036A1C)(*(int *)(*(int *)0x060A5400 + DAT_06042120 + 4),

                       *(int *)(*(int *)0x060A5400 + (int)DAT_06042120));

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())0x060349B6)(local_14);

    *(char *)(*(int *)puVar2 + 0x40) = local_14[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x360) = 2;

  }

  uVar1 = DAT_06042122;

  if ((*(int *)(0x360 + *(int *)puVar2) == 2) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar1) != 0)) {

    *(int *)(*(int *)puVar2 + 0x360) = 0;

  }

  return *(int *)(0x360 + *(int *)puVar2);

}

/* --- FUN_06042134 (L1 import from src/FUN_06042134.c) --- */

int FUN_06042134(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  int iVar4;

  unsigned char bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  short sVar9;

  char local_2c [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  iVar7 = (int)DAT_0604222c;

  for (iVar8 = 0; iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230); iVar8 = iVar8 + 1)

  {

    sVar9 = (short)iVar8;

    bVar5 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4) != -2;

    iVar4 = iVar7;

    if ((int)bVar5) {

      iVar4 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4);

    }

    iVar6 = iVar7;

    if (*(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8) != -2) {

      bVar5 = bVar5 | 2;

      iVar6 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8);

    }

    iVar4 = (*(int(*)())0x06036414)(*(int *)

                        (*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc)),bVar5,iVar4

                       ,iVar6);

    if (iVar4 != 0) break;

    (*(int(*)())puVar1)(local_2c);

    *(char *)(*(int *)puVar2 + 0x40) = local_2c[0];

    *param_1 = *param_1 + 1;

  }

  if (iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230)) {

    iVar7 = 0;

    for (; iVar8 < *(int *)(*(int *)puVar2 + (int)DAT_0604230c); iVar8 = iVar8 + 1) {

      iVar4 = (int)(short)((short)iVar7 * 0xc);

      iVar6 = (int)(short)((short)iVar8 * 0xc);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4 + 4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6 + 4);

      *(int *)(iVar4 + *(int *)puVar2 + (int)DAT_0604230a + 8) =

           *(int *)(iVar6 + *(int *)puVar2 + (int)DAT_0604230a + 8);

      iVar7 = iVar7 + 1;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_0604230c) = iVar7;

  }

  else {

    *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230) = 0;

  }

  uVar3 = (*(int(*)())0x06035C4E)();

  if (((uVar3 & 0x40) != 0) && (*(int *)(*(int *)puVar2 + (int)DAT_0604230c) == 0)) {

    *(int *)(*(int *)puVar2 + 0x1e0) = 0;

  }

  return *(int *)((int)DAT_0604230c + *(int *)puVar2);

}

/* --- FUN_060423CC (L1 import from src/FUN_060423CC.c) --- */

#if 0 /* FUN_060423CC -- replaced by ASM import of original bytes */
int FUN_060423cc()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar6;

  int uVar5;

  puVar4 = (char *)0x0000FBFF;

  puVar3 = (char *)0x06035C4E;

  puVar2 = (char *)0x06035C54;

  uVar1 = PTR_DAT_060423f6;

  do {

    uVar6 = (*(int(*)())puVar3)();

  } while ((uVar6 & uVar1) == 0);

  uVar5 = (*(int(*)())puVar2)((unsigned int)puVar4 & 0xffff);

  return uVar5;

}
#endif

/* --- FUN_060429EC (L1 import from src/FUN_060429EC.c) --- */

void FUN_060429ec(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int *param_4;
{

  int iVar1;

  iVar1 = (*(int(*)())0x0603C156)();

  if (iVar1 == 2) {

    iVar1 = (*(int(*)())0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 2) + (iVar1 << 10),param_4,param_3 << 2);

      return;

    }

    *(int *)(0x25F00000 + (param_2 << 2) + (iVar1 << 10)) = *param_4;

  }

  else {

    iVar1 = (*(int(*)())0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 1) + (iVar1 << 9),param_4,param_3 << 1);

      return;

    }

    *(short *)(0x25F00000 + (param_2 << 1) + (iVar1 << 9)) = *(short *)param_4;

  }

  return;

}

/* FUN_060423CC -- original binary (76 bytes) */
__asm__(
    ".section .text.FUN_060423CC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060423CC\n"
    ".type _FUN_060423CC, @function\n"
    "_FUN_060423CC:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0xDB, 0x0A, 0xDC, 0x0A, 0xDD, 0x0B\n"  /* 0x060423CC */
    ".byte 0x9E, 0x0B, 0x4C, 0x0B, 0x00, 0x09, 0x60, 0x0D, 0x20, 0xE9, 0x20, 0x08, 0x89, 0x03, 0x4B, 0x0B\n"  /* 0x060423DC */
    ".byte 0x64, 0xDD, 0xA0, 0x0D, 0x00, 0x09, 0xAF, 0xF4, 0x00, 0x09, 0x04, 0x00, 0x06, 0x03, 0x49, 0xB6\n"  /* 0x060423EC */
    ".byte 0x06, 0x0A, 0x54, 0x00, 0x06, 0x03, 0x5C, 0x54, 0x06, 0x03, 0x5C, 0x4E, 0x00, 0x00, 0xFB, 0xFF\n"  /* 0x060423FC */
    ".byte 0x4F, 0x26, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0604240C */
);
