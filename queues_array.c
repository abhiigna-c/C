#include<stdio.h>
#include<stdlib.h>
int queue[100],size,front = -1,rear = -1;
void enqueue()
{
  int element;
  if(rear==size-1)
  printf("\nQueue is overflow");
  else{
    printf("enter element to insert :");
    scanf("%d",&element);
    if(rear==-1)
    {
      front++;
    }
    rear++;
    queue[rear]=element;
  }
}
void dequeue()
{
  if(front==-1)
  {
    printf("\nqueue is underflowing");
  }
  else{
    printf("deleting element :%d",queue[front]);
    if(front==rear){
      front= -1;
      rear= -1;
    }
    else{
      front++;
    }
  }
}
void display()
{
  int temp;
  if(front==-1)
  printf("queue is empty");
  else{
    for(temp=front;temp<=rear;temp++){
      printf("%d ",queue[temp]);
    }
  }
}
int main()
{
  int option;
  printf("enter queue size :");
  scanf("%d",&size);
  printf("1.enqueue 2.dequeue 3.display 4. exit");
  while(1){
    printf("\nenter your option :");
    scanf("%d",&option);
    switch(option)
    {
      case 1: enqueue();
             break;
      case 2: dequeue();
             break;
      case 3: display();
             break;
      case 4: exit(1);
      default : printf("\nInvalid");
    }
  }
  return 0;
}
 