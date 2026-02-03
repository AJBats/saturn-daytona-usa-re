extern unsigned short reg_060A3D88;
extern short flag_060635AC;

void FUN_060149CC()
{
    reg_060A3D88 = reg_060A3D88 | 0x8000;
    flag_060635AC = 1;
}
