// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
//edited by Noal Zyglowicz (ntz3sw) 11/24/19

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffman_node.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffman_node*> vec);
    ~heap();

    void insert(huffman_node *x);
    huffman_node* findMin();
    huffman_node* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<huffman_node*> heap1;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
