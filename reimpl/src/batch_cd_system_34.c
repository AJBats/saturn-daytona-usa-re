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
/* FUN_06034708 -- original binary (24 bytes) */
__asm__(
    ".section .text.FUN_06034708, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034708\n"
    ".type _FUN_06034708, @function\n"
    "_FUN_06034708:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0x6E, 0x43\n"  /* 0x06034708 */
    ".byte 0xD0, 0x0C, 0x02, 0xEE, 0xD0, 0x0C, 0x0E, 0x26\n"  /* 0x06034718 */
);





#if 0 /* terrain_data_lookup -- redirected to ASM import via linker PROVIDE */
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
#endif /* terrain_data_lookup */

/* cd_init_and_seek -- Initialize CD status, clear command byte, seek to position.
 * Gets current status via cd_get_status, clears command byte,
 * calls cd_status_full_read, then seeks to param_1 via FUN_06035F04. */
/* FUN_06034984 -- original binary (50 bytes) */
__asm__(
    ".section .text.FUN_06034984, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034984\n"
    ".type _FUN_06034984, @function\n"
    "_FUN_06034984:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0x6D, 0x43, 0x7F, 0xF8, 0xD3, 0x13, 0x43, 0x0B, 0x64, 0xF3\n"  /* 0x06034984 */
    ".byte 0x62, 0xF3, 0xE3, 0x00, 0x65, 0xF3, 0x22, 0x30, 0xD3, 0x10, 0x43, 0x0B, 0xE4, 0x00, 0x6E, 0x03\n"  /* 0x06034994 */
    ".byte 0xD3, 0x0F, 0x43, 0x0B, 0x64, 0xD3, 0x60, 0xE3, 0x7F, 0x08, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B\n"  /* 0x060349A4 */
    ".byte 0x6E, 0xF6\n"  /* 0x060349B4 */
);


/* cd_check_ready -- Check if CD drive is in ready state.
 * Polls via FUN_06034a10; on success, unpacks status.
 * Returns -8 if drive reports specific error (DAT_06034a8e) or not ready
 * (bit 5 clear). Returns 0 on success, or error from FUN_06034a10. */
#if 0 /* FUN_060349C4 -- replaced by ASM import */
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
#endif

/* cd_register_verify -- Read CD register pair and verify consistency.
 * Reads register via 0x06035E5E into param_1 and a local copy.
 * Retries up to 100 times until both reads match (word 0 and word 1).
 * Returns 0 on match, -3 (0xFFFFFFFD) on timeout. */
#if 0 /* FUN_06034A10 -- replaced by ASM import */
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
#endif

/* FUN_06034A10 -- original binary (140 bytes) */
__asm__(
    ".section .text.FUN_06034A10, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034A10\n"
    ".global _FUN_06034a10\n"
    ".type _FUN_06034A10, @function\n"
    "_FUN_06034A10:\n"
    "_FUN_06034a10:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x4F, 0x22, 0x7F, 0xF8\n"  /* 0x06034A10 */
    ".byte 0xEC, 0x00, 0xDE, 0x1D, 0x6B, 0x43, 0xEA, 0xFD, 0x6D, 0xC3, 0x00, 0x02, 0x40, 0x09, 0x40, 0x09\n"  /* 0x06034A20 */
    ".byte 0xC9, 0x0F, 0x69, 0x03, 0x00, 0x02, 0x93, 0x2B, 0x20, 0x39, 0xCB, 0xF0, 0x40, 0x0E, 0x4E, 0x0B\n"  /* 0x06034A30 */
    ".byte 0x64, 0xB3, 0x4E, 0x0B, 0x64, 0xF3, 0x60, 0x93, 0xC9, 0x0F, 0x40, 0x08, 0x40, 0x08, 0x02, 0x02\n"  /* 0x06034A40 */
    ".byte 0x93, 0x1E, 0x22, 0x39, 0x20, 0x2B, 0x40, 0x0E, 0x64, 0xB3, 0x62, 0xF3, 0x63, 0x42, 0x62, 0x22\n"  /* 0x06034A50 */
    ".byte 0x33, 0x20, 0x8B, 0x06, 0x62, 0xF3, 0x53, 0x41, 0x52, 0x21, 0x33, 0x20, 0x8B, 0x01, 0xA0, 0x04\n"  /* 0x06034A60 */
    ".byte 0x6A, 0xC3, 0x7D, 0x01, 0xE2, 0x64, 0x3D, 0x23, 0x8B, 0xD7, 0x60, 0xA3, 0x7F, 0x08, 0x4F, 0x26\n"  /* 0x06034A70 */
    ".byte 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x00, 0xFF\n"  /* 0x06034A80 */
    ".byte 0xFF, 0x0F, 0xFF, 0xFF, 0x06, 0x03, 0x5F, 0x16, 0x06, 0x03, 0x5E, 0x5E\n"  /* 0x06034A90 */
);


