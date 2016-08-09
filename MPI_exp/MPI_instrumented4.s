# mark_description "Intel(R) C++ Intel(R) 64 Compiler XE for applications running on Intel(R) 64, Version 15.0.1.133 Build 20141";
# mark_description "023";
# mark_description "-I/opt/cray/mpt/7.4.1/gni/sma/include -I/opt/cray/libsci/16.07.1/INTEL/15.0/x86_64/include -I/opt/cray/mpt/7";
# mark_description ".4.1/gni/mpich-intel/15.0/include -I/opt/cray/rca/1.0.0-2.0502.57212.2.56.ari/include -I/opt/cray/alps/5.2.3";
# mark_description "-2.0502.9295.14.14.ari/include -I/opt/cray/xpmem/0.1-2.0502.57015.1.15.ari/include -I/opt/cray/gni-headers/4";
# mark_description ".0-1.0502.10317.9.2.ari/include -I/opt/cray/dmapp/7.0.1-1.0502.10246.8.47.ari/include -I/opt/cray/pmi/5.0.10";
# mark_description "-1.0000.11050.0.0.ari/include -I/opt/cray/ugni/6.0-1.0502.10245.9.9.ari/include -I/opt/cray/udreg/2.3.2-1.05";
# mark_description "02.9889.2.20.ari/include -I/usr/local/include -I/opt/cray/wlm_detect/1.0-1.0502.57063.1.1.ari/include -I/opt";
# mark_description "/cray/krca/1.0.0-2.0502.57202.2.45.ari/include -I/opt/cray-hss-devel/7.2.0/include -xCORE-AVX-I -static -D__";
# mark_description "CRAYXC -D__CRAY_IVYBRIDGE -D__CRAYXT_COMPUTE_LINUX_TARGET -S -openmp -noinline";
	.file "MPI_instrumented4.c"
	.text
..TXTST0:
# -- Begin  main, L_main_56__par_region0_2.0
	.text
# mark_begin;
       .align    16,0x90
	.globl main
main:
# parameter 1: %edi
# parameter 2: %rsi
..B1.1:                         # Preds ..B1.0
..___tag_value_main.1:                                          #40.34
        pushq     %rbp                                          #40.34
..___tag_value_main.3:                                          #
        movq      %rsp, %rbp                                    #40.34
..___tag_value_main.4:                                          #
        andq      $-128, %rsp                                   #40.34
        subq      $256, %rsp                                    #40.34
        movl      %edi, 192(%rsp)                               #40.34
        movl      $3, %edi                                      #40.34
        movq      %rsi, 128(%rsp)                               #40.34
        movl      $104446, %esi                                 #40.34
        movq      %rbx, 168(%rsp)                               #40.34
        movq      %r15, 136(%rsp)                               #40.34
        movq      %r14, 144(%rsp)                               #40.34
        movq      %r13, 152(%rsp)                               #40.34
        movq      %r12, 160(%rsp)                               #40.34
        call      __intel_new_feature_proc_init                 #40.34
..___tag_value_main.6:                                          #
                                # LOE
..B1.27:                        # Preds ..B1.1
        vstmxcsr  (%rsp)                                        #40.34
        movl      $.2.9_2_kmpc_loc_struct_pack.5, %edi          #40.34
        xorl      %esi, %esi                                    #40.34
        orl       $32832, (%rsp)                                #40.34
        xorl      %eax, %eax                                    #40.34
        vldmxcsr  (%rsp)                                        #40.34
..___tag_value_main.11:                                         #40.34
        call      __kmpc_begin                                  #40.34
..___tag_value_main.12:                                         #
                                # LOE
..B1.2:                         # Preds ..B1.27
        lea       192(%rsp), %rdi                               #46.3
        lea       128(%rsp), %rsi                               #46.3
..___tag_value_main.13:                                         #46.3
        call      MPI_Init                                      #46.3
..___tag_value_main.14:                                         #
                                # LOE
..B1.3:                         # Preds ..B1.2
        movl      $1140850688, %edi                             #47.3
        lea       176(%rsp), %rsi                               #47.3
