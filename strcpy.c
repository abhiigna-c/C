#include<stdio.h>
#include<string.h>
int main()
{
  char str1[5],str2[5];
  int i;
  printf("enter string: ");
  
      scanf("%s",str1);
  
  strcpy(str2 ,str1);

  printf("str2 is %s",str2);

}