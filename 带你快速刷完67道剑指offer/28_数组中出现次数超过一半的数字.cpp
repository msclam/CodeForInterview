#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> A) {
        // 方法一
//         int n = A.size();
//         int cnt = 0;
//         int res;
//         for (int i = 0; i < n; i ++ ) {
//             if (cnt == 0) {
//                 cnt = 1;
//                 res = A[i];
//             } else {
//                 if (res == A[i]) {
//                     cnt++;
//                 } else {
//                     cnt--;
//                 }
//             }
//         }
//         int tmp = count(A.begin(), A.end(), res);
//         return tmp > A.size() / 2 ? res : 0;
        
        // 方法二
        int n = A.size();
        unordered_map<int, int> mp;
        for (auto i : A) {
            mp[i]++;
            if (mp[i] > n / 2) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int num;
        cin >> num;
        q.push(num);
    }
    
    return 0;
}