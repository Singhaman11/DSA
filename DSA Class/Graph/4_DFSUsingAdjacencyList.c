#include<stdio.h>
#include<stdlib.h>
#include<string.h>         //memset function
#define size 10
struct Node
{
    int vertex;
    struct Node *next;
};
struct Graph
{
    int no_vertices;
    int graph_type;
    struct Node **adjLists;
};
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
};
struct Graph *createGraph(int n, int g_t)
{
    struct Graph *newGraph = (struct Graph*) malloc(sizeof(struct Graph));
    memset(newGraph, '\0', sizeof(struct Graph));
    newGraph -> no_vertices = n;
    newGraph -> graph_type = g_t;                                          //0 for directed & 1 for undirected
    newGraph -> adjLists = (struct Node**) malloc(n * sizeof(struct Node));
    for(int i = 0; i < n; i++)
    {
        newGraph -> adjLists[i] = NULL;
    }
    return newGraph;
}
void AddEdge(struct Graph *graph, int s, int v)
{
    struct Node *newNode = createNode(v);
    newNode -> next = graph -> adjLists[s];
    graph -> adjLists[s] = newNode;
    if(graph -> graph_type == 1)
    {
        newNode = createNode(s);
        newNode -> next = graph -> adjLists[v];
        graph -> adjLists[v] = newNode;
    }
    // if node already exist don't crreate it again
}
void printGraph(struct Graph *graph)
{
    for(int i = 0; i < graph->no_vertices; i++)
    {
        struct Node *temp = graph -> adjLists[i];
        printf("Vertex of %d: ", i);
        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp -> next;
        }
        printf("\n");
    }
}
int v[7] = {0, 0, 0, 0, 0, 0, 0};
void BFS(struct Graph *graph, int start)
{
    printf("%d ", start);
    v[start] = 1;
    struct Node *temp = graph -> adjLists[start];
    while(temp != NULL)
    {
        if(v[temp -> vertex] == 0)
        {
            BFS(graph, temp -> vertex);
        }
        temp = temp -> next;
    }
}
int main()
{
    int n = 7;
    int g_t;
    printf("Enter 0 for directed graph.\n");
    printf("Enter 1 for undirected graph.\n");
    scanf("%d", &g_t);
    struct Graph *g1 = createGraph(n, g_t);
    // int c = 1;
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
    AddEdge(g1, 0, 3);                              
    AddEdge(g1, 1, 2);                              
    AddEdge(g1, 2, 3);                              
    AddEdge(g1, 2, 4);                              
    AddEdge(g1, 3, 4);                              
    AddEdge(g1, 4, 5);                              
    AddEdge(g1, 4, 6);                              
    printGraph(g1);
    BFS(g1, 1);
}