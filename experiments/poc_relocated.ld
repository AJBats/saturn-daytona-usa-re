/* Relocated linker script — everything at DIFFERENT addresses than original.
 * If the symbolic references work, the pool entries will contain these
 * new addresses instead of the originals. The instructions will be identical
 * (they just load from the pool) but the pool VALUES will be different. */
OUTPUT_FORMAT("elf32-sh")
SECTIONS
{
    /* Put the function at a totally different address */
    . = 0x06050000;
    .text : { *(.text) }
}

/* Callees at shifted addresses (originals + 0x1000 offset) */
PROVIDE(_FUN_06008318 = 0x06009318);
PROVIDE(_FUN_06008640 = 0x06009640);
PROVIDE(_FUN_0600D266 = 0x0600E266);
PROVIDE(_FUN_0600C4F8 = 0x0600D4F8);
PROVIDE(_FUN_0600C5D6 = 0x0600D5D6);
PROVIDE(_FUN_0600CEBA = 0x0600DEBA);
PROVIDE(_DAT_0607E940 = 0x0608E940);
PROVIDE(_DAT_0607EA9C = 0x0608EA9C);
