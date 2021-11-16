#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        int cnt = 0;
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