#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string trim(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        return s;
    }
    bool isNumber(string s) {
        s = trim(s); // 6.6e+6
        int n = s.size();
        bool hasNum = false, hasDot = false, hasE = false;
        for (int i = 0; i < n; i ++ ) {
            if (s[i] >= '0' && s[i] <= '9') {
                hasNum = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && !(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
            } else if (s[i] == '.') {
                if (hasDot || hasE) return false;
                hasDot = true;
            } else if (s[i] == 'E' | s[i] == 'e') {
                if (hasE || !hasNum) return false;
                hasE = true;
                hasNum = false;
            } else {
                return false;
            }
        }
        return hasNum;
    }
};