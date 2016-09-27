# mark_description "Intel(R) C++ Intel(R) 64 Compiler XE for applications running on Intel(R) 64, Version 15.0.1.133 Build 20141";
# mark_description "023";
# mark_description "-I/opt/cray/mpt/7.4.1/gni/sma/include -I/opt/cray/libsci/16.07.1/INTEL/15.0/x86_64/include -I/opt/cray/mpt/7";
# mark_description ".4.1/gni/mpich-intel/15.0/include -I/opt/cray/rca/1.0.0-2.0502.57212.2.56.ari/include -I/opt/cray/alps/5.2.3";
# mark_description "-2.0502.9295.14.14.ari/include -I/opt/cray/xpmem/0.1-2.0502.57015.1.15.ari/include -I/opt/cray/gni-headers/4";
# mark_description ".0-1.0502.10317.9.2.ari/include -I/opt/cray/dmapp/7.0.1-1.0502.10246.8.47.ari/include -I/opt/cray/pmi/5.0.10";
# mark_description "-1.0000.11050.0.0.ari/include -I/opt/cray/ugni/6.0-1.0502.10245.9.9.ari/include -I/opt/cray/udreg/2.3.2-1.05";
# mark_description "02.9889.2.20.ari/include -I/usr/local/include -I/opt/cray/wlm_detect/1.0-1.0502.57063.1.1.ari/include -I/opt";
# mark_description "/cray/krca/1.0.0-2.0502.57202.2.45.ari/include -I/opt/cray-hss-devel/7.2.0/include -xCORE-AVX-I -static -D__";
# mark_description "CRAYXC -D__CRAY_IVYBRIDGE -D__CRAYXT_COMPUTE_LINUX_TARGET -S -o custom_tests/MPI_waitall.s -openmp";
	.file "MPI_waitall.c"
	.text
..TXTST0:
# -- Begin  main, L_main_85__par_loop0_2.0, L_main_85__tree_reduce0_2.1
	.text
# mark_begin;
       .align    16,0x90
	.globl main
main:
# parameter 1: %edi
# parameter 2: %rsi
..B1.1:                         # Preds ..B1.0
..___tag_value_main.1:                                          #25.34
        pushq     %rbp                                          #25.34
..___tag_value_main.3:                                          #
        movq      %rsp, %rbp                                    #25.34
..___tag_value_main.4:                                          #
        andq      $-128, %rsp                                   #25.34
        subq      $1664, %rsp                                   #25.34
        movl      %edi, 1600(%rsp)                              #25.34
        movl      $3, %edi                                      #25.34
        movq      %rsi, 1592(%rsp)                              #25.34
        movl      $104446, %esi                                 #25.34
        movq      %rbx, 1384(%rsp)                              #25.34
        movq      %r15, 1352(%rsp)                              #25.34
        movq      %r14, 1360(%rsp)                              #25.34
        movq      %r13, 1368(%rsp)                              #25.34
        movq      %r12, 1376(%rsp)                              #25.34
        call      __intel_new_feature_proc_init                 #25.34
..___tag_value_main.6:                                          #
                                # LOE
..B1.67:                        # Preds ..B1.1
        vstmxcsr  (%rsp)                                        #25.34
        movl      $.2.5_2_kmpc_loc_struct_pack.1, %edi          #25.34
        xorl      %esi, %esi                                    #25.34
        orl       $32832, (%rsp)                                #25.34
        xorl      %eax, %eax                                    #25.34
        vldmxcsr  (%rsp)                                        #25.34
..___tag_value_main.11:                                         #25.34
        call      __kmpc_begin                                  #25.34
..___tag_value_main.12:                                         #
                                # LOE
..B1.2:                         # Preds ..B1.67
        lea       1600(%rsp), %rdi                              #34.3
        lea       1592(%rsp), %rsi                              #34.3
..___tag_value_main.13:                                         #34.3
        call      MPI_Init                                      #34.3
..___tag_value_main.14:                                         #
                                # LOE
..B1.3:                         # Preds ..B1.2
        movl      $1140850688, %edi                             #35.3
        lea       1612(%rsp), %rsi                              #35.3
..___tag_value_main.15:                                         #35.3
        call      MPI_Comm_size                                 #35.3
..___tag_value_main.16:                                         #
                                # LOE
..B1.4:                         # Preds ..B1.3
        movl      $1140850688, %edi                             #36.3
        lea       1604(%rsp), %rsi                              #36.3
..___tag_value_main.17:                                         #36.3
        call      MPI_Comm_rank                                 #36.3
..___tag_value_main.18:                                         #
                                # LOE
..B1.5:                         # Preds ..B1.4
        movl      1612(%rsp), %ebx                              #39.7
        lea       -2(%rbx), %eax                                #39.10
        cmpl      $46, %eax                                     #39.10
        jbe       ..B1.10       # Prob 50%                      #39.10
                                # LOE ebx
