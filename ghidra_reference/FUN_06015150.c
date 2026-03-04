/* FUN_06015150  0x06015150 */


void FUN_06015150(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = PTR_DAT_06015214;
  puVar3 = PTR_DAT_06015210;
  puVar2 = PTR_DAT_0601520c;
  puVar1 = PTR_DAT_06015208;
  if (((uint)*(ushort *)(PTR_DAT_0601520c + 2) & (uint)PTR_DAT_06015218) == 0) {
    if ((*(ushort *)(PTR_DAT_0601520c + 2) & DAT_06015204) != 0) {
      (*(code *)PTR_FUN_06015220)
                (0xc,((uint)(byte)*PTR_DAT_06015208 * 0x40 + (uint)(byte)*PTR_DAT_06015214) * 2,
                 (int)DAT_06015202,PTR_PTR_0601521c);
      *puVar4 = 0xe;
      *puVar3 = 0;
      *PTR_DAT_06015224 = 0;
    }
  }
  else {
    (*(code *)PTR_FUN_06015220)
              (0xc,((uint)(byte)*PTR_DAT_06015208 * 0x40 + (uint)(byte)*PTR_DAT_06015214) * 2,
               (int)DAT_06015202,PTR_PTR_0601521c);
    *puVar3 = 1;
    *puVar4 = 0x18;
    *PTR_DAT_06015224 = 0;
  }
  if ((*(ushort *)(puVar2 + 2) & DAT_06015206) == 0) {
    if ((*(ushort *)(puVar2 + 2) & DAT_060152ce) == 0) goto LAB_0601528e;
  }
  else {
    if (*puVar1 == '\f') {
      *puVar3 = *puVar3 + '\x02';
    }
    if (*puVar3 != '\x01') {
      if (*puVar3 == '\0') {
        *(undefined2 *)PTR_DAT_060152d4 = 1;
        *DAT_060152d8 = 1;
        *(undefined2 *)PTR_DAT_060152dc = 1;
        *(undefined4 *)PTR_DAT_060152e0 = 8;
        FUN_06015338();
        *(undefined4 *)PTR_DAT_060152e4 = 0xe;
      }
      else if (*puVar3 == '\x02') {
        (*(code *)PTR_FUN_060152e8)();
      }
      else if (*puVar3 == '\x03') {
        (*(code *)PTR_FUN_060152ec)();
      }
      goto LAB_0601528e;
    }
  }
  *(undefined2 *)PTR_DAT_060152d4 = 0;
  *(undefined2 *)PTR_DAT_060152dc = 0;
  *(undefined4 *)PTR_DAT_060152e0 = 8;
  FUN_06015338();
LAB_0601528e:
  puVar1 = PTR_DAT_060152f0;
  *PTR_DAT_060152f0 = *PTR_DAT_060152f0 + '@';
  if (*puVar1 != '\0') {
    (*(code *)PTR_FUN_06015334)
              (0xc,((uint)(byte)*PTR_DAT_0601532c * 0x40 + (uint)(byte)*PTR_DAT_06015330) * 2,
               (int)PTR_DAT_06015324._0_2_,PTR_DAT_06015328);
    return;
  }
  (*(code *)PTR_FUN_06015300)
            (0xc,((uint)(byte)*PTR_DAT_060152f8 * 0x40 + (uint)(byte)*PTR_DAT_060152fc) * 2,
             (int)PTR_DAT_060152d0._0_2_,PTR_PTR_060152f4);
  return;
}

