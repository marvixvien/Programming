#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 500
float st[MAX], st2[50];
int top = -1, top2 = -1;;
void push(float st[], float val)
{
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
        st[++top] = val;
}
float pop(float st[])
{
    float val = -1;
    if (top == -1)
        printf("\nStack Underflow");
    else
        val = st[top--];   
    return val;
}
void reverse(char str[])
{
    int n, i;
    n = strlen(str) ;
    for ( i = 0; i < n; i++)
        st2[++top2] = str[i];
    for ( i = 0; i < n; i++)
    {
        str[i] = st2[top2--];
    }
    str[i] = '\0';
}
float evaluateprefix(char exp[])
{
    int i = 0;
    float op1, op2, value;
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
            push(st, (float)(exp[i] - '0'));
        else
        {
            op1 = pop(st);
            op2 = pop(st);
            switch(exp[i])
            {
                case '+' : value = op1 + op2;
                          break;
                case '-' : value = op1 - op2;
                          break;
                case '/' : value = op1/op2;
                          break;
                case '*' : value = op1 * op2;
                          break;
                case '%' : value = (int)op1 % (int)op2;
                          break; 
            }
            push(st, value);
        }
        i++;
    }
    return (pop(st));
}
int main()
{
    char exp[50];
    printf("\nEnter the Prefix Expression : ");
    gets(exp);
    reverse(exp);
    printf("\nValue of the Prefix Expression = %.2f\n", evaluateprefix(exp));
    return 0;
}