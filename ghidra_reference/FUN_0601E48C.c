/* FUN_0601E48C  0x0601E48C */


void FUN_0601e48c(ushort param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0601e520 + (uint)param_1 * 0x20;
  (**(code **)(*(int *)PTR_PTR_0601e51c + 4))(*(undefined2 *)(puVar1 + 0x1c));
                    /* WARNING: Could not recover jumptable at 0x0601e4d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)PTR_PTR_0601e51c + 0xc))
            (*(undefined2 *)(puVar1 + 0x1c),
             *(undefined4 *)(PTR_DAT_0601e528 + (uint)(byte)*PTR_DAT_0601e524 * 4),puVar1);
  return;
}

