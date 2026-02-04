extern int DAT_06010a2a;

void FUN_06010994()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  puVar3 = 0x0602761E;

  puVar2 = 0x06063F5C;

  puVar1 = 0x06059FFC;

  if (*(int *)0x06083255 == '\0') {

    iVar6 = (int)DAT_06010a2a;

    uVar5 = *(int *)(0x0605D05C + *(int *)0x06078868 * 4);

    iVar4 = *(int *)0x06059FFC * 8 + *(int *)0x06063F5C + 0x40;

  }

  else {

    iVar6 = 0x20;

    uVar5 = *(int *)(0x0605D0AC + *(int *)0x0607EAB8 * 4);

    iVar4 = ((unsigned int)(unsigned char)0x060448B5[*(int *)0x0607EAD8] +

            (unsigned int)*(unsigned short *)0x0607886C) * 0x20 + *(int *)0x06059FFC * 8 +

            *(int *)0x06063F5C;

  }

  (*(void(*)())0x0602761E)(iVar4,uVar5,iVar6);

  (*(void(*)())puVar3)(*(int *)puVar1 * 8 + *(int *)puVar2 + DAT_06010a2a + 0x40,

                    *(int *)(0x0605D05C + (unsigned int)(unsigned char)*0x0607ED91 * 4));

  return;

}
