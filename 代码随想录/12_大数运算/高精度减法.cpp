#include <bits/stdc++.h>

using namespace std;

// A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i -- ) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++ ) {  // A - t - B   >= 0 => A-t-B or < 0 A-t-B + 10
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    
    while(C.size() > 1 && C.back() == 0) C.pop_back(); //去除前导0
    
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    // A >= B
    if (cmp(A, B)) {
        auto C = sub(A, B);

        for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    } else {
        auto C = sub(B, A);

        cout << "-";
        for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    }

    return 0;
}