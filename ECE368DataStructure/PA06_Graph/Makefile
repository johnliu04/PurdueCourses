TARGET = pa6
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic -O3

CC = $(GCC) $(CFLAGS)

SRCS = pa6.c seqpair.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

test1: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa6 examples/r8.sp output/r8.pck
	diff output/r8.pck examples/r8.pck

test2: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa6 examples/r100.sp output/r100.pck
	diff output/r100.pck examples/r100.pck

test3: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa6 examples/r100h.sp output/r100h.pck
	diff output/r100h.pck examples/r100h.pck

test4: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa6 examples/r100v.sp output/r100v.pck
	diff output/r100v.pck examples/r100v.pck

test5: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r50.sp output/r50.pck
	diff testcase/r50.pck output/r50.pck

testcase: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r1.sp output/r1.pck
	diff testcase/r1.pck output/r1.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r5.sp output/r5.pck
	diff testcase/r5.pck output/r5.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r50.sp output/r50.pck
	diff testcase/r50.pck output/r50.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r20.sp output/r20.pck
	diff testcase/r20.pck output/r20.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r200.sp output/r200.pck
	diff testcase/r200.pck output/r200.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r2000.sp output/r2000.pck
	diff testcase/r2000.pck output/r2000.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r5000.sp output/r5000.pck
	diff testcase/r5000.pck output/r5000.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r8000.sp output/r8000.pck
	diff testcase/r8000.pck output/r8000.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r10000.sp output/r10000.pck
	diff testcase/r10000.pck output/r10000.pck
	$(VALGRIND)=./valgrind.log time ./pa6 testcase/r15000.sp output/r15000.pck
	diff testcase/r15000.pck output/r15000.pck
	#$(VALGRIND)=./valgrind.log time ./pa6 testcase/r50000.sp output/r50000.pck
	#diff testcase/r50000.pck output/r50000.pck
	#$(VALGRIND)=./valgrind.log time ./pa6 testcase/r100000.sp output/r100000.pck
	#diff testcase/r100000.pck output/r100000.pck

clean:
	rm -f sort *.o output/* pa6