#include<stdio.h>
#include<stdlib.h>
int stack[100];
int size;
int top= -1;
void push()
{
  if(top==size-1)
    printf("\nstack is overflow");
  else{
    top++;
    printf("\n enter stack elements :");
    scanf("%d",&stack[top]);
  }
}
void pop()
{
  if(top==-1)
    printf("\n stack is underflow");
  else{
    int temp=stack[top];
    top--;
    printf("\n deleted element : %d",temp);
  }
}
void display()
{
  int i;
  if(top==-1)
      printf("\n stack is empty");
  else{
    printf("\nstack elements :");
      for(i=top;i>=0;i--)
      printf("%d ",stack[i]);
  }
}
void top_of_the_stack(){
  if(top==-1)
    printf("\nstack is empty");
  else{
    printf("\ntop of the stack :%d",stack[top]);
  }
}
void isempty(){
  if(top==-1)
    printf("\n stack is empty");
  else{
    printf("\nstack is not empty");
  }
}
void isfull(){
  if(top==size-1)
   printf("\nstack is FULL");
  else{
    printf("\nstack is empty");
  }
}
int main()
{
  int opt;
  printf("\nenter size of  the stack :");
  scanf("%d",&size);
  printf("1.push 2.pop 3.top_of_thr_stack 4.isempty 5.display 6.isfull 7.exit");
  while(1){
    printf("\nenter your option:");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1 : push();
               break;
      case 2 : pop();
               break;
      case 3 : top_of_the_stack();
               break;
      case 4 : isempty();
               break;
      case 5 : display();
                break;
      case 6 : isfull();
               break;
      case 7 : exit(1);
      default:printf("\nInvalid");
    }
  }
  return 0;
}