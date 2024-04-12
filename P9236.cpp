#include <bits/stdc++.h>
using namespace std;
using ll = long long;
<<<<<<< HEAD
const int N = 1e5 + 10;
ll a[N], pre[N], n;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    ll sum = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) sum += pre[j] ^ pre[i];
    }
    cout << sum << "\n";
=======
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
>>>>>>> cfb02e72d7d8461123dafa93d92bc15fcd7b82c6
    return 0;
}