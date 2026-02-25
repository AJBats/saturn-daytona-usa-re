/* ai_master_update -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06036BA6 - 0x06036DDC
 *
 * This TU contains the SMPC peripheral input dispatcher and four C runtime
 * library functions compiled into the game binary by the Sega SDK toolchain.
 *
 * Functions:
 *   ai_master_update     -- SMPC input processing dispatcher
 *                           Reads analog axes via input_proc_analog, sets
 *                           peripheral port mask (0x0200 = port A digital),
 *                           issues SMPC INTBACK via sym_06035C92, then
 *                           reads digital buttons via input_proc_buttons.
 *                           Stack frame: 0x8 bytes for local buffer.
 *
 *   sym_06036BE4          -- signed_mod_32: signed 32-bit modulo
 *                           Input:  r0 = divisor, r1 = dividend
 *                           Output: r0 = r1 % r0 (signed remainder)
 *                           On divide-by-zero: stores 0x44E to sym_060A246C,
 *                           returns 0.
 *                           Uses SH-2 div0s/div1 hardware division, 32 iterations.
 *
 *   sym_06036CB0          -- strcpy: copy null-terminated string
 *                           Input:  r0 = dst, r1 = src
 *                           Output: r0 = dst (original pointer)
 *                           Copies longwords (4 bytes at a time) using cmp/str
 *                           to detect null terminator, then copies remaining
 *                           bytes individually.
 *
 *   sym_06036D14          -- strcmp: compare two null-terminated strings
 *                           Input:  r0 = str_a, r1 = str_b
 *                           Output: r0 = difference (0 if equal)
 *                           Checks alignment of both pointers; if both are
 *                           word-aligned, jumps to palette_regs_config (the
 *                           fast word-aligned strcmp). Otherwise does byte-by-byte
 *                           comparison in groups of 5.
 *
 *   sym_06036D78          -- memset: fill memory region with a byte value
 *                           Input:  r4 = dst, r5 = fill byte, r6 = count
 *                           Output: r0 = dst (original pointer)
 *
 *   sym_06036D94          -- memcmp: compare two memory regions
 *                           Input:  r4 = buf_a, r5 = buf_b, r6 = count
 *                           Output: r0 = difference of first mismatched byte
 *                           (0 if regions are identical)
 */

    .section .text.FUN_06036BA6


    .global ai_master_update
    .type ai_master_update, @function
ai_master_update:
    sts.l pr, @-r15                     ! save return address
    add #-0x8, r15                      ! allocate 0x8-byte stack frame for local buffer
    .byte   0xD3, 0x0B    /* mov.l .L_fn_input_proc_analog, r3 */
    jsr @r3                             ! call input_proc_analog(r4=buf)
    mov r15, r4                         ! r4 = stack buffer (delay slot)
    mov r15, r2                         ! r2 → stack buffer base
    mov #0x75, r3                       ! r3 = 0x75 (peripheral mode byte)
    mov.b r3, @r2                       ! buf[0] = 0x75 (SMPC INTBACK status request)
    mov.w   .L_periph_port_mask, r4     ! r4 = 0x0200 (port A digital mask)
    .byte   0xD3, 0x09    /* mov.l .L_fn_smpc_intback, r3 */
    jsr @r3                             ! call sym_06035C92(r4=0x0200) — set SMPC periph flags
    nop                                 ! (delay slot)
    mov.w   .L_periph_port_mask, r4     ! r4 = 0x0200 again (port mask for button read)
    .byte   0xD3, 0x06    /* mov.l .L_fn_input_proc_buttons, r3 */
    jsr @r3                             ! call input_proc_buttons(r4=0x0200, r5=buf)
    mov r15, r5                         ! r5 = stack buffer (delay slot)
    add #0x8, r15                       ! deallocate stack frame
    lds.l @r15+, pr                     ! restore return address
    rts                                 ! return
    mov r0, r4                          ! r4 = result from input_proc_buttons (delay slot)
.L_periph_port_mask:
    .2byte  0x0200                      ! peripheral port A digital mask
    .4byte  0x00FFFFFF                  ! (padding / unused constant)
    .4byte  smpc_secondary_proc         ! (pool entry — not directly referenced)
.L_fn_input_proc_analog:
    .4byte  input_proc_analog           ! → SMPC analog axis reader
.L_fn_input_proc_buttons:
    .4byte  input_proc_buttons          ! → SMPC digital button reader
.L_fn_smpc_intback:
    .4byte  sym_06035C92                ! → SMPC INTBACK peripheral flag setter

    .global sym_06036BE4
