#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
struct pos {
    int n, m;
};
bool vis[N][N];
pos mp[N][N];
int endn, endm;
int n, m, v, ans;
void dfs(int sum_v, int x, int y) {
    vis[x][y] = 1;
    if (x == endn && y == endm) {
        ans = min(ans, sum_v);
        return;
    }
    if (!vis[mp[x][y].n][mp[x][y].m])
        dfs(sum_v + abs(x - mp[x][y].n) * v, mp[x][y].n, mp[x][y].m);
    vis[x][y] = 0;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> v >> endn >> endm;
    ans = 1e8 + 10;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> mp[i][j].n >> mp[i][j].m;
    for (int i = 1; i <= m; ++i) {
        dfs(0, 1, i);
        memset(vis, 0, sizeof(vis));
    }
    if (ans == 1e8 + 10)
        cout << "impossible\n";
    else
        cout << ans << "\n";
    return 0;
}