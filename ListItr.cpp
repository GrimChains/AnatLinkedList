//#include "ListItr.h"
#include <iostream>
using namespace std;

class ListItr {

private: 
  ListNode *front;
  ListNode *back;
  ListNode *current;
  friend class List;

public:

  ListItr();	//Constructor
  ListItr(ListNode* theNode) {	// One parameter constructor
    temp = theNode;
    while(temp->previous != NULL){
      temp = temp->previous;
      
    }     
    front = temp;
    while(temp->next !=NULL){
      temp = temp->next;
    }   
    back = temp;
    current = theNode;
  }

  bool isPastEnd() const  {
    if ( current == back ){
      return true;
    }
    else{
      return false;
    }
  }

  bool isPastBeginning() const {
    if( current == front){
      return true;
    }
    else {
      return false;
    }
  }

  void moveForward(){
    if(!isPastEnd()){
      current= current->next;
    }
  }
  void moveBackward(){
    if(!isPastBeginning()){
      current = current->previous;
    }
  }

  int retrieve() const{
    return current->value;
  }
};
