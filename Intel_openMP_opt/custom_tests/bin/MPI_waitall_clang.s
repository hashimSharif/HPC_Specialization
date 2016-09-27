	.file	"MPI_waitall.c"
	.globl	LOOPCOUNT
	.data
	.align 4
	.type	LOOPCOUNT, @object
	.size	LOOPCOUNT, 4
LOOPCOUNT:
	.long	1000
	.section	.rodata
	.align 8
.LC0:
	.string	"You have to use at lest 2 and at most %d processes\n"
	.align 8
.LC1:
	.string	"Process %d sending to all other processes\n"
.LC2:
	.string	"Process %d sending to %d\n"
	.align 8
.LC3:
	.string	"Process %d receiving from all other processes\n"
	.align 8
.LC4:
	.string	"Process %d received a message from process %d\n"
.LC5:
	.string	"Process %d ready\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$304, %rsp
	movl	%edi, -292(%rbp)
	movq	%rsi, -304(%rbp)
	movl	$42, -8(%rbp)
	leaq	-304(%rbp), %rdx
	leaq	-292(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	MPI_Init
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$1140850688, %edi
	call	MPI_Comm_size
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	movl	$1140850688, %edi
	call	MPI_Comm_rank
	movl	-24(%rbp), %eax
	cmpl	$1, %eax
	jle	.L2
	movl	-24(%rbp), %eax
	cmpl	$8, %eax
	jle	.L3
.L2:
	movl	-28(%rbp), %eax
	testl	%eax, %eax
	jne	.L4
	movl	$8, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L4:
	call	MPI_Finalize
	movl	$0, %edi
	call	exit
.L3:
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-28(%rbp), %eax
	testl	%eax, %eax
	jne	.L5
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-28(%rbp), %eax
	movl	-4(%rbp), %edx
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leaq	-224(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rsi
	subq	$8, %rsp
	movl	-8(%rbp), %ecx
	movl	-4(%rbp), %edx
	leaq	-20(%rbp), %rax
	pushq	%rsi
	movl	$1140850688, %r9d
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	$1275069445, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	MPI_Isend
	addq	$16, %rsp
	addl	$1, -4(%rbp)
.L6:
	movl	-24(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L7
	movl	-24(%rbp), %eax
	subl	$1, %eax
	leaq	-192(%rbp), %rdx
	addq	$20, %rdx
	leaq	-224(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	MPI_Waitall
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -4(%rbp)
	jmp	.L8
.L9:
	leaq	-256(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rcx
	leaq	-288(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	subq	$8, %rsp
	movl	-8(%rbp), %edx
	pushq	%rcx
	movl	$1140850688, %r9d
	movl	%edx, %r8d
	movl	$-2, %ecx
	movl	$1275069445, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	MPI_Irecv
	addq	$16, %rsp
	addl	$1, -4(%rbp)
.L8:
	movl	-24(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L9
	movl	-24(%rbp), %eax
	subl	$1, %eax
	leaq	-192(%rbp), %rdx
	addq	$20, %rdx
	leaq	-256(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	MPI_Waitall
	movl	$1, -4(%rbp)
	jmp	.L10
.L11:
	movl	-4(%rbp), %eax
	cltq
	movl	-288(%rbp,%rax,4), %edx
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L10:
	movl	-24(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L11
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L12
.L5:
	subq	$8, %rsp
	movl	-8(%rbp), %ecx
	leaq	-288(%rbp), %rax
	leaq	-256(%rbp), %rdx
	pushq	%rdx
	movl	$1140850688, %r9d
	movl	%ecx, %r8d
	movl	$0, %ecx
	movl	$1275069445, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	MPI_Irecv
	addq	$16, %rsp
	leaq	-192(%rbp), %rdx
	leaq	-256(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	MPI_Wait
	subq	$8, %rsp
	movl	-8(%rbp), %ecx
	leaq	-20(%rbp), %rax
	leaq	-224(%rbp), %rdx
	pushq	%rdx
	movl	$1140850688, %r9d
	movl	%ecx, %r8d
	movl	$0, %ecx
	movl	$1275069445, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	MPI_Isend
	addq	$16, %rsp
	leaq	-192(%rbp), %rdx
	leaq	-224(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	MPI_Wait
.L12:
	call	MPI_Finalize
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.type	main._omp_fn.0, @function
main._omp_fn.0:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -40(%rbp)
	movl	$0, -20(%rbp)
	movl	LOOPCOUNT(%rip), %ebx
	call	omp_get_num_threads
	movl	%eax, %r12d
	call	omp_get_thread_num
	movl	%eax, %edi
	leal	1(%rbx), %eax
	leal	-1(%rax), %edx
	movl	$0, %ecx
.L16:
	movl	%ecx, %eax
	imull	%r12d, %eax
	addl	%edi, %eax
	leal	1(%rax), %esi
	cmpl	%edx, %esi
	cmovg	%edx, %esi
	cmpl	%edx, %eax
	jge	.L14
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	addl	$1, %esi
.L15:
	movl	-24(%rbp), %eax
	addl	%eax, -20(%rbp)
	addl	$1, -24(%rbp)
	cmpl	%esi, -24(%rbp)
	jl	.L15
	addl	$1, %ecx
	jmp	.L16
.L14:
	movq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	lock addl	%edx, (%rax)
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (GNU) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
