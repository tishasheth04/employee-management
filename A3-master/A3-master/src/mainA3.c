#include "../include/headerA3.h"


/**
This main calls all the various functions.

**/

int main() {

/**
I have initialized multiple variables that will assist me in getting the desired output.

**/

  int userChoice = 0;
  int oneEmployee = 0;
  int empIdCheck = 0;
  int empPositionId = 0;
  int empPositionName = 0;
  char whichName[100];
  int countEmp = 0;
  int fire = 0;
  a3Emp * headLL = NULL;
  int check = 0;
  char fireCheck;

/**
There is a do-while loop that asks the user to enter a value.
Dependending on their value, a specific case is executed,
therefore a specific function is executed.This while loop runs
infinetely, until the user enters a "10". If the user enters "10"
the program exits.

**/

  loadEmpData(&headLL, "proFile.txt");
  do {
    printf("\n");
    printf("\nHere are the different options: \n");
    printf("1. Add a new employee \n");
    printf("2. Print data of all employees \n");
    printf("3. Print data of the nth employee \n");
    printf("4. Search for employee based on empld \n");
    printf("5. Search for employee based on full name \n");
    printf("6. Count the total number of employees \n");
    printf("7. Sort the employees based on their empld \n");
    printf("8. Remove the nth employee in the current LL \n");
    printf("9. Remove all employees in the current LL \n");
    printf("10. Exit \n");
    printf("\n");
    printf("\n");

    printf("Please enter your option: ");
    scanf("%d", &userChoice);
    printf("\n");

    switch(userChoice){

      /**
      This case is executed if the user enters a 1. When the user enters 1,
      the recruitEmployee function is called with the parameters being the headLL.

      **/

       case 1:
         printf("\n");
         recruitEmployee(&headLL);
         break;

      /**
      This case is executed if the user enters a 2. When the user enters 2,
      the printAll function is called with the parameters being the headLL.

      **/

      case 2:
        printAll(headLL);
        break;

      /**
      This case is executed if the user enters a 3. When the user enters 3,
      it first checks the value of the variable "check". If the value != 0,
      then only it goes and asks the user to enter a employee they want to print.
      Else, if check = 0, it means that the linked list is empty, therefore,
      it prints the appropriate message.

      **/

      case 3:
        check = countEmployees(headLL);

        if(check != 0){
          printf("Enter a value: ");
          scanf("%d", &oneEmployee);

          while(oneEmployee > check || oneEmployee <= 0){
            printf("Invalid input. Please enter a number between 1 and %d: ",check);
            scanf("%d", &oneEmployee);
          }

          printf("\n");
          printOne(headLL, oneEmployee);
        }

        else {
          printf("Error. The linked list is empty\n");
        }

        break;

      /**
      This case is executed if the user enters 4. If the user enters 4, 
      the lookOnId function is called. First it asks the user to enter a employee id.
      Then, it calls the function lookOnId with empPositionId grabbing the returned value.
      If the returned value is -1, then it prints the appropriate message indicating the 
      employee does niot exist. Else, it prints the information of the employee if the id matches.

      **/

      case 4:
        printf("Enter a employee id: ");
        scanf("%d", &empIdCheck);
        empPositionId = lookOnId(headLL, empIdCheck);

        if(empPositionId == -1){
          printf("\nThis employee does not exist.\n");
        }

        else {
          printf("\n");
          printOne(headLL, empPositionId);
        }

        break;

      /**
      This case executes if the user enter s 5. If the user enters 5, I first ask the user
      to enter a first name and last name. Then, I call the lookOnFullName function
      with the parameters being headLL, and the name the user entered.
      If the value being returned is -1, it indicates that the employee is not on the list 
      or that the list is empty. Thus, it prints a message indicating that. Else,
      if the user entered name match one in the linked list, the information about the 
      employee is printed out by calling the printOne function.

      **/

      case 5:

        getchar();
        printf("Enter a first name and last name: ");
        fgets(whichName,100, stdin);
        whichName[strlen(whichName) - 1] = '\0';
        empPositionName = lookOnFullName(headLL, whichName);

        if(empPositionName == -1){
          printf("\nError. The person does not exist\n");
        }

        else {
          printf("\n");
          printOne(headLL, empPositionName);
        }

        break;


      /**
      This case is executed if the user enters 6. If the user enters 6, 
      the countEmployees function is called with the parameters being headLL.
      If the value being returned is 0, it means the lsit is empty, thus an appropriate message
      is printed onto the screen indicating so.
      Else, it prints the total number of employees in the linked list.

      **/
    
      case 6:

        countEmp = countEmployees(headLL);

        if(countEmp == 0){
          printf("Error. The list is empty\n");
        }

        else {
          printf("There are %d employees.\n", countEmp);
        }

        break;

      /**
      This case is exceuted if the user enters a 7. If the user enters a 7,
      the sortEmployeesId function is called with the paramters being headLL.

      **/

      case 7:

        sortEmployeesId(headLL);
        break;

      /**
      This case is executed when the user enters 8. First, 
      countEmployees function is called with the parameter being headLL. The returned
      value is then stored into the check variable. 
      If check != 0,
      then only does the code execute. First, it prints the current number of employees.
      Then, it asks the user whihc one htey want to fire (making usre a valid input is inputted)
      Lastly, it calls the fireOne function with the paramter being headLL and the employee the user wants to fire.
      If check == 0, then it indicates the linked lsit is empty, thus an appropriate message is printed onto the screen.

      **/

      case 8:
        check = countEmployees(headLL);
       
        if(check != 0){
          printf("Currently, there are %d employees.\n", check);
          printf("Which employee would you like to fire- enter a number between 1 and %d: ", check);
          scanf("%d", &fire);

          while(fire > check || fire <= 0){
            printf("Enter a number between 1 and %d: ", check);
            scanf("%d", &fire);
          }

          fireOne(&headLL, fire);
        }

       else {
         printf("Error. The linked list is empty\n");
       }

       break;

      /**
      This code executes if the user enters 9 as their input. If so, first, 
      check is assigned the value of the number of employees in the linked list using the 
      countEmployees function. Then, if check != 0, the user is asked if they want to fire everyone. If they enter 'y' or 'Y', the fireAll function is called. 
      If the user enters any other letter, then no employee is fired.
      Finally, if the check value is 0, it indicates the linked list is empty, 
      thus a message indicating so is printed onto the screen.

      **/

      case 9:

        check = countEmployees(headLL);
        printf("\n");
        printf("Are you sure you want to fire everyone: ");
        getchar();
        scanf("%c", &fireCheck);

        if(fireCheck == 'y' || fireCheck == 'Y'){
          fireAll(&headLL);
        }

        else {
          printf("No employee is fired. You have %d employees!\n", check);
        }


        break;

      case 10:
        printf("Exiting the program \n");
        break;

      default: printf ("That is an invalid choice\n");

      }


   } while (userChoice != 10);

   return 0;
}

