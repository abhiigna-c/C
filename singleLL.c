#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};

struct node*head=NULL;

struct node*createNode()
{
  int num;
  struct node*new=(struct node*)malloc(sizeof(struct node));
  if(new==NULL){
    printf("\nmemory not allocated");
  }
  else{
    printf("\nenter number:");
    scanf("%d",&num);
    new->data=num;
    new->next=NULL;
  }
  return new;
}

void Ins_begin(){
  struct node*new=createNode();
  if(head==NULL){
    head=new;
  }
  else{
    new->next=head;
    head=new;
    printf("\nInserted:%d",new->data);
  }
}

void Ins_end(){
  struct node*temp=head;
  struct node*new=createNode();
  if(head==NULL){
    head=new;
  }
  else{
    while (temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=new;
  }
}

void Ins_middle(){
  struct node*temp=head;
  struct node*new=createNode();
  int count=0,pos;
  printf("\nEnter node position:");
  scanf("%d",&pos);
  if(head==NULL){
    head=new;
  }
  else{
    while(count<pos-2)
    {
      count++;
      temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
  }
}

void display(){
  struct node*temp=head;
  if(head==NULL){
    printf("LL is empty");
  }
  else{
    while(temp->next!=NULL)
    {
      printf(" %d -> ",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
  }
}

void del_begin(){
  struct node*temp;
  if(head==NULL){
     printf("LL is empty");
  }
  else{
    temp=head;
    head=temp->next;
    printf("\ndeleted:%d",temp->data);
    free(temp);
  }
}

void del_end()
{
  struct node*temp,*temp1;
  if(head==NULL){
     printf("LL is empty");
  }
  temp1=head;
  while(temp1->next!=NULL){
    temp=temp1;
    temp1=temp1->next;
  }
  temp->next=NULL;
  free(temp1);
}

void del_middle(){
    struct node*temp,*temp1;
    int pos,count=0;
    printf("\nenter node pos:");
    scanf("%d",&pos);
  if(head==NULL){
        printf("LL is empty");
    }
    else{
      temp1=head;
      while(count<pos-2){
        count++;
        temp1=temp1->next;
      }
    temp=temp1->next;
    temp1->next=temp->next;
    free(temp);
    }
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