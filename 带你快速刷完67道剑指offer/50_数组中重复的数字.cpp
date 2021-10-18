#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int A[], int n, int* duplication) {
//         vector<bool> res(n, false);
//         for (int i = 0; i < n; i ++ ) {
//             if (res[A[i]] == false) {
//                 res[A[i]] = true;
//             } else {
//                 duplication[0] = A[i];
//                 return true;
//             }
//         }
//         return false;
        
        for (int i = 0; i < n; i ++ ) {
            int idx = A[i] % n;
            if (A[idx] >= n) {
                duplication[0] = idx;
                return true;
            }
            A[idx] += n;
        }
        return false;
    }
};