extern int DAT_06014306;

extern int PTR_DAT_06014308;

extern int PTR_DAT_06014308;

void FUN_0601424c()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int *piVar4;

  (*(int(*)())0x06026E0C)();

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(0,(int)DAT_06014306,0x000108F5);

  puVar1 = 0x06084AF8;

  piVar4 = (int *)(0x0605AD5C + *(int *)(0x06084B08 << 5));

  iVar3 = (int)*(short *)(piVar4 + 6) - (int)*(short *)0x06084AF8;

  *(short *)0x06084AF8 =

       *(short *)0x06084AF8 + (short)((int)(iVar3 + (unsigned int)(iVar3 < 0)) >> 1);

  (*(int(*)())0x06026F2A)((int)*(short *)puVar1);

  puVar2 = 0x06084AFC;

  iVar3 = (*(int(*)())0x06027552)((*piVar4 - *(int *)0x06084AFC) + (int)PTR_DAT_06014308,

                     0x00008000);

  iVar3 = *(int *)puVar2 + iVar3;

  *(int *)puVar2 = iVar3;

  (*(int(*)())0x06026E2E)(0,iVar3);

  (*(int(*)())0x06026F2A)(-(int)*(short *)puVar1);

  (*(int(*)())0x06026EDE)((*(unsigned int *)0x0607EBC8 & 0x1f) << 0xb);

  (*(int(*)())0x06026E60)(0x00010000,0x00010000,0x00010000);

  (*(int(*)())0x06031D8C)(*(int *)0x060623AC,4);

  (*(int(*)())0x06031A28)(*(int *)0x06062334,(int)*(short *)0x06089E4A,1);

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  return;

}
