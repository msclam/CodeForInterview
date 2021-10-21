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
    for (int i = 0; i < n; i ++ ) {
        int tmp = A[i], j;
        int l = 0, r = i;
        while (l < r) {
            int mid = l + r >> 1;
            if (A[mid] <= tmp) l = mid + 1;
            else r = mid;
        }
        for (j = i - 1; j >= l; j -- ) {
            A[j + 1] = A[j];
        }
        A[j + 1] = tmp;
    }
}

// 3 希尔排序
void shellSort(vector<int> &A, int n) {
    for (int dk = n / 2; dk >= 1; dk /= 2 ) {
        for (int i = dk; i < n; i ++ ) {
            if (A[i - dk] > A[i]) {
                int tmp = A[i], j;
                for (int j = i - dk; j >= 0 && tmp < A[j]; j -= dk ) {
                    A[j + dk] = A[j]; 
                }
                A[j + dk] = tmp;
            }
        }
    }
} 

void shellSort(vector<int> &A, int n) {
    for (int dk = n / 2; dk >= 1; dk /= 2 ) {
        for (int i = dk; i < n; i ++ ) {
            if (A[i - dk] > A[i]) {
                int tmp = A[i], j;
                for (j = i - dk; j >= 0 && tmp < A[j]; j -= dk ) {
                    A[j + dk] = A[j];
                }
                A[j + dk] = tmp;
            }
        }
    }
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
    // halfInsertSort(A, n);
    // insertSort(A, n);
    shellSort(A, n);
    // selectSort(A, n);


    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}