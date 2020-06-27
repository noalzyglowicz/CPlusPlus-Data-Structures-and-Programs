// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#inclyde "huffman_node"
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<*huffman_node> vec);
    ~binary_heap();

    void insert(*huffman_node x);
    *huffman_node findMin();
    *huffman_node deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<*huffman_node> heap;
    unsigned int heap_size;

    void percolateUp(*huffman_node hole);
    void percolateDown(*huffman_node hole);
};

#endif
