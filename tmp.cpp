#include <bits/stdc++.h>
using namespace std;
int n, d, cnt = 1, ans;
struct node {
    double l, r;
} a[1005];
bool cmp(const node& a, const node& b) { return a.l < b.l; }
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    while (n && d) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            if (y > d)
                ans = -1;
            else {
                double t = sqrt(d * d - y * y);
                a[i].l = x - t;
                a[i].r = x + t;
            }
        }
        if (ans != -1) {
            sort(a + 1, a + n + 1, cmp);
            double tmp = -0x7fffffff / 2;
            for (int i = 1; i <= n; i++) {
                if (a[i].l > tmp) {
                    ans++;
                    tmp = a[i].r;
                } else {
                    tmp = min(tmp, a[i].r);
                }
            }
        }
        cout << "Case " << cnt << ": " << ans << '\n';
        cnt++;
        ans = 0;
        cin >> n >> d;
    }
    return 0;
}