#include <bits/stdc++.h>
using namespace std;
int n, start, tail;
int a[1000], ans;
bool flag[1000];
void dfs(int dep, int t)
{
    if (dep > ans)
        return;
    flag[t] = 1;
    if (t == tail)
    {
        ans = min(ans, dep);
    }
    else
    {
        if (t + a[t] <= n && flag[t + a[t]] == 0)
            dfs(dep + 1, t + a[t]);
        if (t - a[t] >= 1 && flag[t - a[t]] == 0)
            dfs(dep + 1, t - a[t]);
    }
    flag[t] = 0;
}
int main()
{
    scanf("%d %d %d", &n, &start, &tail);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = INT_MAX;
    dfs(0, start);
    if (ans < INT_MAX)
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}