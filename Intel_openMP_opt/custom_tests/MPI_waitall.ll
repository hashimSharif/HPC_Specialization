; ModuleID = 'MPI_waitall.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.ompi_predefined_communicator_t = type opaque
%struct.ompi_predefined_datatype_t = type opaque
%ident_t = type { i32, i32, i32, i32, i8* }
%struct.ompi_status_public_t = type { i32, i32, i32, i32, i64 }
%struct.ompi_request_t = type opaque
%struct.ompi_communicator_t = type opaque
%struct.ompi_datatype_t = type opaque

@ompi_mpi_comm_world = external global %struct.ompi_predefined_communicator_t, align 1
@.str = private unnamed_addr constant [52 x i8] c"You have to use at lest 2 and at most %d processes\0A\00", align 1
@.str.1 = private unnamed_addr constant [43 x i8] c"Process %d sending to all other processes\0A\00", align 1
@.str.2 = private unnamed_addr constant [26 x i8] c"Process %d sending to %d\0A\00", align 1
@ompi_mpi_int = external global %struct.ompi_predefined_datatype_t, align 1
@.str.3 = private unnamed_addr constant [47 x i8] c"Process %d receiving from all other processes\0A\00", align 1
@.str.4 = private unnamed_addr constant [47 x i8] c"Process %d received a message from process %d\0A\00", align 1
@.str.5 = private unnamed_addr constant [18 x i8] c"Process %d ready\0A\00", align 1
@LOOPCOUNT = global i32 1000, align 4
@.str.6 = private unnamed_addr constant [23 x i8] c";unknown;unknown;0;0;;\00", align 1
@0 = private unnamed_addr constant %ident_t { i32 0, i32 2, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.6, i32 0, i32 0) }, align 8
@.gomp_critical_user_.reduction.var = common global [8 x i32] zeroinitializer
@1 = private unnamed_addr constant %ident_t { i32 0, i32 18, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.6, i32 0, i32 0) }, align 8

; Function Attrs: nounwind uwtable
define i32 @main(i32 %argc, i8** %argv) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 8
  %i = alloca i32, align 4
  %x = alloca i32, align 4
  %np = alloca i32, align 4
  %me = alloca i32, align 4
  %tag = alloca i32, align 4
  %status = alloca [8 x %struct.ompi_status_public_t], align 16
  %send_req = alloca [8 x %struct.ompi_request_t*], align 16
  %recv_req = alloca [8 x %struct.ompi_request_t*], align 16
  %y = alloca [8 x i32], align 16
  %sum = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 %argc, i32* %2, align 4
  store i8** %argv, i8*** %3, align 8
  store i32 42, i32* %tag, align 4
  %4 = call i32 @MPI_Init(i32* %2, i8*** %3)
  %5 = call i32 @MPI_Comm_size(%struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), i32* %np)
  %6 = call i32 @MPI_Comm_rank(%struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), i32* %me)
  %7 = load i32, i32* %np, align 4
  %8 = icmp slt i32 %7, 2
  br i1 %8, label %12, label %9

; <label>:9                                       ; preds = %0
  %10 = load i32, i32* %np, align 4
  %11 = icmp sgt i32 %10, 8
  br i1 %11, label %12, label %19

; <label>:12                                      ; preds = %9, %0
  %13 = load i32, i32* %me, align 4
  %14 = icmp eq i32 %13, 0
  br i1 %14, label %15, label %17

; <label>:15                                      ; preds = %12
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str, i32 0, i32 0), i32 8)
  br label %17

; <label>:17                                      ; preds = %15, %12
  %18 = call i32 @MPI_Finalize()
  call void @exit(i32 0) #3
  unreachable

; <label>:19                                      ; preds = %9
  %20 = load i32, i32* %me, align 4
  store i32 %20, i32* %x, align 4
  %21 = load i32, i32* %me, align 4
  %22 = icmp eq i32 %21, 0
  br i1 %22, label %23, label %92

; <label>:23                                      ; preds = %19
  %24 = load i32, i32* %me, align 4
  %25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([43 x i8], [43 x i8]* @.str.1, i32 0, i32 0), i32 %24)
  store i32 1, i32* %i, align 4
  br label %26

; <label>:26                                      ; preds = %41, %23
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %np, align 4
  %29 = icmp slt i32 %27, %28
  br i1 %29, label %30, label %44

