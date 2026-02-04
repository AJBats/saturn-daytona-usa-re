extern int DAT_060263c2;

unsigned int FUN_06026362()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  short uVar7;

  unsigned short uVar8;

  puVar5 = 0x00008000;

  puVar4 = 0x06060D34;

  puVar3 = 0x06060D2A;

  puVar2 = 0x06060F2C;

  uVar8 = 0;

  do {

    uVar6 = (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)uVar8 * 8 + 6) - (int)DAT_060263c2;

    if (0xb < uVar6) goto LAB_060263dc;

    uVar1 = (&switchD_060263be::switchdataD_060263c4)[uVar6];

    uVar7 = SUB42(puVar5,0);

    switch(uVar6) {

    case 0:

    case 1:

      uVar7 = 0;

      break;

    case 2:

    case 3:

      uVar7 = 0;

      goto LAB_06026394;

    default:

      break;

    case 8:

    case 9:

    case 10:

    case 0xb:

LAB_06026394:

      *(short *)puVar4 = uVar7;

      uVar6 = (int)(short)uVar1;

      goto LAB_060263dc;

    }

    *(short *)puVar3 = uVar7;

    uVar6 = (int)(short)uVar1;

LAB_060263dc:

    uVar8 = uVar8 + 1;

    if (9 < uVar8) {

      return uVar6;

    }

  } while( true );

}
