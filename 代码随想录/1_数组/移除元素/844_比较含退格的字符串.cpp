#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return transfer(s) == transfer(t); 
    }

    string transfer(string s) {
        string res = "";
        for (char c : s) {
            if (c != '#') {
                res += c;
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};