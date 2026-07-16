#include<stdio.h>
#include<conio.h>
void main()
{
    int f,sum;
    printf("Enter the temprature to fahrenheit: ");
    scanf("%f", &f);
    sum=(f-32)*5/9;
    printf("Temperature in Celsius: %.2f",sum);
    getch();
}