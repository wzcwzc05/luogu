#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, q, a[N], k, maxx[N], minn[N];
priority_queue<int, vector<int>, greater<int>> stk_min;
priority_queue<int, vector<int>, less<int>> stk_max;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= k; ++i)
        stk_min.push(a[i]), stk_max.push(a[i]);
    maxx[1] = stk_max.top(), minn[1] = stk_min.top();
    for (int i = 2; i <= n - k + 1; ++i)
    {
        if (a[i - 1] == stk_min.top())
            cout << stk_min.top() << "min \n", stk_min.pop();
        if (a[i - 1] == stk_max.top())
            cout << stk_max.top() << "max \n", stk_max.pop();
        stk_min.push(a[k + i - 1]), stk_max.push(a[k + i - 1]);
        maxx[i] = stk_max.top(), minn[i] = stk_min.top();
    }
    for (int i = 1; i <= n - k + 1; ++i)
        cout << maxx[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n - k + 1; ++i)
        cout << minn[i] << " ";
    cout << "\n";
    return 0;
}