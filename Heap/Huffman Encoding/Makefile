# Noal Zyglowicz (ntz3sw)
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -g -std=c++11 -o encoder

CXXDEC=clang++ $(CXXFLAGSDEC)
CXXFLAGSDEC=-Wall -g -std=c++11 -o decoder

OFILES=huffman_node.o heap.o huffmanenc.o

OFILESDEC=huffman_node.o huffmandec.o

.SUFFIXES: .o .cpp

Rule1: $(OFILES) Rule2
	$(CXX) $(DEBUG) $(OFILES)

Rule2: $(OFILESDEC)
	$(CXXDEC) $(DEBUG) $(OFILESDEC)

heap.o: heap.cpp heap.h huffman_node.h
huffmandec.o: huffmandec.cpp huffman_node.h
huffmanenc.o: huffmanenc.cpp heap.h huffman_node.h
huffman_node.o: huffman_node.cpp huffman_node.h


clean:
	-rm *.o Rule1 Rule2

