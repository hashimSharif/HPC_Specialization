# This Makefile produces the upc_io.o file

CC = /usr/local/berkeley_upc_2.0/bin/upcc
AR = ar crl
RANLIB = ranlib
INCLUDE_DIR = -I/usr/local/include -I../
CFLAGS = -nightly ${INCLUDE_DIR} -c
LINK_DIR = -L/usr/local/lib
LFLAGS = ${LINK_DIR} -lmpich --uses-mpi
DEFINITION = -DAMMPI_INTERNAL
OPTIONS = -T=${NP}
OBJS = upc_fopen.o upc_fclose.o upc_fsync.o upc_fread_local.o upc_fwrite_local.o upc_fread_shared.o upc_fwrite_shared.o upc_fcntl.o upc_fseek.o upc_fset_size.o upc_fget_size.o upc_fpreallocate.o upc_ftest_async.o upc_fwait_async.o upc_fread_local_async.o upc_fwrite_local_async.o upc_fread_shared_async.o upc_fwrite_shared_async.o upc_fread_list_local.o upc_fread_list_shared.o upc_fwrite_list_local.o upc_fwrite_list_shared.o upc_fread_list_local_async.o upc_fread_list_shared_async.o upc_fwrite_list_local_async.o upc_fwrite_list_shared_async.o
TARGETS = test_open_close test_read_local test_write_local test_read_shared_ind test_read_shared_com test_write_shared_ind test_write_shared_com test_seek test_size test_prealloc test_read_local_async test_write_local_async test_read_shared_ind_async test_read_shared_com_async test_write_shared_ind_async test_write_shared_com_async test_read_list_local test_write_list_local test_read_list_shared test_write_list_shared test_read_list_local_async test_write_list_local_async test_read_list_shared_async test_write_list_shared_async test_async_wait_async  test_async_async_wait test_async_close_wait test_async_wait_close test_async_wait_sync test_async_sync_wait

all: ${TARGETS}

.c.o:
	$(CC) ${OPTIONS} ${DEFINITION} $(CFLAGS) $<

upc_fopen.o: ../upc_fopen.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fopen.c

upc_fclose.o: ../upc_fclose.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fclose.c

upc_fsync.o: ../upc_fsync.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fsync.c

upc_fread_local.o: ../upc_fread_local.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_local.c

upc_fwrite_local.o: ../upc_fwrite_local.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_local.c

upc_fread_shared.o: ../upc_fread_shared.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_shared.c

upc_fwrite_shared.o: ../upc_fwrite_shared.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_shared.c

upc_fcntl.o: ../upc_fcntl.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fcntl.c

upc_fseek.o: ../upc_fseek.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fseek.c

upc_fpreallocate.o: ../upc_fpreallocate.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fpreallocate.c

upc_fset_size.o: ../upc_fset_size.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fset_size.c

upc_fget_size.o: ../upc_fget_size.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fget_size.c

upc_fwait_async.o: ../upc_fwait_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwait_async.c

upc_ftest_async.o: ../upc_ftest_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_ftest_async.c

upc_fread_local_async.o: ../upc_fread_local_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_local_async.c

upc_fwrite_local_async.o: ../upc_fwrite_local_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_local_async.c

upc_fread_shared_async.o: ../upc_fread_shared_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_shared_async.c

upc_fwrite_shared_async.o: ../upc_fwrite_shared_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_shared_async.c

upc_fread_list_local.o: ../upc_fread_list_local.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_list_local.c

upc_fread_list_shared.o: ../upc_fread_list_shared.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_list_shared.c

upc_fwrite_list_local.o: ../upc_fwrite_list_local.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_list_local.c

upc_fwrite_list_shared.o: ../upc_fwrite_list_shared.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_list_shared.c

upc_fread_list_local_async.o: ../upc_fread_list_local_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_list_local_async.c

upc_fread_list_shared_async.o: ../upc_fread_list_shared_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fread_list_shared_async.c

upc_fwrite_list_local_async.o: ../upc_fwrite_list_local_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_list_local_async.c

upc_fwrite_list_shared_async.o: ../upc_fwrite_list_shared_async.c ../upc_io.h
	${CC} ${OPTIONS} ${DEFINITION} $(CFLAGS) ../upc_fwrite_list_shared_async.c

test_open_close: ${OBJS} test_open_close.o
	$(CC) ${OPTIONS} test_open_close.o ${OBJS} ${LFLAGS} -o test_open_close

test_read_local: ${OBJS} test_read_local.o
	$(CC) ${OPTIONS} test_read_local.o ${OBJS} ${LFLAGS} -o test_read_local

test_write_local: ${OBJS} test_write_local.o
	$(CC) ${OPTIONS} test_write_local.o ${OBJS} ${LFLAGS} -o test_write_local

test_read_shared_ind: ${OBJS} test_read_shared_ind.o
	$(CC) ${OPTIONS} test_read_shared_ind.o ${OBJS} ${LFLAGS} -o test_read_shared_ind

test_read_shared_com: ${OBJS} test_read_shared_com.o
	$(CC) ${OPTIONS} test_read_shared_com.o ${OBJS} ${LFLAGS} -o test_read_shared_com

