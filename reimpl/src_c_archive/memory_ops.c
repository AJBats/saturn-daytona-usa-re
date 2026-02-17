/*
 * memory_ops.c -- Memory copy/fill operations
 *
 * Translated from production ASM / existing decomp src/*.c
 */

/* mem_copy_word_idx -- Copy shorts (2-byte units) */
void memcpy_word(char *dst, char *src, int size)
{
    int i = 0;
    size -= 2;
    do {
        *(short *)(dst + i) = *(short *)(src + i);
        i += 2;
    } while (size > i);
}

/* dma_alt_transfer -- Copy ints (4-byte units) */
void memcpy_long(char *dst, char *src, int size)
{
    int i = 0;
    size -= 4;
    do {
        *(int *)(dst + i) = *(int *)(src + i);
        i += 4;
    } while (size > i);
}
