#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[1000];
bool isPrime(int t)
{
    for (int i = 2; i * i <= t;i++)
        if (t%i==0)
            return false;
    return true;
}
void dfs(int dep, int seri, int sum)
{
    if (dep < k)
    {
        for (int i = seri; i <= n; i++)
        {
            dfs(dep + 1, i + 1, sum + a[i]);
        }
        return;
    }
    else
    {
        if (isPrime(sum))
            ans++;
        return;
    }
    return;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = 0;
    dfs(0, 1, 0);
    cout << ans << endl;
    return 0;
}
