#include<stdio.h>
#include<stdlib.h>
#include<string.h>         //memset function
#define size 10
struct Graph
{
    int no_vertices;
    int graph_type;
    int A[size][size];
};
struct Graph *createGraph(int n, int g_t)
{
    struct Graph *newGraph = (struct Graph*) malloc(sizeof(struct Graph));
    memset(newGraph, '\0', sizeof(struct Graph));
    newGraph -> no_vertices = n;
    newGraph -> graph_type = g_t;           //0 for directed & 1 for undirected 
    return newGraph;
}
void AddEdge(struct Graph *G, int s, int v)
{
    G -> A[s][v] = 1;
    if(G -> graph_type == 1)
    {
        G -> A[v][s] = 1;
    }
}
void RemoveEdge(struct Graph *G, int s, int v)
{
    G -> A[s][v] = 0;
    if(G -> graph_type == 1)
    {
        G -> A[v][s] = 0;
    }
}
void printGraph(struct Graph *G)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d\t", G->A[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, v1, v2, g_t, c;
    // printf("Enter the no. of vertices.\n");
    n = 4;
    // scanf("%d", &n);
    printf("Enter 0 for directed graph.\n");
    printf("Enter 1 for undirected graph.\n");
    scanf("%d", &g_t);
    struct Graph *g1 = createGraph(n, g_t);
    c = 1;
    // while(c == 1)
    // {
    //     printf("Enter the edge.\n");
    //     scanf("%d %d", &v1, &v2);
    //     AddEdge(g1, v1, v2);                              
    //     printf("Enter 1 to add an edge.\n");
    //     printf("Enter 0 to exit.\n");
    //     scanf("%d", &c);
    // }
    AddEdge(g1, 0, 1);                              
    AddEdge(g1, 0, 2);                              
    AddEdge(g1, 1, 2);                              
    AddEdge(g1, 2, 0);                              
    AddEdge(g1, 2, 3);                              
    AddEdge(g1, 3, 3);                             
    // {0, 1}, { 0, 2} , {1, 2}, {2, 0}, {2, 3}, {3, 3}                            
    // RemoveEdge(g1, 0, 1);                                  
    printGraph(g1);
}