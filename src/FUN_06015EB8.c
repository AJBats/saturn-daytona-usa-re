void FUN_06015eb8(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  unsigned short uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int *puVar6;

  unsigned int uVar7;

  puVar4 = 0x06084FC8;

  puVar3 = 0x0605B8B8;

  uVar2 = (unsigned short)param_1;

  uVar1 = uVar2 & 0xff;

  uVar7 = (unsigned int)(unsigned char)0x06084FC8[(short)(uVar1 * 0x44) + 0x41] * 4 + (param_1 & 0xff) * 0x10 &

          0xff;

  puVar6 = (int *)(0x0605B8B8 + uVar7 * 4);

  *(int *)(0x06084FC8 + (short)(uVar1 * 0x44) + 0x34) = *puVar6;

  *(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x10) = puVar6[1];

  *(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x1c) = 0;

  puVar5 = (char *)

           (*0x06035438)(*(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x10));

  if (puVar5 == 0x00100000) {

    *(int *)(puVar4 + (short)((uVar2 & 0xff) * 0x44) + 0x1c) = 1;

  }

  *(int *)(puVar4 + (short)((uVar2 & 0xff) * 0x44) + 0x38) =

       *(int *)(puVar3 + uVar7 * 4 + 8);

  *(int *)(puVar4 + (short)((uVar2 & 0xff) * 0x44) + 0x18) =

       *(int *)(puVar3 + uVar7 * 4 + 0xc);

  if (*0x06085F89 != '\0') {

    *(int *)(puVar4 + (short)((uVar2 & 0xff) * 0x44) + 0x30) =

         *(int *)((int)(puVar3 + ((param_1 & 0xff) * 0x10 + 8) * 4) + 8);

    *(int *)(puVar4 + (short)((uVar2 & 0xff) * 0x44) + 4) =

         *(int *)(puVar3 + ((param_1 & 0xff) * 0x10 + 8) * 4);

  }

  puVar4[(short)((uVar2 & 0xff) * 0x44) + 2] = puVar4[(short)((uVar2 & 0xff) * 0x44) + 2] + '\x01';

  return;

}
