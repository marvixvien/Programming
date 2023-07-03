/*Write a Programe in C to delete all the nodes in a singly linked list having
  odd numbers divisable by 3 or 5.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start = NULL;
node *create(node *start)
{
    node *new_node, *ptr;
    int val;
    printf("\nEnter -1 at the end.");
    printf("\nEnter the Data : ");
    scanf("%d", &val);
    while (val != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node -> data = val;
        if(start == NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr -> next != NULL)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = NULL;            
        }
        printf("\nEnter the Data : ");
        scanf("%d", &val);
    }
    return start;
}
node *delete_node(node *start, int val)
{
    node *ptr, *preptr;
    ptr = start;
    while (ptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);    
    return start;
}
node *delete_list(node *start)
{
    node *ptr;
    if(start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
       {
            if((ptr -> data) %2 != 0)
            {
                if (((ptr -> data % 3) == 0) || ((ptr -> data % 5) == 0))
                {
                   printf("\n%d is to be deleted next.", ptr -> data);
                   start = delete_node(ptr, ptr -> data);
                   ptr = start; 
                }
            }
            else
                ptr = ptr -> next;
        }
    }
    return start;
}
node *display(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("| %d | -> ", ptr -> data);
        ptr = ptr -> next;
    }
    return start;
}
int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****\n");
        printf("\n1. Create a Linked List");
        printf("\n2. Delete Odd Numbers divisable by 3 or 5");
        printf("\n3. Display the Linked List");
        printf("\n4. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1: start = create(start);  
                    printf("\nLinked List Created");
                    break;
            case 2: start = delete_list(start);
                    break;
            case 3: start = display(start);
                    break;        
        }
    } while (option != 4);
    return 0;
}