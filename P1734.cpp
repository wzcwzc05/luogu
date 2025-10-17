#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll sum_(ll x) {
    ll i, res = 1;
    for (i = 2; i * i <= x; ++i) {
        if (x % i == 0) {res += (i + x / i);
        cout<<i<<"\n";}
    }
    i -= 1;
    if (i * i == x) res -= i;
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = 0;
    // cout<<sum_(6)<<"\n";
    // for (int i = 1; i < n; ++i) {
    //     for (int j = 1; j <= n - i; ++j) {
    //         ans = max(ans, sum_(i) + sum_(j));
    //     }
    // }
    cout << ans << "\n";
    return 0;
}