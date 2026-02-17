/* scsp_utils.c -- SCSP (Saturn Custom Sound Processor) utilities
 *
 * The SCSP is at 0x25B00000. It controls the 68000 sound CPU.
 * Slot registers are at 0x25B00000-0x25B003FF (32 slots x 32 bytes)
 *
 * FUN_06018EC8: Set SCSP volume registers for two slots
 *   0x25B00217 and 0x25B00237 are slot volume bytes (slots 16 and 17?)
 *   Value 0xE0 = relatively high volume
 *
 * Original address: 0x06018EC8
 */

void FUN_06018EC8(void)
{
    short val = 0x00E0;
    *(volatile char *)0x25B00217 = (unsigned char)val;
    *(char *)0x25B00237 = (char)val;
}
