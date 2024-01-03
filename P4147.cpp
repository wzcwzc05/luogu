#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
int n, m, flag[N][N], pre[N][N], suff[N][N];
char mp[N][N];
ll ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'R')
                flag[i][j] = 0;
            if (mp[i][j] == 'F')
                flag[i][j] = flag[i - 1][j] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        stack<int> stk;
        for (int j = 1; j <= m; j++)
        {
            while (!stk.empty() && flag[i][stk.top()] >= flag[i][j])
                stk.pop();
            if (stk.empty())
                pre[i][j] = 0;
            else
                pre[i][j] = stk.top();
            stk.push(j);
        }
        while (!stk.empty())
            stk.pop();
        for (int j = m; j >= 1; j--)
        {
            while (!stk.empty() && flag[i][stk.top()] >= flag[i][j])
                stk.pop();
            if (stk.empty())
                suff[i][j] = m + 1;
            else
                suff[i][j] = stk.top();
            stk.push(j);
        }
        for (int j = 1; j <= m; j++)
            ans = max(ans, ll(flag[i][j] * (suff[i][j] - pre[i][j] - 1)));
    }
    cout << 3 * ans << "\n";
    return 0;
}