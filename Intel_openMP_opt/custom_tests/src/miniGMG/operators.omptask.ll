; ModuleID = 'operators.omptask.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%ident_t = type { i32, i32, i32, i32, i8* }
%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.domain_type = type { %struct.anon, i32, i32, i32, i32, [27 x i32], [10 x %struct.bufferCopy_type*], i32, i32, i32, i32, i32, i32, %struct.anon.2, %struct.anon.3, %struct.anon.4, %struct.anon.5, %struct.anon.6, i32, i32, i32, i32, i32, [10 x double], [10 x double], %struct.subdomain_type* }
%struct.anon = type { [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], [10 x i64], i64, i64, i64 }
%struct.bufferCopy_type = type { i32, i32, i32, %struct.anon.0, %struct.anon.1, %struct.anon.1 }
%struct.anon.0 = type { i32, i32, i32 }
%struct.anon.1 = type { i32, i32, i32, i32, i32, i32, double* }
%struct.anon.2 = type { i32, i32, i32 }
%struct.anon.3 = type { i32, i32, i32 }
%struct.anon.4 = type { i32, i32, i32 }
%struct.anon.5 = type { i32, i32, i32 }
%struct.anon.6 = type { i32, i32, i32 }
%struct.subdomain_type = type { %struct.anon.7, %struct.anon.8, i32, i32, [27 x %struct.neighbor_type], %struct.box_type* }
%struct.anon.7 = type { i32, i32, i32 }
%struct.anon.8 = type { i32, i32, i32 }
%struct.neighbor_type = type { i32, i32 }
%struct.box_type = type { double, %struct.anon.9, %struct.anon.10, %struct.anon.11, i32, i32, i32, i32, i32, [27 x i32], double**, i64*, [2 x double*], i8* }
%struct.anon.9 = type { i32, i32, i32 }
%struct.anon.10 = type { i32, i32, i32 }
%struct.anon.11 = type { i32, i32, i32 }
%struct.anon.12 = type { i32*, %struct.box_type**, i32*, i32*, i32*, i32*, i32*, double*, double**, double**, double*, double*, double**, double**, double**, double**, double**, double** }
%struct.kmp_task_t_with_privates = type { %struct.kmp_task_t, %struct..kmp_privates.t }
%struct.kmp_task_t = type { i8*, i32 (i32, i8*)*, i32, i32 (i32, i8*)* }
%struct..kmp_privates.t = type { %struct.box_type*, double, double*, double*, double, double, double*, double*, double*, double*, double*, double*, i32, i32, i32, i32, i32, i32 }

@.str = private unnamed_addr constant [15 x i8] c"PlaceHolder \0A\0A\00", align 1
@exchange_boundary.edges = private unnamed_addr constant [27 x i32] [i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 0, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0], align 16
@exchange_boundary.corners = private unnamed_addr constant [27 x i32] [i32 1, i32 0, i32 1, i32 0, i32 0, i32 0, i32 1, i32 0, i32 1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1, i32 0, i32 1, i32 0, i32 0, i32 0, i32 1, i32 0, i32 1], align 16
@.str.1 = private unnamed_addr constant [23 x i8] c";unknown;unknown;0;0;;\00", align 1
@0 = private unnamed_addr constant %ident_t { i32 0, i32 2, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.1, i32 0, i32 0) }, align 8
@.gomp_critical_user_.reduction.var = common global [8 x i32] zeroinitializer
@1 = private unnamed_addr constant %ident_t { i32 0, i32 18, i32 0, i32 0, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.1, i32 0, i32 0) }, align 8
@.str.5 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@.str.6 = private unnamed_addr constant [35 x i8] c"  level=%2d, eigenvalue_max ~= %e\0A\00", align 1
@stdout = external global %struct._IO_FILE*, align 8
@.str.55 = private unnamed_addr constant [33 x i8] c"\0A  average value of f = %20.12e\0A\00", align 1

; Function Attrs: nounwind uwtable
define void @placeHolder() #0 {
entry:
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind uwtable
define void @exchange_boundary(%struct.domain_type* %domain, i32 %level, i32 %grid_id, i32 %exchange_faces, i32 %exchange_edges, i32 %exchange_corners) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %grid_id.addr = alloca i32, align 4
  %exchange_faces.addr = alloca i32, align 4
  %exchange_edges.addr = alloca i32, align 4
  %exchange_corners.addr = alloca i32, align 4
  %_timeCommunicationStart = alloca i64, align 8
  %_timeStart = alloca i64, align 8
  %_timeEnd = alloca i64, align 8
  %buffer = alloca i32, align 4
  %sendBox = alloca i32, align 4
  %recvBox = alloca i32, align 4
  %n = alloca i32, align 4
  %faces = alloca [27 x i32], align 16
  %edges = alloca [27 x i32], align 16
  %corners = alloca [27 x i32], align 16
  %exchange = alloca [27 x i32], align 16
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %grid_id, i32* %grid_id.addr, align 4
  store i32 %exchange_faces, i32* %exchange_faces.addr, align 4
  store i32 %exchange_edges, i32* %exchange_edges.addr, align 4
  store i32 %exchange_corners, i32* %exchange_corners.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeCommunicationStart, align 8
  store i32 0, i32* %buffer, align 4
  %0 = bitcast [27 x i32]* %faces to i8*
  call void @llvm.memset.p0i8.i64(i8* %0, i8 0, i64 108, i32 16, i1 false)
  %1 = bitcast i8* %0 to [27 x i32]*
  %2 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 4
  store i32 1, i32* %2
  %3 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 10
  store i32 1, i32* %3
  %4 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 12
  store i32 1, i32* %4
  %5 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 14
  store i32 1, i32* %5
  %6 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 16
  store i32 1, i32* %6
  %7 = getelementptr [27 x i32], [27 x i32]* %1, i32 0, i32 22
  store i32 1, i32* %7
  %8 = bitcast [27 x i32]* %edges to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* bitcast ([27 x i32]* @exchange_boundary.edges to i8*), i64 108, i32 16, i1 false)
  %9 = bitcast [27 x i32]* %corners to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %9, i8* bitcast ([27 x i32]* @exchange_boundary.corners to i8*), i64 108, i32 16, i1 false)
  %10 = bitcast [27 x i32]* %exchange to i8*
  call void @llvm.memset.p0i8.i64(i8* %10, i8 0, i64 108, i32 16, i1 false)
  store i32 0, i32* %n, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %11 = load i32, i32* %n, align 4
  %cmp = icmp slt i32 %11, 27
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %12 = load i32, i32* %exchange_faces.addr, align 4
  %tobool = icmp ne i32 %12, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %13 = load i32, i32* %n, align 4
  %idxprom = sext i32 %13 to i64
  %arrayidx = getelementptr inbounds [27 x i32], [27 x i32]* %faces, i64 0, i64 %idxprom
  %14 = load i32, i32* %arrayidx, align 4
  %15 = load i32, i32* %n, align 4
  %idxprom1 = sext i32 %15 to i64
  %arrayidx2 = getelementptr inbounds [27 x i32], [27 x i32]* %exchange, i64 0, i64 %idxprom1
  %16 = load i32, i32* %arrayidx2, align 4
  %or = or i32 %16, %14
  store i32 %or, i32* %arrayidx2, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  %17 = load i32, i32* %exchange_edges.addr, align 4
  %tobool3 = icmp ne i32 %17, 0
  br i1 %tobool3, label %if.then4, label %if.end10

if.then4:                                         ; preds = %if.end
  %18 = load i32, i32* %n, align 4
  %idxprom5 = sext i32 %18 to i64
  %arrayidx6 = getelementptr inbounds [27 x i32], [27 x i32]* %edges, i64 0, i64 %idxprom5
  %19 = load i32, i32* %arrayidx6, align 4
  %20 = load i32, i32* %n, align 4
  %idxprom7 = sext i32 %20 to i64
  %arrayidx8 = getelementptr inbounds [27 x i32], [27 x i32]* %exchange, i64 0, i64 %idxprom7
  %21 = load i32, i32* %arrayidx8, align 4
  %or9 = or i32 %21, %19
  store i32 %or9, i32* %arrayidx8, align 4
  br label %if.end10

if.end10:                                         ; preds = %if.then4, %if.end
  %22 = load i32, i32* %exchange_corners.addr, align 4
  %tobool11 = icmp ne i32 %22, 0
  br i1 %tobool11, label %if.then12, label %if.end18

if.then12:                                        ; preds = %if.end10
  %23 = load i32, i32* %n, align 4
  %idxprom13 = sext i32 %23 to i64
  %arrayidx14 = getelementptr inbounds [27 x i32], [27 x i32]* %corners, i64 0, i64 %idxprom13
  %24 = load i32, i32* %arrayidx14, align 4
  %25 = load i32, i32* %n, align 4
  %idxprom15 = sext i32 %25 to i64
  %arrayidx16 = getelementptr inbounds [27 x i32], [27 x i32]* %exchange, i64 0, i64 %idxprom15
  %26 = load i32, i32* %arrayidx16, align 4
  %or17 = or i32 %26, %24
  store i32 %or17, i32* %arrayidx16, align 4
  br label %if.end18

if.end18:                                         ; preds = %if.then12, %if.end10
  br label %for.inc

for.inc:                                          ; preds = %if.end18
  %27 = load i32, i32* %n, align 4
  %inc = add nsw i32 %27, 1
  store i32 %inc, i32* %n, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %call19 = call i64 (...) @CycleTime()
  store i64 %call19, i64* %_timeStart, align 8
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*)* @.omp_outlined. to void (i32*, i32*, ...)*), i32* %buffer, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %exchange_faces.addr, i32* %exchange_edges.addr, i32* %exchange_corners.addr, i32* %grid_id.addr)
  %call20 = call i64 (...) @CycleTime()
  store i64 %call20, i64* %_timeEnd, align 8
  %28 = load i64, i64* %_timeEnd, align 8
  %29 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %28, %29
  %30 = load i32, i32* %level.addr, align 4
  %idxprom21 = sext i32 %30 to i64
  %31 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 0
  %grid2grid = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 7
  %arrayidx22 = getelementptr inbounds [10 x i64], [10 x i64]* %grid2grid, i64 0, i64 %idxprom21
  %32 = load i64, i64* %arrayidx22, align 8
  %add = add i64 %32, %sub
  store i64 %add, i64* %arrayidx22, align 8
  call void @placeHolder()
  %call23 = call i64 (...) @CycleTime()
  %33 = load i64, i64* %_timeCommunicationStart, align 8
  %sub24 = sub i64 %call23, %33
  %34 = load i32, i32* %level.addr, align 4
  %idxprom25 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles26 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 0
  %communication = getelementptr inbounds %struct.anon, %struct.anon* %cycles26, i32 0, i32 5
  %arrayidx27 = getelementptr inbounds [10 x i64], [10 x i64]* %communication, i64 0, i64 %idxprom25
  %36 = load i64, i64* %arrayidx27, align 8
  %add28 = add i64 %36, %sub24
  store i64 %add28, i64* %arrayidx27, align 8
  ret void
}

declare i64 @CycleTime(...) #1

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #2

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined.(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %buffer, %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %exchange_faces, i32* dereferenceable(4) %exchange_edges, i32* dereferenceable(4) %exchange_corners, i32* dereferenceable(4) %grid_id) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %buffer.addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %exchange_faces.addr = alloca i32*, align 8
  %exchange_edges.addr = alloca i32*, align 8
  %exchange_corners.addr = alloca i32*, align 8
  %grid_id.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %buffer3 = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %buffer7 = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %buffer, i32** %buffer.addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %exchange_faces, i32** %exchange_faces.addr, align 8
  store i32* %exchange_edges, i32** %exchange_edges.addr, align 8
  store i32* %exchange_corners, i32** %exchange_corners.addr, align 8
  store i32* %grid_id, i32** %grid_id.addr, align 8
  %0 = load i32*, i32** %buffer.addr, align 8
  %1 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %2 = load i32*, i32** %level.addr, align 8
  %3 = load i32*, i32** %exchange_faces.addr, align 8
  %4 = load i32*, i32** %exchange_edges.addr, align 8
  %5 = load i32*, i32** %exchange_corners.addr, align 8
  %6 = load i32*, i32** %grid_id.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_End = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 10
  %8 = load i32, i32* %bufferCopy_Local_End, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_Start = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 9
  %10 = load i32, i32* %bufferCopy_Local_Start, align 8
  %sub = sub nsw i32 %8, %10
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  %11 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_Start4 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %11, i32 0, i32 9
  %12 = load i32, i32* %bufferCopy_Local_Start4, align 8
  store i32 %12, i32* %buffer3, align 4
  %13 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_Start5 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %13, i32 0, i32 9
  %14 = load i32, i32* %bufferCopy_Local_Start5, align 8
  %15 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_End6 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %15, i32 0, i32 10
  %16 = load i32, i32* %bufferCopy_Local_End6, align 4
  %cmp = icmp slt i32 %14, %16
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %17 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %17, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %18 = load i32*, i32** %.global_tid..addr, align 8
  %19 = load i32, i32* %18, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %19, i32 33, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  br label %omp.dispatch.cond

omp.dispatch.cond:                                ; preds = %omp.dispatch.inc, %omp.precond.then
  %20 = load i32, i32* %.omp.ub, align 4
  %21 = load i32, i32* %.omp.last.iteration, align 4
  %cmp8 = icmp sgt i32 %20, %21
  br i1 %cmp8, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.dispatch.cond
  %22 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.dispatch.cond
  %23 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %22, %cond.true ], [ %23, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %24 = load i32, i32* %.omp.lb, align 4
  store i32 %24, i32* %.omp.iv, align 4
  %25 = load i32, i32* %.omp.iv, align 4
  %26 = load i32, i32* %.omp.ub, align 4
  %cmp9 = icmp sle i32 %25, %26
  br i1 %cmp9, label %omp.dispatch.body, label %omp.dispatch.end

omp.dispatch.body:                                ; preds = %cond.end
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %omp.dispatch.body
  %27 = load i32, i32* %.omp.iv, align 4
  %28 = load i32, i32* %.omp.ub, align 4
  %cmp10 = icmp sle i32 %27, %28
  br i1 %cmp10, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %29 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopy_Local_Start11 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 9
  %30 = load i32, i32* %bufferCopy_Local_Start11, align 8
  %31 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %31, 1
  %add12 = add nsw i32 %30, %mul
  store i32 %add12, i32* %buffer7, align 4
  %32 = load i32, i32* %buffer7, align 4
  %idxprom = sext i32 %32 to i64
  %33 = load i32, i32* %2, align 4
  %idxprom13 = sext i32 %33 to i64
  %34 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopies = getelementptr inbounds %struct.domain_type, %struct.domain_type* %34, i32 0, i32 6
  %arrayidx = getelementptr inbounds [10 x %struct.bufferCopy_type*], [10 x %struct.bufferCopy_type*]* %bufferCopies, i64 0, i64 %idxprom13
  %35 = load %struct.bufferCopy_type*, %struct.bufferCopy_type** %arrayidx, align 8
  %arrayidx14 = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %35, i64 %idxprom
  %isFace = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %arrayidx14, i32 0, i32 0
  %36 = load i32, i32* %isFace, align 8
  %tobool = icmp ne i32 %36, 0
  br i1 %tobool, label %land.lhs.true, label %lor.lhs.false

land.lhs.true:                                    ; preds = %omp.inner.for.body
  %37 = load i32, i32* %3, align 4
  %tobool15 = icmp ne i32 %37, 0
  br i1 %tobool15, label %if.then, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %land.lhs.true, %omp.inner.for.body
  %38 = load i32, i32* %buffer7, align 4
  %idxprom16 = sext i32 %38 to i64
  %39 = load i32, i32* %2, align 4
  %idxprom17 = sext i32 %39 to i64
  %40 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopies18 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %40, i32 0, i32 6
  %arrayidx19 = getelementptr inbounds [10 x %struct.bufferCopy_type*], [10 x %struct.bufferCopy_type*]* %bufferCopies18, i64 0, i64 %idxprom17
  %41 = load %struct.bufferCopy_type*, %struct.bufferCopy_type** %arrayidx19, align 8
  %arrayidx20 = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %41, i64 %idxprom16
  %isEdge = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %arrayidx20, i32 0, i32 1
  %42 = load i32, i32* %isEdge, align 4
  %tobool21 = icmp ne i32 %42, 0
  br i1 %tobool21, label %land.lhs.true22, label %lor.lhs.false24

land.lhs.true22:                                  ; preds = %lor.lhs.false
  %43 = load i32, i32* %4, align 4
  %tobool23 = icmp ne i32 %43, 0
  br i1 %tobool23, label %if.then, label %lor.lhs.false24

lor.lhs.false24:                                  ; preds = %land.lhs.true22, %lor.lhs.false
  %44 = load i32, i32* %buffer7, align 4
  %idxprom25 = sext i32 %44 to i64
  %45 = load i32, i32* %2, align 4
  %idxprom26 = sext i32 %45 to i64
  %46 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %bufferCopies27 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %46, i32 0, i32 6
  %arrayidx28 = getelementptr inbounds [10 x %struct.bufferCopy_type*], [10 x %struct.bufferCopy_type*]* %bufferCopies27, i64 0, i64 %idxprom26
  %47 = load %struct.bufferCopy_type*, %struct.bufferCopy_type** %arrayidx28, align 8
  %arrayidx29 = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %47, i64 %idxprom25
  %isCorner = getelementptr inbounds %struct.bufferCopy_type, %struct.bufferCopy_type* %arrayidx29, i32 0, i32 2
  %48 = load i32, i32* %isCorner, align 8
  %tobool30 = icmp ne i32 %48, 0
  br i1 %tobool30, label %land.lhs.true31, label %if.end

land.lhs.true31:                                  ; preds = %lor.lhs.false24
  %49 = load i32, i32* %5, align 4
  %tobool32 = icmp ne i32 %49, 0
  br i1 %tobool32, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true31, %land.lhs.true22, %land.lhs.true
  %50 = load %struct.domain_type*, %struct.domain_type** %1, align 8
  %51 = load i32, i32* %2, align 4
  %52 = load i32, i32* %6, align 4
  %53 = load i32, i32* %buffer7, align 4
  call void @DoBufferCopy(%struct.domain_type* %50, i32 %51, i32 %52, i32 %53)
  br label %if.end

if.end:                                           ; preds = %if.then, %land.lhs.true31, %lor.lhs.false24
  br label %omp.body.continue

omp.body.continue:                                ; preds = %if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %54 = load i32, i32* %.omp.iv, align 4
  %add33 = add nsw i32 %54, 1
  store i32 %add33, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.dispatch.inc

omp.dispatch.inc:                                 ; preds = %omp.inner.for.end
  %55 = load i32, i32* %.omp.lb, align 4
  %56 = load i32, i32* %.omp.stride, align 4
  %add34 = add nsw i32 %55, %56
  store i32 %add34, i32* %.omp.lb, align 4
  %57 = load i32, i32* %.omp.ub, align 4
  %58 = load i32, i32* %.omp.stride, align 4
  %add35 = add nsw i32 %57, %58
  store i32 %add35, i32* %.omp.ub, align 4
  br label %omp.dispatch.cond

omp.dispatch.end:                                 ; preds = %cond.end
  %59 = load i32*, i32** %.global_tid..addr, align 8
  %60 = load i32, i32* %59, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %60)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.dispatch.end, %entry
  ret void
}

declare void @__kmpc_for_static_init_4(%ident_t*, i32, i32, i32*, i32*, i32*, i32*, i32, i32)

declare void @DoBufferCopy(%struct.domain_type*, i32, i32, i32) #1

declare void @__kmpc_for_static_fini(%ident_t*, i32)

declare void @__kmpc_fork_call(%ident_t*, i32, void (i32*, i32*, ...)*, ...)

; Function Attrs: nounwind uwtable
define void @rebuild_lambda(%struct.domain_type* %domain, i32 %level, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %dominant_eigenvalue = alloca double, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  store double -1.000000e+00, double* %dominant_eigenvalue, align 8
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, double*, double*, double*)* @.omp_outlined..2 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %omp_within_a_box, double* %b.addr, double* %a.addr, double* %dominant_eigenvalue)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..2(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %omp_within_a_box, double* %b.addr, double* %a.addr, double* %dominant_eigenvalue)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  %18 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %18, i32 0, i32 18
  %19 = load i32, i32* %rank, align 4
  %cmp14 = icmp eq i32 %19, 0
  br i1 %cmp14, label %if.then, label %if.end22

if.then:                                          ; preds = %omp_if.end
  %20 = load i32, i32* %level.addr, align 4
  %cmp16 = icmp eq i32 %20, 0
  br i1 %cmp16, label %if.then18, label %if.end

if.then18:                                        ; preds = %if.then
  %call19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then18, %if.then
  %21 = load i32, i32* %level.addr, align 4
  %22 = load double, double* %dominant_eigenvalue, align 8
  %call20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @.str.6, i32 0, i32 0), i32 %21, double %22)
  %23 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 8
  %call21 = call i32 @fflush(%struct._IO_FILE* %23)
  br label %if.end22

if.end22:                                         ; preds = %if.end, %omp_if.end
  %24 = load double, double* %dominant_eigenvalue, align 8
  %25 = load i32, i32* %level.addr, align 4
  %idxprom23 = sext i32 %25 to i64
  %26 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %dominant_eigenvalue_of_DinvA = getelementptr inbounds %struct.domain_type, %struct.domain_type* %26, i32 0, i32 24
  %arrayidx24 = getelementptr inbounds [10 x double], [10 x double]* %dominant_eigenvalue_of_DinvA, i64 0, i64 %idxprom23
  store double %24, double* %arrayidx24, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..2(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %b, double* dereferenceable(8) %a, double* dereferenceable(8) %dominant_eigenvalue) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %b.addr = alloca double*, align 8
  %a.addr = alloca double*, align 8
  %dominant_eigenvalue.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %dominant_eigenvalue5 = alloca double, align 8
  %box6 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %h2inv = alloca double, align 8
  %alpha = alloca double*, align 8
  %beta_i = alloca double*, align 8
  %beta_j = alloca double*, align 8
  %beta_k = alloca double*, align 8
  %lambda = alloca double*, align 8
  %box_eigenvalue = alloca double, align 8
  %.zero.addr = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %b, double** %b.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %dominant_eigenvalue, double** %dominant_eigenvalue.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %omp_within_a_box.addr, align 8
  %3 = load double*, double** %b.addr, align 8
  %4 = load double*, double** %a.addr, align 8
  %5 = load double*, double** %dominant_eigenvalue.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store double 0xFFEFFFFFFFFFFFFF, double* %dominant_eigenvalue5, align 8
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp7 = icmp sgt i32 %13, %14
  br i1 %cmp7, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp8 = icmp sle i32 %18, %19
  br i1 %cmp8, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add9 = add nsw i32 0, %mul
  store i32 %add9, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom10 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom10
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx11 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %pencil12 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx11, i32 0, i32 5
  %26 = load i32, i32* %pencil12, align 8
  store i32 %26, i32* %pencil, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom13 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom14 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains15 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains15, align 8
  %arrayidx16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom14
  %levels17 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx16, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels17, align 8
  %arrayidx18 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom13
  %plane19 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx18, i32 0, i32 6
  %32 = load i32, i32* %plane19, align 4
  store i32 %32, i32* %plane, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom20 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom21 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains22 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains22, align 8
  %arrayidx23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom21
  %levels24 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx23, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels24, align 8
  %arrayidx25 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom20
  %ghosts26 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx25, i32 0, i32 4
  %38 = load i32, i32* %ghosts26, align 4
  store i32 %38, i32* %ghosts, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom27 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom28 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains29 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains29, align 8
  %arrayidx30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom28
  %levels31 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx30, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels31, align 8
  %arrayidx32 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom27
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx32, i32 0, i32 2
  %k33 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %44 = load i32, i32* %k33, align 4
  store i32 %44, i32* %dim_k, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom34 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom35 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains36 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains36, align 8
  %arrayidx37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom35
  %levels38 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx37, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels38, align 8
  %arrayidx39 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom34
  %dim40 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx39, i32 0, i32 2
  %j41 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim40, i32 0, i32 1
  %50 = load i32, i32* %j41, align 4
  store i32 %50, i32* %dim_j, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom42 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom43 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains44 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains44, align 8
  %arrayidx45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom43
  %levels46 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx45, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels46, align 8
  %arrayidx47 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom42
  %dim48 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx47, i32 0, i32 2
  %i49 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim48, i32 0, i32 0
  %56 = load i32, i32* %i49, align 4
  store i32 %56, i32* %dim_i, align 4
  %57 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %57 to i64
  %58 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h = getelementptr inbounds %struct.domain_type, %struct.domain_type* %58, i32 0, i32 23
  %arrayidx51 = getelementptr inbounds [10 x double], [10 x double]* %h, i64 0, i64 %idxprom50
  %59 = load double, double* %arrayidx51, align 8
  %60 = load i32, i32* %1, align 4
  %idxprom52 = sext i32 %60 to i64
  %61 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h53 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %61, i32 0, i32 23
  %arrayidx54 = getelementptr inbounds [10 x double], [10 x double]* %h53, i64 0, i64 %idxprom52
  %62 = load double, double* %arrayidx54, align 8
  %mul55 = fmul double %59, %62
  %div56 = fdiv double 1.000000e+00, %mul55
  store double %div56, double* %h2inv, align 8
  %63 = load i32, i32* %1, align 4
  %idxprom57 = sext i32 %63 to i64
  %64 = load i32, i32* %box4, align 4
  %idxprom58 = sext i32 %64 to i64
  %65 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains59 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %65, i32 0, i32 25
  %66 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains59, align 8
  %arrayidx60 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %66, i64 %idxprom58
  %levels61 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx60, i32 0, i32 5
  %67 = load %struct.box_type*, %struct.box_type** %levels61, align 8
  %arrayidx62 = getelementptr inbounds %struct.box_type, %struct.box_type* %67, i64 %idxprom57
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx62, i32 0, i32 10
  %68 = load double**, double*** %grids, align 8
  %arrayidx63 = getelementptr inbounds double*, double** %68, i64 2
  %69 = load double*, double** %arrayidx63, align 8
  %70 = load i32, i32* %ghosts, align 4
  %71 = load i32, i32* %pencil, align 4
  %add64 = add nsw i32 1, %71
  %72 = load i32, i32* %plane, align 4
  %add65 = add nsw i32 %add64, %72
  %mul66 = mul nsw i32 %70, %add65
  %idx.ext = sext i32 %mul66 to i64
  %add.ptr = getelementptr inbounds double, double* %69, i64 %idx.ext
  store double* %add.ptr, double** %alpha, align 8
  %73 = load i32, i32* %1, align 4
  %idxprom67 = sext i32 %73 to i64
  %74 = load i32, i32* %box4, align 4
  %idxprom68 = sext i32 %74 to i64
  %75 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains69 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %75, i32 0, i32 25
  %76 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains69, align 8
  %arrayidx70 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %76, i64 %idxprom68
  %levels71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx70, i32 0, i32 5
  %77 = load %struct.box_type*, %struct.box_type** %levels71, align 8
  %arrayidx72 = getelementptr inbounds %struct.box_type, %struct.box_type* %77, i64 %idxprom67
  %grids73 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx72, i32 0, i32 10
  %78 = load double**, double*** %grids73, align 8
  %arrayidx74 = getelementptr inbounds double*, double** %78, i64 5
  %79 = load double*, double** %arrayidx74, align 8
  %80 = load i32, i32* %ghosts, align 4
  %81 = load i32, i32* %pencil, align 4
  %add75 = add nsw i32 1, %81
  %82 = load i32, i32* %plane, align 4
  %add76 = add nsw i32 %add75, %82
  %mul77 = mul nsw i32 %80, %add76
  %idx.ext78 = sext i32 %mul77 to i64
  %add.ptr79 = getelementptr inbounds double, double* %79, i64 %idx.ext78
  store double* %add.ptr79, double** %beta_i, align 8
  %83 = load i32, i32* %1, align 4
  %idxprom80 = sext i32 %83 to i64
  %84 = load i32, i32* %box4, align 4
  %idxprom81 = sext i32 %84 to i64
  %85 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains82 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %85, i32 0, i32 25
  %86 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains82, align 8
  %arrayidx83 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %86, i64 %idxprom81
  %levels84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx83, i32 0, i32 5
  %87 = load %struct.box_type*, %struct.box_type** %levels84, align 8
  %arrayidx85 = getelementptr inbounds %struct.box_type, %struct.box_type* %87, i64 %idxprom80
  %grids86 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx85, i32 0, i32 10
  %88 = load double**, double*** %grids86, align 8
  %arrayidx87 = getelementptr inbounds double*, double** %88, i64 6
  %89 = load double*, double** %arrayidx87, align 8
  %90 = load i32, i32* %ghosts, align 4
  %91 = load i32, i32* %pencil, align 4
  %add88 = add nsw i32 1, %91
  %92 = load i32, i32* %plane, align 4
  %add89 = add nsw i32 %add88, %92
  %mul90 = mul nsw i32 %90, %add89
  %idx.ext91 = sext i32 %mul90 to i64
  %add.ptr92 = getelementptr inbounds double, double* %89, i64 %idx.ext91
  store double* %add.ptr92, double** %beta_j, align 8
  %93 = load i32, i32* %1, align 4
  %idxprom93 = sext i32 %93 to i64
  %94 = load i32, i32* %box4, align 4
  %idxprom94 = sext i32 %94 to i64
  %95 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains95 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %95, i32 0, i32 25
  %96 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains95, align 8
  %arrayidx96 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %96, i64 %idxprom94
  %levels97 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx96, i32 0, i32 5
  %97 = load %struct.box_type*, %struct.box_type** %levels97, align 8
  %arrayidx98 = getelementptr inbounds %struct.box_type, %struct.box_type* %97, i64 %idxprom93
  %grids99 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx98, i32 0, i32 10
  %98 = load double**, double*** %grids99, align 8
  %arrayidx100 = getelementptr inbounds double*, double** %98, i64 7
  %99 = load double*, double** %arrayidx100, align 8
  %100 = load i32, i32* %ghosts, align 4
  %101 = load i32, i32* %pencil, align 4
  %add101 = add nsw i32 1, %101
  %102 = load i32, i32* %plane, align 4
  %add102 = add nsw i32 %add101, %102
  %mul103 = mul nsw i32 %100, %add102
  %idx.ext104 = sext i32 %mul103 to i64
  %add.ptr105 = getelementptr inbounds double, double* %99, i64 %idx.ext104
  store double* %add.ptr105, double** %beta_k, align 8
  %103 = load i32, i32* %1, align 4
  %idxprom106 = sext i32 %103 to i64
  %104 = load i32, i32* %box4, align 4
  %idxprom107 = sext i32 %104 to i64
  %105 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains108 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %105, i32 0, i32 25
  %106 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains108, align 8
  %arrayidx109 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %106, i64 %idxprom107
  %levels110 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx109, i32 0, i32 5
  %107 = load %struct.box_type*, %struct.box_type** %levels110, align 8
  %arrayidx111 = getelementptr inbounds %struct.box_type, %struct.box_type* %107, i64 %idxprom106
  %grids112 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx111, i32 0, i32 10
  %108 = load double**, double*** %grids112, align 8
  %arrayidx113 = getelementptr inbounds double*, double** %108, i64 4
  %109 = load double*, double** %arrayidx113, align 8
  %110 = load i32, i32* %ghosts, align 4
  %111 = load i32, i32* %pencil, align 4
  %add114 = add nsw i32 1, %111
  %112 = load i32, i32* %plane, align 4
  %add115 = add nsw i32 %add114, %112
  %mul116 = mul nsw i32 %110, %add115
  %idx.ext117 = sext i32 %mul116 to i64
  %add.ptr118 = getelementptr inbounds double, double* %109, i64 %idx.ext117
  store double* %add.ptr118, double** %lambda, align 8
  store double -1.000000e+00, double* %box_eigenvalue, align 8
  %113 = load i32, i32* %2, align 4
  %tobool = icmp ne i32 %113, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 14, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double*, double**, double**, double**, double*, double**, double**, double*)* @.omp_outlined..3 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %3, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double* %4, double** %alpha, double** %lambda, double* %box_eigenvalue)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %114 = load i32*, i32** %.global_tid..addr, align 8
  %115 = load i32, i32* %114, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %115)
  %116 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..3(i32* %116, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %3, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double* %4, double** %alpha, double** %lambda, double* %box_eigenvalue)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %115)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %117 = load double, double* %box_eigenvalue, align 8
  %118 = load double, double* %dominant_eigenvalue5, align 8
  %cmp119 = fcmp ogt double %117, %118
  br i1 %cmp119, label %if.then, label %if.end

if.then:                                          ; preds = %omp_if.end
  %119 = load double, double* %box_eigenvalue, align 8
  store double %119, double* %dominant_eigenvalue5, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %omp_if.end
  br label %omp.body.continue

omp.body.continue:                                ; preds = %if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %120 = load i32, i32* %.omp.iv, align 4
  %add120 = add nsw i32 %120, 1
  store i32 %add120, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %121 = load i32*, i32** %.global_tid..addr, align 8
  %122 = load i32, i32* %121, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %122)
  %123 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %124 = bitcast double* %dominant_eigenvalue5 to i8*
  store i8* %124, i8** %123, align 8
  %125 = load i32*, i32** %.global_tid..addr, align 8
  %126 = load i32, i32* %125, align 4
  %127 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %128 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %126, i32 1, i64 8, i8* %127, void (i8*, i8*)* @.omp.reduction.reduction_func.4, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %128, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %129 = load double, double* %5, align 8
  %130 = load double, double* %dominant_eigenvalue5, align 8
  %cmp121 = fcmp ogt double %129, %130
  br i1 %cmp121, label %cond.true122, label %cond.false123

cond.true122:                                     ; preds = %.omp.reduction.case1
  %131 = load double, double* %5, align 8
  br label %cond.end124

cond.false123:                                    ; preds = %.omp.reduction.case1
  %132 = load double, double* %dominant_eigenvalue5, align 8
  br label %cond.end124

cond.end124:                                      ; preds = %cond.false123, %cond.true122
  %cond125 = phi double [ %131, %cond.true122 ], [ %132, %cond.false123 ]
  store double %cond125, double* %5, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %126, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %133 = load double, double* %dominant_eigenvalue5, align 8
  %134 = bitcast double* %5 to i64*
  %atomic-load = load atomic i64, i64* %134 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %cond.end129, %.omp.reduction.case2
  %135 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %145, %cond.end129 ]
  %136 = bitcast double* %atomic-temp to i64*
  %137 = bitcast i64 %135 to double
  store double %137, double* %tmp, align 8
  %138 = load double, double* %tmp, align 8
  %139 = load double, double* %dominant_eigenvalue5, align 8
  %cmp126 = fcmp ogt double %138, %139
  br i1 %cmp126, label %cond.true127, label %cond.false128

cond.true127:                                     ; preds = %atomic_cont
  %140 = load double, double* %tmp, align 8
  br label %cond.end129

cond.false128:                                    ; preds = %atomic_cont
  %141 = load double, double* %dominant_eigenvalue5, align 8
  br label %cond.end129

cond.end129:                                      ; preds = %cond.false128, %cond.true127
  %cond130 = phi double [ %140, %cond.true127 ], [ %141, %cond.false128 ]
  store double %cond130, double* %atomic-temp, align 8
  %142 = load i64, i64* %136, align 8
  %143 = bitcast double* %5 to i64*
  %144 = cmpxchg i64* %143, i64 %135, i64 %142 monotonic monotonic
  %145 = extractvalue { i64, i1 } %144, 0
  %146 = extractvalue { i64, i1 } %144, 1
  br i1 %146, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %cond.end129
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %cond.end124, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..3(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %b, double* dereferenceable(8) %h2inv, double** dereferenceable(8) %beta_i, double** dereferenceable(8) %beta_j, double** dereferenceable(8) %beta_k, double* dereferenceable(8) %a, double** dereferenceable(8) %alpha, double** dereferenceable(8) %lambda, double* dereferenceable(8) %box_eigenvalue) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %b.addr = alloca double*, align 8
  %h2inv.addr = alloca double*, align 8
  %beta_i.addr = alloca double**, align 8
  %beta_j.addr = alloca double**, align 8
  %beta_k.addr = alloca double**, align 8
  %a.addr = alloca double*, align 8
  %alpha.addr = alloca double**, align 8
  %lambda.addr = alloca double**, align 8
  %box_eigenvalue.addr = alloca double*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %box_eigenvalue15 = alloca double, align 8
  %k16 = alloca i32, align 4
  %j17 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %sumAij = alloca double, align 8
  %Aii = alloca double, align 8
  %Di = alloca double, align 8
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %b, double** %b.addr, align 8
  store double* %h2inv, double** %h2inv.addr, align 8
  store double** %beta_i, double*** %beta_i.addr, align 8
  store double** %beta_j, double*** %beta_j.addr, align 8
  store double** %beta_k, double*** %beta_k.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double** %alpha, double*** %alpha.addr, align 8
  store double** %lambda, double*** %lambda.addr, align 8
  store double* %box_eigenvalue, double** %box_eigenvalue.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %b.addr, align 8
  %6 = load double*, double** %h2inv.addr, align 8
  %7 = load double**, double*** %beta_i.addr, align 8
  %8 = load double**, double*** %beta_j.addr, align 8
  %9 = load double**, double*** %beta_k.addr, align 8
  %10 = load double*, double** %a.addr, align 8
  %11 = load double**, double*** %alpha.addr, align 8
  %12 = load double**, double*** %lambda.addr, align 8
  %13 = load double*, double** %box_eigenvalue.addr, align 8
  %14 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %14, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %15 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %15, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %16 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %16
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %17 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %17
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %18 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %18, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  store double 0xFFEFFFFFFFFFFFFF, double* %box_eigenvalue15, align 8
  %19 = load i32*, i32** %.global_tid..addr, align 8
  %20 = load i32, i32* %19, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %20, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %21 = load i64, i64* %.omp.ub, align 8
  %22 = load i64, i64* %.omp.last.iteration, align 8
  %cmp18 = icmp sgt i64 %21, %22
  br i1 %cmp18, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %23 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %24 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %23, %cond.true ], [ %24, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %25 = load i64, i64* %.omp.lb, align 8
  store i64 %25, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i64, i64* %.omp.ub, align 8
  %cmp20 = icmp sle i64 %26, %27
  br i1 %cmp20, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %28 = load i64, i64* %.omp.iv, align 8
  %29 = load i32, i32* %1, align 4
  %sub22 = sub nsw i32 %29, 0
  %sub23 = sub nsw i32 %sub22, 1
  %add24 = add nsw i32 %sub23, 1
  %div25 = sdiv i32 %add24, 1
  %conv26 = sext i32 %div25 to i64
  %div27 = sdiv i64 %28, %conv26
  %mul28 = mul nsw i64 %div27, 1
  %add29 = add nsw i64 0, %mul28
  %conv30 = trunc i64 %add29 to i32
  store i32 %conv30, i32* %k13, align 4
  %30 = load i64, i64* %.omp.iv, align 8
  %31 = load i32, i32* %1, align 4
  %sub31 = sub nsw i32 %31, 0
  %sub32 = sub nsw i32 %sub31, 1
  %add33 = add nsw i32 %sub32, 1
  %div34 = sdiv i32 %add33, 1
  %conv35 = sext i32 %div34 to i64
  %rem = srem i64 %30, %conv35
  %mul36 = mul nsw i64 %rem, 1
  %add37 = add nsw i64 0, %mul36
  %conv38 = trunc i64 %add37 to i32
  store i32 %conv38, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %32 = load i32, i32* %i, align 4
  %33 = load i32, i32* %2, align 4
  %cmp39 = icmp slt i32 %32, %33
  br i1 %cmp39, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %34 = load i32, i32* %i, align 4
  %35 = load i32, i32* %j14, align 4
  %36 = load i32, i32* %3, align 4
  %mul41 = mul nsw i32 %35, %36
  %add42 = add nsw i32 %34, %mul41
  %37 = load i32, i32* %k13, align 4
  %38 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %37, %38
  %add44 = add nsw i32 %add42, %mul43
  store i32 %add44, i32* %ijk, align 4
  %39 = load double, double* %5, align 8
  %40 = load double, double* %6, align 8
  %mul45 = fmul double %39, %40
  %41 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %41 to i64
  %42 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %42, i64 %idxprom
  %43 = load double, double* %arrayidx, align 8
  %mul46 = fmul double %mul45, %43
  %call = call double @fabs(double %mul46) #6
  %44 = load double, double* %5, align 8
  %45 = load double, double* %6, align 8
  %mul47 = fmul double %44, %45
  %46 = load i32, i32* %ijk, align 4
  %add48 = add nsw i32 %46, 1
  %idxprom49 = sext i32 %add48 to i64
  %47 = load double*, double** %7, align 8
  %arrayidx50 = getelementptr inbounds double, double* %47, i64 %idxprom49
  %48 = load double, double* %arrayidx50, align 8
  %mul51 = fmul double %mul47, %48
  %call52 = call double @fabs(double %mul51) #6
  %add53 = fadd double %call, %call52
  %49 = load double, double* %5, align 8
  %50 = load double, double* %6, align 8
  %mul54 = fmul double %49, %50
  %51 = load i32, i32* %ijk, align 4
  %idxprom55 = sext i32 %51 to i64
  %52 = load double*, double** %8, align 8
  %arrayidx56 = getelementptr inbounds double, double* %52, i64 %idxprom55
  %53 = load double, double* %arrayidx56, align 8
  %mul57 = fmul double %mul54, %53
  %call58 = call double @fabs(double %mul57) #6
  %add59 = fadd double %add53, %call58
  %54 = load double, double* %5, align 8
  %55 = load double, double* %6, align 8
  %mul60 = fmul double %54, %55
  %56 = load i32, i32* %ijk, align 4
  %57 = load i32, i32* %3, align 4
  %add61 = add nsw i32 %56, %57
  %idxprom62 = sext i32 %add61 to i64
  %58 = load double*, double** %8, align 8
  %arrayidx63 = getelementptr inbounds double, double* %58, i64 %idxprom62
  %59 = load double, double* %arrayidx63, align 8
  %mul64 = fmul double %mul60, %59
  %call65 = call double @fabs(double %mul64) #6
  %add66 = fadd double %add59, %call65
  %60 = load double, double* %5, align 8
  %61 = load double, double* %6, align 8
  %mul67 = fmul double %60, %61
  %62 = load i32, i32* %ijk, align 4
  %idxprom68 = sext i32 %62 to i64
  %63 = load double*, double** %9, align 8
  %arrayidx69 = getelementptr inbounds double, double* %63, i64 %idxprom68
  %64 = load double, double* %arrayidx69, align 8
  %mul70 = fmul double %mul67, %64
  %call71 = call double @fabs(double %mul70) #6
  %add72 = fadd double %add66, %call71
  %65 = load double, double* %5, align 8
  %66 = load double, double* %6, align 8
  %mul73 = fmul double %65, %66
  %67 = load i32, i32* %ijk, align 4
  %68 = load i32, i32* %4, align 4
  %add74 = add nsw i32 %67, %68
  %idxprom75 = sext i32 %add74 to i64
  %69 = load double*, double** %9, align 8
  %arrayidx76 = getelementptr inbounds double, double* %69, i64 %idxprom75
  %70 = load double, double* %arrayidx76, align 8
  %mul77 = fmul double %mul73, %70
  %call78 = call double @fabs(double %mul77) #6
  %add79 = fadd double %add72, %call78
  store double %add79, double* %sumAij, align 8
  %71 = load double, double* %10, align 8
  %72 = load i32, i32* %ijk, align 4
  %idxprom80 = sext i32 %72 to i64
  %73 = load double*, double** %11, align 8
  %arrayidx81 = getelementptr inbounds double, double* %73, i64 %idxprom80
  %74 = load double, double* %arrayidx81, align 8
  %mul82 = fmul double %71, %74
  %75 = load double, double* %5, align 8
  %76 = load double, double* %6, align 8
  %mul83 = fmul double %75, %76
  %77 = load i32, i32* %ijk, align 4
  %idxprom84 = sext i32 %77 to i64
  %78 = load double*, double** %7, align 8
  %arrayidx85 = getelementptr inbounds double, double* %78, i64 %idxprom84
  %79 = load double, double* %arrayidx85, align 8
  %sub86 = fsub double -0.000000e+00, %79
  %80 = load i32, i32* %ijk, align 4
  %add87 = add nsw i32 %80, 1
  %idxprom88 = sext i32 %add87 to i64
  %81 = load double*, double** %7, align 8
  %arrayidx89 = getelementptr inbounds double, double* %81, i64 %idxprom88
  %82 = load double, double* %arrayidx89, align 8
  %sub90 = fsub double %sub86, %82
  %83 = load i32, i32* %ijk, align 4
  %idxprom91 = sext i32 %83 to i64
  %84 = load double*, double** %8, align 8
  %arrayidx92 = getelementptr inbounds double, double* %84, i64 %idxprom91
  %85 = load double, double* %arrayidx92, align 8
  %sub93 = fsub double %sub90, %85
  %86 = load i32, i32* %ijk, align 4
  %87 = load i32, i32* %3, align 4
  %add94 = add nsw i32 %86, %87
  %idxprom95 = sext i32 %add94 to i64
  %88 = load double*, double** %8, align 8
  %arrayidx96 = getelementptr inbounds double, double* %88, i64 %idxprom95
  %89 = load double, double* %arrayidx96, align 8
  %sub97 = fsub double %sub93, %89
  %90 = load i32, i32* %ijk, align 4
  %idxprom98 = sext i32 %90 to i64
  %91 = load double*, double** %9, align 8
  %arrayidx99 = getelementptr inbounds double, double* %91, i64 %idxprom98
  %92 = load double, double* %arrayidx99, align 8
  %sub100 = fsub double %sub97, %92
  %93 = load i32, i32* %ijk, align 4
  %94 = load i32, i32* %4, align 4
  %add101 = add nsw i32 %93, %94
  %idxprom102 = sext i32 %add101 to i64
  %95 = load double*, double** %9, align 8
  %arrayidx103 = getelementptr inbounds double, double* %95, i64 %idxprom102
  %96 = load double, double* %arrayidx103, align 8
  %sub104 = fsub double %sub100, %96
  %mul105 = fmul double %mul83, %sub104
  %sub106 = fsub double %mul82, %mul105
  store double %sub106, double* %Aii, align 8
  %97 = load double, double* %Aii, align 8
  %div107 = fdiv double 1.000000e+00, %97
  %98 = load i32, i32* %ijk, align 4
  %idxprom108 = sext i32 %98 to i64
  %99 = load double*, double** %12, align 8
  %arrayidx109 = getelementptr inbounds double, double* %99, i64 %idxprom108
  store double %div107, double* %arrayidx109, align 8
  %100 = load double, double* %Aii, align 8
  %101 = load double, double* %sumAij, align 8
  %add110 = fadd double %100, %101
  %102 = load double, double* %Aii, align 8
  %div111 = fdiv double %add110, %102
  store double %div111, double* %Di, align 8
  %103 = load double, double* %Di, align 8
  %104 = load double, double* %box_eigenvalue15, align 8
  %cmp112 = fcmp ogt double %103, %104
  br i1 %cmp112, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %105 = load double, double* %Di, align 8
  store double %105, double* %box_eigenvalue15, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %106 = load i32, i32* %i, align 4
  %inc = add nsw i32 %106, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %107 = load i64, i64* %.omp.iv, align 8
  %add114 = add nsw i64 %107, 1
  store i64 %add114, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %108 = load i32*, i32** %.global_tid..addr, align 8
  %109 = load i32, i32* %108, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %109)
  %110 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %111 = bitcast double* %box_eigenvalue15 to i8*
  store i8* %111, i8** %110, align 8
  %112 = load i32*, i32** %.global_tid..addr, align 8
  %113 = load i32, i32* %112, align 4
  %114 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %115 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %113, i32 1, i64 8, i8* %114, void (i8*, i8*)* @.omp.reduction.reduction_func, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %115, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %116 = load double, double* %13, align 8
  %117 = load double, double* %box_eigenvalue15, align 8
  %cmp115 = fcmp ogt double %116, %117
  br i1 %cmp115, label %cond.true117, label %cond.false118

cond.true117:                                     ; preds = %.omp.reduction.case1
  %118 = load double, double* %13, align 8
  br label %cond.end119

cond.false118:                                    ; preds = %.omp.reduction.case1
  %119 = load double, double* %box_eigenvalue15, align 8
  br label %cond.end119

cond.end119:                                      ; preds = %cond.false118, %cond.true117
  %cond120 = phi double [ %118, %cond.true117 ], [ %119, %cond.false118 ]
  store double %cond120, double* %13, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %113, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %120 = load double, double* %box_eigenvalue15, align 8
  %121 = bitcast double* %13 to i64*
  %atomic-load = load atomic i64, i64* %121 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %cond.end125, %.omp.reduction.case2
  %122 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %132, %cond.end125 ]
  %123 = bitcast double* %atomic-temp to i64*
  %124 = bitcast i64 %122 to double
  store double %124, double* %tmp, align 8
  %125 = load double, double* %tmp, align 8
  %126 = load double, double* %box_eigenvalue15, align 8
  %cmp121 = fcmp ogt double %125, %126
  br i1 %cmp121, label %cond.true123, label %cond.false124

cond.true123:                                     ; preds = %atomic_cont
  %127 = load double, double* %tmp, align 8
  br label %cond.end125

cond.false124:                                    ; preds = %atomic_cont
  %128 = load double, double* %box_eigenvalue15, align 8
  br label %cond.end125

cond.end125:                                      ; preds = %cond.false124, %cond.true123
  %cond126 = phi double [ %127, %cond.true123 ], [ %128, %cond.false124 ]
  store double %cond126, double* %atomic-temp, align 8
  %129 = load i64, i64* %123, align 8
  %130 = bitcast double* %13 to i64*
  %131 = cmpxchg i64* %130, i64 %122, i64 %129 monotonic monotonic
  %132 = extractvalue { i64, i1 } %131, 0
  %133 = extractvalue { i64, i1 } %131, 1
  br i1 %133, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %cond.end125
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %cond.end119, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %land.lhs.true, %entry
  ret void
}

declare void @__kmpc_for_static_init_8(%ident_t*, i32, i32, i32*, i64*, i64*, i64*, i64, i64)

; Function Attrs: nounwind readnone
declare double @fabs(double) #3

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %cmp = fcmp ogt double %12, %13
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %14 = load double, double* %11, align 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %15 = load double, double* %8, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi double [ %14, %cond.true ], [ %15, %cond.false ]
  store double %cond, double* %11, align 8
  ret void
}

declare i32 @__kmpc_reduce_nowait(%ident_t*, i32, i32, i64, i8*, void (i8*, i8*)*, [8 x i32]*)

declare void @__kmpc_end_reduce_nowait(%ident_t*, i32, [8 x i32]*)

declare void @__kmpc_serialized_parallel(%ident_t*, i32)

declare void @__kmpc_end_serialized_parallel(%ident_t*, i32)

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.4(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %cmp = fcmp ogt double %12, %13
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %14 = load double, double* %11, align 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %15 = load double, double* %8, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi double [ %14, %cond.true ], [ %15, %cond.false ]
  store double %cond, double* %11, align 8
  ret void
}

declare i32 @__kmpc_global_thread_num(%ident_t*)

declare i32 @fflush(%struct._IO_FILE*) #1

; Function Attrs: nounwind uwtable
define void @__box_smooth_GSRB_multiple(%struct.box_type* %box, i32 %phi_id, i32 %rhs_id, double %a, double %b, i32 %s) #0 {
entry:
  %box.addr = alloca %struct.box_type*, align 8
  %phi_id.addr = alloca i32, align 4
  %rhs_id.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %s.addr = alloca i32, align 4
  %jj = alloca i32, align 4
  %kk = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %h2inv = alloca double, align 8
  %phi = alloca double*, align 8
  %phi_new = alloca double*, align 8
  %rhs = alloca double*, align 8
  %alpha = alloca double*, align 8
  %beta_i = alloca double*, align 8
  %beta_j = alloca double*, align 8
  %beta_k = alloca double*, align 8
  %lambda = alloca double*, align 8
  %ghostsToOperateOn = alloca i32, align 4
  %ss = alloca i32, align 4
  %big_box = alloca i32, align 4
  %agg.captured = alloca %struct.anon.12, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  store %struct.box_type* %box, %struct.box_type** %box.addr, align 8
  store i32 %phi_id, i32* %phi_id.addr, align 4
  store i32 %rhs_id, i32* %rhs_id.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  store i32 %s, i32* %s.addr, align 4
  %1 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %pencil1 = getelementptr inbounds %struct.box_type, %struct.box_type* %1, i32 0, i32 5
  %2 = load i32, i32* %pencil1, align 8
  store i32 %2, i32* %pencil, align 4
  %3 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %plane2 = getelementptr inbounds %struct.box_type, %struct.box_type* %3, i32 0, i32 6
  %4 = load i32, i32* %plane2, align 4
  store i32 %4, i32* %plane, align 4
  %5 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %ghosts3 = getelementptr inbounds %struct.box_type, %struct.box_type* %5, i32 0, i32 4
  %6 = load i32, i32* %ghosts3, align 4
  store i32 %6, i32* %ghosts, align 4
  %7 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %h = getelementptr inbounds %struct.box_type, %struct.box_type* %7, i32 0, i32 0
  %8 = load double, double* %h, align 8
  %9 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %h4 = getelementptr inbounds %struct.box_type, %struct.box_type* %9, i32 0, i32 0
  %10 = load double, double* %h4, align 8
  %mul = fmul double %8, %10
  %div = fdiv double 1.000000e+00, %mul
  store double %div, double* %h2inv, align 8
  %11 = load i32, i32* %phi_id.addr, align 4
  %idxprom = sext i32 %11 to i64
  %12 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %12, i32 0, i32 10
  %13 = load double**, double*** %grids, align 8
  %arrayidx = getelementptr inbounds double*, double** %13, i64 %idxprom
  %14 = load double*, double** %arrayidx, align 8
  %15 = load i32, i32* %ghosts, align 4
  %16 = load i32, i32* %plane, align 4
  %mul5 = mul nsw i32 %15, %16
  %idx.ext = sext i32 %mul5 to i64
  %add.ptr = getelementptr inbounds double, double* %14, i64 %idx.ext
  %17 = load i32, i32* %ghosts, align 4
  %18 = load i32, i32* %pencil, align 4
  %mul6 = mul nsw i32 %17, %18
  %idx.ext7 = sext i32 %mul6 to i64
  %add.ptr8 = getelementptr inbounds double, double* %add.ptr, i64 %idx.ext7
  %19 = load i32, i32* %ghosts, align 4
  %idx.ext9 = sext i32 %19 to i64
  %add.ptr10 = getelementptr inbounds double, double* %add.ptr8, i64 %idx.ext9
  store double* %add.ptr10, double** %phi, align 8
  %20 = load i32, i32* %phi_id.addr, align 4
  %idxprom11 = sext i32 %20 to i64
  %21 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids12 = getelementptr inbounds %struct.box_type, %struct.box_type* %21, i32 0, i32 10
  %22 = load double**, double*** %grids12, align 8
  %arrayidx13 = getelementptr inbounds double*, double** %22, i64 %idxprom11
  %23 = load double*, double** %arrayidx13, align 8
  %24 = load i32, i32* %ghosts, align 4
  %25 = load i32, i32* %plane, align 4
  %mul14 = mul nsw i32 %24, %25
  %idx.ext15 = sext i32 %mul14 to i64
  %add.ptr16 = getelementptr inbounds double, double* %23, i64 %idx.ext15
  %26 = load i32, i32* %ghosts, align 4
  %27 = load i32, i32* %pencil, align 4
  %mul17 = mul nsw i32 %26, %27
  %idx.ext18 = sext i32 %mul17 to i64
  %add.ptr19 = getelementptr inbounds double, double* %add.ptr16, i64 %idx.ext18
  %28 = load i32, i32* %ghosts, align 4
  %idx.ext20 = sext i32 %28 to i64
  %add.ptr21 = getelementptr inbounds double, double* %add.ptr19, i64 %idx.ext20
  store double* %add.ptr21, double** %phi_new, align 8
  %29 = load i32, i32* %rhs_id.addr, align 4
  %idxprom22 = sext i32 %29 to i64
  %30 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids23 = getelementptr inbounds %struct.box_type, %struct.box_type* %30, i32 0, i32 10
  %31 = load double**, double*** %grids23, align 8
  %arrayidx24 = getelementptr inbounds double*, double** %31, i64 %idxprom22
  %32 = load double*, double** %arrayidx24, align 8
  %33 = load i32, i32* %ghosts, align 4
  %34 = load i32, i32* %plane, align 4
  %mul25 = mul nsw i32 %33, %34
  %idx.ext26 = sext i32 %mul25 to i64
  %add.ptr27 = getelementptr inbounds double, double* %32, i64 %idx.ext26
  %35 = load i32, i32* %ghosts, align 4
  %36 = load i32, i32* %pencil, align 4
  %mul28 = mul nsw i32 %35, %36
  %idx.ext29 = sext i32 %mul28 to i64
  %add.ptr30 = getelementptr inbounds double, double* %add.ptr27, i64 %idx.ext29
  %37 = load i32, i32* %ghosts, align 4
  %idx.ext31 = sext i32 %37 to i64
  %add.ptr32 = getelementptr inbounds double, double* %add.ptr30, i64 %idx.ext31
  store double* %add.ptr32, double** %rhs, align 8
  %38 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids33 = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i32 0, i32 10
  %39 = load double**, double*** %grids33, align 8
  %arrayidx34 = getelementptr inbounds double*, double** %39, i64 2
  %40 = load double*, double** %arrayidx34, align 8
  %41 = load i32, i32* %ghosts, align 4
  %42 = load i32, i32* %plane, align 4
  %mul35 = mul nsw i32 %41, %42
  %idx.ext36 = sext i32 %mul35 to i64
  %add.ptr37 = getelementptr inbounds double, double* %40, i64 %idx.ext36
  %43 = load i32, i32* %ghosts, align 4
  %44 = load i32, i32* %pencil, align 4
  %mul38 = mul nsw i32 %43, %44
  %idx.ext39 = sext i32 %mul38 to i64
  %add.ptr40 = getelementptr inbounds double, double* %add.ptr37, i64 %idx.ext39
  %45 = load i32, i32* %ghosts, align 4
  %idx.ext41 = sext i32 %45 to i64
  %add.ptr42 = getelementptr inbounds double, double* %add.ptr40, i64 %idx.ext41
  store double* %add.ptr42, double** %alpha, align 8
  %46 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids43 = getelementptr inbounds %struct.box_type, %struct.box_type* %46, i32 0, i32 10
  %47 = load double**, double*** %grids43, align 8
  %arrayidx44 = getelementptr inbounds double*, double** %47, i64 5
  %48 = load double*, double** %arrayidx44, align 8
  %49 = load i32, i32* %ghosts, align 4
  %50 = load i32, i32* %plane, align 4
  %mul45 = mul nsw i32 %49, %50
  %idx.ext46 = sext i32 %mul45 to i64
  %add.ptr47 = getelementptr inbounds double, double* %48, i64 %idx.ext46
  %51 = load i32, i32* %ghosts, align 4
  %52 = load i32, i32* %pencil, align 4
  %mul48 = mul nsw i32 %51, %52
  %idx.ext49 = sext i32 %mul48 to i64
  %add.ptr50 = getelementptr inbounds double, double* %add.ptr47, i64 %idx.ext49
  %53 = load i32, i32* %ghosts, align 4
  %idx.ext51 = sext i32 %53 to i64
  %add.ptr52 = getelementptr inbounds double, double* %add.ptr50, i64 %idx.ext51
  store double* %add.ptr52, double** %beta_i, align 8
  %54 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids53 = getelementptr inbounds %struct.box_type, %struct.box_type* %54, i32 0, i32 10
  %55 = load double**, double*** %grids53, align 8
  %arrayidx54 = getelementptr inbounds double*, double** %55, i64 6
  %56 = load double*, double** %arrayidx54, align 8
  %57 = load i32, i32* %ghosts, align 4
  %58 = load i32, i32* %plane, align 4
  %mul55 = mul nsw i32 %57, %58
  %idx.ext56 = sext i32 %mul55 to i64
  %add.ptr57 = getelementptr inbounds double, double* %56, i64 %idx.ext56
  %59 = load i32, i32* %ghosts, align 4
  %60 = load i32, i32* %pencil, align 4
  %mul58 = mul nsw i32 %59, %60
  %idx.ext59 = sext i32 %mul58 to i64
  %add.ptr60 = getelementptr inbounds double, double* %add.ptr57, i64 %idx.ext59
  %61 = load i32, i32* %ghosts, align 4
  %idx.ext61 = sext i32 %61 to i64
  %add.ptr62 = getelementptr inbounds double, double* %add.ptr60, i64 %idx.ext61
  store double* %add.ptr62, double** %beta_j, align 8
  %62 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids63 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i32 0, i32 10
  %63 = load double**, double*** %grids63, align 8
  %arrayidx64 = getelementptr inbounds double*, double** %63, i64 7
  %64 = load double*, double** %arrayidx64, align 8
  %65 = load i32, i32* %ghosts, align 4
  %66 = load i32, i32* %plane, align 4
  %mul65 = mul nsw i32 %65, %66
  %idx.ext66 = sext i32 %mul65 to i64
  %add.ptr67 = getelementptr inbounds double, double* %64, i64 %idx.ext66
  %67 = load i32, i32* %ghosts, align 4
  %68 = load i32, i32* %pencil, align 4
  %mul68 = mul nsw i32 %67, %68
  %idx.ext69 = sext i32 %mul68 to i64
  %add.ptr70 = getelementptr inbounds double, double* %add.ptr67, i64 %idx.ext69
  %69 = load i32, i32* %ghosts, align 4
  %idx.ext71 = sext i32 %69 to i64
  %add.ptr72 = getelementptr inbounds double, double* %add.ptr70, i64 %idx.ext71
  store double* %add.ptr72, double** %beta_k, align 8
  %70 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %grids73 = getelementptr inbounds %struct.box_type, %struct.box_type* %70, i32 0, i32 10
  %71 = load double**, double*** %grids73, align 8
  %arrayidx74 = getelementptr inbounds double*, double** %71, i64 4
  %72 = load double*, double** %arrayidx74, align 8
  %73 = load i32, i32* %ghosts, align 4
  %74 = load i32, i32* %plane, align 4
  %mul75 = mul nsw i32 %73, %74
  %idx.ext76 = sext i32 %mul75 to i64
  %add.ptr77 = getelementptr inbounds double, double* %72, i64 %idx.ext76
  %75 = load i32, i32* %ghosts, align 4
  %76 = load i32, i32* %pencil, align 4
  %mul78 = mul nsw i32 %75, %76
  %idx.ext79 = sext i32 %mul78 to i64
  %add.ptr80 = getelementptr inbounds double, double* %add.ptr77, i64 %idx.ext79
  %77 = load i32, i32* %ghosts, align 4
  %idx.ext81 = sext i32 %77 to i64
  %add.ptr82 = getelementptr inbounds double, double* %add.ptr80, i64 %idx.ext81
  store double* %add.ptr82, double** %lambda, align 8
  %78 = load i32, i32* %ghosts, align 4
  %sub = sub nsw i32 %78, 1
  store i32 %sub, i32* %ghostsToOperateOn, align 4
  store i32 0, i32* %big_box, align 4
  %79 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %79, i32 0, i32 2
  %k = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %80 = load i32, i32* %k, align 4
  %cmp = icmp sgt i32 %80, 8
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 1, i32* %big_box, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %81 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %dim83 = getelementptr inbounds %struct.box_type, %struct.box_type* %81, i32 0, i32 2
  %j = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim83, i32 0, i32 1
  %82 = load i32, i32* %j, align 4
  %cmp84 = icmp sgt i32 %82, 8
  br i1 %cmp84, label %if.then85, label %if.end86

if.then85:                                        ; preds = %if.end
  store i32 1, i32* %big_box, align 4
  br label %if.end86

if.end86:                                         ; preds = %if.then85, %if.end
  %83 = load i32, i32* %s.addr, align 4
  store i32 %83, i32* %ss, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc126, %if.end86
  %84 = load i32, i32* %ss, align 4
  %85 = load i32, i32* %s.addr, align 4
  %86 = load i32, i32* %ghosts, align 4
  %add = add nsw i32 %85, %86
  %cmp87 = icmp slt i32 %84, %add
  br i1 %cmp87, label %for.body, label %for.end127

for.body:                                         ; preds = %for.cond
  %87 = load i32, i32* %ghostsToOperateOn, align 4
  %sub88 = sub nsw i32 0, %87
  store i32 %sub88, i32* %kk, align 4
  br label %for.cond89

for.cond89:                                       ; preds = %for.inc120, %for.body
  %88 = load i32, i32* %kk, align 4
  %89 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %dim90 = getelementptr inbounds %struct.box_type, %struct.box_type* %89, i32 0, i32 2
  %k91 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim90, i32 0, i32 2
  %90 = load i32, i32* %k91, align 4
  %91 = load i32, i32* %ghostsToOperateOn, align 4
  %add92 = add nsw i32 %90, %91
  %cmp93 = icmp slt i32 %88, %add92
  br i1 %cmp93, label %for.body94, label %for.end122

for.body94:                                       ; preds = %for.cond89
  %92 = load i32, i32* %ghostsToOperateOn, align 4
  %sub95 = sub nsw i32 0, %92
  store i32 %sub95, i32* %jj, align 4
  br label %for.cond96

for.cond96:                                       ; preds = %for.inc, %for.body94
  %93 = load i32, i32* %jj, align 4
  %94 = load %struct.box_type*, %struct.box_type** %box.addr, align 8
  %dim97 = getelementptr inbounds %struct.box_type, %struct.box_type* %94, i32 0, i32 2
  %j98 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim97, i32 0, i32 1
  %95 = load i32, i32* %j98, align 4
  %96 = load i32, i32* %ghostsToOperateOn, align 4
  %add99 = add nsw i32 %95, %96
  %cmp100 = icmp slt i32 %93, %add99
  br i1 %cmp100, label %for.body101, label %for.end

for.body101:                                      ; preds = %for.cond96
  %97 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 0
  store i32* %kk, i32** %97, align 8
  %98 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 1
  store %struct.box_type** %box.addr, %struct.box_type*** %98, align 8
  %99 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 2
  store i32* %ghostsToOperateOn, i32** %99, align 8
  %100 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 3
  store i32* %jj, i32** %100, align 8
  %101 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 4
  store i32* %ss, i32** %101, align 8
  %102 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 5
  store i32* %pencil, i32** %102, align 8
  %103 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 6
  store i32* %plane, i32** %103, align 8
  %104 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 7
  store double* %a.addr, double** %104, align 8
  %105 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 8
  store double** %alpha, double*** %105, align 8
  %106 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 9
  store double** %phi, double*** %106, align 8
  %107 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 10
  store double* %b.addr, double** %107, align 8
  %108 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 11
  store double* %h2inv, double** %108, align 8
  %109 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 12
  store double** %beta_i, double*** %109, align 8
  %110 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 13
  store double** %beta_j, double*** %110, align 8
  %111 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 14
  store double** %beta_k, double*** %111, align 8
  %112 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 15
  store double** %phi_new, double*** %112, align 8
  %113 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 16
  store double** %lambda, double*** %113, align 8
  %114 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %agg.captured, i32 0, i32 17
  store double** %rhs, double*** %114, align 8
  %115 = call i8* @__kmpc_omp_task_alloc(%ident_t* @0, i32 %0, i32 1, i64 152, i64 144, i32 (i32, i8*)* bitcast (i32 (i32, %struct.kmp_task_t_with_privates*)* @.omp_task_entry. to i32 (i32, i8*)*))
  %116 = bitcast i8* %115 to %struct.kmp_task_t_with_privates*
  %117 = getelementptr inbounds %struct.kmp_task_t_with_privates, %struct.kmp_task_t_with_privates* %116, i32 0, i32 0
  %118 = getelementptr inbounds %struct.kmp_task_t, %struct.kmp_task_t* %117, i32 0, i32 0
  %119 = load i8*, i8** %118, align 8
  %120 = bitcast %struct.anon.12* %agg.captured to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %119, i8* %120, i64 144, i32 8, i1 false)
  %121 = getelementptr inbounds %struct.kmp_task_t_with_privates, %struct.kmp_task_t_with_privates* %116, i32 0, i32 1
  %122 = bitcast i8* %119 to %struct.anon.12*
  %123 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 0
  %124 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 1
  %ref = load %struct.box_type**, %struct.box_type*** %124, align 8
  %125 = load %struct.box_type*, %struct.box_type** %ref, align 8
  store %struct.box_type* %125, %struct.box_type** %123, align 8
  %126 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 1
  %127 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 7
  %ref102 = load double*, double** %127, align 8
  %128 = load double, double* %ref102, align 8
  store double %128, double* %126, align 8
  %129 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 2
  %130 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 8
  %ref103 = load double**, double*** %130, align 8
  %131 = load double*, double** %ref103, align 8
  store double* %131, double** %129, align 8
  %132 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 3
  %133 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 9
  %ref104 = load double**, double*** %133, align 8
  %134 = load double*, double** %ref104, align 8
  store double* %134, double** %132, align 8
  %135 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 4
  %136 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 10
  %ref105 = load double*, double** %136, align 8
  %137 = load double, double* %ref105, align 8
  store double %137, double* %135, align 8
  %138 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 5
  %139 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 11
  %ref106 = load double*, double** %139, align 8
  %140 = load double, double* %ref106, align 8
  store double %140, double* %138, align 8
  %141 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 6
  %142 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 12
  %ref107 = load double**, double*** %142, align 8
  %143 = load double*, double** %ref107, align 8
  store double* %143, double** %141, align 8
  %144 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 7
  %145 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 13
  %ref108 = load double**, double*** %145, align 8
  %146 = load double*, double** %ref108, align 8
  store double* %146, double** %144, align 8
  %147 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 8
  %148 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 14
  %ref109 = load double**, double*** %148, align 8
  %149 = load double*, double** %ref109, align 8
  store double* %149, double** %147, align 8
  %150 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 9
  %151 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 15
  %ref110 = load double**, double*** %151, align 8
  %152 = load double*, double** %ref110, align 8
  store double* %152, double** %150, align 8
  %153 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 10
  %154 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 16
  %ref111 = load double**, double*** %154, align 8
  %155 = load double*, double** %ref111, align 8
  store double* %155, double** %153, align 8
  %156 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 11
  %157 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 17
  %ref112 = load double**, double*** %157, align 8
  %158 = load double*, double** %ref112, align 8
  store double* %158, double** %156, align 8
  %159 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 12
  %160 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 0
  %ref113 = load i32*, i32** %160, align 8
  %161 = load i32, i32* %ref113, align 4
  store i32 %161, i32* %159, align 8
  %162 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 13
  %163 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 2
  %ref114 = load i32*, i32** %163, align 8
  %164 = load i32, i32* %ref114, align 4
  store i32 %164, i32* %162, align 4
  %165 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 14
  %166 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 3
  %ref115 = load i32*, i32** %166, align 8
  %167 = load i32, i32* %ref115, align 4
  store i32 %167, i32* %165, align 8
  %168 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 15
  %169 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 4
  %ref116 = load i32*, i32** %169, align 8
  %170 = load i32, i32* %ref116, align 4
  store i32 %170, i32* %168, align 4
  %171 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 16
  %172 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 5
  %ref117 = load i32*, i32** %172, align 8
  %173 = load i32, i32* %ref117, align 4
  store i32 %173, i32* %171, align 8
  %174 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %121, i32 0, i32 17
  %175 = getelementptr inbounds %struct.anon.12, %struct.anon.12* %122, i32 0, i32 6
  %ref118 = load i32*, i32** %175, align 8
  %176 = load i32, i32* %ref118, align 4
  store i32 %176, i32* %174, align 4
  %177 = getelementptr inbounds %struct.kmp_task_t, %struct.kmp_task_t* %117, i32 0, i32 3
  store i32 (i32, i8*)* null, i32 (i32, i8*)** %177, align 8
  %178 = load i32, i32* %big_box, align 4
  %tobool = icmp ne i32 %178, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %for.body101
  %179 = call i32 @__kmpc_omp_task(%ident_t* @0, i32 %0, i8* %115)
  br label %omp_if.end

omp_if.else:                                      ; preds = %for.body101
  call void @__kmpc_omp_task_begin_if0(%ident_t* @0, i32 %0, i8* %115)
  %180 = call i32 @.omp_task_entry.(i32 %0, %struct.kmp_task_t_with_privates* %116)
  call void @__kmpc_omp_task_complete_if0(%ident_t* @0, i32 %0, i8* %115)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %for.inc

for.inc:                                          ; preds = %omp_if.end
  %181 = load i32, i32* %jj, align 4
  %add119 = add nsw i32 %181, 16
  store i32 %add119, i32* %jj, align 4
  br label %for.cond96

for.end:                                          ; preds = %for.cond96
  br label %for.inc120

for.inc120:                                       ; preds = %for.end
  %182 = load i32, i32* %kk, align 4
  %add121 = add nsw i32 %182, 4
  store i32 %add121, i32* %kk, align 4
  br label %for.cond89

for.end122:                                       ; preds = %for.cond89
  %183 = load i32, i32* %ghostsToOperateOn, align 4
  %cmp123 = icmp sgt i32 %183, 0
  br i1 %cmp123, label %if.then124, label %if.end125

if.then124:                                       ; preds = %for.end122
  %184 = call i32 @__kmpc_omp_taskwait(%ident_t* @0, i32 %0)
  br label %if.end125

if.end125:                                        ; preds = %if.then124, %for.end122
  br label %for.inc126

for.inc126:                                       ; preds = %if.end125
  %185 = load i32, i32* %ss, align 4
  %inc = add nsw i32 %185, 1
  store i32 %inc, i32* %ss, align 4
  %186 = load i32, i32* %ghostsToOperateOn, align 4
  %dec = add nsw i32 %186, -1
  store i32 %dec, i32* %ghostsToOperateOn, align 4
  br label %for.cond

for.end127:                                       ; preds = %for.cond
  ret void
}

; Function Attrs: alwaysinline nounwind uwtable
define internal void @.omp_task_privates_map.(%struct..kmp_privates.t* noalias, i32** noalias, %struct.box_type*** noalias, i32** noalias, i32** noalias, i32** noalias, i32** noalias, i32** noalias, double** noalias, double*** noalias, double*** noalias, double** noalias, double** noalias, double*** noalias, double*** noalias, double*** noalias, double*** noalias, double*** noalias, double*** noalias) #4 {
entry:
  %.addr = alloca %struct..kmp_privates.t*, align 8
  %.addr1 = alloca i32**, align 8
  %.addr2 = alloca %struct.box_type***, align 8
  %.addr3 = alloca i32**, align 8
  %.addr4 = alloca i32**, align 8
  %.addr5 = alloca i32**, align 8
  %.addr6 = alloca i32**, align 8
  %.addr7 = alloca i32**, align 8
  %.addr8 = alloca double**, align 8
  %.addr9 = alloca double***, align 8
  %.addr10 = alloca double***, align 8
  %.addr11 = alloca double**, align 8
  %.addr12 = alloca double**, align 8
  %.addr13 = alloca double***, align 8
  %.addr14 = alloca double***, align 8
  %.addr15 = alloca double***, align 8
  %.addr16 = alloca double***, align 8
  %.addr17 = alloca double***, align 8
  %.addr18 = alloca double***, align 8
  store %struct..kmp_privates.t* %0, %struct..kmp_privates.t** %.addr, align 8
  store i32** %1, i32*** %.addr1, align 8
  store %struct.box_type*** %2, %struct.box_type**** %.addr2, align 8
  store i32** %3, i32*** %.addr3, align 8
  store i32** %4, i32*** %.addr4, align 8
  store i32** %5, i32*** %.addr5, align 8
  store i32** %6, i32*** %.addr6, align 8
  store i32** %7, i32*** %.addr7, align 8
  store double** %8, double*** %.addr8, align 8
  store double*** %9, double**** %.addr9, align 8
  store double*** %10, double**** %.addr10, align 8
  store double** %11, double*** %.addr11, align 8
  store double** %12, double*** %.addr12, align 8
  store double*** %13, double**** %.addr13, align 8
  store double*** %14, double**** %.addr14, align 8
  store double*** %15, double**** %.addr15, align 8
  store double*** %16, double**** %.addr16, align 8
  store double*** %17, double**** %.addr17, align 8
  store double*** %18, double**** %.addr18, align 8
  %19 = load %struct..kmp_privates.t*, %struct..kmp_privates.t** %.addr, align 8
  %20 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 0
  %21 = load %struct.box_type***, %struct.box_type**** %.addr2, align 8
  store %struct.box_type** %20, %struct.box_type*** %21, align 8
  %22 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 1
  %23 = load double**, double*** %.addr8, align 8
  store double* %22, double** %23, align 8
  %24 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 2
  %25 = load double***, double**** %.addr9, align 8
  store double** %24, double*** %25, align 8
  %26 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 3
  %27 = load double***, double**** %.addr10, align 8
  store double** %26, double*** %27, align 8
  %28 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 4
  %29 = load double**, double*** %.addr11, align 8
  store double* %28, double** %29, align 8
  %30 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 5
  %31 = load double**, double*** %.addr12, align 8
  store double* %30, double** %31, align 8
  %32 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 6
  %33 = load double***, double**** %.addr13, align 8
  store double** %32, double*** %33, align 8
  %34 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 7
  %35 = load double***, double**** %.addr14, align 8
  store double** %34, double*** %35, align 8
  %36 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 8
  %37 = load double***, double**** %.addr15, align 8
  store double** %36, double*** %37, align 8
  %38 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 9
  %39 = load double***, double**** %.addr16, align 8
  store double** %38, double*** %39, align 8
  %40 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 10
  %41 = load double***, double**** %.addr17, align 8
  store double** %40, double*** %41, align 8
  %42 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 11
  %43 = load double***, double**** %.addr18, align 8
  store double** %42, double*** %43, align 8
  %44 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 12
  %45 = load i32**, i32*** %.addr1, align 8
  store i32* %44, i32** %45, align 8
  %46 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 13
  %47 = load i32**, i32*** %.addr3, align 8
  store i32* %46, i32** %47, align 8
  %48 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 14
  %49 = load i32**, i32*** %.addr4, align 8
  store i32* %48, i32** %49, align 8
  %50 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 15
  %51 = load i32**, i32*** %.addr5, align 8
  store i32* %50, i32** %51, align 8
  %52 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 16
  %53 = load i32**, i32*** %.addr6, align 8
  store i32* %52, i32** %53, align 8
  %54 = getelementptr inbounds %struct..kmp_privates.t, %struct..kmp_privates.t* %19, i32 0, i32 17
  %55 = load i32**, i32*** %.addr7, align 8
  store i32* %54, i32** %55, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal i32 @.omp_task_entry.(i32, %struct.kmp_task_t_with_privates* noalias) #0 {
entry:
  %.global_tid..addr.i = alloca i32, align 4
  %.part_id..addr.i = alloca i32, align 4
  %.privates..addr.i = alloca i8*, align 8
  %.copy_fn..addr.i = alloca void (i8*, ...)*, align 8
  %__context.addr.i = alloca %struct.anon.12*, align 8
  %tmp.i = alloca i32*, align 8
  %tmp1.i = alloca %struct.box_type**, align 8
  %tmp2.i = alloca i32*, align 8
  %tmp3.i = alloca i32*, align 8
  %tmp4.i = alloca i32*, align 8
  %tmp5.i = alloca i32*, align 8
  %tmp6.i = alloca i32*, align 8
  %tmp7.i = alloca double*, align 8
  %tmp8.i = alloca double**, align 8
  %tmp9.i = alloca double**, align 8
  %tmp10.i = alloca double*, align 8
  %tmp11.i = alloca double*, align 8
  %tmp12.i = alloca double**, align 8
  %tmp13.i = alloca double**, align 8
  %tmp14.i = alloca double**, align 8
  %tmp15.i = alloca double**, align 8
  %tmp16.i = alloca double**, align 8
  %tmp17.i = alloca double**, align 8
  %i.i = alloca i32, align 4
  %j.i = alloca i32, align 4
  %k.i = alloca i32, align 4
  %highK.i = alloca i32, align 4
  %highJ.i = alloca i32, align 4
  %ijk.i = alloca i32, align 4
  %helmholtz.i = alloca double, align 8
  %.addr = alloca i32, align 4
  %.addr1 = alloca %struct.kmp_task_t_with_privates*, align 8
  store i32 %0, i32* %.addr, align 4
  store %struct.kmp_task_t_with_privates* %1, %struct.kmp_task_t_with_privates** %.addr1, align 8
  %2 = load i32, i32* %.addr, align 4
  %3 = load %struct.kmp_task_t_with_privates*, %struct.kmp_task_t_with_privates** %.addr1, align 8
  %4 = getelementptr inbounds %struct.kmp_task_t_with_privates, %struct.kmp_task_t_with_privates* %3, i32 0, i32 0
  %5 = getelementptr inbounds %struct.kmp_task_t, %struct.kmp_task_t* %4, i32 0, i32 2
  %6 = load i32, i32* %5, align 8
  %7 = getelementptr inbounds %struct.kmp_task_t, %struct.kmp_task_t* %4, i32 0, i32 0
  %8 = load i8*, i8** %7, align 8
  %9 = bitcast i8* %8 to %struct.anon.12*
  %10 = getelementptr inbounds %struct.kmp_task_t_with_privates, %struct.kmp_task_t_with_privates* %3, i32 0, i32 1
  %11 = bitcast %struct..kmp_privates.t* %10 to i8*
  store i32 %2, i32* %.global_tid..addr.i, align 4, !noalias !1
  store i32 %6, i32* %.part_id..addr.i, align 4, !noalias !1
  store i8* %11, i8** %.privates..addr.i, align 8, !noalias !1
  store void (i8*, ...)* bitcast (void (%struct..kmp_privates.t*, i32**, %struct.box_type***, i32**, i32**, i32**, i32**, i32**, double**, double***, double***, double**, double**, double***, double***, double***, double***, double***, double***)* @.omp_task_privates_map. to void (i8*, ...)*), void (i8*, ...)** %.copy_fn..addr.i, align 8, !noalias !1
  store %struct.anon.12* %9, %struct.anon.12** %__context.addr.i, align 8, !noalias !1
  %12 = load %struct.anon.12*, %struct.anon.12** %__context.addr.i, align 8, !noalias !1
  %13 = load void (i8*, ...)*, void (i8*, ...)** %.copy_fn..addr.i, align 8, !noalias !1
  %14 = load i8*, i8** %.privates..addr.i, align 8, !noalias !1
  call void (i8*, ...) %13(i8* %14, i32** %tmp.i, %struct.box_type*** %tmp1.i, i32** %tmp2.i, i32** %tmp3.i, i32** %tmp4.i, i32** %tmp5.i, i32** %tmp6.i, double** %tmp7.i, double*** %tmp8.i, double*** %tmp9.i, double** %tmp10.i, double** %tmp11.i, double*** %tmp12.i, double*** %tmp13.i, double*** %tmp14.i, double*** %tmp15.i, double*** %tmp16.i, double*** %tmp17.i) #7
  %15 = load i32*, i32** %tmp.i, align 8, !noalias !1
  %16 = load %struct.box_type**, %struct.box_type*** %tmp1.i, align 8, !noalias !1
  %17 = load i32*, i32** %tmp2.i, align 8, !noalias !1
  %18 = load i32*, i32** %tmp3.i, align 8, !noalias !1
  %19 = load i32*, i32** %tmp4.i, align 8, !noalias !1
  %20 = load i32*, i32** %tmp5.i, align 8, !noalias !1
  %21 = load i32*, i32** %tmp6.i, align 8, !noalias !1
  %22 = load double*, double** %tmp7.i, align 8, !noalias !1
  %23 = load double**, double*** %tmp8.i, align 8, !noalias !1
  %24 = load double**, double*** %tmp9.i, align 8, !noalias !1
  %25 = load double*, double** %tmp10.i, align 8, !noalias !1
  %26 = load double*, double** %tmp11.i, align 8, !noalias !1
  %27 = load double**, double*** %tmp12.i, align 8, !noalias !1
  %28 = load double**, double*** %tmp13.i, align 8, !noalias !1
  %29 = load double**, double*** %tmp14.i, align 8, !noalias !1
  %30 = load double**, double*** %tmp15.i, align 8, !noalias !1
  %31 = load double**, double*** %tmp16.i, align 8, !noalias !1
  %32 = load double**, double*** %tmp17.i, align 8, !noalias !1
  %33 = load i32, i32* %15, align 4
  %add.i = add nsw i32 %33, 4
  %34 = load %struct.box_type*, %struct.box_type** %16, align 8
  %dim.i = getelementptr inbounds %struct.box_type, %struct.box_type* %34, i32 0, i32 2
  %k23.i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim.i, i32 0, i32 2
  %35 = load i32, i32* %k23.i, align 4
  %36 = load i32, i32* %17, align 4
  %add24.i = add nsw i32 %35, %36
  %cmp.i = icmp slt i32 %add.i, %add24.i
  br i1 %cmp.i, label %cond.true.i, label %cond.false.i

cond.true.i:                                      ; preds = %entry
  %37 = load i32, i32* %15, align 4
  %add25.i = add nsw i32 %37, 4
  br label %cond.end.i

cond.false.i:                                     ; preds = %entry
  %38 = load %struct.box_type*, %struct.box_type** %16, align 8
  %dim26.i = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i32 0, i32 2
  %k27.i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim26.i, i32 0, i32 2
  %39 = load i32, i32* %k27.i, align 4
  %40 = load i32, i32* %17, align 4
  %add28.i = add nsw i32 %39, %40
  br label %cond.end.i

cond.end.i:                                       ; preds = %cond.false.i, %cond.true.i
  %cond.i = phi i32 [ %add25.i, %cond.true.i ], [ %add28.i, %cond.false.i ]
  store i32 %cond.i, i32* %highK.i, align 4, !noalias !1
  %41 = load i32, i32* %18, align 4
  %add29.i = add nsw i32 %41, 16
  %42 = load %struct.box_type*, %struct.box_type** %16, align 8
  %dim30.i = getelementptr inbounds %struct.box_type, %struct.box_type* %42, i32 0, i32 2
  %j31.i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim30.i, i32 0, i32 1
  %43 = load i32, i32* %j31.i, align 4
  %44 = load i32, i32* %17, align 4
  %add32.i = add nsw i32 %43, %44
  %cmp33.i = icmp slt i32 %add29.i, %add32.i
  br i1 %cmp33.i, label %cond.true34.i, label %cond.false36.i

cond.true34.i:                                    ; preds = %cond.end.i
  %45 = load i32, i32* %18, align 4
  %add35.i = add nsw i32 %45, 16
  br label %cond.end40.i

cond.false36.i:                                   ; preds = %cond.end.i
  %46 = load %struct.box_type*, %struct.box_type** %16, align 8
  %dim37.i = getelementptr inbounds %struct.box_type, %struct.box_type* %46, i32 0, i32 2
  %j38.i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim37.i, i32 0, i32 1
  %47 = load i32, i32* %j38.i, align 4
  %48 = load i32, i32* %17, align 4
  %add39.i = add nsw i32 %47, %48
  br label %cond.end40.i

cond.end40.i:                                     ; preds = %cond.false36.i, %cond.true34.i
  %cond41.i = phi i32 [ %add35.i, %cond.true34.i ], [ %add39.i, %cond.false36.i ]
  store i32 %cond41.i, i32* %highJ.i, align 4, !noalias !1
  %49 = load i32, i32* %15, align 4
  store i32 %49, i32* %k.i, align 4, !noalias !1
  br label %for.cond.i

for.cond.i:                                       ; preds = %for.end142.i, %cond.end40.i
  %50 = load i32, i32* %k.i, align 4, !noalias !1
  %51 = load i32, i32* %highK.i, align 4, !noalias !1
  %cmp42.i = icmp slt i32 %50, %51
  br i1 %cmp42.i, label %for.body.i, label %.omp_outlined..7.exit

for.body.i:                                       ; preds = %for.cond.i
  %52 = load i32, i32* %18, align 4
  store i32 %52, i32* %j.i, align 4, !noalias !1
  br label %for.cond43.i

for.cond43.i:                                     ; preds = %for.end.i, %for.body.i
  %53 = load i32, i32* %j.i, align 4, !noalias !1
  %54 = load i32, i32* %highJ.i, align 4, !noalias !1
  %cmp44.i = icmp slt i32 %53, %54
  br i1 %cmp44.i, label %for.body45.i, label %for.end142.i

for.body45.i:                                     ; preds = %for.cond43.i
  %55 = load i32, i32* %17, align 4
  %sub.i = sub nsw i32 0, %55
  store i32 %sub.i, i32* %i.i, align 4, !noalias !1
  br label %for.cond46.i

for.cond46.i:                                     ; preds = %if.end.i, %for.body45.i
  %56 = load i32, i32* %i.i, align 4, !noalias !1
  %57 = load %struct.box_type*, %struct.box_type** %16, align 8
  %dim47.i = getelementptr inbounds %struct.box_type, %struct.box_type* %57, i32 0, i32 2
  %i48.i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47.i, i32 0, i32 0
  %58 = load i32, i32* %i48.i, align 4
  %59 = load i32, i32* %17, align 4
  %add49.i = add nsw i32 %58, %59
  %cmp50.i = icmp slt i32 %56, %add49.i
  br i1 %cmp50.i, label %for.body51.i, label %for.end.i

for.body51.i:                                     ; preds = %for.cond46.i
  %60 = load i32, i32* %i.i, align 4, !noalias !1
  %61 = load i32, i32* %j.i, align 4, !noalias !1
  %xor.i = xor i32 %60, %61
  %62 = load i32, i32* %k.i, align 4, !noalias !1
  %xor52.i = xor i32 %xor.i, %62
  %63 = load i32, i32* %19, align 4
  %xor53.i = xor i32 %xor52.i, %63
  %xor54.i = xor i32 %xor53.i, 1
  %and.i = and i32 %xor54.i, 1
  %tobool.i = icmp ne i32 %and.i, 0
  br i1 %tobool.i, label %if.then.i, label %if.end.i

if.then.i:                                        ; preds = %for.body51.i
  %64 = load i32, i32* %i.i, align 4, !noalias !1
  %65 = load i32, i32* %j.i, align 4, !noalias !1
  %66 = load i32, i32* %20, align 4
  %mul.i = mul nsw i32 %65, %66
  %add56.i = add nsw i32 %64, %mul.i
  %67 = load i32, i32* %k.i, align 4, !noalias !1
  %68 = load i32, i32* %21, align 4
  %mul57.i = mul nsw i32 %67, %68
  %add58.i = add nsw i32 %add56.i, %mul57.i
  store i32 %add58.i, i32* %ijk.i, align 4, !noalias !1
  %69 = load double, double* %22, align 8
  %70 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom.i = sext i32 %70 to i64
  %71 = load double*, double** %23, align 8
  %arrayidx.i = getelementptr inbounds double, double* %71, i64 %idxprom.i
  %72 = load double, double* %arrayidx.i, align 8
  %mul60.i = fmul double %69, %72
  %73 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom61.i = sext i32 %73 to i64
  %74 = load double*, double** %24, align 8
  %arrayidx62.i = getelementptr inbounds double, double* %74, i64 %idxprom61.i
  %75 = load double, double* %arrayidx62.i, align 8
  %mul63.i = fmul double %mul60.i, %75
  %76 = load double, double* %25, align 8
  %77 = load double, double* %26, align 8
  %mul64.i = fmul double %76, %77
  %78 = load i32, i32* %ijk.i, align 4, !noalias !1
  %add65.i = add nsw i32 %78, 1
  %idxprom66.i = sext i32 %add65.i to i64
  %79 = load double*, double** %27, align 8
  %arrayidx67.i = getelementptr inbounds double, double* %79, i64 %idxprom66.i
  %80 = load double, double* %arrayidx67.i, align 8
  %81 = load i32, i32* %ijk.i, align 4, !noalias !1
  %add68.i = add nsw i32 %81, 1
  %idxprom69.i = sext i32 %add68.i to i64
  %82 = load double*, double** %24, align 8
  %arrayidx70.i = getelementptr inbounds double, double* %82, i64 %idxprom69.i
  %83 = load double, double* %arrayidx70.i, align 8
  %84 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom71.i = sext i32 %84 to i64
  %85 = load double*, double** %24, align 8
  %arrayidx72.i = getelementptr inbounds double, double* %85, i64 %idxprom71.i
  %86 = load double, double* %arrayidx72.i, align 8
  %sub73.i = fsub double %83, %86
  %mul74.i = fmul double %80, %sub73.i
  %87 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom75.i = sext i32 %87 to i64
  %88 = load double*, double** %27, align 8
  %arrayidx76.i = getelementptr inbounds double, double* %88, i64 %idxprom75.i
  %89 = load double, double* %arrayidx76.i, align 8
  %90 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom77.i = sext i32 %90 to i64
  %91 = load double*, double** %24, align 8
  %arrayidx78.i = getelementptr inbounds double, double* %91, i64 %idxprom77.i
  %92 = load double, double* %arrayidx78.i, align 8
  %93 = load i32, i32* %ijk.i, align 4, !noalias !1
  %sub79.i = sub nsw i32 %93, 1
  %idxprom80.i = sext i32 %sub79.i to i64
  %94 = load double*, double** %24, align 8
  %arrayidx81.i = getelementptr inbounds double, double* %94, i64 %idxprom80.i
  %95 = load double, double* %arrayidx81.i, align 8
  %sub82.i = fsub double %92, %95
  %mul83.i = fmul double %89, %sub82.i
  %sub84.i = fsub double %mul74.i, %mul83.i
  %96 = load i32, i32* %ijk.i, align 4, !noalias !1
  %97 = load i32, i32* %20, align 4
  %add85.i = add nsw i32 %96, %97
  %idxprom86.i = sext i32 %add85.i to i64
  %98 = load double*, double** %28, align 8
  %arrayidx87.i = getelementptr inbounds double, double* %98, i64 %idxprom86.i
  %99 = load double, double* %arrayidx87.i, align 8
  %100 = load i32, i32* %ijk.i, align 4, !noalias !1
  %101 = load i32, i32* %20, align 4
  %add88.i = add nsw i32 %100, %101
  %idxprom89.i = sext i32 %add88.i to i64
  %102 = load double*, double** %24, align 8
  %arrayidx90.i = getelementptr inbounds double, double* %102, i64 %idxprom89.i
  %103 = load double, double* %arrayidx90.i, align 8
  %104 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom91.i = sext i32 %104 to i64
  %105 = load double*, double** %24, align 8
  %arrayidx92.i = getelementptr inbounds double, double* %105, i64 %idxprom91.i
  %106 = load double, double* %arrayidx92.i, align 8
  %sub93.i = fsub double %103, %106
  %mul94.i = fmul double %99, %sub93.i
  %add95.i = fadd double %sub84.i, %mul94.i
  %107 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom96.i = sext i32 %107 to i64
  %108 = load double*, double** %28, align 8
  %arrayidx97.i = getelementptr inbounds double, double* %108, i64 %idxprom96.i
  %109 = load double, double* %arrayidx97.i, align 8
  %110 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom98.i = sext i32 %110 to i64
  %111 = load double*, double** %24, align 8
  %arrayidx99.i = getelementptr inbounds double, double* %111, i64 %idxprom98.i
  %112 = load double, double* %arrayidx99.i, align 8
  %113 = load i32, i32* %ijk.i, align 4, !noalias !1
  %114 = load i32, i32* %20, align 4
  %sub100.i = sub nsw i32 %113, %114
  %idxprom101.i = sext i32 %sub100.i to i64
  %115 = load double*, double** %24, align 8
  %arrayidx102.i = getelementptr inbounds double, double* %115, i64 %idxprom101.i
  %116 = load double, double* %arrayidx102.i, align 8
  %sub103.i = fsub double %112, %116
  %mul104.i = fmul double %109, %sub103.i
  %sub105.i = fsub double %add95.i, %mul104.i
  %117 = load i32, i32* %ijk.i, align 4, !noalias !1
  %118 = load i32, i32* %21, align 4
  %add106.i = add nsw i32 %117, %118
  %idxprom107.i = sext i32 %add106.i to i64
  %119 = load double*, double** %29, align 8
  %arrayidx108.i = getelementptr inbounds double, double* %119, i64 %idxprom107.i
  %120 = load double, double* %arrayidx108.i, align 8
  %121 = load i32, i32* %ijk.i, align 4, !noalias !1
  %122 = load i32, i32* %21, align 4
  %add109.i = add nsw i32 %121, %122
  %idxprom110.i = sext i32 %add109.i to i64
  %123 = load double*, double** %24, align 8
  %arrayidx111.i = getelementptr inbounds double, double* %123, i64 %idxprom110.i
  %124 = load double, double* %arrayidx111.i, align 8
  %125 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom112.i = sext i32 %125 to i64
  %126 = load double*, double** %24, align 8
  %arrayidx113.i = getelementptr inbounds double, double* %126, i64 %idxprom112.i
  %127 = load double, double* %arrayidx113.i, align 8
  %sub114.i = fsub double %124, %127
  %mul115.i = fmul double %120, %sub114.i
  %add116.i = fadd double %sub105.i, %mul115.i
  %128 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom117.i = sext i32 %128 to i64
  %129 = load double*, double** %29, align 8
  %arrayidx118.i = getelementptr inbounds double, double* %129, i64 %idxprom117.i
  %130 = load double, double* %arrayidx118.i, align 8
  %131 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom119.i = sext i32 %131 to i64
  %132 = load double*, double** %24, align 8
  %arrayidx120.i = getelementptr inbounds double, double* %132, i64 %idxprom119.i
  %133 = load double, double* %arrayidx120.i, align 8
  %134 = load i32, i32* %ijk.i, align 4, !noalias !1
  %135 = load i32, i32* %21, align 4
  %sub121.i = sub nsw i32 %134, %135
  %idxprom122.i = sext i32 %sub121.i to i64
  %136 = load double*, double** %24, align 8
  %arrayidx123.i = getelementptr inbounds double, double* %136, i64 %idxprom122.i
  %137 = load double, double* %arrayidx123.i, align 8
  %sub124.i = fsub double %133, %137
  %mul125.i = fmul double %130, %sub124.i
  %sub126.i = fsub double %add116.i, %mul125.i
  %mul127.i = fmul double %mul64.i, %sub126.i
  %sub128.i = fsub double %mul63.i, %mul127.i
  store double %sub128.i, double* %helmholtz.i, align 8, !noalias !1
  %138 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom129.i = sext i32 %138 to i64
  %139 = load double*, double** %24, align 8
  %arrayidx130.i = getelementptr inbounds double, double* %139, i64 %idxprom129.i
  %140 = load double, double* %arrayidx130.i, align 8
  %141 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom131.i = sext i32 %141 to i64
  %142 = load double*, double** %31, align 8
  %arrayidx132.i = getelementptr inbounds double, double* %142, i64 %idxprom131.i
  %143 = load double, double* %arrayidx132.i, align 8
  %144 = load double, double* %helmholtz.i, align 8, !noalias !1
  %145 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom133.i = sext i32 %145 to i64
  %146 = load double*, double** %32, align 8
  %arrayidx134.i = getelementptr inbounds double, double* %146, i64 %idxprom133.i
  %147 = load double, double* %arrayidx134.i, align 8
  %sub135.i = fsub double %144, %147
  %mul136.i = fmul double %143, %sub135.i
  %sub137.i = fsub double %140, %mul136.i
  %148 = load i32, i32* %ijk.i, align 4, !noalias !1
  %idxprom138.i = sext i32 %148 to i64
  %149 = load double*, double** %30, align 8
  %arrayidx139.i = getelementptr inbounds double, double* %149, i64 %idxprom138.i
  store double %sub137.i, double* %arrayidx139.i, align 8
  br label %if.end.i

if.end.i:                                         ; preds = %if.then.i, %for.body51.i
  %150 = load i32, i32* %i.i, align 4, !noalias !1
  %inc.i = add nsw i32 %150, 1
  store i32 %inc.i, i32* %i.i, align 4, !noalias !1
  br label %for.cond46.i

for.end.i:                                        ; preds = %for.cond46.i
  %151 = load i32, i32* %j.i, align 4, !noalias !1
  %inc141.i = add nsw i32 %151, 1
  store i32 %inc141.i, i32* %j.i, align 4, !noalias !1
  br label %for.cond43.i

for.end142.i:                                     ; preds = %for.cond43.i
  %152 = load i32, i32* %k.i, align 4, !noalias !1
  %inc144.i = add nsw i32 %152, 1
  store i32 %inc144.i, i32* %k.i, align 4, !noalias !1
  br label %for.cond.i

.omp_outlined..7.exit:                            ; preds = %for.cond.i
  ret i32 0
}

declare i8* @__kmpc_omp_task_alloc(%ident_t*, i32, i32, i64, i64, i32 (i32, i8*)*)

declare i32 @__kmpc_omp_task(%ident_t*, i32, i8*)

declare void @__kmpc_omp_task_begin_if0(%ident_t*, i32, i8*)

declare void @__kmpc_omp_task_complete_if0(%ident_t*, i32, i8*)

declare i32 @__kmpc_omp_taskwait(%ident_t*, i32)

; Function Attrs: nounwind uwtable
define void @smooth(%struct.domain_type* %domain, i32 %level, i32 %phi_id, i32 %rhs_id, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %phi_id.addr = alloca i32, align 4
  %rhs_id.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %box = alloca i32, align 4
  %s = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %phi_id, i32* %phi_id.addr, align 4
  store i32 %rhs_id, i32* %rhs_id.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  %0 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %ghosts1 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %0, i32 0, i32 22
  %1 = load i32, i32* %ghosts1, align 4
  store i32 %1, i32* %ghosts, align 4
  %2 = load i32, i32* %ghosts, align 4
  %cmp = icmp sgt i32 %2, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %3 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %4 = load i32, i32* %level.addr, align 4
  %5 = load i32, i32* %rhs_id.addr, align 4
  call void @exchange_boundary(%struct.domain_type* %3, i32 %4, i32 %5, i32 1, i32 1, i32 1)
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  store i32 0, i32* %s, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end
  %6 = load i32, i32* %s, align 4
  %cmp2 = icmp slt i32 %6, 4
  br i1 %cmp2, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %7 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %8 = load i32, i32* %level.addr, align 4
  %9 = load i32, i32* %phi_id.addr, align 4
  %10 = load i32, i32* %ghosts, align 4
  %cmp3 = icmp sgt i32 %10, 1
  %conv = zext i1 %cmp3 to i32
  %11 = load i32, i32* %ghosts, align 4
  %cmp4 = icmp sgt i32 %11, 1
  %conv5 = zext i1 %cmp4 to i32
  call void @exchange_boundary(%struct.domain_type* %7, i32 %8, i32 %9, i32 1, i32 %conv, i32 %conv5)
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, double*, double*, i32*)* @.omp_outlined..8 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %phi_id.addr, i32* %rhs_id.addr, double* %a.addr, double* %b.addr, i32* %s)
  %call6 = call i64 (...) @CycleTime()
  %12 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call6, %12
  %13 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %13 to i64
  %14 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %14, i32 0, i32 0
  %smooth = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 0
  %arrayidx = getelementptr inbounds [10 x i64], [10 x i64]* %smooth, i64 0, i64 %idxprom
  %15 = load i64, i64* %arrayidx, align 8
  %add = add i64 %15, %sub
  store i64 %add, i64* %arrayidx, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %16 = load i32, i32* %ghosts, align 4
  %17 = load i32, i32* %s, align 4
  %add7 = add nsw i32 %17, %16
  store i32 %add7, i32* %s, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..8(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %phi_id, i32* dereferenceable(4) %rhs_id, double* dereferenceable(8) %a, double* dereferenceable(8) %b, i32* dereferenceable(4) %s) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %phi_id.addr = alloca i32*, align 8
  %rhs_id.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %b.addr = alloca double*, align 8
  %s.addr = alloca i32*, align 8
  %box = alloca i32, align 4
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box3 = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box5 = alloca i32, align 4
  %box6 = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %phi_id, i32** %phi_id.addr, align 8
  store i32* %rhs_id, i32** %rhs_id.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %b, double** %b.addr, align 8
  store i32* %s, i32** %s.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %phi_id.addr, align 8
  %3 = load i32*, i32** %rhs_id.addr, align 8
  %4 = load double*, double** %a.addr, align 8
  %5 = load double*, double** %b.addr, align 8
  %6 = load i32*, i32** %s.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box3, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank4 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank4, align 8
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %11 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %11, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %14 = load i32, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.last.iteration, align 4
  %cmp7 = icmp sgt i32 %14, %15
  br i1 %cmp7, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %16, %cond.true ], [ %17, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %18 = load i32, i32* %.omp.lb, align 4
  store i32 %18, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i32, i32* %.omp.iv, align 4
  %20 = load i32, i32* %.omp.ub, align 4
  %cmp8 = icmp sle i32 %19, %20
  br i1 %cmp8, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %21, 1
  %add9 = add nsw i32 0, %mul
  store i32 %add9, i32* %box5, align 4
  %22 = load i32, i32* %1, align 4
  %idxprom = sext i32 %22 to i64
  %23 = load i32, i32* %box5, align 4
  %idxprom10 = sext i32 %23 to i64
  %24 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %24, i32 0, i32 25
  %25 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %25, i64 %idxprom10
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %26 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx11 = getelementptr inbounds %struct.box_type, %struct.box_type* %26, i64 %idxprom
  %27 = load i32, i32* %2, align 4
  %28 = load i32, i32* %3, align 4
  %29 = load double, double* %4, align 8
  %30 = load double, double* %5, align 8
  %31 = load i32, i32* %6, align 4
  call void @__box_smooth_GSRB_multiple(%struct.box_type* %arrayidx11, i32 %27, i32 %28, double %29, double %30, i32 %31)
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp.inner.for.body
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %32 = load i32, i32* %.omp.iv, align 4
  %add12 = add nsw i32 %32, 1
  store i32 %add12, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %33 = load i32*, i32** %.global_tid..addr, align 8
  %34 = load i32, i32* %33, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %34)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @apply_op(%struct.domain_type* %domain, i32 %level, i32 %Ax_id, i32 %x_id, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %Ax_id.addr = alloca i32, align 4
  %x_id.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %Ax_id, i32* %Ax_id.addr, align 4
  store i32 %x_id, i32* %x_id.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  %1 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %2 = load i32, i32* %level.addr, align 4
  %3 = load i32, i32* %x_id.addr, align 4
  call void @exchange_boundary(%struct.domain_type* %1, i32 %2, i32 %3, i32 1, i32 0, i32 0)
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %4 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %4 to i64
  %5 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 25
  %6 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %6, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %7 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %7, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %8 = load i32, i32* %i, align 4
  %9 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %8, %9
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %10 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %10 to i64
  %11 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %11, i32 0, i32 25
  %12 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %12, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %13 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %13, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %14 = load i32, i32* %i8, align 4
  %15 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %14, %15
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %16 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %16, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, double*, double*)* @.omp_outlined..9 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %x_id.addr, i32* %Ax_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..9(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %x_id.addr, i32* %Ax_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %17 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %17
  %18 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %18 to i64
  %19 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %19, i32 0, i32 0
  %apply_op = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 1
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %apply_op, i64 0, i64 %idxprom12
  %20 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %20, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..9(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %x_id, i32* dereferenceable(4) %Ax_id, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %a, double* dereferenceable(8) %b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %x_id.addr = alloca i32*, align 8
  %Ax_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %b.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %s = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %h2inv = alloca double, align 8
  %x = alloca double*, align 8
  %Ax = alloca double*, align 8
  %alpha = alloca double*, align 8
  %beta_i = alloca double*, align 8
  %beta_j = alloca double*, align 8
  %beta_k = alloca double*, align 8
  %lambda = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %x_id, i32** %x_id.addr, align 8
  store i32* %Ax_id, i32** %Ax_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %b, double** %b.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %x_id.addr, align 8
  %3 = load i32*, i32** %Ax_id.addr, align 8
  %4 = load i32*, i32** %omp_within_a_box.addr, align 8
  %5 = load double*, double** %a.addr, align 8
  %6 = load double*, double** %b.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %11 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %11, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %14 = load i32, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %14, %15
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %16, %cond.true ], [ %17, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %18 = load i32, i32* %.omp.lb, align 4
  store i32 %18, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i32, i32* %.omp.iv, align 4
  %20 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %19, %20
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %21, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %22 = load i32, i32* %1, align 4
  %idxprom = sext i32 %22 to i64
  %23 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %23 to i64
  %24 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %24, i32 0, i32 25
  %25 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %25, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %26 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %26, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %27 = load i32, i32* %pencil11, align 8
  store i32 %27, i32* %pencil, align 4
  %28 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %28 to i64
  %29 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %29 to i64
  %30 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %30, i32 0, i32 25
  %31 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %31, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %32 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %32, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %33 = load i32, i32* %plane18, align 4
  store i32 %33, i32* %plane, align 4
  %34 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %34 to i64
  %35 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %35 to i64
  %36 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %36, i32 0, i32 25
  %37 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %37, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %38 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %39 = load i32, i32* %ghosts25, align 4
  store i32 %39, i32* %ghosts, align 4
  %40 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %40 to i64
  %41 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %41 to i64
  %42 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %42, i32 0, i32 25
  %43 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %43, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %44 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %44, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %45 = load i32, i32* %k32, align 4
  store i32 %45, i32* %dim_k, align 4
  %46 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %46 to i64
  %47 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %47 to i64
  %48 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %48, i32 0, i32 25
  %49 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %49, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %50 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %50, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %51 = load i32, i32* %j40, align 4
  store i32 %51, i32* %dim_j, align 4
  %52 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %52 to i64
  %53 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %53 to i64
  %54 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %54, i32 0, i32 25
  %55 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %55, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %56 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %56, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %57 = load i32, i32* %i48, align 4
  store i32 %57, i32* %dim_i, align 4
  %58 = load i32, i32* %1, align 4
  %idxprom49 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 23
  %arrayidx50 = getelementptr inbounds [10 x double], [10 x double]* %h, i64 0, i64 %idxprom49
  %60 = load double, double* %arrayidx50, align 8
  %61 = load i32, i32* %1, align 4
  %idxprom51 = sext i32 %61 to i64
  %62 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %62, i32 0, i32 23
  %arrayidx53 = getelementptr inbounds [10 x double], [10 x double]* %h52, i64 0, i64 %idxprom51
  %63 = load double, double* %arrayidx53, align 8
  %mul54 = fmul double %60, %63
  %div55 = fdiv double 1.000000e+00, %mul54
  store double %div55, double* %h2inv, align 8
  %64 = load i32, i32* %2, align 4
  %idxprom56 = sext i32 %64 to i64
  %65 = load i32, i32* %1, align 4
  %idxprom57 = sext i32 %65 to i64
  %66 = load i32, i32* %box4, align 4
  %idxprom58 = sext i32 %66 to i64
  %67 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains59 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %67, i32 0, i32 25
  %68 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains59, align 8
  %arrayidx60 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %68, i64 %idxprom58
  %levels61 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx60, i32 0, i32 5
  %69 = load %struct.box_type*, %struct.box_type** %levels61, align 8
  %arrayidx62 = getelementptr inbounds %struct.box_type, %struct.box_type* %69, i64 %idxprom57
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx62, i32 0, i32 10
  %70 = load double**, double*** %grids, align 8
  %arrayidx63 = getelementptr inbounds double*, double** %70, i64 %idxprom56
  %71 = load double*, double** %arrayidx63, align 8
  %72 = load i32, i32* %ghosts, align 4
  %73 = load i32, i32* %pencil, align 4
  %add64 = add nsw i32 1, %73
  %74 = load i32, i32* %plane, align 4
  %add65 = add nsw i32 %add64, %74
  %mul66 = mul nsw i32 %72, %add65
  %idx.ext = sext i32 %mul66 to i64
  %add.ptr = getelementptr inbounds double, double* %71, i64 %idx.ext
  store double* %add.ptr, double** %x, align 8
  %75 = load i32, i32* %3, align 4
  %idxprom67 = sext i32 %75 to i64
  %76 = load i32, i32* %1, align 4
  %idxprom68 = sext i32 %76 to i64
  %77 = load i32, i32* %box4, align 4
  %idxprom69 = sext i32 %77 to i64
  %78 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains70 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %78, i32 0, i32 25
  %79 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains70, align 8
  %arrayidx71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %79, i64 %idxprom69
  %levels72 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx71, i32 0, i32 5
  %80 = load %struct.box_type*, %struct.box_type** %levels72, align 8
  %arrayidx73 = getelementptr inbounds %struct.box_type, %struct.box_type* %80, i64 %idxprom68
  %grids74 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx73, i32 0, i32 10
  %81 = load double**, double*** %grids74, align 8
  %arrayidx75 = getelementptr inbounds double*, double** %81, i64 %idxprom67
  %82 = load double*, double** %arrayidx75, align 8
  %83 = load i32, i32* %ghosts, align 4
  %84 = load i32, i32* %pencil, align 4
  %add76 = add nsw i32 1, %84
  %85 = load i32, i32* %plane, align 4
  %add77 = add nsw i32 %add76, %85
  %mul78 = mul nsw i32 %83, %add77
  %idx.ext79 = sext i32 %mul78 to i64
  %add.ptr80 = getelementptr inbounds double, double* %82, i64 %idx.ext79
  store double* %add.ptr80, double** %Ax, align 8
  %86 = load i32, i32* %1, align 4
  %idxprom81 = sext i32 %86 to i64
  %87 = load i32, i32* %box4, align 4
  %idxprom82 = sext i32 %87 to i64
  %88 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains83 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %88, i32 0, i32 25
  %89 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains83, align 8
  %arrayidx84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %89, i64 %idxprom82
  %levels85 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx84, i32 0, i32 5
  %90 = load %struct.box_type*, %struct.box_type** %levels85, align 8
  %arrayidx86 = getelementptr inbounds %struct.box_type, %struct.box_type* %90, i64 %idxprom81
  %grids87 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx86, i32 0, i32 10
  %91 = load double**, double*** %grids87, align 8
  %arrayidx88 = getelementptr inbounds double*, double** %91, i64 2
  %92 = load double*, double** %arrayidx88, align 8
  %93 = load i32, i32* %ghosts, align 4
  %94 = load i32, i32* %pencil, align 4
  %add89 = add nsw i32 1, %94
  %95 = load i32, i32* %plane, align 4
  %add90 = add nsw i32 %add89, %95
  %mul91 = mul nsw i32 %93, %add90
  %idx.ext92 = sext i32 %mul91 to i64
  %add.ptr93 = getelementptr inbounds double, double* %92, i64 %idx.ext92
  store double* %add.ptr93, double** %alpha, align 8
  %96 = load i32, i32* %1, align 4
  %idxprom94 = sext i32 %96 to i64
  %97 = load i32, i32* %box4, align 4
  %idxprom95 = sext i32 %97 to i64
  %98 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains96 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %98, i32 0, i32 25
  %99 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains96, align 8
  %arrayidx97 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %99, i64 %idxprom95
  %levels98 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx97, i32 0, i32 5
  %100 = load %struct.box_type*, %struct.box_type** %levels98, align 8
  %arrayidx99 = getelementptr inbounds %struct.box_type, %struct.box_type* %100, i64 %idxprom94
  %grids100 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx99, i32 0, i32 10
  %101 = load double**, double*** %grids100, align 8
  %arrayidx101 = getelementptr inbounds double*, double** %101, i64 5
  %102 = load double*, double** %arrayidx101, align 8
  %103 = load i32, i32* %ghosts, align 4
  %104 = load i32, i32* %pencil, align 4
  %add102 = add nsw i32 1, %104
  %105 = load i32, i32* %plane, align 4
  %add103 = add nsw i32 %add102, %105
  %mul104 = mul nsw i32 %103, %add103
  %idx.ext105 = sext i32 %mul104 to i64
  %add.ptr106 = getelementptr inbounds double, double* %102, i64 %idx.ext105
  store double* %add.ptr106, double** %beta_i, align 8
  %106 = load i32, i32* %1, align 4
  %idxprom107 = sext i32 %106 to i64
  %107 = load i32, i32* %box4, align 4
  %idxprom108 = sext i32 %107 to i64
  %108 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains109 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %108, i32 0, i32 25
  %109 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains109, align 8
  %arrayidx110 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %109, i64 %idxprom108
  %levels111 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx110, i32 0, i32 5
  %110 = load %struct.box_type*, %struct.box_type** %levels111, align 8
  %arrayidx112 = getelementptr inbounds %struct.box_type, %struct.box_type* %110, i64 %idxprom107
  %grids113 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx112, i32 0, i32 10
  %111 = load double**, double*** %grids113, align 8
  %arrayidx114 = getelementptr inbounds double*, double** %111, i64 6
  %112 = load double*, double** %arrayidx114, align 8
  %113 = load i32, i32* %ghosts, align 4
  %114 = load i32, i32* %pencil, align 4
  %add115 = add nsw i32 1, %114
  %115 = load i32, i32* %plane, align 4
  %add116 = add nsw i32 %add115, %115
  %mul117 = mul nsw i32 %113, %add116
  %idx.ext118 = sext i32 %mul117 to i64
  %add.ptr119 = getelementptr inbounds double, double* %112, i64 %idx.ext118
  store double* %add.ptr119, double** %beta_j, align 8
  %116 = load i32, i32* %1, align 4
  %idxprom120 = sext i32 %116 to i64
  %117 = load i32, i32* %box4, align 4
  %idxprom121 = sext i32 %117 to i64
  %118 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains122 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %118, i32 0, i32 25
  %119 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains122, align 8
  %arrayidx123 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %119, i64 %idxprom121
  %levels124 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx123, i32 0, i32 5
  %120 = load %struct.box_type*, %struct.box_type** %levels124, align 8
  %arrayidx125 = getelementptr inbounds %struct.box_type, %struct.box_type* %120, i64 %idxprom120
  %grids126 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx125, i32 0, i32 10
  %121 = load double**, double*** %grids126, align 8
  %arrayidx127 = getelementptr inbounds double*, double** %121, i64 7
  %122 = load double*, double** %arrayidx127, align 8
  %123 = load i32, i32* %ghosts, align 4
  %124 = load i32, i32* %pencil, align 4
  %add128 = add nsw i32 1, %124
  %125 = load i32, i32* %plane, align 4
  %add129 = add nsw i32 %add128, %125
  %mul130 = mul nsw i32 %123, %add129
  %idx.ext131 = sext i32 %mul130 to i64
  %add.ptr132 = getelementptr inbounds double, double* %122, i64 %idx.ext131
  store double* %add.ptr132, double** %beta_k, align 8
  %126 = load i32, i32* %1, align 4
  %idxprom133 = sext i32 %126 to i64
  %127 = load i32, i32* %box4, align 4
  %idxprom134 = sext i32 %127 to i64
  %128 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains135 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %128, i32 0, i32 25
  %129 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains135, align 8
  %arrayidx136 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %129, i64 %idxprom134
  %levels137 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx136, i32 0, i32 5
  %130 = load %struct.box_type*, %struct.box_type** %levels137, align 8
  %arrayidx138 = getelementptr inbounds %struct.box_type, %struct.box_type* %130, i64 %idxprom133
  %grids139 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx138, i32 0, i32 10
  %131 = load double**, double*** %grids139, align 8
  %arrayidx140 = getelementptr inbounds double*, double** %131, i64 4
  %132 = load double*, double** %arrayidx140, align 8
  %133 = load i32, i32* %ghosts, align 4
  %134 = load i32, i32* %pencil, align 4
  %add141 = add nsw i32 1, %134
  %135 = load i32, i32* %plane, align 4
  %add142 = add nsw i32 %add141, %135
  %mul143 = mul nsw i32 %133, %add142
  %idx.ext144 = sext i32 %mul143 to i64
  %add.ptr145 = getelementptr inbounds double, double* %132, i64 %idx.ext144
  store double* %add.ptr145, double** %lambda, align 8
  %136 = load i32, i32* %4, align 4
  %tobool = icmp ne i32 %136, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 14, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double**, double**, double*, double*, double**, double**, double**, double**)* @.omp_outlined..10 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %5, double** %alpha, double** %x, double* %6, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %Ax)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %137 = load i32*, i32** %.global_tid..addr, align 8
  %138 = load i32, i32* %137, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %138)
  %139 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..10(i32* %139, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %5, double** %alpha, double** %x, double* %6, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %Ax)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %138)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %140 = load i32, i32* %.omp.iv, align 4
  %add146 = add nsw i32 %140, 1
  store i32 %add146, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %141 = load i32*, i32** %.global_tid..addr, align 8
  %142 = load i32, i32* %141, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %142)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..10(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %a, double** dereferenceable(8) %alpha, double** dereferenceable(8) %x, double* dereferenceable(8) %b, double* dereferenceable(8) %h2inv, double** dereferenceable(8) %beta_i, double** dereferenceable(8) %beta_j, double** dereferenceable(8) %beta_k, double** dereferenceable(8) %Ax) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %alpha.addr = alloca double**, align 8
  %x.addr = alloca double**, align 8
  %b.addr = alloca double*, align 8
  %h2inv.addr = alloca double*, align 8
  %beta_i.addr = alloca double**, align 8
  %beta_j.addr = alloca double**, align 8
  %beta_k.addr = alloca double**, align 8
  %Ax.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %helmholtz = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double** %alpha, double*** %alpha.addr, align 8
  store double** %x, double*** %x.addr, align 8
  store double* %b, double** %b.addr, align 8
  store double* %h2inv, double** %h2inv.addr, align 8
  store double** %beta_i, double*** %beta_i.addr, align 8
  store double** %beta_j, double*** %beta_j.addr, align 8
  store double** %beta_k, double*** %beta_k.addr, align 8
  store double** %Ax, double*** %Ax.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %a.addr, align 8
  %6 = load double**, double*** %alpha.addr, align 8
  %7 = load double**, double*** %x.addr, align 8
  %8 = load double*, double** %b.addr, align 8
  %9 = load double*, double** %h2inv.addr, align 8
  %10 = load double**, double*** %beta_i.addr, align 8
  %11 = load double**, double*** %beta_j.addr, align 8
  %12 = load double**, double*** %beta_k.addr, align 8
  %13 = load double**, double*** %Ax.addr, align 8
  %14 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %14, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %15 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %15, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %16 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %16
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %17 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %17
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %18 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %18, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %19 = load i32*, i32** %.global_tid..addr, align 8
  %20 = load i32, i32* %19, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %20, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %21 = load i64, i64* %.omp.ub, align 8
  %22 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %21, %22
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %23 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %24 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %23, %cond.true ], [ %24, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %25 = load i64, i64* %.omp.lb, align 8
  store i64 %25, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %26, %27
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %28 = load i64, i64* %.omp.iv, align 8
  %29 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %29, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %28, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %30 = load i64, i64* %.omp.iv, align 8
  %31 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %31, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %30, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %32 = load i32, i32* %i, align 4
  %33 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %32, %33
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %34 = load i32, i32* %i, align 4
  %35 = load i32, i32* %j14, align 4
  %36 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %35, %36
  %add41 = add nsw i32 %34, %mul40
  %37 = load i32, i32* %k13, align 4
  %38 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %37, %38
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %39 = load double, double* %5, align 8
  %40 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %40 to i64
  %41 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %41, i64 %idxprom
  %42 = load double, double* %arrayidx, align 8
  %mul44 = fmul double %39, %42
  %43 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %43 to i64
  %44 = load double*, double** %7, align 8
  %arrayidx46 = getelementptr inbounds double, double* %44, i64 %idxprom45
  %45 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %mul44, %45
  %46 = load double, double* %8, align 8
  %47 = load double, double* %9, align 8
  %mul48 = fmul double %46, %47
  %48 = load i32, i32* %ijk, align 4
  %add49 = add nsw i32 %48, 1
  %idxprom50 = sext i32 %add49 to i64
  %49 = load double*, double** %10, align 8
  %arrayidx51 = getelementptr inbounds double, double* %49, i64 %idxprom50
  %50 = load double, double* %arrayidx51, align 8
  %51 = load i32, i32* %ijk, align 4
  %add52 = add nsw i32 %51, 1
  %idxprom53 = sext i32 %add52 to i64
  %52 = load double*, double** %7, align 8
  %arrayidx54 = getelementptr inbounds double, double* %52, i64 %idxprom53
  %53 = load double, double* %arrayidx54, align 8
  %54 = load i32, i32* %ijk, align 4
  %idxprom55 = sext i32 %54 to i64
  %55 = load double*, double** %7, align 8
  %arrayidx56 = getelementptr inbounds double, double* %55, i64 %idxprom55
  %56 = load double, double* %arrayidx56, align 8
  %sub57 = fsub double %53, %56
  %mul58 = fmul double %50, %sub57
  %57 = load i32, i32* %ijk, align 4
  %idxprom59 = sext i32 %57 to i64
  %58 = load double*, double** %10, align 8
  %arrayidx60 = getelementptr inbounds double, double* %58, i64 %idxprom59
  %59 = load double, double* %arrayidx60, align 8
  %60 = load i32, i32* %ijk, align 4
  %idxprom61 = sext i32 %60 to i64
  %61 = load double*, double** %7, align 8
  %arrayidx62 = getelementptr inbounds double, double* %61, i64 %idxprom61
  %62 = load double, double* %arrayidx62, align 8
  %63 = load i32, i32* %ijk, align 4
  %sub63 = sub nsw i32 %63, 1
  %idxprom64 = sext i32 %sub63 to i64
  %64 = load double*, double** %7, align 8
  %arrayidx65 = getelementptr inbounds double, double* %64, i64 %idxprom64
  %65 = load double, double* %arrayidx65, align 8
  %sub66 = fsub double %62, %65
  %mul67 = fmul double %59, %sub66
  %sub68 = fsub double %mul58, %mul67
  %66 = load i32, i32* %ijk, align 4
  %67 = load i32, i32* %3, align 4
  %add69 = add nsw i32 %66, %67
  %idxprom70 = sext i32 %add69 to i64
  %68 = load double*, double** %11, align 8
  %arrayidx71 = getelementptr inbounds double, double* %68, i64 %idxprom70
  %69 = load double, double* %arrayidx71, align 8
  %70 = load i32, i32* %ijk, align 4
  %71 = load i32, i32* %3, align 4
  %add72 = add nsw i32 %70, %71
  %idxprom73 = sext i32 %add72 to i64
  %72 = load double*, double** %7, align 8
  %arrayidx74 = getelementptr inbounds double, double* %72, i64 %idxprom73
  %73 = load double, double* %arrayidx74, align 8
  %74 = load i32, i32* %ijk, align 4
  %idxprom75 = sext i32 %74 to i64
  %75 = load double*, double** %7, align 8
  %arrayidx76 = getelementptr inbounds double, double* %75, i64 %idxprom75
  %76 = load double, double* %arrayidx76, align 8
  %sub77 = fsub double %73, %76
  %mul78 = fmul double %69, %sub77
  %add79 = fadd double %sub68, %mul78
  %77 = load i32, i32* %ijk, align 4
  %idxprom80 = sext i32 %77 to i64
  %78 = load double*, double** %11, align 8
  %arrayidx81 = getelementptr inbounds double, double* %78, i64 %idxprom80
  %79 = load double, double* %arrayidx81, align 8
  %80 = load i32, i32* %ijk, align 4
  %idxprom82 = sext i32 %80 to i64
  %81 = load double*, double** %7, align 8
  %arrayidx83 = getelementptr inbounds double, double* %81, i64 %idxprom82
  %82 = load double, double* %arrayidx83, align 8
  %83 = load i32, i32* %ijk, align 4
  %84 = load i32, i32* %3, align 4
  %sub84 = sub nsw i32 %83, %84
  %idxprom85 = sext i32 %sub84 to i64
  %85 = load double*, double** %7, align 8
  %arrayidx86 = getelementptr inbounds double, double* %85, i64 %idxprom85
  %86 = load double, double* %arrayidx86, align 8
  %sub87 = fsub double %82, %86
  %mul88 = fmul double %79, %sub87
  %sub89 = fsub double %add79, %mul88
  %87 = load i32, i32* %ijk, align 4
  %88 = load i32, i32* %4, align 4
  %add90 = add nsw i32 %87, %88
  %idxprom91 = sext i32 %add90 to i64
  %89 = load double*, double** %12, align 8
  %arrayidx92 = getelementptr inbounds double, double* %89, i64 %idxprom91
  %90 = load double, double* %arrayidx92, align 8
  %91 = load i32, i32* %ijk, align 4
  %92 = load i32, i32* %4, align 4
  %add93 = add nsw i32 %91, %92
  %idxprom94 = sext i32 %add93 to i64
  %93 = load double*, double** %7, align 8
  %arrayidx95 = getelementptr inbounds double, double* %93, i64 %idxprom94
  %94 = load double, double* %arrayidx95, align 8
  %95 = load i32, i32* %ijk, align 4
  %idxprom96 = sext i32 %95 to i64
  %96 = load double*, double** %7, align 8
  %arrayidx97 = getelementptr inbounds double, double* %96, i64 %idxprom96
  %97 = load double, double* %arrayidx97, align 8
  %sub98 = fsub double %94, %97
  %mul99 = fmul double %90, %sub98
  %add100 = fadd double %sub89, %mul99
  %98 = load i32, i32* %ijk, align 4
  %idxprom101 = sext i32 %98 to i64
  %99 = load double*, double** %12, align 8
  %arrayidx102 = getelementptr inbounds double, double* %99, i64 %idxprom101
  %100 = load double, double* %arrayidx102, align 8
  %101 = load i32, i32* %ijk, align 4
  %idxprom103 = sext i32 %101 to i64
  %102 = load double*, double** %7, align 8
  %arrayidx104 = getelementptr inbounds double, double* %102, i64 %idxprom103
  %103 = load double, double* %arrayidx104, align 8
  %104 = load i32, i32* %ijk, align 4
  %105 = load i32, i32* %4, align 4
  %sub105 = sub nsw i32 %104, %105
  %idxprom106 = sext i32 %sub105 to i64
  %106 = load double*, double** %7, align 8
  %arrayidx107 = getelementptr inbounds double, double* %106, i64 %idxprom106
  %107 = load double, double* %arrayidx107, align 8
  %sub108 = fsub double %103, %107
  %mul109 = fmul double %100, %sub108
  %sub110 = fsub double %add100, %mul109
  %mul111 = fmul double %mul48, %sub110
  %sub112 = fsub double %mul47, %mul111
  store double %sub112, double* %helmholtz, align 8
  %108 = load double, double* %helmholtz, align 8
  %109 = load i32, i32* %ijk, align 4
  %idxprom113 = sext i32 %109 to i64
  %110 = load double*, double** %13, align 8
  %arrayidx114 = getelementptr inbounds double, double* %110, i64 %idxprom113
  store double %108, double* %arrayidx114, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %111 = load i32, i32* %i, align 4
  %inc = add nsw i32 %111, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %112 = load i64, i64* %.omp.iv, align 8
  %add115 = add nsw i64 %112, 1
  store i64 %add115, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %113 = load i32*, i32** %.global_tid..addr, align 8
  %114 = load i32, i32* %113, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %114)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @residual(%struct.domain_type* %domain, i32 %level, i32 %res_id, i32 %phi_id, i32 %rhs_id, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %res_id.addr = alloca i32, align 4
  %phi_id.addr = alloca i32, align 4
  %rhs_id.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %res_id, i32* %res_id.addr, align 4
  store i32 %phi_id, i32* %phi_id.addr, align 4
  store i32 %rhs_id, i32* %rhs_id.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  %1 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %2 = load i32, i32* %level.addr, align 4
  %3 = load i32, i32* %phi_id.addr, align 4
  call void @exchange_boundary(%struct.domain_type* %1, i32 %2, i32 %3, i32 1, i32 0, i32 0)
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %4 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %4 to i64
  %5 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 25
  %6 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %6, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %7 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %7, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %8 = load i32, i32* %i, align 4
  %9 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %8, %9
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %10 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %10 to i64
  %11 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %11, i32 0, i32 25
  %12 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %12, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %13 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %13, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %14 = load i32, i32* %i8, align 4
  %15 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %14, %15
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %16 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %16, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, double*, double*)* @.omp_outlined..11 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %phi_id.addr, i32* %rhs_id.addr, i32* %res_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..11(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %phi_id.addr, i32* %rhs_id.addr, i32* %res_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %17 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %17
  %18 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %18 to i64
  %19 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %19, i32 0, i32 0
  %residual = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 2
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %residual, i64 0, i64 %idxprom12
  %20 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %20, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..11(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %phi_id, i32* dereferenceable(4) %rhs_id, i32* dereferenceable(4) %res_id, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %a, double* dereferenceable(8) %b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %phi_id.addr = alloca i32*, align 8
  %rhs_id.addr = alloca i32*, align 8
  %res_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %b.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %h2inv = alloca double, align 8
  %phi = alloca double*, align 8
  %rhs = alloca double*, align 8
  %alpha = alloca double*, align 8
  %beta_i = alloca double*, align 8
  %beta_j = alloca double*, align 8
  %beta_k = alloca double*, align 8
  %res = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %phi_id, i32** %phi_id.addr, align 8
  store i32* %rhs_id, i32** %rhs_id.addr, align 8
  store i32* %res_id, i32** %res_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %b, double** %b.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %phi_id.addr, align 8
  %3 = load i32*, i32** %rhs_id.addr, align 8
  %4 = load i32*, i32** %res_id.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load double*, double** %a.addr, align 8
  %7 = load double*, double** %b.addr, align 8
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %10 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %10, i32 0, i32 19
  %11 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %12 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %12, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %15 = load i32, i32* %.omp.ub, align 4
  %16 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %15, %16
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %17, %cond.true ], [ %18, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %19 = load i32, i32* %.omp.lb, align 4
  store i32 %19, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i32, i32* %.omp.iv, align 4
  %21 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %20, %21
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %22, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %23 = load i32, i32* %1, align 4
  %idxprom = sext i32 %23 to i64
  %24 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %24 to i64
  %25 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %25, i32 0, i32 25
  %26 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %26, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %27 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %27, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %28 = load i32, i32* %pencil11, align 8
  store i32 %28, i32* %pencil, align 4
  %29 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %29 to i64
  %30 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %30 to i64
  %31 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 25
  %32 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %32, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %33 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %33, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %34 = load i32, i32* %plane18, align 4
  store i32 %34, i32* %plane, align 4
  %35 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %35 to i64
  %36 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %36 to i64
  %37 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %37, i32 0, i32 25
  %38 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %38, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %39 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %39, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %40 = load i32, i32* %ghosts25, align 4
  store i32 %40, i32* %ghosts, align 4
  %41 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %41 to i64
  %42 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %42 to i64
  %43 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %43, i32 0, i32 25
  %44 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %44, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %45 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %45, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %46 = load i32, i32* %k32, align 4
  store i32 %46, i32* %dim_k, align 4
  %47 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %47 to i64
  %48 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %48 to i64
  %49 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %49, i32 0, i32 25
  %50 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %50, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %51 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %51, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %52 = load i32, i32* %j40, align 4
  store i32 %52, i32* %dim_j, align 4
  %53 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %53 to i64
  %54 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %54 to i64
  %55 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %55, i32 0, i32 25
  %56 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %56, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %57 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %57, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %58 = load i32, i32* %i48, align 4
  store i32 %58, i32* %dim_i, align 4
  %59 = load i32, i32* %1, align 4
  %idxprom49 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 23
  %arrayidx50 = getelementptr inbounds [10 x double], [10 x double]* %h, i64 0, i64 %idxprom49
  %61 = load double, double* %arrayidx50, align 8
  %62 = load i32, i32* %1, align 4
  %idxprom51 = sext i32 %62 to i64
  %63 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %63, i32 0, i32 23
  %arrayidx53 = getelementptr inbounds [10 x double], [10 x double]* %h52, i64 0, i64 %idxprom51
  %64 = load double, double* %arrayidx53, align 8
  %mul54 = fmul double %61, %64
  %div55 = fdiv double 1.000000e+00, %mul54
  store double %div55, double* %h2inv, align 8
  %65 = load i32, i32* %2, align 4
  %idxprom56 = sext i32 %65 to i64
  %66 = load i32, i32* %1, align 4
  %idxprom57 = sext i32 %66 to i64
  %67 = load i32, i32* %box4, align 4
  %idxprom58 = sext i32 %67 to i64
  %68 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains59 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %68, i32 0, i32 25
  %69 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains59, align 8
  %arrayidx60 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %69, i64 %idxprom58
  %levels61 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx60, i32 0, i32 5
  %70 = load %struct.box_type*, %struct.box_type** %levels61, align 8
  %arrayidx62 = getelementptr inbounds %struct.box_type, %struct.box_type* %70, i64 %idxprom57
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx62, i32 0, i32 10
  %71 = load double**, double*** %grids, align 8
  %arrayidx63 = getelementptr inbounds double*, double** %71, i64 %idxprom56
  %72 = load double*, double** %arrayidx63, align 8
  %73 = load i32, i32* %ghosts, align 4
  %74 = load i32, i32* %pencil, align 4
  %add64 = add nsw i32 1, %74
  %75 = load i32, i32* %plane, align 4
  %add65 = add nsw i32 %add64, %75
  %mul66 = mul nsw i32 %73, %add65
  %idx.ext = sext i32 %mul66 to i64
  %add.ptr = getelementptr inbounds double, double* %72, i64 %idx.ext
  store double* %add.ptr, double** %phi, align 8
  %76 = load i32, i32* %3, align 4
  %idxprom67 = sext i32 %76 to i64
  %77 = load i32, i32* %1, align 4
  %idxprom68 = sext i32 %77 to i64
  %78 = load i32, i32* %box4, align 4
  %idxprom69 = sext i32 %78 to i64
  %79 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains70 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %79, i32 0, i32 25
  %80 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains70, align 8
  %arrayidx71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %80, i64 %idxprom69
  %levels72 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx71, i32 0, i32 5
  %81 = load %struct.box_type*, %struct.box_type** %levels72, align 8
  %arrayidx73 = getelementptr inbounds %struct.box_type, %struct.box_type* %81, i64 %idxprom68
  %grids74 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx73, i32 0, i32 10
  %82 = load double**, double*** %grids74, align 8
  %arrayidx75 = getelementptr inbounds double*, double** %82, i64 %idxprom67
  %83 = load double*, double** %arrayidx75, align 8
  %84 = load i32, i32* %ghosts, align 4
  %85 = load i32, i32* %pencil, align 4
  %add76 = add nsw i32 1, %85
  %86 = load i32, i32* %plane, align 4
  %add77 = add nsw i32 %add76, %86
  %mul78 = mul nsw i32 %84, %add77
  %idx.ext79 = sext i32 %mul78 to i64
  %add.ptr80 = getelementptr inbounds double, double* %83, i64 %idx.ext79
  store double* %add.ptr80, double** %rhs, align 8
  %87 = load i32, i32* %1, align 4
  %idxprom81 = sext i32 %87 to i64
  %88 = load i32, i32* %box4, align 4
  %idxprom82 = sext i32 %88 to i64
  %89 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains83 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %89, i32 0, i32 25
  %90 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains83, align 8
  %arrayidx84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %90, i64 %idxprom82
  %levels85 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx84, i32 0, i32 5
  %91 = load %struct.box_type*, %struct.box_type** %levels85, align 8
  %arrayidx86 = getelementptr inbounds %struct.box_type, %struct.box_type* %91, i64 %idxprom81
  %grids87 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx86, i32 0, i32 10
  %92 = load double**, double*** %grids87, align 8
  %arrayidx88 = getelementptr inbounds double*, double** %92, i64 2
  %93 = load double*, double** %arrayidx88, align 8
  %94 = load i32, i32* %ghosts, align 4
  %95 = load i32, i32* %pencil, align 4
  %add89 = add nsw i32 1, %95
  %96 = load i32, i32* %plane, align 4
  %add90 = add nsw i32 %add89, %96
  %mul91 = mul nsw i32 %94, %add90
  %idx.ext92 = sext i32 %mul91 to i64
  %add.ptr93 = getelementptr inbounds double, double* %93, i64 %idx.ext92
  store double* %add.ptr93, double** %alpha, align 8
  %97 = load i32, i32* %1, align 4
  %idxprom94 = sext i32 %97 to i64
  %98 = load i32, i32* %box4, align 4
  %idxprom95 = sext i32 %98 to i64
  %99 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains96 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %99, i32 0, i32 25
  %100 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains96, align 8
  %arrayidx97 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %100, i64 %idxprom95
  %levels98 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx97, i32 0, i32 5
  %101 = load %struct.box_type*, %struct.box_type** %levels98, align 8
  %arrayidx99 = getelementptr inbounds %struct.box_type, %struct.box_type* %101, i64 %idxprom94
  %grids100 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx99, i32 0, i32 10
  %102 = load double**, double*** %grids100, align 8
  %arrayidx101 = getelementptr inbounds double*, double** %102, i64 5
  %103 = load double*, double** %arrayidx101, align 8
  %104 = load i32, i32* %ghosts, align 4
  %105 = load i32, i32* %pencil, align 4
  %add102 = add nsw i32 1, %105
  %106 = load i32, i32* %plane, align 4
  %add103 = add nsw i32 %add102, %106
  %mul104 = mul nsw i32 %104, %add103
  %idx.ext105 = sext i32 %mul104 to i64
  %add.ptr106 = getelementptr inbounds double, double* %103, i64 %idx.ext105
  store double* %add.ptr106, double** %beta_i, align 8
  %107 = load i32, i32* %1, align 4
  %idxprom107 = sext i32 %107 to i64
  %108 = load i32, i32* %box4, align 4
  %idxprom108 = sext i32 %108 to i64
  %109 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains109 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %109, i32 0, i32 25
  %110 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains109, align 8
  %arrayidx110 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %110, i64 %idxprom108
  %levels111 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx110, i32 0, i32 5
  %111 = load %struct.box_type*, %struct.box_type** %levels111, align 8
  %arrayidx112 = getelementptr inbounds %struct.box_type, %struct.box_type* %111, i64 %idxprom107
  %grids113 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx112, i32 0, i32 10
  %112 = load double**, double*** %grids113, align 8
  %arrayidx114 = getelementptr inbounds double*, double** %112, i64 6
  %113 = load double*, double** %arrayidx114, align 8
  %114 = load i32, i32* %ghosts, align 4
  %115 = load i32, i32* %pencil, align 4
  %add115 = add nsw i32 1, %115
  %116 = load i32, i32* %plane, align 4
  %add116 = add nsw i32 %add115, %116
  %mul117 = mul nsw i32 %114, %add116
  %idx.ext118 = sext i32 %mul117 to i64
  %add.ptr119 = getelementptr inbounds double, double* %113, i64 %idx.ext118
  store double* %add.ptr119, double** %beta_j, align 8
  %117 = load i32, i32* %1, align 4
  %idxprom120 = sext i32 %117 to i64
  %118 = load i32, i32* %box4, align 4
  %idxprom121 = sext i32 %118 to i64
  %119 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains122 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %119, i32 0, i32 25
  %120 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains122, align 8
  %arrayidx123 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %120, i64 %idxprom121
  %levels124 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx123, i32 0, i32 5
  %121 = load %struct.box_type*, %struct.box_type** %levels124, align 8
  %arrayidx125 = getelementptr inbounds %struct.box_type, %struct.box_type* %121, i64 %idxprom120
  %grids126 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx125, i32 0, i32 10
  %122 = load double**, double*** %grids126, align 8
  %arrayidx127 = getelementptr inbounds double*, double** %122, i64 7
  %123 = load double*, double** %arrayidx127, align 8
  %124 = load i32, i32* %ghosts, align 4
  %125 = load i32, i32* %pencil, align 4
  %add128 = add nsw i32 1, %125
  %126 = load i32, i32* %plane, align 4
  %add129 = add nsw i32 %add128, %126
  %mul130 = mul nsw i32 %124, %add129
  %idx.ext131 = sext i32 %mul130 to i64
  %add.ptr132 = getelementptr inbounds double, double* %123, i64 %idx.ext131
  store double* %add.ptr132, double** %beta_k, align 8
  %127 = load i32, i32* %4, align 4
  %idxprom133 = sext i32 %127 to i64
  %128 = load i32, i32* %1, align 4
  %idxprom134 = sext i32 %128 to i64
  %129 = load i32, i32* %box4, align 4
  %idxprom135 = sext i32 %129 to i64
  %130 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains136 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %130, i32 0, i32 25
  %131 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains136, align 8
  %arrayidx137 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %131, i64 %idxprom135
  %levels138 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx137, i32 0, i32 5
  %132 = load %struct.box_type*, %struct.box_type** %levels138, align 8
  %arrayidx139 = getelementptr inbounds %struct.box_type, %struct.box_type* %132, i64 %idxprom134
  %grids140 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx139, i32 0, i32 10
  %133 = load double**, double*** %grids140, align 8
  %arrayidx141 = getelementptr inbounds double*, double** %133, i64 %idxprom133
  %134 = load double*, double** %arrayidx141, align 8
  %135 = load i32, i32* %ghosts, align 4
  %136 = load i32, i32* %pencil, align 4
  %add142 = add nsw i32 1, %136
  %137 = load i32, i32* %plane, align 4
  %add143 = add nsw i32 %add142, %137
  %mul144 = mul nsw i32 %135, %add143
  %idx.ext145 = sext i32 %mul144 to i64
  %add.ptr146 = getelementptr inbounds double, double* %134, i64 %idx.ext145
  store double* %add.ptr146, double** %res, align 8
  %138 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %138, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 15, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double**, double**, double*, double*, double**, double**, double**, double**, double**)* @.omp_outlined..12 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %6, double** %alpha, double** %phi, double* %7, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %res, double** %rhs)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %139 = load i32*, i32** %.global_tid..addr, align 8
  %140 = load i32, i32* %139, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %140)
  %141 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..12(i32* %141, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %6, double** %alpha, double** %phi, double* %7, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %res, double** %rhs)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %140)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %142 = load i32, i32* %.omp.iv, align 4
  %add147 = add nsw i32 %142, 1
  store i32 %add147, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %143 = load i32*, i32** %.global_tid..addr, align 8
  %144 = load i32, i32* %143, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %144)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..12(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %a, double** dereferenceable(8) %alpha, double** dereferenceable(8) %phi, double* dereferenceable(8) %b, double* dereferenceable(8) %h2inv, double** dereferenceable(8) %beta_i, double** dereferenceable(8) %beta_j, double** dereferenceable(8) %beta_k, double** dereferenceable(8) %res, double** dereferenceable(8) %rhs) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %alpha.addr = alloca double**, align 8
  %phi.addr = alloca double**, align 8
  %b.addr = alloca double*, align 8
  %h2inv.addr = alloca double*, align 8
  %beta_i.addr = alloca double**, align 8
  %beta_j.addr = alloca double**, align 8
  %beta_k.addr = alloca double**, align 8
  %res.addr = alloca double**, align 8
  %rhs.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %helmholtz = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double** %alpha, double*** %alpha.addr, align 8
  store double** %phi, double*** %phi.addr, align 8
  store double* %b, double** %b.addr, align 8
  store double* %h2inv, double** %h2inv.addr, align 8
  store double** %beta_i, double*** %beta_i.addr, align 8
  store double** %beta_j, double*** %beta_j.addr, align 8
  store double** %beta_k, double*** %beta_k.addr, align 8
  store double** %res, double*** %res.addr, align 8
  store double** %rhs, double*** %rhs.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %a.addr, align 8
  %6 = load double**, double*** %alpha.addr, align 8
  %7 = load double**, double*** %phi.addr, align 8
  %8 = load double*, double** %b.addr, align 8
  %9 = load double*, double** %h2inv.addr, align 8
  %10 = load double**, double*** %beta_i.addr, align 8
  %11 = load double**, double*** %beta_j.addr, align 8
  %12 = load double**, double*** %beta_k.addr, align 8
  %13 = load double**, double*** %res.addr, align 8
  %14 = load double**, double*** %rhs.addr, align 8
  %15 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %15, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %16 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %16, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %17 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %17
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %18 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %18
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %19 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %19, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %20 = load i32*, i32** %.global_tid..addr, align 8
  %21 = load i32, i32* %20, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %21, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %22 = load i64, i64* %.omp.ub, align 8
  %23 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %22, %23
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %24 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %25 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %24, %cond.true ], [ %25, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %26 = load i64, i64* %.omp.lb, align 8
  store i64 %26, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %27 = load i64, i64* %.omp.iv, align 8
  %28 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %27, %28
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %29 = load i64, i64* %.omp.iv, align 8
  %30 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %30, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %29, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %31 = load i64, i64* %.omp.iv, align 8
  %32 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %32, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %31, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %33 = load i32, i32* %i, align 4
  %34 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %33, %34
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %35 = load i32, i32* %i, align 4
  %36 = load i32, i32* %j14, align 4
  %37 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %36, %37
  %add41 = add nsw i32 %35, %mul40
  %38 = load i32, i32* %k13, align 4
  %39 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %38, %39
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %40 = load double, double* %5, align 8
  %41 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %41 to i64
  %42 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %42, i64 %idxprom
  %43 = load double, double* %arrayidx, align 8
  %mul44 = fmul double %40, %43
  %44 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %44 to i64
  %45 = load double*, double** %7, align 8
  %arrayidx46 = getelementptr inbounds double, double* %45, i64 %idxprom45
  %46 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %mul44, %46
  %47 = load double, double* %8, align 8
  %48 = load double, double* %9, align 8
  %mul48 = fmul double %47, %48
  %49 = load i32, i32* %ijk, align 4
  %add49 = add nsw i32 %49, 1
  %idxprom50 = sext i32 %add49 to i64
  %50 = load double*, double** %10, align 8
  %arrayidx51 = getelementptr inbounds double, double* %50, i64 %idxprom50
  %51 = load double, double* %arrayidx51, align 8
  %52 = load i32, i32* %ijk, align 4
  %add52 = add nsw i32 %52, 1
  %idxprom53 = sext i32 %add52 to i64
  %53 = load double*, double** %7, align 8
  %arrayidx54 = getelementptr inbounds double, double* %53, i64 %idxprom53
  %54 = load double, double* %arrayidx54, align 8
  %55 = load i32, i32* %ijk, align 4
  %idxprom55 = sext i32 %55 to i64
  %56 = load double*, double** %7, align 8
  %arrayidx56 = getelementptr inbounds double, double* %56, i64 %idxprom55
  %57 = load double, double* %arrayidx56, align 8
  %sub57 = fsub double %54, %57
  %mul58 = fmul double %51, %sub57
  %58 = load i32, i32* %ijk, align 4
  %idxprom59 = sext i32 %58 to i64
  %59 = load double*, double** %10, align 8
  %arrayidx60 = getelementptr inbounds double, double* %59, i64 %idxprom59
  %60 = load double, double* %arrayidx60, align 8
  %61 = load i32, i32* %ijk, align 4
  %idxprom61 = sext i32 %61 to i64
  %62 = load double*, double** %7, align 8
  %arrayidx62 = getelementptr inbounds double, double* %62, i64 %idxprom61
  %63 = load double, double* %arrayidx62, align 8
  %64 = load i32, i32* %ijk, align 4
  %sub63 = sub nsw i32 %64, 1
  %idxprom64 = sext i32 %sub63 to i64
  %65 = load double*, double** %7, align 8
  %arrayidx65 = getelementptr inbounds double, double* %65, i64 %idxprom64
  %66 = load double, double* %arrayidx65, align 8
  %sub66 = fsub double %63, %66
  %mul67 = fmul double %60, %sub66
  %sub68 = fsub double %mul58, %mul67
  %67 = load i32, i32* %ijk, align 4
  %68 = load i32, i32* %3, align 4
  %add69 = add nsw i32 %67, %68
  %idxprom70 = sext i32 %add69 to i64
  %69 = load double*, double** %11, align 8
  %arrayidx71 = getelementptr inbounds double, double* %69, i64 %idxprom70
  %70 = load double, double* %arrayidx71, align 8
  %71 = load i32, i32* %ijk, align 4
  %72 = load i32, i32* %3, align 4
  %add72 = add nsw i32 %71, %72
  %idxprom73 = sext i32 %add72 to i64
  %73 = load double*, double** %7, align 8
  %arrayidx74 = getelementptr inbounds double, double* %73, i64 %idxprom73
  %74 = load double, double* %arrayidx74, align 8
  %75 = load i32, i32* %ijk, align 4
  %idxprom75 = sext i32 %75 to i64
  %76 = load double*, double** %7, align 8
  %arrayidx76 = getelementptr inbounds double, double* %76, i64 %idxprom75
  %77 = load double, double* %arrayidx76, align 8
  %sub77 = fsub double %74, %77
  %mul78 = fmul double %70, %sub77
  %add79 = fadd double %sub68, %mul78
  %78 = load i32, i32* %ijk, align 4
  %idxprom80 = sext i32 %78 to i64
  %79 = load double*, double** %11, align 8
  %arrayidx81 = getelementptr inbounds double, double* %79, i64 %idxprom80
  %80 = load double, double* %arrayidx81, align 8
  %81 = load i32, i32* %ijk, align 4
  %idxprom82 = sext i32 %81 to i64
  %82 = load double*, double** %7, align 8
  %arrayidx83 = getelementptr inbounds double, double* %82, i64 %idxprom82
  %83 = load double, double* %arrayidx83, align 8
  %84 = load i32, i32* %ijk, align 4
  %85 = load i32, i32* %3, align 4
  %sub84 = sub nsw i32 %84, %85
  %idxprom85 = sext i32 %sub84 to i64
  %86 = load double*, double** %7, align 8
  %arrayidx86 = getelementptr inbounds double, double* %86, i64 %idxprom85
  %87 = load double, double* %arrayidx86, align 8
  %sub87 = fsub double %83, %87
  %mul88 = fmul double %80, %sub87
  %sub89 = fsub double %add79, %mul88
  %88 = load i32, i32* %ijk, align 4
  %89 = load i32, i32* %4, align 4
  %add90 = add nsw i32 %88, %89
  %idxprom91 = sext i32 %add90 to i64
  %90 = load double*, double** %12, align 8
  %arrayidx92 = getelementptr inbounds double, double* %90, i64 %idxprom91
  %91 = load double, double* %arrayidx92, align 8
  %92 = load i32, i32* %ijk, align 4
  %93 = load i32, i32* %4, align 4
  %add93 = add nsw i32 %92, %93
  %idxprom94 = sext i32 %add93 to i64
  %94 = load double*, double** %7, align 8
  %arrayidx95 = getelementptr inbounds double, double* %94, i64 %idxprom94
  %95 = load double, double* %arrayidx95, align 8
  %96 = load i32, i32* %ijk, align 4
  %idxprom96 = sext i32 %96 to i64
  %97 = load double*, double** %7, align 8
  %arrayidx97 = getelementptr inbounds double, double* %97, i64 %idxprom96
  %98 = load double, double* %arrayidx97, align 8
  %sub98 = fsub double %95, %98
  %mul99 = fmul double %91, %sub98
  %add100 = fadd double %sub89, %mul99
  %99 = load i32, i32* %ijk, align 4
  %idxprom101 = sext i32 %99 to i64
  %100 = load double*, double** %12, align 8
  %arrayidx102 = getelementptr inbounds double, double* %100, i64 %idxprom101
  %101 = load double, double* %arrayidx102, align 8
  %102 = load i32, i32* %ijk, align 4
  %idxprom103 = sext i32 %102 to i64
  %103 = load double*, double** %7, align 8
  %arrayidx104 = getelementptr inbounds double, double* %103, i64 %idxprom103
  %104 = load double, double* %arrayidx104, align 8
  %105 = load i32, i32* %ijk, align 4
  %106 = load i32, i32* %4, align 4
  %sub105 = sub nsw i32 %105, %106
  %idxprom106 = sext i32 %sub105 to i64
  %107 = load double*, double** %7, align 8
  %arrayidx107 = getelementptr inbounds double, double* %107, i64 %idxprom106
  %108 = load double, double* %arrayidx107, align 8
  %sub108 = fsub double %104, %108
  %mul109 = fmul double %101, %sub108
  %sub110 = fsub double %add100, %mul109
  %mul111 = fmul double %mul48, %sub110
  %sub112 = fsub double %mul47, %mul111
  store double %sub112, double* %helmholtz, align 8
  %109 = load i32, i32* %ijk, align 4
  %idxprom113 = sext i32 %109 to i64
  %110 = load double*, double** %14, align 8
  %arrayidx114 = getelementptr inbounds double, double* %110, i64 %idxprom113
  %111 = load double, double* %arrayidx114, align 8
  %112 = load double, double* %helmholtz, align 8
  %sub115 = fsub double %111, %112
  %113 = load i32, i32* %ijk, align 4
  %idxprom116 = sext i32 %113 to i64
  %114 = load double*, double** %13, align 8
  %arrayidx117 = getelementptr inbounds double, double* %114, i64 %idxprom116
  store double %sub115, double* %arrayidx117, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %115 = load i32, i32* %i, align 4
  %inc = add nsw i32 %115, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %116 = load i64, i64* %.omp.iv, align 8
  %add118 = add nsw i64 %116, 1
  store i64 %add118, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %117 = load i32*, i32** %.global_tid..addr, align 8
  %118 = load i32, i32* %117, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %118)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @residual_and_restriction(%struct.domain_type* %domain, i32 %level_f, i32 %phi_id, i32 %rhs_id, i32 %level_c, i32 %res_id, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level_f.addr = alloca i32, align 4
  %phi_id.addr = alloca i32, align 4
  %rhs_id.addr = alloca i32, align 4
  %level_c.addr = alloca i32, align 4
  %res_id.addr = alloca i32, align 4
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level_f, i32* %level_f.addr, align 4
  store i32 %phi_id, i32* %phi_id.addr, align 4
  store i32 %rhs_id, i32* %rhs_id.addr, align 4
  store i32 %level_c, i32* %level_c.addr, align 4
  store i32 %res_id, i32* %res_id.addr, align 4
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  %1 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %2 = load i32, i32* %level_f.addr, align 4
  %3 = load i32, i32* %phi_id.addr, align 4
  call void @exchange_boundary(%struct.domain_type* %1, i32 %2, i32 %3, i32 1, i32 0, i32 0)
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %4 = load i32, i32* %level_f.addr, align 4
  %idxprom = sext i32 %4 to i64
  %5 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 25
  %6 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %6, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %7 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %7, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %8 = load i32, i32* %i, align 4
  %9 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %8, %9
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %10 = load i32, i32* %level_f.addr, align 4
  %idxprom2 = sext i32 %10 to i64
  %11 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %11, i32 0, i32 25
  %12 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %12, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %13 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %13, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %14 = load i32, i32* %i8, align 4
  %15 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %14, %15
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %16 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %16, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, i32*, double*, double*)* @.omp_outlined..13 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level_c.addr, i32* %level_f.addr, i32* %phi_id.addr, i32* %rhs_id.addr, i32* %res_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..13(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level_c.addr, i32* %level_f.addr, i32* %phi_id.addr, i32* %rhs_id.addr, i32* %res_id.addr, i32* %omp_within_a_box, double* %a.addr, double* %b.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %17 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %17
  %18 = load i32, i32* %level_f.addr, align 4
  %idxprom12 = sext i32 %18 to i64
  %19 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %19, i32 0, i32 0
  %residual = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 2
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %residual, i64 0, i64 %idxprom12
  %20 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %20, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..13(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level_c, i32* dereferenceable(4) %level_f, i32* dereferenceable(4) %phi_id, i32* dereferenceable(4) %rhs_id, i32* dereferenceable(4) %res_id, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %a, double* dereferenceable(8) %b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level_c.addr = alloca i32*, align 8
  %level_f.addr = alloca i32*, align 8
  %phi_id.addr = alloca i32*, align 8
  %rhs_id.addr = alloca i32*, align 8
  %res_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %b.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %kk = alloca i32, align 4
  %jj = alloca i32, align 4
  %pencil_c = alloca i32, align 4
  %plane_c = alloca i32, align 4
  %ghosts_c = alloca i32, align 4
  %dim_k_c = alloca i32, align 4
  %dim_j_c = alloca i32, align 4
  %dim_i_c = alloca i32, align 4
  %pencil_f = alloca i32, align 4
  %plane_f = alloca i32, align 4
  %ghosts_f = alloca i32, align 4
  %dim_k_f = alloca i32, align 4
  %dim_j_f = alloca i32, align 4
  %dim_i_f = alloca i32, align 4
  %h2inv = alloca double, align 8
  %phi = alloca double*, align 8
  %rhs = alloca double*, align 8
  %alpha = alloca double*, align 8
  %beta_i = alloca double*, align 8
  %beta_j = alloca double*, align 8
  %beta_k = alloca double*, align 8
  %res = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level_c, i32** %level_c.addr, align 8
  store i32* %level_f, i32** %level_f.addr, align 8
  store i32* %phi_id, i32** %phi_id.addr, align 8
  store i32* %rhs_id, i32** %rhs_id.addr, align 8
  store i32* %res_id, i32** %res_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %b, double** %b.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level_c.addr, align 8
  %2 = load i32*, i32** %level_f.addr, align 8
  %3 = load i32*, i32** %phi_id.addr, align 8
  %4 = load i32*, i32** %rhs_id.addr, align 8
  %5 = load i32*, i32** %res_id.addr, align 8
  %6 = load i32*, i32** %omp_within_a_box.addr, align 8
  %7 = load double*, double** %a.addr, align 8
  %8 = load double*, double** %b.addr, align 8
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %10, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %11 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %11, i32 0, i32 19
  %12 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %12
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %13 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %13, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %16 = load i32, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %16, %17
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %18, %cond.true ], [ %19, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %20 = load i32, i32* %.omp.lb, align 4
  store i32 %20, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i32, i32* %.omp.iv, align 4
  %22 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %21, %22
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %23, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %24 = load i32, i32* %1, align 4
  %idxprom = sext i32 %24 to i64
  %25 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %25 to i64
  %26 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %26, i32 0, i32 25
  %27 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %27, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %28 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %28, i64 %idxprom
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %29 = load i32, i32* %pencil, align 8
  store i32 %29, i32* %pencil_c, align 4
  %30 = load i32, i32* %1, align 4
  %idxprom11 = sext i32 %30 to i64
  %31 = load i32, i32* %box4, align 4
  %idxprom12 = sext i32 %31 to i64
  %32 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %32, i32 0, i32 25
  %33 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %33, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %34 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %34, i64 %idxprom11
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 6
  %35 = load i32, i32* %plane, align 4
  store i32 %35, i32* %plane_c, align 4
  %36 = load i32, i32* %1, align 4
  %idxprom17 = sext i32 %36 to i64
  %37 = load i32, i32* %box4, align 4
  %idxprom18 = sext i32 %37 to i64
  %38 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %38, i32 0, i32 25
  %39 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains19, align 8
  %arrayidx20 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %39, i64 %idxprom18
  %levels21 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx20, i32 0, i32 5
  %40 = load %struct.box_type*, %struct.box_type** %levels21, align 8
  %arrayidx22 = getelementptr inbounds %struct.box_type, %struct.box_type* %40, i64 %idxprom17
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx22, i32 0, i32 4
  %41 = load i32, i32* %ghosts, align 4
  store i32 %41, i32* %ghosts_c, align 4
  %42 = load i32, i32* %1, align 4
  %idxprom23 = sext i32 %42 to i64
  %43 = load i32, i32* %box4, align 4
  %idxprom24 = sext i32 %43 to i64
  %44 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains25 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %44, i32 0, i32 25
  %45 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains25, align 8
  %arrayidx26 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %45, i64 %idxprom24
  %levels27 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx26, i32 0, i32 5
  %46 = load %struct.box_type*, %struct.box_type** %levels27, align 8
  %arrayidx28 = getelementptr inbounds %struct.box_type, %struct.box_type* %46, i64 %idxprom23
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx28, i32 0, i32 2
  %k = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %47 = load i32, i32* %k, align 4
  store i32 %47, i32* %dim_k_c, align 4
  %48 = load i32, i32* %1, align 4
  %idxprom29 = sext i32 %48 to i64
  %49 = load i32, i32* %box4, align 4
  %idxprom30 = sext i32 %49 to i64
  %50 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains31 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %50, i32 0, i32 25
  %51 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains31, align 8
  %arrayidx32 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %51, i64 %idxprom30
  %levels33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx32, i32 0, i32 5
  %52 = load %struct.box_type*, %struct.box_type** %levels33, align 8
  %arrayidx34 = getelementptr inbounds %struct.box_type, %struct.box_type* %52, i64 %idxprom29
  %dim35 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx34, i32 0, i32 2
  %j = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim35, i32 0, i32 1
  %53 = load i32, i32* %j, align 4
  store i32 %53, i32* %dim_j_c, align 4
  %54 = load i32, i32* %1, align 4
  %idxprom36 = sext i32 %54 to i64
  %55 = load i32, i32* %box4, align 4
  %idxprom37 = sext i32 %55 to i64
  %56 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains38 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %56, i32 0, i32 25
  %57 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains38, align 8
  %arrayidx39 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %57, i64 %idxprom37
  %levels40 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx39, i32 0, i32 5
  %58 = load %struct.box_type*, %struct.box_type** %levels40, align 8
  %arrayidx41 = getelementptr inbounds %struct.box_type, %struct.box_type* %58, i64 %idxprom36
  %dim42 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx41, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim42, i32 0, i32 0
  %59 = load i32, i32* %i, align 4
  store i32 %59, i32* %dim_i_c, align 4
  %60 = load i32, i32* %2, align 4
  %idxprom43 = sext i32 %60 to i64
  %61 = load i32, i32* %box4, align 4
  %idxprom44 = sext i32 %61 to i64
  %62 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains45 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %62, i32 0, i32 25
  %63 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains45, align 8
  %arrayidx46 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %63, i64 %idxprom44
  %levels47 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx46, i32 0, i32 5
  %64 = load %struct.box_type*, %struct.box_type** %levels47, align 8
  %arrayidx48 = getelementptr inbounds %struct.box_type, %struct.box_type* %64, i64 %idxprom43
  %pencil49 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx48, i32 0, i32 5
  %65 = load i32, i32* %pencil49, align 8
  store i32 %65, i32* %pencil_f, align 4
  %66 = load i32, i32* %2, align 4
  %idxprom50 = sext i32 %66 to i64
  %67 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %67 to i64
  %68 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %68, i32 0, i32 25
  %69 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %69, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %70 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %70, i64 %idxprom50
  %plane56 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 6
  %71 = load i32, i32* %plane56, align 4
  store i32 %71, i32* %plane_f, align 4
  %72 = load i32, i32* %2, align 4
  %idxprom57 = sext i32 %72 to i64
  %73 = load i32, i32* %box4, align 4
  %idxprom58 = sext i32 %73 to i64
  %74 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains59 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %74, i32 0, i32 25
  %75 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains59, align 8
  %arrayidx60 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %75, i64 %idxprom58
  %levels61 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx60, i32 0, i32 5
  %76 = load %struct.box_type*, %struct.box_type** %levels61, align 8
  %arrayidx62 = getelementptr inbounds %struct.box_type, %struct.box_type* %76, i64 %idxprom57
  %ghosts63 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx62, i32 0, i32 4
  %77 = load i32, i32* %ghosts63, align 4
  store i32 %77, i32* %ghosts_f, align 4
  %78 = load i32, i32* %2, align 4
  %idxprom64 = sext i32 %78 to i64
  %79 = load i32, i32* %box4, align 4
  %idxprom65 = sext i32 %79 to i64
  %80 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains66 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %80, i32 0, i32 25
  %81 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains66, align 8
  %arrayidx67 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %81, i64 %idxprom65
  %levels68 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx67, i32 0, i32 5
  %82 = load %struct.box_type*, %struct.box_type** %levels68, align 8
  %arrayidx69 = getelementptr inbounds %struct.box_type, %struct.box_type* %82, i64 %idxprom64
  %dim70 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx69, i32 0, i32 2
  %k71 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim70, i32 0, i32 2
  %83 = load i32, i32* %k71, align 4
  store i32 %83, i32* %dim_k_f, align 4
  %84 = load i32, i32* %2, align 4
  %idxprom72 = sext i32 %84 to i64
  %85 = load i32, i32* %box4, align 4
  %idxprom73 = sext i32 %85 to i64
  %86 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains74 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %86, i32 0, i32 25
  %87 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains74, align 8
  %arrayidx75 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %87, i64 %idxprom73
  %levels76 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx75, i32 0, i32 5
  %88 = load %struct.box_type*, %struct.box_type** %levels76, align 8
  %arrayidx77 = getelementptr inbounds %struct.box_type, %struct.box_type* %88, i64 %idxprom72
  %dim78 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx77, i32 0, i32 2
  %j79 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim78, i32 0, i32 1
  %89 = load i32, i32* %j79, align 4
  store i32 %89, i32* %dim_j_f, align 4
  %90 = load i32, i32* %2, align 4
  %idxprom80 = sext i32 %90 to i64
  %91 = load i32, i32* %box4, align 4
  %idxprom81 = sext i32 %91 to i64
  %92 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains82 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %92, i32 0, i32 25
  %93 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains82, align 8
  %arrayidx83 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %93, i64 %idxprom81
  %levels84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx83, i32 0, i32 5
  %94 = load %struct.box_type*, %struct.box_type** %levels84, align 8
  %arrayidx85 = getelementptr inbounds %struct.box_type, %struct.box_type* %94, i64 %idxprom80
  %dim86 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx85, i32 0, i32 2
  %i87 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim86, i32 0, i32 0
  %95 = load i32, i32* %i87, align 4
  store i32 %95, i32* %dim_i_f, align 4
  %96 = load i32, i32* %2, align 4
  %idxprom88 = sext i32 %96 to i64
  %97 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h = getelementptr inbounds %struct.domain_type, %struct.domain_type* %97, i32 0, i32 23
  %arrayidx89 = getelementptr inbounds [10 x double], [10 x double]* %h, i64 0, i64 %idxprom88
  %98 = load double, double* %arrayidx89, align 8
  %99 = load i32, i32* %2, align 4
  %idxprom90 = sext i32 %99 to i64
  %100 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %h91 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %100, i32 0, i32 23
  %arrayidx92 = getelementptr inbounds [10 x double], [10 x double]* %h91, i64 0, i64 %idxprom90
  %101 = load double, double* %arrayidx92, align 8
  %mul93 = fmul double %98, %101
  %div94 = fdiv double 1.000000e+00, %mul93
  store double %div94, double* %h2inv, align 8
  %102 = load i32, i32* %3, align 4
  %idxprom95 = sext i32 %102 to i64
  %103 = load i32, i32* %2, align 4
  %idxprom96 = sext i32 %103 to i64
  %104 = load i32, i32* %box4, align 4
  %idxprom97 = sext i32 %104 to i64
  %105 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains98 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %105, i32 0, i32 25
  %106 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains98, align 8
  %arrayidx99 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %106, i64 %idxprom97
  %levels100 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx99, i32 0, i32 5
  %107 = load %struct.box_type*, %struct.box_type** %levels100, align 8
  %arrayidx101 = getelementptr inbounds %struct.box_type, %struct.box_type* %107, i64 %idxprom96
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx101, i32 0, i32 10
  %108 = load double**, double*** %grids, align 8
  %arrayidx102 = getelementptr inbounds double*, double** %108, i64 %idxprom95
  %109 = load double*, double** %arrayidx102, align 8
  %110 = load i32, i32* %ghosts_f, align 4
  %111 = load i32, i32* %pencil_f, align 4
  %add103 = add nsw i32 1, %111
  %112 = load i32, i32* %plane_f, align 4
  %add104 = add nsw i32 %add103, %112
  %mul105 = mul nsw i32 %110, %add104
  %idx.ext = sext i32 %mul105 to i64
  %add.ptr = getelementptr inbounds double, double* %109, i64 %idx.ext
  store double* %add.ptr, double** %phi, align 8
  %113 = load i32, i32* %4, align 4
  %idxprom106 = sext i32 %113 to i64
  %114 = load i32, i32* %2, align 4
  %idxprom107 = sext i32 %114 to i64
  %115 = load i32, i32* %box4, align 4
  %idxprom108 = sext i32 %115 to i64
  %116 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains109 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %116, i32 0, i32 25
  %117 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains109, align 8
  %arrayidx110 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %117, i64 %idxprom108
  %levels111 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx110, i32 0, i32 5
  %118 = load %struct.box_type*, %struct.box_type** %levels111, align 8
  %arrayidx112 = getelementptr inbounds %struct.box_type, %struct.box_type* %118, i64 %idxprom107
  %grids113 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx112, i32 0, i32 10
  %119 = load double**, double*** %grids113, align 8
  %arrayidx114 = getelementptr inbounds double*, double** %119, i64 %idxprom106
  %120 = load double*, double** %arrayidx114, align 8
  %121 = load i32, i32* %ghosts_f, align 4
  %122 = load i32, i32* %pencil_f, align 4
  %add115 = add nsw i32 1, %122
  %123 = load i32, i32* %plane_f, align 4
  %add116 = add nsw i32 %add115, %123
  %mul117 = mul nsw i32 %121, %add116
  %idx.ext118 = sext i32 %mul117 to i64
  %add.ptr119 = getelementptr inbounds double, double* %120, i64 %idx.ext118
  store double* %add.ptr119, double** %rhs, align 8
  %124 = load i32, i32* %2, align 4
  %idxprom120 = sext i32 %124 to i64
  %125 = load i32, i32* %box4, align 4
  %idxprom121 = sext i32 %125 to i64
  %126 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains122 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %126, i32 0, i32 25
  %127 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains122, align 8
  %arrayidx123 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %127, i64 %idxprom121
  %levels124 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx123, i32 0, i32 5
  %128 = load %struct.box_type*, %struct.box_type** %levels124, align 8
  %arrayidx125 = getelementptr inbounds %struct.box_type, %struct.box_type* %128, i64 %idxprom120
  %grids126 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx125, i32 0, i32 10
  %129 = load double**, double*** %grids126, align 8
  %arrayidx127 = getelementptr inbounds double*, double** %129, i64 2
  %130 = load double*, double** %arrayidx127, align 8
  %131 = load i32, i32* %ghosts_f, align 4
  %132 = load i32, i32* %pencil_f, align 4
  %add128 = add nsw i32 1, %132
  %133 = load i32, i32* %plane_f, align 4
  %add129 = add nsw i32 %add128, %133
  %mul130 = mul nsw i32 %131, %add129
  %idx.ext131 = sext i32 %mul130 to i64
  %add.ptr132 = getelementptr inbounds double, double* %130, i64 %idx.ext131
  store double* %add.ptr132, double** %alpha, align 8
  %134 = load i32, i32* %2, align 4
  %idxprom133 = sext i32 %134 to i64
  %135 = load i32, i32* %box4, align 4
  %idxprom134 = sext i32 %135 to i64
  %136 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains135 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %136, i32 0, i32 25
  %137 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains135, align 8
  %arrayidx136 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %137, i64 %idxprom134
  %levels137 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx136, i32 0, i32 5
  %138 = load %struct.box_type*, %struct.box_type** %levels137, align 8
  %arrayidx138 = getelementptr inbounds %struct.box_type, %struct.box_type* %138, i64 %idxprom133
  %grids139 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx138, i32 0, i32 10
  %139 = load double**, double*** %grids139, align 8
  %arrayidx140 = getelementptr inbounds double*, double** %139, i64 5
  %140 = load double*, double** %arrayidx140, align 8
  %141 = load i32, i32* %ghosts_f, align 4
  %142 = load i32, i32* %pencil_f, align 4
  %add141 = add nsw i32 1, %142
  %143 = load i32, i32* %plane_f, align 4
  %add142 = add nsw i32 %add141, %143
  %mul143 = mul nsw i32 %141, %add142
  %idx.ext144 = sext i32 %mul143 to i64
  %add.ptr145 = getelementptr inbounds double, double* %140, i64 %idx.ext144
  store double* %add.ptr145, double** %beta_i, align 8
  %144 = load i32, i32* %2, align 4
  %idxprom146 = sext i32 %144 to i64
  %145 = load i32, i32* %box4, align 4
  %idxprom147 = sext i32 %145 to i64
  %146 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains148 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %146, i32 0, i32 25
  %147 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains148, align 8
  %arrayidx149 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %147, i64 %idxprom147
  %levels150 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx149, i32 0, i32 5
  %148 = load %struct.box_type*, %struct.box_type** %levels150, align 8
  %arrayidx151 = getelementptr inbounds %struct.box_type, %struct.box_type* %148, i64 %idxprom146
  %grids152 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx151, i32 0, i32 10
  %149 = load double**, double*** %grids152, align 8
  %arrayidx153 = getelementptr inbounds double*, double** %149, i64 6
  %150 = load double*, double** %arrayidx153, align 8
  %151 = load i32, i32* %ghosts_f, align 4
  %152 = load i32, i32* %pencil_f, align 4
  %add154 = add nsw i32 1, %152
  %153 = load i32, i32* %plane_f, align 4
  %add155 = add nsw i32 %add154, %153
  %mul156 = mul nsw i32 %151, %add155
  %idx.ext157 = sext i32 %mul156 to i64
  %add.ptr158 = getelementptr inbounds double, double* %150, i64 %idx.ext157
  store double* %add.ptr158, double** %beta_j, align 8
  %154 = load i32, i32* %2, align 4
  %idxprom159 = sext i32 %154 to i64
  %155 = load i32, i32* %box4, align 4
  %idxprom160 = sext i32 %155 to i64
  %156 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains161 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %156, i32 0, i32 25
  %157 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains161, align 8
  %arrayidx162 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %157, i64 %idxprom160
  %levels163 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx162, i32 0, i32 5
  %158 = load %struct.box_type*, %struct.box_type** %levels163, align 8
  %arrayidx164 = getelementptr inbounds %struct.box_type, %struct.box_type* %158, i64 %idxprom159
  %grids165 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx164, i32 0, i32 10
  %159 = load double**, double*** %grids165, align 8
  %arrayidx166 = getelementptr inbounds double*, double** %159, i64 7
  %160 = load double*, double** %arrayidx166, align 8
  %161 = load i32, i32* %ghosts_f, align 4
  %162 = load i32, i32* %pencil_f, align 4
  %add167 = add nsw i32 1, %162
  %163 = load i32, i32* %plane_f, align 4
  %add168 = add nsw i32 %add167, %163
  %mul169 = mul nsw i32 %161, %add168
  %idx.ext170 = sext i32 %mul169 to i64
  %add.ptr171 = getelementptr inbounds double, double* %160, i64 %idx.ext170
  store double* %add.ptr171, double** %beta_k, align 8
  %164 = load i32, i32* %5, align 4
  %idxprom172 = sext i32 %164 to i64
  %165 = load i32, i32* %1, align 4
  %idxprom173 = sext i32 %165 to i64
  %166 = load i32, i32* %box4, align 4
  %idxprom174 = sext i32 %166 to i64
  %167 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains175 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %167, i32 0, i32 25
  %168 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains175, align 8
  %arrayidx176 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %168, i64 %idxprom174
  %levels177 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx176, i32 0, i32 5
  %169 = load %struct.box_type*, %struct.box_type** %levels177, align 8
  %arrayidx178 = getelementptr inbounds %struct.box_type, %struct.box_type* %169, i64 %idxprom173
  %grids179 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx178, i32 0, i32 10
  %170 = load double**, double*** %grids179, align 8
  %arrayidx180 = getelementptr inbounds double*, double** %170, i64 %idxprom172
  %171 = load double*, double** %arrayidx180, align 8
  %172 = load i32, i32* %ghosts_c, align 4
  %173 = load i32, i32* %pencil_c, align 4
  %add181 = add nsw i32 1, %173
  %174 = load i32, i32* %plane_c, align 4
  %add182 = add nsw i32 %add181, %174
  %mul183 = mul nsw i32 %172, %add182
  %idx.ext184 = sext i32 %mul183 to i64
  %add.ptr185 = getelementptr inbounds double, double* %171, i64 %idx.ext184
  store double* %add.ptr185, double** %res, align 8
  %175 = load i32, i32* %6, align 4
  %tobool = icmp ne i32 %175, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 18, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, i32*, i32*, i32*, double*, double**, double**, double*, double*, double**, double**, double**, double**)* @.omp_outlined..14 to void (i32*, i32*, ...)*), i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, double** %res, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, double* %7, double** %alpha, double** %phi, double* %8, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %rhs)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %176 = load i32*, i32** %.global_tid..addr, align 8
  %177 = load i32, i32* %176, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %177)
  %178 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..14(i32* %178, i32* %.zero.addr, i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, double** %res, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, double* %7, double** %alpha, double** %phi, double* %8, double* %h2inv, double** %beta_i, double** %beta_j, double** %beta_k, double** %rhs)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %177)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %179 = load i32, i32* %.omp.iv, align 4
  %add186 = add nsw i32 %179, 1
  store i32 %add186, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %180 = load i32*, i32** %.global_tid..addr, align 8
  %181 = load i32, i32* %180, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %181)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..14(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_f, i32* dereferenceable(4) %dim_j_f, i32* dereferenceable(4) %dim_i_c, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, double** dereferenceable(8) %res, i32* dereferenceable(4) %dim_i_f, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, double* dereferenceable(8) %a, double** dereferenceable(8) %alpha, double** dereferenceable(8) %phi, double* dereferenceable(8) %b, double* dereferenceable(8) %h2inv, double** dereferenceable(8) %beta_i, double** dereferenceable(8) %beta_j, double** dereferenceable(8) %beta_k, double** dereferenceable(8) %rhs) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_f.addr = alloca i32*, align 8
  %dim_j_f.addr = alloca i32*, align 8
  %dim_i_c.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %res.addr = alloca double**, align 8
  %dim_i_f.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %a.addr = alloca double*, align 8
  %alpha.addr = alloca double**, align 8
  %phi.addr = alloca double**, align 8
  %b.addr = alloca double*, align 8
  %h2inv.addr = alloca double*, align 8
  %beta_i.addr = alloca double**, align 8
  %beta_j.addr = alloca double**, align 8
  %beta_k.addr = alloca double**, align 8
  %rhs.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %kk = alloca i32, align 4
  %jj = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %kk13 = alloca i32, align 4
  %jj14 = alloca i32, align 4
  %kk15 = alloca i32, align 4
  %jj16 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  %ijk_c63 = alloca i32, align 4
  %helmholtz = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_f, i32** %dim_k_f.addr, align 8
  store i32* %dim_j_f, i32** %dim_j_f.addr, align 8
  store i32* %dim_i_c, i32** %dim_i_c.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store double** %res, double*** %res.addr, align 8
  store i32* %dim_i_f, i32** %dim_i_f.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double** %alpha, double*** %alpha.addr, align 8
  store double** %phi, double*** %phi.addr, align 8
  store double* %b, double** %b.addr, align 8
  store double* %h2inv, double** %h2inv.addr, align 8
  store double** %beta_i, double*** %beta_i.addr, align 8
  store double** %beta_j, double*** %beta_j.addr, align 8
  store double** %beta_k, double*** %beta_k.addr, align 8
  store double** %rhs, double*** %rhs.addr, align 8
  %0 = load i32*, i32** %dim_k_f.addr, align 8
  %1 = load i32*, i32** %dim_j_f.addr, align 8
  %2 = load i32*, i32** %dim_i_c.addr, align 8
  %3 = load i32*, i32** %pencil_c.addr, align 8
  %4 = load i32*, i32** %plane_c.addr, align 8
  %5 = load double**, double*** %res.addr, align 8
  %6 = load i32*, i32** %dim_i_f.addr, align 8
  %7 = load i32*, i32** %pencil_f.addr, align 8
  %8 = load i32*, i32** %plane_f.addr, align 8
  %9 = load double*, double** %a.addr, align 8
  %10 = load double**, double*** %alpha.addr, align 8
  %11 = load double**, double*** %phi.addr, align 8
  %12 = load double*, double** %b.addr, align 8
  %13 = load double*, double** %h2inv.addr, align 8
  %14 = load double**, double*** %beta_i.addr, align 8
  %15 = load double**, double*** %beta_j.addr, align 8
  %16 = load double**, double*** %beta_k.addr, align 8
  %17 = load double**, double*** %rhs.addr, align 8
  %18 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %18, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 2
  %div = sdiv i32 %add, 2
  %conv = sext i32 %div to i64
  %19 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %19, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 2
  %div5 = sdiv i32 %add4, 2
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %kk, align 4
  store i32 0, i32* %jj, align 4
  %20 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %20
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %21 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %21
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %22 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %22, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %23 = load i32*, i32** %.global_tid..addr, align 8
  %24 = load i32, i32* %23, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %24, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %25 = load i64, i64* %.omp.ub, align 8
  %26 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %25, %26
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %27 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %28 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %27, %cond.true ], [ %28, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %29 = load i64, i64* %.omp.lb, align 8
  store i64 %29, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %30 = load i64, i64* %.omp.iv, align 8
  %31 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %30, %31
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %32 = load i64, i64* %.omp.iv, align 8
  %33 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %33, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 2
  %div24 = sdiv i32 %add23, 2
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %32, %conv25
  %mul27 = mul nsw i64 %div26, 2
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %kk13, align 4
  %34 = load i64, i64* %.omp.iv, align 8
  %35 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %35, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 2
  %div33 = sdiv i32 %add32, 2
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %34, %conv34
  %mul35 = mul nsw i64 %rem, 2
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %jj14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %36 = load i32, i32* %i, align 4
  %37 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %36, %37
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %38 = load i32, i32* %i, align 4
  %39 = load i32, i32* %jj14, align 4
  %shr = ashr i32 %39, 1
  %40 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %shr, %40
  %add41 = add nsw i32 %38, %mul40
  %41 = load i32, i32* %kk13, align 4
  %shr42 = ashr i32 %41, 1
  %42 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %shr42, %42
  %add44 = add nsw i32 %add41, %mul43
  store i32 %add44, i32* %ijk_c, align 4
  %43 = load i32, i32* %ijk_c, align 4
  %idxprom = sext i32 %43 to i64
  %44 = load double*, double** %5, align 8
  %arrayidx = getelementptr inbounds double, double* %44, i64 %idxprom
  store double 0.000000e+00, double* %arrayidx, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %45 = load i32, i32* %i, align 4
  %inc = add nsw i32 %45, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %46 = load i32, i32* %kk13, align 4
  store i32 %46, i32* %k, align 4
  br label %for.cond45

for.cond45:                                       ; preds = %for.inc155, %for.end
  %47 = load i32, i32* %k, align 4
  %48 = load i32, i32* %kk13, align 4
  %add46 = add nsw i32 %48, 2
  %cmp47 = icmp slt i32 %47, %add46
  br i1 %cmp47, label %for.body49, label %for.end157

for.body49:                                       ; preds = %for.cond45
  %49 = load i32, i32* %jj14, align 4
  store i32 %49, i32* %j, align 4
  br label %for.cond50

for.cond50:                                       ; preds = %for.inc152, %for.body49
  %50 = load i32, i32* %j, align 4
  %51 = load i32, i32* %jj14, align 4
  %add51 = add nsw i32 %51, 2
  %cmp52 = icmp slt i32 %50, %add51
  br i1 %cmp52, label %for.body54, label %for.end154

for.body54:                                       ; preds = %for.cond50
  store i32 0, i32* %i, align 4
  br label %for.cond55

for.cond55:                                       ; preds = %for.inc149, %for.body54
  %52 = load i32, i32* %i, align 4
  %53 = load i32, i32* %6, align 4
  %cmp56 = icmp slt i32 %52, %53
  br i1 %cmp56, label %for.body58, label %for.end151

for.body58:                                       ; preds = %for.cond55
  %54 = load i32, i32* %i, align 4
  %55 = load i32, i32* %j, align 4
  %56 = load i32, i32* %7, align 4
  %mul59 = mul nsw i32 %55, %56
  %add60 = add nsw i32 %54, %mul59
  %57 = load i32, i32* %k, align 4
  %58 = load i32, i32* %8, align 4
  %mul61 = mul nsw i32 %57, %58
  %add62 = add nsw i32 %add60, %mul61
  store i32 %add62, i32* %ijk_f, align 4
  %59 = load i32, i32* %i, align 4
  %shr64 = ashr i32 %59, 1
  %60 = load i32, i32* %j, align 4
  %shr65 = ashr i32 %60, 1
  %61 = load i32, i32* %3, align 4
  %mul66 = mul nsw i32 %shr65, %61
  %add67 = add nsw i32 %shr64, %mul66
  %62 = load i32, i32* %k, align 4
  %shr68 = ashr i32 %62, 1
  %63 = load i32, i32* %4, align 4
  %mul69 = mul nsw i32 %shr68, %63
  %add70 = add nsw i32 %add67, %mul69
  store i32 %add70, i32* %ijk_c63, align 4
  %64 = load double, double* %9, align 8
  %65 = load i32, i32* %ijk_f, align 4
  %idxprom71 = sext i32 %65 to i64
  %66 = load double*, double** %10, align 8
  %arrayidx72 = getelementptr inbounds double, double* %66, i64 %idxprom71
  %67 = load double, double* %arrayidx72, align 8
  %mul73 = fmul double %64, %67
  %68 = load i32, i32* %ijk_f, align 4
  %idxprom74 = sext i32 %68 to i64
  %69 = load double*, double** %11, align 8
  %arrayidx75 = getelementptr inbounds double, double* %69, i64 %idxprom74
  %70 = load double, double* %arrayidx75, align 8
  %mul76 = fmul double %mul73, %70
  %71 = load double, double* %12, align 8
  %72 = load double, double* %13, align 8
  %mul77 = fmul double %71, %72
  %73 = load i32, i32* %ijk_f, align 4
  %add78 = add nsw i32 %73, 1
  %idxprom79 = sext i32 %add78 to i64
  %74 = load double*, double** %14, align 8
  %arrayidx80 = getelementptr inbounds double, double* %74, i64 %idxprom79
  %75 = load double, double* %arrayidx80, align 8
  %76 = load i32, i32* %ijk_f, align 4
  %add81 = add nsw i32 %76, 1
  %idxprom82 = sext i32 %add81 to i64
  %77 = load double*, double** %11, align 8
  %arrayidx83 = getelementptr inbounds double, double* %77, i64 %idxprom82
  %78 = load double, double* %arrayidx83, align 8
  %79 = load i32, i32* %ijk_f, align 4
  %idxprom84 = sext i32 %79 to i64
  %80 = load double*, double** %11, align 8
  %arrayidx85 = getelementptr inbounds double, double* %80, i64 %idxprom84
  %81 = load double, double* %arrayidx85, align 8
  %sub86 = fsub double %78, %81
  %mul87 = fmul double %75, %sub86
  %82 = load i32, i32* %ijk_f, align 4
  %idxprom88 = sext i32 %82 to i64
  %83 = load double*, double** %14, align 8
  %arrayidx89 = getelementptr inbounds double, double* %83, i64 %idxprom88
  %84 = load double, double* %arrayidx89, align 8
  %85 = load i32, i32* %ijk_f, align 4
  %idxprom90 = sext i32 %85 to i64
  %86 = load double*, double** %11, align 8
  %arrayidx91 = getelementptr inbounds double, double* %86, i64 %idxprom90
  %87 = load double, double* %arrayidx91, align 8
  %88 = load i32, i32* %ijk_f, align 4
  %sub92 = sub nsw i32 %88, 1
  %idxprom93 = sext i32 %sub92 to i64
  %89 = load double*, double** %11, align 8
  %arrayidx94 = getelementptr inbounds double, double* %89, i64 %idxprom93
  %90 = load double, double* %arrayidx94, align 8
  %sub95 = fsub double %87, %90
  %mul96 = fmul double %84, %sub95
  %sub97 = fsub double %mul87, %mul96
  %91 = load i32, i32* %ijk_f, align 4
  %92 = load i32, i32* %7, align 4
  %add98 = add nsw i32 %91, %92
  %idxprom99 = sext i32 %add98 to i64
  %93 = load double*, double** %15, align 8
  %arrayidx100 = getelementptr inbounds double, double* %93, i64 %idxprom99
  %94 = load double, double* %arrayidx100, align 8
  %95 = load i32, i32* %ijk_f, align 4
  %96 = load i32, i32* %7, align 4
  %add101 = add nsw i32 %95, %96
  %idxprom102 = sext i32 %add101 to i64
  %97 = load double*, double** %11, align 8
  %arrayidx103 = getelementptr inbounds double, double* %97, i64 %idxprom102
  %98 = load double, double* %arrayidx103, align 8
  %99 = load i32, i32* %ijk_f, align 4
  %idxprom104 = sext i32 %99 to i64
  %100 = load double*, double** %11, align 8
  %arrayidx105 = getelementptr inbounds double, double* %100, i64 %idxprom104
  %101 = load double, double* %arrayidx105, align 8
  %sub106 = fsub double %98, %101
  %mul107 = fmul double %94, %sub106
  %add108 = fadd double %sub97, %mul107
  %102 = load i32, i32* %ijk_f, align 4
  %idxprom109 = sext i32 %102 to i64
  %103 = load double*, double** %15, align 8
  %arrayidx110 = getelementptr inbounds double, double* %103, i64 %idxprom109
  %104 = load double, double* %arrayidx110, align 8
  %105 = load i32, i32* %ijk_f, align 4
  %idxprom111 = sext i32 %105 to i64
  %106 = load double*, double** %11, align 8
  %arrayidx112 = getelementptr inbounds double, double* %106, i64 %idxprom111
  %107 = load double, double* %arrayidx112, align 8
  %108 = load i32, i32* %ijk_f, align 4
  %109 = load i32, i32* %7, align 4
  %sub113 = sub nsw i32 %108, %109
  %idxprom114 = sext i32 %sub113 to i64
  %110 = load double*, double** %11, align 8
  %arrayidx115 = getelementptr inbounds double, double* %110, i64 %idxprom114
  %111 = load double, double* %arrayidx115, align 8
  %sub116 = fsub double %107, %111
  %mul117 = fmul double %104, %sub116
  %sub118 = fsub double %add108, %mul117
  %112 = load i32, i32* %ijk_f, align 4
  %113 = load i32, i32* %8, align 4
  %add119 = add nsw i32 %112, %113
  %idxprom120 = sext i32 %add119 to i64
  %114 = load double*, double** %16, align 8
  %arrayidx121 = getelementptr inbounds double, double* %114, i64 %idxprom120
  %115 = load double, double* %arrayidx121, align 8
  %116 = load i32, i32* %ijk_f, align 4
  %117 = load i32, i32* %8, align 4
  %add122 = add nsw i32 %116, %117
  %idxprom123 = sext i32 %add122 to i64
  %118 = load double*, double** %11, align 8
  %arrayidx124 = getelementptr inbounds double, double* %118, i64 %idxprom123
  %119 = load double, double* %arrayidx124, align 8
  %120 = load i32, i32* %ijk_f, align 4
  %idxprom125 = sext i32 %120 to i64
  %121 = load double*, double** %11, align 8
  %arrayidx126 = getelementptr inbounds double, double* %121, i64 %idxprom125
  %122 = load double, double* %arrayidx126, align 8
  %sub127 = fsub double %119, %122
  %mul128 = fmul double %115, %sub127
  %add129 = fadd double %sub118, %mul128
  %123 = load i32, i32* %ijk_f, align 4
  %idxprom130 = sext i32 %123 to i64
  %124 = load double*, double** %16, align 8
  %arrayidx131 = getelementptr inbounds double, double* %124, i64 %idxprom130
  %125 = load double, double* %arrayidx131, align 8
  %126 = load i32, i32* %ijk_f, align 4
  %idxprom132 = sext i32 %126 to i64
  %127 = load double*, double** %11, align 8
  %arrayidx133 = getelementptr inbounds double, double* %127, i64 %idxprom132
  %128 = load double, double* %arrayidx133, align 8
  %129 = load i32, i32* %ijk_f, align 4
  %130 = load i32, i32* %8, align 4
  %sub134 = sub nsw i32 %129, %130
  %idxprom135 = sext i32 %sub134 to i64
  %131 = load double*, double** %11, align 8
  %arrayidx136 = getelementptr inbounds double, double* %131, i64 %idxprom135
  %132 = load double, double* %arrayidx136, align 8
  %sub137 = fsub double %128, %132
  %mul138 = fmul double %125, %sub137
  %sub139 = fsub double %add129, %mul138
  %mul140 = fmul double %mul77, %sub139
  %sub141 = fsub double %mul76, %mul140
  store double %sub141, double* %helmholtz, align 8
  %133 = load i32, i32* %ijk_f, align 4
  %idxprom142 = sext i32 %133 to i64
  %134 = load double*, double** %17, align 8
  %arrayidx143 = getelementptr inbounds double, double* %134, i64 %idxprom142
  %135 = load double, double* %arrayidx143, align 8
  %136 = load double, double* %helmholtz, align 8
  %sub144 = fsub double %135, %136
  %mul145 = fmul double %sub144, 1.250000e-01
  %137 = load i32, i32* %ijk_c63, align 4
  %idxprom146 = sext i32 %137 to i64
  %138 = load double*, double** %5, align 8
  %arrayidx147 = getelementptr inbounds double, double* %138, i64 %idxprom146
  %139 = load double, double* %arrayidx147, align 8
  %add148 = fadd double %139, %mul145
  store double %add148, double* %arrayidx147, align 8
  br label %for.inc149

for.inc149:                                       ; preds = %for.body58
  %140 = load i32, i32* %i, align 4
  %inc150 = add nsw i32 %140, 1
  store i32 %inc150, i32* %i, align 4
  br label %for.cond55

for.end151:                                       ; preds = %for.cond55
  br label %for.inc152

for.inc152:                                       ; preds = %for.end151
  %141 = load i32, i32* %j, align 4
  %inc153 = add nsw i32 %141, 1
  store i32 %inc153, i32* %j, align 4
  br label %for.cond50

for.end154:                                       ; preds = %for.cond50
  br label %for.inc155

for.inc155:                                       ; preds = %for.end154
  %142 = load i32, i32* %k, align 4
  %inc156 = add nsw i32 %142, 1
  store i32 %inc156, i32* %k, align 4
  br label %for.cond45

for.end157:                                       ; preds = %for.cond45
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end157
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %143 = load i64, i64* %.omp.iv, align 8
  %add158 = add nsw i64 %143, 1
  store i64 %add158, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %144 = load i32*, i32** %.global_tid..addr, align 8
  %145 = load i32, i32* %144, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %145)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @restriction(%struct.domain_type* %domain, i32 %level_f, i32 %id_c, i32 %id_f) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level_f.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %id_f.addr = alloca i32, align 4
  %level_c = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level_f, i32* %level_f.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  store i32 %id_f, i32* %id_f.addr, align 4
  %1 = load i32, i32* %level_f.addr, align 4
  %add = add nsw i32 %1, 1
  store i32 %add, i32* %level_c, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %2 = load i32, i32* %level_c, align 4
  %idxprom = sext i32 %2 to i64
  %3 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %3, i32 0, i32 25
  %4 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %4, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %5 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %5, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %6 = load i32, i32* %i, align 4
  %7 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %6, %7
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %8 = load i32, i32* %level_c, align 4
  %idxprom2 = sext i32 %8 to i64
  %9 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 25
  %10 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %10, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %11 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %11, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %12 = load i32, i32* %i8, align 4
  %13 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %12, %13
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %14 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %14, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*)* @.omp_outlined..15 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..15(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %15 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %15
  %16 = load i32, i32* %level_f.addr, align 4
  %idxprom12 = sext i32 %16 to i64
  %17 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %17, i32 0, i32 0
  %restriction = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 3
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %restriction, i64 0, i64 %idxprom12
  %18 = load i64, i64* %arrayidx13, align 8
  %add14 = add i64 %18, %sub
  store i64 %add14, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..15(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level_c, i32* dereferenceable(4) %level_f, i32* dereferenceable(4) %id_f, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %omp_within_a_box) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level_c.addr = alloca i32*, align 8
  %level_f.addr = alloca i32*, align 8
  %id_f.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %ghosts_c = alloca i32, align 4
  %pencil_c = alloca i32, align 4
  %plane_c = alloca i32, align 4
  %dim_i_c = alloca i32, align 4
  %dim_j_c = alloca i32, align 4
  %dim_k_c = alloca i32, align 4
  %ghosts_f = alloca i32, align 4
  %pencil_f = alloca i32, align 4
  %plane_f = alloca i32, align 4
  %grid_f = alloca double*, align 8
  %grid_c = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level_c, i32** %level_c.addr, align 8
  store i32* %level_f, i32** %level_f.addr, align 8
  store i32* %id_f, i32** %id_f.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level_c.addr, align 8
  %2 = load i32*, i32** %level_f.addr, align 8
  %3 = load i32*, i32** %id_f.addr, align 8
  %4 = load i32*, i32** %id_c.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %13, %14
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %18, %19
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 4
  %26 = load i32, i32* %ghosts, align 4
  store i32 %26, i32* %ghosts_c, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom11 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom12 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom11
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 5
  %32 = load i32, i32* %pencil, align 8
  store i32 %32, i32* %pencil_c, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom17 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom18 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains19, align 8
  %arrayidx20 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom18
  %levels21 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx20, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels21, align 8
  %arrayidx22 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom17
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx22, i32 0, i32 6
  %38 = load i32, i32* %plane, align 4
  store i32 %38, i32* %plane_c, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom23 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom24 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains25 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains25, align 8
  %arrayidx26 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom24
  %levels27 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx26, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels27, align 8
  %arrayidx28 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom23
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx28, i32 0, i32 2
  %i29 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %44 = load i32, i32* %i29, align 4
  store i32 %44, i32* %dim_i_c, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom30 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom31 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains32 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains32, align 8
  %arrayidx33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom31
  %levels34 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx33, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels34, align 8
  %arrayidx35 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom30
  %dim36 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx35, i32 0, i32 2
  %j37 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim36, i32 0, i32 1
  %50 = load i32, i32* %j37, align 4
  store i32 %50, i32* %dim_j_c, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom38 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom39 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains40 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains40, align 8
  %arrayidx41 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom39
  %levels42 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx41, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels42, align 8
  %arrayidx43 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom38
  %dim44 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx43, i32 0, i32 2
  %k45 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim44, i32 0, i32 2
  %56 = load i32, i32* %k45, align 4
  store i32 %56, i32* %dim_k_c, align 4
  %57 = load i32, i32* %2, align 4
  %idxprom46 = sext i32 %57 to i64
  %58 = load i32, i32* %box4, align 4
  %idxprom47 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains48 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 25
  %60 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains48, align 8
  %arrayidx49 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %60, i64 %idxprom47
  %levels50 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx49, i32 0, i32 5
  %61 = load %struct.box_type*, %struct.box_type** %levels50, align 8
  %arrayidx51 = getelementptr inbounds %struct.box_type, %struct.box_type* %61, i64 %idxprom46
  %ghosts52 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx51, i32 0, i32 4
  %62 = load i32, i32* %ghosts52, align 4
  store i32 %62, i32* %ghosts_f, align 4
  %63 = load i32, i32* %2, align 4
  %idxprom53 = sext i32 %63 to i64
  %64 = load i32, i32* %box4, align 4
  %idxprom54 = sext i32 %64 to i64
  %65 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains55 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %65, i32 0, i32 25
  %66 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains55, align 8
  %arrayidx56 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %66, i64 %idxprom54
  %levels57 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx56, i32 0, i32 5
  %67 = load %struct.box_type*, %struct.box_type** %levels57, align 8
  %arrayidx58 = getelementptr inbounds %struct.box_type, %struct.box_type* %67, i64 %idxprom53
  %pencil59 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx58, i32 0, i32 5
  %68 = load i32, i32* %pencil59, align 8
  store i32 %68, i32* %pencil_f, align 4
  %69 = load i32, i32* %2, align 4
  %idxprom60 = sext i32 %69 to i64
  %70 = load i32, i32* %box4, align 4
  %idxprom61 = sext i32 %70 to i64
  %71 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains62 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %71, i32 0, i32 25
  %72 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains62, align 8
  %arrayidx63 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %72, i64 %idxprom61
  %levels64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx63, i32 0, i32 5
  %73 = load %struct.box_type*, %struct.box_type** %levels64, align 8
  %arrayidx65 = getelementptr inbounds %struct.box_type, %struct.box_type* %73, i64 %idxprom60
  %plane66 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx65, i32 0, i32 6
  %74 = load i32, i32* %plane66, align 4
  store i32 %74, i32* %plane_f, align 4
  %75 = load i32, i32* %3, align 4
  %idxprom67 = sext i32 %75 to i64
  %76 = load i32, i32* %2, align 4
  %idxprom68 = sext i32 %76 to i64
  %77 = load i32, i32* %box4, align 4
  %idxprom69 = sext i32 %77 to i64
  %78 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains70 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %78, i32 0, i32 25
  %79 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains70, align 8
  %arrayidx71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %79, i64 %idxprom69
  %levels72 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx71, i32 0, i32 5
  %80 = load %struct.box_type*, %struct.box_type** %levels72, align 8
  %arrayidx73 = getelementptr inbounds %struct.box_type, %struct.box_type* %80, i64 %idxprom68
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx73, i32 0, i32 10
  %81 = load double**, double*** %grids, align 8
  %arrayidx74 = getelementptr inbounds double*, double** %81, i64 %idxprom67
  %82 = load double*, double** %arrayidx74, align 8
  %83 = load i32, i32* %ghosts_f, align 4
  %84 = load i32, i32* %pencil_f, align 4
  %add75 = add nsw i32 1, %84
  %85 = load i32, i32* %plane_f, align 4
  %add76 = add nsw i32 %add75, %85
  %mul77 = mul nsw i32 %83, %add76
  %idx.ext = sext i32 %mul77 to i64
  %add.ptr = getelementptr inbounds double, double* %82, i64 %idx.ext
  store double* %add.ptr, double** %grid_f, align 8
  %86 = load i32, i32* %4, align 4
  %idxprom78 = sext i32 %86 to i64
  %87 = load i32, i32* %1, align 4
  %idxprom79 = sext i32 %87 to i64
  %88 = load i32, i32* %box4, align 4
  %idxprom80 = sext i32 %88 to i64
  %89 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains81 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %89, i32 0, i32 25
  %90 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains81, align 8
  %arrayidx82 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %90, i64 %idxprom80
  %levels83 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx82, i32 0, i32 5
  %91 = load %struct.box_type*, %struct.box_type** %levels83, align 8
  %arrayidx84 = getelementptr inbounds %struct.box_type, %struct.box_type* %91, i64 %idxprom79
  %grids85 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx84, i32 0, i32 10
  %92 = load double**, double*** %grids85, align 8
  %arrayidx86 = getelementptr inbounds double*, double** %92, i64 %idxprom78
  %93 = load double*, double** %arrayidx86, align 8
  %94 = load i32, i32* %ghosts_c, align 4
  %95 = load i32, i32* %pencil_c, align 4
  %add87 = add nsw i32 1, %95
  %96 = load i32, i32* %plane_c, align 4
  %add88 = add nsw i32 %add87, %96
  %mul89 = mul nsw i32 %94, %add88
  %idx.ext90 = sext i32 %mul89 to i64
  %add.ptr91 = getelementptr inbounds double, double* %93, i64 %idx.ext90
  store double* %add.ptr91, double** %grid_c, align 8
  %97 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %97, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**)* @.omp_outlined..16 to void (i32*, i32*, ...)*), i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %grid_c, double** %grid_f)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %98 = load i32*, i32** %.global_tid..addr, align 8
  %99 = load i32, i32* %98, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %99)
  %100 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..16(i32* %100, i32* %.zero.addr, i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %grid_c, double** %grid_f)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %99)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %101 = load i32, i32* %.omp.iv, align 4
  %add92 = add nsw i32 %101, 1
  store i32 %add92, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %102 = load i32*, i32** %.global_tid..addr, align 8
  %103 = load i32, i32* %102, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %103)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..16(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_c, i32* dereferenceable(4) %dim_j_c, i32* dereferenceable(4) %dim_i_c, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, double** dereferenceable(8) %grid_c, double** dereferenceable(8) %grid_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_c.addr = alloca i32*, align 8
  %dim_j_c.addr = alloca i32*, align 8
  %dim_i_c.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %grid_c.addr = alloca double**, align 8
  %grid_f.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_c, i32** %dim_k_c.addr, align 8
  store i32* %dim_j_c, i32** %dim_j_c.addr, align 8
  store i32* %dim_i_c, i32** %dim_i_c.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  store double** %grid_f, double*** %grid_f.addr, align 8
  %0 = load i32*, i32** %dim_k_c.addr, align 8
  %1 = load i32*, i32** %dim_j_c.addr, align 8
  %2 = load i32*, i32** %dim_i_c.addr, align 8
  %3 = load i32*, i32** %pencil_c.addr, align 8
  %4 = load i32*, i32** %plane_c.addr, align 8
  %5 = load i32*, i32** %pencil_f.addr, align 8
  %6 = load i32*, i32** %plane_f.addr, align 8
  %7 = load double**, double*** %grid_c.addr, align 8
  %8 = load double**, double*** %grid_f.addr, align 8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %10, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %11 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %12 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %12
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %13 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %13, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %16 = load i64, i64* %.omp.ub, align 8
  %17 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %16, %17
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %18, %cond.true ], [ %19, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %20 = load i64, i64* %.omp.lb, align 8
  store i64 %20, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %21, %22
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %24, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %23, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %25 = load i64, i64* %.omp.iv, align 8
  %26 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %26, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %25, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %27, %28
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %29 = load i32, i32* %i, align 4
  %30 = load i32, i32* %j14, align 4
  %31 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %30, %31
  %add41 = add nsw i32 %29, %mul40
  %32 = load i32, i32* %k13, align 4
  %33 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %32, %33
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_c, align 4
  %34 = load i32, i32* %i, align 4
  %shl = shl i32 %34, 1
  %35 = load i32, i32* %j14, align 4
  %shl44 = shl i32 %35, 1
  %36 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shl44, %36
  %add46 = add nsw i32 %shl, %mul45
  %37 = load i32, i32* %k13, align 4
  %shl47 = shl i32 %37, 1
  %38 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shl47, %38
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_f, align 4
  %39 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %39 to i64
  %40 = load double*, double** %8, align 8
  %arrayidx = getelementptr inbounds double, double* %40, i64 %idxprom
  %41 = load double, double* %arrayidx, align 8
  %42 = load i32, i32* %ijk_f, align 4
  %add50 = add nsw i32 %42, 1
  %idxprom51 = sext i32 %add50 to i64
  %43 = load double*, double** %8, align 8
  %arrayidx52 = getelementptr inbounds double, double* %43, i64 %idxprom51
  %44 = load double, double* %arrayidx52, align 8
  %add53 = fadd double %41, %44
  %45 = load i32, i32* %ijk_f, align 4
  %46 = load i32, i32* %5, align 4
  %add54 = add nsw i32 %45, %46
  %idxprom55 = sext i32 %add54 to i64
  %47 = load double*, double** %8, align 8
  %arrayidx56 = getelementptr inbounds double, double* %47, i64 %idxprom55
  %48 = load double, double* %arrayidx56, align 8
  %add57 = fadd double %add53, %48
  %49 = load i32, i32* %ijk_f, align 4
  %add58 = add nsw i32 %49, 1
  %50 = load i32, i32* %5, align 4
  %add59 = add nsw i32 %add58, %50
  %idxprom60 = sext i32 %add59 to i64
  %51 = load double*, double** %8, align 8
  %arrayidx61 = getelementptr inbounds double, double* %51, i64 %idxprom60
  %52 = load double, double* %arrayidx61, align 8
  %add62 = fadd double %add57, %52
  %53 = load i32, i32* %ijk_f, align 4
  %54 = load i32, i32* %6, align 4
  %add63 = add nsw i32 %53, %54
  %idxprom64 = sext i32 %add63 to i64
  %55 = load double*, double** %8, align 8
  %arrayidx65 = getelementptr inbounds double, double* %55, i64 %idxprom64
  %56 = load double, double* %arrayidx65, align 8
  %add66 = fadd double %add62, %56
  %57 = load i32, i32* %ijk_f, align 4
  %add67 = add nsw i32 %57, 1
  %58 = load i32, i32* %6, align 4
  %add68 = add nsw i32 %add67, %58
  %idxprom69 = sext i32 %add68 to i64
  %59 = load double*, double** %8, align 8
  %arrayidx70 = getelementptr inbounds double, double* %59, i64 %idxprom69
  %60 = load double, double* %arrayidx70, align 8
  %add71 = fadd double %add66, %60
  %61 = load i32, i32* %ijk_f, align 4
  %62 = load i32, i32* %5, align 4
  %add72 = add nsw i32 %61, %62
  %63 = load i32, i32* %6, align 4
  %add73 = add nsw i32 %add72, %63
  %idxprom74 = sext i32 %add73 to i64
  %64 = load double*, double** %8, align 8
  %arrayidx75 = getelementptr inbounds double, double* %64, i64 %idxprom74
  %65 = load double, double* %arrayidx75, align 8
  %add76 = fadd double %add71, %65
  %66 = load i32, i32* %ijk_f, align 4
  %add77 = add nsw i32 %66, 1
  %67 = load i32, i32* %5, align 4
  %add78 = add nsw i32 %add77, %67
  %68 = load i32, i32* %6, align 4
  %add79 = add nsw i32 %add78, %68
  %idxprom80 = sext i32 %add79 to i64
  %69 = load double*, double** %8, align 8
  %arrayidx81 = getelementptr inbounds double, double* %69, i64 %idxprom80
  %70 = load double, double* %arrayidx81, align 8
  %add82 = fadd double %add76, %70
  %mul83 = fmul double %add82, 1.250000e-01
  %71 = load i32, i32* %ijk_c, align 4
  %idxprom84 = sext i32 %71 to i64
  %72 = load double*, double** %7, align 8
  %arrayidx85 = getelementptr inbounds double, double* %72, i64 %idxprom84
  store double %mul83, double* %arrayidx85, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %73 = load i32, i32* %i, align 4
  %inc = add nsw i32 %73, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %74 = load i64, i64* %.omp.iv, align 8
  %add86 = add nsw i64 %74, 1
  store i64 %add86, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %75 = load i32*, i32** %.global_tid..addr, align 8
  %76 = load i32, i32* %75, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %76)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @restriction_betas(%struct.domain_type* %domain, i32 %level_f, i32 %level_c) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level_f.addr = alloca i32, align 4
  %level_c.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level_f, i32* %level_f.addr, align 4
  store i32 %level_c, i32* %level_c.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level_c.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level_c.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 4, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*)* @.omp_outlined..17 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level_c.addr, i32* %level_f.addr, i32* %omp_within_a_box)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..17(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level_c.addr, i32* %level_f.addr, i32* %omp_within_a_box)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level_f.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %restriction = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 3
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %restriction, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..17(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level_c, i32* dereferenceable(4) %level_f, i32* dereferenceable(4) %omp_within_a_box) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level_c.addr = alloca i32*, align 8
  %level_f.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %ghosts_c = alloca i32, align 4
  %pencil_c = alloca i32, align 4
  %plane_c = alloca i32, align 4
  %dim_i_c = alloca i32, align 4
  %dim_j_c = alloca i32, align 4
  %dim_k_c = alloca i32, align 4
  %ghosts_f = alloca i32, align 4
  %pencil_f = alloca i32, align 4
  %plane_f = alloca i32, align 4
  %beta_f = alloca double*, align 8
  %beta_c = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  %.zero.addr131 = alloca i32, align 4
  %.zero.addr168 = alloca i32, align 4
  store i32 0, i32* %.zero.addr168, align 4
  store i32 0, i32* %.zero.addr131, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level_c, i32** %level_c.addr, align 8
  store i32* %level_f, i32** %level_f.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level_c.addr, align 8
  %2 = load i32*, i32** %level_f.addr, align 8
  %3 = load i32*, i32** %omp_within_a_box.addr, align 8
  %4 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %4, i32 0, i32 19
  %5 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %5, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %7
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %8 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %8, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %9 = load i32*, i32** %.global_tid..addr, align 8
  %10 = load i32, i32* %9, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %10, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %11 = load i32, i32* %.omp.ub, align 4
  %12 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %11, %12
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %13 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %14 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %13, %cond.true ], [ %14, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.lb, align 4
  store i32 %15, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %16 = load i32, i32* %.omp.iv, align 4
  %17 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %16, %17
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %18 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %18, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %19 = load i32, i32* %1, align 4
  %idxprom = sext i32 %19 to i64
  %20 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %20 to i64
  %21 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %21, i32 0, i32 25
  %22 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %22, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %23 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %23, i64 %idxprom
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 4
  %24 = load i32, i32* %ghosts, align 4
  store i32 %24, i32* %ghosts_c, align 4
  %25 = load i32, i32* %1, align 4
  %idxprom11 = sext i32 %25 to i64
  %26 = load i32, i32* %box4, align 4
  %idxprom12 = sext i32 %26 to i64
  %27 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %27, i32 0, i32 25
  %28 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %28, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %29 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %29, i64 %idxprom11
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 5
  %30 = load i32, i32* %pencil, align 8
  store i32 %30, i32* %pencil_c, align 4
  %31 = load i32, i32* %1, align 4
  %idxprom17 = sext i32 %31 to i64
  %32 = load i32, i32* %box4, align 4
  %idxprom18 = sext i32 %32 to i64
  %33 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %33, i32 0, i32 25
  %34 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains19, align 8
  %arrayidx20 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %34, i64 %idxprom18
  %levels21 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx20, i32 0, i32 5
  %35 = load %struct.box_type*, %struct.box_type** %levels21, align 8
  %arrayidx22 = getelementptr inbounds %struct.box_type, %struct.box_type* %35, i64 %idxprom17
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx22, i32 0, i32 6
  %36 = load i32, i32* %plane, align 4
  store i32 %36, i32* %plane_c, align 4
  %37 = load i32, i32* %1, align 4
  %idxprom23 = sext i32 %37 to i64
  %38 = load i32, i32* %box4, align 4
  %idxprom24 = sext i32 %38 to i64
  %39 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains25 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %39, i32 0, i32 25
  %40 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains25, align 8
  %arrayidx26 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %40, i64 %idxprom24
  %levels27 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx26, i32 0, i32 5
  %41 = load %struct.box_type*, %struct.box_type** %levels27, align 8
  %arrayidx28 = getelementptr inbounds %struct.box_type, %struct.box_type* %41, i64 %idxprom23
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx28, i32 0, i32 2
  %i29 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %42 = load i32, i32* %i29, align 4
  store i32 %42, i32* %dim_i_c, align 4
  %43 = load i32, i32* %1, align 4
  %idxprom30 = sext i32 %43 to i64
  %44 = load i32, i32* %box4, align 4
  %idxprom31 = sext i32 %44 to i64
  %45 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains32 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %45, i32 0, i32 25
  %46 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains32, align 8
  %arrayidx33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %46, i64 %idxprom31
  %levels34 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx33, i32 0, i32 5
  %47 = load %struct.box_type*, %struct.box_type** %levels34, align 8
  %arrayidx35 = getelementptr inbounds %struct.box_type, %struct.box_type* %47, i64 %idxprom30
  %dim36 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx35, i32 0, i32 2
  %j37 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim36, i32 0, i32 1
  %48 = load i32, i32* %j37, align 4
  store i32 %48, i32* %dim_j_c, align 4
  %49 = load i32, i32* %1, align 4
  %idxprom38 = sext i32 %49 to i64
  %50 = load i32, i32* %box4, align 4
  %idxprom39 = sext i32 %50 to i64
  %51 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains40 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %51, i32 0, i32 25
  %52 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains40, align 8
  %arrayidx41 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %52, i64 %idxprom39
  %levels42 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx41, i32 0, i32 5
  %53 = load %struct.box_type*, %struct.box_type** %levels42, align 8
  %arrayidx43 = getelementptr inbounds %struct.box_type, %struct.box_type* %53, i64 %idxprom38
  %dim44 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx43, i32 0, i32 2
  %k45 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim44, i32 0, i32 2
  %54 = load i32, i32* %k45, align 4
  store i32 %54, i32* %dim_k_c, align 4
  %55 = load i32, i32* %2, align 4
  %idxprom46 = sext i32 %55 to i64
  %56 = load i32, i32* %box4, align 4
  %idxprom47 = sext i32 %56 to i64
  %57 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains48 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %57, i32 0, i32 25
  %58 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains48, align 8
  %arrayidx49 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %58, i64 %idxprom47
  %levels50 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx49, i32 0, i32 5
  %59 = load %struct.box_type*, %struct.box_type** %levels50, align 8
  %arrayidx51 = getelementptr inbounds %struct.box_type, %struct.box_type* %59, i64 %idxprom46
  %ghosts52 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx51, i32 0, i32 4
  %60 = load i32, i32* %ghosts52, align 4
  store i32 %60, i32* %ghosts_f, align 4
  %61 = load i32, i32* %2, align 4
  %idxprom53 = sext i32 %61 to i64
  %62 = load i32, i32* %box4, align 4
  %idxprom54 = sext i32 %62 to i64
  %63 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains55 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %63, i32 0, i32 25
  %64 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains55, align 8
  %arrayidx56 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %64, i64 %idxprom54
  %levels57 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx56, i32 0, i32 5
  %65 = load %struct.box_type*, %struct.box_type** %levels57, align 8
  %arrayidx58 = getelementptr inbounds %struct.box_type, %struct.box_type* %65, i64 %idxprom53
  %pencil59 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx58, i32 0, i32 5
  %66 = load i32, i32* %pencil59, align 8
  store i32 %66, i32* %pencil_f, align 4
  %67 = load i32, i32* %2, align 4
  %idxprom60 = sext i32 %67 to i64
  %68 = load i32, i32* %box4, align 4
  %idxprom61 = sext i32 %68 to i64
  %69 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains62 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %69, i32 0, i32 25
  %70 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains62, align 8
  %arrayidx63 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %70, i64 %idxprom61
  %levels64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx63, i32 0, i32 5
  %71 = load %struct.box_type*, %struct.box_type** %levels64, align 8
  %arrayidx65 = getelementptr inbounds %struct.box_type, %struct.box_type* %71, i64 %idxprom60
  %plane66 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx65, i32 0, i32 6
  %72 = load i32, i32* %plane66, align 4
  store i32 %72, i32* %plane_f, align 4
  %73 = load i32, i32* %2, align 4
  %idxprom67 = sext i32 %73 to i64
  %74 = load i32, i32* %box4, align 4
  %idxprom68 = sext i32 %74 to i64
  %75 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains69 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %75, i32 0, i32 25
  %76 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains69, align 8
  %arrayidx70 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %76, i64 %idxprom68
  %levels71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx70, i32 0, i32 5
  %77 = load %struct.box_type*, %struct.box_type** %levels71, align 8
  %arrayidx72 = getelementptr inbounds %struct.box_type, %struct.box_type* %77, i64 %idxprom67
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx72, i32 0, i32 10
  %78 = load double**, double*** %grids, align 8
  %arrayidx73 = getelementptr inbounds double*, double** %78, i64 5
  %79 = load double*, double** %arrayidx73, align 8
  %80 = load i32, i32* %ghosts_f, align 4
  %81 = load i32, i32* %plane_f, align 4
  %mul74 = mul nsw i32 %80, %81
  %idx.ext = sext i32 %mul74 to i64
  %add.ptr = getelementptr inbounds double, double* %79, i64 %idx.ext
  %82 = load i32, i32* %ghosts_f, align 4
  %83 = load i32, i32* %pencil_f, align 4
  %mul75 = mul nsw i32 %82, %83
  %idx.ext76 = sext i32 %mul75 to i64
  %add.ptr77 = getelementptr inbounds double, double* %add.ptr, i64 %idx.ext76
  %84 = load i32, i32* %ghosts_f, align 4
  %idx.ext78 = sext i32 %84 to i64
  %add.ptr79 = getelementptr inbounds double, double* %add.ptr77, i64 %idx.ext78
  store double* %add.ptr79, double** %beta_f, align 8
  %85 = load i32, i32* %1, align 4
  %idxprom80 = sext i32 %85 to i64
  %86 = load i32, i32* %box4, align 4
  %idxprom81 = sext i32 %86 to i64
  %87 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains82 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %87, i32 0, i32 25
  %88 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains82, align 8
  %arrayidx83 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %88, i64 %idxprom81
  %levels84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx83, i32 0, i32 5
  %89 = load %struct.box_type*, %struct.box_type** %levels84, align 8
  %arrayidx85 = getelementptr inbounds %struct.box_type, %struct.box_type* %89, i64 %idxprom80
  %grids86 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx85, i32 0, i32 10
  %90 = load double**, double*** %grids86, align 8
  %arrayidx87 = getelementptr inbounds double*, double** %90, i64 5
  %91 = load double*, double** %arrayidx87, align 8
  %92 = load i32, i32* %ghosts_c, align 4
  %93 = load i32, i32* %plane_c, align 4
  %mul88 = mul nsw i32 %92, %93
  %idx.ext89 = sext i32 %mul88 to i64
  %add.ptr90 = getelementptr inbounds double, double* %91, i64 %idx.ext89
  %94 = load i32, i32* %ghosts_c, align 4
  %95 = load i32, i32* %pencil_c, align 4
  %mul91 = mul nsw i32 %94, %95
  %idx.ext92 = sext i32 %mul91 to i64
  %add.ptr93 = getelementptr inbounds double, double* %add.ptr90, i64 %idx.ext92
  %96 = load i32, i32* %ghosts_c, align 4
  %idx.ext94 = sext i32 %96 to i64
  %add.ptr95 = getelementptr inbounds double, double* %add.ptr93, i64 %idx.ext94
  store double* %add.ptr95, double** %beta_c, align 8
  %97 = load i32, i32* %3, align 4
  %tobool = icmp ne i32 %97, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**)* @.omp_outlined..18 to void (i32*, i32*, ...)*), i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %98 = load i32*, i32** %.global_tid..addr, align 8
  %99 = load i32, i32* %98, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %99)
  %100 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..18(i32* %100, i32* %.zero.addr, i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %99)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %101 = load i32, i32* %2, align 4
  %idxprom96 = sext i32 %101 to i64
  %102 = load i32, i32* %box4, align 4
  %idxprom97 = sext i32 %102 to i64
  %103 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains98 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %103, i32 0, i32 25
  %104 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains98, align 8
  %arrayidx99 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %104, i64 %idxprom97
  %levels100 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx99, i32 0, i32 5
  %105 = load %struct.box_type*, %struct.box_type** %levels100, align 8
  %arrayidx101 = getelementptr inbounds %struct.box_type, %struct.box_type* %105, i64 %idxprom96
  %grids102 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx101, i32 0, i32 10
  %106 = load double**, double*** %grids102, align 8
  %arrayidx103 = getelementptr inbounds double*, double** %106, i64 6
  %107 = load double*, double** %arrayidx103, align 8
  %108 = load i32, i32* %ghosts_f, align 4
  %109 = load i32, i32* %plane_f, align 4
  %mul104 = mul nsw i32 %108, %109
  %idx.ext105 = sext i32 %mul104 to i64
  %add.ptr106 = getelementptr inbounds double, double* %107, i64 %idx.ext105
  %110 = load i32, i32* %ghosts_f, align 4
  %111 = load i32, i32* %pencil_f, align 4
  %mul107 = mul nsw i32 %110, %111
  %idx.ext108 = sext i32 %mul107 to i64
  %add.ptr109 = getelementptr inbounds double, double* %add.ptr106, i64 %idx.ext108
  %112 = load i32, i32* %ghosts_f, align 4
  %idx.ext110 = sext i32 %112 to i64
  %add.ptr111 = getelementptr inbounds double, double* %add.ptr109, i64 %idx.ext110
  store double* %add.ptr111, double** %beta_f, align 8
  %113 = load i32, i32* %1, align 4
  %idxprom112 = sext i32 %113 to i64
  %114 = load i32, i32* %box4, align 4
  %idxprom113 = sext i32 %114 to i64
  %115 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains114 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %115, i32 0, i32 25
  %116 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains114, align 8
  %arrayidx115 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %116, i64 %idxprom113
  %levels116 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx115, i32 0, i32 5
  %117 = load %struct.box_type*, %struct.box_type** %levels116, align 8
  %arrayidx117 = getelementptr inbounds %struct.box_type, %struct.box_type* %117, i64 %idxprom112
  %grids118 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx117, i32 0, i32 10
  %118 = load double**, double*** %grids118, align 8
  %arrayidx119 = getelementptr inbounds double*, double** %118, i64 6
  %119 = load double*, double** %arrayidx119, align 8
  %120 = load i32, i32* %ghosts_c, align 4
  %121 = load i32, i32* %plane_c, align 4
  %mul120 = mul nsw i32 %120, %121
  %idx.ext121 = sext i32 %mul120 to i64
  %add.ptr122 = getelementptr inbounds double, double* %119, i64 %idx.ext121
  %122 = load i32, i32* %ghosts_c, align 4
  %123 = load i32, i32* %pencil_c, align 4
  %mul123 = mul nsw i32 %122, %123
  %idx.ext124 = sext i32 %mul123 to i64
  %add.ptr125 = getelementptr inbounds double, double* %add.ptr122, i64 %idx.ext124
  %124 = load i32, i32* %ghosts_c, align 4
  %idx.ext126 = sext i32 %124 to i64
  %add.ptr127 = getelementptr inbounds double, double* %add.ptr125, i64 %idx.ext126
  store double* %add.ptr127, double** %beta_c, align 8
  %125 = load i32, i32* %3, align 4
  %tobool128 = icmp ne i32 %125, 0
  br i1 %tobool128, label %omp_if.then129, label %omp_if.else130

omp_if.then129:                                   ; preds = %omp_if.end
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**)* @.omp_outlined..19 to void (i32*, i32*, ...)*), i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  br label %omp_if.end132

omp_if.else130:                                   ; preds = %omp_if.end
  %126 = load i32*, i32** %.global_tid..addr, align 8
  %127 = load i32, i32* %126, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %127)
  %128 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..19(i32* %128, i32* %.zero.addr131, i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %127)
  br label %omp_if.end132

omp_if.end132:                                    ; preds = %omp_if.else130, %omp_if.then129
  %129 = load i32, i32* %2, align 4
  %idxprom133 = sext i32 %129 to i64
  %130 = load i32, i32* %box4, align 4
  %idxprom134 = sext i32 %130 to i64
  %131 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains135 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %131, i32 0, i32 25
  %132 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains135, align 8
  %arrayidx136 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %132, i64 %idxprom134
  %levels137 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx136, i32 0, i32 5
  %133 = load %struct.box_type*, %struct.box_type** %levels137, align 8
  %arrayidx138 = getelementptr inbounds %struct.box_type, %struct.box_type* %133, i64 %idxprom133
  %grids139 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx138, i32 0, i32 10
  %134 = load double**, double*** %grids139, align 8
  %arrayidx140 = getelementptr inbounds double*, double** %134, i64 7
  %135 = load double*, double** %arrayidx140, align 8
  %136 = load i32, i32* %ghosts_f, align 4
  %137 = load i32, i32* %plane_f, align 4
  %mul141 = mul nsw i32 %136, %137
  %idx.ext142 = sext i32 %mul141 to i64
  %add.ptr143 = getelementptr inbounds double, double* %135, i64 %idx.ext142
  %138 = load i32, i32* %ghosts_f, align 4
  %139 = load i32, i32* %pencil_f, align 4
  %mul144 = mul nsw i32 %138, %139
  %idx.ext145 = sext i32 %mul144 to i64
  %add.ptr146 = getelementptr inbounds double, double* %add.ptr143, i64 %idx.ext145
  %140 = load i32, i32* %ghosts_f, align 4
  %idx.ext147 = sext i32 %140 to i64
  %add.ptr148 = getelementptr inbounds double, double* %add.ptr146, i64 %idx.ext147
  store double* %add.ptr148, double** %beta_f, align 8
  %141 = load i32, i32* %1, align 4
  %idxprom149 = sext i32 %141 to i64
  %142 = load i32, i32* %box4, align 4
  %idxprom150 = sext i32 %142 to i64
  %143 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains151 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %143, i32 0, i32 25
  %144 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains151, align 8
  %arrayidx152 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %144, i64 %idxprom150
  %levels153 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx152, i32 0, i32 5
  %145 = load %struct.box_type*, %struct.box_type** %levels153, align 8
  %arrayidx154 = getelementptr inbounds %struct.box_type, %struct.box_type* %145, i64 %idxprom149
  %grids155 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx154, i32 0, i32 10
  %146 = load double**, double*** %grids155, align 8
  %arrayidx156 = getelementptr inbounds double*, double** %146, i64 7
  %147 = load double*, double** %arrayidx156, align 8
  %148 = load i32, i32* %ghosts_c, align 4
  %149 = load i32, i32* %plane_c, align 4
  %mul157 = mul nsw i32 %148, %149
  %idx.ext158 = sext i32 %mul157 to i64
  %add.ptr159 = getelementptr inbounds double, double* %147, i64 %idx.ext158
  %150 = load i32, i32* %ghosts_c, align 4
  %151 = load i32, i32* %pencil_c, align 4
  %mul160 = mul nsw i32 %150, %151
  %idx.ext161 = sext i32 %mul160 to i64
  %add.ptr162 = getelementptr inbounds double, double* %add.ptr159, i64 %idx.ext161
  %152 = load i32, i32* %ghosts_c, align 4
  %idx.ext163 = sext i32 %152 to i64
  %add.ptr164 = getelementptr inbounds double, double* %add.ptr162, i64 %idx.ext163
  store double* %add.ptr164, double** %beta_c, align 8
  %153 = load i32, i32* %3, align 4
  %tobool165 = icmp ne i32 %153, 0
  br i1 %tobool165, label %omp_if.then166, label %omp_if.else167

omp_if.then166:                                   ; preds = %omp_if.end132
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**)* @.omp_outlined..20 to void (i32*, i32*, ...)*), i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  br label %omp_if.end169

omp_if.else167:                                   ; preds = %omp_if.end132
  %154 = load i32*, i32** %.global_tid..addr, align 8
  %155 = load i32, i32* %154, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %155)
  %156 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..20(i32* %156, i32* %.zero.addr168, i32* %dim_k_c, i32* %dim_j_c, i32* %dim_i_c, i32* %pencil_c, i32* %plane_c, i32* %pencil_f, i32* %plane_f, double** %beta_c, double** %beta_f)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %155)
  br label %omp_if.end169

omp_if.end169:                                    ; preds = %omp_if.else167, %omp_if.then166
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end169
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %157 = load i32, i32* %.omp.iv, align 4
  %add170 = add nsw i32 %157, 1
  store i32 %add170, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %158 = load i32*, i32** %.global_tid..addr, align 8
  %159 = load i32, i32* %158, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %159)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..18(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_c, i32* dereferenceable(4) %dim_j_c, i32* dereferenceable(4) %dim_i_c, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, double** dereferenceable(8) %beta_c, double** dereferenceable(8) %beta_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_c.addr = alloca i32*, align 8
  %dim_j_c.addr = alloca i32*, align 8
  %dim_i_c.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %beta_c.addr = alloca double**, align 8
  %beta_f.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_c, i32** %dim_k_c.addr, align 8
  store i32* %dim_j_c, i32** %dim_j_c.addr, align 8
  store i32* %dim_i_c, i32** %dim_i_c.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store double** %beta_c, double*** %beta_c.addr, align 8
  store double** %beta_f, double*** %beta_f.addr, align 8
  %0 = load i32*, i32** %dim_k_c.addr, align 8
  %1 = load i32*, i32** %dim_j_c.addr, align 8
  %2 = load i32*, i32** %dim_i_c.addr, align 8
  %3 = load i32*, i32** %pencil_c.addr, align 8
  %4 = load i32*, i32** %plane_c.addr, align 8
  %5 = load i32*, i32** %pencil_f.addr, align 8
  %6 = load i32*, i32** %plane_f.addr, align 8
  %7 = load double**, double*** %beta_c.addr, align 8
  %8 = load double**, double*** %beta_f.addr, align 8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %10, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %11 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %12 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %12
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %13 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %13, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %16 = load i64, i64* %.omp.ub, align 8
  %17 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %16, %17
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %18, %cond.true ], [ %19, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %20 = load i64, i64* %.omp.lb, align 8
  store i64 %20, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %21, %22
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %24, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %23, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %25 = load i64, i64* %.omp.iv, align 8
  %26 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %26, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %25, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %27, %28
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %29 = load i32, i32* %i, align 4
  %30 = load i32, i32* %j14, align 4
  %31 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %30, %31
  %add41 = add nsw i32 %29, %mul40
  %32 = load i32, i32* %k13, align 4
  %33 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %32, %33
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_c, align 4
  %34 = load i32, i32* %i, align 4
  %shl = shl i32 %34, 1
  %35 = load i32, i32* %j14, align 4
  %shl44 = shl i32 %35, 1
  %36 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shl44, %36
  %add46 = add nsw i32 %shl, %mul45
  %37 = load i32, i32* %k13, align 4
  %shl47 = shl i32 %37, 1
  %38 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shl47, %38
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_f, align 4
  %39 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %39 to i64
  %40 = load double*, double** %8, align 8
  %arrayidx = getelementptr inbounds double, double* %40, i64 %idxprom
  %41 = load double, double* %arrayidx, align 8
  %42 = load i32, i32* %ijk_f, align 4
  %43 = load i32, i32* %5, align 4
  %add50 = add nsw i32 %42, %43
  %idxprom51 = sext i32 %add50 to i64
  %44 = load double*, double** %8, align 8
  %arrayidx52 = getelementptr inbounds double, double* %44, i64 %idxprom51
  %45 = load double, double* %arrayidx52, align 8
  %add53 = fadd double %41, %45
  %46 = load i32, i32* %ijk_f, align 4
  %47 = load i32, i32* %6, align 4
  %add54 = add nsw i32 %46, %47
  %idxprom55 = sext i32 %add54 to i64
  %48 = load double*, double** %8, align 8
  %arrayidx56 = getelementptr inbounds double, double* %48, i64 %idxprom55
  %49 = load double, double* %arrayidx56, align 8
  %add57 = fadd double %add53, %49
  %50 = load i32, i32* %ijk_f, align 4
  %51 = load i32, i32* %5, align 4
  %add58 = add nsw i32 %50, %51
  %52 = load i32, i32* %6, align 4
  %add59 = add nsw i32 %add58, %52
  %idxprom60 = sext i32 %add59 to i64
  %53 = load double*, double** %8, align 8
  %arrayidx61 = getelementptr inbounds double, double* %53, i64 %idxprom60
  %54 = load double, double* %arrayidx61, align 8
  %add62 = fadd double %add57, %54
  %mul63 = fmul double %add62, 2.500000e-01
  %55 = load i32, i32* %ijk_c, align 4
  %idxprom64 = sext i32 %55 to i64
  %56 = load double*, double** %7, align 8
  %arrayidx65 = getelementptr inbounds double, double* %56, i64 %idxprom64
  store double %mul63, double* %arrayidx65, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %57 = load i32, i32* %i, align 4
  %inc = add nsw i32 %57, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %58 = load i64, i64* %.omp.iv, align 8
  %add66 = add nsw i64 %58, 1
  store i64 %add66, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %59 = load i32*, i32** %.global_tid..addr, align 8
  %60 = load i32, i32* %59, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %60)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..19(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_c, i32* dereferenceable(4) %dim_j_c, i32* dereferenceable(4) %dim_i_c, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, double** dereferenceable(8) %beta_c, double** dereferenceable(8) %beta_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_c.addr = alloca i32*, align 8
  %dim_j_c.addr = alloca i32*, align 8
  %dim_i_c.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %beta_c.addr = alloca double**, align 8
  %beta_f.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_c, i32** %dim_k_c.addr, align 8
  store i32* %dim_j_c, i32** %dim_j_c.addr, align 8
  store i32* %dim_i_c, i32** %dim_i_c.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store double** %beta_c, double*** %beta_c.addr, align 8
  store double** %beta_f, double*** %beta_f.addr, align 8
  %0 = load i32*, i32** %dim_k_c.addr, align 8
  %1 = load i32*, i32** %dim_j_c.addr, align 8
  %2 = load i32*, i32** %dim_i_c.addr, align 8
  %3 = load i32*, i32** %pencil_c.addr, align 8
  %4 = load i32*, i32** %plane_c.addr, align 8
  %5 = load i32*, i32** %pencil_f.addr, align 8
  %6 = load i32*, i32** %plane_f.addr, align 8
  %7 = load double**, double*** %beta_c.addr, align 8
  %8 = load double**, double*** %beta_f.addr, align 8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %10, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %11 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %12 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %12
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %13 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %13, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %16 = load i64, i64* %.omp.ub, align 8
  %17 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %16, %17
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %18, %cond.true ], [ %19, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %20 = load i64, i64* %.omp.lb, align 8
  store i64 %20, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %21, %22
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %24, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %23, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %25 = load i64, i64* %.omp.iv, align 8
  %26 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %26, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %25, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %27, %28
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %29 = load i32, i32* %i, align 4
  %30 = load i32, i32* %j14, align 4
  %31 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %30, %31
  %add41 = add nsw i32 %29, %mul40
  %32 = load i32, i32* %k13, align 4
  %33 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %32, %33
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_c, align 4
  %34 = load i32, i32* %i, align 4
  %shl = shl i32 %34, 1
  %35 = load i32, i32* %j14, align 4
  %shl44 = shl i32 %35, 1
  %36 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shl44, %36
  %add46 = add nsw i32 %shl, %mul45
  %37 = load i32, i32* %k13, align 4
  %shl47 = shl i32 %37, 1
  %38 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shl47, %38
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_f, align 4
  %39 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %39 to i64
  %40 = load double*, double** %8, align 8
  %arrayidx = getelementptr inbounds double, double* %40, i64 %idxprom
  %41 = load double, double* %arrayidx, align 8
  %42 = load i32, i32* %ijk_f, align 4
  %add50 = add nsw i32 %42, 1
  %idxprom51 = sext i32 %add50 to i64
  %43 = load double*, double** %8, align 8
  %arrayidx52 = getelementptr inbounds double, double* %43, i64 %idxprom51
  %44 = load double, double* %arrayidx52, align 8
  %add53 = fadd double %41, %44
  %45 = load i32, i32* %ijk_f, align 4
  %46 = load i32, i32* %6, align 4
  %add54 = add nsw i32 %45, %46
  %idxprom55 = sext i32 %add54 to i64
  %47 = load double*, double** %8, align 8
  %arrayidx56 = getelementptr inbounds double, double* %47, i64 %idxprom55
  %48 = load double, double* %arrayidx56, align 8
  %add57 = fadd double %add53, %48
  %49 = load i32, i32* %ijk_f, align 4
  %add58 = add nsw i32 %49, 1
  %50 = load i32, i32* %6, align 4
  %add59 = add nsw i32 %add58, %50
  %idxprom60 = sext i32 %add59 to i64
  %51 = load double*, double** %8, align 8
  %arrayidx61 = getelementptr inbounds double, double* %51, i64 %idxprom60
  %52 = load double, double* %arrayidx61, align 8
  %add62 = fadd double %add57, %52
  %mul63 = fmul double %add62, 2.500000e-01
  %53 = load i32, i32* %ijk_c, align 4
  %idxprom64 = sext i32 %53 to i64
  %54 = load double*, double** %7, align 8
  %arrayidx65 = getelementptr inbounds double, double* %54, i64 %idxprom64
  store double %mul63, double* %arrayidx65, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %55 = load i32, i32* %i, align 4
  %inc = add nsw i32 %55, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %56 = load i64, i64* %.omp.iv, align 8
  %add66 = add nsw i64 %56, 1
  store i64 %add66, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %57 = load i32*, i32** %.global_tid..addr, align 8
  %58 = load i32, i32* %57, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %58)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..20(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_c, i32* dereferenceable(4) %dim_j_c, i32* dereferenceable(4) %dim_i_c, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, double** dereferenceable(8) %beta_c, double** dereferenceable(8) %beta_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_c.addr = alloca i32*, align 8
  %dim_j_c.addr = alloca i32*, align 8
  %dim_i_c.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %beta_c.addr = alloca double**, align 8
  %beta_f.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_c, i32** %dim_k_c.addr, align 8
  store i32* %dim_j_c, i32** %dim_j_c.addr, align 8
  store i32* %dim_i_c, i32** %dim_i_c.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store double** %beta_c, double*** %beta_c.addr, align 8
  store double** %beta_f, double*** %beta_f.addr, align 8
  %0 = load i32*, i32** %dim_k_c.addr, align 8
  %1 = load i32*, i32** %dim_j_c.addr, align 8
  %2 = load i32*, i32** %dim_i_c.addr, align 8
  %3 = load i32*, i32** %pencil_c.addr, align 8
  %4 = load i32*, i32** %plane_c.addr, align 8
  %5 = load i32*, i32** %pencil_f.addr, align 8
  %6 = load i32*, i32** %plane_f.addr, align 8
  %7 = load double**, double*** %beta_c.addr, align 8
  %8 = load double**, double*** %beta_f.addr, align 8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %10, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %11 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %12 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %12
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %13 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %13, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %16 = load i64, i64* %.omp.ub, align 8
  %17 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %16, %17
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %18, %cond.true ], [ %19, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %20 = load i64, i64* %.omp.lb, align 8
  store i64 %20, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %21, %22
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %24, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %23, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %25 = load i64, i64* %.omp.iv, align 8
  %26 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %26, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %25, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %27, %28
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %29 = load i32, i32* %i, align 4
  %30 = load i32, i32* %j14, align 4
  %31 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %30, %31
  %add41 = add nsw i32 %29, %mul40
  %32 = load i32, i32* %k13, align 4
  %33 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %32, %33
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_c, align 4
  %34 = load i32, i32* %i, align 4
  %shl = shl i32 %34, 1
  %35 = load i32, i32* %j14, align 4
  %shl44 = shl i32 %35, 1
  %36 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shl44, %36
  %add46 = add nsw i32 %shl, %mul45
  %37 = load i32, i32* %k13, align 4
  %shl47 = shl i32 %37, 1
  %38 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shl47, %38
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_f, align 4
  %39 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %39 to i64
  %40 = load double*, double** %8, align 8
  %arrayidx = getelementptr inbounds double, double* %40, i64 %idxprom
  %41 = load double, double* %arrayidx, align 8
  %42 = load i32, i32* %ijk_f, align 4
  %add50 = add nsw i32 %42, 1
  %idxprom51 = sext i32 %add50 to i64
  %43 = load double*, double** %8, align 8
  %arrayidx52 = getelementptr inbounds double, double* %43, i64 %idxprom51
  %44 = load double, double* %arrayidx52, align 8
  %add53 = fadd double %41, %44
  %45 = load i32, i32* %ijk_f, align 4
  %46 = load i32, i32* %5, align 4
  %add54 = add nsw i32 %45, %46
  %idxprom55 = sext i32 %add54 to i64
  %47 = load double*, double** %8, align 8
  %arrayidx56 = getelementptr inbounds double, double* %47, i64 %idxprom55
  %48 = load double, double* %arrayidx56, align 8
  %add57 = fadd double %add53, %48
  %49 = load i32, i32* %ijk_f, align 4
  %add58 = add nsw i32 %49, 1
  %50 = load i32, i32* %5, align 4
  %add59 = add nsw i32 %add58, %50
  %idxprom60 = sext i32 %add59 to i64
  %51 = load double*, double** %8, align 8
  %arrayidx61 = getelementptr inbounds double, double* %51, i64 %idxprom60
  %52 = load double, double* %arrayidx61, align 8
  %add62 = fadd double %add57, %52
  %mul63 = fmul double %add62, 2.500000e-01
  %53 = load i32, i32* %ijk_c, align 4
  %idxprom64 = sext i32 %53 to i64
  %54 = load double*, double** %7, align 8
  %arrayidx65 = getelementptr inbounds double, double* %54, i64 %idxprom64
  store double %mul63, double* %arrayidx65, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %55 = load i32, i32* %i, align 4
  %inc = add nsw i32 %55, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %56 = load i64, i64* %.omp.iv, align 8
  %add66 = add nsw i64 %56, 1
  store i64 %add66, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %57 = load i32*, i32** %.global_tid..addr, align 8
  %58 = load i32, i32* %57, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %58)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @interpolation_constant(%struct.domain_type* %domain, i32 %level_f, double %prescale_f, i32 %id_f, i32 %id_c) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level_f.addr = alloca i32, align 4
  %prescale_f.addr = alloca double, align 8
  %id_f.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %level_c = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level_f, i32* %level_f.addr, align 4
  store double %prescale_f, double* %prescale_f.addr, align 8
  store i32 %id_f, i32* %id_f.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  %1 = load i32, i32* %level_f.addr, align 4
  %add = add nsw i32 %1, 1
  store i32 %add, i32* %level_c, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %2 = load i32, i32* %level_f.addr, align 4
  %idxprom = sext i32 %2 to i64
  %3 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %3, i32 0, i32 25
  %4 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %4, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %5 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %5, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %6 = load i32, i32* %i, align 4
  %7 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %6, %7
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %8 = load i32, i32* %level_f.addr, align 4
  %idxprom2 = sext i32 %8 to i64
  %9 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 25
  %10 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %10, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %11 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %11, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %12 = load i32, i32* %i8, align 4
  %13 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %12, %13
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %14 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %14, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..21 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box, double* %prescale_f.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..21(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box, double* %prescale_f.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %15 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %15
  %16 = load i32, i32* %level_f.addr, align 4
  %idxprom12 = sext i32 %16 to i64
  %17 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %17, i32 0, i32 0
  %interpolation = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 4
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %interpolation, i64 0, i64 %idxprom12
  %18 = load i64, i64* %arrayidx13, align 8
  %add14 = add i64 %18, %sub
  store i64 %add14, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..21(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level_c, i32* dereferenceable(4) %level_f, i32* dereferenceable(4) %id_f, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %prescale_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level_c.addr = alloca i32*, align 8
  %level_f.addr = alloca i32*, align 8
  %id_f.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %prescale_f.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %ghosts_c = alloca i32, align 4
  %pencil_c = alloca i32, align 4
  %plane_c = alloca i32, align 4
  %ghosts_f = alloca i32, align 4
  %pencil_f = alloca i32, align 4
  %plane_f = alloca i32, align 4
  %dim_i_f = alloca i32, align 4
  %dim_j_f = alloca i32, align 4
  %dim_k_f = alloca i32, align 4
  %grid_f = alloca double*, align 8
  %grid_c = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level_c, i32** %level_c.addr, align 8
  store i32* %level_f, i32** %level_f.addr, align 8
  store i32* %id_f, i32** %id_f.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %prescale_f, double** %prescale_f.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level_c.addr, align 8
  %2 = load i32*, i32** %level_f.addr, align 8
  %3 = load i32*, i32** %id_f.addr, align 8
  %4 = load i32*, i32** %id_c.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load double*, double** %prescale_f.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %11 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %11, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %14 = load i32, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %14, %15
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %16, %cond.true ], [ %17, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %18 = load i32, i32* %.omp.lb, align 4
  store i32 %18, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i32, i32* %.omp.iv, align 4
  %20 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %19, %20
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %21, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %22 = load i32, i32* %1, align 4
  %idxprom = sext i32 %22 to i64
  %23 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %23 to i64
  %24 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %24, i32 0, i32 25
  %25 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %25, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %26 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %26, i64 %idxprom
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 4
  %27 = load i32, i32* %ghosts, align 4
  store i32 %27, i32* %ghosts_c, align 4
  %28 = load i32, i32* %1, align 4
  %idxprom11 = sext i32 %28 to i64
  %29 = load i32, i32* %box4, align 4
  %idxprom12 = sext i32 %29 to i64
  %30 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %30, i32 0, i32 25
  %31 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %31, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %32 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %32, i64 %idxprom11
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 5
  %33 = load i32, i32* %pencil, align 8
  store i32 %33, i32* %pencil_c, align 4
  %34 = load i32, i32* %1, align 4
  %idxprom17 = sext i32 %34 to i64
  %35 = load i32, i32* %box4, align 4
  %idxprom18 = sext i32 %35 to i64
  %36 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %36, i32 0, i32 25
  %37 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains19, align 8
  %arrayidx20 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %37, i64 %idxprom18
  %levels21 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx20, i32 0, i32 5
  %38 = load %struct.box_type*, %struct.box_type** %levels21, align 8
  %arrayidx22 = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i64 %idxprom17
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx22, i32 0, i32 6
  %39 = load i32, i32* %plane, align 4
  store i32 %39, i32* %plane_c, align 4
  %40 = load i32, i32* %2, align 4
  %idxprom23 = sext i32 %40 to i64
  %41 = load i32, i32* %box4, align 4
  %idxprom24 = sext i32 %41 to i64
  %42 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains25 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %42, i32 0, i32 25
  %43 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains25, align 8
  %arrayidx26 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %43, i64 %idxprom24
  %levels27 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx26, i32 0, i32 5
  %44 = load %struct.box_type*, %struct.box_type** %levels27, align 8
  %arrayidx28 = getelementptr inbounds %struct.box_type, %struct.box_type* %44, i64 %idxprom23
  %ghosts29 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx28, i32 0, i32 4
  %45 = load i32, i32* %ghosts29, align 4
  store i32 %45, i32* %ghosts_f, align 4
  %46 = load i32, i32* %2, align 4
  %idxprom30 = sext i32 %46 to i64
  %47 = load i32, i32* %box4, align 4
  %idxprom31 = sext i32 %47 to i64
  %48 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains32 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %48, i32 0, i32 25
  %49 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains32, align 8
  %arrayidx33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %49, i64 %idxprom31
  %levels34 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx33, i32 0, i32 5
  %50 = load %struct.box_type*, %struct.box_type** %levels34, align 8
  %arrayidx35 = getelementptr inbounds %struct.box_type, %struct.box_type* %50, i64 %idxprom30
  %pencil36 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx35, i32 0, i32 5
  %51 = load i32, i32* %pencil36, align 8
  store i32 %51, i32* %pencil_f, align 4
  %52 = load i32, i32* %2, align 4
  %idxprom37 = sext i32 %52 to i64
  %53 = load i32, i32* %box4, align 4
  %idxprom38 = sext i32 %53 to i64
  %54 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains39 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %54, i32 0, i32 25
  %55 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains39, align 8
  %arrayidx40 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %55, i64 %idxprom38
  %levels41 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx40, i32 0, i32 5
  %56 = load %struct.box_type*, %struct.box_type** %levels41, align 8
  %arrayidx42 = getelementptr inbounds %struct.box_type, %struct.box_type* %56, i64 %idxprom37
  %plane43 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx42, i32 0, i32 6
  %57 = load i32, i32* %plane43, align 4
  store i32 %57, i32* %plane_f, align 4
  %58 = load i32, i32* %2, align 4
  %idxprom44 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom45 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains46 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains46, align 8
  %arrayidx47 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom45
  %levels48 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx47, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels48, align 8
  %arrayidx49 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom44
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx49, i32 0, i32 2
  %i50 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %63 = load i32, i32* %i50, align 4
  store i32 %63, i32* %dim_i_f, align 4
  %64 = load i32, i32* %2, align 4
  %idxprom51 = sext i32 %64 to i64
  %65 = load i32, i32* %box4, align 4
  %idxprom52 = sext i32 %65 to i64
  %66 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains53 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %66, i32 0, i32 25
  %67 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains53, align 8
  %arrayidx54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %67, i64 %idxprom52
  %levels55 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx54, i32 0, i32 5
  %68 = load %struct.box_type*, %struct.box_type** %levels55, align 8
  %arrayidx56 = getelementptr inbounds %struct.box_type, %struct.box_type* %68, i64 %idxprom51
  %dim57 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx56, i32 0, i32 2
  %j58 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim57, i32 0, i32 1
  %69 = load i32, i32* %j58, align 4
  store i32 %69, i32* %dim_j_f, align 4
  %70 = load i32, i32* %2, align 4
  %idxprom59 = sext i32 %70 to i64
  %71 = load i32, i32* %box4, align 4
  %idxprom60 = sext i32 %71 to i64
  %72 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains61 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %72, i32 0, i32 25
  %73 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains61, align 8
  %arrayidx62 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %73, i64 %idxprom60
  %levels63 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx62, i32 0, i32 5
  %74 = load %struct.box_type*, %struct.box_type** %levels63, align 8
  %arrayidx64 = getelementptr inbounds %struct.box_type, %struct.box_type* %74, i64 %idxprom59
  %dim65 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx64, i32 0, i32 2
  %k66 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim65, i32 0, i32 2
  %75 = load i32, i32* %k66, align 4
  store i32 %75, i32* %dim_k_f, align 4
  %76 = load i32, i32* %3, align 4
  %idxprom67 = sext i32 %76 to i64
  %77 = load i32, i32* %2, align 4
  %idxprom68 = sext i32 %77 to i64
  %78 = load i32, i32* %box4, align 4
  %idxprom69 = sext i32 %78 to i64
  %79 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains70 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %79, i32 0, i32 25
  %80 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains70, align 8
  %arrayidx71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %80, i64 %idxprom69
  %levels72 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx71, i32 0, i32 5
  %81 = load %struct.box_type*, %struct.box_type** %levels72, align 8
  %arrayidx73 = getelementptr inbounds %struct.box_type, %struct.box_type* %81, i64 %idxprom68
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx73, i32 0, i32 10
  %82 = load double**, double*** %grids, align 8
  %arrayidx74 = getelementptr inbounds double*, double** %82, i64 %idxprom67
  %83 = load double*, double** %arrayidx74, align 8
  %84 = load i32, i32* %ghosts_f, align 4
  %85 = load i32, i32* %pencil_f, align 4
  %add75 = add nsw i32 1, %85
  %86 = load i32, i32* %plane_f, align 4
  %add76 = add nsw i32 %add75, %86
  %mul77 = mul nsw i32 %84, %add76
  %idx.ext = sext i32 %mul77 to i64
  %add.ptr = getelementptr inbounds double, double* %83, i64 %idx.ext
  store double* %add.ptr, double** %grid_f, align 8
  %87 = load i32, i32* %4, align 4
  %idxprom78 = sext i32 %87 to i64
  %88 = load i32, i32* %1, align 4
  %idxprom79 = sext i32 %88 to i64
  %89 = load i32, i32* %box4, align 4
  %idxprom80 = sext i32 %89 to i64
  %90 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains81 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %90, i32 0, i32 25
  %91 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains81, align 8
  %arrayidx82 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %91, i64 %idxprom80
  %levels83 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx82, i32 0, i32 5
  %92 = load %struct.box_type*, %struct.box_type** %levels83, align 8
  %arrayidx84 = getelementptr inbounds %struct.box_type, %struct.box_type* %92, i64 %idxprom79
  %grids85 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx84, i32 0, i32 10
  %93 = load double**, double*** %grids85, align 8
  %arrayidx86 = getelementptr inbounds double*, double** %93, i64 %idxprom78
  %94 = load double*, double** %arrayidx86, align 8
  %95 = load i32, i32* %ghosts_c, align 4
  %96 = load i32, i32* %pencil_c, align 4
  %add87 = add nsw i32 1, %96
  %97 = load i32, i32* %plane_c, align 4
  %add88 = add nsw i32 %add87, %97
  %mul89 = mul nsw i32 %95, %add88
  %idx.ext90 = sext i32 %mul89 to i64
  %add.ptr91 = getelementptr inbounds double, double* %94, i64 %idx.ext90
  store double* %add.ptr91, double** %grid_c, align 8
  %98 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %98, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 10, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*, double**)* @.omp_outlined..22 to void (i32*, i32*, ...)*), i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, i32* %pencil_c, i32* %plane_c, double** %grid_f, double* %6, double** %grid_c)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %99 = load i32*, i32** %.global_tid..addr, align 8
  %100 = load i32, i32* %99, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %100)
  %101 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..22(i32* %101, i32* %.zero.addr, i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, i32* %pencil_c, i32* %plane_c, double** %grid_f, double* %6, double** %grid_c)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %100)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %102 = load i32, i32* %.omp.iv, align 4
  %add92 = add nsw i32 %102, 1
  store i32 %add92, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %103 = load i32*, i32** %.global_tid..addr, align 8
  %104 = load i32, i32* %103, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %104)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..22(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_f, i32* dereferenceable(4) %dim_j_f, i32* dereferenceable(4) %dim_i_f, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, double** dereferenceable(8) %grid_f, double* dereferenceable(8) %prescale_f, double** dereferenceable(8) %grid_c) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_f.addr = alloca i32*, align 8
  %dim_j_f.addr = alloca i32*, align 8
  %dim_i_f.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %grid_f.addr = alloca double**, align 8
  %prescale_f.addr = alloca double*, align 8
  %grid_c.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_f, i32** %dim_k_f.addr, align 8
  store i32* %dim_j_f, i32** %dim_j_f.addr, align 8
  store i32* %dim_i_f, i32** %dim_i_f.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store double** %grid_f, double*** %grid_f.addr, align 8
  store double* %prescale_f, double** %prescale_f.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  %0 = load i32*, i32** %dim_k_f.addr, align 8
  %1 = load i32*, i32** %dim_j_f.addr, align 8
  %2 = load i32*, i32** %dim_i_f.addr, align 8
  %3 = load i32*, i32** %pencil_f.addr, align 8
  %4 = load i32*, i32** %plane_f.addr, align 8
  %5 = load i32*, i32** %pencil_c.addr, align 8
  %6 = load i32*, i32** %plane_c.addr, align 8
  %7 = load double**, double*** %grid_f.addr, align 8
  %8 = load double*, double** %prescale_f.addr, align 8
  %9 = load double**, double*** %grid_c.addr, align 8
  %10 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %10, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %11 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %11, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %12 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %12
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %13 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %13
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %14 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %14, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %15 = load i32*, i32** %.global_tid..addr, align 8
  %16 = load i32, i32* %15, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %16, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %17 = load i64, i64* %.omp.ub, align 8
  %18 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %17, %18
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %20 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %19, %cond.true ], [ %20, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %21 = load i64, i64* %.omp.lb, align 8
  store i64 %21, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %22, %23
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %25, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %24, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %27, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %26, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %28, %29
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %30 = load i32, i32* %i, align 4
  %31 = load i32, i32* %j14, align 4
  %32 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %31, %32
  %add41 = add nsw i32 %30, %mul40
  %33 = load i32, i32* %k13, align 4
  %34 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %33, %34
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_f, align 4
  %35 = load i32, i32* %i, align 4
  %shr = ashr i32 %35, 1
  %36 = load i32, i32* %j14, align 4
  %shr44 = ashr i32 %36, 1
  %37 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shr44, %37
  %add46 = add nsw i32 %shr, %mul45
  %38 = load i32, i32* %k13, align 4
  %shr47 = ashr i32 %38, 1
  %39 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shr47, %39
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_c, align 4
  %40 = load double, double* %8, align 8
  %41 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %41 to i64
  %42 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %42, i64 %idxprom
  %43 = load double, double* %arrayidx, align 8
  %mul50 = fmul double %40, %43
  %44 = load i32, i32* %ijk_c, align 4
  %idxprom51 = sext i32 %44 to i64
  %45 = load double*, double** %9, align 8
  %arrayidx52 = getelementptr inbounds double, double* %45, i64 %idxprom51
  %46 = load double, double* %arrayidx52, align 8
  %add53 = fadd double %mul50, %46
  %47 = load i32, i32* %ijk_f, align 4
  %idxprom54 = sext i32 %47 to i64
  %48 = load double*, double** %7, align 8
  %arrayidx55 = getelementptr inbounds double, double* %48, i64 %idxprom54
  store double %add53, double* %arrayidx55, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %49 = load i32, i32* %i, align 4
  %inc = add nsw i32 %49, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %50 = load i64, i64* %.omp.iv, align 8
  %add56 = add nsw i64 %50, 1
  store i64 %add56, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %51 = load i32*, i32** %.global_tid..addr, align 8
  %52 = load i32, i32* %51, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %52)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @interpolation_linear(%struct.domain_type* %domain, i32 %level_f, double %prescale_f, i32 %id_f, i32 %id_c) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level_f.addr = alloca i32, align 4
  %prescale_f.addr = alloca double, align 8
  %id_f.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %level_c = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level_f, i32* %level_f.addr, align 4
  store double %prescale_f, double* %prescale_f.addr, align 8
  store i32 %id_f, i32* %id_f.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  %1 = load i32, i32* %level_f.addr, align 4
  %add = add nsw i32 %1, 1
  store i32 %add, i32* %level_c, align 4
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %3 = load i32, i32* %level_c, align 4
  %4 = load i32, i32* %id_c.addr, align 4
  call void @exchange_boundary(%struct.domain_type* %2, i32 %3, i32 %4, i32 1, i32 1, i32 1)
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %5 = load i32, i32* %level_f.addr, align 4
  %idxprom = sext i32 %5 to i64
  %6 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 25
  %7 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %7, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %8 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %8, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %9 = load i32, i32* %i, align 4
  %10 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %9, %10
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %11 = load i32, i32* %level_f.addr, align 4
  %idxprom2 = sext i32 %11 to i64
  %12 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %12, i32 0, i32 25
  %13 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %13, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %14 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %14, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %15 = load i32, i32* %i8, align 4
  %16 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %15, %16
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %17 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %17, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..23 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box, double* %prescale_f.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..23(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level_c, i32* %level_f.addr, i32* %id_f.addr, i32* %id_c.addr, i32* %omp_within_a_box, double* %prescale_f.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %18 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %18
  %19 = load i32, i32* %level_f.addr, align 4
  %idxprom12 = sext i32 %19 to i64
  %20 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %20, i32 0, i32 0
  %interpolation = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 4
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %interpolation, i64 0, i64 %idxprom12
  %21 = load i64, i64* %arrayidx13, align 8
  %add14 = add i64 %21, %sub
  store i64 %add14, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..23(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level_c, i32* dereferenceable(4) %level_f, i32* dereferenceable(4) %id_f, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %prescale_f) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level_c.addr = alloca i32*, align 8
  %level_f.addr = alloca i32*, align 8
  %id_f.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %prescale_f.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %ghosts_c = alloca i32, align 4
  %pencil_c = alloca i32, align 4
  %plane_c = alloca i32, align 4
  %dim_i_c = alloca i32, align 4
  %dim_j_c = alloca i32, align 4
  %dim_k_c = alloca i32, align 4
  %ghosts_f = alloca i32, align 4
  %pencil_f = alloca i32, align 4
  %plane_f = alloca i32, align 4
  %dim_i_f = alloca i32, align 4
  %dim_j_f = alloca i32, align 4
  %dim_k_f = alloca i32, align 4
  %grid_f = alloca double*, align 8
  %grid_c = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level_c, i32** %level_c.addr, align 8
  store i32* %level_f, i32** %level_f.addr, align 8
  store i32* %id_f, i32** %id_f.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %prescale_f, double** %prescale_f.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level_c.addr, align 8
  %2 = load i32*, i32** %level_f.addr, align 8
  %3 = load i32*, i32** %id_f.addr, align 8
  %4 = load i32*, i32** %id_c.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load double*, double** %prescale_f.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %11 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %11, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %14 = load i32, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %14, %15
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %16, %cond.true ], [ %17, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %18 = load i32, i32* %.omp.lb, align 4
  store i32 %18, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i32, i32* %.omp.iv, align 4
  %20 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %19, %20
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %21, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %22 = load i32, i32* %1, align 4
  %idxprom = sext i32 %22 to i64
  %23 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %23 to i64
  %24 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %24, i32 0, i32 25
  %25 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %25, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %26 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %26, i64 %idxprom
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 4
  %27 = load i32, i32* %ghosts, align 4
  store i32 %27, i32* %ghosts_c, align 4
  %28 = load i32, i32* %1, align 4
  %idxprom11 = sext i32 %28 to i64
  %29 = load i32, i32* %box4, align 4
  %idxprom12 = sext i32 %29 to i64
  %30 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %30, i32 0, i32 25
  %31 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %31, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %32 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %32, i64 %idxprom11
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 5
  %33 = load i32, i32* %pencil, align 8
  store i32 %33, i32* %pencil_c, align 4
  %34 = load i32, i32* %1, align 4
  %idxprom17 = sext i32 %34 to i64
  %35 = load i32, i32* %box4, align 4
  %idxprom18 = sext i32 %35 to i64
  %36 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %36, i32 0, i32 25
  %37 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains19, align 8
  %arrayidx20 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %37, i64 %idxprom18
  %levels21 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx20, i32 0, i32 5
  %38 = load %struct.box_type*, %struct.box_type** %levels21, align 8
  %arrayidx22 = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i64 %idxprom17
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx22, i32 0, i32 6
  %39 = load i32, i32* %plane, align 4
  store i32 %39, i32* %plane_c, align 4
  %40 = load i32, i32* %1, align 4
  %idxprom23 = sext i32 %40 to i64
  %41 = load i32, i32* %box4, align 4
  %idxprom24 = sext i32 %41 to i64
  %42 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains25 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %42, i32 0, i32 25
  %43 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains25, align 8
  %arrayidx26 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %43, i64 %idxprom24
  %levels27 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx26, i32 0, i32 5
  %44 = load %struct.box_type*, %struct.box_type** %levels27, align 8
  %arrayidx28 = getelementptr inbounds %struct.box_type, %struct.box_type* %44, i64 %idxprom23
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx28, i32 0, i32 2
  %i29 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %45 = load i32, i32* %i29, align 4
  store i32 %45, i32* %dim_i_c, align 4
  %46 = load i32, i32* %1, align 4
  %idxprom30 = sext i32 %46 to i64
  %47 = load i32, i32* %box4, align 4
  %idxprom31 = sext i32 %47 to i64
  %48 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains32 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %48, i32 0, i32 25
  %49 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains32, align 8
  %arrayidx33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %49, i64 %idxprom31
  %levels34 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx33, i32 0, i32 5
  %50 = load %struct.box_type*, %struct.box_type** %levels34, align 8
  %arrayidx35 = getelementptr inbounds %struct.box_type, %struct.box_type* %50, i64 %idxprom30
  %dim36 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx35, i32 0, i32 2
  %j37 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim36, i32 0, i32 1
  %51 = load i32, i32* %j37, align 4
  store i32 %51, i32* %dim_j_c, align 4
  %52 = load i32, i32* %1, align 4
  %idxprom38 = sext i32 %52 to i64
  %53 = load i32, i32* %box4, align 4
  %idxprom39 = sext i32 %53 to i64
  %54 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains40 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %54, i32 0, i32 25
  %55 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains40, align 8
  %arrayidx41 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %55, i64 %idxprom39
  %levels42 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx41, i32 0, i32 5
  %56 = load %struct.box_type*, %struct.box_type** %levels42, align 8
  %arrayidx43 = getelementptr inbounds %struct.box_type, %struct.box_type* %56, i64 %idxprom38
  %dim44 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx43, i32 0, i32 2
  %k45 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim44, i32 0, i32 2
  %57 = load i32, i32* %k45, align 4
  store i32 %57, i32* %dim_k_c, align 4
  %58 = load i32, i32* %2, align 4
  %idxprom46 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom47 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains48 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains48, align 8
  %arrayidx49 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom47
  %levels50 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx49, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels50, align 8
  %arrayidx51 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom46
  %ghosts52 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx51, i32 0, i32 4
  %63 = load i32, i32* %ghosts52, align 4
  store i32 %63, i32* %ghosts_f, align 4
  %64 = load i32, i32* %2, align 4
  %idxprom53 = sext i32 %64 to i64
  %65 = load i32, i32* %box4, align 4
  %idxprom54 = sext i32 %65 to i64
  %66 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains55 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %66, i32 0, i32 25
  %67 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains55, align 8
  %arrayidx56 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %67, i64 %idxprom54
  %levels57 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx56, i32 0, i32 5
  %68 = load %struct.box_type*, %struct.box_type** %levels57, align 8
  %arrayidx58 = getelementptr inbounds %struct.box_type, %struct.box_type* %68, i64 %idxprom53
  %pencil59 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx58, i32 0, i32 5
  %69 = load i32, i32* %pencil59, align 8
  store i32 %69, i32* %pencil_f, align 4
  %70 = load i32, i32* %2, align 4
  %idxprom60 = sext i32 %70 to i64
  %71 = load i32, i32* %box4, align 4
  %idxprom61 = sext i32 %71 to i64
  %72 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains62 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %72, i32 0, i32 25
  %73 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains62, align 8
  %arrayidx63 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %73, i64 %idxprom61
  %levels64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx63, i32 0, i32 5
  %74 = load %struct.box_type*, %struct.box_type** %levels64, align 8
  %arrayidx65 = getelementptr inbounds %struct.box_type, %struct.box_type* %74, i64 %idxprom60
  %plane66 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx65, i32 0, i32 6
  %75 = load i32, i32* %plane66, align 4
  store i32 %75, i32* %plane_f, align 4
  %76 = load i32, i32* %2, align 4
  %idxprom67 = sext i32 %76 to i64
  %77 = load i32, i32* %box4, align 4
  %idxprom68 = sext i32 %77 to i64
  %78 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains69 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %78, i32 0, i32 25
  %79 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains69, align 8
  %arrayidx70 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %79, i64 %idxprom68
  %levels71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx70, i32 0, i32 5
  %80 = load %struct.box_type*, %struct.box_type** %levels71, align 8
  %arrayidx72 = getelementptr inbounds %struct.box_type, %struct.box_type* %80, i64 %idxprom67
  %dim73 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx72, i32 0, i32 2
  %i74 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim73, i32 0, i32 0
  %81 = load i32, i32* %i74, align 4
  store i32 %81, i32* %dim_i_f, align 4
  %82 = load i32, i32* %2, align 4
  %idxprom75 = sext i32 %82 to i64
  %83 = load i32, i32* %box4, align 4
  %idxprom76 = sext i32 %83 to i64
  %84 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains77 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %84, i32 0, i32 25
  %85 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains77, align 8
  %arrayidx78 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %85, i64 %idxprom76
  %levels79 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx78, i32 0, i32 5
  %86 = load %struct.box_type*, %struct.box_type** %levels79, align 8
  %arrayidx80 = getelementptr inbounds %struct.box_type, %struct.box_type* %86, i64 %idxprom75
  %dim81 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx80, i32 0, i32 2
  %j82 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim81, i32 0, i32 1
  %87 = load i32, i32* %j82, align 4
  store i32 %87, i32* %dim_j_f, align 4
  %88 = load i32, i32* %2, align 4
  %idxprom83 = sext i32 %88 to i64
  %89 = load i32, i32* %box4, align 4
  %idxprom84 = sext i32 %89 to i64
  %90 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains85 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %90, i32 0, i32 25
  %91 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains85, align 8
  %arrayidx86 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %91, i64 %idxprom84
  %levels87 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx86, i32 0, i32 5
  %92 = load %struct.box_type*, %struct.box_type** %levels87, align 8
  %arrayidx88 = getelementptr inbounds %struct.box_type, %struct.box_type* %92, i64 %idxprom83
  %dim89 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx88, i32 0, i32 2
  %k90 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim89, i32 0, i32 2
  %93 = load i32, i32* %k90, align 4
  store i32 %93, i32* %dim_k_f, align 4
  %94 = load i32, i32* %3, align 4
  %idxprom91 = sext i32 %94 to i64
  %95 = load i32, i32* %2, align 4
  %idxprom92 = sext i32 %95 to i64
  %96 = load i32, i32* %box4, align 4
  %idxprom93 = sext i32 %96 to i64
  %97 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains94 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %97, i32 0, i32 25
  %98 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains94, align 8
  %arrayidx95 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %98, i64 %idxprom93
  %levels96 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx95, i32 0, i32 5
  %99 = load %struct.box_type*, %struct.box_type** %levels96, align 8
  %arrayidx97 = getelementptr inbounds %struct.box_type, %struct.box_type* %99, i64 %idxprom92
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx97, i32 0, i32 10
  %100 = load double**, double*** %grids, align 8
  %arrayidx98 = getelementptr inbounds double*, double** %100, i64 %idxprom91
  %101 = load double*, double** %arrayidx98, align 8
  %102 = load i32, i32* %ghosts_f, align 4
  %103 = load i32, i32* %pencil_f, align 4
  %add99 = add nsw i32 1, %103
  %104 = load i32, i32* %plane_f, align 4
  %add100 = add nsw i32 %add99, %104
  %mul101 = mul nsw i32 %102, %add100
  %idx.ext = sext i32 %mul101 to i64
  %add.ptr = getelementptr inbounds double, double* %101, i64 %idx.ext
  store double* %add.ptr, double** %grid_f, align 8
  %105 = load i32, i32* %4, align 4
  %idxprom102 = sext i32 %105 to i64
  %106 = load i32, i32* %1, align 4
  %idxprom103 = sext i32 %106 to i64
  %107 = load i32, i32* %box4, align 4
  %idxprom104 = sext i32 %107 to i64
  %108 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains105 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %108, i32 0, i32 25
  %109 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains105, align 8
  %arrayidx106 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %109, i64 %idxprom104
  %levels107 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx106, i32 0, i32 5
  %110 = load %struct.box_type*, %struct.box_type** %levels107, align 8
  %arrayidx108 = getelementptr inbounds %struct.box_type, %struct.box_type* %110, i64 %idxprom103
  %grids109 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx108, i32 0, i32 10
  %111 = load double**, double*** %grids109, align 8
  %arrayidx110 = getelementptr inbounds double*, double** %111, i64 %idxprom102
  %112 = load double*, double** %arrayidx110, align 8
  %113 = load i32, i32* %ghosts_c, align 4
  %114 = load i32, i32* %pencil_c, align 4
  %add111 = add nsw i32 1, %114
  %115 = load i32, i32* %plane_c, align 4
  %add112 = add nsw i32 %add111, %115
  %mul113 = mul nsw i32 %113, %add112
  %idx.ext114 = sext i32 %mul113 to i64
  %add.ptr115 = getelementptr inbounds double, double* %112, i64 %idx.ext114
  store double* %add.ptr115, double** %grid_c, align 8
  %116 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %116, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 10, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*, double**)* @.omp_outlined..24 to void (i32*, i32*, ...)*), i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, i32* %pencil_c, i32* %plane_c, double** %grid_f, double* %6, double** %grid_c)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %117 = load i32*, i32** %.global_tid..addr, align 8
  %118 = load i32, i32* %117, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %118)
  %119 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..24(i32* %119, i32* %.zero.addr, i32* %dim_k_f, i32* %dim_j_f, i32* %dim_i_f, i32* %pencil_f, i32* %plane_f, i32* %pencil_c, i32* %plane_c, double** %grid_f, double* %6, double** %grid_c)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %118)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %120 = load i32, i32* %.omp.iv, align 4
  %add116 = add nsw i32 %120, 1
  store i32 %add116, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %121 = load i32*, i32** %.global_tid..addr, align 8
  %122 = load i32, i32* %121, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %122)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..24(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k_f, i32* dereferenceable(4) %dim_j_f, i32* dereferenceable(4) %dim_i_f, i32* dereferenceable(4) %pencil_f, i32* dereferenceable(4) %plane_f, i32* dereferenceable(4) %pencil_c, i32* dereferenceable(4) %plane_c, double** dereferenceable(8) %grid_f, double* dereferenceable(8) %prescale_f, double** dereferenceable(8) %grid_c) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k_f.addr = alloca i32*, align 8
  %dim_j_f.addr = alloca i32*, align 8
  %dim_i_f.addr = alloca i32*, align 8
  %pencil_f.addr = alloca i32*, align 8
  %plane_f.addr = alloca i32*, align 8
  %pencil_c.addr = alloca i32*, align 8
  %plane_c.addr = alloca i32*, align 8
  %grid_f.addr = alloca double**, align 8
  %prescale_f.addr = alloca double*, align 8
  %grid_c.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk_f = alloca i32, align 4
  %ijk_c = alloca i32, align 4
  %xm = alloca double, align 8
  %x0 = alloca double, align 8
  %xp = alloca double, align 8
  %ym = alloca double, align 8
  %y0 = alloca double, align 8
  %yp = alloca double, align 8
  %zm = alloca double, align 8
  %z0 = alloca double, align 8
  %zp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k_f, i32** %dim_k_f.addr, align 8
  store i32* %dim_j_f, i32** %dim_j_f.addr, align 8
  store i32* %dim_i_f, i32** %dim_i_f.addr, align 8
  store i32* %pencil_f, i32** %pencil_f.addr, align 8
  store i32* %plane_f, i32** %plane_f.addr, align 8
  store i32* %pencil_c, i32** %pencil_c.addr, align 8
  store i32* %plane_c, i32** %plane_c.addr, align 8
  store double** %grid_f, double*** %grid_f.addr, align 8
  store double* %prescale_f, double** %prescale_f.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  %0 = load i32*, i32** %dim_k_f.addr, align 8
  %1 = load i32*, i32** %dim_j_f.addr, align 8
  %2 = load i32*, i32** %dim_i_f.addr, align 8
  %3 = load i32*, i32** %pencil_f.addr, align 8
  %4 = load i32*, i32** %plane_f.addr, align 8
  %5 = load i32*, i32** %pencil_c.addr, align 8
  %6 = load i32*, i32** %plane_c.addr, align 8
  %7 = load double**, double*** %grid_f.addr, align 8
  %8 = load double*, double** %prescale_f.addr, align 8
  %9 = load double**, double*** %grid_c.addr, align 8
  %10 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %10, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %11 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %11, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %12 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %12
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %13 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %13
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %14 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %14, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %15 = load i32*, i32** %.global_tid..addr, align 8
  %16 = load i32, i32* %15, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %16, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %17 = load i64, i64* %.omp.ub, align 8
  %18 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %17, %18
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %20 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %19, %cond.true ], [ %20, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %21 = load i64, i64* %.omp.lb, align 8
  store i64 %21, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %22, %23
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %25, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %24, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %27, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %26, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %28, %29
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %30 = load i32, i32* %i, align 4
  %31 = load i32, i32* %j14, align 4
  %32 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %31, %32
  %add41 = add nsw i32 %30, %mul40
  %33 = load i32, i32* %k13, align 4
  %34 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %33, %34
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk_f, align 4
  %35 = load i32, i32* %i, align 4
  %shr = ashr i32 %35, 1
  %36 = load i32, i32* %j14, align 4
  %shr44 = ashr i32 %36, 1
  %37 = load i32, i32* %5, align 4
  %mul45 = mul nsw i32 %shr44, %37
  %add46 = add nsw i32 %shr, %mul45
  %38 = load i32, i32* %k13, align 4
  %shr47 = ashr i32 %38, 1
  %39 = load i32, i32* %6, align 4
  %mul48 = mul nsw i32 %shr47, %39
  %add49 = add nsw i32 %add46, %mul48
  store i32 %add49, i32* %ijk_c, align 4
  store double 1.562500e-01, double* %xm, align 8
  store double 9.375000e-01, double* %x0, align 8
  store double -9.375000e-02, double* %xp, align 8
  store double 1.562500e-01, double* %ym, align 8
  store double 9.375000e-01, double* %y0, align 8
  store double -9.375000e-02, double* %yp, align 8
  store double 1.562500e-01, double* %zm, align 8
  store double 9.375000e-01, double* %z0, align 8
  store double -9.375000e-02, double* %zp, align 8
  %40 = load i32, i32* %i, align 4
  %and = and i32 %40, 1
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  store double -9.375000e-02, double* %xm, align 8
  store double 9.375000e-01, double* %x0, align 8
  store double 1.562500e-01, double* %xp, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  %41 = load i32, i32* %j14, align 4
  %and50 = and i32 %41, 1
  %tobool51 = icmp ne i32 %and50, 0
  br i1 %tobool51, label %if.then52, label %if.end53

if.then52:                                        ; preds = %if.end
  store double -9.375000e-02, double* %ym, align 8
  store double 9.375000e-01, double* %y0, align 8
  store double 1.562500e-01, double* %yp, align 8
  br label %if.end53

if.end53:                                         ; preds = %if.then52, %if.end
  %42 = load i32, i32* %k13, align 4
  %and54 = and i32 %42, 1
  %tobool55 = icmp ne i32 %and54, 0
  br i1 %tobool55, label %if.then56, label %if.end57

if.then56:                                        ; preds = %if.end53
  store double -9.375000e-02, double* %zm, align 8
  store double 9.375000e-01, double* %z0, align 8
  store double 1.562500e-01, double* %zp, align 8
  br label %if.end57

if.end57:                                         ; preds = %if.then56, %if.end53
  %43 = load double, double* %8, align 8
  %44 = load i32, i32* %ijk_f, align 4
  %idxprom = sext i32 %44 to i64
  %45 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %45, i64 %idxprom
  %46 = load double, double* %arrayidx, align 8
  %mul58 = fmul double %43, %46
  %47 = load double, double* %zm, align 8
  %48 = load double, double* %ym, align 8
  %mul59 = fmul double %47, %48
  %49 = load double, double* %xm, align 8
  %mul60 = fmul double %mul59, %49
  %50 = load i32, i32* %ijk_c, align 4
  %sub61 = sub nsw i32 %50, 1
  %51 = load i32, i32* %5, align 4
  %sub62 = sub nsw i32 %sub61, %51
  %52 = load i32, i32* %6, align 4
  %sub63 = sub nsw i32 %sub62, %52
  %idxprom64 = sext i32 %sub63 to i64
  %53 = load double*, double** %9, align 8
  %arrayidx65 = getelementptr inbounds double, double* %53, i64 %idxprom64
  %54 = load double, double* %arrayidx65, align 8
  %mul66 = fmul double %mul60, %54
  %add67 = fadd double %mul58, %mul66
  %55 = load double, double* %zm, align 8
  %56 = load double, double* %ym, align 8
  %mul68 = fmul double %55, %56
  %57 = load double, double* %x0, align 8
  %mul69 = fmul double %mul68, %57
  %58 = load i32, i32* %ijk_c, align 4
  %59 = load i32, i32* %5, align 4
  %sub70 = sub nsw i32 %58, %59
  %60 = load i32, i32* %6, align 4
  %sub71 = sub nsw i32 %sub70, %60
  %idxprom72 = sext i32 %sub71 to i64
  %61 = load double*, double** %9, align 8
  %arrayidx73 = getelementptr inbounds double, double* %61, i64 %idxprom72
  %62 = load double, double* %arrayidx73, align 8
  %mul74 = fmul double %mul69, %62
  %add75 = fadd double %add67, %mul74
  %63 = load double, double* %zm, align 8
  %64 = load double, double* %ym, align 8
  %mul76 = fmul double %63, %64
  %65 = load double, double* %xp, align 8
  %mul77 = fmul double %mul76, %65
  %66 = load i32, i32* %ijk_c, align 4
  %add78 = add nsw i32 %66, 1
  %67 = load i32, i32* %5, align 4
  %sub79 = sub nsw i32 %add78, %67
  %68 = load i32, i32* %6, align 4
  %sub80 = sub nsw i32 %sub79, %68
  %idxprom81 = sext i32 %sub80 to i64
  %69 = load double*, double** %9, align 8
  %arrayidx82 = getelementptr inbounds double, double* %69, i64 %idxprom81
  %70 = load double, double* %arrayidx82, align 8
  %mul83 = fmul double %mul77, %70
  %add84 = fadd double %add75, %mul83
  %71 = load double, double* %zm, align 8
  %72 = load double, double* %y0, align 8
  %mul85 = fmul double %71, %72
  %73 = load double, double* %xm, align 8
  %mul86 = fmul double %mul85, %73
  %74 = load i32, i32* %ijk_c, align 4
  %sub87 = sub nsw i32 %74, 1
  %75 = load i32, i32* %6, align 4
  %sub88 = sub nsw i32 %sub87, %75
  %idxprom89 = sext i32 %sub88 to i64
  %76 = load double*, double** %9, align 8
  %arrayidx90 = getelementptr inbounds double, double* %76, i64 %idxprom89
  %77 = load double, double* %arrayidx90, align 8
  %mul91 = fmul double %mul86, %77
  %add92 = fadd double %add84, %mul91
  %78 = load double, double* %zm, align 8
  %79 = load double, double* %y0, align 8
  %mul93 = fmul double %78, %79
  %80 = load double, double* %x0, align 8
  %mul94 = fmul double %mul93, %80
  %81 = load i32, i32* %ijk_c, align 4
  %82 = load i32, i32* %6, align 4
  %sub95 = sub nsw i32 %81, %82
  %idxprom96 = sext i32 %sub95 to i64
  %83 = load double*, double** %9, align 8
  %arrayidx97 = getelementptr inbounds double, double* %83, i64 %idxprom96
  %84 = load double, double* %arrayidx97, align 8
  %mul98 = fmul double %mul94, %84
  %add99 = fadd double %add92, %mul98
  %85 = load double, double* %zm, align 8
  %86 = load double, double* %y0, align 8
  %mul100 = fmul double %85, %86
  %87 = load double, double* %xp, align 8
  %mul101 = fmul double %mul100, %87
  %88 = load i32, i32* %ijk_c, align 4
  %add102 = add nsw i32 %88, 1
  %89 = load i32, i32* %6, align 4
  %sub103 = sub nsw i32 %add102, %89
  %idxprom104 = sext i32 %sub103 to i64
  %90 = load double*, double** %9, align 8
  %arrayidx105 = getelementptr inbounds double, double* %90, i64 %idxprom104
  %91 = load double, double* %arrayidx105, align 8
  %mul106 = fmul double %mul101, %91
  %add107 = fadd double %add99, %mul106
  %92 = load double, double* %zm, align 8
  %93 = load double, double* %yp, align 8
  %mul108 = fmul double %92, %93
  %94 = load double, double* %xm, align 8
  %mul109 = fmul double %mul108, %94
  %95 = load i32, i32* %ijk_c, align 4
  %sub110 = sub nsw i32 %95, 1
  %96 = load i32, i32* %5, align 4
  %add111 = add nsw i32 %sub110, %96
  %97 = load i32, i32* %6, align 4
  %sub112 = sub nsw i32 %add111, %97
  %idxprom113 = sext i32 %sub112 to i64
  %98 = load double*, double** %9, align 8
  %arrayidx114 = getelementptr inbounds double, double* %98, i64 %idxprom113
  %99 = load double, double* %arrayidx114, align 8
  %mul115 = fmul double %mul109, %99
  %add116 = fadd double %add107, %mul115
  %100 = load double, double* %zm, align 8
  %101 = load double, double* %yp, align 8
  %mul117 = fmul double %100, %101
  %102 = load double, double* %x0, align 8
  %mul118 = fmul double %mul117, %102
  %103 = load i32, i32* %ijk_c, align 4
  %104 = load i32, i32* %5, align 4
  %add119 = add nsw i32 %103, %104
  %105 = load i32, i32* %6, align 4
  %sub120 = sub nsw i32 %add119, %105
  %idxprom121 = sext i32 %sub120 to i64
  %106 = load double*, double** %9, align 8
  %arrayidx122 = getelementptr inbounds double, double* %106, i64 %idxprom121
  %107 = load double, double* %arrayidx122, align 8
  %mul123 = fmul double %mul118, %107
  %add124 = fadd double %add116, %mul123
  %108 = load double, double* %zm, align 8
  %109 = load double, double* %yp, align 8
  %mul125 = fmul double %108, %109
  %110 = load double, double* %xp, align 8
  %mul126 = fmul double %mul125, %110
  %111 = load i32, i32* %ijk_c, align 4
  %add127 = add nsw i32 %111, 1
  %112 = load i32, i32* %5, align 4
  %add128 = add nsw i32 %add127, %112
  %113 = load i32, i32* %6, align 4
  %sub129 = sub nsw i32 %add128, %113
  %idxprom130 = sext i32 %sub129 to i64
  %114 = load double*, double** %9, align 8
  %arrayidx131 = getelementptr inbounds double, double* %114, i64 %idxprom130
  %115 = load double, double* %arrayidx131, align 8
  %mul132 = fmul double %mul126, %115
  %add133 = fadd double %add124, %mul132
  %116 = load double, double* %z0, align 8
  %117 = load double, double* %ym, align 8
  %mul134 = fmul double %116, %117
  %118 = load double, double* %xm, align 8
  %mul135 = fmul double %mul134, %118
  %119 = load i32, i32* %ijk_c, align 4
  %sub136 = sub nsw i32 %119, 1
  %120 = load i32, i32* %5, align 4
  %sub137 = sub nsw i32 %sub136, %120
  %idxprom138 = sext i32 %sub137 to i64
  %121 = load double*, double** %9, align 8
  %arrayidx139 = getelementptr inbounds double, double* %121, i64 %idxprom138
  %122 = load double, double* %arrayidx139, align 8
  %mul140 = fmul double %mul135, %122
  %add141 = fadd double %add133, %mul140
  %123 = load double, double* %z0, align 8
  %124 = load double, double* %ym, align 8
  %mul142 = fmul double %123, %124
  %125 = load double, double* %x0, align 8
  %mul143 = fmul double %mul142, %125
  %126 = load i32, i32* %ijk_c, align 4
  %127 = load i32, i32* %5, align 4
  %sub144 = sub nsw i32 %126, %127
  %idxprom145 = sext i32 %sub144 to i64
  %128 = load double*, double** %9, align 8
  %arrayidx146 = getelementptr inbounds double, double* %128, i64 %idxprom145
  %129 = load double, double* %arrayidx146, align 8
  %mul147 = fmul double %mul143, %129
  %add148 = fadd double %add141, %mul147
  %130 = load double, double* %z0, align 8
  %131 = load double, double* %ym, align 8
  %mul149 = fmul double %130, %131
  %132 = load double, double* %xp, align 8
  %mul150 = fmul double %mul149, %132
  %133 = load i32, i32* %ijk_c, align 4
  %add151 = add nsw i32 %133, 1
  %134 = load i32, i32* %5, align 4
  %sub152 = sub nsw i32 %add151, %134
  %idxprom153 = sext i32 %sub152 to i64
  %135 = load double*, double** %9, align 8
  %arrayidx154 = getelementptr inbounds double, double* %135, i64 %idxprom153
  %136 = load double, double* %arrayidx154, align 8
  %mul155 = fmul double %mul150, %136
  %add156 = fadd double %add148, %mul155
  %137 = load double, double* %z0, align 8
  %138 = load double, double* %y0, align 8
  %mul157 = fmul double %137, %138
  %139 = load double, double* %xm, align 8
  %mul158 = fmul double %mul157, %139
  %140 = load i32, i32* %ijk_c, align 4
  %sub159 = sub nsw i32 %140, 1
  %idxprom160 = sext i32 %sub159 to i64
  %141 = load double*, double** %9, align 8
  %arrayidx161 = getelementptr inbounds double, double* %141, i64 %idxprom160
  %142 = load double, double* %arrayidx161, align 8
  %mul162 = fmul double %mul158, %142
  %add163 = fadd double %add156, %mul162
  %143 = load double, double* %z0, align 8
  %144 = load double, double* %y0, align 8
  %mul164 = fmul double %143, %144
  %145 = load double, double* %x0, align 8
  %mul165 = fmul double %mul164, %145
  %146 = load i32, i32* %ijk_c, align 4
  %idxprom166 = sext i32 %146 to i64
  %147 = load double*, double** %9, align 8
  %arrayidx167 = getelementptr inbounds double, double* %147, i64 %idxprom166
  %148 = load double, double* %arrayidx167, align 8
  %mul168 = fmul double %mul165, %148
  %add169 = fadd double %add163, %mul168
  %149 = load double, double* %z0, align 8
  %150 = load double, double* %y0, align 8
  %mul170 = fmul double %149, %150
  %151 = load double, double* %xp, align 8
  %mul171 = fmul double %mul170, %151
  %152 = load i32, i32* %ijk_c, align 4
  %add172 = add nsw i32 %152, 1
  %idxprom173 = sext i32 %add172 to i64
  %153 = load double*, double** %9, align 8
  %arrayidx174 = getelementptr inbounds double, double* %153, i64 %idxprom173
  %154 = load double, double* %arrayidx174, align 8
  %mul175 = fmul double %mul171, %154
  %add176 = fadd double %add169, %mul175
  %155 = load double, double* %z0, align 8
  %156 = load double, double* %yp, align 8
  %mul177 = fmul double %155, %156
  %157 = load double, double* %xm, align 8
  %mul178 = fmul double %mul177, %157
  %158 = load i32, i32* %ijk_c, align 4
  %sub179 = sub nsw i32 %158, 1
  %159 = load i32, i32* %5, align 4
  %add180 = add nsw i32 %sub179, %159
  %idxprom181 = sext i32 %add180 to i64
  %160 = load double*, double** %9, align 8
  %arrayidx182 = getelementptr inbounds double, double* %160, i64 %idxprom181
  %161 = load double, double* %arrayidx182, align 8
  %mul183 = fmul double %mul178, %161
  %add184 = fadd double %add176, %mul183
  %162 = load double, double* %z0, align 8
  %163 = load double, double* %yp, align 8
  %mul185 = fmul double %162, %163
  %164 = load double, double* %x0, align 8
  %mul186 = fmul double %mul185, %164
  %165 = load i32, i32* %ijk_c, align 4
  %166 = load i32, i32* %5, align 4
  %add187 = add nsw i32 %165, %166
  %idxprom188 = sext i32 %add187 to i64
  %167 = load double*, double** %9, align 8
  %arrayidx189 = getelementptr inbounds double, double* %167, i64 %idxprom188
  %168 = load double, double* %arrayidx189, align 8
  %mul190 = fmul double %mul186, %168
  %add191 = fadd double %add184, %mul190
  %169 = load double, double* %z0, align 8
  %170 = load double, double* %yp, align 8
  %mul192 = fmul double %169, %170
  %171 = load double, double* %xp, align 8
  %mul193 = fmul double %mul192, %171
  %172 = load i32, i32* %ijk_c, align 4
  %add194 = add nsw i32 %172, 1
  %173 = load i32, i32* %5, align 4
  %add195 = add nsw i32 %add194, %173
  %idxprom196 = sext i32 %add195 to i64
  %174 = load double*, double** %9, align 8
  %arrayidx197 = getelementptr inbounds double, double* %174, i64 %idxprom196
  %175 = load double, double* %arrayidx197, align 8
  %mul198 = fmul double %mul193, %175
  %add199 = fadd double %add191, %mul198
  %176 = load double, double* %zp, align 8
  %177 = load double, double* %ym, align 8
  %mul200 = fmul double %176, %177
  %178 = load double, double* %xm, align 8
  %mul201 = fmul double %mul200, %178
  %179 = load i32, i32* %ijk_c, align 4
  %sub202 = sub nsw i32 %179, 1
  %180 = load i32, i32* %5, align 4
  %sub203 = sub nsw i32 %sub202, %180
  %181 = load i32, i32* %6, align 4
  %add204 = add nsw i32 %sub203, %181
  %idxprom205 = sext i32 %add204 to i64
  %182 = load double*, double** %9, align 8
  %arrayidx206 = getelementptr inbounds double, double* %182, i64 %idxprom205
  %183 = load double, double* %arrayidx206, align 8
  %mul207 = fmul double %mul201, %183
  %add208 = fadd double %add199, %mul207
  %184 = load double, double* %zp, align 8
  %185 = load double, double* %ym, align 8
  %mul209 = fmul double %184, %185
  %186 = load double, double* %x0, align 8
  %mul210 = fmul double %mul209, %186
  %187 = load i32, i32* %ijk_c, align 4
  %188 = load i32, i32* %5, align 4
  %sub211 = sub nsw i32 %187, %188
  %189 = load i32, i32* %6, align 4
  %add212 = add nsw i32 %sub211, %189
  %idxprom213 = sext i32 %add212 to i64
  %190 = load double*, double** %9, align 8
  %arrayidx214 = getelementptr inbounds double, double* %190, i64 %idxprom213
  %191 = load double, double* %arrayidx214, align 8
  %mul215 = fmul double %mul210, %191
  %add216 = fadd double %add208, %mul215
  %192 = load double, double* %zp, align 8
  %193 = load double, double* %ym, align 8
  %mul217 = fmul double %192, %193
  %194 = load double, double* %xp, align 8
  %mul218 = fmul double %mul217, %194
  %195 = load i32, i32* %ijk_c, align 4
  %add219 = add nsw i32 %195, 1
  %196 = load i32, i32* %5, align 4
  %sub220 = sub nsw i32 %add219, %196
  %197 = load i32, i32* %6, align 4
  %add221 = add nsw i32 %sub220, %197
  %idxprom222 = sext i32 %add221 to i64
  %198 = load double*, double** %9, align 8
  %arrayidx223 = getelementptr inbounds double, double* %198, i64 %idxprom222
  %199 = load double, double* %arrayidx223, align 8
  %mul224 = fmul double %mul218, %199
  %add225 = fadd double %add216, %mul224
  %200 = load double, double* %zp, align 8
  %201 = load double, double* %y0, align 8
  %mul226 = fmul double %200, %201
  %202 = load double, double* %xm, align 8
  %mul227 = fmul double %mul226, %202
  %203 = load i32, i32* %ijk_c, align 4
  %sub228 = sub nsw i32 %203, 1
  %204 = load i32, i32* %6, align 4
  %add229 = add nsw i32 %sub228, %204
  %idxprom230 = sext i32 %add229 to i64
  %205 = load double*, double** %9, align 8
  %arrayidx231 = getelementptr inbounds double, double* %205, i64 %idxprom230
  %206 = load double, double* %arrayidx231, align 8
  %mul232 = fmul double %mul227, %206
  %add233 = fadd double %add225, %mul232
  %207 = load double, double* %zp, align 8
  %208 = load double, double* %y0, align 8
  %mul234 = fmul double %207, %208
  %209 = load double, double* %x0, align 8
  %mul235 = fmul double %mul234, %209
  %210 = load i32, i32* %ijk_c, align 4
  %211 = load i32, i32* %6, align 4
  %add236 = add nsw i32 %210, %211
  %idxprom237 = sext i32 %add236 to i64
  %212 = load double*, double** %9, align 8
  %arrayidx238 = getelementptr inbounds double, double* %212, i64 %idxprom237
  %213 = load double, double* %arrayidx238, align 8
  %mul239 = fmul double %mul235, %213
  %add240 = fadd double %add233, %mul239
  %214 = load double, double* %zp, align 8
  %215 = load double, double* %y0, align 8
  %mul241 = fmul double %214, %215
  %216 = load double, double* %xp, align 8
  %mul242 = fmul double %mul241, %216
  %217 = load i32, i32* %ijk_c, align 4
  %add243 = add nsw i32 %217, 1
  %218 = load i32, i32* %6, align 4
  %add244 = add nsw i32 %add243, %218
  %idxprom245 = sext i32 %add244 to i64
  %219 = load double*, double** %9, align 8
  %arrayidx246 = getelementptr inbounds double, double* %219, i64 %idxprom245
  %220 = load double, double* %arrayidx246, align 8
  %mul247 = fmul double %mul242, %220
  %add248 = fadd double %add240, %mul247
  %221 = load double, double* %zp, align 8
  %222 = load double, double* %yp, align 8
  %mul249 = fmul double %221, %222
  %223 = load double, double* %xm, align 8
  %mul250 = fmul double %mul249, %223
  %224 = load i32, i32* %ijk_c, align 4
  %sub251 = sub nsw i32 %224, 1
  %225 = load i32, i32* %5, align 4
  %add252 = add nsw i32 %sub251, %225
  %226 = load i32, i32* %6, align 4
  %add253 = add nsw i32 %add252, %226
  %idxprom254 = sext i32 %add253 to i64
  %227 = load double*, double** %9, align 8
  %arrayidx255 = getelementptr inbounds double, double* %227, i64 %idxprom254
  %228 = load double, double* %arrayidx255, align 8
  %mul256 = fmul double %mul250, %228
  %add257 = fadd double %add248, %mul256
  %229 = load double, double* %zp, align 8
  %230 = load double, double* %yp, align 8
  %mul258 = fmul double %229, %230
  %231 = load double, double* %x0, align 8
  %mul259 = fmul double %mul258, %231
  %232 = load i32, i32* %ijk_c, align 4
  %233 = load i32, i32* %5, align 4
  %add260 = add nsw i32 %232, %233
  %234 = load i32, i32* %6, align 4
  %add261 = add nsw i32 %add260, %234
  %idxprom262 = sext i32 %add261 to i64
  %235 = load double*, double** %9, align 8
  %arrayidx263 = getelementptr inbounds double, double* %235, i64 %idxprom262
  %236 = load double, double* %arrayidx263, align 8
  %mul264 = fmul double %mul259, %236
  %add265 = fadd double %add257, %mul264
  %237 = load double, double* %zp, align 8
  %238 = load double, double* %yp, align 8
  %mul266 = fmul double %237, %238
  %239 = load double, double* %xp, align 8
  %mul267 = fmul double %mul266, %239
  %240 = load i32, i32* %ijk_c, align 4
  %add268 = add nsw i32 %240, 1
  %241 = load i32, i32* %5, align 4
  %add269 = add nsw i32 %add268, %241
  %242 = load i32, i32* %6, align 4
  %add270 = add nsw i32 %add269, %242
  %idxprom271 = sext i32 %add270 to i64
  %243 = load double*, double** %9, align 8
  %arrayidx272 = getelementptr inbounds double, double* %243, i64 %idxprom271
  %244 = load double, double* %arrayidx272, align 8
  %mul273 = fmul double %mul267, %244
  %add274 = fadd double %add265, %mul273
  %245 = load i32, i32* %ijk_f, align 4
  %idxprom275 = sext i32 %245 to i64
  %246 = load double*, double** %7, align 8
  %arrayidx276 = getelementptr inbounds double, double* %246, i64 %idxprom275
  store double %add274, double* %arrayidx276, align 8
  br label %for.inc

for.inc:                                          ; preds = %if.end57
  %247 = load i32, i32* %i, align 4
  %inc = add nsw i32 %247, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %248 = load i64, i64* %.omp.iv, align 8
  %add277 = add nsw i64 %248, 1
  store i64 %add277, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %249 = load i32*, i32** %.global_tid..addr, align 8
  %250 = load i32, i32* %249, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %250)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @zero_grid(%struct.domain_type* %domain, i32 %level, i32 %grid_id) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %grid_id.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %grid_id, i32* %grid_id.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 4, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*)* @.omp_outlined..25 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..25(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..25(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %grid_id, i32* dereferenceable(4) %omp_within_a_box) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %grid_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %grid_id, i32** %grid_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %grid_id.addr, align 8
  %3 = load i32*, i32** %omp_within_a_box.addr, align 8
  %4 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %4, i32 0, i32 19
  %5 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %5, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %7
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %8 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %8, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %9 = load i32*, i32** %.global_tid..addr, align 8
  %10 = load i32, i32* %9, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %10, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %11 = load i32, i32* %.omp.ub, align 4
  %12 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %11, %12
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %13 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %14 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %13, %cond.true ], [ %14, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.lb, align 4
  store i32 %15, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %16 = load i32, i32* %.omp.iv, align 4
  %17 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %16, %17
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %18 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %18, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %19 = load i32, i32* %1, align 4
  %idxprom = sext i32 %19 to i64
  %20 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %20 to i64
  %21 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %21, i32 0, i32 25
  %22 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %22, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %23 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %23, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %24 = load i32, i32* %pencil11, align 8
  store i32 %24, i32* %pencil, align 4
  %25 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %25 to i64
  %26 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %26 to i64
  %27 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %27, i32 0, i32 25
  %28 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %28, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %29 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %29, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %30 = load i32, i32* %plane18, align 4
  store i32 %30, i32* %plane, align 4
  %31 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %31 to i64
  %32 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %32 to i64
  %33 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %33, i32 0, i32 25
  %34 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %34, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %35 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %35, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %36 = load i32, i32* %ghosts25, align 4
  store i32 %36, i32* %ghosts, align 4
  %37 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %37 to i64
  %38 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %38 to i64
  %39 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %39, i32 0, i32 25
  %40 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %40, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %41 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %41, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %42 = load i32, i32* %k32, align 4
  store i32 %42, i32* %dim_k, align 4
  %43 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %43 to i64
  %44 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %44 to i64
  %45 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %45, i32 0, i32 25
  %46 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %46, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %47 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %47, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %48 = load i32, i32* %j40, align 4
  store i32 %48, i32* %dim_j, align 4
  %49 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %49 to i64
  %50 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %50 to i64
  %51 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %51, i32 0, i32 25
  %52 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %52, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %53 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %53, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %54 = load i32, i32* %i48, align 4
  store i32 %54, i32* %dim_i, align 4
  %55 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %55 to i64
  %56 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %56 to i64
  %57 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %57 to i64
  %58 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %58, i32 0, i32 25
  %59 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %59, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %60 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %60, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %61 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %61, i64 %idxprom49
  %62 = load double*, double** %arrayidx56, align 8
  %63 = load i32, i32* %ghosts, align 4
  %64 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %64
  %65 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %65
  %mul59 = mul nsw i32 %63, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %62, i64 %idx.ext
  store double* %add.ptr, double** %grid, align 8
  %66 = load i32, i32* %3, align 4
  %tobool = icmp ne i32 %66, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**)* @.omp_outlined..26 to void (i32*, i32*, ...)*), i32* %ghosts, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %67 = load i32*, i32** %.global_tid..addr, align 8
  %68 = load i32, i32* %67, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %68)
  %69 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..26(i32* %69, i32* %.zero.addr, i32* %ghosts, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %68)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %70 = load i32, i32* %.omp.iv, align 4
  %add60 = add nsw i32 %70, 1
  store i32 %add60, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %71 = load i32*, i32** %.global_tid..addr, align 8
  %72 = load i32, i32* %71, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %72)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..26(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %ghosts, i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %ghosts.addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k23 = alloca i32, align 4
  %j24 = alloca i32, align 4
  %i = alloca i32, align 4
  %k25 = alloca i32, align 4
  %j26 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %ghosts, i32** %ghosts.addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid, double*** %grid.addr, align 8
  %0 = load i32*, i32** %ghosts.addr, align 8
  %1 = load i32*, i32** %dim_k.addr, align 8
  %2 = load i32*, i32** %dim_j.addr, align 8
  %3 = load i32*, i32** %dim_i.addr, align 8
  %4 = load i32*, i32** %pencil.addr, align 8
  %5 = load i32*, i32** %plane.addr, align 8
  %6 = load double**, double*** %grid.addr, align 8
  %7 = load i32, i32* %1, align 4
  %8 = load i32, i32* %0, align 4
  %add = add nsw i32 %7, %8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 0, %9
  %sub1 = sub nsw i32 %add, %sub
  %sub2 = sub nsw i32 %sub1, 1
  %add3 = add nsw i32 %sub2, 1
  %div = sdiv i32 %add3, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %2, align 4
  %11 = load i32, i32* %0, align 4
  %add4 = add nsw i32 %10, %11
  %12 = load i32, i32* %0, align 4
  %sub5 = sub nsw i32 0, %12
  %sub6 = sub nsw i32 %add4, %sub5
  %sub7 = sub nsw i32 %sub6, 1
  %add8 = add nsw i32 %sub7, 1
  %div9 = sdiv i32 %add8, 1
  %conv10 = sext i32 %div9 to i64
  %mul = mul nsw i64 %conv, %conv10
  %sub11 = sub nsw i64 %mul, 1
  store i64 %sub11, i64* %.omp.last.iteration, align 8
  %13 = load i32, i32* %0, align 4
  %sub12 = sub nsw i32 0, %13
  store i32 %sub12, i32* %k, align 4
  %14 = load i32, i32* %0, align 4
  %sub13 = sub nsw i32 0, %14
  store i32 %sub13, i32* %j, align 4
  %15 = load i32, i32* %0, align 4
  %sub14 = sub nsw i32 0, %15
  %16 = load i32, i32* %1, align 4
  %17 = load i32, i32* %0, align 4
  %add15 = add nsw i32 %16, %17
  %cmp = icmp slt i32 %sub14, %add15
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %18 = load i32, i32* %0, align 4
  %sub18 = sub nsw i32 0, %18
  %19 = load i32, i32* %2, align 4
  %20 = load i32, i32* %0, align 4
  %add19 = add nsw i32 %19, %20
  %cmp20 = icmp slt i32 %sub18, %add19
  br i1 %cmp20, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %21 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %21, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %22 = load i32*, i32** %.global_tid..addr, align 8
  %23 = load i32, i32* %22, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %23, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %24 = load i64, i64* %.omp.ub, align 8
  %25 = load i64, i64* %.omp.last.iteration, align 8
  %cmp27 = icmp sgt i64 %24, %25
  br i1 %cmp27, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %26 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %27 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %26, %cond.true ], [ %27, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %28 = load i64, i64* %.omp.lb, align 8
  store i64 %28, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %29 = load i64, i64* %.omp.iv, align 8
  %30 = load i64, i64* %.omp.ub, align 8
  %cmp29 = icmp sle i64 %29, %30
  br i1 %cmp29, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %31 = load i32, i32* %0, align 4
  %sub31 = sub nsw i32 0, %31
  %conv32 = sext i32 %sub31 to i64
  %32 = load i64, i64* %.omp.iv, align 8
  %33 = load i32, i32* %2, align 4
  %34 = load i32, i32* %0, align 4
  %add33 = add nsw i32 %33, %34
  %35 = load i32, i32* %0, align 4
  %sub34 = sub nsw i32 0, %35
  %sub35 = sub nsw i32 %add33, %sub34
  %sub36 = sub nsw i32 %sub35, 1
  %add37 = add nsw i32 %sub36, 1
  %div38 = sdiv i32 %add37, 1
  %conv39 = sext i32 %div38 to i64
  %div40 = sdiv i64 %32, %conv39
  %mul41 = mul nsw i64 %div40, 1
  %add42 = add nsw i64 %conv32, %mul41
  %conv43 = trunc i64 %add42 to i32
  store i32 %conv43, i32* %k23, align 4
  %36 = load i32, i32* %0, align 4
  %sub44 = sub nsw i32 0, %36
  %conv45 = sext i32 %sub44 to i64
  %37 = load i64, i64* %.omp.iv, align 8
  %38 = load i32, i32* %2, align 4
  %39 = load i32, i32* %0, align 4
  %add46 = add nsw i32 %38, %39
  %40 = load i32, i32* %0, align 4
  %sub47 = sub nsw i32 0, %40
  %sub48 = sub nsw i32 %add46, %sub47
  %sub49 = sub nsw i32 %sub48, 1
  %add50 = add nsw i32 %sub49, 1
  %div51 = sdiv i32 %add50, 1
  %conv52 = sext i32 %div51 to i64
  %rem = srem i64 %37, %conv52
  %mul53 = mul nsw i64 %rem, 1
  %add54 = add nsw i64 %conv45, %mul53
  %conv55 = trunc i64 %add54 to i32
  store i32 %conv55, i32* %j24, align 4
  %41 = load i32, i32* %0, align 4
  %sub56 = sub nsw i32 0, %41
  store i32 %sub56, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %42 = load i32, i32* %i, align 4
  %43 = load i32, i32* %3, align 4
  %44 = load i32, i32* %0, align 4
  %add57 = add nsw i32 %43, %44
  %cmp58 = icmp slt i32 %42, %add57
  br i1 %cmp58, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %45 = load i32, i32* %i, align 4
  %46 = load i32, i32* %j24, align 4
  %47 = load i32, i32* %4, align 4
  %mul60 = mul nsw i32 %46, %47
  %add61 = add nsw i32 %45, %mul60
  %48 = load i32, i32* %k23, align 4
  %49 = load i32, i32* %5, align 4
  %mul62 = mul nsw i32 %48, %49
  %add63 = add nsw i32 %add61, %mul62
  store i32 %add63, i32* %ijk, align 4
  %50 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %50 to i64
  %51 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %51, i64 %idxprom
  store double 0.000000e+00, double* %arrayidx, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %52 = load i32, i32* %i, align 4
  %inc = add nsw i32 %52, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %53 = load i64, i64* %.omp.iv, align 8
  %add64 = add nsw i64 %53, 1
  store i64 %add64, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %54 = load i32*, i32** %.global_tid..addr, align 8
  %55 = load i32, i32* %54, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %55)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @initialize_grid_to_scalar(%struct.domain_type* %domain, i32 %level, i32 %grid_id, double %scalar) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %grid_id.addr = alloca i32, align 4
  %scalar.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %grid_id, i32* %grid_id.addr, align 4
  store double %scalar, double* %scalar.addr, align 8
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 5, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, double*)* @.omp_outlined..27 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box, double* %scalar.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..27(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box, double* %scalar.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..27(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %grid_id, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %scalar) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %grid_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %scalar.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %grid_id, i32** %grid_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %scalar, double** %scalar.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %grid_id.addr, align 8
  %3 = load i32*, i32** %omp_within_a_box.addr, align 8
  %4 = load double*, double** %scalar.addr, align 8
  %5 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 19
  %6 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %6, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %8
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %9 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %9, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %10 = load i32*, i32** %.global_tid..addr, align 8
  %11 = load i32, i32* %10, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %11, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %12 = load i32, i32* %.omp.ub, align 4
  %13 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %12, %13
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %14 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %14, %cond.true ], [ %15, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %16 = load i32, i32* %.omp.lb, align 4
  store i32 %16, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %17 = load i32, i32* %.omp.iv, align 4
  %18 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %17, %18
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %19 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %19, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %20 = load i32, i32* %1, align 4
  %idxprom = sext i32 %20 to i64
  %21 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %21 to i64
  %22 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %22, i32 0, i32 25
  %23 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %23, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %24 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %24, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %25 = load i32, i32* %pencil11, align 8
  store i32 %25, i32* %pencil, align 4
  %26 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %26 to i64
  %27 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %27 to i64
  %28 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %28, i32 0, i32 25
  %29 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %29, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %30 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %30, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %31 = load i32, i32* %plane18, align 4
  store i32 %31, i32* %plane, align 4
  %32 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %32 to i64
  %33 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %33 to i64
  %34 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %34, i32 0, i32 25
  %35 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %35, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %36 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %36, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %37 = load i32, i32* %ghosts25, align 4
  store i32 %37, i32* %ghosts, align 4
  %38 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %38 to i64
  %39 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %39 to i64
  %40 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %40, i32 0, i32 25
  %41 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %41, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %42 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %42, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %43 = load i32, i32* %k32, align 4
  store i32 %43, i32* %dim_k, align 4
  %44 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %44 to i64
  %45 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %45 to i64
  %46 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %46, i32 0, i32 25
  %47 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %47, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %48 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %48, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %49 = load i32, i32* %j40, align 4
  store i32 %49, i32* %dim_j, align 4
  %50 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %50 to i64
  %51 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %51 to i64
  %52 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %52, i32 0, i32 25
  %53 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %53, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %54 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %54, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %55 = load i32, i32* %i48, align 4
  store i32 %55, i32* %dim_i, align 4
  %56 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %56 to i64
  %57 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %57 to i64
  %58 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 25
  %60 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %60, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %61 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %61, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %62 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %62, i64 %idxprom49
  %63 = load double*, double** %arrayidx56, align 8
  %64 = load i32, i32* %ghosts, align 4
  %65 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %65
  %66 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %66
  %mul59 = mul nsw i32 %64, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %63, i64 %idx.ext
  store double* %add.ptr, double** %grid, align 8
  %67 = load i32, i32* %3, align 4
  %tobool = icmp ne i32 %67, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*)* @.omp_outlined..28 to void (i32*, i32*, ...)*), i32* %ghosts, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid, double* %4)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %68 = load i32*, i32** %.global_tid..addr, align 8
  %69 = load i32, i32* %68, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %69)
  %70 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..28(i32* %70, i32* %.zero.addr, i32* %ghosts, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid, double* %4)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %69)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %71 = load i32, i32* %.omp.iv, align 4
  %add60 = add nsw i32 %71, 1
  store i32 %add60, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %72 = load i32*, i32** %.global_tid..addr, align 8
  %73 = load i32, i32* %72, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %73)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..28(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %ghosts, i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid, double* dereferenceable(8) %scalar) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %ghosts.addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid.addr = alloca double**, align 8
  %scalar.addr = alloca double*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k23 = alloca i32, align 4
  %j24 = alloca i32, align 4
  %i = alloca i32, align 4
  %k25 = alloca i32, align 4
  %j26 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %ghostZone = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %ghosts, i32** %ghosts.addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid, double*** %grid.addr, align 8
  store double* %scalar, double** %scalar.addr, align 8
  %0 = load i32*, i32** %ghosts.addr, align 8
  %1 = load i32*, i32** %dim_k.addr, align 8
  %2 = load i32*, i32** %dim_j.addr, align 8
  %3 = load i32*, i32** %dim_i.addr, align 8
  %4 = load i32*, i32** %pencil.addr, align 8
  %5 = load i32*, i32** %plane.addr, align 8
  %6 = load double**, double*** %grid.addr, align 8
  %7 = load double*, double** %scalar.addr, align 8
  %8 = load i32, i32* %1, align 4
  %9 = load i32, i32* %0, align 4
  %add = add nsw i32 %8, %9
  %10 = load i32, i32* %0, align 4
  %sub = sub nsw i32 0, %10
  %sub1 = sub nsw i32 %add, %sub
  %sub2 = sub nsw i32 %sub1, 1
  %add3 = add nsw i32 %sub2, 1
  %div = sdiv i32 %add3, 1
  %conv = sext i32 %div to i64
  %11 = load i32, i32* %2, align 4
  %12 = load i32, i32* %0, align 4
  %add4 = add nsw i32 %11, %12
  %13 = load i32, i32* %0, align 4
  %sub5 = sub nsw i32 0, %13
  %sub6 = sub nsw i32 %add4, %sub5
  %sub7 = sub nsw i32 %sub6, 1
  %add8 = add nsw i32 %sub7, 1
  %div9 = sdiv i32 %add8, 1
  %conv10 = sext i32 %div9 to i64
  %mul = mul nsw i64 %conv, %conv10
  %sub11 = sub nsw i64 %mul, 1
  store i64 %sub11, i64* %.omp.last.iteration, align 8
  %14 = load i32, i32* %0, align 4
  %sub12 = sub nsw i32 0, %14
  store i32 %sub12, i32* %k, align 4
  %15 = load i32, i32* %0, align 4
  %sub13 = sub nsw i32 0, %15
  store i32 %sub13, i32* %j, align 4
  %16 = load i32, i32* %0, align 4
  %sub14 = sub nsw i32 0, %16
  %17 = load i32, i32* %1, align 4
  %18 = load i32, i32* %0, align 4
  %add15 = add nsw i32 %17, %18
  %cmp = icmp slt i32 %sub14, %add15
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %19 = load i32, i32* %0, align 4
  %sub18 = sub nsw i32 0, %19
  %20 = load i32, i32* %2, align 4
  %21 = load i32, i32* %0, align 4
  %add19 = add nsw i32 %20, %21
  %cmp20 = icmp slt i32 %sub18, %add19
  br i1 %cmp20, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %22 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %22, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %23 = load i32*, i32** %.global_tid..addr, align 8
  %24 = load i32, i32* %23, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %24, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %25 = load i64, i64* %.omp.ub, align 8
  %26 = load i64, i64* %.omp.last.iteration, align 8
  %cmp27 = icmp sgt i64 %25, %26
  br i1 %cmp27, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %27 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %28 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %27, %cond.true ], [ %28, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %29 = load i64, i64* %.omp.lb, align 8
  store i64 %29, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %30 = load i64, i64* %.omp.iv, align 8
  %31 = load i64, i64* %.omp.ub, align 8
  %cmp29 = icmp sle i64 %30, %31
  br i1 %cmp29, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %32 = load i32, i32* %0, align 4
  %sub31 = sub nsw i32 0, %32
  %conv32 = sext i32 %sub31 to i64
  %33 = load i64, i64* %.omp.iv, align 8
  %34 = load i32, i32* %2, align 4
  %35 = load i32, i32* %0, align 4
  %add33 = add nsw i32 %34, %35
  %36 = load i32, i32* %0, align 4
  %sub34 = sub nsw i32 0, %36
  %sub35 = sub nsw i32 %add33, %sub34
  %sub36 = sub nsw i32 %sub35, 1
  %add37 = add nsw i32 %sub36, 1
  %div38 = sdiv i32 %add37, 1
  %conv39 = sext i32 %div38 to i64
  %div40 = sdiv i64 %33, %conv39
  %mul41 = mul nsw i64 %div40, 1
  %add42 = add nsw i64 %conv32, %mul41
  %conv43 = trunc i64 %add42 to i32
  store i32 %conv43, i32* %k23, align 4
  %37 = load i32, i32* %0, align 4
  %sub44 = sub nsw i32 0, %37
  %conv45 = sext i32 %sub44 to i64
  %38 = load i64, i64* %.omp.iv, align 8
  %39 = load i32, i32* %2, align 4
  %40 = load i32, i32* %0, align 4
  %add46 = add nsw i32 %39, %40
  %41 = load i32, i32* %0, align 4
  %sub47 = sub nsw i32 0, %41
  %sub48 = sub nsw i32 %add46, %sub47
  %sub49 = sub nsw i32 %sub48, 1
  %add50 = add nsw i32 %sub49, 1
  %div51 = sdiv i32 %add50, 1
  %conv52 = sext i32 %div51 to i64
  %rem = srem i64 %38, %conv52
  %mul53 = mul nsw i64 %rem, 1
  %add54 = add nsw i64 %conv45, %mul53
  %conv55 = trunc i64 %add54 to i32
  store i32 %conv55, i32* %j24, align 4
  %42 = load i32, i32* %0, align 4
  %sub56 = sub nsw i32 0, %42
  store i32 %sub56, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %43 = load i32, i32* %i, align 4
  %44 = load i32, i32* %3, align 4
  %45 = load i32, i32* %0, align 4
  %add57 = add nsw i32 %44, %45
  %cmp58 = icmp slt i32 %43, %add57
  br i1 %cmp58, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %46 = load i32, i32* %i, align 4
  %47 = load i32, i32* %j24, align 4
  %48 = load i32, i32* %4, align 4
  %mul60 = mul nsw i32 %47, %48
  %add61 = add nsw i32 %46, %mul60
  %49 = load i32, i32* %k23, align 4
  %50 = load i32, i32* %5, align 4
  %mul62 = mul nsw i32 %49, %50
  %add63 = add nsw i32 %add61, %mul62
  store i32 %add63, i32* %ijk, align 4
  %51 = load i32, i32* %i, align 4
  %cmp64 = icmp slt i32 %51, 0
  br i1 %cmp64, label %lor.end, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %for.body
  %52 = load i32, i32* %j24, align 4
  %cmp66 = icmp slt i32 %52, 0
  br i1 %cmp66, label %lor.end, label %lor.lhs.false68

lor.lhs.false68:                                  ; preds = %lor.lhs.false
  %53 = load i32, i32* %k23, align 4
  %cmp69 = icmp slt i32 %53, 0
  br i1 %cmp69, label %lor.end, label %lor.lhs.false71

lor.lhs.false71:                                  ; preds = %lor.lhs.false68
  %54 = load i32, i32* %i, align 4
  %55 = load i32, i32* %3, align 4
  %cmp72 = icmp sge i32 %54, %55
  br i1 %cmp72, label %lor.end, label %lor.lhs.false74

lor.lhs.false74:                                  ; preds = %lor.lhs.false71
  %56 = load i32, i32* %j24, align 4
  %57 = load i32, i32* %2, align 4
  %cmp75 = icmp sge i32 %56, %57
  br i1 %cmp75, label %lor.end, label %lor.rhs

lor.rhs:                                          ; preds = %lor.lhs.false74
  %58 = load i32, i32* %k23, align 4
  %59 = load i32, i32* %1, align 4
  %cmp77 = icmp sge i32 %58, %59
  br label %lor.end

lor.end:                                          ; preds = %lor.rhs, %lor.lhs.false74, %lor.lhs.false71, %lor.lhs.false68, %lor.lhs.false, %for.body
  %60 = phi i1 [ true, %lor.lhs.false74 ], [ true, %lor.lhs.false71 ], [ true, %lor.lhs.false68 ], [ true, %lor.lhs.false ], [ true, %for.body ], [ %cmp77, %lor.rhs ]
  %lor.ext = zext i1 %60 to i32
  store i32 %lor.ext, i32* %ghostZone, align 4
  %61 = load i32, i32* %ghostZone, align 4
  %tobool = icmp ne i32 %61, 0
  br i1 %tobool, label %cond.true79, label %cond.false80

cond.true79:                                      ; preds = %lor.end
  br label %cond.end81

cond.false80:                                     ; preds = %lor.end
  %62 = load double, double* %7, align 8
  br label %cond.end81

cond.end81:                                       ; preds = %cond.false80, %cond.true79
  %cond82 = phi double [ 0.000000e+00, %cond.true79 ], [ %62, %cond.false80 ]
  %63 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %63 to i64
  %64 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %64, i64 %idxprom
  store double %cond82, double* %arrayidx, align 8
  br label %for.inc

for.inc:                                          ; preds = %cond.end81
  %65 = load i32, i32* %i, align 4
  %inc = add nsw i32 %65, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %66 = load i64, i64* %.omp.iv, align 8
  %add83 = add nsw i64 %66, 1
  store i64 %add83, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %67 = load i32*, i32** %.global_tid..addr, align 8
  %68 = load i32, i32* %67, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %68)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @add_grids(%struct.domain_type* %domain, i32 %level, i32 %id_c, double %scale_a, i32 %id_a, double %scale_b, i32 %id_b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %scale_a.addr = alloca double, align 8
  %id_a.addr = alloca i32, align 4
  %scale_b.addr = alloca double, align 8
  %id_b.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  store double %scale_a, double* %scale_a.addr, align 8
  store i32 %id_a, i32* %id_a.addr, align 4
  store double %scale_b, double* %scale_b.addr, align 8
  store i32 %id_b, i32* %id_b.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, double*, double*)* @.omp_outlined..29 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %scale_a.addr, double* %scale_b.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..29(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %scale_a.addr, double* %scale_b.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..29(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %id_b, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %scale_a, double* dereferenceable(8) %scale_b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %id_b.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %scale_a.addr = alloca double*, align 8
  %scale_b.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_c = alloca double*, align 8
  %grid_a = alloca double*, align 8
  %grid_b = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %id_b, i32** %id_b.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %scale_a, double** %scale_a.addr, align 8
  store double* %scale_b, double** %scale_b.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_c.addr, align 8
  %3 = load i32*, i32** %id_a.addr, align 8
  %4 = load i32*, i32** %id_b.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load double*, double** %scale_a.addr, align 8
  %7 = load double*, double** %scale_b.addr, align 8
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %10 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %10, i32 0, i32 19
  %11 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %12 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %12, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %15 = load i32, i32* %.omp.ub, align 4
  %16 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %15, %16
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %17, %cond.true ], [ %18, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %19 = load i32, i32* %.omp.lb, align 4
  store i32 %19, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i32, i32* %.omp.iv, align 4
  %21 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %20, %21
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %22, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %23 = load i32, i32* %1, align 4
  %idxprom = sext i32 %23 to i64
  %24 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %24 to i64
  %25 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %25, i32 0, i32 25
  %26 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %26, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %27 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %27, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %28 = load i32, i32* %pencil11, align 8
  store i32 %28, i32* %pencil, align 4
  %29 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %29 to i64
  %30 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %30 to i64
  %31 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 25
  %32 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %32, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %33 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %33, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %34 = load i32, i32* %plane18, align 4
  store i32 %34, i32* %plane, align 4
  %35 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %35 to i64
  %36 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %36 to i64
  %37 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %37, i32 0, i32 25
  %38 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %38, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %39 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %39, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %40 = load i32, i32* %ghosts25, align 4
  store i32 %40, i32* %ghosts, align 4
  %41 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %41 to i64
  %42 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %42 to i64
  %43 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %43, i32 0, i32 25
  %44 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %44, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %45 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %45, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %46 = load i32, i32* %k32, align 4
  store i32 %46, i32* %dim_k, align 4
  %47 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %47 to i64
  %48 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %48 to i64
  %49 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %49, i32 0, i32 25
  %50 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %50, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %51 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %51, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %52 = load i32, i32* %j40, align 4
  store i32 %52, i32* %dim_j, align 4
  %53 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %53 to i64
  %54 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %54 to i64
  %55 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %55, i32 0, i32 25
  %56 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %56, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %57 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %57, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %58 = load i32, i32* %i48, align 4
  store i32 %58, i32* %dim_i, align 4
  %59 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %59 to i64
  %60 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %60 to i64
  %61 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %61 to i64
  %62 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %62, i32 0, i32 25
  %63 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %63, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %64 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %64, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %65 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %65, i64 %idxprom49
  %66 = load double*, double** %arrayidx56, align 8
  %67 = load i32, i32* %ghosts, align 4
  %68 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %68
  %69 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %69
  %mul59 = mul nsw i32 %67, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %66, i64 %idx.ext
  store double* %add.ptr, double** %grid_c, align 8
  %70 = load i32, i32* %3, align 4
  %idxprom60 = sext i32 %70 to i64
  %71 = load i32, i32* %1, align 4
  %idxprom61 = sext i32 %71 to i64
  %72 = load i32, i32* %box4, align 4
  %idxprom62 = sext i32 %72 to i64
  %73 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %73, i32 0, i32 25
  %74 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %74, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %75 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %75, i64 %idxprom61
  %grids67 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 10
  %76 = load double**, double*** %grids67, align 8
  %arrayidx68 = getelementptr inbounds double*, double** %76, i64 %idxprom60
  %77 = load double*, double** %arrayidx68, align 8
  %78 = load i32, i32* %ghosts, align 4
  %79 = load i32, i32* %pencil, align 4
  %add69 = add nsw i32 1, %79
  %80 = load i32, i32* %plane, align 4
  %add70 = add nsw i32 %add69, %80
  %mul71 = mul nsw i32 %78, %add70
  %idx.ext72 = sext i32 %mul71 to i64
  %add.ptr73 = getelementptr inbounds double, double* %77, i64 %idx.ext72
  store double* %add.ptr73, double** %grid_a, align 8
  %81 = load i32, i32* %4, align 4
  %idxprom74 = sext i32 %81 to i64
  %82 = load i32, i32* %1, align 4
  %idxprom75 = sext i32 %82 to i64
  %83 = load i32, i32* %box4, align 4
  %idxprom76 = sext i32 %83 to i64
  %84 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains77 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %84, i32 0, i32 25
  %85 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains77, align 8
  %arrayidx78 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %85, i64 %idxprom76
  %levels79 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx78, i32 0, i32 5
  %86 = load %struct.box_type*, %struct.box_type** %levels79, align 8
  %arrayidx80 = getelementptr inbounds %struct.box_type, %struct.box_type* %86, i64 %idxprom75
  %grids81 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx80, i32 0, i32 10
  %87 = load double**, double*** %grids81, align 8
  %arrayidx82 = getelementptr inbounds double*, double** %87, i64 %idxprom74
  %88 = load double*, double** %arrayidx82, align 8
  %89 = load i32, i32* %ghosts, align 4
  %90 = load i32, i32* %pencil, align 4
  %add83 = add nsw i32 1, %90
  %91 = load i32, i32* %plane, align 4
  %add84 = add nsw i32 %add83, %91
  %mul85 = mul nsw i32 %89, %add84
  %idx.ext86 = sext i32 %mul85 to i64
  %add.ptr87 = getelementptr inbounds double, double* %88, i64 %idx.ext86
  store double* %add.ptr87, double** %grid_b, align 8
  %92 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %92, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 10, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*, double**, double*, double**)* @.omp_outlined..30 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %6, double** %grid_a, double* %7, double** %grid_b)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %93 = load i32*, i32** %.global_tid..addr, align 8
  %94 = load i32, i32* %93, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %94)
  %95 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..30(i32* %95, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %6, double** %grid_a, double* %7, double** %grid_b)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %94)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %96 = load i32, i32* %.omp.iv, align 4
  %add88 = add nsw i32 %96, 1
  store i32 %add88, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %97 = load i32*, i32** %.global_tid..addr, align 8
  %98 = load i32, i32* %97, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %98)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..30(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid_c, double* dereferenceable(8) %scale_a, double** dereferenceable(8) %grid_a, double* dereferenceable(8) %scale_b, double** dereferenceable(8) %grid_b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid_c.addr = alloca double**, align 8
  %scale_a.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %scale_b.addr = alloca double*, align 8
  %grid_b.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  store double* %scale_a, double** %scale_a.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  store double* %scale_b, double** %scale_b.addr, align 8
  store double** %grid_b, double*** %grid_b.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid_c.addr, align 8
  %6 = load double*, double** %scale_a.addr, align 8
  %7 = load double**, double*** %grid_a.addr, align 8
  %8 = load double*, double** %scale_b.addr, align 8
  %9 = load double**, double*** %grid_b.addr, align 8
  %10 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %10, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %11 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %11, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %12 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %12
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %13 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %13
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %14 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %14, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %15 = load i32*, i32** %.global_tid..addr, align 8
  %16 = load i32, i32* %15, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %16, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %17 = load i64, i64* %.omp.ub, align 8
  %18 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %17, %18
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %20 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %19, %cond.true ], [ %20, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %21 = load i64, i64* %.omp.lb, align 8
  store i64 %21, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %22, %23
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %25, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %24, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %27, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %26, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %28, %29
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %30 = load i32, i32* %i, align 4
  %31 = load i32, i32* %j14, align 4
  %32 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %31, %32
  %add41 = add nsw i32 %30, %mul40
  %33 = load i32, i32* %k13, align 4
  %34 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %33, %34
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %35 = load double, double* %6, align 8
  %36 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %36 to i64
  %37 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %37, i64 %idxprom
  %38 = load double, double* %arrayidx, align 8
  %mul44 = fmul double %35, %38
  %39 = load double, double* %8, align 8
  %40 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %40 to i64
  %41 = load double*, double** %9, align 8
  %arrayidx46 = getelementptr inbounds double, double* %41, i64 %idxprom45
  %42 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %39, %42
  %add48 = fadd double %mul44, %mul47
  %43 = load i32, i32* %ijk, align 4
  %idxprom49 = sext i32 %43 to i64
  %44 = load double*, double** %5, align 8
  %arrayidx50 = getelementptr inbounds double, double* %44, i64 %idxprom49
  store double %add48, double* %arrayidx50, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %45 = load i32, i32* %i, align 4
  %inc = add nsw i32 %45, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %46 = load i64, i64* %.omp.iv, align 8
  %add51 = add nsw i64 %46, 1
  store i64 %add51, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %47 = load i32*, i32** %.global_tid..addr, align 8
  %48 = load i32, i32* %47, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %48)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @mul_grids(%struct.domain_type* %domain, i32 %level, i32 %id_c, double %scale, i32 %id_a, i32 %id_b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %scale.addr = alloca double, align 8
  %id_a.addr = alloca i32, align 4
  %id_b.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  store double %scale, double* %scale.addr, align 8
  store i32 %id_a, i32* %id_a.addr, align 4
  store i32 %id_b, i32* %id_b.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..31 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %scale.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..31(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %scale.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..31(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %id_b, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %scale) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %id_b.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %scale.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_c = alloca double*, align 8
  %grid_a = alloca double*, align 8
  %grid_b = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %id_b, i32** %id_b.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %scale, double** %scale.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_c.addr, align 8
  %3 = load i32*, i32** %id_a.addr, align 8
  %4 = load i32*, i32** %id_b.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load double*, double** %scale.addr, align 8
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %9 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 19
  %10 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %11 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %11, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %14 = load i32, i32* %.omp.ub, align 4
  %15 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %14, %15
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %16, %cond.true ], [ %17, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %18 = load i32, i32* %.omp.lb, align 4
  store i32 %18, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i32, i32* %.omp.iv, align 4
  %20 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %19, %20
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %21, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %22 = load i32, i32* %1, align 4
  %idxprom = sext i32 %22 to i64
  %23 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %23 to i64
  %24 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %24, i32 0, i32 25
  %25 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %25, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %26 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %26, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %27 = load i32, i32* %pencil11, align 8
  store i32 %27, i32* %pencil, align 4
  %28 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %28 to i64
  %29 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %29 to i64
  %30 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %30, i32 0, i32 25
  %31 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %31, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %32 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %32, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %33 = load i32, i32* %plane18, align 4
  store i32 %33, i32* %plane, align 4
  %34 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %34 to i64
  %35 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %35 to i64
  %36 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %36, i32 0, i32 25
  %37 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %37, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %38 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %38, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %39 = load i32, i32* %ghosts25, align 4
  store i32 %39, i32* %ghosts, align 4
  %40 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %40 to i64
  %41 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %41 to i64
  %42 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %42, i32 0, i32 25
  %43 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %43, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %44 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %44, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %45 = load i32, i32* %k32, align 4
  store i32 %45, i32* %dim_k, align 4
  %46 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %46 to i64
  %47 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %47 to i64
  %48 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %48, i32 0, i32 25
  %49 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %49, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %50 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %50, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %51 = load i32, i32* %j40, align 4
  store i32 %51, i32* %dim_j, align 4
  %52 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %52 to i64
  %53 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %53 to i64
  %54 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %54, i32 0, i32 25
  %55 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %55, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %56 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %56, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %57 = load i32, i32* %i48, align 4
  store i32 %57, i32* %dim_i, align 4
  %58 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %58 to i64
  %59 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %59 to i64
  %60 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %60 to i64
  %61 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %61, i32 0, i32 25
  %62 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %62, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %63 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %63, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %64 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %64, i64 %idxprom49
  %65 = load double*, double** %arrayidx56, align 8
  %66 = load i32, i32* %ghosts, align 4
  %67 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %67
  %68 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %68
  %mul59 = mul nsw i32 %66, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %65, i64 %idx.ext
  store double* %add.ptr, double** %grid_c, align 8
  %69 = load i32, i32* %3, align 4
  %idxprom60 = sext i32 %69 to i64
  %70 = load i32, i32* %1, align 4
  %idxprom61 = sext i32 %70 to i64
  %71 = load i32, i32* %box4, align 4
  %idxprom62 = sext i32 %71 to i64
  %72 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %72, i32 0, i32 25
  %73 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %73, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %74 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %74, i64 %idxprom61
  %grids67 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 10
  %75 = load double**, double*** %grids67, align 8
  %arrayidx68 = getelementptr inbounds double*, double** %75, i64 %idxprom60
  %76 = load double*, double** %arrayidx68, align 8
  %77 = load i32, i32* %ghosts, align 4
  %78 = load i32, i32* %pencil, align 4
  %add69 = add nsw i32 1, %78
  %79 = load i32, i32* %plane, align 4
  %add70 = add nsw i32 %add69, %79
  %mul71 = mul nsw i32 %77, %add70
  %idx.ext72 = sext i32 %mul71 to i64
  %add.ptr73 = getelementptr inbounds double, double* %76, i64 %idx.ext72
  store double* %add.ptr73, double** %grid_a, align 8
  %80 = load i32, i32* %4, align 4
  %idxprom74 = sext i32 %80 to i64
  %81 = load i32, i32* %1, align 4
  %idxprom75 = sext i32 %81 to i64
  %82 = load i32, i32* %box4, align 4
  %idxprom76 = sext i32 %82 to i64
  %83 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains77 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %83, i32 0, i32 25
  %84 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains77, align 8
  %arrayidx78 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %84, i64 %idxprom76
  %levels79 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx78, i32 0, i32 5
  %85 = load %struct.box_type*, %struct.box_type** %levels79, align 8
  %arrayidx80 = getelementptr inbounds %struct.box_type, %struct.box_type* %85, i64 %idxprom75
  %grids81 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx80, i32 0, i32 10
  %86 = load double**, double*** %grids81, align 8
  %arrayidx82 = getelementptr inbounds double*, double** %86, i64 %idxprom74
  %87 = load double*, double** %arrayidx82, align 8
  %88 = load i32, i32* %ghosts, align 4
  %89 = load i32, i32* %pencil, align 4
  %add83 = add nsw i32 1, %89
  %90 = load i32, i32* %plane, align 4
  %add84 = add nsw i32 %add83, %90
  %mul85 = mul nsw i32 %88, %add84
  %idx.ext86 = sext i32 %mul85 to i64
  %add.ptr87 = getelementptr inbounds double, double* %87, i64 %idx.ext86
  store double* %add.ptr87, double** %grid_b, align 8
  %91 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %91, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 9, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*, double**, double**)* @.omp_outlined..32 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %6, double** %grid_a, double** %grid_b)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %92 = load i32*, i32** %.global_tid..addr, align 8
  %93 = load i32, i32* %92, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %93)
  %94 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..32(i32* %94, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %6, double** %grid_a, double** %grid_b)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %93)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %95 = load i32, i32* %.omp.iv, align 4
  %add88 = add nsw i32 %95, 1
  store i32 %add88, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %96 = load i32*, i32** %.global_tid..addr, align 8
  %97 = load i32, i32* %96, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %97)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..32(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid_c, double* dereferenceable(8) %scale, double** dereferenceable(8) %grid_a, double** dereferenceable(8) %grid_b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid_c.addr = alloca double**, align 8
  %scale.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %grid_b.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  store double* %scale, double** %scale.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  store double** %grid_b, double*** %grid_b.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid_c.addr, align 8
  %6 = load double*, double** %scale.addr, align 8
  %7 = load double**, double*** %grid_a.addr, align 8
  %8 = load double**, double*** %grid_b.addr, align 8
  %9 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %9, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %10 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %10, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %11 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %11
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %12 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %12
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %13 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %13, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %14 = load i32*, i32** %.global_tid..addr, align 8
  %15 = load i32, i32* %14, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %15, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %16 = load i64, i64* %.omp.ub, align 8
  %17 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %16, %17
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %19 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %18, %cond.true ], [ %19, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %20 = load i64, i64* %.omp.lb, align 8
  store i64 %20, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %21, %22
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %24, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %23, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %25 = load i64, i64* %.omp.iv, align 8
  %26 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %26, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %25, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %27, %28
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %29 = load i32, i32* %i, align 4
  %30 = load i32, i32* %j14, align 4
  %31 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %30, %31
  %add41 = add nsw i32 %29, %mul40
  %32 = load i32, i32* %k13, align 4
  %33 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %32, %33
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %34 = load double, double* %6, align 8
  %35 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %35 to i64
  %36 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %36, i64 %idxprom
  %37 = load double, double* %arrayidx, align 8
  %mul44 = fmul double %34, %37
  %38 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %38 to i64
  %39 = load double*, double** %8, align 8
  %arrayidx46 = getelementptr inbounds double, double* %39, i64 %idxprom45
  %40 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %mul44, %40
  %41 = load i32, i32* %ijk, align 4
  %idxprom48 = sext i32 %41 to i64
  %42 = load double*, double** %5, align 8
  %arrayidx49 = getelementptr inbounds double, double* %42, i64 %idxprom48
  store double %mul47, double* %arrayidx49, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %43 = load i32, i32* %i, align 4
  %inc = add nsw i32 %43, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %44 = load i64, i64* %.omp.iv, align 8
  %add50 = add nsw i64 %44, 1
  store i64 %add50, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %45 = load i32*, i32** %.global_tid..addr, align 8
  %46 = load i32, i32* %45, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %46)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @scale_grid(%struct.domain_type* %domain, i32 %level, i32 %id_c, double %scale_a, i32 %id_a) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %scale_a.addr = alloca double, align 8
  %id_a.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  store double %scale_a, double* %scale_a.addr, align 8
  store i32 %id_a, i32* %id_a.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..33 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %scale_a.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..33(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %scale_a.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..33(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %scale_a) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %scale_a.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_c = alloca double*, align 8
  %grid_a = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %scale_a, double** %scale_a.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_c.addr, align 8
  %3 = load i32*, i32** %id_a.addr, align 8
  %4 = load i32*, i32** %omp_within_a_box.addr, align 8
  %5 = load double*, double** %scale_a.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %13, %14
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %18, %19
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %26 = load i32, i32* %pencil11, align 8
  store i32 %26, i32* %pencil, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %32 = load i32, i32* %plane18, align 4
  store i32 %32, i32* %plane, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %38 = load i32, i32* %ghosts25, align 4
  store i32 %38, i32* %ghosts, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %44 = load i32, i32* %k32, align 4
  store i32 %44, i32* %dim_k, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %50 = load i32, i32* %j40, align 4
  store i32 %50, i32* %dim_j, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %56 = load i32, i32* %i48, align 4
  store i32 %56, i32* %dim_i, align 4
  %57 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %57 to i64
  %58 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %63 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %63, i64 %idxprom49
  %64 = load double*, double** %arrayidx56, align 8
  %65 = load i32, i32* %ghosts, align 4
  %66 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %66
  %67 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %67
  %mul59 = mul nsw i32 %65, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %64, i64 %idx.ext
  store double* %add.ptr, double** %grid_c, align 8
  %68 = load i32, i32* %3, align 4
  %idxprom60 = sext i32 %68 to i64
  %69 = load i32, i32* %1, align 4
  %idxprom61 = sext i32 %69 to i64
  %70 = load i32, i32* %box4, align 4
  %idxprom62 = sext i32 %70 to i64
  %71 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %71, i32 0, i32 25
  %72 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %72, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %73 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %73, i64 %idxprom61
  %grids67 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 10
  %74 = load double**, double*** %grids67, align 8
  %arrayidx68 = getelementptr inbounds double*, double** %74, i64 %idxprom60
  %75 = load double*, double** %arrayidx68, align 8
  %76 = load i32, i32* %ghosts, align 4
  %77 = load i32, i32* %pencil, align 4
  %add69 = add nsw i32 1, %77
  %78 = load i32, i32* %plane, align 4
  %add70 = add nsw i32 %add69, %78
  %mul71 = mul nsw i32 %76, %add70
  %idx.ext72 = sext i32 %mul71 to i64
  %add.ptr73 = getelementptr inbounds double, double* %75, i64 %idx.ext72
  store double* %add.ptr73, double** %grid_a, align 8
  %79 = load i32, i32* %4, align 4
  %tobool = icmp ne i32 %79, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*, double**)* @.omp_outlined..34 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %5, double** %grid_a)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %80 = load i32*, i32** %.global_tid..addr, align 8
  %81 = load i32, i32* %80, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %81)
  %82 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..34(i32* %82, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double* %5, double** %grid_a)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %81)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %83 = load i32, i32* %.omp.iv, align 4
  %add74 = add nsw i32 %83, 1
  store i32 %add74, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %84 = load i32*, i32** %.global_tid..addr, align 8
  %85 = load i32, i32* %84, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %85)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..34(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid_c, double* dereferenceable(8) %scale_a, double** dereferenceable(8) %grid_a) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid_c.addr = alloca double**, align 8
  %scale_a.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %i = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  store double* %scale_a, double** %scale_a.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid_c.addr, align 8
  %6 = load double*, double** %scale_a.addr, align 8
  %7 = load double**, double*** %grid_a.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %9, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %11
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %15, %16
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %20, %21
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %23, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %22, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k13, align 4
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %25, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %24, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j14, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %26, %27
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %j14, align 4
  %30 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %29, %30
  %add41 = add nsw i32 %28, %mul40
  %31 = load i32, i32* %k13, align 4
  %32 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %31, %32
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %33 = load double, double* %6, align 8
  %34 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %34 to i64
  %35 = load double*, double** %7, align 8
  %arrayidx = getelementptr inbounds double, double* %35, i64 %idxprom
  %36 = load double, double* %arrayidx, align 8
  %mul44 = fmul double %33, %36
  %37 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %37 to i64
  %38 = load double*, double** %5, align 8
  %arrayidx46 = getelementptr inbounds double, double* %38, i64 %idxprom45
  store double %mul44, double* %arrayidx46, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %39 = load i32, i32* %i, align 4
  %inc = add nsw i32 %39, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %40 = load i64, i64* %.omp.iv, align 8
  %add47 = add nsw i64 %40, 1
  store i64 %add47, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %41 = load i32*, i32** %.global_tid..addr, align 8
  %42 = load i32, i32* %41, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %42)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define double @dot(%struct.domain_type* %domain, i32 %level, i32 %id_a, i32 %id_b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_a.addr = alloca i32, align 4
  %id_b.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %a_dot_b_domain = alloca double, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_a, i32* %id_a.addr, align 4
  store i32 %id_b, i32* %id_b.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  store double 0.000000e+00, double* %a_dot_b_domain, align 8
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..35 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %a_dot_b_domain)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..35(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_a.addr, i32* %id_b.addr, i32* %omp_within_a_box, double* %a_dot_b_domain)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  %18 = load double, double* %a_dot_b_domain, align 8
  ret double %18
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..35(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %id_b, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %a_dot_b_domain) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %id_b.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %a_dot_b_domain.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %a_dot_b_domain5 = alloca double, align 8
  %box6 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_a = alloca double*, align 8
  %grid_b = alloca double*, align 8
  %a_dot_b_box = alloca double, align 8
  %.zero.addr = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %id_b, i32** %id_b.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %a_dot_b_domain, double** %a_dot_b_domain.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_a.addr, align 8
  %3 = load i32*, i32** %id_b.addr, align 8
  %4 = load i32*, i32** %omp_within_a_box.addr, align 8
  %5 = load double*, double** %a_dot_b_domain.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store double 0.000000e+00, double* %a_dot_b_domain5, align 8
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp7 = icmp sgt i32 %13, %14
  br i1 %cmp7, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp8 = icmp sle i32 %18, %19
  br i1 %cmp8, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add9 = add nsw i32 0, %mul
  store i32 %add9, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom10 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom10
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx11 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %pencil12 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx11, i32 0, i32 5
  %26 = load i32, i32* %pencil12, align 8
  store i32 %26, i32* %pencil, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom13 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom14 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains15 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains15, align 8
  %arrayidx16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom14
  %levels17 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx16, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels17, align 8
  %arrayidx18 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom13
  %plane19 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx18, i32 0, i32 6
  %32 = load i32, i32* %plane19, align 4
  store i32 %32, i32* %plane, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom20 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom21 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains22 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains22, align 8
  %arrayidx23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom21
  %levels24 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx23, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels24, align 8
  %arrayidx25 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom20
  %ghosts26 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx25, i32 0, i32 4
  %38 = load i32, i32* %ghosts26, align 4
  store i32 %38, i32* %ghosts, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom27 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom28 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains29 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains29, align 8
  %arrayidx30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom28
  %levels31 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx30, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels31, align 8
  %arrayidx32 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom27
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx32, i32 0, i32 2
  %k33 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %44 = load i32, i32* %k33, align 4
  store i32 %44, i32* %dim_k, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom34 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom35 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains36 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains36, align 8
  %arrayidx37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom35
  %levels38 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx37, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels38, align 8
  %arrayidx39 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom34
  %dim40 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx39, i32 0, i32 2
  %j41 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim40, i32 0, i32 1
  %50 = load i32, i32* %j41, align 4
  store i32 %50, i32* %dim_j, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom42 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom43 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains44 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains44, align 8
  %arrayidx45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom43
  %levels46 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx45, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels46, align 8
  %arrayidx47 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom42
  %dim48 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx47, i32 0, i32 2
  %i49 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim48, i32 0, i32 0
  %56 = load i32, i32* %i49, align 4
  store i32 %56, i32* %dim_i, align 4
  %57 = load i32, i32* %2, align 4
  %idxprom50 = sext i32 %57 to i64
  %58 = load i32, i32* %1, align 4
  %idxprom51 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom52 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains53 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains53, align 8
  %arrayidx54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom52
  %levels55 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx54, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels55, align 8
  %arrayidx56 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom51
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx56, i32 0, i32 10
  %63 = load double**, double*** %grids, align 8
  %arrayidx57 = getelementptr inbounds double*, double** %63, i64 %idxprom50
  %64 = load double*, double** %arrayidx57, align 8
  %65 = load i32, i32* %ghosts, align 4
  %66 = load i32, i32* %pencil, align 4
  %add58 = add nsw i32 1, %66
  %67 = load i32, i32* %plane, align 4
  %add59 = add nsw i32 %add58, %67
  %mul60 = mul nsw i32 %65, %add59
  %idx.ext = sext i32 %mul60 to i64
  %add.ptr = getelementptr inbounds double, double* %64, i64 %idx.ext
  store double* %add.ptr, double** %grid_a, align 8
  %68 = load i32, i32* %3, align 4
  %idxprom61 = sext i32 %68 to i64
  %69 = load i32, i32* %1, align 4
  %idxprom62 = sext i32 %69 to i64
  %70 = load i32, i32* %box4, align 4
  %idxprom63 = sext i32 %70 to i64
  %71 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains64 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %71, i32 0, i32 25
  %72 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains64, align 8
  %arrayidx65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %72, i64 %idxprom63
  %levels66 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx65, i32 0, i32 5
  %73 = load %struct.box_type*, %struct.box_type** %levels66, align 8
  %arrayidx67 = getelementptr inbounds %struct.box_type, %struct.box_type* %73, i64 %idxprom62
  %grids68 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx67, i32 0, i32 10
  %74 = load double**, double*** %grids68, align 8
  %arrayidx69 = getelementptr inbounds double*, double** %74, i64 %idxprom61
  %75 = load double*, double** %arrayidx69, align 8
  %76 = load i32, i32* %ghosts, align 4
  %77 = load i32, i32* %pencil, align 4
  %add70 = add nsw i32 1, %77
  %78 = load i32, i32* %plane, align 4
  %add71 = add nsw i32 %add70, %78
  %mul72 = mul nsw i32 %76, %add71
  %idx.ext73 = sext i32 %mul72 to i64
  %add.ptr74 = getelementptr inbounds double, double* %75, i64 %idx.ext73
  store double* %add.ptr74, double** %grid_b, align 8
  store double 0.000000e+00, double* %a_dot_b_box, align 8
  %79 = load i32, i32* %4, align 4
  %tobool = icmp ne i32 %79, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double**, double**)* @.omp_outlined..36 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %a_dot_b_box, double** %grid_a, double** %grid_b)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %80 = load i32*, i32** %.global_tid..addr, align 8
  %81 = load i32, i32* %80, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %81)
  %82 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..36(i32* %82, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %a_dot_b_box, double** %grid_a, double** %grid_b)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %81)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %83 = load double, double* %a_dot_b_box, align 8
  %84 = load double, double* %a_dot_b_domain5, align 8
  %add75 = fadd double %84, %83
  store double %add75, double* %a_dot_b_domain5, align 8
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %85 = load i32, i32* %.omp.iv, align 4
  %add76 = add nsw i32 %85, 1
  store i32 %add76, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %86 = load i32*, i32** %.global_tid..addr, align 8
  %87 = load i32, i32* %86, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %87)
  %88 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %89 = bitcast double* %a_dot_b_domain5 to i8*
  store i8* %89, i8** %88, align 8
  %90 = load i32*, i32** %.global_tid..addr, align 8
  %91 = load i32, i32* %90, align 4
  %92 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %93 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %91, i32 1, i64 8, i8* %92, void (i8*, i8*)* @.omp.reduction.reduction_func.38, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %93, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %94 = load double, double* %5, align 8
  %95 = load double, double* %a_dot_b_domain5, align 8
  %add77 = fadd double %94, %95
  store double %add77, double* %5, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %91, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %96 = load double, double* %a_dot_b_domain5, align 8
  %97 = bitcast double* %5 to i64*
  %atomic-load = load atomic i64, i64* %97 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %atomic_cont, %.omp.reduction.case2
  %98 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %106, %atomic_cont ]
  %99 = bitcast double* %atomic-temp to i64*
  %100 = bitcast i64 %98 to double
  store double %100, double* %tmp, align 8
  %101 = load double, double* %tmp, align 8
  %102 = load double, double* %a_dot_b_domain5, align 8
  %add78 = fadd double %101, %102
  store double %add78, double* %atomic-temp, align 8
  %103 = load i64, i64* %99, align 8
  %104 = bitcast double* %5 to i64*
  %105 = cmpxchg i64* %104, i64 %98, i64 %103 monotonic monotonic
  %106 = extractvalue { i64, i1 } %105, 0
  %107 = extractvalue { i64, i1 } %105, 1
  br i1 %107, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %atomic_cont
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %.omp.reduction.case1, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..36(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %a_dot_b_box, double** dereferenceable(8) %grid_a, double** dereferenceable(8) %grid_b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %a_dot_b_box.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %grid_b.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %i = alloca i32, align 4
  %j13 = alloca i32, align 4
  %k14 = alloca i32, align 4
  %a_dot_b_box15 = alloca double, align 8
  %k16 = alloca i32, align 4
  %j17 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %a_dot_b_box, double** %a_dot_b_box.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  store double** %grid_b, double*** %grid_b.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %a_dot_b_box.addr, align 8
  %6 = load double**, double*** %grid_a.addr, align 8
  %7 = load double**, double*** %grid_b.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %9, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %11
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  store double 0.000000e+00, double* %a_dot_b_box15, align 8
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp18 = icmp sgt i64 %15, %16
  br i1 %cmp18, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp20 = icmp sle i64 %20, %21
  br i1 %cmp20, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i32, i32* %1, align 4
  %sub22 = sub nsw i32 %23, 0
  %sub23 = sub nsw i32 %sub22, 1
  %add24 = add nsw i32 %sub23, 1
  %div25 = sdiv i32 %add24, 1
  %conv26 = sext i32 %div25 to i64
  %div27 = sdiv i64 %22, %conv26
  %mul28 = mul nsw i64 %div27, 1
  %add29 = add nsw i64 0, %mul28
  %conv30 = trunc i64 %add29 to i32
  store i32 %conv30, i32* %k14, align 4
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub31 = sub nsw i32 %25, 0
  %sub32 = sub nsw i32 %sub31, 1
  %add33 = add nsw i32 %sub32, 1
  %div34 = sdiv i32 %add33, 1
  %conv35 = sext i32 %div34 to i64
  %rem = srem i64 %24, %conv35
  %mul36 = mul nsw i64 %rem, 1
  %add37 = add nsw i64 0, %mul36
  %conv38 = trunc i64 %add37 to i32
  store i32 %conv38, i32* %j13, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %2, align 4
  %cmp39 = icmp slt i32 %26, %27
  br i1 %cmp39, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %j13, align 4
  %30 = load i32, i32* %3, align 4
  %mul41 = mul nsw i32 %29, %30
  %add42 = add nsw i32 %28, %mul41
  %31 = load i32, i32* %k14, align 4
  %32 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %31, %32
  %add44 = add nsw i32 %add42, %mul43
  store i32 %add44, i32* %ijk, align 4
  %33 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %33 to i64
  %34 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %34, i64 %idxprom
  %35 = load double, double* %arrayidx, align 8
  %36 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %36 to i64
  %37 = load double*, double** %7, align 8
  %arrayidx46 = getelementptr inbounds double, double* %37, i64 %idxprom45
  %38 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %35, %38
  %39 = load double, double* %a_dot_b_box15, align 8
  %add48 = fadd double %39, %mul47
  store double %add48, double* %a_dot_b_box15, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %40 = load i32, i32* %i, align 4
  %inc = add nsw i32 %40, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %41 = load i64, i64* %.omp.iv, align 8
  %add49 = add nsw i64 %41, 1
  store i64 %add49, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %42 = load i32*, i32** %.global_tid..addr, align 8
  %43 = load i32, i32* %42, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %43)
  %44 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %45 = bitcast double* %a_dot_b_box15 to i8*
  store i8* %45, i8** %44, align 8
  %46 = load i32*, i32** %.global_tid..addr, align 8
  %47 = load i32, i32* %46, align 4
  %48 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %49 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %47, i32 1, i64 8, i8* %48, void (i8*, i8*)* @.omp.reduction.reduction_func.37, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %49, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %50 = load double, double* %5, align 8
  %51 = load double, double* %a_dot_b_box15, align 8
  %add50 = fadd double %50, %51
  store double %add50, double* %5, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %47, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %52 = load double, double* %a_dot_b_box15, align 8
  %53 = bitcast double* %5 to i64*
  %atomic-load = load atomic i64, i64* %53 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %atomic_cont, %.omp.reduction.case2
  %54 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %62, %atomic_cont ]
  %55 = bitcast double* %atomic-temp to i64*
  %56 = bitcast i64 %54 to double
  store double %56, double* %tmp, align 8
  %57 = load double, double* %tmp, align 8
  %58 = load double, double* %a_dot_b_box15, align 8
  %add51 = fadd double %57, %58
  store double %add51, double* %atomic-temp, align 8
  %59 = load i64, i64* %55, align 8
  %60 = bitcast double* %5 to i64*
  %61 = cmpxchg i64* %60, i64 %54, i64 %59 monotonic monotonic
  %62 = extractvalue { i64, i1 } %61, 0
  %63 = extractvalue { i64, i1 } %61, 1
  br i1 %63, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %atomic_cont
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %.omp.reduction.case1, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.37(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %add = fadd double %12, %13
  store double %add, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.38(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %add = fadd double %12, %13
  store double %add, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define double @norm(%struct.domain_type* %domain, i32 %level, i32 %grid_id) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %grid_id.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %max_norm = alloca double, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %grid_id, i32* %grid_id.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  store double 0.000000e+00, double* %max_norm, align 8
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 5, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, double*)* @.omp_outlined..39 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box, double* %max_norm)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..39(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %grid_id.addr, i32* %omp_within_a_box, double* %max_norm)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  %18 = load double, double* %max_norm, align 8
  ret double %18
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..39(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %grid_id, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %max_norm) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %grid_id.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %max_norm.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %max_norm5 = alloca double, align 8
  %box6 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid = alloca double*, align 8
  %box_norm = alloca double, align 8
  %.zero.addr = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %grid_id, i32** %grid_id.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %max_norm, double** %max_norm.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %grid_id.addr, align 8
  %3 = load i32*, i32** %omp_within_a_box.addr, align 8
  %4 = load double*, double** %max_norm.addr, align 8
  %5 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 19
  %6 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %6, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %8
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %9 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %9, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store double 0xFFEFFFFFFFFFFFFF, double* %max_norm5, align 8
  %10 = load i32*, i32** %.global_tid..addr, align 8
  %11 = load i32, i32* %10, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %11, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %12 = load i32, i32* %.omp.ub, align 4
  %13 = load i32, i32* %.omp.last.iteration, align 4
  %cmp7 = icmp sgt i32 %12, %13
  br i1 %cmp7, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %14 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %14, %cond.true ], [ %15, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %16 = load i32, i32* %.omp.lb, align 4
  store i32 %16, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %17 = load i32, i32* %.omp.iv, align 4
  %18 = load i32, i32* %.omp.ub, align 4
  %cmp8 = icmp sle i32 %17, %18
  br i1 %cmp8, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %19 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %19, 1
  %add9 = add nsw i32 0, %mul
  store i32 %add9, i32* %box4, align 4
  %20 = load i32, i32* %1, align 4
  %idxprom = sext i32 %20 to i64
  %21 = load i32, i32* %box4, align 4
  %idxprom10 = sext i32 %21 to i64
  %22 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %22, i32 0, i32 25
  %23 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %23, i64 %idxprom10
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %24 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx11 = getelementptr inbounds %struct.box_type, %struct.box_type* %24, i64 %idxprom
  %pencil12 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx11, i32 0, i32 5
  %25 = load i32, i32* %pencil12, align 8
  store i32 %25, i32* %pencil, align 4
  %26 = load i32, i32* %1, align 4
  %idxprom13 = sext i32 %26 to i64
  %27 = load i32, i32* %box4, align 4
  %idxprom14 = sext i32 %27 to i64
  %28 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains15 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %28, i32 0, i32 25
  %29 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains15, align 8
  %arrayidx16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %29, i64 %idxprom14
  %levels17 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx16, i32 0, i32 5
  %30 = load %struct.box_type*, %struct.box_type** %levels17, align 8
  %arrayidx18 = getelementptr inbounds %struct.box_type, %struct.box_type* %30, i64 %idxprom13
  %plane19 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx18, i32 0, i32 6
  %31 = load i32, i32* %plane19, align 4
  store i32 %31, i32* %plane, align 4
  %32 = load i32, i32* %1, align 4
  %idxprom20 = sext i32 %32 to i64
  %33 = load i32, i32* %box4, align 4
  %idxprom21 = sext i32 %33 to i64
  %34 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains22 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %34, i32 0, i32 25
  %35 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains22, align 8
  %arrayidx23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %35, i64 %idxprom21
  %levels24 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx23, i32 0, i32 5
  %36 = load %struct.box_type*, %struct.box_type** %levels24, align 8
  %arrayidx25 = getelementptr inbounds %struct.box_type, %struct.box_type* %36, i64 %idxprom20
  %ghosts26 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx25, i32 0, i32 4
  %37 = load i32, i32* %ghosts26, align 4
  store i32 %37, i32* %ghosts, align 4
  %38 = load i32, i32* %1, align 4
  %idxprom27 = sext i32 %38 to i64
  %39 = load i32, i32* %box4, align 4
  %idxprom28 = sext i32 %39 to i64
  %40 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains29 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %40, i32 0, i32 25
  %41 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains29, align 8
  %arrayidx30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %41, i64 %idxprom28
  %levels31 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx30, i32 0, i32 5
  %42 = load %struct.box_type*, %struct.box_type** %levels31, align 8
  %arrayidx32 = getelementptr inbounds %struct.box_type, %struct.box_type* %42, i64 %idxprom27
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx32, i32 0, i32 2
  %k33 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %43 = load i32, i32* %k33, align 4
  store i32 %43, i32* %dim_k, align 4
  %44 = load i32, i32* %1, align 4
  %idxprom34 = sext i32 %44 to i64
  %45 = load i32, i32* %box4, align 4
  %idxprom35 = sext i32 %45 to i64
  %46 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains36 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %46, i32 0, i32 25
  %47 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains36, align 8
  %arrayidx37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %47, i64 %idxprom35
  %levels38 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx37, i32 0, i32 5
  %48 = load %struct.box_type*, %struct.box_type** %levels38, align 8
  %arrayidx39 = getelementptr inbounds %struct.box_type, %struct.box_type* %48, i64 %idxprom34
  %dim40 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx39, i32 0, i32 2
  %j41 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim40, i32 0, i32 1
  %49 = load i32, i32* %j41, align 4
  store i32 %49, i32* %dim_j, align 4
  %50 = load i32, i32* %1, align 4
  %idxprom42 = sext i32 %50 to i64
  %51 = load i32, i32* %box4, align 4
  %idxprom43 = sext i32 %51 to i64
  %52 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains44 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %52, i32 0, i32 25
  %53 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains44, align 8
  %arrayidx45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %53, i64 %idxprom43
  %levels46 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx45, i32 0, i32 5
  %54 = load %struct.box_type*, %struct.box_type** %levels46, align 8
  %arrayidx47 = getelementptr inbounds %struct.box_type, %struct.box_type* %54, i64 %idxprom42
  %dim48 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx47, i32 0, i32 2
  %i49 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim48, i32 0, i32 0
  %55 = load i32, i32* %i49, align 4
  store i32 %55, i32* %dim_i, align 4
  %56 = load i32, i32* %2, align 4
  %idxprom50 = sext i32 %56 to i64
  %57 = load i32, i32* %1, align 4
  %idxprom51 = sext i32 %57 to i64
  %58 = load i32, i32* %box4, align 4
  %idxprom52 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains53 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 25
  %60 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains53, align 8
  %arrayidx54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %60, i64 %idxprom52
  %levels55 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx54, i32 0, i32 5
  %61 = load %struct.box_type*, %struct.box_type** %levels55, align 8
  %arrayidx56 = getelementptr inbounds %struct.box_type, %struct.box_type* %61, i64 %idxprom51
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx56, i32 0, i32 10
  %62 = load double**, double*** %grids, align 8
  %arrayidx57 = getelementptr inbounds double*, double** %62, i64 %idxprom50
  %63 = load double*, double** %arrayidx57, align 8
  %64 = load i32, i32* %ghosts, align 4
  %65 = load i32, i32* %pencil, align 4
  %add58 = add nsw i32 1, %65
  %66 = load i32, i32* %plane, align 4
  %add59 = add nsw i32 %add58, %66
  %mul60 = mul nsw i32 %64, %add59
  %idx.ext = sext i32 %mul60 to i64
  %add.ptr = getelementptr inbounds double, double* %63, i64 %idx.ext
  store double* %add.ptr, double** %grid, align 8
  store double 0.000000e+00, double* %box_norm, align 8
  %67 = load i32, i32* %3, align 4
  %tobool = icmp ne i32 %67, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double*)* @.omp_outlined..40 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid, double* %box_norm)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %68 = load i32*, i32** %.global_tid..addr, align 8
  %69 = load i32, i32* %68, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %69)
  %70 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..40(i32* %70, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid, double* %box_norm)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %69)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %71 = load double, double* %box_norm, align 8
  %72 = load double, double* %max_norm5, align 8
  %cmp61 = fcmp ogt double %71, %72
  br i1 %cmp61, label %if.then, label %if.end

if.then:                                          ; preds = %omp_if.end
  %73 = load double, double* %box_norm, align 8
  store double %73, double* %max_norm5, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %omp_if.end
  br label %omp.body.continue

omp.body.continue:                                ; preds = %if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %74 = load i32, i32* %.omp.iv, align 4
  %add62 = add nsw i32 %74, 1
  store i32 %add62, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %75 = load i32*, i32** %.global_tid..addr, align 8
  %76 = load i32, i32* %75, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %76)
  %77 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %78 = bitcast double* %max_norm5 to i8*
  store i8* %78, i8** %77, align 8
  %79 = load i32*, i32** %.global_tid..addr, align 8
  %80 = load i32, i32* %79, align 4
  %81 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %82 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %80, i32 1, i64 8, i8* %81, void (i8*, i8*)* @.omp.reduction.reduction_func.42, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %82, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %83 = load double, double* %4, align 8
  %84 = load double, double* %max_norm5, align 8
  %cmp63 = fcmp ogt double %83, %84
  br i1 %cmp63, label %cond.true64, label %cond.false65

cond.true64:                                      ; preds = %.omp.reduction.case1
  %85 = load double, double* %4, align 8
  br label %cond.end66

cond.false65:                                     ; preds = %.omp.reduction.case1
  %86 = load double, double* %max_norm5, align 8
  br label %cond.end66

cond.end66:                                       ; preds = %cond.false65, %cond.true64
  %cond67 = phi double [ %85, %cond.true64 ], [ %86, %cond.false65 ]
  store double %cond67, double* %4, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %80, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %87 = load double, double* %max_norm5, align 8
  %88 = bitcast double* %4 to i64*
  %atomic-load = load atomic i64, i64* %88 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %cond.end71, %.omp.reduction.case2
  %89 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %99, %cond.end71 ]
  %90 = bitcast double* %atomic-temp to i64*
  %91 = bitcast i64 %89 to double
  store double %91, double* %tmp, align 8
  %92 = load double, double* %tmp, align 8
  %93 = load double, double* %max_norm5, align 8
  %cmp68 = fcmp ogt double %92, %93
  br i1 %cmp68, label %cond.true69, label %cond.false70

cond.true69:                                      ; preds = %atomic_cont
  %94 = load double, double* %tmp, align 8
  br label %cond.end71

cond.false70:                                     ; preds = %atomic_cont
  %95 = load double, double* %max_norm5, align 8
  br label %cond.end71

cond.end71:                                       ; preds = %cond.false70, %cond.true69
  %cond72 = phi double [ %94, %cond.true69 ], [ %95, %cond.false70 ]
  store double %cond72, double* %atomic-temp, align 8
  %96 = load i64, i64* %90, align 8
  %97 = bitcast double* %4 to i64*
  %98 = cmpxchg i64* %97, i64 %89, i64 %96 monotonic monotonic
  %99 = extractvalue { i64, i1 } %98, 0
  %100 = extractvalue { i64, i1 } %98, 1
  br i1 %100, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %cond.end71
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %cond.end66, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..40(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid, double* dereferenceable(8) %box_norm) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid.addr = alloca double**, align 8
  %box_norm.addr = alloca double*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %i = alloca i32, align 4
  %j13 = alloca i32, align 4
  %k14 = alloca i32, align 4
  %box_norm15 = alloca double, align 8
  %k16 = alloca i32, align 4
  %j17 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %fabs_grid_ijk = alloca double, align 8
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid, double*** %grid.addr, align 8
  store double* %box_norm, double** %box_norm.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid.addr, align 8
  %6 = load double*, double** %box_norm.addr, align 8
  %7 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %8 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %8, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %9 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %10 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %10
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %11 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %11, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  store double 0xFFEFFFFFFFFFFFFF, double* %box_norm15, align 8
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %14 = load i64, i64* %.omp.ub, align 8
  %15 = load i64, i64* %.omp.last.iteration, align 8
  %cmp18 = icmp sgt i64 %14, %15
  br i1 %cmp18, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %16, %cond.true ], [ %17, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %18 = load i64, i64* %.omp.lb, align 8
  store i64 %18, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i64, i64* %.omp.iv, align 8
  %20 = load i64, i64* %.omp.ub, align 8
  %cmp20 = icmp sle i64 %19, %20
  br i1 %cmp20, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i32, i32* %1, align 4
  %sub22 = sub nsw i32 %22, 0
  %sub23 = sub nsw i32 %sub22, 1
  %add24 = add nsw i32 %sub23, 1
  %div25 = sdiv i32 %add24, 1
  %conv26 = sext i32 %div25 to i64
  %div27 = sdiv i64 %21, %conv26
  %mul28 = mul nsw i64 %div27, 1
  %add29 = add nsw i64 0, %mul28
  %conv30 = trunc i64 %add29 to i32
  store i32 %conv30, i32* %k14, align 4
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub31 = sub nsw i32 %24, 0
  %sub32 = sub nsw i32 %sub31, 1
  %add33 = add nsw i32 %sub32, 1
  %div34 = sdiv i32 %add33, 1
  %conv35 = sext i32 %div34 to i64
  %rem = srem i64 %23, %conv35
  %mul36 = mul nsw i64 %rem, 1
  %add37 = add nsw i64 0, %mul36
  %conv38 = trunc i64 %add37 to i32
  store i32 %conv38, i32* %j13, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %25 = load i32, i32* %i, align 4
  %26 = load i32, i32* %2, align 4
  %cmp39 = icmp slt i32 %25, %26
  br i1 %cmp39, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %j13, align 4
  %29 = load i32, i32* %3, align 4
  %mul41 = mul nsw i32 %28, %29
  %add42 = add nsw i32 %27, %mul41
  %30 = load i32, i32* %k14, align 4
  %31 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %30, %31
  %add44 = add nsw i32 %add42, %mul43
  store i32 %add44, i32* %ijk, align 4
  %32 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %32 to i64
  %33 = load double*, double** %5, align 8
  %arrayidx = getelementptr inbounds double, double* %33, i64 %idxprom
  %34 = load double, double* %arrayidx, align 8
  %call = call double @fabs(double %34) #6
  store double %call, double* %fabs_grid_ijk, align 8
  %35 = load double, double* %fabs_grid_ijk, align 8
  %36 = load double, double* %box_norm15, align 8
  %cmp45 = fcmp ogt double %35, %36
  br i1 %cmp45, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %37 = load double, double* %fabs_grid_ijk, align 8
  store double %37, double* %box_norm15, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %38 = load i32, i32* %i, align 4
  %inc = add nsw i32 %38, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %39 = load i64, i64* %.omp.iv, align 8
  %add47 = add nsw i64 %39, 1
  store i64 %add47, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %40 = load i32*, i32** %.global_tid..addr, align 8
  %41 = load i32, i32* %40, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %41)
  %42 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %43 = bitcast double* %box_norm15 to i8*
  store i8* %43, i8** %42, align 8
  %44 = load i32*, i32** %.global_tid..addr, align 8
  %45 = load i32, i32* %44, align 4
  %46 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %47 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %45, i32 1, i64 8, i8* %46, void (i8*, i8*)* @.omp.reduction.reduction_func.41, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %47, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %48 = load double, double* %6, align 8
  %49 = load double, double* %box_norm15, align 8
  %cmp48 = fcmp ogt double %48, %49
  br i1 %cmp48, label %cond.true50, label %cond.false51

cond.true50:                                      ; preds = %.omp.reduction.case1
  %50 = load double, double* %6, align 8
  br label %cond.end52

cond.false51:                                     ; preds = %.omp.reduction.case1
  %51 = load double, double* %box_norm15, align 8
  br label %cond.end52

cond.end52:                                       ; preds = %cond.false51, %cond.true50
  %cond53 = phi double [ %50, %cond.true50 ], [ %51, %cond.false51 ]
  store double %cond53, double* %6, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %45, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %52 = load double, double* %box_norm15, align 8
  %53 = bitcast double* %6 to i64*
  %atomic-load = load atomic i64, i64* %53 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %cond.end58, %.omp.reduction.case2
  %54 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %64, %cond.end58 ]
  %55 = bitcast double* %atomic-temp to i64*
  %56 = bitcast i64 %54 to double
  store double %56, double* %tmp, align 8
  %57 = load double, double* %tmp, align 8
  %58 = load double, double* %box_norm15, align 8
  %cmp54 = fcmp ogt double %57, %58
  br i1 %cmp54, label %cond.true56, label %cond.false57

cond.true56:                                      ; preds = %atomic_cont
  %59 = load double, double* %tmp, align 8
  br label %cond.end58

cond.false57:                                     ; preds = %atomic_cont
  %60 = load double, double* %box_norm15, align 8
  br label %cond.end58

cond.end58:                                       ; preds = %cond.false57, %cond.true56
  %cond59 = phi double [ %59, %cond.true56 ], [ %60, %cond.false57 ]
  store double %cond59, double* %atomic-temp, align 8
  %61 = load i64, i64* %55, align 8
  %62 = bitcast double* %6 to i64*
  %63 = cmpxchg i64* %62, i64 %54, i64 %61 monotonic monotonic
  %64 = extractvalue { i64, i1 } %63, 0
  %65 = extractvalue { i64, i1 } %63, 1
  br i1 %65, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %cond.end58
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %cond.end52, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.41(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %cmp = fcmp ogt double %12, %13
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %14 = load double, double* %11, align 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %15 = load double, double* %8, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi double [ %14, %cond.true ], [ %15, %cond.false ]
  store double %cond, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.42(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %cmp = fcmp ogt double %12, %13
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %14 = load double, double* %11, align 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %15 = load double, double* %8, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi double [ %14, %cond.true ], [ %15, %cond.false ]
  store double %cond, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define double @mean(%struct.domain_type* %domain, i32 %level, i32 %id_a) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_a.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %sum_domain = alloca double, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  %ncells_domain = alloca double, align 8
  %mean_domain = alloca double, align 8
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_a, i32* %id_a.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  store double 0.000000e+00, double* %sum_domain, align 8
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 5, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, double*)* @.omp_outlined..43 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %sum_domain)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..43(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %sum_domain)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  %18 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %dim14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %18, i32 0, i32 13
  %i15 = getelementptr inbounds %struct.anon.2, %struct.anon.2* %dim14, i32 0, i32 0
  %19 = load i32, i32* %i15, align 8
  %conv16 = sitofp i32 %19 to double
  %20 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %dim17 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %20, i32 0, i32 13
  %j = getelementptr inbounds %struct.anon.2, %struct.anon.2* %dim17, i32 0, i32 1
  %21 = load i32, i32* %j, align 4
  %conv18 = sitofp i32 %21 to double
  %mul = fmul double %conv16, %conv18
  %22 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %dim19 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %22, i32 0, i32 13
  %k = getelementptr inbounds %struct.anon.2, %struct.anon.2* %dim19, i32 0, i32 2
  %23 = load i32, i32* %k, align 8
  %conv20 = sitofp i32 %23 to double
  %mul21 = fmul double %mul, %conv20
  store double %mul21, double* %ncells_domain, align 8
  %24 = load double, double* %sum_domain, align 8
  %25 = load double, double* %ncells_domain, align 8
  %div = fdiv double %24, %25
  store double %div, double* %mean_domain, align 8
  %26 = load double, double* %mean_domain, align 8
  ret double %26
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..43(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %sum_domain) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %sum_domain.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %sum_domain5 = alloca double, align 8
  %box6 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_a = alloca double*, align 8
  %sum_box = alloca double, align 8
  %.zero.addr = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %sum_domain, double** %sum_domain.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_a.addr, align 8
  %3 = load i32*, i32** %omp_within_a_box.addr, align 8
  %4 = load double*, double** %sum_domain.addr, align 8
  %5 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 19
  %6 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %6, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %7 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %7, i32 0, i32 19
  %8 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %8
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %9 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %9, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  store double 0.000000e+00, double* %sum_domain5, align 8
  %10 = load i32*, i32** %.global_tid..addr, align 8
  %11 = load i32, i32* %10, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %11, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %12 = load i32, i32* %.omp.ub, align 4
  %13 = load i32, i32* %.omp.last.iteration, align 4
  %cmp7 = icmp sgt i32 %12, %13
  br i1 %cmp7, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %14 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %14, %cond.true ], [ %15, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %16 = load i32, i32* %.omp.lb, align 4
  store i32 %16, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %17 = load i32, i32* %.omp.iv, align 4
  %18 = load i32, i32* %.omp.ub, align 4
  %cmp8 = icmp sle i32 %17, %18
  br i1 %cmp8, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %19 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %19, 1
  %add9 = add nsw i32 0, %mul
  store i32 %add9, i32* %box4, align 4
  %20 = load i32, i32* %1, align 4
  %idxprom = sext i32 %20 to i64
  %21 = load i32, i32* %box4, align 4
  %idxprom10 = sext i32 %21 to i64
  %22 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %22, i32 0, i32 25
  %23 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %23, i64 %idxprom10
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %24 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx11 = getelementptr inbounds %struct.box_type, %struct.box_type* %24, i64 %idxprom
  %pencil12 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx11, i32 0, i32 5
  %25 = load i32, i32* %pencil12, align 8
  store i32 %25, i32* %pencil, align 4
  %26 = load i32, i32* %1, align 4
  %idxprom13 = sext i32 %26 to i64
  %27 = load i32, i32* %box4, align 4
  %idxprom14 = sext i32 %27 to i64
  %28 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains15 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %28, i32 0, i32 25
  %29 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains15, align 8
  %arrayidx16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %29, i64 %idxprom14
  %levels17 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx16, i32 0, i32 5
  %30 = load %struct.box_type*, %struct.box_type** %levels17, align 8
  %arrayidx18 = getelementptr inbounds %struct.box_type, %struct.box_type* %30, i64 %idxprom13
  %plane19 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx18, i32 0, i32 6
  %31 = load i32, i32* %plane19, align 4
  store i32 %31, i32* %plane, align 4
  %32 = load i32, i32* %1, align 4
  %idxprom20 = sext i32 %32 to i64
  %33 = load i32, i32* %box4, align 4
  %idxprom21 = sext i32 %33 to i64
  %34 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains22 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %34, i32 0, i32 25
  %35 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains22, align 8
  %arrayidx23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %35, i64 %idxprom21
  %levels24 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx23, i32 0, i32 5
  %36 = load %struct.box_type*, %struct.box_type** %levels24, align 8
  %arrayidx25 = getelementptr inbounds %struct.box_type, %struct.box_type* %36, i64 %idxprom20
  %ghosts26 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx25, i32 0, i32 4
  %37 = load i32, i32* %ghosts26, align 4
  store i32 %37, i32* %ghosts, align 4
  %38 = load i32, i32* %1, align 4
  %idxprom27 = sext i32 %38 to i64
  %39 = load i32, i32* %box4, align 4
  %idxprom28 = sext i32 %39 to i64
  %40 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains29 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %40, i32 0, i32 25
  %41 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains29, align 8
  %arrayidx30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %41, i64 %idxprom28
  %levels31 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx30, i32 0, i32 5
  %42 = load %struct.box_type*, %struct.box_type** %levels31, align 8
  %arrayidx32 = getelementptr inbounds %struct.box_type, %struct.box_type* %42, i64 %idxprom27
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx32, i32 0, i32 2
  %k33 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %43 = load i32, i32* %k33, align 4
  store i32 %43, i32* %dim_k, align 4
  %44 = load i32, i32* %1, align 4
  %idxprom34 = sext i32 %44 to i64
  %45 = load i32, i32* %box4, align 4
  %idxprom35 = sext i32 %45 to i64
  %46 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains36 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %46, i32 0, i32 25
  %47 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains36, align 8
  %arrayidx37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %47, i64 %idxprom35
  %levels38 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx37, i32 0, i32 5
  %48 = load %struct.box_type*, %struct.box_type** %levels38, align 8
  %arrayidx39 = getelementptr inbounds %struct.box_type, %struct.box_type* %48, i64 %idxprom34
  %dim40 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx39, i32 0, i32 2
  %j41 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim40, i32 0, i32 1
  %49 = load i32, i32* %j41, align 4
  store i32 %49, i32* %dim_j, align 4
  %50 = load i32, i32* %1, align 4
  %idxprom42 = sext i32 %50 to i64
  %51 = load i32, i32* %box4, align 4
  %idxprom43 = sext i32 %51 to i64
  %52 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains44 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %52, i32 0, i32 25
  %53 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains44, align 8
  %arrayidx45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %53, i64 %idxprom43
  %levels46 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx45, i32 0, i32 5
  %54 = load %struct.box_type*, %struct.box_type** %levels46, align 8
  %arrayidx47 = getelementptr inbounds %struct.box_type, %struct.box_type* %54, i64 %idxprom42
  %dim48 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx47, i32 0, i32 2
  %i49 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim48, i32 0, i32 0
  %55 = load i32, i32* %i49, align 4
  store i32 %55, i32* %dim_i, align 4
  %56 = load i32, i32* %2, align 4
  %idxprom50 = sext i32 %56 to i64
  %57 = load i32, i32* %1, align 4
  %idxprom51 = sext i32 %57 to i64
  %58 = load i32, i32* %box4, align 4
  %idxprom52 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains53 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 25
  %60 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains53, align 8
  %arrayidx54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %60, i64 %idxprom52
  %levels55 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx54, i32 0, i32 5
  %61 = load %struct.box_type*, %struct.box_type** %levels55, align 8
  %arrayidx56 = getelementptr inbounds %struct.box_type, %struct.box_type* %61, i64 %idxprom51
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx56, i32 0, i32 10
  %62 = load double**, double*** %grids, align 8
  %arrayidx57 = getelementptr inbounds double*, double** %62, i64 %idxprom50
  %63 = load double*, double** %arrayidx57, align 8
  %64 = load i32, i32* %ghosts, align 4
  %65 = load i32, i32* %pencil, align 4
  %add58 = add nsw i32 1, %65
  %66 = load i32, i32* %plane, align 4
  %add59 = add nsw i32 %add58, %66
  %mul60 = mul nsw i32 %64, %add59
  %idx.ext = sext i32 %mul60 to i64
  %add.ptr = getelementptr inbounds double, double* %63, i64 %idx.ext
  store double* %add.ptr, double** %grid_a, align 8
  store double 0.000000e+00, double* %sum_box, align 8
  %67 = load i32, i32* %3, align 4
  %tobool = icmp ne i32 %67, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 7, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double**)* @.omp_outlined..44 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %sum_box, double** %grid_a)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %68 = load i32*, i32** %.global_tid..addr, align 8
  %69 = load i32, i32* %68, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %69)
  %70 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..44(i32* %70, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %sum_box, double** %grid_a)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %69)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %71 = load double, double* %sum_box, align 8
  %72 = load double, double* %sum_domain5, align 8
  %add61 = fadd double %72, %71
  store double %add61, double* %sum_domain5, align 8
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %73 = load i32, i32* %.omp.iv, align 4
  %add62 = add nsw i32 %73, 1
  store i32 %add62, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %74 = load i32*, i32** %.global_tid..addr, align 8
  %75 = load i32, i32* %74, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %75)
  %76 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %77 = bitcast double* %sum_domain5 to i8*
  store i8* %77, i8** %76, align 8
  %78 = load i32*, i32** %.global_tid..addr, align 8
  %79 = load i32, i32* %78, align 4
  %80 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %81 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %79, i32 1, i64 8, i8* %80, void (i8*, i8*)* @.omp.reduction.reduction_func.46, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %81, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %82 = load double, double* %4, align 8
  %83 = load double, double* %sum_domain5, align 8
  %add63 = fadd double %82, %83
  store double %add63, double* %4, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %79, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %84 = load double, double* %sum_domain5, align 8
  %85 = bitcast double* %4 to i64*
  %atomic-load = load atomic i64, i64* %85 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %atomic_cont, %.omp.reduction.case2
  %86 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %94, %atomic_cont ]
  %87 = bitcast double* %atomic-temp to i64*
  %88 = bitcast i64 %86 to double
  store double %88, double* %tmp, align 8
  %89 = load double, double* %tmp, align 8
  %90 = load double, double* %sum_domain5, align 8
  %add64 = fadd double %89, %90
  store double %add64, double* %atomic-temp, align 8
  %91 = load i64, i64* %87, align 8
  %92 = bitcast double* %4 to i64*
  %93 = cmpxchg i64* %92, i64 %86, i64 %91 monotonic monotonic
  %94 = extractvalue { i64, i1 } %93, 0
  %95 = extractvalue { i64, i1 } %93, 1
  br i1 %95, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %atomic_cont
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %.omp.reduction.case1, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..44(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %sum_box, double** dereferenceable(8) %grid_a) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %sum_box.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %i = alloca i32, align 4
  %j13 = alloca i32, align 4
  %k14 = alloca i32, align 4
  %sum_box15 = alloca double, align 8
  %k16 = alloca i32, align 4
  %j17 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %sum_box, double** %sum_box.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %sum_box.addr, align 8
  %6 = load double**, double*** %grid_a.addr, align 8
  %7 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %8 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %8, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %9 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %10 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %10
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %11 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %11, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  store double 0.000000e+00, double* %sum_box15, align 8
  %12 = load i32*, i32** %.global_tid..addr, align 8
  %13 = load i32, i32* %12, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %13, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %14 = load i64, i64* %.omp.ub, align 8
  %15 = load i64, i64* %.omp.last.iteration, align 8
  %cmp18 = icmp sgt i64 %14, %15
  br i1 %cmp18, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %16 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %16, %cond.true ], [ %17, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %18 = load i64, i64* %.omp.lb, align 8
  store i64 %18, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %19 = load i64, i64* %.omp.iv, align 8
  %20 = load i64, i64* %.omp.ub, align 8
  %cmp20 = icmp sle i64 %19, %20
  br i1 %cmp20, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %21 = load i64, i64* %.omp.iv, align 8
  %22 = load i32, i32* %1, align 4
  %sub22 = sub nsw i32 %22, 0
  %sub23 = sub nsw i32 %sub22, 1
  %add24 = add nsw i32 %sub23, 1
  %div25 = sdiv i32 %add24, 1
  %conv26 = sext i32 %div25 to i64
  %div27 = sdiv i64 %21, %conv26
  %mul28 = mul nsw i64 %div27, 1
  %add29 = add nsw i64 0, %mul28
  %conv30 = trunc i64 %add29 to i32
  store i32 %conv30, i32* %k14, align 4
  %23 = load i64, i64* %.omp.iv, align 8
  %24 = load i32, i32* %1, align 4
  %sub31 = sub nsw i32 %24, 0
  %sub32 = sub nsw i32 %sub31, 1
  %add33 = add nsw i32 %sub32, 1
  %div34 = sdiv i32 %add33, 1
  %conv35 = sext i32 %div34 to i64
  %rem = srem i64 %23, %conv35
  %mul36 = mul nsw i64 %rem, 1
  %add37 = add nsw i64 0, %mul36
  %conv38 = trunc i64 %add37 to i32
  store i32 %conv38, i32* %j13, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %25 = load i32, i32* %i, align 4
  %26 = load i32, i32* %2, align 4
  %cmp39 = icmp slt i32 %25, %26
  br i1 %cmp39, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %27 = load i32, i32* %i, align 4
  %28 = load i32, i32* %j13, align 4
  %29 = load i32, i32* %3, align 4
  %mul41 = mul nsw i32 %28, %29
  %add42 = add nsw i32 %27, %mul41
  %30 = load i32, i32* %k14, align 4
  %31 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %30, %31
  %add44 = add nsw i32 %add42, %mul43
  store i32 %add44, i32* %ijk, align 4
  %32 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %32 to i64
  %33 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %33, i64 %idxprom
  %34 = load double, double* %arrayidx, align 8
  %35 = load double, double* %sum_box15, align 8
  %add45 = fadd double %35, %34
  store double %add45, double* %sum_box15, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %36 = load i32, i32* %i, align 4
  %inc = add nsw i32 %36, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %37 = load i64, i64* %.omp.iv, align 8
  %add46 = add nsw i64 %37, 1
  store i64 %add46, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %38 = load i32*, i32** %.global_tid..addr, align 8
  %39 = load i32, i32* %38, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %39)
  %40 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %41 = bitcast double* %sum_box15 to i8*
  store i8* %41, i8** %40, align 8
  %42 = load i32*, i32** %.global_tid..addr, align 8
  %43 = load i32, i32* %42, align 4
  %44 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %45 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %43, i32 1, i64 8, i8* %44, void (i8*, i8*)* @.omp.reduction.reduction_func.45, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %45, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %46 = load double, double* %5, align 8
  %47 = load double, double* %sum_box15, align 8
  %add47 = fadd double %46, %47
  store double %add47, double* %5, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %43, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %48 = load double, double* %sum_box15, align 8
  %49 = bitcast double* %5 to i64*
  %atomic-load = load atomic i64, i64* %49 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %atomic_cont, %.omp.reduction.case2
  %50 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %58, %atomic_cont ]
  %51 = bitcast double* %atomic-temp to i64*
  %52 = bitcast i64 %50 to double
  store double %52, double* %tmp, align 8
  %53 = load double, double* %tmp, align 8
  %54 = load double, double* %sum_box15, align 8
  %add48 = fadd double %53, %54
  store double %add48, double* %atomic-temp, align 8
  %55 = load i64, i64* %51, align 8
  %56 = bitcast double* %5 to i64*
  %57 = cmpxchg i64* %56, i64 %50, i64 %55 monotonic monotonic
  %58 = extractvalue { i64, i1 } %57, 0
  %59 = extractvalue { i64, i1 } %57, 1
  br i1 %59, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %atomic_cont
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %.omp.reduction.case1, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.45(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %add = fadd double %12, %13
  store double %add, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.46(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %add = fadd double %12, %13
  store double %add, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @shift_grid(%struct.domain_type* %domain, i32 %level, i32 %id_c, i32 %id_a, double %shift_a) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_c.addr = alloca i32, align 4
  %id_a.addr = alloca i32, align 4
  %shift_a.addr = alloca double, align 8
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_c, i32* %id_c.addr, align 4
  store i32 %id_a, i32* %id_a.addr, align 4
  store double %shift_a, double* %shift_a.addr, align 8
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, double*)* @.omp_outlined..47 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %shift_a.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..47(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_c.addr, i32* %id_a.addr, i32* %omp_within_a_box, double* %shift_a.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..47(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_c, i32* dereferenceable(4) %id_a, i32* dereferenceable(4) %omp_within_a_box, double* dereferenceable(8) %shift_a) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_c.addr = alloca i32*, align 8
  %id_a.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %shift_a.addr = alloca double*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_c = alloca double*, align 8
  %grid_a = alloca double*, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_c, i32** %id_c.addr, align 8
  store i32* %id_a, i32** %id_a.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double* %shift_a, double** %shift_a.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_c.addr, align 8
  %3 = load i32*, i32** %id_a.addr, align 8
  %4 = load i32*, i32** %omp_within_a_box.addr, align 8
  %5 = load double*, double** %shift_a.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %13, %14
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %18, %19
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %26 = load i32, i32* %pencil11, align 8
  store i32 %26, i32* %pencil, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %32 = load i32, i32* %plane18, align 4
  store i32 %32, i32* %plane, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %38 = load i32, i32* %ghosts25, align 4
  store i32 %38, i32* %ghosts, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %44 = load i32, i32* %k32, align 4
  store i32 %44, i32* %dim_k, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %50 = load i32, i32* %j40, align 4
  store i32 %50, i32* %dim_j, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %56 = load i32, i32* %i48, align 4
  store i32 %56, i32* %dim_i, align 4
  %57 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %57 to i64
  %58 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %63 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %63, i64 %idxprom49
  %64 = load double*, double** %arrayidx56, align 8
  %65 = load i32, i32* %ghosts, align 4
  %66 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %66
  %67 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %67
  %mul59 = mul nsw i32 %65, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %64, i64 %idx.ext
  store double* %add.ptr, double** %grid_c, align 8
  %68 = load i32, i32* %3, align 4
  %idxprom60 = sext i32 %68 to i64
  %69 = load i32, i32* %1, align 4
  %idxprom61 = sext i32 %69 to i64
  %70 = load i32, i32* %box4, align 4
  %idxprom62 = sext i32 %70 to i64
  %71 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %71, i32 0, i32 25
  %72 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %72, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %73 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %73, i64 %idxprom61
  %grids67 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 10
  %74 = load double**, double*** %grids67, align 8
  %arrayidx68 = getelementptr inbounds double*, double** %74, i64 %idxprom60
  %75 = load double*, double** %arrayidx68, align 8
  %76 = load i32, i32* %ghosts, align 4
  %77 = load i32, i32* %pencil, align 4
  %add69 = add nsw i32 1, %77
  %78 = load i32, i32* %plane, align 4
  %add70 = add nsw i32 %add69, %78
  %mul71 = mul nsw i32 %76, %add70
  %idx.ext72 = sext i32 %mul71 to i64
  %add.ptr73 = getelementptr inbounds double, double* %75, i64 %idx.ext72
  store double* %add.ptr73, double** %grid_a, align 8
  %79 = load i32, i32* %4, align 4
  %tobool = icmp ne i32 %79, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %omp.inner.for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**, double*)* @.omp_outlined..48 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double** %grid_a, double* %5)
  br label %omp_if.end

omp_if.else:                                      ; preds = %omp.inner.for.body
  %80 = load i32*, i32** %.global_tid..addr, align 8
  %81 = load i32, i32* %80, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %81)
  %82 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..48(i32* %82, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_c, double** %grid_a, double* %5)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %81)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %83 = load i32, i32* %.omp.iv, align 4
  %add74 = add nsw i32 %83, 1
  store i32 %add74, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %84 = load i32*, i32** %.global_tid..addr, align 8
  %85 = load i32, i32* %84, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %85)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..48(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid_c, double** dereferenceable(8) %grid_a, double* dereferenceable(8) %shift_a) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid_c.addr = alloca double**, align 8
  %grid_a.addr = alloca double**, align 8
  %shift_a.addr = alloca double*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %i = alloca i32, align 4
  %j13 = alloca i32, align 4
  %k14 = alloca i32, align 4
  %k15 = alloca i32, align 4
  %j16 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid_c, double*** %grid_c.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  store double* %shift_a, double** %shift_a.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid_c.addr, align 8
  %6 = load double**, double*** %grid_a.addr, align 8
  %7 = load double*, double** %shift_a.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %9, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %11
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %15, %16
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %20, %21
  br i1 %cmp19, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i32, i32* %1, align 4
  %sub21 = sub nsw i32 %23, 0
  %sub22 = sub nsw i32 %sub21, 1
  %add23 = add nsw i32 %sub22, 1
  %div24 = sdiv i32 %add23, 1
  %conv25 = sext i32 %div24 to i64
  %div26 = sdiv i64 %22, %conv25
  %mul27 = mul nsw i64 %div26, 1
  %add28 = add nsw i64 0, %mul27
  %conv29 = trunc i64 %add28 to i32
  store i32 %conv29, i32* %k14, align 4
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub30 = sub nsw i32 %25, 0
  %sub31 = sub nsw i32 %sub30, 1
  %add32 = add nsw i32 %sub31, 1
  %div33 = sdiv i32 %add32, 1
  %conv34 = sext i32 %div33 to i64
  %rem = srem i64 %24, %conv34
  %mul35 = mul nsw i64 %rem, 1
  %add36 = add nsw i64 0, %mul35
  %conv37 = trunc i64 %add36 to i32
  store i32 %conv37, i32* %j13, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %2, align 4
  %cmp38 = icmp slt i32 %26, %27
  br i1 %cmp38, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %j13, align 4
  %30 = load i32, i32* %3, align 4
  %mul40 = mul nsw i32 %29, %30
  %add41 = add nsw i32 %28, %mul40
  %31 = load i32, i32* %k14, align 4
  %32 = load i32, i32* %4, align 4
  %mul42 = mul nsw i32 %31, %32
  %add43 = add nsw i32 %add41, %mul42
  store i32 %add43, i32* %ijk, align 4
  %33 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %33 to i64
  %34 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %34, i64 %idxprom
  %35 = load double, double* %arrayidx, align 8
  %36 = load double, double* %7, align 8
  %add44 = fadd double %35, %36
  %37 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %37 to i64
  %38 = load double*, double** %5, align 8
  %arrayidx46 = getelementptr inbounds double, double* %38, i64 %idxprom45
  store double %add44, double* %arrayidx46, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %39 = load i32, i32* %i, align 4
  %inc = add nsw i32 %39, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %40 = load i64, i64* %.omp.iv, align 8
  %add47 = add nsw i64 %40, 1
  store i64 %add47, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %41 = load i32*, i32** %.global_tid..addr, align 8
  %42 = load i32, i32* %41, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %42)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @project_cell_to_face(%struct.domain_type* %domain, i32 %level, i32 %id_cell, i32 %id_face, i32 %dir) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %id_cell.addr = alloca i32, align 4
  %id_face.addr = alloca i32, align 4
  %dir.addr = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %CollaborativeThreadingBoxSize = alloca i32, align 4
  %omp_across_boxes = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %box = alloca i32, align 4
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store i32 %id_cell, i32* %id_cell.addr, align 4
  store i32 %id_face, i32* %id_face.addr, align 4
  store i32 %dir, i32* %dir.addr, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  store i32 100000, i32* %CollaborativeThreadingBoxSize, align 4
  %1 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %1 to i64
  %2 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %2, i32 0, i32 25
  %3 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %3, i64 0
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %4 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx1 = getelementptr inbounds %struct.box_type, %struct.box_type* %4, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx1, i32 0, i32 2
  %i = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 0
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp = icmp slt i32 %5, %6
  %conv = zext i1 %cmp to i32
  store i32 %conv, i32* %omp_across_boxes, align 4
  %7 = load i32, i32* %level.addr, align 4
  %idxprom2 = sext i32 %7 to i64
  %8 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 25
  %9 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains3, align 8
  %arrayidx4 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %9, i64 0
  %levels5 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx4, i32 0, i32 5
  %10 = load %struct.box_type*, %struct.box_type** %levels5, align 8
  %arrayidx6 = getelementptr inbounds %struct.box_type, %struct.box_type* %10, i64 %idxprom2
  %dim7 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx6, i32 0, i32 2
  %i8 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim7, i32 0, i32 0
  %11 = load i32, i32* %i8, align 4
  %12 = load i32, i32* %CollaborativeThreadingBoxSize, align 4
  %cmp9 = icmp sge i32 %11, %12
  %conv10 = zext i1 %cmp9 to i32
  store i32 %conv10, i32* %omp_within_a_box, align 4
  %13 = load i32, i32* %omp_across_boxes, align 4
  %tobool = icmp ne i32 %13, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 6, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, i32*, i32*, i32*)* @.omp_outlined..49 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_cell.addr, i32* %id_face.addr, i32* %dir.addr, i32* %omp_within_a_box)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..49(i32* %.threadid_temp., i32* %.zero.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32* %id_cell.addr, i32* %id_face.addr, i32* %dir.addr, i32* %omp_within_a_box)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call11 = call i64 (...) @CycleTime()
  %14 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call11, %14
  %15 = load i32, i32* %level.addr, align 4
  %idxprom12 = sext i32 %15 to i64
  %16 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %16, i32 0, i32 0
  %blas1 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 12
  %arrayidx13 = getelementptr inbounds [10 x i64], [10 x i64]* %blas1, i64 0, i64 %idxprom12
  %17 = load i64, i64* %arrayidx13, align 8
  %add = add i64 %17, %sub
  store i64 %add, i64* %arrayidx13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..49(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32* dereferenceable(4) %id_cell, i32* dereferenceable(4) %id_face, i32* dereferenceable(4) %dir, i32* dereferenceable(4) %omp_within_a_box) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_cell.addr = alloca i32*, align 8
  %id_face.addr = alloca i32*, align 8
  %dir.addr = alloca i32*, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %.omp.iv = alloca i32, align 4
  %.omp.last.iteration = alloca i32, align 4
  %box = alloca i32, align 4
  %.omp.lb = alloca i32, align 4
  %.omp.ub = alloca i32, align 4
  %.omp.stride = alloca i32, align 4
  %.omp.is_last = alloca i32, align 4
  %box4 = alloca i32, align 4
  %box5 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_cell = alloca double*, align 8
  %grid_face = alloca double*, align 8
  %stride = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32* %id_cell, i32** %id_cell.addr, align 8
  store i32* %id_face, i32** %id_face.addr, align 8
  store i32* %dir, i32** %dir.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %level.addr, align 8
  %2 = load i32*, i32** %id_cell.addr, align 8
  %3 = load i32*, i32** %id_face.addr, align 8
  %4 = load i32*, i32** %dir.addr, align 8
  %5 = load i32*, i32** %omp_within_a_box.addr, align 8
  %6 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %6, i32 0, i32 19
  %7 = load i32, i32* %subdomains_per_rank, align 8
  %sub = sub nsw i32 %7, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %sub2 = sub nsw i32 %div, 1
  store i32 %sub2, i32* %.omp.last.iteration, align 4
  store i32 0, i32* %box, align 4
  %8 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains_per_rank3 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %8, i32 0, i32 19
  %9 = load i32, i32* %subdomains_per_rank3, align 8
  %cmp = icmp slt i32 0, %9
  br i1 %cmp, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %entry
  store i32 0, i32* %.omp.lb, align 4
  %10 = load i32, i32* %.omp.last.iteration, align 4
  store i32 %10, i32* %.omp.ub, align 4
  store i32 1, i32* %.omp.stride, align 4
  store i32 0, i32* %.omp.is_last, align 4
  %11 = load i32*, i32** %.global_tid..addr, align 8
  %12 = load i32, i32* %11, align 4
  call void @__kmpc_for_static_init_4(%ident_t* @0, i32 %12, i32 34, i32* %.omp.is_last, i32* %.omp.lb, i32* %.omp.ub, i32* %.omp.stride, i32 1, i32 1)
  %13 = load i32, i32* %.omp.ub, align 4
  %14 = load i32, i32* %.omp.last.iteration, align 4
  %cmp6 = icmp sgt i32 %13, %14
  br i1 %cmp6, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %15 = load i32, i32* %.omp.last.iteration, align 4
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %16 = load i32, i32* %.omp.ub, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %15, %cond.true ], [ %16, %cond.false ]
  store i32 %cond, i32* %.omp.ub, align 4
  %17 = load i32, i32* %.omp.lb, align 4
  store i32 %17, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %18 = load i32, i32* %.omp.iv, align 4
  %19 = load i32, i32* %.omp.ub, align 4
  %cmp7 = icmp sle i32 %18, %19
  br i1 %cmp7, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %20 = load i32, i32* %.omp.iv, align 4
  %mul = mul nsw i32 %20, 1
  %add8 = add nsw i32 0, %mul
  store i32 %add8, i32* %box4, align 4
  %21 = load i32, i32* %1, align 4
  %idxprom = sext i32 %21 to i64
  %22 = load i32, i32* %box4, align 4
  %idxprom9 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom9
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom
  %pencil11 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 5
  %26 = load i32, i32* %pencil11, align 8
  store i32 %26, i32* %pencil, align 4
  %27 = load i32, i32* %1, align 4
  %idxprom12 = sext i32 %27 to i64
  %28 = load i32, i32* %box4, align 4
  %idxprom13 = sext i32 %28 to i64
  %29 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains14 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %29, i32 0, i32 25
  %30 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains14, align 8
  %arrayidx15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %30, i64 %idxprom13
  %levels16 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx15, i32 0, i32 5
  %31 = load %struct.box_type*, %struct.box_type** %levels16, align 8
  %arrayidx17 = getelementptr inbounds %struct.box_type, %struct.box_type* %31, i64 %idxprom12
  %plane18 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx17, i32 0, i32 6
  %32 = load i32, i32* %plane18, align 4
  store i32 %32, i32* %plane, align 4
  %33 = load i32, i32* %1, align 4
  %idxprom19 = sext i32 %33 to i64
  %34 = load i32, i32* %box4, align 4
  %idxprom20 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom19
  %ghosts25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 4
  %38 = load i32, i32* %ghosts25, align 4
  store i32 %38, i32* %ghosts, align 4
  %39 = load i32, i32* %1, align 4
  %idxprom26 = sext i32 %39 to i64
  %40 = load i32, i32* %box4, align 4
  %idxprom27 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains28 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains28, align 8
  %arrayidx29 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom27
  %levels30 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx29, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels30, align 8
  %arrayidx31 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom26
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx31, i32 0, i32 2
  %k32 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %44 = load i32, i32* %k32, align 4
  store i32 %44, i32* %dim_k, align 4
  %45 = load i32, i32* %1, align 4
  %idxprom33 = sext i32 %45 to i64
  %46 = load i32, i32* %box4, align 4
  %idxprom34 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains35 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains35, align 8
  %arrayidx36 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom34
  %levels37 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx36, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels37, align 8
  %arrayidx38 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom33
  %dim39 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx38, i32 0, i32 2
  %j40 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim39, i32 0, i32 1
  %50 = load i32, i32* %j40, align 4
  store i32 %50, i32* %dim_j, align 4
  %51 = load i32, i32* %1, align 4
  %idxprom41 = sext i32 %51 to i64
  %52 = load i32, i32* %box4, align 4
  %idxprom42 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains43 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains43, align 8
  %arrayidx44 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom42
  %levels45 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx44, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels45, align 8
  %arrayidx46 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom41
  %dim47 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx46, i32 0, i32 2
  %i48 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim47, i32 0, i32 0
  %56 = load i32, i32* %i48, align 4
  store i32 %56, i32* %dim_i, align 4
  %57 = load i32, i32* %2, align 4
  %idxprom49 = sext i32 %57 to i64
  %58 = load i32, i32* %1, align 4
  %idxprom50 = sext i32 %58 to i64
  %59 = load i32, i32* %box4, align 4
  %idxprom51 = sext i32 %59 to i64
  %60 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains52 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %60, i32 0, i32 25
  %61 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains52, align 8
  %arrayidx53 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %61, i64 %idxprom51
  %levels54 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx53, i32 0, i32 5
  %62 = load %struct.box_type*, %struct.box_type** %levels54, align 8
  %arrayidx55 = getelementptr inbounds %struct.box_type, %struct.box_type* %62, i64 %idxprom50
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx55, i32 0, i32 10
  %63 = load double**, double*** %grids, align 8
  %arrayidx56 = getelementptr inbounds double*, double** %63, i64 %idxprom49
  %64 = load double*, double** %arrayidx56, align 8
  %65 = load i32, i32* %ghosts, align 4
  %66 = load i32, i32* %pencil, align 4
  %add57 = add nsw i32 1, %66
  %67 = load i32, i32* %plane, align 4
  %add58 = add nsw i32 %add57, %67
  %mul59 = mul nsw i32 %65, %add58
  %idx.ext = sext i32 %mul59 to i64
  %add.ptr = getelementptr inbounds double, double* %64, i64 %idx.ext
  store double* %add.ptr, double** %grid_cell, align 8
  %68 = load i32, i32* %3, align 4
  %idxprom60 = sext i32 %68 to i64
  %69 = load i32, i32* %1, align 4
  %idxprom61 = sext i32 %69 to i64
  %70 = load i32, i32* %box4, align 4
  %idxprom62 = sext i32 %70 to i64
  %71 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %71, i32 0, i32 25
  %72 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %72, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %73 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %73, i64 %idxprom61
  %grids67 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 10
  %74 = load double**, double*** %grids67, align 8
  %arrayidx68 = getelementptr inbounds double*, double** %74, i64 %idxprom60
  %75 = load double*, double** %arrayidx68, align 8
  %76 = load i32, i32* %ghosts, align 4
  %77 = load i32, i32* %pencil, align 4
  %add69 = add nsw i32 1, %77
  %78 = load i32, i32* %plane, align 4
  %add70 = add nsw i32 %add69, %78
  %mul71 = mul nsw i32 %76, %add70
  %idx.ext72 = sext i32 %mul71 to i64
  %add.ptr73 = getelementptr inbounds double, double* %75, i64 %idx.ext72
  store double* %add.ptr73, double** %grid_face, align 8
  %79 = load i32, i32* %4, align 4
  switch i32 %79, label %sw.epilog [
    i32 0, label %sw.bb
    i32 1, label %sw.bb74
    i32 2, label %sw.bb75
  ]

sw.bb:                                            ; preds = %omp.inner.for.body
  store i32 1, i32* %stride, align 4
  br label %sw.epilog

sw.bb74:                                          ; preds = %omp.inner.for.body
  %80 = load i32, i32* %pencil, align 4
  store i32 %80, i32* %stride, align 4
  br label %sw.epilog

sw.bb75:                                          ; preds = %omp.inner.for.body
  %81 = load i32, i32* %plane, align 4
  store i32 %81, i32* %stride, align 4
  br label %sw.epilog

sw.epilog:                                        ; preds = %omp.inner.for.body, %sw.bb75, %sw.bb74, %sw.bb
  %82 = load i32, i32* %5, align 4
  %tobool = icmp ne i32 %82, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %sw.epilog
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double**, double**, i32*)* @.omp_outlined..50 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_face, double** %grid_cell, i32* %stride)
  br label %omp_if.end

omp_if.else:                                      ; preds = %sw.epilog
  %83 = load i32*, i32** %.global_tid..addr, align 8
  %84 = load i32, i32* %83, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %84)
  %85 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..50(i32* %85, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double** %grid_face, double** %grid_cell, i32* %stride)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %84)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  br label %omp.body.continue

omp.body.continue:                                ; preds = %omp_if.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %86 = load i32, i32* %.omp.iv, align 4
  %add76 = add nsw i32 %86, 1
  store i32 %add76, i32* %.omp.iv, align 4
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %87 = load i32*, i32** %.global_tid..addr, align 8
  %88 = load i32, i32* %87, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %88)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..50(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double** dereferenceable(8) %grid_face, double** dereferenceable(8) %grid_cell, i32* dereferenceable(4) %stride) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %grid_face.addr = alloca double**, align 8
  %grid_cell.addr = alloca double**, align 8
  %stride.addr = alloca i32*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k11 = alloca i32, align 4
  %j12 = alloca i32, align 4
  %i = alloca i32, align 4
  %k13 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %ijk = alloca i32, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double** %grid_face, double*** %grid_face.addr, align 8
  store double** %grid_cell, double*** %grid_cell.addr, align 8
  store i32* %stride, i32** %stride.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double**, double*** %grid_face.addr, align 8
  %6 = load double**, double*** %grid_cell.addr, align 8
  %7 = load i32*, i32** %stride.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %add = add nsw i32 %sub, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub1 = sub nsw i32 %9, 0
  %add2 = add nsw i32 %sub1, 1
  %div3 = sdiv i32 %add2, 1
  %conv4 = sext i32 %div3 to i64
  %mul = mul nsw i64 %conv, %conv4
  %sub5 = sub nsw i64 %mul, 1
  store i64 %sub5, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp sle i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp8 = icmp sle i32 0, %11
  br i1 %cmp8, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp15 = icmp sgt i64 %15, %16
  br i1 %cmp15, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp17 = icmp sle i64 %20, %21
  br i1 %cmp17, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i32, i32* %1, align 4
  %sub19 = sub nsw i32 %23, 0
  %add20 = add nsw i32 %sub19, 1
  %div21 = sdiv i32 %add20, 1
  %conv22 = sext i32 %div21 to i64
  %div23 = sdiv i64 %22, %conv22
  %mul24 = mul nsw i64 %div23, 1
  %add25 = add nsw i64 0, %mul24
  %conv26 = trunc i64 %add25 to i32
  store i32 %conv26, i32* %k11, align 4
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub27 = sub nsw i32 %25, 0
  %add28 = add nsw i32 %sub27, 1
  %div29 = sdiv i32 %add28, 1
  %conv30 = sext i32 %div29 to i64
  %rem = srem i64 %24, %conv30
  %mul31 = mul nsw i64 %rem, 1
  %add32 = add nsw i64 0, %mul31
  %conv33 = trunc i64 %add32 to i32
  store i32 %conv33, i32* %j12, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %2, align 4
  %cmp34 = icmp sle i32 %26, %27
  br i1 %cmp34, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %j12, align 4
  %30 = load i32, i32* %3, align 4
  %mul36 = mul nsw i32 %29, %30
  %add37 = add nsw i32 %28, %mul36
  %31 = load i32, i32* %k11, align 4
  %32 = load i32, i32* %4, align 4
  %mul38 = mul nsw i32 %31, %32
  %add39 = add nsw i32 %add37, %mul38
  store i32 %add39, i32* %ijk, align 4
  %33 = load i32, i32* %ijk, align 4
  %34 = load i32, i32* %7, align 4
  %sub40 = sub nsw i32 %33, %34
  %idxprom = sext i32 %sub40 to i64
  %35 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %35, i64 %idxprom
  %36 = load double, double* %arrayidx, align 8
  %37 = load i32, i32* %ijk, align 4
  %idxprom41 = sext i32 %37 to i64
  %38 = load double*, double** %6, align 8
  %arrayidx42 = getelementptr inbounds double, double* %38, i64 %idxprom41
  %39 = load double, double* %arrayidx42, align 8
  %add43 = fadd double %36, %39
  %mul44 = fmul double 5.000000e-01, %add43
  %40 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %40 to i64
  %41 = load double*, double** %5, align 8
  %arrayidx46 = getelementptr inbounds double, double* %41, i64 %idxprom45
  store double %mul44, double* %arrayidx46, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %42 = load i32, i32* %i, align 4
  %inc = add nsw i32 %42, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %43 = load i64, i64* %.omp.iv, align 8
  %add47 = add nsw i64 %43, 1
  store i64 %add47, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %44 = load i32*, i32** %.global_tid..addr, align 8
  %45 = load i32, i32* %44, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %45)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @matmul_grids(%struct.domain_type* %domain, i32 %level, double* %C, i32* %id_A, i32* %id_B, i32 %rows, i32 %cols, i32 %A_equals_B_transpose) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %C.addr = alloca double*, align 8
  %id_A.addr = alloca i32*, align 8
  %id_B.addr = alloca i32*, align 8
  %rows.addr = alloca i32, align 4
  %cols.addr = alloca i32, align 4
  %A_equals_B_transpose.addr = alloca i32, align 4
  %omp_across_matrix = alloca i32, align 4
  %omp_within_a_box = alloca i32, align 4
  %mm = alloca i32, align 4
  %nn = alloca i32, align 4
  %_timeStart = alloca i64, align 8
  %0 = call i32 @__kmpc_global_thread_num(%ident_t* @0)
  %.threadid_temp. = alloca i32, align 4
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store double* %C, double** %C.addr, align 8
  store i32* %id_A, i32** %id_A.addr, align 8
  store i32* %id_B, i32** %id_B.addr, align 8
  store i32 %rows, i32* %rows.addr, align 4
  store i32 %cols, i32* %cols.addr, align 4
  store i32 %A_equals_B_transpose, i32* %A_equals_B_transpose.addr, align 4
  store i32 1, i32* %omp_across_matrix, align 4
  store i32 0, i32* %omp_within_a_box, align 4
  %call = call i64 (...) @CycleTime()
  store i64 %call, i64* %_timeStart, align 8
  %1 = load i32, i32* %omp_across_matrix, align 4
  %tobool = icmp ne i32 %1, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %entry
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, %struct.domain_type**, i32*, i32**, i32**, i32*, double**)* @.omp_outlined..51 to void (i32*, i32*, ...)*), i32* %rows.addr, i32* %cols.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32** %id_A.addr, i32** %id_B.addr, i32* %omp_within_a_box, double** %C.addr)
  br label %omp_if.end

omp_if.else:                                      ; preds = %entry
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %0)
  store i32 %0, i32* %.threadid_temp., align 4
  call void @.omp_outlined..51(i32* %.threadid_temp., i32* %.zero.addr, i32* %rows.addr, i32* %cols.addr, %struct.domain_type** %domain.addr, i32* %level.addr, i32** %id_A.addr, i32** %id_B.addr, i32* %omp_within_a_box, double** %C.addr)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %0)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %call1 = call i64 (...) @CycleTime()
  %2 = load i64, i64* %_timeStart, align 8
  %sub = sub i64 %call1, %2
  %3 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %3 to i64
  %4 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %cycles = getelementptr inbounds %struct.domain_type, %struct.domain_type* %4, i32 0, i32 0
  %blas3 = getelementptr inbounds %struct.anon, %struct.anon* %cycles, i32 0, i32 13
  %arrayidx = getelementptr inbounds [10 x i64], [10 x i64]* %blas3, i64 0, i64 %idxprom
  %5 = load i64, i64* %arrayidx, align 8
  %add = add i64 %5, %sub
  store i64 %add, i64* %arrayidx, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..51(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %rows, i32* dereferenceable(4) %cols, %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %level, i32** dereferenceable(8) %id_A, i32** dereferenceable(8) %id_B, i32* dereferenceable(4) %omp_within_a_box, double** dereferenceable(8) %C) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %rows.addr = alloca i32*, align 8
  %cols.addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %level.addr = alloca i32*, align 8
  %id_A.addr = alloca i32**, align 8
  %id_B.addr = alloca i32**, align 8
  %omp_within_a_box.addr = alloca i32*, align 8
  %C.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %mm = alloca i32, align 4
  %nn = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %mm13 = alloca i32, align 4
  %nn14 = alloca i32, align 4
  %mm15 = alloca i32, align 4
  %nn16 = alloca i32, align 4
  %box = alloca i32, align 4
  %a_dot_b_domain = alloca double, align 8
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %pencil = alloca i32, align 4
  %plane = alloca i32, align 4
  %ghosts = alloca i32, align 4
  %dim_k = alloca i32, align 4
  %dim_j = alloca i32, align 4
  %dim_i = alloca i32, align 4
  %grid_a = alloca double*, align 8
  %grid_b = alloca double*, align 8
  %a_dot_b_box = alloca double, align 8
  %.zero.addr = alloca i32, align 4
  store i32 0, i32* %.zero.addr, align 4
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %rows, i32** %rows.addr, align 8
  store i32* %cols, i32** %cols.addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store i32** %id_A, i32*** %id_A.addr, align 8
  store i32** %id_B, i32*** %id_B.addr, align 8
  store i32* %omp_within_a_box, i32** %omp_within_a_box.addr, align 8
  store double** %C, double*** %C.addr, align 8
  %0 = load i32*, i32** %rows.addr, align 8
  %1 = load i32*, i32** %cols.addr, align 8
  %2 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %3 = load i32*, i32** %level.addr, align 8
  %4 = load i32**, i32*** %id_A.addr, align 8
  %5 = load i32**, i32*** %id_B.addr, align 8
  %6 = load i32*, i32** %omp_within_a_box.addr, align 8
  %7 = load double**, double*** %C.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %9, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %mm, align 4
  store i32 0, i32* %nn, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %11
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 33, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  br label %omp.dispatch.cond

omp.dispatch.cond:                                ; preds = %omp.dispatch.inc, %omp.precond.then
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp17 = icmp sgt i64 %15, %16
  br i1 %cmp17, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.dispatch.cond
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.dispatch.cond
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp19 = icmp sle i64 %20, %21
  br i1 %cmp19, label %omp.dispatch.body, label %omp.dispatch.end

omp.dispatch.body:                                ; preds = %cond.end
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %omp.dispatch.body
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i64, i64* %.omp.ub, align 8
  %cmp21 = icmp sle i64 %22, %23
  br i1 %cmp21, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub23 = sub nsw i32 %25, 0
  %sub24 = sub nsw i32 %sub23, 1
  %add25 = add nsw i32 %sub24, 1
  %div26 = sdiv i32 %add25, 1
  %conv27 = sext i32 %div26 to i64
  %div28 = sdiv i64 %24, %conv27
  %mul29 = mul nsw i64 %div28, 1
  %add30 = add nsw i64 0, %mul29
  %conv31 = trunc i64 %add30 to i32
  store i32 %conv31, i32* %mm13, align 4
  %26 = load i64, i64* %.omp.iv, align 8
  %27 = load i32, i32* %1, align 4
  %sub32 = sub nsw i32 %27, 0
  %sub33 = sub nsw i32 %sub32, 1
  %add34 = add nsw i32 %sub33, 1
  %div35 = sdiv i32 %add34, 1
  %conv36 = sext i32 %div35 to i64
  %rem = srem i64 %26, %conv36
  %mul37 = mul nsw i64 %rem, 1
  %add38 = add nsw i64 0, %mul37
  %conv39 = trunc i64 %add38 to i32
  store i32 %conv39, i32* %nn14, align 4
  %28 = load i32, i32* %nn14, align 4
  %29 = load i32, i32* %mm13, align 4
  %cmp40 = icmp sge i32 %28, %29
  br i1 %cmp40, label %if.then, label %if.end128

if.then:                                          ; preds = %omp.inner.for.body
  store double 0.000000e+00, double* %a_dot_b_domain, align 8
  store i32 0, i32* %box, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.then
  %30 = load i32, i32* %box, align 4
  %31 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 19
  %32 = load i32, i32* %subdomains_per_rank, align 8
  %cmp42 = icmp slt i32 %30, %32
  br i1 %cmp42, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %33 = load i32, i32* %3, align 4
  %idxprom = sext i32 %33 to i64
  %34 = load i32, i32* %box, align 4
  %idxprom44 = sext i32 %34 to i64
  %35 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %35, i32 0, i32 25
  %36 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %36, i64 %idxprom44
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %37 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx45 = getelementptr inbounds %struct.box_type, %struct.box_type* %37, i64 %idxprom
  %pencil46 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx45, i32 0, i32 5
  %38 = load i32, i32* %pencil46, align 8
  store i32 %38, i32* %pencil, align 4
  %39 = load i32, i32* %3, align 4
  %idxprom47 = sext i32 %39 to i64
  %40 = load i32, i32* %box, align 4
  %idxprom48 = sext i32 %40 to i64
  %41 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains49 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %41, i32 0, i32 25
  %42 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains49, align 8
  %arrayidx50 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %42, i64 %idxprom48
  %levels51 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx50, i32 0, i32 5
  %43 = load %struct.box_type*, %struct.box_type** %levels51, align 8
  %arrayidx52 = getelementptr inbounds %struct.box_type, %struct.box_type* %43, i64 %idxprom47
  %plane53 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx52, i32 0, i32 6
  %44 = load i32, i32* %plane53, align 4
  store i32 %44, i32* %plane, align 4
  %45 = load i32, i32* %3, align 4
  %idxprom54 = sext i32 %45 to i64
  %46 = load i32, i32* %box, align 4
  %idxprom55 = sext i32 %46 to i64
  %47 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains56 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %47, i32 0, i32 25
  %48 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains56, align 8
  %arrayidx57 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %48, i64 %idxprom55
  %levels58 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx57, i32 0, i32 5
  %49 = load %struct.box_type*, %struct.box_type** %levels58, align 8
  %arrayidx59 = getelementptr inbounds %struct.box_type, %struct.box_type* %49, i64 %idxprom54
  %ghosts60 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx59, i32 0, i32 4
  %50 = load i32, i32* %ghosts60, align 4
  store i32 %50, i32* %ghosts, align 4
  %51 = load i32, i32* %3, align 4
  %idxprom61 = sext i32 %51 to i64
  %52 = load i32, i32* %box, align 4
  %idxprom62 = sext i32 %52 to i64
  %53 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains63 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %53, i32 0, i32 25
  %54 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains63, align 8
  %arrayidx64 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %54, i64 %idxprom62
  %levels65 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx64, i32 0, i32 5
  %55 = load %struct.box_type*, %struct.box_type** %levels65, align 8
  %arrayidx66 = getelementptr inbounds %struct.box_type, %struct.box_type* %55, i64 %idxprom61
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx66, i32 0, i32 2
  %k67 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %56 = load i32, i32* %k67, align 4
  store i32 %56, i32* %dim_k, align 4
  %57 = load i32, i32* %3, align 4
  %idxprom68 = sext i32 %57 to i64
  %58 = load i32, i32* %box, align 4
  %idxprom69 = sext i32 %58 to i64
  %59 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains70 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %59, i32 0, i32 25
  %60 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains70, align 8
  %arrayidx71 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %60, i64 %idxprom69
  %levels72 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx71, i32 0, i32 5
  %61 = load %struct.box_type*, %struct.box_type** %levels72, align 8
  %arrayidx73 = getelementptr inbounds %struct.box_type, %struct.box_type* %61, i64 %idxprom68
  %dim74 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx73, i32 0, i32 2
  %j75 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim74, i32 0, i32 1
  %62 = load i32, i32* %j75, align 4
  store i32 %62, i32* %dim_j, align 4
  %63 = load i32, i32* %3, align 4
  %idxprom76 = sext i32 %63 to i64
  %64 = load i32, i32* %box, align 4
  %idxprom77 = sext i32 %64 to i64
  %65 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains78 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %65, i32 0, i32 25
  %66 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains78, align 8
  %arrayidx79 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %66, i64 %idxprom77
  %levels80 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx79, i32 0, i32 5
  %67 = load %struct.box_type*, %struct.box_type** %levels80, align 8
  %arrayidx81 = getelementptr inbounds %struct.box_type, %struct.box_type* %67, i64 %idxprom76
  %dim82 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx81, i32 0, i32 2
  %i83 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim82, i32 0, i32 0
  %68 = load i32, i32* %i83, align 4
  store i32 %68, i32* %dim_i, align 4
  %69 = load i32, i32* %mm13, align 4
  %idxprom84 = sext i32 %69 to i64
  %70 = load i32*, i32** %4, align 8
  %arrayidx85 = getelementptr inbounds i32, i32* %70, i64 %idxprom84
  %71 = load i32, i32* %arrayidx85, align 4
  %idxprom86 = sext i32 %71 to i64
  %72 = load i32, i32* %3, align 4
  %idxprom87 = sext i32 %72 to i64
  %73 = load i32, i32* %box, align 4
  %idxprom88 = sext i32 %73 to i64
  %74 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains89 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %74, i32 0, i32 25
  %75 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains89, align 8
  %arrayidx90 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %75, i64 %idxprom88
  %levels91 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx90, i32 0, i32 5
  %76 = load %struct.box_type*, %struct.box_type** %levels91, align 8
  %arrayidx92 = getelementptr inbounds %struct.box_type, %struct.box_type* %76, i64 %idxprom87
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx92, i32 0, i32 10
  %77 = load double**, double*** %grids, align 8
  %arrayidx93 = getelementptr inbounds double*, double** %77, i64 %idxprom86
  %78 = load double*, double** %arrayidx93, align 8
  %79 = load i32, i32* %ghosts, align 4
  %80 = load i32, i32* %pencil, align 4
  %add94 = add nsw i32 1, %80
  %81 = load i32, i32* %plane, align 4
  %add95 = add nsw i32 %add94, %81
  %mul96 = mul nsw i32 %79, %add95
  %idx.ext = sext i32 %mul96 to i64
  %add.ptr = getelementptr inbounds double, double* %78, i64 %idx.ext
  store double* %add.ptr, double** %grid_a, align 8
  %82 = load i32, i32* %nn14, align 4
  %idxprom97 = sext i32 %82 to i64
  %83 = load i32*, i32** %5, align 8
  %arrayidx98 = getelementptr inbounds i32, i32* %83, i64 %idxprom97
  %84 = load i32, i32* %arrayidx98, align 4
  %idxprom99 = sext i32 %84 to i64
  %85 = load i32, i32* %3, align 4
  %idxprom100 = sext i32 %85 to i64
  %86 = load i32, i32* %box, align 4
  %idxprom101 = sext i32 %86 to i64
  %87 = load %struct.domain_type*, %struct.domain_type** %2, align 8
  %subdomains102 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %87, i32 0, i32 25
  %88 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains102, align 8
  %arrayidx103 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %88, i64 %idxprom101
  %levels104 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx103, i32 0, i32 5
  %89 = load %struct.box_type*, %struct.box_type** %levels104, align 8
  %arrayidx105 = getelementptr inbounds %struct.box_type, %struct.box_type* %89, i64 %idxprom100
  %grids106 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx105, i32 0, i32 10
  %90 = load double**, double*** %grids106, align 8
  %arrayidx107 = getelementptr inbounds double*, double** %90, i64 %idxprom99
  %91 = load double*, double** %arrayidx107, align 8
  %92 = load i32, i32* %ghosts, align 4
  %93 = load i32, i32* %pencil, align 4
  %add108 = add nsw i32 1, %93
  %94 = load i32, i32* %plane, align 4
  %add109 = add nsw i32 %add108, %94
  %mul110 = mul nsw i32 %92, %add109
  %idx.ext111 = sext i32 %mul110 to i64
  %add.ptr112 = getelementptr inbounds double, double* %91, i64 %idx.ext111
  store double* %add.ptr112, double** %grid_b, align 8
  store double 0.000000e+00, double* %a_dot_b_box, align 8
  %95 = load i32, i32* %6, align 4
  %tobool = icmp ne i32 %95, 0
  br i1 %tobool, label %omp_if.then, label %omp_if.else

omp_if.then:                                      ; preds = %for.body
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 8, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i32*, i32*, i32*, i32*, i32*, double*, double**, double**)* @.omp_outlined..52 to void (i32*, i32*, ...)*), i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %a_dot_b_box, double** %grid_a, double** %grid_b)
  br label %omp_if.end

omp_if.else:                                      ; preds = %for.body
  %96 = load i32*, i32** %.global_tid..addr, align 8
  %97 = load i32, i32* %96, align 4
  call void @__kmpc_serialized_parallel(%ident_t* @0, i32 %97)
  %98 = load i32*, i32** %.global_tid..addr, align 8
  call void @.omp_outlined..52(i32* %98, i32* %.zero.addr, i32* %dim_k, i32* %dim_j, i32* %dim_i, i32* %pencil, i32* %plane, double* %a_dot_b_box, double** %grid_a, double** %grid_b)
  call void @__kmpc_end_serialized_parallel(%ident_t* @0, i32 %97)
  br label %omp_if.end

omp_if.end:                                       ; preds = %omp_if.else, %omp_if.then
  %99 = load double, double* %a_dot_b_box, align 8
  %100 = load double, double* %a_dot_b_domain, align 8
  %add113 = fadd double %100, %99
  store double %add113, double* %a_dot_b_domain, align 8
  br label %for.inc

for.inc:                                          ; preds = %omp_if.end
  %101 = load i32, i32* %box, align 4
  %inc = add nsw i32 %101, 1
  store i32 %inc, i32* %box, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %102 = load double, double* %a_dot_b_domain, align 8
  %103 = load i32, i32* %mm13, align 4
  %104 = load i32, i32* %1, align 4
  %mul114 = mul nsw i32 %103, %104
  %105 = load i32, i32* %nn14, align 4
  %add115 = add nsw i32 %mul114, %105
  %idxprom116 = sext i32 %add115 to i64
  %106 = load double*, double** %7, align 8
  %arrayidx117 = getelementptr inbounds double, double* %106, i64 %idxprom116
  store double %102, double* %arrayidx117, align 8
  %107 = load i32, i32* %mm13, align 4
  %108 = load i32, i32* %1, align 4
  %cmp118 = icmp slt i32 %107, %108
  br i1 %cmp118, label %land.lhs.true120, label %if.end

land.lhs.true120:                                 ; preds = %for.end
  %109 = load i32, i32* %nn14, align 4
  %110 = load i32, i32* %0, align 4
  %cmp121 = icmp slt i32 %109, %110
  br i1 %cmp121, label %if.then123, label %if.end

if.then123:                                       ; preds = %land.lhs.true120
  %111 = load double, double* %a_dot_b_domain, align 8
  %112 = load i32, i32* %nn14, align 4
  %113 = load i32, i32* %1, align 4
  %mul124 = mul nsw i32 %112, %113
  %114 = load i32, i32* %mm13, align 4
  %add125 = add nsw i32 %mul124, %114
  %idxprom126 = sext i32 %add125 to i64
  %115 = load double*, double** %7, align 8
  %arrayidx127 = getelementptr inbounds double, double* %115, i64 %idxprom126
  store double %111, double* %arrayidx127, align 8
  br label %if.end

if.end:                                           ; preds = %if.then123, %land.lhs.true120, %for.end
  br label %if.end128

if.end128:                                        ; preds = %if.end, %omp.inner.for.body
  br label %omp.body.continue

omp.body.continue:                                ; preds = %if.end128
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %116 = load i64, i64* %.omp.iv, align 8
  %add129 = add nsw i64 %116, 1
  store i64 %add129, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.dispatch.inc

omp.dispatch.inc:                                 ; preds = %omp.inner.for.end
  %117 = load i64, i64* %.omp.lb, align 8
  %118 = load i64, i64* %.omp.stride, align 8
  %add130 = add nsw i64 %117, %118
  store i64 %add130, i64* %.omp.lb, align 8
  %119 = load i64, i64* %.omp.ub, align 8
  %120 = load i64, i64* %.omp.stride, align 8
  %add131 = add nsw i64 %119, %120
  store i64 %add131, i64* %.omp.ub, align 8
  br label %omp.dispatch.cond

omp.dispatch.end:                                 ; preds = %cond.end
  %121 = load i32*, i32** %.global_tid..addr, align 8
  %122 = load i32, i32* %121, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %122)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.dispatch.end, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..52(i32* noalias %.global_tid., i32* noalias %.bound_tid., i32* dereferenceable(4) %dim_k, i32* dereferenceable(4) %dim_j, i32* dereferenceable(4) %dim_i, i32* dereferenceable(4) %pencil, i32* dereferenceable(4) %plane, double* dereferenceable(8) %a_dot_b_box, double** dereferenceable(8) %grid_a, double** dereferenceable(8) %grid_b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %dim_k.addr = alloca i32*, align 8
  %dim_j.addr = alloca i32*, align 8
  %dim_i.addr = alloca i32*, align 8
  %pencil.addr = alloca i32*, align 8
  %plane.addr = alloca i32*, align 8
  %a_dot_b_box.addr = alloca double*, align 8
  %grid_a.addr = alloca double**, align 8
  %grid_b.addr = alloca double**, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %i = alloca i32, align 4
  %j13 = alloca i32, align 4
  %k14 = alloca i32, align 4
  %a_dot_b_box15 = alloca double, align 8
  %k16 = alloca i32, align 4
  %j17 = alloca i32, align 4
  %ijk = alloca i32, align 4
  %.omp.reduction.red_list = alloca [1 x i8*], align 8
  %atomic-temp = alloca double, align 8
  %tmp = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store i32* %dim_k, i32** %dim_k.addr, align 8
  store i32* %dim_j, i32** %dim_j.addr, align 8
  store i32* %dim_i, i32** %dim_i.addr, align 8
  store i32* %pencil, i32** %pencil.addr, align 8
  store i32* %plane, i32** %plane.addr, align 8
  store double* %a_dot_b_box, double** %a_dot_b_box.addr, align 8
  store double** %grid_a, double*** %grid_a.addr, align 8
  store double** %grid_b, double*** %grid_b.addr, align 8
  %0 = load i32*, i32** %dim_k.addr, align 8
  %1 = load i32*, i32** %dim_j.addr, align 8
  %2 = load i32*, i32** %dim_i.addr, align 8
  %3 = load i32*, i32** %pencil.addr, align 8
  %4 = load i32*, i32** %plane.addr, align 8
  %5 = load double*, double** %a_dot_b_box.addr, align 8
  %6 = load double**, double*** %grid_a.addr, align 8
  %7 = load double**, double*** %grid_b.addr, align 8
  %8 = load i32, i32* %0, align 4
  %sub = sub nsw i32 %8, 0
  %sub1 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub1, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %9 = load i32, i32* %1, align 4
  %sub2 = sub nsw i32 %9, 0
  %sub3 = sub nsw i32 %sub2, 1
  %add4 = add nsw i32 %sub3, 1
  %div5 = sdiv i32 %add4, 1
  %conv6 = sext i32 %div5 to i64
  %mul = mul nsw i64 %conv, %conv6
  %sub7 = sub nsw i64 %mul, 1
  store i64 %sub7, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k, align 4
  store i32 0, i32* %j, align 4
  %10 = load i32, i32* %0, align 4
  %cmp = icmp slt i32 0, %10
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %11 = load i32, i32* %1, align 4
  %cmp10 = icmp slt i32 0, %11
  br i1 %cmp10, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %12 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %12, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  store double 0.000000e+00, double* %a_dot_b_box15, align 8
  %13 = load i32*, i32** %.global_tid..addr, align 8
  %14 = load i32, i32* %13, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %14, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %15 = load i64, i64* %.omp.ub, align 8
  %16 = load i64, i64* %.omp.last.iteration, align 8
  %cmp18 = icmp sgt i64 %15, %16
  br i1 %cmp18, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %17 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %18 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %17, %cond.true ], [ %18, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %19 = load i64, i64* %.omp.lb, align 8
  store i64 %19, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %20 = load i64, i64* %.omp.iv, align 8
  %21 = load i64, i64* %.omp.ub, align 8
  %cmp20 = icmp sle i64 %20, %21
  br i1 %cmp20, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %22 = load i64, i64* %.omp.iv, align 8
  %23 = load i32, i32* %1, align 4
  %sub22 = sub nsw i32 %23, 0
  %sub23 = sub nsw i32 %sub22, 1
  %add24 = add nsw i32 %sub23, 1
  %div25 = sdiv i32 %add24, 1
  %conv26 = sext i32 %div25 to i64
  %div27 = sdiv i64 %22, %conv26
  %mul28 = mul nsw i64 %div27, 1
  %add29 = add nsw i64 0, %mul28
  %conv30 = trunc i64 %add29 to i32
  store i32 %conv30, i32* %k14, align 4
  %24 = load i64, i64* %.omp.iv, align 8
  %25 = load i32, i32* %1, align 4
  %sub31 = sub nsw i32 %25, 0
  %sub32 = sub nsw i32 %sub31, 1
  %add33 = add nsw i32 %sub32, 1
  %div34 = sdiv i32 %add33, 1
  %conv35 = sext i32 %div34 to i64
  %rem = srem i64 %24, %conv35
  %mul36 = mul nsw i64 %rem, 1
  %add37 = add nsw i64 0, %mul36
  %conv38 = trunc i64 %add37 to i32
  store i32 %conv38, i32* %j13, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %2, align 4
  %cmp39 = icmp slt i32 %26, %27
  br i1 %cmp39, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %28 = load i32, i32* %i, align 4
  %29 = load i32, i32* %j13, align 4
  %30 = load i32, i32* %3, align 4
  %mul41 = mul nsw i32 %29, %30
  %add42 = add nsw i32 %28, %mul41
  %31 = load i32, i32* %k14, align 4
  %32 = load i32, i32* %4, align 4
  %mul43 = mul nsw i32 %31, %32
  %add44 = add nsw i32 %add42, %mul43
  store i32 %add44, i32* %ijk, align 4
  %33 = load i32, i32* %ijk, align 4
  %idxprom = sext i32 %33 to i64
  %34 = load double*, double** %6, align 8
  %arrayidx = getelementptr inbounds double, double* %34, i64 %idxprom
  %35 = load double, double* %arrayidx, align 8
  %36 = load i32, i32* %ijk, align 4
  %idxprom45 = sext i32 %36 to i64
  %37 = load double*, double** %7, align 8
  %arrayidx46 = getelementptr inbounds double, double* %37, i64 %idxprom45
  %38 = load double, double* %arrayidx46, align 8
  %mul47 = fmul double %35, %38
  %39 = load double, double* %a_dot_b_box15, align 8
  %add48 = fadd double %39, %mul47
  store double %add48, double* %a_dot_b_box15, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %40 = load i32, i32* %i, align 4
  %inc = add nsw i32 %40, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %41 = load i64, i64* %.omp.iv, align 8
  %add49 = add nsw i64 %41, 1
  store i64 %add49, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %42 = load i32*, i32** %.global_tid..addr, align 8
  %43 = load i32, i32* %42, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %43)
  %44 = getelementptr inbounds [1 x i8*], [1 x i8*]* %.omp.reduction.red_list, i64 0, i64 0
  %45 = bitcast double* %a_dot_b_box15 to i8*
  store i8* %45, i8** %44, align 8
  %46 = load i32*, i32** %.global_tid..addr, align 8
  %47 = load i32, i32* %46, align 4
  %48 = bitcast [1 x i8*]* %.omp.reduction.red_list to i8*
  %49 = call i32 @__kmpc_reduce_nowait(%ident_t* @1, i32 %47, i32 1, i64 8, i8* %48, void (i8*, i8*)* @.omp.reduction.reduction_func.53, [8 x i32]* @.gomp_critical_user_.reduction.var)
  switch i32 %49, label %.omp.reduction.default [
    i32 1, label %.omp.reduction.case1
    i32 2, label %.omp.reduction.case2
  ]

.omp.reduction.case1:                             ; preds = %omp.loop.exit
  %50 = load double, double* %5, align 8
  %51 = load double, double* %a_dot_b_box15, align 8
  %add50 = fadd double %50, %51
  store double %add50, double* %5, align 8
  call void @__kmpc_end_reduce_nowait(%ident_t* @1, i32 %47, [8 x i32]* @.gomp_critical_user_.reduction.var)
  br label %.omp.reduction.default

.omp.reduction.case2:                             ; preds = %omp.loop.exit
  %52 = load double, double* %a_dot_b_box15, align 8
  %53 = bitcast double* %5 to i64*
  %atomic-load = load atomic i64, i64* %53 monotonic, align 8
  br label %atomic_cont

atomic_cont:                                      ; preds = %atomic_cont, %.omp.reduction.case2
  %54 = phi i64 [ %atomic-load, %.omp.reduction.case2 ], [ %62, %atomic_cont ]
  %55 = bitcast double* %atomic-temp to i64*
  %56 = bitcast i64 %54 to double
  store double %56, double* %tmp, align 8
  %57 = load double, double* %tmp, align 8
  %58 = load double, double* %a_dot_b_box15, align 8
  %add51 = fadd double %57, %58
  store double %add51, double* %atomic-temp, align 8
  %59 = load i64, i64* %55, align 8
  %60 = bitcast double* %5 to i64*
  %61 = cmpxchg i64* %60, i64 %54, i64 %59 monotonic monotonic
  %62 = extractvalue { i64, i1 } %61, 0
  %63 = extractvalue { i64, i1 } %61, 1
  br i1 %63, label %atomic_exit, label %atomic_cont

atomic_exit:                                      ; preds = %atomic_cont
  br label %.omp.reduction.default

.omp.reduction.default:                           ; preds = %atomic_exit, %.omp.reduction.case1, %omp.loop.exit
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %.omp.reduction.default, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp.reduction.reduction_func.53(i8*, i8*) #0 {
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
  %8 = bitcast i8* %7 to double*
  %9 = getelementptr inbounds [1 x i8*], [1 x i8*]* %3, i64 0, i64 0
  %10 = load i8*, i8** %9, align 8
  %11 = bitcast i8* %10 to double*
  %12 = load double, double* %11, align 8
  %13 = load double, double* %8, align 8
  %add = fadd double %12, %13
  store double %add, double* %11, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @initialize_problem(%struct.domain_type* %domain, i32 %level, double %hLevel, double %a, double %b) #0 {
entry:
  %domain.addr = alloca %struct.domain_type*, align 8
  %level.addr = alloca i32, align 4
  %hLevel.addr = alloca double, align 8
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %NPi = alloca double, align 8
  %Bmin = alloca double, align 8
  %Bmax = alloca double, align 8
  %c2 = alloca double, align 8
  %c1 = alloca double, align 8
  %c3 = alloca double, align 8
  %c4 = alloca double, align 8
  %box = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %average_value_of_f = alloca double, align 8
  store %struct.domain_type* %domain, %struct.domain_type** %domain.addr, align 8
  store i32 %level, i32* %level.addr, align 4
  store double %hLevel, double* %hLevel.addr, align 8
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  store double 0x401921FB54442D18, double* %NPi, align 8
  store double 1.000000e+00, double* %Bmin, align 8
  store double 1.000000e+01, double* %Bmax, align 8
  %0 = load double, double* %Bmax, align 8
  %1 = load double, double* %Bmin, align 8
  %sub = fsub double %0, %1
  %div = fdiv double %sub, 2.000000e+00
  store double %div, double* %c2, align 8
  %2 = load double, double* %Bmax, align 8
  %3 = load double, double* %Bmin, align 8
  %add = fadd double %2, %3
  %div1 = fdiv double %add, 2.000000e+00
  store double %div1, double* %c1, align 8
  store double 1.000000e+01, double* %c3, align 8
  store double -2.000000e+01, double* %c4, align 8
  store i32 0, i32* %box, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %4 = load i32, i32* %box, align 4
  %5 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains_per_rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %5, i32 0, i32 19
  %6 = load i32, i32* %subdomains_per_rank, align 8
  %cmp = icmp slt i32 %4, %6
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %7 = load i32, i32* %level.addr, align 4
  %idxprom = sext i32 %7 to i64
  %8 = load i32, i32* %box, align 4
  %idxprom2 = sext i32 %8 to i64
  %9 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %9, i32 0, i32 25
  %10 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %10, i64 %idxprom2
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %11 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx3 = getelementptr inbounds %struct.box_type, %struct.box_type* %11, i64 %idxprom
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx3, i32 0, i32 10
  %12 = load double**, double*** %grids, align 8
  %arrayidx4 = getelementptr inbounds double*, double** %12, i64 11
  %13 = load double*, double** %arrayidx4, align 8
  %14 = bitcast double* %13 to i8*
  %15 = load i32, i32* %level.addr, align 4
  %idxprom5 = sext i32 %15 to i64
  %16 = load i32, i32* %box, align 4
  %idxprom6 = sext i32 %16 to i64
  %17 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains7 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %17, i32 0, i32 25
  %18 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains7, align 8
  %arrayidx8 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %18, i64 %idxprom6
  %levels9 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx8, i32 0, i32 5
  %19 = load %struct.box_type*, %struct.box_type** %levels9, align 8
  %arrayidx10 = getelementptr inbounds %struct.box_type, %struct.box_type* %19, i64 %idxprom5
  %volume = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx10, i32 0, i32 7
  %20 = load i32, i32* %volume, align 8
  %conv = sext i32 %20 to i64
  %mul = mul i64 %conv, 8
  call void @llvm.memset.p0i8.i64(i8* %14, i8 0, i64 %mul, i32 8, i1 false)
  %21 = load i32, i32* %level.addr, align 4
  %idxprom11 = sext i32 %21 to i64
  %22 = load i32, i32* %box, align 4
  %idxprom12 = sext i32 %22 to i64
  %23 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains13 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %23, i32 0, i32 25
  %24 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains13, align 8
  %arrayidx14 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %24, i64 %idxprom12
  %levels15 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx14, i32 0, i32 5
  %25 = load %struct.box_type*, %struct.box_type** %levels15, align 8
  %arrayidx16 = getelementptr inbounds %struct.box_type, %struct.box_type* %25, i64 %idxprom11
  %grids17 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx16, i32 0, i32 10
  %26 = load double**, double*** %grids17, align 8
  %arrayidx18 = getelementptr inbounds double*, double** %26, i64 1
  %27 = load double*, double** %arrayidx18, align 8
  %28 = bitcast double* %27 to i8*
  %29 = load i32, i32* %level.addr, align 4
  %idxprom19 = sext i32 %29 to i64
  %30 = load i32, i32* %box, align 4
  %idxprom20 = sext i32 %30 to i64
  %31 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 25
  %32 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %32, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %33 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %33, i64 %idxprom19
  %volume25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 7
  %34 = load i32, i32* %volume25, align 8
  %conv26 = sext i32 %34 to i64
  %mul27 = mul i64 %conv26, 8
  call void @llvm.memset.p0i8.i64(i8* %28, i8 0, i64 %mul27, i32 8, i1 false)
  call void (%ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%ident_t* @0, i32 11, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.domain_type**, i32*, i32*, double*, double*, double*, double*, double*, double*, double*, double*)* @.omp_outlined..54 to void (i32*, i32*, ...)*), %struct.domain_type** %domain.addr, i32* %box, i32* %level.addr, double* %hLevel.addr, double* %c1, double* %c2, double* %c3, double* %c4, double* %NPi, double* %a.addr, double* %b.addr)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %35 = load i32, i32* %box, align 4
  %inc = add nsw i32 %35, 1
  store i32 %inc, i32* %box, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %36 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %37 = load i32, i32* %level.addr, align 4
  %call = call double @mean(%struct.domain_type* %36, i32 %37, i32 1)
  store double %call, double* %average_value_of_f, align 8
  %38 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %rank = getelementptr inbounds %struct.domain_type, %struct.domain_type* %38, i32 0, i32 18
  %39 = load i32, i32* %rank, align 4
  %cmp28 = icmp eq i32 %39, 0
  br i1 %cmp28, label %if.then, label %if.end

if.then:                                          ; preds = %for.end
  %40 = load double, double* %average_value_of_f, align 8
  %call30 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.55, i32 0, i32 0), double %40)
  %41 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 8
  %call31 = call i32 @fflush(%struct._IO_FILE* %41)
  br label %if.end

if.end:                                           ; preds = %if.then, %for.end
  %42 = load double, double* %a.addr, align 8
  %cmp32 = fcmp une double %42, 0.000000e+00
  br i1 %cmp32, label %if.then34, label %if.end38

if.then34:                                        ; preds = %if.end
  %43 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %44 = load i32, i32* %level.addr, align 4
  %45 = load double, double* %average_value_of_f, align 8
  %sub35 = fsub double -0.000000e+00, %45
  call void @shift_grid(%struct.domain_type* %43, i32 %44, i32 1, i32 1, double %sub35)
  %46 = load %struct.domain_type*, %struct.domain_type** %domain.addr, align 8
  %47 = load i32, i32* %level.addr, align 4
  %48 = load double, double* %average_value_of_f, align 8
  %sub36 = fsub double -0.000000e+00, %48
  %49 = load double, double* %a.addr, align 8
  %div37 = fdiv double %sub36, %49
  call void @shift_grid(%struct.domain_type* %46, i32 %47, i32 11, i32 11, double %div37)
  br label %if.end38

if.end38:                                         ; preds = %if.then34, %if.end
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @.omp_outlined..54(i32* noalias %.global_tid., i32* noalias %.bound_tid., %struct.domain_type** dereferenceable(8) %domain, i32* dereferenceable(4) %box, i32* dereferenceable(4) %level, double* dereferenceable(8) %hLevel, double* dereferenceable(8) %c1, double* dereferenceable(8) %c2, double* dereferenceable(8) %c3, double* dereferenceable(8) %c4, double* dereferenceable(8) %NPi, double* dereferenceable(8) %a, double* dereferenceable(8) %b) #0 {
entry:
  %.global_tid..addr = alloca i32*, align 8
  %.bound_tid..addr = alloca i32*, align 8
  %domain.addr = alloca %struct.domain_type**, align 8
  %box.addr = alloca i32*, align 8
  %level.addr = alloca i32*, align 8
  %hLevel.addr = alloca double*, align 8
  %c1.addr = alloca double*, align 8
  %c2.addr = alloca double*, align 8
  %c3.addr = alloca double*, align 8
  %c4.addr = alloca double*, align 8
  %NPi.addr = alloca double*, align 8
  %a.addr = alloca double*, align 8
  %b.addr = alloca double*, align 8
  %.omp.iv = alloca i64, align 8
  %.omp.last.iteration = alloca i64, align 8
  %k17 = alloca i32, align 4
  %j18 = alloca i32, align 4
  %.omp.lb = alloca i64, align 8
  %.omp.ub = alloca i64, align 8
  %.omp.stride = alloca i64, align 8
  %.omp.is_last = alloca i32, align 4
  %k40 = alloca i32, align 4
  %j41 = alloca i32, align 4
  %i = alloca i32, align 4
  %k42 = alloca i32, align 4
  %j43 = alloca i32, align 4
  %x = alloca double, align 8
  %y = alloca double, align 8
  %z = alloca double, align 8
  %ijk = alloca i32, align 4
  %r2 = alloca double, align 8
  %r2x = alloca double, align 8
  %r2y = alloca double, align 8
  %r2z = alloca double, align 8
  %r2xx = alloca double, align 8
  %r2yy = alloca double, align 8
  %r2zz = alloca double, align 8
  %r = alloca double, align 8
  %rx = alloca double, align 8
  %ry = alloca double, align 8
  %rz = alloca double, align 8
  %rxx = alloca double, align 8
  %ryy = alloca double, align 8
  %rzz = alloca double, align 8
  %A = alloca double, align 8
  %B = alloca double, align 8
  %Bx = alloca double, align 8
  %By = alloca double, align 8
  %Bz = alloca double, align 8
  %u = alloca double, align 8
  %ux = alloca double, align 8
  %uy = alloca double, align 8
  %uz = alloca double, align 8
  %uxx = alloca double, align 8
  %uyy = alloca double, align 8
  %uzz = alloca double, align 8
  %f = alloca double, align 8
  store i32* %.global_tid., i32** %.global_tid..addr, align 8
  store i32* %.bound_tid., i32** %.bound_tid..addr, align 8
  store %struct.domain_type** %domain, %struct.domain_type*** %domain.addr, align 8
  store i32* %box, i32** %box.addr, align 8
  store i32* %level, i32** %level.addr, align 8
  store double* %hLevel, double** %hLevel.addr, align 8
  store double* %c1, double** %c1.addr, align 8
  store double* %c2, double** %c2.addr, align 8
  store double* %c3, double** %c3.addr, align 8
  store double* %c4, double** %c4.addr, align 8
  store double* %NPi, double** %NPi.addr, align 8
  store double* %a, double** %a.addr, align 8
  store double* %b, double** %b.addr, align 8
  %0 = load %struct.domain_type**, %struct.domain_type*** %domain.addr, align 8
  %1 = load i32*, i32** %box.addr, align 8
  %2 = load i32*, i32** %level.addr, align 8
  %3 = load double*, double** %hLevel.addr, align 8
  %4 = load double*, double** %c1.addr, align 8
  %5 = load double*, double** %c2.addr, align 8
  %6 = load double*, double** %c3.addr, align 8
  %7 = load double*, double** %c4.addr, align 8
  %8 = load double*, double** %NPi.addr, align 8
  %9 = load double*, double** %a.addr, align 8
  %10 = load double*, double** %b.addr, align 8
  %11 = load i32, i32* %2, align 4
  %idxprom = sext i32 %11 to i64
  %12 = load i32, i32* %1, align 4
  %idxprom1 = sext i32 %12 to i64
  %13 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains = getelementptr inbounds %struct.domain_type, %struct.domain_type* %13, i32 0, i32 25
  %14 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains, align 8
  %arrayidx = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %14, i64 %idxprom1
  %levels = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx, i32 0, i32 5
  %15 = load %struct.box_type*, %struct.box_type** %levels, align 8
  %arrayidx2 = getelementptr inbounds %struct.box_type, %struct.box_type* %15, i64 %idxprom
  %dim = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx2, i32 0, i32 2
  %k = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim, i32 0, i32 2
  %16 = load i32, i32* %k, align 4
  %sub = sub nsw i32 %16, 0
  %sub3 = sub nsw i32 %sub, 1
  %add = add nsw i32 %sub3, 1
  %div = sdiv i32 %add, 1
  %conv = sext i32 %div to i64
  %17 = load i32, i32* %2, align 4
  %idxprom4 = sext i32 %17 to i64
  %18 = load i32, i32* %1, align 4
  %idxprom5 = sext i32 %18 to i64
  %19 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains6 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %19, i32 0, i32 25
  %20 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains6, align 8
  %arrayidx7 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %20, i64 %idxprom5
  %levels8 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx7, i32 0, i32 5
  %21 = load %struct.box_type*, %struct.box_type** %levels8, align 8
  %arrayidx9 = getelementptr inbounds %struct.box_type, %struct.box_type* %21, i64 %idxprom4
  %dim10 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx9, i32 0, i32 2
  %j = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim10, i32 0, i32 1
  %22 = load i32, i32* %j, align 4
  %sub11 = sub nsw i32 %22, 0
  %sub12 = sub nsw i32 %sub11, 1
  %add13 = add nsw i32 %sub12, 1
  %div14 = sdiv i32 %add13, 1
  %conv15 = sext i32 %div14 to i64
  %mul = mul nsw i64 %conv, %conv15
  %sub16 = sub nsw i64 %mul, 1
  store i64 %sub16, i64* %.omp.last.iteration, align 8
  store i32 0, i32* %k17, align 4
  store i32 0, i32* %j18, align 4
  %23 = load i32, i32* %2, align 4
  %idxprom19 = sext i32 %23 to i64
  %24 = load i32, i32* %1, align 4
  %idxprom20 = sext i32 %24 to i64
  %25 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains21 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %25, i32 0, i32 25
  %26 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains21, align 8
  %arrayidx22 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %26, i64 %idxprom20
  %levels23 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx22, i32 0, i32 5
  %27 = load %struct.box_type*, %struct.box_type** %levels23, align 8
  %arrayidx24 = getelementptr inbounds %struct.box_type, %struct.box_type* %27, i64 %idxprom19
  %dim25 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx24, i32 0, i32 2
  %k26 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim25, i32 0, i32 2
  %28 = load i32, i32* %k26, align 4
  %cmp = icmp slt i32 0, %28
  br i1 %cmp, label %land.lhs.true, label %omp.precond.end

land.lhs.true:                                    ; preds = %entry
  %29 = load i32, i32* %2, align 4
  %idxprom29 = sext i32 %29 to i64
  %30 = load i32, i32* %1, align 4
  %idxprom30 = sext i32 %30 to i64
  %31 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains31 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %31, i32 0, i32 25
  %32 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains31, align 8
  %arrayidx32 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %32, i64 %idxprom30
  %levels33 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx32, i32 0, i32 5
  %33 = load %struct.box_type*, %struct.box_type** %levels33, align 8
  %arrayidx34 = getelementptr inbounds %struct.box_type, %struct.box_type* %33, i64 %idxprom29
  %dim35 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx34, i32 0, i32 2
  %j36 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim35, i32 0, i32 1
  %34 = load i32, i32* %j36, align 4
  %cmp37 = icmp slt i32 0, %34
  br i1 %cmp37, label %omp.precond.then, label %omp.precond.end

omp.precond.then:                                 ; preds = %land.lhs.true
  store i64 0, i64* %.omp.lb, align 8
  %35 = load i64, i64* %.omp.last.iteration, align 8
  store i64 %35, i64* %.omp.ub, align 8
  store i64 1, i64* %.omp.stride, align 8
  store i32 0, i32* %.omp.is_last, align 4
  %36 = load i32*, i32** %.global_tid..addr, align 8
  %37 = load i32, i32* %36, align 4
  call void @__kmpc_for_static_init_8(%ident_t* @0, i32 %37, i32 34, i32* %.omp.is_last, i64* %.omp.lb, i64* %.omp.ub, i64* %.omp.stride, i64 1, i64 1)
  %38 = load i64, i64* %.omp.ub, align 8
  %39 = load i64, i64* %.omp.last.iteration, align 8
  %cmp44 = icmp sgt i64 %38, %39
  br i1 %cmp44, label %cond.true, label %cond.false

cond.true:                                        ; preds = %omp.precond.then
  %40 = load i64, i64* %.omp.last.iteration, align 8
  br label %cond.end

cond.false:                                       ; preds = %omp.precond.then
  %41 = load i64, i64* %.omp.ub, align 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ %40, %cond.true ], [ %41, %cond.false ]
  store i64 %cond, i64* %.omp.ub, align 8
  %42 = load i64, i64* %.omp.lb, align 8
  store i64 %42, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.cond:                               ; preds = %omp.inner.for.inc, %cond.end
  %43 = load i64, i64* %.omp.iv, align 8
  %44 = load i64, i64* %.omp.ub, align 8
  %cmp46 = icmp sle i64 %43, %44
  br i1 %cmp46, label %omp.inner.for.body, label %omp.inner.for.end

omp.inner.for.body:                               ; preds = %omp.inner.for.cond
  %45 = load i64, i64* %.omp.iv, align 8
  %46 = load i32, i32* %2, align 4
  %idxprom48 = sext i32 %46 to i64
  %47 = load i32, i32* %1, align 4
  %idxprom49 = sext i32 %47 to i64
  %48 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains50 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %48, i32 0, i32 25
  %49 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains50, align 8
  %arrayidx51 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %49, i64 %idxprom49
  %levels52 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx51, i32 0, i32 5
  %50 = load %struct.box_type*, %struct.box_type** %levels52, align 8
  %arrayidx53 = getelementptr inbounds %struct.box_type, %struct.box_type* %50, i64 %idxprom48
  %dim54 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx53, i32 0, i32 2
  %j55 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim54, i32 0, i32 1
  %51 = load i32, i32* %j55, align 4
  %sub56 = sub nsw i32 %51, 0
  %sub57 = sub nsw i32 %sub56, 1
  %add58 = add nsw i32 %sub57, 1
  %div59 = sdiv i32 %add58, 1
  %conv60 = sext i32 %div59 to i64
  %div61 = sdiv i64 %45, %conv60
  %mul62 = mul nsw i64 %div61, 1
  %add63 = add nsw i64 0, %mul62
  %conv64 = trunc i64 %add63 to i32
  store i32 %conv64, i32* %k40, align 4
  %52 = load i64, i64* %.omp.iv, align 8
  %53 = load i32, i32* %2, align 4
  %idxprom65 = sext i32 %53 to i64
  %54 = load i32, i32* %1, align 4
  %idxprom66 = sext i32 %54 to i64
  %55 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains67 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %55, i32 0, i32 25
  %56 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains67, align 8
  %arrayidx68 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %56, i64 %idxprom66
  %levels69 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx68, i32 0, i32 5
  %57 = load %struct.box_type*, %struct.box_type** %levels69, align 8
  %arrayidx70 = getelementptr inbounds %struct.box_type, %struct.box_type* %57, i64 %idxprom65
  %dim71 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx70, i32 0, i32 2
  %j72 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim71, i32 0, i32 1
  %58 = load i32, i32* %j72, align 4
  %sub73 = sub nsw i32 %58, 0
  %sub74 = sub nsw i32 %sub73, 1
  %add75 = add nsw i32 %sub74, 1
  %div76 = sdiv i32 %add75, 1
  %conv77 = sext i32 %div76 to i64
  %rem = srem i64 %52, %conv77
  %mul78 = mul nsw i64 %rem, 1
  %add79 = add nsw i64 0, %mul78
  %conv80 = trunc i64 %add79 to i32
  store i32 %conv80, i32* %j41, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %omp.inner.for.body
  %59 = load i32, i32* %i, align 4
  %60 = load i32, i32* %2, align 4
  %idxprom81 = sext i32 %60 to i64
  %61 = load i32, i32* %1, align 4
  %idxprom82 = sext i32 %61 to i64
  %62 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains83 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %62, i32 0, i32 25
  %63 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains83, align 8
  %arrayidx84 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %63, i64 %idxprom82
  %levels85 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx84, i32 0, i32 5
  %64 = load %struct.box_type*, %struct.box_type** %levels85, align 8
  %arrayidx86 = getelementptr inbounds %struct.box_type, %struct.box_type* %64, i64 %idxprom81
  %dim87 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx86, i32 0, i32 2
  %i88 = getelementptr inbounds %struct.anon.10, %struct.anon.10* %dim87, i32 0, i32 0
  %65 = load i32, i32* %i88, align 4
  %cmp89 = icmp slt i32 %59, %65
  br i1 %cmp89, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %66 = load double, double* %3, align 8
  %67 = load i32, i32* %i, align 4
  %68 = load i32, i32* %2, align 4
  %idxprom91 = sext i32 %68 to i64
  %69 = load i32, i32* %1, align 4
  %idxprom92 = sext i32 %69 to i64
  %70 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains93 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %70, i32 0, i32 25
  %71 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains93, align 8
  %arrayidx94 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %71, i64 %idxprom92
  %levels95 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx94, i32 0, i32 5
  %72 = load %struct.box_type*, %struct.box_type** %levels95, align 8
  %arrayidx96 = getelementptr inbounds %struct.box_type, %struct.box_type* %72, i64 %idxprom91
  %low = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx96, i32 0, i32 1
  %i97 = getelementptr inbounds %struct.anon.9, %struct.anon.9* %low, i32 0, i32 0
  %73 = load i32, i32* %i97, align 8
  %add98 = add nsw i32 %67, %73
  %conv99 = sitofp i32 %add98 to double
  %add100 = fadd double %conv99, 5.000000e-01
  %mul101 = fmul double %66, %add100
  store double %mul101, double* %x, align 8
  %74 = load double, double* %3, align 8
  %75 = load i32, i32* %j41, align 4
  %76 = load i32, i32* %2, align 4
  %idxprom102 = sext i32 %76 to i64
  %77 = load i32, i32* %1, align 4
  %idxprom103 = sext i32 %77 to i64
  %78 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains104 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %78, i32 0, i32 25
  %79 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains104, align 8
  %arrayidx105 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %79, i64 %idxprom103
  %levels106 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx105, i32 0, i32 5
  %80 = load %struct.box_type*, %struct.box_type** %levels106, align 8
  %arrayidx107 = getelementptr inbounds %struct.box_type, %struct.box_type* %80, i64 %idxprom102
  %low108 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx107, i32 0, i32 1
  %j109 = getelementptr inbounds %struct.anon.9, %struct.anon.9* %low108, i32 0, i32 1
  %81 = load i32, i32* %j109, align 4
  %add110 = add nsw i32 %75, %81
  %conv111 = sitofp i32 %add110 to double
  %add112 = fadd double %conv111, 5.000000e-01
  %mul113 = fmul double %74, %add112
  store double %mul113, double* %y, align 8
  %82 = load double, double* %3, align 8
  %83 = load i32, i32* %k40, align 4
  %84 = load i32, i32* %2, align 4
  %idxprom114 = sext i32 %84 to i64
  %85 = load i32, i32* %1, align 4
  %idxprom115 = sext i32 %85 to i64
  %86 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains116 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %86, i32 0, i32 25
  %87 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains116, align 8
  %arrayidx117 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %87, i64 %idxprom115
  %levels118 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx117, i32 0, i32 5
  %88 = load %struct.box_type*, %struct.box_type** %levels118, align 8
  %arrayidx119 = getelementptr inbounds %struct.box_type, %struct.box_type* %88, i64 %idxprom114
  %low120 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx119, i32 0, i32 1
  %k121 = getelementptr inbounds %struct.anon.9, %struct.anon.9* %low120, i32 0, i32 2
  %89 = load i32, i32* %k121, align 8
  %add122 = add nsw i32 %83, %89
  %conv123 = sitofp i32 %add122 to double
  %add124 = fadd double %conv123, 5.000000e-01
  %mul125 = fmul double %82, %add124
  store double %mul125, double* %z, align 8
  %90 = load i32, i32* %i, align 4
  %91 = load i32, i32* %2, align 4
  %idxprom126 = sext i32 %91 to i64
  %92 = load i32, i32* %1, align 4
  %idxprom127 = sext i32 %92 to i64
  %93 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains128 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %93, i32 0, i32 25
  %94 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains128, align 8
  %arrayidx129 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %94, i64 %idxprom127
  %levels130 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx129, i32 0, i32 5
  %95 = load %struct.box_type*, %struct.box_type** %levels130, align 8
  %arrayidx131 = getelementptr inbounds %struct.box_type, %struct.box_type* %95, i64 %idxprom126
  %ghosts = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx131, i32 0, i32 4
  %96 = load i32, i32* %ghosts, align 4
  %add132 = add nsw i32 %90, %96
  %97 = load i32, i32* %2, align 4
  %idxprom133 = sext i32 %97 to i64
  %98 = load i32, i32* %1, align 4
  %idxprom134 = sext i32 %98 to i64
  %99 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains135 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %99, i32 0, i32 25
  %100 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains135, align 8
  %arrayidx136 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %100, i64 %idxprom134
  %levels137 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx136, i32 0, i32 5
  %101 = load %struct.box_type*, %struct.box_type** %levels137, align 8
  %arrayidx138 = getelementptr inbounds %struct.box_type, %struct.box_type* %101, i64 %idxprom133
  %pencil = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx138, i32 0, i32 5
  %102 = load i32, i32* %pencil, align 8
  %103 = load i32, i32* %j41, align 4
  %104 = load i32, i32* %2, align 4
  %idxprom139 = sext i32 %104 to i64
  %105 = load i32, i32* %1, align 4
  %idxprom140 = sext i32 %105 to i64
  %106 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains141 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %106, i32 0, i32 25
  %107 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains141, align 8
  %arrayidx142 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %107, i64 %idxprom140
  %levels143 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx142, i32 0, i32 5
  %108 = load %struct.box_type*, %struct.box_type** %levels143, align 8
  %arrayidx144 = getelementptr inbounds %struct.box_type, %struct.box_type* %108, i64 %idxprom139
  %ghosts145 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx144, i32 0, i32 4
  %109 = load i32, i32* %ghosts145, align 4
  %add146 = add nsw i32 %103, %109
  %mul147 = mul nsw i32 %102, %add146
  %add148 = add nsw i32 %add132, %mul147
  %110 = load i32, i32* %2, align 4
  %idxprom149 = sext i32 %110 to i64
  %111 = load i32, i32* %1, align 4
  %idxprom150 = sext i32 %111 to i64
  %112 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains151 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %112, i32 0, i32 25
  %113 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains151, align 8
  %arrayidx152 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %113, i64 %idxprom150
  %levels153 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx152, i32 0, i32 5
  %114 = load %struct.box_type*, %struct.box_type** %levels153, align 8
  %arrayidx154 = getelementptr inbounds %struct.box_type, %struct.box_type* %114, i64 %idxprom149
  %plane = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx154, i32 0, i32 6
  %115 = load i32, i32* %plane, align 4
  %116 = load i32, i32* %k40, align 4
  %117 = load i32, i32* %2, align 4
  %idxprom155 = sext i32 %117 to i64
  %118 = load i32, i32* %1, align 4
  %idxprom156 = sext i32 %118 to i64
  %119 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains157 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %119, i32 0, i32 25
  %120 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains157, align 8
  %arrayidx158 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %120, i64 %idxprom156
  %levels159 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx158, i32 0, i32 5
  %121 = load %struct.box_type*, %struct.box_type** %levels159, align 8
  %arrayidx160 = getelementptr inbounds %struct.box_type, %struct.box_type* %121, i64 %idxprom155
  %ghosts161 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx160, i32 0, i32 4
  %122 = load i32, i32* %ghosts161, align 4
  %add162 = add nsw i32 %116, %122
  %mul163 = mul nsw i32 %115, %add162
  %add164 = add nsw i32 %add148, %mul163
  store i32 %add164, i32* %ijk, align 4
  %123 = load double, double* %x, align 8
  %sub165 = fsub double %123, 5.000000e-01
  %call = call double @pow(double %sub165, double 2.000000e+00) #7
  %124 = load double, double* %y, align 8
  %sub166 = fsub double %124, 5.000000e-01
  %call167 = call double @pow(double %sub166, double 2.000000e+00) #7
  %add168 = fadd double %call, %call167
  %125 = load double, double* %z, align 8
  %sub169 = fsub double %125, 5.000000e-01
  %call170 = call double @pow(double %sub169, double 2.000000e+00) #7
  %add171 = fadd double %add168, %call170
  store double %add171, double* %r2, align 8
  %126 = load double, double* %x, align 8
  %sub172 = fsub double %126, 5.000000e-01
  %mul173 = fmul double 2.000000e+00, %sub172
  store double %mul173, double* %r2x, align 8
  %127 = load double, double* %y, align 8
  %sub174 = fsub double %127, 5.000000e-01
  %mul175 = fmul double 2.000000e+00, %sub174
  store double %mul175, double* %r2y, align 8
  %128 = load double, double* %z, align 8
  %sub176 = fsub double %128, 5.000000e-01
  %mul177 = fmul double 2.000000e+00, %sub176
  store double %mul177, double* %r2z, align 8
  store double 2.000000e+00, double* %r2xx, align 8
  store double 2.000000e+00, double* %r2yy, align 8
  store double 2.000000e+00, double* %r2zz, align 8
  %129 = load double, double* %r2, align 8
  %call178 = call double @pow(double %129, double 5.000000e-01) #7
  store double %call178, double* %r, align 8
  %130 = load double, double* %r2x, align 8
  %mul179 = fmul double 5.000000e-01, %130
  %131 = load double, double* %r2, align 8
  %call180 = call double @pow(double %131, double -5.000000e-01) #7
  %mul181 = fmul double %mul179, %call180
  store double %mul181, double* %rx, align 8
  %132 = load double, double* %r2y, align 8
  %mul182 = fmul double 5.000000e-01, %132
  %133 = load double, double* %r2, align 8
  %call183 = call double @pow(double %133, double -5.000000e-01) #7
  %mul184 = fmul double %mul182, %call183
  store double %mul184, double* %ry, align 8
  %134 = load double, double* %r2z, align 8
  %mul185 = fmul double 5.000000e-01, %134
  %135 = load double, double* %r2, align 8
  %call186 = call double @pow(double %135, double -5.000000e-01) #7
  %mul187 = fmul double %mul185, %call186
  store double %mul187, double* %rz, align 8
  %136 = load double, double* %r2xx, align 8
  %mul188 = fmul double 5.000000e-01, %136
  %137 = load double, double* %r2, align 8
  %call189 = call double @pow(double %137, double -5.000000e-01) #7
  %mul190 = fmul double %mul188, %call189
  %138 = load double, double* %r2x, align 8
  %mul191 = fmul double 2.500000e-01, %138
  %139 = load double, double* %r2x, align 8
  %mul192 = fmul double %mul191, %139
  %140 = load double, double* %r2, align 8
  %call193 = call double @pow(double %140, double -1.500000e+00) #7
  %mul194 = fmul double %mul192, %call193
  %sub195 = fsub double %mul190, %mul194
  store double %sub195, double* %rxx, align 8
  %141 = load double, double* %r2yy, align 8
  %mul196 = fmul double 5.000000e-01, %141
  %142 = load double, double* %r2, align 8
  %call197 = call double @pow(double %142, double -5.000000e-01) #7
  %mul198 = fmul double %mul196, %call197
  %143 = load double, double* %r2y, align 8
  %mul199 = fmul double 2.500000e-01, %143
  %144 = load double, double* %r2y, align 8
  %mul200 = fmul double %mul199, %144
  %145 = load double, double* %r2, align 8
  %call201 = call double @pow(double %145, double -1.500000e+00) #7
  %mul202 = fmul double %mul200, %call201
  %sub203 = fsub double %mul198, %mul202
  store double %sub203, double* %ryy, align 8
  %146 = load double, double* %r2zz, align 8
  %mul204 = fmul double 5.000000e-01, %146
  %147 = load double, double* %r2, align 8
  %call205 = call double @pow(double %147, double -5.000000e-01) #7
  %mul206 = fmul double %mul204, %call205
  %148 = load double, double* %r2z, align 8
  %mul207 = fmul double 2.500000e-01, %148
  %149 = load double, double* %r2z, align 8
  %mul208 = fmul double %mul207, %149
  %150 = load double, double* %r2, align 8
  %call209 = call double @pow(double %150, double -1.500000e+00) #7
  %mul210 = fmul double %mul208, %call209
  %sub211 = fsub double %mul206, %mul210
  store double %sub211, double* %rzz, align 8
  store double 1.000000e+00, double* %A, align 8
  %151 = load double, double* %4, align 8
  %152 = load double, double* %5, align 8
  %153 = load double, double* %6, align 8
  %154 = load double, double* %r, align 8
  %sub212 = fsub double %154, 2.500000e-01
  %mul213 = fmul double %153, %sub212
  %call214 = call double @tanh(double %mul213) #7
  %mul215 = fmul double %152, %call214
  %add216 = fadd double %151, %mul215
  store double %add216, double* %B, align 8
  %155 = load double, double* %5, align 8
  %156 = load double, double* %6, align 8
  %mul217 = fmul double %155, %156
  %157 = load double, double* %rx, align 8
  %mul218 = fmul double %mul217, %157
  %158 = load double, double* %6, align 8
  %159 = load double, double* %r, align 8
  %sub219 = fsub double %159, 2.500000e-01
  %mul220 = fmul double %158, %sub219
  %call221 = call double @tanh(double %mul220) #7
  %call222 = call double @pow(double %call221, double 2.000000e+00) #7
  %sub223 = fsub double 1.000000e+00, %call222
  %mul224 = fmul double %mul218, %sub223
  store double %mul224, double* %Bx, align 8
  %160 = load double, double* %5, align 8
  %161 = load double, double* %6, align 8
  %mul225 = fmul double %160, %161
  %162 = load double, double* %ry, align 8
  %mul226 = fmul double %mul225, %162
  %163 = load double, double* %6, align 8
  %164 = load double, double* %r, align 8
  %sub227 = fsub double %164, 2.500000e-01
  %mul228 = fmul double %163, %sub227
  %call229 = call double @tanh(double %mul228) #7
  %call230 = call double @pow(double %call229, double 2.000000e+00) #7
  %sub231 = fsub double 1.000000e+00, %call230
  %mul232 = fmul double %mul226, %sub231
  store double %mul232, double* %By, align 8
  %165 = load double, double* %5, align 8
  %166 = load double, double* %6, align 8
  %mul233 = fmul double %165, %166
  %167 = load double, double* %rz, align 8
  %mul234 = fmul double %mul233, %167
  %168 = load double, double* %6, align 8
  %169 = load double, double* %r, align 8
  %sub235 = fsub double %169, 2.500000e-01
  %mul236 = fmul double %168, %sub235
  %call237 = call double @tanh(double %mul236) #7
  %call238 = call double @pow(double %call237, double 2.000000e+00) #7
  %sub239 = fsub double 1.000000e+00, %call238
  %mul240 = fmul double %mul234, %sub239
  store double %mul240, double* %Bz, align 8
  %170 = load double, double* %7, align 8
  %171 = load double, double* %r2, align 8
  %mul241 = fmul double %170, %171
  %call242 = call double @exp(double %mul241) #7
  %172 = load double, double* %8, align 8
  %173 = load double, double* %x, align 8
  %mul243 = fmul double %172, %173
  %call244 = call double @sin(double %mul243) #7
  %mul245 = fmul double %call242, %call244
  %174 = load double, double* %8, align 8
  %175 = load double, double* %y, align 8
  %mul246 = fmul double %174, %175
  %call247 = call double @sin(double %mul246) #7
  %mul248 = fmul double %mul245, %call247
  %176 = load double, double* %8, align 8
  %177 = load double, double* %z, align 8
  %mul249 = fmul double %176, %177
  %call250 = call double @sin(double %mul249) #7
  %mul251 = fmul double %mul248, %call250
  store double %mul251, double* %u, align 8
  %178 = load double, double* %7, align 8
  %179 = load double, double* %r2x, align 8
  %mul252 = fmul double %178, %179
  %180 = load double, double* %u, align 8
  %mul253 = fmul double %mul252, %180
  %181 = load double, double* %8, align 8
  %182 = load double, double* %7, align 8
  %183 = load double, double* %r2, align 8
  %mul254 = fmul double %182, %183
  %call255 = call double @exp(double %mul254) #7
  %mul256 = fmul double %181, %call255
  %184 = load double, double* %8, align 8
  %185 = load double, double* %x, align 8
  %mul257 = fmul double %184, %185
  %call258 = call double @cos(double %mul257) #7
  %mul259 = fmul double %mul256, %call258
  %186 = load double, double* %8, align 8
  %187 = load double, double* %y, align 8
  %mul260 = fmul double %186, %187
  %call261 = call double @sin(double %mul260) #7
  %mul262 = fmul double %mul259, %call261
  %188 = load double, double* %8, align 8
  %189 = load double, double* %z, align 8
  %mul263 = fmul double %188, %189
  %call264 = call double @sin(double %mul263) #7
  %mul265 = fmul double %mul262, %call264
  %add266 = fadd double %mul253, %mul265
  store double %add266, double* %ux, align 8
  %190 = load double, double* %7, align 8
  %191 = load double, double* %r2y, align 8
  %mul267 = fmul double %190, %191
  %192 = load double, double* %u, align 8
  %mul268 = fmul double %mul267, %192
  %193 = load double, double* %8, align 8
  %194 = load double, double* %7, align 8
  %195 = load double, double* %r2, align 8
  %mul269 = fmul double %194, %195
  %call270 = call double @exp(double %mul269) #7
  %mul271 = fmul double %193, %call270
  %196 = load double, double* %8, align 8
  %197 = load double, double* %x, align 8
  %mul272 = fmul double %196, %197
  %call273 = call double @sin(double %mul272) #7
  %mul274 = fmul double %mul271, %call273
  %198 = load double, double* %8, align 8
  %199 = load double, double* %y, align 8
  %mul275 = fmul double %198, %199
  %call276 = call double @cos(double %mul275) #7
  %mul277 = fmul double %mul274, %call276
  %200 = load double, double* %8, align 8
  %201 = load double, double* %z, align 8
  %mul278 = fmul double %200, %201
  %call279 = call double @sin(double %mul278) #7
  %mul280 = fmul double %mul277, %call279
  %add281 = fadd double %mul268, %mul280
  store double %add281, double* %uy, align 8
  %202 = load double, double* %7, align 8
  %203 = load double, double* %r2z, align 8
  %mul282 = fmul double %202, %203
  %204 = load double, double* %u, align 8
  %mul283 = fmul double %mul282, %204
  %205 = load double, double* %8, align 8
  %206 = load double, double* %7, align 8
  %207 = load double, double* %r2, align 8
  %mul284 = fmul double %206, %207
  %call285 = call double @exp(double %mul284) #7
  %mul286 = fmul double %205, %call285
  %208 = load double, double* %8, align 8
  %209 = load double, double* %x, align 8
  %mul287 = fmul double %208, %209
  %call288 = call double @sin(double %mul287) #7
  %mul289 = fmul double %mul286, %call288
  %210 = load double, double* %8, align 8
  %211 = load double, double* %y, align 8
  %mul290 = fmul double %210, %211
  %call291 = call double @sin(double %mul290) #7
  %mul292 = fmul double %mul289, %call291
  %212 = load double, double* %8, align 8
  %213 = load double, double* %z, align 8
  %mul293 = fmul double %212, %213
  %call294 = call double @cos(double %mul293) #7
  %mul295 = fmul double %mul292, %call294
  %add296 = fadd double %mul283, %mul295
  store double %add296, double* %uz, align 8
  %214 = load double, double* %7, align 8
  %215 = load double, double* %r2xx, align 8
  %mul297 = fmul double %214, %215
  %216 = load double, double* %u, align 8
  %mul298 = fmul double %mul297, %216
  %217 = load double, double* %7, align 8
  %218 = load double, double* %r2x, align 8
  %mul299 = fmul double %217, %218
  %219 = load double, double* %ux, align 8
  %mul300 = fmul double %mul299, %219
  %add301 = fadd double %mul298, %mul300
  %220 = load double, double* %7, align 8
  %221 = load double, double* %r2x, align 8
  %mul302 = fmul double %220, %221
  %222 = load double, double* %8, align 8
  %mul303 = fmul double %mul302, %222
  %223 = load double, double* %7, align 8
  %224 = load double, double* %r2, align 8
  %mul304 = fmul double %223, %224
  %call305 = call double @exp(double %mul304) #7
  %mul306 = fmul double %mul303, %call305
  %225 = load double, double* %8, align 8
  %226 = load double, double* %x, align 8
  %mul307 = fmul double %225, %226
  %call308 = call double @cos(double %mul307) #7
  %mul309 = fmul double %mul306, %call308
  %227 = load double, double* %8, align 8
  %228 = load double, double* %y, align 8
  %mul310 = fmul double %227, %228
  %call311 = call double @sin(double %mul310) #7
  %mul312 = fmul double %mul309, %call311
  %229 = load double, double* %8, align 8
  %230 = load double, double* %z, align 8
  %mul313 = fmul double %229, %230
  %call314 = call double @sin(double %mul313) #7
  %mul315 = fmul double %mul312, %call314
  %add316 = fadd double %add301, %mul315
  %231 = load double, double* %8, align 8
  %232 = load double, double* %8, align 8
  %mul317 = fmul double %231, %232
  %233 = load double, double* %7, align 8
  %234 = load double, double* %r2, align 8
  %mul318 = fmul double %233, %234
  %call319 = call double @exp(double %mul318) #7
  %mul320 = fmul double %mul317, %call319
  %235 = load double, double* %8, align 8
  %236 = load double, double* %x, align 8
  %mul321 = fmul double %235, %236
  %call322 = call double @sin(double %mul321) #7
  %mul323 = fmul double %mul320, %call322
  %237 = load double, double* %8, align 8
  %238 = load double, double* %y, align 8
  %mul324 = fmul double %237, %238
  %call325 = call double @sin(double %mul324) #7
  %mul326 = fmul double %mul323, %call325
  %239 = load double, double* %8, align 8
  %240 = load double, double* %z, align 8
  %mul327 = fmul double %239, %240
  %call328 = call double @sin(double %mul327) #7
  %mul329 = fmul double %mul326, %call328
  %sub330 = fsub double %add316, %mul329
  store double %sub330, double* %uxx, align 8
  %241 = load double, double* %7, align 8
  %242 = load double, double* %r2yy, align 8
  %mul331 = fmul double %241, %242
  %243 = load double, double* %u, align 8
  %mul332 = fmul double %mul331, %243
  %244 = load double, double* %7, align 8
  %245 = load double, double* %r2y, align 8
  %mul333 = fmul double %244, %245
  %246 = load double, double* %uy, align 8
  %mul334 = fmul double %mul333, %246
  %add335 = fadd double %mul332, %mul334
  %247 = load double, double* %7, align 8
  %248 = load double, double* %r2y, align 8
  %mul336 = fmul double %247, %248
  %249 = load double, double* %8, align 8
  %mul337 = fmul double %mul336, %249
  %250 = load double, double* %7, align 8
  %251 = load double, double* %r2, align 8
  %mul338 = fmul double %250, %251
  %call339 = call double @exp(double %mul338) #7
  %mul340 = fmul double %mul337, %call339
  %252 = load double, double* %8, align 8
  %253 = load double, double* %x, align 8
  %mul341 = fmul double %252, %253
  %call342 = call double @sin(double %mul341) #7
  %mul343 = fmul double %mul340, %call342
  %254 = load double, double* %8, align 8
  %255 = load double, double* %y, align 8
  %mul344 = fmul double %254, %255
  %call345 = call double @cos(double %mul344) #7
  %mul346 = fmul double %mul343, %call345
  %256 = load double, double* %8, align 8
  %257 = load double, double* %z, align 8
  %mul347 = fmul double %256, %257
  %call348 = call double @sin(double %mul347) #7
  %mul349 = fmul double %mul346, %call348
  %add350 = fadd double %add335, %mul349
  %258 = load double, double* %8, align 8
  %259 = load double, double* %8, align 8
  %mul351 = fmul double %258, %259
  %260 = load double, double* %7, align 8
  %261 = load double, double* %r2, align 8
  %mul352 = fmul double %260, %261
  %call353 = call double @exp(double %mul352) #7
  %mul354 = fmul double %mul351, %call353
  %262 = load double, double* %8, align 8
  %263 = load double, double* %x, align 8
  %mul355 = fmul double %262, %263
  %call356 = call double @sin(double %mul355) #7
  %mul357 = fmul double %mul354, %call356
  %264 = load double, double* %8, align 8
  %265 = load double, double* %y, align 8
  %mul358 = fmul double %264, %265
  %call359 = call double @sin(double %mul358) #7
  %mul360 = fmul double %mul357, %call359
  %266 = load double, double* %8, align 8
  %267 = load double, double* %z, align 8
  %mul361 = fmul double %266, %267
  %call362 = call double @sin(double %mul361) #7
  %mul363 = fmul double %mul360, %call362
  %sub364 = fsub double %add350, %mul363
  store double %sub364, double* %uyy, align 8
  %268 = load double, double* %7, align 8
  %269 = load double, double* %r2zz, align 8
  %mul365 = fmul double %268, %269
  %270 = load double, double* %u, align 8
  %mul366 = fmul double %mul365, %270
  %271 = load double, double* %7, align 8
  %272 = load double, double* %r2z, align 8
  %mul367 = fmul double %271, %272
  %273 = load double, double* %uz, align 8
  %mul368 = fmul double %mul367, %273
  %add369 = fadd double %mul366, %mul368
  %274 = load double, double* %7, align 8
  %275 = load double, double* %r2z, align 8
  %mul370 = fmul double %274, %275
  %276 = load double, double* %8, align 8
  %mul371 = fmul double %mul370, %276
  %277 = load double, double* %7, align 8
  %278 = load double, double* %r2, align 8
  %mul372 = fmul double %277, %278
  %call373 = call double @exp(double %mul372) #7
  %mul374 = fmul double %mul371, %call373
  %279 = load double, double* %8, align 8
  %280 = load double, double* %x, align 8
  %mul375 = fmul double %279, %280
  %call376 = call double @sin(double %mul375) #7
  %mul377 = fmul double %mul374, %call376
  %281 = load double, double* %8, align 8
  %282 = load double, double* %y, align 8
  %mul378 = fmul double %281, %282
  %call379 = call double @sin(double %mul378) #7
  %mul380 = fmul double %mul377, %call379
  %283 = load double, double* %8, align 8
  %284 = load double, double* %z, align 8
  %mul381 = fmul double %283, %284
  %call382 = call double @cos(double %mul381) #7
  %mul383 = fmul double %mul380, %call382
  %add384 = fadd double %add369, %mul383
  %285 = load double, double* %8, align 8
  %286 = load double, double* %8, align 8
  %mul385 = fmul double %285, %286
  %287 = load double, double* %7, align 8
  %288 = load double, double* %r2, align 8
  %mul386 = fmul double %287, %288
  %call387 = call double @exp(double %mul386) #7
  %mul388 = fmul double %mul385, %call387
  %289 = load double, double* %8, align 8
  %290 = load double, double* %x, align 8
  %mul389 = fmul double %289, %290
  %call390 = call double @sin(double %mul389) #7
  %mul391 = fmul double %mul388, %call390
  %291 = load double, double* %8, align 8
  %292 = load double, double* %y, align 8
  %mul392 = fmul double %291, %292
  %call393 = call double @sin(double %mul392) #7
  %mul394 = fmul double %mul391, %call393
  %293 = load double, double* %8, align 8
  %294 = load double, double* %z, align 8
  %mul395 = fmul double %293, %294
  %call396 = call double @sin(double %mul395) #7
  %mul397 = fmul double %mul394, %call396
  %sub398 = fsub double %add384, %mul397
  store double %sub398, double* %uzz, align 8
  %295 = load double, double* %9, align 8
  %296 = load double, double* %A, align 8
  %mul399 = fmul double %295, %296
  %297 = load double, double* %u, align 8
  %mul400 = fmul double %mul399, %297
  %298 = load double, double* %10, align 8
  %299 = load double, double* %Bx, align 8
  %300 = load double, double* %ux, align 8
  %mul401 = fmul double %299, %300
  %301 = load double, double* %By, align 8
  %302 = load double, double* %uy, align 8
  %mul402 = fmul double %301, %302
  %add403 = fadd double %mul401, %mul402
  %303 = load double, double* %Bz, align 8
  %304 = load double, double* %uz, align 8
  %mul404 = fmul double %303, %304
  %add405 = fadd double %add403, %mul404
  %305 = load double, double* %B, align 8
  %306 = load double, double* %uxx, align 8
  %307 = load double, double* %uyy, align 8
  %add406 = fadd double %306, %307
  %308 = load double, double* %uzz, align 8
  %add407 = fadd double %add406, %308
  %mul408 = fmul double %305, %add407
  %add409 = fadd double %add405, %mul408
  %mul410 = fmul double %298, %add409
  %sub411 = fsub double %mul400, %mul410
  store double %sub411, double* %f, align 8
  %309 = load double, double* %A, align 8
  %310 = load i32, i32* %ijk, align 4
  %idxprom412 = sext i32 %310 to i64
  %311 = load i32, i32* %2, align 4
  %idxprom413 = sext i32 %311 to i64
  %312 = load i32, i32* %1, align 4
  %idxprom414 = sext i32 %312 to i64
  %313 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains415 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %313, i32 0, i32 25
  %314 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains415, align 8
  %arrayidx416 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %314, i64 %idxprom414
  %levels417 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx416, i32 0, i32 5
  %315 = load %struct.box_type*, %struct.box_type** %levels417, align 8
  %arrayidx418 = getelementptr inbounds %struct.box_type, %struct.box_type* %315, i64 %idxprom413
  %grids = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx418, i32 0, i32 10
  %316 = load double**, double*** %grids, align 8
  %arrayidx419 = getelementptr inbounds double*, double** %316, i64 2
  %317 = load double*, double** %arrayidx419, align 8
  %arrayidx420 = getelementptr inbounds double, double* %317, i64 %idxprom412
  store double %309, double* %arrayidx420, align 8
  %318 = load double, double* %B, align 8
  %319 = load i32, i32* %ijk, align 4
  %idxprom421 = sext i32 %319 to i64
  %320 = load i32, i32* %2, align 4
  %idxprom422 = sext i32 %320 to i64
  %321 = load i32, i32* %1, align 4
  %idxprom423 = sext i32 %321 to i64
  %322 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains424 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %322, i32 0, i32 25
  %323 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains424, align 8
  %arrayidx425 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %323, i64 %idxprom423
  %levels426 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx425, i32 0, i32 5
  %324 = load %struct.box_type*, %struct.box_type** %levels426, align 8
  %arrayidx427 = getelementptr inbounds %struct.box_type, %struct.box_type* %324, i64 %idxprom422
  %grids428 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx427, i32 0, i32 10
  %325 = load double**, double*** %grids428, align 8
  %arrayidx429 = getelementptr inbounds double*, double** %325, i64 3
  %326 = load double*, double** %arrayidx429, align 8
  %arrayidx430 = getelementptr inbounds double, double* %326, i64 %idxprom421
  store double %318, double* %arrayidx430, align 8
  %327 = load double, double* %u, align 8
  %328 = load i32, i32* %ijk, align 4
  %idxprom431 = sext i32 %328 to i64
  %329 = load i32, i32* %2, align 4
  %idxprom432 = sext i32 %329 to i64
  %330 = load i32, i32* %1, align 4
  %idxprom433 = sext i32 %330 to i64
  %331 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains434 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %331, i32 0, i32 25
  %332 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains434, align 8
  %arrayidx435 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %332, i64 %idxprom433
  %levels436 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx435, i32 0, i32 5
  %333 = load %struct.box_type*, %struct.box_type** %levels436, align 8
  %arrayidx437 = getelementptr inbounds %struct.box_type, %struct.box_type* %333, i64 %idxprom432
  %grids438 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx437, i32 0, i32 10
  %334 = load double**, double*** %grids438, align 8
  %arrayidx439 = getelementptr inbounds double*, double** %334, i64 11
  %335 = load double*, double** %arrayidx439, align 8
  %arrayidx440 = getelementptr inbounds double, double* %335, i64 %idxprom431
  store double %327, double* %arrayidx440, align 8
  %336 = load double, double* %f, align 8
  %337 = load i32, i32* %ijk, align 4
  %idxprom441 = sext i32 %337 to i64
  %338 = load i32, i32* %2, align 4
  %idxprom442 = sext i32 %338 to i64
  %339 = load i32, i32* %1, align 4
  %idxprom443 = sext i32 %339 to i64
  %340 = load %struct.domain_type*, %struct.domain_type** %0, align 8
  %subdomains444 = getelementptr inbounds %struct.domain_type, %struct.domain_type* %340, i32 0, i32 25
  %341 = load %struct.subdomain_type*, %struct.subdomain_type** %subdomains444, align 8
  %arrayidx445 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %341, i64 %idxprom443
  %levels446 = getelementptr inbounds %struct.subdomain_type, %struct.subdomain_type* %arrayidx445, i32 0, i32 5
  %342 = load %struct.box_type*, %struct.box_type** %levels446, align 8
  %arrayidx447 = getelementptr inbounds %struct.box_type, %struct.box_type* %342, i64 %idxprom442
  %grids448 = getelementptr inbounds %struct.box_type, %struct.box_type* %arrayidx447, i32 0, i32 10
  %343 = load double**, double*** %grids448, align 8
  %arrayidx449 = getelementptr inbounds double*, double** %343, i64 1
  %344 = load double*, double** %arrayidx449, align 8
  %arrayidx450 = getelementptr inbounds double, double* %344, i64 %idxprom441
  store double %336, double* %arrayidx450, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %345 = load i32, i32* %i, align 4
  %inc = add nsw i32 %345, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %omp.body.continue

omp.body.continue:                                ; preds = %for.end
  br label %omp.inner.for.inc

omp.inner.for.inc:                                ; preds = %omp.body.continue
  %346 = load i64, i64* %.omp.iv, align 8
  %add451 = add nsw i64 %346, 1
  store i64 %add451, i64* %.omp.iv, align 8
  br label %omp.inner.for.cond

omp.inner.for.end:                                ; preds = %omp.inner.for.cond
  br label %omp.loop.exit

omp.loop.exit:                                    ; preds = %omp.inner.for.end
  %347 = load i32*, i32** %.global_tid..addr, align 8
  %348 = load i32, i32* %347, align 4
  call void @__kmpc_for_static_fini(%ident_t* @0, i32 %348)
  br label %omp.precond.end

omp.precond.end:                                  ; preds = %omp.loop.exit, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind
declare double @pow(double, double) #5

; Function Attrs: nounwind
declare double @tanh(double) #5

; Function Attrs: nounwind
declare double @exp(double) #5

; Function Attrs: nounwind
declare double @sin(double) #5

; Function Attrs: nounwind
declare double @cos(double) #5

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { argmemonly nounwind }
attributes #3 = { nounwind readnone "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { alwaysinline nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { nounwind readnone }
attributes #7 = { nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_380/final)"}
!1 = !{!2, !4}
!2 = distinct !{!2, !3, !".omp_outlined..7: %.privates."}
!3 = distinct !{!3, !".omp_outlined..7"}
!4 = distinct !{!4, !3, !".omp_outlined..7: %.copy_fn."}
