#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e2 + 10;
pair<int, int> d_time[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, t;
bool visited[N][N];
struct state {
    int x = 0, y = 0, time = 0;
};
bool isMoveable(int d, int x, int y, int t) {
    int next_x = x + dx[d];
    int next_y = y + dy[d];
    int next_t = t + 1;
    if (visited[next_x][next_y]) return false;
    if (next_x <= 0 || next_x > n || next_y > m || next_y <= 0) return false;
    if (next_t >= d_time[next_x][next_y].first &&
        next_t <= d_time[next_x][next_y].second)
        return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= t; ++i) {
        int x, y, st, et;
        cin >> x >> y >> st >> et;
        d_time[x][y].first = st, d_time[x][y].second = et;
    }
    queue<state> q;
    q.push({1, 1, 0});
    while (!q.empty()) {
        state now = q.front();
        q.pop();
        int nt = now.time, nx = now.x, ny = now.y;
        // cout << nt << " " << nx << " " << ny << "\n";
        if (nx == n && ny == m) {
            cout << nt << "\n";
            return 0;
        }
        visited[nx][ny] = 0;
        for (int i = 0; i < 4; ++i) {
            if (isMoveable(i, nx, ny, nt)) {
                q.push({nx + dx[i], ny + dy[i], nt + 1});
                visited[nx + dx[i]][ny + dy[i]] = 1;
            }
        }
    }
    return 0;
}