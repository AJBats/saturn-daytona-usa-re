extern int DAT_0603a1a2;

extern int DAT_0603a2ca;

extern int DAT_0603a6fa;

extern int DAT_0603a6fc;

extern int DAT_0603a6fe;

extern int PTR_DAT_0603a1a4;

extern int PTR_DAT_0603a1a4;

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

  puVar5 = 0x060A4CD0;

  puVar4 = 0x060A4CCC;

  puVar3 = 0x060A4CC0;

  puVar2 = 0x060A4CB4;

  puVar1 = 0x060A4CAE;

  if (*(int *)0x060A4CFC == ' ') {

    **(char **)0x060A4CD0 = (char)DAT_0603a1a2;

    *(char *)((unsigned int)(unsigned char)*puVar4 + *(int *)puVar5) = (char)DAT_0603a1a2;

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 0x80) == PTR_DAT_0603a1a4) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)*((int)(int)puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)*((int)(int)puVar4 << 2) + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)*((int)(int)puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 0x40) == 0x40) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)*((int)(int)puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)*puVar4 * 3 + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)*((int)(int)puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 1) == 1) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfb;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 4) == 4) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfe;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 2) == 2) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfd;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1)) & 8) == 8) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xf7;

    }

    *puVar1 = *(int *)0x060A4D02;

  }

  puVar6 = 0x060A4CBC;

  puVar7 = (char *)(unsigned int)(unsigned char)*(int *)0x060A4CAF;

  if (puVar7 == (char *)0x0) {

    *(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((*(char **) & 0xFF)puVar5)[(unsigned char)*puVar4]);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[1] = (unsigned short)puVar7;

  }

  else if (puVar7 == (void *)0x00000010) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((*(char **) & 0xFF)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1));

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 4) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*puVar4 * 3);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 6) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 2));

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

  else if (puVar7 == (void *)0x00000020) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((*(char **) & 0xFF)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         ~(unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1));

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

    *(unsigned short *)(iVar10 + 6) = (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 2)) * sVar8;

    puVar9 = (unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[4] = (unsigned short)puVar7;

  }

  else if (puVar7 == (void *)0x00000030) {

    *(unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((*(char **) & 0xFF)puVar5)[(unsigned char)*puVar4]);

    *(unsigned char *)(*(int *)puVar2 * 10 + *(int *)puVar3 + 2) =

         ~*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*((int)(int)puVar4 << 1));

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

         ((**(char **)puVar5) << 8 | ((*(char **) & 0xFF)puVar5)[(unsigned char)*puVar4]);

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