..B1.6:                         # Preds ..B1.5
        cmpl      $0, 1604(%rsp)                                #40.15
        jne       ..B1.8        # Prob 78%                      #40.15
                                # LOE
..B1.7:                         # Preds ..B1.6
        movl      $.L_2__STRING.1, %edi                         #41.7
        movl      $48, %esi                                     #41.7
        xorl      %eax, %eax                                    #41.7
..___tag_value_main.19:                                         #41.7
        call      printf                                        #41.7
..___tag_value_main.20:                                         #
                                # LOE
..B1.8:                         # Preds ..B1.44 ..B1.72 ..B1.39 ..B1.7 ..B1.6
                                #      
..___tag_value_main.21:                                         #43.5
        call      MPI_Finalize                                  #43.5
..___tag_value_main.22:                                         #
                                # LOE
..B1.9:                         # Preds ..B1.8
        xorl      %edi, %edi                                    #44.5
        call      exit                                          #44.5
                                # LOE
..B1.10:                        # Preds ..B1.5
        movl      1604(%rsp), %esi                              #47.7
        movl      %esi, 1608(%rsp)                              #47.3
        testl     %esi, %esi                                    #49.13
        jne       ..B1.41       # Prob 50%                      #49.13
                                # LOE ebx esi
..B1.11:                        # Preds ..B1.10
        movl      $.L_2__STRING.2, %edi                         #51.5
        xorl      %eax, %eax                                    #51.5
..___tag_value_main.23:                                         #51.5
        call      printf                                        #51.5
..___tag_value_main.24:                                         #
                                # LOE ebx
..B1.12:                        # Preds ..B1.11
        movl      $1, %r13d                                     #53.10
        lea       1164(%rsp), %r12                              #53.12
        cmpl      $1, %ebx                                      #53.17
        jle       ..B1.18       # Prob 10%                      #53.17
                                # LOE r12 ebx r13d
..B1.14:                        # Preds ..B1.12 ..B1.16
        movl      $.L_2__STRING.3, %edi                         #54.7
        movl      %r13d, %edx                                   #54.7
        xorl      %eax, %eax                                    #54.7
        movl      1604(%rsp), %esi                              #54.7
..___tag_value_main.25:                                         #54.7
        call      printf                                        #54.7
..___tag_value_main.26:                                         #
                                # LOE r12 r13d
..B1.15:                        # Preds ..B1.14
        addq      $-16, %rsp                                    #55.7
        movl      $1, %esi                                      #55.7
        movl      $1275069445, %edx                             #55.7
        lea       1624(%rsp), %rdi                              #55.7
        movl      %r13d, %ecx                                   #55.7
        movl      $42, %r8d                                     #55.7
        movl      $1140850688, %r9d                             #55.7
        movq      %r12, (%rsp)                                  #55.7
..___tag_value_main.27:                                         #55.7
        call      MPI_Isend                                     #55.7
..___tag_value_main.28:                                         #
                                # LOE r12 r13d
..B1.68:                        # Preds ..B1.15
        addq      $16, %rsp                                     #55.7
                                # LOE r12 r13d
..B1.16:                        # Preds ..B1.68
        incl      %r13d                                         #53.21
        addq      $4, %r12                                      #53.21
        movl      1612(%rsp), %ebx                              #53.17
        cmpl      %ebx, %r13d                                   #53.17
        jl        ..B1.14       # Prob 82%                      #53.17
                                # LOE r12 ebx r13d
..B1.18:                        # Preds ..B1.16 ..B1.12
        decl      %ebx                                          #62.5
        lea       1164(%rsp), %rsi                              #62.5
        movl      %ebx, %edi                                    #62.5
        lea       28(%rsp), %rdx                                #62.5
..___tag_value_main.29:                                         #62.5
        call      MPI_Waitall                                   #62.5
..___tag_value_main.30:                                         #
                                # LOE
..B1.19:                        # Preds ..B1.18
        movl      $.L_2__STRING.4, %edi                         #64.5
        xorl      %eax, %eax                                    #64.5
        movl      1604(%rsp), %esi                              #64.5
..___tag_value_main.31:                                         #64.5
        call      printf                                        #64.5
..___tag_value_main.32:                                         #
                                # LOE
..B1.20:                        # Preds ..B1.19
        movl      1612(%rsp), %r15d                             #66.19
        movl      $1, %r14d                                     #66.10
        movl      $4, %r13d                                     #66.10
        cmpl      $1, %r15d                                     #66.19
        jle       ..B1.25       # Prob 10%                      #66.19
                                # LOE r13 r14 r15d
..B1.21:                        # Preds ..B1.20
        lea       1392(%rsp), %r12                              #67.7
        lea       968(%rsp), %rbx                               #67.7
                                # LOE rbx r12 r13 r14
