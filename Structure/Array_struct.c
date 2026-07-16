#include<stdio.h>
#include<conio.h>
void main()
{
    struct book
    {
    char name;
    float price;
    int pages;
    };
    struct book B1,B2;
    printf("Enter name,Price and no of pages of 2 book's: ");
    scanf("%c %f %d",&B1.name,&B1.price,&B1.pages);
    scanf("%c %f %d",&B2.name,&B2.price,&B2.pages);
    
    printf("The detailes of the book: ");
    printf("%c %f %d",B1.name,B1.price,B1.pages);
    printf("%c %f %d",B2.name,B2.price,B2.pages);
    getch();
}