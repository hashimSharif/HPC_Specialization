	.text
	.file	"mg.bc"
	.globl	create_subdomain
	.align	16, 0x90
	.type	create_subdomain,@function
create_subdomain:                       # @create_subdomain
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
	movl	40(%rbp), %r10d
	movl	32(%rbp), %r11d
	movl	24(%rbp), %eax
	movl	16(%rbp), %ebx
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movl	%edx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	%r8d, -32(%rbp)
	movl	%r9d, -36(%rbp)
	movl	%ebx, -40(%rbp)
	movl	%eax, -44(%rbp)
	movl	%r11d, -48(%rbp)
	movl	%r10d, -52(%rbp)
	movq	$0, -64(%rbp)
	movl	-52(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 24(%rcx)
	movl	-48(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 28(%rcx)
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, (%rcx)
	movl	-24(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 4(%rcx)
	movl	-28(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 8(%rcx)
	movl	-32(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 12(%rcx)
	movl	-36(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 16(%rcx)
	movl	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 20(%rcx)
	movl	$248, %edi
	addq	-16(%rbp), %rdi
	movslq	-52(%rbp), %rax
	imulq	$216, %rax, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movslq	-52(%rbp), %rax
	imulq	$216, %rax, %rax
	addq	%rax, -64(%rbp)
	movl	$0, -56(%rbp)
	jmp	.LBB0_1
	.align	16, 0x90
.LBB0_4:                                # %for.inc
                                        #   in Loop: Header=BB0_1 Depth=1
	movslq	-56(%rbp), %rcx
	movq	-16(%rbp), %rax
	imulq	$216, %rcx, %rdi
	addq	248(%rax), %rdi
	movl	-68(%rbp), %esi
	movl	-20(%rbp), %edx
	sarl	%cl, %edx
	movl	-24(%rbp), %r10d
	sarl	%cl, %r10d
	movl	-28(%rbp), %r8d
	sarl	%cl, %r8d
	movl	-32(%rbp), %r9d
	sarl	%cl, %r9d
	movl	-36(%rbp), %ebx
	sarl	%cl, %ebx
	movl	-40(%rbp), %eax
	sarl	%cl, %eax
	movl	-48(%rbp), %ecx
	movl	%ecx, 16(%rsp)
	movl	%eax, 8(%rsp)
	movl	%ebx, (%rsp)
	movl	%r10d, %ecx
	callq	create_box
	cltq
	addq	%rax, -64(%rbp)
	incl	-56(%rbp)
.LBB0_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-56(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jge	.LBB0_5
# BB#2:                                 # %for.body
                                        #   in Loop: Header=BB0_1 Depth=1
	movl	-44(%rbp), %eax
	movl	%eax, -68(%rbp)
	movl	-52(%rbp), %eax
	decl	%eax
	cmpl	%eax, -56(%rbp)
	jne	.LBB0_4
# BB#3:                                 # %if.then
                                        #   in Loop: Header=BB0_1 Depth=1
	xorl	%eax, %eax
	callq	IterativeSolver_NumGrids
	addl	%eax, -68(%rbp)
	jmp	.LBB0_4
.LBB0_5:                                # %for.end
	movl	-64(%rbp), %eax
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	create_subdomain, .Lfunc_end0-create_subdomain
	.cfi_endproc

	.globl	destroy_subdomain
	.align	16, 0x90
	.type	destroy_subdomain,@function
destroy_subdomain:                      # @destroy_subdomain
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
	movl	$0, -12(%rbp)
	jmp	.LBB1_1
	.align	16, 0x90
.LBB1_2:                                # %for.body
                                        #   in Loop: Header=BB1_1 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	imulq	$216, %rax, %rdi
	addq	248(%rcx), %rdi
	callq	destroy_box
	incl	-12(%rbp)
.LBB1_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	24(%rcx), %eax
	jl	.LBB1_2
# BB#3:                                 # %for.end
	movq	-8(%rbp), %rax
	movq	248(%rax), %rdi
	callq	free
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	destroy_subdomain, .Lfunc_end1-destroy_subdomain
	.cfi_endproc

	.globl	calculate_neighboring_subdomain_index
	.align	16, 0x90
	.type	calculate_neighboring_subdomain_index,@function
calculate_neighboring_subdomain_index:  # @calculate_neighboring_subdomain_index
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp7:
	.cfi_def_cfa_offset 16
.Ltmp8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp9:
	.cfi_def_cfa_register %rbp
	movl	16(%rbp), %eax
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	%r8d, -24(%rbp)
	movl	%r9d, -28(%rbp)
	movl	%eax, -32(%rbp)
	movq	-8(%rbp), %rax
	movl	1560(%rax), %ecx
	movl	-12(%rbp), %eax
	addl	%ecx, %eax
	addl	-24(%rbp), %eax
	cltd
	idivl	%ecx
	movl	%edx, -36(%rbp)
	movq	-8(%rbp), %rax
	movl	1564(%rax), %ecx
	movl	-16(%rbp), %eax
	addl	%ecx, %eax
	addl	-28(%rbp), %eax
	cltd
	idivl	%ecx
	movl	%edx, -40(%rbp)
	movq	-8(%rbp), %rax
	movl	1568(%rax), %ecx
	movl	-20(%rbp), %eax
	addl	%ecx, %eax
	addl	-32(%rbp), %eax
	cltd
	idivl	%ecx
	movl	%edx, -44(%rbp)
	movq	-8(%rbp), %rax
	movl	1560(%rax), %ecx
	imull	%ecx, %edx
	imull	-40(%rbp), %ecx
	addl	-36(%rbp), %ecx
	imull	1564(%rax), %edx
	addl	%ecx, %edx
	movl	%edx, -48(%rbp)
	movl	%edx, %eax
	popq	%rbp
	retq
.Lfunc_end2:
	.size	calculate_neighboring_subdomain_index, .Lfunc_end2-calculate_neighboring_subdomain_index
	.cfi_endproc

	.globl	calculate_neighboring_subdomain_rank
	.align	16, 0x90
	.type	calculate_neighboring_subdomain_rank,@function
calculate_neighboring_subdomain_rank:   # @calculate_neighboring_subdomain_rank
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp10:
	.cfi_def_cfa_offset 16
.Ltmp11:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp12:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
.Ltmp13:
	.cfi_offset %rbx, -24
	movl	40(%rbp), %r10d
	movl	32(%rbp), %r11d
	movl	24(%rbp), %eax
	movl	16(%rbp), %ebx
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	%ecx, -36(%rbp)
	movl	%r8d, -40(%rbp)
	movl	%r9d, -44(%rbp)
	movl	%ebx, -48(%rbp)
	movl	%eax, -52(%rbp)
	movl	%r11d, -56(%rbp)
	movl	%r10d, -60(%rbp)
	movq	-24(%rbp), %rax
	cmpl	$0, 1584(%rax)
	je	.LBB3_5
# BB#1:                                 # %if.then
	movq	-24(%rbp), %rax
	movl	1560(%rax), %eax
	imull	-52(%rbp), %eax
	addl	-28(%rbp), %eax
	addl	-40(%rbp), %eax
	js	.LBB3_2
# BB#3:                                 # %if.end
	movq	-24(%rbp), %rax
	movl	1560(%rax), %ecx
	imull	-52(%rbp), %ecx
	addl	-28(%rbp), %ecx
	addl	-40(%rbp), %ecx
	cmpl	1572(%rax), %ecx
	jl	.LBB3_5
# BB#4:                                 # %if.then12
	movl	$-1, -12(%rbp)
	jmp	.LBB3_28
.LBB3_5:                                # %if.end14
	movq	-24(%rbp), %rax
	cmpl	$0, 1588(%rax)
	je	.LBB3_10
# BB#6:                                 # %if.then17
	movq	-24(%rbp), %rax
	movl	1564(%rax), %eax
	imull	-56(%rbp), %eax
	addl	-32(%rbp), %eax
	addl	-44(%rbp), %eax
	js	.LBB3_7
# BB#8:                                 # %if.end25
	movq	-24(%rbp), %rax
	movl	1564(%rax), %ecx
	imull	-56(%rbp), %ecx
	addl	-32(%rbp), %ecx
	addl	-44(%rbp), %ecx
	cmpl	1576(%rax), %ecx
	jl	.LBB3_10
# BB#9:                                 # %if.then34
	movl	$-1, -12(%rbp)
	jmp	.LBB3_28
.LBB3_10:                               # %if.end36
	movq	-24(%rbp), %rax
	cmpl	$0, 1592(%rax)
	je	.LBB3_15
# BB#11:                                # %if.then39
	movq	-24(%rbp), %rax
	movl	1568(%rax), %eax
	imull	-60(%rbp), %eax
	addl	-36(%rbp), %eax
	addl	-48(%rbp), %eax
	js	.LBB3_12
# BB#13:                                # %if.end47
	movq	-24(%rbp), %rax
	movl	1568(%rax), %ecx
	imull	-60(%rbp), %ecx
	addl	-36(%rbp), %ecx
	addl	-48(%rbp), %ecx
	cmpl	1580(%rax), %ecx
	jl	.LBB3_15
# BB#14:                                # %if.then56
	movl	$-1, -12(%rbp)
	jmp	.LBB3_28
.LBB3_2:                                # %if.then4
	movl	$-1, -12(%rbp)
	jmp	.LBB3_28
.LBB3_15:                               # %if.end58
	movl	-28(%rbp), %eax
	addl	-40(%rbp), %eax
	jns	.LBB3_17
# BB#16:                                # %if.then61
	decl	-52(%rbp)
.LBB3_17:                               # %if.end62
	movl	-28(%rbp), %eax
	addl	-40(%rbp), %eax
	movq	-24(%rbp), %rcx
	cmpl	1560(%rcx), %eax
	jl	.LBB3_19
# BB#18:                                # %if.then67
	incl	-52(%rbp)
.LBB3_19:                               # %if.end68
	movq	-24(%rbp), %rax
	movl	1548(%rax), %ecx
	movl	-52(%rbp), %eax
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -52(%rbp)
	movl	-32(%rbp), %eax
	addl	-44(%rbp), %eax
	jns	.LBB3_21
# BB#20:                                # %if.then75
	decl	-56(%rbp)
.LBB3_21:                               # %if.end77
	movl	-32(%rbp), %eax
	addl	-44(%rbp), %eax
	movq	-24(%rbp), %rcx
	cmpl	1564(%rcx), %eax
	jl	.LBB3_23
# BB#22:                                # %if.then82
	incl	-56(%rbp)
.LBB3_23:                               # %if.end84
	movq	-24(%rbp), %rax
	movl	1552(%rax), %ecx
	movl	-56(%rbp), %eax
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -56(%rbp)
	movl	-36(%rbp), %eax
	addl	-48(%rbp), %eax
	jns	.LBB3_25
# BB#24:                                # %if.then93
	decl	-60(%rbp)
.LBB3_25:                               # %if.end95
	movl	-36(%rbp), %eax
	addl	-48(%rbp), %eax
	movq	-24(%rbp), %rcx
	cmpl	1568(%rcx), %eax
	jl	.LBB3_27
# BB#26:                                # %if.then100
	incl	-60(%rbp)
.LBB3_27:                               # %if.end102
	movq	-24(%rbp), %rax
	movl	1556(%rax), %ecx
	movl	-60(%rbp), %eax
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -60(%rbp)
	movq	-24(%rbp), %rax
	movl	1548(%rax), %ecx
	imull	%ecx, %edx
	imull	-56(%rbp), %ecx
	addl	-52(%rbp), %ecx
	imull	1552(%rax), %edx
	addl	%ecx, %edx
	movl	%edx, -64(%rbp)
	movl	%edx, -12(%rbp)
	jmp	.LBB3_28
.LBB3_7:                                # %if.then24
	movl	$-1, -12(%rbp)
	jmp	.LBB3_28
.LBB3_12:                               # %if.then46
	movl	$-1, -12(%rbp)
.LBB3_28:                               # %return
	movl	-12(%rbp), %eax
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end3:
	.size	calculate_neighboring_subdomain_rank, .Lfunc_end3-calculate_neighboring_subdomain_rank
	.cfi_endproc

	.globl	create_domain
	.align	16, 0x90
	.type	create_domain,@function
create_domain:                          # @create_domain
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp14:
	.cfi_def_cfa_offset 16
.Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp16:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$712, %rsp              # imm = 0x2C8
.Ltmp17:
	.cfi_offset %rbx, -24
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movl	%edx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	%r8d, -32(%rbp)
	movl	80(%rbp), %eax
	movl	%r9d, -36(%rbp)
	movl	16(%rbp), %ecx
	movl	%ecx, -40(%rbp)
	movl	24(%rbp), %ecx
	movl	%ecx, -44(%rbp)
	movl	32(%rbp), %ecx
	movl	%ecx, -48(%rbp)
	movl	40(%rbp), %ecx
	movl	%ecx, -52(%rbp)
	movl	48(%rbp), %ecx
	movl	%ecx, -56(%rbp)
	movq	56(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movl	64(%rbp), %ecx
	movl	%ecx, -68(%rbp)
	movl	72(%rbp), %ecx
	movl	%ecx, -72(%rbp)
	movl	%eax, -76(%rbp)
	movl	-56(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1596(%rcx)
	movq	-16(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB4_2
# BB#1:                                 # %if.then
	movl	$.L.str, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB4_2:                                # %if.end
	movl	-20(%rbp), %eax
	movl	-76(%rbp), %ecx
	decl	%ecx
	sarl	%cl, %eax
	cmpl	%eax, -72(%rbp)
	jg	.LBB4_3
# BB#6:                                 # %if.end13
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	.LBB4_9
# BB#7:                                 # %lor.lhs.false
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.LBB4_9
# BB#8:                                 # %lor.lhs.false16
	movl	-20(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.LBB4_9
# BB#12:                                # %if.end24
	movq	$0, -112(%rbp)
	movl	-56(%rbp), %eax
	movl	-44(%rbp), %ecx
	imull	-48(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -116(%rbp)
	movl	-56(%rbp), %ecx
	movl	-44(%rbp), %esi
	movl	-48(%rbp), %edx
	imull	%esi, %edx
	imull	%eax, %edx
	subl	%edx, %ecx
	movl	%ecx, %eax
	cltd
	idivl	%esi
	movl	%eax, -120(%rbp)
	movl	-56(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %esi
	imull	%edx, %esi
	imull	-116(%rbp), %esi
	subl	%esi, %ecx
	imull	%eax, %edx
	subl	%edx, %ecx
	movl	%ecx, -124(%rbp)
	movl	-44(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1548(%rcx)
	movl	-48(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1552(%rcx)
	movl	-52(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1556(%rcx)
	movl	-32(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1560(%rcx)
	movl	-36(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1564(%rcx)
	movl	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1568(%rcx)
	movl	-32(%rbp), %eax
	imull	-44(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1572(%rcx)
	movl	-36(%rbp), %eax
	imull	-48(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1576(%rcx)
	movl	-40(%rbp), %eax
	imull	-52(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1580(%rcx)
	movl	-32(%rbp), %eax
	imull	-36(%rbp), %eax
	imull	-40(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1600(%rcx)
	movq	-16(%rbp), %rdi
	movslq	1600(%rdi), %rdx
	addq	$1776, %rdi             # imm = 0x6F0
	shlq	$8, %rdx
	movl	$64, %esi
	callq	posix_memalign
	movq	-16(%rbp), %rax
	movslq	1600(%rax), %rax
	shlq	$8, %rax
	addq	%rax, -112(%rbp)
	movq	-16(%rbp), %rax
	movl	1572(%rax), %ecx
	imull	-20(%rbp), %ecx
	movl	%ecx, 1536(%rax)
	movq	-16(%rbp), %rax
	movl	1576(%rax), %ecx
	imull	-24(%rbp), %ecx
	movl	%ecx, 1540(%rax)
	movq	-16(%rbp), %rax
	movl	1580(%rax), %ecx
	imull	-28(%rbp), %ecx
	movl	%ecx, 1544(%rax)
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1584(%rcx)
	movq	-64(%rbp), %rax
	movl	4(%rax), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1588(%rcx)
	movq	-64(%rbp), %rax
	movl	8(%rax), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1592(%rcx)
	movl	-76(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1604(%rcx)
	movl	-68(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1608(%rcx)
	movl	-72(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1612(%rcx)
	movl	$0, -80(%rbp)
	movabsq	$-4616189618054758400, %rax # imm = 0xBFF0000000000000
	jmp	.LBB4_13
	.align	16, 0x90
.LBB4_14:                               # %for.inc
                                        #   in Loop: Header=BB4_13 Depth=1
	movslq	-80(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	%rax, 1616(%rdx,%rcx,8)
	movslq	-80(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	%rax, 1696(%rdx,%rcx,8)
	incl	-80(%rbp)
.LBB4_13:                               # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-80(%rbp), %ecx
	movq	-16(%rbp), %rdx
	cmpl	1604(%rdx), %ecx
	jl	.LBB4_14
# BB#15:                                # %for.end
	movl	$-1, -104(%rbp)
	jmp	.LBB4_16
	.align	16, 0x90
.LBB4_38:                               # %for.inc194
                                        #   in Loop: Header=BB4_16 Depth=1
	incl	-104(%rbp)
.LBB4_16:                               # %for.cond90
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB4_18 Depth 2
                                        #       Child Loop BB4_20 Depth 3
	cmpl	$1, -104(%rbp)
	jg	.LBB4_39
# BB#17:                                # %for.body93
                                        #   in Loop: Header=BB4_16 Depth=1
	movl	$-1, -100(%rbp)
	jmp	.LBB4_18
	.align	16, 0x90
.LBB4_37:                               # %for.inc191
                                        #   in Loop: Header=BB4_18 Depth=2
	incl	-100(%rbp)
.LBB4_18:                               # %for.cond94
                                        #   Parent Loop BB4_16 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB4_20 Depth 3
	cmpl	$1, -100(%rbp)
	jg	.LBB4_38
# BB#19:                                # %for.body97
                                        #   in Loop: Header=BB4_18 Depth=2
	movl	$-1, -96(%rbp)
	jmp	.LBB4_20
	.align	16, 0x90
.LBB4_36:                               # %for.inc188
                                        #   in Loop: Header=BB4_20 Depth=3
	incl	-96(%rbp)
.LBB4_20:                               # %for.cond98
                                        #   Parent Loop BB4_16 Depth=1
                                        #     Parent Loop BB4_18 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	cmpl	$1, -96(%rbp)
	jg	.LBB4_37
# BB#21:                                # %for.body101
                                        #   in Loop: Header=BB4_20 Depth=3
	imull	$3, -100(%rbp), %eax
	addl	-96(%rbp), %eax
	imull	$9, -104(%rbp), %ecx
	leal	13(%rax,%rcx), %eax
	movl	%eax, -128(%rbp)
	movl	-124(%rbp), %eax
	addl	-96(%rbp), %eax
	movl	-44(%rbp), %ecx
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -132(%rbp)
	movl	-120(%rbp), %eax
	addl	-100(%rbp), %eax
	movl	-48(%rbp), %ecx
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -136(%rbp)
	movl	-116(%rbp), %eax
	addl	-104(%rbp), %eax
	movl	-52(%rbp), %ecx
	addl	%ecx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -140(%rbp)
	movl	-44(%rbp), %eax
	movl	-136(%rbp), %ecx
	imull	%eax, %ecx
	addl	-132(%rbp), %ecx
	imull	-48(%rbp), %eax
	imull	%edx, %eax
	addl	%ecx, %eax
	movslq	-128(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movl	%eax, 1320(%rdx,%rcx,4)
	movq	-16(%rbp), %rax
	cmpl	$0, 1584(%rax)
	je	.LBB4_26
# BB#22:                                # %if.then126
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-124(%rbp), %eax
	addl	-96(%rbp), %eax
	jns	.LBB4_24
# BB#23:                                # %if.then130
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
.LBB4_24:                               # %if.end134
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-124(%rbp), %eax
	addl	-96(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.LBB4_26
# BB#25:                                # %if.then138
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
.LBB4_26:                               # %if.end143
                                        #   in Loop: Header=BB4_20 Depth=3
	movq	-16(%rbp), %rax
	cmpl	$0, 1588(%rax)
	je	.LBB4_31
# BB#27:                                # %if.then148
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-120(%rbp), %eax
	addl	-100(%rbp), %eax
	jns	.LBB4_29
# BB#28:                                # %if.then152
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
.LBB4_29:                               # %if.end156
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-120(%rbp), %eax
	addl	-100(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.LBB4_31
# BB#30:                                # %if.then160
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
.LBB4_31:                               # %if.end165
                                        #   in Loop: Header=BB4_20 Depth=3
	movq	-16(%rbp), %rax
	cmpl	$0, 1592(%rax)
	je	.LBB4_36
# BB#32:                                # %if.then170
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-116(%rbp), %eax
	addl	-104(%rbp), %eax
	jns	.LBB4_34
# BB#33:                                # %if.then174
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
.LBB4_34:                               # %if.end178
                                        #   in Loop: Header=BB4_20 Depth=3
	movl	-116(%rbp), %eax
	addl	-104(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.LBB4_36
# BB#35:                                # %if.then182
                                        #   in Loop: Header=BB4_20 Depth=3
	movslq	-128(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$-1, 1320(%rcx,%rax,4)
	jmp	.LBB4_36
.LBB4_39:                               # %for.end196
	movl	$0, -92(%rbp)
	jmp	.LBB4_40
	.align	16, 0x90
.LBB4_56:                               # %for.inc276
                                        #   in Loop: Header=BB4_40 Depth=1
	incl	-92(%rbp)
.LBB4_40:                               # %for.cond197
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB4_42 Depth 2
                                        #       Child Loop BB4_44 Depth 3
                                        #         Child Loop BB4_46 Depth 4
                                        #           Child Loop BB4_48 Depth 5
                                        #             Child Loop BB4_50 Depth 6
	movl	-92(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jge	.LBB4_57
# BB#41:                                # %for.body200
                                        #   in Loop: Header=BB4_40 Depth=1
	movl	$0, -88(%rbp)
	jmp	.LBB4_42
	.align	16, 0x90
.LBB4_55:                               # %for.inc273
                                        #   in Loop: Header=BB4_42 Depth=2
	incl	-88(%rbp)
.LBB4_42:                               # %for.cond201
                                        #   Parent Loop BB4_40 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB4_44 Depth 3
                                        #         Child Loop BB4_46 Depth 4
                                        #           Child Loop BB4_48 Depth 5
                                        #             Child Loop BB4_50 Depth 6
	movl	-88(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	.LBB4_56
# BB#43:                                # %for.body204
                                        #   in Loop: Header=BB4_42 Depth=2
	movl	$0, -84(%rbp)
	jmp	.LBB4_44
	.align	16, 0x90
.LBB4_54:                               # %for.inc270
                                        #   in Loop: Header=BB4_44 Depth=3
	incl	-84(%rbp)
.LBB4_44:                               # %for.cond205
                                        #   Parent Loop BB4_40 Depth=1
                                        #     Parent Loop BB4_42 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB4_46 Depth 4
                                        #           Child Loop BB4_48 Depth 5
                                        #             Child Loop BB4_50 Depth 6
	movl	-84(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.LBB4_55
# BB#45:                                # %for.body208
                                        #   in Loop: Header=BB4_44 Depth=3
	movl	-32(%rbp), %eax
	movl	-88(%rbp), %ecx
	imull	%eax, %ecx
	addl	-84(%rbp), %ecx
	imull	-92(%rbp), %eax
	imull	-36(%rbp), %eax
	addl	%ecx, %eax
	movl	%eax, -144(%rbp)
	movl	-32(%rbp), %eax
	imull	-124(%rbp), %eax
	addl	-84(%rbp), %eax
	imull	-20(%rbp), %eax
	movl	%eax, -148(%rbp)
	movl	-36(%rbp), %eax
	imull	-120(%rbp), %eax
	addl	-88(%rbp), %eax
	imull	-24(%rbp), %eax
	movl	%eax, -152(%rbp)
	movl	-40(%rbp), %ecx
	imull	-116(%rbp), %ecx
	addl	-92(%rbp), %ecx
	imull	-28(%rbp), %ecx
	movl	%ecx, -156(%rbp)
	movslq	-144(%rbp), %rdi
	movq	-16(%rbp), %rax
	shlq	$8, %rdi
	addq	1776(%rax), %rdi
	movl	-148(%rbp), %esi
	movl	-152(%rbp), %edx
	movl	-20(%rbp), %r8d
	movl	-24(%rbp), %r9d
	movl	-28(%rbp), %r10d
	movl	-68(%rbp), %r11d
	movl	-72(%rbp), %eax
	movl	-76(%rbp), %ebx
	movl	%ebx, 24(%rsp)
	movl	%eax, 16(%rsp)
	movl	%r11d, 8(%rsp)
	movl	%r10d, (%rsp)
	callq	create_subdomain
	cltq
	addq	%rax, -112(%rbp)
	movl	$-1, -104(%rbp)
	jmp	.LBB4_46
	.align	16, 0x90
.LBB4_53:                               # %for.inc267
                                        #   in Loop: Header=BB4_46 Depth=4
	incl	-104(%rbp)
.LBB4_46:                               # %for.cond229
                                        #   Parent Loop BB4_40 Depth=1
                                        #     Parent Loop BB4_42 Depth=2
                                        #       Parent Loop BB4_44 Depth=3
                                        # =>      This Loop Header: Depth=4
                                        #           Child Loop BB4_48 Depth 5
                                        #             Child Loop BB4_50 Depth 6
	cmpl	$1, -104(%rbp)
	jg	.LBB4_54
# BB#47:                                # %for.body232
                                        #   in Loop: Header=BB4_46 Depth=4
	movl	$-1, -100(%rbp)
	jmp	.LBB4_48
	.align	16, 0x90
.LBB4_52:                               # %for.inc264
                                        #   in Loop: Header=BB4_48 Depth=5
	incl	-100(%rbp)
.LBB4_48:                               # %for.cond233
                                        #   Parent Loop BB4_40 Depth=1
                                        #     Parent Loop BB4_42 Depth=2
                                        #       Parent Loop BB4_44 Depth=3
                                        #         Parent Loop BB4_46 Depth=4
                                        # =>        This Loop Header: Depth=5
                                        #             Child Loop BB4_50 Depth 6
	cmpl	$1, -100(%rbp)
	jg	.LBB4_53
# BB#49:                                # %for.body236
                                        #   in Loop: Header=BB4_48 Depth=5
	movl	$-1, -96(%rbp)
	jmp	.LBB4_50
	.align	16, 0x90
.LBB4_51:                               # %for.inc261
                                        #   in Loop: Header=BB4_50 Depth=6
	imull	$3, -100(%rbp), %eax
	addl	-96(%rbp), %eax
	imull	$9, -104(%rbp), %ecx
	leal	13(%rax,%rcx), %eax
	movl	%eax, -160(%rbp)
	movq	-16(%rbp), %rdi
	movl	-84(%rbp), %esi
	movl	-88(%rbp), %edx
	movl	-92(%rbp), %ecx
	movl	-96(%rbp), %r8d
	movl	-100(%rbp), %r9d
	movl	-104(%rbp), %r10d
	movl	-124(%rbp), %r11d
	movl	-120(%rbp), %eax
	movl	-116(%rbp), %ebx
	movl	%ebx, 24(%rsp)
	movl	%eax, 16(%rsp)
	movl	%r11d, 8(%rsp)
	movl	%r10d, (%rsp)
	callq	calculate_neighboring_subdomain_rank
	movslq	-160(%rbp), %rcx
	movslq	-144(%rbp), %rdx
	movq	-16(%rbp), %rsi
	shlq	$8, %rdx
	addq	1776(%rsi), %rdx
	movl	%eax, 32(%rdx,%rcx,8)
	movq	-16(%rbp), %rdi
	movl	-84(%rbp), %esi
	movl	-88(%rbp), %edx
	movl	-92(%rbp), %ecx
	movl	-96(%rbp), %r8d
	movl	-100(%rbp), %r9d
	movl	-104(%rbp), %eax
	movl	%eax, (%rsp)
	callq	calculate_neighboring_subdomain_index
	movslq	-160(%rbp), %rcx
	movslq	-144(%rbp), %rdx
	movq	-16(%rbp), %rsi
	shlq	$8, %rdx
	addq	1776(%rsi), %rdx
	movl	%eax, 36(%rdx,%rcx,8)
	incl	-96(%rbp)
.LBB4_50:                               # %for.cond237
                                        #   Parent Loop BB4_40 Depth=1
                                        #     Parent Loop BB4_42 Depth=2
                                        #       Parent Loop BB4_44 Depth=3
                                        #         Parent Loop BB4_46 Depth=4
                                        #           Parent Loop BB4_48 Depth=5
                                        # =>          This Inner Loop Header: Depth=6
	cmpl	$1, -96(%rbp)
	jle	.LBB4_51
	jmp	.LBB4_52
.LBB4_57:                               # %for.end278
	movups	.Lcreate_domain.FacesEdgesCorners+92(%rip), %xmm0
	movups	%xmm0, -180(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners+80(%rip), %xmm0
	movaps	%xmm0, -192(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners+64(%rip), %xmm0
	movaps	%xmm0, -208(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners+48(%rip), %xmm0
	movaps	%xmm0, -224(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners+32(%rip), %xmm0
	movaps	%xmm0, -240(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners+16(%rip), %xmm0
	movaps	%xmm0, -256(%rbp)
	movaps	.Lcreate_domain.FacesEdgesCorners(%rip), %xmm0
	movaps	%xmm0, -272(%rbp)
	xorps	%xmm0, %xmm0
	movups	%xmm0, -292(%rbp)
	movaps	%xmm0, -304(%rbp)
	movaps	%xmm0, -320(%rbp)
	movaps	%xmm0, -336(%rbp)
	movaps	%xmm0, -352(%rbp)
	movaps	%xmm0, -368(%rbp)
	movaps	%xmm0, -384(%rbp)
	movl	$1, -368(%rbp)
	movl	$1, -344(%rbp)
	movl	$1, -336(%rbp)
	movl	$1, -328(%rbp)
	movl	$1, -320(%rbp)
	movl	$1, -296(%rbp)
	movups	.Lcreate_domain.edges+92(%rip), %xmm0
	movups	%xmm0, -404(%rbp)
	movaps	.Lcreate_domain.edges+80(%rip), %xmm0
	movaps	%xmm0, -416(%rbp)
	movaps	.Lcreate_domain.edges+64(%rip), %xmm0
	movaps	%xmm0, -432(%rbp)
	movaps	.Lcreate_domain.edges+48(%rip), %xmm0
	movaps	%xmm0, -448(%rbp)
	movaps	.Lcreate_domain.edges+32(%rip), %xmm0
	movaps	%xmm0, -464(%rbp)
	movaps	.Lcreate_domain.edges+16(%rip), %xmm0
	movaps	%xmm0, -480(%rbp)
	movaps	.Lcreate_domain.edges(%rip), %xmm0
	movaps	%xmm0, -496(%rbp)
	movups	.Lcreate_domain.corners+92(%rip), %xmm0
	movups	%xmm0, -516(%rbp)
	movaps	.Lcreate_domain.corners+80(%rip), %xmm0
	movaps	%xmm0, -528(%rbp)
	movaps	.Lcreate_domain.corners+64(%rip), %xmm0
	movaps	%xmm0, -544(%rbp)
	movaps	.Lcreate_domain.corners+48(%rip), %xmm0
	movaps	%xmm0, -560(%rbp)
	movaps	.Lcreate_domain.corners+32(%rip), %xmm0
	movaps	%xmm0, -576(%rbp)
	movaps	.Lcreate_domain.corners+16(%rip), %xmm0
	movaps	%xmm0, -592(%rbp)
	movaps	.Lcreate_domain.corners(%rip), %xmm0
	movaps	%xmm0, -608(%rbp)
	movl	$0, -80(%rbp)
	jmp	.LBB4_58
	.align	16, 0x90
.LBB4_100:                              # %for.inc738
                                        #   in Loop: Header=BB4_58 Depth=1
	incl	-80(%rbp)
.LBB4_58:                               # %for.cond279
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB4_60 Depth 2
                                        #       Child Loop BB4_62 Depth 3
                                        #         Child Loop BB4_64 Depth 4
                                        #           Child Loop BB4_66 Depth 5
                                        #             Child Loop BB4_68 Depth 6
	movl	-80(%rbp), %eax
	movq	-16(%rbp), %rcx
	cmpl	1604(%rcx), %eax
	jge	.LBB4_101
# BB#59:                                # %for.body283
                                        #   in Loop: Header=BB4_58 Depth=1
	movl	$0, -612(%rbp)
	jmp	.LBB4_60
	.align	16, 0x90
.LBB4_99:                               # %for.inc735
                                        #   in Loop: Header=BB4_60 Depth=2
	incl	-612(%rbp)
.LBB4_60:                               # %for.cond284
                                        #   Parent Loop BB4_58 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB4_62 Depth 3
                                        #         Child Loop BB4_64 Depth 4
                                        #           Child Loop BB4_66 Depth 5
                                        #             Child Loop BB4_68 Depth 6
	cmpl	$1, -612(%rbp)
	jg	.LBB4_100
# BB#61:                                # %for.body287
                                        #   in Loop: Header=BB4_60 Depth=2
	movl	$0, -616(%rbp)
	movq	-16(%rbp), %rax
	movl	$0, 1512(%rax)
	movl	-616(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1516(%rcx)
	movl	-616(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1520(%rcx)
	movl	$0, -620(%rbp)
	jmp	.LBB4_62
	.align	16, 0x90
.LBB4_96:                               # %for.inc719
                                        #   in Loop: Header=BB4_62 Depth=3
	incl	-620(%rbp)
.LBB4_62:                               # %for.cond288
                                        #   Parent Loop BB4_58 Depth=1
                                        #     Parent Loop BB4_60 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB4_64 Depth 4
                                        #           Child Loop BB4_66 Depth 5
                                        #             Child Loop BB4_68 Depth 6
	cmpl	$25, -620(%rbp)
	jg	.LBB4_97
# BB#63:                                # %for.body291
                                        #   in Loop: Header=BB4_62 Depth=3
	movslq	-620(%rbp), %rax
	movl	-272(%rbp,%rax,4), %eax
	movl	%eax, -624(%rbp)
	movslq	-624(%rbp), %rax
	imulq	$1431655766, %rax, %rcx # imm = 0x55555556
	movq	%rcx, %rdx
	shrq	$63, %rdx
	shrq	$32, %rcx
	addl	%edx, %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%ecx, %eax
	decl	%eax
	movl	%eax, -628(%rbp)
	movslq	-624(%rbp), %rax
	imulq	$1431655766, %rax, %rax # imm = 0x55555556
	movq	%rax, %rcx
	shrq	$63, %rcx
	shrq	$32, %rax
	addl	%ecx, %eax
	cltq
	imulq	$1431655766, %rax, %rcx # imm = 0x55555556
	movq	%rcx, %rdx
	shrq	$63, %rdx
	shrq	$32, %rcx
	addl	%edx, %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%ecx, %eax
	decl	%eax
	movl	%eax, -632(%rbp)
	movslq	-624(%rbp), %rax
	imulq	$954437177, %rax, %rax  # imm = 0x38E38E39
	movq	%rax, %rcx
	shrq	$63, %rcx
	shrq	$32, %rax
	sarl	%eax
	addl	%ecx, %eax
	cltq
	imulq	$1431655766, %rax, %rcx # imm = 0x55555556
	movq	%rcx, %rdx
	shrq	$63, %rdx
	shrq	$32, %rcx
	addl	%edx, %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%ecx, %eax
	decl	%eax
	movl	%eax, -636(%rbp)
	movl	$0, -92(%rbp)
	jmp	.LBB4_64
	.align	16, 0x90
.LBB4_95:                               # %for.inc716
                                        #   in Loop: Header=BB4_64 Depth=4
	incl	-92(%rbp)
.LBB4_64:                               # %for.cond307
                                        #   Parent Loop BB4_58 Depth=1
                                        #     Parent Loop BB4_60 Depth=2
                                        #       Parent Loop BB4_62 Depth=3
                                        # =>      This Loop Header: Depth=4
                                        #           Child Loop BB4_66 Depth 5
                                        #             Child Loop BB4_68 Depth 6
	movl	-92(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jge	.LBB4_96
# BB#65:                                # %for.body310
                                        #   in Loop: Header=BB4_64 Depth=4
	movl	$0, -88(%rbp)
	jmp	.LBB4_66
	.align	16, 0x90
.LBB4_94:                               # %for.inc713
                                        #   in Loop: Header=BB4_66 Depth=5
	incl	-88(%rbp)
.LBB4_66:                               # %for.cond311
                                        #   Parent Loop BB4_58 Depth=1
                                        #     Parent Loop BB4_60 Depth=2
                                        #       Parent Loop BB4_62 Depth=3
                                        #         Parent Loop BB4_64 Depth=4
                                        # =>        This Loop Header: Depth=5
                                        #             Child Loop BB4_68 Depth 6
	movl	-88(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	.LBB4_95
# BB#67:                                # %for.body314
                                        #   in Loop: Header=BB4_66 Depth=5
	movl	$0, -84(%rbp)
	jmp	.LBB4_68
	.align	16, 0x90
.LBB4_93:                               # %for.inc710
                                        #   in Loop: Header=BB4_68 Depth=6
	incl	-84(%rbp)
.LBB4_68:                               # %for.cond315
                                        #   Parent Loop BB4_58 Depth=1
                                        #     Parent Loop BB4_60 Depth=2
                                        #       Parent Loop BB4_62 Depth=3
                                        #         Parent Loop BB4_64 Depth=4
                                        #           Parent Loop BB4_66 Depth=5
                                        # =>          This Inner Loop Header: Depth=6
	movl	-84(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.LBB4_94
# BB#69:                                # %for.body318
                                        #   in Loop: Header=BB4_68 Depth=6
	movl	-32(%rbp), %eax
	movl	-88(%rbp), %ecx
	imull	%eax, %ecx
	addl	-84(%rbp), %ecx
	imull	-92(%rbp), %eax
	imull	-36(%rbp), %eax
	addl	%ecx, %eax
	movl	%eax, -640(%rbp)
	movl	$1, -644(%rbp)
	movq	-16(%rbp), %rdi
	movl	-84(%rbp), %esi
	movl	-88(%rbp), %edx
	movl	-92(%rbp), %ecx
	movl	-628(%rbp), %r8d
	movl	-632(%rbp), %r9d
	movl	-636(%rbp), %r10d
	movl	-124(%rbp), %r11d
	movl	-120(%rbp), %eax
	movl	-116(%rbp), %ebx
	movl	%ebx, 24(%rsp)
	movl	%eax, 16(%rsp)
	movl	%r11d, 8(%rsp)
	movl	%r10d, (%rsp)
	callq	calculate_neighboring_subdomain_rank
	movq	-16(%rbp), %rcx
	cmpl	1596(%rcx), %eax
	je	.LBB4_71
# BB#70:                                # %if.then328
                                        #   in Loop: Header=BB4_68 Depth=6
	movl	$0, -644(%rbp)
.LBB4_71:                               # %if.end329
                                        #   in Loop: Header=BB4_68 Depth=6
	cmpl	$0, -644(%rbp)
	je	.LBB4_93
# BB#72:                                # %if.then330
                                        #   in Loop: Header=BB4_68 Depth=6
	movq	-16(%rbp), %rdi
	movl	-84(%rbp), %esi
	movl	-88(%rbp), %edx
	movl	-92(%rbp), %ecx
	movl	-628(%rbp), %r8d
	movl	-632(%rbp), %r9d
	movl	-636(%rbp), %eax
	movl	%eax, (%rsp)
	callq	calculate_neighboring_subdomain_index
	movl	%eax, -648(%rbp)
	movl	-628(%rbp), %eax
	cmpl	$1, %eax
	je	.LBB4_77
# BB#73:                                # %if.then330
                                        #   in Loop: Header=BB4_68 Depth=6
	testl	%eax, %eax
	je	.LBB4_76
# BB#74:                                # %if.then330
                                        #   in Loop: Header=BB4_68 Depth=6
	cmpl	$-1, %eax
	jne	.LBB4_78
# BB#75:                                # %sw.bb
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -652(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -676(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %edx
	addl	20(%rcx,%rax), %edx
	movl	%edx, -664(%rbp)
	jmp	.LBB4_78
.LBB4_76:                               # %sw.bb361
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -652(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -676(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -664(%rbp)
	jmp	.LBB4_78
.LBB4_77:                               # %sw.bb384
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	20(%rcx,%rax), %eax
	movl	%eax, -652(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -676(%rbp)
	movl	$0, -664(%rbp)
.LBB4_78:                               # %sw.epilog
                                        #   in Loop: Header=BB4_68 Depth=6
	movl	-632(%rbp), %eax
	cmpl	$1, %eax
	je	.LBB4_83
# BB#79:                                # %sw.epilog
                                        #   in Loop: Header=BB4_68 Depth=6
	testl	%eax, %eax
	je	.LBB4_82
# BB#80:                                # %sw.epilog
                                        #   in Loop: Header=BB4_68 Depth=6
	cmpl	$-1, %eax
	jne	.LBB4_84
# BB#81:                                # %sw.bb400
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -656(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -680(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %edx
	addl	24(%rcx,%rax), %edx
	movl	%edx, -668(%rbp)
	jmp	.LBB4_84
.LBB4_82:                               # %sw.bb431
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -656(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -680(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -668(%rbp)
	jmp	.LBB4_84
.LBB4_83:                               # %sw.bb454
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	24(%rcx,%rax), %eax
	movl	%eax, -656(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -680(%rbp)
	movl	$0, -668(%rbp)
.LBB4_84:                               # %sw.epilog470
                                        #   in Loop: Header=BB4_68 Depth=6
	movl	-636(%rbp), %eax
	cmpl	$1, %eax
	je	.LBB4_89
# BB#85:                                # %sw.epilog470
                                        #   in Loop: Header=BB4_68 Depth=6
	testl	%eax, %eax
	je	.LBB4_88
# BB#86:                                # %sw.epilog470
                                        #   in Loop: Header=BB4_68 Depth=6
	cmpl	$-1, %eax
	jne	.LBB4_90
# BB#87:                                # %sw.bb471
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -660(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -684(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %edx
	addl	28(%rcx,%rax), %edx
	movl	%edx, -672(%rbp)
	jmp	.LBB4_90
.LBB4_88:                               # %sw.bb502
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -660(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -684(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -672(%rbp)
	jmp	.LBB4_90
.LBB4_89:                               # %sw.bb525
                                        #   in Loop: Header=BB4_68 Depth=6
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	28(%rcx,%rax), %eax
	movl	%eax, -660(%rbp)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movl	44(%rcx,%rax), %eax
	movl	%eax, -684(%rbp)
	movl	$0, -672(%rbp)
.LBB4_90:                               # %sw.epilog541
                                        #   in Loop: Header=BB4_68 Depth=6
	cmpl	$1, -612(%rbp)
	jne	.LBB4_92
# BB#91:                                # %if.then544
                                        #   in Loop: Header=BB4_68 Depth=6
	movl	-676(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 12(%rdx,%rcx)
	movl	-680(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 16(%rdx,%rcx)
	movl	-684(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 20(%rdx,%rcx)
	movl	-640(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 24(%rdx,%rcx)
	movslq	-616(%rbp), %rax
	movslq	-80(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movq	$0, 48(%rcx,%rax)
	movl	-652(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 28(%rdx,%rcx)
	movl	-656(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 32(%rdx,%rcx)
	movl	-660(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 36(%rdx,%rcx)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rsi
	shlq	$8, %rcx
	movq	248(%rsi,%rcx), %rcx
	imulq	$216, %rax, %rsi
	movl	48(%rcx,%rsi), %ecx
	movslq	-616(%rbp), %rsi
	movq	1432(%rdx,%rax,8), %rax
	imulq	$88, %rsi, %rdx
	movl	%ecx, 40(%rax,%rdx)
	movslq	-80(%rbp), %rax
	movslq	-640(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rsi
	shlq	$8, %rcx
	movq	248(%rsi,%rcx), %rcx
	imulq	$216, %rax, %rsi
	movl	52(%rcx,%rsi), %ecx
	movslq	-616(%rbp), %rsi
	movq	1432(%rdx,%rax,8), %rax
	imulq	$88, %rsi, %rdx
	movl	%ecx, 44(%rax,%rdx)
	movl	-648(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 56(%rdx,%rcx)
	movslq	-616(%rbp), %rax
	movslq	-80(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1432(%rdx,%rcx,8), %rcx
	imulq	$88, %rax, %rax
	movq	$0, 80(%rcx,%rax)
	movl	-664(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 60(%rdx,%rcx)
	movl	-668(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 64(%rdx,%rcx)
	movl	-672(%rbp), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 68(%rdx,%rcx)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rsi
	shlq	$8, %rcx
	movq	248(%rsi,%rcx), %rcx
	imulq	$216, %rax, %rsi
	movl	48(%rcx,%rsi), %ecx
	movslq	-616(%rbp), %rsi
	movq	1432(%rdx,%rax,8), %rax
	imulq	$88, %rsi, %rdx
	movl	%ecx, 72(%rax,%rdx)
	movslq	-80(%rbp), %rax
	movslq	-648(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	1776(%rdx), %rsi
	shlq	$8, %rcx
	movq	248(%rsi,%rcx), %rcx
	imulq	$216, %rax, %rsi
	movl	52(%rcx,%rsi), %ecx
	movslq	-616(%rbp), %rsi
	movq	1432(%rdx,%rax,8), %rax
	imulq	$88, %rsi, %rdx
	movl	%ecx, 76(%rax,%rdx)
	movslq	-624(%rbp), %rax
	movl	-384(%rbp,%rax,4), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, (%rdx,%rcx)
	movslq	-624(%rbp), %rax
	movl	-496(%rbp,%rax,4), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 4(%rdx,%rcx)
	movslq	-624(%rbp), %rax
	movl	-608(%rbp,%rax,4), %eax
	movslq	-616(%rbp), %rcx
	movslq	-80(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	1432(%rsi,%rdx,8), %rdx
	imulq	$88, %rcx, %rcx
	movl	%eax, 8(%rdx,%rcx)
.LBB4_92:                               # %if.end707
                                        #   in Loop: Header=BB4_68 Depth=6
	incl	-616(%rbp)
	jmp	.LBB4_93
	.align	16, 0x90
.LBB4_97:                               # %for.end721
                                        #   in Loop: Header=BB4_60 Depth=2
	movl	-616(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1524(%rcx)
	movl	-616(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1528(%rcx)
	movl	-616(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, 1532(%rcx)
	cmpl	$0, -612(%rbp)
	jne	.LBB4_99
# BB#98:                                # %if.then724
                                        #   in Loop: Header=BB4_60 Depth=2
	movslq	-616(%rbp), %rax
	imulq	$88, %rax, %rdi
	callq	malloc
	movslq	-80(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	%rax, 1432(%rdx,%rcx,8)
	movslq	-616(%rbp), %rax
	imulq	$88, %rax, %rax
	addq	%rax, -112(%rbp)
	jmp	.LBB4_99
.LBB4_101:                              # %for.end740
	movq	-16(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB4_103
# BB#102:                               # %if.then744
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %ecx
	movl	$.L.str.4, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-32(%rbp), %esi
	imull	-20(%rbp), %esi
	movl	-36(%rbp), %edx
	imull	-24(%rbp), %edx
	movl	-40(%rbp), %ecx
	imull	-28(%rbp), %ecx
	movl	$.L.str.5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-44(%rbp), %esi
	imull	-32(%rbp), %esi
	imull	-20(%rbp), %esi
	movl	-48(%rbp), %edx
	imull	-36(%rbp), %edx
	imull	-24(%rbp), %edx
	movl	-52(%rbp), %ecx
	imull	-40(%rbp), %ecx
	imull	-28(%rbp), %ecx
	movl	$.L.str.6, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-72(%rbp), %esi
	movl	$.L.str.7, %edi
	xorl	%eax, %eax
	callq	printf
	movq	-112(%rbp), %rsi
	shrq	$20, %rsi
	movl	$.L.str.8, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB4_103:                              # %if.end763
	movl	-112(%rbp), %eax
	addq	$712, %rsp              # imm = 0x2C8
	popq	%rbx
	popq	%rbp
	retq
.LBB4_9:                                # %if.then18
	movq	-16(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB4_11
# BB#10:                                # %if.then21
	movl	$.L.str.2, %edi
	xorl	%eax, %eax
	callq	printf
.LBB4_11:                               # %if.end23
	xorl	%edi, %edi
	callq	exit
.LBB4_3:                                # %if.then5
	movq	-16(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB4_5
# BB#4:                                 # %if.then8
	movl	-72(%rbp), %esi
	movl	-20(%rbp), %edx
	movl	-76(%rbp), %ecx
	decl	%ecx
	sarl	%cl, %edx
	movl	$.L.str.1, %edi
	xorl	%eax, %eax
	callq	printf
.LBB4_5:                                # %if.end12
	xorl	%edi, %edi
	callq	exit
.Lfunc_end4:
	.size	create_domain, .Lfunc_end4-create_domain
	.cfi_endproc

	.globl	destroy_domain
	.align	16, 0x90
	.type	destroy_domain,@function
destroy_domain:                         # @destroy_domain
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp18:
	.cfi_def_cfa_offset 16
.Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpl	$0, 1596(%rdi)
	jne	.LBB5_2
# BB#1:                                 # %if.then
	movl	$.L.str.9, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB5_2:                                # %if.end
	movl	$0, -12(%rbp)
	jmp	.LBB5_3
	.align	16, 0x90
.LBB5_4:                                # %for.body
                                        #   in Loop: Header=BB5_3 Depth=1
	movslq	-12(%rbp), %rdi
	movq	-8(%rbp), %rax
	shlq	$8, %rdi
	addq	1776(%rax), %rdi
	callq	destroy_subdomain
	incl	-12(%rbp)
.LBB5_3:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	1600(%rcx), %eax
	jl	.LBB5_4
# BB#5:                                 # %for.end
	movq	-8(%rbp), %rax
	movq	1776(%rax), %rdi
	callq	free
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB5_7
# BB#6:                                 # %if.then6
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB5_7:                                # %if.end9
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end5:
	.size	destroy_domain, .Lfunc_end5-destroy_domain
	.cfi_endproc

	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI6_0:
	.long	1127219200              # 0x43300000
	.long	1160773632              # 0x45300000
	.long	0                       # 0x0
	.long	0                       # 0x0
.LCPI6_1:
	.quad	4841369599423283200     # double 4503599627370496
	.quad	4985484787499139072     # double 1.9342813113834067E+25
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI6_2:
	.quad	4607182418800017408     # double 1
	.text
	.globl	print_timing
	.align	16, 0x90
	.type	print_timing,@function
print_timing:                           # @print_timing
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp21:
	.cfi_def_cfa_offset 16
.Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp23:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	1604(%rdi), %eax
	movl	%eax, -16(%rbp)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -24(%rbp)
	movl	$1, %edi
	xorl	%eax, %eax
	callq	sleep
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -32(%rbp)
	subq	-24(%rbp), %rax
	movd	%rax, %xmm0
	punpckldq	.LCPI6_0(%rip), %xmm0 # xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm0
	pshufd	$78, %xmm0, %xmm1       # xmm1 = xmm0[2,3,0,1]
	addpd	%xmm0, %xmm1
	movsd	.LCPI6_2(%rip), %xmm0   # xmm0 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movq	-8(%rbp), %rax
	xorps	%xmm1, %xmm1
	cvtsi2sdl	1308(%rax), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB6_41
# BB#1:                                 # %if.end
	movl	$.L.str.10, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_2
	.align	16, 0x90
.LBB6_3:                                # %for.inc
                                        #   in Loop: Header=BB6_2 Depth=1
	movl	-12(%rbp), %esi
	movl	$.L.str.11, %edi
	xorl	%eax, %eax
	callq	printf
	incl	-12(%rbp)
.LBB6_2:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_3
# BB#4:                                 # %for.end
	movl	$.L.str.12, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L.str.10, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_5
	.align	16, 0x90
.LBB6_6:                                # %for.inc19
                                        #   in Loop: Header=BB6_5 Depth=1
	movq	-8(%rbp), %rax
	movq	1776(%rax), %rax
	movq	248(%rax), %rax
	movl	20(%rax), %esi
	movb	-12(%rbp), %cl
	sarl	%cl, %esi
	movl	$.L.str.13, %edi
	xorl	%eax, %eax
	callq	printf
	incl	-12(%rbp)
.LBB6_5:                                # %for.cond13
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_6
# BB#7:                                 # %for.end21
	movl	$.L.str.14, %edi
	xorl	%eax, %eax
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.15, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_8
	.align	16, 0x90
.LBB6_9:                                # %for.inc35
                                        #   in Loop: Header=BB6_8 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	(%rcx,%rax,8), %xmm1    # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_8:                                # %for.cond24
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_9
# BB#10:                                # %for.end37
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.18, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_11
	.align	16, 0x90
.LBB6_12:                               # %for.inc57
                                        #   in Loop: Header=BB6_11 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	160(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	160(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_11:                               # %for.cond42
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_12
# BB#13:                                # %for.end59
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.19, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_14
	.align	16, 0x90
.LBB6_15:                               # %for.inc79
                                        #   in Loop: Header=BB6_14 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	240(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	240(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_14:                               # %for.cond64
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_15
# BB#16:                                # %for.end81
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.20, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_17
	.align	16, 0x90
.LBB6_18:                               # %for.inc101
                                        #   in Loop: Header=BB6_17 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	320(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	320(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_17:                               # %for.cond86
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_18
# BB#19:                                # %for.end103
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.21, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_20
	.align	16, 0x90
.LBB6_21:                               # %for.inc123
                                        #   in Loop: Header=BB6_20 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	80(%rcx,%rax,8), %xmm1  # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	80(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_20:                               # %for.cond108
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_21
# BB#22:                                # %for.end125
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.22, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_23
	.align	16, 0x90
.LBB6_24:                               # %for.inc145
                                        #   in Loop: Header=BB6_23 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	960(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	960(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_23:                               # %for.cond130
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_24
# BB#25:                                # %for.end147
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.23, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_26
	.align	16, 0x90
.LBB6_27:                               # %for.inc167
                                        #   in Loop: Header=BB6_26 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1040(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1040(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_26:                               # %for.cond152
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_27
# BB#28:                                # %for.end169
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.24, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_29
	.align	16, 0x90
.LBB6_30:                               # %for.inc189
                                        #   in Loop: Header=BB6_29 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	400(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	400(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_29:                               # %for.cond174
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_30
# BB#31:                                # %for.end191
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.25, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_32
	.align	16, 0x90
.LBB6_33:                               # %for.inc211
                                        #   in Loop: Header=BB6_32 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	560(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	560(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_32:                               # %for.cond196
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_33
# BB#34:                                # %for.end213
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.26, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_35
	.align	16, 0x90
.LBB6_36:                               # %for.inc224
                                        #   in Loop: Header=BB6_35 Depth=1
	movl	$.L.str.27, %edi
	xorl	%eax, %eax
	callq	printf
	incl	-12(%rbp)
.LBB6_35:                               # %for.cond218
                                        # =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	incl	%eax
	cmpl	%eax, -12(%rbp)
	jl	.LBB6_36
# BB#37:                                # %for.end226
	movl	$.L.str.12, %edi
	xorl	%eax, %eax
	callq	printf
	movq	$0, -48(%rbp)
	movl	$.L.str.28, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, -12(%rbp)
	jmp	.LBB6_38
	.align	16, 0x90
.LBB6_39:                               # %for.inc244
                                        #   in Loop: Header=BB6_38 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1200(%rcx,%rax,8), %xmm1 # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.16, %edi
	movb	$1, %al
	callq	printf
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1200(%rcx,%rax,8), %rax
	addq	%rax, -48(%rbp)
	incl	-12(%rbp)
.LBB6_38:                               # %for.cond229
                                        # =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.LBB6_39
# BB#40:                                # %for.end246
	movq	-48(%rbp), %xmm1        # xmm1 = mem[0],zero
	movdqa	.LCPI6_0(%rip), %xmm0   # xmm0 = [1127219200,1160773632,0,0]
	punpckldq	%xmm0, %xmm1    # xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.17, %edi
	movb	$1, %al
	callq	printf
	movl	$.L.str.12, %edi
	xorl	%eax, %eax
	callq	printf
	movq	-8(%rbp), %rax
	movq	1280(%rax), %xmm1       # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.29, %edi
	movb	$1, %al
	callq	printf
	movq	-8(%rbp), %rax
	movq	1296(%rax), %xmm1       # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.30, %edi
	movb	$1, %al
	callq	printf
	movq	-8(%rbp), %rax
	movq	1288(%rax), %xmm1       # xmm1 = mem[0],zero
	punpckldq	.LCPI6_0(%rip), %xmm1 # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI6_1(%rip), %xmm1
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	addpd	%xmm1, %xmm0
	mulsd	-40(%rbp), %xmm0
	movl	$.L.str.31, %edi
	movb	$1, %al
	callq	printf
	movq	-8(%rbp), %rcx
	movl	1304(%rcx), %eax
	cltd
	idivl	1308(%rcx)
	movl	%eax, %ecx
	movl	$.L.str.32, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movq	-8(%rbp), %rcx
	movl	1312(%rcx), %eax
	cltd
	idivl	1308(%rcx)
	movl	%eax, %ecx
	movl	$.L.str.33, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movl	$.L.str.34, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB6_41:                               # %return
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end6:
	.size	print_timing, .Lfunc_end6-print_timing
	.cfi_endproc

	.globl	MGResetTimers
	.align	16, 0x90
	.type	MGResetTimers,@function
MGResetTimers:                          # @MGResetTimers
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp24:
	.cfi_def_cfa_offset 16
.Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp26:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.LBB7_1
	.align	16, 0x90
.LBB7_2:                                # %for.inc
                                        #   in Loop: Header=BB7_1 Depth=1
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, (%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 80(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 160(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 400(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 240(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 320(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 960(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 1040(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 480(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 640(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 560(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 720(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 800(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 880(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 1120(%rcx,%rax,8)
	movslq	-12(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	$0, 1200(%rcx,%rax,8)
	incl	-12(%rbp)
.LBB7_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$9, -12(%rbp)
	jle	.LBB7_2
# BB#3:                                 # %for.end
	movq	-8(%rbp), %rax
	movq	$0, 1288(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 1296(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 1304(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 1308(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 1312(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 1316(%rax)
	popq	%rbp
	retq
.Lfunc_end7:
	.size	MGResetTimers, .Lfunc_end7-MGResetTimers
	.cfi_endproc

	.globl	MGBuild
	.align	16, 0x90
	.type	MGBuild,@function
MGBuild:                                # @MGBuild
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp27:
	.cfi_def_cfa_offset 16
.Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp29:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	%xmm2, -32(%rbp)
	movq	-8(%rbp), %rax
	movl	1604(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB8_2
# BB#1:                                 # %if.then
	movl	$.L.str.35, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB8_2:                                # %if.end
	movq	-8(%rbp), %rdi
	callq	MGResetTimers
	movq	-8(%rbp), %rax
	movq	$0, 1280(%rax)
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -56(%rbp)
	movl	$0, -40(%rbp)
	jmp	.LBB8_3
	.align	16, 0x90
.LBB8_7:                                # %for.inc14
                                        #   in Loop: Header=BB8_3 Depth=1
	incl	-40(%rbp)
.LBB8_3:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB8_5 Depth 2
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jge	.LBB8_8
# BB#4:                                 # %for.body
                                        #   in Loop: Header=BB8_3 Depth=1
	movb	-40(%rbp), %cl
	movl	$1, %eax
	shll	%cl, %eax
	cvtsi2sdl	%eax, %xmm0
	mulsd	-32(%rbp), %xmm0
	movsd	%xmm0, -64(%rbp)
	movslq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	movsd	%xmm0, 1616(%rcx,%rax,8)
	movl	$0, -36(%rbp)
	jmp	.LBB8_5
	.align	16, 0x90
.LBB8_6:                                # %for.inc
                                        #   in Loop: Header=BB8_5 Depth=2
	movsd	-64(%rbp), %xmm0        # xmm0 = mem[0],zero
	movslq	-40(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	1776(%rdx), %rdx
	shlq	$8, %rcx
	movq	248(%rdx,%rcx), %rcx
	imulq	$216, %rax, %rax
	movsd	%xmm0, (%rcx,%rax)
	incl	-36(%rbp)
.LBB8_5:                                # %for.cond5
                                        #   Parent Loop BB8_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-36(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	1600(%rcx), %eax
	jl	.LBB8_6
	jmp	.LBB8_7
.LBB8_8:                                # %for.end16
	movl	$0, -40(%rbp)
	jmp	.LBB8_9
	.align	16, 0x90
.LBB8_13:                               # %for.inc70
                                        #   in Loop: Header=BB8_9 Depth=1
	incl	-40(%rbp)
.LBB8_9:                                # %for.cond17
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB8_11 Depth 2
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jge	.LBB8_14
# BB#10:                                # %for.body20
                                        #   in Loop: Header=BB8_9 Depth=1
	movl	$1, -36(%rbp)
	jmp	.LBB8_11
	.align	16, 0x90
.LBB8_12:                               # %for.inc67
                                        #   in Loop: Header=BB8_11 Depth=2
	movslq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rdx
	imulq	$216, %rax, %rax
	movq	184(%rdx,%rax), %rdx
	movslq	-36(%rbp), %rsi
	shlq	$8, %rsi
	movq	248(%rcx,%rsi), %rcx
	movq	%rdx, 184(%rcx,%rax)
	movslq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rdx
	imulq	$216, %rax, %rax
	movq	192(%rdx,%rax), %rdx
	movslq	-36(%rbp), %rsi
	shlq	$8, %rsi
	movq	248(%rcx,%rsi), %rcx
	movq	%rdx, 192(%rcx,%rax)
	movslq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	1776(%rcx), %rcx
	movq	248(%rcx), %rdx
	imulq	$216, %rax, %rax
	movq	200(%rdx,%rax), %rdx
	movslq	-36(%rbp), %rsi
	shlq	$8, %rsi
	movq	248(%rcx,%rsi), %rcx
	movq	%rdx, 200(%rcx,%rax)
	incl	-36(%rbp)
.LBB8_11:                               # %for.cond21
                                        #   Parent Loop BB8_9 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-36(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	1600(%rcx), %eax
	jl	.LBB8_12
	jmp	.LBB8_13
.LBB8_14:                               # %for.end72
	movl	$0, -40(%rbp)
	jmp	.LBB8_15
	.align	16, 0x90
.LBB8_16:                               # %for.inc77
                                        #   in Loop: Header=BB8_15 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$2, %edx
	movl	$2, %ecx
	callq	restriction
	incl	-40(%rbp)
.LBB8_15:                               # %for.cond73
                                        # =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	decl	%eax
	cmpl	%eax, -40(%rbp)
	jl	.LBB8_16
# BB#17:                                # %for.end79
	movl	$0, -40(%rbp)
	jmp	.LBB8_18
	.align	16, 0x90
.LBB8_19:                               # %for.inc84
                                        #   in Loop: Header=BB8_18 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$2, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	incl	-40(%rbp)
.LBB8_18:                               # %for.cond80
                                        # =>This Inner Loop Header: Depth=1
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.LBB8_19
# BB#20:                                # %for.end86
	movq	-8(%rbp), %rdi
	movl	$0, %esi
	movl	$3, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	movq	-8(%rbp), %rdi
	xorl	%esi, %esi
	movl	$3, %edx
	movl	$5, %ecx
	xorl	%r8d, %r8d
	callq	project_cell_to_face
	movq	-8(%rbp), %rdi
	xorl	%esi, %esi
	movl	$3, %edx
	movl	$6, %ecx
	movl	$1, %r8d
	callq	project_cell_to_face
	movq	-8(%rbp), %rdi
	xorl	%esi, %esi
	movl	$3, %edx
	movl	$7, %ecx
	movl	$2, %r8d
	callq	project_cell_to_face
	movl	$0, -40(%rbp)
	jmp	.LBB8_21
	.align	16, 0x90
.LBB8_24:                               # %for.inc96
                                        #   in Loop: Header=BB8_21 Depth=1
	incl	-40(%rbp)
.LBB8_21:                               # %for.cond87
                                        # =>This Inner Loop Header: Depth=1
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jge	.LBB8_25
# BB#22:                                # %for.body90
                                        #   in Loop: Header=BB8_21 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$5, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$6, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$7, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	movl	-44(%rbp), %eax
	decl	%eax
	cmpl	%eax, -40(%rbp)
	jge	.LBB8_24
# BB#23:                                # %if.then94
                                        #   in Loop: Header=BB8_21 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	leal	1(%rsi), %edx
	callq	restriction_betas
	jmp	.LBB8_24
.LBB8_25:                               # %for.end98
	movl	$0, -40(%rbp)
	jmp	.LBB8_26
	.align	16, 0x90
.LBB8_27:                               # %for.inc103
                                        #   in Loop: Header=BB8_26 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movsd	-16(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-24(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	rebuild_lambda
	incl	-40(%rbp)
.LBB8_26:                               # %for.cond99
                                        # =>This Inner Loop Header: Depth=1
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.LBB8_27
# BB#28:                                # %for.end105
	movl	$0, -40(%rbp)
	jmp	.LBB8_29
	.align	16, 0x90
.LBB8_30:                               # %for.inc110
                                        #   in Loop: Header=BB8_29 Depth=1
	movq	-8(%rbp), %rdi
	movl	-40(%rbp), %esi
	movl	$4, %edx
	movl	$1, %ecx
	movl	$1, %r8d
	movl	$1, %r9d
	callq	exchange_boundary
	incl	-40(%rbp)
.LBB8_29:                               # %for.cond106
                                        # =>This Inner Loop Header: Depth=1
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.LBB8_30
# BB#31:                                # %for.end112
	xorl	%eax, %eax
	callq	CycleTime
	subq	-56(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-8(%rbp), %rcx
	addq	%rax, 1280(%rcx)
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB8_33
# BB#32:                                # %if.then121
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB8_33:                               # %if.end124
	addq	$80, %rsp
	popq	%rbp
	retq
.Lfunc_end8:
	.size	MGBuild, .Lfunc_end8-MGBuild
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI9_0:
	.quad	4607182418800017408     # double 1
.LCPI9_1:
	.quad	4562254508917369340     # double 0.001
	.text
	.globl	MGSolve
	.align	16, 0x90
	.type	MGSolve,@function
MGSolve:                                # @MGSolve
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp30:
	.cfi_def_cfa_offset 16
.Ltmp31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp32:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	%xmm2, -40(%rbp)
	movq	-8(%rbp), %rax
	incl	1308(%rax)
	movl	$0, -48(%rbp)
	movl	$9, -52(%rbp)
	movq	-8(%rbp), %rax
	movl	1604(%rax), %eax
	movl	%eax, -64(%rbp)
	movl	$10, -68(%rbp)
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB9_2
# BB#1:                                 # %if.then
	movl	$.L.str.36, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB9_2:                                # %if.end
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -80(%rbp)
	movq	-8(%rbp), %rdi
	movl	-48(%rbp), %edx
	xorl	%esi, %esi
	callq	zero_grid
	movq	-8(%rbp), %rdi
	movl	-52(%rbp), %edx
	movl	-16(%rbp), %ecx
	movsd	.LCPI9_0(%rip), %xmm0   # xmm0 = mem[0],zero
	xorl	%esi, %esi
	callq	scale_grid
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -88(%rbp)
	movl	$0, -60(%rbp)
	jmp	.LBB9_3
	.align	16, 0x90
.LBB9_10:                               # %for.inc42
                                        #   in Loop: Header=BB9_3 Depth=1
	incl	-60(%rbp)
.LBB9_3:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB9_5 Depth 2
                                        #     Child Loop BB9_8 Depth 2
	movl	-60(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jge	.LBB9_11
# BB#4:                                 # %for.body
                                        #   in Loop: Header=BB9_3 Depth=1
	movq	-8(%rbp), %rax
	incl	1304(%rax)
	movl	$0, -44(%rbp)
	jmp	.LBB9_5
	.align	16, 0x90
.LBB9_6:                                # %for.inc
                                        #   in Loop: Header=BB9_5 Depth=2
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -96(%rbp)
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %ecx
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-32(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	smooth
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	movl	-48(%rbp), %ecx
	movl	-52(%rbp), %r8d
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-32(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$10, %edx
	callq	residual
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	movl	-52(%rbp), %edx
	movl	$10, %ecx
	callq	restriction
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	incl	%esi
	movl	-48(%rbp), %edx
	callq	zero_grid
	xorl	%eax, %eax
	callq	CycleTime
	subq	-96(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-8(%rbp), %rdx
	addq	%rax, 1200(%rdx,%rcx,8)
	incl	-44(%rbp)
.LBB9_5:                                # %for.cond7
                                        #   Parent Loop BB9_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	-8(%rbp), %rax
	movl	1604(%rax), %eax
	decl	%eax
	cmpl	%eax, -44(%rbp)
	jl	.LBB9_6
# BB#7:                                 # %for.end
                                        #   in Loop: Header=BB9_3 Depth=1
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -104(%rbp)
	movq	-8(%rbp), %rax
	movl	1604(%rax), %esi
	decl	%esi
	movl	%esi, -44(%rbp)
	movq	-8(%rbp), %rdi
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %ecx
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-32(%rbp), %xmm1        # xmm1 = mem[0],zero
	movsd	.LCPI9_1(%rip), %xmm2   # xmm2 = mem[0],zero
	callq	IterativeSolver
	xorl	%eax, %eax
	callq	CycleTime
	subq	-104(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-8(%rbp), %rdx
	addq	%rax, 1200(%rdx,%rcx,8)
	movq	-8(%rbp), %rax
	movl	1604(%rax), %eax
	addl	$-2, %eax
	movl	%eax, -44(%rbp)
	jmp	.LBB9_8
	.align	16, 0x90
.LBB9_9:                                # %for.inc40
                                        #   in Loop: Header=BB9_8 Depth=2
	xorl	%eax, %eax
	callq	CycleTime
	movq	%rax, -112(%rbp)
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	movl	-48(%rbp), %edx
	movsd	.LCPI9_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	%edx, %ecx
	callq	interpolation_constant
	movq	-8(%rbp), %rdi
	movl	-44(%rbp), %esi
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %ecx
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-32(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	smooth
	xorl	%eax, %eax
	callq	CycleTime
	subq	-112(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movq	-8(%rbp), %rdx
	addq	%rax, 1200(%rdx,%rcx,8)
	decl	-44(%rbp)
.LBB9_8:                                # %for.cond28
                                        #   Parent Loop BB9_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$0, -44(%rbp)
	jns	.LBB9_9
	jmp	.LBB9_10
.LBB9_11:                               # %for.end44
	xorl	%eax, %eax
	callq	CycleTime
	subq	-88(%rbp), %rax
	movq	-8(%rbp), %rcx
	addq	%rax, 1288(%rcx)
	xorl	%eax, %eax
	callq	CycleTime
	subq	-80(%rbp), %rax
	movq	-8(%rbp), %rcx
	addq	%rax, 1296(%rcx)
	movq	-8(%rbp), %rax
	cmpl	$0, 1596(%rax)
	jne	.LBB9_13
# BB#12:                                # %if.then55
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	callq	printf
	movq	stdout(%rip), %rdi
	callq	fflush
.LBB9_13:                               # %if.end58
	addq	$112, %rsp
	popq	%rbp
	retq
.Lfunc_end9:
	.size	MGSolve, .Lfunc_end9-MGSolve
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"creating domain...       "
	.size	.L.str, 26

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"#ghosts(%d)>bottom grid size(%d)\n"
	.size	.L.str.1, 34

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"subdomain_dim's must be equal\n"
	.size	.L.str.2, 31

	.type	.Lcreate_domain.FacesEdgesCorners,@object # @create_domain.FacesEdgesCorners
	.section	.rodata,"a",@progbits
	.align	16
.Lcreate_domain.FacesEdgesCorners:
	.long	4                       # 0x4
	.long	10                      # 0xa
	.long	12                      # 0xc
	.long	14                      # 0xe
	.long	16                      # 0x10
	.long	22                      # 0x16
	.long	1                       # 0x1
	.long	3                       # 0x3
	.long	5                       # 0x5
	.long	7                       # 0x7
	.long	9                       # 0x9
	.long	11                      # 0xb
	.long	15                      # 0xf
	.long	17                      # 0x11
	.long	19                      # 0x13
	.long	21                      # 0x15
	.long	23                      # 0x17
	.long	25                      # 0x19
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	6                       # 0x6
	.long	8                       # 0x8
	.long	18                      # 0x12
	.long	20                      # 0x14
	.long	24                      # 0x18
	.long	26                      # 0x1a
	.long	13                      # 0xd
	.size	.Lcreate_domain.FacesEdgesCorners, 108

	.type	.Lcreate_domain.edges,@object # @create_domain.edges
	.align	16
.Lcreate_domain.edges:
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
	.size	.Lcreate_domain.edges, 108

	.type	.Lcreate_domain.corners,@object # @create_domain.corners
	.align	16
.Lcreate_domain.corners:
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
	.size	.Lcreate_domain.corners, 108

	.type	.L.str.3,@object        # @.str.3
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.3:
	.asciz	"done\n"
	.size	.L.str.3, 6

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"  %d x %d x %d (per subdomain)\n"
	.size	.L.str.4, 32

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"  %d x %d x %d (per process)\n"
	.size	.L.str.5, 30

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"  %d x %d x %d (overall)\n"
	.size	.L.str.6, 26

	.type	.L.str.7,@object        # @.str.7
.L.str.7:
	.asciz	"  %d-deep ghost zones\n"
	.size	.L.str.7, 23

	.type	.L.str.8,@object        # @.str.8
.L.str.8:
	.asciz	"  allocated %llu MB\n"
	.size	.L.str.8, 21

	.type	.L.str.9,@object        # @.str.9
.L.str.9:
	.asciz	"deallocating domain...   "
	.size	.L.str.9, 26

	.type	.L.str.10,@object       # @.str.10
.L.str.10:
	.asciz	"                       "
	.size	.L.str.10, 24

	.type	.L.str.11,@object       # @.str.11
.L.str.11:
	.asciz	"%12d "
	.size	.L.str.11, 6

	.type	.L.str.12,@object       # @.str.12
.L.str.12:
	.asciz	"\n"
	.size	.L.str.12, 2

	.type	.L.str.13,@object       # @.str.13
.L.str.13:
	.asciz	"%10d^3 "
	.size	.L.str.13, 8

	.type	.L.str.14,@object       # @.str.14
.L.str.14:
	.asciz	"       total\n"
	.size	.L.str.14, 14

	.type	.L.str.15,@object       # @.str.15
.L.str.15:
	.asciz	"smooth                 "
	.size	.L.str.15, 24

	.type	.L.str.16,@object       # @.str.16
.L.str.16:
	.asciz	"%12.6f "
	.size	.L.str.16, 8

	.type	.L.str.17,@object       # @.str.17
.L.str.17:
	.asciz	"%12.6f\n"
	.size	.L.str.17, 8

	.type	.L.str.18,@object       # @.str.18
.L.str.18:
	.asciz	"residual               "
	.size	.L.str.18, 24

	.type	.L.str.19,@object       # @.str.19
.L.str.19:
	.asciz	"restriction            "
	.size	.L.str.19, 24

	.type	.L.str.20,@object       # @.str.20
.L.str.20:
	.asciz	"interpolation          "
	.size	.L.str.20, 24

	.type	.L.str.21,@object       # @.str.21
.L.str.21:
	.asciz	"applyOp                "
	.size	.L.str.21, 24

	.type	.L.str.22,@object       # @.str.22
.L.str.22:
	.asciz	"BLAS1                  "
	.size	.L.str.22, 24

	.type	.L.str.23,@object       # @.str.23
.L.str.23:
	.asciz	"BLAS3                  "
	.size	.L.str.23, 24

	.type	.L.str.24,@object       # @.str.24
.L.str.24:
	.asciz	"communication          "
	.size	.L.str.24, 24

	.type	.L.str.25,@object       # @.str.25
.L.str.25:
	.asciz	"  local exchange       "
	.size	.L.str.25, 24

	.type	.L.str.26,@object       # @.str.26
.L.str.26:
	.asciz	"--------------         "
	.size	.L.str.26, 24

	.type	.L.str.27,@object       # @.str.27
.L.str.27:
	.asciz	"------------ "
	.size	.L.str.27, 14

	.type	.L.str.28,@object       # @.str.28
.L.str.28:
	.asciz	"Total by level         "
	.size	.L.str.28, 24

	.type	.L.str.29,@object       # @.str.29
.L.str.29:
	.asciz	"  Total time in MGBuild   %12.6f\n"
	.size	.L.str.29, 34

	.type	.L.str.30,@object       # @.str.30
.L.str.30:
	.asciz	"  Total time in MGSolve   %12.6f\n"
	.size	.L.str.30, 34

	.type	.L.str.31,@object       # @.str.31
.L.str.31:
	.asciz	"              \" v-cycles  %12.6f\n"
	.size	.L.str.31, 34

	.type	.L.str.32,@object       # @.str.32
.L.str.32:
	.asciz	"      number of v-cycles  %12d\n"
	.size	.L.str.32, 32

	.type	.L.str.33,@object       # @.str.33
.L.str.33:
	.asciz	"Bottom solver iterations  %12d\n"
	.size	.L.str.33, 32

	.type	.L.str.34,@object       # @.str.34
.L.str.34:
	.asciz	"\n\n"
	.size	.L.str.34, 3

	.type	.L.str.35,@object       # @.str.35
.L.str.35:
	.asciz	"MGBuild...                      "
	.size	.L.str.35, 33

	.type	.L.str.36,@object       # @.str.36
.L.str.36:
	.asciz	"MGSolve...                      "
	.size	.L.str.36, 33


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
