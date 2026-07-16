#include<stdio.h>
#include<conio.h>
void main()
{
    int num, temp, rev=0,remainder;
    printf("Enter any number: ");
    scanf("%d",&num);
    printf("%d\n",num);
    temp=num;
    while(num!=0)
    {
        remainder = num%10;
        num = num/10;
        rev = rev*10+remainder;
    }
    printf("Reverse of the number %d = %d\n",temp,rev);
    getch();
}