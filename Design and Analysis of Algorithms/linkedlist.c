#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertAtLast(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;  
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;
        tail = newNode;
    }
}

void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->link == NULL) {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->link != tail) {
        temp = temp->link;
    }

    free(tail);
    tail = temp;
    tail->link = NULL;
}

void displayList() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(40);

    printf("List before deletion:\n");
    displayList();

    deleteAtLast();

    printf("List after deletion:\n");
    displayList();

    return 0;
}
