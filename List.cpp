#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

//class ListItr;
//class ListNode;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  int count = 0;
}

List::List(const List& source) {
  head = new ListNode();
  tail = new ListNode();
  head ->next = tail;
  tail ->previous = head;
  count = 0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}
List:: ~List(){
  makeEmpty();
  delete head;
  delete tail;
}

List& List:: operator= (const List& source) {
  if (this ==&source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const {
  return size()==0;
}
void List:: makeEmpty(){
  if(!isEmpty())
    delete  head->next;
}

ListItr List::find (int x){
  ListIter *temp = new ListIter(head);
  while(temp->retrieve() !=x && !temp->IsPastEnd()){
    temp->moveForward;
  }
  if(isPastEnd())
    return NULL;
  else
    return *temp;
}

void List::remove (int x){
  ListIterator temp = find(x);
  temp->current->previous->next= temp.current->next;
  temp ->current->next->previous = temp.current->previous;
  temp.current->previous ==NULL;
  temp.current->previous==NULL;
  delete temp.current;
}

ListItr List::first(){
  ListItr *temp;
  temp = new ListIter(head);
  temp->moveForward;
  if(isPastEnd()) return NULL;
  else return *temp; 
}

ListIter List::last(){
  ListItr *temp;
  temp = new ListIter(tail);
  temp ->moveBackward();
  if(isPastBeginning()) return NULL;
  else return *temp;
}

void List:: insertAtTail(int x){
  ListNode l = new ListNode;
  tail->previous ->next = l;
  l->previous = tail->previous;
  l->value = x;
  l->next = tail;
  tail->previous = l;
}

void List:: insertAfter(int x, ListItr position){
  ListNode l = new ListNode;
  position.previous ->next = l;
  l->previous = position.previous;
  l->value = x;
  l->next = position;
  position.previous = l;
  
}

void List:: insertBefore(int x, ListItr position){
  ListNode* l = new ListNode(x);
  position.current->next -> previous= l;
  l->next = position.current->next;
  l->value = x;
  l->previous = position.current;
  position.next = l;
}
