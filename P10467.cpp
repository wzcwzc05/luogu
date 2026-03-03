#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 1;
ll n;
unordered_map<ll, int> hs;
void swap_(vector<ll>& v) {
    for (int i = 0; i <= 2; ++i) {
        swap(v[i], v[5 - i]);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        vector<ll> v;
        ll temp = 0;
        for (int i = 0; i < 6; ++i) {
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < 6; ++i) {
            ll ans = 0;
            for (int j = 0; j < 6; ++j) ans = ans * N + v[(i + j) % 6];
            if (hs[ans] == 1) {
                cout << "Twin snowflakes found.\n";
                return 0;
            }
            hs[ans] = 1;
        }
        swap_(v);
        for (int i = 0; i < 6; ++i) {
            ll ans = 0;
            for (int j = 0; j < 6; ++j) ans = ans * N + v[(i + j) % 6];
            if (hs[ans] == 1) {
                cout << "Twin snowflakes found.\n";
                return 0;
            }
            hs[ans] = 1;
        }
    }
    cout << "No two snowflakes are alike.\n";
    return 0;
}