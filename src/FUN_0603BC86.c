extern int PTR_DAT_0603bcd0;

extern int PTR_DAT_0603bcd0;

int FUN_0603bc86(param_1, param_2, param_3, param_4)
    int param_1;
    int *param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  int uVar2;

  int iVar3;

  iVar1 = (*(int(*)())0x060400D6)(param_1 + 0x14,param_4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    *param_2 = iVar1;

    iVar3 = (*(int(*)())0x0604077C)(PTR_DAT_0603bcd0 + param_1,iVar1,*(int *)(iVar1 + 0xc),

                       *(char *)(iVar1 + 0x1c),0,param_2,param_4);

    if (iVar3 == 0) {

      uVar2 = 0;

    }

    else {

      (*(int(*)())0x060401E4)(iVar1,iVar3);

      uVar2 = (*(int(*)())0x0603F8B8)(param_1 + 0x78,iVar3,0x060408B0,0x06040954,0x06040AF8,

                         0x06040C50,0x06040C5C);

      *(char *)(param_2 + 4) = 0;

    }

  }

  return uVar2;

}
