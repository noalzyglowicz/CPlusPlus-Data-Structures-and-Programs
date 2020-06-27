//Noal Zyglowicz (ntz3sw) 11/30/19

// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffman_node.h"
#include <map>
#include <string.h>
#include <string>
using namespace std;

//Function prototypes
void createTree(huffman_node* root, string path, map<string, string> m);

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

     map<string, string> opcodes;
    
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
	opcodes[prefix] = character;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '"
        //     << prefix << "'" << endl;
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    huffman_node *treeRoot = new huffman_node();
    createTree(treeRoot, "", opcodes);

    huffman_node *currentNode = treeRoot;
    for(int i = 0; i<allbits.length(); i++){
      if(string(allbits)[i] == '0'){
	currentNode = currentNode->left;
	//cout << currentNode->symbol  << endl;
      }
      if(string(allbits)[i] == '1'){
	currentNode = currentNode->right;
	//cout << currentNode->symbol  << endl;
      }
      if(currentNode->left == NULL && currentNode->right == NULL){
	cout << currentNode->symbol;
	currentNode = treeRoot;
      }
    }
    cout << "\n";
}



void createTree(huffman_node* root, string path, map<string, string> m){
  if(m.find(path) != m.end()){
    root->symbol = (m.find(path))->second;
  }
  if(m.find(path) == m.end()){
    huffman_node *leftChild = new huffman_node();
    huffman_node *rightChild = new huffman_node();
    root->left = leftChild;
    leftChild->symbol = path + "0";
    root->right = rightChild;
    rightChild->symbol = path +"1";
    createTree(root->left, path + "0", m);
    createTree(root->right, path + "1", m);
  }
}
