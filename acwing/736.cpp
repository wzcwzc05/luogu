#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, m, l, r, diff[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        diff[l] += 1, diff[r + 1] -= 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += diff[i];
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}