/* cd_read_toc -- Read CD table of contents into output buffer.
 * Sends CD status query (0x06035E90), sets command byte to 2 (read TOC),
 * issues command (0x06035EA2). On success, masks response to 24-bit sector
 * count and reads that many words via FUN_06035CBC into param_1. */
#if 0 /* FUN_06034AEE -- replaced by ASM import */
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
#endif

/* FUN_06034AEE -- original binary (102 bytes) */
__asm__(
    ".section .text.FUN_06034AEE, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034AEE\n"
    ".global _FUN_06034aee\n"
    ".type _FUN_06034AEE, @function\n"
    "_FUN_06034AEE:\n"
    "_FUN_06034aee:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x6E, 0x43, 0x7F, 0xEC, 0x64, 0xF3, 0xD3, 0x12, 0x43, 0x0B, 0x74, 0x0C\n"  /* 0x06034AEE */
    ".byte 0x62, 0xF3, 0xE3, 0x02, 0x66, 0xF3, 0x65, 0xF3, 0x72, 0x0C, 0x76, 0x04, 0x75, 0x0C, 0x22, 0x30\n"  /* 0x06034AFE */
    ".byte 0xD3, 0x0E, 0x43, 0x0B, 0xE4, 0x00, 0x64, 0x03, 0x24, 0x48, 0x89, 0x04, 0x60, 0x43, 0x7F, 0x14\n"  /* 0x06034B0E */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x63, 0xF3, 0x65, 0xE3, 0x73, 0x04, 0x62, 0x32, 0xD3, 0x07\n"  /* 0x06034B1E */
    ".byte 0x22, 0x39, 0x2F, 0x22, 0xD3, 0x07, 0x43, 0x0B, 0x64, 0x23, 0x64, 0x03, 0x7F, 0x14, 0x4F, 0x26\n"  /* 0x06034B2E */
    ".byte 0x00, 0x0B, 0x6E, 0xF6, 0xFF, 0xFF, 0x06, 0x03, 0x5E, 0x90, 0x06, 0x03, 0x5E, 0xA2, 0x00, 0xFF\n"  /* 0x06034B3E */
    ".byte 0xFF, 0xFF, 0x06, 0x03, 0x5C, 0xBC\n"  /* 0x06034B4E */
);


/* cd_get_session_info -- Query CD session info for given session number.
 * Sends CD status query, sets command byte to 3 (session info),
 * session number in byte 1. Returns session data in *param_2. */
#if 0 /* FUN_06034B54 -- replaced by ASM import */
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
#endif

/* cd_play_command -- Issue CD play/seek command with track parameters.
 * Builds 6-byte command packet: cmd=4, track=param_1, FAD=param_2,
 * play mode=param_3, repeat=param_4.
 * If (param_1 & 0x81) == 1: delay loop, set HIRQ bit 0x41, send with
 * flag 0x40, then reset HIRQ on success.
 * Otherwise: send command normally with flag 0. */
#if 0 /* FUN_06034B9A -- replaced by ASM import */
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
#endif

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
#if 0 /* FUN_06034CC8 -- replaced by ASM import */
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
#endif

