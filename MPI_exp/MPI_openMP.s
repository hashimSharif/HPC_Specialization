# mark_description "Intel(R) C++ Intel(R) 64 Compiler XE for applications running on Intel(R) 64, Version 15.0.1.133 Build 20141";
# mark_description "023";
# mark_description "-I/opt/cray/mpt/7.4.1/gni/sma/include -I/opt/cray/libsci/16.07.1/INTEL/15.0/x86_64/include -I/opt/cray/mpt/7";
# mark_description ".4.1/gni/mpich-intel/15.0/include -I/opt/cray/rca/1.0.0-2.0502.57212.2.56.ari/include -I/opt/cray/alps/5.2.3";
# mark_description "-2.0502.9295.14.14.ari/include -I/opt/cray/xpmem/0.1-2.0502.57015.1.15.ari/include -I/opt/cray/gni-headers/4";
# mark_description ".0-1.0502.10317.9.2.ari/include -I/opt/cray/dmapp/7.0.1-1.0502.10246.8.47.ari/include -I/opt/cray/pmi/5.0.10";
# mark_description "-1.0000.11050.0.0.ari/include -I/opt/cray/ugni/6.0-1.0502.10245.9.9.ari/include -I/opt/cray/udreg/2.3.2-1.05";
# mark_description "02.9889.2.20.ari/include -I/usr/local/include -I/opt/cray/wlm_detect/1.0-1.0502.57063.1.1.ari/include -I/opt";
# mark_description "/cray/krca/1.0.0-2.0502.57202.2.45.ari/include -I/opt/cray-hss-devel/7.2.0/include -xCORE-AVX-I -static -D__";
# mark_description "CRAYXC -D__CRAY_IVYBRIDGE -D__CRAYXT_COMPUTE_LINUX_TARGET -S -openmp";
	.file "MPI_openMP.c"
	.text
..TXTST0:
# -- Begin  main, L_main_18__par_region0_2.0
	.text
# mark_begin;
       .align    16,0x90
	.globl main
main:
# parameter 1: %edi
# parameter 2: %rsi
..B1.1:                         # Preds ..B1.0
..___tag_value_main.1:                                          #7.34
        pushq     %rbp                                          #7.34
..___tag_value_main.3:                                          #
        movq      %rsp, %rbp                                    #7.34
..___tag_value_main.4:                                          #
        andq      $-128, %rsp                                   #7.34
        subq      $256, %rsp                                    #7.34
        movl      %edi, 192(%rsp)                               #7.34
        movl      $3, %edi                                      #7.34
        movq      %rsi, 128(%rsp)                               #7.34
        movl      $104446, %esi                                 #7.34
        movq      %rbx, 168(%rsp)                               #7.34
        movq      %r15, 136(%rsp)                               #7.34
        movq      %r14, 144(%rsp)                               #7.34
        movq      %r13, 152(%rsp)                               #7.34
        movq      %r12, 160(%rsp)                               #7.34
        call      __intel_new_feature_proc_init                 #7.34
..___tag_value_main.6:                                          #
                                # LOE
..B1.21:                        # Preds ..B1.1
        vstmxcsr  (%rsp)                                        #7.34
        movl      $.2.3_2_kmpc_loc_struct_pack.1, %edi          #7.34
        xorl      %esi, %esi                                    #7.34
        orl       $32832, (%rsp)                                #7.34
        xorl      %eax, %eax                                    #7.34
        vldmxcsr  (%rsp)                                        #7.34
..___tag_value_main.11:                                         #7.34
        call      __kmpc_begin                                  #7.34
..___tag_value_main.12:                                         #
                                # LOE
..B1.2:                         # Preds ..B1.21
        lea       192(%rsp), %rdi                               #13.3
        lea       128(%rsp), %rsi                               #13.3
..___tag_value_main.13:                                         #13.3
        call      MPI_Init                                      #13.3
..___tag_value_main.14:                                         #
                                # LOE
..B1.3:                         # Preds ..B1.2
        movl      $1140850688, %edi                             #14.3
        lea       176(%rsp), %rsi                               #14.3
..___tag_value_main.15:                                         #14.3
        call      MPI_Comm_size                                 #14.3
..___tag_value_main.16:                                         #
                                # LOE
..B1.4:                         # Preds ..B1.3
        movl      $1140850688, %edi                             #15.3
        lea       180(%rsp), %rsi                               #15.3
..___tag_value_main.17:                                         #15.3
        call      MPI_Comm_rank                                 #15.3
..___tag_value_main.18:                                         #
                                # LOE
..B1.5:                         # Preds ..B1.4
        lea       (%rsp), %rdi                                  #16.3
        lea       184(%rsp), %rsi                               #16.3
..___tag_value_main.19:                                         #16.3
        call      MPI_Get_processor_name                        #16.3
