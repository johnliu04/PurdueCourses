TARGET = hw18
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic

CC = $(GCC) $(CFLAGS)

SRCS = main.c hw18.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND =  valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_DIST -DTEST_MIN

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test1.txt > output1.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test2.txt > output2.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test3.txt > output3.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test4.txt > output4.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test5.txt > output5.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test6.txt > output6.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test7.txt > output7.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test8.txt > output8.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test9.txt > output9.txt
	$(VALGRIND)=./valgrind.log ./hw18 inputs/test10.txt > output10.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test1: $(TARGET)
	./hw18 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
#test2 -> 33 3 inputs/test2.txt
test2: $(TARGET)
	./hw18 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

test3: $(TARGET)
	./hw18 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

test4: $(TARGET)
	./hw18 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt

test5: $(TARGET)
	./hw18 inputs/test5.txt > output5.txt
	diff output5.txt expected/expected5.txt

test6: $(TARGET)
	./hw18 inputs/test6.txt > output6.txt
	diff output6.txt expected/expected6.txt

test7: $(TARGET)
	./hw18 inputs/test7.txt > output7.txt
	diff output7.txt expected/expected7.txt

test8: $(TARGET)
	./hw18 inputs/test8.txt > output8.txt
	diff output8.txt expected/expected8.txt

test9: $(TARGET)
	./hw18 inputs/test9.txt > output9.txt
	diff output9.txt expected/expected9.txt

test10: $(TARGET)
	./hw18 inputs/test10.txt > output10.txt
	diff output10.txt expected/expected10.txt
	
.c.o:
	$(GCC) $(TESTFLAGS)  $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)