#include <stdio.h>
#include<stdlib.h>
typedef struct node 
{
    struct node *prev;
    float data;
    struct node *next;
}node;
node *start = NULL;
node *create_cdll(node *start)
{
    node *new_node, *ptr;
    float num;
    printf("\nEnter -1 at the End");
    printf("\nEnter the Data : ");
    scanf("%f", &num);
    while (num != -1)
    {
        if(start == NULL)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node -> data = num;
            new_node -> prev = NULL;
            new_node -> next = start;
            start = new_node;
         }
        else
        {
            new_node = (node *)malloc(sizeof(node));
            new_node -> data = num;
            ptr = start;
            while(ptr -> next != start)
                ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> prev = ptr;
            new_node -> next = start;
            start -> prev = new_node;            
        }
    }
    return start;
}
node *display(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr -> next != start)
    {
        printf("| %.2f | ", ptr -> data);
        ptr = ptr -> next;
    }
    printf ("| %.2f |", ptr -> data);     
    return start;
}
node *insert_beg(node *start)
{
    node *new_node, *ptr;
    float num;
    printf("\nEnter the Data : ");
    scanf("%f", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    new_node -> next = start;
    start -> prev = new_node;
    new_node -> prev = ptr;
    ptr -> next = new_node;
    return start;
}
node *insert_end(node *start)
{
    node *new_node, *ptr;
    float num;
    printf("\nEnter the Data : ");
    scanf("%f", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    while (ptr -> next != start)
        ptr = ptr -> next;
    new_node -> next = start;
    start -> prev = new_node;
    new_node -> prev = ptr;
    ptr -> next = new_node;
    return start;    
}
node *insert_before(node *start)
{
    node *new_node, *ptr, *temp;
    float num, val;
    printf("\nEnter the Data before which the Node will be added : ");
    scanf("%f", &val);
    printf("\nEnter the Data : ");
    scanf("%f", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    while (ptr -> data != num)
        ptr = ptr -> next;
    temp = ptr -> prev ;
    temp -> next = new_node;
    new_node -> prev = temp;
    ptr -> prev = new_node;
    new_node -> next = ptr;
    return start;
}
node *insert_after(node *start)
{
    node *new_node, *ptr, *temp;
    float val, num;
    printf("\nEnter the Data before which the Node will be added : ");
    scanf("%f", &val);
    printf("\nEnter the Data : ");
    scanf("%f", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    while (ptr -> data != num)
        ptr = ptr -> next;
    temp = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = temp;
    temp -> prev = new_node;
    return start;
}

int main()
{
    int option;
    do
    {
        printf("\n\n ***MAIN MENU*** ");
        printf("\n 1: Create A Circular Doubly Linked List ");
        printf("\n 2: Display the List");
        printf("\n 3: Add a node at the Beginning");
        printf("\n 4: Add a node at the End");
        printf("\n 5: Add a node Before a Given Node");
        printf("\n 6: Add a node after a Given Node");
        printf("\n 7: Delete a node at the Beginning");
        printf("\n 8: Delete a node at the End");
        printf("\n 9: Delete a Given Node");
        printf("\n 10: Delete a node Before a Given Node");
        printf("\n 11: Delete a node after a Given Node");
        printf("\n 12: Delete the Entire List");
        printf("\n 13: Exit");
        printf("\n\nEnter Your Choice : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1 : start = create_cdll(start);
                     printf("\nDoubly Linked List Created.");
                     break;
            case 2 : start = display(start);
                     printf("\nThe Doubly Linked List is : \n");
                     break;
            case 3 : start = insert_beg(start);
                     break;
            case 4 : start = insert_end(start);
                     break;
            case 5 : start = insert_before(start);
                     break;
            case 6 : start = insert_after(start);
                     break;
            case 7 : start = delete_beg(start);
                     break;
            case 8 : start = delete_end(start);
                     break;
            case 9 : start = delete_node(start);
                     break;
            case 10 : start = delete_before(start);
                     break;
            case 11: start = delete_after(start);
                     break;
            case 12: start = delete_list(start);
                     printf("\nEntire List Deleted.");
                     break;
        }
    }while (option != 13);
    return 0;
}