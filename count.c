#include<stdio.h>
int main()
{
  int arr[6],i;
  int positive=0,negative=0,zero=0;
  printf("enter array elements:");
  for(i=0;i<6;i++)
  {
    scanf("%d",&arr[i]);
  }
  
  for(i=0;i<6;i++)
  {
    if(arr[i]>1||arr[i]!=0)
   {
      positive++;
   }
   else if(arr[i]<1||arr[i]!=0)
   {
    negative++;
   }
   else{
    zero++
   }
  }
  printf("\npositives: %d",positive);
  printf("\n negatives: %d",negative);
  printf("\nzeros :%d",zero);
}