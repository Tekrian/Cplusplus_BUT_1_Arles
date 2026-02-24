
CXX=g++

CXXFLAGS=-Wall -O0 -Wfatal-errors -std=c++11

LIBS=-L/usr/X11R6/lib -lX11 -lXext

all: calculatrice tracer main

#Programme 1 : calculatrice
calculatrice: calculatrice.o Polynome.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

#Programme 2 : tracer
tracer: tracer.o ez-draw++.o Polynome.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

#Programme 3 : c'est le main du TD
main: main.o  Polynome.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

calculatrice.o: calculatrice.cpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c $<
ez-draw++.o: ez-draw++.cpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
Polynome.o: Polynome.cpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c $<
tracer.o: tracer.cpp ez-draw++.hpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c $<
main.o: main.cpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o calculatrice tracer main

.PHONY: all clean