#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
}node;
node *start = NULL;
node *insert(node *start)
{
    int val, pri;
    node *ptr, *p;
    ptr = (node *)malloc(sizeof(node));
    printf("\nEnter the value : ");
    scanf("%d", &val);
    printf("\nEnter and its priority :");
    scanf("%d", &pri);
    ptr -> data = val;
    ptr -> priority = pri;
    if(start == NULL || pri < start -> priority)
    {
        ptr -> next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while(p -> next != NULL && p -> next -> priority <= pri)
            p = p-> next;
        ptr -> next = p -> next;
        p -> next = ptr;
    }
    return start;
}
node *delete(node *start)
{
    node *ptr;
    if(start == NULL)
    {
        printf("\nUnder flow\n");
        return start;
    }
    else
    {
        ptr = start;
        printf("\nDeleted item is : %d", ptr -> data);
        start = start -> next;
        free(ptr);
    }
    return start;
}
int peek(node *start)
{
    if(start == NULL)
    {
        printf("\nThe Ques is Empty.\n");
        return 1;
    }
    else 
        return (start -> data);
}
void display(node *start)
{
    node *ptr;
    ptr = start;
    if(start == NULL)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nPriority Queue is : ");
        while(ptr != NULL)
        {
            printf("| %d [priority = %d]| ", ptr -> data, ptr -> priority);
            ptr = ptr -> next;
        }
    }
}
int main()
{
    int option, val;
    char con;
    do
    {
        printf("\n\n--*Main Menu*--");
        printf("\n 1: Insertion.");
        printf("\n 2: Deletion.");
        printf("\n 3: Peek The Queue.");
        printf("\n 4: Display The Queue.");
        printf("\n 5: EXIT.");
        printf("\n\nEnter Your Option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: start = insert(start);
                    break;
            case 2: start = delete(start);
                    if(val != -1)
                        printf("\nThe number deleted is : %d\n", val);
                    break;
            case 3: val = peek(start);
                    if(val != -1)
                        printf("\nThe value at Front of the Queue is : %d\n", val);
                    break;
            case 4: display(start);
                    break;
            default: printf("\nPrograme is Exited.\n");
                     exit(1);
        }
        printf("\nDo you Want to Conitnue? ");
        printf("\nEnter y or Y for Yes.\n Enter n or N for No. ");
        scanf("%s", &con);
    } while (con == 'y'|| con == 'Y');
    
}