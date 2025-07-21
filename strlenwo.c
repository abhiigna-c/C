#include<stdio.h>
int main()
{
  int count=0;
  char str[10];
  printf("enter string:");
  int i;
  
  scanf("%s",str);
  
 for(i=0;str[i]!='\0';i++)
 {
    count++;
 }
 printf("count is %d",count);
}