#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
//         return n * (n + 1) / 2;
//         int res = 0;
//         for (int i = 1; i <= n; i ++ ) {
//             res += i;
//         }
//         return res;

//         bool x = n > 1 && (n = n + Sum_Solution(n - 1));
//         return n;
        
//         if (n == 1) return 1;
//         return n + Sum_Solution(n - 1);
        
        int sum = n;
        bool x = (n > 1) && (sum += Sum_Solution(n - 1));
        return sum;
    }
};

int main() {

    int a = 3;
    a <<= 2;
    cout << a;
    return 0;
}