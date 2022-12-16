#include <stdio.h>
#include <stdlib.h>
char convertUpper(char c);
int main()
{
    FILE *file1, *file2;
    char temp;
    file1 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file1.txt", "r");
    file2 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file2.txt", "w");
    while(1)
    {
        temp = getc(file1);
        if(temp != EOF)
        {
            if(temp >=97 && temp <=122)
            {
                putc(convertUpper(temp), file2);
            }
            else
            {
                putc(temp, file2);
            }
        }
        else
        {
            break;
        }  
    }
    fclose(file1);
    fclose(file2);
}
char convertUpper(char c)
{
    return (c-32);
}