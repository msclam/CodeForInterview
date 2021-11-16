#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) return -1;
        for (int i = 0; i < m - n + 1; i ++ ) {
            int a = i;
            int b = 0;
            while (b < n && s[a] == p[b]) {
                a++;
                b++;
            }
            if (b == n) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string s, string p) {
        if (p.size() == 0) return 0;
        vector<int> next(p.size(), 0);
        getNext(next, p);
        int j = 0; 
        for (int i = 0; i < s.size(); i ++ ) {
            while (j > 0 && s[i] != p[j]) {
                j = next[j - 1];
            }
            if (s[i] == p[j]) {
                j++;
            }
            if (j == p.size()) {
                return i - p.size() + 1;
            }
        }
        return -1;
    }

    void getNext(vector<int> &next, string &p) {
        // j是前缀末尾，i是后缀末尾
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