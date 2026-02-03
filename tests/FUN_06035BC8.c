void FUN_06035bc8()
{

  unsigned int in_r0;

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int *in_stack_00000000;

  

  iVar2 = 0x0000041F;

  if (in_r0 == 0) {

    uVar3 = 0;

    uVar1 = 0;

  }

  else {

    do {

      uVar1 = in_r0;

      iVar2 = iVar2 + -1;

      in_r0 = uVar1 << 1;

    } while ((uVar1 & 0x80000000) == 0);

    uVar3 = uVar1 << 0x15;

    uVar1 = (uVar1 << 1) >> 0xc | iVar2 << 20;

  }

  *in_stack_00000000 = uVar1;

  in_stack_00000000[1] = uVar3;

  return;

}
