#include <stdio.h>
#include <stdlib.h>

#define maxvertices 7

int adj[maxvertices][maxvertices] = {
    {0, 0, 0, 1, 1, 1, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0}};

int visited[maxvertices] = {0};

void bfs(int start)
{
    int queue[maxvertices];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int current = queue[front++];
        printf("%c ", current + 'A');

        for (int i = 0; i < maxvertices; i++)
        {
            if (adj[current][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start)
{
    printf("%c ", start + 'A');
    visited[start] = 1;

    for (int i = 0; i < maxvertices; i++)
    {
        if (adj[start][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    printf("BFS on directed graph starting at vertex C: ");
    bfs(2);
    printf("\n");

    for (int i = 0; i < maxvertices; i++)
    {
        visited[i] = 0;
    }

    printf("DFS on directed graph starting at vertex C: ");
    dfs(2);
    printf("\n");

    // For undirected graph
    for (int i = 0; i < maxvertices; i++)
    {
        for (int j = 0; j < maxvertices; j++)
        {
            if (adj[i][j] == 1)
            {
                adj[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < maxvertices; i++)
    {
        visited[i] = 0;
    }

    printf("BFS on undirected graph starting at vertex C: ");
    bfs(2);
    printf("\n");

    for (int i = 0; i < maxvertices; i++)
    {
        visited[i] = 0;
    }

    printf("DFS on undirected graph starting at vertex C: ");
    dfs(2);
    printf("\n");

    return 0;
}