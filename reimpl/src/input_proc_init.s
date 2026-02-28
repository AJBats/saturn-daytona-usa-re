/* input_proc_init -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06035E00 - 0x06035E90
 *
 * Function catalog:
 *   input_proc_init  (0x06035E00) — Poll CD HIRQ for specific bit(s) with timeout.
 *   cd_cmd_write     (0x06035E3C) — Write command registers CR1-CR4 from buffer.
 *   sym_06035E5E     (0x06035E5E) — Read command registers CR1-CR4 into buffer.
 *
 * The CD block uses four 16-bit command registers (CR1-CR4) at 0x25890018-0x25890024
 * and an interrupt request register (HIRQ) at 0x25890008. Commands are issued by
 * writing CR1-CR4, then polling HIRQ until the requested completion bit(s) appear.
 *
 * input_proc_init:
 *   Arguments:
 *     r4 = HIRQ bit mask (which bits to wait for)
 *     r5 = pointer to store raw HIRQ value on match
 *   Returns:
 *     r0 =  0  success (requested HIRQ bits appeared)
 *     r0 = -3  timeout (bits never appeared within 0x240000 iterations)
 *
 * cd_cmd_write (byte-encoded, shares pool with sym_06035E5E):
 *   Arguments:
 *     r4 = pointer to 8-byte command buffer [CR1, CR2, CR3, CR4] as 16-bit words
 *   Writes buffer contents to CD command registers CR1-CR4.
 *
 * sym_06035E5E:
 *   Arguments:
 *     r4 = pointer to 8-byte output buffer
 *   Reads CD command registers CR1-CR4 into the buffer.
 */

    .section .text.FUN_06035E00


    .global input_proc_init
    .type input_proc_init, @function
input_proc_init:
    mov.l r14, @-r15                    ! push r14 (loop counter)
    mov.l r13, @-r15                    ! push r13 (timeout limit)
    mov.l r11, @-r15                    ! push r11 (HIRQ register pointer)
    mov.l   .L_cd_hirq, r11            ! r11 = 0x25890008 (CD HIRQ register)
    mov.l   .L_hirq_timeout_limit, r13      ! r13 = 0x00240000 (timeout iteration count)
    mov #0x0, r14                       ! r14 = initial return value (success = 0)
    mov #-0x3, r1                       ! r1 = -3 (timeout error code, default)
    mov r14, r7                         ! r7 = 0 (loop counter starts at 0)
.L_poll_hirq:
    mov.w @r11, r6                      ! r6 = current HIRQ register value
    extu.w r4, r2                       ! r2 = requested HIRQ bits (zero-extended)
    extu.w r6, r3                       ! r3 = HIRQ value (zero-extended)
    and r2, r3                          ! r3 = HIRQ & requested_mask
    tst r3, r3                          ! any requested bits set?
    bt      .L_not_yet                  ! no bits set -> keep polling
    mov r14, r1                         ! r1 = 0 (success — bits matched)
    bra     .L_poll_done                ! exit loop
    mov.w r6, @r5                       ! store raw HIRQ value to caller buffer (delay slot)
    .2byte  0x00FF                      ! alignment padding
.L_cd_hirq:
    .4byte  0x25890008                  /* CD HIRQ — interrupt request register */
.L_hirq_timeout_limit:
    .4byte  0x00240000                  /* [HIGH] timeout limit — 0x240000 iterations */
.L_not_yet:
    add #0x1, r7                        ! increment loop counter
    cmp/ge r13, r7                      ! counter >= timeout limit?
    bf      .L_poll_hirq                ! no -> continue polling
.L_poll_done:
    mov r1, r0                          ! r0 = return value (0 = success, -3 = timeout)
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return to caller
    mov.l @r15+, r14                    ! restore r14 (delay slot)
    /* ---- cd_cmd_write: write CR1-CR4 from buffer (byte-encoded) ---- */
    /* 06035E3C: mov r4, r5           ! r5 = source buffer pointer */
    /* 06035E3E: mov.l .L_cd_cr1, r2  ! r2 = 0x25890018 (CD CR1) */
    /* 06035E40: mov.w @r5, r3        ! r3 = buffer[0] (CR1 value) */
    /* 06035E42: mov.w r3, @r2        ! write CR1 register */
    /* 06035E44: mov.w @(2, r5), r0   ! r0 = buffer[2] (CR2 value) */
    /* 06035E46: mov.l .L_cd_cr2, r2  ! r2 = 0x2589001C (CD CR2) */
    /* 06035E48: mov r0, r3           ! transfer to r3 */
    /* 06035E4A: mov.w r3, @r2        ! write CR2 register */
    /* 06035E4C: mov.w @(4, r5), r0   ! r0 = buffer[4] (CR3 value) */
    /* 06035E4E: mov.l .L_cd_cr3, r2  ! r2 = 0x25890020 (CD CR3) */
    /* 06035E50: mov r0, r3           ! transfer to r3 */
    /* 06035E52: mov.w r3, @r2        ! write CR3 register */
    /* 06035E54: mov.w @(6, r5), r0   ! r0 = buffer[6] (CR4 value) */
    /* 06035E56: mov.l .L_cd_cr4, r2  ! r2 = 0x25890024 (CD CR4) */
    /* 06035E58: mov r0, r3           ! transfer to r3 */
    /* 06035E5A: rts                   ! return to caller */
    /* 06035E5C: mov.w r3, @r2        ! write CR4 register (delay slot) */
    .4byte  0x6543D210
    .4byte  0x63512231
    .4byte  0x8551D20F
    .4byte  0x63032231
    .4byte  0x8552D20E
    .4byte  0x63032231
    .4byte  0x8553D20D
    .4byte  0x6303000B
    .2byte  0x2231

    .global sym_06035E5E
sym_06035E5E:
    mov.l   .L_cd_cr1, r3              ! r3 = 0x25890018 (CD CR1 register address)
    mov.w @r3, r3                       ! r3 = CR1 value (16-bit read)
    mov.w r3, @r4                       ! buffer[0] = CR1
    mov.l   .L_cd_cr2, r2              ! r2 = 0x2589001C (CD CR2 register address)
    mov.w @r2, r2                       ! r2 = CR2 value (16-bit read)
    mov r2, r0                          ! r0 = CR2 (for indexed store)
    mov.w r0, @(2, r4)                  ! buffer[2] = CR2
    mov.l   .L_cd_cr3, r3              ! r3 = 0x25890020 (CD CR3 register address)
    mov.w @r3, r3                       ! r3 = CR3 value (16-bit read)
    mov r3, r0                          ! r0 = CR3 (for indexed store)
    mov.w r0, @(4, r4)                  ! buffer[4] = CR3
    mov.l   .L_cd_cr4, r3              ! r3 = 0x25890024 (CD CR4 register address)
    mov.w @r3, r3                       ! r3 = CR4 value (16-bit read)
    mov r3, r0                          ! r0 = CR4 (for indexed store)
    rts                                 ! return to caller
    mov.w r0, @(6, r4)                  ! buffer[6] = CR4 (delay slot)
    .2byte  0xFFFF                      ! alignment padding
.L_cd_cr1:
    .4byte  0x25890018                  /* CD CR1 — command register 1 */
.L_cd_cr2:
    .4byte  0x2589001C                  /* CD CR2 — command register 2 */
.L_cd_cr3:
    .4byte  0x25890020                  /* CD CR3 — command register 3 */
.L_cd_cr4:
    .4byte  0x25890024                  /* CD CR4 — command register 4 */
