#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, a[N], m, len1, len2, sum1, sum2;
deque<ll> dq1, dq2;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll ans = INT_MIN;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            dq1.push_back(a[i]);
            sum1 += a[i];
            if (len1 == m)
                sum1 -= dq1.front(), dq1.pop_front(), ans = max(ans, sum1);
            else
                len1++;
        } else {
            dq2.push_back(a[i]);
            sum2 += a[i];
            if (len2 == m)
                sum2 -= dq2.front(), dq2.pop_front(), ans = max(ans, sum2);
            else
                len2++;
        }
    }
    cout << ans << "\n";
    return 0;
}