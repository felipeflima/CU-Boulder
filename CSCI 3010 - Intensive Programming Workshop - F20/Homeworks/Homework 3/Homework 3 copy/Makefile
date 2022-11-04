CXX = g++
CXXFLAGS	= -std=c++17 -Wall


all: election

clean:
	rm *.o election

election: main.cpp Representative.o District.o Election.o ElectoralMap.o TextUI.o Makefile
	$(CXX) $(CXXFLAGS) main.cpp Representative.o District.o Election.o ElectoralMap.o TextUI.o -o election

Representative.o: Representative.cpp Representative.h
	$(CXX) $(CXXFLAGS) -c Representative.cpp

District.o: District.cpp District.h
	$(CXX) $(CXXFLAGS) -c District.cpp

Election.o: Election.cpp Election.h
	$(CXX) $(CXXFLAGS) -c Election.cpp

ElectoralMap.o: ElectoralMap.cpp ElectoralMap.h
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

TextUI.o: TextUI.cpp TextUI.h
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

test: District.o ElectoralMap.o
	$(CXX) $(CXXFLAGS) test.cpp District.o ElectoralMap.o TextUI.o -o election



# CXX = g++
# CXXFLAGS	= -std=c++17 -Wall

# all: election

# clean:
# 	rm election ElectoralMap.o Election.o

# election: main.cpp ElectoralMap.o Election.o
# 	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o Election.o -o election

# ElectoralMap.o: ElectoralMap.cpp
# 	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

# Election.o: Election.cpp
# 	$(CXX) $(CXXFLAGS) -c Election.cpp

