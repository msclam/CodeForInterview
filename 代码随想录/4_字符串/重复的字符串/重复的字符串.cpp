#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.size();
        // for (int len = 1; len * 2 <= n; len ++ ) {
        //     if (n % len == 0) {
        //         bool flag = true;
        //         for (int j = len; j < n; j ++ ) {
        //             if (s[j] != s[j - len]) {
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if (flag) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        int n = s.size();
        if (n == 0) return false;
        
        vector<int> next(n, 0);
        
        getNext(next, s);
        
        if (next[n - 1] != 0 && n % (n - next[n - 1]) == 0) {
            return true;
        }
        
        return false;
    }

    void getNext(vector<int> &next, string &p) {
        // j为前缀末尾，i为后缀末尾
        int j = 0;
        next[0] = 0; 
        for (int i = 1; i < p.size(); i ++ ) {
            while (j > 0 && p[i] != p[j]) {
                j = next[j - 1];
            }
            if (p[i] == p[j]) {
                j++;
            }
            next[i] = j;
        }
    }
};