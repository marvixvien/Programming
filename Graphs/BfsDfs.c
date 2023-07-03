#include <stdio.h>
#include <stdlib.h>
void bfs(int **a, int n, int s)
{
    int *d = (int*) calloc(n, sizeof(int));
    int *q = (int*) calloc(n, sizeof(int));
    int *parent = (int*) calloc(n, sizeof(int));
    int front = -1, rear = -1, i, count = 0, k, u, v;
    for(i = 0; i < n; i++)
    {
        d[i] = -1;
        parent[i] = -1;
    }
    d[s] = 0;
    q[++rear] = s;
    printf("\nThe dequeued elements are :\n");
    while(front != rear)
    {
        v = q[++front];
        printf("%d\t", v+1);
        count++;
        for(u = 0; u < n; u++)
        {
            if(a[v][u] == 1)
            {
                if(d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    parent[u] = v;
                    q[++rear] = u;
                }
            }
        }
    }
    printf("\nThe distance of the nodes from source node %d : \n", s+1);
    for(i = 0; i < n; i++)
        printf("\nThe distance from node %d to node %d -> %d", (s+1), (i+1),d[i]);
    if(count == n)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is disconnected.\n");
    printf("\nThe shortest path from the nodes to %d :\n", s+1);
    for(i = 0; i < n; i++)
    {
        if(i != s)
        {
            printf("%d\t", i+1);
            k = i;
            while(parent[k] != -1)
            {
                k = parent[k];
                printf("%d\t", k+1);
            }
        }
        printf("\n");
    }
    free(q); free(parent); free(d);
}
void dfs(int **a, int n, int s)
{
    int *d = (int*) calloc(n, sizeof(int));
    int *stk = (int*) calloc(n, sizeof(int));
    int *parent = (int*) calloc(n, sizeof(int));
    int top = -1, i, count = 0, k, u, v;
    for(i = 0; i < n; i++)
    {
        d[i] = -1;
        parent[i] = -1;
    }
    d[s] = 0;
    stk[++top] = s;
    printf("\nThe popped elements are :\n");
    while(top != -1)
    {
        v = stk[top--];
        printf("%d\t", v+1);
        count++;
        for(u = 0; u < n; u++)
        {
            if(a[v][u] == 1)
            {
                if(d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    parent[u] = v;
                    stk[++top] = u;
                }
            }
        }
    }
    printf("\nThe distance of the nodes from source node %d : \n", s+1);
    for(i = 0; i < n; i++)
        printf("\nThe distance from node %d to node %d -> %d", (s+1), (i+1),d[i]);
    if(count == n)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is disconnected.\n");
    printf("\nThe shortest path from the nodes to %d :\n", s+1);
    for(i = 0; i < n; i++)
    {
        if(i != s)
        {
            printf("%d\t", i+1);
            k = i;
            while(parent[k] != -1)
            {
                k = parent[k];
                printf("%d\t", k+1);
            }
        }
        printf("\n");
    }
    free(stk); free(parent); free(d);
}
int main()
{
    int **a, n, u, v, i, j;
    do
    {
        printf("\nEnter the number of vertices in the graph : ");
        scanf("%d", &n);
    }while(n <= 0);
    a = (int**) calloc(n, sizeof(int*));
    for (i=0; i<n; i++)
    {
        a[i] = (int*) calloc(n, sizeof(int));
    }
    printf("\nEnter the edges : \n");
    do{
        printf("\n\tEnter the vertex pair for which there is an edge : ");
        scanf("%d%d", &u, &v);
        a[u-1][v-1] = 1;
        a[v-1][u-1] = 1;
        printf("\nDo you want to enter more number of edges? [1-Yes/0-No] :");
        scanf("%d", &u);
    }while(u != 0);
    printf("\nThe input graph is :\n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d ", a[i][j]);
        }
    printf("\n");
    }
    do
    {
        printf("\n\t1. BFS");
        printf("\n\t2. DFS");
        printf("\n\t3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &v);
        switch(v)
        {
            case 1:
                printf("\nPlease enter the source node : ");
                scanf("%d", &u);
                bfs(a, n, u-1);
                break;
            case 2:
                printf("\nPlease enter the source node : ");
                scanf("%d", &u);
                dfs(a, n, u-1);
                break;
            case 3:
                break;
            default:
                printf("\nEnter a valid choice");
                break;
        }
    }while(v != 3);
    free(a);
    return 0;
}