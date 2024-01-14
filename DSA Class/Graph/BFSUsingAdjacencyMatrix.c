//Breadth first search (BFS) using Adjacency matrix.
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 7
int front = -1, rear = -1;
int queue[QUEUE_SIZE];
void enqueue(int element)
{
    rear++;
    queue[rear] = element;
    if(rear == 0)
    {
        front++;
    }
}
int dequeue()
{
    front++;
    return queue[front-1];
}
int isEmpty()
{
    if(rear == -1 || rear < front)
        return 1;
    return 0;
}
void main()
{
    int visited[QUEUE_SIZE] = {0, 0, 0, 0, 0, 0, 0};
    int a[QUEUE_SIZE][QUEUE_SIZE] = {{0, 1, 1, 1, 0, 0, 0},
                                     {1, 0, 1, 0, 0, 0, 0},
                                     {1, 1, 0, 1, 1, 0, 0},
                                     {1, 0, 1, 0, 1, 0, 0},
                                     {0, 0, 1, 1, 0, 1, 1},
                                     {0, 0, 0, 0, 1, 0, 0},
                                     {0, 0, 0, 0, 1, 0, 0}};
    int starting_node;
    printf("Enter the node from where search should be started.\n");
    scanf("%d", &starting_node);
    printf("%d", starting_node);
    visited[starting_node] = 1;
    enqueue(starting_node);
    while(isEmpty() == 0)
    {
        int node = dequeue();
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if(a[node][i] == 1 && visited[i] == 0)
            {
                printf("%d", i);
                visited[i] = 1;
                enqueue(i);
            }
        } 
    }
}