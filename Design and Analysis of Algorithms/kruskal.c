#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX_EDGES], mst[MAX_VERTICES];
int parent[MAX_VERTICES];

int find(int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]]; 
        i = parent[i];
    }
    return i;
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) {
        parent[rootV] = rootU;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskal(int V, int E, struct Edge edges[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    
    qsort(edges, E, sizeof(edges[0]), compare);
    
    int edgeCount = 0;
    int totalWeight = 0;
    
    printf("\nEdges in the Minimum Spanning Tree:\n");
    printf("SRC | DEST | WEIGHT\n");
    printf("----|------|-------\n");
    
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        
        int uComp = find(u);
        int vComp = find(v);
        
        if (uComp != vComp) {
            mst[edgeCount] = edges[i];
            unionSet(uComp, vComp);
            totalWeight += edges[i].weight;
            
            printf(" %d  |  %d   |   %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            edgeCount++;
        }
    }
    
    printf("\nTotal weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    kruskal(V, E, edges);
    
    return 0;
}
