SHELL=/bin/sh
BENCHMARK=bt
BENCHMARKU=BT

include ../config/make.def
include ../sys/make.common

ifndef VARIANT

OBJS = ${COMMON}/c_${RAND}.o ${COMMON}/c_print_results.o

SOURCE_EXEC = ${BENCHMARK}.c

#UPC_IO_OBJS = upc_fopen.o upc_fclose.o upc_fsync.o upc_fread_local.o upc_fwrite_local.o upc_fread_shared.o upc_fwrite_shared.o upc_fcntl.o upc_fseek.o upc_fset_size.o upc_fget_size.o upc_fpreallocate.o upc_ftest_async.o upc_fwait_async.o upc_fread_local_async.o upc_fwrite_local_async.o upc_fread_shared_async.o upc_fwrite_shared_async.o upc_fread_list_local.o upc_fread_list_shared.o upc_fwrite_list_local.o upc_fwrite_list_shared.o upc_fread_list_local_async.o upc_fread_list_shared_async.o upc_fwrite_list_local_async.o upc_fwrite_list_shared_async.o

OBJ-EXEC                = ${BENCHMARK}.${CLASS}.${NP}.o 
ADD_OBJ                 = add.${CLASS}.${NP}.o 
ADI_OBJ                 = adi.${CLASS}.${NP}.o 
COMPUTE_BUFFER_SIZE_OBJ = compute_buffer_size.${CLASS}.${NP}.o 
COMPUTE_RHS_OBJ         = compute_rhs.${CLASS}.${NP}.o 
COPY_FACES_OBJ          = copy_faces.${CLASS}.${NP}.o 
ERR_NORM_OBJ            = err_norm.${CLASS}.${NP}.o 
EXACT_RHS_OBJ           = exact_rhs.${CLASS}.${NP}.o 
EXACT_SOLUTION_OBJ      = exact_solution.${CLASS}.${NP}.o 
FILE_DEBUG_OBJ          = file_debug.${CLASS}.${NP}.o 
INITIALIZE_OBJ          = initialize.${CLASS}.${NP}.o 
LHSINIT_OBJ             = lhsinit.${CLASS}.${NP}.o 
LHSX_OBJ                = lhsx.${CLASS}.${NP}.o 
LHSY_OBJ                = lhsy.${CLASS}.${NP}.o 
LHSZ_OBJ                = lhsz.${CLASS}.${NP}.o 
MAKE_SET_OBJ            = make_set.${CLASS}.${NP}.o 
RHS_NORM_OBJ            = rhs_norm.${CLASS}.${NP}.o 
SET_CONSTANTS_OBJ       = set_constants.${CLASS}.${NP}.o 
VERIFY_OBJ              = verify.${CLASS}.${NP}.o 
X_SOLVE_OBJ             = x_solve.${CLASS}.${NP}.o 
X_SOLVE_CELL_OBJ        = x_solve_cell.${CLASS}.${NP}.o 
X_BACKSUBSTITUTE_OBJ    = x_backsubstitute.${CLASS}.${NP}.o 
X_UNPACK_BACKSUB_OBJ    = x_unpack_backsub_info.${CLASS}.${NP}.o 
X_UNPACK_SOLVE_OBJ      = x_unpack_solve.${CLASS}.${NP}.o 
Y_SOLVE_OBJ             = y_solve.${CLASS}.${NP}.o 
Y_SOLVE_CELL_OBJ        = y_solve_cell.${CLASS}.${NP}.o 
Y_BACKSUBSTITUTE_OBJ    = y_backsubstitute.${CLASS}.${NP}.o 
Y_UNPACK_BACKSUB_OBJ    = y_unpack_backsub_info.${CLASS}.${NP}.o 
Y_UNPACK_SOLVE_OBJ      = y_unpack_solve.${CLASS}.${NP}.o 
Z_SOLVE_OBJ             = z_solve.${CLASS}.${NP}.o 
Z_SOLVE_CELL_OBJ        = z_solve_cell.${CLASS}.${NP}.o 
Z_BACKSUBSTITUTE_OBJ    = z_backsubstitute.${CLASS}.${NP}.o 
Z_UNPACK_BACKSUB_OBJ    = z_unpack_backsub_info.${CLASS}.${NP}.o 
Z_UNPACK_SOLVE_OBJ      = z_unpack_solve_info.${CLASS}.${NP}.o 
MATMUL_OBJ              = matmul_sub.${CLASS}.${NP}.o 
MATVEC_OBJ              = matvec_sub.${CLASS}.${NP}.o 
BINVRHS_OBJ             = binvrhs.${CLASS}.${NP}.o 
BINVCRHS_OBJ            = binvcrhs.${CLASS}.${NP}.o 
BTIO_COMMON_OBJ         = btio_common.${CLASS}.${NP}.o 
SIMPLE_UPCIO_OBJ        = simple_upcio.${CLASS}.${NP}.o 

