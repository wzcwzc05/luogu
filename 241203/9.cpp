#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll prefix[1010][1010], n, m, a[1010][1010];
ll get(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] +
           prefix[x1 - 1][y1 - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + a[i][j] -
                           prefix[i - 1][j - 1];
    ll ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) cout << prefix[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << get(n, 1, n, m) << "\n";
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= m; y1++)
            for (int x2 = x1; x2 <= n; x2++)
                for (int y2 = y1; y2 <= m; y2++) {
                    ll cnt = get(x1, y1, x2, y1) + get(x1, y1, x1, y2) +
                             get(x1, y2, x2, y2) + get(x2, y1, x2, y2) -
                             a[x1][y1] - a[x1][y2] - a[x2][y1] - a[x2][y2];
                    ans = max(cnt, ans);
                }
    cout << ans << "\n";
    return 0;
}