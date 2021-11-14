#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        string tmp = "";
        s += " ";
        for (char c : s) {
            if (c != ' ') {
                tmp += c;
            } else {
                if (!tmp.empty()) {
                    res.push_back(tmp);
                    tmp = "";
                }
            }
        }
        string str = "";
        for (int i = res.size() - 1; i >= 0; i -- ) {
            str += res[i] + " ";
        }
        str.pop_back();
        return str;
    }
};