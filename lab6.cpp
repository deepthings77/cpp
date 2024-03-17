#include <iostream>
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode *next;

    QueueNode(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode *front = nullptr;
    QueueNode *rear = nullptr;
    int size = 0;

public:
    void insert(int value) {
        QueueNode *temp = new QueueNode(value);
        if (front == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void remove() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        QueueNode *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    void top() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Top value: " << front->data << endl;
        }
    }

    void display() {
        QueueNode *temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "Deepak Kumawat" << endl
         << "Roll no - 22BCS034" << endl;
    Queue q;
    int choice, val;

    while (true) {
        cout << "1. Insert into queue" << endl;
        cout << "2. Delete from queue" << endl;
        cout << "3. Top of queue" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.insert(val);
                break;
            case 2:
                q.remove();
                cout << "Element deleted." << endl;
                break;
            case 3:
                q.top();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
