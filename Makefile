all: test_priorityqueue

run: test_priorityqueue
	./test_priorityqueue

test_priorityqueue: test_priorityqueue.o
	g++ -g -o test_priorityqueue test_priorityqueue.o

test_priorityqueue.o: test_priorityqueue.cpp priorityqueue.h
	g++ -g -c test_priorityqueue.cpp -o test_priorityqueue.o

clean:
	rm -f test_priorityqueue *.o

valgrind: test_priorityqueue
	valgrind --leak-check=full --track-origins=yes ./test_priorityqueue

.PHONY: all clean valgrind