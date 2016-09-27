# mark_description "Intel(R) C++ Intel(R) 64 Compiler XE for applications running on Intel(R) 64, Version 15.0.1.133 Build 20141";
# mark_description "023";
# mark_description "-I/opt/cray/mpt/7.4.1/gni/sma/include -I/opt/cray/libsci/16.07.1/INTEL/15.0/x86_64/include -I/opt/cray/mpt/7";
# mark_description ".4.1/gni/mpich-intel/15.0/include -I/opt/cray/rca/1.0.0-2.0502.57212.2.56.ari/include -I/opt/cray/alps/5.2.3";
# mark_description "-2.0502.9295.14.14.ari/include -I/opt/cray/xpmem/0.1-2.0502.57015.1.15.ari/include -I/opt/cray/gni-headers/4";
# mark_description ".0-1.0502.10317.9.2.ari/include -I/opt/cray/dmapp/7.0.1-1.0502.10246.8.47.ari/include -I/opt/cray/pmi/5.0.10";
# mark_description "-1.0000.11050.0.0.ari/include -I/opt/cray/ugni/6.0-1.0502.10245.9.9.ari/include -I/opt/cray/udreg/2.3.2-1.05";
# mark_description "02.9889.2.20.ari/include -I/usr/local/include -I/opt/cray/wlm_detect/1.0-1.0502.57063.1.1.ari/include -I/opt";
# mark_description "/cray/krca/1.0.0-2.0502.57202.2.45.ari/include -I/opt/cray-hss-devel/7.2.0/include -xCORE-AVX-I -static -D__";
# mark_description "CRAYXC -D__CRAY_IVYBRIDGE -D__CRAYXT_COMPUTE_LINUX_TARGET -S -o custom_tests/hello.s -openmp";
	.file "hello.c"
	.text
..TXTST0:
# -- Begin  main, L_main_8__par_region0_2.0
	.text
# mark_begin;
       .align    16,0x90
	.globl main
main:
..B1.1:                         # Preds ..B1.0
..___tag_value_main.1:                                          #6.11
        pushq     %rbp                                          #6.11
..___tag_value_main.3:                                          #
        movq      %rsp, %rbp                                    #6.11
..___tag_value_main.4:                                          #
        andq      $-128, %rsp                                   #6.11
        subq      $128, %rsp                                    #6.11
        movl      $104446, %esi                                 #6.11
        movl      $3, %edi                                      #6.11
        movq      %rbx, 40(%rsp)                                #6.11
        movq      %r15, 8(%rsp)                                 #6.11
        movq      %r14, 16(%rsp)                                #6.11
        movq      %r13, 24(%rsp)                                #6.11
        movq      %r12, 32(%rsp)                                #6.11
        call      __intel_new_feature_proc_init                 #6.11
..___tag_value_main.6:                                          #
                                # LOE
..B1.14:                        # Preds ..B1.1
        vstmxcsr  (%rsp)                                        #6.11
        movl      $.2.3_2_kmpc_loc_struct_pack.1, %edi          #6.11
        xorl      %esi, %esi                                    #6.11
        orl       $32832, (%rsp)                                #6.11
        xorl      %eax, %eax                                    #6.11
        vldmxcsr  (%rsp)                                        #6.11
..___tag_value_main.11:                                         #6.11
        call      __kmpc_begin                                  #6.11
..___tag_value_main.12:                                         #
                                # LOE
..B1.2:                         # Preds ..B1.14
        movl      $.2.3_2_kmpc_loc_struct_pack.12, %edi         #8.3
        call      __kmpc_global_thread_num                      #8.3
                                # LOE eax
..B1.16:                        # Preds ..B1.2
        movl      %eax, (%rsp)                                  #8.3
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #8.3
        xorl      %eax, %eax                                    #8.3
..___tag_value_main.13:                                         #8.3
        call      __kmpc_ok_to_fork                             #8.3
..___tag_value_main.14:                                         #
                                # LOE eax
