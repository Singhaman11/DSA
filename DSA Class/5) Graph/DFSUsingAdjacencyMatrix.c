//Depth first search (DFS) using Adjacency matrix.
#include<stdio.h>
#define SIZE 7
int visited[SIZE] = {0, 0, 0, 0, 0, 0, 0};
int a[SIZE][SIZE] = {{0, 1, 1, 1, 0, 0, 0}, 
                     {1, 0, 1, 0, 0, 0, 0}, 
                     {1, 1, 0, 1, 1, 0, 0}, 
                     {1, 0, 1, 0, 1, 0, 0}, 
                     {0, 0, 1, 1, 0, 1, 1}, 
                     {0, 0, 0, 0, 1, 0, 0}, 
                     {0, 0, 0, 0, 1, 0, 0}};
int DFS(int n)
{
    printf("%d", n);
    visited[n] = 1;
    for(int i = 0; i < SIZE; i++)
    {
        if(a[n][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
void main()
{
    int starting_node;
    printf("Enter the node from where search should be started.\n");
    scanf("%d", &starting_node);
    DFS(starting_node);
}