#include<stdio.h>
#include<conio.h>
int main()
{
    struct book
    {
        int id;  /* data */
        char name[100];
        char author[100];
    };
    struct book b[100];
    int choice, count=0, i, searchId;

    while(1)
    {
        printf("\n<|------Library Managenemt System ------|>\n");
        printf("1. Add book\n");
        printf("2. Display book\n");
        printf("3. Search book\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf(" %d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter book Id: ");
            scanf(" %d",&b[count].id);

            printf("Enter Book Name: ");
            scanf(" %[^\n]",b[count].name);

            printf("Enter Author Name: ");
            scanf(" %[^\n]",b[count].author);

            count++;
            printf("Book Added Successfully!!\n");
            break;

            case 2:
            if (count == 0)
            {
                printf("No Books Avaible....\n");
            }
            else
            {
                for(i = 0; i<count; i++)
                {
                    printf("\nBook Id: %d",b[i].id);
                    printf("\nBook Name: %s",b[i].name);
                    printf("\nAuthor Name: %s\n",b[i].author);
                }
            }
            break;

            case 3:
            printf("Enter Book Id to search: ");
            scanf(" %d",&searchId);
            for ( i = 0; i < count; i++)
            {
                if(b[i].id == searchId)
                {
                    printf("\nBook Found!!");
                    printf("\nBook Name: %s",b[i].name);
                    printf("\nAuthor Name: %s\n",b[i].author);
                    break;
                }
            }
            if (i == count)
            {
                printf("Book Not Found!!\n");
            }
            break;
            case 4:
            
            printf("Thank You!!\n");
            return 0;

            default:
            printf("Invalid Choice!!\n");
            
        }
    }
}