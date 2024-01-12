#include <bits/stdc++.h>
using namespace std;
int v, n, a[1000], ans, flag[1000];
void dfs(int dep, int remain)
{
    ans = min(remain, ans);
    if (dep <= n && remain <= flag[dep])
    {
        dfs(dep + 1, remain);
        if (remain - a[dep] >= 0)
            dfs(dep + 1, remain - a[dep]);
    }
    else
        return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], flag[i] = INT_MAX;
    ans = INT_MAX, flag[0] = INT_MAX;
    dfs(0, v);
    cout << ans << "\n";
    return 0;
}