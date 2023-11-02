#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll n, m, ans, temp;
vector<ll> g[N];
bool vis[N];
void bfs(int startx)
{
    queue<ll> q;
    q.push(startx);
    while (!q.empty())
    {
        ll node = q.front();
        vis[node] = true;
        q.pop();
        for (auto &y : g[node])
            if (!vis[y])
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
    bfs(1);
    for (ll i = 1; i <= n; i++)
        if (vis[i])
            cout << i << " ";
    cout << "\n";
    return 0;
}