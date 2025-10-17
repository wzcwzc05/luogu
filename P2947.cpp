#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll h[N], n, m, ans[N];
stack<ll> stk;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() && h[stk.top()] <= h[i]) stk.pop();
        if (stk.empty())
            ans[i] = 0;
        else
            ans[i] = stk.top();
        stk.push(i);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
    return 0;
}