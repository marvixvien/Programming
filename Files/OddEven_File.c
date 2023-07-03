// SPLITTING  A FILE OF NATURAL NUBERS UPTO A RANGE
// INTO ODD,EVEN AND PRIME FILES
#include <stdio.h>
#include<math.h>
  int main() {
        FILE *fp1, *fp2, *fp3, *fp4;
        int n, i, num, flag = 0;
		char c;
        /* open data.txt in read mode */
        fp1 = fopen("data.txt", "w");
        printf("Enter the value for n:");
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
                fprintf(fp1, "%d ", i);
        // fprintf(fp1, "\n");
        fclose(fp1);

        /* open files to write even, odd and prime nos separately */
        fp1 = fopen("data.txt", "r");
        fp2 = fopen("even.txt", "w");
        fp3 = fopen("odd.txt", "w");
        fp4 = fopen("prime.txt", "w");

        fprintf(fp2, "Even Numbers:\n");
        fprintf(fp3, "Odd Numbers:\n");
        fprintf(fp4, "Prime Numbers:\n");

        /* print even, odd and prime numbers in separate files */
        while (!feof(fp1)) 
		{
           fscanf(fp1, "%d ", &num);
                if (num % 2 == 0) 
				{
                        fprintf(fp2, "%d ", num);
                } 
				else
				 {
                        if (num > 1) 
						{
                                for (i = 2; i <= sqrt(num); i++) 
								{
                                        if (num % i == 0) 
										{
                                                flag = 1;
                                                break;
                                        }
                                }
                                if (!flag)
								 {
                                        fprintf(fp4, "%d ", num);
                                 }
                        }
                 fprintf(fp3, "%d ", num);
                        flag = 0;
                } // end else
        }   // end while
		
        /* close all opened files */
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
        // reading all files
          fp1 = fopen("data.txt", "r");
          fp2 = fopen("even.txt", "r");
          fp3 = fopen("odd.txt", "r");
          fp4 = fopen("prime.txt", "r");
          
		printf("\n::  original data files upto a range  :: \n");
          while((c=getc(fp1))!=EOF)
	   		printf("%c",c);
	      fclose(fp1);
	      printf("\n::  even number files  :: \n");
	      while((c=getc(fp2))!=EOF)
	   		printf("%c",c);
	      fclose(fp2);
	      printf("\n::  odd number files  :: \n");
	      while((c=getc(fp3))!=EOF)
	   		printf("%c",c);
	      fclose(fp3);
	      printf("\n::  prime number files  :: \n");
			while((c=getc(fp4))!=EOF)
	   		printf("%c",c);
	      fclose(fp4);
  }