..___tag_value_main.15:                                         #47.3
        call      MPI_Comm_size                                 #47.3
..___tag_value_main.16:                                         #
                                # LOE
..B1.4:                         # Preds ..B1.3
        movl      $1140850688, %edi                             #48.3
        lea       180(%rsp), %rsi                               #48.3
..___tag_value_main.17:                                         #48.3
        call      MPI_Comm_rank                                 #48.3
..___tag_value_main.18:                                         #
                                # LOE
..B1.5:                         # Preds ..B1.4
        lea       (%rsp), %rdi                                  #49.3
        lea       184(%rsp), %rsi                               #49.3
..___tag_value_main.19:                                         #49.3
        call      MPI_Get_processor_name                        #49.3
..___tag_value_main.20:                                         #
                                # LOE
..B1.6:                         # Preds ..B1.5
        movslq    count(%rip), %rax                             #54.3
        xorl      %esi, %esi                                    #54.3
        shlq      $4, %rax                                      #54.3
        lea       timeArr(%rax), %rdi                           #54.3
        call      gettimeofday                                  #54.3
                                # LOE
..B1.7:                         # Preds ..B1.6
        movl      $.2.9_2_kmpc_loc_struct_pack.16, %edi         #56.1
        incl      count(%rip)                                   #54.3
        call      __kmpc_global_thread_num                      #56.1
                                # LOE eax
..B1.29:                        # Preds ..B1.7
        movl      %eax, 188(%rsp)                               #56.1
        movl      $.2.9_2_kmpc_loc_struct_pack.32, %edi         #56.1
        xorl      %eax, %eax                                    #56.1
..___tag_value_main.21:                                         #56.1
        call      __kmpc_ok_to_fork                             #56.1
..___tag_value_main.22:                                         #
                                # LOE eax
..B1.8:                         # Preds ..B1.29
        testl     %eax, %eax                                    #56.1
        je        ..B1.10       # Prob 50%                      #56.1
                                # LOE
..B1.9:                         # Preds ..B1.8
        movl      $L_main_56__par_region0_2.0, %edx             #56.1
        movl      $.2.9_2_kmpc_loc_struct_pack.32, %edi         #56.1
        movl      $3, %esi                                      #56.1
        lea       180(%rsp), %rcx                               #56.1
        xorl      %eax, %eax                                    #56.1
        lea       -4(%rcx), %r8                                 #56.1
        lea       (%rsp), %r9                                   #56.1
..___tag_value_main.23:                                         #56.1
        call      __kmpc_fork_call                              #56.1
..___tag_value_main.24:                                         #
        jmp       ..B1.13       # Prob 100%                     #56.1
                                # LOE
..B1.10:                        # Preds ..B1.8
        movl      $.2.9_2_kmpc_loc_struct_pack.32, %edi         #56.1
        xorl      %eax, %eax                                    #56.1
        movl      188(%rsp), %esi                               #56.1
..___tag_value_main.25:                                         #56.1
        call      __kmpc_serialized_parallel                    #56.1
..___tag_value_main.26:                                         #
                                # LOE
..B1.11:                        # Preds ..B1.10
        movl      $___kmpv_zeromain_0, %esi                     #56.1
        lea       188(%rsp), %rdi                               #56.1
        lea       -8(%rdi), %rdx                                #56.1
        lea       -4(%rdx), %rcx                                #56.1
        lea       (%rsp), %r8                                   #56.1
..___tag_value_main.27:                                         #56.1
        call      L_main_56__par_region0_2.0                    #56.1
..___tag_value_main.28:                                         #
                                # LOE
..B1.12:                        # Preds ..B1.11
        movl      $.2.9_2_kmpc_loc_struct_pack.32, %edi         #56.1
        xorl      %eax, %eax                                    #56.1
        movl      188(%rsp), %esi                               #56.1
..___tag_value_main.29:                                         #56.1
        call      __kmpc_end_serialized_parallel                #56.1
..___tag_value_main.30:                                         #
                                # LOE
