extern short offset_0600c9e4;
extern short table_0600c9e8[];
int FUN_0600C970(param_1)
    int param_1;
{
    int idx;
    int val;
    idx = (int)offset_0600c9e4;
    val = *(int *)(param_1 + idx);
    if (val >= 0x45 && val <= 98) {
        *(int *)(param_1 + 0xc) =
            *(int *)(param_1 + 0xc) + (int)table_0600c9e8[val - 0x45];
    }
    return idx;
}
