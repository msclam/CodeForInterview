#include <bits/stdc++.h>

using namespace std;

class cmp {
public:
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
        return l.second < r.second;
    }
};

int main()
{
    // priority_queue<int, vector<int>, greater<int>> q;
    // priority_queue<int> q; // less 降序队列，大顶堆
    // for (int i = 0; i < 10; ++i)
    //     q.push(i);
    // while (!q.empty())
    // {
    //     cout << q.top() << endl;
    //     q.pop();
    // }

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> coll;
    pair<int,int> a(3,4);
    pair<int,int> b(3,5);
    pair<int,int> c(4,3);
    pair<int,int> d(2,6); 
    coll.push(c);
    coll.push(b);
    coll.push(a);
    coll.push(d);
    while(!coll.empty()) // 大顶堆，降序序列
    {
        cout<<coll.top().first<<"\t"<<coll.top().second<<endl;
        coll.pop();
    }

    return 0;
}

// //升序队列，小顶堆
// priority_queue <int,vector<int>,greater<int> > q;
// //降序队列，大顶堆
// priority_queue <int,vector<int>,less<int> >q;