// 图论
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
vector<ll> mp[N];
ll n, m;
queue<ll> q;
bool vis[N];
void bfs()
{
    q.push(1);
    while (!q.empty())
    {
        ll node = q.front();
        vis[node] = 1;
        q.pop();
        cout << node << " ";
        for (auto &i : mp[node])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    cout << "\n";
    return;
}
void dfs(ll node)
{
    vis[node] = 1;
    cout << node << " ";
    for (auto &i : mp[node])
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll pre, past;
        cin >> pre >> past;
        mp[pre].push_back(past);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(mp[i].begin(), mp[i].end());
    }
    dfs(1);
    cout << "\n";
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    bfs();
    return 0;
}