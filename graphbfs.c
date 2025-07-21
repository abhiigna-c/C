/* 
program to traverse a directed graph thru BFS,
visiting only those vertices that are reachable from start vertex
*/
/* 
Using Queue 
using Adjancency matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX 100
#define initial 1		
#define waiting	2 	
#define visited	3	
int n; /* no of vertices in the graph */
int adj[MAX][MAX]; /* adjacency matrix */
int state[MAX]; /* initial, waiting, visited */

int queue[MAX], front = -1, rear = -1;

void create_graph();
void BF_Traversal();
void BFS(int v);

void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void main()
{
	
	create_graph();
	BF_Traversal();
	
}

void BF_Traversal()
{
	int v;
	for (v = 0; v < n; v++)
		state[v] = initial;
	printf("Enter start vertex for BFS :  ");
	scanf("%d", &v);
	BFS(v);

}
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v] = waiting;
	while (!isEmpty_queue())
	{
		v = delete_queue();
		printf("%d ", v);
		state[v] = visited;

		for (i = 0; i < n; i++)
		{
			/* check adjacent unvisited vertices */
			if (adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
}

void insert_queue(int vertex)
{
	if (rear == MAX - 1)
	{
		printf("Queue overflow\n");
		return;
	}
	else
	{
		if (front == -1) /* if queue is intially empty */
			front = 0;
		rear = rear + 1;
		queue[rear] = vertex;
	}
}

int isEmpty_queue()
{
	if (front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("queue underflow \n");
		return (int) NULL;
	}
	del_item = queue[front];
	front = front + 1;
	return del_item;
}

/* create directed graph */
void create_graph()
{
	int i, max_edges, origin, destin;
	printf("Enter no. of vertices : ");
	scanf("%d", &n);
	max_edges = n * (n - 1); /* directed graph*/
	for (i = 1; i <= max_edges; i++)
	{
		printf("Enter edge %d origin & destin (-1 -1 to quit) :", i);
		scanf("%d %d", &origin, &destin);
		if (origin == -1 && destin == -1)
			break;
		if (origin >= n || destin >= n || origin < 0 || destin < 0 || (origin == destin))
		{
			printf("invalid edge\n");
			i--;
		}
		else
			adj[origin][destin] = 1;
	}
}