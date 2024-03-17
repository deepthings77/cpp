#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int postfixevaluate(string s){

stack<int> st;
   for (auto it : s)
    {
        if (it == '+' || it == '-' || it == '/' || it == '*')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (it == '+')
                st.push(a + b);
            if (it == '-')
                st.push(b - a);
            if (it == '*')
                st.push(a * b);
            if (it == '/')
                st.push(b / a);
        }
        else
        {
            st.push((int)it);
        }
    }

return st.top();
}

int main(){

    string s = "56+";

   int ans = postfixevaluate(s);
    cout << ans;
}
