#include <stdio.h>
#include<limits.h>

#define v 5;



int findminkey(visited[v], distance[v])
{
    int min = __INT_MAX__;
    int minkey = -1;
    for (int i = 0; i < v; i++)
    {
        if (distance[i] < min && visited[i] == 0)
        {
            min = distance[i];
            minkey = i;
        }
    }
    return minkey;
};


int dijkstra(int graph[v][v])
{
    int distance[v];
    int visited[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] = __INT_MAX__;
        visited[i] = 0;
    }

    distance[0] = 0;

    for (int i = 0; i < v; i++)
    {
        int u = findminkey(visited, distance);
        visited[u] = 1;

        for (int j = 0; j < v; j++)
        {
            if (visited[j] == 0 && graph[u][j] != 0)
            {
                if (distance[u] + graph[u][j] < distance[j])
                {
                    distance[j] = distance[u] + graph[u][j];
                }
            }
        }
    }
};


void main()
{
    int graph[v][v] = {
        {0, 9, 75, 0, 0},
        {0, 0, 95, 0, 42},
        {0, 0, 0, 51, 0},
        {0, 19, 0, 0, 0},
        {0, 0, 0, 31, 0},
    };
    dijkstra(graph);
}