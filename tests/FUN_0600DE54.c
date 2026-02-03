extern int source_0600deb4;
extern short target_0600deb8;
extern int copy_src_0600debc;
extern int copy_dst_0600dec0;
extern void FUN_0600e99c();
extern void FUN_0600e0c0();

void FUN_0600DE54()
{
    target_0600deb8 = (short)(source_0600deb4 >> 1);
    copy_dst_0600dec0 = copy_src_0600debc;
    FUN_0600e99c();
    FUN_0600e0c0();
}