..B1.22:                        # Preds ..B1.23 ..B1.21
        addq      $-16, %rsp                                    #67.7
        lea       (%r12,%r13), %rdi                             #67.7
        movl      $1, %esi                                      #67.7
        movl      $1275069445, %edx                             #67.7
        movl      $-2, %ecx                                     #67.7
        movl      $42, %r8d                                     #67.7
        movl      $1140850688, %r9d                             #67.7
        lea       (%rbx,%r13), %rax                             #67.7
        movq      %rax, (%rsp)                                  #67.7
..___tag_value_main.33:                                         #67.7
        call      MPI_Irecv                                     #67.7
..___tag_value_main.34:                                         #
                                # LOE rbx r12 r13 r14
..B1.69:                        # Preds ..B1.22
        addq      $16, %rsp                                     #67.7
                                # LOE rbx r12 r13 r14
..B1.23:                        # Preds ..B1.69
        movl      1612(%rsp), %r15d                             #66.19
        incq      %r14                                          #66.23
        movslq    %r15d, %r15                                   #66.5
        addq      $4, %r13                                      #66.23
        cmpq      %r15, %r14                                    #66.19
        jl        ..B1.22       # Prob 97%                      #66.19
                                # LOE rbx r12 r13 r14 r15d
..B1.25:                        # Preds ..B1.23 ..B1.20
        movl      $il0_peep_printf_format_0, %edi               #73.5
        call      puts                                          #73.5
                                # LOE r15d
..B1.26:                        # Preds ..B1.25
        decl      %r15d                                         #74.5
        lea       972(%rsp), %rsi                               #74.5
        movl      %r15d, %edi                                   #74.5
        lea       28(%rsp), %rdx                                #74.5
..___tag_value_main.35:                                         #74.5
        call      MPI_Waitall                                   #74.5
..___tag_value_main.36:                                         #
                                # LOE
..B1.27:                        # Preds ..B1.26
        movslq    1612(%rsp), %r12                              #77.17
        movl      $1, %r13d                                     #77.10
        movl      1604(%rsp), %ebx                              #78.65
        cmpq      $1, %r12                                      #77.17
        jle       ..B1.32       # Prob 10%                      #77.17
                                # LOE r12 r13 ebx
..B1.29:                        # Preds ..B1.27 ..B1.30
        movl      $.L_2__STRING.5, %edi                         #78.7
        movl      %ebx, %esi                                    #78.7
        xorl      %eax, %eax                                    #78.7
        movl      1392(%rsp,%r13,4), %edx                       #78.7
..___tag_value_main.37:                                         #78.7
        call      printf                                        #78.7
..___tag_value_main.38:                                         #
                                # LOE r12 r13 ebx
..B1.30:                        # Preds ..B1.29
        incq      %r13                                          #77.21
        cmpq      %r12, %r13                                    #77.17
        jl        ..B1.29       # Prob 97%                      #77.17
                                # LOE r12 r13 ebx
..B1.32:                        # Preds ..B1.30 ..B1.27
        movl      $.L_2__STRING.6, %edi                         #80.5
        movl      %ebx, %esi                                    #80.5
        xorl      %eax, %eax                                    #80.5
..___tag_value_main.39:                                         #80.5
        call      printf                                        #80.5
..___tag_value_main.40:                                         #
                                # LOE
..B1.33:                        # Preds ..B1.32
        movl      $il0_peep_printf_format_1, %edi               #83.5
        call      puts                                          #83.5
                                # LOE
..B1.34:                        # Preds ..B1.33
        movl      $.2.5_2_kmpc_loc_struct_pack.12, %edi         #85.5
        movl      $0, 1584(%rsp)                                #84.13
        call      __kmpc_global_thread_num                      #85.5
                                # LOE eax
..B1.71:                        # Preds ..B1.34
        movl      %eax, 1588(%rsp)                              #85.5
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        xorl      %eax, %eax                                    #85.5
        movl      $1, .2.5_2__kmpc_chunk_pack_.19(%rip)         #85.5
..___tag_value_main.41:                                         #85.5
        call      __kmpc_ok_to_fork                             #85.5
..___tag_value_main.42:                                         #
                                # LOE eax
..B1.35:                        # Preds ..B1.71
        testl     %eax, %eax                                    #85.5
        je        ..B1.37       # Prob 50%                      #85.5
                                # LOE
..B1.36:                        # Preds ..B1.35
        addq      $-16, %rsp                                    #85.5
        movl      $L_main_85__par_loop0_2.0, %edx               #85.5
        movl      $.2.5_2__kmpc_chunk_pack_.19, %r9d            #85.5
        lea       1600(%rsp), %rax                              #85.5
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        lea       16(%rsp), %rcx                                #85.5
        movl      $4, %esi                                      #85.5
        lea       4(%rcx), %r8                                  #85.5
        movq      %rax, (%rsp)                                  #85.5
        xorl      %eax, %eax                                    #85.5
