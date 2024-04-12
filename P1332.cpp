#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct Node {
    int dep, x, y;
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, sp, ep;
int mp[505][505];
void bfs(int dep, int x, int y) {
    queue<Node> q;
    q.push({0, x, y});
    while (!q.empty()) {
        Node t = q.front();
        if (mp[t.x][t.y] > t.dep) {
            mp[t.x][t.y] = t.dep;
            for (int i = 0; i < 4; ++i) {
                int ex = t.x + dx[i];
                int ey = t.y + dy[i];
                if (ex <= n && ex >= 1 && ey <= m && ey >= 1)
                    q.push({t.dep + 1, ex, ey});
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> sp >> ep;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) mp[i][j] = INT_MAX;
    for (int i = 1; i <= sp; ++i) {
        int x, y;
        cin >> x >> y;
        bfs(0, x, y);
    }
    for (int i = 1; i <= ep; ++i) {
        int x, y;
        cin >> x >> y;
        cout << mp[x][y] << "\n";
    }
    return 0;
}