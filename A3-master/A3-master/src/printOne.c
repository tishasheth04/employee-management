#include "../include/headerA3.h"


/**
This functions main purpose is to print the information of the employee at a specific
index.The parameter of this function is the headLL and the integer value chosen by the user.
First I have initialized the count variable to 1, which increments after each node is checked.
Next, I traverse through the list and check if count is equal to whichOne. If it is,
the information of that specific employee is printed onto the screen.

**/

void printOne (struct employee * headLL, int whichOne){

  int count = 1;

  while (headLL != NULL) {

    if(count == whichOne){
      printf("Employee id: %d \n", headLL->empId);
      printf("First Name: %s\n", headLL->fname);
      printf("Last Name: %s\n", headLL->lname);
      printf("Dependents: ");

      for(int i = 0; i < headLL->numDependents;i++){

        if(i != headLL->numDependents - 1){
          printf("%s, ", headLL->dependents[i]);
        }

        else {
          printf("%s ", headLL->dependents[i]);
        }
      }

    }

    headLL = headLL->nextEmployee;
    count++;
  }

}

