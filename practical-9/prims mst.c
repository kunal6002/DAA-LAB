#include <stdio.h>
#include <limits.h>

#define MAX 100

void primMST(int graph[MAX][MAX], int V)
{
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    int i, v, count;
    int min, u;
    int totalWeight = 0;

    for (i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for (count = 0; count < V - 1; count++)
    {
       
        min = INT_MAX;
        u = -1;

        for (v = 0; v < V; v++)
        {
            if (visited[v] == 0 && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }


        visited[u] = 1;

        for (v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                visited[v] == 0 &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }


    printf("\nEdge\tWeight\n");

    for (i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n",
               parent[i], i, graph[i][parent[i]]);

        totalWeight += graph[i][parent[i]];
    }

    printf("\nTotal weight of MST = %d\n", totalWeight);
}

int main()
{
    int graph[MAX][MAX];
    int V;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}
