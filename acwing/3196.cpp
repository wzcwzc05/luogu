#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, startx, starty, endx, endy, s[N][N], t[N][N];
char mp[N][N];
bool visited[N][N], flag;
bool isMoveable(int d, int x, int y) {
    if (mp[x][y] == '-' && (d == 2 || d == 3)) return false;
    if (mp[x][y] == '|' && (d == 0 || d == 1)) return false;
    if (mp[x][y] == '.' && (d == 0 || d == 1 || d == 3)) return false;
    int nx = x + dx[d], ny = y + dy[d];
    if (nx < 1 || nx > n || ny < 1 || ny > m) return false;
    if (visited[nx][ny]) return false;
    if (mp[nx][ny] == '#') return false;
    return true;
}
bool isMoveableRes(int d, int x, int y) {
    int nx = x + dx[d], ny = y + dy[d];
    if (nx < 1 || nx > n || ny < 1 || ny > m) return false;
    if (mp[nx][ny] == '#') return false;
    if (visited[nx][ny]) return false;
    if ((d == 0 || d == 1) && mp[nx][ny] == '|') return false;
    if ((d == 2 || d == 3) && mp[nx][ny] == '-') return false;
    if ((d == 0 || d == 1 || d == 2) && mp[nx][ny] == '.') return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') startx = i, starty = j;
            if (mp[i][j] == 'T') endx = i, endy = j;
        }
    queue<pair<int, int>> q;
    q.push({startx, starty});
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;
        s[x][y] = 1;
        if (mp[x][y] == 'T') flag = 1;
        for (int i = 0; i < 4; ++i) {
            if (isMoveable(i, x, y))
                q.push({x + dx[i], y + dy[i]}),
                    visited[x + dx[i]][y + dy[i]] = 1;
        }
    }
    if (flag == 0) {
        cout << "I'm stuck!\n";
        return 0;
    }
    while (!q.empty()) q.pop();
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j) visited[i][j] = 0;

    q.push({endx, endy});
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;
        t[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            if (isMoveableRes(i, x, y))
                q.push({x + dx[i], y + dy[i]}),
                    visited[x + dx[i]][y + dy[i]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 1 && t[i][j] == 0) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}