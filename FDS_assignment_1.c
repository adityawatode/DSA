#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // global stack top

// Push (Create)
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed.\n", value);
}

// Display (Read)
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Pop (Delete)
void pop() {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped.\n", temp->data);
    top = top->next;
    free(temp);
}

// Update (change value at a given position from top)
void update(int pos, int newVal) {
    struct Node* temp = top;
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
        printf("\n1. Push\n2. Display\n3. Pop\n4. Update\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:
                printf("Enter position from top: ");
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
