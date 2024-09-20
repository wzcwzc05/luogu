#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll q, n, a[100005], s;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll t;
        do {
            t = 0;
            // cout << avg << "\n";
            for (int i = n; i >= 2; i--) {
                if (a[i] > a[i - 1]) {
                    t++;
                    ll half = (a[i] + a[i - 1]) / 2, sum = a[i] + a[i - 1];
                    a[i - 1] = sum - half, a[i] = half;
                }
            }
        } while (t != 0);
        ll ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = (ans * a[i]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}