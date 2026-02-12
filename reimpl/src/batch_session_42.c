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

/* cd_lba_to_msf_minutes -- Convert LBA offset (0x005A0000-based) to MSF minutes.
 * Uses piecewise linear interpolation from lookup table at DAT_060424c8.
 * Input: LBA value. Returns minutes component. */
int FUN_0604249c(int lba)
{
    int idx = ((unsigned int)(0x005A0000 - lba) >> 16) << 2;
    return (unsigned int)*(unsigned short *)(&DAT_060424ca + idx) +
        ((unsigned int)*(unsigned short *)(&DAT_060424c8 + idx) *
         (0x005A0000 - lba & 0xFFFFU) >> 16);
}

/* cd_lba_to_msf_seconds -- Convert raw LBA to MSF seconds.
 * Same interpolation table as minutes, but uses raw LBA input. */
int FUN_060424a2(unsigned int lba)
{
    int idx = (lba >> 16) << 2;
    return (unsigned int)*(unsigned short *)(&DAT_060424ca + idx) +
        ((unsigned int)*(unsigned short *)(&DAT_060424c8 + idx) *
         (lba & 0xFFFF) >> 16);
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

void FUN_06042a8c(param_1)
    unsigned int *param_1;
{
  register int *reg asm("r2") = &Onchip_DMA0R;
  int flags;
  int val;

  val = *reg;
  val = (val & 0xfffffff7) | *param_1;
  *reg = val;

  flags = param_1[2];

  if ((flags & 4) == 4) {
    val = (val & 0xfffffffe) | param_1[1];
    *reg = val;
  }

  if ((flags & 1) == 1) {
    val = val & 0xfffffffb;
    *reg = val;
  }

  if ((flags & 2) == 2) {
    val = val & 0xfffffffd;
    *reg = val;
  }
}

unsigned int FUN_06042aca(param_1, param_2)
    int *param_1;
    int param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  unsigned int *puVar4;

  *(int *)((param_2 << 4) + -0x80) = *param_1;

  if ((param_1[9] & 1) == 1) {

    *(int *)((param_2 << 4) + -0x7c) = param_1[1];

  }

  if ((param_1[9] & 2) == 2) {

    *(int *)((param_2 << 4) + -0x78) = param_1[2];

  }

  puVar4 = (unsigned int *)((param_2 << 4) + -0x74);

  uVar2 = *puVar4;

  if ((param_1[9] & 4) == 4) {

    uVar2 = uVar2 & 0xFFFF3FFF | param_1[3] << 0xe;

  }

  if ((param_1[9] & 8) == 8) {

    uVar2 = uVar2 & -12289 | param_1[4] << 0xc;

  }

  if ((param_1[9] & 0x10) == 0x10) {

    uVar2 = uVar2 & -3073 | param_1[5];

  }

  if ((param_1[9] & 0x20) == 0x20) {

    uVar2 = uVar2 & -513 | param_1[6];

  }

  uVar1 = param_1[9];

  uVar3 = uVar2 & 0xffffffe7;

  if ((uVar1 & 0x40) == 0x40) {

    uVar3 = uVar2 & 0xffffffe3 | param_1[7];

  }

  if ((param_1[9] & 0x100) == 0x100) {

    uVar3 = uVar3 & 0xfffffffd;

  }

  *puVar4 = uVar3;

  if ((param_1[9] & 0x80) == 0x80) {

    *(char *)(param_2 + DAT_06042ba6) = (char)param_1[8];

  }

  return uVar1 & 0x40;

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