..___tag_value_main.43:                                         #85.5
        call      __kmpc_fork_call                              #85.5
..___tag_value_main.44:                                         #
                                # LOE
..B1.72:                        # Preds ..B1.36
        addq      $16, %rsp                                     #85.5
        jmp       ..B1.8        # Prob 100%                     #85.5
                                # LOE
..B1.37:                        # Preds ..B1.35
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        xorl      %eax, %eax                                    #85.5
        movl      1588(%rsp), %esi                              #85.5
..___tag_value_main.45:                                         #85.5
        call      __kmpc_serialized_parallel                    #85.5
..___tag_value_main.46:                                         #
                                # LOE
..B1.38:                        # Preds ..B1.37
        movl      $___kmpv_zeromain_0, %esi                     #85.5
        lea       1588(%rsp), %rdi                              #85.5
        movl      $.2.5_2__kmpc_chunk_pack_.19, %r8d            #85.5
        lea       (%rsp), %rdx                                  #85.5
        lea       4(%rdx), %rcx                                 #85.5
        lea       -4(%rdi), %r9                                 #85.5
..___tag_value_main.47:                                         #85.5
        call      L_main_85__par_loop0_2.0                      #85.5
..___tag_value_main.48:                                         #
                                # LOE
..B1.39:                        # Preds ..B1.38
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        xorl      %eax, %eax                                    #85.5
        movl      1588(%rsp), %esi                              #85.5
..___tag_value_main.49:                                         #85.5
        call      __kmpc_end_serialized_parallel                #85.5
..___tag_value_main.50:                                         #
        jmp       ..B1.8        # Prob 100%                     #85.5
                                # LOE
..B1.41:                        # Preds ..B1.10
        addq      $-16, %rsp                                    #93.5
        movl      $1, %esi                                      #93.5
        movl      $1275069445, %edx                             #93.5
        lea       1408(%rsp), %rdi                              #93.5
        xorl      %ecx, %ecx                                    #93.5
        movl      $42, %r8d                                     #93.5
        movl      $1140850688, %r9d                             #93.5
        lea       984(%rsp), %rbx                               #93.5
        movq      %rbx, (%rsp)                                  #93.5
..___tag_value_main.51:                                         #93.5
        call      MPI_Irecv                                     #93.5
..___tag_value_main.52:                                         #
                                # LOE rbx
..B1.73:                        # Preds ..B1.41
        addq      $16, %rsp                                     #93.5
                                # LOE rbx
..B1.42:                        # Preds ..B1.73
        movq      %rbx, %rdi                                    #94.5
        lea       8(%rsp), %rsi                                 #94.5
..___tag_value_main.53:                                         #94.5
        call      MPI_Wait                                      #94.5
..___tag_value_main.54:                                         #
                                # LOE
..B1.43:                        # Preds ..B1.42
        addq      $-16, %rsp                                    #96.5
        movl      $1, %esi                                      #96.5
        movl      $1275069445, %edx                             #96.5
        lea       1624(%rsp), %rdi                              #96.5
        xorl      %ecx, %ecx                                    #96.5
        movl      $42, %r8d                                     #96.5
        movl      $1140850688, %r9d                             #96.5
        lea       1176(%rsp), %rbx                              #96.5
        movq      %rbx, (%rsp)                                  #96.5
..___tag_value_main.55:                                         #96.5
        call      MPI_Isend                                     #96.5
..___tag_value_main.56:                                         #
                                # LOE rbx
..B1.74:                        # Preds ..B1.43
        addq      $16, %rsp                                     #96.5
                                # LOE rbx
..B1.44:                        # Preds ..B1.74
        movq      %rbx, %rdi                                    #98.5
        lea       8(%rsp), %rsi                                 #98.5
..___tag_value_main.57:                                         #98.5
        call      MPI_Wait                                      #98.5
..___tag_value_main.58:                                         #
        jmp       ..B1.8        # Prob 100%                     #98.5
..___tag_value_main.59:                                         #
                                # LOE
L_main_85__tree_reduce0_2.1:
# parameter 1: %rdi
# parameter 2: %rsi
..B1.47:                        # Preds ..B1.0
        pushq     %rbp                                          #85.5
..___tag_value_main.66:                                         #
        movq      %rsp, %rbp                                    #85.5
..___tag_value_main.67:                                         #
        andq      $-128, %rsp                                   #85.5
        subq      $1664, %rsp                                   #85.5
        movl      (%rsi), %eax                                  #85.5
        movq      %r15, 1352(%rsp)                              #85.5
        movq      %r14, 1360(%rsp)                              #85.5
        movq      %r13, 1368(%rsp)                              #85.5
        movq      %r12, 1376(%rsp)                              #85.5
        movq      %rbx, 1384(%rsp)                              #85.5
        addl      %eax, (%rdi)                                  #85.5
        xorl      %eax, %eax                                    #85.5
        movq      1352(%rsp), %r15                              #85.5
