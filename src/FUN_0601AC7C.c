extern int PTR_DAT_0601ace4;

extern int PTR_DAT_0601ace4;

extern int FUN_0601ae2c();

unsigned int FUN_0601ac7c()
{

  char *puVar1;

  unsigned int uVar2;

  char uVar3;

  int iVar4;

  int iVar5;

  char *puVar6;

  unsigned char bVar7;

  puVar1 = 0x060786A4;

  iVar4 = *(int *)(0x0605DD6C +

                  (*(int *)0x0607EAD8 * 6 + *(int *)(0x0605AD00 << 1)) << 2);

  iVar5 = *(int *)(0x0605DE24 + *(int *)(0x0607EAD8 << 3));

  uVar2 = (unsigned int)PTR_DAT_0601ace4;

  bVar7 = 0x13;

  if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(iVar4 + uVar2)) &&

     (uVar2 = 0, *(int *)0x0607EBF4 != 0)) {

    do {

      if (*(unsigned int *)((bVar7 - 1) * 0xc + iVar4 + 4) <= *(unsigned int *)puVar1) break;

      (*(int(*)())0x06035168)();

      bVar7 = bVar7 - 1;

    } while (bVar7 != 0);

    puVar6 = (char *)((unsigned int)bVar7 * 0xc + iVar4);

    *(int *)(puVar6 + 4) = *(int *)puVar1;

    uVar3 = FUN_0601ae2c();

    puVar6[8] = uVar3;

    puVar6[9] = *(int *)0x0605DE3C;

    uVar2 = *(unsigned int *)0x0607EAE0 & 0xff;

    puVar6[10] = (char)*(unsigned int *)0x0607EAE0;

    *puVar6 = 0;

    *(char **)0x06085FFC = puVar6;

    *(int *)0x06086012 = bVar7;

  }

  else {

    *(int *)0x06085FFC = 0;

  }

  puVar1 = 0x06086000;

  if ((*(int *)0x06078638 < *(int *)(iVar5 + 4)) && (0 < *(int *)0x06078638)) {

    *(int *)(iVar5 + 4) = *(int *)0x06078638;

    *(int *)puVar1 = iVar5;

  }

  else {

    *(int *)0x06086000 = 0;

  }

  return uVar2;

}
