	.text
	.file	"test9.c"
	.globl	test_omp_parallel_for_private
	.align	16, 0x90
	.type	test_omp_parallel_for_private,@function
test_omp_parallel_for_private:          # @test_omp_parallel_for_private
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movabsq	$.L__unnamed_1, %rdi
	movl	$2, %esi
	movabsq	$.omp_outlined., %rax
	leaq	-20(%rbp), %rcx
	leaq	-4(%rbp), %r8
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	movl	$1000, -20(%rbp)        # imm = 0x3E8
	movq	%rax, %rdx
	movb	$0, %al
	callq	__kmpc_fork_call
	movl	$2, %esi
	movl	-20(%rbp), %r9d
	movl	-20(%rbp), %r10d
	addl	$1, %r10d
	imull	%r10d, %r9d
	movl	%r9d, %eax
	cltd
	idivl	%esi
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-4(%rbp), %eax
	sete	%r11b
	andb	$1, %r11b
	movzbl	%r11b, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	test_omp_parallel_for_private, .Lfunc_end0-test_omp_parallel_for_private
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined.,@function
.omp_outlined.:                         # @.omp_outlined.
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movl	$1, %eax
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rcx
	movq	-32(%rbp), %rdx
	movl	(%rcx), %r8d
	subl	$1, %r8d
	addl	$1, %r8d
	movl	%eax, -92(%rbp)         # 4-byte Spill
	movl	%r8d, %eax
	movq	%rdx, -104(%rbp)        # 8-byte Spill
	cltd
	movl	-92(%rbp), %r8d         # 4-byte Reload
	idivl	%r8d
	subl	$1, %eax
	movl	%eax, -40(%rbp)
	movl	$1, -44(%rbp)
	cmpl	(%rcx), %r8d
	jg	.LBB1_17
