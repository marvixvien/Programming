#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
char st[50];
int top = -1;
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
void Infix_to_postfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy (target , "");
    while (source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while((top != -1) && (st[top] != '('))
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
            while((top != -1) && (st[top] != '(') && (getpriority(st[top]) > getpriority(source[i])))
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
    while((top != -1) && (st[top] != '('))
    {
        target[j++] = pop (st);
    }
    target[j] = '\0';
}
int main ()
{
    char infix[50], postfix[50];
    printf("\nEnter the Infix Expression : ");
    gets(infix);
    strcpy(postfix, "");
    Infix_to_postfix(infix , postfix);
    printf("\nThe corresponding Postfix Expression is : ");
    puts(postfix);
    return 0;
}
