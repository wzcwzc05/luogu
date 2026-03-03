#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct pos {
    double l, r;
};
ll n, d;
bool cmp(pos& a, pos& b) { return a.l < b.l; }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    ll cnt = 1;
    double cur_x = 0;
    while (n != 0 && d != 0) {
        vector<pos> v;
        double x, y;
        bool flag = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            // cout << d << "vs" << y << "\n";
            if ((double)d - y > -1e-9) {
                double len = sqrt((double)d * d - y * y);
                v.push_back({x - len, x + len});
            } else {
                flag = 1;
            }
        }
        if (flag) {
            cout << "Case " << cnt << ": -1\n";
            cin >> n >> d;
            cnt++;
            v.clear();
            continue;
        }
        sort(v.begin(), v.end(), cmp);
        ll res = 1;
        double cur_x = v[0].r;
        // cout << cur_x << "\n";
        for (int i = 1; i < n; ++i) {
            if (cur_x - v[i].l > -1e-9) {
                cur_x = min(v[i].r, cur_x);
            } else {
                res++;
                cur_x = v[i].r;
                // cout << cur_x << "\n";
            }
        }
        cout << "Case " << cnt << ": " << res << "\n";
        cin >> n >> d;
        cnt++;
        v.clear();
    }
    return 0;
}