..B1.3:                         # Preds ..B1.16
        testl     %eax, %eax                                    #8.3
        je        ..B1.5        # Prob 50%                      #8.3
                                # LOE
..B1.4:                         # Preds ..B1.3
        movl      $L_main_8__par_region0_2.0, %edx              #8.3
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #8.3
        xorl      %esi, %esi                                    #8.3
        xorl      %eax, %eax                                    #8.3
..___tag_value_main.15:                                         #8.3
        call      __kmpc_fork_call_start                              #8.3
	call      __kmpc_fork_call_end
..___tag_value_main.16:                                         #
        jmp       ..B1.8        # Prob 100%                     #8.3
                                # LOE
..B1.5:                         # Preds ..B1.3
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #8.3
        xorl      %eax, %eax                                    #8.3
        movl      (%rsp), %esi                                  #8.3
..___tag_value_main.17:                                         #8.3
        call      __kmpc_serialized_parallel                    #8.3
..___tag_value_main.18:                                         #
                                # LOE
..B1.6:                         # Preds ..B1.5
        movl      $___kmpv_zeromain_0, %esi                     #8.3
        lea       (%rsp), %rdi                                  #8.3
..___tag_value_main.19:                                         #8.3
        call      L_main_8__par_region0_2.0                     #8.3
..___tag_value_main.20:                                         #
                                # LOE
..B1.7:                         # Preds ..B1.6
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #8.3
        xorl      %eax, %eax                                    #8.3
        movl      (%rsp), %esi                                  #8.3
..___tag_value_main.21:                                         #8.3
        call      __kmpc_end_serialized_parallel                #8.3
..___tag_value_main.22:                                         #
                                # LOE
..B1.8:                         # Preds ..B1.4 ..B1.7
        movl      $.2.3_2_kmpc_loc_struct_pack.20, %edi         #11.10
        xorl      %eax, %eax                                    #11.10
..___tag_value_main.23:                                         #11.10
        call      __kmpc_end                                    #11.10
..___tag_value_main.24:                                         #
                                # LOE
..B1.9:                         # Preds ..B1.8
        movq      8(%rsp), %r15                                 #11.10
..___tag_value_main.25:                                         #
        xorl      %eax, %eax                                    #11.10
        movq      16(%rsp), %r14                                #11.10
..___tag_value_main.26:                                         #
        movq      24(%rsp), %r13                                #11.10
..___tag_value_main.27:                                         #
        movq      32(%rsp), %r12                                #11.10
..___tag_value_main.28:                                         #
        movq      40(%rsp), %rbx                                #11.10
..___tag_value_main.29:                                         #
        movq      %rbp, %rsp                                    #11.10
        popq      %rbp                                          #11.10
..___tag_value_main.30:                                         #
        ret                                                     #11.10
..___tag_value_main.32:                                         #
                                # LOE
L_main_8__par_region0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
..B1.10:                        # Preds ..B1.0
        pushq     %rbp                                          #8.3
..___tag_value_main.34:                                         #
        movq      %rsp, %rbp                                    #8.3
..___tag_value_main.35:                                         #
        andq      $-128, %rsp                                   #8.3
        subq      $128, %rsp                                    #8.3
        movl      $il0_peep_printf_format_0, %edi               #9.3
        movq      %rbx, 40(%rsp)                                #8.3
        movq      %r15, 8(%rsp)                                 #8.3
        movq      %r14, 16(%rsp)                                #8.3
        movq      %r13, 24(%rsp)                                #8.3
        movq      %r12, 32(%rsp)                                #8.3
        call      puts                                          #9.3
..___tag_value_main.37:                                         #
                                # LOE
..B1.11:                        # Preds ..B1.10
        xorl      %eax, %eax                                    #8.3
        movq      8(%rsp), %r15                                 #8.3
..___tag_value_main.42:                                         #
        movq      16(%rsp), %r14                                #8.3
..___tag_value_main.43:                                         #
        movq      24(%rsp), %r13                                #8.3
..___tag_value_main.44:                                         #
        movq      32(%rsp), %r12                                #8.3
