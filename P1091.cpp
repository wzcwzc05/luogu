#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, h[N], dp[N], len, ans, r1[N], r2[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    dp[0] = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > dp[len]) {
            dp[++len] = h[i];
        } else {
            *lower_bound(dp + 1, dp + len + 1, h[i]) = h[i];
        }
        r1[i] = len;
    }
    len = 0, dp[0] = 0;
    for (int i = n; i >= 1; i--) {
        if (h[i] > dp[len]) {
            dp[++len] = h[i];
        } else {
            *lower_bound(dp + 1, dp + len + 1, h[i]) = h[i];
        }
        r2[i] = len;
    }
    ans = n;
    for (int i = 1; i <= n; ++i) ans = min(ans, n - r1[i] - r2[i] + 1);
    cout << ans << "\n";
    return 0;
}