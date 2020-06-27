// Noal Zyglowicz, ntz3sw, 9/17/19, stack.cpp

#include "stack.h"

Stack::Stack(){
  s = new List();
  count = 0;
}

Stack::~Stack(){
  s -> makeEmpty();
  delete s;
}

bool Stack::isEmpty() const{
  return (count < 1);
}
void Stack::push(int value){
   ListItr first = s -> first();
   s -> insertBefore(value, first);
}

void Stack::pop(){
  ListItr first = s -> first();
  s -> remove(first.retrieve());
}

int Stack::top() const {
  ListItr first = s -> first();
  return first.retrieve();
}



