//program in C implementing all the stack operations using linked list 
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
 	int data; 
	struct node *next; 
};
 struct node *top = NULL; 
void push(); 
void pop(); 
void display(); 
int main() 
{ 
	int choice; 
	printf("\n********* Stack operations using linked list *********\n"); 
	printf("\n----------------------------------------------\n"); 
	do 
	{ 
		printf("\n\nChoose one from the below options...\n"); 
		printf("\n1. Push\n2. Pop\n3. Show\n4. Exit"); 
		printf("\n Enter your choice: "); 
		scanf("%d", &choice); 
         switch (choice) 
        { 
            case 1: push(); 
                	break; 
            case 2: pop(); 
                	break; 
            case 3: display(); 
                	break; 
            case 4: printf("Exiting...\n"); 
                	break; 
            default:printf("Please Enter a valid choice\n"); 
        } 
    } while (choice != 4); 
 
    // Free allocated memory before exiting 
    while (top != NULL) 
    { 
		pop(); 
	}		 
	return 0; 
} 
void push() 
{ 
	int data; 
	struct node *ptr = (struct node*)malloc(sizeof(struct node)); 
	if (ptr == NULL) 
	{ 
	printf("Unable to allocate memory\n"); 
	exit(EXIT_FAILURE); 
	} 
	printf("Enter the value: "); 
	scanf("%d",&data); 
	ptr->data = data; 
	ptr->next = top; 
	top = ptr; 
	printf("Item pushed\n"); 
} 
void pop() 
{ 
	if (top == NULL) 
	{ 
	printf("Underflow\n");
	return;
	}
	struct node *ptr = top; 
	printf("Popped item: %d\n", ptr->data); 
	top = top->next; 
	free(ptr); 
} 
void display() 
{ 
	struct node *ptr = top; 
	if (ptr == NULL) 
	{ 
	printf("Stack is empty\n"); 
	} 
	else 
	{ 
		printf("Printing Stack elements\n"); 
		while (ptr != NULL) 
		{ 
		printf("%d\t", ptr->data); 
		ptr = ptr->next; 
		} 
	} 
} 