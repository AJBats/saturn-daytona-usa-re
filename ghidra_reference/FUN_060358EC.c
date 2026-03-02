void FUN_060358ec()
{

  unsigned int in_r0;

  unsigned int uVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int *in_stack_00000000;

  if (in_r0 == 0) {

    uVar4 = 0;

    uVar2 = 0;

  }

  else {

    uVar2 = in_r0;

    iVar3 = 0x0000041F;

    if ((int)in_r0 < 0) {

      uVar2 = -in_r0;

    }

    do {

      uVar1 = uVar2;

      iVar3 = iVar3 + -1;

      uVar2 = uVar1 << 1;

    } while ((uVar1 & 0x80000000) == 0);

    uVar4 = uVar1 << 0x15;

    uVar2 = (uVar1 << 1) >> 0xc | (iVar3 << 20) & 0x7fffffffU |

            (unsigned int)((int)in_r0 < 0) * -0x80000000;

  }

  *in_stack_00000000 = uVar2;

  in_stack_00000000[1] = uVar4;

  return;

}
