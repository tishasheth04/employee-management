#include "../include/headerA3.h"

/**
The main purpose of this function is to count the number of employees in a linked list.
First, I have initialized the count variable value to 0.
Then, I traverse through the linked list and increment count.
Finally, I return the value of count once the linked list has been traversed.

**/

int countEmployees(a3Emp * headLL){

  int count = 0;

  while(headLL != NULL){

    headLL = headLL->nextEmployee;
    count++;


  }

  return count;
}
