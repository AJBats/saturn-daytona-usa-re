extern int DAT_06014682;

extern int PTR_DAT_06014684;

extern int PTR_DAT_06014684;

extern int FUN_060146d2();

void FUN_060145bc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  puVar4 = 0x06084B20;

  puVar3 = 0x06084B14;

  puVar2 = 0x06084B18;

  puVar1 = 0x0601D5F4;

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06014682) != 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06014684) == 0 &&

        *(int *)0x06084B20 != 0x7d) {

      if (*(int *)0x06084B20 == 0x7b) {

        FUN_060146d2();

        return;

      }

      iVar5 = *(int *)0x06084B18;

      *(int *)0x06084B18 = iVar5 + 1;

      puVar3[iVar5] = (char)*(int *)puVar4;

      uVar6 = 0xAB1102FF;

      if (-1 < *(int *)puVar4 + -0x41) {

        uVar6 = *(int *)(0x0605B0FC + (*(int *)puVar4 + -0x41) << 2);

      }

      (*(int(*)())puVar1)(0,uVar6);

      if (*(int *)puVar2 == 3) {

        *(int *)0x06084B08 = 0x1c;

        (*(int(*)())puVar1)(0,0xAB111EFF);

      }

    }

    else if (*(int *)0x06084B18 == 0) {

      *(int *)0x06084B14 = 0;

      puVar3[1] = 0;

      puVar3[2] = 0;

      puVar3[3] = 0;

    }

    else {

      (*(int(*)())0x0601D5F4)(0,0xAB1101FF);

      iVar5 = *(int *)puVar2;

      *(int *)puVar2 = iVar5 + -1;

      puVar3[iVar5 + -1] = 0;

    }

  }

  return;

}