OBJS-S                  = ${OBJ-EXEC} ${ADD_OBJ} ${ADI_OBJ} \
	                  ${COMPUTE_BUFFER_SIZE_OBJ} ${COMPUTE_RHS_OBJ} \
	                  ${COPY_FACES_OBJ} ${ERR_NORM_OBJ} ${EXACT_RHS_OBJ}\
	                  ${EXACT_SOLUTION_OBJ} ${FILE_DEBUG_OBJ} \
	                  ${INITIALIZE_OBJ} ${LHSINIT_OBJ} ${LHSX_OBJ} \
			  ${LHSY_OBJ} ${LHSZ_OBJ} \
	                  ${MAKE_SET_OBJ}\
	                  ${RHS_NORM_OBJ} ${SET_CONSTANTS_OBJ}\
	                  ${VERIFY_OBJ}\
	                  ${X_SOLVE_OBJ} ${X_BACKSUBSTITUTE_OBJ} ${X_SOLVE_CELL_OBJ} \
			  ${X_UNPACK_SOLVE_OBJ} \
	                  ${X_UNPACK_BACKSUB_OBJ}  \
			  ${Y_SOLVE_OBJ} ${Y_SOLVE_CELL_OBJ} ${Y_BACKSUBSTITUTE_OBJ}  \
			  ${Y_UNPACK_BACKSUB_OBJ} \
			  ${BTIO_COMMON_OBJ} ${SIMPLE_UPCIO_OBJ} \
			   ${Y_UNPACK_SOLVE_OBJ} \
			  ${Z_SOLVE_OBJ} ${Z_SOLVE_CELL_OBJ} ${Z_BACKSUBSTITUTE_OBJ}  \
                          ${Z_UNPACK_BACKSUB_OBJ} \
			  ${Z_UNPACK_SOLVE_OBJ} \
                          ${BINVCRHS_OBJ} ${BINVRHS_OBJ} \
			  ${MATVEC_OBJ} ${MATMUL_OBJ} ${UPC_IO_OBJS}

EXEC = ${PROGRAM}.${NP}

CCOMPILE += -DSIMPLEIO 
#CCOMPILE += --uses-mpi 
# -I$(COMMON)
#CLINKFLAGS += --uses-mpi 

all: ${PROGRAM}

${PROGRAM}: config ${OBJS-S} ${OBJS}
	${CLINK} ${OBJS-S} ${CLINKFLAGS} -o ${EXEC} ${OBJS} 
	#mv ${EXEC} ${BINDIR}


${OBJ-EXEC}: ${SOURCE_EXEC} functions.h header.h global.h bt.c
	${CCOMPILE} -o ${OBJ-EXEC} ${SOURCE_EXEC}

${ADD_OBJ}: functions.h header.h add.c 
	${CCOMPILE} -o ${ADD_OBJ} add.c

${ADI_OBJ}: functions.h header.h adi.c
	${CCOMPILE} -o ${ADI_OBJ} adi.c

${COMPUTE_BUFFER_SIZE_OBJ}: functions.h header.h compute_buffer_size.c
	${CCOMPILE} -o ${COMPUTE_BUFFER_SIZE_OBJ} compute_buffer_size.c

${COMPUTE_RHS_OBJ}: functions.h header.h compute_rhs.c
	${CCOMPILE} -o ${COMPUTE_RHS_OBJ} compute_rhs.c

${COPY_FACES_OBJ}: functions.h header.h copy_faces.c
	${CCOMPILE} -o ${COPY_FACES_OBJ} copy_faces.c

${ERR_NORM_OBJ}: functions.h header.h err_norm.c
	${CCOMPILE} -o ${ERR_NORM_OBJ} err_norm.c

${EXACT_RHS_OBJ}: functions.h header.h  exact_rhs.c
	${CCOMPILE} -o ${EXACT_RHS_OBJ} exact_rhs.c

