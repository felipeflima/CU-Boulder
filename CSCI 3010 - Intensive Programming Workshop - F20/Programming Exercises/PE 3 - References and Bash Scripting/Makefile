# Variables to control Makefile operation

CXX = g++ # the compiler
CXXFLAGS = -std=c++17 -Wall # flags for the compiler

# ****************************************************
# Targets needed to bring the executable up to date

# runs for "make all" and "make"
all: main #executable

 # runs for "make main"
main: pe3_references.cpp
	$(CXX) $(CXXFLAGS) pe3_references.cpp -o main

# executable:
# 	./main

# runs for "make clean" - clean all .o and binary files
clean:
	rm main