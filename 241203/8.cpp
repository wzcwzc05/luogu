#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string str, str1;
int dp[1010][1010];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str;
    str1 = "LANQIAO";
    int n = str.size(), m = str1.size();
    for (int i = 1; i <= m; ++i) {
        char c1 = str1[i - 1];
        for (int j = 1; j <= n; ++j) {
            char c2 = str[j - 1];
            if (c1 == c2)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    if (dp[m][n] == m)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}