#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    printf("%c ", min_index + 'P');
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    // this is the distance array
    int dist[V];
    // this is the visited array
    bool sptSet[V];

    // reset the entire graphZ
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // resetting the distance of source to zero
    dist[src] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = minDistance(dist, sptSet); // acts as the priority queue
                                           // priority queue implemented using linear array
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v]; // edge relaxation
    }

    printf("\n");
    // printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 1, 0, 6, 7, 0},
        {0, 0, 1, 4, 0, 0},
        {0, 0, 0, 2, 0, 1},
        {0, 0, 0, 0, 3, 2},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0},
    };

    printf("\nOrder in which nodes get included into the set of Vertices for which the shortest path distances are finalized : \n");
    dijkstra(graph, 0);
    printf("\n\n");

    return 0;
}