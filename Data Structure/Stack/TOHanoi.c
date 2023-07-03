#include<stdio.h>
void move(int n, char source, char dest, char spare)
{
    if (n == 1)
        printf("\nMove from %c to %c.\n", source, dest);
    else
    {
        printf("\n1.n = %d",n);
        move(n-1, source, spare, dest);/*From A to B*/
        printf("\n2.n = %d",n);
        move(1, source, dest, spare);/*From A to C*/
        printf("\n3.n = %d",n);
        move(n-1, spare, dest, source);/*From B to C*/
        printf("\n4.n = %d",n);
        printf("\n\n1 Loop");
    }
}
int main()
{
    int n;
    printf("\nEnter the Number of Rings : ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B'); 
    return 0;
}