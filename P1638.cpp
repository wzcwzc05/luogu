#include <bits/stdc++.h>
#define int long long
using namespace std;
int hs[2010], a[1000010], n, m, ans, ansl, ansr, l, r, t;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    l = 1, r = 1, ans = INT_MAX, hs[a[1]] = 1, t = 1;
    while (l <= r && r <= n) {
        if (t < m) {
            hs[a[++r]] += 1;
            if (hs[a[r]] == 1) ++t;
        } else {
            // cout << "Find:" << r << " " << l << "\n";
            if (r - l + 1 < ans) ansl = l, ansr = r, ans = r - l + 1;
            hs[a[l++]] -= 1;
            if (hs[a[l - 1]] == 0) --t;
        }
    }
    cout << ansl << " " << ansr << "\n";
    return 0;
}