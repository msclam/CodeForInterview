#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n = str.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i ++ ) {
            mp[str[i]]++;
        } 
        
        for (int i = 0; i < n; i ++ ) {
            if (mp[str[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};