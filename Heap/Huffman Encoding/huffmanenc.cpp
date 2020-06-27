//Noal Zyglowicz (ntz3sw) 11/25/19

// included so we can use cout
#include <iostream>
// stdlib.h is where exit() lives
#include <stdlib.h>
#include "heap.h"
#include "string"
#include <map>
#include <iterator>
#include "huffman_node.h"

using namespace std;

// include the standard I/O library
#include <stdio.h>

//Function prototypes
void storeOpcodes(huffman_node *hn, map<string, string> *m, string path);


// we want to use parameters

int main (int argc, char **argv) {
  
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    //create heap
    heap *h = new heap();
    
    // attempt to open the supplied file.  FILE is a type designed to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    //build table using a map that stores the frequency of each symbol
    
    char g;
    map<string, int> freq;
    while ( (g = fgetc(fp)) != EOF ){
      //cout << g;
	map<string, int>::iterator itr = freq.find(string(1,g));	
	if(itr == freq.end()){
	  freq[string(1,g)] = 1;
	} else {
	  itr->second = itr->second + 1;
	  
	}
    }

    map<string, int>::iterator itr5 = freq.begin();
    while(itr5 != freq.end()){
      if(itr5->first == "" || itr5->first == "\n"){
      freq.erase(itr5);
      }
      itr5++;
    }
    
    //cout << "inserting symbol and frequency pair into heap/priority queue  v" << endl;
    //insert into priority queue each symbol and frequency pair
    map<string, int>::iterator itr2 = freq.begin();
    while(itr2 != freq.end()){
      //if(itr2->first != ""){
      huffman_node *hn = new huffman_node(itr2->first, itr2->second);
      if(hn->symbol != "" || hn->symbol != "\n"){
      h->insert(hn);
      }
      
      itr2++;
    }
    //cout << "inserting symbol and frequency pair into heap/priority queue  ^" << endl;

    
    map<string, int>::iterator itr4 = freq.begin();
    while(itr4 != freq.end()){
      itr4++;
    }
    
    huffman_node *treeRootPtr = h->findMin();
    

    while(h->size() > 1){
      huffman_node *hn = new huffman_node();
      huffman_node *child1 = h->deleteMin();
      huffman_node *child2 = h->deleteMin();
      hn->left = child1;
      hn->right = child2;
      hn->frequency = child1->frequency + child2->frequency;
      h->insert(hn);
      treeRootPtr = hn;
    }

    map<string, string> opcodes;
    //Traverse tree and store symbol and opcode pairs
    storeOpcodes(treeRootPtr, &opcodes,  "");
    
    //print out all symbol and opcode pairs
    map<string, string>::iterator itr3 = opcodes.begin();
    while(itr3 != opcodes.end()){
      cout << (itr3->first) << " " << (itr3->second) << endl;
      itr3++;
    }
    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the beginning
    rewind(fp);
    int total_symbols = 0;
    // read the file again, and print to the screen
    while ( (g = fgetc(fp)) != EOF ){
	if(g != '\n'){
	  cout << opcodes.find(string(1,g))->second << " ";
	  total_symbols++;
	}
    // close the file
    }
    cout << "\n";
    fclose(fp);

    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << total_symbols << " symbols that are encoded." <<endl;
    cout << "There are "<< opcodes.size() << " distinct symbols used." << endl;
    cout << "There were " << total_symbols * 8 << " bits in the original file." << endl;
    int total_encoded_bits = 0;
    double total_cost = 0.0;
    map<string, int>::iterator itr7 = freq.begin();
    while(itr7 != freq.end()){
      total_encoded_bits = total_encoded_bits + ((itr7->second) * ((opcodes.find(itr7->first)->second).length()));
      total_cost = total_cost + ( ((itr7->second)/double(total_symbols) * 1.0) * ((opcodes.find(itr7->first)->second).length()) * 1.0);
      //cout << ((itr7->second)/double(total_symbols) * 1.0) ;
      itr7++;
    }
    cout << "There were " << total_encoded_bits << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << double((total_symbols * 8.0) / total_encoded_bits) << "." <<endl;
    cout << "The cost of the Huffman tree is " << total_cost << " bits per character." << endl;
}


//Function to traverse tree, figure out opcodes and store them in the opcodes map as the pair (symbol, opcode)
void storeOpcodes(huffman_node *hn, map<string, string> *m, string path){
      if(hn != NULL){
	if(hn->left != NULL){
	  if(hn->left->right == NULL && hn->left->left == NULL){
	    (*m)[hn->left->symbol] = path + "0"; 
	  }
	  storeOpcodes(hn->left, m,  path + "0");
	}
	if(hn->right != NULL){
	  if(hn->right->right == NULL && hn->right->left == NULL){
	    (*m)[hn->right->symbol] = path + "1";
	   }
	  storeOpcodes(hn->right, m, path + "1");
	}
      }
}
