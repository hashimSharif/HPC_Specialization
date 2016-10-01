	.text
	.file	"custom_tests/bc/MPI_ping.bc"
	.globl	placeHolder
	.align	16, 0x90
	.type	placeHolder,@function
placeHolder:                            # @placeHolder
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	$.L.str, %edi
	movl	$10, %esi
	xorl	%eax, %eax
	callq	printf
	popq	%rbp
	retq
.Lfunc_end0:
	.size	placeHolder, .Lfunc_end0-placeHolder
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$4000136, %rsp          # imm = 0x3D0988
.Ltmp6:
	.cfi_offset %rbx, -56
.Ltmp7:
	.cfi_offset %r12, -48
.Ltmp8:
	.cfi_offset %r13, -40
.Ltmp9:
	.cfi_offset %r14, -32
.Ltmp10:
	.cfi_offset %r15, -24
	movl	$0, -44(%rbp)
	movl	%edi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movl	$42, -76(%rbp)
	movl	$500, -80(%rbp)         # imm = 0x1F4
	leaq	-48(%rbp), %rdi
	leaq	-56(%rbp), %rsi
	callq	MPI_Init
	leaq	-68(%rbp), %rsi
	movl	$1140850688, %edi       # imm = 0x44000000
	callq	MPI_Comm_size
	leaq	-72(%rbp), %rsi
	movl	$1140850688, %edi       # imm = 0x44000000
	callq	MPI_Comm_rank
	movl	$0, -4000164(%rbp)
	leaq	-4000160(%rbp), %rbx
	leaq	-108(%rbp), %r15
	leaq	-136(%rbp), %r12
	leaq	-128(%rbp), %r13
	leaq	-4000168(%rbp), %r14
	jmp	.LBB1_1
	.align	16, 0x90
.LBB1_11:                               # %if.else
                                        #   in Loop: Header=BB1_1 Depth=1
	movl	$.L.str.4, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-76(%rbp), %r8d
	movq	%r12, (%rsp)
	movl	$1000000, %esi          # imm = 0xF4240
	movl	$1275069445, %edx       # imm = 0x4C000405
	xorl	%ecx, %ecx
	movl	$1140850688, %r9d       # imm = 0x44000000
	movq	%rbx, %rdi
	callq	MPI_Isend
	callq	placeHolder
	movq	%r12, %rdi
	movq	%r13, %rsi
	callq	MPI_Wait
	callq	placeHolder
	movl	$0, -4000168(%rbp)
	movl	$.L__unnamed_1, %edi
	movl	$1, %esi
	movl	$.omp_outlined., %edx
	xorl	%eax, %eax
	movq	%r14, %rcx
	callq	__kmpc_fork_call
	incl	-4000164(%rbp)
