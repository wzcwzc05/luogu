#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll n, a[N], dp1[N], dp2[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) dp1[i] = dp2[i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[i] < a[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = n; j > i; --j) {
            if (a[i] < a[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    ll ans = 0, ansi = 0;
    for (int i = 1; i <= n; ++i) {
        ll tmp = dp1[i] + dp2[i] - 1;
        if (tmp >= 3) {
            ans = max(tmp, ans);
            // if (ans <= tmp) {
            //     ans = tmp;
            //     ansi = a[i];
            // }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ": " << a[i] << " " << dp1[i] << " " << dp2[i] << "\n";
    // }
    cout << ans << "\n";
    return 0;
}