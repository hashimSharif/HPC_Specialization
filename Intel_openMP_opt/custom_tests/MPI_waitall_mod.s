	.text
	.file	"MPI_waitall_mod.bc"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
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
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$408, %rsp              # imm = 0x198
.Ltmp3:
	.cfi_offset %rbx, -40
.Ltmp4:
	.cfi_offset %r14, -32
.Ltmp5:
	.cfi_offset %r15, -24
	movl	$0, -28(%rbp)
	movl	%edi, -32(%rbp)
	movq	%rsi, -40(%rbp)
	movl	$42, -60(%rbp)
	leaq	-32(%rbp), %rdi
	leaq	-40(%rbp), %rsi
	callq	MPI_Init
	leaq	-52(%rbp), %rsi
	movl	$ompi_mpi_comm_world, %edi
	callq	MPI_Comm_size
	leaq	-56(%rbp), %rsi
	movl	$ompi_mpi_comm_world, %edi
	callq	MPI_Comm_rank
	cmpl	$2, -52(%rbp)
	jl	.LBB0_2
# BB#1:
	cmpl	$9, -52(%rbp)
	jge	.LBB0_2
# BB#5:
	movl	-56(%rbp), %eax
	movl	%eax, -48(%rbp)
	cmpl	$0, -56(%rbp)
	jne	.LBB0_16
# BB#6:
	movl	-56(%rbp), %esi
	movl	$.L.str.1, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$1, -44(%rbp)
	leaq	-48(%rbp), %rbx
	jmp	.LBB0_7
	.align	16, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_7 Depth=1
	movl	-56(%rbp), %esi
	movl	-44(%rbp), %edx
	movl	$.L.str.2, %edi
	xorl	%eax, %eax
	callq	printf
	movslq	-44(%rbp), %rcx
	movl	-60(%rbp), %r8d
	leaq	-320(%rbp,%rcx,8), %rax
	movq	%rax, (%rsp)
	movl	$1, %esi
	movl	$ompi_mpi_int, %edx
	movl	$ompi_mpi_comm_world, %r9d
	movq	%rbx, %rdi
	callq	MPI_Isend
	incl	-44(%rbp)
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.LBB0_8
# BB#9:
	movl	-52(%rbp), %edi
	decl	%edi
	leaq	-312(%rbp), %rsi
	leaq	-232(%rbp), %rdx
	callq	MPI_Waitall
	movl	-56(%rbp), %esi
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$1, -44(%rbp)
	jmp	.LBB0_10
	.align	16, 0x90
.LBB0_11:                               #   in Loop: Header=BB0_10 Depth=1
	movslq	-44(%rbp), %rax
	leaq	-416(%rbp,%rax,4), %rdi
	movl	-60(%rbp), %r8d
	leaq	-384(%rbp,%rax,8), %rax
	movq	%rax, (%rsp)
	movl	$1, %esi
	movl	$ompi_mpi_int, %edx
	movl	$-1, %ecx
	movl	$ompi_mpi_comm_world, %r9d
	callq	MPI_Irecv
	incl	-44(%rbp)
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.LBB0_11
# BB#12:
	movl	-52(%rbp), %ebx
	decl	%ebx
	leaq	-376(%rbp), %r14
	leaq	-232(%rbp), %r15
	movl	$0, -420(%rbp)
	leaq	-420(%rbp), %rcx
	movl	$.L__unnamed_1, %edi
	movl	$1, %esi
	movl	$.omp_outlined., %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call_start
	movl	%ebx, %edi
	movq	%r14, %rsi
	movq	%r15, %rdx
	callq	MPI_Waitall
	movl	$1, -44(%rbp)
	jmp	.LBB0_13
	.align	16, 0x90
.LBB0_14:                               #   in Loop: Header=BB0_13 Depth=1
	movl	-56(%rbp), %esi
	movslq	-44(%rbp), %rax
	movl	-416(%rbp,%rax,4), %edx
	movl	$.L.str.4, %edi
	xorl	%eax, %eax
	callq	printf
	incl	-44(%rbp)
.LBB0_13:                               # =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.LBB0_14
# BB#15:
	movl	-56(%rbp), %esi
	movl	$.L.str.5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -420(%rbp)
	callq	__kmpc_fork_call_end
.LBB0_4:
	callq	MPI_Finalize
	xorl	%edi, %edi
	callq	exit
.LBB0_2:
	cmpl	$0, -56(%rbp)
	jne	.LBB0_4
