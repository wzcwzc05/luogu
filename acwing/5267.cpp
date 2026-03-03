#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, k, q, l, r, diff[N], prefix[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> l >> r;
        diff[l] += 1, diff[r + 1] -= 1;
    }
    ll cur = 0;
    for (int i = 1; i <= (int)2e5 + 5; ++i) {
        cur += diff[i];
        if (cur >= k)
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}