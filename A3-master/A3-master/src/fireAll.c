#include "../include/headerA3.h"

/**
The main purpose of this function is to fire all the employees in the linked list.
The parameter of this function consist of the headLL.
Basically, I will be freeing all the nodes in the linked list.
First, I create a temp variable which is initialized to NULL.
Then I traverse through the list firing each employee one by one. 
Basically, I am freeing each employee one by one.

**/

void fireAll (a3Emp ** headLL){

  if(*headLL == NULL){
    printf("Error. The linked list is empty.\n");
  }

  else{
    a3Emp * temp = NULL;

    while(*headLL != NULL){

      temp = *headLL;

      for(int i = 0; i < temp->numDependents; i++){
        free(temp->dependents[i]);
      }

      free(temp->dependents);

      *headLL = temp->nextEmployee;

      free(temp);

    }

    free (*headLL);
   printf("All employees are fired. Linked list is now empty\n");
  }
}






