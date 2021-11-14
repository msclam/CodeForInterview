#include <bits/stdc++.h>

using namespace std;

vector<string> fun(string &s) {
    s += " ";
    string tmp = "";
    vector<string> res;
    for (char c : s) {
        if (c == ' ') {
            if (!tmp.empty()) {
                res.push_back(tmp);
                tmp = "";
            }
        } else {
            tmp += c;
        }
    }
    return res;
}

int main() {
    string s = " abc def hgjk asd. ";
    vector<string> res = fun(s);
    for (string tmp : res) {
        cout << tmp << endl;
    }
    return 0;
}