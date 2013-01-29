#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

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
  ListItr *temp = new ListItr(head);
  while(temp->retrieve() !=x && !temp->isPastEnd()){
    temp->moveForward();
  }
  if(temp->isPastEnd())
    return NULL;
  else
    return *temp;
}

void List::remove (int x){
  ListItr temp = find(x);
  temp.current->previous->next= temp.current->next;
  temp.current->next->previous = temp.current->previous;
  temp.current->previous ==NULL;
  temp.current->previous==NULL;
  delete temp.current;
}

ListItr List::first(){
  ListItr *temp;
  temp = new ListItr(head);
  temp->moveForward();
  if(temp->isPastEnd()){
    return NULL;
  }
  else {
    return *temp; 
  }
}

ListItr List::last(){
  ListItr *temp;
  temp = new ListItr(tail);
  temp ->moveBackward();
  if(temp->isPastBeginning()) return NULL;
  else return *temp;
}

void List:: insertAtTail(int x){
  ListNode* l = new ListNode;
  tail->previous ->next = l;
  l->previous = tail->previous;
  l->value = x;
  l->next = tail;
  tail->previous = l;
}

void List:: insertAfter(int x, ListItr position){
  ListNode* l = new ListNode;
  position.current->previous ->next = l;
  l->previous = position.current->previous;
  l->value = x;
  l->next = position.current;
  position.current->previous = l;
  
}

void List:: insertBefore(int x, ListItr position){
  ListNode* l = new ListNode(x);
  position.current->next -> previous= l;
  l->next = position.current->next;
  l->value = x;
  l->previous = position.current;
  position.current->next = l;
}
