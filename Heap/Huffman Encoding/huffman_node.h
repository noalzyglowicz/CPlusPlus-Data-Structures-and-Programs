//Noal Zyglowicz (ntz3sw) 11/24/19
#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include "string"
using namespace std;

class huffman_node {
public:
  huffman_node(string sym, int freq);
  huffman_node();
  ~huffman_node();
  huffman_node *left;
  huffman_node *right;
  string symbol;
  int frequency;

private:
  
};

#endif
