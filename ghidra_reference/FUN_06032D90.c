void FUN_06032d90()
{

  int *piVar1;

  int *piVar2;

  int unaff_r14;

  piVar2 = (int *)(0x060624A4 + (0x0000000C & 0xffff) * (*(unsigned int *)0x0607EAD8 & 0xffff)

                  );

  piVar1 = (int *)(*(int *)(0x060624F8 + *(int *)(0x0607EAD8 << 2)) +

                  *(char *)(unaff_r14 + 0x000002DC) << 4);

  *(int *)(unaff_r14 + 0x00000000) = *piVar1 + *piVar2;

  *(int *)(unaff_r14 + 0x00000004) = piVar1[1] + piVar2[1];

  *(int *)(unaff_r14 + 0x00000008) = piVar1[2] + piVar2[2];

  *(short *)(unaff_r14 + 0x0000000C) = *(short *)(piVar1 + 3);

  *(char *)(unaff_r14 + 0x000002DD) = *(char *)((int)piVar1 + 0xe);

  *(int *)(unaff_r14 + 0x000002D8) =

       *(int *)(0x06062624 + *(char *)(unaff_r14 + 0x000002DD) << 2);

  return;

}
