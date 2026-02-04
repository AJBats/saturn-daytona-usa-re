extern int DAT_060025c6;

extern int DAT_060026aa;

extern int DAT_060026ac;

extern int DAT_060026ae;

extern int DAT_060026b0;

extern int DAT_060026b2;

extern int PTR_DAT_060025d4;

extern int PTR_DAT_060025d8;

extern int PTR_DAT_060026b4;

extern int PTR_DAT_060026b8;

extern int PTR_DAT_060026bc;

extern int PTR_DAT_060026c0;

extern void FUN_0600245c();

int FUN_06002594()
{

  short sVar1;

  int iVar2;

  short *local_30;

  short *puStack_2c;

  unsigned int uStack_8;

  FUN_0600245c(*(int *)PTR_DAT_060025d4,(int)DAT_060025c6,0);

  iVar2 = *(int *)PTR_DAT_060025d4;

  *(short *)(iVar2 + 0x20) = 1;

  puStack_2c = (short *)PTR_DAT_060025d8;

  local_30 = (short *)(iVar2 + 0x10);

  for (uStack_8 = 0; uStack_8 < 8; uStack_8 = uStack_8 + 1) {

    *local_30 = *puStack_2c;

    local_30 = local_30 + 1;

    puStack_2c = puStack_2c + 1;

  }

  iVar2 = *(int *)PTR_DAT_060026b4;

  *(short *)(iVar2 + 0x30) = (short)PTR_DAT_060026b8;

  *(short *)(iVar2 + 0x40) = DAT_060026aa;

  *(short *)(iVar2 + 0x42) = DAT_060026aa;

  iVar2 = *(int *)PTR_DAT_060026b4;

  *(char **)(iVar2 + 0x78) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x7c) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x88) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x8c) = PTR_DAT_060026bc;

  *(int *)(iVar2 + 0xac) = (int)DAT_060026ac;

  *(short *)PTR_DAT_060026c0 = 0;

  *(short *)(*(int *)PTR_DAT_060026b4 + (int)DAT_060026ae) = 0x20;

  *(short *)(*(int *)PTR_DAT_060026b4 + (int)DAT_060026b0 + 8) = 7;

  iVar2 = *(int *)PTR_DAT_060026b4 + (int)DAT_060026b2;

  *(short *)(iVar2 + 0x10) = 1;

  sVar1 = DAT_060026b2;

  *(short *)(iVar2 + 0x18) = DAT_060026b2;

  *(short *)(iVar2 + 0x16) = sVar1;

  *(short *)(iVar2 + 0x14) = sVar1;

  return 1;

}
