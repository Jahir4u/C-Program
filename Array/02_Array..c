#include<stdio.h>
#include<conio.h>
int main()
{
    int arr1[5],arr2[5],i,j;
    printf("\nEnter 5 elements of array: ");
    for(i=0; i<=4; i++)
        scanf("%d",&arr1[i]);
    for(i=0, j=4;i<=4; i++,j--)
        arr1[j] = arr1[i];
    printf("Elements in reserse order:\n");
    for(i=0;i<=4;i++)
        printf("%d\t",arr2[i]);
    return 0;
}