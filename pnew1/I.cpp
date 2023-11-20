#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3;
int n, m, a[N][N], k, x, y, ans;
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
struct data
{
    int dep;
    int x;
    int y;
};
queue<struct data> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        struct data temp;
        temp.dep = 0, temp.x = x, temp.y = y;
        a[x][y] = 1;
        q.push(temp);
    }
    while (!q.empty())
    {
        struct data temp = q.front();
        q.pop();
        ans = temp.dep;
        int x = temp.x;
        int y = temp.y;
        // cout << x << " " << y << "\n";
        a[x][y] = 1;
        struct data t;
        for (int i = 0; i <= 3; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx <= n - 1 && tx >= 0 && ty <= m - 1 && ty >= 0)
                if (a[tx][ty] == 0)
                {
                    // cout << "XXX" << ans + 1 << "\n";
                    t.dep = ans + 1;
                    t.x = tx;
                    t.y = ty;
                    a[tx][ty] = 1;
                    q.push(t);
                }
        }
    }
    cout << ans << "\n";
    return 0;
}