#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr , int low , int high){
    
  int pivot=arr[high];
  int i=(low-1);
    for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

void QuickSort(vector<int> &arr , int low , int high){
    if(low < high){

        int p = partition(arr , low , high);
         QuickSort(arr,low,p-1);
    QuickSort(arr,p+1,high);
    }

}
void MergeSort(vector<int> &arr){
    int left = arr[0];
    int right = arr[arr.size() -1 ];
    
}
void InsertionSort(vector<int> &arr){

}
void SelectionSort(vector<int> &arr){

}


int main(){

vector<int> arr;
int num;

while(true){


        int val;
        cout << "1: Enter Values" << endl;
        cout << "2: QuickSort" << endl;
        cout << "3: MergeSort" << endl;
        cout << "4: InsertionSort" << endl;
        cout << "5: SelectionSort" << endl;
        cout << "6: Exit" << endl;
        cout << "Enter choice: ";
        cin >> val;
        cout << endl;

        switch (val)
        {
        case 1 :
            cout<< "Enter the Value" << endl;
            cin >> num ;
            cout<< endl;
            arr.push_back(num);

            break;
        case 2 :
            QuickSort(arr , 0 , arr.size() -1);
                
        for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
       }
    cout << endl;

            break;
        case 3 :
            MergeSort(arr);
                 for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
       }
    cout << endl;
            break;
        case 4 :
            InsertionSort(arr);
                 for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
       }
    cout << endl;
            break;
        case 5 :
            SelectionSort(arr);
                 for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
       }
    cout << endl;
            break;
        case 6 :
           return 0;
        
        default:
            break;
        }



}












}