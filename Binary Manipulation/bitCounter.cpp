//Noal Zyglowicz, ntz3sw, 9/9/19, List.cpp

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int count = 0;

int bitCounter(int n){
  if (n % 2 == 0 && n != 0){
    bitCounter(n/2);
  }

  else if(n % 2 != 0){
    count += 1;
    bitCounter(n/2);
  }

  else {
    count = count;
  }

  return count;
  
}

int main(int argc, char **argv){
  if(argc == 1){
  exit(-1);
  }
  
  cout << bitCounter(atoi(argv[argc - 1])) << endl;
  
  return 0;
  
}
