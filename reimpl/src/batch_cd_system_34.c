#include "game.h"

extern char DAT_06082A7C[];
extern int DAT_0603489e;
extern int DAT_06034976;
extern int DAT_06034a8e;
extern int DAT_06034bf4;
extern int DAT_06034bf6;
extern int DAT_06034d02;
extern int DAT_06034ffa;
extern int DAT_06035734;
extern int DAT_06035c46;
extern int FUN_06034754();
extern int FUN_060347a8();
extern unsigned int FUN_06034848();
extern int FUN_06034a10();
extern int FUN_06034cc8();
extern int FUN_06034d5e();
extern long long FUN_060359d2();
extern long long FUN_060359da();
extern int FUN_06035c6e();
extern void FUN_06035f16();




/* scene_object_visibility_check -- Check if static scene object is visible.
 * Implicit r14 = scene object pointer. Implicit r10 = scene data source.
 * Type 2 objects: computes distance from object position to camera
 * (stored at r10+0x10/0x18). If distance < 0x80000 (8.0 fixed),
 * marks obj+0x26 = 1 (visible). Returns obj type or visibility flag. */
char * FUN_0603449c()
{
  long long lVar1;
  char *puVar2;
  int iVar3;
  char *puVar4;
  int uVar5;
  unsigned int uVar6;
  int uVar7;
  int uVar8;
  int unaff_r10 = 0;
  int unaff_r14 = 0;

  puVar2 = (int *)0x06083238;
  puVar4 = (char *)(int)*(char *)(unaff_r14 + 0x00000001);
  if ((char *)(int)*(char *)(unaff_r14 + 0x00000001) == (void *)0x00000002) {
    uVar5 = *(int *)(unaff_r14 + 0x0000000C);
    uVar7 = *(int *)(unaff_r10 + 0x00000010);
    uVar8 = *(int *)(unaff_r10 + 0x00000018);
    *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);
    *(int *)(puVar2 + 4) = uVar5;
    *(int *)(puVar2 + 8) = uVar7;
    *(int *)(puVar2 + 0xc) = uVar8;
    lVar1 = (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2) *
            (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2);
    *(unsigned int *)(puVar2 + 0x10) = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
    lVar1 = (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4)) *
            (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4));
    uVar6 = *(int *)(puVar2 + 0x10) +
            ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);
    if ((int)uVar6 < 0) {
      iVar3 = (*(int(*)())0x06027476)(uVar6 >> 2);
      iVar3 = iVar3 << 1;
    }
    else {
      iVar3 = (*(int(*)())0x06027476)();
    }
    puVar2 = (int *)0x00000026;
    puVar4 = (char *)0x00080000;
    if (iVar3 < (int)0x00080000) {
      ((int *)0x00000026)[unaff_r14] = (char)0x00000001;
      puVar4 = puVar2;
    }
  }
  return puVar4;
}





/* cd_transfer_step -- Execute one step of CD data transfer.
 * Copies state+0x0C to state+0x10 (advance read position),
 * then runs: sector header parse, data validation, transfer completion.
 * Returns transfer status. */
int FUN_06034708(int state)
{
    *(int *)(state + 0x10) = *(int *)(state + 0x0C);
    FUN_06034754();
    FUN_060347a8();
    return FUN_06034848();
}




int terrain_data_lookup(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int uVar1;

  unsigned int uVar2;

  int iVar3;

  int in_pr;

  iVar3 = CAR_PTR_TARGET;

  if ((*(int *)(iVar3 + 0x000000B8) == 0x2c) || (*(int *)(iVar3 + 0x000001BC) == 0x28)) {

    (*(int(*)())0x0601D5F4)(0x00000000,0xAE1128FF);

  }

  uVar2 = *(unsigned int *)(iVar3 + DAT_06034976);

  if ((int)uVar2 < 0) {

    uVar2 = -uVar2;

  }

  uVar2 = uVar2 >> 10;

  if (7 < uVar2) {

    uVar2 = 7;

  }

  uVar1 = (*(int(*)())0x0601D5F4)(2,uVar2,param_3,param_4,in_pr);

  return uVar1;

}

