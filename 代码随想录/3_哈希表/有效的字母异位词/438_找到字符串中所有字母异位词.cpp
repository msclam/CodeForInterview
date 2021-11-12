#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> res;
        if (m < n) return res;

        int pCnt[26] = {0};
        int sCnt[26] = {0};
        
        for (int i = 0; i < n; i ++ ) {
            pCnt[p[i] - 'a']++;
        } 

        int i = 0;
        for (int j = 0; j < m; j ++ ) {
            sCnt[s[j] - 'a']++;
            while (sCnt[s[j] - 'a'] > pCnt[s[j] - 'a']) {
                sCnt[s[i] - 'a']--;
                i++;
            }
            if (j - i + 1 == n) {
                res.push_back(i);
            }
        }
        return res;
    }
};