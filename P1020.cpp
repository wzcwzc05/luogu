#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], dp[N], len;
int main() {
    while (cin >> a[++n]);
    n -= 1;
    len = 0;
    dp[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= dp[len]) {
            dp[++len] = a[i];
        } else {
            *upper_bound(dp + 1, dp + len + 1, a[i], greater<int>()) = a[i];
        }
    }
    cout << len << "\n";
    len = 0;
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (a[i] > dp[len]) {
            dp[++len] = a[i];
        } else {
            *lower_bound(dp + 1, dp + len + 1, a[i]) = a[i];
        }
    }
    cout << len << "\n";
    return 0;
}