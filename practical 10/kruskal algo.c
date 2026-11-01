#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int parent[], int u, int v)
{
    u = find(parent, u);
    v = find(parent, v);

    parent[v] = u;
}

int main()
{
    int n, e;
    struct Edge edge[20];
    int parent[20];
    int i, j, count = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    /* Sort edges */
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edge[j].w > edge[j + 1].w)
            {
                struct Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    /* Initialize parent */
    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nMinimum Spanning Tree:\n");

    for (i = 0; i < e; i++)
    {
        if (find(parent, edge[i].u) !=
            find(parent, edge[i].v))
        {
            printf("%d - %d = %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);

            total = total + edge[i].w;

            unionSet(parent, edge[i].u, edge[i].v);

            count++;

            if (count == n - 1)
                break;
        }
    }

    printf("Total cost = %d\n", total);

    return 0;
}
