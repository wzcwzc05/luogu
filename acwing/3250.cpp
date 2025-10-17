#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> mp[N], mp_r[N];
bitset<N> all(0), visited(0);
int n, m, u, v;
void bfs(int start_node, vector<int> mp[]) {
    queue<int> q;
    bitset<N> visited(0);
    q.push(start_node), visited[start_node] = 1;
    while (!q.empty()) {
        int cur = q.front();
        all[cur] = 1;
        q.pop();
        for (auto& node : mp[cur]) {
            if (visited[node] == 0) q.push(node), visited[node] = 1;
        }
    }
}
void dfs(int cur, vector<int> mp[]) {
    all[cur] = 1;
    for (auto& node : mp[cur]) {
        if (!visited[node]) {
            visited[node] = 1;
            dfs(node, mp);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        mp[u].push_back(v);
        mp_r[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        all.reset();
        // bfs(i, mp);
        // bfs(i, mp_r);
        visited.reset();
        dfs(i, mp);
        visited.reset();
        dfs(i, mp_r);
        bool flag = 0;
        for (int i = 1; i <= n; ++i)
            if (all[i] == 0) {
                flag = 1;
                break;
            }
        if (flag == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
