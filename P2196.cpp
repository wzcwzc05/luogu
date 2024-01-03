#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3;
int n, m, t[N], dp[N], p[N];
vector<int> mp[N];
void printAns(int i)
{
    if (p[i] != 0)
    {
        printAns(p[i]);
        cout << i << " ";
    }
    else
    {
        cout << i << " ";
        return;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
                mp[i].push_back(j), mp[j].push_back(i);
        }
    }
    dp[1] = t[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = t[i];
        for (auto j = mp[i].begin(); j != mp[i].end(); ++j)
        {
            if (*j < i && dp[i] < dp[*j] + t[i])
            {
                dp[i] = dp[*j] + t[i];
                p[i] = *j;
            }
        }
    }
    int ans = INT_MIN, ansN = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] > ans)
        {
            ansN = i;
            ans = dp[i];
        }
    }
    printAns(ansN);

    cout << "\n"
         << ans << "\n";
    return 0;
}