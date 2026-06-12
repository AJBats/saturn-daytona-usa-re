OUTPUT_FORMAT("elf32-sh")
OUTPUT_ARCH(sh)
ENTRY(_start)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x06004000, LENGTH = 0x5C000
}

SECTIONS
{
    .text : {
        *(.text.start)
        *(.text*)
        *(.rodata*)
    } > RAM

    .bss (NOLOAD) : {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > RAM

    .results (NOLOAD) : ALIGN(4) {
        _results_start = .;
        . += 0x2000;    /* 6*7*4*3 = 504 tests * 4 bytes + header */
    } > RAM
}
