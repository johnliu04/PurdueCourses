TARGET = shuf
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c utility.c shuffle.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c

TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV -DTEST_RSHUF

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./shuf 2 2 | sort > output1
	$(VALGRIND)=./valgrind.log ./shuf 4 3 | sort > output2
	$(VALGRIND)=./valgrind.log ./shuf 7 2 | sort > output3

testall: test1 test2 test3 testmemory

test1: shuf
	./shuf 2 2 | sort > output1
	diff output1 expected/expected1

test2: shuf
	./shuf 4 3 | sort > output2
	diff output2 expected/expected2

test3: shuf
	./shuf 7 2 | sort > output3
	diff output3 expected/expected3

clean:
	rm -f $(OBJS) $(TARGET)