.LBB1_1:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_8 Depth 2
	movl	-4000164(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jge	.LBB1_5
# BB#2:                                 # %for.body
                                        #   in Loop: Header=BB1_1 Depth=1
	cmpl	$2, -68(%rbp)
	jne	.LBB1_3
# BB#6:                                 # %if.end8
                                        #   in Loop: Header=BB1_1 Depth=1
	movl	-72(%rbp), %eax
	movl	%eax, -64(%rbp)
	cmpl	$0, -72(%rbp)
	jne	.LBB1_11
# BB#7:                                 # %if.then10
                                        #   in Loop: Header=BB1_1 Depth=1
	movl	-72(%rbp), %esi
	movl	$.L.str.2, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$1, -60(%rbp)
	jmp	.LBB1_8
	.align	16, 0x90
.LBB1_9:                                # %for.inc
                                        #   in Loop: Header=BB1_8 Depth=2
	movl	-60(%rbp), %esi
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-76(%rbp), %r8d
	movslq	-60(%rbp), %rax
	leaq	-144(%rbp,%rax,4), %rax
	movq	%rax, (%rsp)
	movl	$1000000, %esi          # imm = 0xF4240
	movl	$1275069445, %edx       # imm = 0x4C000405
	movl	$-2, %ecx
	movl	$1140850688, %r9d       # imm = 0x44000000
	movq	%rbx, %rdi
	callq	MPI_Irecv
	incl	-60(%rbp)
.LBB1_8:                                # %for.cond12
                                        #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-60(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.LBB1_9
# BB#10:                                # %for.end
                                        #   in Loop: Header=BB1_1 Depth=1
	callq	placeHolder
	movl	-68(%rbp), %edi
	decl	%edi
	leaq	-140(%rbp), %rsi
	movq	%r15, %rdx
	callq	MPI_Waitall
	incl	-4000164(%rbp)
	jmp	.LBB1_1
.LBB1_3:                                # %if.then
	cmpl	$0, -72(%rbp)
	jne	.LBB1_5
# BB#4:                                 # %if.then5
	movl	$.L.str.1, %edi
	movl	$2, %esi
	xorl	%eax, %eax
	callq	printf
.LBB1_5:                                # %if.end
	callq	MPI_Finalize
	xorl	%edi, %edi
	callq	exit
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined.,@function
.omp_outlined.:                         # @.omp_outlined.
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp11:
	.cfi_def_cfa_offset 16
.Ltmp12:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp13:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$96, %rsp
.Ltmp14:
	.cfi_offset %rbx, -32
.Ltmp15:
	.cfi_offset %r14, -24
	movq	%rdx, %r14
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%r14, -40(%rbp)
	movl	LOOPCOUNT(%rip), %eax
	decl	%eax
	movl	%eax, -48(%rbp)
	movl	$1, -52(%rbp)
	cmpl	$0, LOOPCOUNT(%rip)
	jle	.LBB2_13
# BB#1:                                 # %omp.precond.then
	movl	$0, -56(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	$1, -64(%rbp)
	movl	$0, -68(%rbp)
	movl	$0, -76(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %esi
	leaq	-64(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-68(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-60(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$33, %edx
	callq	__kmpc_for_static_init_4
	jmp	.LBB2_2
	.align	16, 0x90
.LBB2_8:                                # %omp.dispatch.inc
                                        #   in Loop: Header=BB2_2 Depth=1
	movl	-64(%rbp), %eax
	addl	%eax, -56(%rbp)
	movl	-64(%rbp), %eax
	addl	%eax, -60(%rbp)
.LBB2_2:                                # %omp.dispatch.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_6 Depth 2
	movl	-60(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jle	.LBB2_4
# BB#3:                                 # %cond.true
                                        #   in Loop: Header=BB2_2 Depth=1
	movl	-48(%rbp), %eax
	jmp	.LBB2_5
	.align	16, 0x90
.LBB2_4:                                # %cond.false
                                        #   in Loop: Header=BB2_2 Depth=1
	movl	-60(%rbp), %eax
.LBB2_5:                                # %cond.end
                                        #   in Loop: Header=BB2_2 Depth=1
	movl	%eax, -60(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -44(%rbp)
	cmpl	-60(%rbp), %eax
	jle	.LBB2_6
	jmp	.LBB2_9
	.align	16, 0x90
.LBB2_7:                                # %omp.inner.for.inc
                                        #   in Loop: Header=BB2_6 Depth=2
	movl	-44(%rbp), %eax
	incl	%eax
	movl	%eax, -72(%rbp)
	addl	%eax, -76(%rbp)
	incl	-44(%rbp)
.LBB2_6:                                # %omp.inner.for.cond
                                        #   Parent Loop BB2_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-44(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jle	.LBB2_7
	jmp	.LBB2_8
.LBB2_9:                                # %omp.dispatch.end
	movq	-24(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-76(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-88(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB2_12
# BB#10:                                # %omp.dispatch.end
	cmpl	$1, %eax
	jne	.LBB2_13
# BB#11:                                # %.omp.reduction.case1
	movl	-76(%rbp), %eax
	addl	%eax, (%r14)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB2_13
.LBB2_12:                               # %.omp.reduction.case2
	movl	-76(%rbp), %eax
	lock		addl	%eax, (%r14)
.LBB2_13:                               # %omp.precond.end
	addq	$96, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
.Lfunc_end2:
	.size	.omp_outlined., .Lfunc_end2-.omp_outlined.
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func,@function
.omp.reduction.reduction_func:          # @.omp.reduction.reduction_func
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp16:
	.cfi_def_cfa_offset 16
.Ltmp17:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp18:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movl	(%rcx), %ecx
	addl	%ecx, (%rax)
	popq	%rbp
	retq
.Lfunc_end3:
	.size	.omp.reduction.reduction_func, .Lfunc_end3-.omp.reduction.reduction_func
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"placeHolder func %d \n"
	.size	.L.str, 22

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"You have to use at lest 2 and at most %d processes\n"
	.size	.L.str.1, 52

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Process %d receiving from all other processes\n"
	.size	.L.str.2, 47

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Master posting Irecv for process %d\n"
	.size	.L.str.3, 37

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"Process 1 sending to Process 0 \n"
	.size	.L.str.4, 33

	.type	LOOPCOUNT,@object       # @LOOPCOUNT
	.data
	.globl	LOOPCOUNT
	.align	4
LOOPCOUNT:
	.long	1000                    # 0x3e8
	.size	LOOPCOUNT, 4

	.type	.L.str.5,@object        # @.str.5
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.5:
	.asciz	";unknown;unknown;0;0;;"
	.size	.L.str.5, 23

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata,"a",@progbits
	.align	8
.L__unnamed_1:
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str.5
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
	.quad	.L.str.5
	.size	.L__unnamed_2, 24


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
