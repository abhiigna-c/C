#include<stdio.h>
int main()
{
  int arr[5],i;
  printf("enter array elements:");
  for(i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=4;i>=0;i--)
  {
    printf("%d\n",arr[i]);
  }
}