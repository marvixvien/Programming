#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int st[MAX], top = -1;
void push(int *st, int val)
{
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
    {
        top++;
        st[top] = val;
    }
}
int pop(int *st)
{
    int val;
    if(top == -1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
    return val;
}
int peek(int *st)
{
    if (top == -1)
    {
        printf("\nStack is Empty");
        return -1;
    }
    else
        return (st[top]);
}
void display(int *st)
{
    int i; 
    if(top == -1) 
        printf("Empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("| %d | ", st[i]);
        printf("\n");
    }
}
int main()
{
    int val, option;
    do
    {
        printf("\n*****MAIN MENU*****\n");
        printf("\n 1 : Push");
        printf("\n 2 : Pop");
        printf("\n 3 : Peek");
        printf("\n 4 : Display");
        printf("\n 5 : Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1 : printf("\nEnter The Number To Be Pushed into Stack : ");
                     scanf("%d", &val);
                     push(st, val);
                     break;
            case 2 : val = pop(st);
                     if (val != -1)
                         printf("\nThe value Deleted from Stack : %d", val);
                     break;
            case 3 : val = peek(st);
                     if(val != -1)
                        printf("\nThe Value Stored at top of stack is : %d", val);
                    break;
            case 4 : printf("\nThe Stack Is : ");
                     display(st);
        }
    } while (option != 5);
    return 0;    
}
