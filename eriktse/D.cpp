#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
long long n, a[N][N], q, m, prefix[N][N], d[N][N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            d[i][j] += a[i][j];
            d[i + 1][j] -= a[i][j];
            d[i][j + 1] -= a[i][j];
            d[i + 1][j + 1] += a[i][j];
        }
    for (int i = 1; i <= q; i++)
    {
        long long x1, x2, y1, y2, v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        d[x1][y1] += v;
        d[x1][y2 + 1] -= v;
        d[x2 + 1][y1] -= v;
        d[x2 + 1][y2 + 1] += v;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}