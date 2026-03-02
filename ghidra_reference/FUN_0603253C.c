char * FUN_0603253c()
{

  char *puVar1;

  unsigned int uVar2;

  int unaff_r14;

  if (*(int *)0x06082A24 == '\0') {

    return 0x06082A24;

  }

  uVar2 = 0x00000001;

  if ((0x00000002 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    uVar2 = 0xFFFFFFFF;

  }

  if ((0x00000001 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    uVar2 = 0x00000000;

  }

  puVar1 = 0x000002C4;

  *(unsigned int *)(0x000002C4 + unaff_r14) = *(int *)(0x000002C4 + unaff_r14) + uVar2;

  return puVar1;

}
