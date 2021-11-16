#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    string tmp;
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", }; // 0~9
        if (digits.size() == 0) {
            return res;
        }
        dfs(mp, digits, 0);
        return res;
    }

    void dfs(vector<string> &mp, string &digits, int idx) {
        if (idx == digits.size()) {
            res.push_back(tmp);
            return;
        }
        int num = digits[idx] - '0'; // "2" -> 2  "3"-> 3   "0" - "0" = 0  "1" - "0" = 1
        string letter = mp[num];  // 2-> "abc"  3->"def"

        for(int i = 0; i < letter.size(); i ++ ) {
            tmp.push_back(letter[i]);
            dfs(mp, digits, idx + 1);
            tmp.pop_back();
        }
    }
};