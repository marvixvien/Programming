// PROGRAM :: READ AND WRITE TO A FILE
#include <stdio.h>
//#include <string.h>
//#include<conio.h>
int main()
{
int mark;
char name[20];
FILE *fp;
// File STUREC.txt is opened in the write mode
fp=fopen("sturec.txt","w");
printf("\nEnter students' name and marks :: \n");
// ctrl + D in linux to save and exit, ctrl + z windows
printf(" Use ctrl + z to stop entry\n");
while( (scanf("%s %d",name,&mark) ) !=EOF)
  // writing student names and marks to file STUREC.txt
    fprintf(fp,"%s %d",name,mark);
fclose(fp);
printf("\n");
// opening file for read
fp=fopen("sturec.txt","r");
printf(" name        mark\n");
printf("-----------------------\n");
  while( (fscanf(fp,"%s %d",name,&mark) ) !=EOF)
      // display file contents
     printf("%10s  %5d\n",name,mark);
  fclose(fp);	  
  return 0;
}