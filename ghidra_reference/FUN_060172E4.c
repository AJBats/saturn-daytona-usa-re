void FUN_060172e4(param_1)
    unsigned short param_1;
{

  char *puVar1;

  puVar1 = 0x06084FC8 + (short)((param_1 & 0xff) * 0x44);

  puVar1[2] = 0;

  puVar1[1] = 0;

  *puVar1 = 0;

  *(int *)(puVar1 + 0xc) = 0;

  *(int *)(puVar1 + 8) = 0;

  *(int *)(puVar1 + 4) = 0;

  *(int *)(puVar1 + 0x18) = 0;

  *(int *)(puVar1 + 0x14) = 0;

  *(int *)(puVar1 + 0x10) = 0;

  *(int *)(puVar1 + 0x24) = 0;

  *(int *)(puVar1 + 0x20) = 0;

  *(int *)(puVar1 + 0x1c) = 0;

  *(int *)(puVar1 + 0x30) = 0;

  *(int *)(puVar1 + 0x2c) = 0;

  *(int *)(puVar1 + 0x28) = 0;

  *(int *)(puVar1 + 0x38) = 0;

  *(int *)(puVar1 + 0x34) = 0;

  puVar1[0x41] = 0;

  puVar1[0x40] = 0;

  return;

}
