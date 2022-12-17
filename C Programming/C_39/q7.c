#include <stdio.h>
#include <stdlib.h>
#define location "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file3.txt"
void printmatx(int *matx);
int main()
{
    FILE *l;
    int n, *matx, count = 0, p = 0;
    l = fopen(location, "r");
    n = getc(l);
    while(n != EOF)
    {
        if(n == 10)
        {
            printf("\n");
        }
        else
        {
            printf("%d\t", n-48);
        }
        n = getc(l);
        count++; 
    }
    fclose(l);
    l = fopen(location, "r");
    matx = (int *)malloc(sizeof(int)*count);
    n = getc(l);
    while(n != EOF)
    {
        *(matx+p) = n;
        p++;
        n = getc(l);           
    }
    printf("\n");
    printmatx(matx);
    fclose(l);
    return 0;
}
void printmatx(int *matx)
{
    int p = 0;
    while(*(matx+p))
    {
        printf("%d ", *(matx+p));
        p++;
    }
    printf("\n");
}
