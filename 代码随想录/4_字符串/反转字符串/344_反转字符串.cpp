#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void reverseString(vector<char>& s) {
        int n = s.size();
        // for (int i = 0, j = n - 1; i < j; i ++, j -- ) {
        //     swap(s[i], s[j]);
        // }    

        for (int i = 0; i < n / 2; i ++ ) {
            swap(s[i], s[n - i - 1]);
        }
    }
};