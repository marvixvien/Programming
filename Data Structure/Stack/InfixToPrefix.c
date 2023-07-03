#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
char st[50], st2[50];
int top = -1, top2 = -1;
void push(char st[], char val)
{
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else    
        st[++top] = val;
}
char pop(char st[])
{
    char val = ' ';
    if(top == -1)
        printf("\nStack Underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}
int getpriority(char op)
{
    if(op == '^')
        return 2;
    else if(op == '/' || op == '*' || op == '%')
        return 1;
    else if(op == '+' || op == '-')
        return 0;
}
void Infix_to_prefix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy (target , "");
    while (source[i] != '\0')
    {
        if(source[i] == ')')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == '(')
        {
            while((top != -1) && (st[top] != ')'))
            {
                target[j] = pop(st);
                j++;
            }
            if(top == -1)
            {
                printf("\nIncorrect Expression");
                exit(1);
            }
            temp = pop(st);/*Remove left parenthesis*/
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            i++;
            j++;
        }
        else if(source[i] == '^' || source[i] == '/' || source[i] == '*' || source[i] == '%' || source[i] == '+' || source[i] == '-')
        {
            while((top != -1) && (st[top] != ')') && (getpriority(st[top]) > getpriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Element in Expression");
            exit(1);
        }
    }
    while((top != -1) && (st[top] != ')'))
    {
        target[j++] = pop (st);
    }
    target[j] = '\0';
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
int main ()
{
    char infix[50], postfix[50];
    printf("\nEnter the Infix Expression : ");
    gets(infix);
    reverse(infix);
    strcpy(postfix, "");
    Infix_to_prefix(infix , postfix);
    reverse(postfix);
    printf("\nThe Prefix Expression is : ");
    puts(postfix);
    return 0;
}