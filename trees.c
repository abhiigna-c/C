#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*left;
  struct node*right;
};
struct node*createNode(int data){
  struct node*newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right=NULL;
  return newNode;
}
struct node *insert(struct node*root, int data){
  if (root==NULL){
    return createNode(data);
    }
    if(data<root->data){
      root->left=insert(root->left,data);
    }
    if(data>root->data){
      root->right=insert(root->right,data);
    }
    return root;
}
void inorder(struct node*root){
  if(root!=NULL){
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
  }
}
void preorder(struct node*root){
  if(root!=NULL){
    printf(" %d ",root->data);
    inorder(root->left);
    inorder(root->right);
  }
}
void postorder(struct node*root){
  if(root!=NULL){
    inorder(root->left);
    inorder(root->right);
    printf(" %d ",root->data);
  }
}
int main(){
  struct node*root=NULL;
  root = insert(root,50);
  root = insert(root,30);
  root = insert(root,20);
  root = insert(root,40);
  root = insert(root,70);
  root = insert(root,60);
  root = insert(root,80);
   
  printf("Inorder traversal:");
  inorder(root);
  printf("\n");

  printf("Preorder traversal:");
  preorder(root);
  printf("\n");

  printf("Postorder traversal:");
  postorder(root);
  printf("\n");
}