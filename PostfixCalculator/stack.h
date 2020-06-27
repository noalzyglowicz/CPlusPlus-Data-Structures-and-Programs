// Noal Zyglowicz, ntz3sw, 9/17/19, stack.h

#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

class Stack {
 public:
  Stack();
  ~Stack();
  bool isEmpty() const;
  void push(int value);
  void pop();
  int top() const;

 private:
  List* s;
  int count;
};

#endif
