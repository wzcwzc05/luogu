#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll n, m, ans, temp;
vector<ll> g[N];
void dfs(int x)
{
    cout << x << " ";
    for (auto &y : g[x])
    {
        dfs(y);
    }
    return;
}
void bfs(int startx)
{
    queue<ll> q;
    q.push(startx);
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        cout << node << " ";
        for (auto &y : g[node])
            q.push(y);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll startx, endx;
        cin >> startx >> endx;
        g[startx].push_back(endx);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    dfs(1);
    cout << "\n";
    bfs(1);
    cout << "\n";
    return 0;
}