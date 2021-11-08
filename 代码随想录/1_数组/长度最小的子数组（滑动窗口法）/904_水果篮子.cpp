#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int res = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j ++ ) {
            mp[fruits[j]]++;
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};