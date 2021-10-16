#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverse(string &s, int l, int r) {
        for (int i = 0; i < (r - l + 1) / 2; i ++ ) {
            swap(s[l + i], s[r - i]);
        }
    }
    string LeftRotateString(string str, int k) {
//         string s;
//         int n = str.size();
//         if (n == 0) return str;
//         if (k > n) k %= n;
//         for (int i = k; i < k + n; i ++ ) {
//             s.push_back(str[i % n]);
//         }
//         return s;
        
        int n = str.size();
        if (n == 0) return str;
        if (k > n) k %= n;
        reverse(str, 0, k - 1);
        reverse(str, k, n - 1);
        reverse(str, 0, n - 1);
        return str;
    }
};