#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100
double atof(char s[]);
int getlin(char s[], int lim);
//rudimentary calculator
int main()
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int getlin(char line[], int max);
    sum = 0;
    while(getlin(line, MAXLINE) > 0)
    printf("  %g\n  ", sum += atof(line));
    return 0;
}
//atof: convert string s to double
double atof(char s[])
{
    double val, power;
    int i, sign;
    for(i = 0; isspace(s[i]); i++)//skip white space
    ; 
    //printf("%d",i);
    sign = (s[i] == '-')? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
    i++;
    for(val = 0.0; isdigit(s[i]); i++)
      { 
        val = 10.0 * val + (s[i] - '0');
      }
    printf("%lf",val);
    if(s[i] == '.')
    i++;
    for(power = 0.0; isdigit(s[i]); i++)
    {
         val = 10.0 * val + (s[i] - '0');
         power *= 10.0;
    }
    return sign * val / power;
}
//getline: get line into s, return length
int getlin(char s[], int lim)
{
    int c, i;
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c!= '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i; 
}
