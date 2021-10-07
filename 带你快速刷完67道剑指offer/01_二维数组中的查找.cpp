#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& A, int target) {
        if (A.size() == 0 || A[0].size() == 0) return false;
        int m = A.size(), n = A[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target == A[i][j]) return true;
            else if (target > A[i][j]) i ++;
            else j --;
        }
        return false;
    }
};

int main() {

    return 0;
}