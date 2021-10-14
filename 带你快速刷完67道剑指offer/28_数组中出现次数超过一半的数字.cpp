#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> A) {
        // 方法一
//         int n = A.size();
//         int cnt = 0;
//         int res;
<<<<<<< HEAD
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
=======
//         for (auto i : A) {
//             if (cnt == 0) {
//                 cnt = 1;
//                 res = i;
//             } else {
//                 if (res == i) cnt++;
//                 else cnt--;
//             }
//         }
//         int tmp = count(A.begin(), A.end(), res);
//         return tmp > n / 2 ? res : 0;
>>>>>>> 1b52e793c5f93c628989990f36a3b706aa831259
        
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
<<<<<<< HEAD
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
=======
};
>>>>>>> 1b52e793c5f93c628989990f36a3b706aa831259
