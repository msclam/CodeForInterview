#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        for (int a : A) {
            for (int b : B) {
                mp[a + b]++;
            }
        }
        int cnt = 0;
        for (int c : C) {
            for (int d : D) {
                int sumAB = 0 - (c + d);
                if (mp.find(sumAB) != mp.end()) {
                    cnt += mp[sumAB];
                }
            }
        }
        return cnt;
    }
};