#include<stdio.h>
int main()
{
  int i,arr[4];
  printf("enter array elements :");
  for(i=0;i<4;i++)
  {
    scanf("%d",&arr[i]);
  }
  int max=arr[0];
  for(i=1;i<4;i++)
  {
    if(max < arr[i])
    {
      max = arr[i];
    }
  }
  printf("max is %d",max);
}