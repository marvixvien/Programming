#include<stdio.h>
int main()
{
	float value[12];
	int group[11] = {0,0,0,0,0,0,0,0,0,0,0};
	int i, low, high;
	printf("ENTER THE MARKS : ");
	fflush(stdin);
	i=0;
	while(i<12)
	{
		scanf("%f", &value[i]);
                        	++group[(int)(value[i])/10];
		i++;
        }
        printf("\nGroup    Range       Frequency\n");
        for(i=0;i<11;i++)
        {
          low = i*10;
	  if(i == 10)
	  high = 100;
	  else
	  high = low + 9;
	  printf("%2d     %3d to %3d    %3d\n",i+1, low, high, group[i]);
	}
	return 0;

}
