#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert (int val)
{
    if(front == 0 && rear == MAX - 1)
        printf("\nUnderflow\n");
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if (front != 0 && rear == MAX - 1)
    {
        rear = 0;
        queue[rear] = val; 
    }
    else
        queue[++rear] = val;    
}
int delete ()
{
    int val;
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
    {
        if(front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return val;
}
int peek()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
        return queue[front];    
}
void display()
{
    int i;
    if(front == -1 && rear == -1)
        printf("\nQueue is Empty\n");
    else
    {
        if(front < rear)
        {
            for(i = front; i <= rear; i++)
                printf("| %d | ", queue[i]);
        }
        else
        {
            for(i = front; i < MAX; i++)
                printf("| %d | ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("| %d | ", queue[i]);
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
            case 1: printf("\nEnter the number to be Inserted : ");
                    scanf("%d", &val);
                    insert(val);
                    break;
            case 2: val = delete();
                    if(val != -1)
                        printf("\nThe number deleted is : %d\n", val);
                    break;
            case 3: val = peek();
                    if(val != -1)
                        printf("\nThe value at Front of the Queue is : %d\n", val);
                    break;
            case 4: display();
                    break;
            default: printf("\nPrograme is Exited.\n");
                     exit(1);
        }
        printf("\nDo you Want to Conitnue? ");
        printf("\nEnter y or Y for Yes.\n Enter n or N for No. ");
        scanf("%s", &con);
    } while (con == 'y'|| con == 'Y');
    
}