/* cd_init_and_seek -- Initialize CD status, clear command byte, seek to position.
 * Gets current status via cd_get_status, clears command byte,
 * calls cd_status_full_read, then seeks to param_1 via FUN_06035F04. */
int FUN_06034984(int param_1)
{
    int result;
    char buf[12];

    (*(int(*)())0x06035E90)(buf);  /* cd_get_status */
    buf[0] = 0;                     /* clear command */
    result = (*(int(*)())0x06035EC8)(0, buf);  /* cd_status_full_read */
    (*(int(*)())0x06035F04)(param_1);          /* seek */
    return result;
}

/* cd_check_ready -- Check if CD drive is in ready state.
 * Polls via FUN_06034a10; on success, unpacks status.
 * Returns -8 if drive reports specific error (DAT_06034a8e) or not ready
 * (bit 5 clear). Returns 0 on success, or error from FUN_06034a10. */
int FUN_060349c4(unsigned char *param_1)
{
    int err;
    char buf[12];

    err = FUN_06034a10(buf);
    if (err == 0) {
        (*(int(*)())0x06035F16)(buf, param_1);  /* cd_status_unpack */
        if (*param_1 == DAT_06034a8e || (*param_1 & 0x20) == 0) {
            err = -8;
        }
    }
    return err;
}

/* cd_register_verify -- Read CD register pair and verify consistency.
 * Reads register via 0x06035E5E into param_1 and a local copy.
 * Retries up to 100 times until both reads match (word 0 and word 1).
 * Returns 0 on match, -3 (0xFFFFFFFD) on timeout. */
int FUN_06034a10(int *param_1)
{
  int retries = 0;
  int local_24;
  int iStack_20;

  while (1) {
    (*(int(*)())0x06035E5E)(param_1);
    (*(int(*)())0x06035E5E)(&local_24);
    if ((*param_1 == local_24) && (param_1[1] == iStack_20)) break;
    retries = retries + 1;
    if (99 < retries) {
      return 0xfffffffd;            /* timeout error */
    }
  }
  return 0;
}

/* cd_read_toc -- Read CD table of contents into output buffer.
 * Sends CD status query (0x06035E90), sets command byte to 2 (read TOC),
 * issues command (0x06035EA2). On success, masks response to 24-bit sector
 * count and reads that many words via FUN_06035CBC into param_1. */
int FUN_06034aee(int param_1)
{
  int iVar1;
  unsigned int local_18[2];
  char local_10[12];

  (*(int(*)())0x06035E90)(local_10);
  local_10[0] = 2;                       /* TOC read command */
  iVar1 = (*(int(*)())0x06035EA2)(0, local_10, local_18);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (*(int(*)())0x06035CBC)(local_18[0] & 0x00FFFFFF, param_1);
  return iVar1;
}

/* cd_get_session_info -- Query CD session info for given session number.
 * Sends CD status query, sets command byte to 3 (session info),
 * session number in byte 1. Returns session data in *param_2. */
int FUN_06034b54(char param_1, int *param_2)
{
  int uVar1;
  char auStack_1c[4];
  int uStack_18;
  char local_14;
  char uStack_13;

  (*(int(*)())0x06035E90)(&local_14);
  local_14 = 3;                          /* session info command */
  uStack_13 = param_1;                   /* session number */
  uVar1 = (*(int(*)())0x06035EA2)(0, &local_14, auStack_1c);
  *param_2 = uStack_18;
  return uVar1;
}

/* cd_play_command -- Issue CD play/seek command with track parameters.
 * Builds 6-byte command packet: cmd=4, track=param_1, FAD=param_2,
 * play mode=param_3, repeat=param_4.
 * If (param_1 & 0x81) == 1: delay loop, set HIRQ bit 0x41, send with
 * flag 0x40, then reset HIRQ on success.
 * Otherwise: send command normally with flag 0. */
