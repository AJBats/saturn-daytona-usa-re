extern int DAT_0600855e;

extern int PTR_DAT_06008560;

extern int PTR_DAT_06008560;

extern int FUN_060086c0();

void FUN_060084ca()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x0607E944;

  iVar2 = (int)DAT_0600855e;

  *(int *)(*(int *)0x0607E944 + iVar2) = *(int *)(*(int *)0x0607E944 + iVar2) + 1;

  *(int *)(*(int *)puVar1 + iVar2 + -0x10) = 0;

  FUN_060086c0();

  if (((*(char **)puVar1 == 0x06078900) &&

      ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0)) &&

     ((*(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

    *(short *)0x0605A016 = 3;

    *(int *)0x06078654 = 7;

    *(int *)0x06063E1C = 2;

    *(int *)0x06059F30 = 1;

    (*(void(*)())0x06038BD4)(8,0);

    *(char **)0x06063E24 = 0x00058000;

    *(char **)0x06063E34 = 0x0000F300;

    *(char **)0x06063E28 = 0x006E0000;

    *(char **)0x06063E2C = 0x00100000;

    *(int *)0x06063E30 = 0;

    *(int *)0x0607866C = (char)*(int *)(*(int *)puVar1 + (int)PTR_DAT_06008560);

  }

  return;

}
