LIB = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lboost_unit_test_framework

all: Test

../BinaryHeapIntImpl.o : ../BinaryHeap.cpp ../BinaryHeap.hpp ../BinaryHeapIntImpl.cpp
	g++ -c ../BinaryHeapIntImpl.cpp -o ../BinaryHeap.o

Test: ../BinaryHeapIntImpl.o
	g++ ../BinaryHeap.o test.cpp -o test $(LIB) $(LIBS) -std=c++14

clean:
	rm test 
	rm ../BinaryHeap.o
