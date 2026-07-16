#include <stdio.h>
#include<conio.h>
void main() 
{
    int arr[5],i; 
    //int i;
    for(i = 0; i < 5; i++)
    {
      printf("Enter 5 numbers %d:",i+1);
      scanf("%d", &arr[i]);
    }
    printf("You entered number of array:\n"); 
    for(i = 0; i < 5; i++) 
    {
        printf("%d ", arr[i]);
    }
    getch();
}