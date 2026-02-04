extern void FUN_06034000();
extern void FUN_06034168();
extern void FUN_0603449c();
extern void FUN_06034560();
extern void FUN_0603458c();
extern void FUN_06034640();
extern void FUN_060346c0();

int FUN_06033f54(param_1)
    unsigned short param_1;
{

  char cVar1;

  int uVar2;

  int iVar3;

  iVar3 = (0x0000002C & 0xffff) * (unsigned int)param_1;

  if ((0x06082A7C[0x00000001 + iVar3] == '\x01') ||

     (0x06082A7C[0x00000001 + iVar3] == '\x04')) {

LAB_06033f80:

    FUN_06034000();

    FUN_06034168();

    uVar2 = FUN_060346c0();

  }

  else {

    cVar1 = 0x06082A7C[0x00000026 + iVar3];

    if (cVar1 == '\0') {

      FUN_0603449c();

      FUN_06034000();

      FUN_06034168();

      uVar2 = FUN_060346c0();

      return uVar2;

    }

    if (cVar1 == '\x01') {

      FUN_06034560();

    }

    else if (cVar1 != '\x02') goto LAB_06033f80;

    FUN_0603449c();

    FUN_0603458c();

    FUN_06034640();

    uVar2 = FUN_060346c0();

  }

  return uVar2;

}
