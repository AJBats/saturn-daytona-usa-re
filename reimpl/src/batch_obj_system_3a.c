#include "game.h"

extern int DAT_0603a1a2;
extern int DAT_0603a2ca;
extern int DAT_0603a6fa;
extern int DAT_0603a6fc;
extern int DAT_0603a6fe;
extern int DAT_0603a8bc;
extern int DAT_0603aa7c;
extern int DAT_0603aa7e;
extern int DAT_0603ac16;
extern int DAT_0603ac18;
extern int DAT_0603ac1a;
extern int DAT_0603ac9e;
extern int DAT_0603adda;
extern int DAT_0603ae60;
extern int DAT_0603ae62;
extern int DAT_0603af70;
extern int DAT_0603af72;
extern int DAT_0603b270;
extern int DAT_0603b4c6;
extern int DAT_0603b4c8;
extern int DAT_0603b4ca;
extern int DAT_0603b4cc;
extern int DAT_0603b4ce;
extern int DAT_0603b7a4;
extern int DAT_0603b7a6;
extern int DAT_0603b7a8;
extern int DAT_0603b7aa;
extern int DAT_0603b838;
extern int DAT_0603b83a;
extern int DAT_0603b88c;
extern int DAT_0603b88e;
extern int DAT_0603b91c;
extern int DAT_0603b91e;
extern int DAT_0603bae6;
extern int DAT_0603bbb0;
extern int DAT_0603bbb2;
extern int DAT_0603bbb4;
extern int DAT_0603bbb6;
extern int DAT_0603bc50;
extern int DAT_0603bc52;
extern int DAT_0603bc54;
extern int DAT_0603bc56;
extern int DAT_0603be0e;
extern int DAT_0603bf6e;
extern unsigned int FUN_0603a7b0();
extern void FUN_0603ab46();
extern void FUN_0603adac();
extern int FUN_0603aee8();
extern void FUN_0603af94();
extern int FUN_0603afd0();
extern int FUN_0603b058();
extern int FUN_0603b21c();
extern int FUN_0603b28e();
extern void FUN_0603b3fa();
extern unsigned int FUN_0603b424();
extern void FUN_0603b734();
extern void FUN_0603b74c();
extern int FUN_0603b7c0();
extern int FUN_0603b81e();
extern int FUN_0603b878();
extern void FUN_0603b8b4();
extern void FUN_0603b8f4();
extern int FUN_0603b93c();
extern int FUN_0603b96a();
extern int FUN_0603b9a4();
extern void FUN_0603b9d6();
extern int FUN_0603ba2c();
extern int FUN_0603bac6();
extern int FUN_0603bb86();
extern int FUN_0603bc86();
extern int FUN_0603bd1c();
extern int FUN_0603bdac();
extern void FUN_0603be7c();
extern void FUN_0603bf22();
extern int FUN_0603bf5a();
extern int PTR_DAT_0603a1a4;
extern int PTR_DAT_0603aa80;
extern int PTR_DAT_0603addc;
extern int PTR_DAT_0603ae64;
extern int PTR_DAT_0603af74;
extern int PTR_DAT_0603b83c;
extern int PTR_DAT_0603bcd0;
extern int PTR_DAT_0603bd64;
extern int PTR_DAT_0603be10;

char FUN_0603a01c(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  puVar3 = (char *)0x060A4CD4;

  puVar2 = (char *)0x060A4CEC;

  func_0x0603aa82();

  puVar5 = (char *)0x060A4CD0;

  puVar4 = (char *)0x060A4CC8;

  *(int *)0x060A4CD0 = *(int *)0x060A4CC8;

  *(int *)puVar3 = *(int *)puVar4;

  *(int *)0x060A4CCC = 1;

  puVar4 = (char *)0x060A4CFD;

  cVar1 = *(int *)0x060A4CFC;

  if (cVar1 == ' ') {

    if ((unsigned char)*(int *)0x060A4D02 < 5) {

      *(char **)puVar5 = (char *)0x060A4CFD;

      *(char **)puVar3 = puVar4 + 2;

    }

    else {

      *(int *)puVar3 = *(int *)puVar3 + 2;

    }

  }

  while (*(unsigned int *)puVar2 < param_1) {

    **(char **)puVar3 = **(char **)puVar2;

    *(int *)puVar3 = *(int *)puVar3 + 1;

    *(int *)puVar2 = *(int *)puVar2 + 2;

  }

  return cVar1;

}

char * FUN_0603a0b0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  short sVar8;

  unsigned short *puVar9;

  int iVar10;

  unsigned char *pbVar11;

  unsigned int uVar12;

  puVar5 = (char *)0x060A4CD0;

  puVar4 = (char *)0x060A4CCC;

  puVar3 = (char *)0x060A4CC0;

  puVar2 = (char *)0x060A4CB4;

  puVar1 = (char *)0x060A4CAE;

  if (*(int *)0x060A4CFC == ' ') {

    **(char **)0x060A4CD0 = (char)DAT_0603a1a2;

    *(char *)((unsigned int)(unsigned char)*puVar4 + *(int *)puVar5) = (char)DAT_0603a1a2;

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 0x80) == PTR_DAT_0603a1a4) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 2) + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 0x40) == 0x40) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)*puVar4 * 3 + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 1) == 1) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfb;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 4) == 4) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfe;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 2) == 2) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfd;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 8) == 8) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xf7;

    }

    *puVar1 = *(int *)0x060A4D02;

  }

  puVar6 = (char *)0x060A4CBC;

  puVar7 = (char *)(unsigned int)(unsigned char)*(int *)0x060A4CAF;

  if (puVar7 == (char *)0x0) {

    *(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[1] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0x00000010) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 4) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*puVar4 * 3);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 6) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 2));

    puVar9 = (unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3);

    puVar9[4] = ~*(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6) | *puVar9;

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    *(short *)(iVar10 + 10) =

         *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 2) - *(short *)(iVar10 + 2);

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    *(short *)(iVar10 + 0xc) =

         *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 4) - *(short *)(iVar10 + 4);

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    sVar8 = *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 6) - *(short *)(iVar10 + 6);

    puVar7 = (char *)(int)sVar8;

    *(short *)(iVar10 + 0xe) = sVar8;

  }

  else if (puVar7 == (char *)0x00000020) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         ~(unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    if ((*(unsigned short *)(iVar10 + 2) & 0x10) == 0x10) {

      sVar8 = 1;

    }

    else {

      sVar8 = -1;

    }

    *(unsigned short *)(iVar10 + 4) = (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*puVar4 * 3) * sVar8;

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    if ((*(unsigned short *)(iVar10 + 2) & 0x20) == 0x20) {

      sVar8 = 1;

    }

    else {

      sVar8 = -1;

    }

    *(unsigned short *)(iVar10 + 6) = (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 2)) * sVar8;

    puVar9 = (unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[4] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0x00000030) {

    *(unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned char *)(*(int *)puVar2 * 10 + *(int *)puVar3 + 2) =

         ~*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    *(char *)(*(int *)puVar2 * 10 + *(int *)puVar3 + 3) =

         *(char *)((unsigned int)(unsigned char)*puVar4 * 3 + *(int *)puVar5);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[2] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0xe1) {

    *(char *)(*(int *)puVar2 * 3 + *(int *)puVar3) = **(char **)puVar5;

    pbVar11 = (unsigned char *)(*(int *)puVar2 * 3 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned char *)(*(int *)puVar2 * 3 + *(int *)puVar6) & 0xff | (unsigned int)*pbVar11);

    pbVar11[1] = (unsigned char)puVar7;

  }

  else if (puVar7 == (char *)0xe2) {

    *(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[1] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)(int)DAT_0603a6fe) {

    for (uVar12 = 0; uVar12 < (unsigned char)*puVar1; uVar12 = uVar12 + 1) {

      puVar7 = (char *)((unsigned char)*puVar4 * uVar12 + *(int *)puVar5);

      *(char *)(((unsigned char)*puVar1 + 1) * *(int *)puVar2 + *(int *)puVar3 + uVar12 + 1) = *puVar7;

    }

  }

  return puVar7;

}

