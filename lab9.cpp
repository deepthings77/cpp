#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int priority;
    int value;

    Node(int p, int v) : priority(p), value(v) {}
};

class MaxPriorityQueue {
private:
    vector<Node> heap;

    void heapifyinsert(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent].priority < heap[index].priority) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left].priority > heap[largest].priority)
            largest = left;
        if (right < heap.size() && heap[right].priority > heap[largest].priority)
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxPriorityQueue() {}

    void insert(int priority, int value) {
        heap.push_back(Node(priority, value));
        heapifyinsert(heap.size() - 1);
    }

    Node extractMax() {
        if (heap.empty()) {
            cout << "Queue is empty!" << endl;
            return Node(-1, -1);
        }

        Node maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return maxElement;
    }

    Node getMax() {
        if (heap.empty()) {
            cout << "Queue is empty!" << endl;
            return Node(-1, -1);
        }

        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printall() {
        for (int i = 0; i < heap.size(); i++) {
            cout << "(" << heap[i].priority << ", " << heap[i].value << ") ";
        }
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;
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