# BB#1:
	movabsq	$.L__unnamed_1, %rdi
	movl	$33, %edx
	leaq	-60(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-52(%rbp), %r9
	leaq	-56(%rbp), %rax
	movl	$1, %esi
	movl	$0, -48(%rbp)
	movl	-40(%rbp), %r10d
	movl	%r10d, -52(%rbp)
	movl	$1, -56(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -72(%rbp)
	movq	-8(%rbp), %r11
	movl	(%r11), %r10d
	movl	%esi, -108(%rbp)        # 4-byte Spill
	movl	%r10d, %esi
	movq	%rax, (%rsp)
	movl	$1, 8(%rsp)
	movl	$1, 16(%rsp)
	callq	__kmpc_for_static_init_4
.LBB1_2:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_7 Depth 2
	movl	-52(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jle	.LBB1_4
# BB#3:                                 #   in Loop: Header=BB1_2 Depth=1
	movl	-40(%rbp), %eax
	movl	%eax, -112(%rbp)        # 4-byte Spill
	jmp	.LBB1_5
.LBB1_4:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-52(%rbp), %eax
	movl	%eax, -112(%rbp)        # 4-byte Spill
.LBB1_5:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-112(%rbp), %eax        # 4-byte Reload
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.LBB1_13
# BB#6:                                 #   in Loop: Header=BB1_2 Depth=1
	jmp	.LBB1_7
.LBB1_7:                                #   Parent Loop BB1_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-36(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.LBB1_11
# BB#8:                                 #   in Loop: Header=BB1_7 Depth=2
	movabsq	$.L__unnamed_1, %rdi
	movl	-36(%rbp), %eax
	shll	$0, %eax
	addl	$1, %eax
	movl	%eax, -64(%rbp)
	movl	-64(%rbp), %eax
	movl	%eax, -68(%rbp)
	callq	__kmpc_flush
	callq	do_some_work
	movabsq	$.L__unnamed_1, %rdi
	callq	__kmpc_flush
	movl	-72(%rbp), %eax
	addl	-68(%rbp), %eax
	movl	%eax, -72(%rbp)
# BB#9:                                 #   in Loop: Header=BB1_7 Depth=2
	jmp	.LBB1_10
.LBB1_10:                               #   in Loop: Header=BB1_7 Depth=2
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	.LBB1_7
.LBB1_11:                               #   in Loop: Header=BB1_2 Depth=1
	jmp	.LBB1_12
.LBB1_12:                               #   in Loop: Header=BB1_2 Depth=1
	movl	-48(%rbp), %eax
	addl	-56(%rbp), %eax
	movl	%eax, -48(%rbp)
	movl	-52(%rbp), %eax
	addl	-56(%rbp), %eax
	movl	%eax, -52(%rbp)
	jmp	.LBB1_2
.LBB1_13:
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %ecx
	movl	%ecx, %edi
	callq	__kmpc_for_static_fini
	leaq	-72(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %ecx
	movq	%rsp, %rax
	movq	$.gomp_critical_user_.reduction.var, (%rax)
	movl	$.L__unnamed_2, %esi
	movl	%esi, %edi
	movl	$.omp.reduction.reduction_func, %esi
	movl	%esi, %r9d
	movl	$8, %esi
	movl	%esi, %eax
	movl	$1, %edx
	leaq	-88(%rbp), %r8
	movl	%ecx, %esi
	movl	%ecx, -116(%rbp)        # 4-byte Spill
	movq	%rax, %rcx
	callq	__kmpc_reduce_nowait
	movl	%eax, %edx
	subl	$1, %eax
	movl	%edx, -120(%rbp)        # 4-byte Spill
	movl	%eax, -124(%rbp)        # 4-byte Spill
	je	.LBB1_14
	jmp	.LBB1_18
.LBB1_18:
	movl	-120(%rbp), %eax        # 4-byte Reload
	subl	$2, %eax
	movl	%eax, -128(%rbp)        # 4-byte Spill
	je	.LBB1_15
	jmp	.LBB1_16
.LBB1_14:
	movabsq	$.L__unnamed_2, %rdi
	movabsq	$.gomp_critical_user_.reduction.var, %rdx
	movq	-104(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	addl	-72(%rbp), %ecx
	movl	%ecx, (%rax)
	movl	-116(%rbp), %esi        # 4-byte Reload
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB1_16
.LBB1_15:
	movl	-72(%rbp), %eax
	movq	-104(%rbp), %rcx        # 8-byte Reload
	lock		addl	%eax, (%rcx)
.LBB1_16:
	jmp	.LBB1_17
.LBB1_17:
	addq	$160, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	.omp_outlined., .Lfunc_end1-.omp_outlined.
	.cfi_endproc

	.align	16, 0x90
	.type	do_some_work,@function
do_some_work:                           # @do_some_work
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorps	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$0, -4(%rbp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$10, -4(%rbp)
	jge	.LBB2_4
# BB#2:                                 #   in Loop: Header=BB2_1 Depth=1
	cvtsi2sdl	-4(%rbp), %xmm0
	callq	sqrt
	addsd	-16(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
# BB#3:                                 #   in Loop: Header=BB2_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB2_1
.LBB2_4:
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end2:
	.size	do_some_work, .Lfunc_end2-do_some_work
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func,@function
.omp.reduction.reduction_func:          # @.omp.reduction.reduction_func
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp11:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	movl	(%rsi), %eax
	addl	(%rdi), %eax
	movl	%eax, (%rsi)
	popq	%rbp
	retq
.Lfunc_end3:
	.size	.omp.reduction.reduction_func, .Lfunc_end3-.omp.reduction.reduction_func
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp12:
	.cfi_def_cfa_offset 16
.Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	movl	$1, -16(%rbp)
	movl	$0, -8(%rbp)
.LBB4_1:                                # =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	.LBB4_6
# BB#2:                                 #   in Loop: Header=BB4_1 Depth=1
	callq	test_omp_parallel_for_private
	cmpl	$0, %eax
	jne	.LBB4_4
# BB#3:                                 #   in Loop: Header=BB4_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
.LBB4_4:                                #   in Loop: Header=BB4_1 Depth=1
	jmp	.LBB4_5
.LBB4_5:                                #   in Loop: Header=BB4_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.LBB4_1
.LBB4_6:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end4:
	.size	main, .Lfunc_end4-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	";unknown;unknown;0;0;;"
	.size	.L.str, 23

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata,"a",@progbits
	.align	8
.L__unnamed_1:
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str
	.size	.L__unnamed_1, 24

	.type	.gomp_critical_user_.reduction.var,@object # @.gomp_critical_user_.reduction.var
	.comm	.gomp_critical_user_.reduction.var,32,16
	.type	.L__unnamed_2,@object   # @1
	.align	8
.L__unnamed_2:
	.long	0                       # 0x0
	.long	18                      # 0x12
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str
	.size	.L__unnamed_2, 24


	.ident	"clang version 3.8.0-svn262614-1~exp1 (branches/release_38)"
	.section	".note.GNU-stack","",@progbits