int FUN_06034b9a(unsigned int param_1, short param_2, char param_3, char param_4)
{
  int iVar1;
  char local_1c;
  char uStack_1b;
  short uStack_1a;
  char uStack_16;
  char uStack_15;

  (*(int(*)())0x06035E90)(&local_1c);
  local_1c = 4;                          /* play command */
  uStack_1b = (char)param_1;             /* track number */
  uStack_1a = param_2;                   /* FAD position */
  uStack_16 = param_3;                   /* play mode */
  uStack_15 = param_4;                   /* repeat flag */

  if ((0x81 & param_1) == 1) {
    for (iVar1 = (int)DAT_06034bf6; 0 < iVar1; iVar1 = iVar1 + -1) {
    }                                    /* busy-wait delay */
    (*(int(*)())0x06035C92)(0x41);       /* set HIRQ bit */
    iVar1 = (*(int(*)())0x06035EC8)(0x40, &local_1c);
    if (iVar1 == 0) {
      (*(int(*)())0x06035C80)();         /* reset HIRQ */
    }
  } else {
    iVar1 = (*(int(*)())0x06035EC8)(0, &local_1c);
  }
  return iVar1;
}

/* cd_tray_command -- Open or close the CD tray.
 * param_1=0: open (cmd 0x02), param_1=1: close (cmd 0x82).
 * Sends command via 0x06035E00, checks close response for disc-in bit.
 * On error, reads disc position via FUN_06034cc8.
 * Clears pending status with mask 0xFFFD via 0x06035C6E. */
int cd_tray_command(param_1)
    int param_1;
{
  int result;
  unsigned short status[2];
  char position_buf[8];

  if (param_1 == 0) {
    result = 2;                                         /* open tray command */
  } else {
    result = 0x82;                                      /* close tray command */
  }
  result = (*(int(*)())0x06035E00)(result, status);
  if (((param_1 == 1) && (result == 0)) && ((status[0] & 0x80) != 0)) {
    result = -4;                                        /* disc not inserted after close */
  }
  if (result != 0) {
    FUN_06034cc8(position_buf);                         /* read disc position on error */
  }
  (*(int(*)())0x06035C6E)(0x0000FFFD);                 /* clear pending status */
  return result;
}

/* cd_get_disc_position -- Read current disc FAD (frame address).
 * Gets status, sets command byte to 6 (get position),
 * calls cd_status_read, masks result to 24-bit FAD. */
int FUN_06034cc8(unsigned int *param_1)
{
    int result;
    unsigned int response[2];
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 6;
    result = (*(int(*)())0x06035EA2)(0, buf, response);
    *param_1 = response[0] & 0x00FFFFFF;
    return result;
}

/* cd_extract_play_params -- Extract CD play parameters from track descriptor.
 * Dispatches by descriptor type (*param_1):
 *   0: call CD sync (0x06035228)
 *   1: FAD-based — set byte 0 = track|0x80, byte 1 = index, byte 2 = flag
 *   2: time-based — set byte 0 = 0, byte 1 = minute, byte 2 = second
 *   3: call CD sync and return immediately
 *   other: fall through to CD sync */
int FUN_06034d5e(int *param_1, unsigned char *param_2)
{
  unsigned char bVar1;
  int iVar2 = *param_1;

  if (iVar2 == 0) {
LAB_06034dac:
    iVar2 = (*(int(*)())0x06035228)();
  } else {
    if (iVar2 == 1) {
      *param_2 = *(unsigned char *)((int)param_1 + 5) | 0x80;
      param_2[1] = *(unsigned char *)((int)param_1 + 6);
      bVar1 = *(unsigned char *)((int)param_1 + 7);
    } else {
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          iVar2 = (*(int(*)())0x06035228)();
          return iVar2;
        }
        goto LAB_06034dac;
      }
      *param_2 = 0;
      param_2[1] = *(unsigned char *)(param_1 + 1);
      bVar1 = *(unsigned char *)((int)param_1 + 5);
    }
    iVar2 = (int)(char)bVar1;
    param_2[2] = bVar1;
  }
  return iVar2;
}

