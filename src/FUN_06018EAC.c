extern void FUN_060349C4();

int
FUN_06018EAC()
{
    char buf[16];
    FUN_060349C4(buf);
    return buf[0] & 0x1f;
}
