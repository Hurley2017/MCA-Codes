#include <stdio.h>
#define ns 100
#define maxrecord 1000
typedef struct
{
    char authorf[ns], authorl[ns], title[ns];
    float price, acc_num, issue; 
} Library;
void takeinp(Library *b);
void printinp(Library b);
int main()
{
    int n;
    Library b[maxrecord];
    printf("Enter the number of books : ");
    scanf("%d", &n);
    printf("Taking input of books one by one.\n");
    for(int i=0; i<n; i++)
    {
        printf("Receiving book information %d\n", i+1);
        takeinp(&b[i]);
    }
    printf("Printing the given structures : \n");
    for(int i=0; i<n; i++)
    {
        printf("Printing book information %d\n", i+1);
        printinp(b[i]);
    }
    return 0;
}
void printinp(Library b)
{
    printf("%s %s %s %f %f %f", b.authorf, b.authorl, b.title, b.acc_num, b.price, b.issue);
}
void takeinp(Library *b)
{
    printf("Author Name : ");
    scanf("%s %s",b->authorf, b->authorl);
    printf("Book Title : ");
    scanf("%s", b->title);
    printf("Accession Number : ");
    scanf("%f", &b->acc_num);
    printf("Price : ");
    scanf("%f", &b->price);
    printf("Issued? [Press '1' for 'YES' or Press '0' for 'NO']");
    scanf("%f", &b->issue);
}
