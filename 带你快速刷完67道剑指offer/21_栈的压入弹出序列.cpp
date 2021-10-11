#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i = 0, j = 0;
        stack<int> st;
        while (i < pushV.size()) {
            if (pushV[i] != popV[j]) {
                st.push(pushV[i]);
                i++;
            } else {
                i++;
                j++;
                while (!st.empty() && popV[j] == st.top()) {
                    st.pop();
                    j++;
                }
            }
        }
        return st.empty();
    }
};