void FUN_060061c8()
{
  register int base asm("r11") = *(int *)0x0607E940;
  register int iVar5 asm("r14") = *(int *)(base + 0x10);
  register int uVar4 asm("r13") = *(int *)(base + 0x14);
  register int iVar3 asm("r12") = *(int *)(base + 0x18);
  int *p;

  (*(int(*)())0x06026DBC)();
  (*(int(*)())0x06026E0C)();
  (*(int(*)())0x06026EDE)(*(int *)(base + 0x30));

  base = 0x06026FFC;
  (*(int(*)())base)(0x0604464C, 0x06063E9C);
  (*(int(*)())base)(0x06044640, 0x06063EB0);
  (*(int(*)())base)(0x06044658, 0x06063ED8);
  (*(int(*)())base)(0x06044664, 0x06063EC4);

  p = (int *)0x06063E9C;
  *p = *p + iVar5;
  p[1] = uVar4;
  p[2] = p[2] + iVar3;

  p = (int *)0x06063EB0;
  *p = *p + iVar5;
  p[1] = uVar4;
  p[2] = p[2] + iVar3;

  p = (int *)0x06063ED8;
  *p = *p + iVar5;
  p[1] = uVar4;
  p[2] = p[2] + iVar3;

  p = (int *)0x06063EC4;
  *p = *p + iVar5;
  p[1] = uVar4;
  p[2] = p[2] + iVar3;

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;
}
