#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int MAX_LOG = 20;
int n, m, x, y, z, ans;
vector<int> G[N];
int depth[N], visited[N], father[N][MAX_LOG + 1];
void dfs(int pos, int fa) {
    depth[pos] = depth[fa] + 1;
    father[pos][0] = fa;
    visited[pos] = 1;
    for (int i = 1; i <= MAX_LOG; ++i)
        father[pos][i] = father[father[pos][i - 1]][i - 1];
    for (auto &i : G[pos]) {
        if (!visited[i]) dfs(i, pos);
    }
    return;
}
int lca(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);
    if (depth[a] != depth[b]) {
        for (int i = MAX_LOG; i >= 0; --i) {
            if (depth[a] - (1 << i) >= depth[b]) a = father[a][i];
        }
    }
    if (a == b) return a;
    for (int i = MAX_LOG; i >= 0; --i) {
        if (father[a][i] != father[b][i]) a = father[a][i], b = father[b][i];
    }
    if (a == b) return a;
    return father[a][0];
}
int cal_score(int a, int b, int c) {
    int sum = 0;
    int tmp1 = lca(a, b);
    sum += (depth[a] - depth[tmp1]) + (depth[b] - depth[tmp1]);
    int tmp2 = lca(tmp1, c);
    sum += (depth[tmp1] - depth[tmp2]) + (depth[c] - depth[tmp2]);
    ans = tmp2;
    return sum;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        cout << ans << " " << sum << "\n";
    }
    return 0;
}