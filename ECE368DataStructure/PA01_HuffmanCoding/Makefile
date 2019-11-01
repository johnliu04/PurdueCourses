TARGET = pa1
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = main.c encode.c count.c tree.c code.c compress.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./pa1 original/gophers output/gophers.count output/gophers.tree output/gophers.code output/gophers.hbt
	$(VALGRIND)=./valgrind.log ./pa1 original/empty output/empty.count output/empty.tree output/empty.code output/empty.hbt
	$(VALGRIND)=./valgrind.log ./pa1 original/woods output/woods.count output/woods.tree output/woods.code output/woods.hbt
	$(VALGRIND)=./valgrind.log ./pa1 original/stone output/stone.count output/stone.tree output/stone.code output/stone.hbt
	$(VALGRIND)=./valgrind.log ./pa1 original/woods output/woods.count output/woods.tree output/woods.code output/woods.hbt
	$(VALGRIND)=./valgrind.log ./pa1 original/binary1 output/binary1.count output/binary1.tree output/binary1.code output/binary1.hbt


testall: test1 test2 test3 test4 test5 test6 testmemory

test1: $(TARGET)
	./pa1 original/gophers output/gophers.count output/gophers.tree output/gophers.code output/gophers.hbt
	diff output/gophers.count count/gophers.count
	diff output/gophers.tree tree/gophers.tree
	diff output/gophers.code code/gophers.code
	diff output/gophers.hbt compressed/gophers.hbt

test2: $(TARGET)
	./pa1 original/empty output/empty.count output/empty.tree output/empty.code output/empty.hbt
	diff output/empty.count count/empty.count
	diff output/empty.tree tree/empty.tree
	diff output/empty.code code/empty.code
	diff output/empty.hbt compressed/empty.hbt

test3: $(TARGET)
	./pa1 original/lorum output/lorum.count output/lorum.tree output/lorum.code output/lorum.hbt
	diff output/lorum.count count/lorum.count
	diff output/lorum.tree tree/lorum.tree
	diff output/lorum.code code/lorum.code
	diff output/lorum.hbt compressed/lorum.hbt

test4: $(TARGET)
	./pa1 original/stone output/stone.count output/stone.tree output/stone.code output/stone.hbt
	diff output/stone.count count/stone.count
	diff output/stone.tree tree/stone.tree
	diff output/stone.code code/stone.code
	diff output/gophers.hbt compressed/gophers.hbt

test5: $(TARGET)
	./pa1 original/woods output/woods.count output/woods.tree output/woods.code output/woods.hbt
	diff output/woods.count count/woods.count
	diff output/woods.tree tree/woods.tree
	diff output/woods.code code/woods.code
	diff output/woods.hbt compressed/woods.hbt

test6: $(TARGET)
	./pa1 original/binary1 output/binary1.count output/binary1.tree output/binary1.code output/binary1.hbt
	diff output/binary1.count count/binary1.count
	diff output/binary1.tree tree/binary1.tree
	diff output/binary1.code code/binary1.code
	diff output/binary1.hbt compressed/binary1.hbt

clean: # remove all machine generated files
	rm -f sort *.o output/*