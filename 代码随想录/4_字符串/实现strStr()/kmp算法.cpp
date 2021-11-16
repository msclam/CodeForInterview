#include <bits/stdc++.h>

using namespace std;

void getNext(vector<int> &next, string &p) {
    // j为前缀末尾，i为后缀末尾
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

int strStr(string &s, string &p) {
    if (p.size() == 0) {
        return 0;
    }
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
        if (p.size() == j) {
            return i - p.size() + 1;
        }
    }
}

int main() {

    // string s = "aabaabaaf";
    // string p = "aabaaf";
    string s = "";
    string p = "";
    cout << strStr(s, p);

    return 0;
}