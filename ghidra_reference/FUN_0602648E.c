extern int DAT_060264ee;

unsigned int FUN_0602648e()
{
  unsigned short uVar1;
  unsigned int uVar6;
  short uVar7;
  unsigned short uVar8;

  uVar8 = 0;

  do {
    uVar6 = (unsigned int)*(unsigned short *)(0x0606107C + (unsigned int)(uVar8 << 3) + 6) - 0x8a;

    if (0xb < uVar6) goto LAB_06026508;

    uVar1 = ((int *)0x060264f0)[uVar6];
    uVar7 = (short)0x8000;

    switch(uVar6) {
    case 0:
    case 1:
      uVar7 = 0;
      break;
    case 2:
    case 3:
      uVar7 = 0;
      goto LAB_060264c0;
    default:
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
LAB_060264c0:
      *(short *)0x06060D34 = uVar7;
      uVar6 = (int)(short)uVar1;
      goto LAB_06026508;
    }

    *(short *)0x06060D2A = uVar7;
    uVar6 = (int)(short)uVar1;

LAB_06026508:
    uVar8 = uVar8 + 1;

    if (7 < uVar8) {
      return uVar6;
    }
  } while( 1 );
}