/* cd_state_init -- Initialize CD subsystem state variables.
 * Sets active flag at 0x060A4D0C=1, zeroes 10 state fields
 * (status bytes, counters, sector index, buffer pointers). */
void FUN_0603a6c0(void)
{
    *(int *)0x060A4D0C = 1;    /* CD subsystem active */
    *(int *)0x060A4D0D = 0;
    *(int *)0x060A4D0E = 0;
    *(int *)0x060A4D0F = 0;
    *(int *)0x060A4D10 = 0;
    *(int *)0x060A4D11 = 0;
    *(int *)0x060A4CD8 = 0;    /* sector buffer state */
    *(int *)0x060A4CB4 = 0;    /* sector counter */
    *(int *)0x060A4CF0 = 0;
    *(int *)0x060A4CF8 = 0;
    *(int *)0x060A4CA9 = 0;
}

/* smpc_command_issue -- Issue SMPC command if SF (Status Flag) is clear.
 * Returns 1 if busy (SF already set). Otherwise sets SF=1,
 * writes IREG0-IREG2 from state at 0x06063602, then issues
 * INTBACK command (0x10) to COMREG at 0x2010001F. */
int FUN_0603a72c(void)
{
    if ((SMPC_SF & 1) == 1)
        return 1;   /* SMPC busy */

    SMPC_SF = 1;
    SMPC_IREG0 = *(int *)0x06063602;
    *(char *)0x20100003 = *(char *)0x06063603;   /* IREG1 */
    *(char *)0x20100005 = *(char *)0x06063604;   /* IREG2 */
    *(char *)0x2010001F = 0x10;                  /* COMREG = INTBACK */
    return 0;
}

/* cd_sector_process_loop -- Process pending CD sectors in a loop.
 * Iterates from current sector counter (0x060A4CB4) up to the limit
 * (0x060A4CAC). Each iteration: flush with mask 0xFF (FUN_0603ab46),
 * then process next sector (FUN_0603a7b0). */
void FUN_0603a766(void)
{
    int *counter = (int *)0x060A4CB4;
    unsigned short *limit = (unsigned short *)0x060A4CAC;

    while (*counter < (int)(unsigned int)*limit) {
        FUN_0603ab46(255);
        FUN_0603a7b0();
        *counter = *counter + 1;
    }
}

unsigned int FUN_0603a7b0()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned char bVar9;

  puVar5 = (char *)0x0000FFFF;

  puVar4 = (char *)0x060A4CC0;

  puVar3 = (char *)0x060A4CB4;

  puVar2 = (char *)0x060A4CAE;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x060A4CAF;

  uVar1 = SUB42(0x0000FFFF,0);

  if (uVar6 == 0) {

    *(short *)(*(int *)0x060A4CB4 * 6 + *(int *)0x060A4CC0) = uVar1;

    iVar7 = *(int *)puVar3;

  }

  else {

    if (uVar6 == 0x10) {

      *(short *)(*(int *)0x060A4CB4 * 0x12 + *(int *)0x060A4CC0) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 2) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 4) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 6) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 8) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 10) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xc) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xe) = 0;

      return 0;

    }

    if (uVar6 == 0x20) {

      *(short *)(*(int *)0x060A4CB4 * 0x12 + *(int *)0x060A4CC0 + 2) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 4) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 6) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 10) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xc) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xe) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 8) = uVar1;

      return (unsigned int)puVar5 & 0xffff;

    }

    bVar9 = (unsigned char)DAT_0603a8bc;

    if (uVar6 == 0x30) {

      *(short *)(*(int *)0x060A4CB4 * 10 + *(int *)0x060A4CC0) = uVar1;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 2) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 3) = bVar9;

      *(short *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 4) = uVar1;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 6) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 7) = bVar9;

      return (unsigned int)bVar9;

    }

    if (uVar6 == 0xe1) {

      *(unsigned char *)(*(int *)0x060A4CB4 * 3 + *(int *)0x060A4CC0) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 3 + *(int *)puVar4 + 1) = bVar9;

      return (unsigned int)bVar9;

    }

    if (uVar6 != 0xe2) {

      if (uVar6 != (int)PTR_DAT_0603aa80) {

        return uVar6;

      }

      for (uVar8 = 0; uVar8 < (unsigned char)*puVar2; uVar8 = uVar8 + 1) {

        uVar6 = (unsigned int)bVar9;

        *(unsigned char *)(((unsigned char)*puVar2 + 1) * *(int *)puVar3 + *(int *)puVar4 + uVar8 + 1) = bVar9;

      }

      return uVar6;

    }

    *(short *)(*(int *)0x060A4CB4 * 6 + *(int *)0x060A4CC0) = uVar1;

    iVar7 = *(int *)puVar3;

  }

  *(short *)(iVar7 * 6 + *(int *)puVar4 + 2) = uVar1;

  return (unsigned int)puVar5 & 0xffff;

}

