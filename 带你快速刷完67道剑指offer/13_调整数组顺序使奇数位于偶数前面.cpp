#include <bits/stdc++.h>

using namespace std;

vector<int> exchange(vector<int> &nums)
{
    // 方式一：暴力方法
    // int n = nums.size();
    // vector<int> res(n, 0);
    // int idx = 0;
    // for (int i = 0; i < n; i ++ ) {
    //     if (nums[i] % 2 != 0) {
    //         res[idx++] = nums[i];
    //     }
    // }
    // for (int i = 0; i < n; i ++ ) {
    //     if (nums[i] % 2 == 0) {
    //         res[idx++] = nums[i];
    //     }
    // }
    // return res;

    // 方式二： 快速排序方法
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && nums[i] % 2 != 0)
            i++;
        while (i < j && nums[j] % 2 == 0)
            j--;
        if (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    return nums;
}
