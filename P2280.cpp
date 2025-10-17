#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
int n, m, max_x, max_y, ans;
int mp[N][N], prefix[N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    max_x = max_y = m;
    for (int i = 1; i <= n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        x++, y++;
        mp[x][y] += v;
        max_x = max(max_x, x), max_y = max(max_y, y);
    }
    for (int i = 1; i <= max_x; ++i)
        for (int j = 1; j <= max_y; ++j)
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] -
                           prefix[i - 1][j - 1] + mp[i][j];
    for (int i = m; i <= max_x; ++i)
        for (int j = m; j <= max_y; ++j)
            ans = max(ans, prefix[i][j] - prefix[i - m][j] - prefix[i][j - m] +
                               prefix[i - m][j - m]);
    cout << ans << '\n';
    return 0;
}