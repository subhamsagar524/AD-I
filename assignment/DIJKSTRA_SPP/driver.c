// Programmed By-
// Subham Sagar Paira (subhamsagarpaira.com)
// 1841017020
// Dt-6/7/20

// Dijkstra's Smallest Path Algorithm in C.

#include <stdio.h>
#define INFINITY 9999   // Using for Infinity
#define MAX 10

// Prototype Declarations.
void Dijkstra(int Graph[MAX][MAX], int n, int start);

// Dijkstra's Algorithm
void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
  
    // Creating cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          if (Graph[i][j] == 0)
            cost[i][j] = INFINITY;
          else
            cost[i][j] = Graph[i][j];
  
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
  
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
  
    while (count < n - 1)
    {
        mindistance = INFINITY;
  
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
  
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Printing the distance
    for (i = 0; i < n; i++)
        if (i != start)
            printf("\nDistance from source to %d: %d", i, distance[i]);

    printf("\n");

}

// Main/Driver Function
int main()
{
    int Graph[MAX][MAX], i, j, n, u, temp;

    // Taking inputs from user.
    printf("Enter number of Nodes : ");
    scanf("%d", &n);

    printf("\nEnter graph in matrix form : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            Graph[i][j] = temp;
        }
        
    }
    printf("\nEnter start Vertex : ");
    scanf("%d", &u);

    // Calling Dijkstra's Algorithm.
    Dijkstra(Graph, n, u);

    return 0;
}

/* Sample Matrix Graph
0 0 1 2 0 0 0 
0 0 2 0 0 3 0 
1 2 0 1 3 0 0 
2 0 1 0 0 0 1
0 0 3 0 0 2 0 
0 3 0 0 2 0 1 
0 0 0 1 0 1 0
*/