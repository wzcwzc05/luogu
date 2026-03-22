#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, l, r, ans, ans_l, ans_r;
ll a[N], pre[N];
ll l_min[N], r_min[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int flag = 0;
    while (cin >> n) {
        ans = 0;
        ans_l = ans_r = 1;
        pre[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
        stack<ll> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
            if (stk.empty())
                l_min[i] = 0;
            else
                l_min[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
            if (stk.empty())
                r_min[i] = n + 1;
            else
                r_min[i] = stk.top();
            stk.push(i);
        }
        for (int i = 1; i <= n; ++i) {
            l = l_min[i] + 1, r = r_min[i] - 1;
            ll sum = (pre[r] - pre[l - 1]) * a[i];
            if (sum > ans) ans_l = l, ans_r = r, ans = sum;
            if (sum == ans && r - l < ans_l - ans_r)
                ans_l = l, ans_r = r, ans = sum;
        }
        if (flag++) cout << "\n";
        cout << ans << "\n" << ans_l << " " << ans_r << "\n";
    }
    return 0;
}