${EXACT_SOLUTION_OBJ}: functions.h header.h exact_solution.c
	${CCOMPILE} -o ${EXACT_SOLUTION_OBJ} exact_solution.c

${FILE_DEBUG_OBJ}: functions.h header.h file_debug.c
	${CCOMPILE} -o ${FILE_DEBUG_OBJ} file_debug.c

${INITIALIZE_OBJ}:   functions.h header.h initialize.c
	${CCOMPILE} -o ${INITIALIZE_OBJ} initialize.c

${LHSINIT_OBJ}: functions.h header.h lhsinit.c
	${CCOMPILE} -o ${LHSINIT_OBJ} lhsinit.c

${LHSX_OBJ}: functions.h header.h lhsx.c
	${CCOMPILE} -o ${LHSX_OBJ} lhsx.c

${LHSY_OBJ}: functions.h header.h lhsy.c
	${CCOMPILE} -o ${LHSY_OBJ} lhsy.c

${LHSZ_OBJ}: functions.h header.h lhsz.c
	${CCOMPILE} -o ${LHSZ_OBJ} lhsz.c

${MAKE_SET_OBJ}: functions.h header.h make_set.c
	${CCOMPILE} -o ${MAKE_SET_OBJ} make_set.c

${RHS_NORM_OBJ}: functions.h header.h rhs_norm.c
	${CCOMPILE} -o ${RHS_NORM_OBJ} rhs_norm.c

${SET_CONSTANTS_OBJ}: functions.h header.h set_constants.c
	${CCOMPILE} -o ${SET_CONSTANTS_OBJ} set_constants.c

${VERIFY_OBJ}: functions.h header.h  verify.c
	${CCOMPILE} -o ${VERIFY_OBJ} verify.c

${X_SOLVE_OBJ}: functions.h header.h  x_solve.c
	${CCOMPILE} -o ${X_SOLVE_OBJ} x_solve.c

${X_SOLVE_CELL_OBJ}: functions.h header.h  x_solve_cell.c
	${CCOMPILE} -o ${X_SOLVE_CELL_OBJ} x_solve_cell.c

${X_BACKSUBSTITUTE_OBJ}: functions.h header.h  x_backsubstitute.c
	${CCOMPILE} -o ${X_BACKSUBSTITUTE_OBJ} x_backsubstitute.c

${X_UNPACK_BACKSUB_OBJ}: functions.h header.h  x_unpack_backsub_info.c
	${CCOMPILE} -o ${X_UNPACK_BACKSUB_OBJ} x_unpack_backsub_info.c

${X_UNPACK_SOLVE_OBJ}: functions.h header.h  x_unpack_solve_info.c
	${CCOMPILE} -o ${X_UNPACK_SOLVE_OBJ} x_unpack_solve_info.c


${Y_SOLVE_OBJ}: functions.h header.h y_solve.c
	${CCOMPILE} -o ${Y_SOLVE_OBJ} y_solve.c
${Y_SOLVE_CELL_OBJ}: functions.h header.h  y_solve_cell.c
	${CCOMPILE} -o ${Y_SOLVE_CELL_OBJ} y_solve_cell.c

${Y_BACKSUBSTITUTE_OBJ}: functions.h header.h  y_backsubstitute.c
	${CCOMPILE} -o ${Y_BACKSUBSTITUTE_OBJ} y_backsubstitute.c

${Y_UNPACK_BACKSUB_OBJ}: functions.h header.h  y_unpack_backsub_info.c
	${CCOMPILE} -o ${Y_UNPACK_BACKSUB_OBJ} y_unpack_backsub_info.c

${Y_UNPACK_SOLVE_OBJ}: functions.h header.h  y_unpack_solve_info.c
	${CCOMPILE} -o ${Y_UNPACK_SOLVE_OBJ} y_unpack_solve_info.c


${Z_SOLVE_OBJ}: functions.h header.h  z_solve.c
	${CCOMPILE} -o ${Z_SOLVE_OBJ} z_solve.c

${Z_SOLVE_CELL_OBJ}: functions.h header.h  z_solve_cell.c
	${CCOMPILE} -o ${Z_SOLVE_CELL_OBJ} z_solve_cell.c

