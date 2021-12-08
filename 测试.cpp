#include <bits/stdc++.h>

using namespace std;

//根据second的值升序排序
// bool cmp2(pair<int, int>a, pair<int, int>b)
//{
//    return a.second < b.second;
//}

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1000010;
int n;
int a[N], b[N];
PII person[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            person[i] = {a[i], i};
        }
        sort(person, person + n);
        for (int i = 0; i < n; i++)
        {
            int left = (person[i].second - 1 + n) % n, right = (person[i].second + 1) % n; //围成一个圈的处理方式
            int lv = 1, rv = 1;
            if (person[i].first > a[left])
                lv = b[left] + 1;
            if (person[i].first > a[right])
                rv = b[right] + 1;
            b[person[i].second] = max(lv, rv);
        }
        LL res = 0;
        for (int i = 0; i < n; i++)
            res += b[i];
        cout << res << endl;
    }

    return 0;
}