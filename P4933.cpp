#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e4 + 10;
ll n, m, h[1010], dp[1010][N], maxh, ans;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll p = 20000;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) {
        ans += 1;
        for (int j = i - 1; j >= 1; --j) {
            dp[i][h[i] - h[j] + p] += dp[j][h[i] - h[j] + p] + 1,
                dp[i][h[i] - h[j] + p] %= 998244353,
                ans = (ans + dp[j][h[i] - h[j] + p] + 1) % 998244353;
        }
    } 
    cout << ans << "\n";
    return 0;
}