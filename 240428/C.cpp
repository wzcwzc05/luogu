#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, h, ans, maxn, t;
ll mp[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> mp[i];
        maxn = max(mp[i], maxn);
    }
    sort(mp + 1, mp + n + 1);   // 从小到大排序
    cin >> t;
    ll l = t, r = t, a = 1;
    while (l <= maxn) {
        ll count = upper_bound(mp + 1, mp + n + 1, r) - // 二分查找返回数组中第一个大于r的数的指针
                   lower_bound(mp + 1, mp + n + 1, l); // 二分查找返回数组中第一个大于等于l的数的指针
        //cout << l << " " << r << " " << count << "\n";
        ans = max(ans, count * a);
        a *= 2, l = l * 3 - 2, r = r * 3;   // 下界更新，上界更新，倍数递增
    }
    cout << ans << "\n";
    return 0;
}