..B1.13:                        # Preds ..B1.9 ..B1.12
        vxorpd    %xmm0, %xmm0, %xmm0                           #64.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #64.3
        vcvtsi2sdq 16+timeArr(%rip), %xmm0, %xmm0               #64.3
        vcvtsi2sdq timeArr(%rip), %xmm1, %xmm1                  #64.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #64.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #64.3
        vcvtsi2sdq 24+timeArr(%rip), %xmm3, %xmm3               #64.3
        vcvtsi2sdq 8+timeArr(%rip), %xmm4, %xmm4                #64.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #64.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #64.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #64.3
        movl      $.L_2__STRING.0, %edi                         #64.3
        movl      $1, %eax                                      #64.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #64.3
..___tag_value_main.31:                                         #64.3
        call      printf                                        #64.3
..___tag_value_main.32:                                         #
                                # LOE
..B1.14:                        # Preds ..B1.13
        vxorpd    %xmm0, %xmm0, %xmm0                           #64.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #64.3
        vcvtsi2sdq 48+timeArr(%rip), %xmm0, %xmm0               #64.3
        vcvtsi2sdq 32+timeArr(%rip), %xmm1, %xmm1               #64.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #64.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #64.3
        vcvtsi2sdq 56+timeArr(%rip), %xmm3, %xmm3               #64.3
        vcvtsi2sdq 40+timeArr(%rip), %xmm4, %xmm4               #64.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #64.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #64.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #64.3
        movl      $.L_2__STRING.0, %edi                         #64.3
        movl      $1, %eax                                      #64.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #64.3
..___tag_value_main.33:                                         #64.3
        call      printf                                        #64.3
..___tag_value_main.34:                                         #
                                # LOE
..B1.15:                        # Preds ..B1.14
        vxorpd    %xmm0, %xmm0, %xmm0                           #64.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #64.3
        vcvtsi2sdq 80+timeArr(%rip), %xmm0, %xmm0               #64.3
        vcvtsi2sdq 64+timeArr(%rip), %xmm1, %xmm1               #64.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #64.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #64.3
        vcvtsi2sdq 88+timeArr(%rip), %xmm3, %xmm3               #64.3
        vcvtsi2sdq 72+timeArr(%rip), %xmm4, %xmm4               #64.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #64.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #64.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #64.3
        movl      $.L_2__STRING.0, %edi                         #64.3
        movl      $1, %eax                                      #64.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #64.3
..___tag_value_main.35:                                         #64.3
        call      printf                                        #64.3
..___tag_value_main.36:                                         #
                                # LOE
..B1.16:                        # Preds ..B1.15
        vxorpd    %xmm0, %xmm0, %xmm0                           #64.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #64.3
        vcvtsi2sdq 112+timeArr(%rip), %xmm0, %xmm0              #64.3
        vcvtsi2sdq 96+timeArr(%rip), %xmm1, %xmm1               #64.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #64.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #64.3
        vcvtsi2sdq 120+timeArr(%rip), %xmm3, %xmm3              #64.3
        vcvtsi2sdq 104+timeArr(%rip), %xmm4, %xmm4              #64.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #64.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #64.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #64.3
        movl      $.L_2__STRING.0, %edi                         #64.3
        movl      $1, %eax                                      #64.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #64.3
..___tag_value_main.37:                                         #64.3
        call      printf                                        #64.3
..___tag_value_main.38:                                         #
                                # LOE
..B1.17:                        # Preds ..B1.16
        vxorpd    %xmm0, %xmm0, %xmm0                           #64.3
        vxorpd    %xmm1, %xmm1, %xmm1                           #64.3
        vcvtsi2sdq 144+timeArr(%rip), %xmm0, %xmm0              #64.3
        vcvtsi2sdq 128+timeArr(%rip), %xmm1, %xmm1              #64.3
        vxorpd    %xmm3, %xmm3, %xmm3                           #64.3
        vxorpd    %xmm4, %xmm4, %xmm4                           #64.3
        vcvtsi2sdq 152+timeArr(%rip), %xmm3, %xmm3              #64.3
        vcvtsi2sdq 136+timeArr(%rip), %xmm4, %xmm4              #64.3
        vsubsd    %xmm1, %xmm0, %xmm2                           #64.3
        vsubsd    %xmm4, %xmm3, %xmm6                           #64.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #64.3
        movl      $.L_2__STRING.0, %edi                         #64.3
        movl      $1, %eax                                      #64.3
        vaddsd    %xmm6, %xmm5, %xmm0                           #64.3
