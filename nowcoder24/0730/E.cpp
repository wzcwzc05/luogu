#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100005], b[100005];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        ll ans = 0, tr = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i] == b[i])
                tr++;
            else if (a[i] > b[i])
                ans++;
        cout << ans + (tr + 1) / 2 << '\n';
    }
    return 0;
}