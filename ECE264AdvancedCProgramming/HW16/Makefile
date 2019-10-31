TARGET = hw16
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = hw16.c main.c binarytree.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS =-DTEST_MAIN -DTEST_FREETREE -DTEST_SEARCH -DTEST_SUBTREE -DTEST_CONTAINED -DPRINT_FUN

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test1.txt inputs/tree2/test1.txt > output1.txt
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test2.txt inputs/tree2/test2.txt > output2.txt
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test3.txt inputs/tree2/test3.txt > output3.txt
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test4.txt inputs/tree2/test4.txt > output4.txt
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test5.txt inputs/tree2/test5.txt > output5.txt
	$(VALGRIND)=./valgrind.log ./hw16 inputs/tree1/test6.txt inputs/tree2/test6.txt > output6.txt

testall: test1 test2 test3 test4 test5 test6 testmemory

test1: $(TARGET)
	./hw16 inputs/tree1/test1.txt inputs/tree2/test1.txt > output1.txt
	diff -i -w output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw16 inputs/tree1/test2.txt inputs/tree2/test2.txt > output2.txt
	diff -i -w output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw16 inputs/tree1/test3.txt inputs/tree2/test3.txt > output3.txt
	diff -i -w output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw16 inputs/tree1/test4.txt inputs/tree2/test4.txt > output4.txt
	diff -i -w output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw16 inputs/tree1/test5.txt inputs/tree2/test5.txt > output5.txt
	diff -i -w output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw16 inputs/tree1/test6.txt inputs/tree2/test6.txt > output6.txt
	diff -i -w output6.txt expected/expected6.txt

.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)