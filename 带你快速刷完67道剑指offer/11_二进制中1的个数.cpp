#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
     int NumberOf1(int n) {
         unsigned int flag = 1;
         int cnt = 0;
         while (flag != 0) {
             if (flag & n) cnt++;
             flag <<= 1;
         }
         return cnt;
     }
};