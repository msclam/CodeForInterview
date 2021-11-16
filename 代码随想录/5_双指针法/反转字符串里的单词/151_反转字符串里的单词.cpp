#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // vector<string> res;
        // string tmp = "";
        // s += " ";
        // for (char c : s) {
        //     if (c != ' ') {
        //         tmp += c;
        //     } else {
        //         if (!tmp.empty()) {
        //             res.push_back(tmp);
        //             tmp = "";
        //         }
        //     }
        // }
        // string str = "";
        // for (int i = res.size() - 1; i >= 0; i -- ) {
        //     str += res[i] + " ";
        // }
        // str.pop_back();
        
        // return str;

        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }

    void reverse(string &s, int l, int r) {
        for (int i = l, j = r; i < j; i ++, j -- ) {
            swap(s[i], s[j]);
        }
    }
   
    void removeExtraSpaces(string &s) {
        int n = s.size();
        int slow = 0, fast = 0;
        while (n > 0 && fast < n && s[fast] == ' ') {
            fast ++;
        }
        for (; fast < n; fast ++ ) {
            if (fast - 1 > 0 && s[fast] == ' ' && s[fast - 1] == s[fast]) {
                continue;
            } else {
                s[slow++] = s[fast];
            }
        }
        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }
};