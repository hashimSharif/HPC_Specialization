# mark_description "Intel(R) C++ Intel(R) 64 Compiler XE for applications running on Intel(R) 64, Version 15.0.1.133 Build 20141";
# mark_description "023";
# mark_description "-I/opt/cray/mpt/7.4.1/gni/sma/include -I/opt/cray/libsci/16.07.1/INTEL/15.0/x86_64/include -I/opt/cray/mpt/7";
# mark_description ".4.1/gni/mpich-intel/15.0/include -I/opt/cray/rca/1.0.0-2.0502.57212.2.56.ari/include -I/opt/cray/alps/5.2.3";
# mark_description "-2.0502.9295.14.14.ari/include -I/opt/cray/xpmem/0.1-2.0502.57015.1.15.ari/include -I/opt/cray/gni-headers/4";
# mark_description ".0-1.0502.10317.9.2.ari/include -I/opt/cray/dmapp/7.0.1-1.0502.10246.8.47.ari/include -I/opt/cray/pmi/5.0.10";
# mark_description "-1.0000.11050.0.0.ari/include -I/opt/cray/ugni/6.0-1.0502.10245.9.9.ari/include -I/opt/cray/udreg/2.3.2-1.05";
# mark_description "02.9889.2.20.ari/include -I/opt/cray/wlm_detect/1.0-1.0502.57063.1.1.ari/include -I/opt/cray/krca/1.0.0-2.05";
# mark_description "02.57202.2.45.ari/include -I/opt/cray-hss-devel/7.2.0/include -mavx -static -D__CRAYXC -D__CRAY_SANDYBRIDGE ";
# mark_description "-D__CRAYXT_COMPUTE_LINUX_TARGET -S -openmp";
	.file "MPI_instrumented3.c"
	.text
..TXTST0:
# -- Begin  main, L_main_39__par_region0_2.0
	.text
# mark_begin;
       .align    16,0x90
	.globl main
main:
# parameter 1: %edi
# parameter 2: %rsi
..B1.1:                         # Preds ..B1.0
..___tag_value_main.1:                                          #19.34
        pushq     %rbp                                          #19.34
..___tag_value_main.3:                                          #
        movq      %rsp, %rbp                                    #19.34
..___tag_value_main.4:                                          #
        andq      $-128, %rsp                                   #19.34
        subq      $256, %rsp                                    #19.34
        movl      %edi, 184(%rsp)                               #19.34
        movl      $3, %edi                                      #19.34
        movq      %rsi, 160(%rsp)                               #19.34
        xorl      %esi, %esi                                    #19.34
        movq      %rbx, 224(%rsp)                               #19.34
        movq      %r15, 192(%rsp)                               #19.34
        movq      %r14, 200(%rsp)                               #19.34
        movq      %r13, 208(%rsp)                               #19.34
        movq      %r12, 216(%rsp)                               #19.34
        call      __intel_new_feature_proc_init                 #19.34
..___tag_value_main.6:                                          #
                                # LOE
..B1.24:                        # Preds ..B1.1
        vstmxcsr  (%rsp)                                        #19.34
        movl      $.2.5_2_kmpc_loc_struct_pack.9, %edi          #19.34
        xorl      %esi, %esi                                    #19.34
        orl       $32832, (%rsp)                                #19.34
        xorl      %eax, %eax                                    #19.34
        vldmxcsr  (%rsp)                                        #19.34
..___tag_value_main.11:                                         #19.34
        call      __kmpc_begin                                  #19.34
..___tag_value_main.12:                                         #
                                # LOE
..B1.2:                         # Preds ..B1.24
        movl      $.2.5_2_kmpc_loc_struct_pack.20, %edi         #19.34
        call      __kmpc_global_thread_num                      #19.34
                                # LOE eax
..B1.25:                        # Preds ..B1.2
        movl      %eax, 168(%rsp)                               #19.34
        lea       184(%rsp), %rdi                               #25.3
        lea       160(%rsp), %rsi                               #25.3
..___tag_value_main.13:                                         #25.3
        call      MPI_Init                                      #25.3
..___tag_value_main.14:                                         #
                                # LOE
..B1.3:                         # Preds ..B1.25
        movl      $1140850688, %edi                             #26.3
        lea       172(%rsp), %rsi                               #26.3
..___tag_value_main.15:                                         #26.3
        call      MPI_Comm_size                                 #26.3
..___tag_value_main.16:                                         #
                                # LOE
..B1.4:                         # Preds ..B1.3
        movl      $1140850688, %edi                             #27.3
        lea       176(%rsp), %rsi                               #27.3
..___tag_value_main.17:                                         #27.3
        call      MPI_Comm_rank                                 #27.3
..___tag_value_main.18:                                         #
                                # LOE