..___tag_value_main.39:                                         #64.3
        call      printf                                        #64.3
..___tag_value_main.40:                                         #
                                # LOE
..B1.18:                        # Preds ..B1.17
..___tag_value_main.41:                                         #66.3
        call      MPI_Finalize                                  #66.3
..___tag_value_main.42:                                         #
                                # LOE
..B1.19:                        # Preds ..B1.18
        movl      $.2.9_2_kmpc_loc_struct_pack.24, %edi         #67.1
        xorl      %eax, %eax                                    #67.1
..___tag_value_main.43:                                         #67.1
        call      __kmpc_end                                    #67.1
..___tag_value_main.44:                                         #
                                # LOE
..B1.20:                        # Preds ..B1.19
        movq      136(%rsp), %r15                               #67.1
..___tag_value_main.45:                                         #
        xorl      %eax, %eax                                    #67.1
        movq      144(%rsp), %r14                               #67.1
..___tag_value_main.46:                                         #
        movq      152(%rsp), %r13                               #67.1
..___tag_value_main.47:                                         #
        movq      160(%rsp), %r12                               #67.1
..___tag_value_main.48:                                         #
        movq      168(%rsp), %rbx                               #67.1
..___tag_value_main.49:                                         #
        movq      %rbp, %rsp                                    #67.1
        popq      %rbp                                          #67.1
..___tag_value_main.50:                                         #
        ret                                                     #67.1
..___tag_value_main.52:                                         #
                                # LOE
L_main_56__par_region0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
# parameter 3: %rdx
# parameter 4: %rcx
# parameter 5: %r8
..B1.21:                        # Preds ..B1.0
        pushq     %rbp                                          #56.1
..___tag_value_main.54:                                         #
        movq      %rsp, %rbp                                    #56.1
..___tag_value_main.55:                                         #
        andq      $-128, %rsp                                   #56.1
        subq      $256, %rsp                                    #56.1
        movq      %rbx, 168(%rsp)                               #56.1
        movq      %r15, 136(%rsp)                               #56.1
        movq      %r14, 144(%rsp)                               #56.1
..___tag_value_main.57:                                         #
        movq      %r8, %r14                                     #56.1
        movq      %r13, 152(%rsp)                               #56.1
..___tag_value_main.60:                                         #
        movq      %rcx, %r13                                    #56.1
        movq      %r12, 160(%rsp)                               #56.1
..___tag_value_main.61:                                         #
        movq      %rdx, %r12                                    #56.1
        call      omp_get_thread_num                            #56.1
                                # LOE r12 r13 r14 eax
..B1.30:                        # Preds ..B1.21
        movl      %eax, %ebx                                    #56.1
                                # LOE r12 r13 r14 ebx
..B1.22:                        # Preds ..B1.30
        call      omp_get_num_threads                           #58.10
                                # LOE r12 r13 r14 eax ebx
..B1.23:                        # Preds ..B1.22
        movl      $.L_2__STRING.1, %edi                         #60.5
        movl      %ebx, %esi                                    #60.5
        movl      %eax, %edx                                    #60.5
        movq      %r14, %r9                                     #60.5
        xorl      %eax, %eax                                    #60.5
        movl      (%r12), %ecx                                  #60.5
        movl      (%r13), %r8d                                  #60.5
..___tag_value_main.62:                                         #60.5
        call      printf                                        #60.5
..___tag_value_main.63:                                         #
                                # LOE
..B1.24:                        # Preds ..B1.23
        xorl      %eax, %eax                                    #56.1
        movq      136(%rsp), %r15                               #56.1
..___tag_value_main.64:                                         #
        movq      144(%rsp), %r14                               #56.1
