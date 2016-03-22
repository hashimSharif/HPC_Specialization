	.file	"AtomicMemExample.cpp"
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
	movl	$10, -24(%rbp)
	movl	$6, -20(%rbp)
	movl	$1, -16(%rbp)
	movl	$1, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	-16(%rbp), %edx
        subl	%eax, %edx
        xchg %eax, -12(%rbp)
	movl	%edx, %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
#APP
# 25 "AtomicMemExample.cpp" 1
	SUB %eax, %eax
	add $1, %eax
# 0 "" 2
#NO_APP
	movl	%eax, -12(%rbp)
	movl	$4, -4(%rbp)
	movl	-20(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
