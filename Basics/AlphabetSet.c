//Printing of alphabet set in decimal form and character form
#include<stdio.h>
main()
{
    char c;
    printf("\n");
    for(c = 65; c <= 122; c++)
    {
        if(c>90 && c<97)
           continue;
        printf("|%4d - %c \n", c, c);
    }
    printf("\n");
}
//65 - 90  : A - Z
//97 - 122 : a - z 