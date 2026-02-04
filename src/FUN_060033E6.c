extern int DAT_0600340a;

extern int DAT_0600340c;

void FUN_060033e6()
{

  if ((*(unsigned int *)0x0607EBC8 & 4) != 0) {

    (*(void(*)())0x060284AE)(8,(int)DAT_0600340c,(int)DAT_0600340a,0x06044638);

    return;

  }

  (*(void(*)())0x060284AE)(8,(int)DAT_0600340c,(int)DAT_0600340a,0x0605ACF0);

  return;

}
