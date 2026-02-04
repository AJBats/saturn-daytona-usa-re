extern int counter_0607EBCC;
extern int state_0605AD10;
extern int func_0601389E();
extern int func_06018E70();
extern char flag_0607864B;

void FUN_06009E02()
{
    counter_0607EBCC = counter_0607EBCC - 1;
    if (counter_0607EBCC == 0) {
        state_0605AD10 = 30;
    }
    func_0601389E();
    if (state_0605AD10 != 27) {
        func_06018E70();
    }
    flag_0607864B = 1;
}
