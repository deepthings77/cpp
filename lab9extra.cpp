#include <iostream>
#include <vector>

using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    void heapifyinsert(int index) {
       int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }


public:
    
    MaxPriorityQueue() {}


    void insert(int key) {
        heap.push_back(key);
        heapifyinsert(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return maxElement;
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }

        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
    void printall(){
        for(int i= 0 ; i < heap.size() ; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;
    int choice, key;

    while (true)
    {
        
    
    
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
                cout << "Enter the key to insert: ";
                cin >> key;
                pq.insert(key);
               
                break;
            case 2:
                if (!pq.isEmpty())
                    cout << "Max element extracted: " << pq.extractMax() << endl;
                else
                    cout << "Queue is empty!\n";
                break;
            case 3:
                if (!pq.isEmpty())
                    cout << "Max element: " << pq.getMax() << endl;
                else
                    cout << "Queue is empty!\n";
                break;
            case 4:
                if (pq.isEmpty())
                    cout << "Queue is empty.\n";
                else
                  pq.printall();
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
