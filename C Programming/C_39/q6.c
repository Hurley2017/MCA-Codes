#include <stdio.h>
#include <string.h>
#define ms 100
#define maxsize 1000
void fixstd();
typedef struct
{
    float price, acc_num, issued;
    char title[ms], author[ms];
} Library;
void disptit(Library b[maxsize], int n);
void disinp(Library b);
void takeinp(Library *b);
void sortbyauth(Library b[maxsize], int n, char* auth);
int chechsim(char*, char*);
int main()
{
    int n;
    char auth[ms];
    Library b[maxsize];
    printf("Enter number of books : ");
    scanf("%d", &n);
    fixstd();
    printf("Receiving inputs of %d books.\n", n);
    for(int i = 0; i<n; i++)
    {
        printf("Book : %d\n", i+1);
        takeinp(&b[i]);
    }
    printf("Printing book information.\n");
    for(int i=0; i<n; i++)
    {
        printf("Book : %d\n", i+1);
        disinp(b[i]);
    }
    printf("Sort by author : \nAuthor Name : ");
    fgets(auth, ms, stdin);
    sortbyauth(b, n, auth);
    disptit(b, n);
    return 0;
}
void disptit(Library b[maxsize], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Book : %d [Title : %s]", i+1, b[i].title);
    }
}
int chechsim(char* a, char* b)
{
    int i = 0;
    while(*(a+i) != '\0' && *(b+i) != '\0')
    {
        if(*(a+i) != *(b+i))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void sortbyauth(Library b[maxsize], int n, char* auth)
{
    for(int i=0; i<n; i++)
    {
        if(chechsim(b[i].author, auth))
        {
            printf("Book : %d\n", i+1);
            disinp(b[i]);
        }
    }
}
void disinp(Library b)
{
    printf("Author : %s", b.author);
    printf("Title : %s", b.title);
    printf("Price : %f\n", b.price);
    printf("Accession Number : %f\n", b.acc_num);
    printf("Issued['0'-> Yes and '1'-> No] : %f\n", b.issued);
}
void fixstd()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void takeinp(Library *b)
{
    printf("Author : ");
    fgets(b->author, ms, stdin);
    printf("Title : ");
    fgets(b->title, ms, stdin);
    printf("Price : ");
    scanf("%f", &b->price);
    fixstd();
    printf("Accession Number : ");
    scanf("%f", &b->acc_num);
    fixstd();
    printf("Issued?['0'-> Yes and '1'-> No] : ");
    scanf("%f", &b->issued);
    fixstd();
}
