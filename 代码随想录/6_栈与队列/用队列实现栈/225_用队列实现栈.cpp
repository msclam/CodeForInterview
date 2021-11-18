#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        size--;
        while (size-- > 0) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */