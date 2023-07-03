/* C program to find the min and mox strings in a file and copy them to another file*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
 int main(int argc,char*argv[])
{
FILE *fp, *fp1;			// creating two file pointers
char ch;				
int len,maxlen=0,minlen=79;
char s[80],min[80],max[80];   
/*creating three arrays first one for general operations and 
other two for storing min and max strings.*/

if(argc!=3)		//checking the number of arguments.
 {
  printf("Invalid numbers of arguments.");
  return 1;
 }
 
fp = fopen(argv[1],"r"); 	//opening the source file in read mode
if(fp == NULL)
   {
     puts("Can not open File!");		// if source file doesnot exist then exit.
     exit(0);
   }
   
printf("Contents of the Source file -------\n\n");
/*displaying the contents of the source file for verification.*/
  while((ch=getc(fp)) != EOF) 
     printf("%c",ch);
printf("\n\n-----------------------\n\n");     
fclose(fp);

 /* Finding the MIN and MAX strings of the file.*/
 
 fp = fopen(argv[1],"r");		//source file opened in read mode 
 fp1 = fopen(argv[2],"w");  	//read file opened in write mode
 
  while(fgets(s, 79, fp) != NULL)	
  {
      len=strlen(s);
      if(len>maxlen)				//finding the max string.
      	{
       	  maxlen=len;
       		 strcpy(max,s);       //storing the max string in the MAX array
	 	}
	  if (len<minlen)				//finding the min string.
	  {
	  	 minlen=len;
	  	 strcpy(min,s);				//storing the min string in the MIN array
	  }	  
}
fputs("The max string is: ",fp1);
fputs(max,fp1);						//copy the max string to the target file
fputs("\n",fp1);
fputs("The min string is: ",fp1);
fputs(min,fp1);						//copy the min string to the target file
fclose(fp1);					//closing the source and target file.
fclose(fp);

printf("Contents of the Target file -------\n\n");//displaying the contents of the target file.
fp = fopen(argv[2],"r");					
while(fgets(s, 79, fp) != NULL)
{
puts(s);
}
fclose(fp);
}