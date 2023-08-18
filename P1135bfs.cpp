#include <bits/stdc++.h>
using namespace std;

int n, start, tail, dep;
int a[1000], ans;
bool flag[1000];
queue<pair<int, int>> q;

int main()
{
    scanf("%d %d %d", &n, &start, &tail);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = INT_MAX;
    q.push({start, 0});
    dep = 0;
    while (!q.empty())
    {
        int t = q.front().first;
        flag[t] = 1;
        int dep = q.front().second;
        q.pop();
        if (t == tail)
        {
            printf("%d\n", dep);
            return 0;
        }
        if (t + a[t] <= n && flag[t + a[t]] == 0)
        {
            q.push({t + a[t], dep + 1});
            flag[t + a[t]] = 1;
        }
        if (t - a[t] >= 1 && flag[t - a[t]] == 0)
        {
            q.push({t - a[t], dep + 1});
            flag[t - a[t]] = 1;
        }
    }
    printf("-1\n");
    return 0;
}
