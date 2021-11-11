#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        size = 0;
        head = new LinkedNode(0);
    }
    
    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }
        LinkedNode* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = head->next;
        head->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = head;
        while (index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkedNode* cur = head;
        while (index--) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }

    void printLinkedList() {
        LinkedNode* cur = head;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int size;
    LinkedNode* head;
};