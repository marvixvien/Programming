#include <stdio.h>
#include <stdlib.h>
#define infinity 99999;

void dijkstra(int **, int, int, int); // function prototype

int min(int *, int *, int); // function prototype to mind the minimum legth

int main()
{
    int **a, s, d, w, n;
    printf("\nEnter the number of vertices in a graph:\t");
    scanf("%d", &n);
    // memory allocation for weighted matrix
    a = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
    }
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        //Initializing the weighted matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    a[i][j] = infinity;
                }
            }
        }
        do
        {
            printf("\n\tEnter the vertex pair for which there is an edge: ");
            scanf("%d%d", &s, &d);
            printf("\n\tEnter the corresponding edge weight: ");
            scanf("%d", &w);
            a[s - 1][d - 1] = w;
            a[d - 1][s - 1] = w;
            printf("\n do you want to enter more no edges:[0/1]");
            scanf("%d", &s);
        } while (s != 0);
        printf("\nThe weighted matix is:\n");
        for (int i = 0; i < n; i++)
        {
            printf("\n");
            for (int j = 0; j < n; j++)
            {
                printf("\t%d", a[i][j]);
            }
        }
        int z, source;
        printf("\n\n\n enter the source and destination:\t");
        scanf("%d%d", &source, &z);
        dijkstra(a, source - 1, z - 1, n); // function calling
        free(a); // free allocated memory
        return 0;
    }
}
// function definition
void dijkstra(int **a, int s, int z, int n)
{
    int *l, *b, u, v, i;
    b = (int *)calloc(n, sizeof(int)); // memory allocaton for b set
    l = (int *)calloc(n, sizeof(int)); // memory allocation for the length array
    if (l == NULL || b == NULL)
    {
        return;
    }
    else
    {
        for (i = 0; i < n; i++)
        {   // initializing length array
            l[i] = infinity;
        }
        l[s] = 0;
        while (b[z] != 1)
        {
            u = min(l, b, n); // finding the vertex with l[u] minimum that is not in b
            b[u] = 1;
            for (v = 0; v < n; v++)
            {
                if (b[v] != 1)
                {
                    if (l[v] > l[u] + a[u][v])
                    {   // updating the length array
                        l[v] = l[u] + a[u][v];
                    }
                }
            }
        }
        printf("\n\n\nThe length array is:\t");
        for (i = 0; i < n; i++)
        {
            printf("%d   ", l[i]);
        }
        for(z = 0; z < n ; z++)
        {
            printf("\n");
            printf("\nthe shortest distance from node %d to node %d is:\t%d\n", s + 1, z + 1, l[z]);
        }
        // free allocated memory
        free(l);
        free(b);
    }
}
// function for finding the minimum weight
int min(int *l, int *b, int n)
{
    int minimum = infinity;
    int i, z;
    for (i = 0; i < n; i++)
    {
        if (l[i] < minimum && b[i] == 0)
        {
            minimum = l[i];
            z = i;
        }
    }
    return z;
}