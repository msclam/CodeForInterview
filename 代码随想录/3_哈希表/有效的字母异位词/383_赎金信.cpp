#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int A[26] = {0};
        for (char i : ransomNote) {
            A[i - 'a']++;
        }
        for (char i : magazine) {
            if (A[i - 'a'] != 0) {
                A[i - 'a']--;
            }
        }
        for (char i : ransomNote) {
            if (A[i - 'a'] > 0) {
                return false;
            }
        }
        return true;
    }
};