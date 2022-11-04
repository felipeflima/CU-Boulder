# Variables to control Makefile operation

CXX = g++ # the compiler
CXXFLAGS = -std=c++17 -Wall -ggdb # flags for the compiler

# ****************************************************
# Targets needed to bring the executable up to date

# runs for "make all" and "make"
all: main #executable

 # runs for "make main"
main: main.o Point.o
	$(CXX) $(CXXFLAGS) main.o Point.o -o main

main.o: main.cpp Point.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Point.o: Point.cpp Point.h
	$(CXX) $(CXXFLAGS) -c Point.cpp

# executable:
# 	./main

# runs for "make clean" - clean all .o and binary files
clean:
	rm *.o main