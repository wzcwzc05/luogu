#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
int n, m, v[N][N], q;
bool flag[N][N], mp[N][N];
int dfs(int dep, int x, int y)
{
    if (!flag[x][y])
    {
        flag[x][y] = true;
        int t = dep;
        if (x + 1 <= n && mp[x + 1][y] == !mp[x][y])
        {
            int temp = dfs(dep + 1, x + 1, y);
            t = max(t, temp);
        }
        if (x - 1 >= 1 && mp[x - 1][y] == !mp[x][y])
        {
            int temp = dfs(dep + 1, x - 1, y);
            t = max(t, temp);
        }
        if (y + 1 <= m && mp[x][y + 1] == !mp[x][y])
        {
            int temp = dfs(dep + 1, x, y + 1);
            t = max(t, temp);
        }
        if (y - 1 >= 1 && mp[x][y - 1] == !mp[x][y])
        {
            int temp = dfs(dep + 1, x, y - 1);
            t = max(t, temp);
        }
        // cout << x << " " << y << " " << t << "\n";
        v[x][y] = t;
        return t;
    }
    else
        return v[x][y];
}
int main()
{
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    m = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = ch - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!flag[i][j])
                v[i][j] = dfs(1, i, j);
        }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << v[x][y] << "\n";
    }
    return 0;
}