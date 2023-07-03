#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char sent[80];
    fp = fopen("myFile2.txt", "w");
    if(fp == NULL)
    {
        printf("\nCannot Open File");
        exit(1);
    }
    printf("\nEnter Sentence to Store : ");
    gets(sent);
    fputs(sent, fp);
    fputs("\n", fp);
    fclose(fp);
    return 0;
}