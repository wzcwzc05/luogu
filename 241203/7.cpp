#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10010;
const ll MAXN = 1000010;
ll n, t;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = MAXN;
    for (ll i = 1; i <= n; ++i) {
        cin >> t;
        if (t % 2 == 0) ans = min(ans, t);
    }
    cout << ans << "\n";
    return 0;
}