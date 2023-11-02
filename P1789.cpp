#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll n, p, q;
bool mp[N][N];
int main()
{
    cin >> n >> p >> q;
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x + 1][y + 1] = 1;
        mp[x - 1][y + 1] = 1;
        mp[x + 1][y - 1] = 1;
        mp[x - 1][y - 1] = 1;
        for (int j = x - 2; j <= x + 2; j++)
            if (j >= 0)
                mp[j][y] = 1;
        for (int j = y - 2; j <= y + 2; j++)
            if (j >= 0)
                mp[x][j] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x - 2; j <= x + 2; j++)
            for (int k = y - 2; k <= y + 2; k++)
                mp[j][k] = 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j] == 0)
                ans++;
    cout << ans << "\n";
    return 0;
}