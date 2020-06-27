# Noal Zyglowicz (ntz3sw)
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11 -O2

OFILES=wordPuzzle.o hashTable.o timer.o

.SUFFIXES: .o .cpp

Rule1: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	
wordPuzzle.o: wordPuzzle.cpp 
	$(CXX) -c wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
clean:
	-rm *.o Rule1
 
