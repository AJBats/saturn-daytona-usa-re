extern int counter_06033518;
extern int offset_0603351c;
int *FUN_06033504()
{
    int *p;
    p = &counter_06033518;
    counter_06033518 = counter_06033518 + 1;
    offset_0603351c = offset_0603351c + 0x20;
    return p;
}