# BB#3:
	movl	$.L.str, %edi
	movl	$8, %esi
	xorl	%eax, %eax
	callq	printf
	jmp	.LBB0_4
.LBB0_16:
	movl	-60(%rbp), %r8d
	leaq	-384(%rbp), %rbx
	movq	%rbx, (%rsp)
	leaq	-416(%rbp), %rdi
	movl	$1, %esi
	movl	$ompi_mpi_int, %edx
	xorl	%ecx, %ecx
	movl	$ompi_mpi_comm_world, %r9d
	callq	MPI_Irecv
	leaq	-256(%rbp), %r14
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	MPI_Wait
	movl	-60(%rbp), %r8d
	leaq	-320(%rbp), %rbx
	movq	%rbx, (%rsp)
	leaq	-48(%rbp), %rdi
	movl	$1, %esi
	movl	$ompi_mpi_int, %edx
	xorl	%ecx, %ecx
	movl	$ompi_mpi_comm_world, %r9d
	callq	MPI_Isend
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	MPI_Wait
	jmp	.LBB0_4
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined.,@function
.omp_outlined.:                         # @.omp_outlined.
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
	pushq	%r14
	pushq	%rbx
	subq	$96, %rsp
.Ltmp9:
	.cfi_offset %rbx, -32
.Ltmp10:
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
	jle	.LBB1_13
# BB#1:
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
	jmp	.LBB1_2
	.align	16, 0x90
.LBB1_8:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-64(%rbp), %eax
	addl	%eax, -56(%rbp)
	movl	-64(%rbp), %eax
	addl	%eax, -60(%rbp)
.LBB1_2:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_6 Depth 2
	movl	-60(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jle	.LBB1_4
# BB#3:                                 #   in Loop: Header=BB1_2 Depth=1
	movl	-48(%rbp), %eax
	jmp	.LBB1_5
	.align	16, 0x90
.LBB1_4:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-60(%rbp), %eax
.LBB1_5:                                #   in Loop: Header=BB1_2 Depth=1
	movl	%eax, -60(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -44(%rbp)
	cmpl	-60(%rbp), %eax
	jle	.LBB1_6
	jmp	.LBB1_9
	.align	16, 0x90
.LBB1_7:                                #   in Loop: Header=BB1_6 Depth=2
	movl	-44(%rbp), %eax
	incl	%eax
	movl	%eax, -72(%rbp)
	addl	%eax, -76(%rbp)
	incl	-44(%rbp)
.LBB1_6:                                #   Parent Loop BB1_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-44(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jle	.LBB1_7
	jmp	.LBB1_8
.LBB1_9:
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
	je	.LBB1_12
# BB#10:
	cmpl	$1, %eax
	jne	.LBB1_13
# BB#11:
	movl	-76(%rbp), %eax
	addl	%eax, (%r14)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB1_13
.LBB1_12:
	movl	-76(%rbp), %eax
	lock		addl	%eax, (%r14)
.LBB1_13:
	addq	$96, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
.Lfunc_end1:
	.size	.omp_outlined., .Lfunc_end1-.omp_outlined.
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func,@function
.omp.reduction.reduction_func:          # @.omp.reduction.reduction_func
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp11:
	.cfi_def_cfa_offset 16
.Ltmp12:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp13:
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
.Lfunc_end2:
	.size	.omp.reduction.reduction_func, .Lfunc_end2-.omp.reduction.reduction_func
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"You have to use at lest 2 and at most %d processes\n"
	.size	.L.str, 52

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Process %d sending to all other processes\n"
	.size	.L.str.1, 43

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Process %d sending to %d\n"
	.size	.L.str.2, 26

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Process %d receiving from all other processes\n"
	.size	.L.str.3, 47

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"Process %d received a message from process %d\n"
	.size	.L.str.4, 47

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"Process %d ready\n"
	.size	.L.str.5, 18

	.type	LOOPCOUNT,@object       # @LOOPCOUNT
	.data
	.globl	LOOPCOUNT
	.align	4
LOOPCOUNT:
	.long	1000                    # 0x3e8
	.size	LOOPCOUNT, 4

	.type	.L.str.6,@object        # @.str.6
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.6:
	.asciz	";unknown;unknown;0;0;;"
	.size	.L.str.6, 23

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata,"a",@progbits
	.align	8
.L__unnamed_1:
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str.6
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
	.quad	.L.str.6
	.size	.L__unnamed_2, 24


	.ident	"clang version 3.8.0-svn262614-1~exp1 (branches/release_38)"
	.section	".note.GNU-stack","",@progbits
