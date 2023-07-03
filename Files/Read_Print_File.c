// take some text of user and write into a file

#include <stdio.h>
#include <string.h>
int main()
{
   /* this is comment */
  char ch;
  FILE *fp;
  fp=fopen("sample.txt","w");
    puts("Enter the text,press ctrl + z to stop: ");

  while((ch=getchar())!= EOF)
	  putc(ch,fp);
    fclose(fp);

    fp=fopen("sample.txt","r");

    while(!feof(fp))
    {
	ch=getc(fp);
	printf("%c",ch);
    }
   return 0;
 }

