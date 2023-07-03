/*Function returning a pointer*/
#include<stdio.h>
int* MaxVal(int list[]) /*Returns int Pointer*/
{
    int i, *p, max;
    max =  list[0];
    p   = &list[0];
    for(i=0 ; i < 10 ; i++)
        if(list[i] > max)
        {
            max =  list[i];
            p   = &list[i];
        }
    return p; /* Pointer returned*/
}

void main()
{
    int arr[10], i, *m;
    for(i=0;i<10;i++)
    {
        printf("Enter the %d element : ", i+1);
        scanf("%d", (arr+i));
    }
    m = MaxVal(arr);
    printf("\nThe Required maximum value is %d.\n", *m);
}