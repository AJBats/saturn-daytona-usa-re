/* Minimal linker script for POC test.
 * Provides symbol addresses so .long _FUN_XXXX resolves correctly. */
OUTPUT_FORMAT("elf32-sh")
SECTIONS
{
    . = 0x0600E71A;
    .text : { *(.text) }
}

/* Provide addresses for all referenced symbols */
PROVIDE(_FUN_06008318 = 0x06008318);
PROVIDE(_FUN_06008640 = 0x06008640);
PROVIDE(_FUN_0600D266 = 0x0600D266);
PROVIDE(_FUN_0600C4F8 = 0x0600C4F8);
PROVIDE(_FUN_0600C5D6 = 0x0600C5D6);
PROVIDE(_FUN_0600CEBA = 0x0600CEBA);
PROVIDE(_DAT_0607E940 = 0x0607E940);
PROVIDE(_DAT_0607EA9C = 0x0607EA9C);