..___tag_value_main.69:                                         #
        movq      1360(%rsp), %r14                              #85.5
..___tag_value_main.73:                                         #
        movq      1368(%rsp), %r13                              #85.5
..___tag_value_main.74:                                         #
        movq      1376(%rsp), %r12                              #85.5
..___tag_value_main.75:                                         #
        movq      1384(%rsp), %rbx                              #85.5
..___tag_value_main.76:                                         #
        movq      %rbp, %rsp                                    #85.5
        popq      %rbp                                          #85.5
..___tag_value_main.77:                                         #
        ret                                                     #85.5
..___tag_value_main.79:                                         #
                                # LOE
L_main_85__par_loop0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
# parameter 3: %rdx
# parameter 4: %rcx
# parameter 5: %r8
# parameter 6: %r9
..B1.48:                        # Preds ..B1.0
        pushq     %rbp                                          #85.5
..___tag_value_main.81:                                         #
        movq      %rsp, %rbp                                    #85.5
..___tag_value_main.82:                                         #
        andq      $-128, %rsp                                   #85.5
        subq      $1664, %rsp                                   #85.5
        movq      %rbx, 1384(%rsp)                              #85.5
..___tag_value_main.84:                                         #
        movl      LOOPCOUNT(%rip), %ebx                         #86.10
        movq      %r12, 1376(%rsp)                              #85.5
        movq      %r15, 1352(%rsp)                              #85.5
        movq      %r14, 1360(%rsp)                              #85.5
        movq      %r13, 1368(%rsp)                              #85.5
..___tag_value_main.85:                                         #
        movq      %r9, %r13                                     #85.5
        movl      (%rdi), %r12d                                 #85.5
        movl      $0, (%rsp)                                    #85.5
        movl      %ebx, (%rdx)                                  #86.10
        testl     %ebx, %ebx                                    #87.5
        jle       ..B1.59       # Prob 10%                      #87.5
                                # LOE r8 r13 ebx r12d
..B1.49:                        # Preds ..B1.48
        movl      $1, %r11d                                     #85.5
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        movl      %r11d, 4(%rsp)                                #85.5
        movl      %r12d, %esi                                   #85.5
        movl      %ebx, 8(%rsp)                                 #85.5
        movl      $33, %edx                                     #85.5
        movl      $0, 12(%rsp)                                  #85.5
        xorl      %eax, %eax                                    #85.5
        movl      %r11d, 16(%rsp)                               #85.5
        addq      $-32, %rsp                                    #85.5
        movl      (%r8), %r14d                                  #85.5
        lea       44(%rsp), %rcx                                #85.5
        lea       36(%rsp), %r8                                 #85.5
        lea       40(%rsp), %r9                                 #85.5
        lea       48(%rsp), %r10                                #85.5
        movq      %r10, (%rsp)                                  #85.5
        movl      %r11d, 8(%rsp)                                #85.5
        movl      %r14d, 16(%rsp)                               #85.5
..___tag_value_main.89:                                         #85.5
        call      __kmpc_for_static_init_4                      #85.5
..___tag_value_main.90:                                         #
                                # LOE r13 ebx r12d
..B1.75:                        # Preds ..B1.49
        addq      $32, %rsp                                     #85.5
                                # LOE r13 ebx r12d
..B1.50:                        # Preds ..B1.75
        movl      4(%rsp), %r10d                                #85.5
        movl      %r10d, %r9d                                   #85.5
        movl      16(%rsp), %r8d                                #85.5
        movl      %r8d, %edi                                    #85.5
        movl      8(%rsp), %eax                                 #85.5
        negl      %r9d                                          #85.5
        movl      (%rsp), %ecx                                  #88.8
        negl      %edi                                          #85.5
        jmp       ..B1.51       # Prob 100%                     #85.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r12d
..B1.56:                        # Preds ..B1.55
        movl      %ecx, (%rsp)                                  #88.2
        addl      %edi, %r9d                                    #85.5
        addl      %r8d, %r10d                                   #85.5
        addl      %r8d, %eax                                    #85.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r12d
..B1.51:                        # Preds ..B1.56 ..B1.50
        cmpl      %ebx, %r10d                                   #85.5
        jg        ..B1.58       # Prob 50%                      #85.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r12d
..B1.52:                        # Preds ..B1.51
        cmpl      %ebx, %eax                                    #85.5
        cmovge    %ebx, %eax                                    #85.5
        cmpl      %eax, %r10d                                   #87.5
        jg        ..B1.58       # Prob 50%                      #87.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r12d
