#include<stdio.h>
#include<stdlib.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag=0;

void stringmatch()
{
i = m = c = j = 0;
while(str[c] != '\0')
{
if(str[m] == pat[i]) // ...... matching
{
i++; m++;
if(pat[i] == '\0') //.....found occurrences
{
flag = 1;
//.... copy replace string in ans string.
for(k = 0; rep[k] != '\0'; k++, j++)
ans[j] = rep[k];
i = 0;
c = m;
}
}
else //... mismatch
{
ans[j] = str[c];
j++;
c++;
m = c;
i = 0;
}
}
ans[j] = '\0';
}
void main()
{
printf("\nEnter a main string \n");
gets(str);
printf("\nEnter a pattern string \n");
gets(pat);
printf("\nEnter a replace string \n");
gets(rep);
stringmatch();
if(flag == 1)
printf("\nThe resultant string is\n %s" , ans);
else
printf("\nPattern string NOT found\n");
}