..___tag_value_main.65:                                         #
        movq      152(%rsp), %r13                               #56.1
..___tag_value_main.66:                                         #
        movq      160(%rsp), %r12                               #56.1
..___tag_value_main.67:                                         #
        movq      168(%rsp), %rbx                               #56.1
..___tag_value_main.68:                                         #
        movq      %rbp, %rsp                                    #56.1
        popq      %rbp                                          #56.1
..___tag_value_main.69:                                         #
        ret                                                     #56.1
        .align    16,0x90
..___tag_value_main.71:                                         #
                                # LOE
# mark_end;
	.type	main,@function
	.size	main,.-main
	.data
	.align 4
	.align 4
.2.9_2_kmpc_loc_struct_pack.5:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.9_2__kmpc_loc_pack.4
	.align 4
.2.9_2__kmpc_loc_pack.4:
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
	.byte	52
	.byte	48
	.byte	59
	.byte	52
	.byte	48
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.9_2_kmpc_loc_struct_pack.16:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.9_2__kmpc_loc_pack.15
	.align 4
.2.9_2__kmpc_loc_pack.15:
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
	.space 3, 0x00 	# pad
	.align 4
.2.9_2_kmpc_loc_struct_pack.32:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.9_2__kmpc_loc_pack.31
	.align 4
.2.9_2__kmpc_loc_pack.31:
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
	.byte	54
	.byte	50
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.9_2_kmpc_loc_struct_pack.24:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.9_2__kmpc_loc_pack.23
	.align 4
.2.9_2__kmpc_loc_pack.23:
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
	.byte	55
	.byte	59
	.byte	54
	.byte	55
	.byte	59
	.byte	59
	.data
# -- End  main, L_main_56__par_region0_2.0
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
..___tag_value__Z9time_diff7timevalS_.72:                       #16.1
        vxorpd    %xmm0, %xmm0, %xmm0                           #19.18
        vxorpd    %xmm1, %xmm1, %xmm1                           #18.18
        vxorpd    %xmm3, %xmm3, %xmm3                           #19.45
        vcvtsi2sdq %rdx, %xmm0, %xmm0                           #19.18
        vcvtsi2sdq %rdi, %xmm1, %xmm1                           #18.18
        vcvtsi2sdq %rcx, %xmm3, %xmm3                           #19.45
        vsubsd    %xmm1, %xmm0, %xmm2                           #20.33
        vxorpd    %xmm4, %xmm4, %xmm4                           #18.45
        vcvtsi2sdq %rsi, %xmm4, %xmm4                           #18.45
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #20.33
        vsubsd    %xmm4, %xmm3, %xmm6                           #20.33
        vaddsd    %xmm6, %xmm5, %xmm0                           #20.33
        ret                                                     #21.10
        .align    16,0x90
..___tag_value__Z9time_diff7timevalS_.74:                       #
                                # LOE
# mark_end;
	.type	_Z9time_diff7timevalS_,@function
	.size	_Z9time_diff7timevalS_,.-_Z9time_diff7timevalS_
	.data
# -- End  _Z9time_diff7timevalS_
	.text
# -- Begin  _Z13printTimeDiffv
	.text
# mark_begin;
       .align    16,0x90
	.globl _Z13printTimeDiffv
_Z13printTimeDiffv:
..B3.1:                         # Preds ..B3.0
..___tag_value__Z13printTimeDiffv.75:                           #25.21
        pushq     %rsi                                          #25.21
..___tag_value__Z13printTimeDiffv.77:                           #
        vxorpd    %xmm0, %xmm0, %xmm0                           #28.5
        vxorpd    %xmm1, %xmm1, %xmm1                           #28.5
        vxorpd    %xmm3, %xmm3, %xmm3                           #28.5
        vcvtsi2sdq 16+timeArr(%rip), %xmm0, %xmm0               #28.5
        vcvtsi2sdq timeArr(%rip), %xmm1, %xmm1                  #28.5
        vcvtsi2sdq 24+timeArr(%rip), %xmm3, %xmm3               #28.5
        vsubsd    %xmm1, %xmm0, %xmm2                           #28.5
        vxorpd    %xmm4, %xmm4, %xmm4                           #28.5
        movl      $.L_2__STRING.0, %edi                         #28.5
        vcvtsi2sdq 8+timeArr(%rip), %xmm4, %xmm4                #28.5
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #28.5
        vsubsd    %xmm4, %xmm3, %xmm6                           #28.5
        movl      $1, %eax                                      #28.5
        vaddsd    %xmm6, %xmm5, %xmm0                           #28.5
