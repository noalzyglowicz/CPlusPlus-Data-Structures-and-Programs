// Noal Zyglowicz, ntz3sw, 9/14/19, testPostfixCalc.cpp

#include "stack.h"
#include "postfixCalculator.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

class postfixCalculator;

int main(){
  
  postfixCalculator pfc;
  
  /*pfc.pushNum(2);
  pfc.pushNum(4);
  pfc.add();
  pfc.negate();
  pfc.pushNum(12);
  pfc.add();
  pfc.pushNum(3);
  pfc.divide();
  pfc.pushNum(2);
  pfc.multiply();
  pfc.pushNum(1);
  pfc.pushNum(1);
  pfc.add();
  pfc.subtract();
  cout << "Result is: " << pfc.getTopValue() << endl; */ 

  string s;
    while (cin >> s) {
      
      if(isdigit(atoi(s.c_str())) != 0){
	break;
      }

      else if(s == "+"){
	  pfc.add();
	}

      else if(s == "-"){
	  pfc.subtract();
	}

      else if(s == "*"){
	  pfc.multiply();
	}

      else if(s == "/"){
	  pfc.divide();
	}

      else if(s == "~"){
	  pfc.negate();
      } else {
	pfc.pushNum(atoi(s.c_str()));
      }
              
    }

    cout << "Result is: " << pfc.getTopValue() << endl; 
    
  return 0; 
  
}


