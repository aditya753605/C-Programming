#include<stdio.h>
int main()
{   
    char operator;

    float a, b;

    //enter first number
    printf("enter 1st number : ");
    scanf("%f",&a);

    //enter the operator
    printf("Enter the operator ( +, -, *, / ) : ");
    scanf(" %c",&operator);

    //enter second number
    printf("enter 2nd number : ");
    scanf("%f",&b);

    switch (operator)
    {
    case '+':
        printf("%.2f + %.2f = %.2f ",a, b , a + b);
        break;

    case '-':
        printf("%.2f - %.2f = %.2f ",a, b , a - b);
        break;

    case '*':
        printf("%.2f * %.2f = %.2f ",a, b , a * b);
        break;
    
    case '/':
        if(b != 0.0)
            printf("%.2f / %.2f = %.2f ",a, b , a / b);
        else 
            printf("Divide by zero not possible.");
        break;
    
    default:
        printf("Invalid Operator");
        break;
    }



}