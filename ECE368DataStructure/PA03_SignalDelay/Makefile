TARGET = pa3
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic -O3

CC = $(GCC) $(CFLAGS)

SRCS = main.c tree.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa3 examples/3.txt output/3.pre output/3.delay
	$(VALGRIND)=./valgrind.log ./pa3 examples/5.txt output/5.pre output/5.delay
	$(VALGRIND)=./valgrind.log ./pa3 examples/10.txt output/10.pre output/10.delay
	$(VALGRIND)=./valgrind.log ./pa3 examples/100.txt output/100.pre output/100.delay
	$(VALGRIND)=./valgrind.log ./pa3 examples/1000.txt output/1000.pre output/1000.delay

testall: test1 test2 test3 test4 test5 test6 testmemory

test1: $(TARGET)
	./pa3 pa3_examples/3.txt output/3pre.pre output/3pre.delay
	diff output/3pre.pre pa3_examples/3.pre
	diff output/3pre.delay pa3_examples/3.delay
	./pa3 pa3_examples/5.txt output/5pre.pre output/5pre.delay
	diff output/5pre.pre pa3_examples/5.pre
	diff output/5pre.delay pa3_examples/5.delay

test2: $(TARGET)
	./pa3 examples/5.txt output/5.pre output/5.delay
	./pa3 examples/3.txt output/3.pre output/3.delay

test3: $(TARGET)
	./pa3 examples/10.txt output/10.pre output/10.delay

test4: $(TARGET)
	./pa3 examples/100000.txt output/100000.pre output/100000.delay

test5: $(TARGET)
	./pa3 examples/1000000.txt output/1000000.pre output/1000000.delay

test6: $(TARGET)
	./pa3 examples/empty output/empty.pre output/empty.delay
	diff output/empty.pre others/empty.pre
	diff output/empty.delay others/empty.delay

clean: # remove all machine generated files
	rm -f sort *.o output/* pa3