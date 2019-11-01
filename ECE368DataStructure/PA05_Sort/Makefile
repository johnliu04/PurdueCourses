TARGET = pa5
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic -O3

CC = $(GCC) $(CFLAGS)

SRCS = pa5.c sorting.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa4 -b PA4_TestCases/build_tests/del_hard_1rot_4.b output/del_hard_1rot_4.b

testall: test1 test2 test3 test4 test5 test6 test7

test1: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/1K.b output/1Kq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/1K.b output/1Km.b
	diff output/1Km.b output/1Kq.b

	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/10K.b output/10Kq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/10K.b output/10Km.b
	diff output/10Km.b output/10Kq.b

	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/1M.b output/1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/1M.b output/1Mm.b
	diff output/1Mm.b output/1Mq.b

test2: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/5.b output/5q.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/5.b output/5m.b
	diff output/5m.b output/5q.b

	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/10.b output/10q.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/10.b output/10m.b
	diff output/10m.b output/10q.b

	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/20.b output/20q.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/20.b output/20m.b
	diff output/20m.b output/20q.b

	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/100.b output/100q.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/100.b output/100m.b
	diff output/100m.b output/100q.b
	
test3: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/50W.b output/50Wq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/50W.b output/50Wm.b
	diff output/50Wq.b output/50Wm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q examples/1MR.b output/1MRq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m examples/1MR.b output/1MRm.b
	diff output/1MRq.b output/1MRm.b

test4: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/1K.b output/1Kq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/1K.b output/1Km.b
	diff output/1Kq.b output/1Km.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/1M.b output/1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/1M.b output/1Mm.b
	diff output/1Mq.b output/1Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/10K.b output/10Kq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/10K.b output/10Km.b
	diff output/10Kq.b output/10Km.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/10M.b output/10Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/10M.b output/10Mm.b
	diff output/10Mq.b output/10Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/20M.b output/20Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/20M.b output/20Mm.b
	diff output/20Mq.b output/20Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/32M.b output/32Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/32M.b output/32Mm.b
	diff output/32Mq.b output/32Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/100K.b output/100Kq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/100K.b output/100Km.b
	diff output/100Kq.b output/100Km.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/ascending_1M.b output/ascending_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/ascending_1M.b output/ascending_1Mm.b
	diff output/ascending_1Mq.b output/ascending_1Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/descending_1M.b output/descending_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/descending_1M.b output/descending_1Mm.b
	diff output/descending_1Mq.b output/descending_1Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/half_1M.b output/half_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/half_1M.b output/half_1Mm.b
	diff output/half_1Mq.b output/half_1Mm.b

test5: $(TARGET)
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/ascending_1M.b output/ascending_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/ascending_1M.b output/ascending_1Mm.b
	diff output/ascending_1Mq.b output/ascending_1Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/descending_1M.b output/descending_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/descending_1M.b output/descending_1Mm.b
	diff output/descending_1Mq.b output/descending_1Mm.b
	$(VALGRIND)=./valgrind.log time ./pa5 -q testcase/half_1M.b output/half_1Mq.b
	$(VALGRIND)=./valgrind.log time ./pa5 -m testcase/half_1M.b output/half_1Mm.b
	diff output/half_1Mq.b output/half_1Mm.b

test7: $(TARGET)
	time ./pa5 -q examples/100M.b output/100Mq.b
	diff output/100Mq.b others/100Mout_q.b
	time ./pa5 -m examples/100M.b output/100Mm.b
	diff output/100Mm.b output/100Mq.b

clean:
	rm -f sort *.o output/* pa5
