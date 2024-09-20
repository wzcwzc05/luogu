#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x, y;
    cin >> n >> x >> y;

    string str;
    cin >> str;

    vector<ll> mp_up(n + 1, 0), mp_right(n + 1, 0);
    map<pair<ll, ll>, vector<ll>> st;

    for (ll i = 0; i < n; ++i) {
        if (str[i] == 'W') mp_up[i + 1] = 1;
        if (str[i] == 'S') mp_up[i + 1] = -1;
        if (str[i] == 'A') mp_right[i + 1] = -1;
        if (str[i] == 'D') mp_right[i + 1] = 1;
    }

    for (ll i = 1; i <= n; ++i) {
        mp_up[i] += mp_up[i - 1];
        mp_right[i] += mp_right[i - 1];
    }

    st[{0, 0}].push_back(0);
    ll ans = 0;

    for (ll i = 1; i <= n; ++i) {
        ll target_up = mp_up[i] - x;
        ll target_right = mp_right[i] - y;

        if (st.find({target_up, target_right}) != st.end()) {
            ans += st[{target_up, target_right}].size();
        }

        st[{mp_up[i], mp_right[i]}].push_back(i);
    }

    cout << ans << endl;
    return 0;
}