/* cd_extract_play_params -- Extract CD play parameters from track descriptor.
 * Dispatches by descriptor type (*param_1):
 *   0: call CD sync (0x06035228)
 *   1: FAD-based — set byte 0 = track|0x80, byte 1 = index, byte 2 = flag
 *   2: time-based — set byte 0 = 0, byte 1 = minute, byte 2 = second
 *   3: call CD sync and return immediately
 *   other: fall through to CD sync */
#if 0 /* FUN_06034D5E -- replaced by ASM import */
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
#endif

/* FUN_06034D5E -- original binary (140 bytes) */
__asm__(
    ".section .text.FUN_06034D5E, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034D5E\n"
    ".global _FUN_06034d5e\n"
    ".type _FUN_06034D5E, @function\n"
    "_FUN_06034D5E:\n"
    "_FUN_06034d5e:\n"
    ".byte 0x4F, 0x22, 0xA0, 0x36, 0x60, 0x42, 0xE2, 0x00, 0x25, 0x20, 0x84, 0x44, 0x63, 0x03, 0x80, 0x51\n"  /* 0x06034D5E */
    ".byte 0x84, 0x45, 0x63, 0x03, 0xA0, 0x12, 0x00, 0x09, 0x60, 0x43, 0x70, 0x04, 0x84, 0x01, 0x60, 0x0C\n"  /* 0x06034D6E */
    ".byte 0xCB, 0x80, 0x60, 0x0C, 0x25, 0x00, 0x63, 0x43, 0x73, 0x04, 0x84, 0x32, 0x62, 0x03, 0x60, 0x23\n"  /* 0x06034D7E */
    ".byte 0x80, 0x51, 0x63, 0x43, 0x73, 0x04, 0x84, 0x33, 0x62, 0x03, 0x60, 0x23, 0xA0, 0x23, 0x80, 0x52\n"  /* 0x06034D8E */
    ".byte 0x61, 0x53, 0xD2, 0x08, 0xD3, 0x09, 0x43, 0x0B, 0xE0, 0x03, 0xA0, 0x1C, 0x00, 0x09, 0x61, 0x53\n"  /* 0x06034D9E */
    ".byte 0xD2, 0x07, 0xD3, 0x05, 0x43, 0x0B, 0xE0, 0x03, 0xA0, 0x15, 0x00, 0x09, 0xFF, 0xFF, 0x06, 0x03\n"  /* 0x06034DAE */
    ".byte 0x5E, 0x90, 0x06, 0x03, 0x5E, 0xC8, 0x06, 0x05, 0x9C, 0xA7, 0x06, 0x03, 0x52, 0x28, 0x06, 0x05\n"  /* 0x06034DBE */
    ".byte 0x9C, 0xA4, 0x88, 0x00, 0x89, 0xEB, 0x88, 0x01, 0x89, 0xCE, 0x88, 0x02, 0x89, 0xC3, 0x88, 0x03\n"  /* 0x06034DCE */
    ".byte 0x89, 0xDE, 0xAF, 0xE4, 0x00, 0x09, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06034DDE */
);


/* cd_play_track -- Start CD audio playback for a track.
 * Gets status, sets command byte to 0x11 (play),
 * extracts play params via FUN_06034d5e, sends full status. */
#if 0 /* FUN_06034DEA -- replaced by ASM import */
void FUN_06034dea(int param_1)
{
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x11;
    FUN_06034d5e(param_1, buf + 1);
    (*(int(*)())0x06035EC8)(0, buf);
    return;

}
#endif

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
#if 0 /* FUN_06035C54 -- replaced by ASM import */
void FUN_06035c54(unsigned int cmd)
{
    *(unsigned short *)0x06063590 |= CD_HIRQREQ;
    FUN_06035c6e(cmd | 1);
}
#endif

