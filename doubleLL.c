#include<stdio.h>   
#include<stdlib.h>
struct node
{
  /* data */
  int data;
  struct node*prev;
  struct node*next;
};

struct node*head=NULL;

struct node *createNode()
{
  int num;
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Memory NOt allocated");
  }
  else{
    printf("\nenter number:");
    scanf("%d",&num);
  temp->data = num;
  temp->next=NULL;
  temp->prev=NULL ;
  }
  return temp;
}

void Ins_begin()
{
  struct node*new=createNode();
  if(head==NULL){
    head=new;
  }
  else{
    new->next=head;
    head->prev=new;
    head=new;
  }
}

void Ins_end()
{
  struct node*new=createNode();
  struct node*temp=head;
  if (head==NULL){
     head=new;
  }
  else{
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
  }
}

void Ins_middle()
{
  struct node*new=createNode();
  struct node*temp=head;
  int pos,count=0;
  printf("\nenter position:");
  scanf("%d",&pos);

  if (head==NULL){
     head=new;
  }
  else{
    while(count<pos-2){
      count++;
      temp=temp->next;
    }
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
  }
}

void del_begin(){
  struct node*temp;
  if(head==NULL){
    printf("\nLinked list is empty");
  }
  else{
    temp=head;
    head=temp->next;
    head->prev=NULL;
    printf("\nDeleting : %d",temp->data);
    free(temp);
  }
}

void del_end(){
  struct node*temp;
  if(head==NULL){
    printf("\nLL is empty");
  }
  else{
    temp=head;
    if(head->next==NULL){
      printf("\ndeleting: %d",temp->data);
      free(head);
      head=NULL;
      return;
    }
    while (temp->next->next!=NULL)
      temp=temp->next;
    printf("\ndeleting: %d",temp->next->data);
    free(temp->next);
    temp->next=NULL;
  }
}

void del_middle(){
  struct node*temp1,*temp;
  int pos , count=0;
  printf("\nenter position:");
  scanf("%d",&pos);
  if(head==NULL){
    printf("\nLLis empty");
  }
  else{
    temp1=head;
    while (count<pos-2)
    {
      count++;
      temp1=temp1->next;
    }
    temp=temp1->next;
    temp1->next=temp->next;
    temp->next->prev=temp1;
    printf("\ndeleting: %d",temp->data);
    free(temp);
  }
}

void display(){
  struct node*temp=head;
  if(temp==NULL){
    printf("\nLL is empty");
    return;
  }
  while(temp->next!=NULL){
    printf(" %d ",temp->data);
    temp=temp->next;
  }
  printf(" %d ",temp->data);
}


int main(){
 int opt;
 printf("\nInsert : 1.begin 2.end 3.middle\n delete: 4.begin 5.end 6.middle \n 7.display");
 while(1)
 {
  printf("\nenter option: ");
  scanf("%d",&opt);
  switch(opt)
  {
    case 1:Ins_begin();
    break;
    case 2:Ins_end();
    break;
    case 3:Ins_middle();
    break;
    case 4:del_begin();
    break;
    case 5:del_end();
    break;
    case 6:del_middle();
    break;
    case 7 :display();
    break;
    default:printf("\nenter valid data!!!!!");
  }
 }
 return 0;
}