#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int n;
string str = "yizhong";
bool flag[105][105];
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

void dfs(int x, int y, int t)
{
    if (a[x][y] != str[t])
        return;
    else
    {
        flag[x][y] = true;
        if (a[x + 1][y] == str[t + 1] && flag[x + 1][y] == false)
            dfs(x + 1, y, t + 1);
        if (a[x - 1][y] == str[t + 1] && flag[x - 1][y] == false)
            dfs(x - 1, y, t + 1);
        if (a[x][y + 1] == str[t + 1] && flag[x][y + 1] == false)
            dfs(x, y + 1, t + 1);
        if (a[x][y - 1] == str[t + 1] && flag[x][y - 1] == false)
            dfs(x, y - 1, t + 1);
        if (a[x + 1][y + 1] == str[t + 1] && flag[x + 1][y + 1] == false)
            dfs(x + 1, y + 1, t + 1);
        if (a[x - 1][y - 1] == str[t + 1] && flag[x - 1][y - 1] == false)
            dfs(x - 1, y - 1, t + 1);
        if (a[x + 1][y - 1] == str[t + 1] && flag[x + 1][y - 1] == false)
            dfs(x + 1, y - 1, t + 1);
        if (a[x - 1][y + 1] == str[t + 1] && flag[x - 1][y + 1] == false)
            dfs(x - 1, y + 1, t + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'y')
                dfs(i, j, 0);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (flag[i][j] == false)
                a[i][j] = '*';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}