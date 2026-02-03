extern int *base_ptr_06030ef8;
int FUN_06030EE0()
{
    int i = 0x0150;
    short val = *(short *)((char *)*base_ptr_06030ef8 + i);
    if (val > 0) {
        *(short *)((char *)*base_ptr_06030ef8 + i) = val - 1;
    }
    return i;
}