..___tag_value_main.20:                                         #
                                # LOE
..B1.6:                         # Preds ..B1.5
        movl      $.2.3_2_kmpc_loc_struct_pack.12, %edi         #18.1
        call      __kmpc_global_thread_num                      #18.1
                                # LOE eax
..B1.23:                        # Preds ..B1.6
        movl      %eax, 188(%rsp)                               #18.1
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #18.1
        xorl      %eax, %eax                                    #18.1
..___tag_value_main.21:                                         #18.1
        call      __kmpc_ok_to_fork                             #18.1
..___tag_value_main.22:                                         #
                                # LOE eax
..B1.7:                         # Preds ..B1.23
        testl     %eax, %eax                                    #18.1
        je        ..B1.9        # Prob 50%                      #18.1
                                # LOE
..B1.8:                         # Preds ..B1.7
        movl      $L_main_18__par_region0_2.0, %edx             #18.1
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #18.1
        movl      $3, %esi                                      #18.1
        lea       180(%rsp), %rcx                               #18.1
        xorl      %eax, %eax                                    #18.1
        lea       -4(%rcx), %r8                                 #18.1
        lea       (%rsp), %r9                                   #18.1
..___tag_value_main.23:                                         #18.1
        call      __kmpc_fork_call                              #18.1
..___tag_value_main.24:                                         #
        jmp       ..B1.12       # Prob 100%                     #18.1
                                # LOE
..B1.9:                         # Preds ..B1.7
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #18.1
        xorl      %eax, %eax                                    #18.1
        movl      188(%rsp), %esi                               #18.1
..___tag_value_main.25:                                         #18.1
        call      __kmpc_serialized_parallel                    #18.1
..___tag_value_main.26:                                         #
                                # LOE
..B1.10:                        # Preds ..B1.9
        movl      $___kmpv_zeromain_0, %esi                     #18.1
        lea       188(%rsp), %rdi                               #18.1
        lea       -8(%rdi), %rdx                                #18.1
        lea       -4(%rdx), %rcx                                #18.1
        lea       (%rsp), %r8                                   #18.1
..___tag_value_main.27:                                         #18.1
        call      L_main_18__par_region0_2.0                    #18.1
..___tag_value_main.28:                                         #
                                # LOE
..B1.11:                        # Preds ..B1.10
        movl      $.2.3_2_kmpc_loc_struct_pack.28, %edi         #18.1
        xorl      %eax, %eax                                    #18.1
        movl      188(%rsp), %esi                               #18.1
..___tag_value_main.29:                                         #18.1
        call      __kmpc_end_serialized_parallel                #18.1
..___tag_value_main.30:                                         #
                                # LOE
..B1.12:                        # Preds ..B1.8 ..B1.11
..___tag_value_main.31:                                         #26.3
        call      MPI_Finalize                                  #26.3
..___tag_value_main.32:                                         #
                                # LOE
..B1.13:                        # Preds ..B1.12
        movl      $.2.3_2_kmpc_loc_struct_pack.20, %edi         #27.1
        xorl      %eax, %eax                                    #27.1
..___tag_value_main.33:                                         #27.1
        call      __kmpc_end                                    #27.1
..___tag_value_main.34:                                         #
                                # LOE
..B1.14:                        # Preds ..B1.13
        movq      136(%rsp), %r15                               #27.1
..___tag_value_main.35:                                         #
        xorl      %eax, %eax                                    #27.1
        movq      144(%rsp), %r14                               #27.1
..___tag_value_main.36:                                         #
        movq      152(%rsp), %r13                               #27.1
..___tag_value_main.37:                                         #
        movq      160(%rsp), %r12                               #27.1
..___tag_value_main.38:                                         #
        movq      168(%rsp), %rbx                               #27.1
..___tag_value_main.39:                                         #
        movq      %rbp, %rsp                                    #27.1
        popq      %rbp                                          #27.1
..___tag_value_main.40:                                         #
        ret                                                     #27.1
..___tag_value_main.42:                                         #
                                # LOE
L_main_18__par_region0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
# parameter 3: %rdx
# parameter 4: %rcx
# parameter 5: %r8
..B1.15:                        # Preds ..B1.0
        pushq     %rbp                                          #18.1
..___tag_value_main.44:                                         #
        movq      %rsp, %rbp                                    #18.1
..___tag_value_main.45:                                         #
        andq      $-128, %rsp                                   #18.1
        subq      $256, %rsp                                    #18.1
        movq      %rbx, 168(%rsp)                               #18.1
        movq      %r15, 136(%rsp)                               #18.1
        movq      %r14, 144(%rsp)                               #18.1
..___tag_value_main.47:                                         #
        movq      %r8, %r14                                     #18.1
        movq      %r13, 152(%rsp)                               #18.1
