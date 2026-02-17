/*
 * slot_manager.c -- 24-slot resource allocation system
 *
 * The slot table is at *(0x060A5400) + 0x18 (24 bytes, one per slot).
 * Each byte: 0 = free, 1 = allocated.
 *
 * Translated from production ASM / existing decomp src/*.c
 */

#define SLOT_TABLE_PTR (*(int *)0x060A5400)
#define SLOT_COUNT 24

/* FUN_06040E88 -- Allocate first free slot, return 0 on success, -3 on full */
int slot_alloc(int *out_slot)
{
    char *table = (char *)(SLOT_TABLE_PTR + 0x18);
    int i;

    for (i = 0; i < SLOT_COUNT; i++) {
        if (table[i] == 0) {
            table[i] = 1;
            *out_slot = i;
            return 0;
        }
    }

    *out_slot = -1;
    return -3;
}

/* FUN_06040EBA -- Release slot, return 0 on success, -6 on bad index, -7 on not allocated */
#if 0 /* slot_free -- redirected to ASM import via linker PROVIDE */
int slot_free(int slot)
{
    char *table;

    if (slot < 0 || slot >= SLOT_COUNT)
        return -6;

    table = (char *)(SLOT_TABLE_PTR + 0x18);
    if (table[slot] != 1)
        return -7;

    table[slot] = 0;
    return 0;
}
#endif /* slot_free */

/* FUN_06041884 -- Set field at +0x3C of slot table struct */
#if 0 /* slot_set_field3c -- redirected to ASM import via linker PROVIDE */
void slot_set_field3c(int val)
{
    *(int *)(SLOT_TABLE_PTR + 0x3C) = val;
}
#endif /* slot_set_field3c */
