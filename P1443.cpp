#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
ll n, m, a[N][N], startx, starty;
int dx[10] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[10] = {2, -2, 2, -2, 1, -1, 1, -1};
queue<pair<int, int>> q;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> startx >> starty;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = -1;
  a[startx][starty] = 0;
  q.push(make_pair(startx, starty));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int u = x + dx[i];
      int v = y + dy[i];
      if (u > 0 && u <= n && v > 0 && v <= m && a[u][v] == -1) {
        a[u][v] = a[x][y] + 1;
        q.push(make_pair(u, v));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}