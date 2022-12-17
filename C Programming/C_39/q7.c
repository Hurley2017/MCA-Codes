#include <stdio.h>
#include <stdlib.h>
#define rlocation "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file3.txt"
#define wlocation "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file4.txt"
void printmatx(int *matx);
void printmax(int max[][2], int row);
int main()
{
    FILE *l;
    int n, *matx, newline = 0, row = 0, sum = 0, count = 0, p = 0;
    l = fopen(rlocation, "r");
    n = getc(l);
    while(n != EOF)
    {
        if(n == 10)
        {
            printf("\n");
            newline++;
        }
        else
        {
            printf("%d\t", n-48);
        }
        n = getc(l);
        count++; 
    }
    fclose(l);
    l = fopen(rlocation, "r");
    matx = (int *)malloc(sizeof(int)*count);
    int max[newline][2]; 
    n = getc(l);
    while(n != EOF)
    {
        if(n != 10)
        {
            sum = sum + n-48;
        }
        else
        {
            max[row][0] = row;
            max[row][1] = sum;
            row++;
            sum = 0;
        }
        *(matx+p) = n;
        p++;
        n = getc(l);           
    }
    max[row][0] = row;
    max[row][1] = sum;
    printf("\n");
    printmax(max, row);
    printmatx(matx);
    fclose(l);
    return 0;
}
void printmax(int max[][2], int row)
{
    int i = 0;
    while(i<=row)
    {
        for(int j=0; j<2; j++)
        {
            printf("%d\t", max[i][j]);
        }
        printf("\n");
        i++;
    }
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
