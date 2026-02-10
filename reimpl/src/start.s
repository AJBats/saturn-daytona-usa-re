! start.s -- Entry point for Daytona USA reimplementation
! Placed at 0x06003000 by linker script (.text.startup section)
! IP.BIN loads APROG.BIN here and jumps to _start

    .section .text.startup
    .global _start
    .type _start, @function
    .align 2

_start:
    ! Set stack pointer (high work RAM, above our code)
    mov.l   stack_addr, r15
    ! Clear status register (all interrupts enabled)
    mov     #0, r0
    ldc     r0, sr
    ! Jump to C boot function
    mov.l   boot_addr, r0
    jmp     @r0
    nop

    .align 2
stack_addr:
    .long   0x06060000
boot_addr:
    .long   _boot
