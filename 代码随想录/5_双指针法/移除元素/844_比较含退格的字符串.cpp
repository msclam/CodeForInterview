#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return check(s) == check(t);
    }

    string check(string str) {
        string res = "";
        for (char c : str) {
            if (c != '#') {
                res += c;
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};