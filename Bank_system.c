#include<stdio.h>   //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()
#include <time.h>   //time(),ctime()

char name[20];//global variables
int deposit_amount, total_amount =1000, acc_no, count = 0 ;

//procalling of the function
void Menu();
void Deposit_money();
void Withdraw_money();
void Transfer_money();
void Account_details();
void Transaction_details();
void LastDetail();

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}
int main()
{
    FILE *ptr = fopen("Account.txt", "w");

    int choice;
    printf("Enter your name : ");//asking name of user
    gets(name);
    fprintf(ptr, "\nName : %s\n", name);

    printf("Enter your account number : ");//asking account number
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);
    
    fclose(ptr);
    while(1)    //loop is used if user wants to perform multiple things
    {
        Menu();//executing the function
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)//checking the choice of user
        {
        case 1:
            system("cls");
            Deposit_money();
            break;

        case 2:
            system("cls");
            Withdraw_money();
            break;

        case 3:        
            system("cls");
            Transfer_money();
            break;

        case 4:
            system("cls");
            Account_details();
            break;

        case 5:
            Transaction_details();
            break;

        case 6:
            system("cls");
            LastDetail();
            exit(0);
        default:
            printf("*****INVALID CHOICE !!! ******");
    }
}
      return 0;
}
void Menu()    //making function for displaying menu
{
    system("cls");
    divider();
    printf("\n\tMAIN MENU \n");

    divider();
    printf("\n1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Account Details\n");
    printf("5. Transaction Details\n");
    printf("6. Exit\n");
    divider();     
}
void Deposit_money()     //if user wnats to make deposit money
{
    time_t tm; //declaring a variable tm as time_t(just like int)
    time(&tm);

    //opening a file named Account.txt by a using pointer ptr here "a" is used as it will create a file if it does not exist
    FILE *ptr = fopen("Account.txt","a");
    printf("*****DEPOSITING MONEY*****\n");
     for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount : ");
    scanf("%d",&deposit_amount);

    total_amount += deposit_amount;
    printf("\n******MONEY DEPOSITED******\n");
    printf("Current Balance = %d\n", total_amount);

    //fprint is used to print in file 
    fprintf(ptr,"Rs %d has been deposited to your bank account\n",deposit_amount);
    fprintf(ptr,"Date /time of transaction : %s\n ", ctime(&tm));
    count++;

    fclose(ptr);//closing the file
    printf("Press any key....\n");
    getch();    //hold the screen at same place

}
void Withdraw_money()   //if user wants to withdraw money
{   
    int withdraw_amount;

    time_t tm;
    time(&tm);
 
    FILE *ptr = fopen("Account.txt","a");

    printf("******WITHDRAWING MONEY******\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\nEnter the amount : ");
    scanf("%d",&withdraw_amount);
    
    if (total_amount < withdraw_amount)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        total_amount = total_amount - withdraw_amount;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %d\n", total_amount);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", withdraw_amount);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");

    getch();
}
void Transfer_money()//if user wants to transfer money
{   
    int transfer_amount, ac;
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("Enter the amount you want to transfer : ");
    scanf("%d",&transfer_amount);
    printf("Enter the account number in which you want to transfer the money :  \n");
    scanf("%d", &ac);

    if(total_amount < transfer_amount )
    {
        printf("You don't have sufficient money to do transaction.\n");
    }
    else
    {
        total_amount -= transfer_amount;
        printf("MONEY TRANSFERRED\n");
        printf("Current Balance : %d", total_amount);
        
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", transfer_amount, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();

}
void Account_details()//if user wants his bank details
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n Name : %s\n",name);
    printf("Account No : %d\n",acc_no);
    printf("Total balance : %d\n",total_amount);
    printf("%d transactions have been made in your account",count);
    printf("enter any key.....");
    getch();
}
void Transaction_details()//if user wants his transaction details
{
    system("cls");
    FILE *ptr;
    ptr = fopen("Account.txt","r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n******NO RECENT TRANSACTION******\n");
    }
    else
    {
        printf("\nTRANSACTION DETAILS \n");
        divider();
        printf("\n%d transactions have been made in your account",count);
        while (c != EOF)
        {
            printf("%c",c);
            c=fgetc(ptr);

        }
    
    }
    getch();
}
void LastDetail()//last details of user 
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", total_amount);

    printf("\n\nPress any key to exit.....");
    getch();
}