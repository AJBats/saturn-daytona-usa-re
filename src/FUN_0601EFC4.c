extern int DAT_0601efda;

char * FUN_0601efc4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  char *puVar5;

  int *puVar6;

  char *puVar7;

  char *puVar8;

  int *puVar9;

  char *puVar10;

  iVar4 = (int)DAT_0601efda;

  puVar2 = (char *)(unsigned int)(unsigned char)*0x06087080;

  if (puVar2 == (char *)0x0) {

    puVar3 = (char *)(*(int *)0x0605E098 + 0x10);

    puVar9 = (int *)(0x0605DD6C + 0x48);

    puVar6 = (int *)0x0605DD6C;

    do {

      puVar10 = (char *)*puVar6;

      puVar2 = puVar10;

      do {

        *puVar3 = *puVar2;

        puVar3[1] = puVar2[1];

        puVar3[2] = puVar2[2];

        puVar3[3] = puVar2[3];

        puVar3[4] = puVar2[4];

        puVar3[5] = puVar2[5];

        puVar3[6] = puVar2[6];

        puVar3[7] = puVar2[7];

        puVar5 = puVar2 + 0xc;

        puVar3[8] = puVar2[8];

        puVar3[9] = puVar2[9];

        puVar3[10] = puVar2[10];

        puVar3[0xb] = puVar2[0xb];

        puVar3 = puVar3 + 0xc;

        puVar2 = puVar5;

      } while (puVar5 < puVar10 + iVar4);

      puVar6 = puVar6 + 2;

    } while (puVar6 < puVar9);

    puVar9 = (int *)(0x0605DE24 + 0x18);

    puVar6 = (int *)0x0605DE24;

    do {

      puVar2 = (char *)*puVar6;

      puVar6 = puVar6 + 1;

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      puVar3 = puVar3 + 8;

    } while (puVar6 < puVar9);

    puVar10 = 0x0605DDB4 + 0x20;

    puVar7 = 0x0605DDB4;

    do {

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar5 = puVar7 + 8;

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3 = puVar3 + 8;

      puVar7 = puVar5;

    } while (puVar5 < puVar10);

    puVar10 = 0x0605DDD4 + 0x20;

    puVar7 = 0x0605DDD4;

    do {

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar5 = puVar7 + 8;

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3 = puVar3 + 8;

      puVar7 = puVar5;

    } while (puVar5 < puVar10);

    puVar10 = 0x0605DE40 + 0x24;

    puVar7 = 0x0605DE40;

    do {

      puVar5 = puVar3;

      *puVar5 = *puVar7;

      puVar5[1] = puVar7[1];

      puVar5[2] = puVar7[2];

      puVar5[3] = puVar7[3];

      puVar5[4] = puVar7[4];

      puVar5[5] = puVar7[5];

      puVar5[6] = puVar7[6];

      puVar5[7] = puVar7[7];

      puVar5[8] = puVar7[8];

      puVar5[9] = puVar7[9];

      puVar8 = puVar7 + 0xc;

      puVar5[10] = puVar7[10];

      puVar5[0xb] = puVar7[0xb];

      puVar1 = 0x0605AD00;

      puVar3 = puVar5 + 0xc;

      puVar7 = puVar8;

    } while (puVar8 < puVar10);

    puVar3 = 0x0605AD00 + 1;

    puVar5[0xc] = *0x0605AD00;

    puVar5[0xd] = *puVar3;

    puVar5[0xe] = puVar1[2];

    puVar5[0xf] = puVar1[3];

    puVar7 = 0x0605AD04;

    puVar3 = 0x0605AD04 + 1;

    puVar5[0x10] = *0x0605AD04;

    puVar5[0x11] = *puVar3;

    puVar5[0x12] = puVar7[2];

    puVar5[0x13] = puVar7[3];

    puVar7 = 0x0605AD0C;

    puVar3 = 0x0605AD0C + 1;

    puVar5[0x14] = *0x0605AD0C;

    puVar5[0x15] = *puVar3;

    puVar5[0x16] = puVar7[2];

    puVar5[0x17] = puVar7[3];

    puVar5[0x18] = *0x0605AB16;

    puVar5[0x19] = *0x0605AB17;

    puVar5[0x1a] = *0x0605D240;

    puVar5[0x1b] = *0x0605D241;

    puVar3 = 0x06060D44 + 1;

    puVar5[0x1c] = *0x06060D44;

    puVar5[0x1d] = *puVar3;

    puVar3 = 0x06060D46 + 1;

    puVar5[0x1e] = *0x06060D46;

    puVar5[0x1f] = *puVar3;

    puVar3 = 0x06060D40 + 1;

    puVar5[0x20] = *0x06060D40;

    puVar5[0x21] = *puVar3;

    puVar3 = 0x06060D42 + 1;

    puVar5[0x22] = *0x06060D42;

    puVar5[0x23] = *puVar3;

    puVar3 = 0x06060D48 + 1;

    puVar5[0x24] = *0x06060D48;

    puVar5[0x25] = *puVar3;

    puVar3 = 0x06060D4A + 1;

    puVar5[0x26] = *0x06060D4A;

    puVar5[0x27] = *puVar3;

    puVar3 = 0x06060D4C + 1;

    puVar5[0x28] = *0x06060D4C;

    puVar5[0x29] = *puVar3;

    puVar3 = 0x06060D4E + 1;

    puVar5[0x2a] = *0x06060D4E;

    puVar5[0x2b] = *puVar3;

    puVar7 = 0x06060D54;

    puVar3 = 0x06060D54 + 1;

    puVar5[0x2c] = *0x06060D54;

    puVar5[0x2d] = *puVar3;

    puVar5[0x2e] = puVar7[2];

    puVar5[0x2f] = puVar7[3];

    puVar7 = 0x06060D58;

    puVar3 = 0x06060D58 + 1;

    puVar5[0x30] = *0x06060D58;

    puVar5[0x31] = *puVar3;

    puVar5[0x32] = puVar7[2];

    puVar5[0x33] = puVar7[3];

    puVar7 = 0x06060D50;

    puVar3 = 0x06060D50 + 1;

    puVar5[0x34] = *0x06060D50;

    puVar5[0x35] = *puVar3;

    puVar5[0x36] = puVar7[2];

    puVar5[0x37] = puVar7[3];

    puVar3 = 0x06060D60 + 1;

    puVar5[0x38] = *0x06060D60;

    puVar5[0x39] = *puVar3;

    puVar3 = 0x06060D62 + 1;

    puVar5[0x3a] = *0x06060D62;

    puVar5[0x3b] = *puVar3;

    puVar3 = 0x06060D5C + 1;

    puVar5[0x3c] = *0x06060D5C;

    puVar5[0x3d] = *puVar3;

    puVar3 = 0x06060D5E + 1;

    puVar5[0x3e] = *0x06060D5E;

    puVar5[0x3f] = *puVar3;

    puVar3 = 0x06060D64 + 1;

    puVar5[0x40] = *0x06060D64;

    puVar5[0x41] = *puVar3;

    puVar3 = 0x06060D66 + 1;

    puVar5[0x42] = *0x06060D66;

    puVar5[0x43] = *puVar3;

    puVar3 = 0x06060D68 + 1;

    puVar5[0x44] = *0x06060D68;

    puVar5[0x45] = *puVar3;

    puVar3 = 0x06060D6A + 1;

    puVar5[0x46] = *0x06060D6A;

    puVar5[0x47] = *puVar3;

    puVar7 = 0x06060D70;

    puVar3 = 0x06060D70 + 1;

    puVar5[0x48] = *0x06060D70;

    puVar5[0x49] = *puVar3;

    puVar5[0x4a] = puVar7[2];

    puVar5[0x4b] = puVar7[3];

    puVar7 = 0x06060D74;

    puVar3 = 0x06060D74 + 1;

    puVar5[0x4c] = *0x06060D74;

    puVar5[0x4d] = *puVar3;

    puVar5[0x4e] = puVar7[2];

    puVar5[0x4f] = puVar7[3];

    puVar7 = 0x06060D6C;

    puVar3 = 0x06060D6C + 1;

    puVar5[0x50] = *0x06060D6C;

    puVar5[0x51] = *puVar3;

    puVar5[0x52] = puVar7[2];

    puVar5[0x53] = puVar7[3];

  }

  return puVar2;

}
