#include<stdio.h>
#include<conio.h>
void mian()
{
    int stud[4][2];
    int i;
    for(i=0;i<3;i++)
    {
        printf("Enter roll no and marks: ");
        scanf("%d %d",&stud[i][0],&stud[i][1]);
    }
    for(i=0;i<3;i++)
    {
        printf("\nThe roll no and marks of the student are: %d %d",stud[i][0],stud[i][1]);
    }
    getch();
}