sym_06036BE4:                           ! signed_mod_32: r0 = r1 % r0 (signed remainder)
    tst r0, r0                          ! divisor == 0?
    mov.l r2, @-r15                     ! save r2
    bt      .L_smod_by_zero            ! yes → divide-by-zero handler
    mov.l r3, @-r15                     ! save r3
    mov #0x0, r2                        ! r2 = 0 (sign reference)
    mov.l r4, @-r15                     ! save r4
    div0s r2, r1                        ! set T from dividend sign (r1)
    .word 0x0429 /* movt r4 */          ! r4 = T (save dividend sign bit)
    subc r3, r3                         ! r3 = -T (sign extension mask)
    subc r2, r1                         ! r1 = abs(r1) if negative (one's complement fixup)
    div0s r0, r3                        ! init signed division: set Q,M from divisor/dividend signs
    rotcl r1                            ! shift dividend bit 31 into T
    div1 r0, r3                         ! division step  1
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  2
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  3
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  4
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  5
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  6
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  7
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  8
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step  9
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 10
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 11
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 12
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 13
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 14
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 15
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 16
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 17
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 18
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 19
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 20
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 21
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 22
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 23
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 24
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 25
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 26
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 27
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 28
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 29
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 30
    rotcl r1                            ! shift next bit
    div1 r0, r3                         ! division step 31
    rotcl r1                            ! shift final bit
    div1 r0, r3                         ! division step 32 (remainder now in r3)
    div0s r2, r3                        ! check remainder sign vs zero
    .word 0x0229 /* movt r2 */          ! r2 = T (remainder-needs-correction flag)
    xor r4, r2                          ! r2 = correction XOR dividend_sign
    rotcr r2                            ! shift correction bit into T
    bf      .L_smod_no_correct         ! T=0: no correction needed
    div0s r0, r3                        ! re-check signs for correction direction
    shar r3                             ! arithmetic shift right (sign-extend remainder)
    div1 r0, r3                         ! one correction step
.L_smod_no_correct:
    add r4, r3                          ! apply sign: r3 += saved_sign (0 or 1)
    mov r3, r0                          ! r0 = signed remainder (return value)
    mov.l @r15+, r4                     ! restore r4
    mov.l @r15+, r3                     ! restore r3
    rts                                 ! return
    mov.l @r15+, r2                     ! restore r2 (delay slot)
.L_smod_by_zero:                        ! --- divide-by-zero handler ---
    .byte   0xD1, 0x03    /* mov.l .L_ptr_smod_error, r1 */
    .byte   0xD2, 0x03    /* mov.l .L_smod_error_code, r2 */
    mov #0x0, r0                        ! return 0
    mov.l r2, @r1                       ! store error code 0x44E to flag variable
    rts                                 ! return
    mov.l @r15+, r2                     ! restore r2 (delay slot)
    .2byte  0x0009                      ! alignment pad (nop encoding)
.L_ptr_smod_error:
    .4byte  sym_060A246C                ! → error flag variable (WRAM)
.L_smod_error_code:
    .4byte  0x0000044E                  ! error code: divide by zero
    .4byte  0x2F362F46                  ! (padding — raw bytes between functions)

    .global sym_06036CB0
sym_06036CB0:                           ! strcpy: copy null-terminated string (word-optimized)
    mov.l r5, @-r15                     ! save r5
    mov.l r6, @-r15                     ! save r6
    mov r0, r3                          ! r3 = dst (save original pointer for return)
    mov.l @r1+, r4                      ! r4 = first longword from src
    mov #0x0, r6                        ! r6 = 0 (null sentinel for cmp/str)
.L_strcpy_word_loop:
    cmp/str r4, r6                      ! does r4 contain a null byte?
    mov.l @r1+, r5                      ! prefetch next longword from src
    bt      .L_strcpy_tail             ! yes → copy remaining bytes
    mov.l r4, @r0                       ! store longword to dst
    cmp/str r5, r6                      ! does r5 contain a null byte?
    mov.l @r1+, r4                      ! prefetch next longword
    bt      .L_strcpy_tail_plus4       ! yes → advance dst by 4, then copy tail
    mov.l r5, @(4, r0)                  ! store second longword at dst+4
    cmp/str r4, r6                      ! null in r4?
    mov.l @r1+, r5                      ! prefetch next
    bt      .L_strcpy_tail_plus8       ! yes → advance dst by 8, then copy tail
    mov.l r4, @(8, r0)                  ! store third longword at dst+8
    cmp/str r5, r6                      ! null in r5?
    mov.l @r1+, r4                      ! prefetch next
    bt      .L_strcpy_tail_plus12      ! yes → advance dst by 12, then copy tail
    mov.l r5, @(12, r0)                 ! store fourth longword at dst+12
    bra     .L_strcpy_word_loop        ! loop — 16 bytes copied per iteration
    add #0x10, r0                       ! dst += 16 (delay slot)
.L_strcpy_tail_plus4:
    bra     .L_strcpy_tail             ! jump to byte-copy tail
    add #0x4, r0                        ! dst += 4 (delay slot)
.L_strcpy_tail_plus8:
    bra     .L_strcpy_tail             ! jump to byte-copy tail
    add #0x8, r0                        ! dst += 8 (delay slot)
.L_strcpy_tail_plus12:
    add #0xC, r0                        ! dst += 12
.L_strcpy_tail:                         ! --- byte-by-byte copy of last 0..7 src bytes ---
    add #-0x8, r1                       ! rewind src ptr by 8 (back up past prefetch)
    mov r0, r6                          ! r6 = current dst position
    mov.b @r1+, r0                      ! read byte from src
    cmp/eq #0x0, r0                     ! is it null terminator?
    mov.b r0, @r6                       ! store byte to dst
    bt      .L_strcpy_done             ! yes → done
    mov.b @r1+, r0                      ! read next byte
    cmp/eq #0x0, r0                     ! null?
    mov.b r0, @(1, r6)                  ! store at dst+1
    bt      .L_strcpy_done             ! yes → done
    mov.b @r1+, r0                      ! read next byte
    cmp/eq #0x0, r0                     ! null?
    mov.b r0, @(2, r6)                  ! store at dst+2
    bt      .L_strcpy_done             ! yes → done
    mov.b @r1+, r0                      ! read final byte
    mov.b r0, @(3, r6)                  ! store at dst+3 (guaranteed to include null)
.L_strcpy_done:
    mov.l @r15+, r6                     ! restore r6
    mov r3, r0                          ! r0 = original dst (return value)
    mov.l @r15+, r5                     ! restore r5
    mov.l @r15+, r4                     ! restore r4
    rts                                 ! return
    mov.l @r15+, r3                     ! restore r3 (delay slot)

    .global sym_06036D14
sym_06036D14:                           ! strcmp: compare two null-terminated strings
    mov.l r3, @-r15                     ! save r3
    mov.l r4, @-r15                     ! save r4
    mov #0x3, r3                        ! r3 = 0x3 (alignment mask)
    mov r0, r4                          ! r4 = str_a low bits
    and r3, r4                          ! r4 = str_a & 0x3 (alignment offset)
    and r1, r3                          ! r3 = str_b & 0x3
    or r4, r3                           ! r3 = combined alignment bits
    tst r3, r3                          ! both word-aligned? (r3 == 0?)
    bt      .L_strcmp_aligned          ! yes → use fast word-aligned path
    mov.l r5, @-r15                     ! save r5 (unaligned path needs it)
    mov.b @r0+, r3                      ! r3 = *str_a++
    mov #0x0, r5                        ! r5 = 0 (null sentinel)
    mov.b @r1+, r4                      ! r4 = *str_b++
.L_strcmp_byte_loop:                    ! --- byte-by-byte comparison (5 per iteration) ---
    cmp/eq r5, r3                       ! str_a byte == null?
    bt      .L_strcmp_diff             ! yes → end of string, compute difference
    cmp/eq r3, r4                       ! str_a byte == str_b byte?
    bf      .L_strcmp_diff             ! no → mismatch, compute difference
    mov.b @r0+, r3                      ! r3 = next str_a byte
    mov.b @r1+, r4                      ! r4 = next str_b byte
    cmp/eq r5, r3                       ! null?
    bt      .L_strcmp_diff             ! yes → end
    cmp/eq r3, r4                       ! match?
    bf      .L_strcmp_diff             ! no → mismatch
    mov.b @r0+, r3                      ! r3 = next str_a byte
    mov.b @r1+, r4                      ! r4 = next str_b byte
    cmp/eq r5, r3                       ! null?
    bt      .L_strcmp_diff             ! yes → end
    cmp/eq r3, r4                       ! match?
    bf      .L_strcmp_diff             ! no → mismatch
    mov.b @r0+, r3                      ! r3 = next str_a byte
    mov.b @r1+, r4                      ! r4 = next str_b byte
    cmp/eq r5, r3                       ! null?
    bt      .L_strcmp_diff             ! yes → end
    cmp/eq r3, r4                       ! match?
    bf      .L_strcmp_diff             ! no → mismatch
    mov.b @r0+, r3                      ! r3 = next str_a byte (5th in group)
    bra     .L_strcmp_byte_loop        ! loop back for next group
    mov.b @r1+, r4                      ! r4 = next str_b byte (delay slot)
.L_strcmp_diff:
    sub r4, r3                          ! r3 = str_a_byte - str_b_byte
    mov.l @r15+, r5                     ! restore r5
    mov r3, r0                          ! r0 = difference (return value)
    mov.l @r15+, r4                     ! restore r4
    rts                                 ! return
    mov.l @r15+, r3                     ! restore r3 (delay slot)
.L_strcmp_aligned:                      ! --- fast path: both pointers word-aligned ---
    .byte   0xD3, 0x01    /* mov.l .L_fn_strcmp_word, r3 */
    jmp @r3                             ! tail-call palette_regs_config (word-aligned strcmp)
    nop                                 ! (delay slot)
    .2byte  0x0009                      ! alignment pad (nop encoding)
.L_fn_strcmp_word:
    .4byte  palette_regs_config         ! → word-aligned strcmp implementation

    .global sym_06036D78
sym_06036D78:                           ! memset: fill r6 bytes at r4 with byte r5
    mov #0x0, r7                        ! r7 = 0 (loop counter)
    mov r7, r3                          ! r3 = 0 (copy of counter for initial check)
    cmp/hs r6, r3                       ! count == 0? (0 >= count unsigned)
    bt/s    .L_memset_done             ! yes → nothing to do
    mov r4, r0                          ! r0 = dst (delay slot; also return value)
.L_memset_loop:
    extu.b r5, r2                       ! r2 = fill_byte zero-extended to 32 bits
    add #0x1, r7                        ! r7++ (increment counter)
    mov.b r2, @r0                       ! *dst = fill_byte
    cmp/hs r6, r7                       ! counter >= count?
    bf/s    .L_memset_loop             ! no → continue loop
    add #0x1, r0                        ! dst++ (delay slot)
.L_memset_done:
    rts                                 ! return
    mov r4, r0                          ! r0 = original dst (delay slot; return value)
    .2byte  0x0000                      ! alignment pad

    .global sym_06036D94
sym_06036D94:                           ! memcmp: compare r6 bytes at r4 vs r5
    tst r6, r6                          ! count == 0?
    bf/s    .L_memcmp_start            ! no → begin comparison
    mov r5, r7                          ! r7 = buf_b (delay slot)
    rts                                 ! count is 0 → return 0 (equal)
    mov #0x0, r0                        ! r0 = 0 (delay slot; return value)
.L_memcmp_start:
    mov #0x0, r5                        ! r5 = 0 (loop counter)
    mov r5, r3                          ! r3 = 0 (copy of counter for initial check)
    cmp/hs r6, r3                       ! counter >= count? (should always be false here)
    bt      .L_memcmp_result           ! yes → skip to result (defensive check)
.L_memcmp_loop:
    mov.b @r4+, r2                      ! r2 = *buf_a++
    mov.b @r7+, r1                      ! r1 = *buf_b++
    extu.b r2, r2                       ! zero-extend buf_a byte
    extu.b r1, r1                       ! zero-extend buf_b byte
    cmp/eq r1, r2                       ! bytes equal?
    bf      .L_memcmp_result           ! no → mismatch, go compute result
    mov r4, r2                          ! r2 = current buf_a pointer
    add #-0x1, r2                       ! back up to byte just read
    mov.b @r2, r3                       ! r3 = re-read byte (check for null/sentinel)
    extu.b r3, r3                       ! zero-extend
    tst r3, r3                          ! byte == 0?
    bf      .L_memcmp_continue         ! no → keep going
    bra     .L_memcmp_result           ! yes → end comparison (null reached)
    nop                                 ! (delay slot)
.L_memcmp_continue:
    add #0x1, r5                        ! r5++ (increment counter)
    cmp/hs r6, r5                       ! counter >= count?
    bf      .L_memcmp_loop             ! no → continue loop
.L_memcmp_result:
    mov r4, r0                          ! r0 → buf_a (current position)
    add #-0x1, r0                       ! back up to last-read byte
    mov.b @r0, r0                       ! r0 = last buf_a byte
    extu.b r0, r0                       ! zero-extend
    add #-0x1, r7                       ! back up buf_b pointer
    mov.b @r7, r3                       ! r3 = last buf_b byte
    extu.b r3, r3                       ! zero-extend
    sub r3, r0                          ! r0 = buf_a_byte - buf_b_byte (return value)
    rts                                 ! return
    nop                                 ! (delay slot)
