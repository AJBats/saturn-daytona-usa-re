int FUN_06035c1c(param_1)
    char *param_1;
{
    int count = 0;
    goto check;
body:
    count++;
check:
    if (*param_1++ != '\0') goto body;
    return count;
}
