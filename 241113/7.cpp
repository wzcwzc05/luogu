#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = 0;
    while (n != 0) {
        ans = max(n % 10, ans);
        n /= 10;
    }
    cout << ans << "\n";
    return 0;
}