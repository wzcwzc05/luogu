#include <bits/stdc++.h>
using namespace std;
int n, dp[1000010];
int main()
{
    cin >> n;
    dp[1] = 1, dp[2] = 2, dp[3] = 5;
    for (int i = 4; i <= n; ++i)
        dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 10000;
    cout << dp[n] << "\n";
    return 0;
}