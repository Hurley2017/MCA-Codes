#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define r "r"
#define w "w"
#define a "a"
#define space " "
#define slash "/"
#define maxs 200
#define maxrecords 1000
#define maxn 50
#define empty ""
#define nl "\n"
#define wlocation "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/fq10/filex.bin"
typedef struct
{
    char fname[maxn], lname[maxn];
    int Roll_Number, bday, bmonth, byear;
    float marks;
} Student;
void takeinp(Student *s);
void gracify(Student *s);
void storeData(FILE *loc, Student s[], int n);
void store(FILE *loc, Student s);
int main()
{
    int n;
    FILE *loc; 
    printf("Number of Students.\n");
    scanf("%d", &n);
    Student s[maxrecords];
    printf("Taking input of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nReceiving data of Student Number %d\n", i+1);
        takeinp(&s[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(s[i].marks <50 && s[i].marks > 40)
        {
            gracify(&s[i]);
        }
    }
    loc = fopen(wlocation, w);
    storeData(loc, s, n);
    fclose(loc);
    return 0;
}
void storeData(FILE *loc, Student s[], int n)
{
    for(int i=0; i<n; i++)
    {
        store(loc, s[i]);
    }
}
void store(FILE *loc, Student s)
{
    char tempc[maxn];
    char statement[maxs];
    sprintf(statement, "%d", s.Roll_Number);
    strcat(statement, space);
    strcat(statement, s.fname);
    strcat(statement, space);
    strcat(statement, s.lname);
    strcat(statement, space);
    sprintf(tempc, "%d", s.bday);
    strcat(statement, tempc);
    strcat(statement, slash);
    sprintf(tempc, "%d", s.bmonth);
    strcat(statement, tempc);
    strcat(statement, slash);
    sprintf(tempc, "%d", s.byear);
    strcat(statement, tempc);
    strcat(statement, space);
    sprintf(tempc, "%f", s.marks);
    strcat(statement, tempc);
    strcat(statement, nl);
    fprintf(loc, "%s", statement);
    strcpy(statement, empty);
    strcpy(tempc, empty);
}
void gracify(Student *s)
{
    s->marks = s->marks + 10;
}
void takeinp(Student *s)
{
    printf("Enter full name : ");
    scanf("%s %s", s->fname, s->lname);
    printf("Enter Roll Number : ");
    scanf("%d", &s->Roll_Number);
    printf("Enter birthday : ");
    scanf("%d %d %d", &s->bday, &s->bmonth, &s->byear);
    printf("Enter marks : ");
    scanf("%f", &s->marks);
}