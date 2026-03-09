#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, startx, starty, endx, endy;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mp[N][N];
struct Node {
    int cnt, x, y;
};
bool check(int d, int x, int y) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    return nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != '#';
}
int bfs() {
    queue<Node> q;
    q.push({0, startx, starty});
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        if (x == endx && y == endy) return cnt;
        for (int d = 0; d < 4; ++d) {
            if (check(d, x, y)) {
                mp[x + dx[d]][y + dy[d]] = '#';
                q.push({cnt + 1, x + dx[d], y + dy[d]});
            }
        }
        q.pop();
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while (n != 0 && m != 0) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') startx = i, starty = j;
                if (mp[i][j] == '*') endx = i, endy = j;
            }
        cout << bfs() << "\n";
        cin >> n >> m;
    }
    return 0;
}