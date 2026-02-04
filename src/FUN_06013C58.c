extern int DAT_06013cca;

extern int DAT_06013ccc;

extern int DAT_06013cce;

extern int DAT_06013cd0;

extern int DAT_06013cd2;

extern int DAT_06013dc6;

extern int DAT_06013dc8;

extern int DAT_06013dca;

extern int DAT_06013dcc;

extern int DAT_06013dce;

extern int DAT_06013dd0;

extern int DAT_06013dd2;

extern int DAT_06013dd4;

extern int DAT_06013dd6;

extern int PTR_DAT_06013cd4;

extern int PTR_DAT_06013cd4;

int FUN_06013c58()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  puVar4 = 0x0602853E;

  puVar6 = 0x06078900;

  puVar3 = 0x06063750;

  puVar2 = 0x06028400;

  (*0x0602853E)(4);

  (*puVar4)(0xc);

  (*0x06028560)();

  (*puVar2)(8,*(int *)(puVar3 + DAT_06013cca),0,

                    *(int *)((int)(puVar3 + DAT_06013cca) + 4));

  (*puVar4)(4);

  iVar8 = (int)DAT_06013ccc;

  (*puVar2)(4,*(int *)(puVar3 + DAT_06013cce),0x18,

                    *(int *)((int)(puVar3 + DAT_06013cce) + 4) + iVar8);

  (*puVar2)(4,*(int *)(puVar3 + DAT_06013cd0),(int)DAT_06013cd2,

                    *(int *)((int)(puVar3 + DAT_06013cd0) + 4) + iVar8);

  sVar1 = DAT_06013dc6;

  if (*0x06085FF4 == '\0') {

    sVar1 = PTR_DAT_06013cd4;

  }

  (*puVar2)(4,*(int *)(puVar3 + sVar1),(int)DAT_06013dc8,

                    *(int *)((int)(puVar3 + sVar1) + 4) + iVar8);

  puVar4 = 0x06014884;

  (*0x06014884)(8,0);

  (*puVar4)(0x10,0);

  (*puVar4)(0x20,0);

  puVar4 = 0x06005DD4;

  uVar5 = (*0x06005DD4)(*(int *)(puVar6 + DAT_06013dca));

  (*0x060284AE)(0xc,(int)DAT_06013dce,(int)DAT_06013dcc,uVar5);

  puVar6 = 0x000927BF;

  if (*(char **)0x060786A4 <= 0x000927BF) {

    puVar6 = *(char **)0x060786A4;

  }

  uVar5 = (*puVar4)(puVar6);

  (*0x060284AE)(0xc,(int)DAT_06013dd0,(int)DAT_06013dcc,uVar5);

  if (*0x06085FF8 == '\0') {

    uVar5 = (*0x060283E0)

                      (0xc,(int)DAT_06013dd6,0x0000F000,0x06044A58);

    return uVar5;

  }

  (*0x06028430)(0xc,(int)DAT_06013dd2,0x30,(unsigned char)*0x06086012 + 1);

  uVar9 = (unsigned int)(unsigned char)*0x06086012;

  uVar7 = uVar9;

  if (2 < uVar9) {

    uVar7 = 3;

  }

  if (2 < uVar9) {

    uVar9 = 3;

  }

  uVar5 = (*puVar2)(0xc,*(int *)(puVar3 + (uVar9 + 0x48) * 8),(int)DAT_06013dd4,

                            *(int *)(puVar3 + (uVar7 + 0x48) * 8 + 4));

  return uVar5;

}
