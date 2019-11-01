TARGET = pa4
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic -O3

CC = $(GCC) $(CFLAGS)

SRCS = main.c evaluate.c construct.c rotation.c stack.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa4 -b examples/ops0.b output/ops0.b
	$(VALGRIND)=./valgrind.log ./pa4 -b examples/ops1.b output/ops1.b
	$(VALGRIND)=./valgrind.log ./pa4 -b examples/ops2.b output/ops2.b
	$(VALGRIND)=./valgrind.log ./pa4 -b examples/ops3.b output/ops3.b

testall: test1 testinva testemp testmemory

test1: $(TARGET)
	./pa4 -b examples/ops0.b output/ops0.b
	./pa4 -e output/ops0.b
	./pa4 -b examples/ops1.b output/ops1.b
	./pa4 -e output/ops1.b
	./pa4 -b examples/ops2.b output/ops2.b
	./pa4 -e output/ops2.b
	diff output/ops2.b output/ops0.b
	./pa4 -b examples/ops3.b output/ops3.b
	./pa4 -e output/ops3.b

test33: $(TARGET)
	./pa4 -b examples/test3.b output/test3.b
	./pa4 -e output/test3.b

test2: $(TARGET)
	./pa4 -b examples/test0.b output/test0.b
	./pa4 -e output/test0.b
	./pa4 -b examples/test1.b output/test1.b
	./pa4 -e output/test1.b
	./pa4 -b examples/test2.b output/test2.b
	./pa4 -e output/test2.b
	./pa4 -b examples/test4.b output/test4.b
	./pa4 -e output/test4.b
	./pa4 -b examples/test5.b output/test5.b
	./pa4 -e output/test5.b

test4: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_asc_1K.b output/ins_del_asc_1K.b
	./pa4 -e output/ins_del_asc_1K.b


test3: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_easy_0rot_2.b output/del_easy_0rot_2.b
	./pa4 -e output/del_easy_0rot_2.b
	diff output/del_easy_0rot_2.b testout/del_easy_0rot_2.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_easy_1rot_2.b output/del_easy_1rot_2.b
	./pa4 -e output/del_easy_1rot_2.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_easy_2rot_4.b output/del_easy_2rot_4.b
	./pa4 -e output/del_easy_2rot_4.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_hard_0rot_2.b output/del_hard_0rot_2.b
	./pa4 -e output/del_hard_0rot_2.b
	diff output/del_hard_0rot_2.b testout/del_hard_0rot_2.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_hard_1rot_4.b output/del_hard_1rot_4.b
	./pa4 -e output/del_hard_1rot_4.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/del_hard_2rot_4.b output/del_hard_2rot_4.b
	./pa4 -e output/del_hard_2rot_4.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_0rot_5.b output/ins_0rot_5.b
	./pa4 -e output/ins_0rot_5.b
	diff output/ins_0rot_5.b testout/ins_0rot_5.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_1rot_5.b output/ins_1rot_5.b
	./pa4 -e output/ins_1rot_5.b
	diff output/ins_1rot_5.b testout/ins_1rot_5.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_2arot_5.b output/ins_2arot_5.b
	./pa4 -e output/ins_2arot_5.b
	diff output/ins_2arot_5.b testout/ins_2arot_5.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_2brot_5.b output/ins_2brot_5.b
	./pa4 -e output/ins_2brot_5.b
	diff output/ins_2brot_5.b testout/ins_2brot_5.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_2crot.b output/ins_2crot.b
	./pa4 -e output/ins_2crot.b
	diff output/ins_2crot.b testout/ins_2crot.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_asc_1K.b output/ins_asc_1K.b
	./pa4 -e output/ins_asc_1K.b
	diff output/ins_asc_1K.b testout/ins_asc_1K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_asc_1M.b output/ins_asc_1M.b
	./pa4 -e output/ins_asc_1M.b
	diff output/ins_asc_1M.b testout/ins_asc_1M.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_asc_1K.b output/ins_del_asc_1K.b
	./pa4 -e output/ins_del_asc_1K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_asc_1M.b output/ins_del_asc_1M.b
	./pa4 -e output/ins_del_asc_1M.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_des_1K.b output/ins_del_des_1K.b
	./pa4 -e output/ins_del_des_1K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_des_1M.b output/ins_del_des_1M.b
	./pa4 -e output/ins_del_des_1M.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_min_5.b output/ins_del_min_5.b
	./pa4 -e output/ins_del_min_5.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_min_27.b output/ins_del_min_27.b
	./pa4 -e output/ins_del_min_27.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_des_1K.b output/ins_des_1K.b
	./pa4 -e output/ins_des_1K.b
	diff output/ins_des_1K.b testout/ins_des_1K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_des_1M.b output/ins_des_1M.b
	./pa4 -e output/ins_des_1M.b
	diff output/ins_des_1M.b testout/ins_des_1M.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_min_5_0rot.b output/ins_min_5_0rot.b
	./pa4 -e output/ins_min_5_0rot.b
	diff output/ins_min_5_0rot.b testout/ins_min_5_0rot.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_min_27_0rot.b output/ins_min_27_0rot.b
	./pa4 -e output/ins_min_27_0rot.b
	diff output/ins_min_27_0rot.b testout/ins_min_27_0rot.b

testrand: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_rand_1K_10.b output/ins_del_rand_1K_10.b
	./pa4 -e output/ins_del_rand_1K_10.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_del_rand_1M_10K.b output/ins_del_rand_1M_10K.b
	./pa4 -e output/ins_del_rand_1M_10K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_rand_1K.b output/ins_rand_1K.b
	./pa4 -e output/ins_rand_1K.b
	diff output/ins_rand_1K.b testout/ins_rand_1K.b
	$(VALGRIND)=./valgrind.log ./pa4 -b TestCases/build_tests/ins_rand_1M.b output/ins_rand_1M.b
	./pa4 -e output/ins_rand_1M.b
	diff output/ins_rand_1M.b testout/ins_rand_1M.b

testtree: $(TARGET)
	./pa4 -e examples/tree0.b
	./pa4 -e examples/tree1.b
	./pa4 -e examples/tree2.b
	./pa4 -e examples/tree3.b
	./pa4 -e examples/tree4.b
	./pa4 -e examples/invalidtree0.b
	./pa4 -e examples/invalidtree1.b
	./pa4 -e examples/invalidtree2.b

testemp: $(TARGET)
	./pa4 -b examples/empty.b output/empty.b
	./pa4 -e examples/empty.b

clean:
	rm -f sort *.o output/* pa4
