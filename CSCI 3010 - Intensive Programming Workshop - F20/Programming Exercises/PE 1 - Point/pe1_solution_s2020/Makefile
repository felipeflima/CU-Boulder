
CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings)

all: main

clean:
	rm Point.o main

main: Point.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.o -o main

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp
