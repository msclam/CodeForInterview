#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
                int A = st.top();
                st.pop();
                int B = st.top();
                st.pop();
                if (s[i] == "+") st.push(B + A);
                if (s[i] == "-") st.push(B - A);
                if (s[i] == "*") st.push(B * A);
                if (s[i] == "/") st.push(B / A);
            } else {
                st.push(stoi(s[i]));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};