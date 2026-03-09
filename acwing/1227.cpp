#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, l, r, mid;
int h[N], w[N];
bool check(int num) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += (h[i] / num) * (w[i] / num);
    }
    return res >= k;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> h[i] >> w[i], r = max(r, max(h[i], w[i]));
    l = 1;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (!check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (check(l))
        cout << l << "\n";
    else
        cout << l - 1 << "\n";
    return 0;
}