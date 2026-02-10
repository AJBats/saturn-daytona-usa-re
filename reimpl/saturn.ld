/* Saturn linker script for Daytona USA reimplementation
 * APROG.BIN loads at 0x06003000 (high work RAM)
 * IP.BIN handles loading and jumps to _start at 0x06003000
 */

OUTPUT_FORMAT("elf32-sh")
OUTPUT_ARCH(sh)
ENTRY(_start)

MEMORY
{
    /* High Work RAM: APROG.BIN lives here */
    HWRAM (rwx) : ORIGIN = 0x06003000, LENGTH = 0x5D000

    /* Low Work RAM: game data, stacks, etc */
    LWRAM (rw)  : ORIGIN = 0x00200000, LENGTH = 0x100000

    /* VDP1 VRAM */
    VDP1VRAM (rw) : ORIGIN = 0x25C00000, LENGTH = 0x80000

    /* VDP2 VRAM */
    VDP2VRAM (rw) : ORIGIN = 0x25E00000, LENGTH = 0x80000

    /* VDP2 Color RAM */
    VDP2CRAM (rw) : ORIGIN = 0x25F00000, LENGTH = 0x1000

    /* Sound RAM (68000 side) */
    SOUNDRAM (rw) : ORIGIN = 0x25A00000, LENGTH = 0x80000
}

SECTIONS
{
    /* Code and read-only data */
    .text ORIGIN(HWRAM) :
    {
        *(.text.startup)
        *(.text .text.*)
        *(.rodata .rodata.*)
    } > HWRAM

    /* Initialized data */
    .data :
    {
        *(.data .data.*)
    } > HWRAM

    /* BSS (zero-initialized) */
    .bss :
    {
        __bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    } > HWRAM

    _end = .;

    /* Discard unnecessary sections */
    /DISCARD/ :
    {
        *(.comment)
        *(.note.*)
        *(.eh_frame)
    }
}
