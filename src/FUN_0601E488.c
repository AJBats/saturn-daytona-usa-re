void FUN_0601e488(param_1)
    unsigned short param_1;
{

  char *puVar1;

  puVar1 = 0x06087094 + (unsigned int)param_1 * 0x20;

  (**(void **)(*(int *)0x06000354 + 4))(*(short *)(puVar1 + 0x1c),0);

  (**(void **)(*(int *)0x06000354 + 0xc))

            (*(short *)(puVar1 + 0x1c),

             *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*0x060877D8 * 4),puVar1);

  return;

}
