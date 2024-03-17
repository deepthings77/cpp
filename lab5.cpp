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

    stack<int> post;
    for (auto it : exp)
    {
        if (it == "+" || it == "-" || it == "/" || it == "*")
        {
            int a = post.top();
            post.pop();
            int b = post.top();
            post.pop();
            if (it == "+")
                post.push(a + b);
            if (it == "-")
                post.push(b - a);
            if (it == "*")
                post.push(a * b);
            if (it == "/")
                post.push(b / a);
        }
        else
        {
            post.push(stoi(it));
        }
    }
    cout << "Ans:" << post.top();
    return post.top();
}