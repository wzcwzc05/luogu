#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
const ll MOD = 1e6 + 7;
ll n, m, dp[N][N], a[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            ll t = min(j, a[i]);
            for (ll k = 0; k <= t; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
    cout << dp[n][m] % MOD << "\n";
    return 0;
}