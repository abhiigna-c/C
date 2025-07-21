#include<stdio.h>
int main()
{
 int arr[5],sum=0,i,avg;
 printf("enter array elements:");
 for(i=0;i<5;i++)
 {
 scanf("%d",&arr[i]);
 }
 
 for(i=0;i<5;i++)
 {
  sum+=arr[i];
 }
 printf("\n sum is %d",sum);
 avg=sum/2;
 printf("\n avg is %d",avg);
}