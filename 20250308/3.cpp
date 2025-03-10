#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, left_[5010], right_[5010];
string str;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str;
    ll now = -1;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '1') now = i;
        left_[i] = now;
    }
    now = n + 1;
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == '1') now = i;
        right_[i] = now;
    }
    // for (int i = 0; i < n; ++i) cout << left_[i] << " " << right_[i] << "\n";
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            ll l = INT_MAX, r = INT_MAX;
            if (left_[i] != -1) l = i - left_[i];
            if (right_[i] != n + 1) r = right_[i] - i;
            ll ans = min(l, r);
            if (ans == INT_MAX)
                cout << "-1 ";
            else
                cout << ans << " ";
        }
    }
    return 0;
}