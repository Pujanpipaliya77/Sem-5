#include <stdio.h>
#include <stdlib.h>

#define size 100
int queue[size];
int front = -1;
int rear = -1;

void push() {
    int value;
    if (rear == size - 1) {
        printf("Queue is full\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

void pop() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        front = rear = -1;  
    } else {
        printf("Deleted element is: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
