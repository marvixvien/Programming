#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    int coeff;
    struct node *next;
}node;
node *start1 = NULL;
node *start2 = NULL;
node *start3 = NULL;
node *start4 = NULL;
node *last3  = NULL;
node *create_poly(node *start)
{
    node *new_node, *ptr;
    int n, c;
    printf("\nEnter the Number : ");
    scanf("%d", &n);
    printf("\nEnter the Coefficient : ");
    scanf("%d", &c);
    while (n != -1)
    {
        if(start == NULL)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr -> next != NULL)
                ptr = ptr -> next;
            new_node = (node *)malloc(sizeof(node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            ptr -> next = new_node;
        }
        printf("\nEnter the Number : ");
        scanf("%d", &n);
        if(n == -1)
            break;
        printf("\nEnter the Coefficient : ");
        scanf("%d", &c);
    }
    return start;
}
node *display_poly(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%dx^%d ", ptr -> num, ptr -> coeff);
        ptr = ptr -> next;        
    }
   return start;
}
node *add_node(node *start, int n, int c)
{
    node *ptr, *new_node;
    if(start == NULL)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr -> next != NULL)
                ptr = ptr -> next;
            new_node = (node *)malloc(sizeof(node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            ptr -> next = new_node;
        }
    return start;
}
node *add_poly(node *start1, node *start2, node *start3)
{
    node *ptr1, *ptr2;
    int sum_num, c;
    ptr1 = start1;
    ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
       if(ptr1 -> coeff == ptr2 ->coeff)
       {
           sum_num = ptr1 -> num + ptr2 -> num;
           start3 = add_node(start3, sum_num, ptr1 -> coeff);
           ptr1 = ptr1 -> next;
           ptr2 = ptr2 -> next;
       } 
       else if (ptr1 -> coeff > ptr2 -> coeff)
       {
           start3 = add_node(start3, ptr1 -> num, ptr1 -> num);
           ptr1 = ptr1-> next;
       }
       else if (ptr1 -> coeff < ptr2 -> coeff)
       {
           start3 = add_node(start3, ptr2 -> num, ptr2 -> num);
           ptr2 = ptr2-> next;
       }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
            ptr2 = ptr2 -> next;
        }
    }    
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
            ptr1 = ptr1 -> next;
        }
    }    
    return start3;
}
node *sub_poly(node *start1, node *start2, node *start4)
{
    node *ptr1, *ptr2;
    int sum_num, c;
    ptr1 = start1;
    ptr2 = start2;
    do
    {
       if(ptr1 -> coeff == ptr2 ->coeff)
       {
           sum_num = ptr1 -> num - ptr2 -> num;
           start4 = add_node(start4, sum_num, ptr1 -> coeff);
           ptr1 = ptr1 -> next;
           ptr2 = ptr2 -> next;
       } 
       else if (ptr1 -> coeff > ptr2 -> coeff)
       {
           start4 = add_node(start4, ptr1 -> num, ptr1 -> num);
           ptr1 = ptr1-> next;
       }
       else if (ptr1 -> coeff < ptr2 -> coeff)
       {
           start4 = add_node(start4, ptr2 -> num, ptr2 -> num);
           ptr2 = ptr2-> next;
       }
    }while (ptr1 != NULL || ptr2 != NULL);
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start4 = add_node(start4, ptr2 -> num, ptr2 -> coeff);
            ptr2 = ptr2 -> next;
        }
    }    
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start4 = add_node(start4, ptr1 -> num, ptr1 -> coeff);
            ptr1 = ptr1 -> next;
        }
    }    
    return start4;
}
int main ()
{
    int option; 
    do
    {
        printf("\n---***MAIN MENU***---\n");
        printf("\n 1. Enter the First Polynomial : ");
        printf("\n 2. Display the First Polynomial : ");
        printf("\n 3. Enter the Second Polynomial : ");
        printf("\n 4. Display the Second Polynomial : ");
        printf("\n 5. Add The Polynomials : ");
        printf("\n 6. Display the Result : ");
        printf("\n 7. Subtract The Polynomials : ");
        printf("\n 8. Display the Result : ");
        printf("\n 9. Exit.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch (option)
        {
                case 1: start1 = create_poly(start1);
                        break;
                case 2: start1 = display_poly(start1);
                        break;
                case 3: start2 = create_poly(start2);
                        break;
                case 4: start2 = display_poly(start2);
                        break;
                case 5: start3 = add_poly(start1, start2, start3);
                        break;
                case 6: start3 = display_poly(start3);
                        break;
                case 7: start4 = sub_poly(start1, start2, start4);
                        break;
                case 8: start4 = display_poly(start4);
                        break;
         }
    } while (option != 9);
    return 0;
}