..B1.5:                         # Preds ..B1.4
        lea       (%rsp), %rdi                                  #28.3
        lea       180(%rsp), %rsi                               #28.3
..___tag_value_main.19:                                         #28.3
        call      MPI_Get_processor_name                        #28.3
..___tag_value_main.20:                                         #
                                # LOE
..B1.6:                         # Preds ..B1.5
        xorl      %esi, %esi                                    #32.3
        lea       128(%rsp), %rdi                               #32.3
        call      gettimeofday                                  #32.3
                                # LOE
..B1.7:                         # Preds ..B1.6
        xorb      %bl, %bl                                      #37.13
                                # LOE bl
..B1.8:                         # Preds ..B1.14 ..B1.7
        movl      $.2.5_2_kmpc_loc_struct_pack.36, %edi         #39.5
        xorl      %eax, %eax                                    #39.5
..___tag_value_main.21:                                         #39.5
        call      __kmpc_ok_to_fork                             #39.5
..___tag_value_main.22:                                         #
                                # LOE eax bl
..B1.9:                         # Preds ..B1.8
        testl     %eax, %eax                                    #39.5
        je        ..B1.11       # Prob 50%                      #39.5
                                # LOE bl
..B1.10:                        # Preds ..B1.9
        movl      $L_main_39__par_region0_2.0, %edx             #39.5
        movl      $.2.5_2_kmpc_loc_struct_pack.36, %edi         #39.5
        xorl      %esi, %esi                                    #39.5
        xorl      %eax, %eax                                    #39.5
..___tag_value_main.23:                                         #39.5
        call      __kmpc_fork_call                              #39.5
..___tag_value_main.24:                                         #
        jmp       ..B1.14       # Prob 100%                     #39.5
                                # LOE bl
..B1.11:                        # Preds ..B1.9
        movl      $.2.5_2_kmpc_loc_struct_pack.36, %edi         #39.5
        xorl      %eax, %eax                                    #39.5
        movl      168(%rsp), %esi                               #39.5
..___tag_value_main.25:                                         #39.5
        call      __kmpc_serialized_parallel                    #39.5
..___tag_value_main.26:                                         #
                                # LOE bl
..B1.12:                        # Preds ..B1.11
        movl      $___kmpv_zeromain_0, %esi                     #39.5
        lea       168(%rsp), %rdi                               #39.5
..___tag_value_main.27:                                         #39.5
        call      L_main_39__par_region0_2.0                    #39.5
..___tag_value_main.28:                                         #
                                # LOE bl
..B1.13:                        # Preds ..B1.12
        movl      $.2.5_2_kmpc_loc_struct_pack.36, %edi         #39.5
        xorl      %eax, %eax                                    #39.5
        movl      168(%rsp), %esi                               #39.5
..___tag_value_main.29:                                         #39.5
        call      __kmpc_end_serialized_parallel                #39.5
..___tag_value_main.30:                                         #
                                # LOE bl
..B1.14:                        # Preds ..B1.10 ..B1.13
        incb      %bl                                           #37.26
        cmpb      $10, %bl                                      #37.22
        jl        ..B1.8        # Prob 90%                      #37.22
                                # LOE bl
..B1.15:                        # Preds ..B1.14
        xorl      %esi, %esi                                    #47.3
        lea       144(%rsp), %rdi                               #47.3
        call      gettimeofday                                  #47.3
                                # LOE
..B1.16:                        # Preds ..B1.15
        vxorpd    %xmm0, %xmm0, %xmm0                           #52.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #52.3
        vcvtsi2sdq 144(%rsp), %xmm0, %xmm0                      #52.3
        vcvtsi2sdq 128(%rsp), %xmm1, %xmm1                      #52.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #52.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #52.3
        vcvtsi2sdq 152(%rsp), %xmm3, %xmm3                      #52.3
        vcvtsi2sdq 136(%rsp), %xmm4, %xmm4                      #52.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #52.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #52.3
        vmulsd    .L_2il0floatpacket.1(%rip), %xmm2, %xmm5      #52.3
        movl      $.L_2__STRING.1, %edi                         #52.3
        movl      $1, %eax                                      #52.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #52.3
..___tag_value_main.31:                                         #52.3
        call      printf                                        #52.3
..___tag_value_main.32:                                         #
                                # LOE
..B1.17:                        # Preds ..B1.16
..___tag_value_main.33:                                         #54.3
        call      MPI_Finalize                                  #54.3
..___tag_value_main.34:                                         #
                                # LOE
..B1.18:                        # Preds ..B1.17
        movl      $.2.5_2_kmpc_loc_struct_pack.28, %edi         #56.1
        xorl      %eax, %eax                                    #56.1
