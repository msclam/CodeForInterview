#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> A) {
        vector<string> tmp;
        for (auto i : A) {
            tmp.push_back(to_string(i));
        }
        sort(tmp.begin(), tmp.end(), [](const string &a, const string &b) {return a + b < b + a;});
//         sort(tmp.begin(), tmp.end(), cmp);
        
        string res;
        for (auto &s : tmp) {
            res += s;
        }
        return res;
    }
    
    static int cmp(const string &a, const string &b) {
        return a + b < b + a;
    }
};