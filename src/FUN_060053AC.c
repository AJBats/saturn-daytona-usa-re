void FUN_060053ac(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int local_24;

  int local_20;

  int uStack_1c;

  int auStack_18 [2];

  (*(void(*)())0x06026E0C)();

  *(int *)(*(int *)0x06089EDC + 0x2c) = param_3;

  if (*(int *)0x06078663 != '\0') {

    (*(void(*)())0x06026E60)(0xFFFF0000,0x00010000);

  }

  (*(void(*)())0x06026E94)(-*param_2);

  (*(void(*)())0x06026F2A)(-param_2[2]);

  (*(void(*)())0x06026EDE)(-param_2[1]);

  (*(void(*)())0x06026E2E)(-*param_1,-param_1[1],-param_1[2]);

  (*(void(*)())0x06027358)(*param_2,auStack_18,&local_24);

  (*(void(*)())0x06027358)(param_2[1],&local_20,&uStack_1c);

  puVar2 = 0x06027552;

  puVar1 = 0x06063DF8;

  uVar3 = (*(void(*)())0x06027552)(local_24,local_20);

  iVar4 = (*(void(*)())puVar2)(param_3,uVar3);

  *(int *)puVar1 = iVar4 + *param_1;

  iVar4 = (*(void(*)())puVar2)(param_3,auStack_18[0]);

  *(int *)(puVar1 + 4) = param_1[1] - iVar4;

  uVar3 = (*(void(*)())puVar2)(local_24,uStack_1c);

  iVar4 = (*(void(*)())puVar2)(param_3,uVar3);

  *(int *)(puVar1 + 8) = param_1[2] - iVar4;

  return;

}
