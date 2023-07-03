#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX], topA = -1, topB = MAX;
void pushA(int val)
{
    if (topA == topB - 1)
        printf("\nOverFlow");
    else
    {
        topA++;
        stack[topA] = val;
    }
}
int popA()
{
    int val; 
    if (topA == -1)
    {
        printf("\nUnderFlow");
        val = -999;
    }
    else
    {
        val = stack[topA];
        topA--;
    }
    return val;
}
void display_stackA()
{
    int i;
    if (topA == -1)
        printf("\nEmpty");
    else
    {
        for(i = topA; i>= 0; i--)
            printf("| %d | ", stack[i]);
    }
}
void pushB(int val)
{
    if (topB - 1 == topA)
        printf("\nOverFlow");
    else
    {
        topB--;
        stack[topB] = val;
    }
}
int popB()
{
    int val; 
    if (topB == MAX)
    {
        printf("\nUnderFlow");
        val = -999;
    }
    else
    {
        val = stack[topA];
        topB++;
    }
    return val;
}
void display_stackB()
{
    int i;
    if (topB == MAX)
        printf("\nEmpty");
    else
    {
        for(i = topB ; i <= MAX; i++)
            printf("| %d | ", stack[i]);
    }
}
int main()
{
    int option, val;
    do
    {
        printf("\n 1 : Push in Stack A");
        printf("\n 2 : Push in Stack B");
        printf("\n 3 : Pop  in Stack A");
        printf("\n 4 : Pop  in Stack B");
     /*printf("\n 5 : Peek in Stack A");
        printf("\n 6 : Peek in Stack B");*/
        printf("\n 5 : Display Stack A");
        printf("\n 6 : Display Stack B");
        printf("\n 7 : Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1 : printf("\nEnter The Number To Be Pushed into Stack A : ");
                     scanf("%d", &val);
                     pushA(val);
                     break;
            case 2 : printf("\nEnter The Number To Be Pushed into Stack B : ");
                     scanf("%d", &val);
                     pushB(val);
                     break;
            case 3 : val = popA();
                     if(val != -9999)
                        printf("\nThe value Poped from Stack A : %d", val);
                     break;
            case 4 : val = popB();
                     if(val != -9999)
                        printf("\nThe value Poped from Stack B : %d", val);
                     break;
            case 5 : printf("\nThe Stack A Is : ");
                     display_stackA();
                     break;
            case 6 : printf("\nThe Stack B Is : ");
                     display_stackB();
                     break;
        }
    } while (option != 7);
    return 0;
}