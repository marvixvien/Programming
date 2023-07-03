#include <stdio.h>
#include <stdlib.h>
int print(int **a, int n)
{ 
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%8d", *(*(a+i)+j));
		}
		printf("\n");
	}
}
int floyd(int **a, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(*(*(a+j)+k) > *(*(a+j)+i) + *(*(a+i)+k))
				{	
					*(*(a+j)+k) = *(*(a+j)+i) + *(*(a+i)+k);
				}
			}
		}
	}
	printf("\nThe output graph: \n");
	print(a,n);
}
int warshall(int **a, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				*(*(a+j)+k)= *(*(a+j)+k) || (*(*(a+j)+i) && *(*(a+i)+k));
			}
		}
	}
	printf("\nThe output graph: \n");
	print(a,n);

}
int main()
{
    int **a, n, u, v, w, i, j;
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
    do
    {
        printf("\n\t1. Floyd");
        printf("\n\t2. Warshall");
        printf("\n\t3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &v);
        switch(v)
        {
            case 1:
            	for(i=0;i<n;i++)
    			{
					for(j=0;j<n;j++)
					{
						if(i!=j)
							*(*(a+i)+j)=9999;
						else
							*(*(a+i)+j)=0;
					}	
  				}
            	printf("\nEnter the edges : \n");
				do
				{
					printf("\n\tEnter the vertex pair for which there is an edge : ");
					scanf("%d%d", &u, &v);
					printf("\nEnter The Corresponding edge weight: ");
					scanf("%d", &w);
					*(*(a+u-1)+v-1) = w;
					*(*(a+v-1)+u-1) = w;
					printf("\nDo you want to enter more number of edges? [1-Yes/0-No] : ");
					scanf("%d", &u);
				}while(u != 0);
				printf("\nThe input graph is :\n");
				print(a,n);
				floyd(a,n);
					break;
            case 2:
            	for(i=0;i<n;i++)
    			{
    				for(j=0;j<n;j++)
    				{
    					*(*(a+i)+j)=0;
    				}	
    			}
            	printf("\nEnter the edges : \n");
				do
				{
					printf("\n\tEnter the vertex pair for which there is an edge : ");
					scanf("%d%d", &u, &v);
					*(*(a+u-1)+v-1) = 1;
					printf("\nDo you want to enter more number of edges? [1-Yes/0-No] : ");
					scanf("%d", &u);
				}while(u != 0);
				printf("\nThe input graph is :\n");
				print(a,n);
				warshall(a,n);
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
