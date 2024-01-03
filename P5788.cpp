#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e6 + 10;
int n, a[N], ans[N];
int main()
{
    cin >> n;
    stack<int> stk;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && a[i] >= a[stk.top()])
            stk.pop();
        if (stk.empty())
            ans[i] = 0;
        else
            ans[i] = stk.top();
        stk.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}