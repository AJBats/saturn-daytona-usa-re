void FUN_06026dbc()
{

  int *puVar1;

  puVar1 = *(int **)0x06089EDC;

  *(int **)0x06089EDC = puVar1 + 0xc;

  puVar1[0xc] = *puVar1;

  puVar1[0xd] = puVar1[1];

  puVar1[0xe] = puVar1[2];

  puVar1[0xf] = puVar1[3];

  puVar1[0x10] = puVar1[4];

  puVar1[0x11] = puVar1[5];

  puVar1[0x12] = puVar1[6];

  puVar1[0x13] = puVar1[7];

  puVar1[0x14] = puVar1[8];

  puVar1[0x15] = puVar1[9];

  puVar1[0x16] = puVar1[10];

  puVar1[0x17] = puVar1[0xb];

  return;

}
