#include <bits/stdc++.h>

using namespace std;

void removeExtraSpaces(string &s) { //去除多余的空格，前后不要，中间只有一个
    int n = s.size();
    int slow = 0, fast = 0;
    while (n > 0 && fast < n && s[fast] == ' ') {
        fast ++;
    }
    for (; fast < n; fast ++ ) {
        if (fast - 1 > 0 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
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

void reverse(string &s, int l, int r) {
    for (int i = l, j = r; i < j; i ++, j -- ) {
        swap(s[i], s[j]);
    }
}

int main() {

    string s = "  ac  sad sad  asdas  sd ";

    removeExtraSpaces(s);

    cout << s << "*";

    return 0;
}