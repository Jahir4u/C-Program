#include<stdio.h>
#include<conio.h>
void main()
{
    float area,radious;
    float pi = 3.14;
    printf(" Enter the area of the curcle: ");
    scanf("%f",&area);
    radious = sqrt(area/pi);
    printf("The radious of the curcle : %.2f",radious);
    getch();
}