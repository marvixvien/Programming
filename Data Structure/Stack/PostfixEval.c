/*Program to Evaluate a Postfix Expression*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50
float st[MAX];
int top = -1;
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
float evaluatepostfix(char exp[])
{
    int i = 0;
    float op1, op2, value;
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
            push(st, (float)(exp[i] - '0'));
        else
        {
            op2 = pop(st);
            op1 = pop(st);
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
    printf("\nEnter the Postfix Expression : ");
    gets(exp);
    printf("\nValue of the Postfix Expression = %.2f\n", evaluatepostfix(exp));
    return 0;
}