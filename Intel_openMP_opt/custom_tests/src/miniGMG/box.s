	.text
	.file	"box.bc"
	.globl	create_box
	.align	16, 0x90
	.type	create_box,@function
create_box:                             # @create_box
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
	pushq	%rbx
	subq	$88, %rsp
.Ltmp3:
	.cfi_offset %rbx, -24
	movl	32(%rbp), %r10d
	movl	24(%rbp), %ebx
	movl	16(%rbp), %eax
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movl	%edx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	%r8d, -32(%rbp)
	movl	%r9d, -36(%rbp)
	movl	%eax, -40(%rbp)
	movl	%ebx, -44(%rbp)
	movl	%r10d, -48(%rbp)
	movq	$0, -56(%rbp)
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 60(%rcx)
	movl	-24(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 8(%rcx)
	movl	-28(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 12(%rcx)
	movl	-32(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 16(%rcx)
	movl	-36(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 20(%rcx)
	movl	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 24(%rcx)
	movl	-44(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 28(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-36(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 32(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 36(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-44(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 40(%rcx)
	movl	-48(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 44(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-36(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 48(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	movl	-36(%rbp), %ecx
	addl	%eax, %ecx
	addl	-40(%rbp), %eax
	imull	%ecx, %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 52(%rcx)
	movl	$16, -60(%rbp)
	movl	$0, -64(%rbp)
	movq	-16(%rbp), %rax
	movl	48(%rax), %eax
	incl	%eax
	movl	-60(%rbp), %ecx
	decl	%ecx
	cmpl	%ecx, %eax
	jge	.LBB0_2
# BB#1:                                 # %if.then
	movl	-60(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	48(%rcx), %ecx
	incl	%ecx
	negl	%ecx
	leal	-1(%rax,%rcx), %eax
	movl	%eax, -64(%rbp)
.LBB0_2:                                # %if.end
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	imull	48(%rcx), %eax
	movl	-64(%rbp), %edx
	leal	7(%rax,%rdx), %eax
	andl	$-8, %eax
	movl	%eax, 52(%rcx)
	movl	-48(%rbp), %eax
	addl	%eax, %eax
	addl	-44(%rbp), %eax
	movq	-16(%rbp), %rcx
	imull	52(%rcx), %eax
	movl	%eax, 56(%rcx)
	cmpl	$32, -36(%rbp)
	jl	.LBB0_5
	jmp	.LBB0_3
	.align	16, 0x90
.LBB0_4:                                # %while.body
                                        #   in Loop: Header=BB0_3 Depth=1
	movq	-16(%rbp), %rax
	addl	$8, 56(%rax)
.LBB0_3:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movl	56(%rax), %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$23, %ecx
	addl	%eax, %ecx
	andl	$-512, %ecx             # imm = 0xFFFFFFFFFFFFFE00
	subl	%ecx, %eax
	cmpl	$64, %eax
	jne	.LBB0_4
.LBB0_5:                                # %if.end49
	movq	-16(%rbp), %rdi
	movslq	60(%rdi), %rdx
	addq	$176, %rdi
	shlq	$3, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movq	-16(%rbp), %rax
	movslq	60(%rax), %rax
	shlq	$3, %rax
	addq	%rax, -56(%rbp)
	movq	-16(%rbp), %rax
	movslq	56(%rax), %rcx
	movslq	60(%rax), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	leaq	-72(%rbp), %rdi
	movl	$64, %esi
	callq	posix_memalign
	movq	-72(%rbp), %rdi
	movq	-16(%rbp), %rax
	movslq	56(%rax), %rcx
	movslq	60(%rax), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	memset
	movq	-16(%rbp), %rax
	movslq	56(%rax), %rcx
	movslq	60(%rax), %rax
	imulq	%rcx, %rax
	shlq	$3, %rax
	addq	%rax, -56(%rbp)
	movl	$0, -76(%rbp)
	jmp	.LBB0_6
	.align	16, 0x90
.LBB0_7:                                # %for.inc
                                        #   in Loop: Header=BB0_6 Depth=1
	movslq	-76(%rbp), %rax
	movq	-16(%rbp), %rcx
	movslq	56(%rcx), %rdx
	imulq	%rax, %rdx
	shlq	$3, %rdx
	addq	-72(%rbp), %rdx
	movq	176(%rcx), %rcx
	movq	%rdx, (%rcx,%rax,8)
	incl	-76(%rbp)
.LBB0_6:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-76(%rbp), %eax
	movq	-16(%rbp), %rcx
	cmpl	60(%rcx), %eax
	jl	.LBB0_7
# BB#8:                                 # %for.end
	movq	-16(%rbp), %rdi
	movslq	52(%rdi), %rdx
	addq	$184, %rdi
	shlq	$3, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movq	-16(%rbp), %rax
	movq	184(%rax), %rdi
	movslq	52(%rax), %rdx
	shlq	$3, %rdx
	xorl	%ebx, %ebx
	xorl	%esi, %esi
	callq	memset
	movq	-16(%rbp), %rax
	movslq	52(%rax), %rax
	shlq	$3, %rax
	addq	%rax, -56(%rbp)
	movq	-16(%rbp), %rdi
	movslq	52(%rdi), %rdx
	addq	$192, %rdi
	shlq	$3, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movq	-16(%rbp), %rax
	movq	192(%rax), %rdi
	movslq	52(%rax), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	memset
	movq	-16(%rbp), %rax
	movslq	52(%rax), %rax
	shlq	$3, %rax
	addq	%rax, -56(%rbp)
	movq	-16(%rbp), %rdi
	movslq	52(%rdi), %rdx
	addq	$200, %rdi
	shlq	$3, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movq	-16(%rbp), %rax
	movq	200(%rax), %rdi
	movslq	52(%rax), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	memset
	movq	-16(%rbp), %rax
	movslq	52(%rax), %rax
	shlq	$3, %rax
	addq	%rax, -56(%rbp)
	subl	-48(%rbp), %ebx
	movl	%ebx, -84(%rbp)
	movabsq	$4607182418800017408, %rax # imm = 0x3FF0000000000000
	jmp	.LBB0_9
	.align	16, 0x90
.LBB0_21:                               # %for.inc183
                                        #   in Loop: Header=BB0_9 Depth=1
	incl	-84(%rbp)
.LBB0_9:                                # %for.cond123
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_11 Depth 2
	movq	-16(%rbp), %rcx
	movl	24(%rcx), %ecx
	addl	-48(%rbp), %ecx
	cmpl	%ecx, -84(%rbp)
	jge	.LBB0_22
# BB#10:                                # %for.body129
                                        #   in Loop: Header=BB0_9 Depth=1
	xorl	%ecx, %ecx
	subl	-48(%rbp), %ecx
	movl	%ecx, -80(%rbp)
	jmp	.LBB0_11
	.align	16, 0x90
.LBB0_19:                               # %if.then169
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	200(%rdx), %rdx
	movq	$0, (%rdx,%rcx,8)
	incl	-80(%rbp)
.LBB0_11:                               # %for.cond131
                                        #   Parent Loop BB0_9 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	-16(%rbp), %rcx
	movl	20(%rcx), %ecx
	addl	-48(%rbp), %ecx
	cmpl	%ecx, -80(%rbp)
	jge	.LBB0_21
# BB#12:                                # %for.body137
                                        #   in Loop: Header=BB0_11 Depth=2
	movl	-48(%rbp), %ecx
	movl	-80(%rbp), %edx
	addl	%ecx, %edx
	addl	-84(%rbp), %ecx
	movq	-16(%rbp), %rsi
	imull	48(%rsi), %ecx
	addl	%edx, %ecx
	movl	%ecx, -88(%rbp)
	movl	-80(%rbp), %ecx
	xorl	-84(%rbp), %ecx
	testb	$1, %cl
	je	.LBB0_14
# BB#13:                                # %if.then144
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	184(%rdx), %rdx
	movq	$-1, (%rdx,%rcx,8)
	jmp	.LBB0_15
	.align	16, 0x90
.LBB0_14:                               # %if.else
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	184(%rdx), %rdx
	movq	$0, (%rdx,%rcx,8)
.LBB0_15:                               # %if.end151
                                        #   in Loop: Header=BB0_11 Depth=2
	movl	-80(%rbp), %ecx
	xorl	-84(%rbp), %ecx
	testb	$1, %cl
	je	.LBB0_17
# BB#16:                                # %if.then155
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	192(%rdx), %rdx
	movq	%rax, (%rdx,%rcx,8)
	jmp	.LBB0_18
	.align	16, 0x90
.LBB0_17:                               # %if.else160
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	192(%rdx), %rdx
	movq	$0, (%rdx,%rcx,8)
.LBB0_18:                               # %if.end165
                                        #   in Loop: Header=BB0_11 Depth=2
	movl	-80(%rbp), %ecx
	xorl	-84(%rbp), %ecx
	testb	$1, %cl
	jne	.LBB0_19
# BB#20:                                # %if.else174
                                        #   in Loop: Header=BB0_11 Depth=2
	movslq	-88(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	200(%rdx), %rdx
	movq	%rax, (%rdx,%rcx,8)
	incl	-80(%rbp)
	jmp	.LBB0_11
.LBB0_22:                               # %for.end185
	movl	-56(%rbp), %eax
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	create_box, .Lfunc_end0-create_box
	.cfi_endproc

	.globl	destroy_box
	.align	16, 0x90
	.type	destroy_box,@function
destroy_box:                            # @destroy_box
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp4:
	.cfi_def_cfa_offset 16
.Ltmp5:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp6:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	176(%rdi), %rax
	movq	(%rax), %rdi
	callq	free
	movq	-8(%rbp), %rax
	movq	176(%rax), %rdi
	callq	free
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	destroy_box, .Lfunc_end1-destroy_box
	.cfi_endproc

	.type	RandomPadding,@object   # @RandomPadding
	.data
	.globl	RandomPadding
	.align	4
RandomPadding:
	.long	4294967295              # 0xffffffff
	.size	RandomPadding, 4


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
