// Noal Zyglowicz, ntz3sw, 9/21/19 prelab4.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void outputBinary(int x){
  int oB[32];

  int i = 0;
  while(i < 32){
    oB[i] = x % 2;
    x = x/2;
    i++;
  }

  for(int h = i - 1; h > -1; h--){
    cout << oB[h];
  }
  cout << " " << endl;
}

int main() {
  string input;
  cout <<  "Enter integer value for x: " << endl;
  cin >> input;
  int x = atoi(input.c_str());
  outputBinary(x);  
}