..B1.54:                        # Preds ..B1.52
        xorl      %r15d, %r15d                                  #85.5
        lea       1(%rax,%r9), %r14d                            #85.5
        movl      %r10d, %r11d                                  #85.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r11d r12d r14d r15d
..B1.55:                        # Preds ..B1.55 ..B1.54
        incl      %r15d                                         #85.5
        addl      %r11d, %ecx                                   #85.5
        incl      %r11d                                         #85.5
        cmpl      %r14d, %r15d                                  #85.5
        jb        ..B1.55       # Prob 82%                      #85.5
        jmp       ..B1.56       # Prob 100%                     #85.5
                                # LOE r13 eax ecx ebx edi r8d r9d r10d r11d r12d r14d r15d
..B1.58:                        # Preds ..B1.51 ..B1.52
        movl      $.2.5_2_kmpc_loc_struct_pack.21, %edi         #85.5
        movl      %r12d, %esi                                   #85.5
        xorl      %eax, %eax                                    #85.5
..___tag_value_main.91:                                         #85.5
        call      __kmpc_for_static_fini                        #85.5
..___tag_value_main.92:                                         #
                                # LOE r13 r12d
..B1.59:                        # Preds ..B1.58 ..B1.48
        addq      $-16, %rsp                                    #85.5
        movl      $.2.5_2_kmpc_loc_struct_pack.52, %ebx         #85.5
        movl      $L_main_85__tree_reduce0_2.1, %r9d            #85.5
        lea       16(%rsp), %r8                                 #85.5
        movq      %rbx, %rdi                                    #85.5
        movl      %r12d, %esi                                   #85.5
        xorl      %edx, %edx                                    #85.5
        incl      %edx                                          #85.5
        movl      $4, %ecx                                      #85.5
        xorl      %eax, %eax                                    #85.5
        movq      $main_kmpc_tree_reduct_lock_0, (%rsp)         #85.5
..___tag_value_main.93:                                         #85.5
        call      __kmpc_reduce_nowait                          #85.5
..___tag_value_main.94:                                         #
                                # LOE rbx r13 eax r12d
..B1.76:                        # Preds ..B1.59
        addq      $16, %rsp                                     #85.5
                                # LOE rbx r13 eax r12d
..B1.60:                        # Preds ..B1.76
        cmpl      $1, %eax                                      #85.5
        jne       ..B1.62       # Prob 50%                      #85.5
                                # LOE rbx r13 eax r12d
..B1.61:                        # Preds ..B1.60
        movl      (%rsp), %eax                                  #85.5
        movl      $main_kmpc_tree_reduct_lock_0, %edx           #85.5
        addl      %eax, (%r13)                                  #85.5
        movq      %rbx, %rdi                                    #85.5
        movl      %r12d, %esi                                   #85.5
        xorl      %eax, %eax                                    #85.5
..___tag_value_main.95:                                         #85.5
        call      __kmpc_end_reduce_nowait                      #85.5
..___tag_value_main.96:                                         #
        jmp       ..B1.64       # Prob 100%                     #85.5
                                # LOE
..B1.62:                        # Preds ..B1.60
        cmpl      $2, %eax                                      #85.5
        jne       ..B1.64       # Prob 50%                      #85.5
                                # LOE rbx r13 r12d
..B1.63:                        # Preds ..B1.62
        movq      %rbx, %rdi                                    #85.5
        movl      %r12d, %esi                                   #85.5
        movq      %r13, %rdx                                    #85.5
        xorl      %eax, %eax                                    #85.5
        movl      (%rsp), %ecx                                  #85.5
..___tag_value_main.97:                                         #85.5
        call      __kmpc_atomic_fixed4_add                      #85.5
..___tag_value_main.98:                                         #
                                # LOE
..B1.64:                        # Preds ..B1.61 ..B1.63 ..B1.62
        xorl      %eax, %eax                                    #85.5
        movq      1352(%rsp), %r15                              #85.5
..___tag_value_main.99:                                         #
        movq      1360(%rsp), %r14                              #85.5
..___tag_value_main.100:                                        #
        movq      1368(%rsp), %r13                              #85.5
..___tag_value_main.101:                                        #
        movq      1376(%rsp), %r12                              #85.5
..___tag_value_main.102:                                        #
        movq      1384(%rsp), %rbx                              #85.5
..___tag_value_main.103:                                        #
        movq      %rbp, %rsp                                    #85.5
        popq      %rbp                                          #85.5
..___tag_value_main.104:                                        #
        ret                                                     #85.5
        .align    16,0x90
..___tag_value_main.106:                                        #
                                # LOE
# mark_end;
	.type	main,@function
	.size	main,.-main
	.bss
	.align 4
	.align 4
