#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, m, l;
ll bright[N], x, b, prefix[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> b;
        bright[x] += b;
        l = max(l, x);
    }
    for (int i = 1; i <= l; ++i) prefix[i] = prefix[i - 1] + bright[i];
    ll ans = 0;
    for (int i = 1; i <= l - m; ++i)
        ans = max(ans, prefix[i + m - 1] - prefix[i - 1]);
    cout << ans << '\n';
    return 0;
}