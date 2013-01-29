#include "ListNode.h"
#include <iostream>


ListNode::ListNode(){
  value = 0;
  next = NULL;
  previous = NULL;
}

ListNode::ListNode(int x) {
  value = x;
  next = NULL;
  previous = NULL;
}

ListNode::~ListNode(){
  if(next !=NULL){
    if(next->next !=NULL){
      delete next;
    }
  }
  if(previous !=NULL){
    if(previous->previous !=NULL){
      delete previous;
    }
  }
}
