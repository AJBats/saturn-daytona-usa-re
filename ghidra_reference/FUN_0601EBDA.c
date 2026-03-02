extern int PTR_DAT_0601ebf0;

extern int PTR_DAT_0601ebf0;

char * FUN_0601ebda()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  char *puVar6;

  int *puVar7;

  char *puVar8;

  int *puVar9;

  char *puVar10;

  iVar5 = 0xf0;

  puVar2 = (char *)(unsigned int)(unsigned char)*(int *)0x06087080;

  if (puVar2 == (char *)0x0) {

    puVar3 = (char *)(*(int *)0x0605E098 + 0x10);

    puVar9 = (int *)(0x0605DD6C + 0x48);

    puVar7 = (int *)0x0605DD6C;

    do {

      puVar10 = (char *)*puVar7;

      puVar2 = puVar10;

      do {

        *puVar2 = *puVar3;

        puVar2[1] = puVar3[1];

        puVar2[2] = puVar3[2];

        puVar2[3] = puVar3[3];

        puVar2[4] = puVar3[4];

        puVar2[5] = puVar3[5];

        puVar2[6] = puVar3[6];

        puVar2[7] = puVar3[7];

        puVar2[8] = puVar3[8];

        puVar6 = puVar2 + 0xc;

        puVar2[9] = puVar3[9];

        puVar4 = puVar3 + 0xb;

        puVar2[10] = puVar3[10];

        puVar3 = puVar3 + 0xc;

        puVar2[0xb] = *puVar4;

        puVar2 = puVar6;

      } while (puVar6 < puVar10 + iVar5);

      puVar7 = puVar7 + 2;

    } while (puVar7 < puVar9);

    puVar9 = (int *)(0x0605DE24 + 0x18);

    puVar7 = (int *)0x0605DE24;

    do {

      puVar2 = (char *)*puVar7;

      puVar7 = puVar7 + 1;

      *puVar2 = *puVar3;

      puVar2[1] = puVar3[1];

      puVar2[2] = puVar3[2];

      puVar2[3] = puVar3[3];

      puVar2[4] = puVar3[4];

      puVar2[5] = puVar3[5];

      puVar10 = puVar3 + 7;

      puVar2[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar2[7] = *puVar10;

    } while (puVar7 < puVar9);

    puVar10 = 0x0605DDB4 + 0x20;

    puVar8 = 0x0605DDB4;

    do {

      *puVar8 = *puVar3;

      puVar8[1] = puVar3[1];

      puVar8[2] = puVar3[2];

      puVar8[3] = puVar3[3];

      puVar6 = puVar8 + 8;

      puVar8[4] = puVar3[4];

      puVar8[5] = puVar3[5];

      puVar4 = puVar3 + 7;

      puVar8[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar8[7] = *puVar4;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    puVar10 = 0x0605DDD4 + 0x20;

    puVar8 = 0x0605DDD4;

    do {

      *puVar8 = *puVar3;

      puVar8[1] = puVar3[1];

      puVar8[2] = puVar3[2];

      puVar8[3] = puVar3[3];

      puVar6 = puVar8 + 8;

      puVar8[4] = puVar3[4];

      puVar8[5] = puVar3[5];

      puVar4 = puVar3 + 7;

      puVar8[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar8[7] = *puVar4;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    puVar10 = 0x0605DE40 + 0x24;

    puVar8 = 0x0605DE40;

    do {

      puVar4 = puVar3;

      *puVar8 = *puVar4;

      puVar8[1] = puVar4[1];

      puVar8[2] = puVar4[2];

      puVar8[3] = puVar4[3];

      puVar8[4] = puVar4[4];

      puVar8[5] = puVar4[5];

      puVar8[6] = puVar4[6];

      puVar8[7] = puVar4[7];

      puVar8[8] = puVar4[8];

      puVar8[9] = puVar4[9];

      puVar6 = puVar8 + 0xc;

      puVar8[10] = puVar4[10];

      puVar8[0xb] = puVar4[0xb];

      puVar1 = 0x0605AD00;

      puVar3 = puVar4 + 0xc;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    *(int *)0x0605AD00 = puVar4[0xc];

    puVar1[1] = puVar4[0xd];

    puVar1[2] = puVar4[0xe];

    puVar1[3] = puVar4[0xf];

    puVar8 = 0x0605AD04;

    *(int *)0x0605AD04 = puVar4[0x10];

    puVar8[1] = puVar4[0x11];

    puVar8[2] = puVar4[0x12];

    puVar8[3] = puVar4[0x13];

    puVar8 = 0x0605AD0C;

    *(int *)0x0605AD0C = puVar4[0x14];

    puVar8[1] = puVar4[0x15];

    puVar8[2] = puVar4[0x16];

    puVar8[3] = puVar4[0x17];

    *(int *)0x0605AB16 = puVar4[0x18];

    *(int *)0x0605AB17 = puVar4[0x19];

    *(int *)0x0605D240 = puVar4[0x1a];

    *(int *)0x0605D241 = puVar4[0x1b];

    puVar8 = 0x06060D44;

    *(int *)0x06060D44 = puVar4[0x1c];

    puVar8[1] = puVar4[0x1d];

    puVar8 = 0x06060D46;

    *(int *)0x06060D46 = puVar4[0x1e];

    puVar8[1] = puVar4[0x1f];

    puVar8 = 0x06060D40;

    *(int *)0x06060D40 = puVar4[0x20];

    puVar8[1] = puVar4[0x21];

    puVar8 = 0x06060D42;

    *(int *)0x06060D42 = puVar4[0x22];

    puVar8[1] = puVar4[0x23];

    puVar8 = 0x06060D48;

    *(int *)0x06060D48 = puVar4[0x24];

    puVar8[1] = puVar4[0x25];

    puVar8 = 0x06060D4A;

    *(int *)0x06060D4A = puVar4[0x26];

    puVar8[1] = puVar4[0x27];

    puVar8 = 0x06060D4C;

    *(int *)0x06060D4C = puVar4[0x28];

    puVar8[1] = puVar4[0x29];

    puVar8 = 0x06060D4E;

    *(int *)0x06060D4E = puVar4[0x2a];

    puVar8[1] = puVar4[0x2b];

    puVar8 = 0x06060D54;

    *(int *)0x06060D54 = puVar4[0x2c];

    puVar8[1] = puVar4[0x2d];

    puVar8[2] = puVar4[0x2e];

    puVar8[3] = puVar4[0x2f];

    puVar8 = 0x06060D58;

    *(int *)0x06060D58 = puVar4[0x30];

    puVar8[1] = puVar4[0x31];

    puVar8[2] = puVar4[0x32];

    puVar8[3] = puVar4[0x33];

    puVar8 = 0x06060D50;

    *(int *)0x06060D50 = puVar4[0x34];

    puVar8[1] = puVar4[0x35];

    puVar8[2] = puVar4[0x36];

    puVar8[3] = puVar4[0x37];

    puVar8 = 0x06060D60;

    *(int *)0x06060D60 = puVar4[0x38];

    puVar8[1] = puVar4[0x39];

    puVar8 = 0x06060D62;

    *(int *)0x06060D62 = puVar4[0x3a];

    puVar8[1] = puVar4[0x3b];

    puVar3 = 0x06060D5C + 1;

    *(int *)0x06060D5C = puVar4[0x3c];

    *puVar3 = puVar4[0x3d];

    puVar8 = 0x06060D5E;

    *(int *)0x06060D5E = puVar4[0x3e];

    puVar8[1] = puVar4[0x3f];

    puVar8 = 0x06060D64;

    *(int *)0x06060D64 = puVar4[0x40];

    puVar8[1] = puVar4[0x41];

    puVar8 = 0x06060D66;

    *(int *)0x06060D66 = puVar4[0x42];

    puVar8[1] = puVar4[0x43];

    puVar8 = 0x06060D68;

    *(int *)0x06060D68 = puVar4[0x44];

    puVar8[1] = puVar4[0x45];

    puVar8 = 0x06060D6A;

    *(int *)0x06060D6A = puVar4[0x46];

    puVar8[1] = puVar4[0x47];

    puVar8 = 0x06060D70;

    *(int *)0x06060D70 = puVar4[0x48];

    puVar8[1] = puVar4[0x49];

    puVar8[2] = puVar4[0x4a];

    puVar8[3] = puVar4[0x4b];

    puVar8 = 0x06060D74;

    *(int *)0x06060D74 = puVar4[0x4c];

    puVar8[1] = puVar4[0x4d];

    puVar8[2] = puVar4[0x4e];

    puVar8[3] = puVar4[0x4f];

    puVar8 = 0x06060D6C;

    *(int *)0x06060D6C = puVar4[0x50];

    puVar8[1] = puVar4[0x51];

    puVar8[2] = puVar4[0x52];

    puVar8[3] = puVar4[0x53];

  }

  return puVar2;

}
