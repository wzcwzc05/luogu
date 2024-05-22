#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, d, u, v, ans;
vector<ll> mp[100010];
bitset<100010> vis;
struct Node {
    ll node, step;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v;
        mp[u].push_back(v), mp[v].push_back(u);
    }
    queue<Node> q;
    q.push({1, 0});
    while (!q.empty()) {
        Node t = q.front();
        q.pop(), ans++, vis[t.node] = 1;
        for (auto &i : mp[t.node])
            if (!vis[i] && t.step + 1 <= d) q.push({i, t.step + 1});
    }
    cout << ans - 1 << "\n";
    return 0;
}