extern int FUN_06034d5e();

void FUN_06034d1c(param_1)
    int param_1;
{

  char local_10;

  char auStack_f [3];

  char uStack_c;

  char auStack_b [7];

  (*(void(*)())0x06035E90)(&local_10);

  local_10 = 0x10;

  FUN_06034d5e(param_1,auStack_f);

  uStack_c = *(char *)(param_1 + 0x10);

  FUN_06034d5e(param_1 + 8,auStack_b);

  (*(void(*)())0x06035EC8)(0,&local_10);

  return;

}