..___tag_value__Z13printTimeDiffv.78:                           #28.5
        call      printf                                        #28.5
..___tag_value__Z13printTimeDiffv.79:                           #
                                # LOE rbx rbp r12 r13 r14 r15
..B3.2:                         # Preds ..B3.1
        vxorpd    %xmm0, %xmm0, %xmm0                           #28.5
        vxorpd    %xmm1, %xmm1, %xmm1                           #28.5
        vcvtsi2sdq 48+timeArr(%rip), %xmm0, %xmm0               #28.5
        vcvtsi2sdq 32+timeArr(%rip), %xmm1, %xmm1               #28.5
        vxorpd    %xmm3, %xmm3, %xmm3                           #28.5
        vxorpd    %xmm4, %xmm4, %xmm4                           #28.5
        vcvtsi2sdq 56+timeArr(%rip), %xmm3, %xmm3               #28.5
        vcvtsi2sdq 40+timeArr(%rip), %xmm4, %xmm4               #28.5
        vsubsd    %xmm1, %xmm0, %xmm2                           #28.5
        vsubsd    %xmm4, %xmm3, %xmm6                           #28.5
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #28.5
        movl      $.L_2__STRING.0, %edi                         #28.5
        movl      $1, %eax                                      #28.5
        vaddsd    %xmm6, %xmm5, %xmm0                           #28.5
..___tag_value__Z13printTimeDiffv.80:                           #28.5
        call      printf                                        #28.5
..___tag_value__Z13printTimeDiffv.81:                           #
                                # LOE rbx rbp r12 r13 r14 r15
..B3.3:                         # Preds ..B3.2
        vxorpd    %xmm0, %xmm0, %xmm0                           #28.5
        vxorpd    %xmm1, %xmm1, %xmm1                           #28.5
        vcvtsi2sdq 80+timeArr(%rip), %xmm0, %xmm0               #28.5
        vcvtsi2sdq 64+timeArr(%rip), %xmm1, %xmm1               #28.5
        vxorpd    %xmm3, %xmm3, %xmm3                           #28.5
        vxorpd    %xmm4, %xmm4, %xmm4                           #28.5
        vcvtsi2sdq 88+timeArr(%rip), %xmm3, %xmm3               #28.5
        vcvtsi2sdq 72+timeArr(%rip), %xmm4, %xmm4               #28.5
        vsubsd    %xmm1, %xmm0, %xmm2                           #28.5
        vsubsd    %xmm4, %xmm3, %xmm6                           #28.5
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #28.5
        movl      $.L_2__STRING.0, %edi                         #28.5
        movl      $1, %eax                                      #28.5
        vaddsd    %xmm6, %xmm5, %xmm0                           #28.5
..___tag_value__Z13printTimeDiffv.82:                           #28.5
        call      printf                                        #28.5
..___tag_value__Z13printTimeDiffv.83:                           #
                                # LOE rbx rbp r12 r13 r14 r15
..B3.4:                         # Preds ..B3.3
        vxorpd    %xmm0, %xmm0, %xmm0                           #28.5
        vxorpd    %xmm1, %xmm1, %xmm1                           #28.5
        vcvtsi2sdq 112+timeArr(%rip), %xmm0, %xmm0              #28.5
        vcvtsi2sdq 96+timeArr(%rip), %xmm1, %xmm1               #28.5
        vxorpd    %xmm3, %xmm3, %xmm3                           #28.5
        vxorpd    %xmm4, %xmm4, %xmm4                           #28.5
        vcvtsi2sdq 120+timeArr(%rip), %xmm3, %xmm3              #28.5
        vcvtsi2sdq 104+timeArr(%rip), %xmm4, %xmm4              #28.5
        vsubsd    %xmm1, %xmm0, %xmm2                           #28.5
        vsubsd    %xmm4, %xmm3, %xmm6                           #28.5
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #28.5
        movl      $.L_2__STRING.0, %edi                         #28.5
        movl      $1, %eax                                      #28.5
        vaddsd    %xmm6, %xmm5, %xmm0                           #28.5
