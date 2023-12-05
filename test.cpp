#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e2 + 10;
int mp[N][N], n, m, k, ans;
bool vis[N][N];
bool check(int x, int y)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
        if (mp[i][y] == 1)
            return false;
    for (int i = 1; i <= m; i++)
        if (mp[x][i] == 1)
            return false;
    for (int i = x, j = y; i <= n && j <= m; i++, j++)
        if (mp[i][j] == 1)
            return false;
    for (int i = x, j = y; i >= 1 && j >= 1; i--, j--)
        if (mp[i][j] == 1)
            return false;
    for (int i = x, j = y; i <= n && j >= 1; i++, j--)
        if (mp[i][j] == 1)
            return false;
    for (int i = x, j = y; i >= 1 && j <= m; i--, j++)
        if (mp[i][j] == 1)
            return false;
    return true;
}
void print()
{
    for (int i = 1; i <= n; i++, cout << "\n")
        for (int j = 1; j <= m; j++)
            cout << mp[i][j] << " ";
    cout << "\n";
}
void dfs(int dep, int c)
{
    if (dep == k)
    {
        ans++;
        return;
    }
    if (c > n)
    {
        return;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (check(c, i))
        {
            mp[c][i] = 1;
            dfs(dep + 1, c + 1);
            mp[c][i] = 0;
        }
    }
    dfs(dep, c + 1);
}
int main()
{
    cin >> n >> m >> k;
    dfs(0, 1);
    cout << ans << "\n";
    return 0;
}