#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, q;
priority_queue<int> stk;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int q, t;
        cin >> q;
        if (q == 1)
        {
            cin >> t;
            ans += t;
            stk.push(t);
        }
        if (q == 2 && !stk.empty())
        {
            ans -= stk.top();
            stk.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}