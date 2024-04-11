#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;

        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        QuickSort(arr, low, pIndex - 1);
        QuickSort(arr, pIndex + 1, high);
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void InsertionSort(vector<int> &arr, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
void SelectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main()
{

    cout << "DEEPAK KUMAWAT" << endl
         << "22BCS034" << endl;
    vector<int> arr;
    int num;

    while (true)
    {

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
        case 1:
            cout << "Enter the Value" << endl;
            cin >> num;
            cout << endl;
            arr.push_back(num);

            break;
        case 2:
            QuickSort(arr, 0, arr.size() - 1);

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            break;
        case 3:
            MergeSort(arr, 0, arr.size() - 1);
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 4:
            int n;
            n = arr.size();
            InsertionSort(arr, n);
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 5:
            int m;
            m = arr.size();
            SelectionSort(arr, n);
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 6:
            return 0;

        default:
            break;
        }
    }
}