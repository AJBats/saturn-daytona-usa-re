! start.s -- Minimal crt0 for Daytona USA reimplementation
!
! The BIOS loads APROG.BIN to 0x06003000 and jumps here.
! We set the stack pointer, clear SR, and jump to boot() in main.c.
! All function addresses are resolved by the linker -- no hardcoded pools.
!
! Replaces the original 138-line raw binary dump that had hardcoded
! constant pool addresses for system_init, per_frame_setup, and all 32
! state handlers. Those hardcoded addresses broke when functions moved
! to overflow sections (Class 3 bug).

    .section .text.startup
    .global _start
    .type _start, @function
    .balign 4

_start:
    mov.l   _sp_init, r15       ! set stack pointer (grows down from code base)
    mov     #0, r0
    ldc     r0, sr              ! clear status register (all interrupts enabled)
    mov.l   _boot_addr, r0
    jmp     @r0                 ! jump to boot() — linker resolves address
    nop                         ! delay slot

    .align 2
_sp_init:
    .long   0x06003000          ! stack base (same as original)
_boot_addr:
    .long   _boot               ! resolved by linker — no hardcoded address
