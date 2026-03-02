char * FUN_0603449c()
{

  long long lVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  int uVar5;

  unsigned int uVar6;

  int uVar7;

  int uVar8;

  int unaff_r10;

  int unaff_r14;

  puVar2 = 0x06083238;

  puVar4 = (char *)(int)*(char *)(unaff_r14 + 0x00000001);

  if ((char *)(int)*(char *)(unaff_r14 + 0x00000001) == (void *)0x00000002) {

    uVar5 = *(int *)(unaff_r14 + 0x0000000C);

    uVar7 = *(int *)(unaff_r10 + 0x00000010);

    uVar8 = *(int *)(unaff_r10 + 0x00000018);

    *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);

    *(int *)(puVar2 + 4) = uVar5;

    *(int *)(puVar2 + 8) = uVar7;

    *(int *)(puVar2 + 0xc) = uVar8;

    lVar1 = (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2) *

            (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2);

    *(unsigned int *)(puVar2 + 0x10) = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    lVar1 = (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4)) *

            (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4));

    uVar6 = *(int *)(puVar2 + 0x10) +

            ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

    if ((int)uVar6 < 0) {

      iVar3 = (*(int(*)())0x06027476)(uVar6 >> 2);

      iVar3 = iVar3 << 1;

    }

    else {

      iVar3 = (*(int(*)())0x06027476)();

    }

    puVar2 = 0x00000026;

    puVar4 = 0x00080000;

    if (iVar3 < (int)0x00080000) {

      ((int *)0x00000026)[unaff_r14] = (char)0x00000001;

      puVar4 = puVar2;

    }

  }

  return puVar4;

}
