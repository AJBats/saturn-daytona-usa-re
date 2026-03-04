/* FUN_060197F4  0x060197F4 */


void FUN_060197f4(undefined4 param_1)

{
  if ((*(ushort *)PTR_DAT_06019874 & DAT_06019866) != 0) {
    *(undefined4 *)PTR_DAT_06019878 = 0;
    *PTR_DAT_0601987c = 0;
    *(undefined4 *)PTR_DAT_06019880 = param_1;
    (*(code *)PTR_FUN_06019894)
              (0xc,*(undefined4 *)
                    (PTR_DAT_0601988c +
                    (uint)*(ushort *)(PTR_PTR_06019888 + (char)*PTR_DAT_06019884 * 2) * 8),
               ((uint)(byte)(PTR_DAT_06019890 + (char)*PTR_DAT_06019884 * 2)[1] * 0x40 +
               (uint)(byte)PTR_DAT_06019890[(char)*PTR_DAT_06019884 * 2]) * 2,
               *(int *)((int)(PTR_DAT_0601988c +
                             (uint)*(ushort *)(PTR_PTR_06019888 + (char)*PTR_DAT_06019884 * 2) * 8)
                       + 4) + (int)DAT_06019868);
    (*(code *)PTR_FUN_06019898)();
    return;
  }
  return;
}

