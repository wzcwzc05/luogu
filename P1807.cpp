#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2000;
ll n, m, u, v, w;
vector<ll> g[N], d[N];
ll out_g[N], in_g[N], dp[N];
vector<ll> order;
queue<ll> q;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back(v);
        d[u].push_back(w);
        out_g[u]++, in_g[v]++;
    }
    for (int i = 2; i <= n; ++i) {
        if (in_g[i] == 0) {
            // cout << i << "\n";
            for (auto &j : g[i]) {
                in_g[j]--;
            }
        }
    }
    q.push(1);
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        order.push_back(node);
        for (auto &i : g[node]) {
            // cout << node << "->" << i << endl;
            in_g[i]--;
            if (in_g[i] == 0) {
                q.push(i);
            }
        }
    }
    for (auto &i : order) cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i) dp[i] = INT_MIN;
    dp[1] = 0;
    for (auto &node : order) {
        for (int i = 0; i < g[node].size(); ++i) {
            ll to = g[node][i], w = d[node][i];
            if (dp[to] < dp[node] + w) {
                dp[to] = dp[node] + w;
            }
        }
    }
    if (dp[n] == INT_MIN)
        cout << "-1\n";
    else
        cout << dp[n] << "\n";
    return 0;
}