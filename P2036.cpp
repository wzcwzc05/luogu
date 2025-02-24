#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, ans;
ll s[100], b[100];
void dfs(ll dep, ll s_sum, ll b_sum) {
    if (dep > n) {
        if (s_sum == 1 && b_sum == 0) return;
        ans = min(ans, abs(s_sum - b_sum));
        // cout << s_sum << " " << b_sum << "!\n";
        return;
    }
    dfs(dep + 1, s_sum, b_sum);
    dfs(dep + 1, s_sum * s[dep], b_sum + b[dep]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ans = INT_MAX;
    for (int i = 1; i <= n; ++i) cin >> s[i] >> b[i];
    dfs(1, 1, 0);
    cout << ans << "\n";
    return 0;
}