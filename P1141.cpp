#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool mp[1010][1010], vis[1010][1010];
int ans[1010][1010];
int n, m;
int dfs(int dep, int x, int y) {
    vis[x][y] = 1;
    ans[x][y] = dep;
    for (int i = 0; i < 4; ++i) {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (mp[dx][dy] == !mp[x][y] && !vis[dx][dy] && dx <= n && dy <= n &&
            dx >= 1 && dy >= 1)
            ans[x][y] = dfs(ans[x][y] + 1, dx, dy);
    }
    return ans[x][y];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    char t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> t, mp[i][j] = t - '0';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!vis[i][j]) ans[i][j] = dfs(1, i, j);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << "\n";
    }
    return 0;
}