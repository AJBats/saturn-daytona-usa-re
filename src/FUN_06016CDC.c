extern void FUN_06016dd8();

void FUN_06016cdc(param_1, param_2)
    unsigned char param_1;
    unsigned char param_2;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar1 = 0x06084FC8;

  0x06084FC8[(short)((unsigned short)param_1 * 0x44) + 1] = 0;

  iVar3 = 0;

  if (((unsigned int)(*0x06085F89 == '\0') & *(unsigned int *)0x0607EBF4) != 0) {

    iVar3 = 0x28;

    *(char **)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 0x2c) = 0x00008000;

  }

  puVar2 = 0x0605BB74;

  iVar3 = (unsigned int)param_2 * 5 + iVar3;

  *(int *)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 4) =

       (int)*(short *)(0x0605BB74 + iVar3 * 2) << 0x10;

  *(int *)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 8) =

       (int)*(short *)(puVar2 + (iVar3 + 1) * 2) << 0x10;

  *(int *)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 0xc) =

       (int)*(short *)(puVar2 + (iVar3 + 2) * 2) << 0x10;

  *(int *)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 0x10) =

       (int)*(short *)(puVar2 + (iVar3 + 3) * 2) << 0x10;

  *(int *)(puVar1 + (short)((unsigned short)param_1 * 0x44) + 0x34) =

       (int)*(short *)(puVar2 + (iVar3 + 4) * 2) << 0x10;

  FUN_06016dd8(param_1);

  puVar1 = 0x06085490;

  *(unsigned short *)(0x06085490 + (short)((unsigned short)param_1 * 0x18) + 6) = param_2 + 0x17;

  puVar1[(short)((unsigned short)param_1 * 0x18) + 4] = 1;

  puVar1[(short)((unsigned short)param_1 * 0x18) + 5] = 0x3a;

  return;

}
