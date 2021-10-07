#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string str) {
        // string str = "";
        // for (int i = 0; i < s.size(); i ++ ) {
        //     if (s[i] == ' ') {
        //         str += "%20";
        //     } else {
        //         str += s[i];
        //     }
        // }
        // return str;

        int n = str.size();
        int cnt = 0;
        for (int i = 0; i < n; i ++ ) {
            if (str[i] ==' ') cnt ++;
        }
        int len = n;
        len += cnt * 2;
        string s(len, ' ');
        for (int i = n - 1; i >= 0; i -- ) {
            if (str[i] != ' ') s[--len] = str[i];
            else {
                s[--len] = '0';
                s[--len] = '2';
                s[--len] = '%';
            }
        }
        return s;
        
    }
};