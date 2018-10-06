LIB = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lboost_unit_test_framework

all : Test

../IterativeDoubleLinkedList.o : ../IterativeDoubleLinkedListIntImpl.cpp ../IterativeDoubleLinkedList.hpp ../IterativeDoubleLinkedList.cpp
	g++ -c $< -o $@ -std=c++14

../RecursiveDoubleLinkedList.o : ../RecursiveDoubleLinkedListIntImpl.cpp ../RecursiveDoubleLinkedList.hpp ../RecursiveDoubleLinkedList.cpp
	g++ -c $< -o $@ -std=c++14


Test: ../IterativeDoubleLinkedList.o ../RecursiveDoubleLinkedList.o
	g++ $^ test.cpp -o test $(LIB) $(LIBS) -std=c++14

clean:
	rm test 
	rm ../IterativeDoubleLinkedList.o
	rm ../RecursiveDoubleLinkedList.o
