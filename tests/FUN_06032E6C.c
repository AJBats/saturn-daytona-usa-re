int FUN_06032e6c()
{

  int iVar1;

  int *puVar2;

  int *puVar3;

  int iVar4;

  int uVar5;

  int unaff_r14;

  

  iVar1 = 0x000002CC;

  puVar2 = (int *)

           (*(int *)(unaff_r14 + 0x000002CC) +

           (int)(short)0x00000044 * (int)(short)*(int *)(unaff_r14 + 0x000002C4));

  puVar3 = (int *)(0x00000010 + unaff_r14);

  iVar4 = 0x00000011;

  do {

    uVar5 = *puVar2;

    puVar2 = puVar2 + 1;

    *puVar3 = uVar5;

    puVar3 = puVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return iVar1;

}
