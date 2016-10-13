	.text
	.file	"solver.bc"
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI0_0:
	.quad	4607182418800017408     # double 1
.LCPI0_2:
	.quad	0                       # double 0
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI0_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	TelescopingCABiCGStab
	.align	16, 0x90
	.type	TelescopingCABiCGStab,@function
TelescopingCABiCGStab:                  # @TelescopingCABiCGStab
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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$11320, %rsp            # imm = 0x2C38
.Ltmp3:
	.cfi_offset %rbx, -56
.Ltmp4:
	.cfi_offset %r12, -48
.Ltmp5:
	.cfi_offset %r13, -40
.Ltmp6:
	.cfi_offset %r14, -32
.Ltmp7:
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)
	movl	%esi, -52(%rbp)
	movl	%edx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movsd	%xmm0, -72(%rbp)
	movsd	%xmm1, -80(%rbp)
	movsd	%xmm2, -88(%rbp)
	movl	$200, -11012(%rbp)
	movl	$0, -11016(%rbp)
	movl	$0, -11036(%rbp)
	movl	$0, -11040(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %r8d
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$12, %edx
	callq	residual
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$13, %edx
	movl	$12, %ecx
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$14, %edx
	movl	$12, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$12, %edx
	callq	norm
	movsd	%xmm0, -11144(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_2
	jp	.LBB0_2
# BB#1:                                 # %if.then
	movl	$1, -11040(%rbp)
.LBB0_2:                                # %if.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$13, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -11088(%rbp)
	ucomisd	.LCPI0_2, %xmm0
	jne	.LBB0_4
	jp	.LBB0_4
# BB#3:                                 # %if.then3
	movl	$1, -11040(%rbp)
.LBB0_4:                                # %if.end4
	movsd	-11088(%rbp), %xmm1     # xmm1 = mem[0],zero
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB0_6
# BB#5:                                 # %call.sqrt
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB0_6:                                # %if.end4.split
	movsd	%xmm0, -11112(%rbp)
	movl	$1, -11148(%rbp)
	leaq	-5440(%rbp), %r14
	leaq	-2832(%rbp), %rbx
	movabsq	$4607182418800017408, %r13 # imm = 0x3FF0000000000000
	jmp	.LBB0_7
	.align	16, 0x90
.LBB0_134:                              # %if.then693
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$4, -11148(%rbp)
.LBB0_7:                                # %while.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_14 Depth 2
                                        #       Child Loop BB0_16 Depth 3
                                        #     Child Loop BB0_20 Depth 2
                                        #       Child Loop BB0_22 Depth 3
                                        #     Child Loop BB0_26 Depth 2
                                        #     Child Loop BB0_29 Depth 2
                                        #     Child Loop BB0_32 Depth 2
                                        #     Child Loop BB0_35 Depth 2
                                        #     Child Loop BB0_38 Depth 2
                                        #     Child Loop BB0_41 Depth 2
                                        #     Child Loop BB0_44 Depth 2
                                        #     Child Loop BB0_47 Depth 2
                                        #       Child Loop BB0_49 Depth 3
                                        #     Child Loop BB0_53 Depth 2
                                        #     Child Loop BB0_56 Depth 2
                                        #     Child Loop BB0_59 Depth 2
                                        #     Child Loop BB0_62 Depth 2
                                        #       Child Loop BB0_64 Depth 3
                                        #         Child Loop BB0_66 Depth 4
                                        #       Child Loop BB0_70 Depth 3
                                        #         Child Loop BB0_72 Depth 4
                                        #       Child Loop BB0_76 Depth 3
                                        #         Child Loop BB0_78 Depth 4
                                        #       Child Loop BB0_84 Depth 3
                                        #         Child Loop BB0_86 Depth 4
                                        #       Child Loop BB0_90 Depth 3
                                        #         Child Loop BB0_92 Depth 4
                                        #       Child Loop BB0_105 Depth 3
                                        #         Child Loop BB0_107 Depth 4
                                        #     Child Loop BB0_123 Depth 2
                                        #     Child Loop BB0_128 Depth 2
                                        #     Child Loop BB0_131 Depth 2
	movl	-11016(%rbp), %eax
	cmpl	-11012(%rbp), %eax
	jge	.LBB0_8
# BB#9:                                 # %land.lhs.true
                                        #   in Loop: Header=BB0_7 Depth=1
	cmpl	$0, -11036(%rbp)
	je	.LBB0_11
# BB#10:                                #   in Loop: Header=BB0_7 Depth=1
	xorl	%eax, %eax
	jmp	.LBB0_12
	.align	16, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_7 Depth=1
	xorl	%eax, %eax
	jmp	.LBB0_12
.LBB0_11:                               # %land.rhs
                                        #   in Loop: Header=BB0_7 Depth=1
	cmpl	$0, -11040(%rbp)
	sete	%al
	.align	16, 0x90
.LBB0_12:                               # %land.end
                                        #   in Loop: Header=BB0_7 Depth=1
	testb	%al, %al
	je	.LBB0_135
# BB#13:                                # %while.body
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5296(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	movq	%r14, %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5584(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5728(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5872(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-6016(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-224(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-368(%rbp), %rdi
	callq	__zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-512(%rbp), %rdi
	callq	__zero
	movl	$0, -11024(%rbp)
	jmp	.LBB0_14
	.align	16, 0x90
.LBB0_18:                               # %for.inc42
                                        #   in Loop: Header=BB0_14 Depth=2
	incl	-11024(%rbp)
.LBB0_14:                               # %for.cond
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_16 Depth 3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jge	.LBB0_19
# BB#15:                                # %for.body
                                        #   in Loop: Header=BB0_14 Depth=2
	movl	$0, -11028(%rbp)
	jmp	.LBB0_16
	.align	16, 0x90
.LBB0_17:                               # %for.inc
                                        #   in Loop: Header=BB0_16 Depth=3
	movslq	-11028(%rbp), %rax
	movslq	-11024(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-11028(%rbp)
.LBB0_16:                               # %for.cond35
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_14 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11028(%rbp)
	jl	.LBB0_17
	jmp	.LBB0_18
	.align	16, 0x90
.LBB0_19:                               # %for.end44
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_20
	.align	16, 0x90
.LBB0_24:                               # %for.inc62
                                        #   in Loop: Header=BB0_20 Depth=2
	incl	-11024(%rbp)
.LBB0_20:                               # %for.cond45
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_22 Depth 3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jge	.LBB0_25
# BB#21:                                # %for.body49
                                        #   in Loop: Header=BB0_20 Depth=2
	movl	$0, -11028(%rbp)
	jmp	.LBB0_22
	.align	16, 0x90
.LBB0_23:                               # %for.inc59
                                        #   in Loop: Header=BB0_22 Depth=3
	movslq	-11028(%rbp), %rax
	movslq	-11024(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-5152(%rbp,%rcx), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-11028(%rbp)
.LBB0_22:                               # %for.cond50
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_20 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11028(%rbp)
	jl	.LBB0_23
	jmp	.LBB0_24
	.align	16, 0x90
.LBB0_25:                               # %for.end64
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_26
	.align	16, 0x90
.LBB0_27:                               # %for.inc74
                                        #   in Loop: Header=BB0_26 Depth=2
	movslq	-11024(%rbp), %rax
	imulq	$136, %rax, %rcx
	addq	%rbx, %rcx
	movq	%r13, 136(%rcx,%rax,8)
	incl	-11024(%rbp)
.LBB0_26:                               # %for.cond65
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_27
# BB#28:                                # %for.end76
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	-11148(%rbp), %eax
	leal	1(%rax,%rax), %eax
	movl	%eax, -11024(%rbp)
	jmp	.LBB0_29
	.align	16, 0x90
.LBB0_30:                               # %for.inc88
                                        #   in Loop: Header=BB0_29 Depth=2
	movslq	-11024(%rbp), %rax
	imulq	$136, %rax, %rcx
	addq	%rbx, %rcx
	movq	%r13, 136(%rcx,%rax,8)
	incl	-11024(%rbp)
.LBB0_29:                               # %for.cond79
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	shll	$2, %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_30
# BB#31:                                # %for.end90
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_32
	.align	16, 0x90
.LBB0_33:                               # %for.inc100
                                        #   in Loop: Header=BB0_32 Depth=2
	movslq	-11024(%rbp), %rax
	imulq	$136, %rax, %rcx
	leaq	-5152(%rbp), %rdx
	addq	%rdx, %rcx
	movq	%r13, 272(%rcx,%rax,8)
	incl	-11024(%rbp)
.LBB0_32:                               # %for.cond91
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	-1(%rax,%rax), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_33
# BB#34:                                # %for.end102
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	-11148(%rbp), %eax
	leal	1(%rax,%rax), %eax
	movl	%eax, -11024(%rbp)
	jmp	.LBB0_35
	.align	16, 0x90
.LBB0_36:                               # %for.inc115
                                        #   in Loop: Header=BB0_35 Depth=2
	movslq	-11024(%rbp), %rax
	imulq	$136, %rax, %rcx
	leaq	-5152(%rbp), %rdx
	addq	%rdx, %rcx
	movq	%r13, 272(%rcx,%rax,8)
	incl	-11024(%rbp)
.LBB0_35:                               # %for.cond105
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	-1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_36
# BB#37:                                # %for.end117
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_38
	.align	16, 0x90
.LBB0_39:                               # %for.inc126
                                        #   in Loop: Header=BB0_38 Depth=2
	movslq	-11024(%rbp), %rax
	leal	15(%rax), %ecx
	movl	%ecx, -11008(%rbp,%rax,4)
	incl	-11024(%rbp)
.LBB0_38:                               # %for.cond118
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_39
# BB#40:                                # %for.end128
                                        #   in Loop: Header=BB0_7 Depth=1
	movslq	-11148(%rbp), %rax
	shlq	$4, %rax
	leaq	-11008(%rbp), %rcx
	movl	$12, 4(%rax,%rcx)
	movq	%rcx, -11160(%rbp)
	movq	%rcx, %rbx
	movslq	-11148(%rbp), %rax
	leaq	-11004(%rbp,%rax,8), %rax
	movq	%rax, -11168(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-11160(%rbp), %rax
	movl	(%rax), %edx
	movl	$14, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -11020(%rbp)
	jmp	.LBB0_41
	.align	16, 0x90
.LBB0_42:                               # %for.inc149
                                        #   in Loop: Header=BB0_41 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11020(%rbp), %rax
	movq	-11160(%rbp), %rcx
	movl	-4(%rcx,%rax,4), %r8d
	movl	$10, %edx
	movl	$4, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	mul_grids
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11020(%rbp), %rax
	movq	-11160(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$10, %ecx
	callq	apply_op
	incl	-11020(%rbp)
.LBB0_41:                               # %for.cond139
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(%rax,%rax), %eax
	cmpl	%eax, -11020(%rbp)
	jl	.LBB0_42
# BB#43:                                # %for.end151
                                        #   in Loop: Header=BB0_7 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-11168(%rbp), %rax
	movl	(%rax), %edx
	movl	$13, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -11020(%rbp)
	jmp	.LBB0_44
	.align	16, 0x90
.LBB0_45:                               # %for.inc162
                                        #   in Loop: Header=BB0_44 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11020(%rbp), %rax
	movq	-11168(%rbp), %rcx
	movl	-4(%rcx,%rax,4), %r8d
	movl	$10, %edx
	movl	$4, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	mul_grids
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11020(%rbp), %rax
	movq	-11168(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$10, %ecx
	callq	apply_op
	incl	-11020(%rbp)
.LBB0_44:                               # %for.cond153
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -11020(%rbp)
	jl	.LBB0_45
# BB#46:                                # %for.end164
                                        #   in Loop: Header=BB0_7 Depth=1
	movq	-48(%rbp), %rax
	incl	1316(%rax)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %r9d
	leal	2(,%rax,4), %eax
	movl	%eax, (%rsp)
	movl	$1, 8(%rsp)
	leaq	-10928(%rbp), %rdx
	movq	%rbx, %rcx
	movq	%rcx, %r8
	callq	matmul_grids
	movl	$0, -11024(%rbp)
	movl	$0, -11032(%rbp)
	jmp	.LBB0_47
	.align	16, 0x90
.LBB0_51:                               # %for.inc198
                                        #   in Loop: Header=BB0_47 Depth=2
	movslq	-11032(%rbp), %rax
	leal	1(%rax), %ecx
	movl	%ecx, -11032(%rbp)
	movsd	-10928(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	movslq	-11024(%rbp), %rax
	movsd	%xmm0, -8480(%rbp,%rax,8)
	incl	-11024(%rbp)
.LBB0_47:                               # %for.cond173
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_49 Depth 3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jge	.LBB0_52
# BB#48:                                # %for.body177
                                        #   in Loop: Header=BB0_47 Depth=2
	movl	$0, -11028(%rbp)
	jmp	.LBB0_49
	.align	16, 0x90
.LBB0_50:                               # %for.inc190
                                        #   in Loop: Header=BB0_49 Depth=3
	movslq	-11032(%rbp), %rax
	leal	1(%rax), %ecx
	movl	%ecx, -11032(%rbp)
	movsd	-10928(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	movslq	-11028(%rbp), %rax
	movslq	-11024(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-11028(%rbp)
.LBB0_49:                               # %for.cond178
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_47 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11028(%rbp)
	jl	.LBB0_50
	jmp	.LBB0_51
	.align	16, 0x90
.LBB0_52:                               # %for.end200
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_53
	.align	16, 0x90
.LBB0_54:                               # %for.inc208
                                        #   in Loop: Header=BB0_53 Depth=2
	movslq	-11024(%rbp), %rax
	movq	$0, -5296(%rbp,%rax,8)
	incl	-11024(%rbp)
.LBB0_53:                               # %for.cond201
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_54
# BB#55:                                # %for.end210
                                        #   in Loop: Header=BB0_7 Depth=1
	movq	%r13, -5296(%rbp)
	movl	$0, -11024(%rbp)
	jmp	.LBB0_56
	.align	16, 0x90
.LBB0_57:                               # %for.inc219
                                        #   in Loop: Header=BB0_56 Depth=2
	movslq	-11024(%rbp), %rax
	movq	$0, -5440(%rbp,%rax,8)
	incl	-11024(%rbp)
.LBB0_56:                               # %for.cond212
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_57
# BB#58:                                # %for.end221
                                        #   in Loop: Header=BB0_7 Depth=1
	movslq	-11148(%rbp), %rax
	shlq	$4, %rax
	movq	%r13, 8(%rax,%r14)
	movl	$0, -11024(%rbp)
	jmp	.LBB0_59
	.align	16, 0x90
.LBB0_60:                               # %for.inc233
                                        #   in Loop: Header=BB0_59 Depth=2
	movslq	-11024(%rbp), %rax
	movq	$0, -5584(%rbp,%rax,8)
	incl	-11024(%rbp)
.LBB0_59:                               # %for.cond226
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_60
# BB#61:                                # %for.end235
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11020(%rbp)
	jmp	.LBB0_62
	.align	16, 0x90
.LBB0_136:                              # %for.inc638
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11104(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-5296(%rbp), %r12
	movq	%r12, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	movq	%r12, %rdx
	callq	__axpy
	movsd	-11080(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI0_1(%rip), %xmm1
	mulsd	-11104(%rbp), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r12, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r12, %rsi
	leaq	-5728(%rbp), %rdx
	callq	__axpy
	movsd	-11096(%rbp), %xmm0     # xmm0 = mem[0],zero
	movsd	%xmm0, -11088(%rbp)
	incl	-11020(%rbp)
.LBB0_62:                               # %for.cond236
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_64 Depth 3
                                        #         Child Loop BB0_66 Depth 4
                                        #       Child Loop BB0_70 Depth 3
                                        #         Child Loop BB0_72 Depth 4
                                        #       Child Loop BB0_76 Depth 3
                                        #         Child Loop BB0_78 Depth 4
                                        #       Child Loop BB0_84 Depth 3
                                        #         Child Loop BB0_86 Depth 4
                                        #       Child Loop BB0_90 Depth 3
                                        #         Child Loop BB0_92 Depth 4
                                        #       Child Loop BB0_105 Depth 3
                                        #         Child Loop BB0_107 Depth 4
	movl	-11020(%rbp), %eax
	cmpl	-11148(%rbp), %eax
	xorpd	%xmm1, %xmm1
	jge	.LBB0_122
# BB#63:                                # %for.body238
                                        #   in Loop: Header=BB0_62 Depth=2
	movq	-48(%rbp), %rax
	incl	1312(%rax)
	movl	$0, -11172(%rbp)
	jmp	.LBB0_64
	.align	16, 0x90
.LBB0_68:                               # %for.inc268
                                        #   in Loop: Header=BB0_64 Depth=3
	movslq	-11172(%rbp), %rax
	movsd	-5728(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11184(%rbp), %xmm0
	movsd	%xmm0, -5728(%rbp,%rax,8)
	incl	-11172(%rbp)
.LBB0_64:                               # %for.cond240
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_66 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11172(%rbp)
	jge	.LBB0_69
# BB#65:                                # %for.body244
                                        #   in Loop: Header=BB0_64 Depth=3
	movq	$0, -11184(%rbp)
	movl	$0, -11176(%rbp)
	jmp	.LBB0_66
	.align	16, 0x90
.LBB0_67:                               # %for.inc258
                                        #   in Loop: Header=BB0_66 Depth=4
	movslq	-11176(%rbp), %rax
	movslq	-11172(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5296(%rbp,%rax,8), %xmm0
	addsd	-11184(%rbp), %xmm0
	movsd	%xmm0, -11184(%rbp)
	incl	-11176(%rbp)
.LBB0_66:                               # %for.cond245
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_64 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11176(%rbp)
	jl	.LBB0_67
	jmp	.LBB0_68
	.align	16, 0x90
.LBB0_69:                               # %for.end270
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	$0, -11188(%rbp)
	jmp	.LBB0_70
	.align	16, 0x90
.LBB0_74:                               # %for.inc302
                                        #   in Loop: Header=BB0_70 Depth=3
	movslq	-11188(%rbp), %rax
	movsd	-5872(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11200(%rbp), %xmm0
	movsd	%xmm0, -5872(%rbp,%rax,8)
	incl	-11188(%rbp)
.LBB0_70:                               # %for.cond274
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_72 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11188(%rbp)
	jge	.LBB0_75
# BB#71:                                # %for.body278
                                        #   in Loop: Header=BB0_70 Depth=3
	movq	$0, -11200(%rbp)
	movl	$0, -11192(%rbp)
	jmp	.LBB0_72
	.align	16, 0x90
.LBB0_73:                               # %for.inc292
                                        #   in Loop: Header=BB0_72 Depth=4
	movslq	-11192(%rbp), %rax
	movslq	-11188(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5440(%rbp,%rax,8), %xmm0
	addsd	-11200(%rbp), %xmm0
	movsd	%xmm0, -11200(%rbp)
	incl	-11192(%rbp)
.LBB0_72:                               # %for.cond279
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_70 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11192(%rbp)
	jl	.LBB0_73
	jmp	.LBB0_74
	.align	16, 0x90
.LBB0_75:                               # %for.end304
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	$0, -11204(%rbp)
	jmp	.LBB0_76
	.align	16, 0x90
.LBB0_80:                               # %for.inc336
                                        #   in Loop: Header=BB0_76 Depth=3
	movslq	-11204(%rbp), %rax
	movsd	-6016(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11216(%rbp), %xmm0
	movsd	%xmm0, -6016(%rbp,%rax,8)
	incl	-11204(%rbp)
.LBB0_76:                               # %for.cond308
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_78 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11204(%rbp)
	jge	.LBB0_81
# BB#77:                                # %for.body312
                                        #   in Loop: Header=BB0_76 Depth=3
	movq	$0, -11216(%rbp)
	movl	$0, -11208(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB0_78
	.align	16, 0x90
.LBB0_79:                               # %for.inc326
                                        #   in Loop: Header=BB0_78 Depth=4
	movslq	-11208(%rbp), %rax
	movslq	-11204(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-5152(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5296(%rbp,%rax,8), %xmm0
	addsd	-11216(%rbp), %xmm0
	movsd	%xmm0, -11216(%rbp)
	incl	-11208(%rbp)
.LBB0_78:                               # %for.cond313
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_76 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11208(%rbp)
	jl	.LBB0_79
	jmp	.LBB0_80
	.align	16, 0x90
.LBB0_81:                               # %for.end338
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-8480(%rbp), %rdi
	leaq	-5728(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -11048(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_82
	jnp	.LBB0_121
.LBB0_82:                               # %cond.true349
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11088(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11048(%rbp), %xmm0
	movsd	%xmm0, -11056(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB0_121
# BB#83:                                # %if.end357
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11056(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI0_1(%rip), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-224(%rbp), %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	leaq	-5872(%rbp), %rsi
	leaq	-6016(%rbp), %rdx
	callq	__axpy
	movl	$0, -11220(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB0_84
	.align	16, 0x90
.LBB0_88:                               # %for.inc397
                                        #   in Loop: Header=BB0_84 Depth=3
	movslq	-11220(%rbp), %rax
	movsd	-368(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11232(%rbp), %xmm0
	movsd	%xmm0, -368(%rbp,%rax,8)
	incl	-11220(%rbp)
.LBB0_84:                               # %for.cond367
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_86 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11220(%rbp)
	jge	.LBB0_89
# BB#85:                                # %for.body372
                                        #   in Loop: Header=BB0_84 Depth=3
	movq	$0, -11232(%rbp)
	movl	$0, -11224(%rbp)
	jmp	.LBB0_86
	.align	16, 0x90
.LBB0_87:                               # %for.inc387
                                        #   in Loop: Header=BB0_86 Depth=4
	movslq	-11224(%rbp), %rax
	movslq	-11220(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-224(%rbp,%rax,8), %xmm0
	addsd	-11232(%rbp), %xmm0
	movsd	%xmm0, -11232(%rbp)
	incl	-11224(%rbp)
.LBB0_86:                               # %for.cond373
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_84 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11224(%rbp)
	jl	.LBB0_87
	jmp	.LBB0_88
	.align	16, 0x90
.LBB0_89:                               # %for.end399
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11056(%rbp), %xmm1     # xmm1 = mem[0],zero
	movapd	.LCPI0_1(%rip), %xmm0   # xmm0 = [9223372036854775808,9223372036854775808]
	xorpd	%xmm0, %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-512(%rbp), %r15
	movq	%r15, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	leaq	-5728(%rbp), %rbx
	movq	%rbx, %rdx
	callq	__axpy
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	movq	%r15, %rdi
	leaq	-368(%rbp), %r15
	movq	%r15, %rsi
	callq	__dot
	movsd	%xmm0, -11064(%rbp)
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-224(%rbp), %r12
	movq	%r12, %rdi
	movq	%r15, %rsi
	callq	__dot
	movsd	%xmm0, -11072(%rbp)
	movsd	-11056(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-5584(%rbp), %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rdi, %rsi
	leaq	-5296(%rbp), %rdx
	callq	__axpy
	movsd	-11056(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI0_1(%rip), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r12, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movl	$0, -11236(%rbp)
	jmp	.LBB0_90
	.align	16, 0x90
.LBB0_94:                               # %for.inc460
                                        #   in Loop: Header=BB0_90 Depth=3
	movslq	-11236(%rbp), %rax
	movsd	-368(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11248(%rbp), %xmm0
	movsd	%xmm0, -368(%rbp,%rax,8)
	incl	-11236(%rbp)
.LBB0_90:                               # %for.cond430
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_92 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11236(%rbp)
	jge	.LBB0_95
# BB#91:                                # %for.body435
                                        #   in Loop: Header=BB0_90 Depth=3
	movq	$0, -11248(%rbp)
	movl	$0, -11240(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB0_92
	.align	16, 0x90
.LBB0_93:                               # %for.inc450
                                        #   in Loop: Header=BB0_92 Depth=4
	movslq	-11240(%rbp), %rax
	movslq	-11236(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-224(%rbp,%rax,8), %xmm0
	addsd	-11248(%rbp), %xmm0
	movsd	%xmm0, -11248(%rbp)
	incl	-11240(%rbp)
.LBB0_92:                               # %for.cond436
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_90 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11240(%rbp)
	jl	.LBB0_93
	jmp	.LBB0_94
	.align	16, 0x90
.LBB0_95:                               # %for.end462
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-224(%rbp), %rdi
	leaq	-368(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -11136(%rbp)
	xorpd	%xmm2, %xmm2
	ucomisd	%xmm0, %xmm2
	jbe	.LBB0_97
# BB#96:                                # %if.then470
                                        #   in Loop: Header=BB0_62 Depth=2
	movq	$0, -11136(%rbp)
	jmp	.LBB0_100
	.align	16, 0x90
.LBB0_97:                               # %if.else
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11136(%rbp), %xmm1     # xmm1 = mem[0],zero
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB0_99
# BB#98:                                # %call.sqrt1
                                        #   in Loop: Header=BB0_62 Depth=2
	movapd	%xmm1, %xmm0
	callq	sqrt
	xorpd	%xmm2, %xmm2
.LBB0_99:                               # %if.else.split
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	%xmm0, -11136(%rbp)
.LBB0_100:                              # %if.end472
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-11112(%rbp), %xmm0
	ucomisd	-11136(%rbp), %xmm0
	ja	.LBB0_101
# BB#102:                               # %if.end477
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11072(%rbp), %xmm0     # xmm0 = mem[0],zero
	ucomisd	%xmm2, %xmm0
	jne	.LBB0_103
	jnp	.LBB0_121
.LBB0_103:                              # %cond.true488
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11064(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11072(%rbp), %xmm0
	movsd	%xmm0, -11080(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB0_121
# BB#104:                               # %if.end496
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11080(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-5584(%rbp), %rbx
	movq	%rbx, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rbx, %rsi
	movq	%r14, %rdx
	callq	__axpy
	movsd	-11080(%rbp), %xmm1     # xmm1 = mem[0],zero
	movapd	.LCPI0_1(%rip), %xmm0   # xmm0 = [9223372036854775808,9223372036854775808]
	xorpd	%xmm0, %xmm1
	mulsd	-11056(%rbp), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%rbx, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rbx, %rsi
	leaq	-5728(%rbp), %rbx
	movq	%rbx, %rdx
	callq	__axpy
	movsd	-11080(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI0_1(%rip), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r14, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	leaq	-5872(%rbp), %rdx
	callq	__axpy
	movsd	-11056(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI0_1(%rip), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r14, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movsd	-11080(%rbp), %xmm1     # xmm1 = mem[0],zero
	mulsd	-11056(%rbp), %xmm1
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r14, %rdi
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r14, %rsi
	leaq	-6016(%rbp), %rdx
	callq	__axpy
	movl	$0, -11252(%rbp)
	jmp	.LBB0_105
	.align	16, 0x90
.LBB0_109:                              # %for.inc560
                                        #   in Loop: Header=BB0_105 Depth=3
	movslq	-11252(%rbp), %rax
	movsd	-224(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11264(%rbp), %xmm0
	movsd	%xmm0, -224(%rbp,%rax,8)
	incl	-11252(%rbp)
.LBB0_105:                              # %for.cond530
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB0_107 Depth 4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11252(%rbp)
	jge	.LBB0_110
# BB#106:                               # %for.body535
                                        #   in Loop: Header=BB0_105 Depth=3
	movq	$0, -11264(%rbp)
	movl	$0, -11256(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB0_107
	.align	16, 0x90
.LBB0_108:                              # %for.inc550
                                        #   in Loop: Header=BB0_107 Depth=4
	movslq	-11256(%rbp), %rax
	movslq	-11252(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5440(%rbp,%rax,8), %xmm0
	addsd	-11264(%rbp), %xmm0
	movsd	%xmm0, -11264(%rbp)
	incl	-11256(%rbp)
.LBB0_107:                              # %for.cond536
                                        #   Parent Loop BB0_7 Depth=1
                                        #     Parent Loop BB0_62 Depth=2
                                        #       Parent Loop BB0_105 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11256(%rbp)
	jl	.LBB0_108
	jmp	.LBB0_109
	.align	16, 0x90
.LBB0_110:                              # %for.end562
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	movq	%r14, %rdi
	leaq	-224(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -11128(%rbp)
	movq	$0, -11120(%rbp)
	movsd	-11128(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jbe	.LBB0_114
# BB#111:                               # %if.then570
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11128(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorps	%xmm0, %xmm0
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB0_113
# BB#112:                               # %call.sqrt2
                                        #   in Loop: Header=BB0_62 Depth=2
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB0_113:                              # %if.then570.split
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	%xmm0, -11120(%rbp)
.LBB0_114:                              # %if.end572
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-11112(%rbp), %xmm0
	ucomisd	-11120(%rbp), %xmm0
	ja	.LBB0_115
# BB#116:                               # %cond.true588
                                        #   in Loop: Header=BB0_62 Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-8480(%rbp), %rdi
	movq	%r14, %rsi
	callq	__dot
	movsd	%xmm0, -11096(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB0_121
# BB#117:                               # %if.end596
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11096(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_118
	jnp	.LBB0_121
.LBB0_118:                              # %if.end600
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11080(%rbp), %xmm0     # xmm0 = mem[0],zero
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_119
	jnp	.LBB0_121
.LBB0_119:                              # %cond.true613
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	divsd	-11088(%rbp), %xmm1
	movsd	-11056(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11080(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -11104(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB0_121
# BB#120:                               # %if.end621
                                        #   in Loop: Header=BB0_62 Depth=2
	movsd	-11104(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB0_136
	jp	.LBB0_136
	.align	16, 0x90
.LBB0_121:                              # %if.then624
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$1, -11036(%rbp)
.LBB0_122:                              # %for.end640
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$0, -11024(%rbp)
	jmp	.LBB0_123
	.align	16, 0x90
.LBB0_124:                              # %for.inc651
                                        #   in Loop: Header=BB0_123 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movslq	-11024(%rbp), %rax
	movsd	-5584(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	%edx, %ecx
	callq	add_grids
	incl	-11024(%rbp)
.LBB0_123:                              # %for.cond641
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_124
# BB#125:                               # %for.end653
                                        #   in Loop: Header=BB0_7 Depth=1
	cmpl	$0, -11036(%rbp)
	jne	.LBB0_133
# BB#126:                               # %land.lhs.true655
                                        #   in Loop: Header=BB0_7 Depth=1
	cmpl	$0, -11040(%rbp)
	jne	.LBB0_133
# BB#127:                               # %if.then657
                                        #   in Loop: Header=BB0_7 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-5296(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	-11008(%rbp), %r8d
	movl	$14, %edx
	xorpd	%xmm0, %xmm0
	movl	$14, %ecx
	callq	add_grids
	movl	$1, -11024(%rbp)
	jmp	.LBB0_128
	.align	16, 0x90
.LBB0_129:                              # %for.inc670
                                        #   in Loop: Header=BB0_128 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11024(%rbp), %rax
	movsd	-5296(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movl	$14, %edx
	movl	$14, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-11024(%rbp)
.LBB0_128:                              # %for.cond660
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_129
# BB#130:                               # %for.end672
                                        #   in Loop: Header=BB0_7 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-5440(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	-11008(%rbp), %r8d
	movl	$13, %edx
	xorpd	%xmm0, %xmm0
	movl	$13, %ecx
	callq	add_grids
	movl	$1, -11024(%rbp)
	jmp	.LBB0_131
	.align	16, 0x90
.LBB0_132:                              # %for.inc685
                                        #   in Loop: Header=BB0_131 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11024(%rbp), %rax
	movsd	-5440(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movl	$13, %edx
	movl	$13, %ecx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-11024(%rbp)
.LBB0_131:                              # %for.cond675
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11148(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11024(%rbp)
	jl	.LBB0_132
	.align	16, 0x90
.LBB0_133:                              # %if.end688
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	-11148(%rbp), %eax
	addl	%eax, -11016(%rbp)
	movl	-11148(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -11148(%rbp)
	cmpl	$5, %eax
	leaq	-2832(%rbp), %rbx
	jl	.LBB0_7
	jmp	.LBB0_134
.LBB0_101:                              # %if.then476
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$1, -11040(%rbp)
	jmp	.LBB0_122
.LBB0_115:                              # %if.then576
                                        #   in Loop: Header=BB0_7 Depth=1
	movl	$1, -11040(%rbp)
	jmp	.LBB0_122
.LBB0_135:                              # %while.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$4, %ecx
	movl	%edx, %r8d
	callq	mul_grids
	addq	$11320, %rsp            # imm = 0x2C38
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end0:
	.size	TelescopingCABiCGStab, .Lfunc_end0-TelescopingCABiCGStab
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI1_0:
	.quad	4607182418800017408     # double 1
.LCPI1_2:
	.quad	0                       # double 0
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI1_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	CABiCGStab
	.align	16, 0x90
	.type	CABiCGStab,@function
CABiCGStab:                             # @CABiCGStab
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$11336, %rsp            # imm = 0x2C48
.Ltmp11:
	.cfi_offset %rbx, -56
.Ltmp12:
	.cfi_offset %r12, -48
.Ltmp13:
	.cfi_offset %r13, -40
.Ltmp14:
	.cfi_offset %r14, -32
.Ltmp15:
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)
	movl	%esi, -52(%rbp)
	movl	%edx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movsd	%xmm0, -72(%rbp)
	movsd	%xmm1, -80(%rbp)
	movsd	%xmm2, -88(%rbp)
	leaq	-11008(%rbp), %rax
	movq	%rax, -11016(%rbp)
	leaq	-10972(%rbp), %rax
	movq	%rax, -11024(%rbp)
	movl	$200, -11028(%rbp)
	movl	$0, -11032(%rbp)
	movl	$0, -11052(%rbp)
	movl	$0, -11056(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %r8d
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$12, %edx
	callq	residual
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$13, %edx
	movl	$12, %ecx
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$14, %edx
	movl	$12, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$12, %edx
	callq	norm
	movsd	%xmm0, -11160(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB1_2
	jp	.LBB1_2
# BB#1:                                 # %if.then
	movl	$1, -11056(%rbp)
.LBB1_2:                                # %if.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$13, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -11104(%rbp)
	ucomisd	.LCPI1_2, %xmm0
	jne	.LBB1_4
	jp	.LBB1_4
# BB#3:                                 # %if.then6
	movl	$1, -11056(%rbp)
.LBB1_4:                                # %if.end7
	movsd	-11104(%rbp), %xmm1     # xmm1 = mem[0],zero
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB1_6
# BB#5:                                 # %call.sqrt
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB1_6:                                # %if.end7.split
	movsd	%xmm0, -11128(%rbp)
	movl	$4, -11164(%rbp)
	movl	$0, -11040(%rbp)
	jmp	.LBB1_7
	.align	16, 0x90
.LBB1_11:                               # %for.inc17
                                        #   in Loop: Header=BB1_7 Depth=1
	incl	-11040(%rbp)
.LBB1_7:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_9 Depth 2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jge	.LBB1_12
# BB#8:                                 # %for.body
                                        #   in Loop: Header=BB1_7 Depth=1
	movl	$0, -11044(%rbp)
	jmp	.LBB1_9
	.align	16, 0x90
.LBB1_10:                               # %for.inc
                                        #   in Loop: Header=BB1_9 Depth=2
	movslq	-11044(%rbp), %rax
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-11044(%rbp)
.LBB1_9:                                # %for.cond10
                                        #   Parent Loop BB1_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11044(%rbp)
	jl	.LBB1_10
	jmp	.LBB1_11
.LBB1_12:                               # %for.end19
	movl	$0, -11040(%rbp)
	jmp	.LBB1_13
	.align	16, 0x90
.LBB1_17:                               # %for.inc37
                                        #   in Loop: Header=BB1_13 Depth=1
	incl	-11040(%rbp)
.LBB1_13:                               # %for.cond20
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_15 Depth 2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jge	.LBB1_18
# BB#14:                                # %for.body24
                                        #   in Loop: Header=BB1_13 Depth=1
	movl	$0, -11044(%rbp)
	jmp	.LBB1_15
	.align	16, 0x90
.LBB1_16:                               # %for.inc34
                                        #   in Loop: Header=BB1_15 Depth=2
	movslq	-11044(%rbp), %rax
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-5152(%rbp,%rcx), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-11044(%rbp)
.LBB1_15:                               # %for.cond25
                                        #   Parent Loop BB1_13 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11044(%rbp)
	jl	.LBB1_16
	jmp	.LBB1_17
.LBB1_18:                               # %for.end39
	movl	$0, -11040(%rbp)
	leaq	-2832(%rbp), %rax
	movabsq	$4607182418800017408, %r15 # imm = 0x3FF0000000000000
	jmp	.LBB1_19
	.align	16, 0x90
.LBB1_20:                               # %for.inc49
                                        #   in Loop: Header=BB1_19 Depth=1
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rdx
	addq	%rax, %rdx
	movq	%r15, 136(%rdx,%rcx,8)
	incl	-11040(%rbp)
.LBB1_19:                               # %for.cond40
                                        # =>This Inner Loop Header: Depth=1
	movl	-11164(%rbp), %ecx
	addl	%ecx, %ecx
	cmpl	%ecx, -11040(%rbp)
	jl	.LBB1_20
# BB#21:                                # %for.end51
	movl	-11164(%rbp), %ecx
	leal	1(%rcx,%rcx), %ecx
	movl	%ecx, -11040(%rbp)
	jmp	.LBB1_22
	.align	16, 0x90
.LBB1_23:                               # %for.inc63
                                        #   in Loop: Header=BB1_22 Depth=1
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rdx
	addq	%rax, %rdx
	movq	%r15, 136(%rdx,%rcx,8)
	incl	-11040(%rbp)
.LBB1_22:                               # %for.cond54
                                        # =>This Inner Loop Header: Depth=1
	movl	-11164(%rbp), %ecx
	shll	$2, %ecx
	cmpl	%ecx, -11040(%rbp)
	jl	.LBB1_23
# BB#24:                                # %for.end65
	movl	$0, -11040(%rbp)
	leaq	-5152(%rbp), %rax
	jmp	.LBB1_25
	.align	16, 0x90
.LBB1_26:                               # %for.inc75
                                        #   in Loop: Header=BB1_25 Depth=1
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rdx
	addq	%rax, %rdx
	movq	%r15, 272(%rdx,%rcx,8)
	incl	-11040(%rbp)
.LBB1_25:                               # %for.cond66
                                        # =>This Inner Loop Header: Depth=1
	movl	-11164(%rbp), %ecx
	leal	-1(%rcx,%rcx), %ecx
	cmpl	%ecx, -11040(%rbp)
	jl	.LBB1_26
# BB#27:                                # %for.end77
	movl	-11164(%rbp), %ecx
	leal	1(%rcx,%rcx), %ecx
	movl	%ecx, -11040(%rbp)
	jmp	.LBB1_28
	.align	16, 0x90
.LBB1_29:                               # %for.inc90
                                        #   in Loop: Header=BB1_28 Depth=1
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rdx
	addq	%rax, %rdx
	movq	%r15, 272(%rdx,%rcx,8)
	incl	-11040(%rbp)
.LBB1_28:                               # %for.cond80
                                        # =>This Inner Loop Header: Depth=1
	movl	-11164(%rbp), %ecx
	leal	-1(,%rcx,4), %ecx
	cmpl	%ecx, -11040(%rbp)
	jl	.LBB1_29
# BB#30:                                # %for.end92
	movl	$0, -11040(%rbp)
	jmp	.LBB1_31
	.align	16, 0x90
.LBB1_32:                               # %for.inc101
                                        #   in Loop: Header=BB1_31 Depth=1
	movslq	-11040(%rbp), %rax
	leal	15(%rax), %ecx
	movl	%ecx, -11008(%rbp,%rax,4)
	incl	-11040(%rbp)
.LBB1_31:                               # %for.cond93
                                        # =>This Inner Loop Header: Depth=1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_32
# BB#33:                                # %for.end103
	movslq	-11164(%rbp), %rax
	shlq	$4, %rax
	leaq	-11008(%rbp), %rcx
	movl	$12, 4(%rax,%rcx)
	leaq	-5296(%rbp), %r12
	leaq	-5440(%rbp), %r13
	jmp	.LBB1_34
	.align	16, 0x90
.LBB1_132:                              # %if.end687
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	-11164(%rbp), %eax
	addl	%eax, -11032(%rbp)
	movabsq	$4607182418800017408, %r15 # imm = 0x3FF0000000000000
.LBB1_34:                               # %while.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_40 Depth 2
                                        #     Child Loop BB1_43 Depth 2
                                        #     Child Loop BB1_46 Depth 2
                                        #       Child Loop BB1_48 Depth 3
                                        #     Child Loop BB1_52 Depth 2
                                        #     Child Loop BB1_55 Depth 2
                                        #     Child Loop BB1_58 Depth 2
                                        #     Child Loop BB1_61 Depth 2
                                        #       Child Loop BB1_63 Depth 3
                                        #         Child Loop BB1_65 Depth 4
                                        #       Child Loop BB1_69 Depth 3
                                        #         Child Loop BB1_71 Depth 4
                                        #       Child Loop BB1_75 Depth 3
                                        #         Child Loop BB1_77 Depth 4
                                        #       Child Loop BB1_83 Depth 3
                                        #         Child Loop BB1_85 Depth 4
                                        #       Child Loop BB1_89 Depth 3
                                        #         Child Loop BB1_91 Depth 4
                                        #       Child Loop BB1_104 Depth 3
                                        #         Child Loop BB1_106 Depth 4
                                        #     Child Loop BB1_122 Depth 2
                                        #     Child Loop BB1_127 Depth 2
                                        #     Child Loop BB1_130 Depth 2
	movl	-11032(%rbp), %eax
	cmpl	-11028(%rbp), %eax
	jge	.LBB1_35
# BB#36:                                # %land.lhs.true
                                        #   in Loop: Header=BB1_34 Depth=1
	cmpl	$0, -11052(%rbp)
	je	.LBB1_37
.LBB1_35:                               #   in Loop: Header=BB1_34 Depth=1
	movq	%r12, %rbx
	xorl	%eax, %eax
	jmp	.LBB1_38
.LBB1_37:                               # %land.rhs
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	%r12, %rbx
	cmpl	$0, -11056(%rbp)
	sete	%al
	.align	16, 0x90
.LBB1_38:                               # %land.end
                                        #   in Loop: Header=BB1_34 Depth=1
	testb	%al, %al
	je	.LBB1_133
# BB#39:                                # %while.body
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	movq	%rbx, %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	movq	%r13, %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5584(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5728(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-5872(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-6016(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-224(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-368(%rbp), %rdi
	callq	__zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %esi
	leaq	-512(%rbp), %rdi
	callq	__zero
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-11016(%rbp), %rax
	movl	(%rax), %edx
	movl	$14, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -11036(%rbp)
	jmp	.LBB1_40
	.align	16, 0x90
.LBB1_41:                               # %for.inc148
                                        #   in Loop: Header=BB1_40 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11036(%rbp), %rax
	movq	-11016(%rbp), %rcx
	movl	-4(%rcx,%rax,4), %r8d
	movl	$10, %edx
	movl	$4, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	mul_grids
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11036(%rbp), %rax
	movq	-11016(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$10, %ecx
	callq	apply_op
	incl	-11036(%rbp)
.LBB1_40:                               # %for.cond138
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(%rax,%rax), %eax
	cmpl	%eax, -11036(%rbp)
	jl	.LBB1_41
# BB#42:                                # %for.end150
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-11024(%rbp), %rax
	movl	(%rax), %edx
	movl	$13, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -11036(%rbp)
	jmp	.LBB1_43
	.align	16, 0x90
.LBB1_44:                               # %for.inc161
                                        #   in Loop: Header=BB1_43 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11036(%rbp), %rax
	movq	-11024(%rbp), %rcx
	movl	-4(%rcx,%rax,4), %r8d
	movl	$10, %edx
	movl	$4, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	mul_grids
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11036(%rbp), %rax
	movq	-11024(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$10, %ecx
	callq	apply_op
	incl	-11036(%rbp)
.LBB1_43:                               # %for.cond152
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	addl	%eax, %eax
	cmpl	%eax, -11036(%rbp)
	jl	.LBB1_44
# BB#45:                                # %for.end163
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	-48(%rbp), %rax
	incl	1316(%rax)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %r9d
	leal	2(,%rax,4), %eax
	movl	%eax, (%rsp)
	movl	$1, 8(%rsp)
	leaq	-10928(%rbp), %rdx
	leaq	-11008(%rbp), %rcx
	movq	%rcx, %r8
	callq	matmul_grids
	movl	$0, -11040(%rbp)
	movl	$0, -11048(%rbp)
	jmp	.LBB1_46
	.align	16, 0x90
.LBB1_50:                               # %for.inc197
                                        #   in Loop: Header=BB1_46 Depth=2
	movslq	-11048(%rbp), %rax
	leal	1(%rax), %ecx
	movl	%ecx, -11048(%rbp)
	movsd	-10928(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	movslq	-11040(%rbp), %rax
	movsd	%xmm0, -8480(%rbp,%rax,8)
	incl	-11040(%rbp)
.LBB1_46:                               # %for.cond172
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB1_48 Depth 3
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jge	.LBB1_51
# BB#47:                                # %for.body176
                                        #   in Loop: Header=BB1_46 Depth=2
	movl	$0, -11044(%rbp)
	jmp	.LBB1_48
	.align	16, 0x90
.LBB1_49:                               # %for.inc189
                                        #   in Loop: Header=BB1_48 Depth=3
	movslq	-11048(%rbp), %rax
	leal	1(%rax), %ecx
	movl	%ecx, -11048(%rbp)
	movsd	-10928(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	movslq	-11044(%rbp), %rax
	movslq	-11040(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-11044(%rbp)
.LBB1_48:                               # %for.cond177
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_46 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11044(%rbp)
	jl	.LBB1_49
	jmp	.LBB1_50
	.align	16, 0x90
.LBB1_51:                               # %for.end199
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$0, -11040(%rbp)
	jmp	.LBB1_52
	.align	16, 0x90
.LBB1_53:                               # %for.inc207
                                        #   in Loop: Header=BB1_52 Depth=2
	movslq	-11040(%rbp), %rax
	movq	$0, -5296(%rbp,%rax,8)
	incl	-11040(%rbp)
.LBB1_52:                               # %for.cond200
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_53
# BB#54:                                # %for.end209
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	%r15, -5296(%rbp)
	movl	$0, -11040(%rbp)
	jmp	.LBB1_55
	.align	16, 0x90
.LBB1_56:                               # %for.inc218
                                        #   in Loop: Header=BB1_55 Depth=2
	movslq	-11040(%rbp), %rax
	movq	$0, -5440(%rbp,%rax,8)
	incl	-11040(%rbp)
.LBB1_55:                               # %for.cond211
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_56
# BB#57:                                # %for.end220
                                        #   in Loop: Header=BB1_34 Depth=1
	movslq	-11164(%rbp), %rax
	shlq	$4, %rax
	movq	%r15, 8(%rax,%r13)
	movl	$0, -11040(%rbp)
	movq	%rbx, %r12
	leaq	-5584(%rbp), %rbx
	movq	%rbx, %r15
	leaq	-5728(%rbp), %rbx
	jmp	.LBB1_58
	.align	16, 0x90
.LBB1_59:                               # %for.inc232
                                        #   in Loop: Header=BB1_58 Depth=2
	movslq	-11040(%rbp), %rax
	movq	$0, -5584(%rbp,%rax,8)
	incl	-11040(%rbp)
.LBB1_58:                               # %for.cond225
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_59
# BB#60:                                # %for.end234
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$0, -11036(%rbp)
	jmp	.LBB1_61
	.align	16, 0x90
.LBB1_134:                              # %for.inc637
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11120(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r12, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	movq	%r12, %rdx
	callq	__axpy
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI1_1(%rip), %xmm1
	mulsd	-11120(%rbp), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r12, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r12, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movsd	-11112(%rbp), %xmm0     # xmm0 = mem[0],zero
	movsd	%xmm0, -11104(%rbp)
	incl	-11036(%rbp)
.LBB1_61:                               # %for.cond235
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB1_63 Depth 3
                                        #         Child Loop BB1_65 Depth 4
                                        #       Child Loop BB1_69 Depth 3
                                        #         Child Loop BB1_71 Depth 4
                                        #       Child Loop BB1_75 Depth 3
                                        #         Child Loop BB1_77 Depth 4
                                        #       Child Loop BB1_83 Depth 3
                                        #         Child Loop BB1_85 Depth 4
                                        #       Child Loop BB1_89 Depth 3
                                        #         Child Loop BB1_91 Depth 4
                                        #       Child Loop BB1_104 Depth 3
                                        #         Child Loop BB1_106 Depth 4
	movl	-11036(%rbp), %eax
	cmpl	-11164(%rbp), %eax
	xorpd	%xmm1, %xmm1
	jge	.LBB1_121
# BB#62:                                # %for.body237
                                        #   in Loop: Header=BB1_61 Depth=2
	movq	-48(%rbp), %rax
	incl	1312(%rax)
	movl	$0, -11168(%rbp)
	jmp	.LBB1_63
	.align	16, 0x90
.LBB1_67:                               # %for.inc267
                                        #   in Loop: Header=BB1_63 Depth=3
	movslq	-11168(%rbp), %rax
	movsd	-5728(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11184(%rbp), %xmm0
	movsd	%xmm0, -5728(%rbp,%rax,8)
	incl	-11168(%rbp)
.LBB1_63:                               # %for.cond239
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_65 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11168(%rbp)
	jge	.LBB1_68
# BB#64:                                # %for.body243
                                        #   in Loop: Header=BB1_63 Depth=3
	movq	$0, -11184(%rbp)
	movl	$0, -11172(%rbp)
	jmp	.LBB1_65
	.align	16, 0x90
.LBB1_66:                               # %for.inc257
                                        #   in Loop: Header=BB1_65 Depth=4
	movslq	-11172(%rbp), %rax
	movslq	-11168(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5296(%rbp,%rax,8), %xmm0
	addsd	-11184(%rbp), %xmm0
	movsd	%xmm0, -11184(%rbp)
	incl	-11172(%rbp)
.LBB1_65:                               # %for.cond244
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_63 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11172(%rbp)
	jl	.LBB1_66
	jmp	.LBB1_67
	.align	16, 0x90
.LBB1_68:                               # %for.end269
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	$0, -11188(%rbp)
	jmp	.LBB1_69
	.align	16, 0x90
.LBB1_73:                               # %for.inc301
                                        #   in Loop: Header=BB1_69 Depth=3
	movslq	-11188(%rbp), %rax
	movsd	-5872(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11200(%rbp), %xmm0
	movsd	%xmm0, -5872(%rbp,%rax,8)
	incl	-11188(%rbp)
.LBB1_69:                               # %for.cond273
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_71 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11188(%rbp)
	jge	.LBB1_74
# BB#70:                                # %for.body277
                                        #   in Loop: Header=BB1_69 Depth=3
	movq	$0, -11200(%rbp)
	movl	$0, -11192(%rbp)
	jmp	.LBB1_71
	.align	16, 0x90
.LBB1_72:                               # %for.inc291
                                        #   in Loop: Header=BB1_71 Depth=4
	movslq	-11192(%rbp), %rax
	movslq	-11188(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-2832(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5440(%rbp,%rax,8), %xmm0
	addsd	-11200(%rbp), %xmm0
	movsd	%xmm0, -11200(%rbp)
	incl	-11192(%rbp)
.LBB1_71:                               # %for.cond278
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_69 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11192(%rbp)
	jl	.LBB1_72
	jmp	.LBB1_73
	.align	16, 0x90
.LBB1_74:                               # %for.end303
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	$0, -11204(%rbp)
	jmp	.LBB1_75
	.align	16, 0x90
.LBB1_79:                               # %for.inc335
                                        #   in Loop: Header=BB1_75 Depth=3
	movslq	-11204(%rbp), %rax
	movsd	-6016(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11216(%rbp), %xmm0
	movsd	%xmm0, -6016(%rbp,%rax,8)
	incl	-11204(%rbp)
.LBB1_75:                               # %for.cond307
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_77 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11204(%rbp)
	jge	.LBB1_80
# BB#76:                                # %for.body311
                                        #   in Loop: Header=BB1_75 Depth=3
	movq	$0, -11216(%rbp)
	movl	$0, -11208(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB1_77
	.align	16, 0x90
.LBB1_78:                               # %for.inc325
                                        #   in Loop: Header=BB1_77 Depth=4
	movslq	-11208(%rbp), %rax
	movslq	-11204(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-5152(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5296(%rbp,%rax,8), %xmm0
	addsd	-11216(%rbp), %xmm0
	movsd	%xmm0, -11216(%rbp)
	incl	-11208(%rbp)
.LBB1_77:                               # %for.cond312
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_75 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11208(%rbp)
	jl	.LBB1_78
	jmp	.LBB1_79
	.align	16, 0x90
.LBB1_80:                               # %for.end337
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-8480(%rbp), %rdi
	movq	%rbx, %rsi
	callq	__dot
	movsd	%xmm0, -11064(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB1_81
	jnp	.LBB1_120
.LBB1_81:                               # %cond.true348
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11104(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11064(%rbp), %xmm0
	movsd	%xmm0, -11072(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB1_120
# BB#82:                                # %if.end356
                                        #   in Loop: Header=BB1_61 Depth=2
	movq	%rbx, %r14
	movq	%r15, %r12
	movsd	-11072(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI1_1(%rip), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-224(%rbp), %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	leaq	-5872(%rbp), %rsi
	leaq	-6016(%rbp), %rdx
	callq	__axpy
	movl	$0, -11220(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB1_83
	.align	16, 0x90
.LBB1_87:                               # %for.inc396
                                        #   in Loop: Header=BB1_83 Depth=3
	movslq	-11220(%rbp), %rax
	movsd	-368(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11232(%rbp), %xmm0
	movsd	%xmm0, -368(%rbp,%rax,8)
	incl	-11220(%rbp)
.LBB1_83:                               # %for.cond366
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_85 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11220(%rbp)
	jge	.LBB1_88
# BB#84:                                # %for.body371
                                        #   in Loop: Header=BB1_83 Depth=3
	movq	$0, -11232(%rbp)
	movl	$0, -11224(%rbp)
	jmp	.LBB1_85
	.align	16, 0x90
.LBB1_86:                               # %for.inc386
                                        #   in Loop: Header=BB1_85 Depth=4
	movslq	-11224(%rbp), %rax
	movslq	-11220(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-224(%rbp,%rax,8), %xmm0
	addsd	-11232(%rbp), %xmm0
	movsd	%xmm0, -11232(%rbp)
	incl	-11224(%rbp)
.LBB1_85:                               # %for.cond372
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_83 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11224(%rbp)
	jl	.LBB1_86
	jmp	.LBB1_87
	.align	16, 0x90
.LBB1_88:                               # %for.end398
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11072(%rbp), %xmm1     # xmm1 = mem[0],zero
	movapd	.LCPI1_1(%rip), %xmm0   # xmm0 = [9223372036854775808,9223372036854775808]
	xorpd	%xmm0, %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	leaq	-512(%rbp), %rbx
	movq	%rbx, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	movq	%r14, %rdx
	callq	__axpy
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	movq	%rbx, %rdi
	leaq	-368(%rbp), %r15
	movq	%r15, %rsi
	callq	__dot
	movsd	%xmm0, -11080(%rbp)
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-224(%rbp), %rbx
	movq	%rbx, %rdi
	movq	%r15, %rsi
	callq	__dot
	movsd	%xmm0, -11088(%rbp)
	movsd	-11072(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r12, %r15
	movq	%r15, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r15, %rsi
	leaq	-5296(%rbp), %r12
	movq	%r12, %rdx
	callq	__axpy
	movsd	-11072(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI1_1(%rip), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%rbx, %rdi
	movq	%r14, %rbx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movl	$0, -11236(%rbp)
	jmp	.LBB1_89
	.align	16, 0x90
.LBB1_93:                               # %for.inc459
                                        #   in Loop: Header=BB1_89 Depth=3
	movslq	-11236(%rbp), %rax
	movsd	-368(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11248(%rbp), %xmm0
	movsd	%xmm0, -368(%rbp,%rax,8)
	incl	-11236(%rbp)
.LBB1_89:                               # %for.cond429
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_91 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11236(%rbp)
	jge	.LBB1_94
# BB#90:                                # %for.body434
                                        #   in Loop: Header=BB1_89 Depth=3
	movq	$0, -11248(%rbp)
	movl	$0, -11240(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB1_91
	.align	16, 0x90
.LBB1_92:                               # %for.inc449
                                        #   in Loop: Header=BB1_91 Depth=4
	movslq	-11240(%rbp), %rax
	movslq	-11236(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-224(%rbp,%rax,8), %xmm0
	addsd	-11248(%rbp), %xmm0
	movsd	%xmm0, -11248(%rbp)
	incl	-11240(%rbp)
.LBB1_91:                               # %for.cond435
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_89 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11240(%rbp)
	jl	.LBB1_92
	jmp	.LBB1_93
	.align	16, 0x90
.LBB1_94:                               # %for.end461
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-224(%rbp), %rdi
	leaq	-368(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -11152(%rbp)
	xorpd	%xmm2, %xmm2
	ucomisd	%xmm0, %xmm2
	jbe	.LBB1_96
# BB#95:                                # %if.then469
                                        #   in Loop: Header=BB1_61 Depth=2
	movq	$0, -11152(%rbp)
	jmp	.LBB1_99
	.align	16, 0x90
.LBB1_96:                               # %if.else
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11152(%rbp), %xmm1     # xmm1 = mem[0],zero
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB1_98
# BB#97:                                # %call.sqrt1
                                        #   in Loop: Header=BB1_61 Depth=2
	movapd	%xmm1, %xmm0
	callq	sqrt
	xorpd	%xmm2, %xmm2
.LBB1_98:                               # %if.else.split
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	%xmm0, -11152(%rbp)
.LBB1_99:                               # %if.end471
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-11128(%rbp), %xmm0
	ucomisd	-11152(%rbp), %xmm0
	ja	.LBB1_100
# BB#101:                               # %if.end476
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11088(%rbp), %xmm0     # xmm0 = mem[0],zero
	ucomisd	%xmm2, %xmm0
	jne	.LBB1_102
	jnp	.LBB1_120
.LBB1_102:                              # %cond.true487
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11080(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11088(%rbp), %xmm0
	movsd	%xmm0, -11096(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB1_120
# BB#103:                               # %if.end495
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r15, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r15, %rsi
	movq	%r13, %rdx
	callq	__axpy
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	movapd	.LCPI1_1(%rip), %xmm0   # xmm0 = [9223372036854775808,9223372036854775808]
	xorpd	%xmm0, %xmm1
	mulsd	-11072(%rbp), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r15, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r15, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI1_1(%rip), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r13, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	leaq	-5872(%rbp), %rdx
	callq	__axpy
	movsd	-11072(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorpd	.LCPI1_1(%rip), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r13, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	movq	%rbx, %rdx
	callq	__axpy
	movsd	-11096(%rbp), %xmm1     # xmm1 = mem[0],zero
	mulsd	-11072(%rbp), %xmm1
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %ecx
	movq	%r13, %rdi
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r13, %rsi
	leaq	-6016(%rbp), %rdx
	callq	__axpy
	movl	$0, -11252(%rbp)
	jmp	.LBB1_104
	.align	16, 0x90
.LBB1_108:                              # %for.inc559
                                        #   in Loop: Header=BB1_104 Depth=3
	movslq	-11252(%rbp), %rax
	movsd	-224(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	addsd	-11264(%rbp), %xmm0
	movsd	%xmm0, -224(%rbp,%rax,8)
	incl	-11252(%rbp)
.LBB1_104:                              # %for.cond529
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB1_106 Depth 4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11252(%rbp)
	jge	.LBB1_109
# BB#105:                               # %for.body534
                                        #   in Loop: Header=BB1_104 Depth=3
	movq	$0, -11264(%rbp)
	movl	$0, -11256(%rbp)
	xorpd	%xmm1, %xmm1
	jmp	.LBB1_106
	.align	16, 0x90
.LBB1_107:                              # %for.inc549
                                        #   in Loop: Header=BB1_106 Depth=4
	movslq	-11256(%rbp), %rax
	movslq	-11252(%rbp), %rcx
	imulq	$136, %rcx, %rcx
	leaq	-8336(%rbp,%rcx), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-5440(%rbp,%rax,8), %xmm0
	addsd	-11264(%rbp), %xmm0
	movsd	%xmm0, -11264(%rbp)
	incl	-11256(%rbp)
.LBB1_106:                              # %for.cond535
                                        #   Parent Loop BB1_34 Depth=1
                                        #     Parent Loop BB1_61 Depth=2
                                        #       Parent Loop BB1_104 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11256(%rbp)
	jl	.LBB1_107
	jmp	.LBB1_108
	.align	16, 0x90
.LBB1_109:                              # %for.end561
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	movq	%r13, %rdi
	leaq	-224(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -11144(%rbp)
	movq	$0, -11136(%rbp)
	movsd	-11144(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jbe	.LBB1_113
# BB#110:                               # %if.then569
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11144(%rbp), %xmm1     # xmm1 = mem[0],zero
	xorps	%xmm0, %xmm0
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB1_112
# BB#111:                               # %call.sqrt2
                                        #   in Loop: Header=BB1_61 Depth=2
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB1_112:                              # %if.then569.split
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	%xmm0, -11136(%rbp)
.LBB1_113:                              # %if.end571
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-11128(%rbp), %xmm0
	ucomisd	-11136(%rbp), %xmm0
	ja	.LBB1_114
# BB#115:                               # %cond.true587
                                        #   in Loop: Header=BB1_61 Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %edx
	leaq	-8480(%rbp), %rdi
	movq	%r13, %rsi
	callq	__dot
	movsd	%xmm0, -11112(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB1_120
# BB#116:                               # %if.end595
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11112(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB1_117
	jnp	.LBB1_120
.LBB1_117:                              # %if.end599
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11096(%rbp), %xmm0     # xmm0 = mem[0],zero
	ucomisd	%xmm1, %xmm0
	jne	.LBB1_118
	jnp	.LBB1_120
.LBB1_118:                              # %cond.true612
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11112(%rbp), %xmm1     # xmm1 = mem[0],zero
	divsd	-11104(%rbp), %xmm1
	movsd	-11072(%rbp), %xmm0     # xmm0 = mem[0],zero
	divsd	-11096(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -11120(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB1_120
# BB#119:                               # %if.end620
                                        #   in Loop: Header=BB1_61 Depth=2
	movsd	-11120(%rbp), %xmm0     # xmm0 = mem[0],zero
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB1_134
	jp	.LBB1_134
	.align	16, 0x90
.LBB1_120:                              # %if.then623
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$1, -11052(%rbp)
.LBB1_121:                              # %for.end639
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$0, -11040(%rbp)
	jmp	.LBB1_122
	.align	16, 0x90
.LBB1_123:                              # %for.inc650
                                        #   in Loop: Header=BB1_122 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movslq	-11040(%rbp), %rax
	movsd	-5584(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	%edx, %ecx
	callq	add_grids
	incl	-11040(%rbp)
.LBB1_122:                              # %for.cond640
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_123
# BB#124:                               # %for.end652
                                        #   in Loop: Header=BB1_34 Depth=1
	cmpl	$0, -11052(%rbp)
	jne	.LBB1_132
# BB#125:                               # %land.lhs.true654
                                        #   in Loop: Header=BB1_34 Depth=1
	cmpl	$0, -11056(%rbp)
	jne	.LBB1_132
# BB#126:                               # %if.then656
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-5296(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	-11008(%rbp), %r8d
	movl	$14, %edx
	xorpd	%xmm0, %xmm0
	movl	$14, %ecx
	callq	add_grids
	movl	$1, -11040(%rbp)
	jmp	.LBB1_127
	.align	16, 0x90
.LBB1_128:                              # %for.inc669
                                        #   in Loop: Header=BB1_127 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11040(%rbp), %rax
	movsd	-5296(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movl	$14, %edx
	movl	$14, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-11040(%rbp)
.LBB1_127:                              # %for.cond659
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_128
# BB#129:                               # %for.end671
                                        #   in Loop: Header=BB1_34 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-5440(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	-11008(%rbp), %r8d
	movl	$13, %edx
	xorpd	%xmm0, %xmm0
	movl	$13, %ecx
	callq	add_grids
	movl	$1, -11040(%rbp)
	jmp	.LBB1_130
	.align	16, 0x90
.LBB1_131:                              # %for.inc684
                                        #   in Loop: Header=BB1_130 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-11040(%rbp), %rax
	movsd	-5440(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-11008(%rbp,%rax,4), %r8d
	movl	$13, %edx
	movl	$13, %ecx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-11040(%rbp)
.LBB1_130:                              # %for.cond674
                                        #   Parent Loop BB1_34 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-11164(%rbp), %eax
	leal	1(,%rax,4), %eax
	cmpl	%eax, -11040(%rbp)
	jl	.LBB1_131
	jmp	.LBB1_132
.LBB1_100:                              # %if.then475
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$1, -11056(%rbp)
	jmp	.LBB1_121
.LBB1_114:                              # %if.then575
                                        #   in Loop: Header=BB1_34 Depth=1
	movl	$1, -11056(%rbp)
	jmp	.LBB1_121
.LBB1_133:                              # %while.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$4, %ecx
	movl	%edx, %r8d
	callq	mul_grids
	addq	$11336, %rsp            # imm = 0x2C48
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end1:
	.size	CABiCGStab, .Lfunc_end1-CABiCGStab
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI2_0:
	.quad	4607182418800017408     # double 1
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI2_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	BiCGStab
	.align	16, 0x90
	.type	BiCGStab,@function
BiCGStab:                               # @BiCGStab
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
	subq	$160, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movsd	%xmm0, -32(%rbp)
	movsd	%xmm1, -40(%rbp)
	movsd	%xmm2, -48(%rbp)
	movl	$200, -52(%rbp)
	movl	$0, -56(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -64(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %ecx
	movl	-20(%rbp), %r8d
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$12, %edx
	callq	residual
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$13, %edx
	movl	$12, %ecx
	callq	scale_grid
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$14, %edx
	movl	$12, %ecx
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -72(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	callq	norm
	movsd	%xmm0, -80(%rbp)
	movsd	-72(%rbp), %xmm1        # xmm1 = mem[0],zero
	xorpd	%xmm0, %xmm0
	ucomisd	%xmm0, %xmm1
	jne	.LBB2_2
	jp	.LBB2_2
# BB#1:                                 # %if.then
	movl	$1, -64(%rbp)
.LBB2_2:                                # %if.end
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	ucomisd	%xmm0, %xmm1
	jne	.LBB2_4
	jp	.LBB2_4
# BB#3:                                 # %if.then3
	movl	$1, -64(%rbp)
	jmp	.LBB2_4
	.align	16, 0x90
.LBB2_28:                               # %if.end89
                                        #   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-128(%rbp), %xmm1       # xmm1 = mem[0],zero
	xorpd	.LCPI2_1(%rip), %xmm1
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$10, %edx
	movl	$14, %ecx
	movl	$16, %r8d
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-152(%rbp), %xmm1       # xmm1 = mem[0],zero
	movl	$14, %edx
	movl	$13, %ecx
	movl	$10, %r8d
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	movsd	-144(%rbp), %xmm0       # xmm0 = mem[0],zero
	movsd	%xmm0, -72(%rbp)
.LBB2_4:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-56(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jge	.LBB2_5
# BB#6:                                 # %land.lhs.true
                                        #   in Loop: Header=BB2_4 Depth=1
	cmpl	$0, -60(%rbp)
	je	.LBB2_8
# BB#7:                                 #   in Loop: Header=BB2_4 Depth=1
	xorl	%eax, %eax
	jmp	.LBB2_9
	.align	16, 0x90
.LBB2_5:                                #   in Loop: Header=BB2_4 Depth=1
	xorl	%eax, %eax
	jmp	.LBB2_9
.LBB2_8:                                # %land.rhs
                                        #   in Loop: Header=BB2_4 Depth=1
	cmpl	$0, -64(%rbp)
	sete	%al
	.align	16, 0x90
.LBB2_9:                                # %land.end
                                        #   in Loop: Header=BB2_4 Depth=1
	testb	%al, %al
	je	.LBB2_27
# BB#10:                                # %while.body
                                        #   in Loop: Header=BB2_4 Depth=1
	incl	-56(%rbp)
	movq	-8(%rbp), %rax
	incl	1312(%rax)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$10, %edx
	movl	$4, %ecx
	movl	$14, %r8d
	callq	mul_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$16, %edx
	movl	$10, %ecx
	callq	apply_op
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$16, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -88(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB2_11
	jnp	.LBB2_26
.LBB2_11:                               # %cond.true14
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	divsd	-88(%rbp), %xmm0
	movsd	%xmm0, -96(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB2_26
# BB#12:                                # %if.end22
                                        #   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movsd	-96(%rbp), %xmm1        # xmm1 = mem[0],zero
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$14, %r8d
	movl	%edx, %ecx
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-96(%rbp), %xmm1        # xmm1 = mem[0],zero
	xorpd	.LCPI2_1(%rip), %xmm1
	movl	$15, %edx
	movl	$13, %ecx
	movl	$16, %r8d
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$15, %edx
	callq	norm
	movsd	%xmm0, -104(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB2_14
	jp	.LBB2_14
	jmp	.LBB2_13
.LBB2_14:                               # %if.end27
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-48(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-80(%rbp), %xmm0
	ucomisd	-104(%rbp), %xmm0
	ja	.LBB2_15
# BB#16:                                # %if.end31
                                        #   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$10, %edx
	movl	$4, %ecx
	movl	$15, %r8d
	callq	mul_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$17, %edx
	movl	$10, %ecx
	callq	apply_op
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$17, %edx
	movl	$17, %ecx
	callq	dot
	movsd	%xmm0, -112(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$17, %edx
	movl	$15, %ecx
	callq	dot
	movsd	%xmm0, -120(%rbp)
	movsd	-112(%rbp), %xmm1       # xmm1 = mem[0],zero
	xorpd	%xmm0, %xmm0
	ucomisd	%xmm0, %xmm1
	jne	.LBB2_18
	jp	.LBB2_18
	jmp	.LBB2_17
.LBB2_18:                               # %if.end37
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-120(%rbp), %xmm1       # xmm1 = mem[0],zero
	divsd	-112(%rbp), %xmm1
	movsd	%xmm1, -128(%rbp)
	ucomisd	%xmm0, %xmm1
	jne	.LBB2_19
	jnp	.LBB2_26
.LBB2_19:                               # %cond.true48
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-128(%rbp), %xmm0       # xmm0 = mem[0],zero
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB2_26
# BB#20:                                # %if.end56
                                        #   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movsd	-128(%rbp), %xmm1       # xmm1 = mem[0],zero
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$15, %r8d
	movl	%edx, %ecx
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-128(%rbp), %xmm1       # xmm1 = mem[0],zero
	xorpd	.LCPI2_1(%rip), %xmm1
	movl	$13, %edx
	movl	$15, %ecx
	movl	$17, %r8d
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	callq	norm
	movsd	%xmm0, -136(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB2_22
	jp	.LBB2_22
	jmp	.LBB2_21
.LBB2_22:                               # %if.end62
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-48(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-80(%rbp), %xmm0
	ucomisd	-136(%rbp), %xmm0
	ja	.LBB2_23
# BB#24:                                # %if.end67
                                        #   in Loop: Header=BB2_4 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -144(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB2_25
	jnp	.LBB2_26
.LBB2_25:                               # %cond.true81
                                        #   in Loop: Header=BB2_4 Depth=1
	movsd	-144(%rbp), %xmm1       # xmm1 = mem[0],zero
	divsd	-72(%rbp), %xmm1
	movsd	-96(%rbp), %xmm0        # xmm0 = mem[0],zero
	divsd	-128(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -152(%rbp)
	callq	__isinf
	testl	%eax, %eax
	je	.LBB2_28
.LBB2_26:                               # %if.then88
	movl	$1, -60(%rbp)
.LBB2_27:                               # %while.end
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movsd	.LCPI2_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$4, %ecx
	movl	%edx, %r8d
	callq	mul_grids
	addq	$160, %rsp
	popq	%rbp
	retq
.LBB2_13:                               # %if.then26
	movl	$1, -64(%rbp)
	jmp	.LBB2_27
.LBB2_15:                               # %if.then30
	movl	$1, -64(%rbp)
	jmp	.LBB2_27
.LBB2_17:                               # %if.then36
	movl	$1, -64(%rbp)
	jmp	.LBB2_27
.LBB2_21:                               # %if.then61
	movl	$1, -64(%rbp)
	jmp	.LBB2_27
.LBB2_23:                               # %if.then66
	movl	$1, -64(%rbp)
	jmp	.LBB2_27
.Lfunc_end2:
	.size	BiCGStab, .Lfunc_end2-BiCGStab
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI3_0:
	.quad	4607182418800017408     # double 1
.LCPI3_2:
	.quad	0                       # double 0
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI3_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	CACG
	.align	16, 0x90
	.type	CACG,@function
CACG:                                   # @CACG
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp19:
	.cfi_def_cfa_offset 16
.Ltmp20:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp21:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$2840, %rsp             # imm = 0xB18
.Ltmp22:
	.cfi_offset %rbx, -56
.Ltmp23:
	.cfi_offset %r12, -48
.Ltmp24:
	.cfi_offset %r13, -40
.Ltmp25:
	.cfi_offset %r14, -32
.Ltmp26:
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)
	movl	%esi, -52(%rbp)
	movl	%edx, -56(%rbp)
	movl	%ecx, -60(%rbp)
	movsd	%xmm0, -72(%rbp)
	movsd	%xmm1, -80(%rbp)
	movsd	%xmm2, -88(%rbp)
	leaq	-2656(%rbp), %rax
	movq	%rax, -2664(%rbp)
	leaq	-2636(%rbp), %rax
	movq	%rax, -2672(%rbp)
	movl	$200, -2676(%rbp)
	movl	$0, -2680(%rbp)
	movl	$0, -2700(%rbp)
	movl	$0, -2704(%rbp)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %r8d
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$12, %edx
	callq	residual
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$13, %edx
	movl	$12, %ecx
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$14, %edx
	movl	$12, %ecx
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$12, %edx
	callq	norm
	movsd	%xmm0, -2776(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB3_2
	jp	.LBB3_2
# BB#1:                                 # %if.then
	movl	$1, -2704(%rbp)
.LBB3_2:                                # %if.end
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$13, %edx
	movl	$12, %ecx
	callq	dot
	movsd	%xmm0, -2768(%rbp)
	ucomisd	.LCPI3_2, %xmm0
	jne	.LBB3_4
	jp	.LBB3_4
# BB#3:                                 # %if.then6
	movl	$1, -2704(%rbp)
.LBB3_4:                                # %if.end7
	movsd	-2768(%rbp), %xmm1      # xmm1 = mem[0],zero
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB3_6
# BB#5:                                 # %call.sqrt
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB3_6:                                # %if.end7.split
	movsd	%xmm0, -2752(%rbp)
	movl	$0, -2688(%rbp)
	jmp	.LBB3_7
	.align	16, 0x90
.LBB3_11:                               # %for.inc15
                                        #   in Loop: Header=BB3_7 Depth=1
	incl	-2688(%rbp)
.LBB3_7:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB3_9 Depth 2
	cmpl	$8, -2688(%rbp)
	jg	.LBB3_12
# BB#8:                                 # %for.body
                                        #   in Loop: Header=BB3_7 Depth=1
	movl	$0, -2692(%rbp)
	jmp	.LBB3_9
	.align	16, 0x90
.LBB3_10:                               # %for.inc
                                        #   in Loop: Header=BB3_9 Depth=2
	movslq	-2692(%rbp), %rax
	movslq	-2688(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1296(%rbp,%rcx,8), %rcx
	movq	$0, (%rcx,%rax,8)
	incl	-2692(%rbp)
.LBB3_9:                                # %for.cond10
                                        #   Parent Loop BB3_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2692(%rbp)
	jle	.LBB3_10
	jmp	.LBB3_11
.LBB3_12:                               # %for.end17
	movl	$0, -2688(%rbp)
	movabsq	$4607182418800017408, %r13 # imm = 0x3FF0000000000000
	jmp	.LBB3_13
	.align	16, 0x90
.LBB3_14:                               # %for.inc25
                                        #   in Loop: Header=BB3_13 Depth=1
	movslq	-2688(%rbp), %rax
	leaq	(%rax,%rax,8), %rcx
	leaq	-1296(%rbp,%rcx,8), %rcx
	movq	%r13, 72(%rcx,%rax,8)
	incl	-2688(%rbp)
.LBB3_13:                               # %for.cond18
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$3, -2688(%rbp)
	jle	.LBB3_14
# BB#15:                                # %for.end27
	movl	$5, -2688(%rbp)
	jmp	.LBB3_16
	.align	16, 0x90
.LBB3_17:                               # %for.inc36
                                        #   in Loop: Header=BB3_16 Depth=1
	movslq	-2688(%rbp), %rax
	leaq	(%rax,%rax,8), %rcx
	leaq	-1296(%rbp,%rcx,8), %rcx
	movq	%r13, 72(%rcx,%rax,8)
	incl	-2688(%rbp)
.LBB3_16:                               # %for.cond28
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$7, -2688(%rbp)
	jle	.LBB3_17
# BB#18:                                # %for.end38
	movl	$0, -2688(%rbp)
	jmp	.LBB3_19
	.align	16, 0x90
.LBB3_99:                               # %for.inc45
                                        #   in Loop: Header=BB3_19 Depth=1
	movslq	-2688(%rbp), %rax
	leal	15(%rax), %ecx
	movl	%ecx, -2656(%rbp,%rax,4)
	incl	-2688(%rbp)
.LBB3_19:                               # %for.cond39
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_99
# BB#20:
	leaq	-400(%rbp), %r14
	leaq	-480(%rbp), %rbx
	leaq	-560(%rbp), %r15
	leaq	-240(%rbp), %r12
	jmp	.LBB3_21
	.align	16, 0x90
.LBB3_97:                               # %if.end361
                                        #   in Loop: Header=BB3_21 Depth=1
	addl	$4, -2680(%rbp)
.LBB3_21:                               # %while.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB3_28 Depth 2
                                        #     Child Loop BB3_31 Depth 2
                                        #     Child Loop BB3_34 Depth 2
                                        #       Child Loop BB3_36 Depth 3
                                        #     Child Loop BB3_40 Depth 2
                                        #     Child Loop BB3_43 Depth 2
                                        #     Child Loop BB3_46 Depth 2
                                        #     Child Loop BB3_49 Depth 2
                                        #       Child Loop BB3_51 Depth 3
                                        #         Child Loop BB3_53 Depth 4
                                        #       Child Loop BB3_57 Depth 3
                                        #         Child Loop BB3_59 Depth 4
                                        #       Child Loop BB3_63 Depth 3
                                        #         Child Loop BB3_65 Depth 4
                                        #       Child Loop BB3_71 Depth 3
                                        #         Child Loop BB3_73 Depth 4
                                        #     Child Loop BB3_87 Depth 2
                                        #     Child Loop BB3_92 Depth 2
                                        #     Child Loop BB3_95 Depth 2
	movl	-2680(%rbp), %eax
	cmpl	-2676(%rbp), %eax
	jge	.LBB3_22
# BB#23:                                # %land.lhs.true
                                        #   in Loop: Header=BB3_21 Depth=1
	cmpl	$0, -2700(%rbp)
	je	.LBB3_25
# BB#24:                                #   in Loop: Header=BB3_21 Depth=1
	xorl	%eax, %eax
	jmp	.LBB3_26
	.align	16, 0x90
.LBB3_22:                               #   in Loop: Header=BB3_21 Depth=1
	xorl	%eax, %eax
	jmp	.LBB3_26
.LBB3_25:                               # %land.rhs
                                        #   in Loop: Header=BB3_21 Depth=1
	cmpl	$0, -2704(%rbp)
	sete	%al
	.align	16, 0x90
.LBB3_26:                               # %land.end
                                        #   in Loop: Header=BB3_21 Depth=1
	testb	%al, %al
	je	.LBB3_98
# BB#27:                                # %while.body
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$9, %esi
	movq	%r14, %rdi
	callq	__zero
	movl	$9, %esi
	movq	%rbx, %rdi
	callq	__zero
	movl	$9, %esi
	movq	%r15, %rdi
	callq	__zero
	movl	$9, %esi
	leaq	-640(%rbp), %rdi
	callq	__zero
	movl	$9, %esi
	leaq	-160(%rbp), %rdi
	callq	__zero
	movl	$9, %esi
	movq	%r12, %rdi
	callq	__zero
	movl	$9, %esi
	leaq	-320(%rbp), %rdi
	callq	__zero
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-2664(%rbp), %rax
	movl	(%rax), %edx
	movl	$14, %ecx
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -2684(%rbp)
	jmp	.LBB3_28
	.align	16, 0x90
.LBB3_29:                               # %for.inc65
                                        #   in Loop: Header=BB3_28 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-2684(%rbp), %rax
	movq	-2664(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movl	-4(%rcx,%rax,4), %ecx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	apply_op
	incl	-2684(%rbp)
.LBB3_28:                               # %for.cond58
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$4, -2684(%rbp)
	jle	.LBB3_29
# BB#30:                                # %for.end67
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movq	-2672(%rbp), %rax
	movl	(%rax), %edx
	movl	$13, %ecx
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movl	$1, -2684(%rbp)
	jmp	.LBB3_31
	.align	16, 0x90
.LBB3_32:                               # %for.inc77
                                        #   in Loop: Header=BB3_31 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-2684(%rbp), %rax
	movq	-2672(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movl	-4(%rcx,%rax,4), %ecx
	movsd	-72(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-80(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	apply_op
	incl	-2684(%rbp)
.LBB3_31:                               # %for.cond69
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$3, -2684(%rbp)
	jle	.LBB3_32
# BB#33:                                # %for.end79
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	-48(%rbp), %rax
	incl	1316(%rax)
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	$1, 8(%rsp)
	movl	$9, (%rsp)
	movl	$9, %r9d
	leaq	-2608(%rbp), %rdx
	leaq	-2656(%rbp), %rcx
	movq	%rcx, %r8
	callq	matmul_grids
	movl	$0, -2688(%rbp)
	movl	$0, -2696(%rbp)
	jmp	.LBB3_34
	.align	16, 0x90
.LBB3_38:                               # %for.inc100
                                        #   in Loop: Header=BB3_34 Depth=2
	incl	-2688(%rbp)
.LBB3_34:                               # %for.cond84
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB3_36 Depth 3
	cmpl	$8, -2688(%rbp)
	jg	.LBB3_39
# BB#35:                                # %for.body86
                                        #   in Loop: Header=BB3_34 Depth=2
	movl	$0, -2692(%rbp)
	jmp	.LBB3_36
	.align	16, 0x90
.LBB3_37:                               # %for.inc97
                                        #   in Loop: Header=BB3_36 Depth=3
	movslq	-2696(%rbp), %rax
	leal	1(%rax), %ecx
	movl	%ecx, -2696(%rbp)
	movsd	-2608(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	movslq	-2692(%rbp), %rax
	movslq	-2688(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1952(%rbp,%rcx,8), %rcx
	movsd	%xmm0, (%rcx,%rax,8)
	incl	-2692(%rbp)
.LBB3_36:                               # %for.cond87
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_34 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	cmpl	$8, -2692(%rbp)
	jle	.LBB3_37
	jmp	.LBB3_38
	.align	16, 0x90
.LBB3_39:                               # %for.end102
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$0, -2688(%rbp)
	jmp	.LBB3_40
	.align	16, 0x90
.LBB3_41:                               # %for.inc108
                                        #   in Loop: Header=BB3_40 Depth=2
	movslq	-2688(%rbp), %rax
	movq	$0, -400(%rbp,%rax,8)
	incl	-2688(%rbp)
.LBB3_40:                               # %for.cond103
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_41
# BB#42:                                # %for.end110
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	%r13, -400(%rbp)
	movl	$0, -2688(%rbp)
	jmp	.LBB3_43
	.align	16, 0x90
.LBB3_44:                               # %for.inc117
                                        #   in Loop: Header=BB3_43 Depth=2
	movslq	-2688(%rbp), %rax
	movq	$0, -480(%rbp,%rax,8)
	incl	-2688(%rbp)
.LBB3_43:                               # %for.cond112
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_44
# BB#45:                                # %for.end119
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	%r13, -440(%rbp)
	movl	$0, -2688(%rbp)
	jmp	.LBB3_46
	.align	16, 0x90
.LBB3_47:                               # %for.inc126
                                        #   in Loop: Header=BB3_46 Depth=2
	movslq	-2688(%rbp), %rax
	movq	$0, -560(%rbp,%rax,8)
	incl	-2688(%rbp)
.LBB3_46:                               # %for.cond121
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_47
# BB#48:                                # %for.end128
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$0, -2684(%rbp)
	jmp	.LBB3_49
	.align	16, 0x90
.LBB3_100:                              # %for.inc317
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2744(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	$9, %ecx
	movq	%r14, %rdi
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rbx, %rsi
	movq	%r14, %rdx
	callq	__axpy
	incl	-2684(%rbp)
.LBB3_49:                               # %for.cond129
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB3_51 Depth 3
                                        #         Child Loop BB3_53 Depth 4
                                        #       Child Loop BB3_57 Depth 3
                                        #         Child Loop BB3_59 Depth 4
                                        #       Child Loop BB3_63 Depth 3
                                        #         Child Loop BB3_65 Depth 4
                                        #       Child Loop BB3_71 Depth 3
                                        #         Child Loop BB3_73 Depth 4
	cmpl	$3, -2684(%rbp)
	jg	.LBB3_86
# BB#50:                                # %for.body131
                                        #   in Loop: Header=BB3_49 Depth=2
	movq	-48(%rbp), %rax
	incl	1312(%rax)
	movl	$0, -2780(%rbp)
	jmp	.LBB3_51
	.align	16, 0x90
.LBB3_55:                               # %for.inc156
                                        #   in Loop: Header=BB3_51 Depth=3
	movslq	-2780(%rbp), %rax
	movsd	-640(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	.LCPI3_2, %xmm0
	addsd	-2792(%rbp), %xmm0
	movsd	%xmm0, -640(%rbp,%rax,8)
	incl	-2780(%rbp)
.LBB3_51:                               # %for.cond133
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB3_53 Depth 4
	cmpl	$8, -2780(%rbp)
	jg	.LBB3_56
# BB#52:                                # %for.body135
                                        #   in Loop: Header=BB3_51 Depth=3
	movq	$0, -2792(%rbp)
	movl	$0, -2784(%rbp)
	jmp	.LBB3_53
	.align	16, 0x90
.LBB3_54:                               # %for.inc146
                                        #   in Loop: Header=BB3_53 Depth=4
	movslq	-2784(%rbp), %rax
	movslq	-2780(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1296(%rbp,%rcx,8), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-400(%rbp,%rax,8), %xmm0
	addsd	-2792(%rbp), %xmm0
	movsd	%xmm0, -2792(%rbp)
	incl	-2784(%rbp)
.LBB3_53:                               # %for.cond136
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        #       Parent Loop BB3_51 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	cmpl	$8, -2784(%rbp)
	jle	.LBB3_54
	jmp	.LBB3_55
	.align	16, 0x90
.LBB3_56:                               # %for.end158
                                        #   in Loop: Header=BB3_49 Depth=2
	movl	$0, -2796(%rbp)
	jmp	.LBB3_57
	.align	16, 0x90
.LBB3_61:                               # %for.inc186
                                        #   in Loop: Header=BB3_57 Depth=3
	movslq	-2796(%rbp), %rax
	movsd	-160(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	.LCPI3_2, %xmm0
	addsd	-2808(%rbp), %xmm0
	movsd	%xmm0, -160(%rbp,%rax,8)
	incl	-2796(%rbp)
.LBB3_57:                               # %for.cond162
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB3_59 Depth 4
	cmpl	$8, -2796(%rbp)
	jg	.LBB3_62
# BB#58:                                # %for.body164
                                        #   in Loop: Header=BB3_57 Depth=3
	movq	$0, -2808(%rbp)
	movl	$0, -2800(%rbp)
	jmp	.LBB3_59
	.align	16, 0x90
.LBB3_60:                               # %for.inc176
                                        #   in Loop: Header=BB3_59 Depth=4
	movslq	-2800(%rbp), %rax
	movslq	-2796(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1952(%rbp,%rcx,8), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-640(%rbp,%rax,8), %xmm0
	addsd	-2808(%rbp), %xmm0
	movsd	%xmm0, -2808(%rbp)
	incl	-2800(%rbp)
.LBB3_59:                               # %for.cond165
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        #       Parent Loop BB3_57 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	cmpl	$8, -2800(%rbp)
	jle	.LBB3_60
	jmp	.LBB3_61
	.align	16, 0x90
.LBB3_62:                               # %for.end188
                                        #   in Loop: Header=BB3_49 Depth=2
	movl	$0, -2812(%rbp)
	jmp	.LBB3_63
	.align	16, 0x90
.LBB3_67:                               # %for.inc216
                                        #   in Loop: Header=BB3_63 Depth=3
	movslq	-2812(%rbp), %rax
	movsd	-240(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	.LCPI3_2, %xmm0
	addsd	-2824(%rbp), %xmm0
	movsd	%xmm0, -240(%rbp,%rax,8)
	incl	-2812(%rbp)
.LBB3_63:                               # %for.cond192
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB3_65 Depth 4
	cmpl	$8, -2812(%rbp)
	jg	.LBB3_68
# BB#64:                                # %for.body194
                                        #   in Loop: Header=BB3_63 Depth=3
	movq	$0, -2824(%rbp)
	movl	$0, -2816(%rbp)
	jmp	.LBB3_65
	.align	16, 0x90
.LBB3_66:                               # %for.inc206
                                        #   in Loop: Header=BB3_65 Depth=4
	movslq	-2816(%rbp), %rax
	movslq	-2812(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1952(%rbp,%rcx,8), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-480(%rbp,%rax,8), %xmm0
	addsd	-2824(%rbp), %xmm0
	movsd	%xmm0, -2824(%rbp)
	incl	-2816(%rbp)
.LBB3_65:                               # %for.cond195
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        #       Parent Loop BB3_63 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	cmpl	$8, -2816(%rbp)
	jle	.LBB3_66
	jmp	.LBB3_67
	.align	16, 0x90
.LBB3_68:                               # %for.end218
                                        #   in Loop: Header=BB3_49 Depth=2
	movl	$9, %edx
	movq	%r14, %rdi
	leaq	-160(%rbp), %rsi
	callq	__dot
	movsd	%xmm0, -2712(%rbp)
	movl	$9, %edx
	movq	%rbx, %rdi
	movq	%r12, %rsi
	callq	__dot
	movsd	%xmm0, -2720(%rbp)
	movsd	-2712(%rbp), %xmm0      # xmm0 = mem[0],zero
	ucomisd	.LCPI3_2, %xmm0
	jne	.LBB3_69
	jnp	.LBB3_85
.LBB3_69:                               # %cond.true230
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2720(%rbp), %xmm0      # xmm0 = mem[0],zero
	divsd	-2712(%rbp), %xmm0
	movsd	%xmm0, -2728(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB3_85
# BB#70:                                # %if.end238
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2728(%rbp), %xmm1      # xmm1 = mem[0],zero
	movl	$9, %ecx
	movq	%r15, %rdi
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%r15, %rsi
	movq	%r14, %rdx
	callq	__axpy
	movsd	-2728(%rbp), %xmm1      # xmm1 = mem[0],zero
	xorpd	.LCPI3_1(%rip), %xmm1
	movl	$9, %ecx
	movq	%rbx, %rdi
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rbx, %rsi
	leaq	-640(%rbp), %rdx
	callq	__axpy
	movl	$0, -2828(%rbp)
	jmp	.LBB3_71
	.align	16, 0x90
.LBB3_75:                               # %for.inc275
                                        #   in Loop: Header=BB3_71 Depth=3
	movslq	-2828(%rbp), %rax
	movsd	-240(%rbp,%rax,8), %xmm0 # xmm0 = mem[0],zero
	mulsd	.LCPI3_2, %xmm0
	addsd	-2840(%rbp), %xmm0
	movsd	%xmm0, -240(%rbp,%rax,8)
	incl	-2828(%rbp)
.LBB3_71:                               # %for.cond249
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        # =>    This Loop Header: Depth=3
                                        #         Child Loop BB3_73 Depth 4
	cmpl	$8, -2828(%rbp)
	jg	.LBB3_76
# BB#72:                                # %for.body252
                                        #   in Loop: Header=BB3_71 Depth=3
	movq	$0, -2840(%rbp)
	movl	$0, -2832(%rbp)
	jmp	.LBB3_73
	.align	16, 0x90
.LBB3_74:                               # %for.inc265
                                        #   in Loop: Header=BB3_73 Depth=4
	movslq	-2832(%rbp), %rax
	movslq	-2828(%rbp), %rcx
	leaq	(%rcx,%rcx,8), %rcx
	leaq	-1952(%rbp,%rcx,8), %rcx
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	mulsd	-480(%rbp,%rax,8), %xmm0
	addsd	-2840(%rbp), %xmm0
	movsd	%xmm0, -2840(%rbp)
	incl	-2832(%rbp)
.LBB3_73:                               # %for.cond253
                                        #   Parent Loop BB3_21 Depth=1
                                        #     Parent Loop BB3_49 Depth=2
                                        #       Parent Loop BB3_71 Depth=3
                                        # =>      This Inner Loop Header: Depth=4
	cmpl	$8, -2832(%rbp)
	jle	.LBB3_74
	jmp	.LBB3_75
	.align	16, 0x90
.LBB3_76:                               # %for.end277
                                        #   in Loop: Header=BB3_49 Depth=2
	movl	$9, %edx
	movq	%rbx, %rdi
	movq	%r12, %rsi
	callq	__dot
	movsd	%xmm0, -2736(%rbp)
	movq	$0, -2760(%rbp)
	movsd	-2736(%rbp), %xmm0      # xmm0 = mem[0],zero
	ucomisd	.LCPI3_2, %xmm0
	jbe	.LBB3_80
# BB#77:                                # %if.then283
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2736(%rbp), %xmm1      # xmm1 = mem[0],zero
	xorps	%xmm0, %xmm0
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.LBB3_79
# BB#78:                                # %call.sqrt1
                                        #   in Loop: Header=BB3_49 Depth=2
	movapd	%xmm1, %xmm0
	callq	sqrt
.LBB3_79:                               # %if.then283.split
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	%xmm0, -2760(%rbp)
.LBB3_80:                               # %if.end285
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-88(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-2752(%rbp), %xmm0
	ucomisd	-2760(%rbp), %xmm0
	ja	.LBB3_81
# BB#82:                                # %if.end290
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2736(%rbp), %xmm0      # xmm0 = mem[0],zero
	ucomisd	.LCPI3_2, %xmm0
	jne	.LBB3_83
	jnp	.LBB3_85
.LBB3_83:                               # %cond.true301
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2736(%rbp), %xmm0      # xmm0 = mem[0],zero
	divsd	-2720(%rbp), %xmm0
	movsd	%xmm0, -2744(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB3_85
# BB#84:                                # %if.end309
                                        #   in Loop: Header=BB3_49 Depth=2
	movsd	-2744(%rbp), %xmm0      # xmm0 = mem[0],zero
	ucomisd	.LCPI3_2, %xmm0
	jne	.LBB3_100
	jp	.LBB3_100
	.align	16, 0x90
.LBB3_85:                               # %if.then312
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$1, -2700(%rbp)
	jmp	.LBB3_86
.LBB3_81:                               # %if.then289
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$1, -2704(%rbp)
	.align	16, 0x90
.LBB3_86:                               # %for.end319
                                        #   in Loop: Header=BB3_21 Depth=1
	movl	$0, -2688(%rbp)
	jmp	.LBB3_87
	.align	16, 0x90
.LBB3_88:                               # %for.inc328
                                        #   in Loop: Header=BB3_87 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movl	-56(%rbp), %edx
	movslq	-2688(%rbp), %rax
	movsd	-560(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-2656(%rbp,%rax,4), %r8d
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	%edx, %ecx
	callq	add_grids
	incl	-2688(%rbp)
.LBB3_87:                               # %for.cond320
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_88
# BB#89:                                # %for.end330
                                        #   in Loop: Header=BB3_21 Depth=1
	cmpl	$0, -2700(%rbp)
	jne	.LBB3_97
# BB#90:                                # %land.lhs.true332
                                        #   in Loop: Header=BB3_21 Depth=1
	cmpl	$0, -2704(%rbp)
	jne	.LBB3_97
# BB#91:                                # %if.then334
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-400(%rbp), %xmm1       # xmm1 = mem[0],zero
	movl	-2656(%rbp), %r8d
	movl	$14, %edx
	xorpd	%xmm0, %xmm0
	movl	$14, %ecx
	callq	add_grids
	movl	$1, -2688(%rbp)
	jmp	.LBB3_92
	.align	16, 0x90
.LBB3_93:                               # %for.inc345
                                        #   in Loop: Header=BB3_92 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-2688(%rbp), %rax
	movsd	-400(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-2656(%rbp,%rax,4), %r8d
	movl	$14, %edx
	movl	$14, %ecx
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-2688(%rbp)
.LBB3_92:                               # %for.cond337
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_93
# BB#94:                                # %for.end347
                                        #   in Loop: Header=BB3_21 Depth=1
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movsd	-480(%rbp), %xmm1       # xmm1 = mem[0],zero
	movl	-2656(%rbp), %r8d
	movl	$13, %edx
	xorpd	%xmm0, %xmm0
	movl	$13, %ecx
	callq	add_grids
	movl	$1, -2688(%rbp)
	jmp	.LBB3_95
	.align	16, 0x90
.LBB3_96:                               # %for.inc358
                                        #   in Loop: Header=BB3_95 Depth=2
	movq	-48(%rbp), %rdi
	movl	-52(%rbp), %esi
	movslq	-2688(%rbp), %rax
	movsd	-480(%rbp,%rax,8), %xmm1 # xmm1 = mem[0],zero
	movl	-2656(%rbp,%rax,4), %r8d
	movl	$13, %edx
	movl	$13, %ecx
	movsd	.LCPI3_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	incl	-2688(%rbp)
.LBB3_95:                               # %for.cond350
                                        #   Parent Loop BB3_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$8, -2688(%rbp)
	jle	.LBB3_96
	jmp	.LBB3_97
.LBB3_98:                               # %while.end
	addq	$2840, %rsp             # imm = 0xB18
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end3:
	.size	CACG, .Lfunc_end3-CACG
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI4_0:
	.quad	4607182418800017408     # double 1
.LCPI4_2:
	.quad	0                       # double 0
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI4_1:
	.quad	-9223372036854775808    # 0x8000000000000000
	.quad	-9223372036854775808    # 0x8000000000000000
	.text
	.globl	CG
	.align	16, 0x90
	.type	CG,@function
CG:                                     # @CG
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
	subq	$128, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movsd	%xmm0, -32(%rbp)
	movsd	%xmm1, -40(%rbp)
	movsd	%xmm2, -48(%rbp)
	movl	$200, -52(%rbp)
	movl	$0, -56(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -64(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %ecx
	movl	-20(%rbp), %r8d
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$12, %edx
	callq	residual
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	.LCPI4_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	$13, %edx
	movl	$12, %ecx
	callq	scale_grid
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$14, %edx
	movl	$12, %ecx
	movsd	.LCPI4_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	scale_grid
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	callq	norm
	movsd	%xmm0, -72(%rbp)
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.LBB4_2
	jp	.LBB4_2
# BB#1:                                 # %if.then
	movl	$1, -64(%rbp)
.LBB4_2:                                # %if.end
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	movl	$13, %ecx
	callq	dot
	jmp	.LBB4_3
	.align	16, 0x90
.LBB4_19:                               # %if.end48
                                        #   in Loop: Header=BB4_3 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-120(%rbp), %xmm1       # xmm1 = mem[0],zero
	movl	$14, %edx
	movl	$13, %ecx
	movl	$14, %r8d
	movsd	.LCPI4_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	movsd	-112(%rbp), %xmm0       # xmm0 = mem[0],zero
.LBB4_3:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	movsd	%xmm0, -80(%rbp)
	movl	-56(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jge	.LBB4_4
# BB#5:                                 # %land.lhs.true
                                        #   in Loop: Header=BB4_3 Depth=1
	cmpl	$0, -60(%rbp)
	je	.LBB4_7
# BB#6:                                 #   in Loop: Header=BB4_3 Depth=1
	xorl	%eax, %eax
	jmp	.LBB4_8
	.align	16, 0x90
.LBB4_4:                                #   in Loop: Header=BB4_3 Depth=1
	xorl	%eax, %eax
	jmp	.LBB4_8
.LBB4_7:                                # %land.rhs
                                        #   in Loop: Header=BB4_3 Depth=1
	cmpl	$0, -64(%rbp)
	sete	%al
	.align	16, 0x90
.LBB4_8:                                # %land.end
                                        #   in Loop: Header=BB4_3 Depth=1
	testb	%al, %al
	je	.LBB4_18
# BB#9:                                 # %while.body
                                        #   in Loop: Header=BB4_3 Depth=1
	incl	-56(%rbp)
	movq	-8(%rbp), %rax
	incl	1312(%rax)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$16, %edx
	movl	$14, %ecx
	callq	apply_op
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$16, %edx
	movl	$14, %ecx
	callq	dot
	movsd	%xmm0, -88(%rbp)
	ucomisd	.LCPI4_2, %xmm0
	jne	.LBB4_10
	jnp	.LBB4_17
.LBB4_10:                               # %cond.true11
                                        #   in Loop: Header=BB4_3 Depth=1
	movsd	-80(%rbp), %xmm0        # xmm0 = mem[0],zero
	divsd	-88(%rbp), %xmm0
	movsd	%xmm0, -96(%rbp)
	callq	__isinf
	testl	%eax, %eax
	jne	.LBB4_17
# BB#11:                                # %if.end19
                                        #   in Loop: Header=BB4_3 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movsd	-96(%rbp), %xmm1        # xmm1 = mem[0],zero
	movl	$14, %r8d
	movsd	.LCPI4_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movl	%edx, %ecx
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movsd	-96(%rbp), %xmm1        # xmm1 = mem[0],zero
	xorpd	.LCPI4_1(%rip), %xmm1
	movl	$13, %edx
	movl	$13, %ecx
	movl	$16, %r8d
	movsd	.LCPI4_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	add_grids
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	callq	norm
	movsd	%xmm0, -104(%rbp)
	ucomisd	.LCPI4_2, %xmm0
	jne	.LBB4_13
	jp	.LBB4_13
	jmp	.LBB4_12
.LBB4_13:                               # %if.end24
                                        #   in Loop: Header=BB4_3 Depth=1
	movsd	-48(%rbp), %xmm0        # xmm0 = mem[0],zero
	mulsd	-72(%rbp), %xmm0
	ucomisd	-104(%rbp), %xmm0
	ja	.LBB4_14
# BB#15:                                # %if.end28
                                        #   in Loop: Header=BB4_3 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	$13, %edx
	movl	$13, %ecx
	callq	dot
	movsd	%xmm0, -112(%rbp)
	ucomisd	.LCPI4_2, %xmm0
	jne	.LBB4_16
	jnp	.LBB4_17
.LBB4_16:                               # %cond.true40
                                        #   in Loop: Header=BB4_3 Depth=1
	movsd	-112(%rbp), %xmm0       # xmm0 = mem[0],zero
	divsd	-80(%rbp), %xmm0
	movsd	%xmm0, -120(%rbp)
	callq	__isinf
	testl	%eax, %eax
	je	.LBB4_19
.LBB4_17:                               # %if.then47
	movl	$1, -60(%rbp)
	jmp	.LBB4_18
.LBB4_12:                               # %if.then23
	movl	$1, -64(%rbp)
	jmp	.LBB4_18
.LBB4_14:                               # %if.then27
	movl	$1, -64(%rbp)
.LBB4_18:                               # %while.end
	addq	$128, %rsp
	popq	%rbp
	retq
.Lfunc_end4:
	.size	CG, .Lfunc_end4-CG
	.cfi_endproc

	.globl	IterativeSolver
	.align	16, 0x90
	.type	IterativeSolver,@function
IterativeSolver:                        # @IterativeSolver
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
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movsd	%xmm0, -32(%rbp)
	movsd	%xmm1, -40(%rbp)
	movsd	%xmm2, -48(%rbp)
	movl	$48, -56(%rbp)
	movl	$0, -52(%rbp)
	jmp	.LBB5_1
	.align	16, 0x90
.LBB5_2:                                # %for.body
                                        #   in Loop: Header=BB5_1 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %ecx
	movsd	-32(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-40(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	smooth
	addl	$4, -52(%rbp)
.LBB5_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movl	-52(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jl	.LBB5_2
# BB#3:                                 # %for.end
	addq	$64, %rsp
	popq	%rbp
	retq
.Lfunc_end5:
	.size	IterativeSolver, .Lfunc_end5-IterativeSolver
	.cfi_endproc

	.globl	IterativeSolver_NumGrids
	.align	16, 0x90
	.type	IterativeSolver_NumGrids,@function
IterativeSolver_NumGrids:               # @IterativeSolver_NumGrids
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp33:
	.cfi_def_cfa_offset 16
.Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp35:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	popq	%rbp
	retq
.Lfunc_end6:
	.size	IterativeSolver_NumGrids, .Lfunc_end6-IterativeSolver_NumGrids
	.cfi_endproc


	.ident	"clang version 3.8.0 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
