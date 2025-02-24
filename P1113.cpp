#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, tmp, x;
ll time_;
ll dp[10010];  // 最迟时间
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp >> time_ >> x;
        ll now = 0;
        while (x != 0) {
            now = max(now, dp[x]);
            cin >> x;
        }
        dp[i] = time_ + now;
    }
    cout << dp[n] << "\n";
    return 0;
}