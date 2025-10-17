#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, w, s, ans;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> s;
        ans += (w * s);
    }
    cout << max(0ll, ans) << "\n";
    return 0;
}
