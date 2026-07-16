#include<stdio.h>
#include<conio.h>
int main()
{
 struct book{
    char name[20];
    int price;
    int pages;
    };
    struct book b[3];
    int i;
    for(int i=0;i<3;i++) 
    {
        printf("Enter name price and pages: ");
        scanf("%s %d %d",&b[i].name,&b[i].price,&b[i].pages);
    }
    for(int i=0;i<3;i++) 
    {
        printf("The name, price and pages are: %s %d %d\n",b[i].name,b[i].price,b[i].pages);
    }
    return 0;
}