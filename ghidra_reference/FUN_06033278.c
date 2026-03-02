long long FUN_06033278(param_1, param_2)
    int param_1;
    int param_2;
{

  int in_r0;

  int in_r1;

  char *puVar1;

  unsigned int uVar2;

  int in_r2;

  char *puVar3;

  unsigned int uVar4;

  unsigned char bVar5;

  if (param_2 != 0) {

    puVar1 = 0x00240000 + in_r1;

    puVar3 = 0x001C0000 + in_r2;

    if (((((int)0x00040000 <= (int)puVar1) && ((int)0x00040000 <= (int)puVar3)) &&

        ((int)puVar1 <= (int)0x00460000)) && ((int)puVar3 <= (int)0x00360000)) {

      if (((unsigned int)0x00008000 & (unsigned int)puVar3) != 0) {

        puVar3 = puVar3 + (int)0x00010000;

      }

      if (((unsigned int)0x00008000 & (unsigned int)puVar1) != 0) {

        puVar1 = puVar1 + (int)0x00010000;

      }

      uVar4 = (unsigned int)(short)((unsigned int)puVar3 >> 0x10);

      uVar2 = (unsigned int)(short)((unsigned int)puVar1 >> 0x10);

      bVar5 = 0xf0;

      if ((uVar2 & 1) == 0) {

        bVar5 = 0xf;

        param_2 = param_2 << 4;

      }

      0x060629AC

      [(uVar4 & 0xf8) * 0x24 + (uVar4 & 7) << 2 + (uVar2 & 0xf8) << 2 + ((uVar2 & 7) >> 1)] =

           0x060629AC

           [(uVar4 & 0xf8) * 0x24 + (uVar4 & 7) << 2 + (uVar2 & 0xf8) << 2 + ((uVar2 & 7) >> 1)] &

           bVar5 | (unsigned char)param_2;

    }

  }

  return CONCAT44(in_r1,in_r0);

}
