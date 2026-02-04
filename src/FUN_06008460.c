extern int DAT_060084a2;

extern int DAT_060084a4;

extern int DAT_060084a6;

extern int FUN_060084ca();

void FUN_06008460()
{

  char *puVar1;

  unsigned char *pbVar2;

  puVar1 = 0x0607E944;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_060084a2) == 0) {

    if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0) {

      (*(void(*)())0x0601D5F4)(0,0xAE1102FF);

    }

    pbVar2 = (unsigned char *)(*(int *)puVar1 + 1);

    *pbVar2 = *pbVar2 & 0xfe | 1;

    *(int *)(*(int *)puVar1 + (int)DAT_060084a6) = (int)DAT_060084a4;

    FUN_060084ca(*(int *)0x060453BC);

    return;

  }

  return;

}