..___tag_value_main.45:                                         #
        movq      40(%rsp), %rbx                                #8.3
..___tag_value_main.46:                                         #
        movq      %rbp, %rsp                                    #8.3
        popq      %rbp                                          #8.3
..___tag_value_main.47:                                         #
        ret                                                     #8.3
        .align    16,0x90
..___tag_value_main.49:                                         #
                                # LOE
# mark_end;
	.type	main,@function
	.size	main,.-main
	.data
	.align 4
	.align 4
.2.3_2_kmpc_loc_struct_pack.1:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.0
	.align 4
.2.3_2__kmpc_loc_pack.0:
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
	.byte	54
	.byte	59
	.byte	54
	.byte	59
	.byte	59
	.space 1, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.12:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.11
	.align 4
.2.3_2__kmpc_loc_pack.11:
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
	.byte	56
	.byte	59
	.byte	56
	.byte	59
	.byte	59
	.space 1, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.28:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.27
	.align 4
.2.3_2__kmpc_loc_pack.27:
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
	.byte	56
	.byte	59
	.byte	57
	.byte	59
	.byte	59
	.space 1, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.20:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.19
	.align 4
.2.3_2__kmpc_loc_pack.19:
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
	.byte	49
	.byte	59
	.byte	49
	.byte	49
	.byte	59
	.byte	59
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
il0_peep_printf_format_0:
	.long	1819043176
	.long	1919295599
	.long	1948282223
	.long	1634038376
	.word	8292
	.byte	0
	.data
# -- End  main, L_main_8__par_region0_2.0
	.bss
	.align 4
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
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
	.8byte ..___tag_value_main.49-..___tag_value_main.1
	.2byte 0x0400
	.4byte ..___tag_value_main.3-..___tag_value_main.1
	.2byte 0x100e
	.byte 0x04
	.4byte ..___tag_value_main.4-..___tag_value_main.3
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.6-..___tag_value_main.4
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffa80d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xffffa00d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xff980d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0x900d1affffff800d
	.8byte 0x380e0f1022ffffff
	.8byte 0x0d1affffff800d1c
	.4byte 0xffffff88
	.2byte 0x0422
	.4byte ..___tag_value_main.25-..___tag_value_main.6
	.2byte 0x04cf
	.4byte ..___tag_value_main.26-..___tag_value_main.25
	.2byte 0x04ce
	.4byte ..___tag_value_main.27-..___tag_value_main.26
	.2byte 0x04cd
	.4byte ..___tag_value_main.28-..___tag_value_main.27
	.2byte 0x04cc
	.4byte ..___tag_value_main.29-..___tag_value_main.28
	.2byte 0x04c3
	.4byte ..___tag_value_main.30-..___tag_value_main.29
	.4byte 0xc608070c
	.byte 0x04
	.4byte ..___tag_value_main.32-..___tag_value_main.30
	.4byte 0x0410060c
	.4byte ..___tag_value_main.34-..___tag_value_main.32
	.4byte 0x0410070c
	.4byte ..___tag_value_main.35-..___tag_value_main.34
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.37-..___tag_value_main.35
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffa80d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xffffa00d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xff980d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0x900d1affffff800d
	.8byte 0x380e0f1022ffffff
	.8byte 0x0d1affffff800d1c
	.4byte 0xffffff88
	.2byte 0x0422
	.4byte ..___tag_value_main.42-..___tag_value_main.37
	.2byte 0x04cf
	.4byte ..___tag_value_main.43-..___tag_value_main.42
	.2byte 0x04ce
	.4byte ..___tag_value_main.44-..___tag_value_main.43
	.2byte 0x04cd
	.4byte ..___tag_value_main.45-..___tag_value_main.44
	.2byte 0x04cc
	.4byte ..___tag_value_main.46-..___tag_value_main.45
	.2byte 0x04c3
	.4byte ..___tag_value_main.47-..___tag_value_main.46
	.4byte 0xc608070c
	.2byte 0x0000
# End
