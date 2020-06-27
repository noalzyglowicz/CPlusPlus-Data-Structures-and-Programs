//Noal Zyglowicz (ntz3sw), 10/20/19
#include "hashTable.h"
#include <vector>
#include <list>
#include <string>
#include <array>
#include <cstdlib>
#include <iostream>


using namespace std;

//Constructor
hashTable::hashTable(int size) {
  hTable = new vector<list<string>>;

  spotsFilled = 0;
  
  if(!(checkprime(size))){
    int nextPrime = getNextPrime(size);
    hTable->resize(nextPrime);
    size = nextPrime;
    }
  

  loadFactor = 0.9;
  
  //create array for power of 37 to reduce time of calculating powers everytime
  powerArray37[0] = 1;
  for(int i = 1; i<22; i++){
    powerArray37[i] = 37 * powerArray37[i - 1];
  }

  powerArray59[0] = 1;
  for(int i = 1; i<22; i++){
    powerArray59[i] = 59 * powerArray37[i - 1];
  }
}

//Destructor- frees memory
hashTable::~hashTable() {
  delete hTable;
}

//creates a hash value number based on an input string s
int hashTable::hashT(string &s) {
  int sum = 0;
  for(int i = 0; i<s.size(); i++){
    sum += s[i];
  }
  
  return sum * powerArray37[s.size()] % hTable->size();
  //return sum * 59 %hTable->size();
}

//second hash function used for probing to avoid collisions
int hashTable::secondHashT(string &s) {
  int sum = 0;
  for(int i = 0; i<s.size(); i++){
    sum += s[i];
  }
  
  return sum * powerArray59[s.size()] % hTable->size();
  //return sum * 59 %hTable->size();
}

//checks to see if the hashTable contains the given string input
//separate chaining
bool hashTable::hasValue(string &s){
  int hashValue = hashT(s);
  
  list<string> &l = hTable -> at(hashValue);
  
  if(l.empty()){
    return false;
  }
  list<string> :: iterator first;
  list<string> :: iterator last;
  first = l.begin();
  last = l.end();
  while(first != last){
    if(*first == s){
      return first != last;
    }
    ++first;
  }
     
  return last != last; 
}



//checks to see if the hashTable contains the given string input
//for linear probing
/*
bool hashTable::isNotEmpty(int hashv){
  int hashValue = hashv;
  
  list<string> &l = hTable -> at(hashValue);
  
  if(l.empty()){
    return false;
  }
  list<string> :: iterator first;
  list<string> :: iterator last;
  first = l.begin();
  last = l.end();
  
     
  return first == last; 
}
*/



//inserts a string input in the hash table based on the index created by the hash function
//separate chaining
bool hashTable::insert(string &s){
  
  
    int hashValue = hashT(s);
    cout << hashValue << endl;
    list<string> &l = hTable -> at(hashValue);
    l.push_back(s);
    return true;
}

/*
//linear probing
bool hashTable::checkLoadFactor(){
  if(double(spotsFilled/size) > double(loadFactor)){
     hTable->resize(getNextPrime(size));
    return true;
  } else {
    return false;
  }
}
*/

/*
//linear probing
bool hashTable::insert(string &s){
  checkLoadFactor();
  int hashValue = hashT(s);
  if(!(this -> hasValue(s))){
    list<string> &l = hTable -> at(hashValue);
    l.push_back(s);
    spotsFilled++;
    return true;
  }

  else {
    //int quadProbeBase = 1; //varaible used for quadratic probing
    while(this -> isNotEmpty(hashValue)){
      hashValue = secondHashT(s);
      //linear probing
      //hashValue += 1;
	
      //quadratic probing
      //hashValue += quadProbeBase * quadProbeBase;
      //quadProbeBase += 1;
    }
    list<string> &l = hTable -> at(hashValue);
    l.push_back(s);
    spotsFilled++;
    return true;
    
  }
}
*/



// yes, there are much faster -- and much better -- ways to check if a
// number is prime (see the Sieve of Eratosthenes, for one example),
// but this code will work correctly, it is fairly straightforward,
// and it is fast enough for our purposes in the hash lab
bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}