..___tag_value__Z13printTimeDiffv.84:                           #28.5
        call      printf                                        #28.5
..___tag_value__Z13printTimeDiffv.85:                           #
                                # LOE rbx rbp r12 r13 r14 r15
..B3.5:                         # Preds ..B3.4
        vxorpd    %xmm0, %xmm0, %xmm0                           #28.5
        vxorpd    %xmm1, %xmm1, %xmm1                           #28.5
        vcvtsi2sdq 144+timeArr(%rip), %xmm0, %xmm0              #28.5
        vcvtsi2sdq 128+timeArr(%rip), %xmm1, %xmm1              #28.5
        vxorpd    %xmm3, %xmm3, %xmm3                           #28.5
        vxorpd    %xmm4, %xmm4, %xmm4                           #28.5
        vcvtsi2sdq 152+timeArr(%rip), %xmm3, %xmm3              #28.5
        vcvtsi2sdq 136+timeArr(%rip), %xmm4, %xmm4              #28.5
        vsubsd    %xmm1, %xmm0, %xmm2                           #28.5
        vsubsd    %xmm4, %xmm3, %xmm6                           #28.5
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm5      #28.5
        movl      $.L_2__STRING.0, %edi                         #28.5
        movl      $1, %eax                                      #28.5
        vaddsd    %xmm6, %xmm5, %xmm0                           #28.5
        addq      $8, %rsp                                      #28.5
..___tag_value__Z13printTimeDiffv.86:                           #
        jmp       printf                                        #28.5
        .align    16,0x90
..___tag_value__Z13printTimeDiffv.87:                           #
                                # LOE
# mark_end;
	.type	_Z13printTimeDiffv,@function
	.size	_Z13printTimeDiffv,.-_Z13printTimeDiffv
	.data
# -- End  _Z13printTimeDiffv
	.text
# -- Begin  _Z7addTimev
	.text
# mark_begin;
       .align    16,0x90
	.globl _Z7addTimev
_Z7addTimev:
..B4.1:                         # Preds ..B4.0
..___tag_value__Z7addTimev.88:                                  #33.15
        pushq     %rsi                                          #33.15
..___tag_value__Z7addTimev.90:                                  #
        xorl      %esi, %esi                                    #35.3
        movslq    count(%rip), %rax                             #35.3
        shlq      $4, %rax                                      #35.3
        lea       timeArr(%rax), %rdi                           #35.3
        call      gettimeofday                                  #35.3
                                # LOE rbx rbp r12 r13 r14 r15
..B4.2:                         # Preds ..B4.1
        incl      count(%rip)                                   #36.3
        popq      %rcx                                          #37.1
..___tag_value__Z7addTimev.91:                                  #
        ret                                                     #37.1
        .align    16,0x90
..___tag_value__Z7addTimev.92:                                  #
                                # LOE
# mark_end;
	.type	_Z7addTimev,@function
	.size	_Z7addTimev,.-_Z7addTimev
	.data
# -- End  _Z7addTimev
	.bss
	.align 32
	.align 32
	.globl timeArr
timeArr:
	.type	timeArr,@object
	.size	timeArr,320
	.space 320	# pad
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
	.align 4
	.globl count
count:
	.type	count,@object
	.size	count,4
	.space 4	# pad
	.section .rodata, "a"
	.align 8
	.align 8
.L_2il0floatpacket.5:
	.long	0x00000000,0x412e8480
	.type	.L_2il0floatpacket.5,@object
	.size	.L_2il0floatpacket.5,8
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
.L_2__STRING.0:
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
	.type	.L_2__STRING.0,@object
	.size	.L_2__STRING.0,53
	.section .rodata.str1.32, "aMS",@progbits,1
	.align 32
	.align 32
