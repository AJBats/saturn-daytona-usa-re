extern int PTR_DAT_06026cd4;

extern int PTR_DAT_06026cd4;

void FUN_06026ca4(param_1, param_2)
    int param_1;
    short param_2;
{

  char local_c;

  char uStack_b;

  local_c = *(char *)(param_1 + param_2);

  uStack_b = 0;

  (*(void(*)())0x060283E0)(0xc,((int)param_2 + (int)PTR_DAT_06026cd4) * 2,0x0000E000,&local_c);

  return;

}
