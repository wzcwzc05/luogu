#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x, y, z, n, T;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x >> y >> z >> T;
    ll re = z + T, total = x + y;
    for (int i = 1; i <= n; ++i) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t1 + t2 <= total || t3 > re)
            continue;
        else {
            total = t1 + t2;
        }
    }
    cout << total << "\n";
    return 0;
}