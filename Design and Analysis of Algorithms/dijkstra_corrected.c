#include <stdio.h>
#include <limits.h>

#define v 5

int findminkey(int visited[v], int distance[v]) {
    int min = INT_MAX;
    int minkey = -1;
    for (int i = 0; i < v; i++) {
        if (distance[i] < min && visited[i] == 0) {
            min = distance[i];
            minkey = i;
        }
    }
    return minkey;
}

void dijkstra(int graph[v][v]) {
    int distance[v];
    int visited[v];

    for (int i = 0; i < v; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[0] = 0;

    for (int i = 0; i < v; i++) {
        int u = findminkey(visited, distance);
        if (u == -1) break; // No reachable vertices left
        
        visited[u] = 1; // Mark as visited

        for (int j = 0; j < v; j++) {
            if (visited[j] == 0 && graph[u][j] != 0 && distance[u] != INT_MAX) {
                if (distance[u] + graph[u][j] < distance[j]) {
                    distance[j] = distance[u] + graph[u][j];
                }
            }
        }
    }

    // Print results
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < v; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int graph[v][v] = {
        {0, 9, 75, 0, 0},
        {0, 0, 95, 0, 42},
        {0, 0, 0, 51, 0},
        {0, 19, 0, 0, 0},
        {0, 0, 0, 31, 0},
    };
    
    printf("Dijkstra's Algorithm Results:\n");
    dijkstra(graph);
    
    return 0;
