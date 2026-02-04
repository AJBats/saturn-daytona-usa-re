extern int DAT_06037154;

extern int DAT_06037156;

extern int DAT_0603728e;

extern int DAT_06037362;

extern int DAT_0603743a;

extern int DAT_06037532;

extern int DAT_06037534;

extern int DAT_06037536;

extern int PTR_DAT_06037158;

extern int PTR_DAT_06037158;

extern int PTR_DAT_06037364;

extern int PTR_DAT_06037364;

extern int PTR_DAT_0603743c;

extern int PTR_DAT_0603743c;

unsigned int FUN_060370e4(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned short uVar7;

  int iVar8;

  int *piVar9;

  unsigned char bVar10;

  puVar5 = 0x060A4C4C;

  puVar4 = 0x060A3E38;

  puVar3 = 0x060A3D88;

  puVar2 = 0x060A4C44;

  puVar1 = 0x0000FF00;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar2 + 4) = 0;

  *(int *)puVar5 = *param_1;

  *(int *)(puVar5 + 4) = param_1[1];

  *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & DAT_06037154;

  if (*(char *)(param_1 + 2) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | DAT_06037156;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FEFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  if (*(char *)((int)param_1 + 9) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | PTR_DAT_06037158;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FDFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  iVar8 = 0;

  bVar10 = 0;

  uVar7 = (unsigned short)puVar1;

  if (*(unsigned char *)((int)param_1 + 10) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC | (unsigned short)*(unsigned char *)((int)param_1 + 10)

    ;

    if (*(char *)((int)param_1 + 10) == '\x01') {

      bVar10 = *(int *)puVar5 == 0;

      if (!(int)bVar10) {

        *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC;

      }

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

      *(char **)puVar2 = 0x25E00000 + *(int *)puVar5;

      iVar8 = 1;

    }

  }

  else if (*(char *)((int)param_1 + 10) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(char **)(puVar2 + 4) = 0x25E00000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xb) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3 |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xb) << 2;

    if (*(char *)((int)param_1 + 0xb) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 2;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 1;

        *(char **)puVar2 = 0x25E20000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603728e;

        *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

        iVar8 = iVar8 + 1;

      }

    }

  }

  else if (*(char *)((int)param_1 + 0xb) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037362;

    *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)(param_1 + 3) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF | (unsigned short)*(unsigned char *)(param_1 + 3) << 4;

    if (*(char *)(param_1 + 3) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 3;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 2;

        *(char **)puVar2 = 0x25E40000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_06037364;

        iVar8 = iVar8 + 1;

        *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)(param_1 + 3) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603743a;

    *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xd) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xd) << 6;

    if (*(char *)((int)param_1 + 0xd) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 4;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 3;

        *(char **)puVar2 = 0x25E60000 + *(int *)puVar5;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_0603743c;

        *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)((int)param_1 + 0xd) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037532;

    *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

  }

  uVar6 = *(unsigned int *)(puVar2 + 4);

  if (uVar6 == 0) {

    if (((*(char *)((int)param_1 + 0xe) == '\x01') && (*(int *)0x060A4C44 == 0)) &&

       (iVar8 = (*(int(*)())0x0603C156)(), iVar8 == 1)) {

      uVar6 = (int)*(short *)(puVar3 + 0xe) | (unsigned int)0x00008000;

      *(short *)(puVar3 + 0xe) = (short)uVar6;

      *(char **)puVar2 = 0x25F00800;

    }

    else if ((*(int *)puVar2 == 0) || (*(int *)0x060A4C59 == '\0')) {

      uVar6 = *(unsigned int *)puVar2;

      if (uVar6 == 0) {

        if ((*(int *)puVar5 != 0) && (*(int *)0x060A4C58 != '\0')) {

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

          piVar9 = (int *)puVar5;

          uVar7 = (*(int(*)())0x06034FFC)();

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | uVar7;

          *(char **)puVar2 = 0x25E00000 + *piVar9;

        }

        uVar6 = *(unsigned int *)(puVar5 + 4);

        if ((uVar6 != 0) && (*(int *)0x060A4C59 != '\0')) {

          piVar9 = (int *)(puVar5 + 4);

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

          uVar6 = (*(int(*)())0x06034FFC)();

          uVar6 = (int)*(short *)(puVar4 + 6) | (uVar6 & 0xffff) << 8;

          *(short *)(puVar4 + 6) = (short)uVar6;

          *(char **)(puVar2 + 4) = 0x25E00000 + *piVar9;

        }

      }

    }

    else {

      if (*(int *)(puVar5 + 4) == 0) {

        *(int *)(puVar5 + 4) = *(int *)puVar5 + 0x400;

      }

      if (*(int *)puVar5 == 0) {

        *(int *)puVar5 = 0xffffffff;

      }

      *(int *)(puVar2 + 4) = *(int *)(puVar5 + 4) + *(int *)puVar2;

      *(unsigned short *)(puVar4 + 6) =

           DAT_06037536 & *(unsigned short *)(puVar4 + 6) | *(unsigned short *)(puVar4 + 6) << 8;

      uVar6 = (unsigned int)bVar10;

      if (uVar6 == 1) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFFC;

      }

      else if (uVar6 == 2) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFF3;

      }

      else if (uVar6 == 3) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFCF;

      }

      else {

        if (uVar6 != 4) {

          return uVar6;

        }

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FF3F;

      }

      *(short *)(puVar3 + 0xe) = (short)uVar6;

    }

  }

  return uVar6;

}
