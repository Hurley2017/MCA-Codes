#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char fname[50];
    char lname[50];
    int Roll_Number;
    int Sub[5];
} Student;
void takeinp(Student *s);
void disp(Student s);
int main()
{
    int n;
    printf("Number of Students : ");
    scanf("%d", &n);
    Student s[n];
    printf("Taking input of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nReceiving data of Student Number %d\n", i+1);
        takeinp(&s[i]);
    }
    printf("\nDisplaying output of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nStudent Number %d - ", i+1);
        disp(s[i]);
    }
    return 0;
}
void disp(Student s)
{
    printf("\nName : %s %s", s.fname, s.lname);
    printf("\nRoll : %d\n", s.Roll_Number);
    int sum = 0;
    for(int i=0; i<5; i++)
    {
        sum = sum + s.Sub[i];   
    }
    printf("Total marks : %d\n", sum);
}
void takeinp(Student *s)
{
    printf("\nEnter first name : ");
    scanf("%s", s->fname);
    printf("Enter second name : ");
    scanf("%s", s->lname);
    printf("Enter Roll Number : ");
    scanf("%d", &s->Roll_Number);
    for(int i=0; i<5; i++)
    {
        printf("Enter marks %i : ", i+1);
        scanf("%d", &s->Sub[i]);
    }
}