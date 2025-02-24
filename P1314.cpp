#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, s, l, r, x, y;
ll w[200001], v[200001];
ll pre[200001], pre1[200001];
vector<pair<ll, ll>> t;
ll check(int e) {
    pre[0] = 0;
    for (int i = 1; i <= n; ++i)
        if (w[i] >= e)
            pre[i] = pre[i - 1] + 1, pre1[i] = pre1[i - 1] +  v[i];
        else
            pre[i] = pre[i - 1], pre1[i] = pre1[i - 1];
    ll ans = 0;
    for (auto &i : t)
        ans += (pre[i.second] - pre[i.first - 1]) *
               (pre1[i.second] - pre1[i.first - 1]);
    return ans - s;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    l = INT_MAX, r = INT_MIN;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i], l = min(l, w[i]), r = max(r, w[i]);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        t.push_back(make_pair(x, y));
    }
    int mid = (l + r) / 2;
    while (l <= r) {
        ll tmp = check(mid);
        if (tmp > 0)
            l = mid + 1;
        else if (tmp < 0)
            r = mid - 1;
        else if (tmp == 0) {
            cout << mid << "\n";
            return 0;
        }
        mid = (l + r) / 2;
    }
    // cout << "Mid: " << mid << "\n";
    // cout << "Check: " << check(4) << " " << check(5) << "\n";
    cout << min(abs(check(mid)), min(abs(check(mid - 1)), abs(check(mid + 1))))
         << "\n";
    return 0;
}