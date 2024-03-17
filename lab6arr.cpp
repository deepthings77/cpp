#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class arrqueue
{
public:
    int *arr;
    int start, end;
    int currsize;
    int maxsize;

    arrqueue()
    {
        arr = new int[20];
        start = -1;
        end = -1;
        currsize = 0;
    };
    arrqueue(int maxsize)
    {
        arr = new int[maxsize];
        start = -1;
        end = -1;
        currsize = 0;
    }
    void insertele(int val)
    {

        if (currsize >= maxsize)
        {
            cout << "storage full";
        }
        else
        {

            if (start == -1)
            {
                start = 0;
                end = 0;
            }
            else
            {
                end = (end + 1) % maxsize;
            }
            arr[end] = val;
            currsize++;
        }
    };
    void deleteele()
    {
        if (start == -1)
        {
            cout << "queue emoty";
        }

        int popppedele = arr[start];

        if (currsize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxsize;
        }
        currsize--;
    };
    void top()
    {

        if (start == -1)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << arr[start] << endl;
        }
    };
    void displayele()
    {
        for (int i = start; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };
};

int main()
{
    cout << "Deepak Kumawat" << endl
         << "Roll no - 22BCS034" << endl;
    int choice, val;
    // cin>>max;
    arrqueue a(15);

    while (true)
    {

        cout << "enter in queue = 1";
        cout << endl;
        cout << "delete from queue = 2";
        cout << endl;
        cout << "top of queue = 3";
        cout << endl;
        cout << "to exit = 4";
        cout << endl;
        cout << "display = 5";
        cout << endl;
        cout << "Enter your choice: ";
        cout << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
        {
            cout << "Enter value ";
            cout << endl;
            cin >> val;
            a.insertele(val);
            break;
        }
        case 2:
        {
            a.deleteele();
            cout << "element deleted";
            break;
        }
        case 3:
        {
            a.top();
            break;
        }
        case 5:
        {
            a.displayele();
            break;
        }
        case 4:
        {

            cout << "exiting";
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    }

    return 0;
}