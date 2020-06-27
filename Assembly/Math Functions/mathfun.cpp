// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

// Purpose: This main program produces a vector of random numbers
// between 0 and 99, then calls the externally defined function
// 'vecsum' to add up the elements of the vector.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

    // delcare the local variables
  long  n1, n2, product1, power1;

    // first integer?
    cout << "Please enter an integer:  ";
    cin >> n1;

    // second integer?
    cout << "Please enter an integer:  ";
    cin >> n2;

    // calculate the product of the two numbers
    product1 = product(n1, n2);
    cout << "The product of the two integers is " << product1 << endl;

    // calculate the product of the two numbers
    power1 = power(n1, n2);
    cout << "The power result of the two integers is " << power1 << endl;

    // all done!
    return 0;
}