; <label>:30                                      ; preds = %26
  %31 = load i32, i32* %me, align 4
  %32 = load i32, i32* %i, align 4
  %33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.2, i32 0, i32 0), i32 %31, i32 %32)
  %34 = bitcast i32* %x to i8*
  %35 = load i32, i32* %i, align 4
  %36 = load i32, i32* %tag, align 4
  %37 = load i32, i32* %i, align 4
  %38 = sext i32 %37 to i64
  %39 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %send_req, i64 0, i64 %38
  %40 = call i32 @MPI_Isend(i8* %34, i32 1, %struct.ompi_datatype_t* bitcast (%struct.ompi_predefined_datatype_t* @ompi_mpi_int to %struct.ompi_datatype_t*), i32 %35, i32 %36, %struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), %struct.ompi_request_t** %39)
  br label %41

; <label>:41                                      ; preds = %30
  %42 = load i32, i32* %i, align 4
  %43 = add nsw i32 %42, 1
  store i32 %43, i32* %i, align 4
  br label %26

; <label>:44                                      ; preds = %26
  %45 = load i32, i32* %np, align 4
  %46 = sub nsw i32 %45, 1
  %47 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %send_req, i64 0, i64 1
  %48 = getelementptr inbounds [8 x %struct.ompi_status_public_t], [8 x %struct.ompi_status_public_t]* %status, i64 0, i64 1
  %49 = call i32 @MPI_Waitall(i32 %46, %struct.ompi_request_t** %47, %struct.ompi_status_public_t* %48)
  %50 = load i32, i32* %me, align 4
  %51 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.3, i32 0, i32 0), i32 %50)
  store i32 1, i32* %i, align 4
  br label %52

; <label>:52                                      ; preds = %66, %44
  %53 = load i32, i32* %i, align 4
  %54 = load i32, i32* %np, align 4
  %55 = icmp slt i32 %53, %54
  br i1 %55, label %56, label %69

; <label>:56                                      ; preds = %52
  %57 = load i32, i32* %i, align 4
  %58 = sext i32 %57 to i64
  %59 = getelementptr inbounds [8 x i32], [8 x i32]* %y, i64 0, i64 %58
  %60 = bitcast i32* %59 to i8*
  %61 = load i32, i32* %tag, align 4
  %62 = load i32, i32* %i, align 4
  %63 = sext i32 %62 to i64
  %64 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %recv_req, i64 0, i64 %63
  %65 = call i32 @MPI_Irecv(i8* %60, i32 1, %struct.ompi_datatype_t* bitcast (%struct.ompi_predefined_datatype_t* @ompi_mpi_int to %struct.ompi_datatype_t*), i32 -1, i32 %61, %struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), %struct.ompi_request_t** %64)
  br label %66

; <label>:66                                      ; preds = %56
  %67 = load i32, i32* %i, align 4
  %68 = add nsw i32 %67, 1
  store i32 %68, i32* %i, align 4
  br label %52

; <label>:69                                      ; preds = %52
  %70 = load i32, i32* %np, align 4
  %71 = sub nsw i32 %70, 1
  %72 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %recv_req, i64 0, i64 1
  %73 = getelementptr inbounds [8 x %struct.ompi_status_public_t], [8 x %struct.ompi_status_public_t]* %status, i64 0, i64 1
  store i32 0, i32* %sum, align 4
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call_start(%ident_t* @0, i32 1, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*)* @.omp_outlined. to void (i32*, i32*, ...)*), i32* %sum)
  %74 = call i32 @MPI_Waitall(i32 %71, %struct.ompi_request_t** %72, %struct.ompi_status_public_t* %73)
  store i32 1, i32* %i, align 4
  br label %75

; <label>:75                                      ; preds = %86, %69
  %76 = load i32, i32* %i, align 4
  %77 = load i32, i32* %np, align 4
  %78 = icmp slt i32 %76, %77
  br i1 %78, label %79, label %89

; <label>:79                                      ; preds = %75
  %80 = load i32, i32* %me, align 4
  %81 = load i32, i32* %i, align 4
  %82 = sext i32 %81 to i64
  %83 = getelementptr inbounds [8 x i32], [8 x i32]* %y, i64 0, i64 %82
  %84 = load i32, i32* %83, align 4
  %85 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.4, i32 0, i32 0), i32 %80, i32 %84)
  br label %86

; <label>:86                                      ; preds = %79
  %87 = load i32, i32* %i, align 4
  %88 = add nsw i32 %87, 1
  store i32 %88, i32* %i, align 4
  br label %75

; <label>:89                                      ; preds = %75
  %90 = load i32, i32* %me, align 4
  %91 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.5, i32 0, i32 0), i32 %90)
  store i32 0, i32* %sum, align 4
  call void @__kmpc_fork_call_end()
  br label %107

