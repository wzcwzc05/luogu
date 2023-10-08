#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 3;
ll n, m, ans;
char a[N][N];
int dx[10] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[10] = {1, 0, -1, -1, 1, 0, -1, 1};
void dfs(int x, int y)
{
    a[x][y] = '.';
    for (int i = 0; i <= 7; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u <= 0 || u > n)
            continue;
        if (v <= 0 || v > m)
            continue;
        if (a[u][v] == 'W')
        {
            a[x][y] = '.';
            dfs(u, v);
        }
    }
}
void printN();
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'W')
            {

                ans++;
                dfs(i, j);
               // printN();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
void printN()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << "\n";
    }
    cout << "\n"
         << "\n";
    return;
}