#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start = NULL;
node *create_cll(node *start)
{
    node *new_node, *ptr;
    int num;
    printf("\nEnter -1 at the End.");
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node -> data = num;
        if(start == NULL)
        {
            new_node -> next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr -> next != start)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = start;
        }
        printf("\nEnter the Data : ");
        scanf("%d", &num);
    }
    return start;
}
node *display(node *start)
{
    node *ptr;
    ptr = start;
    while(ptr -> next != start)
    {
        printf(" | %d | ", ptr -> data);
        ptr = ptr -> next;
    }
    printf(" | %d | X", ptr -> data);
    return start;
}
node *insert_beg(node *start)
{
    node *new_node , *ptr;
    int num;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    while (ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    start = new_node;
    return start;
}
node *insert_end(node *start) 
{
    node *ptr, *new_node;
    int num;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    new_node  = (node *)malloc(sizeof(node));
    new_node -> data = num ;
    ptr = start;
    while(ptr -> next != start);
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    return start;
}
node *delete_beg(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = start -> next;
    free(start);
    start = ptr -> next;
    return start;
}
node *delete_end(node *start)
{
    node *ptr, *preptr;
    ptr = start;
    while (ptr -> next != start)
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
    ptr = start;
    while(ptr -> next != start)
        start = delete_end(start);
    free(start);
    return start;
}
int main()
{
    int option;
    do
    {
        printf("\n*** MAIN MENU ***");
        printf("\n 1: Create a Circular Linked List.");
        printf("\n 2: Display The list.");
        printf("\n 3: Add a Node at the Beginning.");
        printf("\n 4: Add a Node at the End.");
        printf("\n 5: Delete a Node at the Beginning.");
        printf("\n 6: Delete a Node at the End.");
        printf("\n 7: Delete The Entire List.");
        printf("\n 8: EXIT.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1 : start = create_cll(start);
                     printf("\nCircular Linked List : \n");
                     break;
            case 2 : start = display(start);
                     break;
            case 3 : start = insert_beg(start);
                     break;
            case 4 : start = insert_end(start);
                     break;
            case 5 : start = delete_beg(start);
                     break;
            case 6 : start = delete_end(start);
                     break;
            case 7 : start = delete_list(start);
                     printf("\nCircular Linked List Deleted.\n");
                     break;
        }
    } while (option != 9);
    return 0;
}