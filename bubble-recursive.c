 #include<stdio.h>
 int BubblrSortRecursion(int a[],int num);
 int main()
 {
  int i,j,num,temp;
  printf("Enter size :");
  scanf("%d",&num);
  int a[num];
  printf("enter numbers\n");
  for(i=0;i<num;i++)
  {
    scanf("%d",&a[i]);
  }
  BubblrSortRecursion(a,num);
  
 }