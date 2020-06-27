// Noal Zyglowicz, ntz3sw, 9/9/19, List.cpp
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

List::List(){
  head = new ListNode;
  tail = new ListNode;
  head -> next = tail;
  tail -> previous = head;
  count=0;
  head -> previous = NULL;
  tail -> next = NULL;
    
}


List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


bool List::isEmpty() const {
  if(count == 0){
    return true;
  } else {
    return false;
  }
}

void List::makeEmpty(){
  while(!isEmpty()){
    remove(first().retrieve());
  }
}

ListItr List::first(){
  ListItr *itr = new ListItr();
  itr -> current = head -> next;
  return *itr;
}

ListItr List::last(){
  ListItr *itr = new ListItr();
  itr -> current = tail -> previous;
  return *itr;
}

void List::insertAfter(int x, ListItr position){
  ListNode *l = new ListNode;
  l -> value = x;
  l -> previous = position.current;
  l-> next = position.current -> next;
  position.current -> next -> previous = l;
  position.current -> next = l;
  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode *l = new ListNode();
  l -> value = x;
  l -> next = position.current;
  l -> previous = position.current -> previous;
  
  position.current -> previous = l;
  l -> previous-> next = l;
  count++;
}

void List::insertAtTail(int x){
 ListNode *l = new ListNode;
  l -> value = x;
  l -> next = tail;
  tail -> previous -> next = l;
  l -> previous = tail -> previous;
  tail -> previous = l;
  count += 1;
}

void List::remove(int x){
  ListItr *itr = new ListItr(find(x));

  if(!itr -> isPastEnd()){
    itr -> current -> previous -> next = itr -> current -> next;
    itr -> current -> next -> previous = itr -> current -> previous;
  }
  count--;
  delete itr;
}

ListItr List::find(int x){
  ListItr *itr = new ListItr(first());
  while(!itr -> isPastEnd()){
    if(itr -> current -> value == x){
	return *itr;
      }
  itr -> moveForward();
  }
  return  *itr;
}

int List::size() const{
  return count;
}

void printList(List& theList, bool forward){
   if(forward == true){
     ListItr *itr = new ListItr(theList.first());
     while(!itr -> isPastEnd()){
       cout << itr -> retrieve() << " ";
	 itr -> moveForward();
       }
   } else {
     ListItr *itr = new ListItr(theList.last());
     while(!itr -> isPastBeginning()){
       cout << itr -> retrieve() << " ";
       itr -> moveBackward();
       } 
       }   
}
