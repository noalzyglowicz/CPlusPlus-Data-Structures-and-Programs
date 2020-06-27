# Noal Zyglowicz (ntz3sw)
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -g -O2 -std=c++11

OFILES=traveling.o middleearth.o

.SUFFIXES: .o .cpp

Rule1: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	doxygen

middleearth.o: middleearth.cpp middleearth.h

traveling.o: traveling.cpp middleearth.cpp

clean:
	-rm *.o Rule1
