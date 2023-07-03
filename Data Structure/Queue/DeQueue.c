#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int deque[10];
int left = -1, right = -1;
void insert_beg()
{
    int val;
    printf("\nEnter the data to be Inserted : ");
    scanf("%d", &val);
    if ((left == 0 && right == MAX -1) || (left == right + 1))
    {
        printf("\nOverflow.");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if(left == 0)
            left = MAX -1;
        else
            left = left - 1;
    }
    deque[left] = val;
}
void insert_end()
{
    int val;
    printf("\nEnter the data to be Inserted : ");
    scanf("%d", &val);
    if ((left == 0 && right == MAX -1) || (left == right + 1))
    {
        printf("\nOverflow.");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if(right == MAX - 1)
            right = 0;
        else
            right = right + 1;
    }
    deque[right] = val;
}
void delete_beg()
{
    if(left == -1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\nThe value to be deleted is = %d", deque[left]);
    if(left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if(left == MAX - 1)
            left = 0;
        else
            left = left + 1;
    }
}
void delete_end()
{
    if(left == -1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\nThe value to be deleted is = %d", deque[right]);
    if(left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if(right == 0)
            right = MAX - 1;
        else
            right = right - 1;
    }
}
void display()
{
    int front = left, rear = right;
    if(front == -1)
    {
        printf("\nUnderflow.");
        return;
    }
    printf("\nThe Elements of the Queue are : ");
    if (front <= rear)
    {
        while (front <= rear)
        {
            printf("| %d | ", deque[front]);
            front++;
        }
    }
    else
    {
        while(front <= MAX - 1)
        {
            printf("| %d | ", deque[front]);
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            printf("| %d | ", deque[front]);
            front++;
        }
        
    }
    printf("\n");
}
void input_deque()
{
    int option;
    do
    {    
        printf("\n Input Restricted Deque : \n");
        printf("\n 1. Insertion at the End.");
        printf("\n 2. Deletion at the Beginning.");
        printf("\n 3. Deletion at the End.");
        printf("\n 4. Display the List.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: insert_end();
                break;
        case 2: delete_beg();
                break;
        case 3: delete_end();
                break;
        case 4: display();
                break;
        }
    }while(option != 5);
}
void output_deque()
{
    int option;
    do
    {    
        printf("\n Output Restricted Deque : \n");
        printf("\n 1. Insertion at the Beginning.");
        printf("\n 2. Insertion at the End.");
        printf("\n 3. Deletion at the End.");
        printf("\n 4. Display the List.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: insert_beg();
                break;
        case 2: insert_end();
                break;
        case 3: delete_end();
                break;
        case 4: display();
                break;
        }
    }while(option != 5);
}
int main()
{
    int option;
    printf("\n***** MAIN MENU *****");
    printf("\n 1. Input Restricted Deque.");
    printf("\n 2. Output Restricted Deque.");
    printf("\nEnter Your Choice : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1: input_deque();
            break;
    case 2: output_deque();
            break;
    default: printf("\nWrong Input.");
        break;
    }
    printf("\n");
}