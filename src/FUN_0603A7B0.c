extern int DAT_0603a8bc;

extern int DAT_0603aa7c;

extern int DAT_0603aa7e;

extern int PTR_DAT_0603aa80;

extern int PTR_DAT_0603aa80;

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

  puVar5 = 0x0000FFFF;

  puVar4 = 0x060A4CC0;

  puVar3 = 0x060A4CB4;

  puVar2 = 0x060A4CAE;

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
