extern void FUN_060388c0();
extern void FUN_06038a48();
extern void FUN_06038ac8();

void FUN_060389a6()
{

  char *puVar1;

  puVar1 = 0x060635AC;

  if (*(short *)0x060635AC == 1) {

    FUN_060388c0();

  }

  else {

    if (*(short *)0x060635AC != 2) goto LAB_06038a42;

    FUN_06038a48(*(int *)0x060A3D70,*(int *)0x060A3D74,

                 (unsigned int)*(unsigned short *)0x060635A0 * 0xc);

    FUN_06038a48(*(int *)0x060A3D78,*(int *)0x060A3D7C,

                 (unsigned int)*(unsigned short *)0x060635A2 << 2);

    FUN_060388c0();

  }

  *(short *)puVar1 = 0;

LAB_06038a42:

  FUN_06038ac8();

  return;

}
