#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#define maxn 500
typedef struct
{
    char fname[maxn], lname[maxn];
    int Roll_Number, bday, bmonth, byear;
    float marks;
} Student;
void storeinfiles(Student s[], FILE *file[], int n);
void takeinp(Student *s);
void initfiles(FILE *file[], Student s[], int n);
void closefiles(FILE *file[], int n);
int main()
{
    int n;
    printf("Number of Students : ");
    scanf("%d", &n);
    Student s[n];
    FILE *file[n];
    printf("Taking input of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nReceiving data of Student Number %d", i+1);
        takeinp(&s[i]);
    }
    initfiles(file, s, n);
    storeinfiles(s, file, n);
    closefiles(file, n);
    return 0;
}
void storeinfiles(Student s[], FILE *file[], int n)
{
    for(int i=0; i<n; i++)
    {
        
    }
}
void closefiles(FILE *file[], int n)
{
    for(int i=0; i<n; i++)
    {
        fclose(file[i]);
    }

}
void initfiles(FILE *file[], Student s[], int n)
{
    char location[maxn] = "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/fq10/";
    char locationbackup[maxn] = "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/fq10/";
    char extension[maxn] = ".bin";
    for(int i=0; i<n; i++)
    {
        char tempc[maxn];
        sprintf(tempc, "%d", s[i].Roll_Number);
        strcat(location, tempc);
        strcat(location, extension);
        file[i] = fopen(location, "wb");
        strcpy(location, locationbackup);
    }
}
void takeinp(Student *s)
{
    printf("\nEnter full name : ");
    scanf("%s %s", s->fname, s->lname);
    printf("Enter Roll Number : ");
    scanf("%d", &s->Roll_Number);
    printf("\nEnter birthday : ");
    scanf("%d %d %d", &s->bday, &s->bmonth, &s->byear);
    printf("Enter marks : ");
    scanf("%f", &s->marks);
}