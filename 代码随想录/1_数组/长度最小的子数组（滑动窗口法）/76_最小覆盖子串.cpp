#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int n = s.size();
        int cnt = 0;  // 匹配个数
        int i = 0;
        int len = INT_MAX;
        int minst = 0;

        for (int j = 0; j < n; j ++ ) {
            char c = s[j];
            if (mp.count(c)) {
                mp[c]--;
                if (mp[c] == 0) cnt++;
            }

            while (cnt == mp.size()) {
                int size = j - i + 1;
                if (size < len) {
                    len = size;
                    minst = i;
                }

                char b = s[i];
                if (mp.count(b)) {
                    mp[b]++;
                    if (mp[b] > 0) cnt--;
                }
                i++;
            }
        }

        string res = (len == INT_MAX) ? "" : s.substr(minst, len);
        return res;
    }
};


