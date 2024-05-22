#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll n, h, ans, maxn, t, sum1, sum2;
ll a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> a[i], sum1 += a[i], sum2 += a[i] * i;
    ll x, y, z;
    if (sum1 == 0)
        x = y = z = n;
    else
        x = sum2 / sum1, y = sum2 / sum1 + 1, z = sum2 / sum1 - 1;
    ll ans = LLONG_MAX, temp = 0;
    if (x >= 1 && x <= n) {
        for (ll i = 1; i <= n; ++i) temp += (x - i) * (x - i) * a[i];
        ans = min(temp, ans), temp = 0;
    }
    if (y >= 1 && y <= n) {
        for (ll i = 1; i <= n; ++i) temp += (y - i) * (y - i) * a[i];
        ans = min(temp, ans), temp = 0;
    }
    if (z >= 1 && z <= n) {
        for (ll i = 1; i <= n; ++i) temp += (z - i) * (z - i) * a[i];
        ans = min(temp, ans), temp = 0;
    }
    cout << ans << "\n";
    return 0;
}