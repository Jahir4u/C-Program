#include<stdio.h>
#include<conio.h>
int main()
{
    char name;
    int age;
    float mark;
    printf("Enter the name: ");
    scanf(" %c",&name);
    printf("Enter the age: ");
    scanf(" %d",&age);
    printf("Enter the mark: ");
    scanf(" %f",&mark);

    printf("\n----student details----\n");
    printf("Name:%c",name);
    printf("\nage:%d",age);
    printf("\nmark:%f",mark);
    return 0;
}