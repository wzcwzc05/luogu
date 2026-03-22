#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, s, t;
ll a[N];
double min_t[N], pre[N];
bool check(double avg) {
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i] - avg;
    ll len = t - s + 1;
    deque<double> q;
    for (int i = 0; i <= n; ++i) {
        if (i - len >= 0 && q.front() == pre[i - len]) q.pop_front();
        while (!q.empty() && q.front() > pre[i]) q.pop_front();
        q.push_back(pre[i]);
        min_t[i] = q.front();
    }
    // for (int i = 0; i <= n; ++i)
    //     cout << i << ". " << pre[i] << " " << min_t[i] << "\n";
    for (int i = s; i <= n; ++i) {
        if (pre[i] - min_t[i-s] >= 0) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> s >> t;
    double l = a[1], r = a[1], mid = a[1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l = min(l, (double)a[i]), r = max(r, (double)a[i]);
    }
    // cout << check(1.300) << "\n";
    while (r - l >= 1e-4) {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(3) << l << "\n";
    return 0;
}