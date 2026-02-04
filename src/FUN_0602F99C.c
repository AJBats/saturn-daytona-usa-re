extern int DAT_0602fb3c;

extern int DAT_0602fba8;

extern int DAT_0602fbca;

extern int DAT_0602fc6e;

extern int DAT_0602fc70;

extern int DAT_0602fc72;

extern int DAT_0602fc74;

extern int DAT_0602fc76;

extern int DAT_0602fc9c;

extern int DAT_0602fc9e;

extern int DAT_0602fd1a;

extern int PTR_DAT_0602fa60;

extern int PTR_DAT_0602fa60;

extern int PTR_DAT_0602fb10;

extern int PTR_DAT_0602fb10;

extern int PTR_DAT_0602fc14;

extern int PTR_DAT_0602fc14;

extern int PTR_DAT_0602fcb8;

extern int PTR_DAT_0602fcb8;

extern int PTR_DAT_0602fcdc;

extern int PTR_DAT_0602fcdc;

unsigned int FUN_0602f99c()
{

  int uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  char cVar6;

  unsigned int *puVar7;

  int iVar8;

  int uVar9;

  int iVar10;

  short *psVar11;

  unsigned int *puVar12;

  puVar3 = 0x0602FD98;

  puVar2 = 0x0601D5F4;

  puVar12 = *(unsigned int **)0x0607E944;

  if (((char)*0x0602FD98 != 0) &&

     (iVar4 = (char)*0x0602FD98 + -1, *0x0602FD98 = (char)iVar4, iVar4 == 2)) {

    (*puVar2)(0,0xAE1103FF);

  }

  if (((char)puVar3[1] != 0) && (iVar4 = (char)puVar3[1] + -1, puVar3[1] = (char)iVar4, iVar4 == 2))

  {

    (*puVar2)(0,0xAE1104FF);

  }

  if (((char)puVar3[2] != 0) && (iVar4 = (char)puVar3[2] + -1, puVar3[2] = (char)iVar4, iVar4 == 2))

  {

    (*puVar2)(0,0xAE1104FF);

  }

  uVar1 = 0xAE1112FF;

  uVar9 = 0xAE1110FF;

  if ((char)*0x0602FD9B == 0) {

    if ((char)0x0602FD9B[1] == 0) goto LAB_0602fa42;

    iVar4 = (char)0x0602FD9B[1] + -1;

    0x0602FD9B[1] = (char)iVar4;

    uVar9 = uVar1;

    uVar1 = 0xAE1113FF;

  }

  else {

    iVar4 = (char)*0x0602FD9B + -1;

    *0x0602FD9B = (char)iVar4;

    uVar1 = 0xAE1111FF;

  }

  if ((iVar4 == 4) || (uVar9 = uVar1, iVar4 == 0)) {

    (*puVar2)(0,uVar9);

  }

LAB_0602fa42:

  puVar3 = 0x0602FD9D;

  uVar5 = *(unsigned int *)0x0607EAD8;

  if (uVar5 == 0) {

    cVar6 = *0x0602FD9D;

    uVar5 = (unsigned int)(char)0x0602FD9D[1];

    if ((int)uVar5 < 1) {

      if ((*(int *)((int)PTR_DAT_0602fa60 + (int)puVar12) == 0) ||

         (0x1e < *(int *)((int)PTR_DAT_0602fa60 + (int)puVar12))) {

        if (cVar6 != '\0') {

          uVar9 = 0xAE111AFF;

          if (*0x0605D241 != '\0') {

            uVar9 = 0xAE113EFF;

          }

          uVar5 = (*puVar2)(0,uVar9);

          cVar6 = '\0';

        }

      }

      else {

        (*puVar2)(0,0xAE1119FF);

        uVar5 = 0x14;

        cVar6 = '\x01';

      }

    }

    else {

      uVar5 = uVar5 - 1;

    }

    *puVar3 = cVar6;

    puVar3[1] = (char)uVar5;

  }

  puVar3 = 0x06086054;

  if (*(short *)0x06086054 == 0) {

    uVar5 = *puVar12;

    if ((uVar5 & 8) == 0) {

      if (*(int *)0x0607EAE0 == 0) {

        iVar8 = *(int *)0x0607EA98 + -1;

        puVar7 = *(unsigned int **)0x0607E948;

        iVar4 = 0;

        iVar10 = 0;

        while( true ) {

          for (; (0x01800000 == (char *)(*puVar7 & (unsigned int)0x01800000) ||

                 (0x01400000 == (char *)(*puVar7 & (unsigned int)0x01400000)));

              puVar7 = (unsigned int *)((int)puVar7 + (int)DAT_0602fb3c)) {

            iVar4 = iVar4 + 1;

            if (iVar4 == 2) {

              if (*0x0602FDA1 == '\0') {

                if ((int)puVar7[3] <= (int)puVar12[3]) {

                  *0x0602FDA1 = 10;

                  uVar5 = (*puVar2)(0,0xAE1135FF);

                  *(short *)puVar3 = 0x3c;

                  return uVar5;

                }

              }

              else {

                *0x0602FDA1 = *0x0602FDA1 + -1;

              }

              goto LAB_0602fbb4;

            }

            iVar8 = iVar8 + -1;

            if (iVar8 == 0) goto LAB_0602fb6c;

          }

          if (0x02C00000 == (char *)(*puVar7 & (unsigned int)0x02C00000)) {

            iVar10 = iVar10 + 1;

          }

          iVar8 = iVar8 + -1;

          if (iVar8 == 0) break;

          puVar7 = (unsigned int *)((int)puVar7 + (int)PTR_DAT_0602fb10);

        }

LAB_0602fb6c:

        if (0 < iVar10) {

          if (*0x0602FDA0 == '\0') {

            if (-1 < (int)(puVar7[3] - puVar12[3])) {

              uVar9 = 0xAE113AFF;

              if ((int)(unsigned int)DAT_0602fba8 <= (int)(puVar7[3] - puVar12[3])) {

                uVar9 = 0xAE1130FF;

              }

              *0x0602FDA0 = 3;

              uVar5 = (*puVar2)(0,uVar9);

              *(short *)puVar3 = 0x3c;

              return uVar5;

            }

          }

          else {

            *0x0602FDA0 = *0x0602FDA0 + -1;

          }

        }

      }

LAB_0602fbb4:

      if (*(int *)((int)puVar12 + (int)DAT_0602fbca) == 1) {

        uVar5 = (*puVar2)(0,0xAE1132FF);

        *(short *)puVar3 = 0x3c;

      }

      else if ((int)(char)*0x0602FD9B + (int)(char)0x0602FD9B[1]

               == 1) {

        uVar5 = (*puVar2)(0,0xAE1137FF);

        *(short *)puVar3 = 0x3c;

      }

      else {

        iVar4 = (int)*(short *)(0x0602FD54 + *(int *)0x0607EAD8 * 4);

        for (psVar11 = (short *)(0x0602FD60 +

                                *(short *)((int)(0x0602FD54 + *(int *)0x0607EAD8 * 4) +

                                          2));

            *(int *)((int)puVar12 + (int)PTR_DAT_0602fc14) != (int)*psVar11;

            psVar11 = psVar11 + 2) {

          iVar4 = iVar4 + -1;

          if (iVar4 == 0) goto LAB_0602fcc0;

        }

        iVar4 = (int)psVar11[1];

        if (iVar4 == 2) {

          if (((int)DAT_0602fc9c <= (int)puVar12[2]) &&

             (0x17ff < *(int *)((int)puVar12 + (int)DAT_0602fc9e))) {

            uVar5 = (*puVar2)(0,0xAE1136FF);

            *(short *)puVar3 = 0x3c;

            return uVar5;

          }

        }

        else if (iVar4 == 3) {

          if ((int)PTR_DAT_0602fcb8 <= (int)puVar12[2]) {

            uVar5 = (*puVar2)(0,0xAE112CFF);

            *(short *)puVar3 = 0x3c;

            return uVar5;

          }

        }

        else if ((*(int *)((int)DAT_0602fc74 + (int)puVar12) +

                  *(int *)((int)DAT_0602fc72 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc70 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc6e + (int)puVar12) == 0) &&

                ((*(unsigned int *)((int)DAT_0602fc76 + (int)puVar12) & 1) != 0)) {

          uVar5 = (*puVar2)(0,*(int *)(0x0602FD30 + iVar4 * 4));

          *(short *)puVar3 = 0x3c;

          return uVar5;

        }

LAB_0602fcc0:

        if ((*(int *)((int)puVar12 + (int)PTR_DAT_0602fcdc) == 1) &&

           ((int)0x00028000 < (int)puVar12[3])) {

          uVar5 = (*puVar2)(0,0xAE1131FF);

          *(short *)puVar3 = 0x3c;

        }

        else {

          uVar5 = *(unsigned int *)0x0607EAD8;

          if ((uVar5 == 1) &&

             (((*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe0 ||

               (*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe1)) &&

              (uVar5 = puVar12[5], 0xa0000 < (int)uVar5)))) {

            uVar5 = (*puVar2)(0,0xAE112EFF);

            *(short *)puVar3 = 0x3c;

          }

        }

      }

    }

  }

  else {

    *(short *)0x06086054 = *(short *)0x06086054 + -1;

  }

  return uVar5;

}
