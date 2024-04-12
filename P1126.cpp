#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
int d[4] = {0, 1, 2, 3};
int dm[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct Node {
    int dct, x, y, t;
};
char ch;
int mp[N][N], n, m, startx, starty, endx, endy;
int ans[N][N];
int vis[50][50][50];
bool check(int x, int y, int dct) {
    if (x >= 1 && y >= 1 && x <= n && y <= m)
        if (vis[x][y][dct] == 0)
            return true;
        else
            return false;
    else
        return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> mp[i][j], ans[i][j] = INT_MAX;
    cin >> startx >> starty >> endx >> endy;
    cin >> ch;
    Node st;
    st.x = startx, st.y = starty, st.t = 0;
    if (ch == 'S') st.dct = 3;
    if (ch == 'N') st.dct = 1;
    if (ch == 'E') st.dct = 0;
    if (ch == 'W') st.dct = 2;
    queue<Node> q;
    q.push(st);
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        cout << temp.x << " " << temp.y << " " << temp.dct << "\n";
        if (ans[temp.x][temp.y] > temp.t) ans[temp.x][temp.y] = temp.t;
        vis[temp.x][temp.y][temp.dct] = 1;
        int base = 0;
        for (int i = 0; i <= 3; ++i) {
            if (abs(d[i] - temp.dct) % 2 == 1)
                base = 1;
            else if (d[i] == temp.dct)
                base = 0;
            else
                base = 2;
            for (int j = 1; j <= 3; ++j) {
                int dx = temp.x + dm[i][0] * j;
                int dy = temp.y + dm[i][1] * j;
                // cout << dx << " " << dy << "\n";
                if (check(dx, dy, i)) {
                    Node t;
                    t.x = dx, t.y = dy, t.t = temp.t + 1 + base, t.dct = i;
                    q.push(t);
                }
            }
        }
    }
    cout << ans[endx][endy] << "\n";
    return 0;
}