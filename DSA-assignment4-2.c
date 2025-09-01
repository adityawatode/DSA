// queue implementation

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {   
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Queue overflow! (Memory not available)\n";
            return;
        }
        if (rear == nullptr) { // first element
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued.\n";
    }

    // Dequeue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow! (Queue is empty)\n";
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        if (front == nullptr) rear = nullptr; // if queue became empty
        delete temp;
        cout << dequeuedValue << " dequeued.\n";
        return dequeuedValue;
    }

    // Display
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Update
    void update(int pos, int newVal) {
        if (front == nullptr) {
            cout << "Queue is empty, nothing to update.\n";
            return;
        }
        Node* temp = front;
        int i = 1;
        while (temp != nullptr && i < pos) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) {
            cout << "Invalid position.\n";
        } else {
            cout << "Updated position " << pos << " from " << temp->data << " to " << newVal << ".\n";
            temp->data = newVal;
        }
    }

    // Destructor → free memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Enqueue\n2. Display\n3. Dequeue\n4. Update\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.display();
                break;
            case 3:
                val = q.dequeue();
                if (val != -1) {
                    cout << "Returned value: " << val << endl;
                }
                break;
            case 4:
                cout << "Enter position from front: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> val;
                q.update(pos, val);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
