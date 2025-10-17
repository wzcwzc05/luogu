#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 1e9 + 7;
ll n, l, sum;
void solve() {
    cin >> n >> l;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    cout << (l / 2 * (l - l / 2)) % MOD *
                ((1ll << ((ll)log2(n) + 1)) % MOD - 1) % MOD
         << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
