extern int DAT_0602f464;

extern int DAT_0602f466;

extern int PTR_DAT_0602f468;

extern int PTR_DAT_0602f468;

void FUN_0602f3ec()
{

  int in_r0;

  int iVar1;

  char *puVar2;

  char *puVar3;

  iVar1 = (int)(short)((unsigned long long)

                       ((long long)(int)0x00480000 * (long long)*(int *)(in_r0 + 0xc)) >> 0x20);

  if (iVar1 < 1) {

    iVar1 = 0;

  }

  else if (0x00000158 <= iVar1) {

    iVar1 = 0x00000158;

  }

  *(int *)(in_r0 + 8) = iVar1;

  puVar2 = (char *)((unsigned int)(iVar1 << 8) >> 2);

  puVar3 = 0x00000000;

  if ((((int)0x00000000 <= (int)puVar2) &&

      (puVar3 = 0x00002AAA, (int)puVar2 <= (int)0x00002AAA)) &&

     (puVar3 = puVar2, (int)0x00000AAA < (int)puVar2)) {

    puVar3 = 0x00000AAA;

  }

  *(int *)(DAT_0602f464 + in_r0) = *(int *)(DAT_0602f464 + in_r0) - (int)puVar3;

  if (*(int *)(DAT_0602f466 + in_r0) != 0) {

    puVar3 = 0x00002AAA;

  }

  *(int *)(PTR_DAT_0602f468 + in_r0) = *(int *)(PTR_DAT_0602f468 + in_r0) - (int)puVar3;

  return;

}
