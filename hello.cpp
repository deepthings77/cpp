#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<string> tokens;
    cout << "enter string length" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "enter expression" << endl;
        string a;
        cin >> a;
        tokens.push_back(a);
    }

    // vector<string> tokens = {"4", "13", "5", "/", "+"};
    stack<int> st;
    for (auto it : tokens)
    {
        if (it == "+" || it == "-" || it == "/" || it == "*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (it == "+")
                st.push(a + b);
            if (it == "-")
                st.push(b - a);
            if (it == "*")
                st.push(a * b);
            if (it == "/")
                st.push(b / a);
        }
        else
        {
            st.push(stoi(it));
        }
    }
    cout << "Ans:" << st.top();
    return st.top();
}