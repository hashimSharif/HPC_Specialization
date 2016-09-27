; ModuleID = 'custom_tests/bc/MPI_waitall.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%ident_t = type { i32, i32, i32, i32, i8* }
%struct.MPI_Status = type { i32, i32, i32, i32, i32 }

@.str = private unnamed_addr constant [22 x i8] c"placeHolder func %d \0A\00", align 1
@.str.1 = private unnamed_addr constant [52 x i8] c"You have to use at lest 2 and at most %d processes\0A\00", align 1
@.str.2 = private unnamed_addr constant [43 x i8] c"Process %d sending to all other processes\0A\00", align 1
@.str.3 = private unnamed_addr constant [26 x i8] c"Process %d sending to %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [47 x i8] c"Process %d receiving from all other processes\0A\00", align 1
@.str.5 = private unnamed_addr constant [47 x i8] c"Process %d received a message from process %d\0A\00", align 1
@.str.6 = private unnamed_addr constant [18 x i8] c"Process %d ready\0A\00", align 1
@LOOPCOUNT = global i32 1000, align 4
@.str.7 = private unnamed_addr constant [23 x i8] c";unknown;unknown;0;0;;\00", align 1
@0 = private unnamed_addr constant %ident_t { i32 0, i32 2, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.7, i32 0, i32 0) }, align 8
@.gomp_critical_user_.reduction.var = common global [8 x i32] zeroinitializer
@1 = private unnamed_addr constant %ident_t { i32 0, i32 18, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.7, i32 0, i32 0) }, align 8

; Function Attrs: noinline nounwind uwtable
define void @placeHolder() #0 {
entry:
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @.str, i32 0, i32 0), i32 10)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind uwtable
define i32 @main(i32 %argc, i8** %argv) #2 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %i = alloca i32, align 4
  %x = alloca i32, align 4
  %np = alloca i32, align 4
  %me = alloca i32, align 4
  %tag = alloca i32, align 4
  %status = alloca [8 x %struct.MPI_Status], align 16
  %send_req = alloca [8 x i32], align 16
  %recv_req = alloca [8 x i32], align 16
  %y = alloca [8 x i32], align 16
  %buffer = alloca [100000 x i32], align 16
  %sum = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  store i32 42, i32* %tag, align 4
  %call = call i32 @MPI_Init(i32* %argc.addr, i8*** %argv.addr)
  %call1 = call i32 @MPI_Comm_size(i32 1140850688, i32* %np)
  %call2 = call i32 @MPI_Comm_rank(i32 1140850688, i32* %me)
  %0 = load i32, i32* %np, align 4
  %cmp = icmp slt i32 %0, 2
  br i1 %cmp, label %if.then, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %entry
  %1 = load i32, i32* %np, align 4
  %cmp3 = icmp sgt i32 %1, 8
  br i1 %cmp3, label %if.then, label %if.end8

if.then:                                          ; preds = %lor.lhs.false, %entry
  %2 = load i32, i32* %me, align 4
  %cmp4 = icmp eq i32 %2, 0
  br i1 %cmp4, label %if.then5, label %if.end

if.then5:                                         ; preds = %if.then
  %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 8)
  br label %if.end

if.end:                                           ; preds = %if.then5, %if.then
  %call7 = call i32 @MPI_Finalize()
  call void @exit(i32 0) #4
  unreachable

if.end8:                                          ; preds = %lor.lhs.false
  %3 = load i32, i32* %me, align 4
  store i32 %3, i32* %x, align 4
  %4 = load i32, i32* %me, align 4
  %cmp9 = icmp eq i32 %4, 0
  br i1 %cmp9, label %if.then10, label %if.else

