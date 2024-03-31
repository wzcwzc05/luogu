#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
ll v[N], w[N], n, m, dp[10000001];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= m; ++j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << "\n";
    return 0;
}