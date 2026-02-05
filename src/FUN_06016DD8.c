extern int DAT_06016eda;

extern int DAT_06016ffa;

void FUN_06016dd8(param_1)
    char param_1;
{
  int stack0xfffffff0;
  int stack0x0000002c;
  int stack0xfffffff4;
  int stack0xfffffff8;
  int stack0x00000008;
  int stack0xfffffffe;
  int stack0xfffffffc;
  int stack0xffffffe8;
  int stack0x0000000c;
  int stack0xffffffec;
  int stack0xffffffe4;
  int stack0x0000003c;
  int stack0x0000001c;
  int stack0x00000004;
  int stack0x0000000a;
  int stack0x00000006;
  int stack0x0000005c;
  int stack0x0000004c;
  int stack0x00000002;
  int stack0x00000000;

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  int iVar5;

  short uVar6;

  int *puVar7;

  short sVar9;

  short *psVar8;

  short sVar10;

  int iVar11;

  unsigned char bVar12;

  unsigned char bVar14;

  int *piVar13;

  int aiStack_28 [2];

  int local_20;

  puVar1 = 0x06027552;

  iVar3 = -140;

  sVar9 = 0x10;

  (&stack0xffffffec)[iVar3] = param_1;

  sVar10 = 0xc;

  if (*(int *)0x0605AD10 == 0x15) {

    sVar9 = 0x20;

    sVar10 = 0x18;

  }

  *(short *)(&stack0x00000004 + iVar3) = -sVar9;

  *(short *)(&stack0x00000006 + iVar3) = sVar9;

  *(short *)(&stack0x00000008 + iVar3) = sVar9;

  *(short *)(&stack0x0000000a + iVar3) = -sVar9;

  *(short *)(&stack0xfffffffc + iVar3) = -sVar10;

  *(short *)(&stack0xfffffffe + iVar3) = -sVar10;

  *(short *)(&stack0x00000000 + iVar3) = sVar10;

  *(short *)(&stack0x00000002 + iVar3) = sVar10;

  (*(int(*)())0x06027358)(*(int *)

              (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x30),

             (int)&local_20 + iVar3,&stack0xffffffe4 + iVar3);

  bVar14 = 0;

  do {

    iVar11 = (unsigned int)(bVar14 << 2);

    *(char **)((int)aiStack_28 + iVar3 + 4) = &stack0x0000005c + iVar11 + iVar3;

    *(unsigned int *)(&stack0xffffffe8 + iVar3) = (unsigned int)(bVar14 << 1);

    *(char **)(&stack0xfffffff0 + iVar3) = &stack0x00000004 + (unsigned int)(bVar14 << 1) + iVar3;

    uVar4 = (*(int(*)())puVar1)((int)*(short *)(&stack0x00000004 + (unsigned int)(bVar14 << 1) + iVar3) << 0x10,

                              *(int *)(&stack0xffffffe4 + iVar3));

    *(int *)((int)aiStack_28 + iVar3) = uVar4;

    psVar8 = (short *)(*(int *)(&stack0xffffffe8 + iVar3) + (int)(&stack0xfffffffc + iVar3));

    *(short **)(&stack0xfffffff4 + iVar3) = psVar8;

    iVar5 = (*(int(*)())puVar1)((int)*psVar8 << 0x10,*(int *)((int)&local_20 + iVar3));

    **(int **)((int)aiStack_28 + iVar3 + 4) = iVar5 + *(int *)((int)aiStack_28 + iVar3);

    *(char **)((int)aiStack_28 + iVar3 + 4) = &stack0x0000004c + iVar11 + iVar3;

    uVar4 = (*(int(*)())puVar1)((int)**(short **)(&stack0xfffffff4 + iVar3) << 0x10,

                              *(int *)(&stack0xffffffe4 + iVar3));

    *(int *)((int)aiStack_28 + iVar3) = uVar4;

    iVar5 = (*(int(*)())puVar1)((int)**(short **)(&stack0xfffffff0 + iVar3) << 0x10,

                              *(int *)((int)&local_20 + iVar3));

    bVar14 = bVar14 + 1;

    **(int **)((int)aiStack_28 + iVar3 + 4) = *(int *)((int)aiStack_28 + iVar3) - iVar5;

    *(int *)(&stack0x0000003c + iVar11 + iVar3) = 0;

  } while (bVar14 < 4);

  *(int *)(&stack0xfffffff8 + iVar3) =

       *(int *)

        (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x2c);

  if (*(int *)0x06078663 != '\0') {

    *(char **)

     (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x2c) =

         0x00008000 +

         *(int *)(0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x2c)

    ;

  }

  (*(int(*)())0x06027358)(*(int *)

              (0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x2c),

             (int)&local_20 + iVar3,&stack0xffffffe4 + iVar3);

  bVar14 = 0;

  do {

    iVar11 = (unsigned int)(bVar14 << 2);

    *(char **)(&stack0xffffffe8 + iVar3) = &stack0x0000000c + iVar11 + iVar3;

    *(char **)((int)aiStack_28 + iVar3 + 4) = &stack0x0000000c + iVar11 + iVar3;

    puVar7 = (int *)((int)aiStack_28 + iVar11 + DAT_06016ffa + iVar3 + 4);

    *(int **)(&stack0xfffffff4 + iVar3) = puVar7;

    uVar4 = (*(int(*)())puVar1)(*puVar7,*(int *)((int)&local_20 + iVar3));

    *(int *)((int)aiStack_28 + iVar3) = uVar4;

    *(char **)(&stack0xfffffff0 + iVar3) = &stack0x0000003c + iVar11 + iVar3;

    iVar5 = (*(int(*)())puVar1)(*(int *)(&stack0x0000003c + iVar11 + iVar3),

                              *(int *)(&stack0xffffffe4 + iVar3));

    **(int **)((int)aiStack_28 + iVar3 + 4) = iVar5 + *(int *)((int)aiStack_28 + iVar3);

    *(char **)((int)aiStack_28 + iVar3 + 4) = &stack0x0000002c + iVar11 + iVar3;

    uVar4 = (*(int(*)())puVar1)(**(int **)(&stack0xfffffff4 + iVar3),

                              *(int *)(&stack0xffffffe4 + iVar3));

    *(int *)((int)aiStack_28 + iVar3) = uVar4;

    iVar5 = (*(int(*)())puVar1)(**(int **)(&stack0xfffffff0 + iVar3),

                              *(int *)((int)&local_20 + iVar3));

    **(int **)((int)aiStack_28 + iVar3 + 4) = *(int *)((int)aiStack_28 + iVar3) - iVar5;

    *(int *)(&stack0x0000001c + iVar11 + iVar3) =

         *(int *)(&stack0x0000004c + iVar11 + iVar3);

    if (**(int **)(&stack0xffffffe8 + iVar3) != 0) {

      iVar11 = (unsigned int)(bVar14 << 2);

      puVar7 = (int *)(&stack0x0000002c + iVar11 + iVar3);

      *(int **)(&stack0xfffffff4 + iVar3) = puVar7;

      *(int **)((int)aiStack_28 + iVar3 + 4) = puVar7;

      *(int *)(&stack0xffffffe8 + iVar3) = *puVar7;

      *(char **)(&stack0xfffffff0 + iVar3) = &stack0x0000000c + iVar11 + iVar3;

      iVar5 = (*(int(*)())0x0602755C)(*(int *)(&stack0xffffffe8 + iVar3),

                         *(int *)(&stack0x0000000c + iVar11 + iVar3));

      **(int **)((int)aiStack_28 + iVar3 + 4) = iVar5 + *(int *)(&stack0xffffffe8 + iVar3);

      piVar13 = (int *)(&stack0x0000001c + iVar11 + iVar3);

      *(int **)(&stack0xfffffff4 + iVar3) = piVar13;

      iVar5 = *piVar13;

      *(int *)(&stack0xffffffe8 + iVar3) = iVar5;

      (*(int(*)())0x0602755C)(iVar5,**(int **)(&stack0xfffffff0 + iVar3));

      iVar5 = (*(int(*)())0x06034FE0)();

      *piVar13 = *(int *)(&stack0xffffffe8 + iVar3) - iVar5;

    }

    bVar14 = bVar14 + 1;

  } while (bVar14 < 4);

  *(int *)(0x06084FC8 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x44) + 0x2c)

       = *(int *)(&stack0xfffffff8 + iVar3);

  puVar2 = 0x06084FC8;

  *(char **)(&stack0xfffffff0 + iVar3) =

       0x06085490 + (short)((unsigned short)(unsigned char)(&stack0xffffffec)[iVar3] * 0x18) + 8;

  bVar12 = 0;

  bVar14 = (&stack0xffffffec)[iVar3];

  do {

    iVar5 = (unsigned int)(bVar12 << 2) + *(int *)(&stack0xfffffff0 + iVar3);

    *(int *)(&stack0xffffffec + iVar3) = iVar5;

    *(int *)((int)aiStack_28 + iVar3 + 4) = iVar5;

    uVar4 = *(int *)(puVar2 + (short)((unsigned short)bVar14 * 0x44) + 0xc);

    *(unsigned int *)(&stack0xffffffe8 + iVar3) = (unsigned int)(bVar12 << 2);

    iVar5 = (*(int(*)())puVar1)(*(int *)(&stack0x0000002c + (unsigned int)(bVar12 << 2) + iVar3),uVar4);

    uVar6 = (*(int(*)())0x0602754C)(*(int *)(puVar2 + (short)((unsigned short)bVar14 * 0x44) + 4) + iVar5);

    **(short **)((int)aiStack_28 + iVar3 + 4) = uVar6;

    *(int *)((int)aiStack_28 + iVar3 + 4) = *(int *)(&stack0xffffffec + iVar3) + 2;

    iVar5 = (*(int(*)())puVar1)(*(int *)

                               (&stack0x0000001c + *(int *)(&stack0xffffffe8 + iVar3) + iVar3),

                              *(int *)(puVar2 + (short)((unsigned short)bVar14 * 0x44) + 0xc));

    uVar6 = (*(int(*)())0x0602754C)(*(int *)(puVar2 + (short)((unsigned short)bVar14 * 0x44) + 8) + iVar5);

    bVar12 = bVar12 + 1;

    **(short **)((int)aiStack_28 + iVar3 + 4) = uVar6;

  } while (bVar12 < 4);

  return;

}
