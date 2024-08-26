#include "../include/headerA3.h"

/**
The main purpose of this function is to print all the employees information that are in the linked list.
The parameters of this function is the headLL.
First, I have initialized the count value to 1.
If the headLL is empty, it prints the message saying the list is empty.
Else, it traverses through the list, and prints the information of each employee.
Finally, it prints the total number of employees in the linked list.
**/

void printAll (struct employee * headLL){

  int count = 1;

  //Executes if the linked list is empty
  if(headLL == NULL){
    printf("\nError. The linked list is empty\n");
  }

  //If the list is not empty, this block of code executes

  else{

    while (headLL != NULL) {
      printf("\nEmployee #%d \n", count);
      printf("\tEmployee id: %d \n", headLL->empId);
      printf("\tFirst Name: %s\n", headLL->fname);
      printf("\tLast Name: %s\n", headLL->lname);
      printf("\tDependents[%d]: ",headLL->numDependents);

      for(int i = 0; i < headLL->numDependents;i++){
        
        if(i != headLL->numDependents - 1){
          printf("%s, ", headLL->dependents[i]);
        }

        else {
          printf("%s ", headLL->dependents[i]);
        }

      }

    headLL = headLL->nextEmployee;
    count++;
   }

  printf("\nCurrently there are %d employees!\n",(count - 1)); 
  }
}
