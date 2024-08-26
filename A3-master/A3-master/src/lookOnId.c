#include "../include/headerA3.h"

/**
This functions main purpose is to see whether a employee id a user entered 
matches one in the linked list. The parameters of this function are the headLL, and 
the employee id entered by the user in the calling program.
First, I have initialized the value of count to 1. 
Next, I traverse through the list and see if the employee id entered by
the user matches that of the specific node's employee id.
If it does, it returns the value of count (the position at which this employee is).
Else, it returns -1. It also returns -1, if the linked list is empty.
**/

int lookOnId (struct employee * headLL, int whichEmpId){

  int count = 1;

  while (headLL != NULL) {

    if(headLL->empId == whichEmpId){
      return count;

    }

    headLL = headLL->nextEmployee;
    count++;
  }

  return -1;
}

