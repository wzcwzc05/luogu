#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, m, prefix[N], a[N];
bool check(ll maxn) {
    ll res = 1, cur_sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > maxn) return false;
        if (cur_sum + a[i] > maxn) {
            cur_sum = 0;
            res += 1;
        }
        cur_sum += a[i];
    }
    return res <= m;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll l = 1, r = prefix[n], mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r + 1 << "\n";
    return 0;
}