test_write_shared_ind: ${OBJS} test_write_shared_ind.o
	$(CC) ${OPTIONS} test_write_shared_ind.o ${OBJS} ${LFLAGS} -o test_write_shared_ind

test_write_shared_com: ${OBJS} test_write_shared_com.o
	$(CC) ${OPTIONS} test_write_shared_com.o ${OBJS} ${LFLAGS} -o test_write_shared_com

test_seek: ${OBJS} test_seek.o
	$(CC) ${OPTIONS} test_seek.o ${OBJS} ${LFLAGS} -o test_seek

test_size: ${OBJS} test_size.o
	$(CC) ${OPTIONS} test_size.o ${OBJS} ${LFLAGS} -o test_size

test_prealloc: ${OBJS} test_prealloc.o
	$(CC) ${OPTIONS} test_prealloc.o ${OBJS} ${LFLAGS} -o test_prealloc

test_read_local_async: ${OBJS} test_read_local_async.o
	$(CC) ${OPTIONS} test_read_local_async.o ${OBJS} ${LFLAGS} -o test_read_local_async

test_write_local_async: ${OBJS} test_write_local_async.o
	$(CC) ${OPTIONS} test_write_local_async.o ${OBJS} ${LFLAGS} -o test_write_local_async

test_read_shared_ind_async: ${OBJS} test_read_shared_ind_async.o
	$(CC) ${OPTIONS} test_read_shared_ind_async.o ${OBJS} ${LFLAGS} -o test_read_shared_ind_async

test_read_shared_com_async: ${OBJS} test_read_shared_com_async.o
	$(CC) ${OPTIONS} test_read_shared_com_async.o ${OBJS} ${LFLAGS} -o test_read_shared_com_async

test_write_shared_ind_async: ${OBJS} test_write_shared_ind_async.o
	$(CC) ${OPTIONS} test_write_shared_ind_async.o ${OBJS} ${LFLAGS} -o test_write_shared_ind_async

test_write_shared_com_async: ${OBJS} test_write_shared_com_async.o
	$(CC) ${OPTIONS} test_write_shared_com_async.o ${OBJS} ${LFLAGS} -o test_write_shared_com_async

test_read_list_local: ${OBJS} test_read_list_local.o
	$(CC) ${OPTIONS} test_read_list_local.o ${OBJS} ${LFLAGS} -o test_read_list_local

test_write_list_local: ${OBJS} test_write_list_local.o
	$(CC) ${OPTIONS} test_write_list_local.o ${OBJS} ${LFLAGS} -o test_write_list_local

test_read_list_shared: ${OBJS} test_read_list_shared.o
	$(CC) ${OPTIONS} test_read_list_shared.o ${OBJS} ${LFLAGS} -o test_read_list_shared

test_write_list_shared: ${OBJS} test_write_list_shared.o
	$(CC) ${OPTIONS} test_write_list_shared.o ${OBJS} ${LFLAGS} -o test_write_list_shared

test_read_list_local_async: ${OBJS} test_read_list_local_async.o
	$(CC) ${OPTIONS} test_read_list_local_async.o ${OBJS} ${LFLAGS} -o test_read_list_local_async

test_write_list_local_async: ${OBJS} test_write_list_local_async.o
	$(CC) ${OPTIONS} test_write_list_local_async.o ${OBJS} ${LFLAGS} -o test_write_list_local_async

test_read_list_shared_async: ${OBJS} test_read_list_shared_async.o
	$(CC) ${OPTIONS} test_read_list_shared_async.o ${OBJS} ${LFLAGS} -o test_read_list_shared_async

test_write_list_shared_async: ${OBJS} test_write_list_shared_async.o
	$(CC) ${OPTIONS} test_write_list_shared_async.o ${OBJS} ${LFLAGS} -o test_write_list_shared_async

test_async_async_wait: ${OBJS} test_async_async_wait.o
	$(CC) ${OPTIONS} test_async_async_wait.o ${OBJS} ${LFLAGS} -o test_async_async_wait

test_async_wait_async: ${OBJS} test_async_wait_async.o
	$(CC) ${OPTIONS} test_async_wait_async.o ${OBJS} ${LFLAGS} -o test_async_wait_async

test_async_close_wait: ${OBJS} test_async_close_wait.o
	$(CC) ${OPTIONS} test_async_close_wait.o ${OBJS} ${LFLAGS} -o test_async_close_wait

test_async_wait_close: ${OBJS} test_async_wait_close.o
	$(CC) ${OPTIONS} test_async_wait_close.o ${OBJS} ${LFLAGS} -o test_async_wait_close

test_async_wait_sync: ${OBJS} test_async_wait_sync.o
	$(CC) ${OPTIONS} test_async_wait_sync.o ${OBJS} ${LFLAGS} -o test_async_wait_sync

test_async_sync_wait: ${OBJS} test_async_sync_wait.o
	$(CC) ${OPTIONS} test_async_sync_wait.o ${OBJS} ${LFLAGS} -o test_async_sync_wait
	
clean: 
	rm -f core *.o ${TARGETS} *~
