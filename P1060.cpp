#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e4 + 10;
ll n, m, a[N], v[N], dp[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i] >> v[i], v[i] *= a[i];
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= a[i]; --j)
            dp[j] = max(dp[j], dp[j - a[i]] + v[i]);
    }
    ll ans = INT_MIN, ansn = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}