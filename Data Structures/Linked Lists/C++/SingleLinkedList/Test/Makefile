B = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lboost_unit_test_framework


all : Test

../IterativeLinkedList.o : ../IterativeLinkedListIntImpl.cpp ../IterativeLinkedList.cpp ../IterativeLinkedList.hpp
	g++ -c $< -o $@

../RecursiveLinkedList.o : ../RecursiveLinkedListIntImpl.cpp ../RecursiveLinkedList.hpp ../RecursiveLinkedList.cpp
	g++ -c $< -o $@

Test: ../IterativeLinkedList.o ../RecursiveLinkedList.o
	g++ $^ test.cpp -o test $(LIB) $(LIBS) -std=c++14

clean:
	rm test 
	rm ../IterativeLinkedList.o
	rm ../RecursiveLinkedList.o
