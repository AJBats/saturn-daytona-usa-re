extern int DAT_06026336;

unsigned int FUN_060262c0(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  short uVar6;

  unsigned short uVar7;

  puVar4 = 0x06089ED4;

  puVar3 = 0x06089ED6;

  puVar2 = 0x06060F2C;

  uVar5 = 0;

  *(short *)0x06089ED6 = 0;

  *(short *)puVar4 = 0;

  uVar7 = 0;

  do {

    if (9 < uVar7) {

      return uVar5;

    }

    if ((uVar7 == param_1) ||

       (uVar5 = (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(uVar7 << 3) + 6) - 0x8a, 0xb < uVar5))

    goto LAB_06026350;

    uVar1 = ((int *)0x06026338)[uVar5];

    switch(uVar5) {

    case 0:

    case 1:

      uVar6 = 1;

      break;

    case 2:

    case 3:

      uVar6 = 1;

      goto LAB_0602630a;

    default:

      uVar6 = 2;

      break;

    case 8:

    case 9:

    case 10:

    case 0xb:

      uVar6 = 2;

LAB_0602630a:

      *(short *)puVar4 = uVar6;

      uVar5 = (int)(short)uVar1;

      goto LAB_06026350;

    }

    *(short *)puVar3 = uVar6;

    uVar5 = (int)(short)uVar1;

LAB_06026350:

    uVar7 = uVar7 + 1;

  } while( 1 );

}
