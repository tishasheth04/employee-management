#include "../include/headerA3.h"

/**
This function's main purpose is to add a new employee. The paramters of this function 
consist of the double pointer of the linked list head. First I have created multiple 
variables that will assist me in getting the desired output. Next, I have dynamically allocated space for a node. Then, I check if the head is null, indicating 
that this is the first employee in the linked list. In this case I make headLL = temp (space dynamically allocated for the linked list) and newPtr = the head.
Once that is done, I ask the user to enter multiple things such as the employee's first name, last name, and dependents.
The space for dependents is dynamically allocated and reallocs as necessary.
Depending on the number of dependents, specific messages are printed onto the screen.
Finally, a employee id is assigned based on the first name and last name and if the emp id already exists, a rand id is assigned to the employee.

**/

void recruitEmployee (struct employee ** headLL){
 
  //This is done so that the random function actually generates a rand value.
  srand(time(0));

  //Variables used to assist me in getting the desired output.
  int count = 1;
  int sum = 0;
  int id = 0;
  int check = 0;
  char userChoice = 'y';
  int dependentCount = 0;
  a3Emp * newPtr = NULL;
  newPtr = *headLL;

  a3Emp * temp= malloc(sizeof(a3Emp));

  char notTemp[MAX_LENGTH];

  if(*headLL == NULL){
    *headLL = temp;
    newPtr = *headLL;
    check = 1;
  }


  //This block of code asks the user to enter employee information.
  printf("Enter the first name of the employee: ");
  scanf("%s", temp->fname);

  printf("\n");

  printf("Enter the last name of the employee: ");

  scanf("%s", temp->lname);
  printf("\n");

  temp->dependents = malloc(sizeof(char *));

  //This block of code runs until the user says yes when asked if they have another dependent.
  while(userChoice == 'y' || userChoice == 'Y'){

    temp->dependents = realloc(temp->dependents, sizeof(char *) * (count + 1));
    printf("Enter name of dependent #%d: ", count); 
    scanf("%s", notTemp);

    temp->dependents[count - 1] = malloc(sizeof(char) * (strlen(notTemp) + 1));
    strcpy(temp->dependents[count - 1],notTemp);

    count++;
    dependentCount++;
    getchar();
    printf("Do you have any more dependents? ");
    scanf("%c", &userChoice);
    printf("\n");
  }  // end of while

  if(dependentCount == 1){
    printf("You have one dependent\n");
  }// end of if

  else{
    printf("You have %d dependents\n", dependentCount);
  }// end of else

  temp->numDependents = dependentCount;

  //This block of code assigns a employee id to the employee being added
  for(int i = 0; i < strlen(temp->fname); i++){
    sum = sum + (int)(temp->fname[i]);
  }


  id = sum + strlen(temp->lname);

  temp->empId = id;

  while((temp != *headLL) && newPtr != NULL ){
  
    if(newPtr->empId == temp->empId && check != 1){
      temp->empId = rand() % 1000 + 1;
    }

    newPtr = newPtr->nextEmployee;
  }

  newPtr=*headLL;

  while((temp != *headLL) && newPtr->nextEmployee != NULL){
    newPtr = newPtr->nextEmployee;
  } //end of while

  newPtr->nextEmployee  = temp;

  printf("Your computer generated id is: %d", temp->empId);
  temp->nextEmployee = NULL;
}//end of function
