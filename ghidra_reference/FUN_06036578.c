/* FUN_06036578  0x06036578 */


undefined4 FUN_06036578(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_14 [6];
  ushort uStack_e;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_060365bc)(local_c);
  local_c[0] = 0x51;
  uVar1 = (*(code *)PTR_FUN_060365c0)(0,local_c,auStack_14);
  *param_2 = (uint)uStack_e;
  return uVar1;
}

