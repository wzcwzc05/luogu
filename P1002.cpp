#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll n, m, a[N][N], x, y;
ll dx[10] = {1, 1, -1, -1, 2, 2, -2, -2};
ll dy[10] = {2, -2, 2, -2, 1, -1, 1, -1};
int main()
{
    cin >> n >> m >> x >> y;
    memset(a, -1, sizeof(a));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
            a[i][j] = 0;
    }
    a[x][y] = -1;
    for (ll i = 0; i < 8; i++)
    {
        if (x + dx[i] >= 0 && y + dy[i] >= 0)
            a[x + dx[i]][y + dy[i]] = -1;
    }
    a[0][0] = 1;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (a[i][j] == -1)
                continue;
            if (i != 0 && j != 0)
                a[i][j] = 0;
            if (a[i - 1][j] != -1)
                a[i][j] += a[i - 1][j];
            if (a[i][j - 1] != -1)
                a[i][j] += a[i][j - 1];
        }
    }
    cout << a[n][m] << "\n";
    return 0;
}