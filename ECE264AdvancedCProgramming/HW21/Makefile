TARGET = hw21
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = main.c decode.c list.c tree.c utility.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw21 input/input1.bin output1.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input2.bin output2.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input3.bin output3.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input4.bin output4.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input5.bin output5.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input6.bin output6.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input7.bin output7.txt
	$(VALGRIND)=./valgrind.log ./hw21 input/input8.bin output8.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8

test1: $(TARGET)
	./hw21 input/input1.bin output1.txt
	diff -i -w output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw21 input/input2.bin output2.txt
	diff -i -w output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw21 input/input3.bin output3.txt
	diff -i -w output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw21 input/input4.bin output4.txt
	diff -i -w output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw21 input/input5.bin output5.txt
	diff -i -w output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw21 input/input6.bin output6.txt
	diff -i -w output6.txt expected/expected6.txt

test7: $(TARGET)
	./hw21 input/input7.bin output7.txt
	diff -i -w output7.txt expected/expected7.txt

test8: $(TARGET)
	./hw21 input/input8.bin output8.txt
	diff -i -w output8.txt expected/expected8.txt
	
.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)