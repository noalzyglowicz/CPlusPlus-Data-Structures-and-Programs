// Noal Zyglowicz, ntz3sw, 9/14/19, postfixCalculator.h
/*
 * Filename: postfixCalculator.h
 * Description: posfix calculator class definition
 */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include <stack>

using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();

  void add();

  void subtract();

  void multiply();
  
  void divide();

  void negate();

  void pushNum(int x);

  int getTopValue();

  bool isEmpty();

 private:
  stack<int> *s;
};

#endif
