extern unsigned short reg_060A3D88;
extern short flag_060635AC;

void FUN_060149E0()
{
    reg_060A3D88 = reg_060A3D88 & 0x7FFF;
    flag_060635AC = 1;
}
