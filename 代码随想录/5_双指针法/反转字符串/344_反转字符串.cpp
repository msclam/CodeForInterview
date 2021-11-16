#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverse(vector<char> &s, int l, int r) {
        for (int i = 0; i < (r - l + 1) / 2; i ++ ) {
            swap(s[l + i], s[r - i]);
        }

        // for (int i = l, j = r; i < j; i ++, j -- ) {
        //     swap(s[i], s[j]);
        // }
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        // for (int i = 0, j = n - 1; i < j; i ++, j -- ) {
        //     swap(s[i], s[j]);
        // }    

        // for (int i = 0; i < n / 2; i ++ ) {
        //     swap(s[i], s[n - i - 1]);
        // }
        reverse(s, 0, n - 1);
    }
};