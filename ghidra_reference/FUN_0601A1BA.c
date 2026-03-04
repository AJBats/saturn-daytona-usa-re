/* FUN_0601A1BA  0x0601A1BA */


void FUN_0601a1ba(void)

{
  undefined *puVar1;
  
  if ((*(ushort *)PTR_DAT_0601a248 & DAT_0601a23a) != 0) {
    *PTR_DAT_0601a240 = *PTR_DAT_0601a240 + '\x01';
    *PTR_DAT_0601a24c = *PTR_DAT_0601a24c + '\x01';
    *PTR_DAT_0601a250 = 0;
    *(undefined4 *)PTR_DAT_0601a254 = 0;
    puVar1 = PTR_FUN_0601a260;
    *(uint *)PTR_DAT_0601a258 = *(uint *)PTR_DAT_0601a258 | DAT_0601a25c;
    (*(code *)puVar1)();
    *PTR_DAT_0601a264 = 1;
  }
  puVar1 = PTR_DAT_0601a268;
  if ((byte)*PTR_DAT_0601a268 < 8) {
    (*(code *)PTR_FUN_0601a274)
              (0xc,((uint)(byte)PTR_DAT_0601a270[0xd] * 0x40 + (uint)(byte)PTR_DAT_0601a270[0xc] +
                   0xd) * 2,(int)PTR_DAT_0601a23c._0_2_,PTR_s_PRESS_NEXT_0601a26c);
    return;
  }
  (*(code *)PTR_FUN_0601a318)
            (0xc,((uint)(byte)PTR_DAT_0601a314[0xd] * 0x40 + (uint)(byte)PTR_DAT_0601a314[0xc] + 0xd
                 ) * 2,(int)DAT_0601a30e,*(undefined4 *)PTR_PTR_0601a310,PTR_DAT_0601a314);
  if (0x10 < (byte)*puVar1) {
    *puVar1 = 0;
  }
  return;
}

