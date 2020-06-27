// main.cpp
//Noal Zyglowicz (ntz3sw) 11/16/19


#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" long collatz (long);

// Purpose: 

int  main () {

    // delcare the local variables
  long  x, collatz1, n;

    // first integer?
    cout << "Integer input x:  ";
    cin >> x;

    cout << "Integer number of runs n: ";
    cin >> n;

    timer t;
    double total = 0.000000000;
    for(int i = 0; i < n; i++){
      t.start();
      collatz(x);
      t.stop();
      total = total + t.getTime();
    }

    double avgTime = total / n;
    
    collatz1 = collatz(x);
    cout << "The number of steps is:  " << collatz1 << endl;

    cout << "The average runtime is:  " << avgTime << endl;
    // all done!
    return 0;
}
