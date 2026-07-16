#include<stdio.h>
#include<stdio.h>
int main()
{
    int num1, num2, result;
    char op, choice;
    printf("________Simple calculator________");
    do
    {
        printf("\nEnter the first number: ");
        scanf("%d",&num1);
        printf("\nEnter the second number: ");
        scanf("%d",&num2);
        printf("\nEnter the operator (+, -, *, /): ");
        scanf(" %c",&op);
        if (op == '+')
        {
            result = num1 + num2;
            printf("\nresult: %d + %d = %d", num1, num2, result);
        }
        else if (op == '-')
        {
            result = num1 - num2;
            printf("\nresult: %d - %d = %d", num1, num2, result);
        }
        else if (op == '*')
        {
            result = num1 * num2;
            printf("\nresult: %d * %d = %d", num1, num2, result);
        }
        else if (op == '/')
        {
            if(num2 != 0)
            {
                result = num1 / num2;
                printf("\nResult: %d / %d = %d", num1, num2, result);
            }
            else
            {
                printf("\nError: Division by zero is not allowed.");
            }
        }
        else
        {
            printf("\nError: Invalid operator.");
        }
        printf("\nDo you want to perform another calculation? (Y/N): ");
        scanf(" %c",&choice);
    }
    while(choice == 'Y' || choice == 'y');
    return 0;
}