#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#define maxrecord 1000
#define maxn 500
#define read "rb"
#define write "wb"
#define append "ab" 
#define extension ".bin"
#define locationbackup "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/fq10/"    
typedef struct
{
    char fname[maxn], lname[maxn];
    int Roll_Number, bday, bmonth, byear;
    float marks;
} Student;
void gracify(Student *s);
void storeinfiles(Student s[], FILE *file[], int n);
void takeinp(Student *s);
void initfiles(FILE *file[], Student s[], int n);
void closefiles(FILE *file[], int n);
void storestatement(char statement[], FILE *file);
void fdelete(int rm);
void store(Student s, FILE *file);
void init(FILE *file, Student s);
int main()
{
    int n, sw, rm, ex = 0;
    char tempc[maxn], location[maxn];
    printf("Number of Students : ");
    scanf("%d", &n);
    Student s[maxrecord];
    FILE *file[maxrecord], *re;
    printf("Taking input of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nReceiving data of Student Number %d", i+1);
        takeinp(&s[i]);
    }
    initfiles(file, s, n);
    for(int i=0; i<n; i++)
    {
        if(s[i].marks <50 && s[i].marks > 40)
        {
            gracify(&s[i]);
        }
    }    
    storeinfiles(s, file, n);
    closefiles(file, n);
    restart:
    printf("\n1) Add a new record\n2) Delete a record.\n3) Exit.\n\n Enter choice : ");
    scanf("%d", &sw);
    switch(sw)
    {
        case 1:
            printf("\n\n");
            takeinp(&s[n+ex]);
            init(file[n+ex], s[n+ex]);
            store(s[n+ex], file[n+ex]);
            fclose(file[n+ex]);
            ex++;
        case 2:
            printf("\nEnter roll number to delete record.\n");
            scanf("%d", &rm);
            fdelete(rm);
            goto restart;
        case 3:
            return 0;   
        default:
            printf("Invalid input.\nRestarting.\n");
            goto restart;
    }
    return 0;
}
void fdelete(int rm)
{
    char tempc[maxn], location[maxn];
    FILE *re;    
    sprintf(tempc, "%d", rm);
    strcat(tempc, extension);
    strcpy(location, locationbackup);
    strcat(location, tempc);
    re = fopen(location, read);
    if(re != NULL)
    {
        remove(location);
    }
    else
    {
        printf("File/Record doesn't exist.\n");
    }
    fclose(re);
}
void gracify(Student *s)
{
    s->marks = s->marks + 10;
}
void store(Student s, FILE *file)
{
    char tempc[maxn], statement[maxn];
    strcpy(statement, "");
    strcat(statement, s.fname);
    strcat(statement, " ");
    strcat(statement, s.lname);
    strcat(statement, " ");
    sprintf(tempc, "%d", s.bday);
    strcat(statement, tempc);
    strcat(statement, "/");
    sprintf(tempc, "%d", s.bmonth);
    strcat(statement, tempc);
    strcat(statement, "/");
    sprintf(tempc, "%d", s.byear);
    strcat(statement, tempc);
    strcat(statement, " ");
    sprintf(tempc, "%f", s.marks);
    strcat(statement, tempc);
    storestatement(statement, file);
}
void storeinfiles(Student s[], FILE *file[], int n)
{
    for(int i=0; i<n; i++)
    {
        store(s[i], file[i]);
    }
}
void storestatement(char statement[], FILE *file)
{
    int i = 0;
    while(statement[i] != '\0')
    {
        putc(statement[i], file);
        i++;
    }
}
void closefiles(FILE *file[], int n)
{
    for(int i=0; i<n; i++)
    {
        fclose(file[i]);
    }

}
void init(FILE *file, Student s)
{
    char tempc[maxn], location[maxn];
    strcpy(location, locationbackup);
    sprintf(tempc, "%d", s.Roll_Number);
    strcat(location, tempc);
    strcat(location, extension);
    file = fopen(location, write);
}
void initfiles(FILE *file[], Student s[], int n)
{    
    for(int i=0; i<n; i++)
    {
        init(file[i], s[i]);
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