#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, m;
ll a[N], b[N];
bool check(ll pos) {
    for (int i = 1; i < pos; ++i) b[i] = a[i];
    sort(b + 1, b + pos);
    ll tmp = n - pos;
    for (int i = 1; i < pos; ++i)
        if (b[i] > tmp)
            return false;
        else
            tmp++;
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll l = 1, r = n, mid = 0;
    while (l <= r) {
        mid = (r + l) / 2;
        // cout << mid << "!\n";
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << n - r << "\n";
    return 0;
}