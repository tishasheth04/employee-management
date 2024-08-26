#include "../include/headerA3.h"

/**
This function's main purpose is to fire one employee based on whichever employee the user
chooses to fire. Thus, the parameter of this function is the headLL and the integer value 
of the employee the user wants to fire.
First, I have initialized multiple variables which will assist me in getting the desired output.
One of the first cases I have is to check if the linked list only has one employee and the count value is also 1.
If so, it fires the head of the linked list as there is only one node (head).
Next, I initialize temp to headLL again and traverse through the list until count is the same value as the value in the parameter of the function.
If so, I fire that employee.
Finally, the last case I have is if the user wants to fire the head but there are multiple employees.
If so, I fire the head and create the nextEmployee as the head and link them altogether.

**/

void fireOne(a3Emp ** headLL, int whichOne){

  a3Emp * temp = *headLL;
  a3Emp * after = *headLL;
  a3Emp * fire = *headLL;
  int total = countEmployees(*headLL);
  int count = 1;


  //This block of code executes if there is only one node in the linked list.
  if(total == 1 && count == 1){
    fire = temp;

    for(int i = 0; i < fire->numDependents;i++){
      free(fire->dependents[i]);
    }

    free(fire->dependents);
    free(fire);
    *headLL = NULL;

  }

  temp = *headLL;
  
  //This block of code executes if there are multiple employees in the linked list.

  while(temp != NULL){

    //This block of code executes if the employee that needs to be fired is within the linked list but is not the head of the linked list.
    //I am checking if count + 1 is equal to whichOne as I need to make sure I grab the node before the one that needs to be fired so that I can link those nodes
    //once I fire the middle node.
    //To do so, I make after = to the next, next employee (the one after the one that is being fired).
    //I make fire = to the next employee (the one being fired).
    //I am doing this so it is easier for me to connect the employee before the one being fired and the employee after being fired.
    if(count + 1 == whichOne){

      after = temp->nextEmployee->nextEmployee;
      fire = temp->nextEmployee;
      temp->nextEmployee = after;

      for(int i = 0; i < fire->numDependents; i++){
        free(fire->dependents[i]);
      } //end of for
     
      free(fire->dependents);
      free(fire);
    } //end of if


    //This block of code executes if the head is the employee that is being fired
    //but there are other employees in the linked list as well.
    //If so, I make after = to the next employee and fire = to the current employee
    //node we are on. Then, I fire the employee and make the head = to the next employee.

    if(whichOne == 1 && count == 1){

      after = temp->nextEmployee;
      fire = temp;

      for(int i = 0; i < fire->numDependents; i++){
        free(fire->dependents[i]);
      }

      free(fire->dependents);

      free(fire);
      *headLL = after;
    }

  temp = temp->nextEmployee;
  count++;

  }

}
