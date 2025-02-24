#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[5][200], n, m, ans;
void dfs(int dep, int left_, int right_,
         int d) {  // 深度,左脑用时,右脑用时,第d科
    if (dep > a[d][0]) {
        ans = min(ans, max(left_, right_));
    } else {
        dfs(dep + 1, left_ + a[d][dep], right_, d);
        dfs(dep + 1, left_, right_ + a[d][dep], d);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 4; ++i) cin >> a[i][0];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= a[i][0]; ++j) cin >> a[i][j];
    }
    int sum = 0;
    for (int i = 1; i <= 4; ++i) {
        ans = INT_MAX;
        dfs(1, 0, 0, i);
        sum += ans;
    }
    cout << sum << "\n";
    return 0;
}