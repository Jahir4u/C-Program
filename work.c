#include <stdio.h>

int main() 
{
    int fno,sno;
    printf("Enter the first Number: ");
    scanf("%d",&fno);
    printf("\nEnter the second number: ");
    scanf("%d",&sno);
    printf("Number Before Swapping: %d\t%d",fno,sno);
    swapno(fno,sno);
    return 0;
}
swapno (int a,int b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
        printf("\nNumber After swapping: %d\t%d",a,b);
    }


