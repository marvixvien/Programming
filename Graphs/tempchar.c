#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **wtm;
    int n, ii, ij, iu, iv, wt;
    char cu, cv;
    do
    {
        printf("\nEnter number of vertices: ");
        scanf("%d", &n);
    } while (n <= 0);
    wtm = (int **)calloc(n, sizeof(int *)); // memory allocation
    for (ii = 0; ii < n; ii++)
    {
        *(wtm + ii) = (int *)calloc(n, sizeof(int));
    }
    if (wtm == NULL)
    {
        printf("\n\nMemory allocation failed.");
        exit(0);
    }
    printf("\nEnter the edges for the graph:\n");
    do
    {
        printf("\nEnter the node pairs (u v) which you want to connect: ");
        scanf("%s%s", &cu, &cv);
        printf("\nEnter the corresponding edge weight: ");
        scanf("%d", &wt);
        iu = (int)(cu)-65;
        iv = (int)(cv)-65;
        *(*(wtm + iu) + iv) = wt;
        *(*(wtm + iv) + iu) = wt;
        printf("\niu = %d || iv = %d || wt = %d || wtm[%d][%d] = %d || cu = %d || cv = %d \n", iu, iv, wt, iu, iv, *(*(wtm + iu) + iv), cu, cv);
        printf("\nDo you want to insert more number of edges? (1 yes/0-no):");
        scanf("%d", &iu);
    } while (iu != 0);

    printf("\nInput Graph is:");
    for(ii = 0; ii < n; ii++)
    {
        printf("\ni = %d", ii);
        for(ij = 0; ij < n; ij++)
        {
            printf("%d\t", *(*(wtm + ii)+ij));
        }
    }
    
    printf("\n");
    free(wtm);
    return 0;
}