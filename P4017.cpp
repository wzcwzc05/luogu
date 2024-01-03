#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4;
vector<int> mp[N];
int n, m, in[N], out[N], starti, endi;
int dp[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        ++out[a], ++in[b];
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0 && out[i] != 0)
        {
            dp[i] = 1, q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i = mp[x].begin(); i != mp[x].end(); ++i)
        {
            --in[*i];
            dp[*i] = (dp[x] + dp[*i]) % 80112002;
            if (in[*i] == 0)
                q.push(*i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (out[i] == 0)
        {
            ans = (ans + dp[i]) % 80112002;
        }
    cout << ans << "\n";
    return 0;
}