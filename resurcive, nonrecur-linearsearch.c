#include<stdio.h>

int recur(int arr[],int n,int s,int i)
{
  if(i==n){
		return -1;
	}
	if(arr[i]==s){
		return (i+1);
	}
	else{
		recur(arr,n,s,i+1);
	}
}

int iterative(int arr[],int n,int s)
{
   for(int i=0;i<n;i++)
	 {
		if(arr[i]==s)
		{
			return i;
		}
		return -1;
	 }
}

int main(){
	int arr[10],n,s,i,temp,result;
	printf("\nenter number");
	scanf("%d",&n);
	
}