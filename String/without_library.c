#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char ch[50];
    int i=0;
    printf("Enter a string: ");
    scanf("%[^\n]",&ch);
    while(ch[i]!='\0')
    {
        i++;
    }
    printf("The length of the string is: %d",i);
    getch();
}
