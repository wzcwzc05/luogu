#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 100010;
ll q, n, push_v[N], pop_v[N], p;
stack<ll> stk;
void solve() {
    p = 1;
    while (!stk.empty()) stk.pop();
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> push_v[i];
    for (int i = 1; i <= n; ++i) cin >> pop_v[i];
    for (int i = 1; i <= n; ++i) {
        stk.push(push_v[i]);
        if (stk.top() == pop_v[p]) {
            while (!stk.empty() && stk.top() == pop_v[p]) stk.pop(), ++p;
        }
    }
    if (!stk.empty())
        cout << "No\n";
    else
        cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}