#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &A, int n) {
    for (int i = 0; i < n - 1; i ++ ) {
        for (int j = 0; j < n - i - 1; j ++ ) {
            if (A[j + 1] < A[j]) {
                swap(A[j + 1], A[j]);
            }
        }
    }
}

void quickSort(vector<int> &A, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = A[l + r >> 1];
    while (i < j) {
        while (A[i] < x) i++;
        while (A[j] > x) j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    } 
    if (l < j) quickSort(A, l, j);
    if (i < r) quickSort(A, i, r);
}

int partition(vector<int> &A, int l, int r) {
    int x = A[l];
    while (l < r) {
        while (l < r && A[r] > x) r--;
        A[l] = A[r];
        while (l < r && A[l] <= x) l++;
        A[r] = A[l]; 
    }
    A[l] = x;
    return l;
}

void quick_sort(vector<int> &A, int l, int r) {
    if (l < r) {
        int pos = partition(A, l, r);
        quick_sort(A, l, pos - 1);
        quick_sort(A, pos + 1, r);
    }
}

void merge(vector<int> &A, vector<int> &tmp, int l1, int r1, int l2, int r2) {
    int idx = l1;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
        if (A[i] <= A[j]) {
            tmp[idx++] = A[i++];
        } else {
            tmp[idx++] = A[j++];
        }
    }
    while (i <= r1) tmp[idx++] = A[i++];
    while (j <= r2) tmp[idx++] = A[j++];
    copy(tmp.begin() + l1, tmp.begin() + r2 + 1, A.begin() + l1);
}

void mergeSort(vector<int> &A, vector<int> &tmp, int l, int r) {
    if (l < r) {
        int mid = l + r >> 1;
        mergeSort(A, tmp, l, mid);
        mergeSort(A, tmp, mid + 1, r);
        merge(A, tmp, l, mid, mid + 1, r);
    }
}

void adjustDown(vector<int> &A, int low, int high) {
    int i = low, j = 2 * i + 1;
    while (j <= high) {
        if (j + 1 <= high && A[j + 1] > A[j]) {
            j++;
        }
        if (A[j] > A[i]) {
            swap(A[j], A[i]);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
}

void heapSort(vector<int> &A, int n) {
    for (int i = n / 2 - 1; i >= 0; i -- ) {
        adjustDown(A, i, n - 1);
    }
    for (int i = n - 1; i > 0; i -- ) {
        swap(A[i], A[0]);
        adjustDown(A, 0, i - 1);
    }
}

void selectSort(vector<int> &A, int n) {
    for (int i = 0; i < n - 1; i ++ ) {
        int min = i;
        for (int j = i + 1; j < n; j ++ ) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[min], A[i]);
        }
    }
}

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

void insertSort(vector<int> &A, int n) {
    for (int i = 0; i < n; i ++ ) {
        int tmp = A[i], j;
        for (j = i - 1; j >= 0 && tmp < A[j]; j -- ) {
            A[j + 1] = A[j];
        }
        A[j + 1] = tmp;
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