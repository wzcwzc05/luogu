#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, ans, t;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        ll count = (n - i) * i + 1;
        if (count % 2 == 1)
            ans += t * (count / 2 + 1);
        else
            ans += t * (count / 2);
    }
    cout << ans << "\n";
    return 0;
}