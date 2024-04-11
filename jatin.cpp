#include <iostream>
#include <vector>

using namespace std;

class MaxHeapQueue {
private:
    vector<int> heaparr;

    void insertHeapMethod(int index) {
        int parentIndex = (index - 1) / 2;
          while (index > 0 && heaparr[parentIndex] < heaparr[index]) {
            swap(heaparr[index], heaparr[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapify(int index) {
        int largestIndex = index;
        int leftIndex =  2 * index + 1;
        int rightIndex =  2 * index + 2;

        if (leftIndex < heaparr.size() && heaparr[leftIndex] > heaparr[largestIndex])
            largestIndex = leftIndex;
        if (rightIndex < heaparr.size() && heaparr[rightIndex] > heaparr[largestIndex])
            largestIndex = rightIndex;

        if (largestIndex != index) {
            swap(heaparr[index], heaparr[largestIndex]);
            heapify(largestIndex);
        }
    }
  


public:
    
    MaxHeapQueue() {}


    void insert(int key) {
        heaparr.push_back(key);
        insertHeapMethod(heaparr.size() - 1);
    }

    int deleteEle() {
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

    int topele() {
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
                    cout << "Max element extracted: " << pq.deleteEle()<< endl;
                else
                    cout << "Queue is empty!\n";
                break;
            case 3:
                if (!pq.isEmpty())
                    cout << "Max element: " << pq.topele() << endl;
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
