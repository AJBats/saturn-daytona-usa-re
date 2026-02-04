extern int DAT_060059da;

extern int DAT_060059dc;

extern int DAT_060059de;

extern int DAT_060059e0;

extern int DAT_060059e2;

extern int DAT_060059e4;

extern int DAT_060059e6;

extern int PTR_DAT_060059e8;

extern int PTR_DAT_060059e8;

extern void FUN_06005dd4();

void FUN_06005928()
{

  int uVar1;

  int iVar2;

  int iVar3;

  char *puVar4;

  puVar4 = 0x0607EAC0;

  iVar3 = (int)DAT_060059da;

  iVar2 = *(int *)0x0607E944;

  if (((0 < *(int *)0x0607EAC0) &&

      (*(int *)0x0607EAC0 = *(int *)0x0607EAC0 + -1, *(int *)(iVar2 + DAT_060059dc) != 0

      )) && (*(int *)0x0607EBF4 == 0)) {

    if ((*(unsigned int *)puVar4 & 2) != 0) {

      puVar4 = *(char **)(iVar2 + DAT_060059de);

      if ((int)0x000927BF < (int)*(char **)(iVar2 + DAT_060059de)) {

        puVar4 = 0x000927BF;

      }

      if (puVar4 == *(char **)(iVar2 + DAT_060059e0)) {

        (*0x06028400)

                  (8,*(int *)0x06063810,iVar3,

                   *(int *)(0x06063810 + 4) + (int)DAT_060059e2,0x06063810);

      }

      else {

        (*0x06028400)

                  (8,*(int *)0x06063818,iVar3,

                   *(int *)(0x06063818 + 4) + (int)DAT_060059e2,0x06063818);

      }

      uVar1 = FUN_06005dd4(puVar4);

      (*0x060284AE)(8,(int)DAT_060059e4,0x78,uVar1);

      return;

    }

    (*0x060283E0)(8,iVar3,(int)DAT_060059e6,0x0605ACE5);

    (*0x060284AE)(8,(int)DAT_060059e4,(int)PTR_DAT_060059e8,0x0605ACDD);

    return;

  }

  return;

}