/* FUN_06035C54 -- original binary (44 bytes) */
__asm__(
    ".section .text.FUN_06035C54, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035C54\n"
    ".global _FUN_06035c54\n"
    ".type _FUN_06035C54, @function\n"
    "_FUN_06035C54:\n"
    "_FUN_06035c54:\n"
    ".byte 0x4F, 0x22, 0xD3, 0x08, 0x63, 0x31, 0x63, 0x3D, 0xD2, 0x07, 0x62, 0x21, 0x22, 0x3B, 0xD3, 0x06\n"  /* 0x06035C54 */
    ".byte 0x23, 0x21, 0xE1, 0x01, 0x24, 0x1B, 0xA0, 0x00, 0x4F, 0x26, 0xD3, 0x02, 0x00, 0x0B, 0x23, 0x41\n"  /* 0x06035C64 */
    ".byte 0x25, 0x81, 0x80, 0x00, 0x25, 0x89, 0x00, 0x08, 0x06, 0x06, 0x35, 0x90\n"  /* 0x06035C74 */
);


/* cd_reset_hirq -- Send CD reset command (0x0BE1) and clear HIRQ status */
#if 0 /* FUN_06035C80 -- replaced by ASM import */
void FUN_06035c80(void)
{
    FUN_06035c6e(0x0BE1);
    *(short *)0x06063590 = 0;
}
#endif

/* FUN_06035C80 -- original binary (60 bytes) */
__asm__(
    ".section .text.FUN_06035C80, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035C80\n"
    ".global _FUN_06035c80\n"
    ".type _FUN_06035C80, @function\n"
    "_FUN_06035C80:\n"
    "_FUN_06035c80:\n"
    ".byte 0x4F, 0x22, 0x94, 0x10, 0xBF, 0xF3, 0x00, 0x09, 0xE2, 0x00, 0xD3, 0x07, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x06035C80 */
    ".byte 0x23, 0x21, 0x64, 0x4D, 0xD3, 0x04, 0xD2, 0x04, 0x63, 0x31, 0x23, 0x4B, 0x00, 0x0B, 0x22, 0x31\n"  /* 0x06035C90 */
    ".byte 0xD0, 0x02, 0x00, 0x0B, 0x60, 0x01, 0x0B, 0xE1, 0x06, 0x06, 0x35, 0x90, 0x25, 0x89, 0x00, 0x0C\n"  /* 0x06035CA0 */
    ".byte 0xD3, 0x0A, 0x00, 0x0B, 0x23, 0x41, 0xD0, 0x0A, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06035CB0 */
);


/* cd_sector_read_words -- Read param_1 words from CD data register into buffer.
 * Initializes transfer via FUN_06034C68, then reads words from the CD
 * data port at 0x25898000 into param_2. After transfer, verifies the
 * actual word count matches expected. Returns -7 on count mismatch. */
#if 0 /* FUN_06035CBC -- replaced by ASM import */
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
#endif

/* FUN_06035CBC -- original binary (102 bytes) */
__asm__(
    ".section .text.FUN_06035CBC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035CBC\n"
    ".global _FUN_06035cbc\n"
    ".type _FUN_06035CBC, @function\n"
    "_FUN_06035CBC:\n"
    "_FUN_06035cbc:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43, 0x2F, 0xD6, 0x2F, 0xC6, 0x4F, 0x22, 0x6C, 0x53, 0x7F, 0xFC, 0xDD, 0x06\n"  /* 0x06035CBC */
    ".byte 0xD3, 0x06, 0x43, 0x0B, 0xE4, 0x00, 0x64, 0x03, 0x24, 0x48, 0x89, 0x09, 0xA0, 0x1D, 0x60, 0x43\n"  /* 0x06035CCC */
    ".byte 0x25, 0x89, 0x00, 0x0C, 0x25, 0x81, 0x80, 0x28, 0x25, 0x89, 0x80, 0x00, 0x06, 0x03, 0x4C, 0x68\n"  /* 0x06035CDC */
    ".byte 0x64, 0xC3, 0x4E, 0x15, 0x8F, 0x06, 0xE5, 0x00, 0x62, 0xD1, 0x75, 0x01, 0x24, 0x21, 0x35, 0xE3\n"  /* 0x06035CEC */
    ".byte 0x8F, 0xFA, 0x74, 0x02, 0xD3, 0x22, 0x43, 0x0B, 0x64, 0xF3, 0x64, 0x03, 0x24, 0x48, 0x8B, 0x03\n"  /* 0x06035CFC */
    ".byte 0x63, 0xF2, 0x3E, 0x30, 0x89, 0x00, 0xE4, 0xF9, 0x60, 0x43, 0x7F, 0x04, 0x4F, 0x26, 0x6C, 0xF6\n"  /* 0x06035D0C */
    ".byte 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06035D1C */
);


