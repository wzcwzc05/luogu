#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
unordered_map<ll, ll> hs, ans;
ll calc_step(ll ori, ll offset) {
    ori -= offset % n;
    if (ori >= 0)
        return ori;
    else
        return n - abs(ori);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    if (k == 0) {
        cout << "0\n";
        return 0;
    }
    ll now_steps = 0, s = 0, first = 0;
    for (int i = 1; i <= n; ++i) {
        ll temp;
        cin >> temp;
        hs[temp - 1] = i - 1;
        if (temp == 1) {
            now_steps = i - 1;
            first = i - 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        ll now = calc_step(hs[i], now_steps);
        now_steps += now, s += now;
        ans[i] = now;
    }
    ll steps = calc_step(hs[0], now_steps);
    ans[n] = steps, s += steps;
    if (k == 1) {
        cout << first << "\n";
        return 0;
    }
    // cout << "fuck " << s << "\n";
    // for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
    k -= 1;
    ll res = first;
    res += k / n * s;
    for (int i = 1; i < k % n + 1; ++i) {
        res += ans[i];
    }
    cout << res << "\n";
    return 0;
}