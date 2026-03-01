
    .section .text.FUN_0603BF22


    .global save_commit_write
    .type save_commit_write, @function
save_commit_write:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r5, r14
    add #-0x4, r15
    mov.l r4, @r15
    .byte   0xBD, 0x53    /* bsr 0x0603B9D6 (external) */  ! call save_field_read
    mov r5, r4
    mov.l @r15, r4
    mov #0x0, r3
    mov.w   save_dirty_offset, r0
    mov.l r3, @(r0, r4)
    tst r14, r14
    bf      .have_callback
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.have_callback:
    mov.l @r14, r4
    mov.l @(24, r4), r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x08    /* mov.l .pool_watchdog_fn, r3 */  ! r3 = &watchdog_timer_reset
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x7F04
    .4byte  0x4F26000B
    .4byte  0x6EF6E11D
    .4byte  0x6042001C
    .4byte  0x600CC860
    .4byte  0x8B066542
    .4byte  0x5556A004
    .2byte  0x5459

    .global DAT_0603bf6e
save_dirty_offset:
DAT_0603bf6e:
    .2byte  0x00EC
.pool_watchdog_fn:
    .4byte  watchdog_timer_reset
    .4byte  0xE400000B
    .4byte  0x60430000

    .global sym_0603BF7C
sym_0603BF7C:
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x3F, r9
    mov #0x40, r10
    .byte   0xDB, 0x1C    /* mov.l .pool_cache_addr_array, r11 */  ! r11 = 0x60000000 (cache addr array base)
    mov.w   .cache_total_entries, r12
    mov #0x0, r7
    mov.w   .ccr_addr, r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov r7, r13
.way_loop:
    mov.b @r5, r3
    extu.b r3, r3
    and r9, r3
    extu.b r13, r2
    or r2, r3
    extu.b r3, r3
    mov.b r3, @r5
    mov r11, r6
    mov r10, r1
.entry_clear_loop:
    mov.l r7, @r6
    add #-0x2, r1
    add #0x10, r6
    mov.l r7, @r6
    tst r1, r1
    bf/s    .entry_clear_loop
    add #0x10, r6
    add #0x40, r13
    cmp/hs r12, r13
    bf      .way_loop
    extu.b r4, r4
    mov.b @r5, r0
    extu.b r0, r0
    and #0xF7, r0
    or r4, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFD, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFB, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    or #0x1, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13
.cache_total_entries:
    .2byte  0x0100
.ccr_addr:
    .2byte  0xFE92
.pool_cache_addr_array:
    .4byte  0x60000000

    .global sym_0603C000
sym_0603C000:
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x40, r10
    mov #0x3F, r11
    mov.w   DAT_0603c07a, r12
    .byte   0xDD, 0x1C    /* mov.l .pool_cache_addr_array_b, r13 */  ! r13 = 0x60000000 (cache addr array base)
    mov #0x0, r7
    mov.w   .ccr_addr_b, r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov r7, r1
.way_loop_b:
    mov.b @r5, r3
    extu.b r3, r3
    and r11, r3
    extu.b r1, r2
    or r2, r3
    extu.b r3, r3
    mov.b r3, @r5
    mov r13, r4
    mov r10, r6
.entry_clear_loop_b:
    add #-0x2, r6
    mov.l r7, @r4
    add #0x10, r4
    mov.l r7, @r4
    tst r6, r6
    bf/s    .entry_clear_loop_b
    add #0x10, r4
    add #0x40, r1
    cmp/hs r12, r1
    bf      .way_loop_b
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    or #0x1, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13

    .global sym_0603C05C
sym_0603C05C:
    .byte   0xD3, 0x09    /* mov.l .pool_addr_mask_16align, r3 */  ! r3 = 0x1FFFFFF0 (28-bit addr mask, 16-byte aligned)
    .byte   0xD2, 0x0A    /* mov.l .pool_purge_region_base, r2 */ ! r2 = 0x40000000 (associative purge region base)
    and r3, r4
    or r2, r4
    mov r4, r7
    add r5, r7
    cmp/hs r7, r4
    bt/s    .purge_done
    mov #0x0, r6
.purge_loop:
    mov.l r6, @r4
    add #0x10, r4
    cmp/hs r7, r4
    bf      .purge_loop
.purge_done:
    rts
    nop

    .global DAT_0603c07a
DAT_0603c07a:
    .2byte  0x0100
.ccr_addr_b:
    .2byte  0xFE92
    .2byte  0xFFFF
.pool_cache_addr_array_b:
    .4byte  0x60000000
.pool_addr_mask_16align:
    .4byte  0x1FFFFFF0
.pool_purge_region_base:
    .4byte  0x40000000                  /* associative purge region base address */
