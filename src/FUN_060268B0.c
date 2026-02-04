extern int DAT_06026922;

extern void FUN_06026ca4();

void FUN_060268b0(param_1)
    short param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  puVar5 = 0x06061238;

  puVar4 = 0x0606123A;

  puVar3 = 0x0607864C;

  puVar2 = 0x0606123C;

  puVar1 = 0x060283E0;

  iVar7 = (int)DAT_06026922;

  if (param_1 == 0) {

    iVar6 = *(int *)0x0607EAD8;

    if (iVar6 == 0) {

      if (*(short *)0x06061238 < 0x36) {

        if ((unsigned int)(*(short *)(0x060597B8 + *(short *)0x06061238 * 2) * 3) <=

            *(unsigned int *)0x0607864C) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x36) &&

              ((unsigned int)(*(short *)(0x060597B8 + *(short *)0x06061238 * 2) * 3) <=

               *(unsigned int *)0x0607864C)) {

        (*0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611FC + (char)0x060591BA[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060597B8 + (*(short *)puVar5 + -1) * 2) +

                        (int)(char)0x060595D8

                                   [(int)*(short *)puVar4 +

                                    (char)0x060591BA[*(short *)puVar5 + -1] * 0x20]) * 3) <=

                 *(unsigned int *)puVar3 &&

                ((char)0x060595D8

                       [(int)*(short *)puVar4 + (char)0x060591BA[*(short *)puVar5 + -1] * 0x20

                       ] != -1)) && (*(short *)puVar4 < 0x20))) {

          FUN_06026ca4(*(int *)

                        (0x060611FC + (char)0x060591BA[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 1) {

      if (*(short *)0x06061238 < 0x3a) {

        if ((unsigned int)(*(short *)(0x060591F0 + *(short *)0x06061238 * 2) * 3) <=

            *(unsigned int *)0x0607864C) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x3a) &&

              ((unsigned int)(*(short *)(0x060591F0 + *(short *)0x06061238 * 2) * 3) <=

               *(unsigned int *)0x0607864C)) {

        (*0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x0606119C + (char)0x0605914C[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060591F0 + (*(short *)puVar5 + -1) * 2) +

                        (int)(char)0x06059266

                                   [(int)*(short *)puVar4 +

                                    (int)(short)((char)0x0605914C[*(short *)puVar5 + -1] *

                                                0x24)]) * 3) <= *(unsigned int *)puVar3 &&

                ((char)0x06059266

                       [(int)*(short *)puVar4 +

                        (int)(short)((char)0x0605914C[*(short *)puVar5 + -1] * 0x24)] != -1))

               && (*(short *)puVar4 < 0x24))) {

          FUN_06026ca4(*(int *)

                        (0x0606119C + (char)0x0605914C[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 2) {

      if (*(short *)0x06061238 < 0x34) {

        if ((unsigned int)(*(short *)(0x0605956E + *(short *)0x06061238 * 2) * 3) <=

            *(unsigned int *)0x0607864C) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x34) &&

              ((unsigned int)(*(short *)(0x0605956E + *(short *)0x06061238 * 2) * 3) <=

               *(unsigned int *)0x0607864C)) {

        (*0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611DC + (char)0x06059186[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x0605956E + (*(short *)puVar5 + -1) * 2) +

                        (int)(char)0x060594A6

                                   [(int)*(short *)puVar4 +

                                    (((int)(char)0x06059186[*(short *)puVar5 + -1] & 0xffffU)

                                     * 0x19 & 0xff)]) * 3) <= *(unsigned int *)puVar3 &&

                ((char)0x060594A6

                       [(int)*(short *)puVar4 +

                        (((int)(char)0x06059186[*(short *)puVar5 + -1] & 0xffffU) * 0x19 &

                        0xff)] != -1)) && (*(short *)puVar4 < 0x19))) {

          FUN_06026ca4(*(int *)

                        (0x060611DC + (char)0x06059186[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    if (*(short *)0x0606123E != 0) {

      *(int *)puVar3 = 0;

      *(short *)0x0606123E = 0;

    }

  }

  else {

    *(short *)0x0606123C = 0;

    *(short *)puVar4 = 0;

    *(short *)puVar5 = 0;

    *(short *)0x0606123E = 0;

    *(int *)puVar3 = 0;

  }

  return;

}