/* cd_sector_write_by_mode -- Write byte to CD sector buffer by transfer mode.
 * Mode byte at 0x060A4CAF selects record stride/offset:
 *   0x00: stride 6, offset +4
 *   0x10: stride 0x12, offset +0x10
 *   0x20: stride 0x12, offset +0x10
 *   0x30: stride 10, offset +8
 *   DAT_0603ac16: stride 3, offset +2
 *   DAT_0603ac18: stride 6, offset +4
 *   DAT_0603ac1a: stride (byte+1), offset +0
 * Index from 0x060A4CB4, base from 0x060A4CC0. */
void FUN_0603ab46(param_1)
    char param_1;
{
  unsigned short mode;
  int idx;

  mode = (unsigned short)(unsigned char)*(int *)0x060A4CAF;
  idx = *(int *)0x060A4CB4;

  if (mode == 0) {
    *(char *)(idx * 6 + *(int *)0x060A4CC0 + 4) = param_1;
  } else if (mode == 0x10 || mode == 0x20) {
    *(char *)(idx * 0x12 + *(int *)0x060A4CC0 + 0x10) = param_1;
  } else if (mode == 0x30) {
    *(char *)(idx * 10 + *(int *)0x060A4CC0 + 8) = param_1;
  } else if (mode == DAT_0603ac16) {
    *(char *)(idx * 3 + *(int *)0x060A4CC0 + 2) = param_1;
  } else if (mode == DAT_0603ac18) {
    *(char *)(idx * 6 + *(int *)0x060A4CC0 + 4) = param_1;
  } else if (mode == DAT_0603ac1a) {
    *(char *)(((unsigned char)*(int *)0x060A4CAE + 1) * idx + *(int *)0x060A4CC0) = param_1;
  }
}

/* cd_subsystem_init -- Initialize CD subsystem with work area and config.
 * param_1: sector count (must be 1..24)
 * param_2: work area base address (must be 4-byte aligned)
 * param_3: config struct (NULL for default, or [mode, bufcount, callback])
 * Returns 0 on success, negative error codes:
 *   -5: sector count out of range
 *   -21: work area not aligned
 *   -4: invalid config struct
 *   -2: hardware not ready
 *   -7: filesystem init failed
 *   -1: buffer config failed */
int FUN_0603ac1c(param_1, param_2, param_3)
    int param_1;
    unsigned int param_2;
    int *param_3;
{
  int iVar1;

  if ((param_1 < 1) || (0x18 < param_1)) {
    iVar1 = -5; /* sector count out of range */
  } else if ((param_2 & 3) == 0) {
    if ((param_3 == (int *)0x0) ||
       ((((*param_3 == 0 || (*param_3 == 1)) && (1 < param_3[1])) && (param_3[2] != 0)))) {
      CD_STATE_A = param_2; /* set work area base */
      FUN_0603b74c(); /* cd_state_table_init */
      iVar1 = (*(int(*)())0x0604000C)(param_3 == (int *)0x0); /* hardware init */
      if (iVar1 != 0) {
        iVar1 = FUN_0603b93c();
        return iVar1;
      }
      if ((*(unsigned int *)((int)DAT_0603ac9e + CD_STATE_A) & 1) == 0) {
        iVar1 = FUN_0603b93c(0xfffffffe); /* hardware not ready */
        return iVar1;
      }
      if (param_3 == (int *)0x0) {
        iVar1 = (*(int(*)())0x0603F22C)(); /* cd_filesystem_init (default) */
        if (iVar1 < 0) {
          iVar1 = FUN_0603b93c(0xfffffff9);
          return iVar1;
        }
      } else {
        iVar1 = (*(int(*)())0x0603BC12)(param_3); /* cd_buffer_config */
        if (iVar1 < 1) {
          iVar1 = FUN_0603b93c(0xffffffff);
          return iVar1;
        }
      }
      FUN_0603adac(param_3); /* cd_transfer_init */
      FUN_0603b93c(0); /* success */
    } else {
      iVar1 = -4; /* invalid config */
    }
  } else {
    iVar1 = -0x15; /* not aligned */
  }
  return iVar1;
}

/* cd_transfer_init -- Initialize or reset a CD data transfer.
 * param_1==0: if a transfer is active (+0xa0), report error -7.
 *   Otherwise clear transfer state at CD_STATE_A+0x98 (bytes 4,8,C).
 * param_1!=0: sync CD (0x06035168), allocate transfer buffer (FUN_0603b7c0),
 *   store buffer pointer at +0xA4.
 * Reports success (0) via FUN_0603b93c. */
void FUN_0603adac(int param_1)
{
  int uVar1;
  int state_base = CD_STATE_A + 0x98;

  if (param_1 == 0) {
    if (*(int *)(CD_STATE_A + 0xa0) != 0) {
      FUN_0603b93c(0xfffffff9);          /* error: transfer active */
      return;
    }
    *(int *)(state_base + 8) = 0;
    *(int *)(state_base + 0xc) = 0;
    *(int *)(state_base + 4) = 0;
  } else {
    (*(int(*)())0x06035168)();           /* CD sync */
    uVar1 = FUN_0603b7c0();             /* allocate buffer */
    *(int *)(state_base + 0xc) = uVar1;
  }
  FUN_0603b93c(0);
}

/* cd_transfer_submit -- Submit a CD read transfer request.
 * Requires active transfer (+0xa0 != 0) and state==1 (+0x98).
 * Calls file read (0x0603F148) with active handle, param_1 (sector count),
 * and buffer from PTR_DAT_0603ae64 offset.
 * Reports -7 on read failure, -8 if no active transfer. */
int FUN_0603ae08(int param_1)
{
  int iVar1;

  if ((*(int *)(CD_STATE_A + 0xa0) != 0) &&
     (*(int *)(0x98 + CD_STATE_A) == 1)) {
    iVar1 = (*(int(*)())0x0603F148)(*(int *)(CD_STATE_A + 0xa0), param_1,
                       *(int *)(CD_STATE_A + (int)PTR_DAT_0603ae64));
    if (iVar1 < 0) {
      iVar1 = FUN_0603b93c(0xfffffff7);
      return iVar1;
    }
    FUN_0603b93c(0);
    return iVar1;
  }
  iVar1 = FUN_0603b93c(0xfffffff8);     /* no active transfer */
  return iVar1;
}

