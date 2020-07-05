// Programmed By-
// Subham Sagar Paira (subhamsagarpaira.com)
// 1841017020
// Dt-5/7/20

// DFS(Depth First Search) Implementation In C:
#include <stdio.h>
#include <stdlib.h>

// Declaration of a structure for storing each node.
struct node
{
    int vertex;
    struct node* next;
};

// Create the basic node.
struct node* createNode(int v);

// To keep track of the full graph.(Visited/Not-Visited)
struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

// DFS algorithm.
void DFS(struct Graph* graph, int vertex)
{
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
            DFS(graph, connectedVertex);
  
        temp = temp->next;
    }
}

// Create a node
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
  
    graph->adjLists = malloc(vertices * sizeof(struct node*));
  
    graph->visited = malloc(vertices * sizeof(int));
  
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
  
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Main/Driver Function
int main()
{
    int edge = 0;
    printf("Enter the number of edges : ");
    
    // Edges from user.
    scanf("%d", &edge);
    struct Graph* graph = createGraph(edge);
    printf("\n");

    // Input the nodes of each edges connected.
    int i = 0, n1, n2;
    for (; i < edge; i++)
    {
        printf("Enter edge : ");
        scanf("%d %d", &n1, &n2);

        //Add the edge
        addEdge(graph, n1, n2);
    }
  
    // Input the Vertex
    int vertex;
    printf("\nEnter the Vertex : ");
    scanf("%d", &vertex);

    // Call for DFS Algorithm.
    printf("\nVisited ");
    DFS(graph, vertex);
    printf("\n");
  
    return 0;
}