extern int DAT_06003498;

extern int PTR_DAT_0600349a;

extern int PTR_DAT_0600349a;

void FUN_06003430()
{

  if (*(int *)0x06083255 == '\0') {

    (*(void(*)())0x06028400)(4,*(int *)0x06063798,(int)DAT_06003498,

               *(int *)(0x06063798 + 4));

    return;

  }

  (*(void(*)())0x06028400)(4,*(int *)0x06063790,(int)PTR_DAT_0600349a,((int *)0x06063790)[1]);

  return;

}
