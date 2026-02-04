extern int FUN_0603f3da();
extern int FUN_0603f582();
extern int FUN_0603f84c();

int FUN_0603f342(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char local_4c [16];

  char auStack_3c [16];

  char auStack_2c [24];

  puVar1 = 0x06036DDC;

  FUN_0603f3da(auStack_2c,param_1,param_3,param_4,param_1);

  iVar3 = 0;

  while ((0 < param_3 && (FUN_0603f582(auStack_2c,local_4c), local_4c[0] != '\0'))) {

    if ((iVar3 < 3) ||

       (iVar2 = (*(void(*)())0x06036D94)(param_2 + -0xc,auStack_3c,0xc), iVar2 != 0)) {

      FUN_0603f84c(param_2,local_4c);

      (*(void(*)())puVar1)(param_2 + 0xc,auStack_3c,0xc);

    }

    param_2 = param_2 + 0x18;

    iVar3 = iVar3 + 1;

    param_3 = param_3 + -1;

  }

  *(unsigned char *)(param_2 + -0xd) = *(unsigned char *)(param_2 + -0xd) | 0x80;

  return iVar3;

}