.2.5_2__kmpc_chunk_pack_.19:
	.type	.2.5_2__kmpc_chunk_pack_.19,@object
	.size	.2.5_2__kmpc_chunk_pack_.19,4
	.space 4	# pad
	.data
	.align 4
	.align 4
.2.5_2_kmpc_loc_struct_pack.1:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.0
	.align 4
.2.5_2__kmpc_loc_pack.0:
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
	.byte	53
	.byte	59
	.byte	50
	.byte	53
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.12:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.11
	.align 4
.2.5_2__kmpc_loc_pack.11:
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
	.byte	53
	.byte	59
	.byte	56
	.byte	53
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.21:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.20
	.align 4
.2.5_2__kmpc_loc_pack.20:
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
	.byte	53
	.byte	59
	.byte	56
	.byte	57
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.5_2_kmpc_loc_struct_pack.52:
	.long	0
	.long	18
	.long	0
	.long	0
	.quad	.2.5_2__kmpc_loc_pack.51
	.align 4
.2.5_2__kmpc_loc_pack.51:
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
	.byte	53
	.byte	59
	.byte	56
	.byte	53
	.byte	59
	.byte	59
	.section .rodata.str1.4, "aMS",@progbits,1
	.align 4
	.align 4
il0_peep_printf_format_0:
	.long	1667329136
	.long	1869095013
	.long	1919247468
	.long	1853187616
	.long	1869182051
	.word	8302
	.byte	0
	.space 1, 0x00 	# pad
	.align 4
il0_peep_printf_format_1:
	.long	1667329136
	.long	1869095013
	.long	1919247468
	.long	1853187616
	.long	1869182051
	.word	8302
	.byte	0
	.data
# -- End  main, L_main_85__par_loop0_2.0, L_main_85__tree_reduce0_2.1
	.text
# -- Begin  _Z19placeHolderFunctionv
	.text
# mark_begin;
       .align    16,0x90
	.globl _Z19placeHolderFunctionv
_Z19placeHolderFunctionv:
..B2.1:                         # Preds ..B2.0
..___tag_value__Z19placeHolderFunctionv.107:                    #21.27
        movl      $il0_peep_printf_format_2, %edi               #22.3
        jmp       puts                                          #22.3
        .align    16,0x90
..___tag_value__Z19placeHolderFunctionv.109:                    #
                                # LOE
# mark_end;
	.type	_Z19placeHolderFunctionv,@function
	.size	_Z19placeHolderFunctionv,.-_Z19placeHolderFunctionv
	.section .rodata.str1.4, "aMS",@progbits,1
	.space 1, 0x00 	# pad
	.align 4
il0_peep_printf_format_2:
	.long	1667329136
	.long	1869095013
	.long	1919247468
	.long	1853187616
	.long	1869182051
	.word	8302
	.byte	0
	.data
# -- End  _Z19placeHolderFunctionv
	.bss
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
	.data
	.space 3, 0x00 	# pad
	.align 4
	.globl LOOPCOUNT
LOOPCOUNT:
	.long	1000
	.type	LOOPCOUNT,@object
	.size	LOOPCOUNT,4
	.section .rodata.str1.4, "aMS",@progbits,1
	.space 1, 0x00 	# pad
	.align 4
.L_2__STRING.1:
	.long	544567129
	.long	1702257000
	.long	544175136
	.long	543519605
	.long	1701606497
	.long	544502625
	.long	1851858994
	.long	1952522340
	.long	1936682272
	.long	1680154740
	.long	1869770784
	.long	1936942435
	.long	684901
	.type	.L_2__STRING.1,@object
	.size	.L_2__STRING.1,52
	.align 4
.L_2__STRING.2:
	.long	1668248144
	.long	544437093
	.long	1931502629
	.long	1768189541
	.long	1948280686
	.long	1818304623
	.long	1953439852
	.long	544367976
	.long	1668248176
	.long	1702064997
	.word	2675
	.byte	0
	.type	.L_2__STRING.2,@object
	.size	.L_2__STRING.2,43
	.space 1, 0x00 	# pad
	.align 4
.L_2__STRING.3:
	.long	1668248144
	.long	544437093
	.long	1931502629
	.long	1768189541
	.long	1948280686
	.long	1680154735
	.word	10
	.type	.L_2__STRING.3,@object
	.size	.L_2__STRING.3,26
	.space 2, 0x00 	# pad
	.align 4
.L_2__STRING.4:
	.long	1668248144
	.long	544437093
	.long	1914725413
	.long	1768252261
	.long	1735289206
	.long	1869768224
	.long	1818304621
	.long	1953439852
	.long	544367976
	.long	1668248176
	.long	1702064997
	.word	2675
	.byte	0
	.type	.L_2__STRING.4,@object
	.size	.L_2__STRING.4,47
	.space 1, 0x00 	# pad
	.align 4
