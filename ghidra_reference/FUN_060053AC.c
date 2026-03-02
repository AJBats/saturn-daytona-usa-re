void FUN_060053ac(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int param_3;
{
  register int (*func)() asm("r3") = (int(*)())0x06027552;
  register int *dest asm("r2") = (int *)0x06063DF8;
  int uVar3;
  int iVar4;
  int local_24;
  int local_20;
  int uStack_1c;
  int auStack_18[2];

  (*(void(*)())0x06026E0C)();
  *(int *)(*(int *)0x06089EDC + 0x2c) = param_3;

  if (*(int *)0x06078663 != '\0') {
    (*(void(*)())0x06026E60)(0xFFFF0000, 0x00010000);
  }

  (*(void(*)())0x06026E94)(-*param_2);
  (*(void(*)())0x06026F2A)(-param_2[2]);
  (*(void(*)())0x06026EDE)(-param_2[1]);
  (*(void(*)())0x06026E2E)(-*param_1, -param_1[1], -param_1[2]);

  (*(void(*)())0x06027358)(*param_2, auStack_18, &local_24);
  (*(void(*)())0x06027358)(param_2[1], &local_20, &uStack_1c);

  uVar3 = func(local_24, local_20);
  iVar4 = func(param_3, uVar3);
  *dest = iVar4 + *param_1;

  iVar4 = func(param_3, auStack_18[0]);
  dest[1] = param_1[1] - iVar4;

  uVar3 = func(local_24, uStack_1c);
  iVar4 = func(param_3, uVar3);
  dest[2] = param_1[2] - iVar4;
}
