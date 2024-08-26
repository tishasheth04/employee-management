#include "../include/headerA3.h"

/**
This function's main purpose is to match the user entered name with an employee name 
in the linked list. The parameters of this function consist of the headLL and the name entered by the user in the calling program.
First, I have initialized multiple variables which will assist me in getting the desired output.
I traverse through the list to see if the first name entered matches one in the linked list.
If so, it checks to see if the last name matches.
If they both match, then the position of that employee is returned back to the calling program.
Else, I return -1 back to the calling program, indicating that either the name does not match
that of the ones in the linked list or that the linked list is empty. 

**/

int lookOnFullName (struct employee * headLL, char whichName [100]){


  int count = 1;
  char firstName[MAX_LENGTH];
  char lastName[MAX_LENGTH];

  sscanf(whichName, "%s %s",firstName,lastName);

  while (headLL != NULL) {

    if((strcmp(headLL->fname, firstName)) == 0 && strcmp(headLL->lname, lastName) == 0){
      return count;

    }

    headLL = headLL->nextEmployee;
    count++;
 
  }


  return -1;
}

