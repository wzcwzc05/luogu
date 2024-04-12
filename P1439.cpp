#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, a[N], dp[N], t, b[N], len;
map<int, int> mp;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        b[i] = mp[t];
    }
    dp[0] = 0, len = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[len] < b[i]) {
            dp[++len] = b[i];
        } else {
            *lower_bound(dp + 1, dp + len + 1, b[i]) = b[i];
        }
    }
    cout << len << "\n";
    return 0;
}