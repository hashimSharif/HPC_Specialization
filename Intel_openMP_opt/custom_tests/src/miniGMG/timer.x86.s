	.text
	.file	"timer.x86.bc"
	.globl	CycleTime
	.align	16, 0x90
	.type	CycleTime,@function
CycleTime:                              # @CycleTime
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
	#APP
	rdtsc
	#NO_APP
	movq	%rax, -8(%rbp)
	movq	%rdx, -16(%rbp)
	shlq	$32, %rdx
	orq	-8(%rbp), %rdx
	movq	%rdx, %rax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	CycleTime, .Lfunc_end0-CycleTime
	.cfi_endproc


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
