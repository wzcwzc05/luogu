#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> mp[N];
int n, m, ans;
int vis[N];
void dfs(int node, int start)
{
    // cout << node << " " << start << "\n";
    if (vis[node] > start)
        return;
    for (auto &i : mp[node])
    {
        if (vis[i] < start)
        {
            vis[i] = start;
            dfs(i, start);
        }
    }
}
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int pre, past;
        cin >> pre >> past;
        mp[past].push_back(pre);
    }
    for (int i = n; i >= 1; i--)
    {
        vis[i] = max(vis[i], i);
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << "\n";
    return 0;
}