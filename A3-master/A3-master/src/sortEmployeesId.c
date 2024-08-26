#include "../include/headerA3.h"

/**
This function's main purpose is to sort the employees in a ascending order based on 
their employee id. The parameter of this function is only the linked list head.
First, I have created various variables to get the desired output.
One of the first things I do is check if the head is null. If so, that indicates that the linked list is empty.
Thus, I print a message indicating so.
If the total number of nodes is 1, I call the printAll function as there is no need to sort it.
Else, I actually sort the linked list given through the parameter.
**/

void sortEmployeesId(struct employee * headLL){

  int check = 0;
  int total = countEmployees(headLL);
  int isntLowest = 0;
  a3Emp * swap;
  a3Emp * before;
  a3Emp * after;
  a3Emp * temp = headLL;
  a3Emp * headCpy = NULL;
  a3Emp * tempLinkedList = NULL;

  if(total == 0){
    printf("Error! The linked list is empty!\n");

  }

  else if(total == 1){
    printAll(temp);
  }

  /**
  This block of code is simply calling the copy function to copy the linked list 
  in the correct order. This while loop traverses through the list and calls the copy function.
  Once everything is copied, I make temp = the headCpy(copied list). This temp is what I will be traversing through to make changes to the list.
  **/

  else{

    headCpy = copy(temp);
    tempLinkedList = headCpy;
    temp = temp->nextEmployee;

    while(temp != NULL){
      tempLinkedList-> nextEmployee = copy(temp);
      temp = temp->nextEmployee;
      tempLinkedList = tempLinkedList->nextEmployee;
    } //end of while

    temp = headCpy;

    /**
    This block of code is what is switching the order of the nodes when the head node is not the highest empId.
    I have another condition where check is != 0. The only time check is = 0, is when the next employee is null (therefore the list has reached its end).
    In these if statements first I am making sure that the 2 nodes ahead of the current node is not null.
    If it is, then, it moves onto the next function. However if it is not null, then it checks to see if the next employee has a employee ID greater than the next two employee than the current position.
    If that condition is true as well, the swapping process starts. This is where I need to make sure I do not lose the current position therefore I assign 
    the before variable the current position of temp. I assign swap the next employee as that is higher then the temp->nextEmployee->nextEmployee.
    Finally, I link the two new nodes in the new order and assign temp to headCpy again.
    If the order is correct for the current position, then I just move onto the next employee.
    **/

    while((temp != NULL) && (check != 1)){
      check = 0;

      if (temp->nextEmployee->nextEmployee != NULL){
        if(temp->nextEmployee->empId > temp->nextEmployee->nextEmployee->empId){
          before = temp;
          swap = temp->nextEmployee;
          after = temp->nextEmployee->nextEmployee;
          before->nextEmployee = after;
          swap->nextEmployee = after->nextEmployee;
          after ->nextEmployee = swap;
          temp = headCpy;
        }

        else{
          temp = temp->nextEmployee;
        }
      }

      else if (temp->nextEmployee != NULL){
        temp = temp->nextEmployee;
      }

      if(temp->nextEmployee == NULL){
        check=1;
      }

  } //first while ends


  temp = headCpy;

  /**
  This block of code executes when the head is the node with the highest empId. It traverses through the list and makes sure the
  head is in the right position. I am also assigning the variable istLowest a value of 1, which will be a condition that is used 
  for the next if statement. This if statement is only executed when the head is the only node with the highest empId.
  **/ 

  while(temp != NULL){

    if(temp->empId < headCpy->empId){
      isntLowest = 1;
      before = temp;
      after = temp->nextEmployee;
    }


  temp = temp->nextEmployee;

  }

  if(isntLowest != 0){ 
    swap = headCpy;
    headCpy = headCpy->nextEmployee;
    before->nextEmployee = swap;
    swap->nextEmployee = after;
  }

  /**
  Finally, it prints new ordered list that is sorted and clears it as it is only supposed to be ordered for this function only.
  Thus I call the fireAll function to then erase the headCpy.
  **/
  printAll(headCpy);
  } 

  fireAll(&headCpy);
}

/**
This function is a function I created to help me with the sortEmployeesId function
The main purpose of this function is to copy whatever is in my actual linked list
into a new list. This is because in this function we are not supposed to 
change the order of the actual linked list. Thus, I created a copy function which 
copies all employee information into appropriate nodes. Once copied, it 
returns the copied linked list into the sortEmployeesId function.

**/

a3Emp * copy(struct employee * headLL){

  a3Emp * newNodeCpy = NULL;

  newNodeCpy = malloc(sizeof(a3Emp));

  strcpy(newNodeCpy->fname, headLL->fname);
  strcpy(newNodeCpy->lname, headLL->lname);
  newNodeCpy->numDependents = headLL->numDependents;

  newNodeCpy->dependents = calloc(headLL->numDependents, sizeof(char *));

  for(int i = 0; i < newNodeCpy->numDependents; i++){
    newNodeCpy->dependents[i] = calloc(strlen(headLL->dependents[i]) + 1, sizeof(char));
    strcpy(newNodeCpy->dependents[i], headLL->dependents[i]);

  }

  newNodeCpy->empId = headLL->empId;
  return newNodeCpy;
}