; <label>:92                                      ; preds = %19
  %93 = bitcast [8 x i32]* %y to i8*
  %94 = load i32, i32* %tag, align 4
  %95 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %recv_req, i64 0, i64 0
  %96 = call i32 @MPI_Irecv(i8* %93, i32 1, %struct.ompi_datatype_t* bitcast (%struct.ompi_predefined_datatype_t* @ompi_mpi_int to %struct.ompi_datatype_t*), i32 0, i32 %94, %struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), %struct.ompi_request_t** %95)
  %97 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %recv_req, i64 0, i64 0
  %98 = getelementptr inbounds [8 x %struct.ompi_status_public_t], [8 x %struct.ompi_status_public_t]* %status, i64 0, i64 0
  %99 = call i32 @MPI_Wait(%struct.ompi_request_t** %97, %struct.ompi_status_public_t* %98)
  %100 = bitcast i32* %x to i8*
  %101 = load i32, i32* %tag, align 4
  %102 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %send_req, i64 0, i64 0
  %103 = call i32 @MPI_Isend(i8* %100, i32 1, %struct.ompi_datatype_t* bitcast (%struct.ompi_predefined_datatype_t* @ompi_mpi_int to %struct.ompi_datatype_t*), i32 0, i32 %101, %struct.ompi_communicator_t* bitcast (%struct.ompi_predefined_communicator_t* @ompi_mpi_comm_world to %struct.ompi_communicator_t*), %struct.ompi_request_t** %102)
  %104 = getelementptr inbounds [8 x %struct.ompi_request_t*], [8 x %struct.ompi_request_t*]* %send_req, i64 0, i64 0
  %105 = getelementptr inbounds [8 x %struct.ompi_status_public_t], [8 x %struct.ompi_status_public_t]* %status, i64 0, i64 0
  %106 = call i32 @MPI_Wait(%struct.ompi_request_t** %104, %struct.ompi_status_public_t* %105)
  br label %107

; <label>:107                                     ; preds = %92, %89
  %108 = call i32 @MPI_Finalize()
  call void @exit(i32 0) #3
  unreachable
                                                  ; No predecessors!
  %110 = load i32, i32* %1, align 4
  ret i32 %110
}

declare i32 @MPI_Init(i32*, i8***) #1

declare i32 @MPI_Comm_size(%struct.ompi_communicator_t*, i32*) #1

declare i32 @MPI_Comm_rank(%struct.ompi_communicator_t*, i32*) #1

declare i32 @printf(i8*, ...) #1

declare i32 @MPI_Finalize() #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #2

declare i32 @MPI_Isend(i8*, i32, %struct.ompi_datatype_t*, i32, i32, %struct.ompi_communicator_t*, %struct.ompi_request_t**) #1

declare i32 @MPI_Waitall(i32, %struct.ompi_request_t**, %struct.ompi_status_public_t*) #1

declare i32 @MPI_Irecv(i8*, i32, %struct.ompi_datatype_t*, i32, i32, %struct.ompi_communicator_t*, %struct.ompi_request_t**) #1

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined.(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %sum) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %i = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %i1 = alloca i32, align 4
  %sum2 = alloca i32, align 4
  %i3 = alloca i32, align 4
  %4 = alloca [1 x i8*], align 8
  store i32* %.global_tid., i32** %1, align 8
  store i32* %.bound_tid., i32** %2, align 8
  store i32* %sum, i32** %3, align 8
  %5 = load i32*, i32** %3, align 8
  %6 = load i32, i32* @LOOPCOUNT, align 4
  %7 = sub nsw i32 %6, 1
  %8 = add nsw i32 %7, 1
  %9 = sdiv i32 %8, 1
  %10 = sub nsw i32 %9, 1
  store i32 %10, i32* %.omp.last.iteration, align 4
  store i32 1, i32* %i, align 4
  %11 = load i32, i32* @LOOPCOUNT, align 4
  %12 = icmp sle i32 1, %11
  br i1 %12, label %13, label %72

; <label>:13                                      ; preds = %0
  store i32 0, i32* %.omp.lb, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %14, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store i32 0, i32* %sum2, align 4
  %15 = load i32*, i32** %1, align 8
  %16 = load i32, i32* %15, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %16, i32 33, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  br label %17

; <label>:17                                      ; preds = %48, %13
  %18 = load i32, i32* %.omp.ub, align 4
  %19 = load i32, i32* %.omp.last.iteration, align 4
  %20 = icmp sgt i32 %18, %19
  br i1 %20, label %21, label %23

; <label>:21                                      ; preds = %17
  %22 = load i32, i32* %.omp.last.iteration, align 4
  br label %25

; <label>:23                                      ; preds = %17
  %24 = load i32, i32* %.omp.ub, align 4
  br label %25