/* cd_file_open -- Open a CD file by index (param_1).
 * Validates index against max file count at CD_STATE_A + DAT_0603af72.
 * Allocates a handle via FUN_0603b81e, resolves file sector based on
 * filesystem state (mode at +0x98: 0=by-index, else=by-name),
 * then registers via FUN_0603ba2c.
 * Returns handle on success, 0 on failure (with error via FUN_0603b93c). */
int FUN_0603aee8(param_1)
    int param_1;
{
  int *cd_ctx = (int *)*(int *)0x060A4D14; /* CD context pointer */
  int handle;
  int sector;

  if ((*(int *)(CD_STATE_A + 0xa0) == 0) ||
     ((-1 < param_1 && (param_1 < *(int *)(CD_STATE_A + (int)DAT_0603af72))))) {
    handle = FUN_0603b81e(); /* allocate handle */
    if (handle == 0) {
      FUN_0603b93c(0xffffffed); /* error: no free handles (-19) */
      handle = 0;
    } else {
      if (*(int *)((int)cd_ctx + 0xa0) == 0) {
        sector = 0; /* no active filesystem */
      } else if (*(int *)((int)cd_ctx + 0x98) == 0) {
        sector = (*(int(*)())0x0603F1E0)(param_1, *(int *)((int)cd_ctx + 0xa0)); /* lookup by index */
      } else {
        sector = (*(int(*)())0x0603F1F0)(param_1, *(int *)((int)cd_ctx + 0xa0)); /* lookup by name */
      }
      handle = FUN_0603ba2c(handle, sector, param_1); /* register file handle */
      if (handle == 0) {
        FUN_0603b93c(0xfffffff6); /* error: registration failed (-10) */
      } else {
        FUN_0603b93c(0); /* success */
      }
    }
  } else {
    FUN_0603b93c(0xfffffff6); /* error: index out of range */
    handle = 0;
  }
  return handle;
}

/* cd_request_abort -- Abort a CD request and clean up resources.
 * Gets abort context via FUN_0603b878; if NULL, report error (-11).
 * Otherwise: complete active transfer, cancel pending, release request. */
void FUN_0603af94(int param_1)
{
    int ctx = FUN_0603b878();

    if (ctx == 0) {
        FUN_0603b93c(-11);  /* error: no context */
        return;
    }

    FUN_0603b8b4(param_1);       /* cd_transfer_complete */
    FUN_0603b8f4(param_1);       /* cd_cancel_pending */
    (*(int(*)())0x0603BF22)(ctx, param_1);  /* cd_request_release */
    FUN_0603b93c(0);             /* success */
}

int FUN_0603afd0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int uVar2;

  int iVar3;

  iVar3 = CD_STATE_A + 4 + (unsigned int)*(unsigned char *)(param_1 + 4) << 4;

  if (param_3 == 1) {

    iVar1 = (*(int(*)())(*(int *)(iVar3 + 0xc)))(*param_1);

    param_2 = param_2 + iVar1;

  }

  else if (param_3 == 2) {

    param_2 = param_2 + *(int *)(*param_1 + 0x10);

  }

  else if (param_3 != 0) {

    uVar2 = FUN_0603b93c(0xfffffff3);

    return uVar2;

  }

  if (param_2 < 0) {

    uVar2 = FUN_0603b93c(0xfffffff1);

    return uVar2;

  }

  uVar2 = (*(int(*)())(*(int *)(iVar3 + 8)))(*param_1,param_2);

  FUN_0603b93c(0);

  return uVar2;

}

/* cd_command_dispatch -- Dispatch CD command via command type vtable.
 * Reads command type from param[4] byte, looks up handler in CD_STATE_A table,
 * calls it with param[0], then invokes callback dispatch (FUN_0603b93c). */
int FUN_0603b058(int *param_1)
{
    int result = (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + CD_STATE_A + 0x10)))(*param_1);
    FUN_0603b93c(0);
    return result;
}

/* cd_read_sync -- Synchronous CD sector read with auto-size.
 * Allocates request via FUN_0603aee8, configures offset (param_2),
 * calculates remaining sectors. If param_4 == -1, auto-calculates
 * transfer size. Calls cd_read_blocking (FUN_0603b21c), then releases. */
int FUN_0603b1b6(int param_1, int param_2, int param_3, int param_4)
{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_0603aee8();
  if (piVar1 == (int *)0x0) {
    iVar2 = FUN_0603b93c(0xfffffff7);   /* alloc failed */
    return iVar2;
  }

  FUN_0603afd0(piVar1, param_2, 0);
  param_2 = *(int *)(*piVar1 + 0x10) - param_2;
  if (param_4 == -1) {
    param_4 = param_2 * DAT_0603b270;   /* auto-calculate size */
  }

  iVar2 = FUN_0603b21c(piVar1, param_2, param_3, param_4);
  FUN_0603af94(piVar1);
  if (-1 < iVar2) {
    FUN_0603b93c(0);
  }
  return iVar2;
}

/* cd_read_blocking -- Blocking CD read: submit and poll until complete.
 * Saves/restores timeout value at handle+0x28 (sets to 0x7FFFFFFF).
 * Submits read via FUN_0603b28e, then polls FUN_0603b424 in a loop
 * with CD sync (0x060423CC) between iterations.
 * On completion (0): extracts result via FUN_0603b3fa. */
int FUN_0603b21c(param_1)
    int *param_1;
{
  int iVar1;
  int uVar2;
  int local_18;
  char auStack_14[4];
  int uStack_10;

  uStack_10 = 0x7FFFFFFF;
  uVar2 = *(int *)(*param_1 + 0x28);
  *(int *)(*param_1 + 0x28) = 0x7FFFFFFF;  /* set max timeout */

  iVar1 = FUN_0603b28e(param_1);
  if (iVar1 == 0) {
    while (iVar1 = FUN_0603b424(param_1), -1 < iVar1) {
      if (iVar1 == 0) {
        FUN_0603b3fa(param_1, auStack_14, &local_18);
        FUN_0603b93c(0);
        *(int *)(*param_1 + 0x28) = uVar2;
        return local_18;
      }
      (*(int(*)())0x060423CC)();         /* CD sync wait */
    }
    *(int *)(*param_1 + 0x28) = uVar2;
    uVar2 = FUN_0603b93c();
  } else {
    *(int *)(*param_1 + 0x28) = uVar2;
    uVar2 = FUN_0603b93c();
  }
  return uVar2;
}

