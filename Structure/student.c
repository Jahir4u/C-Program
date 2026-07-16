#include<stdio.h>
#include<conio.h>

int main() 
{
    struct student 
    {
        int roll;
        char name[20];
        float marks;
    };
    struct student s[50];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d",&n);

    for(i=0;i<n; i++) 
    {
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }
    printf("\nStudents with 75+ marks:\n");
    for(i=0; i<n; i++) 
    {
        if(s[i].marks >= 75)
            printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }

    return 0;
}
