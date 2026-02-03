extern int count_06019300;
extern char *dest_060192fc;
void FUN_060192B4()
{
    char *p;
    int n;
    p = dest_060192fc;
    n = count_06019300;
    do {
        *p = 0;
        p = p + 1;
        n = n - 1;
    } while (n != 0);
}
