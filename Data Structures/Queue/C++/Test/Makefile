LIB = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lboost_unit_test_framework
INCLUDE = -I../.

all: Test

../StandardQueue/SimpleQueue.o: ../StandardQueue/SimpleQueueIntImpl.cpp ../StandardQueue/SimpleQueue.hpp ../StandardQueue/SimpleQueue.cpp
	g++ -c $< -o $@ $(INCLUDE)

../CircularQueue/CircularQueue.o: ../CircularQueue/CircularQueueIntImpl.cpp ../CircularQueue/CircularQueue.cpp ../CircularQueue/CircularQueue.hpp
	g++ -c $< -o $@ $(INCLUDE)

Test: ../CircularQueue/CircularQueue.o ../StandardQueue/SimpleQueue.o
	g++ $^ test.cpp -o test $(LIB) $(LIBS) $(INCLUDE) -std=c++14

clean:
	rm ../StandardQueue/SimpleQueue.o
	rm ../CircularQueue/CircularQueue.o
	rm test