/* cd_read_request_start -- Start a CD read request (async initiation).
 * If not already pending (+0x12 == 0): registers in queue (FUN_0603b9a4),
 * sets mode=1 (read), marks pending, calculates sectors to read
 * (min of remaining sectors and param_2), configures buffer and filter.
 * Returns 0 on success, reports -16 if already pending. */
int FUN_0603b28e(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    int param_4;
{
  int iVar1;
  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {
    FUN_0603b9a4(param_1);               /* register in queue */
    *(char *)((int)param_1 + 0x11) = 1;  /* mode = read */
    *(char *)((int)param_1 + 0x12) = 1;  /* mark pending */

    iVar2 = *(int *)(*param_1 + 0x10);
    iVar1 = FUN_0603b058(param_1);
    iVar2 = iVar2 - iVar1;
    if (param_2 < iVar2) {
      iVar2 = param_2;
    }
    FUN_0603be7c(*param_1, iVar2);               /* set sector count */
    (*(int(*)())0x0603F9DA)(param_1[2], iVar2);  /* configure buffer */
    (*(int(*)())0x0603EF54)(param_1[1], param_3, param_4, 1);  /* set filter */
    (*(int(*)())0x0603FA00)(param_1[2]);          /* start transfer */
    FUN_0603b93c(0);
    return 0;
  }
  FUN_0603b93c(0xfffffff0);              /* already pending */
  return 0;
}

/* cd_write_request_start -- Start a CD write request (async initiation).
 * Same structure as cd_read_request_start but sets mode=2 (write),
 * configures buffer for output (0x0603F9DA with size=0),
 * and opens filter for writing (0x0603FA1A with -1 = unlimited). */
void FUN_0603b31c(int *param_1, int param_2)
{
  int iVar1;
  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {
    FUN_0603b9a4(param_1);               /* register in queue */
    *(char *)((int)param_1 + 0x11) = 2;  /* mode = write */
    *(char *)((int)param_1 + 0x12) = 1;  /* mark pending */

    iVar2 = *(int *)(*param_1 + 0x10);
    iVar1 = FUN_0603b058(param_1);
    iVar2 = iVar2 - iVar1;
    if (param_2 < iVar2) {
      iVar2 = param_2;
    }
    FUN_0603be7c(*param_1, iVar2);               /* set sector count */
    (*(int(*)())0x0603F9DA)(param_1[2], 0);      /* configure write buffer */
    (*(int(*)())0x0603EF54)(param_1[1], 0, 0, 1);  /* set filter */
    (*(int(*)())0x0603FA1A)(param_1[2], 0xffffffff);  /* open for write */
    FUN_0603b93c(0);
    return;
  }
  FUN_0603b93c(0xfffffff0);              /* already pending */
}

/* cd_block_read_start -- Start CD block data read.
 * Extracts sector count from offset +0x11, sets max read length (0x7FFFFFFF),
 * calls CD read function (0x0603EF64), then resets CD state via FUN_0603b93c. */
void FUN_0603b3fa(int param_1, unsigned int *param_2)
{
    *param_2 = (unsigned int)*(unsigned char *)(param_1 + 0x11);
    (*(int(*)())0x0603EF64)(*(int *)(param_1 + 4), 0x7FFFFFFF);
    FUN_0603b93c(0);
}

unsigned int FUN_0603b424(param_1)
    int param_1;
{

  int iVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned char bVar4;

  if (*(char *)(param_1 + 0x12) != '\0') {

    iVar1 = FUN_0603bd1c(param_1);

    if (iVar1 == 0) {

      if (*(char *)(param_1 + 0x11) == '\x02') {

        *(char *)(param_1 + 0x12) = 0;

        FUN_0603b9d6(param_1);

        FUN_0603b93c(0);

        bVar4 = *(unsigned char *)(param_1 + 0x12);

        goto LAB_0603b530;

      }

    }

    else if (iVar1 == 1) {

      iVar3 = FUN_0603bf5a(param_1);

      if (iVar3 == 1) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ce;

        uVar2 = FUN_0603b93c(0xffffffe8);

        return uVar2;

      }

    }

    else {

      if (iVar1 == 3) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c8;

        uVar2 = FUN_0603b93c(0xffffffe9);

        return uVar2;

      }

      if (iVar1 == 4) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ca;

        uVar2 = FUN_0603b93c(0xfffffffe);

        return uVar2;

      }

      if (iVar1 == 5) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4cc;

        uVar2 = FUN_0603b93c(0xffffffec);

        return uVar2;

      }

      if (iVar1 == 6) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c6;

        uVar2 = FUN_0603b93c(0xffffffff);

        return uVar2;

      }

    }

    iVar3 = FUN_0603bdac(param_1);

    if ((iVar1 == 2) && (iVar3 == 5)) {

      iVar1 = (*(int(*)())0x0603F9F2)(*(int *)(param_1 + 8));

      iVar3 = (*(int(*)())0x0603F9F6)(*(int *)(param_1 + 8));

      FUN_0603afd0(param_1,iVar1 - iVar3,1);

      *(char *)(param_1 + 0x12) = 0;

      FUN_0603b8b4(param_1);

      FUN_0603b8f4(param_1);

      FUN_0603b9d6(param_1);

    }

  }

  FUN_0603b93c(0);

  bVar4 = *(unsigned char *)(param_1 + 0x12);

LAB_0603b530:

  return (unsigned int)bVar4;

}

/* cd_vtable_init -- Initialize CD subsystem function pointer table.
 * Sets 4 handler function pointers in CD_STATE_A structure:
 * +0x04: read, +0x08: write, +0x0C: status, +0x10: error. */
void FUN_0603b734(void)
{
    int base = CD_STATE_A;
    *(char **)(base + 0x04) = (char *)0x060402BC;
    *(char **)(base + 0x08) = (char *)0x0604053A;
    *(char **)(base + 0x0c) = (char *)0x060406A6;
    *(char **)(base + 0x10) = (char *)0x0604069A;
}