if.then10:                                        ; preds = %if.end8
  %5 = load i32, i32* %me, align 4
  %call11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([43 x i8], [43 x i8]* @.str.2, i32 0, i32 0), i32 %5)
  store i32 1, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.then10
  %6 = load i32, i32* %i, align 4
  %7 = load i32, i32* %np, align 4
  %cmp12 = icmp slt i32 %6, %7
  br i1 %cmp12, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %8 = load i32, i32* %me, align 4
  %9 = load i32, i32* %i, align 4
  %call13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.3, i32 0, i32 0), i32 %8, i32 %9)
  %10 = bitcast [8 x i32]* %y to i8*
  %11 = load i32, i32* %i, align 4
  %12 = load i32, i32* %tag, align 4
  %13 = load i32, i32* %i, align 4
  %idxprom = sext i32 %13 to i64
  %arrayidx = getelementptr inbounds [8 x i32], [8 x i32]* %send_req, i64 0, i64 %idxprom
  %call14 = call i32 @MPI_Isend(i8* %10, i32 1, i32 1275069445, i32 %11, i32 %12, i32 1140850688, i32* %arrayidx)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %14 = load i32, i32* %i, align 4
  %inc = add nsw i32 %14, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %15 = load i32, i32* %np, align 4
  %sub = sub nsw i32 %15, 1
  %arrayidx15 = getelementptr inbounds [8 x i32], [8 x i32]* %send_req, i64 0, i64 1
  %arrayidx16 = getelementptr inbounds [8 x %struct.MPI_Status], [8 x %struct.MPI_Status]* %status, i64 0, i64 1
  %call17 = call i32 @MPI_Waitall(i32 %sub, i32* %arrayidx15, %struct.MPI_Status* %arrayidx16)
  %16 = load i32, i32* %me, align 4
  %call18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.4, i32 0, i32 0), i32 %16)
  store i32 1, i32* %i, align 4
  br label %for.cond19

for.cond19:                                       ; preds = %for.inc25, %for.end
  %17 = load i32, i32* %i, align 4
  %18 = load i32, i32* %np, align 4
  %cmp20 = icmp slt i32 %17, %18
  br i1 %cmp20, label %for.body21, label %for.end27

for.body21:                                       ; preds = %for.cond19
  %19 = bitcast [100000 x i32]* %buffer to i8*
  %20 = load i32, i32* %tag, align 4
  %21 = load i32, i32* %i, align 4
  %idxprom22 = sext i32 %21 to i64
  %arrayidx23 = getelementptr inbounds [8 x i32], [8 x i32]* %recv_req, i64 0, i64 %idxprom22
  %call24 = call i32 @MPI_Irecv(i8* %19, i32 100000, i32 1275069445, i32 -2, i32 %20, i32 1140850688, i32* %arrayidx23)
  br label %for.inc25

for.inc25:                                        ; preds = %for.body21
  %22 = load i32, i32* %i, align 4
  %inc26 = add nsw i32 %22, 1
  store i32 %inc26, i32* %i, align 4
  br label %for.cond19

for.end27:                                        ; preds = %for.cond19
  
  store i32 0, i32* %sum, align 4
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call_start(%ident_t* @0, i32 1, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*)* @.omp_outlined. to void (i32*, i32*, ...)*), i32* %sum)

  call void @placeHolder()
  %23 = load i32, i32* %np, align 4
  %sub28 = sub nsw i32 %23, 1
  %arrayidx29 = getelementptr inbounds [8 x i32], [8 x i32]* %recv_req, i64 0, i64 1
  %arrayidx30 = getelementptr inbounds [8 x %struct.MPI_Status], [8 x %struct.MPI_Status]* %status, i64 0, i64 1
  %call31 = call i32 @MPI_Waitall(i32 %sub28, i32* %arrayidx29, %struct.MPI_Status* %arrayidx30)
  store i32 1, i32* %i, align 4
  br label %for.cond32

for.cond32:                                       ; preds = %for.inc38, %for.end27
  %24 = load i32, i32* %i, align 4
  %25 = load i32, i32* %np, align 4
  %cmp33 = icmp slt i32 %24, %25
  br i1 %cmp33, label %for.body34, label %for.end40

for.body34:                                       ; preds = %for.cond32
  %26 = load i32, i32* %me, align 4
  %27 = load i32, i32* %i, align 4
  %idxprom35 = sext i32 %27 to i64
  %arrayidx36 = getelementptr inbounds [8 x i32], [8 x i32]* %y, i64 0, i64 %idxprom35
  %28 = load i32, i32* %arrayidx36, align 4
  %call37 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.5, i32 0, i32 0), i32 %26, i32 %28)
  br label %for.inc38

for.inc38:                                        ; preds = %for.body34
  %29 = load i32, i32* %i, align 4
  %inc39 = add nsw i32 %29, 1
  store i32 %inc39, i32* %i, align 4
  br label %for.cond32