/* cd_play_track -- Start CD audio playback for a track.
 * Gets status, sets command byte to 0x11 (play),
 * extracts play params via FUN_06034d5e, sends full status. */
void FUN_06034dea(int param_1)
{
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x11;
    FUN_06034d5e(param_1, buf + 1);
    (*(int(*)())0x06035EC8)(0, buf);
    return;

}

/* FUN_06034f78: L2 version in bitfield_utils.c */
extern void FUN_06034F78(int val, int param, int ptr);
extern void FUN_06035bc8();
extern void FUN_06035b34();
extern void FUN_060359e4();
extern void FUN_060358ec();
extern void FUN_06035844();
extern void FUN_060357b8();
extern void FUN_06035460();
extern void FUN_06035340();
extern void FUN_06035280();
extern void FUN_06035228();
extern void FUN_06035168();
extern void FUN_060350b0();
extern void FUN_06034ffc();
extern void FUN_06034fe0();
extern void FUN_06034f78();
extern void FUN_060346c0();
extern void FUN_06034640();
extern void FUN_0603458c();
extern void FUN_06034560();
extern void FUN_0603446c();
extern void FUN_06034168();
extern void FUN_06034000();

















/* cd_strlen -- String length (custom strlen for CD subsystem).
 * Counts characters until null terminator. Goto/check pattern
 * matches original SH-2 dt/bf loop. */
int FUN_06035c1c(char *str)
{
    register int count asm("r0") = 0;
    goto check;
body:
    count++;
check:
    if (*str++ != '\0') goto body;
    return count;
}

/* sh2_div32_remainder -- Signed 32-bit division via SH-2 hardware, return remainder.
 * Same as FUN_06034fe0 but returns remainder from DVDNT+16 instead
 * of quotient. Writes dividend/divisor to SH-2 DIVU at 0xFFFFFF00. */
int FUN_06035c2c()
{
  int in_r0 = 0;
  int in_r1 = 0;
  int *puVar1;

  puVar1 = (int *)-256;
  *puVar1 = in_r0;
  puVar1[2] = 0;
  puVar1[1] = in_r1;
  return puVar1[4];
}

/* cd_hirq_set_and_send -- Set HIRQ request bit and send CD command with bit 0 set */
void FUN_06035c54(unsigned int cmd)
{
    *(unsigned short *)0x06063590 |= CD_HIRQREQ;
    FUN_06035c6e(cmd | 1);
}

/* cd_reset_hirq -- Send CD reset command (0x0BE1) and clear HIRQ status */
void FUN_06035c80(void)
{
    FUN_06035c6e(0x0BE1);
    *(short *)0x06063590 = 0;
}

/* cd_sector_read_words -- Read param_1 words from CD data register into buffer.
 * Initializes transfer via FUN_06034C68, then reads words from the CD
 * data port at 0x25898000 into param_2. After transfer, verifies the
 * actual word count matches expected. Returns -7 on count mismatch. */
int FUN_06035cbc(int param_1, short *param_2)
{
  short *cd_data_port = (short *)0x25898000;
  int iVar2;
  int local_14[2];

  iVar2 = (*(int(*)())0x06034C68)(0);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (0 < param_1) {
      do {
        iVar2 = iVar2 + 1;
        *param_2 = *cd_data_port;
        param_2 = param_2 + 1;
      } while (iVar2 < param_1);
    }
    iVar2 = (*(int(*)())0x06034CC8)(local_14);
    if ((iVar2 == 0) && (param_1 != local_14[0])) {
      iVar2 = -7;                        /* word count mismatch */
    }
  }
  return iVar2;
}

/* cd_wait_hirq -- Poll CD HIRQ register until requested bits are set.
 * Spins up to 0x240000 iterations (~2.3M) checking CD_HIRQREQ against
 * param_1 mask. On match, stores current HIRQ status to *param_2.
 * Returns 0 on success, -3 (0xFFFFFFFD) on timeout. */
