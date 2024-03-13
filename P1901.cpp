#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Node {
    int h, v;
} a[N];
int left_p[N], right_p[N];
int n, ans[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].h >> a[i].v;
    stack<int> stk_l, stk_r;
    stk_l.push(1);
    for (int i = 2; i <= n; ++i) {
        while (!stk_l.empty() && a[stk_l.top()].h < a[i].h)
            stk_l.pop();
        if (!stk_l.empty())
            left_p[i] = stk_l.top();
        stk_l.push(i);
    }
    stk_r.push(n);
    for (int i = n - 1; i >= 1; --i) {
        while (!stk_r.empty() && a[stk_r.top()].h < a[i].h)
            stk_r.pop();
        if (!stk_r.empty())
            right_p[i] = stk_r.top();
        stk_r.push(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (left_p[i] != 0)
            ans[left_p[i]] += a[i].v;
        if (right_p[i] != 0)
            ans[right_p[i]] += a[i].v;
    }
    int res = INT_MIN;
    for (int i = 1; i <= n; i++)
        res = max(ans[i], res);
    cout << res << "\n";
    return 0;
}