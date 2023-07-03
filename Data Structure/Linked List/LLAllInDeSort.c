/*this program Creates a Linked List and performs Insertions and Deletions of all cases
  then Sorts the Linked List and finnaly Deletes the entire List at once.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start = NULL;
node *create_ll(node *start)
{
    node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to End.");
    printf("\nEnter The Data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node -> data = num;
        if (start == NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr -> next != NULL)
                ptr = ptr-> next;
            ptr -> next = new_node;
            new_node -> next = NULL;
        }
        printf("\nEnter The Data : ");
        scanf("%d", &num);
    }
    return start;
}
node *display(node *start)
{
    node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\t%d", ptr -> data);
        ptr = ptr-> next;
    }
    return start;
}
node *search(node *start)
{
    int key, count = 1;
    node *ptr;
    ptr = start;
    printf("\nEnter the Element you are Searching For : ");
    scanf("%d", &key);
    while(ptr -> data != key)
    {
        count++;
        ptr = ptr -> next;
    }
    printf("\n%d is at the %dth Position.", key ,count);
    return start;
}
node *insert_beg(node *start)
{
    node *new_node;
    int num;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    new_node -> next = start;
    start = new_node;
    return start;
}
node *insert_end(node *start)
{
    node *new_node, *ptr;
    int num;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    new_node -> next = NULL;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    return start;
}
node *insert_before(node *start)
{
    node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    printf("\nEnter the Value before which the Data has to be inserted : ");
    scanf("%d", &val);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    preptr = ptr;
    while(ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}
node *insert_after(node *start)
{
    node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the Data : ");
    scanf("%d", &num);
    printf("\nEnter the Value After which the Data has to be inserted : ");
    scanf("%d", &val);
    new_node = (node *)malloc(sizeof(node));
    new_node -> data = num;
    ptr = start;
    preptr = ptr;
    while(preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}
node *delete_beg(node *start)
{
    node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
node *delete_end(node *start)
{
    node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    while(ptr -> next != NULL)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
}
node *delete_node(node *start)
{
    node *ptr, *preptr;
    int val;
    printf("\nEnter the Value of the node which has to be Deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    if (ptr -> data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while(ptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }
}
node *delete_before(node *start)
{
    node *ptr, *preptr;
    int val;
    printf("\nEnter the Value before which the Node has to be Deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while(ptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    ptr = preptr;
    free(preptr);
    return start;
}
node *delete_after(node *start)
{
    node *ptr, *preptr;
    int val;
    printf("\nEnter the Value after which the Node has to be Deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while(preptr -> data != val)
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
    if (start != NULL)
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("\n%d is to be Deleted Next", ptr-> data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}
node *SortList(node *start)
{
    node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while(ptr1 -> next != NULL)
    {
        ptr2 = ptr1 -> next;
        while(ptr2 != NULL)
        {
            if(ptr1 -> data > ptr2 -> data)
            {
                        temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
    return start;
}
int main()
{
    int option;
    char con;
    do
    {
        printf("\n\n--*Main Menu*--");
        printf("\n 1: Create A Linked List.");
        printf("\n 2: Display The List.");
        printf("\n 3: Search For A Data.");
        printf("\n 4: Add A Node At The Beginning.");
        printf("\n 5: Add A Node At The End.");
        printf("\n 6: Add A Node Before a Given Node.");
        printf("\n 7: Add A Node After a Given node.");
        printf("\n 8: Delete A Node From The Beginning.");
        printf("\n 9: Delete A Node From The End.");
        printf("\n10: Delete A Given Node.");
        printf("\n11: Delete A Node Before A Given Node.");
        printf("\n12: Delete A Node After A Given Node.");
        printf("\n13: Delete The Entire List.");
        printf("\n14: Sort The List.");
        printf("\n15: EXIT.");
        printf("\n\nEnter Your Option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: start = create_ll(start);
                    printf("\nLinked List Created");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = search(start);
                    break;
            case 4: start = insert_beg(start);
                    break;
            case 5: start = insert_end(start);
                    break;
            case 6: start = insert_before(start);
                    break;
            case 7: start = insert_after(start);
                    break;
            case 8: start = delete_beg(start);
                    break;
            case 9: start = delete_end(start);
                    break;
            case 10: start = delete_node(start);
                    break;
            case 11: start = delete_before(start);
                    break;
            case 12: start = delete_after(start);
                    break;
            case 13: start = delete_list(start);
                    break;
            case 14: start = SortList(start);
                    break;
            default: printf("\nPrograme is Exited.\n");
                     exit(1);

        }
        printf("\nDo you Want to Conitnue? ");
        printf("\nEnter y or Y for Yes.\n Enter n or N for No. ");
        scanf("%s", &con);
    } while (con == 'y'|| con == 'Y');
    
}