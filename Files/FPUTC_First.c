#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *fp;
    char letter;
    fp = fopen("myfile1.txt", "w");
    if(fp == NULL)
    {
        printf("\nCannot open File.");
        exit(1);
    }
    printf("\nEnter Name. Press enter to end : ");
    do
    {
        letter = getchar();
        if(letter = '\n')
           break;
        fputc(letter, fp);  
    }while(1);
    
    fclose(fp);
    return 0;
}