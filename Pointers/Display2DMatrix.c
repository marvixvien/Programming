/*Passing matrix as a function Argument*/
#include<stdio.h>
void Display(int (*m)[4]) /*Pointer to an array containing 4 int values.*/
{
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("\t%d", *(*(m + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}
void main()
{
    int mat[3][4], i, j;
    for(i = 0; i < 3 ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
        {
            printf("\nEnter number [%d][%d] : ", i+1 , j+1);
            scanf("%d", (*(mat +i)+j));
        }
    }
    printf("\n");
    printf("The matrix is : \n");
    Display(mat);
}