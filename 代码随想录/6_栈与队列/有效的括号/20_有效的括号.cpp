#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 左多， 右多， 左右不匹配
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i ++ ) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (st.empty() || st.top() != s[i]) {
                return false;
            } else {
                st.pop();
            }
        }

        return st.empty();

        // int n = s.size();
        // stack<char> st;
        // for (int i = 0; i < n; i ++ ) {
        //     if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        //         st.push(s[i]);
        //     } else if (s[i] == ')') {
        //         if (!st.empty() && st.top() == '(') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     } else if (s[i] == '}') {
        //         if (!st.empty() && st.top() == '{') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     } else if (s[i] == ']') {
        //         if (!st.empty() && st.top() == '[') {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     }
        // }
        // if (!st.empty()) {
        //     return false;
        // }
        // return true;
    }
};