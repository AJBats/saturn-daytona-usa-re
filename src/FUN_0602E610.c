extern int DAT_0602e80a;

int FUN_0602e610()
{

  short sVar1;

  int iVar2;

  unsigned int uVar3;

  int iVar4;

  int iVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int in_pr;

  iVar9 = *(int *)0x0607E944;

  iVar10 = *(int *)(iVar9 + 0x00000238);

  if (*(int *)0x06083264 == iVar10) goto LAB_0602e78c;

  if (*(int *)0x06083268 == iVar10) {

    iVar8 = *(int *)(iVar10 + 0x00000008) - *(int *)(iVar9 + 0x00000008);

    if (iVar8 < 0) {

      iVar8 = -iVar8;

    }

    iVar5 = *(int *)(iVar9 + 0x00000018);

    iVar2 = *(int *)(iVar10 + 0x00000018);

    iVar4 = *(int *)(iVar10 + 0x00000010) - *(int *)(iVar9 + 0x00000010);

    iVar4 = (*(void(*)())0x06027552)(iVar4,iVar4,iVar5);

    iVar2 = (*(void(*)())0x06027552)(iVar2 - iVar5,iVar2 - iVar5);

    uVar7 = iVar4 + iVar2;

    if ((int)uVar7 < 0) {

      iVar4 = (*(void(*)())0x06027476)(uVar7 >> 2);

      iVar4 = iVar4 << 1;

    }

    else {

      iVar4 = (*(void(*)())0x06027476)(uVar7);

    }

    iVar2 = iVar4;

    if (iVar4 < 0) {

      iVar2 = -iVar4;

    }

    if ((int)0x000F0000 <= iVar2) goto LAB_0602e78c;

  }

  else {

    iVar10 = *(int *)(iVar9 + 0x0000023C);

    if (iVar10 != *(int *)0x06083264) goto LAB_0602e78c;

    iVar8 = *(int *)(iVar10 + 0x00000008) - *(int *)(iVar9 + 0x00000008);

    if (iVar8 < 0) {

      iVar8 = -iVar8;

    }

    iVar5 = *(int *)(iVar9 + 0x00000018);

    iVar2 = *(int *)(iVar10 + 0x00000018);

    iVar4 = *(int *)(iVar10 + 0x00000010) - *(int *)(iVar9 + 0x00000010);

    iVar4 = (*(void(*)())0x06027552)(iVar4,iVar4,iVar5);

    iVar2 = (*(void(*)())0x06027552)(iVar2 - iVar5,iVar2 - iVar5);

    uVar7 = iVar4 + iVar2;

    if ((int)uVar7 < 0) {

      iVar4 = (*(void(*)())0x06027476)(uVar7 >> 2);

      iVar4 = iVar4 << 1;

    }

    else {

      iVar4 = (*(void(*)())0x06027476)(uVar7);

    }

    iVar2 = iVar4;

    if (iVar4 < 0) {

      iVar2 = -iVar4;

    }

    if ((int)0x000F0000 <= iVar2) goto LAB_0602e78c;

  }

  sVar1 = (*(void(*)())0x0602744C)(*(int *)(iVar10 + 0x10) - *(int *)(iVar9 + 0x10),

                     *(int *)(iVar10 + 0x18) - *(int *)(iVar9 + 0x18),*(int *)(iVar9 + 0x10),

                     *(int *)(iVar9 + 0x18),in_pr,iVar4);

  uVar3 = (unsigned int)DAT_0602e80a;

  uVar6 = (unsigned int)(unsigned short)-sVar1 | uVar3 << 1;

  uVar7 = *(int *)(iVar9 + 0x28) - uVar6;

  if ((int)uVar7 < 1) {

    uVar7 = -uVar7;

  }

  iVar10 = (int)(char)*0x06078663;

  if (iVar10 == 0) {

    if ((uVar7 & 0xffff) < uVar3) {

LAB_0602e864:

      if (iVar8 < 0x00000050) {

        (*(void(*)())0x0601D5F4)(0x00000000,0xAE1105FF,uVar6,iVar10,in_pr);

      }

      else {

        (*(void(*)())0x0601D5F4)(0x00000000,0xAE1109FF,uVar6,iVar10,in_pr);

      }

      goto LAB_0602e78c;

    }

  }

  else if (uVar3 <= (uVar7 & 0xffff)) goto LAB_0602e864;

  if (iVar8 < 0x00000050) {

    (*(void(*)())0x0601D5F4)(0x00000000,0xAE1106FF,uVar6,iVar10,in_pr);

  }

  else {

    (*(void(*)())0x0601D5F4)(0x00000000,0xAE110AFF,uVar6,iVar10,in_pr);

  }

LAB_0602e78c:

  *(int *)0x06083264 = *(int *)(iVar9 + 0x00000238);

  iVar10 = 0x0000023C;

  *(int *)0x06083268 = *(int *)(iVar9 + 0x0000023C);

  return iVar10;

}
