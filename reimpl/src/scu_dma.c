/* scu_dma.c -- SCU DMA transfer setup
 *
 * FUN_0602766C sets up an SCU DMA transfer.
 * SCU DMA registers are at 0x25FE0000:
 *   +0x00: DMA destination (write order depends on original)
 *   +0x04: DMA source
 *   +0x08: DMA transfer count
 *   +0x0C: DMA add value (0x101 = src+1/dst+1)
 *   +0x10: DMA enable
 *   +0x14: DMA start/mode (7 = start)
 *
 * Waits until DMA status register (0x25FE007C) bits 0x272E are clear.
 *
 * Original address: 0x0602766C
 */

void FUN_0602766C(int param_1, int param_2, int param_3)
{
    volatile int *base = (volatile int *)0x25FE0000;

    do {
    } while ((*(volatile int *)0x25FE007C & 0x272E) != 0);

    base[1] = param_1;
    base[0] = param_2;
    base[2] = param_3;
    base[3] = 0x101;
    base[5] = 7;
    base[4] = 0x101;
}
