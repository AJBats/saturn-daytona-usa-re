extern int DAT_06020b46;

extern int PTR_DAT_06020b48;

extern int PTR_DAT_06020b48;

int FUN_06020b20()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  int iVar5;

  puVar2 = 0x25F800A4;

  puVar1 = 0x25E5F800;

  iVar5 = 0x100;

  *(int *)0x25F800A4 = 0x12F2FC00;

  *(short *)(puVar2 + -10) = PTR_DAT_06020b48;

  uVar4 = 0;

  do {

    iVar3 = (uVar4 & 0xffff) << 2;

    uVar4 = uVar4 + 1;

    *(int *)(puVar1 + iVar3) = 0;

  } while ((int)(uVar4 & 0xffff) < iVar5);

  return iVar3;

}
