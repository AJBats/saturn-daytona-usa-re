extern int *DAT_0607E944;
extern int DAT_06083264;
extern int DAT_06083268;

void FUN_0602e5e4()
{
  int *p;
  p = DAT_0607E944;
  DAT_06083264 = *(int *)((char *)p + 0x238);
  DAT_06083268 = *(int *)((char *)p + 0x23C);
  return;
}
