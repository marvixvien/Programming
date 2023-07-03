/*Dynamic Memory Allocation of Matrix*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **m, row, col, i, j;

    printf("\nEnter the number of Rows in the matrix: ");
    scanf("%d", &row);
    printf("\nEnter the number of Columns in the matrix: ");
    scanf("%d", &col);

    m = (int**)calloc(row , sizeof(int)); /*Array of pointers declared*/
    for ( i= 0 ; i < row ; i++)
     *(m + i) = (int*)calloc(col , sizeof(int));/*Memory allocated for each Row*/

    for(i = 0 ; i < row ; i++)
    {
     for(j = 0 ; j < col ; j++)
        {
            printf("\nEnter the value of Matrix[%d][%d] : ", (i + 1) , (j + 1));
            scanf("%d", (*(m + i) + j)); /*same as &m[i][j]*/
        }
    } 
    printf("\nThe Matrix is : \n");
    for(i = 0 ; i < row ; i++)
    {
     for(j = 0 ; j < col ; j++)
        {
            printf(" %d  ", *(*(m + i) + j)); /*same as m[i][j]*/
        }
        printf("\n");
    } 
    free(m);
}
