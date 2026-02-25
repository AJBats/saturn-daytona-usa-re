/* geom_display_handler -- Geometry display list dispatcher
 * Translation unit: 0x0601FE20 - 0x0601FEC0
 *
 * Iterates over all active cars and submits their geometry to the
 * display pipeline via geom_final_output.
 *
 * Flow:
 *   1. Load display list descriptor from sym_060877F4 (indirect).
 *   2. Copy descriptor+4 to sym_060877FC (display list data word).
 *   3. Store (car_count - 1) to sym_0607EA98 as loop bound.
 *   4. Call obj_list_state_reset (sym_060054EA) with descriptor+8.
 *   5. Zero the entry count (sym_06087800) and iteration counter
 *      (sym_06087802).
 *   6. Loop over each car index 0..car_count-1:
 *        a. Compute car struct address = car_array_base + index * 0x0268.
 *        b. Store into current_car_ptr (sym_0607E940).
 *        c. Call geom_final_output with display list entry (r13).
 *        d. Advance display list entry by 8 bytes.
 *   7. Call car_ptr_list_init (sym_0600D280) to rebuild sorted lists.
 *   8. Set handler mode (sym_06087804) = 2.
 *
 * Persistent registers:
 *   r9  = &current_car_ptr (sym_0607E940)
 *   r10 = car_array_base (sym_06078900)
 *   r11 = &car_count_store (sym_0607EA98, loop bound)
 *   r12 = 0x0268 (car struct stride)
 *   r13 = display list entry pointer (advanced per car)
 *   r14 = loop counter (car index)
 */

    .section .text.FUN_0601FE20


    .global geom_display_handler
    .type geom_display_handler, @function
geom_display_handler:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    mov.l r13, @-r15                       ! save r13 (callee-saved)
    mov.l r12, @-r15                       ! save r12 (callee-saved)
    mov.l r11, @-r15                       ! save r11 (callee-saved)
    mov.l r10, @-r15                       ! save r10 (callee-saved)
    mov.l r9, @-r15                        ! save r9 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    sts.l macl, @-r15                      ! save macl (will use mul.l)
    mov.l   .L_ptr_current_car, r9         ! r9 = &current_car_ptr (sym_0607E940)
    mov.l   .L_ptr_car_array_base, r10     ! r10 = car_array_base (sym_06078900)
    mov.l   .L_ptr_car_count_store, r11    ! r11 = &car_count_store (sym_0607EA98)
    mov.w   .L_car_struct_stride, r12      ! r12 = 0x0268 (car struct stride = 616 bytes)
    mov.l   .L_ptr_disp_list_desc, r14     ! r14 = &display_list_desc_ptr (sym_060877F4)
    mov.l   .L_ptr_disp_data_word, r2      ! r2 = &display_data_word (sym_060877FC)
    mov.l @r14, r14                        ! r14 = display_list_desc (dereference pointer)
    mov.l @(4, r14), r3                    ! r3 = desc[1] (display list data word)
    mov.l r3, @r2                          ! display_data_word = desc[1]
    mov.l @r14, r3                         ! r3 = desc[0] (total car count)
    add #-0x1, r3                          ! r3 = car_count - 1 (loop bound, inclusive)
    mov.l r3, @r11                         ! car_count_store = car_count - 1
    mov.l   .L_ptr_fn_obj_list_reset, r3   ! r3 = &obj_list_state_reset (sym_060054EA)
    jsr @r3                                ! call obj_list_state_reset(r4=desc[2])
    mov.l @(8, r14), r4                    ! (delay slot) r4 = desc[2] (object list head)
    mov.l @(12, r14), r13                  ! r13 = desc[3] (first display list entry ptr)
    mov #0x0, r4                           ! r4 = 0 (will zero counters)
    extu.w r4, r2                          ! r2 = 0 (16-bit zero)
    mov.l   .L_ptr_entry_count, r3         ! r3 = &entry_count (sym_06087800)
    mov.w r2, @r3                          ! entry_count = 0
    extu.w r4, r1                          ! r1 = 0 (16-bit zero)
    mov.l   .L_ptr_iter_counter, r3        ! r3 = &iteration_counter (sym_06087802)
    mov.w r1, @r3                          ! iteration_counter = 0
    bra     .L_loop_test                   ! jump to loop condition check
    mov r4, r14                            ! (delay slot) r14 = 0 (loop counter init)
.L_loop_body:
    mul.l r12, r14                         ! macl = car_index * car_struct_stride
    sts macl, r2                           ! r2 = byte offset into car array
    add r10, r2                            ! r2 = &car_array[car_index]
    mov.l r2, @r9                          ! current_car_ptr = &car_array[car_index]
    .byte   0xB0, 0x29    /* bsr 0x0601FEC0 (external) */  ! call geom_final_output
    mov r13, r4                            ! (delay slot) r4 = display list entry ptr
    add #0x8, r13                          ! advance to next display list entry (+8 bytes)
    add #0x1, r14                          ! car_index++
.L_loop_test:
    mov.l @r11, r2                         ! r2 = car_count - 1 (loop bound)
    cmp/hi r2, r14                         ! car_index > (car_count - 1)?
    bf      .L_loop_body                   ! no -> process next car
    mov.l   .L_ptr_fn_car_list_init, r3    ! r3 = &car_ptr_list_init (sym_0600D280)
    jsr @r3                                ! call car_ptr_list_init (rebuild sorted lists)
    nop                                    ! (delay slot)
    mov #0x2, r2                           ! r2 = 2 (handler mode: processing complete)
    mov.l   .L_ptr_handler_mode, r3        ! r3 = &handler_mode (sym_06087804)
    mov.w r2, @r3                          ! handler_mode = 2
    lds.l @r15+, macl                      ! restore macl
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return
    mov.l @r15+, r14                       ! (delay slot) restore r14
.L_car_struct_stride:
    .2byte  0x0268                         /* car struct stride (616 bytes) */
.L_ptr_current_car:
    .4byte  sym_0607E940                   /* &current_car_ptr (active car) */
.L_ptr_car_array_base:
    .4byte  sym_06078900                   /* car struct array base address */
.L_ptr_car_count_store:
    .4byte  sym_0607EA98                   /* &car_count_store (loop bound) */
.L_ptr_disp_list_desc:
    .4byte  sym_060877F4                   /* &display_list_desc_ptr (indirect) */
.L_ptr_disp_data_word:
    .4byte  sym_060877FC                   /* &display_data_word (from descriptor) */
.L_ptr_fn_obj_list_reset:
    .4byte  sym_060054EA                   /* obj_list_state_reset function */
.L_ptr_entry_count:
    .4byte  sym_06087800                   /* entry count (16-bit) */
.L_ptr_iter_counter:
    .4byte  sym_06087802                   /* iteration counter (16-bit) */
.L_ptr_fn_car_list_init:
    .4byte  sym_0600D280                   /* car_ptr_list_init function */
.L_ptr_handler_mode:
    .4byte  sym_06087804                   /* handler mode (16-bit) */
