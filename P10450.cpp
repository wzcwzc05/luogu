#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, len, a[N], l, r, prefix[N];
bool check(ll mid) {
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] - mid + a[i];
    ll mins = INT_MAX;
    for (int i = len; i <= n; ++i) {
        mins = min(mins, prefix[i - len]);
        if (prefix[i] - mins >= 0) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> len;
    l = INT_MAX, r = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]), r = max(r, a[i]);
    }
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + a[i];
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << "\n";
    return 0;
}