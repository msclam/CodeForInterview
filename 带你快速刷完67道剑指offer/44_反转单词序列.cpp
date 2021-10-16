#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string res = "";
        string tmp = "";
        for (auto &c : str) {
            if (c == ' ') {
                if (!tmp.empty()) {
                    res = " " + tmp + res;
                    tmp = "";
                }
            } else {
                tmp += c;
            }
        }
        if (!tmp.empty()) {
            res = tmp + res;
        }
        
        return res;
    }
};

void qSort(vector<int> &A, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = A[l + r >> 1];
    while (i < j) {
        while (A[i] < x) i ++;
        while (A[j] > x) j --;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (l < j) qSort(A, l, j);
    if (i < r) qSort(A, i, r);
}