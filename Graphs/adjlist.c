#include<stdio.h>
#include<stdlib.h>
struct neigh
{
    int data;
    struct neigh *next;
};
struct node
{
    int data;
    struct node *next;
    struct neigh *succ;
};
struct node *start = NULL;
void display(void);
int main()
{
    int n, ch, nbr; 
    struct node *p, *ptr; 
    struct neigh *s, *nptr;
    if(p == NULL)
    {
        printf("Not enough memory.\n");
        return 1;
    }
    do
    {
        printf("\nEnter the node : ");
        scanf("%d", &n);
        p = (struct node*)malloc(sizeof(struct node));
        p->data = n;
        p->next = NULL;
        p->succ = NULL;
        if(start == NULL)
            start = p;
        else
        {
            ptr=start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = p; 
        }
        do
        {
            printf("\nNode has a neighbour? [0/1] : ");
            scanf("%d", &ch);
            if(ch != 1)
                continue;
            printf("\nEnter the neighbour of the node : ");
            scanf("%d", &nbr);
            s = (struct neigh*)malloc(sizeof(struct neigh));
            if(s == NULL)
            {
                printf("Not enough memory.\n");
                return 1;
            }
            s->data = nbr;
            s->next = NULL;
            if(p->succ == NULL)
            {
                p->succ = s;
            }
            else
            {
                nptr = p->succ;
                while(nptr->next != NULL)
                    nptr = nptr->next;
                nptr->next = s;
            }
        }while(ch == 1);
        printf("\nDo you want to enter any more nodes? [0/1] : ");
        scanf("%d", &ch);
    }while(ch == 1);
    display();
    free(p); free(s);
    return 0;
}
void display()
{
    struct node *ptr; 
    struct neigh *nptr;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        ptr = start;
        printf("The adjacency list elements are : \n");
        while(ptr != NULL)
        {
            printf("%d", ptr->data);
            if(ptr->succ != NULL)
            {
                nptr = ptr->succ;
                while(nptr != NULL)
                {
                    printf(" -> %d", nptr->data);
                    nptr = nptr->next;
                }
            }
            printf("\n");
            ptr = ptr->next;
        }
    }
}
