extern int DAT_060376a4;

extern int DAT_060376a6;

extern int DAT_060376a8;

extern int DAT_060378f8;

extern int DAT_060378fa;

extern int DAT_060378fc;

extern int DAT_060378fe;

extern int DAT_06037b10;

extern int DAT_06037c8e;

extern int DAT_06037c90;

extern int DAT_06037c92;

extern int DAT_06037c94;

extern int DAT_06037c96;

extern int PTR_DAT_06037900;

extern int PTR_DAT_06037900;

extern int PTR_DAT_06037c98;

extern int PTR_DAT_06037c98;

void FUN_06037660(param_1, param_2)
    unsigned short *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  unsigned short *extraout_r3;

  unsigned short uVar8;

  unsigned short uVar11;

  char *puVar9;

  unsigned short *puVar10;

  char *puVar12;

  unsigned short local_38;

  char *puStack_2c;

  puVar12 = 0x060A3D88;

  puVar4 = 0x060A3DB0;

  uVar3 = DAT_060376a6;

  uVar2 = DAT_060376a4;

  puStack_2c = (char *)0x0;

  local_38 = (unsigned short)param_2[8];

  uVar11 = local_38 << 0xe & DAT_060376a8;

  puVar9 = (char *)(unsigned int)uVar11;

  uVar5 = (unsigned int)param_1 & 0xffff;

  uVar6 = (unsigned short)0x00008000;

  uVar7 = (unsigned short)0x0000BFFF;

  if (uVar5 == 1) {

    bVar1 = *param_2;

    *(unsigned short *)(0x060A3D88 + 0x20) =

         *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFEF;

    *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 4;

    uVar8 = (unsigned short)param_2[1] << 8 & DAT_06037c8e;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FEFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar8;

    *(short *)(puVar4 + 0x10) = *(short *)(param_2 + 10);

    bVar1 = param_2[2];

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar2;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | (unsigned short)bVar1 << 0xf & uVar6;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar7;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | uVar11;

    uVar6 = (unsigned short)param_2[3] << 8 & DAT_06037c90;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FCFF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[7] << 10 & DAT_06037c92;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000F3FF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[4] << 10 & DAT_06037c94;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FBFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[5] << 0xc & DAT_06037c96;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x00008FFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037c98;

    param_1 = (unsigned short *)(unsigned int)uVar6;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FDFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    puVar12 = (void *)0x00000008;

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x01')) {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

      puStack_2c = puVar4 + 0x38;

    }

    else if (*(int *)0x060A4C58 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

    }

    else if (*(int *)0x060A4C59 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

    }

  }

  else if (uVar5 == 2) {

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x02')) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFDF;

      if (*param_2 != 0) {

        *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | 0x20;

      }

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

      puVar12 = (void *)0x00000008;

    }

  }

  else {

    if (uVar5 == 4) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | bVar1 & 1;

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[4];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF3;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 3) << 2;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      bVar1 = param_2[6];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FFF0;

      puVar9 = puVar4 + 0x18;

    }

    else if (uVar5 == 8) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FDFD;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | DAT_060378f8;

      uVar8 = (unsigned short)param_2[1] << 8 & DAT_060378fa;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FEFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar8;

      *(short *)(puVar4 + 10) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar2;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar7;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFF3;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 2;

      uVar6 = (unsigned short)param_2[4] << 10 & DAT_060378fc;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000F3FF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[5] << 0xc & DAT_060378fe;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000CFFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037900;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FDFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FF0F;

      puVar9 = puVar4 + 0x1c;

    }

    else if (uVar5 == 0x10) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFB;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 2;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | bVar1 & 1;

      *(short *)(puVar4 + 0xc) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar2;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar7;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFCF;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 4;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000F0FF;

      puVar9 = puVar4 + 0x20;

    }

    else {

      if (uVar5 != 0x20) goto LAB_06037e88;

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFF7;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 3;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFEF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 4;

      *(short *)(puVar4 + 0xe) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar2;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar7;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FF3F;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 6;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFDF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 5;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & DAT_06037b10;

      puVar9 = puVar4 + 0x24;

    }

    param_1 = (unsigned short *)(puVar4 + 0x14);

    puVar12 = (void *)0x00000002;

  }

LAB_06037e88:

  if (param_2[6] == 1) {

    uVar6 = (*(int(*)())0x06035280)();

  }

  else {

    (*(int(*)())0x06035F44)();

    uVar6 = (*(int(*)())0x06035280)();

  }

  *param_1 = *param_1 | uVar6;

  uVar6 = 0;

  if (((unsigned int)puVar12 & 0xffff) != 0) {

    do {

      uVar7 = (*(int(*)())0x06035F44)();

      *extraout_r3 = uVar7 & 0x3f;

      uVar7 = (*(int(*)())0x06035F44)();

      *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) =

           *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) | (uVar7 & 0x3f) << 8 & uVar3;

      uVar6 = uVar6 + 1;

    } while ((unsigned int)uVar6 < ((unsigned int)puVar12 & 0xffff));

  }

  if (puStack_2c != (char *)0x0) {

    *param_1 = *param_1 & 0xf;

    *param_1 = *param_1 | *param_1 << 4;

    uVar5 = 0;

    if (((unsigned int)puVar12 & 0xffff) != 0) {

      do {

        puVar10 = (unsigned short *)(puStack_2c + ((uVar5 & 0xffff) << 1));

        uVar6 = (*(int(*)())0x06035F44)();

        *puVar10 = uVar6 & 0x3f;

        uVar6 = (*(int(*)())0x06035F44)();

        uVar5 = uVar5 + 1;

        *puVar10 = *puVar10 | (uVar6 & 0x3f) << 8 & uVar3;

      } while ((uVar5 & 0xffff) < ((unsigned int)puVar12 & 0xffff));

    }

  }

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}
