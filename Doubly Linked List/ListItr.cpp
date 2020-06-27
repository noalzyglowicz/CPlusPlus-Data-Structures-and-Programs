// Noal Zyglowicz, ntz3sw, 9/9/19, ListItr.cpp
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

ListItr::ListItr(){
  current = new ListNode;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
} 

bool ListItr::isPastEnd() const{
  return current -> next == NULL;
}

bool ListItr::isPastBeginning() const{
  return current -> previous == NULL;
}

void ListItr::moveForward() {
  if(!isPastEnd()){
current = current -> next;
    }
}

void ListItr::moveBackward(){
  if(!isPastBeginning()){
current = current -> previous;
    }
}

int ListItr::retrieve() const {
return current -> value;
}


