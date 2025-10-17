#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 20;
long long a[N];
int n, d, ans;
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int t = upper_bound(a, a + n, a[i] + d) - a;
        ans += t - i - 1;
    }
    cout << ans;
    return 0;
}