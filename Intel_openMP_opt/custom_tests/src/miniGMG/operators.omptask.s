	.text
	.file	"operators.omptask.bc"
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
	xorl	%eax, %eax
	callq	printf
	popq	%rbp
	retq
.Lfunc_end0:
	.size	placeHolder, .Lfunc_end0-placeHolder
	.cfi_endproc

	.globl	DoBufferCopy
	.align	16, 0x90
	.type	DoBufferCopy,@function
DoBufferCopy:                           # @DoBufferCopy
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
	pushq	%rax
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	12(%rcx,%rax), %eax
	movl	%eax, -24(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	16(%rcx,%rax), %eax
	movl	%eax, -28(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -32(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -36(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	32(%rcx,%rax), %eax
	movl	%eax, -40(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	36(%rcx,%rax), %eax
	movl	%eax, -44(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	40(%rcx,%rax), %eax
	movl	%eax, -48(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -52(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	60(%rcx,%rax), %eax
	movl	%eax, -56(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	64(%rcx,%rax), %eax
	movl	%eax, -60(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	68(%rcx,%rax), %eax
	movl	%eax, -64(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	72(%rcx,%rax), %eax
	movl	%eax, -68(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movl	76(%rcx,%rax), %eax
	movl	%eax, -72(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movq	48(%rcx,%rax), %rax
	movq	%rax, -80(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movq	80(%rcx,%rax), %rax
	movq	%rax, -88(%rbp)
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	cmpl	$0, 24(%rcx,%rax)
	js	.LBB1_2
# BB#1:                                 # %if.then
	movslq	-16(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movslq	-20(%rbp), %rdx
	movq	-8(%rbp), %rsi
	movq	1432(%rsi,%rcx,8), %rdi
	imulq	$88, %rdx, %rdx
	movslq	24(%rdi,%rdx), %rdx
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	(%rcx,%rax,8), %rax
	movq	%rax, -80(%rbp)
.LBB1_2:                                # %if.end
	movslq	-20(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	cmpl	$0, 56(%rcx,%rax)
	js	.LBB1_4
# BB#3:                                 # %if.then123
	movslq	-16(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movslq	-20(%rbp), %rdx
	movq	-8(%rbp), %rsi
	movq	1432(%rsi,%rcx,8), %rdi
	imulq	$88, %rdx, %rdx
	movslq	56(%rdi,%rdx), %rdx
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	(%rcx,%rax,8), %rax
	movq	%rax, -88(%rbp)
.LBB1_4:                                # %if.end140
	cmpl	$1, -24(%rbp)
	jne	.LBB1_11
# BB#5:                                 # %if.then145
	movl	$0, -100(%rbp)
	jmp	.LBB1_6
	.align	16, 0x90
.LBB1_10:                               # %for.inc166
                                        #   in Loop: Header=BB1_6 Depth=1
	incl	-100(%rbp)
.LBB1_6:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_8 Depth 2
	movl	-100(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.LBB1_27
# BB#7:                                 # %for.body
                                        #   in Loop: Header=BB1_6 Depth=1
	movl	$0, -96(%rbp)
	jmp	.LBB1_8
	.align	16, 0x90
.LBB1_9:                                # %for.inc
                                        #   in Loop: Header=BB1_8 Depth=2
	movl	-96(%rbp), %eax
	addl	-40(%rbp), %eax
	imull	-48(%rbp), %eax
	addl	-36(%rbp), %eax
	movl	-100(%rbp), %ecx
	addl	-44(%rbp), %ecx
	imull	-52(%rbp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -112(%rbp)
	movl	-96(%rbp), %eax
	addl	-60(%rbp), %eax
	imull	-68(%rbp), %eax
	addl	-56(%rbp), %eax
	movl	-100(%rbp), %ecx
	addl	-64(%rbp), %ecx
	imull	-72(%rbp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -116(%rbp)
	movslq	-112(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movslq	-116(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-96(%rbp)
.LBB1_8:                                # %for.cond147
                                        #   Parent Loop BB1_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-96(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.LBB1_9
	jmp	.LBB1_10
.LBB1_11:                               # %if.else
	cmpl	$4, -24(%rbp)
	jne	.LBB1_18
# BB#12:                                # %if.then170
	movl	$0, -100(%rbp)
	jmp	.LBB1_13
	.align	16, 0x90
.LBB1_17:                               # %for.inc218
                                        #   in Loop: Header=BB1_13 Depth=1
	incl	-100(%rbp)
.LBB1_13:                               # %for.cond171
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_15 Depth 2
	movl	-100(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.LBB1_27
# BB#14:                                # %for.body173
                                        #   in Loop: Header=BB1_13 Depth=1
	movl	$0, -96(%rbp)
	jmp	.LBB1_15
	.align	16, 0x90
.LBB1_16:                               # %for.inc215
                                        #   in Loop: Header=BB1_15 Depth=2
	movl	-96(%rbp), %eax
	addl	-40(%rbp), %eax
	imull	-48(%rbp), %eax
	addl	-36(%rbp), %eax
	movl	-100(%rbp), %ecx
	addl	-44(%rbp), %ecx
	imull	-52(%rbp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -120(%rbp)
	movl	-96(%rbp), %eax
	addl	-60(%rbp), %eax
	imull	-68(%rbp), %eax
	addl	-56(%rbp), %eax
	movl	-100(%rbp), %ecx
	addl	-64(%rbp), %ecx
	imull	-72(%rbp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -124(%rbp)
	movslq	-120(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movslq	-124(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	movslq	-120(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	8(%rcx,%rax,8), %xmm0   # xmm0 = mem[0],zero
	movslq	-124(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, 8(%rcx,%rax,8)
	movslq	-120(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	16(%rcx,%rax,8), %xmm0  # xmm0 = mem[0],zero
	movslq	-124(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, 16(%rcx,%rax,8)
	movslq	-120(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	24(%rcx,%rax,8), %xmm0  # xmm0 = mem[0],zero
	movslq	-124(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, 24(%rcx,%rax,8)
	incl	-96(%rbp)
.LBB1_15:                               # %for.cond174
                                        #   Parent Loop BB1_13 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-96(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.LBB1_16
	jmp	.LBB1_17
.LBB1_18:                               # %if.else221
	movl	$0, -100(%rbp)
	jmp	.LBB1_19
	.align	16, 0x90
.LBB1_26:                               # %for.inc257
                                        #   in Loop: Header=BB1_19 Depth=1
	incl	-100(%rbp)
.LBB1_19:                               # %for.cond222
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_21 Depth 2
                                        #       Child Loop BB1_23 Depth 3
	movl	-100(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.LBB1_27
# BB#20:                                # %for.body224
                                        #   in Loop: Header=BB1_19 Depth=1
	movl	$0, -96(%rbp)
	jmp	.LBB1_21
	.align	16, 0x90
.LBB1_25:                               # %for.inc254
                                        #   in Loop: Header=BB1_21 Depth=2
	incl	-96(%rbp)
.LBB1_21:                               # %for.cond225
                                        #   Parent Loop BB1_19 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB1_23 Depth 3
	movl	-96(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.LBB1_26
# BB#22:                                # %for.body227
                                        #   in Loop: Header=BB1_21 Depth=2
	movl	$0, -92(%rbp)
	jmp	.LBB1_23
	.align	16, 0x90
.LBB1_24:                               # %for.inc251
                                        #   in Loop: Header=BB1_23 Depth=3
	movl	-92(%rbp), %eax
	addl	-36(%rbp), %eax
	movl	-96(%rbp), %ecx
	addl	-40(%rbp), %ecx
	imull	-48(%rbp), %ecx
	addl	%eax, %ecx
	movl	-100(%rbp), %eax
	addl	-44(%rbp), %eax
	imull	-52(%rbp), %eax
	addl	%ecx, %eax
	movl	%eax, -128(%rbp)
	movl	-92(%rbp), %eax
	addl	-56(%rbp), %eax
	movl	-96(%rbp), %ecx
	addl	-60(%rbp), %ecx
	imull	-68(%rbp), %ecx
	addl	%eax, %ecx
	movl	-100(%rbp), %eax
	addl	-64(%rbp), %eax
	imull	-72(%rbp), %eax
	addl	%ecx, %eax
	movl	%eax, -132(%rbp)
	movslq	-128(%rbp), %rax
	movq	-80(%rbp), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movslq	-132(%rbp), %rax
	movq	-88(%rbp), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-92(%rbp)
.LBB1_23:                               # %for.cond228
                                        #   Parent Loop BB1_19 Depth=1
                                        #     Parent Loop BB1_21 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-92(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.LBB1_24
	jmp	.LBB1_25
.LBB1_27:                               # %if.end261
	addq	$8, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	DoBufferCopy, .Lfunc_end1-DoBufferCopy
	.cfi_endproc

	.globl	exchange_boundary
	.align	16, 0x90
	.type	exchange_boundary,@function
exchange_boundary:                      # @exchange_boundary
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$560, %rsp              # imm = 0x230
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	%r8d, -24(%rbp)
	movl	%r9d, -28(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -40(%rbp)
	movl	$0, -60(%rbp)
	xorps	%xmm0, %xmm0
	movups	%xmm0, -100(%rbp)
	movaps	%xmm0, -112(%rbp)
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm0, -144(%rbp)
	movaps	%xmm0, -160(%rbp)
	movaps	%xmm0, -176(%rbp)
	movaps	%xmm0, -192(%rbp)
	movl	$1, -176(%rbp)
	movl	$1, -152(%rbp)
	movl	$1, -144(%rbp)
	movl	$1, -136(%rbp)
	movl	$1, -128(%rbp)
	movl	$1, -104(%rbp)
	movups	.Lexchange_boundary.edges+92(%rip), %xmm1
	movups	%xmm1, -212(%rbp)
	movaps	.Lexchange_boundary.edges+80(%rip), %xmm1
	movaps	%xmm1, -224(%rbp)
	movaps	.Lexchange_boundary.edges+64(%rip), %xmm1
	movaps	%xmm1, -240(%rbp)
	movaps	.Lexchange_boundary.edges+48(%rip), %xmm1
	movaps	%xmm1, -256(%rbp)
	movaps	.Lexchange_boundary.edges+32(%rip), %xmm1
	movaps	%xmm1, -272(%rbp)
	movaps	.Lexchange_boundary.edges+16(%rip), %xmm1
	movaps	%xmm1, -288(%rbp)
	movaps	.Lexchange_boundary.edges(%rip), %xmm1
	movaps	%xmm1, -304(%rbp)
	movups	.Lexchange_boundary.corners+92(%rip), %xmm1
	movups	%xmm1, -324(%rbp)
	movaps	.Lexchange_boundary.corners+80(%rip), %xmm1
	movaps	%xmm1, -336(%rbp)
	movaps	.Lexchange_boundary.corners+64(%rip), %xmm1
	movaps	%xmm1, -352(%rbp)
	movaps	.Lexchange_boundary.corners+48(%rip), %xmm1
	movaps	%xmm1, -368(%rbp)
	movaps	.Lexchange_boundary.corners+32(%rip), %xmm1
	movaps	%xmm1, -384(%rbp)
	movaps	.Lexchange_boundary.corners+16(%rip), %xmm1
	movaps	%xmm1, -400(%rbp)
	movaps	.Lexchange_boundary.corners(%rip), %xmm1
	movaps	%xmm1, -416(%rbp)
	movups	%xmm0, -436(%rbp)
	movaps	%xmm0, -448(%rbp)
	movaps	%xmm0, -464(%rbp)
	movaps	%xmm0, -480(%rbp)
	movaps	%xmm0, -496(%rbp)
	movaps	%xmm0, -512(%rbp)
	movaps	%xmm0, -528(%rbp)
	movl	$0, -72(%rbp)
	jmp	.LBB2_1
	.align	16, 0x90
.LBB2_8:                                # %for.inc
                                        #   in Loop: Header=BB2_1 Depth=1
	incl	-72(%rbp)
.LBB2_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$26, -72(%rbp)
	jg	.LBB2_9
# BB#2:                                 # %for.body
                                        #   in Loop: Header=BB2_1 Depth=1
	cmpl	$0, -20(%rbp)
	je	.LBB2_4
# BB#3:                                 # %if.then
                                        #   in Loop: Header=BB2_1 Depth=1
	movslq	-72(%rbp), %rax
	movl	-192(%rbp,%rax,4), %ecx
	orl	%ecx, -528(%rbp,%rax,4)
.LBB2_4:                                # %if.end
                                        #   in Loop: Header=BB2_1 Depth=1
	cmpl	$0, -24(%rbp)
	je	.LBB2_6
# BB#5:                                 # %if.then4
                                        #   in Loop: Header=BB2_1 Depth=1
	movslq	-72(%rbp), %rax
	movl	-304(%rbp,%rax,4), %ecx
	orl	%ecx, -528(%rbp,%rax,4)
.LBB2_6:                                # %if.end10
                                        #   in Loop: Header=BB2_1 Depth=1
	cmpl	$0, -28(%rbp)
	je	.LBB2_8
# BB#7:                                 # %if.then12
                                        #   in Loop: Header=BB2_1 Depth=1
	movslq	-72(%rbp), %rax
	movl	-416(%rbp,%rax,4), %ecx
	orl	%ecx, -528(%rbp,%rax,4)
	jmp	.LBB2_8
.LBB2_9:                                # %for.end
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -48(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-28(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-24(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-20(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-60(%rbp), %rcx
	leaq	-8(%rbp), %r8
	leaq	-12(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined., %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	subq	-48(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	addq	%rax, 560(%rdx,%rcx,8)
	callq	placeHolder
	xorl	%eax, %eax
	callq	CycleTime
	subq	-40(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movq	-8(%rbp), %rdx
	addq	%rax, 400(%rdx,%rcx,8)
	addq	$560, %rsp              # imm = 0x230
	popq	%rbp
	retq
.Lfunc_end2:
	.size	exchange_boundary, .Lfunc_end2-exchange_boundary
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined.,@function
.omp_outlined.:                         # @.omp_outlined.
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp11:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$136, %rsp
.Ltmp12:
	.cfi_offset %rbx, -56
.Ltmp13:
	.cfi_offset %r12, -48
.Ltmp14:
	.cfi_offset %r13, -40
.Ltmp15:
	.cfi_offset %r14, -32
.Ltmp16:
	.cfi_offset %r15, -24
	movq	32(%rbp), %r14
	movq	24(%rbp), %rax
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%rax, -104(%rbp)
	movq	%r14, -112(%rbp)
	movq	-72(%rbp), %rbx
	movq	-80(%rbp), %r15
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %rax
	movq	%rax, -152(%rbp)        # 8-byte Spill
	movq	(%rbx), %rax
	movl	1524(%rax), %ecx
	subl	1520(%rax), %ecx
	decl	%ecx
	movl	%ecx, -120(%rbp)
	movq	(%rbx), %rax
	movl	1520(%rax), %eax
	movl	%eax, -124(%rbp)
	movq	(%rbx), %rax
	movl	1520(%rax), %ecx
	cmpl	1524(%rax), %ecx
	jge	.LBB3_17
# BB#1:                                 # %omp.precond.then
	movl	$0, -128(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	$1, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-136(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-140(%rbp), %rcx
	leaq	-128(%rbp), %r8
	leaq	-132(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$33, %edx
	callq	__kmpc_for_static_init_4
	jmp	.LBB3_2
	.align	16, 0x90
.LBB3_15:                               # %omp.dispatch.inc
                                        #   in Loop: Header=BB3_2 Depth=1
	movl	-136(%rbp), %eax
	addl	%eax, -128(%rbp)
	movl	-136(%rbp), %eax
	addl	%eax, -132(%rbp)
.LBB3_2:                                # %omp.dispatch.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB3_6 Depth 2
	movl	-132(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jle	.LBB3_4
# BB#3:                                 # %cond.true
                                        #   in Loop: Header=BB3_2 Depth=1
	movl	-120(%rbp), %eax
	jmp	.LBB3_5
	.align	16, 0x90
.LBB3_4:                                # %cond.false
                                        #   in Loop: Header=BB3_2 Depth=1
	movl	-132(%rbp), %eax
.LBB3_5:                                # %cond.end
                                        #   in Loop: Header=BB3_2 Depth=1
	movl	%eax, -132(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -116(%rbp)
	cmpl	-132(%rbp), %eax
	jle	.LBB3_6
	jmp	.LBB3_16
	.align	16, 0x90
.LBB3_14:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB3_6 Depth=2
	incl	-116(%rbp)
.LBB3_6:                                # %omp.inner.for.cond
                                        #   Parent Loop BB3_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jg	.LBB3_15
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB3_6 Depth=2
	movq	(%rbx), %rax
	movl	1520(%rax), %eax
	addl	-116(%rbp), %eax
	movl	%eax, -144(%rbp)
	movslq	-144(%rbp), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	cmpl	$0, (%rcx,%rax)
	je	.LBB3_9
# BB#8:                                 # %land.lhs.true
                                        #   in Loop: Header=BB3_6 Depth=2
	cmpl	$0, (%r12)
	jne	.LBB3_13
.LBB3_9:                                # %lor.lhs.false
                                        #   in Loop: Header=BB3_6 Depth=2
	movslq	-144(%rbp), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	cmpl	$0, 4(%rcx,%rax)
	je	.LBB3_11
# BB#10:                                # %land.lhs.true22
                                        #   in Loop: Header=BB3_6 Depth=2
	cmpl	$0, (%r13)
	jne	.LBB3_13
.LBB3_11:                               # %lor.lhs.false24
                                        #   in Loop: Header=BB3_6 Depth=2
	movslq	-144(%rbp), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	cmpl	$0, 8(%rcx,%rax)
	je	.LBB3_14
# BB#12:                                # %land.lhs.true31
                                        #   in Loop: Header=BB3_6 Depth=2
	movq	-152(%rbp), %rax        # 8-byte Reload
	cmpl	$0, (%rax)
	je	.LBB3_14
	.align	16, 0x90
.LBB3_13:                               # %if.then
                                        #   in Loop: Header=BB3_6 Depth=2
	movq	(%rbx), %rdi
	movl	(%r15), %esi
	movl	(%r14), %edx
	movl	-144(%rbp), %ecx
	callq	DoBufferCopy
	jmp	.LBB3_14
.LBB3_16:                               # %omp.dispatch.end
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB3_17:                               # %omp.precond.end
	addq	$136, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end3:
	.size	.omp_outlined., .Lfunc_end3-.omp_outlined.
	.cfi_endproc

	.globl	rebuild_lambda
	.align	16, 0x90
	.type	rebuild_lambda,@function
rebuild_lambda:                         # @rebuild_lambda
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp17:
	.cfi_def_cfa_offset 16
.Ltmp18:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp19:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$120, %rsp
.Ltmp20:
	.cfi_offset %rbx, -40
.Ltmp21:
	.cfi_offset %r14, -32
.Ltmp22:
	.cfi_offset %r15, -24
	movsd	%xmm1, -104(%rbp)       # 8-byte Spill
	movsd	%xmm0, -112(%rbp)       # 8-byte Spill
	movl	%esi, %r15d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -96(%rbp)
	movq	%rbx, -32(%rbp)
	movl	%r15d, -36(%rbp)
	movsd	-112(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -48(%rbp)
	movsd	-104(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -56(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -64(%rbp)
	movl	$100000, -68(%rbp)      # imm = 0x186A0
	movslq	-36(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -72(%rbp)
	movslq	-36(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-68(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -76(%rbp)
	movabsq	$-4616189618054758400, %rax # imm = 0xBFF0000000000000
	movq	%rax, -88(%rbp)
	cmpl	$0, -72(%rbp)
	je	.LBB4_2
# BB#1:                                 # %omp_if.then
	leaq	-88(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-48(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-32(%rbp), %rcx
	leaq	-36(%rbp), %r8
	leaq	-76(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..2, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB4_3
.LBB4_2:                                # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -92(%rbp)
	leaq	-88(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-48(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-92(%rbp), %rdi
	leaq	-96(%rbp), %rsi
	leaq	-32(%rbp), %rdx
	leaq	-36(%rbp), %rcx
	leaq	-76(%rbp), %r8
	leaq	-56(%rbp), %r9
	callq	.omp_outlined..2
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB4_3:                                # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-64(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movq	-32(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	movq	-32(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB4_7
# BB#4:                                 # %if.then
	cmpl	$0, -36(%rbp)
	jne	.LBB4_6
# BB#5:                                 # %if.then18
	movl	$.L.str.5, %edi
	xorl	%eax, %eax
	callq	printf
.LBB4_6:                                # %if.end
	movl	-36(%rbp), %esi
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	movl	$.L.str.6, %edi
	movb	$1, %al
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB4_7:                                # %if.end22
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	movslq	-36(%rbp), %rax
	movq	-32(%rbp), %rcx
	movsd	%xmm0, 1696(%rcx,%rax,8)
	addq	$120, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end4:
	.size	rebuild_lambda, .Lfunc_end4-rebuild_lambda
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI5_0:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..2,@function
.omp_outlined..2:                       # @.omp_outlined..2
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp23:
	.cfi_def_cfa_offset 16
.Ltmp24:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp25:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$328, %rsp              # imm = 0x148
.Ltmp26:
	.cfi_offset %rbx, -56
.Ltmp27:
	.cfi_offset %r12, -48
.Ltmp28:
	.cfi_offset %r13, -40
.Ltmp29:
	.cfi_offset %r14, -32
.Ltmp30:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -244(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r12
	movq	%r12, -280(%rbp)        # 8-byte Spill
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB5_23
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movabsq	$-4503599627370497, %rax # imm = 0xFFEFFFFFFFFFFFFF
	movq	%rax, -144(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB5_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB5_4
.LBB5_3:                                # %cond.false
	movl	-124(%rbp), %eax
.LBB5_4:                                # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB5_5
	.align	16, 0x90
.LBB5_11:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB5_5 Depth=1
	incl	-108(%rbp)
.LBB5_5:                                # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB5_12
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB5_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r15), %rax
	movq	(%r14), %rcx
	movsd	1616(%rcx,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	.LCPI5_0(%rip), %xmm1   # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -192(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-172(%rbp), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	16(%rax), %rdx
	movq	%rdx, -200(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-172(%rbp), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movq	%rdx, -208(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-172(%rbp), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movq	%rdx, -216(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-172(%rbp), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movq	%rdx, -224(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-172(%rbp), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	32(%rax), %rdx
	movq	%rdx, -232(%rbp)
	movabsq	$-4616189618054758400, %rax # imm = 0xBFF0000000000000
	movq	%rax, -240(%rbp)
	cmpl	$0, (%rbx)
	je	.LBB5_8
# BB#7:                                 # %omp_if.then
                                        #   in Loop: Header=BB5_5 Depth=1
	leaq	-240(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 64(%rsp)
	movq	%r12, 56(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 48(%rsp)
	leaq	-216(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	%r13, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-164(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$14, %esi
	movl	$.omp_outlined..3, %edx
	xorl	%eax, %eax
	leaq	-176(%rbp), %rcx
	leaq	-180(%rbp), %r8
	leaq	-184(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB5_9
	.align	16, 0x90
.LBB5_8:                                # %omp_if.else
                                        #   in Loop: Header=BB5_5 Depth=1
	movq	-48(%rbp), %rax
	movq	%r13, %r12
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-240(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 56(%rsp)
	movq	-280(%rbp), %rax        # 8-byte Reload
	movq	%rax, 48(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-216(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	%r12, 8(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-244(%rbp), %rsi
	leaq	-176(%rbp), %rdx
	leaq	-180(%rbp), %rcx
	leaq	-184(%rbp), %r8
	leaq	-164(%rbp), %r9
	callq	.omp_outlined..3
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	movq	%r12, %r13
	movq	-280(%rbp), %r12        # 8-byte Reload
	callq	__kmpc_end_serialized_parallel
.LBB5_9:                                # %omp_if.end
                                        #   in Loop: Header=BB5_5 Depth=1
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
	ucomisd	-144(%rbp), %xmm0
	jbe	.LBB5_11
# BB#10:                                # %if.then
                                        #   in Loop: Header=BB5_5 Depth=1
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	%xmm0, -144(%rbp)
	jmp	.LBB5_11
.LBB5_12:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-144(%rbp), %rax
	movq	%rax, -256(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-256(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.4, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB5_18
# BB#13:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	24(%rbp), %rax
	jne	.LBB5_23
# BB#14:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	-144(%rbp), %xmm0
	jbe	.LBB5_16
# BB#15:                                # %cond.true122
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB5_17
.LBB5_18:                               # %.omp.reduction.case2
	movq	24(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB5_19:                               # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -272(%rbp)
	ucomisd	-144(%rbp), %xmm0
	jbe	.LBB5_21
# BB#20:                                # %cond.true127
                                        #   in Loop: Header=BB5_19 Depth=1
	movsd	-272(%rbp), %xmm0       # xmm0 = mem[0],zero
	jmp	.LBB5_22
	.align	16, 0x90
.LBB5_21:                               # %cond.false128
                                        #   in Loop: Header=BB5_19 Depth=1
	movsd	-144(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB5_22:                               # %cond.end129
                                        #   in Loop: Header=BB5_19 Depth=1
	movsd	%xmm0, -264(%rbp)
	movq	-264(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB5_19
	jmp	.LBB5_23
.LBB5_16:                               # %cond.false123
	movsd	-144(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB5_17:                               # %cond.end124
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
.LBB5_23:                               # %omp.precond.end
	addq	$328, %rsp              # imm = 0x148
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end5:
	.size	.omp_outlined..2, .Lfunc_end5-.omp_outlined..2
	.cfi_endproc

	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI6_0:
	.quad	9223372036854775807     # 0x7fffffffffffffff
	.quad	9223372036854775807     # 0x7fffffffffffffff
.LCPI6_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI6_2:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..3,@function
.omp_outlined..3:                       # @.omp_outlined..3
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp31:
	.cfi_def_cfa_offset 16
.Ltmp32:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp33:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$344, %rsp              # imm = 0x158
.Ltmp34:
	.cfi_offset %rbx, -56
.Ltmp35:
	.cfi_offset %r12, -48
.Ltmp36:
	.cfi_offset %r13, -40
.Ltmp37:
	.cfi_offset %r14, -32
.Ltmp38:
	.cfi_offset %r15, -24
	movq	88(%rbp), %r12
	movq	80(%rbp), %r10
	movq	72(%rbp), %r11
	movq	64(%rbp), %r14
	movq	56(%rbp), %r15
	movq	48(%rbp), %rax
	movq	40(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	32(%rbp), %rdi
	movq	%rsi, -56(%rbp)
	movq	24(%rbp), %rsi
	movq	%rdx, -64(%rbp)
	movq	16(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%r12, %rcx
	movq	%rdi, -112(%rbp)
	movq	%rbx, -120(%rbp)
	movq	%rax, -128(%rbp)
	movq	%r15, -136(%rbp)
	movq	%r14, -144(%rbp)
	movq	%r11, -152(%rbp)
	movq	%r10, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r8
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %rbx
	movq	-104(%rbp), %r9
	movq	-112(%rbp), %rdi
	movq	-120(%rbp), %r12
	movq	-128(%rbp), %r14
	movq	-136(%rbp), %r15
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	movq	-144(%rbp), %rcx
	decq	%rdx
	movq	%rdx, -184(%rbp)
	movq	-152(%rbp), %rdx
	movl	$0, -188(%rbp)
	movl	$0, -192(%rbp)
	cmpl	$0, (%rax)
	movq	-160(%rbp), %rax
	movq	%rax, -312(%rbp)        # 8-byte Spill
	jle	.LBB6_24
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB6_24
# BB#2:                                 # %omp.precond.then
	movq	%rdx, -360(%rbp)        # 8-byte Spill
	movq	%rcx, -352(%rbp)        # 8-byte Spill
	movq	%rdi, -344(%rbp)        # 8-byte Spill
	movq	%r9, -336(%rbp)         # 8-byte Spill
	movq	%r8, -328(%rbp)         # 8-byte Spill
	movq	%rsi, -320(%rbp)        # 8-byte Spill
	movq	$0, -200(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	$1, -216(%rbp)
	movl	$0, -220(%rbp)
	movabsq	$-4503599627370497, %rax # imm = 0xFFEFFFFFFFFFFFFF
	movq	%rax, -240(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-216(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-220(%rbp), %rcx
	leaq	-200(%rbp), %r8
	leaq	-208(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-208(%rbp), %rax
	cmpq	-184(%rbp), %rax
	jle	.LBB6_4
# BB#3:                                 # %cond.true
	movq	-184(%rbp), %rax
	jmp	.LBB6_5
.LBB6_4:                                # %cond.false
	movq	-208(%rbp), %rax
.LBB6_5:                                # %cond.end
	movq	-320(%rbp), %r8         # 8-byte Reload
	movq	-328(%rbp), %r9         # 8-byte Reload
	movq	-336(%rbp), %rsi        # 8-byte Reload
	movq	-344(%rbp), %rdi        # 8-byte Reload
	movq	-352(%rbp), %r10        # 8-byte Reload
	movq	-360(%rbp), %r11        # 8-byte Reload
	movq	%rax, -208(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -176(%rbp)
	movapd	.LCPI6_0(%rip), %xmm0   # xmm0 = [9223372036854775807,9223372036854775807]
	movapd	.LCPI6_1(%rip), %xmm1   # xmm1 = [9223372036854775808,9223372036854775808]
	movsd	.LCPI6_2(%rip), %xmm2   # xmm2 = mem[0],zero
	jmp	.LBB6_6
	.align	16, 0x90
.LBB6_12:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB6_6 Depth=1
	incq	-176(%rbp)
.LBB6_6:                                # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB6_8 Depth 2
	movq	-176(%rbp), %rax
	cmpq	-208(%rbp), %rax
	jg	.LBB6_13
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB6_6 Depth=1
	movq	-176(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -224(%rbp)
	movq	-176(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -228(%rbp)
	movl	$0, -232(%rbp)
	jmp	.LBB6_8
	.align	16, 0x90
.LBB6_11:                               # %for.inc
                                        #   in Loop: Header=BB6_8 Depth=2
	incl	-232(%rbp)
.LBB6_8:                                # %for.cond
                                        #   Parent Loop BB6_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-232(%rbp), %eax
	cmpl	(%r9), %eax
	jge	.LBB6_12
# BB#9:                                 # %for.body
                                        #   in Loop: Header=BB6_8 Depth=2
	movl	-228(%rbp), %eax
	imull	(%r13), %eax
	addl	-232(%rbp), %eax
	movl	-224(%rbp), %ecx
	imull	(%rbx), %ecx
	addl	%eax, %ecx
	movl	%ecx, -252(%rbp)
	movsd	(%rsi), %xmm3           # xmm3 = mem[0],zero
	mulsd	(%rdi), %xmm3
	movslq	-252(%rbp), %rax
	movq	(%r12), %rcx
	movsd	(%rcx,%rax,8), %xmm4    # xmm4 = mem[0],zero
	mulsd	%xmm3, %xmm4
	andpd	%xmm0, %xmm4
	movsd	8(%rcx,%rax,8), %xmm5   # xmm5 = mem[0],zero
	mulsd	%xmm3, %xmm5
	andpd	%xmm0, %xmm5
	addsd	%xmm4, %xmm5
	movq	(%r14), %rcx
	movsd	(%rcx,%rax,8), %xmm4    # xmm4 = mem[0],zero
	mulsd	%xmm3, %xmm4
	andpd	%xmm0, %xmm4
	addsd	%xmm5, %xmm4
	movslq	(%r13), %rdx
	addq	%rax, %rdx
	movsd	(%rcx,%rdx,8), %xmm5    # xmm5 = mem[0],zero
	mulsd	%xmm3, %xmm5
	andpd	%xmm0, %xmm5
	addsd	%xmm4, %xmm5
	movq	(%r15), %rcx
	movsd	(%rcx,%rax,8), %xmm4    # xmm4 = mem[0],zero
	mulsd	%xmm3, %xmm4
	andpd	%xmm0, %xmm4
	addsd	%xmm5, %xmm4
	movslq	(%rbx), %rdx
	addq	%rax, %rdx
	mulsd	(%rcx,%rdx,8), %xmm3
	andpd	%xmm0, %xmm3
	addsd	%xmm4, %xmm3
	movsd	%xmm3, -264(%rbp)
	movsd	(%r10), %xmm3           # xmm3 = mem[0],zero
	movslq	-252(%rbp), %rax
	movq	(%r11), %rcx
	mulsd	(%rcx,%rax,8), %xmm3
	movsd	(%rsi), %xmm4           # xmm4 = mem[0],zero
	mulsd	(%rdi), %xmm4
	movq	(%r12), %rcx
	movsd	(%rcx,%rax,8), %xmm5    # xmm5 = mem[0],zero
	xorpd	%xmm1, %xmm5
	subsd	8(%rcx,%rax,8), %xmm5
	movq	(%r14), %rcx
	subsd	(%rcx,%rax,8), %xmm5
	movslq	(%r13), %rdx
	addq	%rax, %rdx
	subsd	(%rcx,%rdx,8), %xmm5
	movq	(%r15), %rcx
	subsd	(%rcx,%rax,8), %xmm5
	movslq	(%rbx), %rdx
	addq	%rax, %rdx
	subsd	(%rcx,%rdx,8), %xmm5
	mulsd	%xmm4, %xmm5
	subsd	%xmm5, %xmm3
	movsd	%xmm3, -272(%rbp)
	movapd	%xmm2, %xmm4
	divsd	%xmm3, %xmm4
	movslq	-252(%rbp), %rax
	movq	-312(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movsd	%xmm4, (%rcx,%rax,8)
	movsd	-272(%rbp), %xmm3       # xmm3 = mem[0],zero
	movsd	-264(%rbp), %xmm4       # xmm4 = mem[0],zero
	addsd	%xmm3, %xmm4
	divsd	%xmm3, %xmm4
	movsd	%xmm4, -280(%rbp)
	ucomisd	-240(%rbp), %xmm4
	jbe	.LBB6_11
# BB#10:                                # %if.then
                                        #   in Loop: Header=BB6_8 Depth=2
	movsd	-280(%rbp), %xmm3       # xmm3 = mem[0],zero
	movsd	%xmm3, -240(%rbp)
	jmp	.LBB6_11
.LBB6_13:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-240(%rbp), %rax
	movq	%rax, -288(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-288(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB6_19
# BB#14:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	88(%rbp), %rax
	jne	.LBB6_24
# BB#15:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	-240(%rbp), %xmm0
	jbe	.LBB6_17
# BB#16:                                # %cond.true117
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB6_18
.LBB6_19:                               # %.omp.reduction.case2
	movq	88(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB6_20:                               # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -304(%rbp)
	ucomisd	-240(%rbp), %xmm0
	jbe	.LBB6_22
# BB#21:                                # %cond.true123
                                        #   in Loop: Header=BB6_20 Depth=1
	movsd	-304(%rbp), %xmm0       # xmm0 = mem[0],zero
	jmp	.LBB6_23
	.align	16, 0x90
.LBB6_22:                               # %cond.false124
                                        #   in Loop: Header=BB6_20 Depth=1
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB6_23:                               # %cond.end125
                                        #   in Loop: Header=BB6_20 Depth=1
	movsd	%xmm0, -296(%rbp)
	movq	-296(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB6_20
	jmp	.LBB6_24
.LBB6_17:                               # %cond.false118
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB6_18:                               # %cond.end119
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
.LBB6_24:                               # %omp.precond.end
	addq	$344, %rsp              # imm = 0x158
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end6:
	.size	.omp_outlined..3, .Lfunc_end6-.omp_outlined..3
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func,@function
.omp.reduction.reduction_func:          # @.omp.reduction.reduction_func
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp39:
	.cfi_def_cfa_offset 16
.Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp41:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	(%rcx), %xmm0
	jbe	.LBB7_2
# BB#1:                                 # %cond.true
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB7_3
.LBB7_2:                                # %cond.false
	movsd	(%rcx), %xmm0           # xmm0 = mem[0],zero
.LBB7_3:                                # %cond.end
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end7:
	.size	.omp.reduction.reduction_func, .Lfunc_end7-.omp.reduction.reduction_func
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.4,@function
.omp.reduction.reduction_func.4:        # @.omp.reduction.reduction_func.4
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp42:
	.cfi_def_cfa_offset 16
.Ltmp43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp44:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	(%rcx), %xmm0
	jbe	.LBB8_2
# BB#1:                                 # %cond.true
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB8_3
.LBB8_2:                                # %cond.false
	movsd	(%rcx), %xmm0           # xmm0 = mem[0],zero
.LBB8_3:                                # %cond.end
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end8:
	.size	.omp.reduction.reduction_func.4, .Lfunc_end8-.omp.reduction.reduction_func.4
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI9_0:
	.quad	4607182418800017408     # double 1
	.text
	.globl	__box_smooth_GSRB_multiple
	.align	16, 0x90
	.type	__box_smooth_GSRB_multiple,@function
__box_smooth_GSRB_multiple:             # @__box_smooth_GSRB_multiple
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp45:
	.cfi_def_cfa_offset 16
.Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp47:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$312, %rsp              # imm = 0x138
.Ltmp48:
	.cfi_offset %rbx, -56
.Ltmp49:
	.cfi_offset %r12, -48
.Ltmp50:
	.cfi_offset %r13, -40
.Ltmp51:
	.cfi_offset %r14, -32
.Ltmp52:
	.cfi_offset %r15, -24
	movl	%ecx, %r14d
	movsd	%xmm1, -336(%rbp)       # 8-byte Spill
	movsd	%xmm0, -344(%rbp)       # 8-byte Spill
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r15d
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movsd	-344(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movsd	-336(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -72(%rbp)
	movl	%r14d, -76(%rbp)
	movq	-48(%rbp), %rax
	movl	48(%rax), %eax
	movl	%eax, -88(%rbp)
	movq	-48(%rbp), %rax
	movl	52(%rax), %eax
	movl	%eax, -92(%rbp)
	movq	-48(%rbp), %rax
	movl	44(%rax), %eax
	movl	%eax, -96(%rbp)
	movq	-48(%rbp), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	.LCPI9_0(%rip), %xmm1   # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -104(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	176(%rcx), %rcx
	movslq	-96(%rbp), %rdx
	movslq	-92(%rbp), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movslq	-88(%rbp), %rax
	imulq	%rdx, %rax
	leaq	(%rsi,%rax,8), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	%rax, -112(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	176(%rcx), %rcx
	movslq	-96(%rbp), %rdx
	movslq	-92(%rbp), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movslq	-88(%rbp), %rax
	imulq	%rdx, %rax
	leaq	(%rsi,%rax,8), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	%rax, -120(%rbp)
	movslq	-56(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	176(%rcx), %rcx
	movslq	-96(%rbp), %rdx
	movslq	-92(%rbp), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movslq	-88(%rbp), %rax
	imulq	%rdx, %rax
	leaq	(%rsi,%rax,8), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	%rax, -128(%rbp)
	movq	-48(%rbp), %rax
	movq	176(%rax), %rax
	movslq	-96(%rbp), %rcx
	movslq	-92(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	16(%rax), %rdx
	movslq	-88(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -136(%rbp)
	movq	-48(%rbp), %rax
	movq	176(%rax), %rax
	movslq	-96(%rbp), %rcx
	movslq	-92(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movslq	-88(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -144(%rbp)
	movq	-48(%rbp), %rax
	movq	176(%rax), %rax
	movslq	-96(%rbp), %rcx
	movslq	-92(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movslq	-88(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -152(%rbp)
	movq	-48(%rbp), %rax
	movq	176(%rax), %rax
	movslq	-96(%rbp), %rcx
	movslq	-92(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movslq	-88(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -160(%rbp)
	movq	-48(%rbp), %rax
	movq	176(%rax), %rax
	movslq	-96(%rbp), %rcx
	movslq	-92(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	32(%rax), %rdx
	movslq	-88(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -168(%rbp)
	movl	-96(%rbp), %eax
	decl	%eax
	movl	%eax, -172(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	cmpl	$9, 28(%rax)
	jl	.LBB9_2
# BB#1:                                 # %if.then
	movl	$1, -180(%rbp)
.LBB9_2:                                # %if.end
	movq	-48(%rbp), %rax
	cmpl	$9, 24(%rax)
	jl	.LBB9_4
# BB#3:                                 # %if.then85
	movl	$1, -180(%rbp)
.LBB9_4:                                # %if.end86
	movl	-76(%rbp), %eax
	movl	%eax, -176(%rbp)
	leaq	-128(%rbp), %r13
	leaq	-328(%rbp), %r14
	jmp	.LBB9_5
	.align	16, 0x90
.LBB9_16:                               # %for.inc126
                                        #   in Loop: Header=BB9_5 Depth=1
	incl	-176(%rbp)
	decl	-172(%rbp)
.LBB9_5:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB9_7 Depth 2
                                        #       Child Loop BB9_9 Depth 3
	movl	-76(%rbp), %eax
	addl	-96(%rbp), %eax
	cmpl	%eax, -176(%rbp)
	jge	.LBB9_17
# BB#6:                                 # %for.body
                                        #   in Loop: Header=BB9_5 Depth=1
	xorl	%eax, %eax
	subl	-172(%rbp), %eax
	movl	%eax, -84(%rbp)
	jmp	.LBB9_7
	.align	16, 0x90
.LBB9_13:                               # %for.inc120
                                        #   in Loop: Header=BB9_7 Depth=2
	addl	$4, -84(%rbp)
.LBB9_7:                                # %for.cond89
                                        #   Parent Loop BB9_5 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB9_9 Depth 3
	movq	-48(%rbp), %rax
	movl	28(%rax), %eax
	addl	-172(%rbp), %eax
	cmpl	%eax, -84(%rbp)
	jge	.LBB9_14
# BB#8:                                 # %for.body94
                                        #   in Loop: Header=BB9_7 Depth=2
	xorl	%eax, %eax
	subl	-172(%rbp), %eax
	movl	%eax, -80(%rbp)
	jmp	.LBB9_9
	.align	16, 0x90
.LBB9_11:                               # %omp_if.then
                                        #   in Loop: Header=BB9_9 Depth=3
	movl	$.L__unnamed_1, %edi
	movl	%r15d, %esi
	movq	%r12, %rdx
	callq	__kmpc_omp_task
	addl	$16, -80(%rbp)
.LBB9_9:                                # %for.cond96
                                        #   Parent Loop BB9_5 Depth=1
                                        #     Parent Loop BB9_7 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-48(%rbp), %rax
	movl	24(%rax), %eax
	addl	-172(%rbp), %eax
	cmpl	%eax, -80(%rbp)
	jge	.LBB9_13
# BB#10:                                # %for.body101
                                        #   in Loop: Header=BB9_9 Depth=3
	leaq	-84(%rbp), %rax
	movq	%rax, -328(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, -320(%rbp)
	leaq	-172(%rbp), %rax
	movq	%rax, -312(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, -304(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -296(%rbp)
	leaq	-88(%rbp), %rax
	movq	%rax, -288(%rbp)
	leaq	-92(%rbp), %rax
	movq	%rax, -280(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -272(%rbp)
	leaq	-136(%rbp), %rax
	movq	%rax, -264(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, -256(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, -248(%rbp)
	leaq	-104(%rbp), %rax
	movq	%rax, -240(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, -232(%rbp)
	leaq	-152(%rbp), %rax
	movq	%rax, -224(%rbp)
	leaq	-160(%rbp), %rax
	movq	%rax, -216(%rbp)
	leaq	-120(%rbp), %rax
	movq	%rax, -208(%rbp)
	leaq	-168(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	%r13, -192(%rbp)
	movl	$.L__unnamed_1, %edi
	movl	$1, %edx
	movl	$152, %ecx
	movl	$144, %r8d
	movl	$.omp_task_entry., %r9d
	movl	%r15d, %esi
	callq	__kmpc_omp_task_alloc
	movq	%rax, %r12
	movq	(%r12), %rbx
	movl	$144, %edx
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	memcpy
	movq	8(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 32(%r12)
	movq	56(%rbx), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, 40(%r12)
	movq	64(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 48(%r12)
	movq	72(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 56(%r12)
	movq	80(%rbx), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, 64(%r12)
	movq	88(%rbx), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, 72(%r12)
	movq	96(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 80(%r12)
	movq	104(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 88(%r12)
	movq	112(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 96(%r12)
	movq	120(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 104(%r12)
	movq	128(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 112(%r12)
	movq	136(%rbx), %rax
	movq	(%rax), %rax
	movq	%rax, 120(%r12)
	movq	(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 128(%r12)
	movq	16(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 132(%r12)
	movq	24(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 136(%r12)
	movq	32(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 140(%r12)
	movq	40(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 144(%r12)
	movq	48(%rbx), %rax
	movl	(%rax), %eax
	movl	%eax, 148(%r12)
	movq	$0, 24(%r12)
	cmpl	$0, -180(%rbp)
	jne	.LBB9_11
# BB#12:                                # %omp_if.else
                                        #   in Loop: Header=BB9_9 Depth=3
	movl	$.L__unnamed_1, %edi
	movl	%r15d, %esi
	movq	%r12, %rdx
	callq	__kmpc_omp_task_begin_if0
	movl	%r15d, %edi
	movq	%r12, %rsi
	callq	.omp_task_entry.
	movl	$.L__unnamed_1, %edi
	movl	%r15d, %esi
	movq	%r12, %rdx
	callq	__kmpc_omp_task_complete_if0
	addl	$16, -80(%rbp)
	jmp	.LBB9_9
	.align	16, 0x90
.LBB9_14:                               # %for.end122
                                        #   in Loop: Header=BB9_5 Depth=1
	cmpl	$0, -172(%rbp)
	jle	.LBB9_16
# BB#15:                                # %if.then124
                                        #   in Loop: Header=BB9_5 Depth=1
	movl	$.L__unnamed_1, %edi
	movl	%r15d, %esi
	callq	__kmpc_omp_taskwait
	jmp	.LBB9_16
.LBB9_17:                               # %for.end127
	addq	$312, %rsp              # imm = 0x138
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end9:
	.size	__box_smooth_GSRB_multiple, .Lfunc_end9-__box_smooth_GSRB_multiple
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_task_privates_map.,@function
.omp_task_privates_map.:                # @.omp_task_privates_map.
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp53:
	.cfi_def_cfa_offset 16
.Ltmp54:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp55:
	.cfi_def_cfa_register %rbp
	subq	$24, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	112(%rbp), %rax
	movq	%r8, -40(%rbp)
	movq	104(%rbp), %rcx
	movq	%r9, -48(%rbp)
	movq	16(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	24(%rbp), %rdx
	movq	%rdx, -64(%rbp)
	movq	32(%rbp), %rdx
	movq	%rdx, -72(%rbp)
	movq	40(%rbp), %rdx
	movq	%rdx, -80(%rbp)
	movq	48(%rbp), %rdx
	movq	%rdx, -88(%rbp)
	movq	56(%rbp), %rdx
	movq	%rdx, -96(%rbp)
	movq	64(%rbp), %rdx
	movq	%rdx, -104(%rbp)
	movq	72(%rbp), %rdx
	movq	%rdx, -112(%rbp)
	movq	80(%rbp), %rdx
	movq	%rdx, -120(%rbp)
	movq	88(%rbp), %rdx
	movq	%rdx, -128(%rbp)
	movq	96(%rbp), %rdx
	movq	%rdx, -136(%rbp)
	movq	%rcx, -144(%rbp)
	movq	%rax, -152(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	leaq	8(%rax), %rcx
	movq	-72(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	16(%rax), %rcx
	movq	-80(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	24(%rax), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	32(%rax), %rcx
	movq	-96(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	40(%rax), %rcx
	movq	-104(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	48(%rax), %rcx
	movq	-112(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	56(%rax), %rcx
	movq	-120(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	64(%rax), %rcx
	movq	-128(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	72(%rax), %rcx
	movq	-136(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	80(%rax), %rcx
	movq	-144(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	88(%rax), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	96(%rax), %rcx
	movq	-16(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	100(%rax), %rcx
	movq	-32(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	104(%rax), %rcx
	movq	-40(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	108(%rax), %rcx
	movq	-48(%rbp), %rdx
	movq	%rcx, (%rdx)
	leaq	112(%rax), %rcx
	movq	-56(%rbp), %rdx
	movq	%rcx, (%rdx)
	addq	$116, %rax
	movq	-64(%rbp), %rcx
	movq	%rax, (%rcx)
	addq	$24, %rsp
	popq	%rbp
	retq
.Lfunc_end10:
	.size	.omp_task_privates_map., .Lfunc_end10-.omp_task_privates_map.
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_task_entry.,@function
.omp_task_entry.:                       # @.omp_task_entry.
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp56:
	.cfi_def_cfa_offset 16
.Ltmp57:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp58:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$392, %rsp              # imm = 0x188
.Ltmp59:
	.cfi_offset %rbx, -56
.Ltmp60:
	.cfi_offset %r12, -48
.Ltmp61:
	.cfi_offset %r13, -40
.Ltmp62:
	.cfi_offset %r14, -32
.Ltmp63:
	.cfi_offset %r15, -24
	movl	%edi, -252(%rbp)
	movq	%rsi, -264(%rbp)
	movl	-252(%rbp), %eax
	movl	16(%rsi), %ecx
	movq	(%rsi), %rdx
	addq	$32, %rsi
	movl	%eax, -44(%rbp)
	movl	%ecx, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	$.omp_task_privates_map., -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-56(%rbp), %rdi
	leaq	-216(%rbp), %rax
	movq	%rax, 96(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 88(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 48(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-152(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-136(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-128(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-120(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-80(%rbp), %rsi
	leaq	-88(%rbp), %rdx
	leaq	-96(%rbp), %rcx
	leaq	-104(%rbp), %r8
	leaq	-112(%rbp), %r9
	xorl	%eax, %eax
	callq	*-64(%rbp)
	movq	-80(%rbp), %r15
	movq	-88(%rbp), %rax
	movq	-96(%rbp), %rcx
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %r11
	movq	-120(%rbp), %r13
	movq	-128(%rbp), %rdx
	movq	-136(%rbp), %rsi
	movq	%rsi, -272(%rbp)        # 8-byte Spill
	movq	-144(%rbp), %rsi
	movq	%rsi, -280(%rbp)        # 8-byte Spill
	movq	-152(%rbp), %rsi
	movq	-160(%rbp), %rbx
	movq	%rbx, -288(%rbp)        # 8-byte Spill
	movq	-168(%rbp), %rbx
	movq	%rbx, -296(%rbp)        # 8-byte Spill
	movl	(%r15), %r8d
	addl	$4, %r8d
	movq	(%rax), %rbx
	movl	28(%rbx), %ebx
	addl	(%rcx), %ebx
	cmpl	%ebx, %r8d
	movq	-176(%rbp), %rbx
	movq	%rbx, -304(%rbp)        # 8-byte Spill
	movq	-184(%rbp), %rbx
	movq	%rbx, -312(%rbp)        # 8-byte Spill
	movq	-192(%rbp), %rbx
	movq	%rbx, -320(%rbp)        # 8-byte Spill
	movq	-200(%rbp), %rbx
	movq	%rbx, -328(%rbp)        # 8-byte Spill
	movq	-208(%rbp), %r9
	movq	-216(%rbp), %r10
	jge	.LBB11_2
# BB#1:                                 # %cond.true.i
	movl	(%r15), %r14d
	addl	$4, %r14d
	jmp	.LBB11_3
.LBB11_2:                               # %cond.false.i
	movq	(%rax), %rbx
	movl	28(%rbx), %r14d
	addl	(%rcx), %r14d
.LBB11_3:                               # %cond.end.i
	movl	%r14d, -232(%rbp)
	movl	(%rdi), %r14d
	addl	$16, %r14d
	movq	(%rax), %rbx
	movl	24(%rbx), %ebx
	addl	(%rcx), %ebx
	cmpl	%ebx, %r14d
	jge	.LBB11_5
# BB#4:                                 # %cond.true34.i
	movl	(%rdi), %r14d
	addl	$16, %r14d
	jmp	.LBB11_6
.LBB11_5:                               # %cond.false36.i
	movq	(%rax), %rbx
	movl	24(%rbx), %r14d
	addl	(%rcx), %r14d
.LBB11_6:                               # %cond.end40.i
	movl	%r14d, -236(%rbp)
	movl	(%r15), %ebx
	movl	%ebx, -228(%rbp)
	jmp	.LBB11_7
	.align	16, 0x90
.LBB11_16:                              # %for.end142.i
                                        #   in Loop: Header=BB11_7 Depth=1
	incl	-228(%rbp)
.LBB11_7:                               # %for.cond.i
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB11_9 Depth 2
                                        #       Child Loop BB11_11 Depth 3
	movl	-228(%rbp), %ebx
	cmpl	-232(%rbp), %ebx
	jge	.LBB11_17
# BB#8:                                 # %for.body.i
                                        #   in Loop: Header=BB11_7 Depth=1
	movl	(%rdi), %ebx
	movl	%ebx, -224(%rbp)
	jmp	.LBB11_9
	.align	16, 0x90
.LBB11_15:                              # %for.end.i
                                        #   in Loop: Header=BB11_9 Depth=2
	incl	-224(%rbp)
.LBB11_9:                               # %for.cond43.i
                                        #   Parent Loop BB11_7 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB11_11 Depth 3
	movl	-224(%rbp), %ebx
	cmpl	-236(%rbp), %ebx
	jge	.LBB11_16
# BB#10:                                # %for.body45.i
                                        #   in Loop: Header=BB11_9 Depth=2
	xorl	%ebx, %ebx
	subl	(%rcx), %ebx
	movl	%ebx, -220(%rbp)
	jmp	.LBB11_11
	.align	16, 0x90
.LBB11_14:                              # %if.end.i
                                        #   in Loop: Header=BB11_11 Depth=3
	incl	-220(%rbp)
.LBB11_11:                              # %for.cond46.i
                                        #   Parent Loop BB11_7 Depth=1
                                        #     Parent Loop BB11_9 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	(%rax), %rbx
	movl	20(%rbx), %ebx
	addl	(%rcx), %ebx
	cmpl	%ebx, -220(%rbp)
	jge	.LBB11_15
# BB#12:                                # %for.body51.i
                                        #   in Loop: Header=BB11_11 Depth=3
	movl	-220(%rbp), %ebx
	xorl	-224(%rbp), %ebx
	xorl	-228(%rbp), %ebx
	xorl	(%r11), %ebx
	testb	$1, %bl
	jne	.LBB11_14
# BB#13:                                # %if.then.i
                                        #   in Loop: Header=BB11_11 Depth=3
	movl	-224(%rbp), %ebx
	imull	(%r13), %ebx
	addl	-220(%rbp), %ebx
	movq	%rdi, %r8
	movl	-228(%rbp), %edi
	imull	(%rdx), %edi
	addl	%ebx, %edi
	movl	%edi, -240(%rbp)
	movq	-272(%rbp), %rdi        # 8-byte Reload
	movsd	(%rdi), %xmm0           # xmm0 = mem[0],zero
	movslq	-240(%rbp), %r14
	movq	-280(%rbp), %rdi        # 8-byte Reload
	movq	(%rdi), %rdi
	mulsd	(%rdi,%r14,8), %xmm0
	movq	(%rsi), %r15
	movsd	(%r15,%r14,8), %xmm1    # xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movsd	8(%r15,%r14,8), %xmm2   # xmm2 = mem[0],zero
	subsd	%xmm1, %xmm2
	movapd	%xmm1, %xmm3
	movslq	(%r13), %rdi
	leaq	(%r14,%rdi), %r12
	movsd	(%r15,%r12,8), %xmm4    # xmm4 = mem[0],zero
	subsd	%xmm1, %xmm4
	movq	%r14, %rbx
	subq	%rdi, %rbx
	movapd	%xmm1, %xmm5
	subsd	(%r15,%rbx,8), %xmm5
	movslq	(%rdx), %rdi
	movq	%r14, %rbx
	subq	%rdi, %rbx
	leaq	(%r14,%rdi), %rdi
	movsd	(%r15,%rdi,8), %xmm6    # xmm6 = mem[0],zero
	subsd	%xmm1, %xmm6
	subsd	(%r15,%rbx,8), %xmm1
	subsd	-8(%r15,%r14,8), %xmm3
	movq	-304(%rbp), %rbx        # 8-byte Reload
	movq	(%rbx), %rbx
	mulsd	8(%rbx,%r14,8), %xmm2
	mulsd	(%rbx,%r14,8), %xmm3
	movq	-312(%rbp), %rbx        # 8-byte Reload
	movq	(%rbx), %rbx
	mulsd	(%rbx,%r12,8), %xmm4
	mulsd	(%rbx,%r14,8), %xmm5
	movq	-320(%rbp), %rbx        # 8-byte Reload
	movq	(%rbx), %rbx
	mulsd	(%rbx,%rdi,8), %xmm6
	subsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm4
	subsd	%xmm5, %xmm4
	movq	-288(%rbp), %rdi        # 8-byte Reload
	movsd	(%rdi), %xmm2           # xmm2 = mem[0],zero
	movq	-296(%rbp), %rdi        # 8-byte Reload
	mulsd	(%rdi), %xmm2
	addsd	%xmm4, %xmm6
	mulsd	(%rbx,%r14,8), %xmm1
	subsd	%xmm1, %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm0
	movsd	%xmm0, -248(%rbp)
	movslq	-240(%rbp), %rdi
	movq	(%rsi), %rbx
	movsd	(%rbx,%rdi,8), %xmm1    # xmm1 = mem[0],zero
	movq	(%r10), %rbx
	subsd	(%rbx,%rdi,8), %xmm0
	movq	(%r9), %rbx
	mulsd	(%rbx,%rdi,8), %xmm0
	subsd	%xmm0, %xmm1
	movq	-328(%rbp), %rbx        # 8-byte Reload
	movq	(%rbx), %rbx
	movsd	%xmm1, (%rbx,%rdi,8)
	movq	%r8, %rdi
	jmp	.LBB11_14
.LBB11_17:                              # %.omp_outlined..7.exit
	xorl	%eax, %eax
	addq	$392, %rsp              # imm = 0x188
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end11:
	.size	.omp_task_entry., .Lfunc_end11-.omp_task_entry.
	.cfi_endproc

	.globl	smooth
	.align	16, 0x90
	.type	smooth,@function
smooth:                                 # @smooth
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp64:
	.cfi_def_cfa_offset 16
.Ltmp65:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp66:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
.Ltmp67:
	.cfi_offset %rbx, -56
.Ltmp68:
	.cfi_offset %r12, -48
.Ltmp69:
	.cfi_offset %r13, -40
.Ltmp70:
	.cfi_offset %r14, -32
.Ltmp71:
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)
	movl	%esi, -52(%rbp)
	movl	%edx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movsd	%xmm0, -72(%rbp)
	movsd	%xmm1, -80(%rbp)
	movq	-48(%rbp), %rax
	movl	1612(%rax), %eax
	movl	%eax, -92(%rbp)
	cmpl	$2, %eax
	jl	.LBB12_2
# BB#1:                                 # %if.then
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-60(%rbp), %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
.LBB12_2:                               # %if.end
	movl	$0, -88(%rbp)
	leaq	-72(%rbp), %r12
	leaq	-60(%rbp), %r13
	leaq	-48(%rbp), %r14
	leaq	-52(%rbp), %r15
	leaq	-56(%rbp), %rbx
	jmp	.LBB12_3
	.align	16, 0x90
.LBB12_4:                               # %for.inc
                                        #   in Loop: Header=BB12_3 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	cmpl	$1, -92(%rbp)
	setg	%al
	movzbl	%al, %r8d
	movl	$1, %ecx
	movl	%r8d, %r9d
	callq	exchange_boundary
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -104(%rbp)
	leaq	-88(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-80(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	%r12, 8(%rsp)
	movq	%r13, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..8, %edx
	xorl	%eax, %eax
	movq	%r14, %rcx
	movq	%r15, %r8
	movq	%rbx, %r9
	callq	__kmpc_fork_call
	xorl	%eax, %eax
	callq	CycleTime
	subq	-104(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, (%rdx,%rcx,8)
	movl	-92(%rbp), %eax
	addl	%eax, -88(%rbp)
.LBB12_3:                               # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$3, -88(%rbp)
	jle	.LBB12_4
# BB#5:                                 # %for.end
	addq	$104, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end12:
	.size	smooth, .Lfunc_end12-smooth
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..8,@function
.omp_outlined..8:                       # @.omp_outlined..8
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp72:
	.cfi_def_cfa_offset 16
.Ltmp73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp74:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$152, %rsp
.Ltmp75:
	.cfi_offset %rbx, -56
.Ltmp76:
	.cfi_offset %r12, -48
.Ltmp77:
	.cfi_offset %r13, -40
.Ltmp78:
	.cfi_offset %r14, -32
.Ltmp79:
	.cfi_offset %r15, -24
	movq	32(%rbp), %rax
	movq	24(%rbp), %r10
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r10, -104(%rbp)
	movq	%rax, -112(%rbp)
	movq	-64(%rbp), %rbx
	movq	-72(%rbp), %rax
	movq	%rax, -160(%rbp)        # 8-byte Spill
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r14
	movq	-104(%rbp), %r15
	movq	(%rbx), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -124(%rbp)
	movl	$0, -128(%rbp)
	movq	(%rbx), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB13_8
# BB#1:                                 # %omp.precond.then
	movl	$0, -132(%rbp)
	movl	-124(%rbp), %eax
	movl	%eax, -136(%rbp)
	movl	$1, -140(%rbp)
	movl	$0, -144(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-140(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-144(%rbp), %rcx
	leaq	-132(%rbp), %r8
	leaq	-136(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-136(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jle	.LBB13_3
# BB#2:                                 # %cond.true
	movl	-124(%rbp), %eax
	jmp	.LBB13_4
.LBB13_3:                               # %cond.false
	movl	-136(%rbp), %eax
.LBB13_4:                               # %cond.end
	movl	%eax, -136(%rbp)
	movl	-132(%rbp), %eax
	movl	%eax, -120(%rbp)
	jmp	.LBB13_5
	.align	16, 0x90
.LBB13_6:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB13_5 Depth=1
	movl	-120(%rbp), %eax
	movl	%eax, -148(%rbp)
	movq	-160(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	-148(%rbp), %rcx
	movq	(%rbx), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	imulq	$216, %rax, %rdi
	addq	248(%rdx,%rcx), %rdi
	movl	(%r12), %esi
	movl	(%r13), %edx
	movsd	(%r14), %xmm0           # xmm0 = mem[0],zero
	movsd	(%r15), %xmm1           # xmm1 = mem[0],zero
	movq	32(%rbp), %rax
	movl	(%rax), %ecx
	callq	__box_smooth_GSRB_multiple
	incl	-120(%rbp)
.LBB13_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-120(%rbp), %eax
	cmpl	-136(%rbp), %eax
	jle	.LBB13_6
# BB#7:                                 # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB13_8:                               # %omp.precond.end
	addq	$152, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end13:
	.size	.omp_outlined..8, .Lfunc_end13-.omp_outlined..8
	.cfi_endproc

	.globl	apply_op
	.align	16, 0x90
	.type	apply_op,@function
apply_op:                               # @apply_op
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp80:
	.cfi_def_cfa_offset 16
.Ltmp81:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp82:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
.Ltmp83:
	.cfi_offset %rbx, -56
.Ltmp84:
	.cfi_offset %r12, -48
.Ltmp85:
	.cfi_offset %r13, -40
.Ltmp86:
	.cfi_offset %r14, -32
.Ltmp87:
	.cfi_offset %r15, -24
	movsd	%xmm1, -120(%rbp)       # 8-byte Spill
	movsd	%xmm0, -128(%rbp)       # 8-byte Spill
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -112(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movl	%r15d, -60(%rbp)
	movsd	-128(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -72(%rbp)
	movsd	-120(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -80(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-60(%rbp), %edx
	movl	$1, %ecx
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
	callq	exchange_boundary
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -88(%rbp)
	movl	$100000, -92(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -96(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-92(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -100(%rbp)
	cmpl	$0, -96(%rbp)
	je	.LBB14_2
# BB#1:                                 # %omp_if.then
	leaq	-80(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-60(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..9, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB14_3
.LBB14_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -108(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-108(%rbp), %rdi
	leaq	-112(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-60(%rbp), %r8
	leaq	-56(%rbp), %r9
	callq	.omp_outlined..9
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB14_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-88(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 80(%rdx,%rcx,8)
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end14:
	.size	apply_op, .Lfunc_end14-apply_op
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI15_0:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..9,@function
.omp_outlined..9:                       # @.omp_outlined..9
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp88:
	.cfi_def_cfa_offset 16
.Ltmp89:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp90:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$328, %rsp              # imm = 0x148
.Ltmp91:
	.cfi_offset %rbx, -56
.Ltmp92:
	.cfi_offset %r12, -48
.Ltmp93:
	.cfi_offset %r13, -40
.Ltmp94:
	.cfi_offset %r14, -32
.Ltmp95:
	.cfi_offset %r15, -24
	movq	32(%rbp), %rax
	movq	24(%rbp), %r10
	movq	16(%rbp), %rbx
	movl	$0, -260(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r10, -104(%rbp)
	movq	%rax, -112(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -272(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rax
	movq	%rax, -280(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %r12
	movq	-104(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB15_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -128(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	$1, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-136(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-140(%rbp), %rcx
	leaq	-128(%rbp), %r8
	leaq	-132(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-132(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jle	.LBB15_3
# BB#2:                                 # %cond.true
	movl	-120(%rbp), %eax
	jmp	.LBB15_4
.LBB15_3:                               # %cond.false
	movl	-132(%rbp), %eax
.LBB15_4:                               # %cond.end
	movl	%eax, -132(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -116(%rbp)
	jmp	.LBB15_5
	.align	16, 0x90
.LBB15_7:                               # %omp_if.then
                                        #   in Loop: Header=BB15_5 Depth=1
	leaq	-216(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	%rbx, 16(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$14, %esi
	movl	$.omp_outlined..10, %edx
	xorl	%eax, %eax
	leaq	-180(%rbp), %rcx
	leaq	-184(%rbp), %r8
	leaq	-188(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-116(%rbp)
.LBB15_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jg	.LBB15_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB15_5 Depth=1
	movl	-116(%rbp), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r15), %rax
	movq	(%r14), %rcx
	movsd	1616(%rcx,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	.LCPI15_0(%rip), %xmm1  # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -200(%rbp)
	movq	-272(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-176(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	movslq	-172(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	movq	-280(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-176(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	movslq	-172(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -216(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-176(%rbp), %rcx
	movslq	-168(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	16(%rax), %rdx
	movq	%rdx, -224(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-176(%rbp), %rcx
	movslq	-168(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movq	%rdx, -232(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-176(%rbp), %rcx
	movslq	-168(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movq	%rdx, -240(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-176(%rbp), %rcx
	movslq	-168(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movq	%rdx, -248(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-176(%rbp), %rcx
	movslq	-168(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	32(%rax), %rdx
	movq	%rdx, -256(%rbp)
	cmpl	$0, (%r12)
	jne	.LBB15_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB15_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-216(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 48(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 40(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	%rbx, 8(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-260(%rbp), %rsi
	leaq	-180(%rbp), %rdx
	leaq	-184(%rbp), %rcx
	leaq	-188(%rbp), %r8
	leaq	-168(%rbp), %r9
	callq	.omp_outlined..10
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-116(%rbp)
	jmp	.LBB15_5
.LBB15_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB15_10:                              # %omp.precond.end
	addq	$328, %rsp              # imm = 0x148
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end15:
	.size	.omp_outlined..9, .Lfunc_end15-.omp_outlined..9
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..10,@function
.omp_outlined..10:                      # @.omp_outlined..10
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp96:
	.cfi_def_cfa_offset 16
.Ltmp97:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp98:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$296, %rsp              # imm = 0x128
.Ltmp99:
	.cfi_offset %rbx, -56
.Ltmp100:
	.cfi_offset %r12, -48
.Ltmp101:
	.cfi_offset %r13, -40
.Ltmp102:
	.cfi_offset %r14, -32
.Ltmp103:
	.cfi_offset %r15, -24
	movq	88(%rbp), %rax
	movq	80(%rbp), %r10
	movq	72(%rbp), %r11
	movq	64(%rbp), %r14
	movq	56(%rbp), %r15
	movq	48(%rbp), %r12
	movq	40(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	32(%rbp), %rdi
	movq	%rsi, -56(%rbp)
	movq	24(%rbp), %rsi
	movq	%rdx, -64(%rbp)
	movq	16(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%rax, %rcx
	movq	%r9, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%rdi, -112(%rbp)
	movq	%rbx, -120(%rbp)
	movq	%r12, -128(%rbp)
	movq	%r15, -136(%rbp)
	movq	%r14, -144(%rbp)
	movq	%r11, -152(%rbp)
	movq	%r10, -160(%rbp)
	movq	%rcx, -168(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r8
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %rbx
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %rcx
	movq	%rcx, -264(%rbp)        # 8-byte Spill
	movq	-120(%rbp), %rcx
	movq	%rcx, -272(%rbp)        # 8-byte Spill
	movq	-128(%rbp), %rcx
	movq	%rcx, -280(%rbp)        # 8-byte Spill
	movq	-136(%rbp), %rcx
	movq	%rcx, -288(%rbp)        # 8-byte Spill
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	movq	-144(%rbp), %r15
	decq	%rdx
	movq	%rdx, -184(%rbp)
	movq	-152(%rbp), %r12
	movl	$0, -188(%rbp)
	movl	$0, -192(%rbp)
	cmpl	$0, (%rax)
	movq	-160(%rbp), %r14
	jle	.LBB16_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB16_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -312(%rbp)        # 8-byte Spill
	movq	%r8, -304(%rbp)         # 8-byte Spill
	movq	%rsi, -296(%rbp)        # 8-byte Spill
	movq	$0, -200(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	$1, -216(%rbp)
	movl	$0, -220(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-216(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-220(%rbp), %rcx
	leaq	-200(%rbp), %r8
	leaq	-208(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-208(%rbp), %rax
	cmpq	-184(%rbp), %rax
	jle	.LBB16_4
# BB#3:                                 # %cond.true
	movq	-184(%rbp), %rax
	jmp	.LBB16_5
.LBB16_4:                               # %cond.false
	movq	-208(%rbp), %rax
.LBB16_5:                               # %cond.end
	movq	88(%rbp), %r8
	movq	-296(%rbp), %r9         # 8-byte Reload
	movq	-304(%rbp), %r10        # 8-byte Reload
	movq	-312(%rbp), %r11        # 8-byte Reload
	movq	%rax, -208(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -176(%rbp)
	jmp	.LBB16_6
	.align	16, 0x90
.LBB16_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB16_6 Depth=1
	incq	-176(%rbp)
.LBB16_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB16_8 Depth 2
	movq	-176(%rbp), %rax
	cmpq	-208(%rbp), %rax
	jg	.LBB16_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB16_6 Depth=1
	movq	-176(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -224(%rbp)
	movq	-176(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -228(%rbp)
	movl	$0, -232(%rbp)
	jmp	.LBB16_8
	.align	16, 0x90
.LBB16_9:                               # %for.inc
                                        #   in Loop: Header=BB16_8 Depth=2
	movl	-228(%rbp), %eax
	imull	(%r13), %eax
	addl	-232(%rbp), %eax
	movl	-224(%rbp), %ecx
	imull	(%rbx), %ecx
	addl	%eax, %ecx
	movl	%ecx, -244(%rbp)
	movsd	(%r11), %xmm0           # xmm0 = mem[0],zero
	movslq	-244(%rbp), %rax
	movq	-264(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movq	-272(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movsd	8(%rcx,%rax,8), %xmm2   # xmm2 = mem[0],zero
	subsd	%xmm1, %xmm2
	movapd	%xmm1, %xmm3
	movslq	(%r13), %rsi
	leaq	(%rax,%rsi), %rdx
	movsd	(%rcx,%rdx,8), %xmm4    # xmm4 = mem[0],zero
	subsd	%xmm1, %xmm4
	movq	%rax, %rdi
	subq	%rsi, %rdi
	movapd	%xmm1, %xmm5
	subsd	(%rcx,%rdi,8), %xmm5
	movslq	(%rbx), %rsi
	movq	%rax, %rdi
	subq	%rsi, %rdi
	leaq	(%rax,%rsi), %rsi
	movsd	(%rcx,%rsi,8), %xmm6    # xmm6 = mem[0],zero
	subsd	%xmm1, %xmm6
	subsd	(%rcx,%rdi,8), %xmm1
	subsd	-8(%rcx,%rax,8), %xmm3
	movq	(%r15), %rcx
	mulsd	8(%rcx,%rax,8), %xmm2
	mulsd	(%rcx,%rax,8), %xmm3
	movq	(%r12), %rcx
	mulsd	(%rcx,%rdx,8), %xmm4
	mulsd	(%rcx,%rax,8), %xmm5
	movq	(%r14), %rcx
	mulsd	(%rcx,%rsi,8), %xmm6
	subsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm4
	subsd	%xmm5, %xmm4
	movq	-280(%rbp), %rdx        # 8-byte Reload
	movsd	(%rdx), %xmm2           # xmm2 = mem[0],zero
	movq	-288(%rbp), %rdx        # 8-byte Reload
	mulsd	(%rdx), %xmm2
	addsd	%xmm4, %xmm6
	mulsd	(%rcx,%rax,8), %xmm1
	subsd	%xmm1, %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm0
	movsd	%xmm0, -256(%rbp)
	movslq	-244(%rbp), %rax
	movq	(%r8), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-232(%rbp)
.LBB16_8:                               # %for.cond
                                        #   Parent Loop BB16_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-232(%rbp), %eax
	cmpl	(%r10), %eax
	jl	.LBB16_9
	jmp	.LBB16_10
.LBB16_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB16_12:                              # %omp.precond.end
	addq	$296, %rsp              # imm = 0x128
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end16:
	.size	.omp_outlined..10, .Lfunc_end16-.omp_outlined..10
	.cfi_endproc

	.globl	residual
	.align	16, 0x90
	.type	residual,@function
residual:                               # @residual
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp104:
	.cfi_def_cfa_offset 16
.Ltmp105:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp106:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$136, %rsp
.Ltmp107:
	.cfi_offset %rbx, -56
.Ltmp108:
	.cfi_offset %r12, -48
.Ltmp109:
	.cfi_offset %r13, -40
.Ltmp110:
	.cfi_offset %r14, -32
.Ltmp111:
	.cfi_offset %r15, -24
	movsd	%xmm1, -120(%rbp)       # 8-byte Spill
	movsd	%xmm0, -128(%rbp)       # 8-byte Spill
	movl	%r8d, %r15d
	movl	%ecx, %r12d
	movl	%edx, %r13d
	movl	%esi, %ebx
	movq	%rdi, %r14
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -132(%rbp)        # 4-byte Spill
	movl	$0, -112(%rbp)
	movq	%r14, -48(%rbp)
	movl	%ebx, -52(%rbp)
	movl	%r13d, -56(%rbp)
	movl	%r12d, -60(%rbp)
	movl	%r15d, -64(%rbp)
	movsd	-128(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -72(%rbp)
	movsd	-120(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -80(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-60(%rbp), %edx
	movl	$1, %ecx
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
	callq	exchange_boundary
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -88(%rbp)
	movl	$100000, -92(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -96(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-92(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -100(%rbp)
	cmpl	$0, -96(%rbp)
	je	.LBB17_2
# BB#1:                                 # %omp_if.then
	leaq	-80(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-64(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-60(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..11, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB17_3
.LBB17_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-132(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -108(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-108(%rbp), %rdi
	leaq	-112(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-60(%rbp), %r8
	leaq	-64(%rbp), %r9
	callq	.omp_outlined..11
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB17_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-88(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 160(%rdx,%rcx,8)
	addq	$136, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end17:
	.size	residual, .Lfunc_end17-residual
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI18_0:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..11,@function
.omp_outlined..11:                      # @.omp_outlined..11
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp112:
	.cfi_def_cfa_offset 16
.Ltmp113:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp114:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$344, %rsp              # imm = 0x158
.Ltmp115:
	.cfi_offset %rbx, -56
.Ltmp116:
	.cfi_offset %r12, -48
.Ltmp117:
	.cfi_offset %r13, -40
.Ltmp118:
	.cfi_offset %r14, -32
.Ltmp119:
	.cfi_offset %r15, -24
	movq	40(%rbp), %rbx
	movq	32(%rbp), %r10
	movq	24(%rbp), %r11
	movq	16(%rbp), %rax
	movl	$0, -260(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r11, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%rbx, -120(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -272(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rax
	movq	%rax, -280(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -288(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rbx
	movq	-112(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB18_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -136(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -140(%rbp)
	movl	$1, -144(%rbp)
	movl	$0, -148(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-144(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-148(%rbp), %rcx
	leaq	-136(%rbp), %r8
	leaq	-140(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-140(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.LBB18_3
# BB#2:                                 # %cond.true
	movl	-128(%rbp), %eax
	jmp	.LBB18_4
.LBB18_3:                               # %cond.false
	movl	-140(%rbp), %eax
.LBB18_4:                               # %cond.end
	movl	%eax, -140(%rbp)
	movl	-136(%rbp), %eax
	movl	%eax, -124(%rbp)
	jmp	.LBB18_5
	.align	16, 0x90
.LBB18_7:                               # %omp_if.then
                                        #   in Loop: Header=BB18_5 Depth=1
	leaq	-216(%rbp), %rax
	movq	%rax, 88(%rsp)
	leaq	-256(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	40(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	%r12, 16(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$15, %esi
	movl	$.omp_outlined..12, %edx
	xorl	%eax, %eax
	leaq	-184(%rbp), %rcx
	leaq	-188(%rbp), %r8
	leaq	-192(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-124(%rbp)
.LBB18_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-124(%rbp), %eax
	cmpl	-140(%rbp), %eax
	jg	.LBB18_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB18_5 Depth=1
	movl	-124(%rbp), %eax
	movl	%eax, -152(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -192(%rbp)
	movslq	(%r15), %rax
	movq	(%r14), %rcx
	movsd	1616(%rcx,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	.LCPI18_0(%rip), %xmm1  # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -200(%rbp)
	movq	-272(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	movq	-280(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -216(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-180(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-176(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	16(%rax), %rdx
	movq	%rdx, -224(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-180(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-176(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movq	%rdx, -232(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-180(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-176(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movq	%rdx, -240(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-180(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-176(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movq	%rdx, -248(%rbp)
	movq	-288(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -256(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB18_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB18_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-216(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-256(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 48(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 40(%rsp)
	movq	40(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-224(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	%r12, 8(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-260(%rbp), %rsi
	leaq	-184(%rbp), %rdx
	leaq	-188(%rbp), %rcx
	leaq	-192(%rbp), %r8
	leaq	-172(%rbp), %r9
	callq	.omp_outlined..12
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-124(%rbp)
	jmp	.LBB18_5
.LBB18_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB18_10:                              # %omp.precond.end
	addq	$344, %rsp              # imm = 0x158
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end18:
	.size	.omp_outlined..11, .Lfunc_end18-.omp_outlined..11
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..12,@function
.omp_outlined..12:                      # @.omp_outlined..12
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp120:
	.cfi_def_cfa_offset 16
.Ltmp121:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp122:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$312, %rsp              # imm = 0x138
.Ltmp123:
	.cfi_offset %rbx, -56
.Ltmp124:
	.cfi_offset %r12, -48
.Ltmp125:
	.cfi_offset %r13, -40
.Ltmp126:
	.cfi_offset %r14, -32
.Ltmp127:
	.cfi_offset %r15, -24
	movq	96(%rbp), %r13
	movq	88(%rbp), %r10
	movq	80(%rbp), %r11
	movq	72(%rbp), %r14
	movq	64(%rbp), %r15
	movq	56(%rbp), %r12
	movq	48(%rbp), %rbx
	movq	40(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	32(%rbp), %rdi
	movq	%rsi, -56(%rbp)
	movq	24(%rbp), %rsi
	movq	%rdx, -64(%rbp)
	movq	16(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r13, %rcx
	movq	%r9, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movq	%rsi, -104(%rbp)
	movq	%rdi, -112(%rbp)
	movq	%rax, -120(%rbp)
	movq	%rbx, -128(%rbp)
	movq	%r12, -136(%rbp)
	movq	%r15, -144(%rbp)
	movq	%r14, -152(%rbp)
	movq	%r11, -160(%rbp)
	movq	%r10, -168(%rbp)
	movq	%rcx, -176(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r8
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %rbx
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %rcx
	movq	%rcx, -272(%rbp)        # 8-byte Spill
	movq	-120(%rbp), %rcx
	movq	%rcx, -280(%rbp)        # 8-byte Spill
	movq	-128(%rbp), %rcx
	movq	%rcx, -288(%rbp)        # 8-byte Spill
	movq	-136(%rbp), %rcx
	movq	%rcx, -296(%rbp)        # 8-byte Spill
	movq	-144(%rbp), %rcx
	movq	%rcx, -304(%rbp)        # 8-byte Spill
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	movq	-152(%rbp), %r12
	decq	%rdx
	movq	%rdx, -192(%rbp)
	movq	-160(%rbp), %r14
	movl	$0, -196(%rbp)
	movl	$0, -200(%rbp)
	cmpl	$0, (%rax)
	movq	-168(%rbp), %r15
	jle	.LBB19_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB19_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -328(%rbp)        # 8-byte Spill
	movq	%r8, -320(%rbp)         # 8-byte Spill
	movq	%rsi, -312(%rbp)        # 8-byte Spill
	movq	$0, -208(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	$1, -224(%rbp)
	movl	$0, -228(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-224(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-228(%rbp), %rcx
	leaq	-208(%rbp), %r8
	leaq	-216(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-216(%rbp), %rax
	cmpq	-192(%rbp), %rax
	jle	.LBB19_4
# BB#3:                                 # %cond.true
	movq	-192(%rbp), %rax
	jmp	.LBB19_5
.LBB19_4:                               # %cond.false
	movq	-216(%rbp), %rax
.LBB19_5:                               # %cond.end
	movq	96(%rbp), %r8
	movq	-312(%rbp), %r9         # 8-byte Reload
	movq	-320(%rbp), %r10        # 8-byte Reload
	movq	-328(%rbp), %r11        # 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -184(%rbp)
	jmp	.LBB19_6
	.align	16, 0x90
.LBB19_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB19_6 Depth=1
	incq	-184(%rbp)
.LBB19_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB19_8 Depth 2
	movq	-184(%rbp), %rax
	cmpq	-216(%rbp), %rax
	jg	.LBB19_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB19_6 Depth=1
	movq	-184(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -232(%rbp)
	movq	-184(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -236(%rbp)
	movl	$0, -240(%rbp)
	jmp	.LBB19_8
	.align	16, 0x90
.LBB19_9:                               # %for.inc
                                        #   in Loop: Header=BB19_8 Depth=2
	movl	-236(%rbp), %eax
	imull	(%r13), %eax
	addl	-240(%rbp), %eax
	movl	-232(%rbp), %ecx
	imull	(%rbx), %ecx
	addl	%eax, %ecx
	movl	%ecx, -252(%rbp)
	movsd	(%r11), %xmm0           # xmm0 = mem[0],zero
	movslq	-252(%rbp), %rax
	movq	-272(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movq	-280(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movsd	8(%rcx,%rax,8), %xmm2   # xmm2 = mem[0],zero
	subsd	%xmm1, %xmm2
	movapd	%xmm1, %xmm3
	movslq	(%r13), %rsi
	leaq	(%rax,%rsi), %rdx
	movsd	(%rcx,%rdx,8), %xmm4    # xmm4 = mem[0],zero
	subsd	%xmm1, %xmm4
	movq	%rax, %rdi
	subq	%rsi, %rdi
	movapd	%xmm1, %xmm5
	subsd	(%rcx,%rdi,8), %xmm5
	movslq	(%rbx), %rsi
	movq	%rax, %rdi
	subq	%rsi, %rdi
	leaq	(%rax,%rsi), %rsi
	movsd	(%rcx,%rsi,8), %xmm6    # xmm6 = mem[0],zero
	subsd	%xmm1, %xmm6
	subsd	(%rcx,%rdi,8), %xmm1
	subsd	-8(%rcx,%rax,8), %xmm3
	movq	-304(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	mulsd	8(%rcx,%rax,8), %xmm2
	mulsd	(%rcx,%rax,8), %xmm3
	movq	(%r12), %rcx
	mulsd	(%rcx,%rdx,8), %xmm4
	mulsd	(%rcx,%rax,8), %xmm5
	movq	(%r14), %rcx
	mulsd	(%rcx,%rsi,8), %xmm6
	subsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm4
	subsd	%xmm5, %xmm4
	movq	-288(%rbp), %rdx        # 8-byte Reload
	movsd	(%rdx), %xmm2           # xmm2 = mem[0],zero
	movq	-296(%rbp), %rdx        # 8-byte Reload
	mulsd	(%rdx), %xmm2
	addsd	%xmm4, %xmm6
	mulsd	(%rcx,%rax,8), %xmm1
	subsd	%xmm1, %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm0
	movsd	%xmm0, -264(%rbp)
	movslq	-252(%rbp), %rax
	movq	(%r8), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movq	(%r15), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-240(%rbp)
.LBB19_8:                               # %for.cond
                                        #   Parent Loop BB19_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-240(%rbp), %eax
	cmpl	(%r10), %eax
	jl	.LBB19_9
	jmp	.LBB19_10
.LBB19_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB19_12:                              # %omp.precond.end
	addq	$312, %rsp              # imm = 0x138
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end19:
	.size	.omp_outlined..12, .Lfunc_end19-.omp_outlined..12
	.cfi_endproc

	.globl	residual_and_restriction
	.align	16, 0x90
	.type	residual_and_restriction,@function
residual_and_restriction:               # @residual_and_restriction
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp128:
	.cfi_def_cfa_offset 16
.Ltmp129:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp130:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$152, %rsp
.Ltmp131:
	.cfi_offset %rbx, -56
.Ltmp132:
	.cfi_offset %r12, -48
.Ltmp133:
	.cfi_offset %r13, -40
.Ltmp134:
	.cfi_offset %r14, -32
.Ltmp135:
	.cfi_offset %r15, -24
	movsd	%xmm1, -128(%rbp)       # 8-byte Spill
	movsd	%xmm0, -136(%rbp)       # 8-byte Spill
	movl	%r9d, -140(%rbp)        # 4-byte Spill
	movl	%r8d, %r12d
	movl	%ecx, %r13d
	movl	%edx, %ebx
	movl	%esi, %r14d
	movq	%rdi, %r15
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -144(%rbp)        # 4-byte Spill
	movl	$0, -120(%rbp)
	movq	%r15, -48(%rbp)
	movl	%r14d, -52(%rbp)
	movl	%ebx, -56(%rbp)
	movl	%r13d, -60(%rbp)
	movl	%r12d, -64(%rbp)
	movl	-140(%rbp), %eax        # 4-byte Reload
	movl	%eax, -68(%rbp)
	movsd	-136(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -80(%rbp)
	movsd	-128(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -88(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movl	$1, %ecx
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
	callq	exchange_boundary
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -96(%rbp)
	movl	$100000, -100(%rbp)     # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -104(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-100(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -108(%rbp)
	cmpl	$0, -104(%rbp)
	je	.LBB20_2
# BB#1:                                 # %omp_if.then
	leaq	-88(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-80(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-108(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-64(%rbp), %r8
	leaq	-52(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..13, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB20_3
.LBB20_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-144(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -116(%rbp)
	leaq	-88(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-80(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-108(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-116(%rbp), %rdi
	leaq	-120(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	callq	.omp_outlined..13
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB20_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-96(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 160(%rdx,%rcx,8)
	addq	$152, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end20:
	.size	residual_and_restriction, .Lfunc_end20-residual_and_restriction
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI21_0:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..13,@function
.omp_outlined..13:                      # @.omp_outlined..13
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp136:
	.cfi_def_cfa_offset 16
.Ltmp137:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp138:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$408, %rsp              # imm = 0x198
.Ltmp139:
	.cfi_offset %rbx, -56
.Ltmp140:
	.cfi_offset %r12, -48
.Ltmp141:
	.cfi_offset %r13, -40
.Ltmp142:
	.cfi_offset %r14, -32
.Ltmp143:
	.cfi_offset %r15, -24
	movq	48(%rbp), %rax
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %r14
	movq	16(%rbp), %rbx
	movl	$0, -292(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r14, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%rax, -128(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rax
	movq	%rax, -304(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -312(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rax
	movq	%rax, -320(%rbp)        # 8-byte Spill
	movq	-112(%rbp), %rax
	movq	%rax, -328(%rbp)        # 8-byte Spill
	movq	-120(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB21_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -144(%rbp)
	movl	-136(%rbp), %eax
	movl	%eax, -148(%rbp)
	movl	$1, -152(%rbp)
	movl	$0, -156(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-152(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-156(%rbp), %rcx
	leaq	-144(%rbp), %r8
	leaq	-148(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-148(%rbp), %eax
	cmpl	-136(%rbp), %eax
	jle	.LBB21_3
# BB#2:                                 # %cond.true
	movl	-136(%rbp), %eax
	jmp	.LBB21_4
.LBB21_3:                               # %cond.false
	movl	-148(%rbp), %eax
.LBB21_4:                               # %cond.end
	movl	%eax, -148(%rbp)
	movl	-144(%rbp), %eax
	movl	%eax, -132(%rbp)
	jmp	.LBB21_5
	.align	16, 0x90
.LBB21_7:                               # %omp_if.then
                                        #   in Loop: Header=BB21_5 Depth=1
	leaq	-248(%rbp), %rax
	movq	%rax, 112(%rsp)
	leaq	-280(%rbp), %rax
	movq	%rax, 104(%rsp)
	leaq	-272(%rbp), %rax
	movq	%rax, 96(%rsp)
	leaq	-264(%rbp), %rax
	movq	%rax, 88(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 80(%rsp)
	movq	48(%rbp), %rax
	movq	%rax, 72(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-256(%rbp), %rax
	movq	%rax, 56(%rsp)
	movq	%rbx, 48(%rsp)
	leaq	-204(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-220(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-288(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-180(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$18, %esi
	movl	$.omp_outlined..14, %edx
	xorl	%eax, %eax
	leaq	-212(%rbp), %rcx
	leaq	-216(%rbp), %r8
	leaq	-196(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-132(%rbp)
.LBB21_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-132(%rbp), %eax
	cmpl	-148(%rbp), %eax
	jg	.LBB21_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB21_5 Depth=1
	movl	-132(%rbp), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -192(%rbp)
	movslq	(%r15), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -196(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -200(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -204(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -208(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -212(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -216(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -220(%rbp)
	movslq	(%r12), %rax
	movq	(%r14), %rcx
	movsd	1616(%rcx,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	.LCPI21_0(%rip), %xmm1  # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -232(%rbp)
	movq	-304(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r12), %rcx
	movslq	-160(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-208(%rbp), %rdx
	movslq	-200(%rbp), %rsi
	movslq	-204(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -240(%rbp)
	movq	-312(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r12), %rcx
	movslq	-160(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-208(%rbp), %rdx
	movslq	-200(%rbp), %rsi
	movslq	-204(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -248(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-208(%rbp), %rcx
	movslq	-200(%rbp), %rdx
	movslq	-204(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	16(%rax), %rdx
	movq	%rdx, -256(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-208(%rbp), %rcx
	movslq	-200(%rbp), %rdx
	movslq	-204(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movq	%rdx, -264(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-208(%rbp), %rcx
	movslq	-200(%rbp), %rdx
	movslq	-204(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movq	%rdx, -272(%rbp)
	movslq	(%r12), %rax
	movslq	-160(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-208(%rbp), %rcx
	movslq	-200(%rbp), %rdx
	movslq	-204(%rbp), %rsi
	leaq	1(%rdx,%rsi), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movq	%rdx, -280(%rbp)
	movq	-320(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-160(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-184(%rbp), %rdx
	movslq	-176(%rbp), %rsi
	movslq	-180(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -288(%rbp)
	movq	-328(%rbp), %rax        # 8-byte Reload
	cmpl	$0, (%rax)
	jne	.LBB21_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB21_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-248(%rbp), %rax
	movq	%rax, 104(%rsp)
	leaq	-280(%rbp), %rax
	movq	%rax, 96(%rsp)
	leaq	-272(%rbp), %rax
	movq	%rax, 88(%rsp)
	leaq	-264(%rbp), %rax
	movq	%rax, 80(%rsp)
	leaq	-232(%rbp), %rax
	movq	%rax, 72(%rsp)
	movq	48(%rbp), %rax
	movq	%rax, 64(%rsp)
	leaq	-240(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-256(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	%rbx, 40(%rsp)
	leaq	-204(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-220(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-288(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-180(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-292(%rbp), %rsi
	leaq	-212(%rbp), %rdx
	leaq	-216(%rbp), %rcx
	leaq	-196(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	.omp_outlined..14
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-132(%rbp)
	jmp	.LBB21_5
.LBB21_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB21_10:                              # %omp.precond.end
	addq	$408, %rsp              # imm = 0x198
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end21:
	.size	.omp_outlined..13, .Lfunc_end21-.omp_outlined..13
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI22_0:
	.quad	4593671619917905920     # double 0.125
	.text
	.align	16, 0x90
	.type	.omp_outlined..14,@function
.omp_outlined..14:                      # @.omp_outlined..14
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp144:
	.cfi_def_cfa_offset 16
.Ltmp145:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp146:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$392, %rsp              # imm = 0x188
.Ltmp147:
	.cfi_offset %rbx, -56
.Ltmp148:
	.cfi_offset %r12, -48
.Ltmp149:
	.cfi_offset %r13, -40
.Ltmp150:
	.cfi_offset %r14, -32
.Ltmp151:
	.cfi_offset %r15, -24
	movq	120(%rbp), %rax
	movq	104(%rbp), %r11
	movq	96(%rbp), %r14
	movq	88(%rbp), %r15
	movq	80(%rbp), %r12
	movq	72(%rbp), %r13
	movq	64(%rbp), %r10
	movq	%rdi, -48(%rbp)
	movq	56(%rbp), %rdi
	movq	%rsi, -56(%rbp)
	movq	48(%rbp), %rsi
	movq	%rdx, -64(%rbp)
	movq	40(%rbp), %rdx
	movq	%rcx, -72(%rbp)
	movq	32(%rbp), %rcx
	movq	%r8, -80(%rbp)
	movq	%rax, %r8
	movq	24(%rbp), %rbx
	movq	%r9, -88(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	%rdi, -136(%rbp)
	movq	%r10, -144(%rbp)
	movq	%r13, -152(%rbp)
	movq	%r12, -160(%rbp)
	movq	%r15, -168(%rbp)
	movq	%r14, -176(%rbp)
	movq	%r11, -184(%rbp)
	movq	112(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	%r8, -200(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdi
	movq	-80(%rbp), %r9
	movq	-88(%rbp), %r10
	movq	-96(%rbp), %rbx
	movq	-104(%rbp), %rcx
	movq	%rcx, -320(%rbp)        # 8-byte Spill
	movq	-112(%rbp), %rcx
	movq	%rcx, -312(%rbp)        # 8-byte Spill
	movq	-120(%rbp), %r12
	movq	-128(%rbp), %r13
	movq	-136(%rbp), %rcx
	movq	%rcx, -328(%rbp)        # 8-byte Spill
	movl	(%rax), %ecx
	leal	1(%rcx), %edx
	shrl	$31, %edx
	leal	1(%rcx,%rdx), %ecx
	movl	(%rdi), %edx
	leal	1(%rdx), %esi
	shrl	$31, %esi
	leal	1(%rdx,%rsi), %edx
	movq	-144(%rbp), %rsi
	movq	%rsi, -336(%rbp)        # 8-byte Spill
	sarl	%ecx
	movslq	%ecx, %rcx
	sarl	%edx
	movslq	%edx, %rdx
	imulq	%rcx, %rdx
	movq	-152(%rbp), %rcx
	movq	%rcx, -344(%rbp)        # 8-byte Spill
	decq	%rdx
	movq	%rdx, -216(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -352(%rbp)        # 8-byte Spill
	movl	$0, -220(%rbp)
	movl	$0, -224(%rbp)
	cmpl	$0, (%rax)
	movq	-168(%rbp), %rax
	movq	%rax, -360(%rbp)        # 8-byte Spill
	movq	-176(%rbp), %rax
	movq	%rax, -368(%rbp)        # 8-byte Spill
	movq	-184(%rbp), %r15
	movq	-192(%rbp), %r14
	jle	.LBB22_21
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rdi)
	jle	.LBB22_21
# BB#2:                                 # %omp.precond.then
	movq	%rbx, -400(%rbp)        # 8-byte Spill
	movq	%r10, -392(%rbp)        # 8-byte Spill
	movq	%r9, -384(%rbp)         # 8-byte Spill
	movq	%rdi, -376(%rbp)        # 8-byte Spill
	movq	%r8, %rbx
	movq	$0, -232(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -240(%rbp)
	movq	$1, -248(%rbp)
	movl	$0, -252(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-248(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-252(%rbp), %rcx
	leaq	-232(%rbp), %r8
	leaq	-240(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-240(%rbp), %rax
	cmpq	-216(%rbp), %rax
	jle	.LBB22_4
# BB#3:                                 # %cond.true
	movq	-216(%rbp), %rax
	jmp	.LBB22_5
.LBB22_4:                               # %cond.false
	movq	-240(%rbp), %rax
.LBB22_5:                               # %cond.end
	movq	-376(%rbp), %r8         # 8-byte Reload
	movq	-384(%rbp), %r9         # 8-byte Reload
	movq	-392(%rbp), %r10        # 8-byte Reload
	movq	-400(%rbp), %r11        # 8-byte Reload
	movq	%rax, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	%rax, -208(%rbp)
	movsd	.LCPI22_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB22_6
	.align	16, 0x90
.LBB22_19:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB22_6 Depth=1
	incq	-208(%rbp)
.LBB22_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB22_8 Depth 2
                                        #     Child Loop BB22_11 Depth 2
                                        #       Child Loop BB22_13 Depth 3
                                        #         Child Loop BB22_15 Depth 4
	movq	-208(%rbp), %rax
	cmpq	-240(%rbp), %rax
	jg	.LBB22_20
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB22_6 Depth=1
	movq	-208(%rbp), %rax
	movl	(%r8), %ecx
	leal	1(%rcx), %edx
	shrl	$31, %edx
	leal	1(%rcx,%rdx), %ecx
	sarl	%ecx
	movslq	%ecx, %rcx
	cqto
	idivq	%rcx
	addl	%eax, %eax
	movl	%eax, -256(%rbp)
	movq	-208(%rbp), %rax
	movl	(%r8), %ecx
	leal	1(%rcx), %edx
	shrl	$31, %edx
	leal	1(%rcx,%rdx), %ecx
	sarl	%ecx
	movslq	%ecx, %rcx
	cqto
	idivq	%rcx
	addl	%edx, %edx
	movl	%edx, -260(%rbp)
	movl	$0, -272(%rbp)
	jmp	.LBB22_8
	.align	16, 0x90
.LBB22_9:                               # %for.inc
                                        #   in Loop: Header=BB22_8 Depth=2
	movl	-260(%rbp), %eax
	sarl	%eax
	imull	(%r10), %eax
	addl	-272(%rbp), %eax
	movl	-256(%rbp), %ecx
	sarl	%ecx
	imull	(%r11), %ecx
	addl	%eax, %ecx
	movl	%ecx, -284(%rbp)
	movslq	-284(%rbp), %rax
	movq	-320(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-272(%rbp)
.LBB22_8:                               # %for.cond
                                        #   Parent Loop BB22_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-272(%rbp), %eax
	cmpl	(%r9), %eax
	jl	.LBB22_9
# BB#10:                                # %for.end
                                        #   in Loop: Header=BB22_6 Depth=1
	movl	-256(%rbp), %eax
	movl	%eax, -280(%rbp)
	jmp	.LBB22_11
	.align	16, 0x90
.LBB22_18:                              # %for.inc155
                                        #   in Loop: Header=BB22_11 Depth=2
	incl	-280(%rbp)
.LBB22_11:                              # %for.cond45
                                        #   Parent Loop BB22_6 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB22_13 Depth 3
                                        #         Child Loop BB22_15 Depth 4
	movl	-256(%rbp), %eax
	addl	$2, %eax
	cmpl	%eax, -280(%rbp)
	jge	.LBB22_19
# BB#12:                                # %for.body49
                                        #   in Loop: Header=BB22_11 Depth=2
	movl	-260(%rbp), %eax
	movl	%eax, -276(%rbp)
	jmp	.LBB22_13
	.align	16, 0x90
.LBB22_17:                              # %for.inc152
                                        #   in Loop: Header=BB22_13 Depth=3
	incl	-276(%rbp)
.LBB22_13:                              # %for.cond50
                                        #   Parent Loop BB22_6 Depth=1
                                        #     Parent Loop BB22_11 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB22_15 Depth 4
	movl	-260(%rbp), %eax
	addl	$2, %eax
	cmpl	%eax, -276(%rbp)
	jge	.LBB22_18
# BB#14:                                # %for.body54
                                        #   in Loop: Header=BB22_13 Depth=3
	movl	$0, -272(%rbp)
	jmp	.LBB22_15
	.align	16, 0x90
.LBB22_16:                              # %for.inc149
                                        #   in Loop: Header=BB22_15 Depth=4
	movl	-276(%rbp), %eax
	imull	(%r12), %eax
	addl	-272(%rbp), %eax
	movl	-280(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -288(%rbp)
	movl	-272(%rbp), %eax
	sarl	%eax
	movl	-276(%rbp), %ecx
	sarl	%ecx
	imull	(%r10), %ecx
	addl	%eax, %ecx
	movl	-280(%rbp), %eax
	sarl	%eax
	imull	(%r11), %eax
	addl	%ecx, %eax
	movl	%eax, -292(%rbp)
	movq	-328(%rbp), %rax        # 8-byte Reload
	movsd	(%rax), %xmm1           # xmm1 = mem[0],zero
	movslq	-288(%rbp), %rax
	movq	-336(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	mulsd	(%rcx,%rax,8), %xmm1
	movq	-344(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm2    # xmm2 = mem[0],zero
	mulsd	%xmm2, %xmm1
	movsd	8(%rcx,%rax,8), %xmm3   # xmm3 = mem[0],zero
	subsd	%xmm2, %xmm3
	movapd	%xmm2, %xmm4
	movslq	(%r12), %rsi
	leaq	(%rax,%rsi), %rdx
	movsd	(%rcx,%rdx,8), %xmm5    # xmm5 = mem[0],zero
	subsd	%xmm2, %xmm5
	movq	%rax, %rdi
	subq	%rsi, %rdi
	movapd	%xmm2, %xmm6
	subsd	(%rcx,%rdi,8), %xmm6
	movslq	(%r13), %rsi
	movq	%rax, %rdi
	subq	%rsi, %rdi
	leaq	(%rax,%rsi), %rsi
	movsd	(%rcx,%rsi,8), %xmm7    # xmm7 = mem[0],zero
	subsd	%xmm2, %xmm7
	subsd	(%rcx,%rdi,8), %xmm2
	subsd	-8(%rcx,%rax,8), %xmm4
	movq	-368(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	mulsd	8(%rcx,%rax,8), %xmm3
	mulsd	(%rcx,%rax,8), %xmm4
	movq	(%r15), %rcx
	mulsd	(%rcx,%rdx,8), %xmm5
	mulsd	(%rcx,%rax,8), %xmm6
	movq	(%r14), %rcx
	mulsd	(%rcx,%rsi,8), %xmm7
	subsd	%xmm4, %xmm3
	addsd	%xmm3, %xmm5
	subsd	%xmm6, %xmm5
	movq	-352(%rbp), %rdx        # 8-byte Reload
	movsd	(%rdx), %xmm3           # xmm3 = mem[0],zero
	movq	-360(%rbp), %rdx        # 8-byte Reload
	mulsd	(%rdx), %xmm3
	addsd	%xmm5, %xmm7
	mulsd	(%rcx,%rax,8), %xmm2
	subsd	%xmm2, %xmm7
	mulsd	%xmm3, %xmm7
	subsd	%xmm7, %xmm1
	movsd	%xmm1, -304(%rbp)
	movslq	-288(%rbp), %rax
	movq	(%rbx), %rcx
	movsd	(%rcx,%rax,8), %xmm2    # xmm2 = mem[0],zero
	subsd	%xmm1, %xmm2
	mulsd	%xmm0, %xmm2
	movslq	-292(%rbp), %rax
	movq	-320(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	addsd	(%rcx,%rax,8), %xmm2
	movsd	%xmm2, (%rcx,%rax,8)
	incl	-272(%rbp)
.LBB22_15:                              # %for.cond55
                                        #   Parent Loop BB22_6 Depth=1
                                        #     Parent Loop BB22_11 Depth=2
                                        #       Parent Loop BB22_13 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-272(%rbp), %eax
	movq	-312(%rbp), %rcx        # 8-byte Reload
	cmpl	(%rcx), %eax
	jl	.LBB22_16
	jmp	.LBB22_17
.LBB22_20:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB22_21:                              # %omp.precond.end
	addq	$392, %rsp              # imm = 0x188
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end22:
	.size	.omp_outlined..14, .Lfunc_end22-.omp_outlined..14
	.cfi_endproc

	.globl	restriction
	.align	16, 0x90
	.type	restriction,@function
restriction:                            # @restriction
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp152:
	.cfi_def_cfa_offset 16
.Ltmp153:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp154:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
.Ltmp155:
	.cfi_offset %rbx, -56
.Ltmp156:
	.cfi_offset %r12, -48
.Ltmp157:
	.cfi_offset %r13, -40
.Ltmp158:
	.cfi_offset %r14, -32
.Ltmp159:
	.cfi_offset %r15, -24
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -96(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movl	%r15d, -60(%rbp)
	movl	-52(%rbp), %eax
	incl	%eax
	movl	%eax, -64(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -72(%rbp)
	movl	$100000, -76(%rbp)      # imm = 0x186A0
	movslq	-64(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -80(%rbp)
	movslq	-64(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-76(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -84(%rbp)
	cmpl	$0, -80(%rbp)
	je	.LBB23_2
# BB#1:                                 # %omp_if.then
	leaq	-84(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-64(%rbp), %r8
	leaq	-52(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..15, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB23_3
.LBB23_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -92(%rbp)
	leaq	-84(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-92(%rbp), %rdi
	leaq	-96(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-60(%rbp), %r9
	callq	.omp_outlined..15
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB23_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-72(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 240(%rdx,%rcx,8)
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end23:
	.size	restriction, .Lfunc_end23-restriction
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..15,@function
.omp_outlined..15:                      # @.omp_outlined..15
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp160:
	.cfi_def_cfa_offset 16
.Ltmp161:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp162:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
.Ltmp163:
	.cfi_offset %rbx, -56
.Ltmp164:
	.cfi_offset %r12, -48
.Ltmp165:
	.cfi_offset %r13, -40
.Ltmp166:
	.cfi_offset %r14, -32
.Ltmp167:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -212(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rax
	movq	%rax, -224(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB24_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB24_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB24_4
.LBB24_3:                               # %cond.false
	movl	-124(%rbp), %eax
.LBB24_4:                               # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB24_5
	.align	16, 0x90
.LBB24_7:                               # %omp_if.then
                                        #   in Loop: Header=BB24_5 Depth=1
	leaq	-200(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-188(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-164(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..16, %edx
	xorl	%eax, %eax
	leaq	-176(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-168(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-108(%rbp)
.LBB24_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB24_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB24_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r12), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r12), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r12), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movq	-224(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r12), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-184(%rbp), %rsi
	movslq	-188(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -200(%rbp)
	movslq	(%rbx), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-156(%rbp), %rdx
	movslq	-160(%rbp), %rsi
	movslq	-164(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	movq	24(%rbp), %rax
	cmpl	$0, (%rax)
	jne	.LBB24_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB24_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-200(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-188(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-164(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-212(%rbp), %rsi
	leaq	-176(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-168(%rbp), %r8
	leaq	-160(%rbp), %r9
	callq	.omp_outlined..16
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-108(%rbp)
	jmp	.LBB24_5
.LBB24_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB24_10:                              # %omp.precond.end
	addq	$232, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end24:
	.size	.omp_outlined..15, .Lfunc_end24-.omp_outlined..15
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI25_0:
	.quad	4593671619917905920     # double 0.125
	.text
	.align	16, 0x90
	.type	.omp_outlined..16,@function
.omp_outlined..16:                      # @.omp_outlined..16
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp168:
	.cfi_def_cfa_offset 16
.Ltmp169:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp170:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp171:
	.cfi_offset %rbx, -56
.Ltmp172:
	.cfi_offset %r12, -48
.Ltmp173:
	.cfi_offset %r13, -40
.Ltmp174:
	.cfi_offset %r14, -32
.Ltmp175:
	.cfi_offset %r15, -24
	movq	48(%rbp), %r14
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %rax
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%rax, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%r14, -128(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rbx
	movq	-80(%rbp), %r13
	movq	-88(%rbp), %rsi
	movq	-96(%rbp), %rdi
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movslq	(%rax), %rcx
	movslq	(%rbx), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -144(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -152(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB25_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rbx)
	jle	.LBB25_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -224(%rbp)        # 8-byte Spill
	movq	%rsi, -216(%rbp)        # 8-byte Spill
	movq	$0, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	$1, -176(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-180(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-168(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-168(%rbp), %rax
	cmpq	-144(%rbp), %rax
	jle	.LBB25_4
# BB#3:                                 # %cond.true
	movq	-144(%rbp), %rax
	jmp	.LBB25_5
.LBB25_4:                               # %cond.false
	movq	-168(%rbp), %rax
.LBB25_5:                               # %cond.end
	movq	48(%rbp), %r8
	movq	%rbx, %r9
	movq	-216(%rbp), %r10        # 8-byte Reload
	movq	-224(%rbp), %r11        # 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movsd	.LCPI25_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB25_6
	.align	16, 0x90
.LBB25_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB25_6 Depth=1
	incq	-136(%rbp)
.LBB25_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB25_8 Depth 2
	movq	-136(%rbp), %rax
	cmpq	-168(%rbp), %rax
	jg	.LBB25_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB25_6 Depth=1
	movq	-136(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-136(%rbp), %rax
	movslq	(%r9), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -188(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB25_8
	.align	16, 0x90
.LBB25_9:                               # %for.inc
                                        #   in Loop: Header=BB25_8 Depth=2
	movl	-188(%rbp), %eax
	imull	(%r10), %eax
	addl	-192(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%r11), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movl	-192(%rbp), %eax
	movl	-188(%rbp), %ecx
	imull	(%r14), %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rax,2), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	leal	(%rax,%rcx,2), %eax
	movl	%eax, -208(%rbp)
	movslq	-208(%rbp), %rax
	movq	(%r8), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	addsd	8(%rcx,%rax,8), %xmm1
	movslq	(%r14), %rdx
	leaq	(%rax,%rdx), %rsi
	addsd	(%rcx,%rsi,8), %xmm1
	leaq	1(%rax,%rdx), %rdx
	addsd	(%rcx,%rdx,8), %xmm1
	movslq	(%r15), %rdi
	leaq	(%rax,%rdi), %rbx
	addsd	(%rcx,%rbx,8), %xmm1
	leaq	1(%rax,%rdi), %rax
	addsd	(%rcx,%rax,8), %xmm1
	addq	%rdi, %rsi
	addsd	(%rcx,%rsi,8), %xmm1
	addq	%rdi, %rdx
	addsd	(%rcx,%rdx,8), %xmm1
	mulsd	%xmm0, %xmm1
	movslq	-204(%rbp), %rax
	movq	(%r12), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-192(%rbp)
.LBB25_8:                               # %for.cond
                                        #   Parent Loop BB25_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-192(%rbp), %eax
	cmpl	(%r13), %eax
	jl	.LBB25_9
	jmp	.LBB25_10
.LBB25_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB25_12:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end25:
	.size	.omp_outlined..16, .Lfunc_end25-.omp_outlined..16
	.cfi_endproc

	.globl	restriction_betas
	.align	16, 0x90
	.type	restriction_betas,@function
restriction_betas:                      # @restriction_betas
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp176:
	.cfi_def_cfa_offset 16
.Ltmp177:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp178:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
.Ltmp179:
	.cfi_offset %rbx, -48
.Ltmp180:
	.cfi_offset %r12, -40
.Ltmp181:
	.cfi_offset %r14, -32
.Ltmp182:
	.cfi_offset %r15, -24
	movl	%edx, %r15d
	movl	%esi, %r12d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -80(%rbp)
	movq	%rbx, -40(%rbp)
	movl	%r12d, -44(%rbp)
	movl	%r15d, -48(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	movl	$100000, -60(%rbp)      # imm = 0x186A0
	movslq	-48(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -64(%rbp)
	movslq	-48(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-60(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -68(%rbp)
	cmpl	$0, -64(%rbp)
	je	.LBB26_2
# BB#1:                                 # %omp_if.then
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-40(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-44(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$4, %esi
	movl	$.omp_outlined..17, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB26_3
.LBB26_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -76(%rbp)
	leaq	-76(%rbp), %rdi
	leaq	-80(%rbp), %rsi
	leaq	-40(%rbp), %rdx
	leaq	-48(%rbp), %rcx
	leaq	-44(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..17
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB26_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-56(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-40(%rbp), %rdx
	addq	%rax, 240(%rdx,%rcx,8)
	addq	$64, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end26:
	.size	restriction_betas, .Lfunc_end26-restriction_betas
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..17,@function
.omp_outlined..17:                      # @.omp_outlined..17
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp183:
	.cfi_def_cfa_offset 16
.Ltmp184:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp185:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp186:
	.cfi_offset %rbx, -56
.Ltmp187:
	.cfi_offset %r12, -48
.Ltmp188:
	.cfi_offset %r13, -40
.Ltmp189:
	.cfi_offset %r14, -32
.Ltmp190:
	.cfi_offset %r15, -24
	movq	%r9, %r14
	movl	$0, -204(%rbp)
	movl	$0, -200(%rbp)
	movl	$0, -196(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r14, -88(%rbp)
	movq	-64(%rbp), %r12
	movq	-72(%rbp), %r13
	movq	-80(%rbp), %r15
	movq	(%r12), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -96(%rbp)
	movl	$0, -100(%rbp)
	movq	(%r12), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB27_16
# BB#1:                                 # %omp.precond.then
	movl	$0, -104(%rbp)
	movl	-96(%rbp), %eax
	movl	%eax, -108(%rbp)
	movl	$1, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-112(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-116(%rbp), %rcx
	leaq	-104(%rbp), %r8
	leaq	-108(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-108(%rbp), %eax
	cmpl	-96(%rbp), %eax
	jle	.LBB27_3
# BB#2:                                 # %cond.true
	movl	-96(%rbp), %eax
	jmp	.LBB27_4
.LBB27_3:                               # %cond.false
	movl	-108(%rbp), %eax
.LBB27_4:                               # %cond.end
	movl	%eax, -108(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -92(%rbp)
	jmp	.LBB27_5
	.align	16, 0x90
.LBB27_13:                              # %omp_if.then166
                                        #   in Loop: Header=BB27_5 Depth=1
	leaq	-184(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..20, %edx
	xorl	%eax, %eax
	leaq	-160(%rbp), %rcx
	leaq	-156(%rbp), %r8
	leaq	-152(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-92(%rbp)
.LBB27_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-92(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jg	.LBB27_15
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB27_5 Depth=1
	movl	-92(%rbp), %eax
	movl	%eax, -120(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -140(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -148(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -152(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-164(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movslq	-168(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -184(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-140(%rbp), %rcx
	movslq	-148(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	40(%rax), %rdx
	movslq	-144(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -192(%rbp)
	cmpl	$0, (%r14)
	je	.LBB27_8
# BB#7:                                 # %omp_if.then
                                        #   in Loop: Header=BB27_5 Depth=1
	leaq	-184(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..18, %edx
	xorl	%eax, %eax
	leaq	-160(%rbp), %rcx
	leaq	-156(%rbp), %r8
	leaq	-152(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB27_9
	.align	16, 0x90
.LBB27_8:                               # %omp_if.else
                                        #   in Loop: Header=BB27_5 Depth=1
	movq	-48(%rbp), %rax
	movq	%r14, %rbx
	movl	(%rax), %r14d
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-184(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-196(%rbp), %rsi
	leaq	-160(%rbp), %rdx
	leaq	-156(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-144(%rbp), %r9
	callq	.omp_outlined..18
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	movq	%rbx, %r14
	callq	__kmpc_end_serialized_parallel
.LBB27_9:                               # %omp_if.end
                                        #   in Loop: Header=BB27_5 Depth=1
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-164(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movslq	-168(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -184(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-140(%rbp), %rcx
	movslq	-148(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	48(%rax), %rdx
	movslq	-144(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -192(%rbp)
	cmpl	$0, (%r14)
	je	.LBB27_11
# BB#10:                                # %omp_if.then129
                                        #   in Loop: Header=BB27_5 Depth=1
	leaq	-184(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..19, %edx
	xorl	%eax, %eax
	leaq	-160(%rbp), %rcx
	leaq	-156(%rbp), %r8
	leaq	-152(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB27_12
	.align	16, 0x90
.LBB27_11:                              # %omp_if.else130
                                        #   in Loop: Header=BB27_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-184(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-200(%rbp), %rsi
	leaq	-160(%rbp), %rdx
	leaq	-156(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-144(%rbp), %r9
	callq	.omp_outlined..19
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB27_12:                              # %omp_if.end132
                                        #   in Loop: Header=BB27_5 Depth=1
	movslq	(%r15), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-164(%rbp), %rcx
	movslq	-172(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movslq	-168(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -184(%rbp)
	movslq	(%r13), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r12), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rax
	movslq	-140(%rbp), %rcx
	movslq	-148(%rbp), %rdx
	imulq	%rcx, %rdx
	shlq	$3, %rdx
	addq	56(%rax), %rdx
	movslq	-144(%rbp), %rax
	imulq	%rcx, %rax
	leaq	(%rdx,%rax,8), %rax
	leaq	(%rax,%rcx,8), %rax
	movq	%rax, -192(%rbp)
	cmpl	$0, (%r14)
	jne	.LBB27_13
# BB#14:                                # %omp_if.else167
                                        #   in Loop: Header=BB27_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-184(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-204(%rbp), %rsi
	leaq	-160(%rbp), %rdx
	leaq	-156(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-144(%rbp), %r9
	callq	.omp_outlined..20
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-92(%rbp)
	jmp	.LBB27_5
.LBB27_15:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB27_16:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end27:
	.size	.omp_outlined..17, .Lfunc_end27-.omp_outlined..17
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI28_0:
	.quad	4598175219545276416     # double 0.25
	.text
	.align	16, 0x90
	.type	.omp_outlined..18,@function
.omp_outlined..18:                      # @.omp_outlined..18
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp191:
	.cfi_def_cfa_offset 16
.Ltmp192:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp193:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp194:
	.cfi_offset %rbx, -56
.Ltmp195:
	.cfi_offset %r12, -48
.Ltmp196:
	.cfi_offset %r13, -40
.Ltmp197:
	.cfi_offset %r14, -32
.Ltmp198:
	.cfi_offset %r15, -24
	movq	48(%rbp), %rax
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %r14
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rax, %rdi
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r14, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%rdi, -128(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r13
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %rdi
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -144(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -152(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB28_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB28_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -224(%rbp)        # 8-byte Spill
	movq	%rsi, -216(%rbp)        # 8-byte Spill
	movq	$0, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	$1, -176(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-180(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-168(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-168(%rbp), %rax
	cmpq	-144(%rbp), %rax
	jle	.LBB28_4
# BB#3:                                 # %cond.true
	movq	-144(%rbp), %rax
	jmp	.LBB28_5
.LBB28_4:                               # %cond.false
	movq	-168(%rbp), %rax
.LBB28_5:                               # %cond.end
	movq	48(%rbp), %rdi
	movq	%rdi, %r9
	movq	-216(%rbp), %r8         # 8-byte Reload
	movq	-224(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movsd	.LCPI28_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB28_6
	.align	16, 0x90
.LBB28_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB28_6 Depth=1
	incq	-136(%rbp)
.LBB28_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB28_8 Depth 2
	movq	-136(%rbp), %rax
	cmpq	-168(%rbp), %rax
	jg	.LBB28_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB28_6 Depth=1
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -188(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB28_8
	.align	16, 0x90
.LBB28_9:                               # %for.inc
                                        #   in Loop: Header=BB28_8 Depth=2
	movl	-188(%rbp), %eax
	imull	(%rbx), %eax
	addl	-192(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%rdi), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movl	-192(%rbp), %eax
	movl	-188(%rbp), %ecx
	imull	(%r14), %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rax,2), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	leal	(%rax,%rcx,2), %eax
	movl	%eax, -208(%rbp)
	movslq	-208(%rbp), %rax
	movq	(%r9), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	movslq	(%r14), %rdx
	addq	%rax, %rdx
	addsd	(%rcx,%rdx,8), %xmm1
	movslq	(%r15), %rsi
	addq	%rsi, %rax
	addsd	(%rcx,%rax,8), %xmm1
	addq	%rsi, %rdx
	addsd	(%rcx,%rdx,8), %xmm1
	mulsd	%xmm0, %xmm1
	movslq	-204(%rbp), %rax
	movq	(%r12), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-192(%rbp)
.LBB28_8:                               # %for.cond
                                        #   Parent Loop BB28_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-192(%rbp), %eax
	cmpl	(%r13), %eax
	jl	.LBB28_9
	jmp	.LBB28_10
.LBB28_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB28_12:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end28:
	.size	.omp_outlined..18, .Lfunc_end28-.omp_outlined..18
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI29_0:
	.quad	4598175219545276416     # double 0.25
	.text
	.align	16, 0x90
	.type	.omp_outlined..19,@function
.omp_outlined..19:                      # @.omp_outlined..19
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp199:
	.cfi_def_cfa_offset 16
.Ltmp200:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp201:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp202:
	.cfi_offset %rbx, -56
.Ltmp203:
	.cfi_offset %r12, -48
.Ltmp204:
	.cfi_offset %r13, -40
.Ltmp205:
	.cfi_offset %r14, -32
.Ltmp206:
	.cfi_offset %r15, -24
	movq	48(%rbp), %rax
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %r14
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rax, %rdi
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r14, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%rdi, -128(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r13
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %rdi
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -144(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -152(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB29_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB29_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -224(%rbp)        # 8-byte Spill
	movq	%rsi, -216(%rbp)        # 8-byte Spill
	movq	$0, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	$1, -176(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-180(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-168(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-168(%rbp), %rax
	cmpq	-144(%rbp), %rax
	jle	.LBB29_4
# BB#3:                                 # %cond.true
	movq	-144(%rbp), %rax
	jmp	.LBB29_5
.LBB29_4:                               # %cond.false
	movq	-168(%rbp), %rax
.LBB29_5:                               # %cond.end
	movq	48(%rbp), %rdi
	movq	%rdi, %r9
	movq	-216(%rbp), %r8         # 8-byte Reload
	movq	-224(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movsd	.LCPI29_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB29_6
	.align	16, 0x90
.LBB29_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB29_6 Depth=1
	incq	-136(%rbp)
.LBB29_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB29_8 Depth 2
	movq	-136(%rbp), %rax
	cmpq	-168(%rbp), %rax
	jg	.LBB29_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB29_6 Depth=1
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -188(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB29_8
	.align	16, 0x90
.LBB29_9:                               # %for.inc
                                        #   in Loop: Header=BB29_8 Depth=2
	movl	-188(%rbp), %eax
	imull	(%rbx), %eax
	addl	-192(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%rdi), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movl	-192(%rbp), %eax
	movl	-188(%rbp), %ecx
	imull	(%r14), %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rax,2), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	leal	(%rax,%rcx,2), %eax
	movl	%eax, -208(%rbp)
	movslq	-208(%rbp), %rax
	movq	(%r9), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	addsd	8(%rcx,%rax,8), %xmm1
	movslq	(%r15), %rdx
	leaq	(%rax,%rdx), %rsi
	addsd	(%rcx,%rsi,8), %xmm1
	leaq	1(%rax,%rdx), %rax
	addsd	(%rcx,%rax,8), %xmm1
	mulsd	%xmm0, %xmm1
	movslq	-204(%rbp), %rax
	movq	(%r12), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-192(%rbp)
.LBB29_8:                               # %for.cond
                                        #   Parent Loop BB29_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-192(%rbp), %eax
	cmpl	(%r13), %eax
	jl	.LBB29_9
	jmp	.LBB29_10
.LBB29_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB29_12:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end29:
	.size	.omp_outlined..19, .Lfunc_end29-.omp_outlined..19
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI30_0:
	.quad	4598175219545276416     # double 0.25
	.text
	.align	16, 0x90
	.type	.omp_outlined..20,@function
.omp_outlined..20:                      # @.omp_outlined..20
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp207:
	.cfi_def_cfa_offset 16
.Ltmp208:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp209:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp210:
	.cfi_offset %rbx, -56
.Ltmp211:
	.cfi_offset %r12, -48
.Ltmp212:
	.cfi_offset %r13, -40
.Ltmp213:
	.cfi_offset %r14, -32
.Ltmp214:
	.cfi_offset %r15, -24
	movq	48(%rbp), %rax
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %r14
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rax, %rdi
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r14, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%rdi, -128(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r13
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %rdi
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -144(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -152(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB30_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB30_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -224(%rbp)        # 8-byte Spill
	movq	%rsi, -216(%rbp)        # 8-byte Spill
	movq	$0, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	$1, -176(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-180(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-168(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-168(%rbp), %rax
	cmpq	-144(%rbp), %rax
	jle	.LBB30_4
# BB#3:                                 # %cond.true
	movq	-144(%rbp), %rax
	jmp	.LBB30_5
.LBB30_4:                               # %cond.false
	movq	-168(%rbp), %rax
.LBB30_5:                               # %cond.end
	movq	48(%rbp), %rdi
	movq	%rdi, %r9
	movq	-216(%rbp), %r8         # 8-byte Reload
	movq	-224(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	movsd	.LCPI30_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB30_6
	.align	16, 0x90
.LBB30_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB30_6 Depth=1
	incq	-136(%rbp)
.LBB30_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB30_8 Depth 2
	movq	-136(%rbp), %rax
	cmpq	-168(%rbp), %rax
	jg	.LBB30_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB30_6 Depth=1
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -188(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB30_8
	.align	16, 0x90
.LBB30_9:                               # %for.inc
                                        #   in Loop: Header=BB30_8 Depth=2
	movl	-188(%rbp), %eax
	imull	(%rbx), %eax
	addl	-192(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%rdi), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movl	-192(%rbp), %eax
	movl	-188(%rbp), %ecx
	imull	(%r14), %ecx
	addl	%ecx, %ecx
	leal	(%rcx,%rax,2), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	leal	(%rax,%rcx,2), %eax
	movl	%eax, -208(%rbp)
	movslq	-208(%rbp), %rax
	movq	(%r9), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	addsd	8(%rcx,%rax,8), %xmm1
	movslq	(%r14), %rdx
	leaq	(%rax,%rdx), %rsi
	addsd	(%rcx,%rsi,8), %xmm1
	leaq	1(%rax,%rdx), %rax
	addsd	(%rcx,%rax,8), %xmm1
	mulsd	%xmm0, %xmm1
	movslq	-204(%rbp), %rax
	movq	(%r12), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-192(%rbp)
.LBB30_8:                               # %for.cond
                                        #   Parent Loop BB30_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-192(%rbp), %eax
	cmpl	(%r13), %eax
	jl	.LBB30_9
	jmp	.LBB30_10
.LBB30_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB30_12:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end30:
	.size	.omp_outlined..20, .Lfunc_end30-.omp_outlined..20
	.cfi_endproc

	.globl	interpolation_constant
	.align	16, 0x90
	.type	interpolation_constant,@function
interpolation_constant:                 # @interpolation_constant
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp215:
	.cfi_def_cfa_offset 16
.Ltmp216:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp217:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
.Ltmp218:
	.cfi_offset %rbx, -56
.Ltmp219:
	.cfi_offset %r12, -48
.Ltmp220:
	.cfi_offset %r13, -40
.Ltmp221:
	.cfi_offset %r14, -32
.Ltmp222:
	.cfi_offset %r15, -24
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movsd	%xmm0, -120(%rbp)       # 8-byte Spill
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -112(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movsd	-120(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movl	%r12d, -68(%rbp)
	movl	%r15d, -72(%rbp)
	movl	-52(%rbp), %eax
	incl	%eax
	movl	%eax, -76(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -88(%rbp)
	movl	$100000, -92(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -96(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-92(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -100(%rbp)
	cmpl	$0, -96(%rbp)
	je	.LBB31_2
# BB#1:                                 # %omp_if.then
	leaq	-64(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-76(%rbp), %r8
	leaq	-52(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..21, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB31_3
.LBB31_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -108(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-108(%rbp), %rdi
	leaq	-112(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-76(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..21
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB31_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-88(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 320(%rdx,%rcx,8)
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end31:
	.size	interpolation_constant, .Lfunc_end31-interpolation_constant
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..21,@function
.omp_outlined..21:                      # @.omp_outlined..21
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp223:
	.cfi_def_cfa_offset 16
.Ltmp224:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp225:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$264, %rsp              # imm = 0x108
.Ltmp226:
	.cfi_offset %rbx, -56
.Ltmp227:
	.cfi_offset %r12, -48
.Ltmp228:
	.cfi_offset %r13, -40
.Ltmp229:
	.cfi_offset %r14, -32
.Ltmp230:
	.cfi_offset %r15, -24
	movq	32(%rbp), %rax
	movq	24(%rbp), %r10
	movq	16(%rbp), %rbx
	movl	$0, -220(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r10, -104(%rbp)
	movq	%rax, -112(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rax
	movq	%rax, -232(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -240(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB32_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -128(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	$1, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-136(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-140(%rbp), %rcx
	leaq	-128(%rbp), %r8
	leaq	-132(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-132(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jle	.LBB32_3
# BB#2:                                 # %cond.true
	movl	-120(%rbp), %eax
	jmp	.LBB32_4
.LBB32_3:                               # %cond.false
	movl	-132(%rbp), %eax
.LBB32_4:                               # %cond.end
	movl	%eax, -132(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -116(%rbp)
	jmp	.LBB32_5
	.align	16, 0x90
.LBB32_7:                               # %omp_if.then
                                        #   in Loop: Header=BB32_5 Depth=1
	leaq	-216(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-180(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$10, %esi
	movl	$.omp_outlined..22, %edx
	xorl	%eax, %eax
	leaq	-196(%rbp), %rcx
	leaq	-192(%rbp), %r8
	leaq	-188(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-116(%rbp)
.LBB32_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jg	.LBB32_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB32_5 Depth=1
	movl	-116(%rbp), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -192(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -196(%rbp)
	movq	-232(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r12), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-176(%rbp), %rdx
	movslq	-180(%rbp), %rsi
	movslq	-184(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	movq	-240(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	movslq	-172(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -216(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB32_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB32_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-216(%rbp), %rax
	movq	%rax, 40(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-220(%rbp), %rsi
	leaq	-196(%rbp), %rdx
	leaq	-192(%rbp), %rcx
	leaq	-188(%rbp), %r8
	leaq	-180(%rbp), %r9
	callq	.omp_outlined..22
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-116(%rbp)
	jmp	.LBB32_5
.LBB32_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB32_10:                              # %omp.precond.end
	addq	$264, %rsp              # imm = 0x108
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end32:
	.size	.omp_outlined..21, .Lfunc_end32-.omp_outlined..21
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..22,@function
.omp_outlined..22:                      # @.omp_outlined..22
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp231:
	.cfi_def_cfa_offset 16
.Ltmp232:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp233:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
.Ltmp234:
	.cfi_offset %rbx, -56
.Ltmp235:
	.cfi_offset %r12, -48
.Ltmp236:
	.cfi_offset %r13, -40
.Ltmp237:
	.cfi_offset %r14, -32
.Ltmp238:
	.cfi_offset %r15, -24
	movq	56(%rbp), %rbx
	movq	48(%rbp), %r10
	movq	40(%rbp), %r11
	movq	32(%rbp), %r14
	movq	24(%rbp), %r15
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rbx, %rdi
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r15, -104(%rbp)
	movq	%r14, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	%r10, -128(%rbp)
	movq	%rdi, -136(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r14
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %r8
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movq	-128(%rbp), %r13
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -152(%rbp)
	movl	$0, -156(%rbp)
	movl	$0, -160(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB33_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB33_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -240(%rbp)        # 8-byte Spill
	movq	%r8, -232(%rbp)         # 8-byte Spill
	movq	%rsi, -224(%rbp)        # 8-byte Spill
	movq	$0, -168(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	$1, -184(%rbp)
	movl	$0, -188(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-184(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-188(%rbp), %rcx
	leaq	-168(%rbp), %r8
	leaq	-176(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-176(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jle	.LBB33_4
# BB#3:                                 # %cond.true
	movq	-152(%rbp), %rax
	jmp	.LBB33_5
.LBB33_4:                               # %cond.false
	movq	-176(%rbp), %rax
.LBB33_5:                               # %cond.end
	movq	56(%rbp), %rdi
	movq	%rdi, %r9
	movq	-224(%rbp), %r8         # 8-byte Reload
	movq	-232(%rbp), %r10        # 8-byte Reload
	movq	-240(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -176(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -144(%rbp)
	jmp	.LBB33_6
	.align	16, 0x90
.LBB33_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB33_6 Depth=1
	incq	-144(%rbp)
.LBB33_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB33_8 Depth 2
	movq	-144(%rbp), %rax
	cmpq	-176(%rbp), %rax
	jg	.LBB33_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB33_6 Depth=1
	movq	-144(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -192(%rbp)
	movq	-144(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -196(%rbp)
	movl	$0, -200(%rbp)
	jmp	.LBB33_8
	.align	16, 0x90
.LBB33_9:                               # %for.inc
                                        #   in Loop: Header=BB33_8 Depth=2
	movl	-196(%rbp), %eax
	imull	(%rbx), %eax
	addl	-200(%rbp), %eax
	movl	-192(%rbp), %ecx
	imull	(%r10), %ecx
	addl	%eax, %ecx
	movl	%ecx, -212(%rbp)
	movl	-200(%rbp), %eax
	sarl	%eax
	movl	-196(%rbp), %ecx
	sarl	%ecx
	imull	(%rdi), %ecx
	addl	%eax, %ecx
	movl	-192(%rbp), %eax
	sarl	%eax
	imull	(%r15), %eax
	addl	%ecx, %eax
	movl	%eax, -216(%rbp)
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	movslq	-212(%rbp), %rax
	movq	(%r12), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movslq	-216(%rbp), %rdx
	movq	(%r9), %rsi
	addsd	(%rsi,%rdx,8), %xmm0
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-200(%rbp)
.LBB33_8:                               # %for.cond
                                        #   Parent Loop BB33_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-200(%rbp), %eax
	cmpl	(%r14), %eax
	jl	.LBB33_9
	jmp	.LBB33_10
.LBB33_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB33_12:                              # %omp.precond.end
	addq	$232, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end33:
	.size	.omp_outlined..22, .Lfunc_end33-.omp_outlined..22
	.cfi_endproc

	.globl	interpolation_linear
	.align	16, 0x90
	.type	interpolation_linear,@function
interpolation_linear:                   # @interpolation_linear
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp239:
	.cfi_def_cfa_offset 16
.Ltmp240:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp241:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
.Ltmp242:
	.cfi_offset %rbx, -56
.Ltmp243:
	.cfi_offset %r12, -48
.Ltmp244:
	.cfi_offset %r13, -40
.Ltmp245:
	.cfi_offset %r14, -32
.Ltmp246:
	.cfi_offset %r15, -24
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movsd	%xmm0, -120(%rbp)       # 8-byte Spill
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -112(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movsd	-120(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movl	%r12d, -68(%rbp)
	movl	%r15d, -72(%rbp)
	movl	-52(%rbp), %esi
	incl	%esi
	movl	%esi, -76(%rbp)
	movq	-48(%rbp), %rdi
	movl	-72(%rbp), %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -88(%rbp)
	movl	$100000, -92(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -96(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-92(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -100(%rbp)
	cmpl	$0, -96(%rbp)
	je	.LBB34_2
# BB#1:                                 # %omp_if.then
	leaq	-64(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-76(%rbp), %r8
	leaq	-52(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..23, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB34_3
.LBB34_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -108(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-108(%rbp), %rdi
	leaq	-112(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-76(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..23
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB34_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-88(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 320(%rdx,%rcx,8)
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end34:
	.size	interpolation_linear, .Lfunc_end34-interpolation_linear
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..23,@function
.omp_outlined..23:                      # @.omp_outlined..23
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp247:
	.cfi_def_cfa_offset 16
.Ltmp248:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp249:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$264, %rsp              # imm = 0x108
.Ltmp250:
	.cfi_offset %rbx, -56
.Ltmp251:
	.cfi_offset %r12, -48
.Ltmp252:
	.cfi_offset %r13, -40
.Ltmp253:
	.cfi_offset %r14, -32
.Ltmp254:
	.cfi_offset %r15, -24
	movq	32(%rbp), %rax
	movq	24(%rbp), %r10
	movq	16(%rbp), %rbx
	movl	$0, -228(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r10, -104(%rbp)
	movq	%rax, -112(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rax
	movq	%rax, -240(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -248(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB35_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -128(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	$1, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-136(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-140(%rbp), %rcx
	leaq	-128(%rbp), %r8
	leaq	-132(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-132(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jle	.LBB35_3
# BB#2:                                 # %cond.true
	movl	-120(%rbp), %eax
	jmp	.LBB35_4
.LBB35_3:                               # %cond.false
	movl	-132(%rbp), %eax
.LBB35_4:                               # %cond.end
	movl	%eax, -132(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -116(%rbp)
	jmp	.LBB35_5
	.align	16, 0x90
.LBB35_7:                               # %omp_if.then
                                        #   in Loop: Header=BB35_5 Depth=1
	leaq	-224(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-216(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-196(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$10, %esi
	movl	$.omp_outlined..24, %edx
	xorl	%eax, %eax
	leaq	-208(%rbp), %rcx
	leaq	-204(%rbp), %r8
	leaq	-200(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-116(%rbp)
.LBB35_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jg	.LBB35_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB35_5 Depth=1
	movl	-116(%rbp), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -192(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -196(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -200(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -204(%rbp)
	movslq	(%r12), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -208(%rbp)
	movq	-240(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r12), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-188(%rbp), %rdx
	movslq	-192(%rbp), %rsi
	movslq	-196(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -216(%rbp)
	movq	-248(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-168(%rbp), %rsi
	movslq	-172(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -224(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB35_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB35_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-224(%rbp), %rax
	movq	%rax, 40(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-216(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-196(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-228(%rbp), %rsi
	leaq	-208(%rbp), %rdx
	leaq	-204(%rbp), %rcx
	leaq	-200(%rbp), %r8
	leaq	-192(%rbp), %r9
	callq	.omp_outlined..24
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-116(%rbp)
	jmp	.LBB35_5
.LBB35_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB35_10:                              # %omp.precond.end
	addq	$264, %rsp              # imm = 0x108
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end35:
	.size	.omp_outlined..23, .Lfunc_end35-.omp_outlined..23
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..24,@function
.omp_outlined..24:                      # @.omp_outlined..24
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp255:
	.cfi_def_cfa_offset 16
.Ltmp256:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp257:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$360, %rsp              # imm = 0x168
.Ltmp258:
	.cfi_offset %rbx, -56
.Ltmp259:
	.cfi_offset %r12, -48
.Ltmp260:
	.cfi_offset %r13, -40
.Ltmp261:
	.cfi_offset %r14, -32
.Ltmp262:
	.cfi_offset %r15, -24
	movq	56(%rbp), %rbx
	movq	48(%rbp), %r10
	movq	40(%rbp), %r11
	movq	32(%rbp), %r14
	movq	24(%rbp), %r15
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r15, -104(%rbp)
	movq	%r14, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	%r10, -128(%rbp)
	movq	%rbx, -136(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rbx
	movq	%rbx, -360(%rbp)        # 8-byte Spill
	movq	-80(%rbp), %rcx
	movq	%rcx, -304(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rcx
	movq	%rcx, -312(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rcx
	movq	%rcx, -320(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rsi
	movq	-112(%rbp), %rdi
	movq	-120(%rbp), %rcx
	movq	%rcx, -328(%rbp)        # 8-byte Spill
	movq	-128(%rbp), %rcx
	movq	%rcx, -336(%rbp)        # 8-byte Spill
	movslq	(%rax), %rcx
	movslq	(%rbx), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -152(%rbp)
	movl	$0, -156(%rbp)
	movl	$0, -160(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB36_18
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rbx)
	jle	.LBB36_18
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -352(%rbp)        # 8-byte Spill
	movq	%rsi, -344(%rbp)        # 8-byte Spill
	movq	$0, -168(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	$1, -184(%rbp)
	movl	$0, -188(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-184(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-188(%rbp), %rcx
	leaq	-168(%rbp), %r8
	leaq	-176(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-176(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jle	.LBB36_4
# BB#3:                                 # %cond.true
	movq	-152(%rbp), %rax
	jmp	.LBB36_5
.LBB36_4:                               # %cond.false
	movq	-176(%rbp), %rax
.LBB36_5:                               # %cond.end
	movq	%rax, -176(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -144(%rbp)
	movabsq	$-4631952216750555136, %r10 # imm = 0xBFB8000000000000
	jmp	.LBB36_6
	.align	16, 0x90
.LBB36_16:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB36_6 Depth=1
	incq	-144(%rbp)
	movq	-360(%rbp), %rbx        # 8-byte Reload
.LBB36_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB36_8 Depth 2
	movq	-144(%rbp), %rax
	cmpq	-176(%rbp), %rax
	jg	.LBB36_17
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB36_6 Depth=1
	movq	-144(%rbp), %rax
	movslq	(%rbx), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -192(%rbp)
	movq	-144(%rbp), %rax
	movslq	(%rbx), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -196(%rbp)
	movl	$0, -200(%rbp)
	jmp	.LBB36_8
	.align	16, 0x90
.LBB36_15:                              # %for.inc
                                        #   in Loop: Header=BB36_8 Depth=2
	movsd	-272(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	-248(%rbp), %xmm8       # xmm8 = mem[0],zero
	movapd	%xmm0, %xmm5
	mulsd	%xmm8, %xmm5
	movsd	-224(%rbp), %xmm13      # xmm13 = mem[0],zero
	movapd	%xmm5, %xmm11
	mulsd	%xmm13, %xmm11
	movslq	-216(%rbp), %rax
	leaq	-1(%rax), %r15
	movslq	(%rdx), %r14
	movq	%r15, %rcx
	subq	%r14, %rcx
	movslq	(%rsi), %rdx
	movq	%rcx, %rsi
	subq	%rdx, %rsi
	movq	56(%rbp), %rdi
	movq	(%rdi), %rbx
	mulsd	(%rbx,%rsi,8), %xmm11
	movsd	-232(%rbp), %xmm14      # xmm14 = mem[0],zero
	movapd	%xmm5, %xmm12
	mulsd	%xmm14, %xmm12
	leaq	1(%rax), %rdi
	movq	%rax, %r12
	movq	%rax, %r9
	subq	%r14, %r9
	movq	%r9, %rsi
	subq	%rdx, %rsi
	mulsd	(%rbx,%rsi,8), %xmm12
	movsd	-240(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm5
	movapd	%xmm1, %xmm15
	movq	%rdi, %r8
	subq	%r14, %r8
	movq	%r8, %rsi
	subq	%rdx, %rsi
	mulsd	(%rbx,%rsi,8), %xmm5
	leaq	-1(%rax,%r14), %r11
	movsd	-256(%rbp), %xmm9       # xmm9 = mem[0],zero
	movapd	%xmm0, %xmm2
	mulsd	%xmm9, %xmm2
	movapd	%xmm2, %xmm3
	mulsd	%xmm13, %xmm3
	subq	%rdx, %r15
	mulsd	(%rbx,%r15,8), %xmm3
	leaq	(%rax,%r14), %r13
	leaq	1(%rax,%r14), %r14
	movq	-336(%rbp), %rsi        # 8-byte Reload
	movsd	(%rsi), %xmm6           # xmm6 = mem[0],zero
	movapd	%xmm2, %xmm7
	mulsd	%xmm14, %xmm7
	subq	%rdx, %r12
	mulsd	(%rbx,%r12,8), %xmm7
	movslq	-212(%rbp), %r12
	mulsd	%xmm15, %xmm2
	subq	%rdx, %rdi
	mulsd	(%rbx,%rdi,8), %xmm2
	movsd	-264(%rbp), %xmm10      # xmm10 = mem[0],zero
	mulsd	%xmm10, %xmm0
	movapd	%xmm0, %xmm4
	mulsd	%xmm13, %xmm4
	movq	%r11, %rsi
	subq	%rdx, %rsi
	mulsd	(%rbx,%rsi,8), %xmm4
	movapd	%xmm0, %xmm1
	mulsd	%xmm14, %xmm1
	movq	%r13, %rsi
	subq	%rdx, %rsi
	mulsd	(%rbx,%rsi,8), %xmm1
	mulsd	%xmm15, %xmm0
	movq	%r14, %rsi
	subq	%rdx, %rsi
	mulsd	(%rbx,%rsi,8), %xmm0
	movq	-328(%rbp), %rsi        # 8-byte Reload
	movq	(%rsi), %r15
	mulsd	(%r15,%r12,8), %xmm6
	addsd	%xmm6, %xmm11
	addsd	%xmm11, %xmm12
	addsd	%xmm12, %xmm5
	addsd	%xmm5, %xmm3
	addsd	%xmm3, %xmm7
	addsd	%xmm7, %xmm2
	addsd	%xmm2, %xmm4
	addsd	%xmm4, %xmm1
	addsd	%xmm1, %xmm0
	movsd	-280(%rbp), %xmm5       # xmm5 = mem[0],zero
	movapd	%xmm5, %xmm6
	mulsd	%xmm8, %xmm6
	movapd	%xmm6, %xmm1
	mulsd	%xmm13, %xmm1
	mulsd	(%rbx,%rcx,8), %xmm1
	addsd	%xmm0, %xmm1
	movapd	%xmm6, %xmm0
	mulsd	%xmm14, %xmm0
	mulsd	(%rbx,%r9,8), %xmm0
	addsd	%xmm1, %xmm0
	mulsd	%xmm15, %xmm6
	mulsd	(%rbx,%r8,8), %xmm6
	addsd	%xmm0, %xmm6
	movapd	%xmm5, %xmm7
	mulsd	%xmm9, %xmm7
	movapd	%xmm7, %xmm0
	mulsd	%xmm13, %xmm0
	movsd	%xmm0, -296(%rbp)       # 8-byte Spill
	movapd	%xmm7, %xmm12
	mulsd	%xmm14, %xmm12
	mulsd	%xmm15, %xmm7
	movapd	%xmm15, %xmm1
	mulsd	%xmm10, %xmm5
	movapd	%xmm5, %xmm15
	mulsd	%xmm13, %xmm15
	movapd	%xmm5, %xmm11
	mulsd	%xmm14, %xmm11
	mulsd	%xmm1, %xmm5
	movapd	%xmm1, %xmm3
	movsd	-288(%rbp), %xmm1       # xmm1 = mem[0],zero
	movapd	%xmm8, %xmm0
	mulsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm2
	mulsd	%xmm13, %xmm2
	movapd	%xmm0, %xmm4
	mulsd	%xmm14, %xmm4
	mulsd	%xmm3, %xmm0
	movapd	%xmm3, %xmm8
	mulsd	%xmm1, %xmm9
	mulsd	%xmm10, %xmm1
	movapd	%xmm9, %xmm10
	mulsd	%xmm13, %xmm10
	movapd	%xmm9, %xmm3
	mulsd	%xmm14, %xmm3
	mulsd	%xmm8, %xmm9
	mulsd	%xmm1, %xmm13
	mulsd	%xmm1, %xmm14
	mulsd	%xmm8, %xmm1
	addq	%rdx, %rcx
	mulsd	(%rbx,%rcx,8), %xmm2
	addq	%rdx, %r9
	mulsd	(%rbx,%r9,8), %xmm4
	addq	%rdx, %r8
	mulsd	(%rbx,%r8,8), %xmm0
	leaq	-1(%rax,%rdx), %rcx
	mulsd	(%rbx,%rcx,8), %xmm10
	leaq	(%rax,%rdx), %rcx
	mulsd	(%rbx,%rcx,8), %xmm3
	movsd	-296(%rbp), %xmm8       # 8-byte Reload
                                        # xmm8 = mem[0],zero
	mulsd	-8(%rbx,%rax,8), %xmm8
	mulsd	(%rbx,%rax,8), %xmm12
	mulsd	8(%rbx,%rax,8), %xmm7
	leaq	1(%rax,%rdx), %rax
	mulsd	(%rbx,%rax,8), %xmm9
	mulsd	(%rbx,%r11,8), %xmm15
	addq	%rdx, %r11
	mulsd	(%rbx,%r11,8), %xmm13
	mulsd	(%rbx,%r13,8), %xmm11
	addq	%rdx, %r13
	mulsd	(%rbx,%r13,8), %xmm14
	mulsd	(%rbx,%r14,8), %xmm5
	addq	%rdx, %r14
	mulsd	(%rbx,%r14,8), %xmm1
	addsd	%xmm6, %xmm8
	addsd	%xmm8, %xmm12
	addsd	%xmm12, %xmm7
	addsd	%xmm7, %xmm15
	addsd	%xmm15, %xmm11
	addsd	%xmm11, %xmm5
	addsd	%xmm5, %xmm2
	addsd	%xmm2, %xmm4
	addsd	%xmm4, %xmm0
	addsd	%xmm0, %xmm10
	addsd	%xmm10, %xmm3
	addsd	%xmm3, %xmm9
	addsd	%xmm9, %xmm13
	addsd	%xmm13, %xmm14
	addsd	%xmm14, %xmm1
	movsd	%xmm1, (%r15,%r12,8)
	incl	-200(%rbp)
.LBB36_8:                               # %for.cond
                                        #   Parent Loop BB36_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-200(%rbp), %eax
	movq	-304(%rbp), %rcx        # 8-byte Reload
	cmpl	(%rcx), %eax
	jge	.LBB36_16
# BB#9:                                 # %for.body
                                        #   in Loop: Header=BB36_8 Depth=2
	movl	-196(%rbp), %eax
	movq	-312(%rbp), %rcx        # 8-byte Reload
	imull	(%rcx), %eax
	addl	-200(%rbp), %eax
	movl	-192(%rbp), %ecx
	movq	-320(%rbp), %rdx        # 8-byte Reload
	imull	(%rdx), %ecx
	addl	%eax, %ecx
	movl	%ecx, -212(%rbp)
	movl	-200(%rbp), %eax
	sarl	%eax
	movl	-196(%rbp), %ecx
	sarl	%ecx
	movq	-344(%rbp), %rdx        # 8-byte Reload
	imull	(%rdx), %ecx
	addl	%eax, %ecx
	movl	-192(%rbp), %eax
	sarl	%eax
	movq	-352(%rbp), %rsi        # 8-byte Reload
	imull	(%rsi), %eax
	addl	%ecx, %eax
	movl	%eax, -216(%rbp)
	movabsq	$4594797519824748544, %rax # imm = 0x3FC4000000000000
	movq	%rax, -224(%rbp)
	movabsq	$4606619468846596096, %rcx # imm = 0x3FEE000000000000
	movq	%rcx, -232(%rbp)
	movq	%r10, -240(%rbp)
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	%r10, -264(%rbp)
	movq	%rax, -272(%rbp)
	movq	%rcx, -280(%rbp)
	movq	%r10, -288(%rbp)
	testb	$1, -200(%rbp)
	je	.LBB36_11
# BB#10:                                # %if.then
                                        #   in Loop: Header=BB36_8 Depth=2
	movq	%r10, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	%rax, -240(%rbp)
.LBB36_11:                              # %if.end
                                        #   in Loop: Header=BB36_8 Depth=2
	testb	$1, -196(%rbp)
	je	.LBB36_13
# BB#12:                                # %if.then52
                                        #   in Loop: Header=BB36_8 Depth=2
	movq	%r10, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	%rax, -264(%rbp)
.LBB36_13:                              # %if.end53
                                        #   in Loop: Header=BB36_8 Depth=2
	testb	$1, -192(%rbp)
	je	.LBB36_15
# BB#14:                                # %if.then56
                                        #   in Loop: Header=BB36_8 Depth=2
	movq	%r10, -272(%rbp)
	movq	%rcx, -280(%rbp)
	movq	%rax, -288(%rbp)
	jmp	.LBB36_15
.LBB36_17:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB36_18:                              # %omp.precond.end
	addq	$360, %rsp              # imm = 0x168
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end36:
	.size	.omp_outlined..24, .Lfunc_end36-.omp_outlined..24
	.cfi_endproc

	.globl	zero_grid
	.align	16, 0x90
	.type	zero_grid,@function
zero_grid:                              # @zero_grid
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp263:
	.cfi_def_cfa_offset 16
.Ltmp264:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp265:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
.Ltmp266:
	.cfi_offset %rbx, -48
.Ltmp267:
	.cfi_offset %r12, -40
.Ltmp268:
	.cfi_offset %r14, -32
.Ltmp269:
	.cfi_offset %r15, -24
	movl	%edx, %r15d
	movl	%esi, %r12d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -80(%rbp)
	movq	%rbx, -40(%rbp)
	movl	%r12d, -44(%rbp)
	movl	%r15d, -48(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	movl	$100000, -60(%rbp)      # imm = 0x186A0
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -64(%rbp)
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-60(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -68(%rbp)
	cmpl	$0, -64(%rbp)
	je	.LBB37_2
# BB#1:                                 # %omp_if.then
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-40(%rbp), %rcx
	leaq	-44(%rbp), %r8
	leaq	-48(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$4, %esi
	movl	$.omp_outlined..25, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB37_3
.LBB37_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -76(%rbp)
	leaq	-76(%rbp), %rdi
	leaq	-80(%rbp), %rsi
	leaq	-40(%rbp), %rdx
	leaq	-44(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..25
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB37_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-56(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-40(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$64, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end37:
	.size	zero_grid, .Lfunc_end37-zero_grid
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..25,@function
.omp_outlined..25:                      # @.omp_outlined..25
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp270:
	.cfi_def_cfa_offset 16
.Ltmp271:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp272:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$168, %rsp
.Ltmp273:
	.cfi_offset %rbx, -56
.Ltmp274:
	.cfi_offset %r12, -48
.Ltmp275:
	.cfi_offset %r13, -40
.Ltmp276:
	.cfi_offset %r14, -32
.Ltmp277:
	.cfi_offset %r15, -24
	movq	%r9, %rbx
	movl	$0, -172(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%rbx, -88(%rbp)
	movq	-64(%rbp), %r15
	movq	-72(%rbp), %r12
	movq	-80(%rbp), %r13
	movq	(%r15), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -96(%rbp)
	movl	$0, -100(%rbp)
	movq	(%r15), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB38_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -104(%rbp)
	movl	-96(%rbp), %eax
	movl	%eax, -108(%rbp)
	movl	$1, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-112(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-116(%rbp), %rcx
	leaq	-104(%rbp), %r8
	leaq	-108(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-108(%rbp), %eax
	cmpl	-96(%rbp), %eax
	jle	.LBB38_3
# BB#2:                                 # %cond.true
	movl	-96(%rbp), %eax
	jmp	.LBB38_4
.LBB38_3:                               # %cond.false
	movl	-108(%rbp), %eax
.LBB38_4:                               # %cond.end
	movl	%eax, -108(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -92(%rbp)
	jmp	.LBB38_5
	.align	16, 0x90
.LBB38_7:                               # %omp_if.then
                                        #   in Loop: Header=BB38_5 Depth=1
	leaq	-168(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-140(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..26, %edx
	xorl	%eax, %eax
	leaq	-148(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-92(%rbp)
.LBB38_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-92(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jg	.LBB38_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB38_5 Depth=1
	movl	-92(%rbp), %eax
	movl	%eax, -120(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -140(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -148(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -152(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r12), %rax
	movslq	-120(%rbp), %rcx
	movq	(%r15), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r13), %rax
	movslq	(%r12), %rcx
	movslq	-120(%rbp), %rdx
	movq	(%r15), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-148(%rbp), %rdx
	movslq	-140(%rbp), %rsi
	movslq	-144(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -168(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB38_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB38_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r14d
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-168(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-144(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-140(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-172(%rbp), %rsi
	leaq	-148(%rbp), %rdx
	leaq	-152(%rbp), %rcx
	leaq	-156(%rbp), %r8
	leaq	-160(%rbp), %r9
	callq	.omp_outlined..26
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-92(%rbp)
	jmp	.LBB38_5
.LBB38_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB38_10:                              # %omp.precond.end
	addq	$168, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end38:
	.size	.omp_outlined..25, .Lfunc_end38-.omp_outlined..25
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..26,@function
.omp_outlined..26:                      # @.omp_outlined..26
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp278:
	.cfi_def_cfa_offset 16
.Ltmp279:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp280:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$184, %rsp
.Ltmp281:
	.cfi_offset %rbx, -56
.Ltmp282:
	.cfi_offset %r12, -48
.Ltmp283:
	.cfi_offset %r13, -40
.Ltmp284:
	.cfi_offset %r14, -32
.Ltmp285:
	.cfi_offset %r15, -24
	movq	32(%rbp), %r14
	movq	24(%rbp), %rax
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%rax, -104(%rbp)
	movq	%r14, -112(%rbp)
	movq	-64(%rbp), %rbx
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r15
	movl	(%rbx), %ecx
	movl	(%rax), %edx
	addl	%ecx, %edx
	movl	%ecx, %esi
	negl	%esi
	subl	%esi, %edx
	movslq	%edx, %rdx
	addl	(%rdi), %ecx
	subl	%esi, %ecx
	movslq	%ecx, %rcx
	imulq	%rdx, %rcx
	decq	%rcx
	movq	%rcx, -128(%rbp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	subl	(%rbx), %edx
	movl	%edx, -132(%rbp)
	subl	(%rbx), %ecx
	movl	%ecx, -136(%rbp)
	movl	(%rbx), %ecx
	movl	%ecx, %edx
	negl	%edx
	addl	(%rax), %ecx
	cmpl	%ecx, %edx
	jge	.LBB39_12
# BB#1:                                 # %land.lhs.true
	movl	(%rbx), %eax
	movl	%eax, %ecx
	negl	%ecx
	addl	(%rdi), %eax
	cmpl	%eax, %ecx
	jge	.LBB39_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -200(%rbp)        # 8-byte Spill
	movq	$0, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	$1, -160(%rbp)
	movl	$0, -164(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-164(%rbp), %rcx
	leaq	-144(%rbp), %r8
	leaq	-152(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-152(%rbp), %rax
	cmpq	-128(%rbp), %rax
	jle	.LBB39_4
# BB#3:                                 # %cond.true
	movq	-128(%rbp), %rax
	jmp	.LBB39_5
.LBB39_4:                               # %cond.false
	movq	-152(%rbp), %rax
.LBB39_5:                               # %cond.end
	movq	-200(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	jmp	.LBB39_6
	.align	16, 0x90
.LBB39_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB39_6 Depth=1
	incq	-120(%rbp)
.LBB39_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB39_8 Depth 2
	movq	-120(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jg	.LBB39_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB39_6 Depth=1
	movl	(%rbx), %ecx
	movq	-120(%rbp), %rax
	movl	(%rdi), %edx
	addl	%ecx, %edx
	movl	%ecx, %esi
	negl	%esi
	subl	%esi, %edx
	movslq	%edx, %rsi
	cqto
	idivq	%rsi
	subl	%ecx, %eax
	movl	%eax, -168(%rbp)
	movl	(%rbx), %ecx
	movq	-120(%rbp), %rax
	movl	(%rdi), %edx
	addl	%ecx, %edx
	movl	%ecx, %esi
	negl	%esi
	subl	%esi, %edx
	movslq	%edx, %rsi
	cqto
	idivq	%rsi
	subl	%ecx, %edx
	movl	%edx, -172(%rbp)
	xorl	%eax, %eax
	subl	(%rbx), %eax
	movl	%eax, -176(%rbp)
	jmp	.LBB39_8
	.align	16, 0x90
.LBB39_9:                               # %for.inc
                                        #   in Loop: Header=BB39_8 Depth=2
	movl	-172(%rbp), %eax
	imull	(%r13), %eax
	addl	-176(%rbp), %eax
	movl	-168(%rbp), %ecx
	imull	(%r15), %ecx
	addl	%eax, %ecx
	movl	%ecx, -188(%rbp)
	movslq	-188(%rbp), %rax
	movq	(%r14), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-176(%rbp)
.LBB39_8:                               # %for.cond
                                        #   Parent Loop BB39_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	(%r12), %eax
	addl	(%rbx), %eax
	cmpl	%eax, -176(%rbp)
	jl	.LBB39_9
	jmp	.LBB39_10
.LBB39_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB39_12:                              # %omp.precond.end
	addq	$184, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end39:
	.size	.omp_outlined..26, .Lfunc_end39-.omp_outlined..26
	.cfi_endproc

	.globl	initialize_grid_to_scalar
	.align	16, 0x90
	.type	initialize_grid_to_scalar,@function
initialize_grid_to_scalar:              # @initialize_grid_to_scalar
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp286:
	.cfi_def_cfa_offset 16
.Ltmp287:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp288:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$80, %rsp
.Ltmp289:
	.cfi_offset %rbx, -48
.Ltmp290:
	.cfi_offset %r12, -40
.Ltmp291:
	.cfi_offset %r14, -32
.Ltmp292:
	.cfi_offset %r15, -24
	movsd	%xmm0, -96(%rbp)        # 8-byte Spill
	movl	%edx, %r15d
	movl	%esi, %r12d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -88(%rbp)
	movq	%rbx, -40(%rbp)
	movl	%r12d, -44(%rbp)
	movl	%r15d, -48(%rbp)
	movsd	-96(%rbp), %xmm0        # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -56(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -64(%rbp)
	movl	$100000, -68(%rbp)      # imm = 0x186A0
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -72(%rbp)
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-68(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -76(%rbp)
	cmpl	$0, -72(%rbp)
	je	.LBB40_2
# BB#1:                                 # %omp_if.then
	leaq	-56(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-76(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-40(%rbp), %rcx
	leaq	-44(%rbp), %r8
	leaq	-48(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$5, %esi
	movl	$.omp_outlined..27, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB40_3
.LBB40_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -84(%rbp)
	leaq	-56(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-84(%rbp), %rdi
	leaq	-88(%rbp), %rsi
	leaq	-40(%rbp), %rdx
	leaq	-44(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-76(%rbp), %r9
	callq	.omp_outlined..27
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB40_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-64(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-40(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$80, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end40:
	.size	initialize_grid_to_scalar, .Lfunc_end40-initialize_grid_to_scalar
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..27,@function
.omp_outlined..27:                      # @.omp_outlined..27
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp293:
	.cfi_def_cfa_offset 16
.Ltmp294:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp295:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$184, %rsp
.Ltmp296:
	.cfi_offset %rbx, -56
.Ltmp297:
	.cfi_offset %r12, -48
.Ltmp298:
	.cfi_offset %r13, -40
.Ltmp299:
	.cfi_offset %r14, -32
.Ltmp300:
	.cfi_offset %r15, -24
	movq	16(%rbp), %rax
	movl	$0, -180(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -104(%rbp)
	movl	$0, -108(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB41_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -112(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -116(%rbp)
	movl	$1, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-120(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-124(%rbp), %rcx
	leaq	-112(%rbp), %r8
	leaq	-116(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-116(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jle	.LBB41_3
# BB#2:                                 # %cond.true
	movl	-104(%rbp), %eax
	jmp	.LBB41_4
.LBB41_3:                               # %cond.false
	movl	-116(%rbp), %eax
.LBB41_4:                               # %cond.end
	movl	%eax, -116(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -100(%rbp)
	jmp	.LBB41_5
	.align	16, 0x90
.LBB41_7:                               # %omp_if.then
                                        #   in Loop: Header=BB41_5 Depth=1
	movq	16(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-152(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..28, %edx
	xorl	%eax, %eax
	leaq	-156(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-164(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-100(%rbp)
.LBB41_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-100(%rbp), %eax
	cmpl	-116(%rbp), %eax
	jg	.LBB41_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB41_5 Depth=1
	movl	-100(%rbp), %eax
	movl	%eax, -128(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -148(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -152(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r12), %rax
	movslq	(%r15), %rcx
	movslq	-128(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-156(%rbp), %rdx
	movslq	-148(%rbp), %rsi
	movslq	-152(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -176(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB41_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB41_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	movq	16(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-152(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-148(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-180(%rbp), %rsi
	leaq	-156(%rbp), %rdx
	leaq	-160(%rbp), %rcx
	leaq	-164(%rbp), %r8
	leaq	-168(%rbp), %r9
	callq	.omp_outlined..28
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-100(%rbp)
	jmp	.LBB41_5
.LBB41_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB41_10:                              # %omp.precond.end
	addq	$184, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end41:
	.size	.omp_outlined..27, .Lfunc_end41-.omp_outlined..27
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..28,@function
.omp_outlined..28:                      # @.omp_outlined..28
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp301:
	.cfi_def_cfa_offset 16
.Ltmp302:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp303:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$200, %rsp
.Ltmp304:
	.cfi_offset %rbx, -56
.Ltmp305:
	.cfi_offset %r12, -48
.Ltmp306:
	.cfi_offset %r13, -40
.Ltmp307:
	.cfi_offset %r14, -32
.Ltmp308:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r11
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	-64(%rbp), %r13
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %r15
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r12
	movl	(%r13), %eax
	movl	(%rsi), %ecx
	addl	%eax, %ecx
	movl	%eax, %edx
	negl	%edx
	subl	%edx, %ecx
	movslq	%ecx, %rcx
	addl	(%rdi), %eax
	subl	%edx, %eax
	cltq
	imulq	%rcx, %rax
	decq	%rax
	movq	%rax, -136(%rbp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	subl	(%r13), %ecx
	movl	%ecx, -140(%rbp)
	subl	(%r13), %eax
	movl	%eax, -144(%rbp)
	movl	(%r13), %eax
	movl	%eax, %ecx
	negl	%ecx
	addl	(%rsi), %eax
	cmpl	%eax, %ecx
	jge	.LBB42_20
# BB#1:                                 # %land.lhs.true
	movl	(%r13), %eax
	movl	%eax, %ecx
	negl	%ecx
	addl	(%rdi), %eax
	cmpl	%eax, %ecx
	jge	.LBB42_20
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -216(%rbp)        # 8-byte Spill
	movq	%rsi, -208(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB42_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB42_5
.LBB42_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB42_5:                               # %cond.end
	movq	40(%rbp), %rdi
	movq	-208(%rbp), %r8         # 8-byte Reload
	movq	-216(%rbp), %r9         # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	jmp	.LBB42_6
	.align	16, 0x90
.LBB42_18:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB42_6 Depth=1
	incq	-128(%rbp)
.LBB42_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB42_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB42_19
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB42_6 Depth=1
	movl	(%r13), %ecx
	movq	-128(%rbp), %rax
	movl	(%r9), %edx
	addl	%ecx, %edx
	movl	%ecx, %esi
	negl	%esi
	subl	%esi, %edx
	movslq	%edx, %rsi
	cqto
	idivq	%rsi
	subl	%ecx, %eax
	movl	%eax, -176(%rbp)
	movl	(%r13), %ecx
	movq	-128(%rbp), %rax
	movl	(%r9), %edx
	addl	%ecx, %edx
	movl	%ecx, %esi
	negl	%esi
	subl	%esi, %edx
	movslq	%edx, %rsi
	cqto
	idivq	%rsi
	subl	%ecx, %edx
	movl	%edx, -180(%rbp)
	xorl	%eax, %eax
	subl	(%r13), %eax
	movl	%eax, -184(%rbp)
	jmp	.LBB42_8
	.align	16, 0x90
.LBB42_17:                              # %for.inc
                                        #   in Loop: Header=BB42_8 Depth=2
	movslq	-196(%rbp), %rax
	movq	(%r12), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-184(%rbp)
.LBB42_8:                               # %for.cond
                                        #   Parent Loop BB42_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	(%rbx), %eax
	addl	(%r13), %eax
	cmpl	%eax, -184(%rbp)
	jge	.LBB42_18
# BB#9:                                 # %for.body
                                        #   in Loop: Header=BB42_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r15), %eax
	addl	-184(%rbp), %eax
	movl	-176(%rbp), %ecx
	imull	(%r14), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movb	$1, %al
	cmpl	$0, -184(%rbp)
	js	.LBB42_15
# BB#10:                                # %lor.lhs.false
                                        #   in Loop: Header=BB42_8 Depth=2
	cmpl	$0, -180(%rbp)
	js	.LBB42_15
# BB#11:                                # %lor.lhs.false68
                                        #   in Loop: Header=BB42_8 Depth=2
	cmpl	$0, -176(%rbp)
	js	.LBB42_15
# BB#12:                                # %lor.lhs.false71
                                        #   in Loop: Header=BB42_8 Depth=2
	movl	-184(%rbp), %ecx
	cmpl	(%rbx), %ecx
	jge	.LBB42_15
# BB#13:                                # %lor.lhs.false74
                                        #   in Loop: Header=BB42_8 Depth=2
	movl	-180(%rbp), %ecx
	cmpl	(%r9), %ecx
	jge	.LBB42_15
# BB#14:                                # %lor.rhs
                                        #   in Loop: Header=BB42_8 Depth=2
	movl	-176(%rbp), %eax
	cmpl	(%r8), %eax
	setge	%al
	.align	16, 0x90
.LBB42_15:                              # %lor.end
                                        #   in Loop: Header=BB42_8 Depth=2
	movzbl	%al, %eax
	movl	%eax, -200(%rbp)
	xorpd	%xmm0, %xmm0
	testb	%al, %al
	jne	.LBB42_17
# BB#16:                                # %cond.false80
                                        #   in Loop: Header=BB42_8 Depth=2
	movsd	(%rdi), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB42_17
.LBB42_19:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB42_20:                              # %omp.precond.end
	addq	$200, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end42:
	.size	.omp_outlined..28, .Lfunc_end42-.omp_outlined..28
	.cfi_endproc

	.globl	add_grids
	.align	16, 0x90
	.type	add_grids,@function
add_grids:                              # @add_grids
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp309:
	.cfi_def_cfa_offset 16
.Ltmp310:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp311:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$152, %rsp
.Ltmp312:
	.cfi_offset %rbx, -56
.Ltmp313:
	.cfi_offset %r12, -48
.Ltmp314:
	.cfi_offset %r13, -40
.Ltmp315:
	.cfi_offset %r14, -32
.Ltmp316:
	.cfi_offset %r15, -24
	movl	%r8d, %r15d
	movsd	%xmm1, -128(%rbp)       # 8-byte Spill
	movl	%ecx, %r12d
	movsd	%xmm0, -136(%rbp)       # 8-byte Spill
	movl	%edx, %r13d
	movl	%esi, %ebx
	movq	%rdi, %r14
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -140(%rbp)        # 4-byte Spill
	movl	$0, -120(%rbp)
	movq	%r14, -48(%rbp)
	movl	%ebx, -52(%rbp)
	movl	%r13d, -56(%rbp)
	movsd	-136(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movl	%r12d, -68(%rbp)
	movsd	-128(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -80(%rbp)
	movl	%r15d, -84(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -96(%rbp)
	movl	$100000, -100(%rbp)     # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -104(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-100(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -108(%rbp)
	cmpl	$0, -104(%rbp)
	je	.LBB43_2
# BB#1:                                 # %omp_if.then
	leaq	-80(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-64(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-108(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-84(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..29, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB43_3
.LBB43_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-140(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -116(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-108(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-84(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-116(%rbp), %rdi
	leaq	-120(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..29
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB43_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-96(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$152, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end43:
	.size	add_grids, .Lfunc_end43-add_grids
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..29,@function
.omp_outlined..29:                      # @.omp_outlined..29
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp317:
	.cfi_def_cfa_offset 16
.Ltmp318:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp319:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$264, %rsp              # imm = 0x108
.Ltmp320:
	.cfi_offset %rbx, -56
.Ltmp321:
	.cfi_offset %r12, -48
.Ltmp322:
	.cfi_offset %r13, -40
.Ltmp323:
	.cfi_offset %r14, -32
.Ltmp324:
	.cfi_offset %r15, -24
	movq	40(%rbp), %rbx
	movq	32(%rbp), %r10
	movq	24(%rbp), %r11
	movq	16(%rbp), %rax
	movl	$0, -220(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r11, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%rbx, -120(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -232(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rax
	movq	%rax, -240(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -248(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rbx
	movq	-112(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB44_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -136(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -140(%rbp)
	movl	$1, -144(%rbp)
	movl	$0, -148(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-144(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-148(%rbp), %rcx
	leaq	-136(%rbp), %r8
	leaq	-140(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-140(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jle	.LBB44_3
# BB#2:                                 # %cond.true
	movl	-128(%rbp), %eax
	jmp	.LBB44_4
.LBB44_3:                               # %cond.false
	movl	-140(%rbp), %eax
.LBB44_4:                               # %cond.end
	movl	%eax, -140(%rbp)
	movl	-136(%rbp), %eax
	movl	%eax, -124(%rbp)
	jmp	.LBB44_5
	.align	16, 0x90
.LBB44_7:                               # %omp_if.then
                                        #   in Loop: Header=BB44_5 Depth=1
	leaq	-216(%rbp), %rax
	movq	%rax, 48(%rsp)
	movq	40(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	movq	%r12, 24(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-172(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$10, %esi
	movl	$.omp_outlined..30, %edx
	xorl	%eax, %eax
	leaq	-184(%rbp), %rcx
	leaq	-188(%rbp), %r8
	leaq	-192(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-124(%rbp)
.LBB44_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-124(%rbp), %eax
	cmpl	-140(%rbp), %eax
	jg	.LBB44_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB44_5 Depth=1
	movl	-124(%rbp), %eax
	movl	%eax, -152(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -188(%rbp)
	movslq	(%r15), %rax
	movslq	-152(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -192(%rbp)
	movq	-232(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -200(%rbp)
	movq	-240(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	movq	-248(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-152(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-180(%rbp), %rdx
	movslq	-172(%rbp), %rsi
	movslq	-176(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -216(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB44_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB44_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-216(%rbp), %rax
	movq	%rax, 40(%rsp)
	movq	40(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	%r12, 16(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-220(%rbp), %rsi
	leaq	-184(%rbp), %rdx
	leaq	-188(%rbp), %rcx
	leaq	-192(%rbp), %r8
	leaq	-172(%rbp), %r9
	callq	.omp_outlined..30
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-124(%rbp)
	jmp	.LBB44_5
.LBB44_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB44_10:                              # %omp.precond.end
	addq	$264, %rsp              # imm = 0x108
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end44:
	.size	.omp_outlined..29, .Lfunc_end44-.omp_outlined..29
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..30,@function
.omp_outlined..30:                      # @.omp_outlined..30
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp325:
	.cfi_def_cfa_offset 16
.Ltmp326:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp327:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
.Ltmp328:
	.cfi_offset %rbx, -56
.Ltmp329:
	.cfi_offset %r12, -48
.Ltmp330:
	.cfi_offset %r13, -40
.Ltmp331:
	.cfi_offset %r14, -32
.Ltmp332:
	.cfi_offset %r15, -24
	movq	56(%rbp), %rbx
	movq	48(%rbp), %r10
	movq	40(%rbp), %r11
	movq	32(%rbp), %r14
	movq	24(%rbp), %r15
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rbx, %rsi
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r15, -104(%rbp)
	movq	%r14, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	%r10, -128(%rbp)
	movq	%rsi, -136(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %r14
	movq	-88(%rbp), %r8
	movq	-96(%rbp), %rbx
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movq	-128(%rbp), %r13
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -152(%rbp)
	movl	$0, -156(%rbp)
	movl	$0, -160(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB45_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB45_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -240(%rbp)        # 8-byte Spill
	movq	%r8, -232(%rbp)         # 8-byte Spill
	movq	%rsi, -224(%rbp)        # 8-byte Spill
	movq	$0, -168(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	$1, -184(%rbp)
	movl	$0, -188(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-184(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-188(%rbp), %rcx
	leaq	-168(%rbp), %r8
	leaq	-176(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-176(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jle	.LBB45_4
# BB#3:                                 # %cond.true
	movq	-152(%rbp), %rax
	jmp	.LBB45_5
.LBB45_4:                               # %cond.false
	movq	-176(%rbp), %rax
.LBB45_5:                               # %cond.end
	movq	56(%rbp), %rsi
	movq	%rsi, %r9
	movq	-224(%rbp), %r8         # 8-byte Reload
	movq	-232(%rbp), %rdi        # 8-byte Reload
	movq	-240(%rbp), %rsi        # 8-byte Reload
	movq	%rax, -176(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -144(%rbp)
	jmp	.LBB45_6
	.align	16, 0x90
.LBB45_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB45_6 Depth=1
	incq	-144(%rbp)
.LBB45_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB45_8 Depth 2
	movq	-144(%rbp), %rax
	cmpq	-176(%rbp), %rax
	jg	.LBB45_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB45_6 Depth=1
	movq	-144(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -192(%rbp)
	movq	-144(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -196(%rbp)
	movl	$0, -200(%rbp)
	jmp	.LBB45_8
	.align	16, 0x90
.LBB45_9:                               # %for.inc
                                        #   in Loop: Header=BB45_8 Depth=2
	movl	-196(%rbp), %eax
	imull	(%rdi), %eax
	addl	-200(%rbp), %eax
	movl	-192(%rbp), %ecx
	imull	(%rbx), %ecx
	addl	%eax, %ecx
	movl	%ecx, -212(%rbp)
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	movslq	-212(%rbp), %rax
	movq	(%r12), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movsd	(%r13), %xmm1           # xmm1 = mem[0],zero
	movq	(%r9), %rcx
	mulsd	(%rcx,%rax,8), %xmm1
	addsd	%xmm0, %xmm1
	movq	(%rsi), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-200(%rbp)
.LBB45_8:                               # %for.cond
                                        #   Parent Loop BB45_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-200(%rbp), %eax
	cmpl	(%r14), %eax
	jl	.LBB45_9
	jmp	.LBB45_10
.LBB45_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB45_12:                              # %omp.precond.end
	addq	$232, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end45:
	.size	.omp_outlined..30, .Lfunc_end45-.omp_outlined..30
	.cfi_endproc

	.globl	mul_grids
	.align	16, 0x90
	.type	mul_grids,@function
mul_grids:                              # @mul_grids
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp333:
	.cfi_def_cfa_offset 16
.Ltmp334:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp335:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
.Ltmp336:
	.cfi_offset %rbx, -56
.Ltmp337:
	.cfi_offset %r12, -48
.Ltmp338:
	.cfi_offset %r13, -40
.Ltmp339:
	.cfi_offset %r14, -32
.Ltmp340:
	.cfi_offset %r15, -24
	movl	%r8d, %r15d
	movl	%ecx, %r12d
	movsd	%xmm0, -112(%rbp)       # 8-byte Spill
	movl	%edx, %r13d
	movl	%esi, %ebx
	movq	%rdi, %r14
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -116(%rbp)        # 4-byte Spill
	movl	$0, -104(%rbp)
	movq	%r14, -48(%rbp)
	movl	%ebx, -52(%rbp)
	movl	%r13d, -56(%rbp)
	movsd	-112(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movl	%r12d, -68(%rbp)
	movl	%r15d, -72(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -80(%rbp)
	movl	$100000, -84(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -88(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-84(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -92(%rbp)
	cmpl	$0, -88(%rbp)
	je	.LBB46_2
# BB#1:                                 # %omp_if.then
	leaq	-64(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..31, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB46_3
.LBB46_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-116(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -100(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-100(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..31
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB46_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-80(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end46:
	.size	mul_grids, .Lfunc_end46-mul_grids
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..31,@function
.omp_outlined..31:                      # @.omp_outlined..31
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp341:
	.cfi_def_cfa_offset 16
.Ltmp342:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp343:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$248, %rsp
.Ltmp344:
	.cfi_offset %rbx, -56
.Ltmp345:
	.cfi_offset %r12, -48
.Ltmp346:
	.cfi_offset %r13, -40
.Ltmp347:
	.cfi_offset %r14, -32
.Ltmp348:
	.cfi_offset %r15, -24
	movq	32(%rbp), %rax
	movq	24(%rbp), %r10
	movq	16(%rbp), %rbx
	movl	$0, -212(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r10, -104(%rbp)
	movq	%rax, -112(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -224(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rax
	movq	%rax, -232(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %r12
	movq	-104(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB47_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -128(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	$1, -136(%rbp)
	movl	$0, -140(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-136(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-140(%rbp), %rcx
	leaq	-128(%rbp), %r8
	leaq	-132(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-132(%rbp), %eax
	cmpl	-120(%rbp), %eax
	jle	.LBB47_3
# BB#2:                                 # %cond.true
	movl	-120(%rbp), %eax
	jmp	.LBB47_4
.LBB47_3:                               # %cond.false
	movl	-132(%rbp), %eax
.LBB47_4:                               # %cond.end
	movl	%eax, -132(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -116(%rbp)
	jmp	.LBB47_5
	.align	16, 0x90
.LBB47_7:                               # %omp_if.then
                                        #   in Loop: Header=BB47_5 Depth=1
	leaq	-208(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 32(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-164(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	movl	$.omp_outlined..32, %edx
	xorl	%eax, %eax
	leaq	-176(%rbp), %rcx
	leaq	-180(%rbp), %r8
	leaq	-184(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-116(%rbp)
.LBB47_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jg	.LBB47_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB47_5 Depth=1
	movl	-116(%rbp), %eax
	movl	%eax, -144(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-144(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movq	-224(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-164(%rbp), %rsi
	movslq	-168(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -192(%rbp)
	movq	-232(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-164(%rbp), %rsi
	movslq	-168(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -200(%rbp)
	movslq	(%r12), %rax
	movslq	(%r15), %rcx
	movslq	-144(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-164(%rbp), %rsi
	movslq	-168(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -208(%rbp)
	cmpl	$0, (%rbx)
	jne	.LBB47_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB47_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-208(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-200(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	32(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-212(%rbp), %rsi
	leaq	-176(%rbp), %rdx
	leaq	-180(%rbp), %rcx
	leaq	-184(%rbp), %r8
	leaq	-164(%rbp), %r9
	callq	.omp_outlined..32
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-116(%rbp)
	jmp	.LBB47_5
.LBB47_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB47_10:                              # %omp.precond.end
	addq	$248, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end47:
	.size	.omp_outlined..31, .Lfunc_end47-.omp_outlined..31
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..32,@function
.omp_outlined..32:                      # @.omp_outlined..32
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp349:
	.cfi_def_cfa_offset 16
.Ltmp350:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp351:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp352:
	.cfi_offset %rbx, -56
.Ltmp353:
	.cfi_offset %r12, -48
.Ltmp354:
	.cfi_offset %r13, -40
.Ltmp355:
	.cfi_offset %r14, -32
.Ltmp356:
	.cfi_offset %r15, -24
	movq	48(%rbp), %rax
	movq	40(%rbp), %r10
	movq	32(%rbp), %r11
	movq	24(%rbp), %r14
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rax, %rsi
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r14, -104(%rbp)
	movq	%r11, -112(%rbp)
	movq	%r10, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %rdi
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movq	-120(%rbp), %r12
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -144(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -152(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB48_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB48_12
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -224(%rbp)        # 8-byte Spill
	movq	%rsi, -216(%rbp)        # 8-byte Spill
	movq	$0, -160(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -168(%rbp)
	movq	$1, -176(%rbp)
	movl	$0, -180(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-176(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-180(%rbp), %rcx
	leaq	-160(%rbp), %r8
	leaq	-168(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-168(%rbp), %rax
	cmpq	-144(%rbp), %rax
	jle	.LBB48_4
# BB#3:                                 # %cond.true
	movq	-144(%rbp), %rax
	jmp	.LBB48_5
.LBB48_4:                               # %cond.false
	movq	-168(%rbp), %rax
.LBB48_5:                               # %cond.end
	movq	48(%rbp), %rsi
	movq	-216(%rbp), %r8         # 8-byte Reload
	movq	-224(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -136(%rbp)
	jmp	.LBB48_6
	.align	16, 0x90
.LBB48_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB48_6 Depth=1
	incq	-136(%rbp)
.LBB48_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB48_8 Depth 2
	movq	-136(%rbp), %rax
	cmpq	-168(%rbp), %rax
	jg	.LBB48_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB48_6 Depth=1
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-136(%rbp), %rax
	movslq	(%r8), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -188(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB48_8
	.align	16, 0x90
.LBB48_9:                               # %for.inc
                                        #   in Loop: Header=BB48_8 Depth=2
	movl	-188(%rbp), %eax
	imull	(%rdi), %eax
	addl	-192(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	movslq	-204(%rbp), %rax
	movq	(%r12), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movq	(%rsi), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movq	(%r14), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-192(%rbp)
.LBB48_8:                               # %for.cond
                                        #   Parent Loop BB48_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-192(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB48_9
	jmp	.LBB48_10
.LBB48_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB48_12:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end48:
	.size	.omp_outlined..32, .Lfunc_end48-.omp_outlined..32
	.cfi_endproc

	.globl	scale_grid
	.align	16, 0x90
	.type	scale_grid,@function
scale_grid:                             # @scale_grid
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp357:
	.cfi_def_cfa_offset 16
.Ltmp358:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp359:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
.Ltmp360:
	.cfi_offset %rbx, -56
.Ltmp361:
	.cfi_offset %r12, -48
.Ltmp362:
	.cfi_offset %r13, -40
.Ltmp363:
	.cfi_offset %r14, -32
.Ltmp364:
	.cfi_offset %r15, -24
	movl	%ecx, %r15d
	movsd	%xmm0, -112(%rbp)       # 8-byte Spill
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -104(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movsd	-112(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -64(%rbp)
	movl	%r15d, -68(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -80(%rbp)
	movl	$100000, -84(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -88(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-84(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -92(%rbp)
	cmpl	$0, -88(%rbp)
	je	.LBB49_2
# BB#1:                                 # %omp_if.then
	leaq	-64(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..33, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB49_3
.LBB49_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -100(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-100(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..33
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB49_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-80(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$104, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end49:
	.size	scale_grid, .Lfunc_end49-scale_grid
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..33,@function
.omp_outlined..33:                      # @.omp_outlined..33
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp365:
	.cfi_def_cfa_offset 16
.Ltmp366:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp367:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp368:
	.cfi_offset %rbx, -56
.Ltmp369:
	.cfi_offset %r12, -48
.Ltmp370:
	.cfi_offset %r13, -40
.Ltmp371:
	.cfi_offset %r14, -32
.Ltmp372:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -196(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -208(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB50_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB50_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB50_4
.LBB50_3:                               # %cond.false
	movl	-124(%rbp), %eax
.LBB50_4:                               # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB50_5
	.align	16, 0x90
.LBB50_7:                               # %omp_if.then
                                        #   in Loop: Header=BB50_5 Depth=1
	leaq	-192(%rbp), %rax
	movq	%rax, 32(%rsp)
	movq	24(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-156(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..34, %edx
	xorl	%eax, %eax
	leaq	-168(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-108(%rbp)
.LBB50_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB50_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB50_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movq	-208(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -184(%rbp)
	movslq	(%rbx), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -192(%rbp)
	cmpl	$0, (%r12)
	jne	.LBB50_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB50_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	movq	24(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-196(%rbp), %rsi
	leaq	-168(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	.omp_outlined..34
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-108(%rbp)
	jmp	.LBB50_5
.LBB50_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB50_10:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end50:
	.size	.omp_outlined..33, .Lfunc_end50-.omp_outlined..33
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..34,@function
.omp_outlined..34:                      # @.omp_outlined..34
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp373:
	.cfi_def_cfa_offset 16
.Ltmp374:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp375:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$200, %rsp
.Ltmp376:
	.cfi_offset %rbx, -56
.Ltmp377:
	.cfi_offset %r12, -48
.Ltmp378:
	.cfi_offset %r13, -40
.Ltmp379:
	.cfi_offset %r14, -32
.Ltmp380:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r11
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB51_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB51_12
# BB#2:                                 # %omp.precond.then
	movq	%rsi, -208(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB51_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB51_5
.LBB51_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB51_5:                               # %cond.end
	movq	40(%rbp), %rsi
	movq	-208(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	jmp	.LBB51_6
	.align	16, 0x90
.LBB51_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB51_6 Depth=1
	incq	-128(%rbp)
.LBB51_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB51_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB51_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB51_6 Depth=1
	movq	-128(%rbp), %rax
	movslq	(%rdi), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -176(%rbp)
	movq	-128(%rbp), %rax
	movslq	(%rdi), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	movl	$0, -184(%rbp)
	jmp	.LBB51_8
	.align	16, 0x90
.LBB51_9:                               # %for.inc
                                        #   in Loop: Header=BB51_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r12), %eax
	addl	-184(%rbp), %eax
	movl	-176(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	movslq	-196(%rbp), %rax
	movq	(%rsi), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	movq	(%r14), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-184(%rbp)
.LBB51_8:                               # %for.cond
                                        #   Parent Loop BB51_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-184(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB51_9
	jmp	.LBB51_10
.LBB51_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB51_12:                              # %omp.precond.end
	addq	$200, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end51:
	.size	.omp_outlined..34, .Lfunc_end51-.omp_outlined..34
	.cfi_endproc

	.globl	dot
	.align	16, 0x90
	.type	dot,@function
dot:                                    # @dot
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp381:
	.cfi_def_cfa_offset 16
.Ltmp382:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp383:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
.Ltmp384:
	.cfi_offset %rbx, -56
.Ltmp385:
	.cfi_offset %r12, -48
.Ltmp386:
	.cfi_offset %r13, -40
.Ltmp387:
	.cfi_offset %r14, -32
.Ltmp388:
	.cfi_offset %r15, -24
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -104(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movl	%r15d, -60(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -72(%rbp)
	movl	$100000, -76(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -80(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-76(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -84(%rbp)
	movq	$0, -96(%rbp)
	cmpl	$0, -80(%rbp)
	je	.LBB52_2
# BB#1:                                 # %omp_if.then
	leaq	-96(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-84(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..35, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB52_3
.LBB52_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -100(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-84(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-100(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-60(%rbp), %r9
	callq	.omp_outlined..35
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB52_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-72(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	movsd	-96(%rbp), %xmm0        # xmm0 = mem[0],zero
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end52:
	.size	dot, .Lfunc_end52-dot
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..35,@function
.omp_outlined..35:                      # @.omp_outlined..35
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp389:
	.cfi_def_cfa_offset 16
.Ltmp390:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp391:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$248, %rsp
.Ltmp392:
	.cfi_offset %rbx, -56
.Ltmp393:
	.cfi_offset %r12, -48
.Ltmp394:
	.cfi_offset %r13, -40
.Ltmp395:
	.cfi_offset %r14, -32
.Ltmp396:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -212(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB53_15
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	$0, -144(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB53_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB53_4
.LBB53_3:                               # %cond.false
	movl	-124(%rbp), %eax
.LBB53_4:                               # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB53_5
	.align	16, 0x90
.LBB53_9:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB53_5 Depth=1
	movsd	-144(%rbp), %xmm0       # xmm0 = mem[0],zero
	addsd	-208(%rbp), %xmm0
	movsd	%xmm0, -144(%rbp)
	incl	-108(%rbp)
.LBB53_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB53_10
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB53_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -180(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -184(%rbp)
	movslq	(%rbx), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-164(%rbp), %rsi
	movslq	-168(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -192(%rbp)
	movslq	(%r13), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-172(%rbp), %rdx
	movslq	-164(%rbp), %rsi
	movslq	-168(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -200(%rbp)
	movq	$0, -208(%rbp)
	cmpl	$0, (%r12)
	je	.LBB53_8
# BB#7:                                 # %omp_if.then
                                        #   in Loop: Header=BB53_5 Depth=1
	leaq	-200(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-164(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..36, %edx
	xorl	%eax, %eax
	leaq	-176(%rbp), %rcx
	leaq	-180(%rbp), %r8
	leaq	-184(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB53_9
	.align	16, 0x90
.LBB53_8:                               # %omp_if.else
                                        #   in Loop: Header=BB53_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	%esi, -244(%rbp)        # 4-byte Spill
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-200(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-208(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-212(%rbp), %rsi
	leaq	-176(%rbp), %rdx
	leaq	-180(%rbp), %rcx
	leaq	-184(%rbp), %r8
	leaq	-164(%rbp), %r9
	callq	.omp_outlined..36
	movl	$.L__unnamed_1, %edi
	movl	-244(%rbp), %esi        # 4-byte Reload
	callq	__kmpc_end_serialized_parallel
	jmp	.LBB53_9
.LBB53_10:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-144(%rbp), %rax
	movq	%rax, -224(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-224(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.38, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB53_13
# BB#11:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	24(%rbp), %rax
	jne	.LBB53_15
# BB#12:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	-144(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB53_15
.LBB53_13:                              # %.omp.reduction.case2
	movq	24(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB53_14:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -240(%rbp)
	addsd	-144(%rbp), %xmm0
	movsd	%xmm0, -232(%rbp)
	movq	-232(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB53_14
.LBB53_15:                              # %omp.precond.end
	addq	$248, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end53:
	.size	.omp_outlined..35, .Lfunc_end53-.omp_outlined..35
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..36,@function
.omp_outlined..36:                      # @.omp_outlined..36
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp397:
	.cfi_def_cfa_offset 16
.Ltmp398:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp399:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
.Ltmp400:
	.cfi_offset %rbx, -56
.Ltmp401:
	.cfi_offset %r12, -48
.Ltmp402:
	.cfi_offset %r13, -40
.Ltmp403:
	.cfi_offset %r14, -32
.Ltmp404:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r12
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r12, -120(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r15
	movq	-104(%rbp), %rsi
	movq	-112(%rbp), %r14
	movslq	(%rax), %rcx
	movslq	(%rdi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB54_16
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rdi)
	jle	.LBB54_16
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -248(%rbp)        # 8-byte Spill
	movq	%rsi, -240(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	$0, -192(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB54_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB54_5
.LBB54_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB54_5:                               # %cond.end
	movq	-248(%rbp), %rsi        # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	jmp	.LBB54_6
	.align	16, 0x90
.LBB54_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB54_6 Depth=1
	incq	-128(%rbp)
.LBB54_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB54_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB54_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB54_6 Depth=1
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	movl	$0, -176(%rbp)
	jmp	.LBB54_8
	.align	16, 0x90
.LBB54_9:                               # %for.inc
                                        #   in Loop: Header=BB54_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r13), %eax
	addl	-176(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movslq	-204(%rbp), %rax
	movq	(%r14), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movq	(%r12), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, -192(%rbp)
	incl	-176(%rbp)
.LBB54_8:                               # %for.cond
                                        #   Parent Loop BB54_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-176(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB54_9
	jmp	.LBB54_10
.LBB54_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-192(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %r14d
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-216(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.37, %r9d
	movl	%r14d, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB54_14
# BB#12:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	-240(%rbp), %rax        # 8-byte Reload
	jne	.LBB54_16
# BB#13:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%r14d, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB54_16
.LBB54_14:                              # %.omp.reduction.case2
	movq	-240(%rbp), %rdx        # 8-byte Reload
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB54_15:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -232(%rbp)
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, -224(%rbp)
	movq	-224(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB54_15
.LBB54_16:                              # %omp.precond.end
	addq	$232, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end54:
	.size	.omp_outlined..36, .Lfunc_end54-.omp_outlined..36
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.37,@function
.omp.reduction.reduction_func.37:       # @.omp.reduction.reduction_func.37
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp405:
	.cfi_def_cfa_offset 16
.Ltmp406:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp407:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end55:
	.size	.omp.reduction.reduction_func.37, .Lfunc_end55-.omp.reduction.reduction_func.37
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.38,@function
.omp.reduction.reduction_func.38:       # @.omp.reduction.reduction_func.38
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp408:
	.cfi_def_cfa_offset 16
.Ltmp409:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp410:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end56:
	.size	.omp.reduction.reduction_func.38, .Lfunc_end56-.omp.reduction.reduction_func.38
	.cfi_endproc

	.globl	norm
	.align	16, 0x90
	.type	norm,@function
norm:                                   # @norm
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp411:
	.cfi_def_cfa_offset 16
.Ltmp412:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp413:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$80, %rsp
.Ltmp414:
	.cfi_offset %rbx, -48
.Ltmp415:
	.cfi_offset %r12, -40
.Ltmp416:
	.cfi_offset %r14, -32
.Ltmp417:
	.cfi_offset %r15, -24
	movl	%edx, %r15d
	movl	%esi, %r12d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -88(%rbp)
	movq	%rbx, -40(%rbp)
	movl	%r12d, -44(%rbp)
	movl	%r15d, -48(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	movl	$100000, -60(%rbp)      # imm = 0x186A0
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -64(%rbp)
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-60(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -68(%rbp)
	movq	$0, -80(%rbp)
	cmpl	$0, -64(%rbp)
	je	.LBB57_2
# BB#1:                                 # %omp_if.then
	leaq	-80(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-40(%rbp), %rcx
	leaq	-44(%rbp), %r8
	leaq	-48(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$5, %esi
	movl	$.omp_outlined..39, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB57_3
.LBB57_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -84(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-84(%rbp), %rdi
	leaq	-88(%rbp), %rsi
	leaq	-40(%rbp), %rdx
	leaq	-44(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..39
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB57_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-56(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-40(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	movsd	-80(%rbp), %xmm0        # xmm0 = mem[0],zero
	addq	$80, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end57:
	.size	norm, .Lfunc_end57-norm
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..39,@function
.omp_outlined..39:                      # @.omp_outlined..39
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp418:
	.cfi_def_cfa_offset 16
.Ltmp419:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp420:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp421:
	.cfi_offset %rbx, -56
.Ltmp422:
	.cfi_offset %r12, -48
.Ltmp423:
	.cfi_offset %r13, -40
.Ltmp424:
	.cfi_offset %r14, -32
.Ltmp425:
	.cfi_offset %r15, -24
	movq	16(%rbp), %rax
	movl	$0, -196(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -104(%rbp)
	movl	$0, -108(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB58_23
# BB#1:                                 # %omp.precond.then
	movl	$0, -112(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -116(%rbp)
	movl	$1, -120(%rbp)
	movl	$0, -124(%rbp)
	movabsq	$-4503599627370497, %rax # imm = 0xFFEFFFFFFFFFFFFF
	movq	%rax, -136(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-120(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-124(%rbp), %rcx
	leaq	-112(%rbp), %r8
	leaq	-116(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-116(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jle	.LBB58_3
# BB#2:                                 # %cond.true
	movl	-104(%rbp), %eax
	jmp	.LBB58_4
.LBB58_3:                               # %cond.false
	movl	-116(%rbp), %eax
.LBB58_4:                               # %cond.end
	movl	%eax, -116(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -100(%rbp)
	jmp	.LBB58_5
	.align	16, 0x90
.LBB58_11:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB58_5 Depth=1
	incl	-100(%rbp)
.LBB58_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-100(%rbp), %eax
	cmpl	-116(%rbp), %eax
	jg	.LBB58_12
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB58_5 Depth=1
	movl	-100(%rbp), %eax
	movl	%eax, -128(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r12), %rax
	movslq	(%r15), %rcx
	movslq	-128(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -184(%rbp)
	movq	$0, -192(%rbp)
	cmpl	$0, (%rbx)
	je	.LBB58_8
# BB#7:                                 # %omp_if.then
                                        #   in Loop: Header=BB58_5 Depth=1
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-156(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..40, %edx
	xorl	%eax, %eax
	leaq	-168(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB58_9
	.align	16, 0x90
.LBB58_8:                               # %omp_if.else
                                        #   in Loop: Header=BB58_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-196(%rbp), %rsi
	leaq	-168(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	.omp_outlined..40
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB58_9:                               # %omp_if.end
                                        #   in Loop: Header=BB58_5 Depth=1
	movsd	-192(%rbp), %xmm0       # xmm0 = mem[0],zero
	ucomisd	-136(%rbp), %xmm0
	jbe	.LBB58_11
# BB#10:                                # %if.then
                                        #   in Loop: Header=BB58_5 Depth=1
	movsd	-192(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	%xmm0, -136(%rbp)
	jmp	.LBB58_11
.LBB58_12:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-136(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-208(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.42, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB58_18
# BB#13:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	16(%rbp), %rax
	jne	.LBB58_23
# BB#14:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	-136(%rbp), %xmm0
	jbe	.LBB58_16
# BB#15:                                # %cond.true64
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB58_17
.LBB58_18:                              # %.omp.reduction.case2
	movq	16(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB58_19:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -224(%rbp)
	ucomisd	-136(%rbp), %xmm0
	jbe	.LBB58_21
# BB#20:                                # %cond.true69
                                        #   in Loop: Header=BB58_19 Depth=1
	movsd	-224(%rbp), %xmm0       # xmm0 = mem[0],zero
	jmp	.LBB58_22
	.align	16, 0x90
.LBB58_21:                              # %cond.false70
                                        #   in Loop: Header=BB58_19 Depth=1
	movsd	-136(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB58_22:                              # %cond.end71
                                        #   in Loop: Header=BB58_19 Depth=1
	movsd	%xmm0, -216(%rbp)
	movq	-216(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB58_19
	jmp	.LBB58_23
.LBB58_16:                              # %cond.false65
	movsd	-136(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB58_17:                              # %cond.end66
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
.LBB58_23:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end58:
	.size	.omp_outlined..39, .Lfunc_end58-.omp_outlined..39
	.cfi_endproc

	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI59_0:
	.quad	9223372036854775807     # 0x7fffffffffffffff
	.quad	9223372036854775807     # 0x7fffffffffffffff
	.text
	.align	16, 0x90
	.type	.omp_outlined..40,@function
.omp_outlined..40:                      # @.omp_outlined..40
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp426:
	.cfi_def_cfa_offset 16
.Ltmp427:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp428:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp429:
	.cfi_offset %rbx, -56
.Ltmp430:
	.cfi_offset %r12, -48
.Ltmp431:
	.cfi_offset %r13, -40
.Ltmp432:
	.cfi_offset %r14, -32
.Ltmp433:
	.cfi_offset %r15, -24
	movq	32(%rbp), %r10
	movq	24(%rbp), %rax
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%rax, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %r14
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r15
	movslq	(%rax), %rcx
	movslq	(%r14), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -128(%rbp)
	movl	$0, -132(%rbp)
	movl	$0, -136(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB59_24
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%r14)
	jle	.LBB59_24
# BB#2:                                 # %omp.precond.then
	movq	$0, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	$1, -160(%rbp)
	movl	$0, -164(%rbp)
	movabsq	$-4503599627370497, %rax # imm = 0xFFEFFFFFFFFFFFFF
	movq	%rax, -184(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-164(%rbp), %rcx
	leaq	-144(%rbp), %r8
	leaq	-152(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-152(%rbp), %rax
	cmpq	-128(%rbp), %rax
	jle	.LBB59_4
# BB#3:                                 # %cond.true
	movq	-128(%rbp), %rax
	jmp	.LBB59_5
.LBB59_4:                               # %cond.false
	movq	-152(%rbp), %rax
.LBB59_5:                               # %cond.end
	movq	%rax, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	movapd	.LCPI59_0(%rip), %xmm0  # xmm0 = [9223372036854775807,9223372036854775807]
	jmp	.LBB59_6
	.align	16, 0x90
.LBB59_12:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB59_6 Depth=1
	incq	-120(%rbp)
.LBB59_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB59_8 Depth 2
	movq	-120(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jg	.LBB59_13
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB59_6 Depth=1
	movq	-120(%rbp), %rax
	movslq	(%r14), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -176(%rbp)
	movq	-120(%rbp), %rax
	movslq	(%r14), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -172(%rbp)
	movl	$0, -168(%rbp)
	jmp	.LBB59_8
	.align	16, 0x90
.LBB59_11:                              # %for.inc
                                        #   in Loop: Header=BB59_8 Depth=2
	incl	-168(%rbp)
.LBB59_8:                               # %for.cond
                                        #   Parent Loop BB59_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-168(%rbp), %eax
	cmpl	(%rbx), %eax
	jge	.LBB59_12
# BB#9:                                 # %for.body
                                        #   in Loop: Header=BB59_8 Depth=2
	movl	-172(%rbp), %eax
	imull	(%r12), %eax
	addl	-168(%rbp), %eax
	movl	-176(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movslq	-196(%rbp), %rax
	movq	(%r15), %rcx
	movsd	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	andpd	%xmm0, %xmm1
	movlpd	%xmm1, -208(%rbp)
	ucomisd	-184(%rbp), %xmm1
	jbe	.LBB59_11
# BB#10:                                # %if.then
                                        #   in Loop: Header=BB59_8 Depth=2
	movsd	-208(%rbp), %xmm1       # xmm1 = mem[0],zero
	movsd	%xmm1, -184(%rbp)
	jmp	.LBB59_11
.LBB59_13:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-184(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %r14d
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-216(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.41, %r9d
	movl	%r14d, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB59_19
# BB#14:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	32(%rbp), %rax
	jne	.LBB59_24
# BB#15:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	-184(%rbp), %xmm0
	jbe	.LBB59_17
# BB#16:                                # %cond.true50
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB59_18
.LBB59_19:                              # %.omp.reduction.case2
	movq	32(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB59_20:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -232(%rbp)
	ucomisd	-184(%rbp), %xmm0
	jbe	.LBB59_22
# BB#21:                                # %cond.true56
                                        #   in Loop: Header=BB59_20 Depth=1
	movsd	-232(%rbp), %xmm0       # xmm0 = mem[0],zero
	jmp	.LBB59_23
	.align	16, 0x90
.LBB59_22:                              # %cond.false57
                                        #   in Loop: Header=BB59_20 Depth=1
	movsd	-184(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB59_23:                              # %cond.end58
                                        #   in Loop: Header=BB59_20 Depth=1
	movsd	%xmm0, -224(%rbp)
	movq	-224(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB59_20
	jmp	.LBB59_24
.LBB59_17:                              # %cond.false51
	movsd	-184(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB59_18:                              # %cond.end52
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%r14d, %esi
	callq	__kmpc_end_reduce_nowait
.LBB59_24:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end59:
	.size	.omp_outlined..40, .Lfunc_end59-.omp_outlined..40
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.41,@function
.omp.reduction.reduction_func.41:       # @.omp.reduction.reduction_func.41
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp434:
	.cfi_def_cfa_offset 16
.Ltmp435:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp436:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	(%rcx), %xmm0
	jbe	.LBB60_2
# BB#1:                                 # %cond.true
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB60_3
.LBB60_2:                               # %cond.false
	movsd	(%rcx), %xmm0           # xmm0 = mem[0],zero
.LBB60_3:                               # %cond.end
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end60:
	.size	.omp.reduction.reduction_func.41, .Lfunc_end60-.omp.reduction.reduction_func.41
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.42,@function
.omp.reduction.reduction_func.42:       # @.omp.reduction.reduction_func.42
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp437:
	.cfi_def_cfa_offset 16
.Ltmp438:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp439:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	ucomisd	(%rcx), %xmm0
	jbe	.LBB61_2
# BB#1:                                 # %cond.true
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	jmp	.LBB61_3
.LBB61_2:                               # %cond.false
	movsd	(%rcx), %xmm0           # xmm0 = mem[0],zero
.LBB61_3:                               # %cond.end
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end61:
	.size	.omp.reduction.reduction_func.42, .Lfunc_end61-.omp.reduction.reduction_func.42
	.cfi_endproc

	.globl	mean
	.align	16, 0x90
	.type	mean,@function
mean:                                   # @mean
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp440:
	.cfi_def_cfa_offset 16
.Ltmp441:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp442:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$96, %rsp
.Ltmp443:
	.cfi_offset %rbx, -48
.Ltmp444:
	.cfi_offset %r12, -40
.Ltmp445:
	.cfi_offset %r14, -32
.Ltmp446:
	.cfi_offset %r15, -24
	movl	%edx, %r15d
	movl	%esi, %r12d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -88(%rbp)
	movq	%rbx, -40(%rbp)
	movl	%r12d, -44(%rbp)
	movl	%r15d, -48(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	movl	$100000, -60(%rbp)      # imm = 0x186A0
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -64(%rbp)
	movslq	-44(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-60(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -68(%rbp)
	movq	$0, -80(%rbp)
	cmpl	$0, -64(%rbp)
	je	.LBB62_2
# BB#1:                                 # %omp_if.then
	leaq	-80(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-68(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-40(%rbp), %rcx
	leaq	-44(%rbp), %r8
	leaq	-48(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$5, %esi
	movl	$.omp_outlined..43, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB62_3
.LBB62_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -84(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-84(%rbp), %rdi
	leaq	-88(%rbp), %rsi
	leaq	-40(%rbp), %rdx
	leaq	-44(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-68(%rbp), %r9
	callq	.omp_outlined..43
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB62_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-56(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-40(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	movq	-40(%rbp), %rax
	cvtsi2sdl	1536(%rax), %xmm0
	cvtsi2sdl	1540(%rax), %xmm1
	mulsd	%xmm0, %xmm1
	cvtsi2sdl	1544(%rax), %xmm2
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, -96(%rbp)
	movsd	-80(%rbp), %xmm0        # xmm0 = mem[0],zero
	divsd	%xmm2, %xmm0
	movsd	%xmm0, -104(%rbp)
	addq	$96, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end62:
	.size	mean, .Lfunc_end62-mean
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..43,@function
.omp_outlined..43:                      # @.omp_outlined..43
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp447:
	.cfi_def_cfa_offset 16
.Ltmp448:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp449:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp450:
	.cfi_offset %rbx, -56
.Ltmp451:
	.cfi_offset %r12, -48
.Ltmp452:
	.cfi_offset %r13, -40
.Ltmp453:
	.cfi_offset %r14, -32
.Ltmp454:
	.cfi_offset %r15, -24
	movq	16(%rbp), %rax
	movl	$0, -196(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r12
	movq	-88(%rbp), %rbx
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -104(%rbp)
	movl	$0, -108(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB63_15
# BB#1:                                 # %omp.precond.then
	movl	$0, -112(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -116(%rbp)
	movl	$1, -120(%rbp)
	movl	$0, -124(%rbp)
	movq	$0, -136(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-120(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-124(%rbp), %rcx
	leaq	-112(%rbp), %r8
	leaq	-116(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-116(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jle	.LBB63_3
# BB#2:                                 # %cond.true
	movl	-104(%rbp), %eax
	jmp	.LBB63_4
.LBB63_3:                               # %cond.false
	movl	-116(%rbp), %eax
.LBB63_4:                               # %cond.end
	movl	%eax, -116(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -100(%rbp)
	jmp	.LBB63_5
	.align	16, 0x90
.LBB63_9:                               # %omp.inner.for.inc
                                        #   in Loop: Header=BB63_5 Depth=1
	movsd	-136(%rbp), %xmm0       # xmm0 = mem[0],zero
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, -136(%rbp)
	incl	-100(%rbp)
.LBB63_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-100(%rbp), %eax
	cmpl	-116(%rbp), %eax
	jg	.LBB63_10
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB63_5 Depth=1
	movl	-100(%rbp), %eax
	movl	%eax, -128(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-128(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%r12), %rax
	movslq	(%r15), %rcx
	movslq	-128(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -184(%rbp)
	movq	$0, -192(%rbp)
	cmpl	$0, (%rbx)
	je	.LBB63_8
# BB#7:                                 # %omp_if.then
                                        #   in Loop: Header=BB63_5 Depth=1
	leaq	-184(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-156(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$7, %esi
	movl	$.omp_outlined..44, %edx
	xorl	%eax, %eax
	leaq	-168(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB63_9
	.align	16, 0x90
.LBB63_8:                               # %omp_if.else
                                        #   in Loop: Header=BB63_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-196(%rbp), %rsi
	leaq	-168(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	.omp_outlined..44
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	jmp	.LBB63_9
.LBB63_10:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-136(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ebx
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-208(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.46, %r9d
	movl	%ebx, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB63_13
# BB#11:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	16(%rbp), %rax
	jne	.LBB63_15
# BB#12:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	-136(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%ebx, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB63_15
.LBB63_13:                              # %.omp.reduction.case2
	movq	16(%rbp), %rdx
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB63_14:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -224(%rbp)
	addsd	-136(%rbp), %xmm0
	movsd	%xmm0, -216(%rbp)
	movq	-216(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB63_14
.LBB63_15:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end63:
	.size	.omp_outlined..43, .Lfunc_end63-.omp_outlined..43
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..44,@function
.omp_outlined..44:                      # @.omp_outlined..44
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp455:
	.cfi_def_cfa_offset 16
.Ltmp456:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp457:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp458:
	.cfi_offset %rbx, -56
.Ltmp459:
	.cfi_offset %r12, -48
.Ltmp460:
	.cfi_offset %r13, -40
.Ltmp461:
	.cfi_offset %r14, -32
.Ltmp462:
	.cfi_offset %r15, -24
	movq	32(%rbp), %r12
	movq	24(%rbp), %rax
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%rax, -104(%rbp)
	movq	%r12, -112(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %r14
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r15
	movq	-104(%rbp), %rsi
	movslq	(%rax), %rcx
	movslq	(%r14), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -128(%rbp)
	movl	$0, -132(%rbp)
	movl	$0, -136(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB64_16
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%r14)
	jle	.LBB64_16
# BB#2:                                 # %omp.precond.then
	movq	%rsi, -232(%rbp)        # 8-byte Spill
	movq	$0, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, -152(%rbp)
	movq	$1, -160(%rbp)
	movl	$0, -164(%rbp)
	movq	$0, -184(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-164(%rbp), %rcx
	leaq	-144(%rbp), %r8
	leaq	-152(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-152(%rbp), %rax
	cmpq	-128(%rbp), %rax
	jle	.LBB64_4
# BB#3:                                 # %cond.true
	movq	-128(%rbp), %rax
	jmp	.LBB64_5
.LBB64_4:                               # %cond.false
	movq	-152(%rbp), %rax
.LBB64_5:                               # %cond.end
	movq	%rax, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	%rax, -120(%rbp)
	jmp	.LBB64_6
	.align	16, 0x90
.LBB64_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB64_6 Depth=1
	incq	-120(%rbp)
.LBB64_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB64_8 Depth 2
	movq	-120(%rbp), %rax
	cmpq	-152(%rbp), %rax
	jg	.LBB64_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB64_6 Depth=1
	movq	-120(%rbp), %rax
	movslq	(%r14), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -176(%rbp)
	movq	-120(%rbp), %rax
	movslq	(%r14), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -172(%rbp)
	movl	$0, -168(%rbp)
	jmp	.LBB64_8
	.align	16, 0x90
.LBB64_9:                               # %for.inc
                                        #   in Loop: Header=BB64_8 Depth=2
	movl	-172(%rbp), %eax
	imull	(%r13), %eax
	addl	-168(%rbp), %eax
	movl	-176(%rbp), %ecx
	imull	(%r15), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movslq	-196(%rbp), %rax
	movq	(%r12), %rcx
	movsd	-184(%rbp), %xmm0       # xmm0 = mem[0],zero
	addsd	(%rcx,%rax,8), %xmm0
	movsd	%xmm0, -184(%rbp)
	incl	-168(%rbp)
.LBB64_8:                               # %for.cond
                                        #   Parent Loop BB64_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-168(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB64_9
	jmp	.LBB64_10
.LBB64_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-184(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %r14d
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-208(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.45, %r9d
	movl	%r14d, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB64_14
# BB#12:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	-232(%rbp), %rax        # 8-byte Reload
	jne	.LBB64_16
# BB#13:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	-184(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%r14d, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB64_16
.LBB64_14:                              # %.omp.reduction.case2
	movq	-232(%rbp), %rdx        # 8-byte Reload
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB64_15:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -224(%rbp)
	addsd	-184(%rbp), %xmm0
	movsd	%xmm0, -216(%rbp)
	movq	-216(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB64_15
.LBB64_16:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end64:
	.size	.omp_outlined..44, .Lfunc_end64-.omp_outlined..44
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.45,@function
.omp.reduction.reduction_func.45:       # @.omp.reduction.reduction_func.45
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp463:
	.cfi_def_cfa_offset 16
.Ltmp464:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp465:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end65:
	.size	.omp.reduction.reduction_func.45, .Lfunc_end65-.omp.reduction.reduction_func.45
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.46,@function
.omp.reduction.reduction_func.46:       # @.omp.reduction.reduction_func.46
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp466:
	.cfi_def_cfa_offset 16
.Ltmp467:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp468:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end66:
	.size	.omp.reduction.reduction_func.46, .Lfunc_end66-.omp.reduction.reduction_func.46
	.cfi_endproc

	.globl	shift_grid
	.align	16, 0x90
	.type	shift_grid,@function
shift_grid:                             # @shift_grid
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp469:
	.cfi_def_cfa_offset 16
.Ltmp470:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp471:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
.Ltmp472:
	.cfi_offset %rbx, -56
.Ltmp473:
	.cfi_offset %r12, -48
.Ltmp474:
	.cfi_offset %r13, -40
.Ltmp475:
	.cfi_offset %r14, -32
.Ltmp476:
	.cfi_offset %r15, -24
	movsd	%xmm0, -112(%rbp)       # 8-byte Spill
	movl	%ecx, %r15d
	movl	%edx, %r12d
	movl	%esi, %r13d
	movq	%rdi, %rbx
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, %r14d
	movl	$0, -104(%rbp)
	movq	%rbx, -48(%rbp)
	movl	%r13d, -52(%rbp)
	movl	%r12d, -56(%rbp)
	movl	%r15d, -60(%rbp)
	movsd	-112(%rbp), %xmm0       # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, -72(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -80(%rbp)
	movl	$100000, -84(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -88(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-84(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -92(%rbp)
	cmpl	$0, -88(%rbp)
	je	.LBB67_2
# BB#1:                                 # %omp_if.then
	leaq	-72(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..47, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB67_3
.LBB67_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_serialized_parallel
	movl	%r14d, -100(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-92(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-100(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-60(%rbp), %r9
	callq	.omp_outlined..47
	movl	$.L__unnamed_1, %edi
	movl	%r14d, %esi
	callq	__kmpc_end_serialized_parallel
.LBB67_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-80(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$104, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end67:
	.size	shift_grid, .Lfunc_end67-shift_grid
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..47,@function
.omp_outlined..47:                      # @.omp_outlined..47
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp477:
	.cfi_def_cfa_offset 16
.Ltmp478:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp479:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp480:
	.cfi_offset %rbx, -56
.Ltmp481:
	.cfi_offset %r12, -48
.Ltmp482:
	.cfi_offset %r13, -40
.Ltmp483:
	.cfi_offset %r14, -32
.Ltmp484:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -196(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rax
	movq	%rax, -208(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rbx
	movq	-96(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB68_10
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB68_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB68_4
.LBB68_3:                               # %cond.false
	movl	-124(%rbp), %eax
.LBB68_4:                               # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB68_5
	.align	16, 0x90
.LBB68_7:                               # %omp_if.then
                                        #   in Loop: Header=BB68_5 Depth=1
	movq	24(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-156(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..48, %edx
	xorl	%eax, %eax
	leaq	-168(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-108(%rbp)
.LBB68_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB68_9
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB68_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movq	-208(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -184(%rbp)
	movslq	(%rbx), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -192(%rbp)
	cmpl	$0, (%r12)
	jne	.LBB68_7
# BB#8:                                 # %omp_if.else
                                        #   in Loop: Header=BB68_5 Depth=1
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	movq	24(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-196(%rbp), %rsi
	leaq	-168(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	.omp_outlined..48
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	incl	-108(%rbp)
	jmp	.LBB68_5
.LBB68_9:                               # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB68_10:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end68:
	.size	.omp_outlined..47, .Lfunc_end68-.omp_outlined..47
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..48,@function
.omp_outlined..48:                      # @.omp_outlined..48
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp485:
	.cfi_def_cfa_offset 16
.Ltmp486:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp487:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$200, %rsp
.Ltmp488:
	.cfi_offset %rbx, -56
.Ltmp489:
	.cfi_offset %r12, -48
.Ltmp490:
	.cfi_offset %r13, -40
.Ltmp491:
	.cfi_offset %r14, -32
.Ltmp492:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r11
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movslq	(%rax), %rcx
	movslq	(%rsi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB69_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	jle	.LBB69_12
# BB#2:                                 # %omp.precond.then
	movq	%rsi, -208(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB69_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB69_5
.LBB69_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB69_5:                               # %cond.end
	movq	40(%rbp), %rsi
	movq	-208(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	jmp	.LBB69_6
	.align	16, 0x90
.LBB69_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB69_6 Depth=1
	incq	-128(%rbp)
.LBB69_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB69_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB69_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB69_6 Depth=1
	movq	-128(%rbp), %rax
	movslq	(%rdi), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-128(%rbp), %rax
	movslq	(%rdi), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	movl	$0, -176(%rbp)
	jmp	.LBB69_8
	.align	16, 0x90
.LBB69_9:                               # %for.inc
                                        #   in Loop: Header=BB69_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r12), %eax
	addl	-176(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movslq	-196(%rbp), %rax
	movq	(%r15), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	addsd	(%rsi), %xmm0
	movq	(%r14), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-176(%rbp)
.LBB69_8:                               # %for.cond
                                        #   Parent Loop BB69_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-176(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB69_9
	jmp	.LBB69_10
.LBB69_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB69_12:                              # %omp.precond.end
	addq	$200, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end69:
	.size	.omp_outlined..48, .Lfunc_end69-.omp_outlined..48
	.cfi_endproc

	.globl	project_cell_to_face
	.align	16, 0x90
	.type	project_cell_to_face,@function
project_cell_to_face:                   # @project_cell_to_face
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp493:
	.cfi_def_cfa_offset 16
.Ltmp494:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp495:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
.Ltmp496:
	.cfi_offset %rbx, -56
.Ltmp497:
	.cfi_offset %r12, -48
.Ltmp498:
	.cfi_offset %r13, -40
.Ltmp499:
	.cfi_offset %r14, -32
.Ltmp500:
	.cfi_offset %r15, -24
	movl	%r8d, %r15d
	movl	%ecx, %r12d
	movl	%edx, %r13d
	movl	%esi, %ebx
	movq	%rdi, %r14
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -100(%rbp)        # 4-byte Spill
	movl	$0, -96(%rbp)
	movq	%r14, -48(%rbp)
	movl	%ebx, -52(%rbp)
	movl	%r13d, -56(%rbp)
	movl	%r12d, -60(%rbp)
	movl	%r15d, -64(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -72(%rbp)
	movl	$100000, -76(%rbp)      # imm = 0x186A0
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$100000, 20(%rcx,%rax)  # imm = 0x186A0
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -80(%rbp)
	movslq	-52(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	cmpl	-76(%rbp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -84(%rbp)
	cmpl	$0, -80(%rbp)
	je	.LBB70_2
# BB#1:                                 # %omp_if.then
	leaq	-84(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-64(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-60(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-56(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$6, %esi
	movl	$.omp_outlined..49, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB70_3
.LBB70_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-100(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -92(%rbp)
	leaq	-84(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-64(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-92(%rbp), %rdi
	leaq	-96(%rbp), %rsi
	leaq	-48(%rbp), %rdx
	leaq	-52(%rbp), %rcx
	leaq	-56(%rbp), %r8
	leaq	-60(%rbp), %r9
	callq	.omp_outlined..49
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB70_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-72(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 960(%rdx,%rcx,8)
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end70:
	.size	project_cell_to_face, .Lfunc_end70-project_cell_to_face
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..49,@function
.omp_outlined..49:                      # @.omp_outlined..49
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp501:
	.cfi_def_cfa_offset 16
.Ltmp502:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp503:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
.Ltmp504:
	.cfi_offset %rbx, -56
.Ltmp505:
	.cfi_offset %r12, -48
.Ltmp506:
	.cfi_offset %r13, -40
.Ltmp507:
	.cfi_offset %r14, -32
.Ltmp508:
	.cfi_offset %r15, -24
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movl	$0, -200(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	-64(%rbp), %r14
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %rbx
	movq	%rbx, -208(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r12
	movq	(%r14), %rax
	movl	1600(%rax), %eax
	decl	%eax
	movl	%eax, -112(%rbp)
	movl	$0, -116(%rbp)
	movq	(%r14), %rax
	cmpl	$0, 1600(%rax)
	jle	.LBB71_17
# BB#1:                                 # %omp.precond.then
	movl	$0, -120(%rbp)
	movl	-112(%rbp), %eax
	movl	%eax, -124(%rbp)
	movl	$1, -128(%rbp)
	movl	$0, -132(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-128(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$1, 16(%rsp)
	movl	$1, 8(%rsp)
	leaq	-132(%rbp), %rcx
	leaq	-120(%rbp), %r8
	leaq	-124(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_4
	movl	-124(%rbp), %eax
	cmpl	-112(%rbp), %eax
	jle	.LBB71_3
# BB#2:                                 # %cond.true
	movl	-112(%rbp), %eax
	jmp	.LBB71_4
.LBB71_3:                               # %cond.false
	movl	-124(%rbp), %eax
.LBB71_4:                               # %cond.end
	movl	%eax, -124(%rbp)
	movl	-120(%rbp), %eax
	movl	%eax, -108(%rbp)
	jmp	.LBB71_5
	.align	16, 0x90
.LBB71_14:                              # %omp_if.then
                                        #   in Loop: Header=BB71_5 Depth=1
	leaq	-196(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-156(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..50, %edx
	xorl	%eax, %eax
	leaq	-168(%rbp), %rcx
	leaq	-172(%rbp), %r8
	leaq	-176(%rbp), %r9
	callq	__kmpc_fork_call
	incl	-108(%rbp)
.LBB71_5:                               # %omp.inner.for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-108(%rbp), %eax
	cmpl	-124(%rbp), %eax
	jg	.LBB71_16
# BB#6:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB71_5 Depth=1
	movl	-108(%rbp), %eax
	movl	%eax, -136(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -156(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -160(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -164(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -168(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -172(%rbp)
	movslq	(%r15), %rax
	movslq	-136(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -176(%rbp)
	movslq	(%rbx), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -184(%rbp)
	movslq	(%r13), %rax
	movslq	(%r15), %rcx
	movslq	-136(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-164(%rbp), %rdx
	movslq	-156(%rbp), %rsi
	movslq	-160(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -192(%rbp)
	movl	(%r12), %eax
	cmpl	$2, %eax
	je	.LBB71_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB71_5 Depth=1
	cmpl	$1, %eax
	je	.LBB71_10
# BB#8:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB71_5 Depth=1
	testl	%eax, %eax
	jne	.LBB71_13
# BB#9:                                 # %sw.bb
                                        #   in Loop: Header=BB71_5 Depth=1
	movl	$1, -196(%rbp)
	jmp	.LBB71_13
	.align	16, 0x90
.LBB71_11:                              # %sw.bb75
                                        #   in Loop: Header=BB71_5 Depth=1
	movl	-160(%rbp), %eax
	jmp	.LBB71_12
	.align	16, 0x90
.LBB71_10:                              # %sw.bb74
                                        #   in Loop: Header=BB71_5 Depth=1
	movl	-156(%rbp), %eax
.LBB71_12:                              # %sw.epilog
                                        #   in Loop: Header=BB71_5 Depth=1
	movl	%eax, -196(%rbp)
.LBB71_13:                              # %sw.epilog
                                        #   in Loop: Header=BB71_5 Depth=1
	movq	24(%rbp), %rax
	cmpl	$0, (%rax)
	jne	.LBB71_14
# BB#15:                                # %omp_if.else
                                        #   in Loop: Header=BB71_5 Depth=1
	movq	-48(%rbp), %rax
	movq	%r12, %rbx
	movq	%r13, %r12
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-196(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-184(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-192(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-160(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-200(%rbp), %rsi
	leaq	-168(%rbp), %rdx
	leaq	-172(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-156(%rbp), %r9
	callq	.omp_outlined..50
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	movq	%r12, %r13
	movq	%rbx, %r12
	movq	-208(%rbp), %rbx        # 8-byte Reload
	callq	__kmpc_end_serialized_parallel
	incl	-108(%rbp)
	jmp	.LBB71_5
.LBB71_16:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB71_17:                              # %omp.precond.end
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end71:
	.size	.omp_outlined..49, .Lfunc_end71-.omp_outlined..49
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI72_0:
	.quad	4602678819172646912     # double 0.5
	.text
	.align	16, 0x90
	.type	.omp_outlined..50,@function
.omp_outlined..50:                      # @.omp_outlined..50
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp509:
	.cfi_def_cfa_offset 16
.Ltmp510:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp511:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$200, %rsp
.Ltmp512:
	.cfi_offset %rbx, -56
.Ltmp513:
	.cfi_offset %r12, -48
.Ltmp514:
	.cfi_offset %r13, -40
.Ltmp515:
	.cfi_offset %r14, -32
.Ltmp516:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r11
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r11, -120(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r12
	movq	-96(%rbp), %r13
	movq	-104(%rbp), %r14
	movq	-112(%rbp), %r15
	movl	(%rax), %ecx
	incl	%ecx
	movslq	%ecx, %rcx
	movl	(%rsi), %edx
	incl	%edx
	movslq	%edx, %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rax)
	js	.LBB72_12
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rsi)
	js	.LBB72_12
# BB#2:                                 # %omp.precond.then
	movq	%rsi, -208(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB72_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB72_5
.LBB72_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB72_5:                               # %cond.end
	movq	40(%rbp), %rsi
	movq	-208(%rbp), %rdi        # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	movsd	.LCPI72_0(%rip), %xmm0  # xmm0 = mem[0],zero
	jmp	.LBB72_6
	.align	16, 0x90
.LBB72_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB72_6 Depth=1
	incq	-128(%rbp)
.LBB72_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB72_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB72_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB72_6 Depth=1
	movq	-128(%rbp), %rax
	movl	(%rdi), %ecx
	incl	%ecx
	movslq	%ecx, %rcx
	cqto
	idivq	%rcx
	movl	%eax, -176(%rbp)
	movq	-128(%rbp), %rax
	movl	(%rdi), %ecx
	incl	%ecx
	movslq	%ecx, %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	movl	$0, -184(%rbp)
	jmp	.LBB72_8
	.align	16, 0x90
.LBB72_9:                               # %for.inc
                                        #   in Loop: Header=BB72_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r12), %eax
	addl	-184(%rbp), %eax
	movl	-176(%rbp), %ecx
	imull	(%r13), %ecx
	addl	%eax, %ecx
	movl	%ecx, -196(%rbp)
	movslq	-196(%rbp), %rax
	movslq	(%rsi), %rcx
	movq	%rax, %rdx
	subq	%rcx, %rdx
	movq	(%r15), %rcx
	movsd	(%rcx,%rdx,8), %xmm1    # xmm1 = mem[0],zero
	addsd	(%rcx,%rax,8), %xmm1
	mulsd	%xmm0, %xmm1
	movq	(%r14), %rcx
	movsd	%xmm1, (%rcx,%rax,8)
	incl	-184(%rbp)
.LBB72_8:                               # %for.cond
                                        #   Parent Loop BB72_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-184(%rbp), %eax
	cmpl	(%rbx), %eax
	jle	.LBB72_9
	jmp	.LBB72_10
.LBB72_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB72_12:                              # %omp.precond.end
	addq	$200, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end72:
	.size	.omp_outlined..50, .Lfunc_end72-.omp_outlined..50
	.cfi_endproc

	.globl	matmul_grids
	.align	16, 0x90
	.type	matmul_grids,@function
matmul_grids:                           # @matmul_grids
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp517:
	.cfi_def_cfa_offset 16
.Ltmp518:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp519:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$136, %rsp
.Ltmp520:
	.cfi_offset %rbx, -56
.Ltmp521:
	.cfi_offset %r12, -48
.Ltmp522:
	.cfi_offset %r13, -40
.Ltmp523:
	.cfi_offset %r14, -32
.Ltmp524:
	.cfi_offset %r15, -24
	movl	%r9d, -132(%rbp)        # 4-byte Spill
	movq	%r8, %r12
	movq	%rcx, %r13
	movq	%rdx, %rbx
	movl	%esi, %r14d
	movq	%rdi, %r15
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_global_thread_num
	movl	%eax, -136(%rbp)        # 4-byte Spill
	movl	$0, -128(%rbp)
	movq	%r15, -48(%rbp)
	movl	%r14d, -52(%rbp)
	movq	%rbx, -64(%rbp)
	movq	%r13, -72(%rbp)
	movq	%r12, -80(%rbp)
	movl	-132(%rbp), %eax        # 4-byte Reload
	movl	%eax, -84(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, -88(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -92(%rbp)
	movl	$1, -96(%rbp)
	movl	$0, -100(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -120(%rbp)
	cmpl	$0, -96(%rbp)
	je	.LBB73_2
# BB#1:                                 # %omp_if.then
	leaq	-64(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-80(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-52(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-84(%rbp), %rcx
	leaq	-88(%rbp), %r8
	leaq	-48(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..51, %edx
	xorl	%eax, %eax
	callq	__kmpc_fork_call
	jmp	.LBB73_3
.LBB73_2:                               # %omp_if.else
	movl	$.L__unnamed_1, %edi
	movl	-136(%rbp), %ebx        # 4-byte Reload
	movl	%ebx, %esi
	callq	__kmpc_serialized_parallel
	movl	%ebx, -124(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-100(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-80(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-124(%rbp), %rdi
	leaq	-128(%rbp), %rsi
	leaq	-84(%rbp), %rdx
	leaq	-88(%rbp), %rcx
	leaq	-48(%rbp), %r8
	leaq	-52(%rbp), %r9
	callq	.omp_outlined..51
	movl	$.L__unnamed_1, %edi
	movl	%ebx, %esi
	callq	__kmpc_end_serialized_parallel
.LBB73_3:                               # %omp_if.end
	xorl	%eax, %eax
	callq	CycleTime
	subq	-120(%rbp), %rax
	movslq	-52(%rbp), %rcx
	movq	-48(%rbp), %rdx
	addq	%rax, 1040(%rdx,%rcx,8)
	addq	$136, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end73:
	.size	matmul_grids, .Lfunc_end73-matmul_grids
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..51,@function
.omp_outlined..51:                      # @.omp_outlined..51
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp525:
	.cfi_def_cfa_offset 16
.Ltmp526:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp527:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$296, %rsp              # imm = 0x128
.Ltmp528:
	.cfi_offset %rbx, -56
.Ltmp529:
	.cfi_offset %r12, -48
.Ltmp530:
	.cfi_offset %r13, -40
.Ltmp531:
	.cfi_offset %r14, -32
.Ltmp532:
	.cfi_offset %r15, -24
	movq	40(%rbp), %rbx
	movq	32(%rbp), %r10
	movq	24(%rbp), %r11
	movq	16(%rbp), %rax
	movl	$0, -268(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%r11, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%rbx, -120(%rbp)
	movq	-64(%rbp), %rdx
	movq	%rdx, -296(%rbp)        # 8-byte Spill
	movq	-72(%rbp), %r13
	movq	-80(%rbp), %r14
	movq	-88(%rbp), %r15
	movq	-96(%rbp), %rax
	movq	%rax, -280(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rbx
	movq	-112(%rbp), %r12
	movslq	(%rdx), %rax
	movslq	(%r13), %rcx
	imulq	%rax, %rcx
	decq	%rcx
	movq	%rcx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rdx)
	jle	.LBB74_21
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%r13)
	jle	.LBB74_21
# BB#2:                                 # %omp.precond.then
	movq	%r13, -288(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$33, %edx
	callq	__kmpc_for_static_init_8
	jmp	.LBB74_3
	.align	16, 0x90
.LBB74_19:                              # %omp.dispatch.inc
                                        #   in Loop: Header=BB74_3 Depth=1
	movq	%rsi, %r13
	movq	-168(%rbp), %rax
	addq	%rax, -152(%rbp)
	movq	-168(%rbp), %rax
	addq	%rax, -160(%rbp)
.LBB74_3:                               # %omp.dispatch.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB74_7 Depth 2
                                        #       Child Loop BB74_10 Depth 3
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	movq	%r13, %rsi
	jle	.LBB74_5
# BB#4:                                 # %cond.true
                                        #   in Loop: Header=BB74_3 Depth=1
	movq	-136(%rbp), %rax
	jmp	.LBB74_6
	.align	16, 0x90
.LBB74_5:                               # %cond.false
                                        #   in Loop: Header=BB74_3 Depth=1
	movq	-160(%rbp), %rax
.LBB74_6:                               # %cond.end
                                        #   in Loop: Header=BB74_3 Depth=1
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	cmpq	-160(%rbp), %rax
	jle	.LBB74_7
	jmp	.LBB74_20
	.align	16, 0x90
.LBB74_18:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB74_7 Depth=2
	incq	-128(%rbp)
.LBB74_7:                               # %omp.inner.for.cond
                                        #   Parent Loop BB74_3 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB74_10 Depth 3
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB74_19
# BB#8:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB74_7 Depth=2
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -176(%rbp)
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	cmpl	-176(%rbp), %edx
	jl	.LBB74_18
# BB#9:                                 # %if.then
                                        #   in Loop: Header=BB74_7 Depth=2
	movq	$0, -200(%rbp)
	movl	$0, -192(%rbp)
	jmp	.LBB74_10
	.align	16, 0x90
.LBB74_14:                              # %for.inc
                                        #   in Loop: Header=BB74_10 Depth=3
	movsd	-200(%rbp), %xmm0       # xmm0 = mem[0],zero
	addsd	-264(%rbp), %xmm0
	movsd	%xmm0, -200(%rbp)
	incl	-192(%rbp)
.LBB74_10:                              # %for.cond
                                        #   Parent Loop BB74_3 Depth=1
                                        #     Parent Loop BB74_7 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-192(%rbp), %eax
	movq	(%r14), %rcx
	cmpl	1600(%rcx), %eax
	jge	.LBB74_15
# BB#11:                                # %for.body
                                        #   in Loop: Header=BB74_10 Depth=3
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	48(%rcx,%rax), %eax
	movl	%eax, -216(%rbp)
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	52(%rcx,%rax), %eax
	movl	%eax, -220(%rbp)
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -224(%rbp)
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -228(%rbp)
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -232(%rbp)
	movslq	(%r15), %rax
	movslq	-192(%rbp), %rcx
	movq	(%r14), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -236(%rbp)
	movslq	-176(%rbp), %rax
	movq	-280(%rbp), %rcx        # 8-byte Reload
	movq	(%rcx), %rcx
	movslq	(%rcx,%rax,4), %rax
	movslq	(%r15), %rcx
	movslq	-192(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-224(%rbp), %rdx
	movslq	-216(%rbp), %rsi
	movslq	-220(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -248(%rbp)
	movslq	-180(%rbp), %rax
	movq	(%rbx), %rcx
	movslq	(%rcx,%rax,4), %rax
	movslq	(%r15), %rcx
	movslq	-192(%rbp), %rdx
	movq	(%r14), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movslq	-224(%rbp), %rdx
	movslq	-216(%rbp), %rsi
	movslq	-220(%rbp), %rdi
	leaq	1(%rsi,%rdi), %rsi
	imulq	%rdx, %rsi
	shlq	$3, %rsi
	addq	(%rcx,%rax,8), %rsi
	movq	%rsi, -256(%rbp)
	movq	$0, -264(%rbp)
	cmpl	$0, (%r12)
	je	.LBB74_13
# BB#12:                                # %omp_if.then
                                        #   in Loop: Header=BB74_10 Depth=3
	leaq	-256(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-264(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-220(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-216(%rbp), %rax
	movq	%rax, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$8, %esi
	movl	$.omp_outlined..52, %edx
	xorl	%eax, %eax
	leaq	-228(%rbp), %rcx
	leaq	-232(%rbp), %r8
	leaq	-236(%rbp), %r9
	callq	__kmpc_fork_call
	jmp	.LBB74_14
	.align	16, 0x90
.LBB74_13:                              # %omp_if.else
                                        #   in Loop: Header=BB74_10 Depth=3
	movq	-48(%rbp), %rax
	movl	(%rax), %r13d
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_serialized_parallel
	movq	-48(%rbp), %rdi
	leaq	-256(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-248(%rbp), %rax
	movq	%rax, 16(%rsp)
	leaq	-264(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-220(%rbp), %rax
	movq	%rax, (%rsp)
	leaq	-268(%rbp), %rsi
	leaq	-228(%rbp), %rdx
	leaq	-232(%rbp), %rcx
	leaq	-236(%rbp), %r8
	leaq	-216(%rbp), %r9
	callq	.omp_outlined..52
	movl	$.L__unnamed_1, %edi
	movl	%r13d, %esi
	callq	__kmpc_end_serialized_parallel
	jmp	.LBB74_14
	.align	16, 0x90
.LBB74_15:                              # %for.end
                                        #   in Loop: Header=BB74_7 Depth=2
	movsd	-200(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-176(%rbp), %rax
	movq	-288(%rbp), %rsi        # 8-byte Reload
	movslq	(%rsi), %rcx
	imulq	%rax, %rcx
	movslq	-180(%rbp), %rax
	addq	%rcx, %rax
	movq	40(%rbp), %rcx
	movq	(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	movl	-176(%rbp), %eax
	cmpl	(%rsi), %eax
	jge	.LBB74_18
# BB#16:                                # %land.lhs.true120
                                        #   in Loop: Header=BB74_7 Depth=2
	movl	-180(%rbp), %eax
	movq	-296(%rbp), %rcx        # 8-byte Reload
	cmpl	(%rcx), %eax
	jge	.LBB74_18
# BB#17:                                # %if.then123
                                        #   in Loop: Header=BB74_7 Depth=2
	movsd	-200(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-180(%rbp), %rax
	movslq	(%rsi), %rcx
	imulq	%rax, %rcx
	movslq	-176(%rbp), %rax
	addq	%rcx, %rax
	movq	40(%rbp), %rcx
	movq	(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	jmp	.LBB74_18
.LBB74_20:                              # %omp.dispatch.end
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB74_21:                              # %omp.precond.end
	addq	$296, %rsp              # imm = 0x128
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end74:
	.size	.omp_outlined..51, .Lfunc_end74-.omp_outlined..51
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined..52,@function
.omp_outlined..52:                      # @.omp_outlined..52
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp533:
	.cfi_def_cfa_offset 16
.Ltmp534:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp535:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$232, %rsp
.Ltmp536:
	.cfi_offset %rbx, -56
.Ltmp537:
	.cfi_offset %r12, -48
.Ltmp538:
	.cfi_offset %r13, -40
.Ltmp539:
	.cfi_offset %r14, -32
.Ltmp540:
	.cfi_offset %r15, -24
	movq	40(%rbp), %r12
	movq	32(%rbp), %r10
	movq	24(%rbp), %rbx
	movq	16(%rbp), %rax
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rax, -96(%rbp)
	movq	%rbx, -104(%rbp)
	movq	%r10, -112(%rbp)
	movq	%r12, -120(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdi
	movq	-80(%rbp), %rbx
	movq	-88(%rbp), %r13
	movq	-96(%rbp), %r15
	movq	-104(%rbp), %rsi
	movq	-112(%rbp), %r14
	movslq	(%rax), %rcx
	movslq	(%rdi), %rdx
	imulq	%rcx, %rdx
	decq	%rdx
	movq	%rdx, -136(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -144(%rbp)
	cmpl	$0, (%rax)
	jle	.LBB75_16
# BB#1:                                 # %land.lhs.true
	cmpl	$0, (%rdi)
	jle	.LBB75_16
# BB#2:                                 # %omp.precond.then
	movq	%rdi, -248(%rbp)        # 8-byte Spill
	movq	%rsi, -240(%rbp)        # 8-byte Spill
	movq	$0, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	$1, -168(%rbp)
	movl	$0, -172(%rbp)
	movq	$0, -192(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-168(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %r8
	leaq	-160(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-160(%rbp), %rax
	cmpq	-136(%rbp), %rax
	jle	.LBB75_4
# BB#3:                                 # %cond.true
	movq	-136(%rbp), %rax
	jmp	.LBB75_5
.LBB75_4:                               # %cond.false
	movq	-160(%rbp), %rax
.LBB75_5:                               # %cond.end
	movq	-248(%rbp), %rsi        # 8-byte Reload
	movq	%rax, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	%rax, -128(%rbp)
	jmp	.LBB75_6
	.align	16, 0x90
.LBB75_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB75_6 Depth=1
	incq	-128(%rbp)
.LBB75_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB75_8 Depth 2
	movq	-128(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jg	.LBB75_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB75_6 Depth=1
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -184(%rbp)
	movq	-128(%rbp), %rax
	movslq	(%rsi), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -180(%rbp)
	movl	$0, -176(%rbp)
	jmp	.LBB75_8
	.align	16, 0x90
.LBB75_9:                               # %for.inc
                                        #   in Loop: Header=BB75_8 Depth=2
	movl	-180(%rbp), %eax
	imull	(%r13), %eax
	addl	-176(%rbp), %eax
	movl	-184(%rbp), %ecx
	imull	(%r15), %ecx
	addl	%eax, %ecx
	movl	%ecx, -204(%rbp)
	movslq	-204(%rbp), %rax
	movq	(%r14), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movq	(%r12), %rcx
	mulsd	(%rcx,%rax,8), %xmm0
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, -192(%rbp)
	incl	-176(%rbp)
.LBB75_8:                               # %for.cond
                                        #   Parent Loop BB75_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-176(%rbp), %eax
	cmpl	(%rbx), %eax
	jl	.LBB75_9
	jmp	.LBB75_10
.LBB75_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
	leaq	-192(%rbp), %rax
	movq	%rax, -216(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %r14d
	movq	$.gomp_critical_user_.reduction.var, (%rsp)
	leaq	-216(%rbp), %r8
	movl	$.L__unnamed_2, %edi
	movl	$1, %edx
	movl	$8, %ecx
	movl	$.omp.reduction.reduction_func.53, %r9d
	movl	%r14d, %esi
	callq	__kmpc_reduce_nowait
	cmpl	$2, %eax
	je	.LBB75_14
# BB#12:                                # %omp.loop.exit
	cmpl	$1, %eax
	movq	-240(%rbp), %rax        # 8-byte Reload
	jne	.LBB75_16
# BB#13:                                # %.omp.reduction.case1
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	$.L__unnamed_2, %edi
	movl	$.gomp_critical_user_.reduction.var, %edx
	movl	%r14d, %esi
	callq	__kmpc_end_reduce_nowait
	jmp	.LBB75_16
.LBB75_14:                              # %.omp.reduction.case2
	movq	-240(%rbp), %rdx        # 8-byte Reload
	movq	(%rdx), %rax
	.align	16, 0x90
.LBB75_15:                              # %atomic_cont
                                        # =>This Inner Loop Header: Depth=1
	movd	%rax, %xmm0
	movq	%rax, -232(%rbp)
	addsd	-192(%rbp), %xmm0
	movsd	%xmm0, -224(%rbp)
	movq	-224(%rbp), %rcx
	lock		cmpxchgq	%rcx, (%rdx)
	jne	.LBB75_15
.LBB75_16:                              # %omp.precond.end
	addq	$232, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end75:
	.size	.omp_outlined..52, .Lfunc_end75-.omp_outlined..52
	.cfi_endproc

	.align	16, 0x90
	.type	.omp.reduction.reduction_func.53,@function
.omp.reduction.reduction_func.53:       # @.omp.reduction.reduction_func.53
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp541:
	.cfi_def_cfa_offset 16
.Ltmp542:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp543:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rax)
	popq	%rbp
	retq
.Lfunc_end76:
	.size	.omp.reduction.reduction_func.53, .Lfunc_end76-.omp.reduction.reduction_func.53
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI77_0:
	.quad	4621819117588971520     # double 10
.LCPI77_1:
	.quad	4611686018427387904     # double 2
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI77_2:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	initialize_problem
	.align	16, 0x90
	.type	initialize_problem,@function
initialize_problem:                     # @initialize_problem
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp544:
	.cfi_def_cfa_offset 16
.Ltmp545:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp546:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$184, %rsp
.Ltmp547:
	.cfi_offset %rbx, -56
.Ltmp548:
	.cfi_offset %r12, -48
.Ltmp549:
	.cfi_offset %r13, -40
.Ltmp550:
	.cfi_offset %r14, -32
.Ltmp551:
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)
	movl	%esi, -52(%rbp)
	movsd	%xmm0, -64(%rbp)
	movsd	%xmm1, -72(%rbp)
	movsd	%xmm2, -80(%rbp)
	movabsq	$4618760256179416344, %rax # imm = 0x401921FB54442D18
	movq	%rax, -88(%rbp)
	movabsq	$4607182418800017408, %rax # imm = 0x3FF0000000000000
	movq	%rax, -96(%rbp)
	movabsq	$4621819117588971520, %rax # imm = 0x4024000000000000
	movq	%rax, -104(%rbp)
	movsd	.LCPI77_0(%rip), %xmm0  # xmm0 = mem[0],zero
	subsd	-96(%rbp), %xmm0
	movsd	.LCPI77_1(%rip), %xmm1  # xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -112(%rbp)
	movsd	-104(%rbp), %xmm0       # xmm0 = mem[0],zero
	addsd	-96(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -120(%rbp)
	movq	%rax, -128(%rbp)
	movabsq	$-4597049319638433792, %rax # imm = 0xC034000000000000
	movq	%rax, -136(%rbp)
	movl	$0, -140(%rbp)
	leaq	-120(%rbp), %r12
	leaq	-64(%rbp), %r13
	leaq	-48(%rbp), %r14
	leaq	-140(%rbp), %r15
	leaq	-52(%rbp), %rbx
	jmp	.LBB77_1
	.align	16, 0x90
.LBB77_2:                               # %for.body
                                        #   in Loop: Header=BB77_1 Depth=1
	movslq	-52(%rbp), %rax
	movslq	-140(%rbp), %rcx
	movq	-48(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rdx
	movq	88(%rdx), %rdi
	movslq	56(%rcx,%rax), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	memset
	movslq	-52(%rbp), %rax
	movslq	-140(%rbp), %rcx
	movq	-48(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movq	176(%rcx,%rax), %rdx
	movq	8(%rdx), %rdi
	movslq	56(%rcx,%rax), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	memset
	leaq	-80(%rbp), %rax
	movq	%rax, 56(%rsp)
	leaq	-72(%rbp), %rax
	movq	%rax, 48(%rsp)
	leaq	-88(%rbp), %rax
	movq	%rax, 40(%rsp)
	leaq	-136(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-128(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-112(%rbp), %rax
	movq	%rax, 16(%rsp)
	movq	%r12, 8(%rsp)
	movq	%r13, (%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$11, %esi
	movl	$.omp_outlined..54, %edx
	xorl	%eax, %eax
	movq	%r14, %rcx
	movq	%r15, %r8
	movq	%rbx, %r9
	callq	__kmpc_fork_call
	incl	-140(%rbp)
.LBB77_1:                               # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-140(%rbp), %eax
	movq	-48(%rbp), %rcx
	cmpl	1600(%rcx), %eax
	jl	.LBB77_2
# BB#3:                                 # %for.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$1, %edx
	callq	mean
	movsd	%xmm0, -160(%rbp)
	movq	-48(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB77_5
# BB#4:                                 # %if.then
	movsd	-160(%rbp), %xmm0       # xmm0 = mem[0],zero
	movl	$.L.str.55, %edi
	movb	$1, %al
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB77_5:                               # %if.end
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB77_6
	jnp	.LBB77_7
.LBB77_6:                               # %if.then34
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-160(%rbp), %xmm0       # xmm0 = mem[0],zero
	xorpd	.LCPI77_2(%rip), %xmm0
	movl	$1, %edx
	movl	$1, %ecx
	callq	shift_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-160(%rbp), %xmm0       # xmm0 = mem[0],zero
	xorpd	.LCPI77_2(%rip), %xmm0
	divsd	-72(%rbp), %xmm0
	movl	$11, %edx
	movl	$11, %ecx
	callq	shift_grid
.LBB77_7:                               # %if.end38
	addq	$184, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end77:
	.size	initialize_problem, .Lfunc_end77-initialize_problem
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI78_0:
	.quad	4602678819172646912     # double 0.5
.LCPI78_1:
	.quad	4611686018427387904     # double 2
.LCPI78_2:
	.quad	-4620693217682128896    # double -0.5
.LCPI78_3:
	.quad	4598175219545276416     # double 0.25
.LCPI78_4:
	.quad	-4613937818241073152    # double -1.5
.LCPI78_5:
	.quad	4607182418800017408     # double 1
	.text
	.align	16, 0x90
	.type	.omp_outlined..54,@function
.omp_outlined..54:                      # @.omp_outlined..54
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp552:
	.cfi_def_cfa_offset 16
.Ltmp553:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp554:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$568, %rsp              # imm = 0x238
.Ltmp555:
	.cfi_offset %rbx, -56
.Ltmp556:
	.cfi_offset %r12, -48
.Ltmp557:
	.cfi_offset %r13, -40
.Ltmp558:
	.cfi_offset %r14, -32
.Ltmp559:
	.cfi_offset %r15, -24
	movq	64(%rbp), %rax
	movq	56(%rbp), %r10
	movq	48(%rbp), %r11
	movq	40(%rbp), %r14
	movq	32(%rbp), %r15
	movq	24(%rbp), %r12
	movq	16(%rbp), %rbx
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movq	%rbx, -96(%rbp)
	movq	%r12, -104(%rbp)
	movq	%r15, -112(%rbp)
	movq	%r14, -120(%rbp)
	movq	%r11, -128(%rbp)
	movq	%r10, -136(%rbp)
	movq	%rax, -144(%rbp)
	movq	-64(%rbp), %rbx
	movq	-72(%rbp), %r15
	movq	-80(%rbp), %r14
	movq	%r14, -520(%rbp)        # 8-byte Spill
	movq	-88(%rbp), %rax
	movq	%rax, -488(%rbp)        # 8-byte Spill
	movq	-96(%rbp), %rax
	movq	%rax, -496(%rbp)        # 8-byte Spill
	movq	-104(%rbp), %rax
	movq	%rax, -504(%rbp)        # 8-byte Spill
	movq	-112(%rbp), %rax
	movq	%rax, -512(%rbp)        # 8-byte Spill
	movq	-120(%rbp), %rax
	movq	%rax, -528(%rbp)        # 8-byte Spill
	movq	-128(%rbp), %r13
	movq	-136(%rbp), %rax
	movq	%rax, -536(%rbp)        # 8-byte Spill
	movslq	(%r14), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movslq	28(%rcx,%rax), %rdx
	movslq	24(%rcx,%rax), %rax
	imulq	%rdx, %rax
	decq	%rax
	movq	%rax, -160(%rbp)
	movl	$0, -164(%rbp)
	movl	$0, -168(%rbp)
	movslq	(%r14), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$0, 28(%rcx,%rax)
	jle	.LBB78_12
# BB#1:                                 # %land.lhs.true
	movslq	(%r14), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	cmpl	$0, 24(%rcx,%rax)
	jle	.LBB78_12
# BB#2:                                 # %omp.precond.then
	movq	$0, -176(%rbp)
	movq	-160(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	$1, -192(%rbp)
	movl	$0, -196(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	leaq	-192(%rbp), %rax
	movq	%rax, (%rsp)
	movq	$1, 16(%rsp)
	movq	$1, 8(%rsp)
	leaq	-196(%rbp), %rcx
	leaq	-176(%rbp), %r8
	leaq	-184(%rbp), %r9
	movl	$.L__unnamed_1, %edi
	movl	$34, %edx
	callq	__kmpc_for_static_init_8
	movq	-184(%rbp), %rax
	cmpq	-160(%rbp), %rax
	jle	.LBB78_4
# BB#3:                                 # %cond.true
	movq	-160(%rbp), %rax
	jmp	.LBB78_5
.LBB78_4:                               # %cond.false
	movq	-184(%rbp), %rax
.LBB78_5:                               # %cond.end
	movq	%rax, -184(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, -152(%rbp)
	jmp	.LBB78_6
	.align	16, 0x90
.LBB78_10:                              # %omp.inner.for.inc
                                        #   in Loop: Header=BB78_6 Depth=1
	incq	-152(%rbp)
.LBB78_6:                               # %omp.inner.for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB78_8 Depth 2
	movq	-152(%rbp), %rax
	cmpq	-184(%rbp), %rax
	jg	.LBB78_11
# BB#7:                                 # %omp.inner.for.body
                                        #   in Loop: Header=BB78_6 Depth=1
	movq	-152(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movslq	24(%rdx,%rcx), %rcx
	cqto
	idivq	%rcx
	movl	%eax, -200(%rbp)
	movq	-152(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movslq	24(%rdx,%rcx), %rcx
	cqto
	idivq	%rcx
	movl	%edx, -204(%rbp)
	movl	$0, -208(%rbp)
	jmp	.LBB78_8
	.align	16, 0x90
.LBB78_9:                               # %for.inc
                                        #   in Loop: Header=BB78_8 Depth=2
	movl	-208(%rbp), %eax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	addl	8(%rdx,%rcx), %eax
	cvtsi2sdl	%eax, %xmm0
	movsd	.LCPI78_0(%rip), %xmm1  # xmm1 = mem[0],zero
	addsd	%xmm1, %xmm0
	movq	-488(%rbp), %rdi        # 8-byte Reload
	mulsd	(%rdi), %xmm0
	movsd	%xmm0, -224(%rbp)
	movl	-204(%rbp), %eax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	addl	12(%rdx,%rcx), %eax
	xorps	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	addsd	%xmm1, %xmm0
	mulsd	(%rdi), %xmm0
	movsd	%xmm0, -232(%rbp)
	movl	-200(%rbp), %eax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	addl	16(%rdx,%rcx), %eax
	xorps	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	addsd	%xmm1, %xmm0
	mulsd	(%rdi), %xmm0
	movsd	%xmm0, -240(%rbp)
	movslq	(%r14), %rax
	movslq	(%r15), %rcx
	movq	(%rbx), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %edx
	movl	-208(%rbp), %esi
	addl	%edx, %esi
	movl	-204(%rbp), %edi
	addl	%edx, %edi
	imull	48(%rcx,%rax), %edi
	addl	%esi, %edi
	addl	-200(%rbp), %edx
	imull	52(%rcx,%rax), %edx
	addl	%edi, %edx
	movl	%edx, -244(%rbp)
	movsd	-224(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	%xmm1, %xmm0
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-232(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_0(%rip), %xmm0
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_0(%rip), %xmm0
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -256(%rbp)
	movsd	-224(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_0(%rip), %xmm1  # xmm1 = mem[0],zero
	subsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -264(%rbp)
	movsd	-232(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -272(%rbp)
	movsd	-240(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	%xmm0, -280(%rbp)
	movabsq	$4611686018427387904, %rax # imm = 0x4000000000000000
	movq	%rax, -288(%rbp)
	movq	%rax, -296(%rbp)
	movq	%rax, -304(%rbp)
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	callq	pow
	movsd	%xmm0, -312(%rbp)
	movsd	-264(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -320(%rbp)
	movsd	-272(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -328(%rbp)
	movsd	-280(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -336(%rbp)
	movsd	-288(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-264(%rbp), %xmm0       # xmm0 = mem[0],zero
	movapd	%xmm0, %xmm2
	movsd	.LCPI78_3(%rip), %xmm1  # xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm2
	mulsd	%xmm0, %xmm2
	movsd	%xmm2, -480(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_4(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -344(%rbp)
	movsd	-296(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-272(%rbp), %xmm0       # xmm0 = mem[0],zero
	movapd	%xmm0, %xmm1
	mulsd	.LCPI78_3(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -480(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_4(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -352(%rbp)
	movsd	-304(%rbp), %xmm0       # xmm0 = mem[0],zero
	mulsd	.LCPI78_0(%rip), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_2(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-280(%rbp), %xmm0       # xmm0 = mem[0],zero
	movapd	%xmm0, %xmm1
	mulsd	.LCPI78_3(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -480(%rbp)       # 8-byte Spill
	movsd	-256(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	.LCPI78_4(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -360(%rbp)
	movabsq	$4607182418800017408, %rax # imm = 0x3FF0000000000000
	movq	%rax, -368(%rbp)
	movq	-496(%rbp), %rax        # 8-byte Reload
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movq	%r15, %r12
	movq	-504(%rbp), %r15        # 8-byte Reload
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	-312(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_3(%rip), %xmm0
	movq	-512(%rbp), %r14        # 8-byte Reload
	mulsd	(%r14), %xmm0
	callq	tanh
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -376(%rbp)
	movsd	(%r14), %xmm1           # xmm1 = mem[0],zero
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	mulsd	-320(%rbp), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-312(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	callq	tanh
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	movsd	.LCPI78_5(%rip), %xmm1  # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	mulsd	-472(%rbp), %xmm1       # 8-byte Folded Reload
	movsd	%xmm1, -384(%rbp)
	movsd	(%r14), %xmm1           # xmm1 = mem[0],zero
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	mulsd	-328(%rbp), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-312(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	callq	tanh
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	movsd	.LCPI78_5(%rip), %xmm1  # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	mulsd	-472(%rbp), %xmm1       # 8-byte Folded Reload
	movsd	%xmm1, -392(%rbp)
	movsd	(%r14), %xmm1           # xmm1 = mem[0],zero
	movsd	(%r15), %xmm0           # xmm0 = mem[0],zero
	movq	%r12, %r15
	movq	-520(%rbp), %r14        # 8-byte Reload
	mulsd	%xmm1, %xmm0
	mulsd	-336(%rbp), %xmm0
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	-312(%rbp), %xmm0       # xmm0 = mem[0],zero
	subsd	.LCPI78_3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	callq	tanh
	movsd	.LCPI78_1(%rip), %xmm1  # xmm1 = mem[0],zero
	callq	pow
	movsd	.LCPI78_5(%rip), %xmm1  # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	mulsd	-472(%rbp), %xmm1       # 8-byte Folded Reload
	movsd	%xmm1, -400(%rbp)
	movq	-528(%rbp), %r12        # 8-byte Reload
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	mulsd	-256(%rbp), %xmm0
	callq	exp
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -408(%rbp)
	movsd	(%r12), %xmm1           # xmm1 = mem[0],zero
	movsd	-264(%rbp), %xmm2       # xmm2 = mem[0],zero
	mulsd	%xmm1, %xmm2
	mulsd	%xmm0, %xmm2
	movsd	%xmm2, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm1
	movapd	%xmm1, %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -416(%rbp)
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	movsd	-272(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	mulsd	-408(%rbp), %xmm1
	movsd	%xmm1, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm1           # xmm1 = mem[0],zero
	movsd	%xmm1, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -424(%rbp)
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	movsd	-280(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	mulsd	-408(%rbp), %xmm1
	movsd	%xmm1, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm1           # xmm1 = mem[0],zero
	movsd	%xmm1, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -432(%rbp)
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	movsd	-288(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	mulsd	-408(%rbp), %xmm1
	movsd	-264(%rbp), %xmm3       # xmm3 = mem[0],zero
	mulsd	%xmm0, %xmm3
	movsd	-416(%rbp), %xmm2       # xmm2 = mem[0],zero
	mulsd	%xmm3, %xmm2
	addsd	%xmm1, %xmm2
	movsd	%xmm2, -472(%rbp)       # 8-byte Spill
	mulsd	(%r13), %xmm3
	movsd	%xmm3, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -440(%rbp)
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	movsd	-296(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	mulsd	-408(%rbp), %xmm1
	movsd	-272(%rbp), %xmm3       # xmm3 = mem[0],zero
	mulsd	%xmm0, %xmm3
	movsd	-424(%rbp), %xmm2       # xmm2 = mem[0],zero
	mulsd	%xmm3, %xmm2
	addsd	%xmm1, %xmm2
	movsd	%xmm2, -472(%rbp)       # 8-byte Spill
	mulsd	(%r13), %xmm3
	movsd	%xmm3, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -448(%rbp)
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	movsd	-304(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	mulsd	-408(%rbp), %xmm1
	movsd	-280(%rbp), %xmm3       # xmm3 = mem[0],zero
	mulsd	%xmm0, %xmm3
	movsd	-432(%rbp), %xmm2       # xmm2 = mem[0],zero
	mulsd	%xmm3, %xmm2
	addsd	%xmm1, %xmm2
	movsd	%xmm2, -472(%rbp)       # 8-byte Spill
	mulsd	(%r13), %xmm3
	movsd	%xmm3, -480(%rbp)       # 8-byte Spill
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	cos
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	addsd	-472(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -472(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	%xmm0, %xmm0
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r12), %xmm0           # xmm0 = mem[0],zero
	mulsd	-256(%rbp), %xmm0
	callq	exp
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-224(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-232(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	%xmm0, -480(%rbp)       # 8-byte Spill
	movsd	(%r13), %xmm0           # xmm0 = mem[0],zero
	mulsd	-240(%rbp), %xmm0
	callq	sin
	mulsd	-480(%rbp), %xmm0       # 8-byte Folded Reload
	movsd	-472(%rbp), %xmm1       # 8-byte Reload
                                        # xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -456(%rbp)
	movapd	%xmm1, %xmm3
	movq	-536(%rbp), %rax        # 8-byte Reload
	movsd	(%rax), %xmm0           # xmm0 = mem[0],zero
	mulsd	-368(%rbp), %xmm0
	mulsd	-408(%rbp), %xmm0
	movsd	-384(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	-416(%rbp), %xmm1
	movsd	-392(%rbp), %xmm2       # xmm2 = mem[0],zero
	mulsd	-424(%rbp), %xmm2
	addsd	%xmm1, %xmm2
	movsd	-400(%rbp), %xmm1       # xmm1 = mem[0],zero
	mulsd	-432(%rbp), %xmm1
	addsd	%xmm2, %xmm1
	movsd	-440(%rbp), %xmm2       # xmm2 = mem[0],zero
	addsd	-448(%rbp), %xmm2
	addsd	%xmm3, %xmm2
	mulsd	-376(%rbp), %xmm2
	addsd	%xmm1, %xmm2
	movq	64(%rbp), %rax
	mulsd	(%rax), %xmm2
	subsd	%xmm2, %xmm0
	movsd	%xmm0, -464(%rbp)
	movsd	-368(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-244(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	16(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	movsd	-376(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-244(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	24(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	movsd	-408(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-244(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	88(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	movsd	-464(%rbp), %xmm0       # xmm0 = mem[0],zero
	movslq	-244(%rbp), %rax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	movq	176(%rdx,%rcx), %rcx
	movq	8(%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-208(%rbp)
.LBB78_8:                               # %for.cond
                                        #   Parent Loop BB78_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-208(%rbp), %eax
	movslq	(%r14), %rcx
	movslq	(%r15), %rdx
	movq	(%rbx), %rsi
	movq	1776(%rsi), %rsi
	shlq	$8, %rdx
	movq	248(%rsi,%rdx), %rdx
	imulq	$216, %rcx, %rcx
	cmpl	20(%rdx,%rcx), %eax
	jl	.LBB78_9
	jmp	.LBB78_10
.LBB78_11:                              # %omp.loop.exit
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	movl	$.L__unnamed_1, %edi
	callq	__kmpc_for_static_fini
.LBB78_12:                              # %omp.precond.end
	addq	$568, %rsp              # imm = 0x238
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end78:
	.size	.omp_outlined..54, .Lfunc_end78-.omp_outlined..54
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"PlaceHolder \n\n"
	.size	.L.str, 15

	.type	.Lexchange_boundary.edges,@object # @exchange_boundary.edges
	.section	.rodata,"a",@progbits
	.align	16
.Lexchange_boundary.edges:
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.size	.Lexchange_boundary.edges, 108

	.type	.Lexchange_boundary.corners,@object # @exchange_boundary.corners
	.align	16
.Lexchange_boundary.corners:
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	0                       # 0x0
	.long	1                       # 0x1
	.long	0                       # 0x0
	.long	1                       # 0x1
	.size	.Lexchange_boundary.corners, 108

	.type	.L.str.1,@object        # @.str.1
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.1:
	.asciz	";unknown;unknown;0;0;;"
	.size	.L.str.1, 23

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata,"a",@progbits
	.align	8
.L__unnamed_1:
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str.1
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
	.quad	.L.str.1
	.size	.L__unnamed_2, 24

	.type	.L.str.5,@object        # @.str.5
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.5:
	.asciz	"\n"
	.size	.L.str.5, 2

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"  level=%2d, eigenvalue_max ~= %e\n"
	.size	.L.str.6, 35

	.type	.L.str.55,@object       # @.str.55
.L.str.55:
	.asciz	"\n  average value of f = %20.12e\n"
	.size	.L.str.55, 33


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
