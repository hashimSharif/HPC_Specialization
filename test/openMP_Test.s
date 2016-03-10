	.file	"openMP_Test.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1264, %rsp
	movl	%edi, -1252(%rbp)
	movq	%rsi, -1264(%rbp)
	movl	$0, -1244(%rbp)
	jmp	.L2
.L3:
	cvtsi2sd	-1244(%rbp), %xmm0
	unpcklpd	%xmm0, %xmm0
	cvtpd2ps	%xmm0, %xmm0
	movl	-1244(%rbp), %eax
	cltq
	movss	%xmm0, -800(%rbp,%rax,4)
	movl	-1244(%rbp), %eax
	cltq
	movl	-800(%rbp,%rax,4), %eax
	movl	-1244(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, -1200(%rbp,%rdx,4)
	addl	$1, -1244(%rbp)
.L2:
	cmpl	$99, -1244(%rbp)
	jle	.L3
	movl	$10, -1240(%rbp)
	leaq	-1200(%rbp), %rax
	movq	%rax, -1232(%rbp)
	leaq	-800(%rbp), %rax
	movq	%rax, -1224(%rbp)
	leaq	-400(%rbp), %rax
	movq	%rax, -1216(%rbp)
	movl	-1236(%rbp), %eax
	movl	%eax, -1208(%rbp)
	movl	-1240(%rbp), %eax
	movl	%eax, -1204(%rbp)
	leaq	-1232(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_start
	leaq	-1232(%rbp), %rax
	movq	%rax, %rdi
	call	main._omp_fn.0
	call	GOMP_parallel_end
	movl	-1208(%rbp), %eax
	movl	%eax, -1236(%rbp)
	movl	-1204(%rbp), %eax
	movl	%eax, -1240(%rbp)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"Thread %d starting...\n"
.LC1:
	.string	"Thread %d: c[%d]= %f\n"
.LC2:
	.string	"Number of threads = %d\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	call	omp_get_thread_num
	movl	%eax, -36(%rbp)
	cmpl	$0, -36(%rbp)
	je	.L5
.L9:
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-56(%rbp), %rax
	movl	28(%rax), %eax
	cltq
	leaq	-24(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rcx
	movl	$1, %edx
	movl	$100, %esi
	movl	$0, %edi
	call	GOMP_loop_dynamic_start
	testb	%al, %al
	je	.L6
.L8:
	movq	-32(%rbp), %rax
	movl	%eax, -40(%rbp)
	movq	-24(%rbp), %rax
	movl	%eax, %ebx
.L7:
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm1
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	addss	%xmm1, %xmm0
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	-40(%rbp), %edx
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	addl	$1, -40(%rbp)
	cmpl	%ebx, -40(%rbp)
	jl	.L7
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	GOMP_loop_dynamic_next
	testb	%al, %al
	jne	.L8
.L6:
	call	GOMP_loop_end
	jmp	.L10
.L5:
	call	omp_get_num_threads
	movq	-56(%rbp), %rdx
	movl	%eax, 24(%rdx)
	movq	-56(%rbp), %rax
	movl	24(%rax), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L10:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
