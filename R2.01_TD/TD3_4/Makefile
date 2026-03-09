CXX=g++

CXXFLAGS=-g -Wall -Wfatal-errors -O0 -std=c++11

LIBS=-lX11 -lXext


ListOfStrings.o: ListOfStrings.cpp ListOfStrings.hpp
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm -f *.o
.PHONY: clean