.L_2__STRING.5:
	.long	1668248144
	.long	544437093
	.long	1914725413
	.long	1768252261
	.long	543450486
	.long	1701650529
	.long	1734439795
	.long	1919295589
	.long	1881173359
	.long	1701015410
	.long	622883699
	.word	2660
	.byte	0
	.type	.L_2__STRING.5,@object
	.size	.L_2__STRING.5,47
	.space 1, 0x00 	# pad
	.align 4
.L_2__STRING.6:
	.long	1668248144
	.long	544437093
	.long	1914725413
	.long	2036621669
	.word	10
	.type	.L_2__STRING.6,@object
	.size	.L_2__STRING.6,18
	.data
	.comm main_kmpc_tree_reduct_lock_0,32,8
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
	.4byte 0x000001ac
	.4byte 0x00000024
	.8byte ..___tag_value_main.1
	.8byte ..___tag_value_main.106-..___tag_value_main.1
	.2byte 0x0400
	.4byte ..___tag_value_main.3-..___tag_value_main.1
	.2byte 0x100e
	.byte 0x04
	.4byte ..___tag_value_main.4-..___tag_value_main.3
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.6-..___tag_value_main.4
	.8byte 0xff800d1c380e0310
	.8byte 0xfffffee80d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xfffee00d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xfed80d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0xd00d1affffff800d
	.8byte 0x380e0f1022fffffe
	.8byte 0x0d1affffff800d1c
	.4byte 0xfffffec8
	.2byte 0x0422
	.4byte ..___tag_value_main.59-..___tag_value_main.6
	.4byte 0xcdccc6c3
	.2byte 0xcfce
	.byte 0x04
	.4byte ..___tag_value_main.66-..___tag_value_main.59
	.4byte 0x0410070c
	.4byte ..___tag_value_main.67-..___tag_value_main.66
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.69-..___tag_value_main.67
	.8byte 0xff800d1c380e0310
	.8byte 0xfffffee80d1affff
	.8byte 0x800d1c380e0c1022
	.8byte 0xfffee00d1affffff
	.8byte 0x0d1c380e0d1022ff
	.8byte 0xfed80d1affffff80
	.8byte 0x1c380e0e1022ffff
	.8byte 0xd00d1affffff800d
	.4byte 0x22fffffe
	.byte 0x04
	.4byte ..___tag_value_main.73-..___tag_value_main.69
	.2byte 0x04ce
	.4byte ..___tag_value_main.74-..___tag_value_main.73
	.2byte 0x04cd
	.4byte ..___tag_value_main.75-..___tag_value_main.74
	.2byte 0x04cc
	.4byte ..___tag_value_main.76-..___tag_value_main.75
	.2byte 0x04c3
	.4byte ..___tag_value_main.77-..___tag_value_main.76
	.4byte 0xc608070c
	.byte 0x04
	.4byte ..___tag_value_main.79-..___tag_value_main.77
	.4byte 0x0410060c
	.4byte ..___tag_value_main.81-..___tag_value_main.79
	.4byte 0x0410070c
	.4byte ..___tag_value_main.82-..___tag_value_main.81
	.4byte 0x8610060c
	.2byte 0x0402
	.4byte ..___tag_value_main.84-..___tag_value_main.82
	.8byte 0xff800d1c380e0310
	.8byte 0xfffffee80d1affff
	.2byte 0x0422
	.4byte ..___tag_value_main.85-..___tag_value_main.84
	.8byte 0xff800d1c380e0c10
	.8byte 0xfffffee00d1affff
	.8byte 0x800d1c380e0d1022
	.8byte 0xfffed80d1affffff
	.8byte 0x0d1c380e0e1022ff
	.8byte 0xfed00d1affffff80
	.8byte 0x1c380e0f1022ffff
	.8byte 0xc80d1affffff800d
	.4byte 0x22fffffe
	.byte 0x04
	.4byte ..___tag_value_main.99-..___tag_value_main.85
	.2byte 0x04cf
	.4byte ..___tag_value_main.100-..___tag_value_main.99
	.2byte 0x04ce
	.4byte ..___tag_value_main.101-..___tag_value_main.100
	.2byte 0x04cd
	.4byte ..___tag_value_main.102-..___tag_value_main.101
	.2byte 0x04cc
	.4byte ..___tag_value_main.103-..___tag_value_main.102
	.2byte 0x04c3
	.4byte ..___tag_value_main.104-..___tag_value_main.103
	.8byte 0x00000000c608070c
	.byte 0x00
	.4byte 0x0000001c
	.4byte 0x000001d4
	.8byte ..___tag_value__Z19placeHolderFunctionv.107
	.8byte ..___tag_value__Z19placeHolderFunctionv.109-..___tag_value__Z19placeHolderFunctionv.107
	.8byte 0x0000000000000000
# End
