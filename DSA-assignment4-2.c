// Queue implementation

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue (Create)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

// Display (Read)
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Dequeue (Delete)
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow!\n");
        return;
    }
    struct Node* temp = front;
    printf("%d dequeued.\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL; // queue became empty
    free(temp);
}

// Update (change value at position from front)
void update(int pos, int newVal) {
    struct Node* temp = front;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        printf("Updated position %d from %d to %d.\n", pos, temp->data, newVal);
        temp->data = newVal;
    }
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1. Enqueue\n2. Display\n3. Dequeue\n4. Update\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                printf("Enter position from front: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &val);
                update(pos, val);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
