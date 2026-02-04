extern int DAT_0600db40;

extern int DAT_0600db44;

extern int DAT_0600db46;

extern int FUN_0600db9e();
extern int FUN_0600dc74();

void FUN_0600da7c()
{

  short sVar1;

  char *puVar2;

  unsigned int uVar3;

  int iVar4;

  short *puVar5;

  short *psVar6;

  short uVar7;

  unsigned int uVar8;

  puVar2 = 0x0607869A;

  iVar4 = *(int *)0x0607E940;

  uVar7 = 1;

  if (*(int *)(iVar4 + DAT_0600db40) != 0) {

    if (*(short *)0x0607869A != 0) {

      psVar6 = (short *)0x06078698;

      (*(void(*)())0x06034F78)();

      *psVar6 = *psVar6 + 1;

      FUN_0600db9e();

      return;

    }

    return;

  }

  sVar1 = *(short *)(*(int *)(iVar4 + DAT_0600db44) * 0x18 + *(int *)(iVar4 + DAT_0600db44 + -4) +

                    0xe);

  uVar3 = (unsigned int)(unsigned short)((short)*(int *)(iVar4 + 0x28) + sVar1 * -4);

  uVar8 = *(int *)(iVar4 + 0x20) + sVar1 * -4 & 0xffff;

  if (((((int)DAT_0600db46 <= (int)uVar3) && ((int)uVar3 <= (int)0x0000C000)) &&

      ((int)DAT_0600db46 <= (int)uVar8)) && ((int)uVar8 <= (int)0x0000C000)) {

    psVar6 = (short *)0x06078698;

    (*(void(*)())0x06034F78)();

    *psVar6 = *psVar6 + 1;

    *(short *)puVar2 = uVar7;

    FUN_0600db9e();

    return;

  }

  uVar7 = 0;

  puVar5 = (short *)0x06078698;

  (*(void(*)())0x06034F78)();

  *puVar5 = uVar7;

  *(short *)puVar2 = uVar7;

  FUN_0600dc74();

  return;

}
