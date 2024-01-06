#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e2;
int mp[N][N], n, m, value[N][N];
void dfs(int w, int x, int y)
{
    if (w >= value[x][y])
    {
        value[x][y] = w;
        if (x + 1 <= n)
            dfs(w + mp[x][y], x + 1, y);
        if (y + 1 <= m)
            dfs(w + mp[x][y], x, y + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    dfs(0, 1, 1);
    cout << value[n][m] << "\n";
    return 0;
}