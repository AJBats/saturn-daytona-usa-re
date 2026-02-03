extern int val_long_06011670;
extern int dst_long_06011674;
extern short val_short_0601165a;
void FUN_0601164A()
{
    int *p;
    p = &dst_long_06011674;
    *p = val_long_06011670;
    *(short *)((char *)p + -10) = val_short_0601165a;
}