/* cd_state_table_init -- Initialize CD state tables and slot array.
 * Sets max handle count, installs vtable via FUN_0603b734,
 * clears transfer state fields at DAT_0603b7a4 offsets,
 * then zeroes all handle slots (stride DAT_0603b7aa). */
void FUN_0603b74c(param_1)
    int param_1;
{
  int *cd_ctx = *(int **)0x060A4D14;
  int base_off;
  int slot_ptr;
  int i;

  *cd_ctx = param_1; /* set max handle count */
  FUN_0603b734(); /* install vtable handlers */

  base_off = (int)DAT_0603b7a4;
  *(int *)((int)cd_ctx + base_off) = 0;
  *(int *)((int)cd_ctx + base_off + 0x14) = 0;
  *(int *)((int)cd_ctx + base_off + 0x1c) = 0;
  *(int *)((int)cd_ctx + base_off + 0x18) = 0;
  *(int *)((int)cd_ctx + base_off + 0x24) = 0;
  *(int *)((int)cd_ctx + base_off + 0x30) = 0;

  /* clear all handle slots */
  slot_ptr = (int)cd_ctx + (int)DAT_0603b7a6;
  for (i = 0; i < *cd_ctx; i = i + 1) {
    *(int *)(slot_ptr + DAT_0603b7a8) = 0;
    slot_ptr = slot_ptr + DAT_0603b7aa;
  }
}

/* cd_buffer_scan -- Scan CD buffers for first free slot.
 * Mode param_1[0] selects scan function (0: 0x0603F202, else: 0x0603F216).
 * Iterates up to param_1[1] buffers, each with param_1[2] as size arg.
 * Returns 1-based index of first free slot (DAT_0603b838 mask match),
 * or 0 if no free slot found. */
int FUN_0603b7c0(param_1)
    int *param_1;
{
  unsigned int result;
  unsigned int mask = (unsigned int)DAT_0603b838;
  int i;
  int (*scan_a)(int, int) = (int (*)(int, int))0x0603F202;
  int (*scan_b)(int, int) = (int (*)(int, int))0x0603F216;

  for (i = 0; i < param_1[1]; i = i + 1) {
    if (*param_1 == 0) {
      result = scan_a(i, param_1[2]);
    } else {
      result = scan_b(i, param_1[2]);
    }
    if ((result & mask) != 0) break;
  }

  if (param_1[1] < i) {
    i = 0;
  } else {
    i = i + 1; /* convert to 1-based index */
  }
  return i;
}

/* cd_handle_allocate -- Allocate a free CD file handle from the slot pool.
 * Scans handle slots at CD_STATE_A + DAT_0603b83a (stride DAT_0603b88c).
 * Returns slot pointer and marks it active (+DAT_0603b88e = 1),
 * or 0 if all slots are occupied. */
int FUN_0603b81e()
{
  int slot;
  int i;

  i = 0;
  for (slot = CD_STATE_A + (int)DAT_0603b83a;
      (i < **(int **)0x060A4D14 && (*(int *)(slot + PTR_DAT_0603b83c) != 0));
      slot = slot + DAT_0603b88c) {
    i = i + 1;
  }

  if (i == **(int **)0x060A4D14) {
    slot = 0; /* no free slots */
  } else {
    *(int *)(slot + DAT_0603b88e) = 1; /* mark slot active */
  }
  return slot;
}

/* cd_find_request_slot -- Search CD request slots for a matching handle.
 * Iterates slots at 0x060A4D14 base + 0x0C3C (stride 0xF0) up to
 * the active slot count. Returns slot pointer if found, 0 if not found. */
int FUN_0603b878(int param_1)
{
  int iVar1;
  int iVar2;
  int *pp = (int *)0x060A4D14;

  iVar2 = 0;
  iVar1 = *(int *)pp + 0x0C3C;
  goto check;
loop:
  if (iVar1 == param_1) goto done;
  iVar1 = iVar1 + 0x00F0;
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < **(int **)pp) goto loop;
done:
  if (iVar2 == **(int **)pp) {
    iVar1 = 0;                           /* not found */
  }
  return iVar1;
}

/* cd_transfer_complete -- Handle CD transfer completion for a request.
 * If param_1 matches the active transfer at CD_STATE_A+0xa8,
 * clears it and calls the completion callback via vtable dispatch. */
void FUN_0603b8b4(int *param_1)
{
    if (*(int **)(CD_STATE_A + 0xa8) == param_1) {
        *(int *)(CD_STATE_A + 0xa8) = 0;
        (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + *(int *)0x060A4D14 + 8)))(*param_1, 1);
    }
}

/* cd_cancel_pending -- Cancel a pending CD request if it matches.
 * Checks CD_STATE_A at offset DAT_0603b91e for param_1.
 * On match: clears the slot and calls abort handler (0x0603FA1A)
 * with the request's data pointer and -1 (cancel signal). */
void FUN_0603b8f4(int param_1)
{
    if (*(int *)(CD_STATE_A + (int)DAT_0603b91e) == param_1) {
        *(int *)(CD_STATE_A + (int)DAT_0603b91e) = 0;
        (*(int(*)())0x0603FA1A)(*(int *)(param_1 + 8), 0xffffffff);
    }
}

/* cd_request_find -- Search CD pending request queue for a handle.
 * Scans queue at CD_STATE_A+0x34 (count at +0x94) for param_1.
 * Returns queue index if found, -1 if not found.
 * Note: param_1 passed implicitly via register (K&R convention). */
int FUN_0603b96a(param_1)
    int param_1;
{
  int iVar1;
  int iVar2 = CD_STATE_A;

  for (iVar1 = 0;
      (iVar1 < *(int *)(iVar2 + 0x94) && (param_1 != *(int *)((iVar1 << 2) + iVar2 + 0x34)));
      iVar1 = iVar1 + 1) {
  }
  if (iVar1 == *(int *)(iVar2 + 0x94)) {
    iVar1 = -1;                          /* not found */
  }
  return iVar1;
}

/* cd_request_register -- Register a new CD request in the pending queue.
 * First checks if param_1 is already registered via FUN_0603b96a.
 * If not found (-1), appends to the queue at CD_STATE_A+0x34,
 * increments queue count at +0x94, returns 0x60 (success).
 * If already queued, returns the existing index. */
