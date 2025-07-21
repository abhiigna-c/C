#include<stdio.h>
int factorial(int n)
{
  int f=1;
  if(n==0||n==1)
  {
    return 1;
  }
  else{
     f=n*factorial(n-1);
  }
  return f;
}

int main()
{
  int n,i;
  printf("\nenter number:");
  scanf("%d",&n);
 /* int fact=1; 
   for(i=1;i<=n;i++)
  {
     fact=fact*i;
  }
  printf("\nFactorial of %d is : %d",n,fact);*/
  int result;
  result = factorial(n);
  printf("\nFactorial of %d is %d",n,result);
}
