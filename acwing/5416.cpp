#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e10 + 10;
ll q, n, k;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> k;
        ll ans = 1;
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ll count = 0, s = 1;
                while (n % i == 0) {
                    n /= i;
                    s *= i;
                    count++;
                }
                if (count >= k) {
                    ans *= s;
                }
            }
            if (n == 1) break;
        }
        if (n >= 1 && k <= 1)
            cout << n * ans << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}