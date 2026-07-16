#include<stdio.h>
#include<conio.h>
void main()
{
    int mark[2][3]={{85,90,95},{80,70,75}};
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",mark[i][j]);
        }
        printf("\n");
    }
    getch();
}