/* cd_wait_hirq -- Poll CD HIRQ register until requested bits are set.
 * Spins up to 0x240000 iterations (~2.3M) checking CD_HIRQREQ against
 * param_1 mask. On match, stores current HIRQ status to *param_2.
 * Returns 0 on success, -3 (0xFFFFFFFD) on timeout. */
#if 0 /* FUN_06035E00 -- replaced by ASM import */
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
#endif

/* FUN_06035E00 -- original binary (144 bytes) */
__asm__(
    ".section .text.FUN_06035E00, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035E00\n"
    ".global _FUN_06035e00\n"
    ".type _FUN_06035E00, @function\n"
    "_FUN_06035E00:\n"
    "_FUN_06035e00:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xB6, 0xDB, 0x07, 0xDD, 0x07, 0xEE, 0x00, 0xE1, 0xFD, 0x67, 0xE3\n"  /* 0x06035E00 */
    ".byte 0x66, 0xB1, 0x62, 0x4D, 0x63, 0x6D, 0x23, 0x29, 0x23, 0x38, 0x89, 0x07, 0x61, 0xE3, 0xA0, 0x08\n"  /* 0x06035E10 */
    ".byte 0x25, 0x61, 0x00, 0xFF, 0x25, 0x89, 0x00, 0x08, 0x00, 0x24, 0x00, 0x00, 0x77, 0x01, 0x37, 0xD3\n"  /* 0x06035E20 */
    ".byte 0x8B, 0xEE, 0x60, 0x13, 0x6B, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x65, 0x43, 0xD2, 0x10\n"  /* 0x06035E30 */
    ".byte 0x63, 0x51, 0x22, 0x31, 0x85, 0x51, 0xD2, 0x0F, 0x63, 0x03, 0x22, 0x31, 0x85, 0x52, 0xD2, 0x0E\n"  /* 0x06035E40 */
    ".byte 0x63, 0x03, 0x22, 0x31, 0x85, 0x53, 0xD2, 0x0D, 0x63, 0x03, 0x00, 0x0B, 0x22, 0x31, 0xD3, 0x08\n"  /* 0x06035E50 */
    ".byte 0x63, 0x31, 0x24, 0x31, 0xD2, 0x07, 0x62, 0x21, 0x60, 0x23, 0x81, 0x41, 0xD3, 0x06, 0x63, 0x31\n"  /* 0x06035E60 */
    ".byte 0x60, 0x33, 0x81, 0x42, 0xD3, 0x05, 0x63, 0x31, 0x60, 0x33, 0x00, 0x0B, 0x81, 0x43, 0xFF, 0xFF\n"  /* 0x06035E70 */
    ".byte 0x25, 0x89, 0x00, 0x18, 0x25, 0x89, 0x00, 0x1C, 0x25, 0x89, 0x00, 0x20, 0x25, 0x89, 0x00, 0x24\n"  /* 0x06035E80 */
);


/* cd_get_status -- Thin wrapper: query CD drive status via FUN_06035168 */
#if 0 /* FUN_06035E90 -- replaced by ASM import of original bytes */
int FUN_06035e90(void)
{
    return (*(int(*)())0x06035168)();
}
#endif

/* cd_status_read -- Read CD drive status byte.
 * Calls low-level CD command (0x06035D22); on success, copies
 * first byte of response to CD status mirror at 0x06063594. */
#if 0 /* FUN_06035EA2 -- replaced by ASM import */
int FUN_06035ea2(int param_1, int param_2, char *param_3)
{
    int err = (*(int(*)())0x06035D22)();
    if (err != 0)
        return err;

    *(int *)0x06063594 = *param_3;
    return 0;
}
#endif

