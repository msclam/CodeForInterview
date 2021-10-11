#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<int> data;
    stack<int> minData;
    void push(int value) {
        data.push(value);
        if (minData.empty() || value < minData.top()) {
            minData.push(value);
        } else {
            minData.push(minData.top());
        }
    }
    void pop() {
        data.pop();
        minData.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minData.top();
    }
};