/* FUN_0601503A  0x0601503A */


undefined4 FUN_0601503a(undefined1 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (((*PTR_DAT_06015074 == '\0' || *(int *)PTR_DAT_06015078 == 0) || *PTR_DAT_0601507c != '\0') ||
      *(int *)PTR_DAT_06015080 == 0) {
    uVar2 = FUN_06015338();
    return uVar2;
  }
  if (*(uint *)PTR_DAT_06015114 < (uint)(int)DAT_06015108) {
    (*(code *)PTR_FUN_06015118)(0xc);
    (*(code *)PTR_FUN_0601511c)();
    (*(code *)PTR_FUN_06015120)();
    puVar1 = PTR_FUN_06015124;
    (*(code *)PTR_FUN_06015124)(0xc,(int)DAT_0601510a,0x60,PTR_s_REPLAY__06015128);
    (*(code *)puVar1)(0xc,(int)DAT_0601510c,0x60,PTR_DAT_0601512c);
    (*(code *)puVar1)(0xc,(int)DAT_0601510e,0x60,PTR_DAT_06015130);
    (*(code *)puVar1)(0xc,(int)DAT_06015112,(int)DAT_06015110,PTR_DAT_06015134);
    uVar2 = (*(code *)PTR_FUN_06015138)(param_1);
    *PTR_DAT_0601513c = 0;
    *PTR_DAT_06015140 = 0xe;
    *PTR_DAT_06015144 = 10;
    *PTR_DAT_06015148 = 0;
    return uVar2;
  }
  *(undefined2 *)PTR_DAT_0601514c = 0;
  uVar2 = FUN_06015338();
  return uVar2;
}

