#include <stdio.h>

float balanceAmount = 0; // intial balance to be zero for everyone 
int anotherTransaction; //Variale to check if the user wants to perform multiple transactions
int WidthdrawAmt; //Variable to store the amount of money the customr wants to withdraw
int DepositAmt; //Variable to store the amount of money the customr wants to Deposit


void transaction(){
  int choice; 
  printf("************************************\n");
  printf("*************** A T M **************\n");
  printf("************************************\n");
  printf("Enter the desired option!\n\n");
  printf("1. Withdraw\n"); 
  printf("2. Deposit\n"); 
  printf("3. Balance\n");
  printf("Enter you choice by choosing the desired number among 1,2 and 3\n");
  printf("************************************\n");
  scanf("%d",  &choice); 
 
  
  switch(choice){
    case 1:
    // first option should be withdraw
    printf("Please enter amount to withdraw: "); 
    scanf("%d", &WidthdrawAmt); 
    if(WidthdrawAmt > balanceAmount){
      printf("There is no insuffient funds in your account"); 
      // ask them for another transaction
      printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      scanf("%d", &anotherTransaction); 
      if(anotherTransaction == 1){
        // call our transaction method here
        transaction();
      }
    } else {
      // this means account has something
      // so withdraw amount and update the balance variable 
      balanceAmount = balanceAmount - WidthdrawAmt; 
      
      printf("You have withdrawn %d and your new balance is %f ", WidthdrawAmt, balanceAmount);
      
      // request for another transaction
      printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      scanf("%d", &anotherTransaction); 
      if(anotherTransaction == 1){
        // call our transaction method here
        transaction();
      }
      
      
    }
    break; 
    
    case 2:
    // DEPOSIT
    
   
    printf("Please enter amount to deposit: "); 
    scanf("%d", &DepositAmt); 
    // now that you have deposited something, update the balance variable
    
    balanceAmount = DepositAmt + balanceAmount; 
    
    printf("Thank you for depositing, new balance is: %f", balanceAmount); 
    
    // request for another transaction
      printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      scanf("%d", &anotherTransaction); 
      if(anotherTransaction == 1){
        // call our transaction method here
        transaction();
      }
    
    break; 
    
    case 3:
    
    // BALANCE
    printf("Your bank balance is: %f", balanceAmount); 
    
    // request for another transaction
      printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      scanf("%d", &anotherTransaction); 
      if(anotherTransaction == 1){
        // call our transaction method here
        transaction();
      }
    break;
  }
}

int main(){
  transaction();
  return 0;
}