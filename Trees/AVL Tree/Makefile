# Noal Zyglowicz (ntz3sw)
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11

OFILES=AVLNode.o AVLTree.o AVLPathTest.o

.SUFFIXES: .o .cpp

Rule1: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLTree.cpp

BinaryNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp

BSTPathTest.o: AVLPathTest.cpp AVLTree.h
	$(CXX) -c AVLPathTest.cpp
clean:
	-rm *.o Rule1