int FUN_06035e00(unsigned short param_1, unsigned short *param_2)
{
  int iVar1 = 0;

  do {
    if ((CD_HIRQREQ & param_1) != 0) {
      *param_2 = CD_HIRQREQ;
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < (int)0x00240000);

  return 0xfffffffd;                     /* timeout */
}

/* cd_get_status -- Thin wrapper: query CD drive status via FUN_06035168 */
int FUN_06035e90(void)
{
    return (*(int(*)())0x06035168)();
}

/* cd_status_read -- Read CD drive status byte.
 * Calls low-level CD command (0x06035D22); on success, copies
 * first byte of response to CD status mirror at 0x06063594. */
int FUN_06035ea2(int param_1, int param_2, char *param_3)
{
    int err = (*(int(*)())0x06035D22)();
    if (err != 0)
        return err;

    *(int *)0x06063594 = *param_3;
    return 0;
}

/* cd_status_full_read -- Read full CD status and copy to mirror buffer.
 * Calls low-level CD command into temp buffer, then copies parsed
 * fields to the CD status mirror at 0x06063594 via FUN_06035f16. */
int FUN_06035ec8(int param_1, int param_2)
{
    int err;
    char buf[12];

    err = (*(int(*)())0x06035D22)(param_1, param_2, buf);
    if (err != 0)
        return err;

    FUN_06035f16(buf, (char *)0x06063594);
    return 0;
}

/* cd_status_unpack -- Unpack CD status from compact 5-byte format to expanded fields.
 * src[0] -> dest[0] (status byte)
 * src[1..4] -> dest[4..7] (FAD/track info)
 * src[4..7] masked to 24-bit -> dest[8..11] (position) */
void FUN_06035f16(char *src, char *dest)
{
    dest[0] = src[0];
    dest[4] = src[1];
    dest[5] = src[2];
    dest[6] = src[3];
    dest[7] = src[4];
    *(unsigned int *)(dest + 8) = *(unsigned int *)(src + 4) & 0x00FFFFFF;
}

/* softfloat_double_subtract -- Software IEEE 754 double-precision subtraction.
 * Negates second operand sign bit and falls through to addition logic.
 * Handles exponent alignment, mantissa subtraction with borrow,
 * normalization, and special cases (NaN, infinity, denormals). */
unsigned int FUN_06035f44()
{
  char cVar1;
  int bVar2;
  int bVar3;
  int bVar4;
  unsigned char bVar5;
  unsigned int uVar6;
  int in_r0 = 0;
  unsigned int in_r1 = 0;
  unsigned int uVar7;
  unsigned int uVar9;
  unsigned int uVar11;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  unsigned int uVar20;
  unsigned int uVar21;
  unsigned int uVar22;
  unsigned int uVar23;
  unsigned int uVar24;
  unsigned int uVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  unsigned int uVar30;
  unsigned int uVar31;
  unsigned int uVar32;
  unsigned int uVar33;
  unsigned int uVar34;
  unsigned int uVar35;
  unsigned int uVar36;
  unsigned int uVar37;
  unsigned int uVar38;
  unsigned int uVar39;
  unsigned int uVar40;
  unsigned int uVar8;
  unsigned int uVar10;

  if (in_r0 != 0) {
    uVar7 = (unsigned int)((in_r1 & 0x80000000) != 0);
    uVar8 = uVar7 - in_r0;
    bVar4 = uVar8 <= uVar7;
    uVar12 = in_r1 << 2;
    bVar3 = (uVar8 & 0x80000000) == 0;
    uVar7 = (uVar8 << 1) | (unsigned int)((in_r1 & 0x40000000) != 0);
    uVar8 = (unsigned int)bVar4 * (uVar7 - in_r0) + (unsigned int)!bVar4 * (uVar7 + in_r0);
    cVar1 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    bVar5 = bVar3 * cVar1 + (!bVar3 && cVar1 == '\0');
    uVar7 = (unsigned int)bVar5 << 8;
    uVar9 = (uVar8 << 1) | (unsigned int)((uVar12 & 0x80000000) != 0);
    bVar3 = (bVar5 & 1) == ((unsigned char)(uVar7 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar7 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar9 - in_r0) + (unsigned int)!bVar3 * (uVar9 + in_r0);
    cVar1 = bVar3 * (uVar9 < uVar10) + !bVar3 * (uVar10 < uVar9);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar13 = uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar7 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar14 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar15 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar16 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar17 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar18 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar19 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar20 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar21 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar22 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar23 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar24 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar25 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar26 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar27 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar28 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar29 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar30 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar31 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar32 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar33 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar34 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar35 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar36 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar37 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar38 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar39 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar40 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 8) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar11 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar12 = (uVar10 << 1) | (unsigned int)((uVar12 & 4) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar9 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
    cVar1 = bVar3 * (uVar12 < uVar9) + !bVar3 * (uVar9 < uVar12);
    uVar8 = uVar6 | uVar8 & 0xfffffeff |
            (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    return (((((((((((((((((((((((((((((((unsigned int)bVar4 << 1 |
                                        (unsigned int)((bVar5 & 1) == ((unsigned char)(uVar7 >> 9) & 1))) << 1 |
                                       (unsigned int)(((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1)
                                             )) << 1 |
                                      (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) == ((unsigned char)(uVar14 >> 9) & 1))
                                      ) << 1 | (unsigned int)(((unsigned char)(uVar15 >> 8) & 1) ==
                                                     ((unsigned char)(uVar15 >> 9) & 1))) << 1 |
                                    (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) == ((unsigned char)(uVar16 >> 9) & 1)))
                                    << 1 | (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) ==
                                                 ((unsigned char)(uVar17 >> 9) & 1))) << 1 |
                                  (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) == ((unsigned char)(uVar18 >> 9) & 1))) <<
                                  1 | (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) == ((unsigned char)(uVar19 >> 9) & 1))
                                 ) << 1 | (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) ==
                                                ((unsigned char)(uVar20 >> 9) & 1))) << 1 |
                               (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) == ((unsigned char)(uVar21 >> 9) & 1))) << 1
                              | (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) == ((unsigned char)(uVar22 >> 9) & 1))) << 1
                             | (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) == ((unsigned char)(uVar23 >> 9) & 1))) << 1
                            | (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) == ((unsigned char)(uVar24 >> 9) & 1))) << 1 |
                           (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1))) << 1 |
                          (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))) << 1 |
                         (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) == ((unsigned char)(uVar27 >> 9) & 1))) << 1 |
                        (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1))) << 1 |
                       (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) == ((unsigned char)(uVar29 >> 9) & 1))) << 1 |
                      (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) << 1 |
                     (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))) << 1 |
                    (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) == ((unsigned char)(uVar32 >> 9) & 1))) << 1 |
                   (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1 |
                  (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1 |
                 (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1 |
                (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |
               (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |
              (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |
             (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |
            (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1));
  }
  *(int *)0x060A246C = 0x0000044E;
  return 0;
}

/* --- FUN_06034C68 (L1 import from src/FUN_06034C68.c) --- */

int FUN_06034c68(param_1)
    int param_1;
{

  int iVar1;

  unsigned short local_14 [2];

  char auStack_10 [8];

  if (param_1 == 0) {

    iVar1 = 2;

  }

  else {

    iVar1 = 0x82;

  }

  iVar1 = (*(int(*)())0x06035E00)(iVar1,local_14);

  if (((param_1 == 1) && (iVar1 == 0)) && ((local_14[0] & 0x80) != 0)) {

    iVar1 = -4;

  }

  if (iVar1 != 0) {

    FUN_06034cc8(auStack_10);

  }

  (*(int(*)())0x06035C6E)(0x0000FFFD);

  return iVar1;

}
