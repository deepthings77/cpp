#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void mergeArr(vector<int> &arr, int low, int mid, int high)
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
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeArr(arr, low, mid, high);
}

int searchEle(vector<int> &arr, int n, int item)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == item)
        {

            return mid;
        }
        else if (arr[mid] > item)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

void deleteItem(vector<int> &arr, int index)
{
    // arr.erase(arr.begin() + index);
    for (int i = index; i < arr.size() - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    arr.pop_back();
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void insertInSortedPosition(vector<int> &arr, int item)
{
    int index = 0;
    while (index < arr.size() && arr[index] < item)
    {
        index++;
    }
    // arr.insert(arr.begin() + index, item);
    arr.push_back(item);
    for (int i = arr.size() - 1; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }
    // arr[index] = item;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    cout << "Deepak Kumawat" << endl
         << "Roll no - 22BCS034" << endl;
    int n;
    cout << "Enter Array size ";
    cin >> n;
    cout << endl;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cout << " Enter number " << i + 1 << " ";
        cin >> num;
        arr[i] = num;
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int item;
    cout << "Enter item to search"
         << "/n";
    cin >> item;
    cout << endl;

    int index = searchEle(arr, n, item);
    ;
    if (index != -1)
    {
        cout << "Item found at index " << index << " and deleted.\n";
        deleteItem(arr, index);
    }
    else
    {
        cout << "Item not found, inserting...\n";
        insertInSortedPosition(arr, item);
    }

    return 0;
}