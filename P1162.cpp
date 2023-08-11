#include <bits/stdc++.h>
using namespace std;
int a[100][100], n, m;
long long sum;
void dfs(int x, int y, int t)
{
    if (a[x][y] != 0)
        return;
    else
    {
        a[x][y] = t;
        if (a[x + 1][y] == 0)
            dfs(x + 1, y, t);
        if (a[x - 1][y] == 0)
            dfs(x - 1, y, t);
        if (a[x][y + 1] == 0)
            dfs(x, y + 1, t);
        if (a[x][y - 1] == 0)
            dfs(x, y - 1, t);
    }
}
int main()
{
    cin >> n;
    memset(a, 1, sizeof(a));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        dfs(1, i, 3);
        dfs(n, i, 3);
        dfs(i, 1, 3);
        dfs(i, n, 3);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
                a[i][j] = 2;
            if (a[i][j] == 3)
                a[i][j] = 0;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}