.L_2__STRING.1:
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
	.type	.L_2__STRING.1,@object
	.size	.L_2__STRING.1,64
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
	.8byte ..___tag_value_main.71-..___tag_value_main.1
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
	.4byte ..___tag_value_main.45-..___tag_value_main.6
	.2byte 0x04cf
	.4byte ..___tag_value_main.46-..___tag_value_main.45
	.2byte 0x04ce
	.4byte ..___tag_value_main.47-..___tag_value_main.46
	.2byte 0x04cd
	.4byte ..___tag_value_main.48-..___tag_value_main.47
	.2byte 0x04cc
	.4byte ..___tag_value_main.49-..___tag_value_main.48
	.2byte 0x04c3
	.4byte ..___tag_value_main.50-..___tag_value_main.49
	.4byte 0xc608070c
	.byte 0x04
	.4byte ..___tag_value_main.52-..___tag_value_main.50
	.4byte 0x0410060c
	.4byte ..___tag_value_main.54-..___tag_value_main.52
	.4byte 0x0410070c
	.4byte ..___tag_value_main.55-..___tag_value_main.54
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.57-..___tag_value_main.55
	.8byte 0xff800d1c380e0310
	.8byte 0xffffffa80d1affff
	.8byte 0x800d1c380e0e1022
	.8byte 0xffff900d1affffff
	.8byte 0x0d1c380e0f1022ff
	.8byte 0xff880d1affffff80
	.4byte 0x0422ffff
	.4byte ..___tag_value_main.60-..___tag_value_main.57
	.8byte 0xff800d1c380e0d10
	.8byte 0xffffff980d1affff
	.2byte 0x0422
	.4byte ..___tag_value_main.61-..___tag_value_main.60
	.8byte 0xff800d1c380e0c10
	.8byte 0xffffffa00d1affff
	.2byte 0x0422
	.4byte ..___tag_value_main.64-..___tag_value_main.61
	.2byte 0x04cf
	.4byte ..___tag_value_main.65-..___tag_value_main.64
	.2byte 0x04ce
	.4byte ..___tag_value_main.66-..___tag_value_main.65
	.2byte 0x04cd
	.4byte ..___tag_value_main.67-..___tag_value_main.66
	.2byte 0x04cc
	.4byte ..___tag_value_main.68-..___tag_value_main.67
	.2byte 0x04c3
	.4byte ..___tag_value_main.69-..___tag_value_main.68
	.4byte 0xc608070c
	.4byte 0x0000001c
	.4byte 0x00000174
	.8byte ..___tag_value__Z9time_diff7timevalS_.72
	.8byte ..___tag_value__Z9time_diff7timevalS_.74-..___tag_value__Z9time_diff7timevalS_.72
	.8byte 0x0000000000000000
	.4byte 0x00000024
	.4byte 0x00000194
	.8byte ..___tag_value__Z13printTimeDiffv.75
	.8byte ..___tag_value__Z13printTimeDiffv.87-..___tag_value__Z13printTimeDiffv.75
	.2byte 0x0400
	.4byte ..___tag_value__Z13printTimeDiffv.77-..___tag_value__Z13printTimeDiffv.75
	.2byte 0x100e
	.byte 0x04
	.4byte ..___tag_value__Z13printTimeDiffv.86-..___tag_value__Z13printTimeDiffv.77
	.2byte 0x080e
	.byte 0x00
	.4byte 0x00000024
	.4byte 0x000001bc
	.8byte ..___tag_value__Z7addTimev.88
	.8byte ..___tag_value__Z7addTimev.92-..___tag_value__Z7addTimev.88
	.2byte 0x0400
	.4byte ..___tag_value__Z7addTimev.90-..___tag_value__Z7addTimev.88
	.2byte 0x100e
	.byte 0x04
	.4byte ..___tag_value__Z7addTimev.91-..___tag_value__Z7addTimev.90
	.2byte 0x080e
	.byte 0x00
# End
