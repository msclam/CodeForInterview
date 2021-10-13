#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<bool> st;
    vector<string> permutation(string s) {
        int n = s.size();
        if (n == 0) return vector<string>();
        st.resize(n, false);
        string tmp = "";

        sort(s.begin(), s.end());
        
        // dfs(s, n, tmp, 0);
        dfs(s, n, 0);
        // fun(s);

        return res;
    }

    void fun(string &s) {
        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
    }

    void dfs(string &s, int n, int u) {
        if (u == n) {
            res.push_back(s);
            return;
        }
        set<char> set;
        for (int i = u; i < n; i ++ ) {
            if (set.find(s[i]) == set.end()) {
                set.insert(s[i]);
                swap(s[i], s[u]);
                dfs(s, n, u + 1);
                swap(s[i], s[u]);
            }
        }
    }

    void dfs(string &s, int n, string &tmp, int u) {
        if (u == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i ++ ) {
            if (!st[i] && !(i > 0 && s[i - 1] == s[i] && st[i - 1])) {
                st[i] = true;
                tmp.push_back(s[i]);
                dfs(s, n, tmp, u + 1);
                tmp.pop_back();
                st[i] = false;
            }
        }
    }
};

int main() {
    vector<int> res = {5, 6, 7};

    sort(res.begin(), res.end());
    
    do { 
        for (int i = 0; i < res.size(); i ++ ) {
            cout << res[i] << " ";
        }
        cout << endl;
    } while (next_permutation(res.begin(), res.end()));
    
    return 0;
}