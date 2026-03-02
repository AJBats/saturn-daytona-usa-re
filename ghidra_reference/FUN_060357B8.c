long long FUN_060357b8()
{

  unsigned int uVar1;

  unsigned int uVar2;

  int in_r1;

  int iVar3;

  int iVar4;

  unsigned int in_stack_00000000;

  unsigned int in_stack_00000004;

  iVar3 = (in_stack_00000000 >> 0x14 & 0x000007FF) - 0x000003FF;

  if ((iVar3 < 0) || (0x53 < iVar3)) {

    uVar2 = 0;

  }

  else {

    uVar2 = in_stack_00000000 & 0x000FFFFF | (unsigned int)0x00100000;

    iVar4 = iVar3 + -0x14;

    if (iVar4 < 0) {

      iVar4 = -iVar4;

      do {

        iVar4 = iVar4 + -1;

        uVar2 = uVar2 >> 1;

      } while (iVar4 != 0);

    }

    else if (iVar4 < 0x20) {

      iVar3 = iVar3 + -0x13;

      while (iVar3 = iVar3 + -1, iVar3 != 0) {

        uVar1 = in_stack_00000004 & 0x80000000;

        in_stack_00000004 = in_stack_00000004 << 1;

        uVar2 = uVar2 << 1 | (unsigned int)(uVar1 != 0);

      }

    }

    else {

      uVar2 = in_stack_00000004;

      for (iVar3 = iVar3 + -0x34; iVar3 != 0; iVar3 = iVar3 + -1) {

        uVar2 = uVar2 << 1;

      }

    }

    if ((in_stack_00000000 & 0x80000000) != 0) {

      uVar2 = -uVar2;

    }

  }

  return CONCAT44(in_r1,uVar2);

}
