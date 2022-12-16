#include <stdio.h>
#define maxn 50
typedef struct
{
    long long acc_num, curr_bal;
    char fname[maxn], lname[maxn];
} Janata;
void takeinp(Janata *c);
int main()
{
    int n;
    printf("Enter the number of customers.\n");
    scanf("%d", &n);
    Janata c[n];
    for(int i=0; i<n; i++)
    {

    }
    return 0;
}
void takeinp(Janata *c)
{
    printf("Account Holder : ");
    scanf("%s %s", c->fname, c->lname);
    printf("Account Number : ");
    scanf("%ld", c->acc_num);
    printf("Account Balance : ");
    scanf("%ld", c->curr_bal);
}