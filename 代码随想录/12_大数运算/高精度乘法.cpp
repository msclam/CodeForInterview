#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ ) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> multi(string &a, string &b) {
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    
    for (int i = n - 1; i >= 0; i -- ) {
        for (int j = m - 1; j >= 0; j -- ) {
            int sum = (a[i] - '0') * (b[j] - '0') + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    } 
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
    // string a;
    // int b;
    // vector<int> A;
    
    // cin >> a >> b;
    // for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    
    // auto C = mul(A, b);
    
    // for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    
    string a, b;
    cin >> a >> b;
    
    auto C = multi(a, b);
    
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    
    return 0;
}

// vector<int> mul(string a, string b) {
//     int n1 = a.size();
//     int n2 = b.size();

//     vector<int> res(n1 + n2);

//     for (int i = 0; i < n1; i ++ ) {
//         for (int j = 0; j < n2; j ++ ) {
//             res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
//         }
//     }

//     for (int i = n1 + n2 - 1; i >= 1; i -- ) {
//         if (res[i] >= 10) {
//             res[i - 1] += res[i] / 10;
//             res[i] %= 10;
//         }
//     }

//     int i = 0;
//     while (res[i] == 0) i ++;
    
//     vector<int> C;
//     if (a == "0" || b == "0") {
//         C.push_back(0);
//     }
    
//     for (; i <= n1 + n2 - 1; i ++ ) {
//         C.push_back(res[i]);
//     }
//     return C;
// }