#include <bits/stdc++.h>
using namespace std;
int a[505][505], n, m, q;
char mp[505][505];
int check(int x, int y)
{
    int ans = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (a[i][j] == -1)
                ans++;
        }
    }
    return ans;
}
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x+1][y+1] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == -1)
            {
                mp[i][j] = 'x';
                continue;
            }
            a[i][j] = check(i, j);
            mp[i][j] = a[i][j] + '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mp[i][j];
        cout << "\n";
    }
    return 0;
}