for.end40:                                        ; preds = %for.cond32
  %30 = load i32, i32* %me, align 4
  %call41 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.6, i32 0, i32 0), i32 %30)
  call void @placeHolder()

  call void () @__kmpc_fork_call_end()
  br label %if.end52

if.else:                                          ; preds = %if.end8
  %31 = bitcast [8 x i32]* %y to i8*
  %32 = load i32, i32* %tag, align 4
  %arrayidx42 = getelementptr inbounds [8 x i32], [8 x i32]* %recv_req, i64 0, i64 0
  %call43 = call i32 @MPI_Irecv(i8* %31, i32 1, i32 1275069445, i32 0, i32 %32, i32 1140850688, i32* %arrayidx42)
  %arrayidx44 = getelementptr inbounds [8 x i32], [8 x i32]* %recv_req, i64 0, i64 0
  %arrayidx45 = getelementptr inbounds [8 x %struct.MPI_Status], [8 x %struct.MPI_Status]* %status, i64 0, i64 0
  %call46 = call i32 @MPI_Wait(i32* %arrayidx44, %struct.MPI_Status* %arrayidx45)
  %33 = bitcast [100000 x i32]* %buffer to i8*
  %34 = load i32, i32* %tag, align 4
  %arrayidx47 = getelementptr inbounds [8 x i32], [8 x i32]* %send_req, i64 0, i64 0
  %call48 = call i32 @MPI_Isend(i8* %33, i32 100000, i32 1275069445, i32 0, i32 %34, i32 1140850688, i32* %arrayidx47)
  %arrayidx49 = getelementptr inbounds [8 x i32], [8 x i32]* %send_req, i64 0, i64 0
  %arrayidx50 = getelementptr inbounds [8 x %struct.MPI_Status], [8 x %struct.MPI_Status]* %status, i64 0, i64 0
  %call51 = call i32 @MPI_Wait(i32* %arrayidx49, %struct.MPI_Status* %arrayidx50)
  br label %if.end52

if.end52:                                         ; preds = %if.else, %for.end40
  %call53 = call i32 @MPI_Finalize()
  call void @exit(i32 0) #4
  unreachable

return:                                           ; No predecessors!
  %35 = load i32, i32* %retval, align 4
  ret i32 %35
}

declare i32 @MPI_Init(i32*, i8***) #1

declare i32 @MPI_Comm_size(i32, i32*) #1

declare i32 @MPI_Comm_rank(i32, i32*) #1

declare i32 @MPI_Finalize() #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #3

declare i32 @MPI_Isend(i8*, i32, i32, i32, i32, i32, i32*) #1

declare i32 @MPI_Waitall(i32, i32*, %struct.MPI_Status*) #1

declare i32 @MPI_Irecv(i8*, i32, i32, i32, i32, i32, i32*) #1

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined.(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %sum) #2 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %sum.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %i = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %i2 = alloca i32, align 4
  %sum3 = alloca i32, align 4
  %i4 = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %sum, i32** %sum.addr, align 8
  %0 = load i32*, i32** %sum.addr, align 8
  %1 = load i32, i32* @LOOPCOUNT, align 4
  %sub = sub nsw i32 %1, 1
  %add = add nsw i32 %sub, 1
  %div = sdiv i32 %add, 1
  %sub1 = sub nsw i32 %div, 1
  store i32 %sub1, i32* %.omp.last.iteration, align 4
  store i32 1, i32* %i, align 4
  %2 = load i32, i32* @LOOPCOUNT, align 4
  %cmp = icmp sle i32 1, %2
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %3 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %3, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store i32 0, i32* %sum3, align 4
  %4 = load i32*, i32** %.global_tid..addr, align 8
  %5 = load i32, i32* %4, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %5, i32 33, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  br label %omp.dispatch.cond

