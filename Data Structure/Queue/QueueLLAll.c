#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *next;
}node;
typedef struct queue
{
    node *front;
    node *rear;
}queue;
queue *create_queue(queue *q)
{
    q = (queue *)malloc(sizeof(queue));
    q -> rear = q -> front = NULL;
    return q;
}
queue *q = NULL;
queue *insert(queue *q, int val)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> data = val;
    if(q -> front == NULL)
    {
        q -> front = ptr;
        q -> rear = ptr;
        q -> front -> next = q ->rear -> next = NULL;
    }
    else
    {
        q -> rear -> next = ptr;
        q -> rear = ptr;
        q -> rear -> next = NULL;
    }
    return q;
}
queue *delete(queue *q)
{
    node *ptr;
    ptr = q -> front;
    if(q -> front == NULL)
    {
        printf("\nUnderflow\n");
        return q;
    }
    else
    {
        q -> front = q -> front -> next;
        printf("\nThe value being deleted : %d\n", ptr -> data);
        free(ptr);
    }
    return q;
}
int peek(queue *q)
{
    if(q -> front == NULL)
    {
        printf("\nThe Ques is Empty.\n");
        return 1;
    }
    else 
        return (q -> front -> data);
}
queue *display(queue *q)
{
    node *ptr;
    ptr = q -> front;
    if(ptr == NULL)
        printf("\nThe Queue is empty\n");
    else
    {
        while (ptr != q -> rear)
        {
            printf("| %d | ", ptr -> data);
            ptr = ptr -> next;   
        }
        printf("| %d |", ptr -> data);
    }
    return q;
}
int main()
{
    int option, val;
    char con;
    q = create_queue(q);
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
            case 1: printf("\nEnter the number to be Inserted : ");
                    scanf("%d", &val);
                    q = insert(q,val);
                    break;
            case 2: q = delete(q);
                    break;
            case 3: val = peek(q);
                    if(val != -1)
                        printf("\nThe value at Front of the Queue is : %d\n", val);
                    break;
            case 4: q = display(q);
                    break;
            default: printf("\nPrograme is Exited.\n");
                     exit(1);
        }
        printf("\nDo you Want to Conitnue? ");
        printf("\nEnter y or Y for Yes.\n Enter n or N for No. ");
        scanf("%s", &con);
    } while (con == 'y'|| con == 'Y');
    
}