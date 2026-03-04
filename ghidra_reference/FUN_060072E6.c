/* FUN_060072E6  0x060072E6 */


undefined8 FUN_060072e6(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  
  (**(code **)PTR_DAT_06007364)(0xffffffff,(int)DAT_0600735c);
  *(int *)PTR_DAT_06007368 = *(int *)PTR_DAT_06007368 + 1;
  *(byte *)(int)DAT_0600735e = *(byte *)(int)DAT_0600735e & 0x87;
  (**(code **)PTR_DAT_06007364)((int)DAT_06007360,0);
  return CONCAT44(in_r1,in_r0);
}

