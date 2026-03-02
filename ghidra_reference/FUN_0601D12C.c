extern int DAT_0601d18c;

extern int DAT_0601d18e;

extern int DAT_0601d24c;

extern int DAT_0601d24e;

extern int DAT_0601d2c6;

extern int PTR_DAT_0601d250;

extern int PTR_DAT_0601d250;

extern int PTR_DAT_0601d2c8;

extern int PTR_DAT_0601d2c8;

void FUN_0601d12c()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x0608602C;

  iVar2 = *(int *)0x0608602C;

  if ((iVar2 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d18c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 1) && ((*(unsigned short *)0x06063D9A & DAT_0601d18c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 2) && ((*(unsigned short *)0x06063D9A & DAT_0601d18e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 3) && ((*(unsigned short *)0x06063D9A & DAT_0601d24c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 4) && ((*(unsigned short *)0x06063D9A & DAT_0601d24e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 5) &&

          (((unsigned int)*(unsigned short *)0x06063D9A & (unsigned int)0x00008000) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 6) && ((*(unsigned short *)0x06063D9A & DAT_0601d24e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 7) &&

          (((unsigned int)*(unsigned short *)0x06063D9A & (unsigned int)0x00008000) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 8) &&

          ((*(unsigned short *)0x06063D9A & PTR_DAT_0601d250) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 9) && ((*(unsigned short *)0x06063D9A & DAT_0601d2c6) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 10) &&

          ((*(unsigned short *)0x06063D9A & PTR_DAT_0601d2c8) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  if ((*(int *)puVar1 == iVar2) && (*(short *)0x06063D9A != 0)) {

    *(int *)puVar1 = 0;

  }

  if (*(int *)puVar1 == 0xb) {

    *(int *)0x06086030 = 1;

    *(int *)puVar1 = 0;

    (*(int(*)())0x0601D5F4)(0,0xAE1146FF);

    return;

  }

  return;

}
