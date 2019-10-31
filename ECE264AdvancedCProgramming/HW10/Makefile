TARGET = hw10
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw10.c bmpfunc.c bmpimage.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file


TESTFLAGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw10 exampleImages/RV.bmp expected1.bmp
	$(VALGRIND)=./valgrind.log ./hw10 exampleImages/RV2.bmp expected2.bmp
	$(VALGRIND)=./valgrind.log ./hw10 exampleImages/CondProb.bmp expected3.bmp
	$(VALGRIND)=./valgrind.log ./hw10 exampleImages/RV2Small.bmp expected4.bmp

testall: test1 test2 test3 test4 testmemory

test1: hw10
	./hw10 exampleImages/RV.bmp expected1.bmp
	diff expected1.bmp expectedImages/expectedRV.bmp

test2: hw10
	./hw10 exampleImages/RV2.bmp expected2.bmp
	diff expected2.bmp expectedImages/expectedRV2.bmp


test3: hw10
	./hw10 exampleImages/CondProb.bmp expected3.bmp
	diff expected3.bmp expectedImages/expectedCondProb.bmp

test4: hw10
	./hw10 exampleImages/RV2Small.bmp expected4.bmp
	diff expected4.bmp expectedImages/expectedRV2Small.bmp

.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
