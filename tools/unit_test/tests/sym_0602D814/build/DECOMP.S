
! Hitachi SH cc1 (cygnus-2.7-96q3 SOA-960904) arguments: -O -fdefer-pop
! -fomit-frame-pointer -fcse-follow-jumps -fcse-skip-blocks
! -fexpensive-optimizations -fthread-jumps -fstrength-reduce -fpeephole
! -fforce-mem -ffunction-cse -finline -fkeep-static-consts -fcaller-saves
! -freg-struct-return -fdelayed-branch -frerun-cse-after-loop
! -fschedule-insns2 -fcommon -fgnu-linker

    .section .text.sym_0602D814
	.align 2
	.global sym_0602D814
sym_0602D814:
	mov.w	.L_c_L10,r3
	mov.l	@(12,r4),r2
	mov	r4,r0
	mov.l	@(r0,r3),r1
	add	r1,r2
	mov.l	r2,@(12,r4)
	cmp/pz	r2
	bt	.L_c_L3
	mov	#0,r1
	mov.l	r1,@(12,r4)
	mov.l	r1,@(r0,r3)
.L_c_L3:
	mov.w	.L_c_L11,r1
	mov	r4,r0
	mov.w	@(r0,r1),r3
	mov.l	@(12,r4),r2
	shll2	r3
	mov.l	.L_c_L12,r1
	mov	r3,r0
	mov.l	@(r0,r1),r1
	dmuls.l r2,r1
	sts mach,r2
	sts macl,r1
	shll16	r2
	shlr16	r1
	or	r1,r2
	mov.l	.L_c_L13,r0
	dmuls.l r2,r0
	sts mach,r2
	sts macl,r1
	extu.w	r2,r3
	mov	r3,r2
	cmp/pl	r3
	bt	.L_c_L6
	bra	.L_c_L7
	mov	#0,r2
.L_c_L6:
	mov.w	.L_c_L14,r1
	cmp/gt	r1,r3
	bf	.L_c_L7
	mov	r1,r2
.L_c_L7:
	mov.w	.L_c_L15,r1
	mov	r4,r0
	mov.l	r2,@(r0,r1)
	sub	r2,r3
	mov	r3,r2
	cmp/pz	r2
	bt	.L_c_L9
	mov	#0,r2
.L_c_L9:
	mov.w	.L_c_L16,r1
	mov	r4,r0
	rts	
	mov.l	r2,@(r0,r1)
	.align 1
.L_c_L10:
	.2byte 252
.L_c_L11:
	.2byte 220
.L_c_L14:
	.2byte 8500
.L_c_L15:
	.2byte 224
.L_c_L16:
	.2byte 232
.L_c_L17:
	.align 2
.L_c_L12:
	.4byte sym_060477BC
.L_c_L13:
	.long	35761297
