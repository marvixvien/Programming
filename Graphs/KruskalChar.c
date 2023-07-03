#include <stdio.h>
#include <stdlib.h>
typedef struct edge
{
    int s, e, wt;
} edge;
void sort(edge *e, int n)
{
    edge *t;
    int i, j;

    t = (edge *)malloc(sizeof(edge));

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((e + i)->wt > (e + j)->wt)
            {
                *t = *(e + i);
                *(e + i) = *(e + j);
                *(e + j) = *t;
            }
        }
    }
    free(t);
}
void kruskal(int **wtm, int n, int ecnt)
{
    edge *elist, *stlist;
    int *des;
    int t, t1, i, j, cost = 0;

    elist = (edge *)calloc(ecnt, sizeof(edge));
    stlist = (edge *)calloc(n - 1, sizeof(edge));
    des = (int *)calloc(n - 1, sizeof(int));

    if (elist == NULL || stlist == NULL || des == NULL)
    {
        printf("\n\nMemory allocation failed.");
        exit(0);
    }
    t = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(*(wtm + i) + j) != 0)
            {
                (elist + t)->s = i;
                (elist + t)->e = j;
                (elist + t)->wt = *(*(wtm + i) + j);
                t++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        *(des + i) = i;
    }

    sort(elist, ecnt); // function call to sort the edges

    t = 0;
    t1 = 0;
    while (t < ecnt)
    {
        if (*(des + (elist + t)->s) != *(des + (elist + t)->e))
        {
            *(stlist + t1) = *(elist + t);
            t1++;
            for (i = 0; i < n; i++)
            {
                if (*(des + i) == *(des + (elist + t)->e))
                {
                    *(des + i) = *(des + (elist + t)->s);
                }
            }
        }
        t++;
    }
    printf("\nMinimum Spanning Tree is:\n");
    printf("\nEdge : Weight\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("%c - %c : %d\n", (char)(stlist + i)->s + 65, (char)(stlist +i)->e + 65, (stlist + i)->wt);
        cost += (stlist + i)->wt;
    }
    printf("\nTotal cost of the spanning tree: %d\n", cost);
}
int main()
{
    int **wtm;
    int n, i, j, iu, iv, wt, ecnt = 0;
    char cu, cv;
    do
    {
        printf("\nEnter number of vertices: ");
        scanf("%d", &n);
    } while (n <= 0);
    wtm = (int **)calloc(n, sizeof(int *)); // memory allocation
    for (i = 0; i < n; i++)
    {
        *(wtm + i) = (int *)calloc(n, sizeof(int));
    }
    if (wtm == NULL)
    {
        printf("\n\nMemory allocation failed.");
        exit(0);
    }
    printf("\nEnter the edges for the graph:\n");
    do
    {
        printf("\n1. Enter the node pairs (u v) which you want to connect: ");
        scanf(" %c", &cu);
        printf("\n2. Enter the node pairs (u v) which you want to connect: ");
        scanf(" %c", &cv);
        printf("\nEnter the corresponding edge weight: ");
        scanf("%d", &wt);
        iu = (int)(cu)-65;
        iv = (int)(cv)-65;
        *(*(wtm + iu) + iv) = wt;
        *(*(wtm + iv) + iu) = wt;
        printf("\nDo you want to insert more number of edges? (1 yes/0-no):");
        scanf("%d", &iu);
    } while (iu != 0);

    printf("\nInput Graph is:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*(wtm + i) + j));
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (*(*(wtm + i) + j) != 0)
            {
                ecnt++;
            }
        }
    }
    kruskal(wtm, n, ecnt); // function calling for kruskal
    free(wtm);
    return 0;
}