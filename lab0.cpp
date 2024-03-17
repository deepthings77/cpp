#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void avg1(vector<float> &arr)
{
    // TC = O(N^2)

    vector<float> ans;
    int s = arr.size();
    for (int i = 0; i < s; i++)
    {
        float sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
        sum = sum / (i + 1);
        ans.push_back(sum);
    }
    for (int i = 0; i < s; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << "FOR ARR1";

    cout << endl;
}

void avg2(vector<float> &arr)
{
    // TC = O(N)

    float sum = 0;
    vector<float> ans2;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        ans2.push_back((sum / (i + 1)));
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << endl
         << "FOR ARR2";
}

int main()
{
    cout << "Deepak Kumawat" << "Roll No. 22BCS34" << endl;
    int n;
    float ele;
    cout << "Enter number of elements in array" << endl;
    cin >> n;
    cout << endl;

    vector<float> arr;
    for (int i = 0; i < n; i++)
    {

        cout << "Enter element : " << i + 1 << " ";
        cin >> ele;
        arr.push_back(ele);
        cout << endl;
    }

    // Measure time for avg1
    auto start1 = high_resolution_clock::now();
    avg1(arr);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Time taken by avg1: " << duration1.count() << " nanoseconds" << endl;

    // Measure time for avg2
    auto start2 = high_resolution_clock::now();
    avg2(arr);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Time taken by avg2: " << duration2.count() << " nanoseconds" << endl;

    return 0;
}
