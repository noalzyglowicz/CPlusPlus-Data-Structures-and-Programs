// Noal Zyglowicz, ntz3sw, 9/14/19, postfixCalculator.cpp

#include "postfixCalculator.h"
#include <cstdlib>
using namespace std;

postfixCalculator::postfixCalculator(){
  stack<int> s;
}

bool postfixCalculator::isEmpty(){
  return s->empty();
}

void postfixCalculator::add(){
  if(!isEmpty()){
  int num1 = s->top();
  s->pop();
  int num2 = s->top();
  s->pop();
  int result = num1 + num2;
  s->push(result);
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}

void postfixCalculator::subtract(){
  if(!isEmpty()){
  int num1 = s->top();
    s->pop();
    int num2 = s->top();
    s->pop();
  int result = num2 - num1;
  s->push(result);
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}

void postfixCalculator::multiply(){
  if(!isEmpty()){
  int num1 = s->top();
    s->pop();
    int num2 = s->top();
    s->pop();
  int result = num1 * num2;
  s->push(result);
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}

void postfixCalculator::divide(){
  if(!isEmpty()){
  int num1 = s->top();
    s->pop();
    int num2 = s->top();
    s->pop();
  int result = num2 / num1;
  s->push(result);
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}

void postfixCalculator::negate(){
  if(!isEmpty()){
  int num1 = s->top();
    s->pop();
  int result = num1 * -1;
  s->push(result);
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}

void postfixCalculator::pushNum(int x){
  s->push(x);
}

int postfixCalculator::getTopValue(){
  if(!isEmpty()){
  return s->top();
  } else {
    cout << "Error: stack is empty " << endl; 
    exit(-1);
  }
}


