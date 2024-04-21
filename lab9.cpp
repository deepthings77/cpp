#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int priority;
    int value;

    Node(int p, int v) : priority(p), value(v) {}
};

class MaxHeapQueue {
private:
    vector<Node> heaparr;

    void insertHeapMethod(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heaparr[parent].priority < heaparr[index].priority) {
            swap(heaparr[index], heaparr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heaparr.size() && heaparr[left].priority > heaparr[largest].priority)
            largest = left;
        if (right < heaparr.size() && heaparr[right].priority > heaparr[largest].priority)
            largest = right;

        if (largest != index) {
            swap(heaparr[index], heaparr[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeapQueue() {}

    void insert(int priority, int value) {
        heaparr.push_back(Node(priority, value));
        insertHeapMethod(heaparr.size() - 1);
    }

    Node extractMax() {
        if (heaparr.empty()) {
            cout << "Queue is empty!" << endl;
            return Node(-1, -1);
        }

        Node maxElement = heaparr[0];
        heaparr[0] = heaparr.back();
        heaparr.pop_back();
        heapify(0);

        return maxElement;
    }

    Node getMax() {
        if (heaparr.empty()) {
            cout << "Queue is empty!" << endl;
            return Node(-1, -1);
        }

        return heaparr[0];
    }

    bool isEmpty() {
        return heaparr.empty();
    }

    void printall() {
        
        for (int i = 0; i < heaparr.size(); i++) {
            cout << "(" << heaparr[i].priority << ", " << heaparr[i].value << ") ";
        }
        cout << endl;
    }
};

int main() {
    cout << "DEEPAK KUMAWAT " << "22BCS034" << endl;
    MaxHeapQueue pq;
    int choice, priority, value;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete top\n";
        cout << "3. Get top Max\n";
        cout << "4. Print all \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the priority and value to insert: ";
                cin >> priority >> value;
                pq.insert(priority, value);
                break;
            case 2:
                if (!pq.isEmpty()) {
                    Node maxElement = pq.extractMax();
                    cout << "Max element extracted: (" << maxElement.priority << ", " << maxElement.value << ")\n";
                } else {
                    cout << "Queue is empty!\n";
                }
                break;
            case 3:
                if (!pq.isEmpty()) {
                    Node maxElement = pq.getMax();
                    cout << "Max element: (" << maxElement.priority << ", " << maxElement.value << ")\n";
                } else {
                    cout << "Queue is empty!\n";
                }
                break;
            case 4:
                if (pq.isEmpty()) {
                    cout << "Queue is empty.\n";
                } else {
                    pq.printall();
                }
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
