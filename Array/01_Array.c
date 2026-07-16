#include<stdio.h>
#include<conio.h>
int main()
{
    int i=3, *x;
    float j=1.5,*y;
    char k ='c',*z;
    printf("Value of i = %d\n",i);
    printf("Value of j = %d\n",j);    
    printf("Value of k = %d\n",k);
    x =&i; y=&j; z=&k;   
    printf("original address in x = %u\n",x);
    printf("original address in y = %u\n",y);    
    printf("original address in z = %u\n",z);
    x++; y++; z++;
    printf("New address in x = %u\n",x);
    printf("New address in y = %u\n",y);
    printf("New address in z = %u\n",z);  
      
    return 0;
}