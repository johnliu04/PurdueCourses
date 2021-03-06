TARGET = hw13
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw13.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_DIV -DLINKEDLIST

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw13 inputs/test1.txt > output1.txt
	$(VALGRIND)=./valgrind.log ./hw13 inputs/test2.txt > output2.txt
	$(VALGRIND)=./valgrind.log ./hw13 inputs/test3.txt > output3.txt
	$(VALGRIND)=./valgrind.log ./hw13 inputs/test4.txt > output4.txt

testall: test1 test2 test3 test4 testmemory

test1: $(TARGET)
	./hw13 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw13 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw13 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw13 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt

.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
