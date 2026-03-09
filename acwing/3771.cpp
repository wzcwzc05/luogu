#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll> mp;
ll n, tmp, ans;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> tmp;
        mp[tmp - i] += tmp;
        ans = max(mp[tmp - i], ans);
    }
    cout << ans << "\n";
    return 0;
}