..___tag_value_main.50:                                         #
        movq      %rcx, %r13                                    #18.1
        movq      %r12, 160(%rsp)                               #18.1
..___tag_value_main.51:                                         #
        movq      %rdx, %r12                                    #18.1
        call      omp_get_thread_num                            #18.1
                                # LOE r12 r13 r14 eax
..B1.24:                        # Preds ..B1.15
        movl      %eax, %ebx                                    #18.1
                                # LOE r12 r13 r14 ebx
..B1.16:                        # Preds ..B1.24
        call      omp_get_num_threads                           #20.10
                                # LOE r12 r13 r14 eax ebx
..B1.17:                        # Preds ..B1.16
        movl      $.L_2__STRING.0, %edi                         #22.5
        movl      %ebx, %esi                                    #22.5
        movl      %eax, %edx                                    #22.5
        movq      %r14, %r9                                     #22.5
        xorl      %eax, %eax                                    #22.5
        movl      (%r12), %ecx                                  #22.5
        movl      (%r13), %r8d                                  #22.5
..___tag_value_main.52:                                         #22.5
        call      printf                                        #22.5
..___tag_value_main.53:                                         #
                                # LOE
..B1.18:                        # Preds ..B1.17
        xorl      %eax, %eax                                    #18.1
        movq      136(%rsp), %r15                               #18.1
..___tag_value_main.54:                                         #
        movq      144(%rsp), %r14                               #18.1
..___tag_value_main.55:                                         #
        movq      152(%rsp), %r13                               #18.1
..___tag_value_main.56:                                         #
        movq      160(%rsp), %r12                               #18.1
..___tag_value_main.57:                                         #
        movq      168(%rsp), %rbx                               #18.1
..___tag_value_main.58:                                         #
        movq      %rbp, %rsp                                    #18.1
        popq      %rbp                                          #18.1
..___tag_value_main.59:                                         #
        ret                                                     #18.1
        .align    16,0x90
..___tag_value_main.61:                                         #
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
	.byte	55
	.byte	59
	.byte	55
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
	.byte	49
	.byte	56
	.byte	59
	.byte	49
	.byte	56
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
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
	.byte	49
	.byte	56
	.byte	59
	.byte	50
	.byte	52
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
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
	.byte	50
	.byte	55
	.byte	59
	.byte	50
	.byte	55
	.byte	59
	.byte	59
	.data
# -- End  main, L_main_18__par_region0_2.0
	.bss
	.align 4
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
	.section .rodata.str1.32, "aMS",@progbits,1
	.align 32
	.align 32
.L_2__STRING.0:
	.long	1819043144
	.long	1919295599
	.long	1948282223
	.long	1634038376
	.long	1680154724
	.long	1953853216
	.long	543584032
	.long	1713398821
	.long	544042866
	.long	1668248176
	.long	544437093
	.long	1864393765
	.long	1864397941
	.long	1680154726
	.long	544108320
	.long	684837
	.type	.L_2__STRING.0,@object
	.size	.L_2__STRING.0,64
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
	.4byte 0x0000014c
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
	.4byte ..___tag_value_main.35-..___tag_value_main.6
	.2byte 0x04cf
	.4byte ..___tag_value_main.36-..___tag_value_main.35
	.2byte 0x04ce
	.4byte ..___tag_value_main.37-..___tag_value_main.36
	.2byte 0x04cd
	.4byte ..___tag_value_main.38-..___tag_value_main.37
	.2byte 0x04cc
	.4byte ..___tag_value_main.39-..___tag_value_main.38
	.2byte 0x04c3
	.4byte ..___tag_value_main.40-..___tag_value_main.39
	.4byte 0xc608070c
	.byte 0x04
	.4byte ..___tag_value_main.42-..___tag_value_main.40
	.4byte 0x0410060c
	.4byte ..___tag_value_main.44-..___tag_value_main.42
	.4byte 0x0410070c
	.4byte ..___tag_value_main.45-..___tag_value_main.44
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.47-..___tag_value_main.45
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffa80d1affff
	.8byte 0x800d1c380e0e1022
	.8byte 0xffff900d1affffff
	.8byte 0x0d1c380e0f1022ff
	.8byte 0xff880d1affffff80
	.4byte 0x0422ffff
	.4byte ..___tag_value_main.50-..___tag_value_main.47
	.8byte 0xff800d1c380e0d10
	.8byte 0xffffff980d1affff
	.2byte 0x0422
	.4byte ..___tag_value_main.51-..___tag_value_main.50
	.8byte 0xff800d1c380e0c10
	.8byte 0xffffffa00d1affff
	.2byte 0x0422
	.4byte ..___tag_value_main.54-..___tag_value_main.51
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
# End
