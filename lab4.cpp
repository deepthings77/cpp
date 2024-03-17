#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{

public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Element " << value << " inserted successfully.\n";
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
            return;

        Node *temp = head;

        if (position == 1)
        {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; temp != nullptr && i < position - 1; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr)
            return;

        Node *nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked List: ";
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << "Deepak Kumawat" << endl
         << "Roll no - 22BCS034" << endl;
    LinkedList list;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete at position\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insert(value);
            break;
        }
        case 2:
        {
            cout << "Enter the postion to delete: ";
            cin >> value;
            list.deleteAtPosition(value);
            break;
        }
        case 3:
        {
            list.display();
            break;
        }
        case 4:
        {
            cout << "Exiting program...\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    }

    return 0;
}
