#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 方法一: [l, r]型
        // int n = nums.size();
        // if (n == 0) return -1;
        // int l = 0, r = n - 1;
        // while (l <= r) {
        //     int mid = l + r >> 1;
        //     if (target == nums[mid]) return mid;
        //     else if (target > nums[mid]) l = mid + 1;
        //     else r = mid - 1;
        // }
        // return -1;

        // 方法二: [l, r)型
        int n = nums.size();
        if (n == 0) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] == target) return l;
        return -1;
    }
};

int main() {
    vector<int> A = {1, 2, 2, 3, 3, 3, 4, 5};
    int target = 3; // 3 5

    int n = A.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        // if (A[mid] < target) l = mid + 1;
        // else r = mid;
        if (A[mid] > target) r = mid - 1;
        else l = mid;
    }
    if (A[l] == target) cout << l << endl;
    else cout << "Not found" << endl;
    return 0;
}