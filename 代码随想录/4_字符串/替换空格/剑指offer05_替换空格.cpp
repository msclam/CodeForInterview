#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // string str = "";
        // for (int i = 0; i < s.size(); i ++ ) {
        //     if (s[i] == ' ') {
        //         str += "%20";
        //     } else {
        //         str += s[i];
        //     }
        // }
        // return str;

        int cnt = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; i ++ ) {
            if (s[i] == ' ') {
                cnt++;
            }
        }
        s.resize(oldSize + 2 * cnt);
        int newSize = s.size();
        for (int i = oldSize - 1, j = newSize - 1; i < j; i --, j -- ) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};