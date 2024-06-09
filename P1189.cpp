#include <bits/stdc++.h>
using namespace std;
int n, m, mp[101][101], q, p[1010], vis[1010][101][101];
int startx, starty;
int d[10][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
string str;
void dfs(int dep, int x, int y) {
    if (vis[dep][x][y]) return;
    vis[dep][x][y] = 1;
    if (dep > q) {
        mp[x][y] = 2;
        // cout << dep << " " << x << " " << y << "\n";
        return;
    }
    int dx = d[p[dep]][0], dy = d[p[dep]][1];
    for (int i = x + dx, j = y + dy; i >= 1 && i <= n && j >= 1 && j <= m;
         i += dx, j += dy) {
        if (mp[i][j] == 1)
            break;
        else {
            dfs(dep + 1, i, j);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char t;
            cin >> t;
            if (t == '.') mp[i][j] = 0;
            if (t == 'X') mp[i][j] = 1;
            if (t == '*') startx = i, starty = j, mp[i][j] = 0;
        }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> str;
        if (str == "NORTH") p[i] = 0;
        if (str == "SOUTH") p[i] = 1;
        if (str == "EAST") p[i] = 2;
        if (str == "WEST") p[i] = 3;
    }
    dfs(1, startx, starty);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 0) cout << ".";
            if (mp[i][j] == 1) cout << "X";
            if (mp[i][j] == 2) cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
/*
4 5
..XX.
.X...
.X.*X
X.X..
3
NORTH
WEST
SOUTH
*/