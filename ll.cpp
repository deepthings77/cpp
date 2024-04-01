#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Deepak Kumawat" << endl
         << "Roll no - 22BCS034" << endl;
    vector<string> exp;
    cout << "enter length of expression" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << " expression  : " << i + 1 << endl;
        string a;
        cin >> a;
        exp.push_back(a);
    }

    stack<int> postordertrivaersal;
    for (auto postorder : exp)
    {
        if (postorder == "+" || postorder == "-" || postorder == "/" || postorder == "*")
        {
            int a = postordertrivaersal.top();
            postordertrivaersal.pop();
            int b = postordertrivaersal.top();
            postordertrivaersal.pop();
            if (postorder == "+")
                postordertrivaersal.push(a + b);
            if (postorder == "-")
                postordertrivaersal.push(b - a);
            if (postorder == "*")
                postordertrivaersal.push(a * b);
            if (postorder == "/")
                postordertrivaersal.push(b / a);
             else if (postorder == "/")
            {
                if (a == 0)
                {
                    cout << "Error: Division by zero" << endl;
                    return 1;
                }
                postordertrivaersal.push(b / a);
            }
             else if (postorder == "^")
                postordertrivaersal.push(pow(b, a));
        }
        else
        {
            postordertrivaersal.push(stoi(postorder));
        }
    }
    cout << "Ans:" << postordertrivaersal.top();
    return postordertrivaersal.top();
}