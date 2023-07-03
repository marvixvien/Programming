/*print longest line with its length*/
/* line of a file abc.txt should be terminated by dot*/
#include<stdio.h>
#include<string.h>
int main()
{
  FILE *fp;
  int i=0;
  char u[100],c,line[100];
  //clrscr();
  fp=fopen("abc.txt","r");
  while(!feof(fp))
  {
    c=getc(fp);
    line[i++]=c;
    if(c=='.')
    {
      line[i]='\0';
      if(strlen(u)<strlen(line))
	 strcpy(u,line);
      i=0;
    }
  }
  fclose(fp);
  printf("%s",u);
  printf("\nLength=%d",strlen(u));
  //return 0;
  //getch();
}