#include <stdio.h>
#define maxn 50
#define start 1
typedef struct
{
    long long acc_num, curr_bal;
    char fname[maxn], lname[maxn];
} Janata;
void function1(Janata c[], int n);
void function2(Janata c[], int n);
void takeinp(Janata *c);
int main()
{
    int n, sw;
    printf("Enter the number of customers.\n");
    scanf("%d", &n);
    Janata c[n];
    for(int i=0; i<n; i++)
    {
        printf("\n\nEnter the data of customer %d\n", i+1);
        takeinp(&c[i]);
    }
    restart:
    system("clear");
    printf("\n1)View all customers having less than 1000/- in their account.\n2)Enter transaction mode.\n3) Clear Screen.\n4)Exit.");
    switch (sw)
    {
        case 1:
            printf("\nDisplaying all name of the customers with account balance less than 1000/- .\n");
            function1(c, n);
            goto restart;
            break;
        case 2:
            printf("\nIn transaction mode.\n");
            function2(c, n);
            goto restart;
            break;
        case 3:
            system("clear");
            goto restart;
        case 4:
            return 0;
        default:
            printf("invalid input.\n");
            goto restart;
            break;
    }
    return 0;
}
void function2(Janata c[], int n)
{
    
}
void function1(Janata c[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(c[i].curr_bal < 1000)
        {
            printf("%s %s\t", c[i].fname, c[i].lname);
        }
    }
}
void takeinp(Janata *c)
{
    printf("Account Holder : ");
    scanf("%s %s", c->fname, c->lname);
    printf("Account Number : ");
    scanf("%lld", &c->acc_num);
    printf("Account Balance : ");
    scanf("%lld", &c->curr_bal);
}
