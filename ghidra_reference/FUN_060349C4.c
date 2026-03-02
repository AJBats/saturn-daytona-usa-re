extern int DAT_06034a8e;

extern int FUN_06034a10();

int FUN_060349c4(param_1)
    unsigned char *param_1;
{

  int iVar1;

  char auStack_14 [12];

  iVar1 = FUN_06034a10(auStack_14);

  if (iVar1 == 0) {

    (*(int(*)())0x06035F16)(auStack_14,param_1);

    if ((*param_1 == DAT_06034a8e) || ((*param_1 & 0x20) == 0)) {

      iVar1 = -8;

    }

  }

  return iVar1;

}
