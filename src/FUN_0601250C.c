extern short DAT_06012586;

void FUN_0601250c()
{
  int idx;

  (*(int(*)())0x06026DBC)();
  (*(int(*)())0x06026E0C)();

  (*(int(*)())0x06026E2E)(*(int *)0x060788B4, *(int *)0x060788B8, *(int *)0x060788BC);

  (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2);
  (*(int(*)())0x06026EDE)(0);
  (*(int(*)())0x06026E94)(0);

  if (99 < *(int *)0x0607EBCC) {
    (*(int(*)())0x06026E94)((int)DAT_06012586);
  }

  idx = (*(int *)0x0607EAD8 + -1) << 2;

  (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + idx), *(int *)0x06063558);

  (*(int(*)())0x06031A28)(*(int *)(0x06063544 + idx), (int)*(short *)0x06089EA0, *(int *)0x06063554);

  (*(int(*)())0x06026DF8)();
}