..___tag_value_main.35:                                         #56.1
        call      __kmpc_end                                    #56.1
..___tag_value_main.36:                                         #
                                # LOE
..B1.19:                        # Preds ..B1.18
        movq      192(%rsp), %r15                               #56.1
..___tag_value_main.37:                                         #
        xorl      %eax, %eax                                    #56.1
        movq      200(%rsp), %r14                               #56.1
..___tag_value_main.38:                                         #
        movq      208(%rsp), %r13                               #56.1
..___tag_value_main.39:                                         #
        movq      216(%rsp), %r12                               #56.1
..___tag_value_main.40:                                         #
        movq      224(%rsp), %rbx                               #56.1
..___tag_value_main.41:                                         #
        movq      %rbp, %rsp                                    #56.1
        popq      %rbp                                          #56.1
..___tag_value_main.42:                                         #
        ret                                                     #56.1
..___tag_value_main.44:                                         #
                                # LOE
L_main_39__par_region0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
..B1.20:                        # Preds ..B1.0
        pushq     %rbp                                          #39.5
..___tag_value_main.46:                                         #
        movq      %rsp, %rbp                                    #39.5
..___tag_value_main.47:                                         #
        andq      $-128, %rsp                                   #39.5
        subq      $256, %rsp                                    #39.5
        movl      $il0_peep_printf_format_0, %edi               #43.7
        movq      %rbx, 224(%rsp)                               #39.5
        movq      %r15, 192(%rsp)                               #39.5
        movq      %r14, 200(%rsp)                               #39.5
        movq      %r13, 208(%rsp)                               #39.5
        movq      %r12, 216(%rsp)                               #39.5
        call      puts                                          #43.7
..___tag_value_main.49:                                         #
                                # LOE
..B1.21:                        # Preds ..B1.20
        xorl      %eax, %eax                                    #39.5
        movq      192(%rsp), %r15                               #39.5
..___tag_value_main.54:                                         #
        movq      200(%rsp), %r14                               #39.5
..___tag_value_main.55:                                         #
        movq      208(%rsp), %r13                               #39.5
..___tag_value_main.56:                                         #
        movq      216(%rsp), %r12                               #39.5
..___tag_value_main.57:                                         #
        movq      224(%rsp), %rbx                               #39.5
..___tag_value_main.58:                                         #
        movq      %rbp, %rsp                                    #39.5
        popq      %rbp                                          #39.5
..___tag_value_main.59:                                         #
        ret                                                     #39.5
        .align    16,0x90
..___tag_value_main.61:                                         #
                                # LOE
# mark_end;
	.type	main,@function
	.size	main,.-main
	.data
	.align 4
	.align 4
.2.5_2_kmpc_loc_struct_pack.9:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.8
	.align 4
.2.5_2__kmpc_loc_pack.8:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	49
	.byte	57
	.byte	59
	.byte	49
	.byte	57
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.20:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.19
	.align 4
.2.5_2__kmpc_loc_pack.19:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	49
	.byte	57
	.byte	59
	.byte	49
	.byte	57
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.36:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.35
	.align 4
.2.5_2__kmpc_loc_pack.35:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	51
	.byte	57
	.byte	59
	.byte	52
	.byte	52
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.28:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.27
	.align 4
.2.5_2__kmpc_loc_pack.27:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	53
	.byte	54
	.byte	59
	.byte	53
	.byte	54
	.byte	59
	.byte	59
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
il0_peep_printf_format_0:
	.long	1819043144
	.long	1919295599
	.long	1948282223
	.long	1634038376
	.word	8292
	.byte	0
	.data
# -- End  main, L_main_39__par_region0_2.0
	.text
# -- Begin  _Z9time_diff7timevalS_
	.text
# mark_begin;
       .align    16,0x90
	.globl _Z9time_diff7timevalS_
_Z9time_diff7timevalS_:
# parameter 1: %rsi %rdi
# parameter 2: %rdx %rcx
..B2.1:                         # Preds ..B2.0
..___tag_value__Z9time_diff7timevalS_.62:                       #11.1
        vxorpd    %xmm0, %xmm0, %xmm0                           #14.18
        vxorpd    %xmm1, %xmm1, %xmm1                           #13.18
        vxorpd    %xmm3, %xmm3, %xmm3                           #14.45
        vcvtsi2sdq %rdx, %xmm0, %xmm0                           #14.18
        vcvtsi2sdq %rdi, %xmm1, %xmm1                           #13.18
        vcvtsi2sdq %rcx, %xmm3, %xmm3                           #14.45
        vsubsd    %xmm1, %xmm0, %xmm2                           #15.33
        vxorpd    %xmm4, %xmm4, %xmm4                           #13.45
        vcvtsi2sdq %rsi, %xmm4, %xmm4                           #13.45
        vmulsd    .L_2il0floatpacket.1(%rip), %xmm2, %xmm5      #15.33
        vsubsd    %xmm4, %xmm3, %xmm6                           #15.33
        vaddsd    %xmm6, %xmm5, %xmm0                           #15.33
        ret                                                     #16.10
        .align    16,0x90
