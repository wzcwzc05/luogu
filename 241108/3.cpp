#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a[100005], total, res, b[100005];
bool check(ll t) {
    ll tmp = 0, x = t;
    for (int i = 1; i <= n; ++i) {
        ll re = a[i] - t;
        if (re <= 0)
            continue;
        else {
            if (i + 1 <= n) {
                ll xx = min(x, min(re, a[i + 1] - t >= 0 ? a[i + 1] - t : 0));
                if (xx <= 0) xx = 0;
                re -= xx, x -= xx, a[i + 1] -= xx;
            } else {
                ll xx = min(x, re);
                re -= xx, x -= xx;
            }
            // if (x >= re) {
            //     x -= re;
            //     a[i + 1] -= re;
            //     re = 0;
            // } else {
            //     a[i + 1] -= x;
            //     re -= x;
            //     x = 0;
            // }
        }
        if (re > 0) tmp += re;
    }
    return tmp - x <= t;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll l = 1, r = 0, mid = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], r = max(a[i], r), b[i] = a[i];
    while (l <= r) {
        // cout << "l,r" << l << " " << r << "\n";
        mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        for (int i = 1; i <= n; ++i) a[i] = b[i];
    }
    // cout << check(2) << "\n";
    cout << res << "\n";
    return 0;
}