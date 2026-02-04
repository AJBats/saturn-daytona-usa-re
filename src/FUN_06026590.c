extern int PTR_DAT_06026668;

extern int PTR_DAT_06026668;

extern int FUN_06026362();
extern int FUN_0602648e();

void FUN_06026590(param_1, param_2)
    char param_1;
    unsigned int param_2;
{

  short *puVar1;

  unsigned short *puVar2;

  unsigned int uVar3;

  int *puVar4;

  int *puVar5;

  int iVar6;

  int *puVar7;

  int *puVar8;

  int iVar9;

  int *piVar10;

  puVar4 = (int *)0x060610BC;

  iVar9 = 0xa8;

  if ((param_2 & 0xffff) == iVar9 + 1U) {

    puVar7 = (int *)(0x060610BC + iVar9);

    puVar8 = (int *)0x060610BC;

    do {

      puVar1 = (short *)*puVar8;

      *(short *)puVar8[1] = 0;

      *puVar1 = 0;

      puVar1 = (short *)puVar8[3];

      puVar5 = puVar8 + 4;

      puVar8 = puVar8 + 6;

      *(short *)*puVar5 = 0;

      *puVar1 = 0;

    } while (puVar8 < puVar7);

    if (param_1 == '\x04') {

      FUN_06026362();

    }

    iVar6 = 0;

    piVar10 = (int *)(0x06061170 + (param_1 << 2));

    for (uVar3 = 0; uVar3 < 0x50; uVar3 = uVar3 + 8) {

      if (*(int *)(*piVar10 + uVar3) != 0) {

        puVar8 = (int *)(*piVar10 + iVar6);

        puVar2 = (unsigned short *)*puVar8;

        *puVar2 = *puVar2 | *(unsigned short *)(puVar8 + 1);

      }

      iVar6 = iVar6 + 8;

    }

  }

  else {

    puVar7 = (int *)(0x060610BC + iVar9);

    puVar8 = (int *)0x060610BC;

    do {

      puVar1 = (short *)*puVar8;

      *(short *)puVar8[1] = 0;

      *puVar1 = 0;

      puVar1 = (short *)puVar8[3];

      puVar5 = puVar8 + 4;

      puVar8 = puVar8 + 6;

      *(short *)*puVar5 = 0;

      *puVar1 = 0;

    } while (puVar8 < puVar7);

    if (param_1 == '\x04') {

      FUN_0602648e();

    }

    iVar6 = 0;

    piVar10 = (int *)(0x06061184 + (param_1 << 2));

    for (uVar3 = 0; uVar3 < 0x40; uVar3 = uVar3 + 8) {

      if (*(int *)(*piVar10 + uVar3) != 0) {

        puVar8 = (int *)(*piVar10 + iVar6);

        puVar2 = (unsigned short *)*puVar8;

        *puVar2 = *puVar2 | *(unsigned short *)(puVar8 + 1);

      }

      iVar6 = iVar6 + 8;

    }

  }

  if (param_1 == '\x04') {

    puVar8 = (int *)((int)puVar4 + iVar9);

    do {

      puVar5 = puVar4 + 3;

      *(short *)*puVar4 = *(short *)puVar4[1];

      puVar7 = puVar4 + 4;

      puVar4 = puVar4 + 6;

      *(short *)*puVar5 = *(short *)*puVar7;

    } while (puVar4 < puVar8);

  }

  return;

}
