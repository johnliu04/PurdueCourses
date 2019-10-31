TARGET = hw12
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw12.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DLINKEDLIST -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_JOSEPHUS

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw12 10 3 1 > output1.txt
	$(VALGRIND)=./valgrind.log ./hw12 10 4 2 > output2.txt
	$(VALGRIND)=./valgrind.log ./hw12 8 5 3 > output3.txt
	$(VALGRIND)=./valgrind.log ./hw12 8 9 1 > output4.txt
	$(VALGRIND)=./valgrind.log ./hw12 41 3 1 > output5.txt
	$(VALGRIND)=./valgrind.log ./hw12 100 3 20 > output6.txt


testall: test1 test2 test3 test4 test5 test6

test1: hw12
	./hw12 10 3 1 > output1.txt
	diff output1.txt expected/expected1.txt

test2: hw12
	./hw12 10 4 2 > output2.txt
	diff output2.txt expected/expected2.txt

test3: hw12
	./hw12 8 5 3 > output3.txt
	diff output3.txt expected/expected3.txt

test4: hw12
	./hw12 8 9 1 > output4.txt
	diff output4.txt expected/expected4.txt

test5: hw12
	./hw12 41 3 1 > output5.txt
	diff output5.txt expected/expected5.txt

test6: hw12
	./hw12 100 3 20 > output6.txt
	diff output6.txt expected/expected6.txt

.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
