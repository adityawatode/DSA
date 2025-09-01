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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push
    void push(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Stack overflow! (Memory not available)\n";
            return;
        }
        newNode->next = top;
        top = newNode;
        cout << value << " pushed.\n";
    }

    // Pop
    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow! (Stack is empty)\n";
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped.\n";
        return poppedValue;
    }

    // Display
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Update
    void update(int pos, int newVal) {
        if (top == nullptr) {
            cout << "Stack is empty, nothing to update.\n";
            return;
        }
        Node* temp = top;
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

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Push\n2. Display\n3. Pop\n4. Update\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.display();
                break;
            case 3:
                val = s.pop();
                if (val != -1) {
                    cout << "Returned value: " << val << endl;
                }
                break;
            case 4:
                cout << "Enter position from top: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> val;
                s.update(pos, val);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
