extern void FUN_0600e0c0();
extern void FUN_0600e410();
extern void FUN_0600e47c();

void FUN_0600df66()
{

  char cVar1;

  *(short *)0x060786CA = (short)(*(int *)0x0607EA98 >> 1);

  cVar1 = *0x06083261;

  if (cVar1 == '\0') {

    FUN_0600e410();

  }

  else if (cVar1 == '\x01') {

    FUN_0600e47c();

  }

  else if (cVar1 == '\x02') {

    FUN_0600e47c();

  }

  FUN_0600e0c0();

  return;

}
