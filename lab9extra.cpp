#include <iostream>
#include <vector>

using namespace std;

class MaxHeapQueue {
private:
    vector<int> heaparr;

    void insertHeapMethod(int index) {
          while (index > 0 && heaparr[parent(index)] < heaparr[index]) {
            swap(heaparr[index], heaparr[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heaparr.size() && heaparr[left] > heaparr[largest])
            largest = left;
        if (right < heaparr.size() && heaparr[right] > heaparr[largest])
            largest = right;

        if (largest != index) {
            swap(heaparr[index], heaparr[largest]);
            heapify(largest);
        }
    }
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }


public:
    
    MaxHeapQueue() {}


    void insert(int key) {
        heaparr.push_back(key);
        insertHeapMethod(heaparr.size() - 1);
    }

    int extractMax() {
        if (heaparr.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }

        int maxElement = heaparr[0];
        heaparr[0] = heaparr.back();
        heaparr.pop_back();
        heapify(0);

        return maxElement;
    }

    int getMax() {
        if (heaparr.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }

        return heaparr[0];
    }

    bool isEmpty() {
        return heaparr.empty();
    }
    void printall(){
        for(int i= 0 ; i < heaparr.size() ; i++){
            cout << heaparr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeapQueue pq;
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
