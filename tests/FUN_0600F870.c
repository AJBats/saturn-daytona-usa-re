extern void func_060114AC();
extern int func_06011094();

extern short counter_0607887C;
extern char flag_0607887F;

void FUN_0600F870()
{
    short val;

    func_060114AC(0);
    func_06011094();
    val = counter_0607887C;
    counter_0607887C = val - 1;
    if ((short)(val - 1) <= 0) {
        flag_0607887F = 4;
    }
}