/* FUN_06035EA2 -- original binary (38 bytes) */
__asm__(
    ".section .text.FUN_06035EA2, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035EA2\n"
    ".global _FUN_06035ea2\n"
    ".type _FUN_06035EA2, @function\n"
    "_FUN_06035EA2:\n"
    "_FUN_06035ea2:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0xD3, 0x11, 0x43, 0x0B, 0x6E, 0x63, 0x64, 0x03, 0x24, 0x48, 0x89, 0x03\n"  /* 0x06035EA2 */
    ".byte 0x60, 0x43, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0xD3, 0x0D, 0x62, 0xE0, 0x23, 0x20, 0x60, 0x43\n"  /* 0x06035EB2 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06035EC2 */
);


/* cd_status_full_read -- Read full CD status and copy to mirror buffer.
 * Calls low-level CD command into temp buffer, then copies parsed
 * fields to the CD status mirror at 0x06063594 via FUN_06035f16. */
#if 0 /* FUN_06035EC8 -- replaced by ASM import */
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
#endif

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

#if 0 /* FUN_06034C68 -- replaced by ASM import of original bytes */
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
#endif

/* FUN_06034C68 -- original binary (96 bytes) */
__asm__(
    ".section .text.FUN_06034C68, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034C68\n"
    ".global _FUN_06034c68\n"
    ".type _FUN_06034C68, @function\n"
    "_FUN_06034C68:\n"
    "_FUN_06034c68:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0x6D, 0x43, 0x7F, 0xF8, 0x2D, 0xD8, 0x8B, 0x0A, 0xA0, 0x0A\n"  /* 0x06034C68 */
    ".byte 0xE4, 0x02, 0xFF, 0xFF, 0x06, 0x03, 0x5C, 0x92, 0x06, 0x03, 0x5E, 0xC8, 0x06, 0x03, 0x5C, 0x80\n"  /* 0x06034C78 */
    ".byte 0x06, 0x03, 0x5E, 0x90, 0x94, 0x39, 0xD3, 0x1D, 0x43, 0x0B, 0x65, 0xF3, 0x6E, 0x03, 0x60, 0xD3\n"  /* 0x06034C88 */
    ".byte 0x88, 0x01, 0x8B, 0x06, 0x2E, 0xE8, 0x8B, 0x04, 0x60, 0xF1, 0x60, 0x0D, 0xC8, 0x80, 0x89, 0x00\n"  /* 0x06034C98 */
    ".byte 0xEE, 0xFC, 0x2E, 0xE8, 0x89, 0x02, 0x64, 0xF3, 0xB0, 0x0A, 0x74, 0x04, 0xD4, 0x14, 0xD3, 0x15\n"  /* 0x06034CA8 */
    ".byte 0x43, 0x0B, 0x00, 0x09, 0x60, 0xE3, 0x7F, 0x08, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06034CB8 */
);

/* FUN_06035E90 -- original binary (18 bytes) */
__asm__(
    ".section .text.FUN_06035E90, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035E90\n"
    ".global _FUN_06035e90\n"
    ".type _FUN_06035E90, @function\n"
    "_FUN_06035E90:\n"
    "_FUN_06035e90:\n"
    ".byte 0x4F, 0x22, 0x61, 0x43, 0xD2, 0x13, 0xD3, 0x14, 0x43, 0x0B, 0xE0, 0x08, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x06035E90 */
    ".byte 0x00, 0x09\n"  /* 0x06035EA0 */
);

