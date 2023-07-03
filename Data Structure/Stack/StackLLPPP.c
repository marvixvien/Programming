#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct stack *next;
}stack;
stack *top = NULL;
stack *push(stack *top, int val)
{
    stack *ptr;
    ptr = (stack *)malloc(sizeof(stack));
    ptr -> data = val;
    if (top == NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    else
    {
        ptr -> next = top;
        top = ptr;
    }
    return top;
}
stack *pop(stack *top)
{
    stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\nEmpty");
    else
    {
        top = top -> next;
        printf("\nThe Value being deleted is : %d", ptr -> data);
        free(ptr);
    }
    return top;
}
int *peek(stack *top)
{
    if(top == NULL)
        return -1;
    else
        return (top -> data);
}
stack *display(stack *top)
{
    stack *ptr;
    ptr = top;
    if(top == NULL)
        printf("\nEmpty");
    else
    {
        while(ptr != NULL)
        {
            printf("| %d | ",  ptr -> data);
            ptr = ptr -> next;
        }
    }
    return top;
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
                     top = push(top, val);
                     break;
            case 2 : top = pop(top);
                     break;
            case 3 : val = peek(top);
                     if(val != -1)
                        printf("\nThe Value Stored at top of stack is : %d", val);
                     else
                        printf("\nThe Stack Is Empty");
                    break;
            case 4 : printf("\nThe Stack Is : ");
                     top = display(top);
        }
    } while (option != 5);
    return 0;
}