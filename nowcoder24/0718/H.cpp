#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, x, y, ans;
string str;
ll mp_up[100005], mp_right[100005];
map<ll, vector<ll>> st_up, st_right;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x >> y;
    cin >> str;
    if (x == 0 && y == 0) {
        cout << n * (n + 1) / 2 << endl;
        return 0;
    }
    for (ll i = 0; i < str.size(); i++) {
        if (str[i] == 'W') mp_up[i + 1] = 1, mp_right[i + 1] = 0;
        if (str[i] == 'S') mp_up[i + 1] = -1, mp_right[i + 1] = 0;
        if (str[i] == 'A') mp_up[i + 1] = 0, mp_right[i + 1] = -1;
        if (str[i] == 'D') mp_up[i + 1] = 0, mp_right[i + 1] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
        mp_up[i] += mp_up[i - 1];
        mp_right[i] += mp_right[i - 1];
    }
    for (ll i = 1; i <= n; ++i) {
        st_up[mp_up[i - 1]].push_back(i - 1);
        st_right[mp_right[i - 1]].push_back(i - 1);
        if (!st_up[mp_up[i] - x].empty()) {
            for (auto j : st_up[mp_up[i] - x]) {
                if (mp_right[i] - mp_right[j] == y) {
                    cout << i << " " << j << endl;
                    ans += (n - i + 1);
                }
            }
        }
    }
    // for (auto j : st_up[1]) cout << j << " ";
    cout << ans << endl;
    return 0;
}