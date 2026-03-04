/* FUN_0601F938  0x0601F938 */


undefined4 FUN_0601f938(void)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined1 in_r3;
  
  puVar2 = PTR_DAT_0601f974;
  uVar1 = DAT_0601f962;
  *PTR_DAT_0601f978 = in_r3;
  FUN_0601f87a();
  uVar4 = (*(code *)PTR_FUN_0601f97c)();
  puVar3 = PTR_FUN_0601fa30;
  if (*PTR_DAT_0601f978 != '\0') {
    *(uint *)puVar2 = *(uint *)puVar2 | DAT_0601fa2c;
    (*(code *)puVar3)();
    (*(code *)PTR_FUN_0601fa30)();
    FUN_0601f9cc();
    *(uint *)puVar2 = *(uint *)puVar2 | DAT_0601fa34;
    puVar3 = PTR_DAT_0601fa38;
    do {
      FUN_0601fd20();
    } while ((*(ushort *)puVar3 & uVar1) == 0);
    uVar4 = FUN_0601fd20();
    *(uint *)puVar2 = *(uint *)puVar2 | DAT_0601fa2c;
  }
  return uVar4;
}

