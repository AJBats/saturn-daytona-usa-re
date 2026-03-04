/* FUN_060158DE  0x060158DE */


void FUN_060158de(byte param_1)

{
  if (*(int *)PTR_DAT_0601593c == 0) {
    PTR_DAT_06015934[(short)((ushort)param_1 * 0x44) + 1] = 1;
    (*(code *)PTR_FUN_0601594c)
              (0,*(undefined4 *)(PTR_DAT_06015948 + *(int *)(PTR_DAT_06015944 + DAT_06015932) * 4));
  }
  else {
    *(undefined2 *)PTR_DAT_06015940 = 1;
  }
  (*(code *)PTR_FUN_06015950)(param_1);
  return;
}

