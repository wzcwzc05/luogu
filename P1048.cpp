#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll t, m, v[N], a[N], dp[N][N];
int main()
{
    cin >> t >> m;
    for (ll i = 1; i <= m; i++)
        cin >> a[i] >> v[i];
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = t; j >= 0; j--)
        {
            if (j - a[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    ll ans = INT_MIN;
    for (ll i = 0; i <= t; i++)
        ans = max(ans, dp[m][i]);
    cout << ans << "\n";
    return 0;
}
