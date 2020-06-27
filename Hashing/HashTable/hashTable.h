//Noal Zyglowicz (ntz3sw), 10/20/19
#ifndef hashTable_H
#define hashTable_H

// include your stack implementation here
#include <vector>
#include <list>
#include <string>
#include <array>
#include <cstdlib>
#include <iostream>

using namespace std;

class hashTable {

 public:
   hashTable(int size);
  ~hashTable();

  int hashT(string &s); //hash function determines spot in hash table
  int secondHashT(string &s); //secondary hash function used for collision resolution
  bool insert(string &s); //inserts string into hash table based on result from hash function 
  bool hasValue(string &s); //check if hashtable contains the string 
  bool checkprime(unsigned int p);//check to see if the size given to hashTable is a prime number
  int getNextPrime (unsigned int n);//gives the next prime number
  bool checkLoadFactor();
  bool isNotEmpty(int hashv); //linearprobing
  
 private:
  vector<list<string>> *hTable;
  int powerArray37[22]; //arrays used to pre-calculate powers for hash functions
  int powerArray59[22];
  int size; // variables used to calculate if over load factor 
  int spotsFilled;
  double loadFactor;
};

#endif
