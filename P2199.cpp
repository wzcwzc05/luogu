#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char mp[1800000], backup[1800000];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m, startx, starty, endx, endy;
void print();
int toint(int x, int y) { return (x - 1) * m + y; }
int pos_x(int pos) { return (pos - 1) / m + 1; }
int pos_y(int pos) { return (pos - 1) % m + 1; }
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[toint(x, y)] != 'X';
}
int bfs() {
    queue<pair<int, int>> q;
    if (mp[toint(startx, starty)] == '$') return 0;
    q.push({0, toint(startx, starty)});
    while (!q.empty()) {
        auto [step, pos] = q.front();
        if (mp[pos] == '$') return step;
        q.pop();
        int x = pos_x(pos), y = pos_y(pos);
        for (int d = 0; d < 4; ++d)
            if (check(x + dx[d], y + dy[d])) {
                q.push({step + 1, toint(x + dx[d], y + dy[d])});
                if (mp[toint(x + dx[d], y + dy[d])] == '$')
                    return step + 1;
                else
                    mp[toint(x + dx[d], y + dy[d])] = 'X';
            }
    }
    return -1;
}
void print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << mp[toint(i, j)] << " ";
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[toint(i, j)], backup[toint(i, j)] = mp[toint(i, j)];
    cin >> endx >> endy >> startx >> starty;
    while (startx != 0 && starty != 0) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) mp[toint(i, j)] = backup[toint(i, j)];
        for (int d = 0; d < 8; ++d) {
            int x = endx, y = endy;
            while (check(x + dx[d], y + dy[d])) {
                x += dx[d], y += dy[d];
                mp[toint(x, y)] = '$';
            }
        }
        // print();
        int tmp = bfs();
        if (tmp == -1)
            cout << "Poor Harry\n";
        else
            cout << tmp << "\n";
        cin >> endx >> endy >> startx >> starty;
    }
    return 0;
}