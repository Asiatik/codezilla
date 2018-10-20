compileargs ::= -std=c++11 -g -Wall -Wextra -Wpedantic
linkargs ::=
libraries ::=
# Prefix all object file names with the compilation directory
objects ::= $(addprefix out/, \
              mst.o LinkedGraph.o LinkedGraphEdge.o \
              ArrayList.o LinkedList.o LinkedListElement.o)
# Prefix all data structure headers with their directory
data_structure_headers ::= $(addprefix data-structures/, \
                             ArrayList.h \
                             LinkedList.h LinkedListElement.h \
                             LinkedGraph.h LinkedGraphEdge.h)

# Set executable extension for the platform
ifeq ($(OS),Windows_NT)
	binext ::= .exe
else
	binext ::=
endif
binary ::= out/mst$(binext)


# Default target: build executable
$(binary) : $(objects) | out
	@echo "###### Linking executable..."
	$(CXX) $(linkargs) -o $(binary) $(objects) $(libraries)

# Alias for default target
mst : $(binary)
.PHONY : mst

# Build and run
run : $(binary)
	@echo
	$(binary)
.PHONY : run

# Alias for 'out'
init : out
.PHONY : init

# Create compilation directory
out :
	mkdir out/

# Build each compilation unit

out/mst.o : mst.cpp mst.h $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/mst.o mst.cpp

out/LinkedGraph.o : data-structures/LinkedGraph.cpp $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/LinkedGraph.o data-structures/LinkedGraph.cpp

out/LinkedGraphEdge.o : data-structures/LinkedGraphEdge.cpp $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/LinkedGraphEdge.o data-structures/LinkedGraphEdge.cpp

out/ArrayList.o : data-structures/ArrayList.cpp $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/ArrayList.o data-structures/ArrayList.cpp

out/LinkedList.o : data-structures/LinkedList.cpp $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/LinkedList.o data-structures/LinkedList.cpp

out/LinkedListElement.o : data-structures/LinkedListElement.cpp $(data_structure_headers) | out
	$(CXX) $(compileargs) -c -o out/LinkedListElement.o data-structures/LinkedListElement.cpp
