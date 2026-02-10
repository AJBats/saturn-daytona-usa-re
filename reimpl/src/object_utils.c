/*
 * object_utils.c -- Game object struct accessors and mutators
 *
 * Game objects use a common struct layout:
 *   +0x00: type/id
 *   +0x04: field_04
 *   +0x08: field_08 (often X or width)
 *   +0x0C: field_0C (often Y or height)
 *   +0x10: field_10 (often Z or depth)
 *   +0x14: field_14
 *   +0x18: field_18
 *   +0x1C-+0x2C: transform data (rotation, position)
 *   +0x34: flags byte
 *
 * Translated from production ASM / existing decomp src/*.c
 */

/* FUN_0603EFD4 -- Compute: field_08 * field_0C - field_10 */
int obj_compute_area(int obj)
{
    return *(int *)(obj + 0x08) * *(int *)(obj + 0x0C) - *(int *)(obj + 0x10);
}

/* FUN_060409DE -- Compute: field_08 + field_10 */
int obj_compute_sum(int obj)
{
    return *(int *)(obj + 0x08) + *(int *)(obj + 0x10);
}

/* FUN_0603F9F2 -- Get field_14 */
int obj_get_field14(int obj)
{
    return *(int *)(obj + 0x14);
}

/* FUN_0603F9F6 -- Get field_18 */
int obj_get_field18(int obj)
{
    return *(int *)(obj + 0x18);
}

/* FUN_060401E4 -- Set field_18 */
void obj_set_field18(int obj, int val)
{
    *(int *)(obj + 0x18) = val;
}

/* FUN_0603FA00 -- Set bit 7 of flags byte (+0x34) */
void obj_set_flag80(int obj)
{
    *(unsigned char *)(obj + 0x34) |= 0x80;
}

/* FUN_0603F9DA -- Set field_14, clear field_18, keep only bit 7 of flags */
void obj_set_field14_reset(int obj, int val)
{
    *(int *)(obj + 0x14) = val;
    *(int *)(obj + 0x18) = 0;
    *(unsigned char *)(obj + 0x34) &= 0x80;
}

/* FUN_0603F92C -- Set field_20 and copy 3 ints from array to fields 24/28/2C */
void obj_set_transform(int obj, int val, int *src)
{
    *(int *)(obj + 0x20) = val;
    *(int *)(obj + 0x24) = src[0];
    *(int *)(obj + 0x28) = src[1];
    *(int *)(obj + 0x2C) = src[2];
}

/* FUN_0603EF34 -- Initialize object struct (6 fields) */
int *obj_init(int *obj, int type)
{
    obj[0] = type;
    obj[1] = 0;
    obj[2] = 0;
    obj[3] = 1;
    obj[5] = 0;
    obj[4] = 0;
    return obj;
}

/* FUN_0603EF54 -- Set object fields 04/08/0C, clear 10/14 */
void obj_set_params(int obj, int a, int b, int c)
{
    *(int *)(obj + 0x04) = a;
    *(int *)(obj + 0x08) = b;
    *(int *)(obj + 0x0C) = c;
    *(int *)(obj + 0x14) = 0;
    *(int *)(obj + 0x10) = 0;
}
