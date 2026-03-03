#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll n, m, startx, starty, endx, endy, ans[N][N];
map<char, int> p;
bool vis[N][N];
char mp[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct node {
    ll x, y;
    ll step = 0;
};
pair<ll, ll> find_w(ll x, ll y, char ch) {
    // cout << "@" << x << " " << y << " " << ch << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((i != x || j != y) && mp[i][j] == ch) return make_pair(i, j);
        }
    }
    return make_pair(x, y);
}
ll bfs(ll x, ll y) {
    ans[x][y] == 0;
    queue<node> q;
    q.push({x, y, 0});
    while (!q.empty()) {
        ll x = q.front().x, y = q.front().y, step = q.front().step;
        // cout << step << ' ' << x << ' ' << y << "\n";
        if (x == endx && y == endy) return step;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (mp[nx][ny] == '#') continue;
            if (mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z') {
                // cout << "!!!" << nx << ' ' << ny << "\n";
                auto tmp = find_w(nx, ny, mp[nx][ny]);
                nx = tmp.first, ny = tmp.second;
                // cout << mp[nx][ny] << " " << nx << " " << ny << "\n";
            }
            if (vis[nx][ny]) continue;
            q.push({nx, ny, step + 1});
            vis[nx][ny] = 1;
        }
    }
    return 114514;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == '=') endx = i, endy = j;
            if (mp[i][j] == '@') startx = i, starty = j;
            ans[i][j] = INT_MAX;
        }
    cout << bfs(startx, starty) << "\n";
    return 0;
}