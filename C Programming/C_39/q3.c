#include <stdio.h>
#define maxn 50
typedef struct
{
    long long acc_num, curr_bal;
    char fname[maxn], lname[maxn];
} Janata;
void function1(Janata c[], int n);
void takeinp(Janata *c);
int main()
{
    int n;
    printf("Enter the number of customers.\n");
    scanf("%d", &n);
    Janata c[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the data of customer %d\n", i+1);
        takeinp(&c[i]);
    }
    printf("Displaying all name of the customers with account balance less than 1000/- .\n");
    function1(c, n);
    return 0;
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