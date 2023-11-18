// dfs模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3;
int mp[N][N], n, m, ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    mp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 0)
            dfs(nx, ny);
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == 0)
            {
                dfs(i, j);
                ans++;
            }
    cout << ans << "\n";
    return 0;
}