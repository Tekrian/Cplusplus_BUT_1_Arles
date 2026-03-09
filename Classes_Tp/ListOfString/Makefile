CXX=g++

CXXFLAGS=-g -Wall -Wfatal-errors -O0 -std=c++11

LIBS=-lX11 -lXext

all : test
test : ListOfStrings.o test0.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

test0.o : test0.cpp ListOfStrings.hpp
	$(CXX) $(CXXFLAGS) -c $<
ListOfStrings.o: ListOfStrings.cpp ListOfStrings.hpp
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm -f *.o test
.PHONY: clean all