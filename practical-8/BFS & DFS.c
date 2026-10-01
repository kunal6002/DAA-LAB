#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int V;
int adj[MAX][MAX];

/* DFS Utility Function */
void DFSUtil(int v, int visited[])
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < V; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFSUtil(i, visited);
        }
    }
}

/* DFS Function */
void DFS(int start)
{
    int visited[MAX] = {0};

    DFSUtil(start, visited);
}

/* BFS Function */
void BFS(int start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0;
    int rear = 0;
    int node, i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        node = queue[front++];

        printf("%d ", node);

        for (i = 0; i < V; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int E;
    int u, v;
    int start;
    int i, j;

    clock_t startDFS, endDFS;
    clock_t startBFS, endBFS;

    double dfsTime, bfsTime;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    /* Initialize adjacency matrix */
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* DFS Time Analysis */
    startDFS = clock();

    printf("\nDFS Traversal: ");
    DFS(start);

    endDFS = clock();

    dfsTime = ((double)(endDFS - startDFS) / CLOCKS_PER_SEC);

    /* BFS Time Analysis */
    startBFS = clock();

    printf("\n\nBFS Traversal: ");
    BFS(start);

    endBFS = clock();

    bfsTime = ((double)(endBFS - startBFS) / CLOCKS_PER_SEC);

    printf("\n\nExecution Time:");
    printf("\nDFS: %f seconds", dfsTime);
    printf("\nBFS: %f seconds", bfsTime);

    return 0;
}
