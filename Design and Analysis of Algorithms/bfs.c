#include<stdio.h>

int queue[7];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == 7 - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return value;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int bfshelper(int v[7][7], int start, int visited[]) {
    int i;
    
    visited[start] = 1;
    enqueue(start);
    
    printf("BFS Traversal starting from vertex %d: ", start);
    
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        
        for (i = 0; i < 7; i++) {
            if (v[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int bfs(int v[7][7]) {
    int visited[7] = {0};
    int i;
    
    printf("BFS Traversal for the entire graph:\n");

    for (i = 0; i < 7; i++) {
        if (visited[i] == 0) {
            bfshelper(v, i, visited);
        }
    }
}

void main() {
    int v[7][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {1, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };
    bfs(v);
}
