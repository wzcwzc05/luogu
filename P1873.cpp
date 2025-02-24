#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
using ll = long long;
ll n, m, a[MAXN], pre[MAXN];
ll check(ll x) {
    ll pos = lower_bound(a + 1, a + n + 1, x) - a;
    return ((pre[n] - pre[pos - 1]) - (n - pos + 1) * x) >= m;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    ll l = 0, r = a[n], mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << "\n";
    return 0;
}