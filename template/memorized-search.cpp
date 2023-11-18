// 记忆化搜索
#include <bits/stdc++.h>
using namespace std;
int n, m;
int i, j;
int d[105][105], a[105][105];
int maxn;
int dfs(int dep, int x, int y)
{
    if (d[x][y] != 1)
        return d[x][y]; // 如果这个点已经搜索过了，那么直接返回
    int ans = 0;        // ans初始化一定要是0
    if (a[x + 1][y] < a[x][y])
        ans = max(ans, dfs(dep + 1, x + 1, y) + 1);
    if (a[x - 1][y] < a[x][y])
        ans = max(ans, dfs(dep + 1, x - 1, y) + 1);
    if (a[x][y + 1] < a[x][y])
        ans = max(ans, dfs(dep + 1, x, y + 1) + 1);
    if (a[x][y - 1] < a[x][y])
        ans = max(ans, dfs(dep + 1, x, y - 1) + 1);
    d[x][y] = max(d[x][y], ans);
    return d[x][y];
}
int main()
{
    scanf("%d %d", &n, &m);
    int k = 0, t;
    for (i = 0; i <= n + 2; i++)
        for (j = 0; j <= m + 2; j++)
        {
            a[i][j] = INT_MAX;
            d[i][j] = 1;
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> a[i][j];
    maxn = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            maxn = max(dfs(1, i, j), maxn);
    cout << maxn << endl;
    return 0;
}