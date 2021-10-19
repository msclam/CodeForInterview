#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    queue<char> q;
    unordered_map<char, int> mp; 
    void Insert(char ch) {
//          if (mp[ch] == 0) {
        if (mp.find(ch) == mp.end()) {
             q.push(ch);
         }
        mp[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!q.empty()) {
            char c = q.front();
            if (mp[c] == 1) {
                return c;
            } else {
                q.pop();
            }
        }
        return '#';
    }

};