#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // void reverse(string &s, int l, int r) {
        // for (int i = 0; i < (r - l + 1) / 2; i ++ ) {
        //     swap(s[l + i], s[r - i]);
        // }

        // for (int i = l, j = r; i < j; i ++, j -- ) {
        //     swap(s[i], s[j]);
        // }
    // }

    string reverseLeftWords(string s, int t) {
        // int n = s.size();
        // t %= n;

        // reverse(s, 0, t - 1);
        // reverse(s, t, n - 1);
        // reverse(s, 0, n - 1);

        // return s;

        // int n = s.size();
        // t %= n;
        // reverse(s.begin(), s.begin() + t);
        // reverse(s.begin() + t, s.begin() + n);
        // reverse(s.begin(), s.begin() + n);
        // return s;

        int n = s.size();
        string res;
        for (int i = t; i < n + t; i ++ ) {
            res.push_back(s[i % n]);
        }
        return res;
    }
};