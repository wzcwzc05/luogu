#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[1010], ans;
bool vis[1010];
void dfs(int k, int r)
{
    if (k <= n) {
        dfs(k + 1, r);
        if (r - a[k] > 0) {
            vis[k] = 1;
            dfs(k + 1, r - a[k]);
        };
        vis[k] = 0;
    } else {
        for (int i = 1; i <= n; ++i)
            vis[k] == 1 ? printf("%d ", i) : 0;
        ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, m);
    cout << ans << "\n";
    return 0;
}