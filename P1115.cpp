#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 10;
ll dp[N], n, t, ans;
int main()
{
    cin >> n;
    ans=INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (i == 1)
            dp[i] = t;
        else
            dp[i] = max(dp[i - 1] + t, t);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}