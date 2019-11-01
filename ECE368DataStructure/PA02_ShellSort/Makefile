TARGET = pa2
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = pa2.c sequence.c shell_array.c shell_list.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/empty.b output/emptya.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/empty.b output/emptyl.b
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/15.b output/15a.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/15.b output/15l.b
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/1000.b output/1000a.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/1000.b output/1000l.b
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/10000.b output/10000a.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/10000.b output/10000l.b
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/100000.b output/100000a.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/100000.b output/100000l.b
	$(VALGRIND)=./valgrind.log ./pa2 -a examples/1000000.b output/1000000a.b
	$(VALGRIND)=./valgrind.log ./pa2 -l examples/1000000.b output/1000000l.b

testall: test1 test2 test3 test4 test5

test1: $(TARGET)
	./pa2 -a examples/500.b output/500a.b
	diff output/500a.b examples/500sa.b
	./pa2 -l examples/500.b output/500l.b
	diff output/500l.b examples/500sl.b

test2: $(TARGET)
	./pa2 -a examples/900.b output/900a.b
	diff output/900a.b examples/900sa.b
	./pa2 -l examples/900.b output/900l.b
	diff output/900l.b examples/900sl.b

test3: $(TARGET)
	./pa2 -a examples/9000.b output/9000a.b
	diff output/9000a.b examples/9000sa.b
	./pa2 -l examples/9000.b output/9000l.b
	diff output/9000l.b examples/9000sl.b

test4: $(TARGET)
	./pa2 -a examples/90000.b output/90000a.b
	diff output/90000a.b examples/90000sa.b
	./pa2 -l examples/90000.b output/90000l.b
	diff output/90000l.b examples/90000sl.b

test5: $(TARGET)
	./pa2 -a examples/empty.b output/emptya.b
	./pa2 -l examples/empty.b output/emptyl.b
	diff output/emptya.b examples/empty.b
	diff output/emptyl.b examples/empty.b
	
clean: # remove all machine generated files
	rm -f sort *.o output/*