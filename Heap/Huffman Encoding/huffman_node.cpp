//Noal Zyglowicz (ntz3sw) 11/24/19

#include "huffman_node.h"
#include "string"
using namespace std;

huffman_node::huffman_node(string sym, int freq){
  symbol = sym;
  frequency = freq;
  left = NULL;
  right = NULL;
}

huffman_node::huffman_node(){
  symbol = "";
  frequency = 0;
  left = NULL;
  right = NULL;
}

huffman_node::~huffman_node(){
}
