#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// For sorting the array
void bubble(vector<int> &arr, int n)
{
    int flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int flag = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (i != 0)
        {
            if (flag == 0)
            {
                cout << "Already Sorted" << endl;
                break;
            }
        }
    }

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Deepak Kumawat" << endl << "Roll no - 22BCS034" << endl;
    
    int n;
    cout << "Enter Array size ";
    cin >> n;
    cout << endl;
    // int *arr = new int[size];

    // cout << "Enter the elements: ";
    // for (int i = 0; i < size; i++)
    //     cin >> arr[i];
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cout << " Enter number " << i + 1 << " ";
        cin >> num;
        arr[i] = num;
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble(arr, n);
    return 0;
}