int FUN_0603b9a4(int param_1)
{
    int idx = FUN_0603b96a();

    if (idx == -1) {
        int base = CD_STATE_A;
        *(int *)((*(int *)(base + 0x94) << 2) + base + 0x34) = param_1;
        idx = 0x60;
        *(int *)(base + 0x94) = *(int *)(base + 0x94) + 1;
    }

    return idx;
}

/* cd_request_dequeue -- Remove a CD request from the pending queue.
 * Finds request in queue via FUN_0603b96a, then shifts all
 * subsequent entries down by one slot to fill the gap.
 * Decrements queue count at CD_STATE_A+0x94. */
void FUN_0603b9d6(param_1)
    int param_1;
{
  int idx;
  int count;
  int base;
  int src_off;
  int dst_off;

  if (param_1 != 0) {
    idx = FUN_0603b96a(); /* find in queue */
    if (idx != -1) {
      base = CD_STATE_A;
      count = *(int *)(base + 0x94) + -1;
      *(int *)(base + 0x94) = count; /* decrement count */
      dst_off = idx << 2;
      src_off = (idx + 1) << 2;
      for (; idx < count; idx = idx + 1) {
        *(int *)(base + 0x34 + dst_off) = *(int *)(src_off + base + 0x34);
        dst_off = dst_off + 4;
        src_off = src_off + 4;
      }
    }
  }
}

/* cd_file_handle_setup -- Set up a CD file handle with data pipeline.
 * param_1: handle pointer (from cd_handle_allocate)
 * param_2: file sector info
 * param_3: file index
 * Initializes connection (0x0603F93C), configures file data (FUN_0603bc86),
 * creates filter (0x0603EF34) and buffer pipeline (0x0603F8B8) with
 * callbacks for sectors remaining/valid/step/complete/error.
 * Returns handle on success, 0 on failure. */
int FUN_0603ba2c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  int conn;
  int file_data;
  int filter;
  int buffer;

  conn = (*(int(*)())0x0603F93C)(param_1 + 0x40); /* init connection */
  if (param_1 == 0) {
    param_1 = 0;
  } else {
    file_data = FUN_0603bc86(param_1, param_1, param_3, param_2);
    if (file_data == 0) {
      param_1 = 0; /* file data setup failed */
    } else {
      filter = (*(int(*)())0x0603EF34)(DAT_0603bae6 + param_1, 0, 0xffffffff);
      buffer = (*(int(*)())0x0603F8B8)(
          param_1 + 0x90, filter,
          0x0603EF64,  /* cd_calc_sectors_remaining */
          0x0603EFD4,  /* sector valid check */
          0x0603EFE6,  /* sector step */
          0x0603F036,  /* transfer complete */
          0x0603F070); /* error handler */
      (*(int(*)())0x0603F9B8)(conn, file_data, buffer); /* link pipeline */
      *(int *)(param_1 + 4) = filter;
      *(char *)(param_1 + 0x11) = 0; /* clear mode */
      *(char *)(param_1 + 0x12) = 0; /* clear pending flag */
      *(int *)(param_1 + 8) = conn;
    }
  }
  return param_1;
}

/* cd_boot_sector_read -- Read boot sector (0x800 bytes) from CD.
 * Queries disc info (0x06040680), gets session offset (0x06040F82),
 * adds DAT_0603bbb0 offset, allocates handle, reads 1 sector
 * (0x800 bytes) via cd_read_blocking. Returns 1 on success, 0 on failure.
 * Releases handle after read regardless of result. */
int FUN_0603bac6(param_1)
    int param_1;
{
  int iVar1;
  int handle;
  int read_result;
  int result;
  int local_24;
  int iStack_20;
  char uStack_1c;
  char uStack_1b;
  char uStack_1a;
  char uStack_19;

  result = 0;
  iVar1 = (*(int(*)())0x06040680)(); /* get disc info */
  if (iVar1 == 0) {
    result = 0;
  } else {
    local_24 = (*(int(*)())0x06040F82)(); /* get session offset */
    local_24 = local_24 + DAT_0603bbb0;
    uStack_1a = 0;
    uStack_19 = 0;
    uStack_1c = 0;
    uStack_1b = 0;
    iStack_20 = 0x800; /* sector size */
    handle = FUN_0603b81e(); /* allocate handle */
    iVar1 = FUN_0603ba2c(handle, &local_24, 0); /* setup file handle */
    if ((iVar1 != 0) && (read_result = FUN_0603b21c(iVar1, 1, param_1, 0x800), read_result == 0x800)) {
      result = 1; /* read full sector successfully */
    }
    FUN_0603bf22(handle, iVar1); /* release handle */
  }
  return result;
}

/* cd_volume_info_read -- Read volume descriptor from CD boot sector.
 * Checks hardware ready flag at CD_STATE_A + DAT_0603bbb4.
 * Reads boot sector via cd_boot_sector_read, extracts volume info:
 *   param_1[0]: root dir sector + DAT_0603bc54 adjustment
 *   param_1[1]: root dir size (from boot sector offset +0xe)
 * Clears remaining fields. Returns 1 on success, 0 on failure. */
int FUN_0603bb86(param_1)
    int *param_1;
{
  int result;
  int iVar3;
  int *cd_ctx = (int *)0x060A4D14;

  if ((*(unsigned int *)((int)DAT_0603bbb4 + CD_STATE_A) & 1) == 0) {
    result = 0;
  } else {
    iVar3 = FUN_0603bac6(CD_STATE_A + (int)DAT_0603bbb6); /* read boot sector */
    if (iVar3 == 0) {
      result = 0;
    } else {
      iVar3 = (int)DAT_0603bc50 + *(int *)cd_ctx + (int)DAT_0603bc52;
      (*(int(*)())0x060360FC)(param_1, iVar3 + 6, 4);     /* memmove: root dir sector */
      *param_1 = *param_1 + (int)DAT_0603bc54;            /* adjust sector offset */
      (*(int(*)())0x060360FC)(param_1 + 1, iVar3 + 0xe, 4); /* memmove: root dir size */
      if (param_1[1] == 0) {
        result = 0; /* empty volume */
      } else {
        *(char *)((int)param_1 + 10) = 0;
        *(char *)((int)param_1 + 0xb) = 0;
        *(char *)(param_1 + 2) = 0;
        *(char *)((int)param_1 + 9) = 0;
        result = 1;
      }
    }
  }
  return result;
}

