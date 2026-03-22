#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 20;
ll a[N];
ll n, d, ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (ll i = 0; i < n; i++) {
        ll t = upper_bound(a, a + n, a[i] + d) - a;
        ans += t - i - 1;
    }
    cout << ans;
    return 0;
}