omp.dispatch.cond:                                ; preds = %omp.dispatch.inc, %omp.precond.then
  %6 = load i32, i32* %.omp.ub, align 4
  %7 = load i32, i32* %.omp.last.iteration, align 4
  %cmp5 = icmp sgt i32 %6, %7
  br i1 %cmp5, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.dispatch.cond
  %8 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.dispatch.cond
  %9 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %8, %cond.true ], [ %9, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %10 = load i32, i32* %.omp.lb, align 4
  store i32 %10, i32* %.omp.iv, align 4
  %11 = load i32, i32* %.omp.iv, align 4
  %12 = load i32, i32* %.omp.ub, align 4
  %cmp6 = icmp sle i32 %11, %12
  br i1 %cmp6, label %omp.dispatch.body, label %omp.dispatch.end

omp.dispatch.body:                                ; preds = %cond.end
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %omp.dispatch.body
  %13 = load i32, i32* %.omp.iv, align 4
  %14 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %13, %14
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %15 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %15, 1
  %add8 = add nsw i32 1, %mul
  store i32 %add8, i32* %i2, align 4
  %16 = load i32, i32* %sum3, align 4
  %17 = load i32, i32* %i2, align 4
  %add9 = add nsw i32 %16, %17
  store i32 %add9, i32* %sum3, align 4
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp.inner.for.body
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %18 = load i32, i32* %.omp.iv, align 4
  %add10 = add nsw i32 %18, 1
  store i32 %add10, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.dispatch.inc

omp.dispatch.inc:                                 ; preds = %omp.inner.for.end
  %19 = load i32, i32* %.omp.lb, align 4
  %20 = load i32, i32* %.omp.stride, align 4
  %add11 = add nsw i32 %19, %20
  store i32 %add11, i32* %.omp.lb, align 4
  %21 = load i32, i32* %.omp.ub, align 4
  %22 = load i32, i32* %.omp.stride, align 4
  %add12 = add nsw i32 %21, %22
  store i32 %add12, i32* %.omp.ub, align 4
  br label %omp.dispatch.cond

omp.dispatch.end:                                 ; preds = %cond.end
  %23 = load i32*, i32** %.global_tid..addr, align 8
  %24 = load i32, i32* %23, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %24)
  %25 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %26 = bitcast i32* %sum3 to i8*
  store i8* %26, i8** %25, align 8
  %27 = load i32*, i32** %.global_tid..addr, align 8
  %28 = load i32, i32* %27, align 4
  %29 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %30 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %28, i32 1, i64 8, i8* %29, void (i8*, i8*)* @.omp.reduction.reduction_func, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %30, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.dispatch.end
  %31 = load i32, i32* %0, align 4
  %32 = load i32, i32* %sum3, align 4
  %add13 = add nsw i32 %31, %32
  store i32 %add13, i32* %0, align 4
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %28, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.dispatch.end
  %33 = load i32, i32* %sum3, align 4
  %34 = atomicrmw add i32* %0, i32 %33 monotonic
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %.omp.reduction.case2, %.omp.reduction.case1, %omp.dispatch.end
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %entry
  ret void
}

declare void @__kmpc_for_static_init_4(%ident_t*, i32, i32, i32*, i32*, i32*, i32*, i32, i32)

declare void @__kmpc_for_static_fini(%ident_t*, i32)

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func(i8*, i8*) #2 {
entry:
  %.addr = alloca i8*, align 8
  %.addr1 = alloca i8*, align 8
  store i8* %0, i8** %.addr, align 8
  store i8* %1, i8** %.addr1, align 8
  %2 = load i8*, i8** %.addr, align 8
  %3 = bitcast i8* %2 to [1 x i8*]*
  %4 = load i8*, i8** %.addr1, align 8
  %5 = bitcast i8* %4 to [1 x i8*]*
  %6 = getelementptr inbounds [1 x i8*], [1 x i8*]* %5, i64 0, i64 0
  %7 = load i8*, i8** %6, align 8
  %8 = bitcast i8* %7 to i32*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to i32*
  %12 = load i32, i32* %11, align 4
  %13 = load i32, i32* %8, align 4
  %add = add nsw i32 %12, %13
  store i32 %add, i32* %11, align 4
  ret void
}

declare i32 @__kmpc_reduce_nowait(%ident_t*, i32, i32, i64, i8*, void (i8*, i8*)*, [8 x i32]*)

declare void @__kmpc_end_reduce_nowait(%ident_t*, i32, [8 x i32]*)

declare void @__kmpc_fork_call_start(%ident_t*, i32, void (i32*, i32*, ...)*, ...)

declare void @__kmpc_fork_call_end()

declare i32 @MPI_Wait(i32*, %struct.MPI_Status*) #1

attributes #0 = { noinline nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_380/final)"}
