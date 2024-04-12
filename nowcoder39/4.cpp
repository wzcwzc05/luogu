#include <bits/stdc++.h>
using namespace std;
int n, p, a[2010], dp[2010];
int hs[2010], ans, hs_b[2010];
int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % p != 0)
            hs[a[i] % p] = 1;
        else
            hs[0] = 1;
    }
    ans = 1;
    for (int j = 1; j <= p; ++j) hs_b[j] = hs[j];
    while (!hs[0]) {
        ans++;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= p; ++j)
                if (hs[j]) {
                    hs_b[(j + a[i]) % p] = 1;
                }
        }
        for (int j = 0; j <= p; ++j) hs[j] = hs_b[j];
    }
    // for (int i = 1; i <= n; ++i)
    //     if (dp[i] >= p) {
    //         cout << i << "\n";
    //         return 0;
    //     }
    cout << ans << "\n";
    return 0;
}