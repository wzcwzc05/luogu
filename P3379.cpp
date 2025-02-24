#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int LOG = 20;  // 优化步长到20，足够覆盖5e5的节点

ll n, m, s, x, y;
vector<ll> G[N];
bool visited[N];
ll father[N][LOG], depth[N];

void dfs(ll pos, ll f) {
    depth[pos] = depth[f] + 1;
    visited[pos] = 1;
    father[pos][0] = f;
    for (int i = 1; i < LOG; ++i) {
        father[pos][i] = father[father[pos][i - 1]][i - 1];
    }
    for (auto &i : G[pos]) {
        if (!visited[i]) dfs(i, pos);
    }
}

ll lca(ll a, ll b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = father[a][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (father[a][i] != father[b][i]) {
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> x >> y;
        G[y].push_back(x);
        G[x].push_back(y);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}