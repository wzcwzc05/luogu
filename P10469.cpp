#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll N = 3e5 + 10;
const ll BASE = 1e9 + 7;
string str;
ll height[N], sa[N];
ll hs[N], bases[N], len;
ll get_h(ll l, ll r) { return hs[r] - hs[l - 1] * bases[r - l + 1]; }
ll get_prefix(ll x, ll y) {
    ll l = -1, r = min(len - x + 1, len - y + 1) + 1, mid = 0, res = 0;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (get_h(x, x + mid - 1) == get_h(y, y + mid - 1)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
bool cmp(ll a, ll b) {
    ll pos = get_prefix(a, b);
    return str[a + pos] < str[b + pos];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str;
    len = str.length();
    str = "#" + str + char(10);
    bases[0] = 1;
    for (int i = 1; i <= len; ++i) {
        sa[i] = i;
        bases[i] = bases[i - 1] * BASE;
        hs[i] = hs[i - 1] * BASE + str[i];
    }
    sort(sa + 1, sa + len + 1, cmp);
    for (int i = 1; i <= len; ++i) cout << sa[i] - 1 << " ";
    cout << "\n";
    cout << "0 ";
    for (int i = 2; i <= len; ++i) cout << get_prefix(sa[i], sa[i - 1]) << " ";
    cout << "\n";
    return 0;
}