int FUN_0603bc12(param_1)
    int param_1;
{

  int iVar1;

  int uVar2;

  int unaff_r13 = 0;

  char auStack_18 [4];

  int uStack_14;

  iVar1 = FUN_0603bb86(auStack_18);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    unaff_r13 = FUN_0603b81e();

    iVar1 = FUN_0603ba2c(unaff_r13,auStack_18,0);

  }

  if (((*(unsigned int *)((int)DAT_0603bc56 + CD_STATE_A) & 1) == 0) || (iVar1 != 0)) {

    uVar2 = (*(int(*)())0x0603F0FC)(iVar1,param_1,uStack_14);

    if (iVar1 != 0) {

      FUN_0603bf22(unaff_r13,iVar1);

    }

  }

  else {

    uVar2 = 0xfffffffd;

  }

  return uVar2;

}

/* cd_file_data_setup -- Initialize file data structures for a CD handle.
 * Locates file entry (0x060400D6) by sector (param_4) in handle's directory.
 * Creates data parser (0x0604077C) from file entry fields,
 * links parser to entry (0x060401E4), then creates buffer pipeline
 * (0x0603F8B8) with sector-level callbacks.
 * Returns buffer handle on success, 0 on failure. */
int FUN_0603bc86(param_1, param_2, param_3, param_4)
    int param_1;
    int *param_2;
    int param_3;
    int param_4;
{
  int file_entry;
  int parser;
  int result;

  file_entry = (*(int(*)())0x060400D6)(param_1 + 0x14, param_4); /* find file entry */
  if (file_entry == 0) {
    result = 0;
  } else {
    *param_2 = file_entry;
    parser = (*(int(*)())0x0604077C)(
        PTR_DAT_0603bcd0 + param_1, file_entry,
        *(int *)(file_entry + 0xc),      /* file size */
        *(char *)(file_entry + 0x1c),    /* file flags */
        0, param_2, param_4);
    if (parser == 0) {
      result = 0;
    } else {
      (*(int(*)())0x060401E4)(file_entry, parser); /* link parser to entry */
      result = (*(int(*)())0x0603F8B8)(
          param_1 + 0x78, parser,
          0x060408B0,  /* sectors remaining */
          0x06040954,  /* sector valid */
          0x06040AF8,  /* sector step */
          0x06040C50,  /* complete */
          0x06040C5C); /* error */
      *(char *)(param_2 + 4) = 0; /* clear status byte */
    }
  }
  return result;
}

/* cd_transfer_step -- Step a CD transfer request forward.
 * If no active transfer or this request IS the active transfer:
 *   dispatch handler via vtable at CD_STATE_A+4 (indexed by request type).
 *   Result 0: set this request as active. Result 2: clear active slot.
 * If another transfer is active: return 5 (busy). */
int FUN_0603bd1c(int *param_1)
{
  int iVar2;

  if ((*(int **)(CD_STATE_A + 0xa8) == (int *)0x0) ||
      (*(int **)(CD_STATE_A + 0xa8) == param_1)) {
    iVar2 = (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + CD_STATE_A + 4)))(*param_1);
    if (iVar2 == 0) {
      *(int **)(*(int *)0x060A4D14 + 0xa8) = param_1;
    } else if ((iVar2 == 2) && (*(int **)(*(int *)0x060A4D14 + 0xa8) == param_1)) {
      *(int *)(*(int *)0x060A4D14 + 0xa8) = 0;
    }
  } else {
    iVar2 = 5;                           /* busy */
  }
  return iVar2;
}

/* cd_request_poll -- Poll status of a CD request and handle completion.
 * Queries request status via 0x0603FACE. If status==5 (complete) or
 * file handle invalid (0x0603EFD4 returns 0): release handle, clear
 * active slot if it matches, return 5.
 * If status!=0 and not complete: set as active slot, mark pending. */
int FUN_0603bdac(int param_1)
{
  int iVar2;
  int iVar3;
  char auStack_14[8];

  iVar2 = (*(int(*)())0x0603FACE)(*(int *)(param_1 + 8), auStack_14);

  if ((iVar2 == 5) ||
     (iVar3 = (*(int(*)())0x0603EFD4)(*(int *)(param_1 + 4)), iVar3 == 0)) {
    (*(int(*)())0x0603FA1A)(*(int *)(param_1 + 8), 0xffffffff);
    if (*(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603be10) == param_1) {
      *(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603be10) = 0;
    }
    iVar2 = 5;                           /* complete */
  } else if (iVar2 != 0) {
    *(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603be10) = param_1;
    *(char *)(param_1 + 0x12) = 1;       /* mark pending */
  }
  return iVar2;
}

/* cd_seek_or_reset -- Seek to position or reset based on flags.
 * If flag bits 5-6 at param_1+0x1D are clear, calls cd_session_seek.
 * Otherwise, stores position at +0x20 and zeros offset at +0x24. */
void FUN_0603be7c(int param_1, int param_2)
{
    if ((*(unsigned char *)(param_1 + 0x1d) & 0x60) == 0) {
        (*(int(*)())0x060401F8)();
        return;
    }
    *(int *)(param_1 + 0x20) = param_2;
    *(int *)(param_1 + 0x24) = 0;
}

/* cd_request_release -- Release a CD request and clean up.
 * Unregisters param_2 via FUN_0603b9d6, clears slot in param_1.
 * If param_2 is non-NULL, frees the associated buffer via FUN_0604087C. */
void FUN_0603bf22(int param_1, int *param_2)
{
    FUN_0603b9d6(param_2);
    *(int *)(param_1 + DAT_0603bf6e) = 0;

    if (param_2 == (int *)0x0)
        return;

    (*(int(*)())0x0604087C)(*(int *)(*param_2 + 0x18));
}

/* cd_get_read_offset -- Get current read offset for a CD request.
 * If flag bits 5-6 at (*param_1)+0x1D are clear (normal mode),
 * returns the sector offset from the session structure.
 * Otherwise returns 0 (no offset in direct mode). */
int FUN_0603bf5a(int *param_1)
{
    if ((*(unsigned char *)(*param_1 + 0x1d) & 0x60) == 0)
        return *(int *)(*(int *)(*param_1 + 0x18) + 0x24);

    return 0;
}
