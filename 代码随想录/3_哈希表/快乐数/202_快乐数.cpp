#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while (true) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (st.find(sum) != st.end()) {
                return false;
            } else {
                st.insert(sum);
            }
            n = sum;
        }
    }
};