${Z_BACKSUBSTITUTE_OBJ}: functions.h header.h  z_backsubstitute.c
	${CCOMPILE} -o ${Z_BACKSUBSTITUTE_OBJ} z_backsubstitute.c

${Z_UNPACK_BACKSUB_OBJ}: functions.h header.h  z_unpack_backsub_info.c
	${CCOMPILE} -o ${Z_UNPACK_BACKSUB_OBJ} z_unpack_backsub_info.c

${Z_UNPACK_SOLVE_OBJ}: functions.h header.h  z_unpack_solve_info.c
	${CCOMPILE} -o ${Z_UNPACK_SOLVE_OBJ} z_unpack_solve_info.c

${BINVCRHS_OBJ}: functions.h header.h  binvcrhs.c
	${CCOMPILE} -o ${BINVCRHS_OBJ} binvcrhs.c

${BINVRHS_OBJ}: functions.h header.h  binvrhs.c
	${CCOMPILE} -o ${BINVRHS_OBJ} binvrhs.c

${MATVEC_OBJ}: functions.h header.h  matvec_sub.c
	${CCOMPILE} -o ${MATVEC_OBJ} matvec_sub.c

${MATMUL_OBJ}: functions.h header.h  matmul_sub.c
	${CCOMPILE} -o ${MATMUL_OBJ} matmul_sub.c

${BTIO_COMMON_OBJ}: functions.h header.h  btio_common.c
	${CCOMPILE} -o ${BTIO_COMMON_OBJ} btio_common.c

${SIMPLE_UPCIO_OBJ}: functions.h header.h  simple_upcio.c
	${CCOMPILE} -o ${SIMPLE_UPCIO_OBJ} simple_upcio.c

upc_fopen.o: ./upcio/upc_fopen.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fopen.c

upc_fclose.o: ./upcio/upc_fclose.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fclose.c

upc_fsync.o: ./upcio/upc_fsync.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fsync.c

upc_fread_local.o: ./upcio/upc_fread_local.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_local.c

upc_fwrite_local.o: ./upcio/upc_fwrite_local.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_local.c

upc_fread_shared.o: ./upcio/upc_fread_shared.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_shared.c

upc_fwrite_shared.o: ./upcio/upc_fwrite_shared.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_shared.c

upc_fcntl.o: ./upcio/upc_fcntl.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fcntl.c

upc_fseek.o: ./upcio/upc_fseek.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fseek.c

upc_fpreallocate.o: ./upcio/upc_fpreallocate.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fpreallocate.c

upc_fset_size.o: ./upcio/upc_fset_size.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fset_size.c

upc_fget_size.o: ./upcio/upc_fget_size.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fget_size.c

upc_fwait_async.o: ./upcio/upc_fwait_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwait_async.c

upc_ftest_async.o: ./upcio/upc_ftest_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_ftest_async.c

upc_fread_local_async.o: ./upcio/upc_fread_local_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_local_async.c

upc_fwrite_local_async.o: ./upcio/upc_fwrite_local_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_local_async.c

upc_fread_shared_async.o: ./upcio/upc_fread_shared_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_shared_async.c

upc_fwrite_shared_async.o: ./upcio/upc_fwrite_shared_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_shared_async.c

upc_fread_list_local.o: ./upcio/upc_fread_list_local.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_list_local.c

upc_fread_list_shared.o: ./upcio/upc_fread_list_shared.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_list_shared.c

upc_fwrite_list_local.o: ./upcio/upc_fwrite_list_local.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_list_local.c

upc_fwrite_list_shared.o: ./upcio/upc_fwrite_list_shared.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_list_shared.c

upc_fread_list_local_async.o: ./upcio/upc_fread_list_local_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_list_local_async.c

upc_fread_list_shared_async.o: ./upcio/upc_fread_list_shared_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fread_list_shared_async.c

upc_fwrite_list_local_async.o: ./upcio/upc_fwrite_list_local_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_list_local_async.c

upc_fwrite_list_shared_async.o: ./upcio/upc_fwrite_list_shared_async.c ./upcio/upc_io.h
	${CCOMPILE} ${OPTIONS} ${DEFINITION} $(CFLAGS) ./upcio/upc_fwrite_list_shared_async.c

else
	# VARIANT SPECIFIED
all:	${PROGRAM}

${PROGRAM}: 
	${MAKE} -C variants/${VARIANT}

endif

.PHONY:
clean:
	rm -f *.o *~
	rm -f core

