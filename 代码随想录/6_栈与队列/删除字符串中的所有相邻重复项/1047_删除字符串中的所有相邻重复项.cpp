#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // int n = s.size();
        // string res = "";
        // for (int i = 0; i < n; i ++ ) {
        //     if (res.empty() || res.back() != s[i]) {
        //         res.push_back(s[i]);
        //     } else {
        //         res.pop_back();
        //     }
        // }
        // return res;

        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i ++ ) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        } 
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};