; <label>:25                                      ; preds = %23, %21
  %26 = phi i32 [ %22, %21 ], [ %24, %23 ]
  store i32 %26, i32* %.omp.ub, align 4
  %27 = load i32, i32* %.omp.lb, align 4
  store i32 %27, i32* %.omp.iv, align 4
  %28 = load i32, i32* %.omp.iv, align 4
  %29 = load i32, i32* %.omp.ub, align 4
  %30 = icmp sle i32 %28, %29
  br i1 %30, label %31, label %55

; <label>:31                                      ; preds = %25
  br label %32

; <label>:32                                      ; preds = %44, %31
  %33 = load i32, i32* %.omp.iv, align 4
  %34 = load i32, i32* %.omp.ub, align 4
  %35 = icmp sle i32 %33, %34
  br i1 %35, label %36, label %47

; <label>:36                                      ; preds = %32
  %37 = load i32, i32* %.omp.iv, align 4
  %38 = mul nsw i32 %37, 1
  %39 = add nsw i32 1, %38
  store i32 %39, i32* %i1, align 4
  %40 = load i32, i32* %sum2, align 4
  %41 = load i32, i32* %i1, align 4
  %42 = add nsw i32 %40, %41
  store i32 %42, i32* %sum2, align 4
  br label %43

; <label>:43                                      ; preds = %36
  br label %44

; <label>:44                                      ; preds = %43
  %45 = load i32, i32* %.omp.iv, align 4
  %46 = add nsw i32 %45, 1
  store i32 %46, i32* %.omp.iv, align 4
  br label %32

; <label>:47                                      ; preds = %32
  br label %48

; <label>:48                                      ; preds = %47
  %49 = load i32, i32* %.omp.lb, align 4
  %50 = load i32, i32* %.omp.stride, align 4
  %51 = add nsw i32 %49, %50
  store i32 %51, i32* %.omp.lb, align 4
  %52 = load i32, i32* %.omp.ub, align 4
  %53 = load i32, i32* %.omp.stride, align 4
  %54 = add nsw i32 %52, %53
  store i32 %54, i32* %.omp.ub, align 4
  br label %17

; <label>:55                                      ; preds = %25
  %56 = load i32*, i32** %1, align 8
  %57 = load i32, i32* %56, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %57)
  %58 = getelementptr inbounds [1 x i8*], [1 x i8*]* %4, i64 0, i64 0
  %59 = bitcast i32* %sum2 to i8*
  store i8* %59, i8** %58, align 8
  %60 = load i32*, i32** %1, align 8
  %61 = load i32, i32* %60, align 4
  %62 = bitcast [1 x i8*]* %4 to i8*
  %63 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %61, i32 1, i64 8, i8* %62, void (i8*, i8*)* @.omp.reduction.reduction_func, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %63, label %71 [
    i32 1, label %64
    i32 2, label %68
  ]

; <label>:64                                      ; preds = %55
  %65 = load i32, i32* %5, align 4
  %66 = load i32, i32* %sum2, align 4
  %67 = add nsw i32 %65, %66
  store i32 %67, i32* %5, align 4
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %61, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %71

; <label>:68                                      ; preds = %55
  %69 = load i32, i32* %sum2, align 4
  %70 = atomicrmw add i32* %5, i32 %69 monotonic
  br label %71

; <label>:71                                      ; preds = %68, %64, %55
  br label %72

; <label>:72                                      ; preds = %71, %0
  ret void
}

declare void @__kmpc_for_static_init_4(%ident_t*, i32, i32, i32*, i32*, i32*, i32*, i32, i32)

declare void @__kmpc_for_static_fini(%ident_t*, i32)

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func(i8*, i8*) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  store i8* %1, i8** %4, align 8
  %5 = load i8*, i8** %3, align 8
  %6 = bitcast i8* %5 to [1 x i8*]*
  %7 = load i8*, i8** %4, align 8
  %8 = bitcast i8* %7 to [1 x i8*]*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %8, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to i32*
  %12 = getelementptr inbounds [1 x i8*], [1 x i8*]* %6, i64 0, i64 0
  %13 = load i8*, i8** %12, align 8
  %14 = bitcast i8* %13 to i32*
  %15 = load i32, i32* %14, align 4
  %16 = load i32, i32* %11, align 4
  %17 = add nsw i32 %15, %16
  store i32 %17, i32* %14, align 4
  ret void
}

declare i32 @__kmpc_reduce_nowait(%ident_t*, i32, i32, i64, i8*, void (i8*, i8*)*, [8 x i32]*)

declare void @__kmpc_end_reduce_nowait(%ident_t*, i32, [8 x i32]*)

declare void @__kmpc_fork_call_start(%ident_t*, i32, void (i32*, i32*, ...)*, ...)

declare void @__kmpc_fork_call_end()

declare i32 @MPI_Wait(%struct.ompi_request_t**, %struct.ompi_status_public_t*) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-svn262614-1~exp1 (branches/release_38)"}