/* FUN_060349C4 -- original binary (76 bytes) */
__asm__(
    ".section .text.FUN_060349C4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060349C4\n"
    ".global _FUN_060349c4\n"
    ".type _FUN_060349C4, @function\n"
    "_FUN_060349C4:\n"
    "_FUN_060349c4:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0x6D, 0x43, 0x7F, 0xF8, 0xB0, 0x1F, 0x64, 0xF3, 0x6E, 0x03\n"  /* 0x060349C4 */
    ".byte 0x2E, 0xE8, 0x89, 0x07, 0xA0, 0x15, 0x60, 0xE3, 0x06, 0x03, 0x5E, 0x90, 0x06, 0x03, 0x5E, 0xC8\n"  /* 0x060349D4 */
    ".byte 0x06, 0x03, 0x5F, 0x04, 0x65, 0xD3, 0xD3, 0x2A, 0x43, 0x0B, 0x64, 0xF3, 0x64, 0xD0, 0x92, 0x4C\n"  /* 0x060349E4 */
    ".byte 0x64, 0x4C, 0x34, 0x20, 0x89, 0x03, 0xE2, 0x20, 0x22, 0x49, 0x22, 0x28, 0x8B, 0x00, 0xEE, 0xF8\n"  /* 0x060349F4 */
    ".byte 0x60, 0xE3, 0x7F, 0x08, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06034A04 */
);

/* FUN_06034B9A -- original binary (14 bytes) */
__asm__(
    ".section .text.FUN_06034B9A, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034B9A\n"
    ".global _FUN_06034b9a\n"
    ".type _FUN_06034B9A, @function\n"
    "_FUN_06034B9A:\n"
    "_FUN_06034b9a:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x6E, 0x43, 0x2F, 0xC6, 0x6D, 0x63, 0x2F, 0xB6, 0x6C, 0x73\n"  /* 0x06034B9A */
);

/* FUN_06034CC8 -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_06034CC8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034CC8\n"
    ".global _FUN_06034cc8\n"
    ".type _FUN_06034CC8, @function\n"
    "_FUN_06034CC8:\n"
    "_FUN_06034cc8:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43\n"  /* 0x06034CC8 */
);

/* FUN_06034B54 -- original binary (8 bytes) */
__asm__(
    ".section .text.FUN_06034B54, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034B54\n"
    ".global _FUN_06034b54\n"
    ".type _FUN_06034B54, @function\n"
    "_FUN_06034B54:\n"
    "_FUN_06034b54:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43, 0x2F, 0xD6, 0x6D, 0x53\n"  /* 0x06034B54 */
);

/* FUN_06035EC8 -- original binary (60 bytes) */
__asm__(
    ".section .text.FUN_06035EC8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06035EC8\n"
    ".global _FUN_06035ec8\n"
    ".type _FUN_06035EC8, @function\n"
    "_FUN_06035EC8:\n"
    "_FUN_06035ec8:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x7F, 0xF8, 0xD3, 0x07, 0x43, 0x0B, 0x66, 0xF3, 0x6E, 0x03, 0x2E, 0xE8\n"  /* 0x06035EC8 */
    ".byte 0x89, 0x0C, 0x60, 0xE3, 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x06, 0x05, 0x9C, 0xB0\n"  /* 0x06035ED8 */
    ".byte 0x06, 0x03, 0x51, 0x68, 0x06, 0x03, 0x5D, 0x22, 0x06, 0x06, 0x35, 0x94, 0xD5, 0x10, 0xB0, 0x0E\n"  /* 0x06035EE8 */
    ".byte 0x64, 0xF3, 0x60, 0xE3, 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06035EF8 */
);

/* FUN_06034DEA -- original binary (54 bytes) */
__asm__(
    ".section .text.FUN_06034DEA, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06034DEA\n"
    ".global _FUN_06034dea\n"
    ".type _FUN_06034DEA, @function\n"
    "_FUN_06034DEA:\n"
    "_FUN_06034dea:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x6E, 0x43, 0x7F, 0xF8, 0xD3, 0x09, 0x43, 0x0B, 0x64, 0xF3, 0x62, 0xF3\n"  /* 0x06034DEA */
    ".byte 0xE3, 0x11, 0x65, 0xF3, 0x22, 0x30, 0x75, 0x01, 0xBF, 0xAC, 0x64, 0xE3, 0x65, 0xF3, 0xD3, 0x04\n"  /* 0x06034DFA */
    ".byte 0x43, 0x0B, 0xE4, 0x00, 0x64, 0x03, 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x06, 0x03\n"  /* 0x06034E0A */
    ".byte 0x5E, 0x90, 0x06, 0x03, 0x5E, 0xC8\n"  /* 0x06034E1A */
);
