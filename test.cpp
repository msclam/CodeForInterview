#include <bits/stdc++.h>

using namespace std;

//插入排序：直接插入、折半插入、希尔排序
// 1 直接插入
void insertSort(vector<int> &A, int n) {
    for (int i = 0; i < n; i ++ ) {
        int tmp = A[i], j;
        for (j = i - 1; j >= 0 && tmp < A[j]; j -- ) {
            A[j + 1] = A[j];
        }
        A[j + 1] = tmp;
    }
}

// 2 折半插入
void halfInsertSort(vector<int> &A, int n) {
    
}

int main() {
    // vector<int> A = {-7, -5, -4, -1, -1, -1, 0, 0, 4, 7, 9 };
    vector<int> A = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1, 91, 0};
    int n = A.size();
    vector<int> tmp(n, 0);
    
    // bubbleSort(A, n);
    // quickSort(A, 0, n - 1);
    // quick_sort(A, 0, n - 1);
    // mergeSort(A, tmp, 0, n - 1);
    // heapSort(A, n);
    halfInsertSort(A, n);
    // insertSort(A, n);
    // shellSort(A, n);
    // selectSort(A, n);


    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}