..___tag_value__Z9time_diff7timevalS_.64:                       #
                                # LOE
# mark_end;
	.type	_Z9time_diff7timevalS_,@function
	.size	_Z9time_diff7timevalS_,.-_Z9time_diff7timevalS_
	.data
# -- End  _Z9time_diff7timevalS_
	.bss
	.align 4
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
	.section .rodata, "a"
	.align 8
	.align 8
.L_2il0floatpacket.1:
	.long	0x00000000,0x412e8480
	.type	.L_2il0floatpacket.1,@object
	.size	.L_2il0floatpacket.1,8
	.section .rodata.str1.4, "aMS",@progbits,1
	.space 1, 0x00 	# pad
	.align 4
.L_2__STRING.1:
	.long	707398176
	.long	707406378
	.long	170535466
	.long	1953453088
	.long	1948281953
	.long	543518057
	.long	1885432933
	.long	543450483
	.long	774185018
	.long	543583280
	.long	169898869
	.long	707406378
	.long	170535466
	.byte	0
	.type	.L_2__STRING.1,@object
	.size	.L_2__STRING.1,53
	.data
	.section .note.GNU-stack, ""
// -- Begin DWARF2 SEGMENT .eh_frame
	.section .eh_frame,"a",@progbits
.eh_frame_seg:
	.align 8
	.4byte 0x0000001c
	.8byte 0x00507a0100000000
	.4byte 0x09107801
	.byte 0x00
	.8byte __gxx_personality_v0
	.4byte 0x9008070c
	.2byte 0x0001
	.byte 0x00
	.4byte 0x00000144
	.4byte 0x00000024
	.8byte ..___tag_value_main.1
	.8byte ..___tag_value_main.61-..___tag_value_main.1
	.2byte 0x0400
	.4byte ..___tag_value_main.3-..___tag_value_main.1
	.2byte 0x100e
	.byte 0x04
	.4byte ..___tag_value_main.4-..___tag_value_main.3
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.6-..___tag_value_main.4
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffe00d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xffffd80d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xffd00d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0xc80d1affffff800d
	.8byte 0x380e0f1022ffffff
	.8byte 0x0d1affffff800d1c
	.4byte 0xffffffc0
	.2byte 0x0422
	.4byte ..___tag_value_main.37-..___tag_value_main.6
	.2byte 0x04cf
	.4byte ..___tag_value_main.38-..___tag_value_main.37
	.2byte 0x04ce
	.4byte ..___tag_value_main.39-..___tag_value_main.38
	.2byte 0x04cd
	.4byte ..___tag_value_main.40-..___tag_value_main.39
	.2byte 0x04cc
	.4byte ..___tag_value_main.41-..___tag_value_main.40
	.2byte 0x04c3
	.4byte ..___tag_value_main.42-..___tag_value_main.41
	.4byte 0xc608070c
	.byte 0x04
	.4byte ..___tag_value_main.44-..___tag_value_main.42
	.4byte 0x0410060c
	.4byte ..___tag_value_main.46-..___tag_value_main.44
	.4byte 0x0410070c
	.4byte ..___tag_value_main.47-..___tag_value_main.46
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.49-..___tag_value_main.47
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffe00d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xffffd80d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xffd00d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0xc80d1affffff800d
	.8byte 0x380e0f1022ffffff
	.8byte 0x0d1affffff800d1c
	.4byte 0xffffffc0
	.2byte 0x0422
	.4byte ..___tag_value_main.54-..___tag_value_main.49
	.2byte 0x04cf
	.4byte ..___tag_value_main.55-..___tag_value_main.54
	.2byte 0x04ce
	.4byte ..___tag_value_main.56-..___tag_value_main.55
	.2byte 0x04cd
	.4byte ..___tag_value_main.57-..___tag_value_main.56
	.2byte 0x04cc
	.4byte ..___tag_value_main.58-..___tag_value_main.57
	.2byte 0x04c3
	.4byte ..___tag_value_main.59-..___tag_value_main.58
	.4byte 0xc608070c
	.2byte 0x0000
	.4byte 0x0000001c
	.4byte 0x0000016c
	.8byte ..___tag_value__Z9time_diff7timevalS_.62
	.8byte ..___tag_value__Z9time_diff7timevalS_.64-..___tag_value__Z9time_diff7timevalS_.62
	.8byte 0x0000000000000000
# End
