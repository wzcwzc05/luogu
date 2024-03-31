#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
ll n, m, dp[N], v[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j) {
            dp[j] += dp[j - v[i]];
        }
    cout << dp[m] << "\n";
    return 0;
}