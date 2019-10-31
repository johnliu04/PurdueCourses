TARGET = hw14
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = hw14.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST


$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw14 inputs/test1.txt > output1.txt
	$(VALGRIND)=./valgrind.log ./hw14 inputs/test2.txt > output2.txt

testall: test1 test2 testmemory

test1: $(TARGET)
	./hw14 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: $(TARGET)
	./hw14 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
