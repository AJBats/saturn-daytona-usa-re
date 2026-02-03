int FUN_06030EE0()
{
    int i = 0x0150;
    int val = *(short *)((char *)*(int *)0x0607E940 + i);
    if (val > 0) {
        *(short *)((char *)*(int *)0x0607E940 + i) = val - 1;
    }
    return i;
}
